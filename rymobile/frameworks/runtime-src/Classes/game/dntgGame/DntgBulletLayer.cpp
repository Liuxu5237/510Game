#include "DntgBulletLayer.h"

#include "DntgRoleNode.h"
#include "DntgBulletNode.h"

#include "DntgTimestampManager.h"
#include "DntgRoleLayer.h"

#include "DntgGameScene.h"
#include "DntgSimpleTools.h"
#include "DntgGameHeader.h"
#include "DntgObjectPool.h"
#include "DntgActionCustom.h"
#include "kernel/game/CGameFrameEngine.h"
#include "kernel/game/IGameFrameEngineSink.h"

USING_NS_CC;
using namespace Dntg;
//////////////////////////////////////////////////////////////////////////
BulletLayer::BulletLayer()
{
}

BulletLayer::~BulletLayer()
{
}

//初始化方法
bool BulletLayer::init()
{
	do
	{
		CC_BREAK_IF(!CCLayer::init());
		CCSpriteFrameCache* cache = CCSpriteFrameCache::sharedSpriteFrameCache();
		batch_node_ = CCSpriteBatchNode::createWithTexture(cache->spriteFrameByName("Bullet0_01.png")->getTexture(), 128);
		addChild(batch_node_);

		return true;
	} while (0);

	return false;
}

void BulletLayer::send_bullet(Bullet* bullet, const cocos2d::Vec2& pt, int trad)
{

	BulletNode* node = ObjectPool::shared()->createBulletNode(bullet->chair_id_, bullet->bullet_type_);
	BulletNode* shadow = ObjectPool::shared()->createBulletNode(bullet->chair_id_, bullet->bullet_type_);
	shadow->born(true);
	node->born(false);

	///< 缩放
	shadow->setScale(0.75f);
	node->setScale(0.75f);

	node->setNetType(bullet->net_type_);
	node->setPosition(pt);
	node->setRotation(toCCRotation(bullet->rotation_ - M_PI_2));
	node->setBirdId(bullet->lock_bird_id_);
	batch_node_->addChild(node, 1);
	shadow->setPosition(Vec2(node->getPositionX() + 15, node->getPositionY() - 15));
	batch_node_->addChild(shadow, 0);
	// 	Action_Bullet_Move* act = Action_Bullet_Move::create(bullet->rotation_, bullet->speed_);
	// 	act->setTag(2000);
	// 	node->runAction(act);
	// 	act->step(0);
	// 	act->step((float)(trad) / 1000.0);
	// 
	// 	bullet->node_ = node;
	// 	bullet->move_action_id_ = act->getTag();
	fire_process(node, shadow, bullet, pt, trad);
}

void BulletLayer::fire_failed(int id)
{

}

float BulletLayer::fire(Bullet* bullet, int trad /*= 0*/, bool isSpecialBullet /*= false*/)
{
	CCPoint pt_bullet = toCCP(
		CANNON_POSITION[bullet->chair_id_][0] + 56 * std::cos(bullet->rotation_ - M_PI_2) / 3.0f,
		CANNON_POSITION[bullet->chair_id_][1] + 56 * std::sin(bullet->rotation_ - M_PI_2) / 3.0f);

	// 	float angle = CC_RADIANS_TO_DEGREES(bullet->rotation_);
	// 	log("now_bullet_rotation is %f and %f", bullet->rotation_, angle);
	BulletNode* node = ObjectPool::shared()->createBulletNode(bullet->chair_id_, bullet->bullet_type_, isSpecialBullet);
	BulletNode* shadow = ObjectPool::shared()->createBulletNode(bullet->chair_id_, bullet->bullet_type_, isSpecialBullet);
	shadow->born(true);
	node->born(false);


	///< 缩放
	shadow->setScale(0.75f);
	node->setScale(0.75f);


	node->setNetType(bullet->net_type_);
	//log("x is ~~~~~~~~%f, y is ~~~~~~~~~~ %f", pt_bullet.x, pt_bullet.y);
	node->setPosition(pt_bullet);
	node->setBirdId(bullet->lock_bird_id_);
	batch_node_->addChild(node, 1);
	shadow->setPosition(Vec2(node->getPositionX() + 15, node->getPositionY() - 15));
	batch_node_->addChild(shadow, 0);

	if (isSpecialBullet)
		return fire_process(node, shadow, bullet, trad);
	else
		return fire_process(node, shadow, bullet, pt_bullet, trad);


}

float BulletLayer::fire_process(BulletNode * node, BulletNode* shadow, Bullet * bullet, cocos2d::Vec2 pt_bullet, float trad)
{
	float playerAngle = bullet->rotation_;

	ActionInterval * act = nullptr;
	ActionInterval * act_shadow = nullptr;

	if (CGameFrameEngine::Get()->GetGameFrameEngineSink())
	{
		//CGameSceneEngine* pGameSceneSink = (CGameSceneEngine*)(CGameFrameEngine::Get()->GetGameFrameEngineSink()->GetGameSceneSink());
        CGameSceneEngine* pGameSceneSink = dynamic_cast<CGameSceneEngine*>(CGameFrameEngine::Get()->GetGameFrameEngineSink()->GetGameSceneSink());
		if (pGameSceneSink)
		{
			RoleNode* role = pGameSceneSink->role_layer_->get_role(bullet->chair_id_);
            
			///< 让鱼知道自己被谁绑定了
			pGameSceneSink->setBirdLock(bullet->chair_id_, bullet->lock_bird_id_);
            //CCLOG("--1-- CGameFrameEngine=%p GameFrameEngineSink=%p pGameSceneSink=%p  get_role_layer=%p  get_role=%p",CGameFrameEngine::Get(), CGameFrameEngine::Get()->GetGameFrameEngineSink(), pGameSceneSink, pGameSceneSink->role_layer_, role);

			if (role && role->isLockBird() && role->getLockBird()->bird)
			{
				///< 获取的是,世界坐标/
				xPoint fish_pos = toNetPoint(role->getLockBirdPos());
				///< 火炮的位置
				xPoint fire_pos = toNetPoint(pt_bullet);
				///< 获取子弹的移动时间
				float speed_bird = role->getLockBird()->bird->speed_;	//鱼游动速度
				if (speed_bird > 10 || pGameSceneSink->isDing) // || 定屏状态
					speed_bird = 1;
				float elapsed = bulletMoveDuration(fire_pos, fish_pos, bullet->speed_ / speed_bird);

				///< 获取鱼在指定时间到达的目标点
				xPoint fish_target_pos = role->getFishNextPosition(elapsed);
				///< 计算鱼与炮台的角度
				float fish_and_fire_angle = bulletMoveAngle(fire_pos, fish_pos);
				//float angle = CC_RADIANS_TO_DEGREES(fish_and_fire_angle);
				///< 计算鱼鱼炮台的位置
				playerAngle = SimpleTools::calcRotate(bullet->chair_id_, fish_pos);
				//float tAngle = CC_RADIANS_TO_DEGREES(playerAngle);
				playerAngle = SimpleTools::calcRotate(bullet->chair_id_, fish_target_pos);
				/*tAngle = CC_RADIANS_TO_DEGREES(playerAngle);*/
				//angle = CC_RADIANS_TO_DEGREES(fish_and_fire_angle);

				act = Action_Bullet_Move_To::create(fire_pos, fish_target_pos, playerAngle, bullet->speed_);
				act_shadow = Action_Bullet_Move_To::create(fire_pos + xPoint(15, -15), fish_target_pos + xPoint(15, -15), playerAngle, bullet->speed_);
			}
			else
			{
				act = Action_Bullet_Move::create(bullet->rotation_, bullet->speed_);
				act_shadow = Action_Bullet_Move::create(bullet->rotation_, bullet->speed_);
			}

			act->setTag(2000);
			node->runAction(act);
			shadow->runAction(act_shadow);
			act->step(0);
			act->step((trad) / 1000.0);
			act_shadow->step(0);
			act_shadow->step(trad / 1000.0);

			bullet->node_ = node;
			bullet->shadow_ = shadow;
			bullet->move_action_id_ = act->getTag();
		}
	}

	return playerAngle;
}

float BulletLayer::fire_process(BulletNode * node, BulletNode* shadow, Bullet * bullet, float trad)
{
	float playerAngle = bullet->rotation_;

	bullet->node_ = node;
	bullet->shadow_ = shadow;
	bullet->move_action_id_ = 0;

	return playerAngle;
}

float BulletLayer::energy_fire_process(BulletNode * node, BulletNode* shadow, Bullet * bullet, cocos2d::Vec2 pt_bullet, float trad)
{
	return 0.0f;
}


float BulletLayer::bulletMoveDuration(const xPoint & start, const xPoint & end, float bullet_speed)
{
	xPoint delta = end - start;
	float length = std::sqrt(delta.x_ * delta.x_ + delta.y_ * delta.y_);
	return length / bullet_speed;
}

float BulletLayer::bulletMoveAngle(const xPoint & start, const xPoint & end)
{
	float angle = (toCCP(start) - toCCP(end)).getAngle();
	return angle;
}

