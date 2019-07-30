#ifndef _Dntg_TaskLayer_H_
#define _Dntg_TaskLayer_H_

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "DntgCMD_CatchBird.h"
namespace  Dntg
{
	class TaskLayer
		: public cocos2d::Layer
	{
	public:
		CREATE_FUNC(TaskLayer);

	public:
		TaskLayer();
		~TaskLayer();
		bool init();

		void task_start(CMD_S_Task_Open* task);
		void task_count(CMD_S_TaskCount* cmd);
		void task_complete(CMD_S_Task_Finish* cmd);
		void setMyChairId(float mid) { mCharId_ = mid; }
	private:
		void chair_task_start(CMD_S_Task_Open* task);
		void room_task_start(CMD_S_Task_Open* task);
		void chair_task_complete(CMD_S_Task_Finish* cmd);
		void room_task_complete(CMD_S_Task_Finish* cmd);
		void chair_task_start_show(cocos2d::Node* node);
		void chair_task_start_hide(cocos2d::Node* node);
		void chair_task_start_end(cocos2d::Node* node);
		void chair_task_complete_end(cocos2d::Node* node);
		void room_task_start_end(cocos2d::Node* node);
		void room_task_complete_end(cocos2d::Node* node);
		void func_chair_time_tick(float dt);

		///< 龙王任务完成
		void dargon_task_complete(CMD_S_Task_Finish* cmd);
		void dargon_task_complete_end(cocos2d::Node* node);
	private:
		// 个人任务倒计时
		int					mChairTimeLeft;
		// 个人任务开始
		cocos2d::Sprite *spr_task_start_bg;
		cocos2d::Sprite *spr_task_start_ani;

		// 个人任务完成
		cocos2d::Sprite *spr_task_complete_bg;
		cocos2d::Sprite *spr_task_complete;
		bool	spr_task_complete_is_visible;

		// 个人任务
		cocos2d::Sprite *spr_task_bg;
		cocos2d::Sprite *spr_task_fish;
		cocos2d::Label  *lb_task_cur_num;
		cocos2d::Label  *lb_task_target_num;
		cocos2d::Label  *lb_task_time_num;
		cocos2d::Label  *lb_task_award_num;

		// 房间任务开始
		cocos2d::Sprite *spr_room_task_start_bg;

		// 房间任务完成
		cocos2d::Sprite *spr_room_task_complete_bg;
		bool	spr_room_task_complete_is_visible;
		// 房间任务
		cocos2d::Sprite *spr_room_task_bg;
		cocos2d::Sprite *spr_room_task_fish;
		cocos2d::Label  *lb_room_task_cur_num;
		cocos2d::Label  *lb_room_task_target_num;
		cocos2d::Label  *lb_room_task_award_num;

		///< 四海龙王任务
		///< 金币
		cocos2d::Sprite *spr_dragon_king_complete_gold;
		cocos2d::ui::TextAtlas  *lb_dragon_king_reward_money;

		///< 椅子id
		int mCharId_;
		///< 房间计数
		int mRoomCount;
		///< 椅子计数
		int mChairCount;
	};
}
#endif // _TaskLayer_H_