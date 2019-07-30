#include "DntgNetLayer.h"
#include "tools/manager/SpriteHelper.h"
USING_NS_CC;
using namespace Dntg;
//////////////////////////////////////////////////////////////////////////
NetLayer::NetLayer()
{
}

NetLayer::~NetLayer()
{
}

//初始化方法
bool NetLayer::init()
{
	do
	{
		CC_BREAK_IF(!CCLayer::init());
		CCSpriteFrameCache* cache = CCSpriteFrameCache::sharedSpriteFrameCache();
		batch_node1_ = CCSpriteBatchNode::createWithTexture(cache->spriteFrameByName("Net1_01.png")->getTexture(), 128);
		addChild(batch_node1_);

		batch_node2_ = CCSpriteBatchNode::createWithTexture(cache->spriteFrameByName("Net1_01.png")->getTexture(), 128);
		addChild(batch_node2_);

		return true;
	} while (0);

	return false;
}

void NetLayer::net_open(int char_id, int net, const cocos2d::Vec2& pt)
{
	char name[64] = { 0 };
	sprintf(name, "Net%d", net);

	//创建网动画
	CCSprite* spt = CCSprite::create();
	spt->setDisplayFrameWithAnimationName(name, 0);
	spt->setPosition(pt);
	//spt->setScale(0.75f);
	if (net < 10)
		batch_node1_->addChild(spt, 1);
	else
		batch_node2_->addChild(spt, 1);

	CCSequence* act = CCSequence::create(
		SpriteHelper::createAnimate(name),
		CCCallFuncND::create(this, callfuncND_selector(NetLayer::func_net_end), 0),
		0);
	spt->runAction(act);
	//创建网阴影
	CCSprite* spt_shadow = CCSprite::create();
	spt_shadow->setDisplayFrameWithAnimationName(name, 0);
	spt_shadow->setPosition(Vec2(pt.x + 30, pt.y - 30));
	spt_shadow->setColor(ccc3(0, 0, 0));
	spt_shadow->setOpacity(0);
	spt_shadow->setScale(0.75f);
	spt_shadow->runAction(CCFadeTo::create(0.1f, 100));
	if (net < 10)
		batch_node1_->addChild(spt_shadow, 0);
	else
		batch_node2_->addChild(spt_shadow, 0);

	CCSequence* act_shadow = CCSequence::create(
		SpriteHelper::createAnimate(name),
		CCCallFuncND::create(this, callfuncND_selector(NetLayer::func_net_end), 0),
		0);
	spt_shadow->runAction(act_shadow);

}

void NetLayer::func_net_end(cocos2d::Node* node, void* data)
{
	node->stopAllActions();
	node->removeFromParentAndCleanup(true);
}