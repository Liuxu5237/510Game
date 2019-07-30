#include "DntgCoinsNode.h"

USING_NS_CC;
//////////////////////////////////////////////////////////////////////////
using namespace Dntg;

//////////////////////////////////////////////////////////////////////////
CoinsNode* CoinsNode::create()
{
	CoinsNode* node = new CoinsNode();
	if (node && node->init())
	{
		node->autorelease();
		return node;
	}

	delete node;
	return 0;
}
//////////////////////////////////////////////////////////////////////////

 bool CoinsNode::m_bShow = false;


CoinsNode::CoinsNode()
{

}

CoinsNode::~CoinsNode()
{

}


bool CoinsNode::init()
{
	do
	{
		CC_BREAK_IF(!CCNode::init());

		SpriteFrameCache* cache = SpriteFrameCache::sharedSpriteFrameCache();
		mBatchNode = CCSpriteBatchNode::createWithTexture(cache->spriteFrameByName("JinbiShow.png")->getTexture(), MAX_COIN);
		addChild(mBatchNode);

		for (int j = 0; j < MAX_COIN; j++)
		{
			spr_coin_[j] = CCSprite::createWithSpriteFrameName("JinbiShow.png");
			spr_coin_[j]->setAnchorPoint(cocos2d::Vec2(0.5, 0));
			spr_coin_[j]->setVisible(false);
			spr_coin_[j]->setPosition(Vec2(0, 5 * j - 15));
			mBatchNode->addChild(spr_coin_[j]);
		}

		label_coin_ = Label::createWithBMFont("bmfonts/zhuzi0.fnt", "10");
		//label_coin_->setAnchorPoint(cocos2d::Vec2(0.5, 0));
		label_coin_->setVisible(false);
		addChild(label_coin_);


		//label_coinSwitch_ = Label::createWithBMFont("bmfonts/zhuzi1.fnt", "10");
		//label_coinSwitch_->setVisible(false);
		//addChild(label_coinSwitch_);



		



		// 		for (int j = 0; j < MAX_COIN; j++)
		// 		{
		// 			spr_coin_[j]->setPosition(cocos2d::Vec2(0, 5 * j));
		// 		}
		// 
		// 		label_coin_ ->setPosition(cocos2d::Vec2(0, 5 * MAX_COIN));
		// 		label_coin_->setVisible(false);

		return true;
	} while (0);

	return false;
}

void CoinsNode::show_coin(int count, int score, int  chair_id_)
{
	if (count >= MAX_COIN)
	{
		count = MAX_COIN;
	}

	for (int i = 0; i < MAX_COIN; i++)
	{
		spr_coin_[i]->setVisible(false);
		spr_coin_[i]->stopAllActions();
	}


	m_mCharID = chair_id_;
	std::ostringstream ostr;
	ostr.str("");
	ostr << score;
	//if (m_bShowNodt)
	//{
		label_coin_->setString(ostr.str().c_str());
		label_coin_->setVisible(false);
		label_coin_->setPosition(cocos2d::Vec2(0, 5 * count + 8));
	//}
	//else
	//{
	//	label_coinSwitch_->setString(ostr.str().c_str());
	//	label_coinSwitch_->setVisible(false);
	//	label_coinSwitch_->setPosition(cocos2d::Vec2(0, 5 * count + 8));
	//}


	///< +的是字的高度
	
	
	for (int i = 0; i < count; i++)
	{
		CCSequence* act;

		if (i == count - 1)
		{
			act = CCSequence::create(
				CCDelayTime::create(0.3 + (i + 1) * 0.02f),
				CCShow::create(),
				CCCallFuncN::create(this, callfuncN_selector(CoinsNode::func_show)),
				0);
		}
		else
		{
			act = CCSequence::create(
				CCDelayTime::create(0.3 + (i + 1) * 0.02f),
				CCShow::create(),
				0);
		}

		spr_coin_[i]->runAction(act);
		//spr_coin_[i]->setVisible(true);
	}
}

void CoinsNode::func_show(cocos2d::Node* node)
{
	if (m_mCharID == 2 || m_mCharID == 1 || m_mCharID == 0)
	{
		//if (m_bShow)
	//	{
			label_coin_->setRotation(180);
			Vec2 CurPos = label_coin_->getPosition();
			CurPos.y -= 4;
			label_coin_->setPosition(CurPos);
		//}
	/*	else
		{
			label_coinSwitch_->setRotation(180);
			Vec2 CurPos = label_coinSwitch_->getPosition();
			CurPos.y -= 4;
			label_coinSwitch_->setPosition(CurPos);
		}

		m_bShow = !m_bShow;*/
		
	}

	if (label_coin_ != nullptr)
	{
		if (m_bShow)label_coin_->setBMFontFilePath("bmfonts/zhuzi0.fnt");
		else label_coin_->setBMFontFilePath("bmfonts/zhuzi1.fnt");

		m_bShow = !m_bShow;
		//label_coin_ = Label::createWithBMFont(, "10");
	/*	label_coin_->setPosition(CurPos);
		addChild(label_coin_);
		label_coin_->setw*/

	}
	

	//if (m_bShowNodt)
	 label_coin_->setVisible(true);
	//else label_coinSwitch_->setVisible(true);
}