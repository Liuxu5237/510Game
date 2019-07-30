#include "tools/manager/SpriteHelper.h"
#include "DntgTaskLayer.h"
#include "tools/tools/MTNotification.h"
#include "tools/tools/StringData.h"
#include "tools/ViewHeader.h"
#include "platform/data/GlobalUserInfo.h"

USING_NS_CC;

using namespace Dntg;
//////////////////////////////////////////////////////////////////////////
inline float getSpriteScaleSize(int bird_type) {

	float fs = 1;

	switch (bird_type)
	{
	case 0:		fs = 0.65f; break;
	case 1:		fs = 0.65f; break;
	case 2:		fs = 0.65f; break;
	case 3:		fs = 0.65f; break;
	case 4:		fs = 0.6f; break;
	case 5:		fs = 0.6f; break;
	case 6:		fs = 0.6f; break;
	case 7:		fs = 0.6f; break;
	case 8:		fs = 0.5f; break;
	case 9:		fs = 0.5f; break;
	case 10:	fs = 0.4f; break;
	case 11:	fs = 0.4f; break;
	case 12:	fs = 0.4f; break;
	case 13:	fs = 0.3f; break;
	case 14:	fs = 0.3f; break;
	case 15:	fs = 0.3f; break;
	case 16:	fs = 0.3f; break;
	case 17:	fs = 0.25f; break;
	case 18:	fs = 0.25f; break;
	case 19:	fs = 0.25f; break;
	case 20:	fs = 0.25f; break;
	case 21:	fs = 0.25f; break;
	case 22:	fs = 0.25f; break;
	case 23:	fs = 0.25f; break;
	case 24:	fs = 0.25f; break;
	default:
		fs = 0.4f;
	}
	return fs;
}

//////////////////////////////////////////////////////////////////////////
TaskLayer::TaskLayer() :mCharId_(0), mRoomCount(0), mChairCount(0)
{
}

TaskLayer::~TaskLayer()
{
}

//初始化方法
bool TaskLayer::init()
{
	do
	{
		CC_BREAK_IF(!CCLayer::init());

		CCSize winSize = CCDirector::sharedDirector()->getWinSize();
		float cx = winSize.width / 2;
		float cy = winSize.height / 2;
		//////////////////////////////////////////////////////////////////////////
		// 个人任务完成,
		///< 恭喜完成任务图片,还有海盗在亲!
		spr_task_complete_is_visible = false;
		spr_task_complete_bg = CCSprite::createWithSpriteFrameName("TaskCompleteBg.png");
		spr_task_complete_bg->setVisible(false);
		spr_task_complete_bg->setPosition(cocos2d::Vec2(cx, cy - 100));
		addChild(spr_task_complete_bg);

		spr_task_complete = CCSprite::create();
		spr_task_complete->setPosition(cocos2d::Vec2(33, 80));
		spr_task_complete->runAction(
			CCRepeatForever::create(SpriteHelper::createAnimate("TaskComplete")));
		spr_task_complete_bg->addChild(spr_task_complete);

		//////////////////////////////////////////////////////////////////////////
		// 个人任务开始
		///< 图片是击杀指定鱼类,完成任务可获得高额奖励
		spr_task_start_bg = CCSprite::createWithSpriteFrameName("TaskStartBg.png");
		spr_task_start_bg->setVisible(false);
		addChild(spr_task_start_bg);
		spr_task_start_bg->setPosition(cocos2d::Vec2(cx, cy - 100));

		spr_task_start_ani = CCSprite::create();
		spr_task_start_ani->setPosition(cocos2d::Vec2(32, 72));
		spr_task_start_bg->addChild(spr_task_start_ani);

		//////////////////////////////////////////////////////////////////////////
		// 个人任务
		///< 捕鱼任务~包括了鱼图片,时间,鱼数量,奖章
		spr_task_bg = CCSprite::createWithSpriteFrameName("Task.png");
		spr_task_bg->setVisible(false);
		addChild(spr_task_bg);
		spr_task_bg->setPosition(cocos2d::Vec2(125 + 20, cy - 65));

		spr_task_fish = CCSprite::create();
		spr_task_fish->setPosition(cocos2d::Vec2(80, 40));
		spr_task_fish->setRotation(90);
		spr_task_bg->addChild(spr_task_fish);
		spr_task_fish->setScale(getSpriteScaleSize(18));
		spr_task_fish->runAction(CCRepeatForever::create(SpriteHelper::createBirdAnimate(18)));

		lb_task_cur_num = Label::create("99", "Arial", 14);
		lb_task_cur_num->setColor(ccc3(255, 0, 0));
		lb_task_cur_num->setAnchorPoint(cocos2d::Vec2(1, 0.5f));
		lb_task_cur_num->setPosition(cocos2d::Vec2(160, 35));
		spr_task_bg->addChild(lb_task_cur_num);

		lb_task_target_num = Label::create("/ 99", "Arial", 14);
		lb_task_target_num->setColor(ccc3(255, 255, 0));
		lb_task_target_num->setAnchorPoint(cocos2d::Vec2(0, 0.5f));
		lb_task_target_num->setPosition(cocos2d::Vec2(165, 35));
		spr_task_bg->addChild(lb_task_target_num);

		lb_task_time_num = Label::create("00:00:00", "Arial", 14);
		lb_task_time_num->setColor(ccc3(0, 162, 255));
		lb_task_time_num->setAnchorPoint(cocos2d::Vec2(0, 0.5f));
		lb_task_time_num->setPosition(cocos2d::Vec2(20, 15));
		spr_task_bg->addChild(lb_task_time_num);

		lb_task_award_num = Label::create("1 medal", "Arial", 14);
		lb_task_award_num->setColor(ccc3(255, 255, 0));
		lb_task_award_num->setAnchorPoint(cocos2d::Vec2(1, 0.5f));
		lb_task_award_num->setPosition(cocos2d::Vec2(200, 15));
		spr_task_bg->addChild(lb_task_award_num);
		spr_task_bg->setScale(1.2f);
		mChairTimeLeft = 0;

		//////////////////////////////////////////////////////////////////////////
		// 房间任务完成
		///< 聚宝盆开启.很遗憾,被其他玩家捷足先登
		spr_room_task_complete_is_visible = false;
		spr_room_task_complete_bg = CCSprite::createWithSpriteFrameName("TaskRoomCompleteBg0.png");
		spr_room_task_complete_bg->setVisible(false);
		spr_room_task_complete_bg->setPosition(cocos2d::Vec2(cx, cy + 100));
		addChild(spr_room_task_complete_bg);

		//////////////////////////////////////////////////////////////////////////
		// 房间任务开始
		///< 聚宝盆开启,第一个完成指定任务的玩家~
		spr_room_task_start_bg = CCSprite::createWithSpriteFrameName("TaskRoomStartBg.png");
		spr_room_task_start_bg->setVisible(false);
		spr_room_task_start_bg->setPosition(cocos2d::Vec2(cx, cy + 100));
		addChild(spr_room_task_start_bg);


		//////////////////////////////////////////////////////////////////////////
		// 房间任务
		///< 聚宝盆任务,显示在左边,包括了要打的鱼,数量和完成数量,奖牌数
		spr_room_task_bg = CCSprite::createWithSpriteFrameName("TaskRoom.png");
		spr_room_task_bg->setVisible(false);
		addChild(spr_room_task_bg);
		spr_room_task_bg->setPosition(cocos2d::Vec2(125 + 20, cy + 65));

		spr_room_task_fish = CCSprite::create();
		spr_room_task_fish->setPosition(cocos2d::Vec2(80, 40));
		spr_room_task_fish->setRotation(90);
		spr_room_task_bg->addChild(spr_room_task_fish);
		spr_room_task_fish->setScale(getSpriteScaleSize(16));
		spr_room_task_fish->runAction(CCRepeatForever::create(SpriteHelper::createBirdAnimate(16)));

		lb_room_task_cur_num = Label::create("99", "Arial", 14);
		lb_room_task_cur_num->setColor(ccc3(255, 0, 0));
		lb_room_task_cur_num->setAnchorPoint(cocos2d::Vec2(1, 0.5f));
		lb_room_task_cur_num->setPosition(cocos2d::Vec2(160, 35));
		spr_room_task_bg->addChild(lb_room_task_cur_num);

		lb_room_task_target_num = Label::create("/ 99", "Arial", 14);
		lb_room_task_target_num->setColor(ccc3(255, 255, 0));
		lb_room_task_target_num->setAnchorPoint(cocos2d::Vec2(0, 0.5f));
		lb_room_task_target_num->setPosition(cocos2d::Vec2(165, 35));
		spr_room_task_bg->addChild(lb_room_task_target_num);

		lb_room_task_award_num = Label::create("1 medal", "Arial", 14);
		lb_room_task_award_num->setColor(ccc3(255, 255, 0));
		lb_room_task_award_num->setAnchorPoint(cocos2d::Vec2(1, 0.5f));
		lb_room_task_award_num->setPosition(cocos2d::Vec2(200, 15));
		spr_room_task_bg->addChild(lb_room_task_award_num);
		spr_room_task_bg->setScale(1.2f);

		spr_dragon_king_complete_gold = Sprite::createWithSpriteFrameName("img_TaskDragonKingCompleteDiamondBg.png");
		spr_dragon_king_complete_gold->setVisible(false);
		spr_dragon_king_complete_gold->setPosition(cocos2d::Vec2(cx, cy + 100));
		addChild(spr_dragon_king_complete_gold);

		lb_dragon_king_reward_money = ui::TextAtlas::create("0", "fonts/img_reword_number.png", 19, 27, "0");
		lb_dragon_king_reward_money->setAnchorPoint(Vec2(0, 1));
		lb_dragon_king_reward_money->setPosition(Vec2(420, 70));
		spr_dragon_king_complete_gold->addChild(lb_dragon_king_reward_money);

		return true;
	} while (0);

	return false;
}


void TaskLayer::task_start(CMD_S_Task_Open* task)
{
	switch (task->type_)
	{
	case TASK_PERSONAL_GOLD:	// 个人金币任务
		//chair_task_start(task);
		break;
	case TASK_PERSONAL_INGOT: // 个人元宝任务
		//chair_task_start(task);
		break;
	case TASK_EVERYONE_GOLD: // 全场金币任务
	//	room_task_start(task);
		break;
	case TASK_EVERYONE_INGOT: //全场元宝任务
	//	room_task_start(task);
		break;
	case TASK_DRAGON_GOLD: //四海龙王金币任务
		break;
	case TASK_DRAGON_INGOT: //四海龙王元宝任务
		break;
	}
}

void TaskLayer::chair_task_start(CMD_S_Task_Open* task)
{
	if (task->chair_id_ != mCharId_) return;
	// 隐藏任务
	spr_task_bg->setVisible(false);
	spr_task_bg->stopAllActions();
	spr_task_fish->stopAllActions();
	if (this->isScheduled(SEL_SCHEDULE(&TaskLayer::func_chair_time_tick)))
		this->unschedule(schedule_selector(TaskLayer::func_chair_time_tick));

	bool bVisible = task->time_ > 0;

	if (!bVisible)
	{
		return;
	}

	mChairCount = 0;

	spr_task_fish->setScale(getSpriteScaleSize(task->bird_type));
	spr_task_fish->runAction(CCRepeatForever::create(SpriteHelper::createBirdAnimate(task->bird_type)));

	spr_task_start_bg->stopAllActions();
	spr_task_start_ani->stopAllActions();
	spr_task_start_bg->setVisible(true);
	spr_task_start_ani->setVisible(false);

	float showDelay = spr_task_complete_is_visible ? 5.5f : 1.0;
	CCAction* act = CCSequence::create(
		CCDelayTime::create(showDelay),
		CCFadeIn::create(0.5f),
		CCCallFuncN::create(this, callfuncN_selector(TaskLayer::chair_task_start_show)),
		CCDelayTime::create(5),
		CCCallFuncN::create(this, callfuncN_selector(TaskLayer::chair_task_start_hide)),
		CCFadeOut::create(0.5f),
		CCCallFuncN::create(this, callfuncN_selector(TaskLayer::chair_task_start_end)),
		0);
	spr_task_start_bg->setOpacity(0);
	spr_task_start_bg->runAction(act);



	// 设置任务
	// 	int left = task->startTime + task->time * 1000 - task->curTime;
	// 	left	 = left / 1000;
	// 	mChairTimeLeft = left > 0 ? left : 0;
	mChairTimeLeft = task->time_;
	if (mChairTimeLeft > 0)
		this->schedule(schedule_selector(TaskLayer::func_chair_time_tick), 1);

	lb_task_cur_num->setString("0");
	lb_task_time_num->setString(FormatTime(mChairTimeLeft));

	char str[64] = { 0 };
	sprintf(str, "/ %02d", task->capture_count);
	lb_task_target_num->setString(str);

	char sAward[32] = { 0 };
	sprintf(sAward, "award%d", task->type_);
	sprintf(str, "%d %s", task->reward_, SSTRING(sAward));
	lb_task_award_num->setString(str);

}

void TaskLayer::room_task_start(CMD_S_Task_Open* task)
{
	// 隐藏任务
	spr_room_task_bg->setVisible(false);
	spr_room_task_bg->stopAllActions();
	spr_room_task_fish->stopAllActions();

	bool bVisible = task->bird_type >= 0;

	if (!bVisible)
	{
		return;
	}

	mRoomCount = 0;

	CCSize winSize = CCDirector::sharedDirector()->getWinSize();

	spr_room_task_fish->setScale(getSpriteScaleSize(task->bird_type));
	spr_room_task_fish->runAction(CCRepeatForever::create(SpriteHelper::createBirdAnimate(task->bird_type)));

	spr_room_task_start_bg->stopAllActions();
	spr_room_task_start_bg->setVisible(true);

	float showDelay = spr_room_task_complete_is_visible ? 2.5f : 1.0f;
	spr_room_task_start_bg->setPosition(cocos2d::Vec2(winSize.width + 500, winSize.height / 2));
	CCAction *act = CCSequence::create(
		CCDelayTime::create(showDelay),
		CCMoveTo::create(0.5f, cocos2d::Vec2(winSize.width / 2, winSize.height / 2)),
		CCDelayTime::create(2.0f),
		CCMoveTo::create(0.5f, cocos2d::Vec2(-500, winSize.height / 2)),
		CCCallFuncN::create(this, callfuncN_selector(TaskLayer::room_task_start_end)),
		0);

	spr_room_task_start_bg->runAction(act);

	lb_room_task_cur_num->setString("0");

	char str[64] = { 0 };
	sprintf(str, "/ %02d", task->capture_count);
	lb_room_task_target_num->setString(str);

	char sAward[32] = { 0 };
	sprintf(sAward, "award%d", task->type_);
	sprintf(str, "%d %s", task->reward_, SSTRING(sAward));
	lb_room_task_award_num->setString(str);
}

void TaskLayer::task_count(CMD_S_TaskCount* cmd)
{
	switch (cmd->type)
	{
	case TASK_PERSONAL_GOLD:	// 个人金币任务
	case TASK_PERSONAL_INGOT: // 个人元宝任务
	{
								  mChairCount += cmd->count;
								  lb_task_cur_num->setString(toString(mChairCount));
	}
		break;
	case TASK_EVERYONE_GOLD: // 全场金币任务
	case TASK_EVERYONE_INGOT: //全场元宝任务
	{
								  mRoomCount += cmd->count;
								  lb_room_task_cur_num->setString(toString(mRoomCount));
	}
		break;
	case TASK_DRAGON_GOLD: //四海龙王金币任务
		break;
	case TASK_DRAGON_INGOT: //四海龙王元宝任务
		break;
	}

	delete cmd;
}

void TaskLayer::task_complete(CMD_S_Task_Finish* cmd)
{
	switch (cmd->type_)
	{
	case TASK_PERSONAL_GOLD:	// 个人金币任务
		chair_task_complete(cmd);
		break;
	case TASK_PERSONAL_INGOT: // 个人元宝任务
		chair_task_complete(cmd);
		break;
	case TASK_EVERYONE_GOLD: // 全场金币任务
		room_task_complete(cmd);
		break;
	case TASK_EVERYONE_INGOT: //全场元宝任务
		room_task_complete(cmd);
		break;
	case TASK_DRAGON_GOLD: //四海龙王金币任务
	case TASK_DRAGON_INGOT: //四海龙王元宝任务
		dargon_task_complete(cmd);
		break;
	}
}

void TaskLayer::chair_task_complete(CMD_S_Task_Finish* cmd)
{
	if (cmd->reward_ > 0)
	{
		spr_task_complete_bg->stopAllActions();
		spr_task_complete_bg->setVisible(true);

		CCAction* act = CCSequence::create(
			CCFadeIn::create(0.5f),
			CCDelayTime::create(4.5f),
			CCFadeOut::create(0.5f),
			CCCallFuncN::create(this, callfuncN_selector(TaskLayer::chair_task_complete_end)),
			0);

		spr_task_complete_bg->setOpacity(0);
		spr_task_complete_bg->runAction(act);
		spr_task_complete_is_visible = true;
	}

	// 隐藏任务
	spr_task_bg->setVisible(false);
}


void TaskLayer::room_task_complete(CMD_S_Task_Finish* cmd)
{
	spr_room_task_complete_bg->stopAllActions();

	if (cmd->chair_id_ != mCharId_)
	{
		spr_room_task_complete_bg->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("TaskRoomCompleteBg0.png"));
	}
	else
	{
		spr_room_task_complete_bg->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("TaskRoomCompleteBg1.png"));
	}

	spr_room_task_complete_bg->setVisible(true);

	CCAction *act = CCSequence::create(
		CCFadeOut::create(0.01f),
		CCFadeIn::create(0.5f),
		CCDelayTime::create(2),
		CCFadeOut::create(0.5f),
		CCCallFuncN::create(this, callfuncN_selector(TaskLayer::room_task_complete_end)),
		0);
	spr_room_task_complete_bg->setOpacity(0);
	spr_room_task_complete_bg->runAction(act);
	spr_room_task_complete_is_visible = true;

	// 隐藏任务
	spr_room_task_bg->setVisible(false);
}

void TaskLayer::chair_task_start_show(cocos2d::Node* node)
{
	spr_task_start_ani->setVisible(true);
	spr_task_start_ani->runAction(SpriteHelper::createAnimate("TaskStartAni"));
}

void TaskLayer::chair_task_start_hide(cocos2d::Node* node)
{
	spr_task_start_ani->setVisible(false);
}

void TaskLayer::chair_task_start_end(cocos2d::Node* node)
{
	spr_task_start_bg->stopAllActions();
	spr_task_start_ani->stopAllActions();
	spr_task_start_bg->setVisible(false);

	// 显示任务
	spr_task_bg->setVisible(true);
	spr_task_bg->setOpacity(0);
	spr_task_bg->runAction(CCFadeIn::create(0.5f));
}

void TaskLayer::chair_task_complete_end(cocos2d::Node* node)
{
	spr_task_complete_bg->setVisible(false);
	spr_task_complete_bg->stopAllActions();
	spr_task_complete_is_visible = false;
}

void TaskLayer::room_task_start_end(cocos2d::Node* node)
{
	spr_room_task_start_bg->stopAllActions();
	spr_room_task_start_bg->setVisible(false);

	// 显示任务
	spr_room_task_bg->setVisible(true);
	spr_room_task_bg->setOpacity(0);
	spr_room_task_bg->runAction(CCFadeIn::create(0.5f));
}

void TaskLayer::room_task_complete_end(cocos2d::Node* node)
{
	spr_room_task_complete_bg->stopAllActions();
	spr_room_task_complete_bg->setVisible(false);
	spr_room_task_complete_is_visible = false;
}


void TaskLayer::func_chair_time_tick(float dt)
{
	--mChairTimeLeft;

	if (mChairTimeLeft < 0)
	{
		this->unschedule(SEL_SCHEDULE(&TaskLayer::func_chair_time_tick));
		///< 隐藏对应面板
		spr_task_bg->setVisible(false);
		return;
	}
	lb_task_time_num->setString(FormatTime(mChairTimeLeft));
}

void TaskLayer::dargon_task_complete(CMD_S_Task_Finish* cmd)
{
	if (cmd->reward_ > 0 && cmd->chair_id_ == mCharId_)
	{
		if (cmd->type_ == TASK_DRAGON_GOLD)
		{
			spr_dragon_king_complete_gold->setSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("img_TaskDragonKingCompleteGoldBg.png"));
		}
		else if (cmd->type_ == TASK_DRAGON_INGOT)
		{
			spr_dragon_king_complete_gold->setSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("img_TaskDragonKingCompleteDiamondBg.png"));
		}

		lb_dragon_king_reward_money->setString(StringUtils::format("%ld", cmd->reward_));

		spr_dragon_king_complete_gold->setVisible(true);

		CCAction *act = CCSequence::create(
			CCFadeOut::create(0.01f),
			CCFadeIn::create(0.5f),
			CCDelayTime::create(2),
			CCFadeOut::create(0.5f),
			CCCallFuncN::create(this, callfuncN_selector(TaskLayer::dargon_task_complete_end)),
			0);
		spr_dragon_king_complete_gold->setOpacity(0);
		spr_dragon_king_complete_gold->runAction(act);

		///< 把元宝加入!!
		CGlobalUserInfo * pGlobalUserInfo = CGlobalUserInfo::GetInstance();
		pGlobalUserInfo->lUserIngot = pGlobalUserInfo->lUserIngot + cmd->reward_;
	}
}

void TaskLayer::dargon_task_complete_end(cocos2d::Node* node)
{
	spr_dragon_king_complete_gold->stopAllActions();
	spr_dragon_king_complete_gold->setVisible(false);

}
