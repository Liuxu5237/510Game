#include "DntgCoinLayer.h"
#include "tools/tools/MTNotification.h"
#include "DntgHeader.h"
#include "tools/manager/SpriteHelper.h"
#include "tools/manager/SoundManager.h"
#include "platform/GlobalConfig.h"
#include "widget/TailorView.h"
#include "tools/manager/Move_Point_Manager.h"

using namespace Dntg;
//////////////////////////////////////////////////////////////////////////
CoinLayer::CoinLayer()
{
	mSptAlarm = 0;
	mMsgContentIndex = 0;
}

CoinLayer::~CoinLayer()
{
	G_NOTIFY_UNREG("GLAD_MSG");
}

//初始化方法
bool CoinLayer::init()
{
	do
	{
		CC_BREAK_IF(!CCLayer::init());

		CCSize winSize = CCDirector::sharedDirector()->getWinSize();
		CCSpriteFrameCache* cache = CCSpriteFrameCache::sharedSpriteFrameCache();
		batch_node_ = CCSpriteBatchNode::createWithTexture(cache->spriteFrameByName("CoinMove0_01.png")->getTexture(), 128);
		addChild(batch_node_);

		G_NOTIFY_REG("GLAD_MSG", CoinLayer::onGladMessage);
		return true;
	} while (0);

	return false;
}

void CoinLayer::coin_label(const xPoint& pt_src, int font_index, int price, bool bmeChairID)
{
	font_index = 1;
	if (bmeChairID)font_index = 0;
	char font[64] = { 0 };
	sprintf(font, "bmfonts/fiskbit%d.fnt", font_index);
	CCLabelBMFont* label = CCLabelBMFont::create(toString(price), font);
	label->setScale(0.85);
	label->setPosition(toCCP(pt_src));
	this->addChild(label);

	CCSequence *act = CCSequence::create(
		CCDelayTime::create(0.2f),
		CCMoveTo::create(0.3f, toCCP(pt_src.x_, pt_src.y_ - 50)),
		CCFadeOut::create(0.6f),
		CCCallFuncND::create(this, callfuncND_selector(CoinLayer::func_coin_label_end), 0),
		0);

	label->runAction(act);
}

void CoinLayer::coin_move(int chair_id, int bird_type, const xPoint& pt_src, const xPoint& pt_dst)
{
	int coin_index = 1;
	int count = 0;
	if (bird_type<26) count = bird_type % 10 + 1;
	float coinSize = 0.7f;

	float size = 50;
	float x_offset = -size*(count > 5 ? 5 : count) / 2;
	float y_offset = -size*(count / 5 + 1) / 2;

	char ani_name[64] = { 0 };
	sprintf(ani_name, "CoinMove%d", coin_index);

	for (int i = 0; i < count; ++i)
	{
		int r = i / 5;
		int c = i % 5;

		xPoint pt_cur(pt_src.x_ + c * size + x_offset, pt_src.y_ + r * size + y_offset);
		float y = 100;
		if (chair_id > 2)
			y = -y;

		CCSprite* spt = CCSprite::createWithSpriteFrameName("CoinMove0_01.png");
		spt->setScale(coinSize);
		batch_node_->addChild(spt);
		spt->setPosition(toCCP(pt_src));
		spt->runAction(CCRepeatForever::create(SpriteHelper::createAnimate(ani_name)));
		spt->runAction(CCSequence::create(
			CCMoveTo::create(0.3f, toCCP(pt_cur.x_, pt_cur.y_)),
			CCMoveTo::create(0.3f, toCCP(pt_cur.x_, pt_cur.y_ + y)),
			CCMoveTo::create(0.15f, toCCP(pt_cur.x_, pt_cur.y_)),
			CCMoveTo::create(0.15f, toCCP(pt_cur.x_, pt_cur.y_ + y / 2)),
			CCMoveTo::create(0.5f + 0.1f*i, toCCP(pt_dst.x_, pt_dst.y_)),
			CCCallFuncND::create(this, callfuncND_selector(CoinLayer::func_coin_move_end), 0),
			0));
	}
}

void CoinLayer::big_fish_flash(const xPoint& pt, int price)
{
	CCLabelBMFont* label = CCLabelBMFont::create(toString(price), "bmfonts/BirdNumber3.fnt");
	label->setPosition(toCCP(pt));

	CCRepeatForever *act = CCRepeatForever::create(CCSequence::create(
		CCMoveTo::create(0.5, toCCP(pt.x_, pt.y_ + 20)),
		CCMoveTo::create(0.5, toCCP(pt)),
		0));

	label->setScale(0.8f);
	label->runAction(act);

	if (rand() % 2 == 1)
	{
		CCSprite* spt = CCSprite::createWithSpriteFrameName("Bingo_1.png");
		if (spt)
		{
			spt->setPosition(toCCP(pt));
			spt->runAction(CCSequence::create(
				CCFadeOut::create(0.01f),
				CCDelayTime::create(0.4f),
				CCFadeIn::create(0.1f),
				CCRotateBy::create(4, 360 * 3),
				CCCallFuncND::create(this, callfuncND_selector(CoinLayer::func_big_fish_flash_end), label),
				0));
			spt->setScale(0.7f);
			this->addChild(spt);
		}
		
	}
	else
	{
		CCSprite* spt = CCSprite::createWithSpriteFrameName("Bingo_2.png");
		if (spt)
		{
			spt->setPosition(toCCP(pt));
			spt->runAction(CCSequence::create(
				CCFadeOut::create(0.01f),
				CCDelayTime::create(0.4f),
				CCFadeIn::create(0.1f),
				CCRotateBy::create(4, 360 * 3),
				CCCallFuncND::create(this, callfuncND_selector(CoinLayer::func_big_fish_flash_end), label),
				0));
			spt->setScale(0.7f);
			this->addChild(spt);
		}
	}
	this->addChild(label);
	SoundManager::shared()->playSound("bingo");
}

void CoinLayer::add_award(int chair_id, const xPoint& pt_src, int award_type, int award_count)
{
	return;

	if (award_type < 0 || award_count <= 0)
	{
		return;
	}

	MTData* data = MTData::create();
	data->mData1 = chair_id;
	data->mData2 = award_type;
	data->mData3 = award_count;

	mAwardNum->setString(toString(award_count));
	mAwardBg->setOpacity(0);
	mAwardBg->setVisible(true);
	mAwardBg->runAction(CCSequence::create(
		CCFadeIn::create(0.3f),
		CCDelayTime::create(1.5f),
		CCFadeOut::create(0.3f),
		CCHide::create(),
		0));

}
void CoinLayer::effect_play(const xPoint& pt, int index, float time, float delay, float scale)
{
	//bool isCan = GlobalConfig::getInstance()->getIsSpecialEffect();
	//if (!isCan) return;
	char ani_name[64] = { 0 };
	sprintf(ani_name, "Effect%d", index);

	CCSprite* spt = CCSprite::create();
	spt->setPosition(toCCP(pt));
	spt->setScale(scale);
	this->addChild(spt);

	spt->runAction(CCSequence::create(
		DelayTime::create(delay),
		SpriteHelper::createEffectAnimate(ani_name, time),
		CCFadeOut::create(0.2f),
		CCCallFuncND::create(this, callfuncND_selector(CoinLayer::func_effect_end), 0),
		0));
}

void CoinLayer::ParSma_paly(const xPoint& pt, const std::string ParName, int count, int Opacity)
{
	for (int i = 0; i < count; i++)
	{
		Sprite * swordSprite = Sprite::createWithSpriteFrameName(ParName);
		if (swordSprite)
		{
			swordSprite->setScale(1.4f);
			swordSprite->setOpacity(Opacity);

			float angle = rand() % 360;
			swordSprite->setRotation(angle);
			this->addChild(swordSprite);

			float dre = CC_DEGREES_TO_RADIANS(angle);
			float x = 700 * sin(dre);
			float y = 700 * cos(dre);

			int sandDist = rand() % 200;
			float randPosX = sandDist * sin(dre);
			float randPosY = sandDist * cos(dre);
			swordSprite->setPosition(toCCP(pt) + Vec2(randPosX, randPosY));

			swordSprite->runAction(CCSequence::create(
				MoveBy::create(1.2f, Vec2(x, y)),
				CCCallFuncND::create(this, callfuncND_selector(CoinLayer::clearParticleSprite), 0),
				CCFadeOut::create(0.2f),
				0));

			swordSprite->runAction(CCSequence::create(
				ScaleTo::create(1.2f, 0.1f, 0.1f),
				0));
		}
	}
}
//炉子粒子展示
void CoinLayer::Particle_paly(const xPoint& pt, float time, const std::string ParName)
{
	for (int i = 0; i < 80; i++)
	{
		Sprite * swordSprite = Sprite::createWithSpriteFrameName(ParName);
		if (swordSprite)
		{
			swordSprite->setScale(0.01f);

			float angle = rand() % 360;
			swordSprite->setRotation(angle);
			this->addChild(swordSprite);

			float dre = CC_DEGREES_TO_RADIANS(angle);
			float x = 1500 * sin(dre);
			float y = 1500 * cos(dre);

			swordSprite->setPosition(toCCP(pt));

			swordSprite->runAction(CCSequence::create(
				DelayTime::create(time + i*0.02),
				MoveBy::create(3, Vec2(x, y)),
				CCCallFuncND::create(this, callfuncND_selector(CoinLayer::clearParticleSprite), 0),
				CCFadeOut::create(0.2f),
				0));

			swordSprite->runAction(CCSequence::create(
				DelayTime::create(time + i*0.02),
				ScaleTo::create(0.01f, 1.f, 1.f),
				0));
		}
	}
}
//爆炸粒子展示
void CoinLayer::Explosion_paly(const xPoint& pt, const std::string ParName, int count, float time, int randColor)
{

	for (int i = 0; i < count; i++)
	{
		Sprite * swordSprite = Sprite::createWithSpriteFrameName(ParName);
		if (swordSprite)
		{
			swordSprite->setScale(0.7f);

			switch (randColor)
			{
			case 0:
				swordSprite->setColor(ccc3(0, 127, 255));
				swordSprite->setOpacity(100);
				break;
			case 1:
				swordSprite->setOpacity(50);
				break;
			case 2:
				swordSprite->setColor(ccc3(255, 0, 255));
				break;
			default:
				break;
			}

			float angle = rand() % 360;
			swordSprite->setRotation(angle);
			this->addChild(swordSprite);

			float dre = CC_DEGREES_TO_RADIANS(angle);
			float x = 1200 * sin(dre);
			float y = 1200 * cos(dre);

			int sandDist = rand() % 300;
			float randPosX = sandDist * sin(dre);
			float randPosY = sandDist * cos(dre);
			swordSprite->setPosition(toCCP(pt) + Vec2(randPosX, randPosY));

			swordSprite->runAction(CCSequence::create(
				DelayTime::create(time),
				MoveBy::create(4, Vec2(x, y)),
				CCCallFuncND::create(this, callfuncND_selector(CoinLayer::clearParticleSprite), 0),
				CCFadeOut::create(0.2f),
				0));

			swordSprite->runAction(CCSequence::create(
				DelayTime::create(time),
				ScaleTo::create(4.f, 0.8f, 0.8f),
				0));
		}
	}
}
//定粒子展示
void CoinLayer::Ding_paly(const xPoint& pt, float time, const std::string ParName)
{
	for (int i = 0; i < 32; i++)
	{
		Sprite * swordSprite = Sprite::createWithSpriteFrameName(ParName);
		if (swordSprite)
		{
			swordSprite->setScale(0.01f);

			float angle = rand() % 360;
			//swordSprite->setRotation(angle);
			this->addChild(swordSprite);

			float dre = CC_DEGREES_TO_RADIANS(angle);
			float x = 250 * sin(dre);
			float y = 250 * cos(dre);

			int sandDist = rand() % 100;
			float randPosX = sandDist * sin(dre);
			float randPosY = sandDist * cos(dre);
			swordSprite->setPosition(toCCP(pt) + Vec2(randPosX, randPosY));

			swordSprite->runAction(CCSequence::create(
				DelayTime::create(time),
				MoveBy::create(3, Vec2(x, y)),
				CCCallFuncND::create(this, callfuncND_selector(CoinLayer::clearParticleSprite), 0),
				CCFadeOut::create(0.2f),
				0));

			swordSprite->runAction(CCSequence::create(
				DelayTime::create(time),
				ScaleTo::create(0.01f, 1.f, 1.f),
				0));
		}
	}
}
void CoinLayer::clearParticleSprite(cocos2d::Node* node, void* data)
{
	node->removeFromParent();
}

// 添加消息
void CoinLayer::add_msg(const std::string& msg)
{
	mMessageList.push_back(msg);

	if (mMessageList.size() == 1)
	{
		mMsgBackground->setVisible(true);
		mMsgBackground->setOpacity(0);
		mMsgBackground->stopAllActions();
		mMsgBackground->runAction(CCSequence::create(
			CCFadeIn::create(0.3f),
			CCCallFuncND::create(this, callfuncND_selector(CoinLayer::func_msg_show), 0),
			0));
	}
}

//////////////////////////////////////////////////////////////////////////

void CoinLayer::func_coin_label_end(cocos2d::Node *target, void* data)
{
	target->pauseSchedulerAndActions();
	target->removeFromParentAndCleanup(true);
}

void CoinLayer::func_coin_move_end(cocos2d::Node *target, void* data)
{
	target->pauseSchedulerAndActions();
	target->removeFromParentAndCleanup(true);
}

void CoinLayer::func_big_fish_flash_end(cocos2d::Node *target, void* data)
{
	target->pauseSchedulerAndActions();
	target->removeFromParentAndCleanup(true);

	target = (cocos2d::Node *)data;
	target->pauseSchedulerAndActions();
	target->removeFromParentAndCleanup(true);
}

void CoinLayer::func_award_move_end(cocos2d::Node *target, void* data)
{
	//target->pauseSchedulerAndActions();
	//target->removeFromParentAndCleanup(true);

	//IClientKernel* kernel = IClientKernel::get();

	//if (chair_id == kernel->GetMeChairID())
	//{// 奖牌数字
	//	xPoint pt;

	//	switch (award_type)
	//	{
	//	case 2:
	//	case 3:
	//		pt.set_point(225, 680);
	//		break;
	//	case 0:
	//		pt.set_point(560, 680);
	//		break;
	//	case 1:
	//		pt.set_point(435, 680);
	//		break;
	//	}

	//	CCLabelBMFont* label=CCLabelBMFont::create(("+" + toStringA(award_count)).c_str(), "bmfonts/AwardNumber.fnt");
	//	label->setPosition(toCCP(pt));
	//	this->addChild(label)

	//		CCSequence *act = new CCSequence(
	//		CCMoveTo::create(1.5, toCCP(pt.x_, pt.y_ - 50)),
	//		CCCallFuncND::create(this, callfuncND_selector(CoinLayer::func_award_label_end), 0), 
	//		0);
	//	label->runAction(act);		
	//}
}


void CoinLayer::func_award_label_end(cocos2d::Node *target, void* data)
{
	target->pauseSchedulerAndActions();
	target->removeFromParentAndCleanup(true);
}


void CoinLayer::func_effect_end(cocos2d::Node *target, void* data)
{
	target->pauseSchedulerAndActions();
	target->removeFromParentAndCleanup(true);
}

void CoinLayer::func_alarm_tips_end(cocos2d::Node *target, void* data)
{
	target->stopAllActions();
	target->setVisible(false);
}

void CoinLayer::func_msg_show(cocos2d::Node* target, void* data)
{
	msg_start_next(false);
}

void CoinLayer::func_msg_start_next(cocos2d::Node* target, void* data)
{
	msg_start_next(true);
}

void CoinLayer::msg_start_next(bool bRemoveFront)
{
	if (bRemoveFront && !mMessageList.empty())
		mMessageList.pop_front();

	if (mMessageList.empty())
	{
		//mMsgBackground->stopAllActions();
		//mMsgBackground->runAction(CCSequence::create(
		//	CCFadeOut::create(0.3f),
		//	CCHide::create(),
		//	0));
		return;
	}

	int index = mMsgContentIndex;
	mMsgContentIndex = (mMsgContentIndex + 1) % 2;
	Label* label = mMsgContents[index];

	CCSize cs = mTailor->getContentSize();

	label->setString(mMessageList.front().c_str());

	CCSize csMsg = label->getContentSize();
	if (cs.width >= csMsg.width)
	{
		label->setPosition(ccp(cs.width / 2, cs.height / 2 + 20));

		label->setVisible(true);
		//label->setOpacity(0);
		label->runAction(CCSequence::create(
			CCSpawn::create(CCFadeIn::create(0.2f), CCMoveTo::create(0.2f, ccp(cs.width / 2, cs.height / 2)), 0),
			CCDelayTime::create(3),
			CCCallFuncND::create(this, callfuncND_selector(CoinLayer::func_msg_start_next), 0),
			CCSpawn::create(CCFadeOut::create(0.2f), CCMoveTo::create(0.2f, ccp(cs.width / 2, cs.height / 2 - 20)), 0),
			CCHide::create(),
			0));
	}
	else
	{
		float lenMoveSpeed = 0.01f;
		float len = (csMsg.width - cs.width) / 2;
		label->setPosition(ccp(cs.width / 2 + len, cs.height / 2 + 20));

		label->setVisible(true);
		//label->setOpacity(0);
		label->runAction(CCSequence::create(
			CCSpawn::create(CCFadeIn::create(0.2f), CCMoveTo::create(0.2f, ccp(cs.width / 2 + len, cs.height / 2)), 0),
			CCDelayTime::create(2),
			CCMoveTo::create(lenMoveSpeed * len * 2, ccp(cs.width / 2 - len, cs.height / 2)),
			CCDelayTime::create(2),
			CCCallFuncND::create(this, callfuncND_selector(CoinLayer::func_msg_start_next), 0),
			CCSpawn::create(CCFadeOut::create(0.2f), CCMoveTo::create(0.2f, ccp(cs.width / 2 - len, cs.height / 2 - 20)), 0),
			CCHide::create(),
			0));
	}

}

//////////////////////////////////////////////////////////////////////////
// Notifcation

#define SET_COLOR(label, col)	label->setColor(ccc3(col>>16&0xff, col>>8&0xff, col&0xff))

void CoinLayer::onGladMessage(cocos2d::Ref* obj)
{
	EventCustom *event_ = (EventCustom*)obj;
	if (event_ == 0){
		return;
	}

	MTData* data = (MTData*)event_->getUserData();
	if (data == 0)
		return;


	int nLen = (int)data->mStr1.size();
	int iStrStart = 0;
	int iStrLen = 0;

	CCRichText* richText = CCRichText::create();
	richText->retain();
	float width = 0;
	float height = 0;

	for (int i = 0; i < nLen; ++i)
	{
		if (data->mStr1[i] == '%' && (i + 1 < nLen) && data->mStr1[i + 1] == 'n')
		{
			//conent
			Label* label = Label::create(data->mStr1.substr(iStrStart, iStrLen).c_str(), "Arial", 20);
			SET_COLOR(label, data->mData1);
			label->setAnchorPoint(ccp(0, 0.5));
			richText->addChild(label);
			width += label->getContentSize().width;
			height = tmax(height, label->getContentSize().height);

			//nickname
			label = Label::create(data->mStr2.c_str(), "Arial", 20);
			SET_COLOR(label, data->mData2);
			label->setAnchorPoint(ccp(0, 0.5));
			richText->addChild(label);
			width += label->getContentSize().width;
			height = tmax(height, label->getContentSize().height);

			i += 2;
			iStrStart = i;
			iStrLen = 1;
		}
		else if (data->mStr1[i] == '%' && (i + 1 < nLen) && data->mStr1[i + 1] == 's')
		{
			//conent
			Label* label = Label::create(data->mStr1.substr(iStrStart, iStrLen).c_str(), "Arial", 20);
			SET_COLOR(label, data->mData1);
			label->setAnchorPoint(ccp(0, 0.5));
			richText->addChild(label);
			width += label->getContentSize().width;
			height = tmax(height, label->getContentSize().height);

			//nickname
			label = Label::create(data->mStr3.c_str(), "Arial", 20);
			SET_COLOR(label, data->mData3);
			label->setAnchorPoint(ccp(0, 0.5));
			richText->addChild(label);
			width += label->getContentSize().width;
			height = tmax(height, label->getContentSize().height);

			i += 2;
			iStrStart = i;
			iStrLen = 1;
		}
		else
		{
			++iStrLen;
		}
	}

	if (iStrStart <= nLen - 1)
	{
		//conent
		Label* label = Label::create(data->mStr1.substr(iStrStart).c_str(), "Arial", 20);
		SET_COLOR(label, data->mData1);
		label->setAnchorPoint(ccp(0, 0.5));
		richText->addChild(label);
		width += label->getContentSize().width;
		height = tmax(height, label->getContentSize().height);

	}

	//add_msg(sRet);
	auto ary = richText->getChildren();
	float pos = -width / 2;
	for (int i = 0, l = (int)richText->getChildrenCount(); i < l; ++i)
	{
		Label* ttf = (Label*)ary.at(i);
		if (ttf)
		{
			ttf->setPosition(ccp(pos, 0));
			pos += ttf->getContentSize().width;
		}
	}
	richText->setContentSize(CCSizeMake(width, height));
	mMsgNodeList.push_back(richText);

	if (mMsgNodeList.size() == 1)
	{
		//mMsgBackground->setVisible(true);
		//mMsgBackground->setOpacity(0);
		//mMsgBackground->stopAllActions();
		//mMsgBackground->runAction(CCSequence::create(
		//	CCFadeIn::create(0.3f),
		//	CCCallFuncND::create(this,callfuncND_selector(CoinLayer::func_msg_show_n), 0), 
		//	0));
	}
}

void CoinLayer::func_msg_show_n(cocos2d::Node* target, void* data)
{
	msg_start_next_n(false);
}

void CoinLayer::func_msg_start_next_n(cocos2d::Node* target, void* data)
{
	msg_start_next_n(true);
}

void CoinLayer::msg_start_next_n(bool bRemoveFront)
{
	if (bRemoveFront && !mMsgNodeList.empty())
	{
		mMsgNodeList.front()->release();
		mMsgNodeList.pop_front();
	}

	if (mMsgNodeList.empty())
	{
		//mMsgBackground->stopAllActions();
		//mMsgBackground->runAction(CCSequence::create(
		//	CCFadeOut::create(0.3f),
		//	CCHide::create(),
		//	0));
		return;
	}

	CCRichText* richText = mMsgNodeList.front();
	mTailor->addChild(richText);

	CCSize cs = mTailor->getContentSize();

	CCSize csMsg = richText->getContentSize();
	if (cs.width >= csMsg.width)
	{
		richText->setPosition(ccp(cs.width / 2, cs.height / 2 + 20));

		richText->setVisible(true);
		richText->setOpacity(0);
		richText->runAction(CCSequence::create(
			CCSpawn::create(CCFadeIn::create(0.2f), CCMoveTo::create(0.2f, ccp(cs.width / 2, cs.height / 2)), 0),
			CCDelayTime::create(3),
			CCCallFuncND::create(this, callfuncND_selector(CoinLayer::func_msg_start_next_n), 0),
			CCSpawn::create(CCFadeOut::create(0.2f), CCMoveTo::create(0.2f, ccp(cs.width / 2, cs.height / 2 - 20)), 0),
			CCHide::create(),
			CCRemoveSelf::create(true),
			0));
	}
	else
	{
		float lenMoveSpeed = 0.01f;
		float len = (csMsg.width - cs.width) / 2;
		richText->setPosition(ccp(cs.width / 2 + len, cs.height / 2 + 20));

		richText->setVisible(true);
		richText->setOpacity(0);
		richText->runAction(CCSequence::create(
			CCSpawn::create(CCFadeIn::create(0.2f), CCMoveTo::create(0.2f, ccp(cs.width / 2 + len, cs.height / 2)), 0),
			CCDelayTime::create(2),
			CCMoveTo::create(lenMoveSpeed * len * 2, ccp(cs.width / 2 - len, cs.height / 2)),
			CCDelayTime::create(2),
			CCCallFuncND::create(this, callfuncND_selector(CoinLayer::func_msg_start_next_n), 0),
			CCSpawn::create(CCFadeOut::create(0.2f), CCMoveTo::create(0.2f, ccp(cs.width / 2 - len, cs.height / 2 - 20)), 0),
			CCHide::create(),
			CCRemoveSelf::create(true),
			0));
	}

}

	