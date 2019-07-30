#include "DntgUIRankList.h"
#include "tools/tools/MTNotification.h"
#include "DntgGoDataProxy.h"
#include "tools/dialog/Timer.h"
#include "tools/tools/StringData.h"
#include "platform/PlatformHeader.h"
#include "kernel/game/IClientKernel.h"
#include "DntgHeader.h"
#include "tools/ViewHeader.h"
#include "tools/tools/Convert.h"
USING_NS_CC;
USING_NS_CC_EXT;
using namespace Dntg;
UIRankList* __gDntgRankList = 0;

//////////////////////////////////////////////////////////////////////////
#define PLIST_PATH		"gamescene/ranklist/ranklist.plist"
#define TEXTURE_PATH	"gamescene/ranklist/ranklist.pvr.ccz"

#define IMG_RANK_BG		"ranklist_bg.png"
#define FNT_RANK_1		"gamescene/ranklist/RankNumber1.fnt"
#define FNT_RANK_2		"gamescene/ranklist/RankNumber2.fnt"


//////////////////////////////////////////////////////////////////////////
UIRankList* UIRankList::create()
{
	UIRankList* obj = new UIRankList();

	if (obj && obj->init())
	{
		obj->autorelease();
		return obj;
	}

	delete obj;
	return 0;
}

UIRankList* UIRankList::shared()
{
	return __gDntgRankList;
}
//////////////////////////////////////////////////////////////////////////
UIRankList::UIRankList()
{
}

UIRankList::~UIRankList()
{
	__gDntgRankList = 0;
	G_NOTIFY_UNREG("RANK_LIST");
	G_NOTIFY_UNREG("RANK_INFO");
	CCSpriteFrameCache::sharedSpriteFrameCache()->removeSpriteFramesFromFile(PLIST_PATH);
	CCTextureCache::sharedTextureCache()->removeTextureForKey(TEXTURE_PATH);
}

//初始化方法
bool UIRankList::init()
{
	do
	{
		CC_BREAK_IF(!CCNode::init());
		CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(PLIST_PATH);

		CCSprite* bg = CCSprite::createWithSpriteFrameName(IMG_RANK_BG);
		addChild(bg);

		float x = -180;
		float y = 70;
		for (int i = 0; i < 10; ++i)
		{
			int size = i < 3 ? 30 : 24;
			mLbNames[i] = Label::create("nicknamenickname", "Arial", size - 4, cocos2d::Size(170, size), kCCTextAlignmentLeft, kCCVerticalTextAlignmentCenter);
			mLbNames[i]->setPosition(cocos2d::Vec2(x, y));
			addChild(mLbNames[i]);

			mLbScores[i] = Label::createWithBMFont(i < 3 ? FNT_RANK_1 : FNT_RANK_2, "0123456789");
			mLbScores[i]->setAnchorPoint(cocos2d::Vec2(0, 0.5f));
			mLbScores[i]->setPosition(cocos2d::Vec2(x + 100, y - (i < 3 ? 8 : 10)));
			addChild(mLbScores[i]);


			mLbDescs[i] = Label::create("descdescdsec", "Arial", size - 4, cocos2d::Size(200, size), kCCTextAlignmentLeft, kCCVerticalTextAlignmentCenter);
			mLbDescs[i]->setPosition(cocos2d::Vec2(x + 200 + 220, y));
			addChild(mLbDescs[i]);
			y -= i < 2 ? 37 : 28;
		}

		mLbTime = Label::create("", "Arial", 18, cocos2d::Size(165, 20), kCCTextAlignmentLeft, kCCVerticalTextAlignmentCenter);
		mLbTime->setColor(ccc3(255, 0, 0));
		mLbTime->setPosition(cocos2d::Vec2(-95, 170));
		addChild(mLbTime);

		mLbCurRank = Label::create(SSTRING("System_Tips_24"), "Arial", 18, cocos2d::Size(165, 20), kCCTextAlignmentLeft, kCCVerticalTextAlignmentCenter);
		mLbCurRank->setPosition(cocos2d::Vec2(-80, -240));
		addChild(mLbCurRank);

		mLbCurScore = Label::createWithBMFont(FNT_RANK_2, "0123456789");
		mLbCurScore->setAnchorPoint(cocos2d::Vec2(0, 0.5));
		mLbCurScore->setPosition(cocos2d::Vec2(90, -240 - 10));
		addChild(mLbCurScore);

		updateRankInfo();
		updateRankList();

		G_NOTIFY_REG("RANK_LIST", UIRankList::onRankListNotify);
		G_NOTIFY_REG("RANK_INFO", UIRankList::onRankInfoNotify);

		static CoTimer update_timer;

		if (update_timer.isTimeUp())
		{
			update_timer.init(5000);
			//发送消息
			IClientKernel* kernel = IClientKernel::get();
			if (kernel)
				kernel->SendSocketData(MDM_GF_GAME, SUB_C_RANK_LIST, 0, 0);
		}

		__gDntgRankList = this;

		return true;
	} while (0);

	return false;
}

void UIRankList::updateRankList()
{
	for (int i = 0; i < 10; ++i)
	{
		bool hasItem = i < GoDataProxy::shared()->getRankListCount();
		mLbNames[i]->setVisible(hasItem);
		mLbScores[i]->setVisible(hasItem);

		char sDesc[64] = { 0 };
		sprintf(sDesc, "%s%s", FormatMoney(GoDataProxy::shared()->getRankScores(i)).c_str(), SSTRING("rank_award_type"));
		mLbDescs[i]->setString(sDesc);

		if (hasItem)
		{
			const tagRankItem& item = GoDataProxy::shared()->getRankListItem(i);
			mLbNames[i]->setString(u2_8(item.szNickname));
			mLbScores[i]->setString(FormatMoney(item.lScore).c_str());
		}
	}

	int iRank = GoDataProxy::shared()->getSelfRank();
	char sRank[32] = { 0 };
	if (iRank == -1)
	{
		sprintf(sRank, ">%d", GameConfig::getInstance().get_max_rank());
	}
	else
	{
		sprintf(sRank, SSTRING("System_Tips_25"), iRank + 1);
	}

	mLbCurRank->setString(sRank);

	mLbTime->setString(FormatTime(GoDataProxy::shared()->getRankRefresh()));
}

void UIRankList::updateRankInfo()
{
	mLbCurScore->setString(FormatMoney(GoDataProxy::shared()->getRankScore()).c_str());
}

void UIRankList::onRankInfoNotify(cocos2d::Ref* obj)
{
	updateRankInfo();
}

void UIRankList::onRankListNotify(cocos2d::Ref* obj)
{
	updateRankList();
}
