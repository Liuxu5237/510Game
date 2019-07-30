#include "DntgGameScene.h"

#include "DntgTimestampManager.h"

#include "DntgUIAdmin.h"
#include "DntgClientKernelSink.h"
#include "DntgWeaponConfig.h"

#include "kernel/game/IClientKernel.h"

//#include "fttypes.h"
using namespace Dntg;

/************************************************************************/
/* 购买子弹成功                                                         */
/************************************************************************/
bool CGameSceneEngine::on_sub_buy_bullet_success(void* data, int dataSize)
{
	//效验数据
	if (dataSize != sizeof(CMD_S_Buy_Bullet_Success)) return false;
	CMD_S_Buy_Bullet_Success * success = (CMD_S_Buy_Bullet_Success *)data;

	net_buy_bullet_success(success->chair_id_, success->count_);
	return true;
}



bool CGameSceneEngine::on_sub_buy_AndirInfo(void* data, int dataSize)
{
	CMD_S_FishAndisNick *FishAndir = (CMD_S_FishAndisNick*)data;
	net_buy_jiqirmomoda(FishAndir);

	return true;
}

////最可爱的人在眼前
//bool CGameSceneEngine::on_sub_buy_Paotai_success(void* data, int dataSize)
//{
//	CMD_S_Buy_Chaid *FishAndir = (CMD_S_Buy_Chaid*)data;
//	net_buy_PaoTai(FishAndir);
//	return true;
//}
//
//
////机器人跑路
//bool CGameSceneEngine::on_sub_buy_AndirQuit(void* data, int dataSize)
//{
//	word *pWcharID = (word*)data;
//	net_buy_jiqirmomodaQuit(*pWcharID);
//
//	return true;
//}


// 管理员
bool CGameSceneEngine::on_sub_buy_Admin_success(void* data, int dataSize)
{
	////效验数据
	//if (dataSize != sizeof(CMD_GR_FishingServer)) return false;
	CMD_GR_FishingServer * success = (CMD_GR_FishingServer *)data;

	//tagListoffishing *ps = success->Listoffishing;
	net_buy_Admin_Room(success, dataSize);

	return true;
}


//人数收益表
bool CGameSceneEngine::on_sub_buy_Admin_UserInfo(void* data, int dataSize)
{
	CMD_GR_FishingServerInfo * success = (CMD_GR_FishingServerInfo *)data;
	net_buy_Admin_UserInfo(success, dataSize);
	return true;
}
bool CGameSceneEngine::on_sub_buy_Admin_MingDan(void* data, int dataSize)
{
	CMD_S_Kongzhi * success = (CMD_S_Kongzhi *)data;
	net_buy_Admin_MingList(success, dataSize);
	return true;
}

/************************************************************************/
/* 购买子弹失败                                                         */
/************************************************************************/
bool CGameSceneEngine::on_sub_buy_bullet_failed(void* data, int dataSize)
{
	//效验数据
	if (dataSize != sizeof(CMD_S_Buy_Bullet_Failed)) return false;
	CMD_S_Buy_Bullet_Failed* failed = (CMD_S_Buy_Bullet_Failed *)data;

	net_buy_bullet_failed(failed->chair_id_);
	return true;
}

/************************************************************************/
/* 改变炮类型                                                           */
/************************************************************************/
bool CGameSceneEngine::on_sub_change_cannon(void* data, int dataSize)
{
	net_change_cannon(data, dataSize);
	return true;
}

/************************************************************************/
/* 鱼生成                                                               */
/************************************************************************/
bool CGameSceneEngine::on_sub_send_bird(void* data, int dataSize)
{
	ASSERT(dataSize % sizeof(CMD_S_Send_Bird) == 0);
	if (dataSize % sizeof(CMD_S_Send_Bird) != 0)
		return false;

	CMD_S_Send_Bird* send_bird = (CMD_S_Send_Bird*)(data);
	uint16_t bird_count = dataSize / sizeof(CMD_S_Send_Bird);

	for (uint16_t i = 0; i < bird_count; i++)
	{
		net_send_bird(send_bird);
		send_bird++;
	}
	return true;
}

/************************************************************************/
/* 子弹生成                                                             */
/************************************************************************/
bool CGameSceneEngine::on_sub_send_bullet(void* data, int dataSize)
{
	//效验数据
	if (dataSize != sizeof(CMD_S_Send_Bullet))
	{
		log("CMD_S_Send_Bullet is error!!!");
		return false;
	}
	CMD_S_Send_Bullet * send_bullet = (CMD_S_Send_Bullet *)data;

	net_send_bullet(send_bullet);
	return true;
}

/************************************************************************/
/* 开火失败                                                             */
/************************************************************************/
bool CGameSceneEngine::on_sub_fire_failed(void* data, int dataSize)
{
	if (dataSize != sizeof(CMD_S_Fire_Failed))
		return false;
	CMD_S_Fire_Failed *pFireFailed = (CMD_S_Fire_Failed *)data;

	net_fire_failed(pFireFailed);

	return true;
}

/************************************************************************/
/* 抓住鱼, 系统回掉                                                     */
/************************************************************************/
bool CGameSceneEngine::on_sub_catch_bird(void * data, int dataSize)
{
	//效验数据
	if (dataSize != sizeof(CMD_S_Catch_Bird)) return false;
	thread_count++;
	CMD_S_Catch_Bird * catch_bird = (CMD_S_Catch_Bird *)data;

	CMD_S_Special_Catch_Bird special_catch_bird;
	special_catch_bird.chair_id_		= catch_bird->chair_id_;
	special_catch_bird.cannon_type_		= catch_bird->cannon_type_;
	special_catch_bird.catch_gold_		= catch_bird->catch_gold_;
	special_catch_bird.bird_id_			= catch_bird->bird_id_;
	special_catch_bird.award_type_		= catch_bird->award_type_;
	special_catch_bird.award_count_		= catch_bird->award_count_;
	special_catch_bird.medal_			= catch_bird->medal_;
	special_catch_bird.link_bird_id_	= -1;
	special_catch_bird.thread_id		= thread_count;


	net_bird_dead(&special_catch_bird);
	return true;
}

/************************************************************************/
/* 抓住鱼, 代码内调用, 写2个函数是为了不破坏整个代码的风格              */
/************************************************************************/
bool CGameSceneEngine::on_sub_catch_bird_class(void * data, int dataSize)
{
	//效验数据
	if (dataSize != sizeof(CMD_S_Special_Catch_Bird)) return false;
	CMD_S_Special_Catch_Bird * catch_bird = (CMD_S_Special_Catch_Bird *)data;

	net_bird_dead(catch_bird);
	return true;
}

/************************************************************************/
/* 抓住鱼                                                               */
/************************************************************************/
bool CGameSceneEngine::on_sub_catch_bird_group(void* data, int dataSize)
{
	//效验数据
	if (dataSize % sizeof(CMD_S_Catch_Bird_Group) != 0) return false;
	thread_count++;
	CMD_S_Catch_Bird_Group * catch_bird_group = (CMD_S_Catch_Bird_Group *)data;
    printf("%lu" , sizeof(CMD_S_Catch_Bird_Group));
	uint16 bird_count = dataSize / sizeof(CMD_S_Catch_Bird_Group);

	for (uint16 i = 0; i < bird_count; i++)
	{
		if (i + 1 < bird_count)
			net_bird_group_dead(catch_bird_group, thread_count);
		//最后一波
		else
			net_bird_group_dead(catch_bird_group, thread_count, true);
		//这个每次都要增加
		int count = catch_bird_group->count_;

		CMD_S_Special_Catch_Bird catch_bird;
		catch_bird.chair_id_ = catch_bird_group->chair_id_;
		catch_bird.cannon_type_ = catch_bird_group->cannon_type_;

		for (int i = 0; i < count; i++)
		{
			catch_bird.bird_id_ = catch_bird_group->catch_bird_[i].bird_id_;
			catch_bird.catch_gold_ = catch_bird_group->catch_bird_[i].catch_gold_;
			catch_bird.award_type_ = catch_bird_group->catch_bird_[i].award_type_;
			catch_bird.award_count_ = catch_bird_group->catch_bird_[i].award_count_;
			catch_bird.medal_ = catch_bird_group->catch_bird_[i].medal_;
			catch_bird.link_bird_id_ = catch_bird_group->catch_bird_[i].link_bird_id_;
			catch_bird.thread_id = thread_count;

			//先做任务检测后 才能删掉鱼
			if (mChairTask && mChairTask->bird_type == getBirdTypeByBirdId(catch_bird.bird_id_) &&
				mChairTask->chair_id_ == catch_bird.chair_id_)
			{
				CMD_S_TaskCount * task_ = new CMD_S_TaskCount;
				task_->type = mChairTask->type_;
				task_->bird_type = mChairTask->bird_type;
				task_->count = 1;
				on_sub_task_count(task_, sizeof(CMD_S_TaskCount));
			}
			if (mRoomTask && mRoomTask->bird_type == getBirdTypeByBirdId(catch_bird.bird_id_) &&
				mRoomTask->chair_id_ == catch_bird.chair_id_)
			{
				CMD_S_TaskCount * task_ = new CMD_S_TaskCount;
				task_->type = mRoomTask->type_;
				task_->bird_type = mRoomTask->bird_type;
				task_->count = 1;
				on_sub_task_count(task_, sizeof(CMD_S_TaskCount));
			}

			on_sub_catch_bird_class(&catch_bird, sizeof(CMD_S_Special_Catch_Bird));
		}

		catch_bird_group++;
	}

	if (thread_count > 0xFFFFFFFF) 
		thread_count = 0;

	return true;
}

/************************************************************************/
/* 抓住闪电鱼                                                           */
/************************************************************************/
bool CGameSceneEngine::on_sub_catch_bird_chain(void* data, int dataSize)
{
	//效验数据
	if (dataSize % sizeof(CMD_S_Catch_Bird_Chain) != 0) return false;
	thread_count++;
	CMD_S_Catch_Bird_Chain * catch_bird_group = (CMD_S_Catch_Bird_Chain *)data;

	uint16 bird_count = dataSize / sizeof(CMD_S_Catch_Bird_Group);

	for (uint16 i = 0; i < bird_count; i++)
	{
		if (i + 1 < bird_count)
			net_bird_group_dead(catch_bird_group, thread_count);
		// 最后一波
		else
			net_bird_group_dead(catch_bird_group, thread_count, true);

		///< 这个每次都要增加
		int count = catch_bird_group->count_;

		CMD_S_Special_Catch_Bird catch_bird;
		catch_bird.chair_id_ = catch_bird_group->chair_id_;
		catch_bird.cannon_type_ = catch_bird_group->cannon_type_;

		for (int i = 0; i < count; i++)
		{
			catch_bird.bird_id_ = catch_bird_group->catch_bird_[i].bird_id_;
			catch_bird.catch_gold_ = catch_bird_group->catch_bird_[i].catch_gold_;
			catch_bird.award_type_ = catch_bird_group->catch_bird_[i].award_type_;
			catch_bird.award_count_ = catch_bird_group->catch_bird_[i].award_count_;
			catch_bird.medal_ = catch_bird_group->catch_bird_[i].medal_;
			catch_bird.link_bird_id_ = catch_bird_group->catch_bird_[i].link_bird_id_;
			catch_bird.thread_id = thread_count;

			on_sub_catch_bird_class(&catch_bird, sizeof(CMD_S_Special_Catch_Bird));
		}

		catch_bird_group++;
	}
	return true;
}

/************************************************************************/
/* 改变场景                                                             */
/************************************************************************/
bool CGameSceneEngine::on_sub_scene_change(void* data, int dataSize)
{
	//效验数据
	if (dataSize != sizeof(CMD_S_Change_Scene)) return false;
	CMD_S_Change_Scene * change_scene = (CMD_S_Change_Scene *)data;

	net_change_scene(change_scene->scene_);
	return true;
}

/************************************************************************/
/* 上下分                                                               */
/************************************************************************/
bool CGameSceneEngine::on_sub_game_account(void* data, int dataSize)
{
	if (dataSize != sizeof(CMD_S_Account))
		return false;

	CMD_S_Account *account = (CMD_S_Account *)data;
	net_account(account);
	return true;
}

/************************************************************************/
/* 时间校准                                                             */
/************************************************************************/
bool CGameSceneEngine::on_sub_time_check(void* data, int dataSize)
{
	//效验数据
	if (dataSize != sizeof(CMD_S_TimeCheck)) return false;
	CMD_S_TimeCheck* time_check = (CMD_S_TimeCheck *)data;

	gDntgTimestampManager.timeCheck(time_check->client_time_, time_check->server_time_);

	if (!mIsNetworkPrepared)
		set_fire_enable(true);

	net_time_check();

	mIsNetworkPrepared = true;
	return true;
}

/************************************************************************/
/* 时间校准                                                             */
/************************************************************************/
bool CGameSceneEngine::on_sub_order_time_check(void* data, int dataSize)
{
	if (dataSize != sizeof(CMD_S_OrderTimeCheck))
		return false;

	send_time_check(false);
	return true;
}

/************************************************************************/
/* 鱼特效                                                               */
/************************************************************************/
bool CGameSceneEngine::on_sub_bird_effect(void* data, int dataSize)
{
	//效验数据
	if (dataSize > sizeof(CMD_S_Bird_Effect))
		return false;

	net_bird_effect((CMD_S_Bird_Effect*)data);
	return true;
}

/************************************************************************/
/* 鱼boss                                                               */
/************************************************************************/
bool CGameSceneEngine::on_sub_bird_boss(void* data, int dataSize)
{
	//效验数据
	if (dataSize > sizeof(CMD_S_Bird_Effect))
		return false;
	CMD_S_Bird_Boss * bird_boss = (CMD_S_Bird_Boss *)data;

	bird_speed_up(bird_boss->bird_item_ != 0);

	return true;
}

/************************************************************************/
/* 武器信息                                                             */
/************************************************************************/
bool CGameSceneEngine::on_sub_weapon_info(void* data, int dataSize)
{
	//效验数据
	ASSERT(dataSize == sizeof(CMD_S_WeaponInfo));
	if (dataSize != sizeof(CMD_S_WeaponInfo))
		return false;
	CMD_S_WeaponInfo* pWeaponInfo = (CMD_S_WeaponInfo *)data;
	WeaponConfig::getInstance().set_weapon_info(pWeaponInfo->weapons_);
	return true;
}

/************************************************************************/
/* 武器等级                                                             */
/************************************************************************/
bool CGameSceneEngine::on_sub_weapon_level(void* data, int dataSize)
{
	net_weapon_level(data, dataSize);
	return true;
}

/************************************************************************/
/* 财富信息                                                             */
/************************************************************************/
bool CGameSceneEngine::on_sub_treasure(void* data, int dataSize)
{
	//效验数据
	ASSERT(dataSize == sizeof(CMD_S_Treasure));
	if (dataSize != sizeof(CMD_S_Treasure))
		return false;
	CMD_S_Treasure* pTreasure = (CMD_S_Treasure *)data;
	mDataProxy.setTreasure(pTreasure->treasure_);
	return true;
}

/************************************************************************/
/* 技能                                                                 */
/************************************************************************/
bool CGameSceneEngine::on_sub_skill(void* data, int dataSize)
{
	net_skill(data, dataSize);
	return true;
}

/************************************************************************/
/* 强化结果                                                             */
/************************************************************************/
bool CGameSceneEngine::on_sub_strengthen_result(void* data, int dataSize)
{
	net_strengthen_result(data, dataSize);
	return true;
}

/************************************************************************/
/* 任务悬赏                                                             */
/************************************************************************/
bool CGameSceneEngine::on_sub_task_reward(void* data, int dataSize)
{
	return true;
}

/************************************************************************/
/* 任务                                                                 */
/************************************************************************/
bool CGameSceneEngine::on_sub_task(void* data, int dataSize)
{
	if (dataSize > sizeof(CMD_S_Task))
		return false;

	return true;
}

/************************************************************************/
/* 任务数量                                                             */
/************************************************************************/
bool CGameSceneEngine::on_sub_task_count(void* data, int dataSize)
{
	if (dataSize > sizeof(CMD_S_TaskCount))
		return false;

	net_task_count((CMD_S_TaskCount*)data);
	return true;
}

/************************************************************************/
/* 任务完成                                                             */
/************************************************************************/
bool CGameSceneEngine::on_sub_task_complete(void* data, int dataSize)
{
	if (dataSize > sizeof(CMD_S_TaskComplete))
		return false;

	return true;
}

/************************************************************************/
/* 排名信息                                                             */
/************************************************************************/
bool CGameSceneEngine::on_sub_rank_info(void* data, int dataSize)
{
	//效验数据
	ASSERT(dataSize == sizeof(CMD_S_RankInfo));
	if (dataSize != sizeof(CMD_S_RankInfo))
		return false;

	CMD_S_RankInfo* pRankInfo = (CMD_S_RankInfo*)data;
	mDataProxy.setRankInfo(pRankInfo->score_, pRankInfo->catch_score_);
	return true;
}

/************************************************************************/
/* 排行榜                                                               */
/************************************************************************/
bool CGameSceneEngine::on_sub_rank_list(void* data, int dataSize)
{
	ASSERT(dataSize == sizeof(CMD_S_RankList));
	if (dataSize != sizeof(CMD_S_RankList))
		return false;

	CMD_S_RankList* pRankList = (CMD_S_RankList*)data;
	mDataProxy.setRankList(pRankList->dwRefreshTime, pRankList->wRanks, pRankList->items, pRankList->lScores);
	return true;
}

/************************************************************************/
/* 库存操作                                                             */
/************************************************************************/
bool CGameSceneEngine::on_sub_storage(void* data, int dataSize)
{
	return true;
}

/************************************************************************/
/* 黑白名单                                                             */
/************************************************************************/
bool CGameSceneEngine::on_sub_black_white(void* data, int dataSize)
{
	return true;
}

/************************************************************************/
/* 场景鱼                                                               */
/************************************************************************/
bool CGameSceneEngine::on_sub_play_bird(void* data, int dataSize)
{
	ASSERT(dataSize % sizeof(CMD_S_Send_Bird) == 0);
	if (dataSize % sizeof(CMD_S_Send_Bird) != 0)
		return false;

	CMD_S_Send_Bird* send_bird = (CMD_S_Send_Bird*)(data);
	uint16_t bird_count = dataSize / sizeof(CMD_S_Send_Bird);

	for (uint16_t i = 0; i < bird_count; i++)
	{
		net_send_bird(send_bird);
		send_bird++;
	}
	return true;
}

/************************************************************************/
/* 场景子弹                                                             */
/************************************************************************/
bool CGameSceneEngine::on_sub_play_bullet(void* data, int dataSize)
{
	ASSERT(dataSize % sizeof(CMD_S_Send_Bullet) == 0);
	if (dataSize % sizeof(CMD_S_Send_Bullet) != 0)
		return false;

	CMD_S_Send_Bullet* send_bullet = (CMD_S_Send_Bullet*)data;
	uint16_t bullet_count = dataSize / sizeof(CMD_S_Send_Bullet);

	for (uint16_t i = 0; i < bullet_count; i++)
	{
		net_send_bullet(send_bullet);
		send_bullet++;
	}

	return true;
}

/************************************************************************/
/* 特殊鱼阵                                                             */
/************************************************************************/
bool CGameSceneEngine::on_sub_bird_linear(void* data, int dataSize)
{
	ASSERT(dataSize % sizeof(CMD_S_Send_Bird_Linear) == 0);
	if (dataSize % sizeof(CMD_S_Send_Bird_Linear) != 0)
		return false;

	CMD_S_Send_Bird_Linear * send_bird = (CMD_S_Send_Bird_Linear*)data;
	uint16_t bird_count = dataSize / sizeof(CMD_S_Send_Bird_Linear);

	for (uint16_t i = 0; i < bird_count; i++)
	{
		net_send_bird_linear(send_bird);
		send_bird++;
	}
	return true;
}

/************************************************************************/
/* 特殊鱼阵                                                             */
/************************************************************************/
bool CGameSceneEngine::on_sub_bird_round(void* data, int dataSize)
{
	ASSERT(dataSize % sizeof(CMD_S_Send_Bird_Round) == 0);
	if (dataSize % sizeof(CMD_S_Send_Bird_Round) != 0)
		return false;

	CMD_S_Send_Bird_Round* send_bird = (CMD_S_Send_Bird_Round*)data;
	uint16_t bird_count = dataSize / sizeof(CMD_S_Send_Bird_Round);

	for (uint16 i = 0; i < bird_count; i++)
	{
		net_send_bird_round(send_bird);
		send_bird++;
	}
	return true;
}

/************************************************************************/
/* 前控 解析                                                            */
/************************************************************************/
bool CGameSceneEngine::onSockOperateResult(void *data, int dataSize)
{
	if (dataSize % sizeof(CMD_S_StockOperateResult) != 0) return false;
	CMD_S_StockOperateResult* stock_op_result_ = static_cast<CMD_S_StockOperateResult*>(data);

	UIAdmin * admin_layer_ = getAdminLayer();
	if (!admin_layer_){
		return false;
	}

	admin_layer_->updateStockList(stock_op_result_->stock_range, 
		stock_op_result_->range_count, 
		(long long*)stock_op_result_->stock_score);

	return true;
}

/************************************************************************/
/* 白名单黑名单操作                                                     */
/************************************************************************/
bool CGameSceneEngine::onRBLControlResult(void*data, int dataSize)
{
	if (dataSize % sizeof(CMD_S_RBL_Control) != 0) return false;
	CMD_S_RBL_Control* rbl_control_ = static_cast<CMD_S_RBL_Control*>(data);

	UIAdmin *admin_layer_ = getAdminLayer();
	if (!admin_layer_){
		return false;
	}

	if (!rbl_control_->operate_RBL){
		admin_layer_->updateBlackNameList(rbl_control_->game_id, rbl_control_->id_count);
	}
	else{
		admin_layer_->updateWhiteNameList(rbl_control_->game_id, rbl_control_->id_count);
	}

	return true;
}

/************************************************************************/
/* 难度控制                                                             */
/************************************************************************/
bool CGameSceneEngine::onDifficultOperateResult(void *data, int dataSize)
{
	if (dataSize % sizeof(CMD_S_Difficulty) != 0) return false;
	CMD_S_Difficulty* diff_ = static_cast<CMD_S_Difficulty*>(data);

	CCLOG(" onDifficultOperateResult  %d  ", diff_->dificulty);

	UIAdmin *admin_layer_ = getAdminLayer();
	if (!admin_layer_){
		return false;
	}

	admin_layer_->updateDifficultySlider(diff_->dificulty * 20 % 100);

	return true;
}



bool CGameSceneEngine::on_sub_game_Admin_finish(void* data, int dataSize)
{
	//CMD_GR_FishingServer *pRoomList = (CMD_GR_FishingServer*)data;
	//for (int i = 0; i < pRoomList->cbColumnCount; i++)
	//{
	//	//DWORD dwGameServer = pRoomList->Listoffishing[i].wServerID;
	//	
	//	//if (frame_layer_ != nullptr)
	//	
	//}

	//给我初始化哈
	return true;
}

/************************************************************************/
/* 特殊鱼阵                                                             */
/************************************************************************/
bool CGameSceneEngine::on_sub_bird_pause_linear(void* data, int dataSize)
{
	ASSERT(dataSize % sizeof(CMD_S_Send_Bird_Pause_Linear) == 0);
	if (dataSize % sizeof(CMD_S_Send_Bird_Pause_Linear) != 0)
		return false;

	CMD_S_Send_Bird_Pause_Linear* send_bird = (CMD_S_Send_Bird_Pause_Linear*)data;
	uint16 bird_count = dataSize / sizeof(CMD_S_Send_Bird_Pause_Linear);

	for (uint16 i = 0; i < bird_count; i++)
	{
		net_send_bird_pause_linear(send_bird);
		send_bird++;
	}
	return true;
}

/************************************************************************/
/* 任务开启                                                             */
/************************************************************************/
bool CGameSceneEngine::on_sub_game_task_open(void* data, int dataSize)
{

	return true;
	if (dataSize % sizeof(CMD_S_Task_Open) != 0)
	{
		return false;
	}
	CMD_S_Task_Open* task_ = static_cast<CMD_S_Task_Open*>(data);

	if (task_->type_ == TASK_PERSONAL_GOLD || task_->type_ == TASK_PERSONAL_INGOT)
	{
		if (mChairTask) delete mChairTask;
		mChairTask = new CMD_S_Task_Open;
		mChairTask->bird_type = task_->bird_type;
		mChairTask->capture_count = task_->capture_count;
		mChairTask->chair_id_ = task_->chair_id_;
		mChairTask->reward_ = task_->reward_;
		mChairTask->time_ = task_->time_;
		mChairTask->type_ = task_->type_;

	}
	else if (task_->type_ == TASK_EVERYONE_GOLD || task_->type_ == TASK_EVERYONE_INGOT)
	{
		if (mRoomTask) delete mRoomTask;
		mRoomTask = new CMD_S_Task_Open;
		mRoomTask->bird_type = task_->bird_type;
		mRoomTask->capture_count = task_->capture_count;
		IClientKernel* kernel = IClientKernel::get();
		mRoomTask->chair_id_ = kernel->GetMeChairID();
		mRoomTask->reward_ = task_->reward_;
		mRoomTask->time_ = task_->time_;
		mRoomTask->type_ = task_->type_;
	}

	net_task(task_);

	return true;
}

/************************************************************************/
/* 任务结束                                                             */
/************************************************************************/
bool CGameSceneEngine::on_sub_game_task_finish(void* data, int dataSize)
{
	int zzz_size = sizeof(dword);
	int old_Size = sizeof(CMD_S_Task_Finish);
	if (dataSize % old_Size != 0)
	{
		return false;
	}
	CMD_S_Task_Finish* task_ = static_cast<CMD_S_Task_Finish*>(data);

	CCLOG(" on_sub_game_task_open message  ");

	if (task_->type_ == TASK_PERSONAL_GOLD || task_->type_ == TASK_PERSONAL_INGOT)
	{
		if (mChairTask) delete mChairTask;
		mChairTask = nullptr;
	}
	else if (task_->type_ == TASK_EVERYONE_GOLD || task_->type_ == TASK_EVERYONE_INGOT)
	{
		if (mRoomTask) delete mRoomTask;
		mRoomTask = nullptr;
	}

	net_task_complete(task_);

	return true;
}

