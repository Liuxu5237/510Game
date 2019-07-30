#include "DntgBirdLayer.h"

#include "DntgGameScene.h"
#include "DntgActionCustom.h"
#include "DntgSimpleTools.h"
#include "DntgGameHeader.h"
#include "DntgObjectPool.h"
#include "DntgBirdNode.h"
#include "tools/manager/SpriteHelper.h"
#include "tools/manager/Game_Path_Manager.h"
#include "platform/GlobalConfig.h"
#include "kernel/game/CGameFrameEngine.h"
#include "kernel/game/IGameFrameEngineSink.h"


#define __BIRD_SHAKE_TIME__			(0.8f)			//鱼震动时间
#define __BIRD_SHAKE_RANGE__		(3.0F)			//鱼震动幅度

USING_NS_CC;
using namespace Dntg;
//////////////////////////////////////////////////////////////////////////
BirdLayer::BirdLayer()
{
	dinged_ = false;
}

BirdLayer::~BirdLayer()
{
}

//初始化方法
bool BirdLayer::init()
{
	do
	{
		CC_BREAK_IF(!CCLayer::init());
		CCSpriteFrameCache* cache = CCSpriteFrameCache::sharedSpriteFrameCache();
		batch_node1_ = CCSpriteBatchNode::createWithTexture(cache->spriteFrameByName("img_toumingdian_1.png")->getTexture(), 128);
		addChild(batch_node1_);
		batch_node2_ = CCSpriteBatchNode::createWithTexture(cache->spriteFrameByName("Bird20_01.png")->getTexture(), 128);
		addChild(batch_node2_);
		return true;
	} while (0);

	return false;
}


void BirdLayer::send_bird(Bird* bird)
{
	BirdNode* node = nullptr;
	BirdNode* shadow = nullptr;
	if (!SimpleTools::isDntgSpecialBird(bird->type_))
	{
		node = ObjectPool::shared()->createBirdNode(bird->type_);
		shadow = ObjectPool::shared()->createBirdNode(bird->type_);

	}
	else if (SimpleTools::isDntgSpecialRoundBird(bird->type_))
	{
		
		///< 是圆盘鱼,用特殊类去创建它
		node = ObjectPool::shared()->createBirdNode(bird->item_, true);
		dynamic_cast<SpecialBirdNode *>(node)->setBirdNum(bird->type_ - BIRD_TYPE_ONE + 1);
		shadow = ObjectPool::shared()->createBirdNode(bird->item_, true);
		dynamic_cast<SpecialBirdNode *>(shadow)->setBirdNum(bird->type_ - BIRD_TYPE_ONE + 1);

	}
	else if (SimpleTools::isDntgSpecialBird(bird->type_))
	{
		node = ObjectPool::shared()->createBirdNode(bird->item_);
		shadow = ObjectPool::shared()->createBirdNode(bird->item_);
	}

	node->born(false);
	shadow->born(true);

	///< 缩放
	node->autoScale();
	shadow->autoScale();

	///, 阴影都是0
	node->setPosition(toCCP(-500, -500));
	shadow->setPosition(toCCP(-500, -500));


	/*	int tType = bird->type_ < 15 ? 30 : bird->type_;*/

	///< 特效用tap来做判断
	char sEffect[32] = { 0 };

	sprintf(sEffect, "BirdEffect%d", bird->type_);
	CCAnimate* effect_animate = SpriteHelper::createAnimate(sEffect);
	CCSprite* effect = 0;

	if (effect_animate != 0)
	{

		if (SimpleTools::isDntgSpecialRoundBird(bird->type_))
		{
			///< 是圆盘鱼
			CCSpriteFrameCache* cache = CCSpriteFrameCache::sharedSpriteFrameCache();
			effect = CCSprite::createWithSpriteFrame(cache->spriteFrameByName("img_toumingdian_1.png"));
			//effect->setDisplayFrameWithAnimationName(sEffect, 0);
			dynamic_cast<SpecialBirdNode *>(node)->setEffect(effect, effect_animate);
			effect->setPosition(toCCP(-500, -500));
		}
		else
		{
			effect = CCSprite::create();
			effect->setDisplayFrameWithAnimationName(sEffect, 0);
			effect->runAction(CCRepeatForever::create(effect_animate));
			effect->setPosition(toCCP(-500, -500));
		}

		effect->setOpacity(0);
		effect->runAction(CCFadeIn::create(1));
		effect->setScale(0.75f);
		///< 先判断特殊情况
		if (bird->type_ == BIRD_TYPE_CHAIN || bird->type_ == BIRD_TYPE_INGOT)///< 闪电鱼,闪电鱼都是小鱼,所以在batch_node_1中
			batch_node1_->addChild(effect, 2);
		else if (bird->type_ == BIRD_TYPE_RED || SimpleTools::isDntgSpecialRoundBird(bird->type_)) ///< 红鱼效果在下面
			batch_node1_->addChild(effect, 0);
		else if (bird->type_ <= 16)
			batch_node1_->addChild(effect, 0);
		/*else if (bird->type_ > 21 && bird->type_ < 27)
		batch_node2_->addChild(effect, 0);
		else
		batch_node3_->addChild(effect, 0);*/
	}

	///< 添加顺序是先特效,在影子在鱼
	if (SimpleTools::isDntgSpecialBird(bird->type_))
	{
		batch_node1_->addChild(shadow, 0);
	}
	else if (bird->type_ <= 19)
		batch_node1_->addChild(shadow, 0);
	else
		batch_node2_->addChild(shadow, 0);

	///< 小鱼,或者闪电鱼,红鱼
	if (bird->type_ <= 19 || SimpleTools::isDntgSpecialBird(bird->type_))
		batch_node1_->addChild(node, bird->item_ == BIRD_ITEM_ZORDER_0 ? this->getChildrenCount() : 1);
	else
		batch_node2_->addChild(node, bird->item_ == BIRD_ITEM_ZORDER_0 ? this->getChildrenCount() : 1);

	///< 调整光圈大小,使之能完全包裹鱼
	if (bird->type_ == BIRD_TYPE_CHAIN || bird->type_ == BIRD_TYPE_INGOT)
	{
		Size bird_Size = node->getSize();
		Size effect_Size = effect->getContentSize();
		//	Rect frame_Size = effect_animate->getAnimation()->getFrames().at(0)->getSpriteFrame()->getRect();
		Vec2 scale_effect = Vec2(bird_Size.width / effect_Size.width, bird_Size.height / effect_Size.width);

		if (scale_effect.x < scale_effect.y) scale_effect.x = scale_effect.y;
		else scale_effect.y = scale_effect.x;
		if (scale_effect.x < 0.2f) scale_effect.x = scale_effect.y = 0.2f;
		if (bird->type_ == BIRD_TYPE_CHAIN)
			effect->setScale(scale_effect.x);
		else if (bird->type_ == BIRD_TYPE_INGOT)
		{
			if (scale_effect.x > 0.6f)
			{
				effect->setScale(0.75f);
			}
			else
			{
				effect->setScale(0.45f);
			}
		}

	}



	node->bird = bird;
	bird->shadow_ = shadow;
	bird->node_ = node;
	bird->effect_ = effect;


	//我上次扩大是我的错， 应该是在原基础上面扩大哈loathe

	//鱼都给我扩大
	float CurFish = node->getScale();
	node->setScale(CurFish*1.40);

	if (shadow != nullptr)
	{
		float buzhidao = shadow->getScale();
		shadow->setScale(buzhidao*1.40);
	}

	if (effect != nullptr)
	{
		float CurPan = effect->getScale();
		effect->setScale(CurPan*1.40);
	}
	
	

	//node->setColor(Color3B::RED);
	//effect->setColor(Color3B::RED);
	//shadow->setColor(Color3B::RED);

	if (bird->type_ == BIRD_TYPE_RED)
		node->setRed();

	// 创建动作
	Move_Points &move_points = Game_Path_Manager::shared()->get_paths(bird->path_id_, bird->path_type_);
	Action * action = Action_Move_Point::create((float)BIRD_FRAME_SPEED, move_points, bird->path_offset_);

	node->birdMove = action;
	CCActionInterval* act = CCSequence::create(
		CCDelayTime::create(bird->path_delay_),
		action,
		CCCallFuncND::create(this, callfuncND_selector(BirdLayer::func_bird_hide), bird),
		CCDelayTime::create(5),
		CCCallFuncND::create(this, callfuncND_selector(BirdLayer::func_bird_end), bird),
		0);
	CCAction* actSpeed = CCSpeed::create(act, bird->speed_);

	actSpeed->setTag(1000);
	node->runAction(actSpeed);
	//node->runAction(act);
	actSpeed->step(0);
	actSpeed->step(bird->elapsed_);


	bird->move_action_id_ = actSpeed->getTag();
	if (dinged_)
	{
		node->pauseSchedulerAndActions();
	}
}

void BirdLayer::send_scene_bird(Bird* bird, Action_Bird_Move* action)
{
	BirdNode* node = nullptr;
	BirdNode* shadow = nullptr;

	int test_value = 0;
	if (!SimpleTools::isDntgSpecialBird(bird->type_))
	{
		node = ObjectPool::shared()->createBirdNode(bird->type_);
		shadow = ObjectPool::shared()->createBirdNode(bird->type_);

	}
	else if (SimpleTools::isDntgSpecialRoundBird(bird->type_))
	{
		///< 是圆盘鱼,用特殊类去创建它
		node = ObjectPool::shared()->createBirdNode(bird->item_, true);
		dynamic_cast<SpecialBirdNode *>(node)->setBirdNum(bird->type_ - BIRD_TYPE_ONE + 1);
		shadow = ObjectPool::shared()->createBirdNode(bird->item_, true);
		dynamic_cast<SpecialBirdNode *>(shadow)->setBirdNum(bird->type_ - BIRD_TYPE_ONE + 1);
		test_value += 1;

	}
	else if (SimpleTools::isDntgSpecialBird(bird->type_))
	{
		node = ObjectPool::shared()->createBirdNode(bird->item_);
		shadow = ObjectPool::shared()->createBirdNode(bird->item_);

	}
	node->born(false);
	shadow->born(true);

	///< 缩放
	node->autoScale();
	shadow->autoScale();

	node->setPosition(Vec2(-500, -500));
	shadow->setPosition(Vec2(-500, -500));
	///< 把鱼的特效加入到鱼自己里面
	node->birdMove = action;

	char sEffect[32] = { 0 };
	sprintf(sEffect, "BirdEffect%d", bird->type_);
	CCAnimate* effect_animate = SpriteHelper::createAnimate(sEffect);
	CCSprite* effect = 0;

	if (effect_animate != 0)
	{
		if (SimpleTools::isDntgSpecialRoundBird(bird->type_))
		{
			///< 是圆盘鱼
			CCSpriteFrameCache* cache = CCSpriteFrameCache::sharedSpriteFrameCache();
			effect = CCSprite::createWithSpriteFrame(cache->spriteFrameByName("img_toumingdian_1.png"));
			/*effect->setDisplayFrameWithAnimationName(sEffect, 0);*/
			dynamic_cast<SpecialBirdNode *>(node)->setEffect(effect, effect_animate);
			effect->setPosition(toCCP(-500, -500));
			test_value += 1;
		}
		else
		{
			effect = CCSprite::create();
			effect->setDisplayFrameWithAnimationName(sEffect, 0);
			effect->runAction(CCRepeatForever::create(effect_animate));
			effect->setPosition(toCCP(-500, -500));
		}

		if (test_value != 0 && test_value != 2)
		{
			CCAssert(this, "madenishisbma?");
		}
		effect->setOpacity(0);
		effect->runAction(CCFadeIn::create(1));
		effect->setScale(0.75f);
		///< 先判断特殊情况
		if (bird->type_ == BIRD_TYPE_CHAIN || bird->type_ == BIRD_TYPE_INGOT)///< 闪电鱼,闪电鱼都是小鱼,所以在batch_node_1中
			batch_node1_->addChild(effect, 2);
		else if (bird->type_ == BIRD_TYPE_RED || SimpleTools::isDntgSpecialRoundBird(bird->type_)) ///< 红鱼效果在下面
			batch_node1_->addChild(effect, 0);
		else if (bird->type_ <= 16)
			batch_node1_->addChild(effect, 0);
		/*else
		batch_node2_->addChild(effect, 0);*/
	}

	if (bird->type_ <= 19 || SimpleTools::isDntgSpecialBird(bird->type_))
		batch_node1_->addChild(shadow, 0);
	else
		batch_node2_->addChild(shadow, 0);

	shadow->setPosition(toCCP(bird->position_));
	if (bird->type_ <= 19 || SimpleTools::isDntgSpecialBird(bird->type_))
		batch_node1_->addChild(node, bird->item_ == BIRD_ITEM_ZORDER_0 ? this->getChildrenCount() : 1);
	else
		batch_node2_->addChild(node, bird->item_ == BIRD_ITEM_ZORDER_0 ? this->getChildrenCount() : 1);

	node->setPosition(toCCP(bird->position_));
	node->bird = bird;
	bird->shadow_ = shadow;
	bird->node_ = node;
	bird->effect_ = effect;

	if (bird->type_ == BIRD_TYPE_RED)
		node->setRed();

	// 创建动作
	CCActionInterval* act = CCSequence::create(
		CCDelayTime::create(bird->path_delay_),
		action,
		CCCallFuncND::create(this, callfuncND_selector(BirdLayer::func_bird_hide), bird),
		CCDelayTime::create(5),
		CCCallFuncND::create(this, callfuncND_selector(BirdLayer::func_bird_end), bird),
		0);

	CCAction* actSpeed = CCSpeed::create(act, 1);
	actSpeed->setTag(1000);
	node->runAction(actSpeed);
	actSpeed->step(0);
	actSpeed->step(bird->elapsed_);

	bird->move_action_id_ = actSpeed->getTag();
}

void BirdLayer::bird_dead(Bird* bird, bool isCleanup)
{
	//删除节点
	BirdNode* node = (BirdNode*)bird->node_;

	if (!isCleanup)
	{
		//创建死亡动画
		BirdNode * spt;
		if (SimpleTools::isDntgSpecialRoundBird(bird->type_))
		{
			spt = SpecialBirdNode::create(bird->item_);
			dynamic_cast<SpecialBirdNode *>(spt)->setBirdNum(bird->type_ - BIRD_TYPE_ONE + 1);
			///< 死亡特效
			spt->death();
			batch_node1_->addChild(spt, 10);
		}
		else if (SimpleTools::isDntgSpecialBird(bird->type_))
		{
			spt = BirdNode::create(bird->item_);
			///< 死亡特效
			spt->death();
			batch_node1_->addChild(spt, 10);
		}
		else if (bird->type_ <= 19)
		{
			spt = BirdNode::create(bird->type_);
			///< 死亡特效
			spt->death();
			batch_node1_->addChild(spt, 10);
		}
		else
		{
			spt = BirdNode::create(bird->type_);
			///< 死亡特效
			spt->death();
			batch_node2_->addChild(spt, 10);
		}

		spt->autoScale();

		spt->setRotation(node->getRotation());
		spt->setPosition(node->getPosition());

		///< 抖动特效
		spt->runAction(Shake::create(__BIRD_SHAKE_TIME__, __BIRD_SHAKE_RANGE__, __BIRD_SHAKE_RANGE__));
		//sp->runAction(spawn);   3.0秒后删除
		CCSequence* act = CCSequence::create(
			DelayTime::create(__BIRD_SHAKE_TIME__),
			CCCallFuncND::create(this, callfuncND_selector(BirdLayer::func_bird_dead_end), 0),
			0);
		//spt->setScale(1.5);

		if (!SimpleTools::isDntgSpecialRoundBird(bird->type_))
			spt->setScale(1.25);
		spt->runAction(act);

		if (bird->type_ >= 16 && bird->type_ < 26 && !SimpleTools::isDntgSpecialBird(bird->type_))
		{
			BirdDeathAction * FishRotate = BirdDeathAction::create(1.6f);
			spt->runAction(FishRotate);
			spt->setScale(1.25);
		}

		///< 检测红鱼
		if (bird->type_ == BIRD_TYPE_RED)
		{
			spt->setColor(Color3B::RED);
		}
	}

	//删除特效
	CCSprite* effect = (CCSprite*)bird->effect_;
	if (effect)
	{
		effect->runAction(Shake::create(__BIRD_SHAKE_TIME__, __BIRD_SHAKE_RANGE__, __BIRD_SHAKE_RANGE__));
		CCSequence* act = CCSequence::create(
			DelayTime::create(__BIRD_SHAKE_TIME__),
			CCCallFuncND::create(this, callfuncND_selector(BirdLayer::func_bird_effect_end), 0),
			0);
		effect->runAction(act);

	}

	ObjectPool::shared()->destroyBirdNode(node);
	ObjectPool::shared()->destroyBirdNode((BirdNode*)bird->shadow_);
}

void BirdLayer::set_ding_bird(bool ding)
{
	CCLOG("is ding ~~~~ %d", ding);
	dinged_ = ding;
}

void BirdLayer::func_bird_hide(cocos2d::Node* node, void* data)
{

	//标记死亡
	Bird* bird = (Bird*)data;
	bird->live_ = 0;

	//隐藏显示
	node->setVisible(false);
	if (bird->shadow_)
		((BirdNode*)bird->shadow_)->setVisible(false);
	CCSprite* effect = (CCSprite*)bird->effect_;
	if (effect)
	{
		effect->setVisible(false);
	}
}

void BirdLayer::func_bird_end(cocos2d::Node* node, void* data)
{
	Bird* bird = (Bird*)data;
	ObjectPool::shared()->destroyBirdNode((BirdNode*)node);
	ObjectPool::shared()->destroyBirdNode((BirdNode*)bird->shadow_);
	///< 删除指定
	((BirdNode *)node)->autoCallBack();
	//删除特效
	CCSprite* effect = (CCSprite*)bird->effect_;
	if (effect)
	{
		effect->stopAllActions();
		effect->removeFromParentAndCleanup(true);
	}

	// 移除鱼
	
	if (CGameFrameEngine::Get()->GetGameFrameEngineSink())
	{
		CGameSceneEngine* pGameSceneSink = (CGameSceneEngine*)(CGameFrameEngine::Get()->GetGameFrameEngineSink()->GetGameSceneSink());
		if (pGameSceneSink)
		{
			pGameSceneSink->destoryBird(bird);
		}
	}
	

	//SoundManager::shared()->playSound("jinbi");
}

void BirdLayer::func_bird_dead_end(cocos2d::Node* node, void* data)
{
	CCSprite* deadSpt = (CCSprite*)node;

	node->pauseSchedulerAndActions();
	deadSpt->removeFromParentAndCleanup(true);
}

void BirdLayer::showLightLineConnection(cocos2d::Vec2 start_p, std::vector<cocos2d::Vec2> other_p, int bird_type)
{
	Sprite * show_text_3 = nullptr;
	if (bird_type == BIRD_TYPE_CHAIN)
	{
		//show_text_3 = SimpleTools::getLightAction(0.8f, start_p, other_p, LINETYPE::BLUE);
		show_text_3 = SimpleTools::getLightAction(0.4f, start_p, other_p, LINETYPE::BLUE);
	}
	if (bird_type == BIRD_TYPE_RED)
	{
		//show_text_3 = SimpleTools::getLightAction(0.8f, start_p, other_p, LINETYPE::YELLOW);
		show_text_3 = SimpleTools::getLightAction(0.4f, start_p, other_p, LINETYPE::YELLOW);
	}

	CCSequence* act = CCSequence::create(
		DelayTime::create(1.6f), // 播放动画结束 
		FadeOut::create(0.4f),
		CCCallFuncND::create(this, callfuncND_selector(BirdLayer::func_bird_dead_end), 0),
		0);
	show_text_3->runAction(act);
	this->addChild(show_text_3, 100);
}

void BirdLayer::func_light_line_end(cocos2d::Node* node, void* data)
{
	CCSprite* deadSpt = (CCSprite*)node;
	if (node)
	{
		node->pauseSchedulerAndActions();
		deadSpt->removeFromParentAndCleanup(true);
	}
}

void BirdLayer::func_bird_effect_end(cocos2d::Node* node, void* data)
{

	node->stopAllActions();
	node->removeFromParentAndCleanup(true);
}

BirdLayer * BirdLayer::create()
{
	BirdLayer * layer = new BirdLayer;
	if (layer && layer->init())
	{
		layer->autorelease();
		return layer;
	}
	delete layer;
	layer = nullptr;
	return nullptr;
}
