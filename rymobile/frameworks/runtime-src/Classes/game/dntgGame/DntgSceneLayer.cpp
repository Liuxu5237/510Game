#include "DntgSceneLayer.h"
#include "tools/manager/SpriteHelper.h"
#include "DntgBirdDefine.h"

USING_NS_CC;
//////////////////////////////////////////////////////////////////////////
using namespace Dntg;
//////////////////////////////////////////////////////////////////////////
SceneLayer::SceneLayer()
{
	scene_ = 0;
}

SceneLayer::~SceneLayer()
{
}

//初始化方法
bool SceneLayer::init()
{
	do
	{
		CC_BREAK_IF(!CCLayer::init());

		Size winSize = CCDirector::getInstance()->getWinSize();

		float cx = winSize.width / 2;
		float cy = winSize.height / 2;


		CCSpriteFrameCache* cache = CCSpriteFrameCache::sharedSpriteFrameCache();
		spr_background_ = CCSprite::createWithSpriteFrame(cache->spriteFrameByName("SceneBack0.png"));
		spr_background_->setAnchorPoint(cocos2d::Vec2(0, 0));
		spr_background_->setScale(1.1f);
		addChild(spr_background_);

		spr_background2_ = CCSprite::createWithSpriteFrame(cache->spriteFrameByName("SceneBack0.png"));
		spr_background2_->setAnchorPoint(cocos2d::Vec2(0, 0));
		spr_background2_->setVisible(false);
		spr_background2_->setScale(1.1f);
		addChild(spr_background2_);


		//spr_water_wave_ = CCSprite::createWithSpriteFrameName("WaterWave0.png");
		//spr_water_wave_->runAction(CCRepeatForever::create(SpriteHelper::createAnimate("WaterWave")));
		//spr_water_wave_->setAnchorPoint(cocos2d::Vec2(0, 0));
		//spr_water_wave_->setScaleX(winSize.width/(float)spr_water_wave_->displayFrame()->getOriginalSize().width);
		//spr_water_wave_->setScaleY(winSize.height/(float)spr_water_wave_->displayFrame()->getOriginalSize().height);
		//addChild(spr_water_wave_);


		spr_cloud_ = CCSprite::create();
		auto animate = SpriteHelper::createAnimate("Cloud");
		CCASSERT(animate, "animate is null");
		spr_cloud_->runAction(CCRepeatForever::create(animate));
		spr_cloud_->setPosition(cocos2d::Vec2(cx, cy));
		spr_cloud_->setVisible(false);
		addChild(spr_cloud_);

		//change by xy

		spr_water_wave_1 = Sprite::createWithSpriteFrameName("waterAni_0.png");
		spr_water_wave_1->setPosition(cocos2d::Vec2(cx, cy));
		cocos2d::Animate* action_1 = SceneLayer::animationWithFrame("waterAni_", 0, 7, 0.2f);
		spr_water_wave_1->setAnchorPoint(cocos2d::Vec2(1, 0));
		spr_water_wave_1->setScale(1.0f);
		spr_water_wave_1->runAction(action_1);
		addChild(spr_water_wave_1, 100);

		spr_water_wave_2 = Sprite::createWithSpriteFrameName("waterAni_0.png");
		spr_water_wave_2->setPosition(cocos2d::Vec2(cx, cy));
		cocos2d::Animate* action_2 = SceneLayer::animationWithFrame("waterAni_", 0, 7, 0.2f);
		spr_water_wave_2->setAnchorPoint(cocos2d::Vec2(1, 1));
		spr_water_wave_2->setScale(1.0f);
		spr_water_wave_2->runAction(action_2);
		addChild(spr_water_wave_2, 100);

		spr_water_wave_3 = Sprite::createWithSpriteFrameName("waterAni_0.png");
		spr_water_wave_3->setPosition(cocos2d::Vec2(cx, cy));
		cocos2d::Animate* action_3 = SceneLayer::animationWithFrame("waterAni_", 0, 7, 0.2f);
		spr_water_wave_3->setAnchorPoint(cocos2d::Vec2(0, 0));
		spr_water_wave_3->setScale(1.0f);
		spr_water_wave_3->runAction(action_3);
		addChild(spr_water_wave_3, 100);

		spr_water_wave_4 = Sprite::createWithSpriteFrameName("waterAni_0.png");
		spr_water_wave_4->setPosition(cocos2d::Vec2(cx, cy));
		cocos2d::Animate* action_4 = SceneLayer::animationWithFrame("waterAni_", 0, 7, 0.2f);
		spr_water_wave_4->setAnchorPoint(cocos2d::Vec2(0, 1));
		spr_water_wave_4->setScale(1.0f);
		spr_water_wave_4->runAction(action_4);
		addChild(spr_water_wave_4, 100);

		return true;
	} while (0);

	return false;
}

Animate* SceneLayer::animationWithFrame(const char *frameName, int beginNun, int endNum, float delay)
{
	SpriteFrame* frame = NULL;
	Animation* animation = Animation::create();
	for (int index = beginNun; index <= endNum; index++)
	{
		String * name = String::createWithFormat("%s%d.png", frameName, index);
		frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(name->getCString());
		animation->addSpriteFrame(frame);
	}
	animation->setDelayPerUnit(delay);
	animation->setRestoreOriginalFrame(true);
	animation->setLoops(-1);

	Animate* animate = Animate::create(animation);

	return animate;
}

void SceneLayer::set_scene(int scene)
{
	scene_ = scene;
	//change by xy
	if (scene_ > 3){
		scene_ = 0;
	}
	//change end
	char sceneback[64] = { 0 };
	sprintf(sceneback, "SceneBack%d.png", scene_);
	spr_background_->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(sceneback));
	spr_background_->setScale(1.1f);

	spr_cloud_->setPosition(cocos2d::Vec2(1272, spr_cloud_->getPosition().y));
	spr_cloud_->setVisible(false);
	spr_cloud_->pauseSchedulerAndActions();
	//change end
	spr_background2_->stopAllActions();
	spr_background2_->setVisible(false);
}

void SceneLayer::chang_scene(int scene)
{
	if (scene_ == scene)
	{
		log("two scene is equit ! scene is %d", scene);
		return;
	}


	scene_ = scene;


	spr_cloud_->setPosition(cocos2d::Vec2(kGameRevolutionWidth + 256, spr_cloud_->getPosition().y)); /*02*/
	spr_cloud_->setVisible(true);
	spr_cloud_->resumeSchedulerAndActions();

	//change end
	CCSequence* act = CCSequence::create(
		CCDelayTime::create(1),
		CCMoveTo::create(8, cocos2d::Vec2(-256, spr_cloud_->getPosition().y)),
		CCCallFuncN::create(this, callfuncN_selector(SceneLayer::change_scene_end)),
		0);

	spr_cloud_->runAction(act);
	//change by xy
	if (scene_ > 3){
		scene_ = 0;
	}
	//change end
	char sceneback[64] = { 0 };
	sprintf(sceneback, "SceneBack%d.png", scene_);
	spr_background2_->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(sceneback));
	spr_background2_->setVisible(true);
	spr_background2_->setPositionX(spr_cloud_->getPosition().x - 140);
	CCSequence* act2 = CCSequence::create(
		CCDelayTime::create(1),
		CCMoveTo::create(6.5f, cocos2d::Vec2(0, spr_background2_->getPosition().y)),
		0);

	spr_background2_->runAction(act2);

	//	this->scheduleUpdate();
}

void SceneLayer::update(float delta)
{
	float x = spr_cloud_->getPosition().x - 140;

	if (x < 0)
		x = 0;
	spr_background2_->setPosition(cocos2d::Vec2(x, spr_background2_->getPosition().y));
}
void SceneLayer::change_scene_end(cocos2d::Node* node)
{
	set_scene(scene_);
	//	this->unscheduleUpdate();
}
