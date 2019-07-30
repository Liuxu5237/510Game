#ifndef _Dntg_GameScene_H_
#define _Dntg_GameScene_H_

#include "cocos2d.h"
#include "tools/dialog/Timer.h"
#include "DntgCMD_CatchBird.h"
#include "DntgBird.h"
#include "tools/manager/SoundManager.h"

#include "kernel/game/IGameSceneSink.h"
#include "DntgGoDataProxy.h"

#include "../GlobalDefine/Define.h"
#include "tools/tools/Convert.h"
USING_NS_CC;

#define KEY_FOR_GUIDE_SHOW_SET		("IsGuideShowOnStart")
class IClientUserItem;

namespace  Dntg
{
	class CSoundNode;
	class BirdLayer;
	class RoleLayer;
	class BulletLayer;
	class CoinLayer;
	class NetLayer;
	class TaskLayer;
	class SceneLayer;
	class MeInfoLayer;
	class FrameLayer;
	class CashShopLayer;
	class BirdNode;
	class ChatLayer;
	class UIAdmin;
	class GameGuideLayer;
	struct CMD_S_Task_Open;

	enum GameStatus {
		GAME_LOGIC,
		GAME_BUY_PREPARE,
		GAME_BUY_SEND,
		GAME_ACCOUNT,
		GAME_END
	};


	struct SendSavaStruct
	{
	public:
		std::map<int, Vec2> startList; ///< 保证的红鱼
		std::map<int, std::vector<Vec2>> otherList; ///< 其他的链接鱼
		std::map<int, int> type_value; ///< 表示使用哪种效果
		int total_price; ///< 总价值

		SendSavaStruct() : total_price(0) {}

	};

	//游戏引擎
	class CGameSceneEngine : public IGameSceneSink, public cocos2d::Ref
	{
		//函数定义
	public:
		//构造函数
		CGameSceneEngine();
		//析构函数
		virtual ~CGameSceneEngine();

	public:

		// 初始化接口 
		virtual bool init(CGameScene * pGameScene);

		// 重入游戏接口
		virtual void OnReconnectResumeGame();

	public:

		//启动游戏
		virtual bool SetupGameClient();

		//重置游戏
		virtual void ResetGameClient();

		//关闭游戏
		virtual void CloseGameClient();


	public:

		//用户进入
		virtual void OnEventUserEnter(IClientUserItem * pIClientUserItem, bool bLookonUser);

		//用户离开
		virtual void OnEventUserLeave(IClientUserItem * pIClientUserItem, bool bLookonUser);

		//用户状态变化
		virtual void OnEventUserStatus(IClientUserItem * pIClientUserItem, bool bLookonUser);

		//用户积分
		virtual void OnEventUserScore(IClientUserItem * pIClientUserItem, bool bLookonUser);

		//用户属性
		virtual void OnEventUserAttrib(IClientUserItem * pIClientUserItem, bool bLookonUser);

	public:

		//场景消息
		bool OnEventSceneMessage(byte cbGameStatus, bool bLookonUser, void* data, int dataSize);

		//游戏消息
		bool OnEventGameMessage(int sub, void* data, int dataSize);

	public:

		// 游戏暂停接口
		virtual void OnGameEnterBackground();

		// 游戏恢复接口
		virtual void OnGameEnterForeground();

	public:

		// 检测到网络断开
		virtual void OnDetectNetDown();

		// 网络已经可用，进入到断线重连状态
		virtual void OnEnterReconnectState();

	public:

		virtual void OnSubWaitBack();

	public:

		// 初始化触摸屏幕事件
		virtual void initTouch(Node* node);

		// 触摸开始
		virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);

		// 触摸移动
		virtual void ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);

		// 触摸结束
		virtual void ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);

	public:

		//场景进入接口
		virtual void onEnterTransitionDidFinish();

		// 更新函数
		virtual void update(float delta);

	public:

		//得到玩家的层
		//RoleLayer* get_role_layer() { return role_layer_; }

		//得到当前的状态
		GameStatus get_status() const { return status_; }

		//设置当前的状态
		void set_status(GameStatus status)  { status_ = status; }

		//获取当前总财富
		int64 getTreasure();

	public:

		//菜单选项点击 
		void onMenuItemClick(cocos2d::Ref* obj);
		
		// 添加管理员UI
		void addAdminUI();

		// 显示管理员UI 
		void showAdminUI();

		// 移除管理员UI
		void removeAdminUI();

		// 碰撞检测
		void collision_dection();

		// 现在始终锁定最大鱼
		bool collision_pos_bird(cocos2d::Vec2 touch_pos);

		// 现在始终锁定最大鱼
		bool collision_pos_bird();

		//切换锁定鱼
		void collision_change_bird();

		// 计算碰撞
		bool compute_collision(float bird_x, float bird_y, 
							   float bird_width, float bird_height, float bird_rotation,
							   float bullet_x, float bullet_y, float bullet_radius);

		//
		int bullet_index_factroy();

		// 打开鱼网
		void open_net(Bullet *bullet);

		// 销毁鱼
		void destoryBird(Bird* bird);
		
		//自动开火
		void autoFire();

		//是否可以开炮
		bool getIsFire();

		//设置是否可以开火
		void setIsFire(bool isCanFire);
	public:

		//用户进入
		void net_user_enter(int chair_id);

		//用户离开
		void net_user_leave(int chair_id);

		//用户分数
		void net_user_score(int chair_id);

		//场景消息
		void on_scene_message(byte cbGameStatus, bool bLookonUser, void* data, int dataSize);

		// 购买子弹成功
		void net_buy_bullet_success(int chair_id, uint64 count);



		// 我想操作机器人
		void net_buy_jiqirmomoda(CMD_S_FishAndisNick *FishAndir);


		// 管理员控制
		void net_buy_Admin_Room(void* data, int dataSize);

		// 房间收益列表
		void net_buy_Admin_UserInfo(void* data, int dataSize);


		// 名单表
		void net_buy_Admin_MingList(void* data, int dataSize);


		//购买子弹失败
		void net_buy_bullet_failed(int chair_id);

		//开火失败
		void net_fire_failed(CMD_S_Fire_Failed *pFireFailed);

		//改变炮弹
		bool net_change_cannon(void* data, int dataSize);
		
		//子弹生成
		void net_send_bullet(CMD_S_Send_Bullet* send_bullet);

		//鱼生成
		void net_send_bird(CMD_S_Send_Bird* send_bird);

		//特殊鱼阵生成
		void net_send_bird_linear(CMD_S_Send_Bird_Linear* send_bird);
		void net_send_bird_round(CMD_S_Send_Bird_Round* send_bird);
		void net_send_bird_pause_linear(CMD_S_Send_Bird_Pause_Linear* send_bird);

		//圆阵
		void net_send_scene_round();

		//一圈一圈鼓出的鱼
		void net_send_scene_bloating();
		
		void round_linear(cocos2d::Node* node, void* data);

		//鱼群中的抓住鱼
		void net_bird_dead(CMD_S_Special_Catch_Bird * catch_bird);

		//抓住鱼
		void net_bird_group_dead(CMD_S_Catch_Bird_Group* catch_group, 
								 int thread_id, bool isEndWave = false);
		///< 抓住闪电鱼
		void net_bird_group_dead(CMD_S_Catch_Bird_Chain* catch_group, 
								 int thread_id, bool isEndWave = false);
		//切换场景
		void net_change_scene(int scene);

		//上下分
		void net_account(CMD_S_Account* account);

		//鱼特效
		void net_bird_effect(CMD_S_Bird_Effect* bird_effect);

		//网络时间校准
		void net_time_check();

		//武器信息
		bool net_weapon_level(void* data, int dataSize);

		//技能
		bool net_skill(void* data, int dataSize);

		//强化结果
		bool net_strengthen_result(void* data, int dataSize);

		//任务
		void net_task(CMD_S_Task_Open* task);

		//任务数量
		void net_task_count(CMD_S_TaskCount* taskCount);

		//任务完成
		void net_task_complete(CMD_S_Task_Finish* taskComplete);

		//定
		void bird_ding(bool ding);

		//加速
		void bird_speed_up(bool speed_up);

		//设置是否可开火
		void set_fire_enable(bool isEanbled);

		//关闭窗口
		void func_close_windows(cocos2d::Ref* obj);

	private:
		//定时器
		void func_send_time_check(float dt);

		//删除爆炸
		void func_bomb_effect_end(cocos2d::Node * node, void * data);

		//把点从UI坐标系转到GL坐标系
		cocos2d::Vec2 locationFromTouch(cocos2d::CCTouch *touch);

	public:

		//震屏
		void start_shake_screen(float shake_radius);

		//停止震屏幕
		void stop_shake_screen();

		//震屏心跳
		void shake_screen_update(float dt);

	public:

		//购买子弹
		void op_buy_bullet(SCORE fishCoins);

	private:

		//下分
		void op_account();

		//最大分
		void op_buy_max();

		//增加炮类型
		void op_cannon_add();

		// 减少炮
		void op_cannon_sub();

		// 最大炮
		void op_cannon_max();

		// 发炮
		void op_fire();

		// 想服务器发送子弹
		void send_op_fire(Bullet * bullet);

		// 关闭响应函数
		void closeCallback(cocos2d::Node *pNode);

		// 强化确认
		void func_strenthen_confirm(cocos2d::Ref* obj);

		// 打开强化面板
		void func_ui_strenthen_open(cocos2d::Ref* obj);

		//上分
		void func_score_up(cocos2d::Ref* obj);

		//下分
		void func_score_down(cocos2d::Ref* obj);

		//更换炮类型
		void func_cannon_add(cocos2d::Ref* obj);

		//更换炮类型
		void func_cannon_sub(cocos2d::Ref* obj);

		//最大炮类型
		void func_cannon_max(cocos2d::Ref* obj);

		//win32键盘消息
		void func_keyboard(cocos2d::Ref* obj);

		//win32键盘按下消息
		void func_key_Pressed(EventKeyboard::KeyCode keyCode, Event * event);

		//win32键盘抬起消息
		void func_key_Released(EventKeyboard::KeyCode keyCode, Event * event);


		bool isHistoryLockBird(int FishId);


		//清除鱼
		void clearSceneBird();

		//清除子弹
		void clearSceneBullet();

	protected:
		//隐藏兑换界面
		void funcHideExchang(cocos2d::Ref* obj);
		//显示引导
		void funcShowGuide(cocos2d::Ref* obj);
		//购买子弹
		void funcBuyBullet(cocos2d::Ref* obj);

	public:
		//取消鱼的锁定的回调
		void cancelBirdLock(cocos2d::Ref * obj);

		//取消全部鱼的锁定
		void cancelAllBirdLock();

		//设置鱼锁定
		void setBirdLock(int char_id, int bird_id);
		//定标志
		bool isDing;

	public:
		///< 是断线重连
		static bool is_Reconnect_on_loss();

		//获得鱼死亡统计管理器
		BirdDealCountManager & getBirdDealCountnManager() { return bird_deal_count_manager_; }
		
		//获得单局获得总金币
		std::string getSingleGameTotalGold();
		
		//获得对应总钱数
		std::string getUserTotalMoney();

	public:

		UIAdmin* getAdminLayer()
		{
			return admin_layer_;
		}

		// 通过鱼的ID得到鱼的类型
		int getBirdTypeByBirdId(int bird_id);

		//显示介绍
		void showGuide();
		
		//显示兑换界面
		void showExchange();

		//隐藏兑换界面
		void hideExchange();

		//显示排行榜
		bool showRankList(void* data, int dataSize);

	public:

		// 管理员
		bool on_sub_buy_Admin_success(void* data, int dataSize);
		bool on_sub_buy_Admin_MingDan(void* data, int dataSize);
		//人数收益表
		bool on_sub_buy_Admin_UserInfo(void* data, int dataSize);
		// 购买子弹成功
		bool on_sub_buy_bullet_success(void* data, int dataSize);
		bool on_sub_buy_AndirInfo(void* data, int dataSize);
		// 购买子弹失败
		bool on_sub_buy_bullet_failed(void* data, int dataSize);

		// 改变炮类型
		bool on_sub_change_cannon(void* data, int dataSize);

		// 鱼生成
		bool on_sub_send_bird(void* data, int dataSize);

		// 子弹生成
		bool on_sub_send_bullet(void* data, int dataSize);

		// 开火失败
		bool on_sub_fire_failed(void* data, int dataSize);

		// 抓住鱼, 系统回掉
		bool on_sub_catch_bird(void * data, int dataSize);

		// 抓住鱼, 代码内调用, 写2个函数是为了不破坏整个代码的风格
		bool on_sub_catch_bird_class(void * data, int dataSize);

		// 抓住鱼
		bool on_sub_catch_bird_group(void* data, int dataSize);

		// 抓住闪电鱼
		bool on_sub_catch_bird_chain(void* data, int dataSize);

		// 改变场景
		bool on_sub_scene_change(void* data, int dataSize);

		// 上下分
		bool on_sub_game_account(void* data, int dataSize);

		// 时间校准
		bool on_sub_time_check(void* data, int dataSize);

		// 时间校准
		bool on_sub_order_time_check(void* data, int dataSize);

		// 鱼特效
		bool on_sub_bird_effect(void* data, int dataSize);

		// 鱼boss
		bool on_sub_bird_boss(void* data, int dataSize);

		// 武器信息
		bool on_sub_weapon_info(void* data, int dataSize);

		// 武器等级
		bool on_sub_weapon_level(void* data, int dataSize);

		// 财富信息
		bool on_sub_treasure(void* data, int dataSize);

		// 技能
		bool on_sub_skill(void* data, int dataSize);

		// 强化结果
		bool on_sub_strengthen_result(void* data, int dataSize);

		// 任务悬赏
		bool on_sub_task_reward(void* data, int dataSize);

		// 任务
		bool on_sub_task(void* data, int dataSize);

		// 任务数量
		bool on_sub_task_count(void* data, int dataSize);

		// 任务完成
		bool on_sub_task_complete(void* data, int dataSize);

		// 排名信息
		bool on_sub_rank_info(void* data, int dataSize);

		// 排行榜
		bool on_sub_rank_list(void* data, int dataSize);

		// 库存操作
		bool on_sub_storage(void* data, int dataSize);

		// 黑白名单
		bool on_sub_black_white(void* data, int dataSize);

		// 游戏状态 所有鱼
		bool on_sub_play_bird(void* data, int dataSize);

		// 游戏状态 所有子弹
		bool on_sub_play_bullet(void* data, int dataSize);

		// 特殊鱼阵
		bool on_sub_bird_linear(void* data, int dataSize);

		// 特殊鱼阵
		bool on_sub_bird_round(void* data, int dataSize);

		// 特殊鱼阵
		bool on_sub_bird_pause_linear(void* data, int dataSize);

		// 任务开启
		bool on_sub_game_task_open(void* data, int dataSize);

		//任务结束
		bool on_sub_game_task_finish(void* data, int dataSize);

		// 前控操作
		bool onSockOperateResult(void *data, int dataSize);

		// 白名单黑名单操作
		bool onRBLControlResult(void*data, int dataSize);

		// 难度控制
		bool onDifficultOperateResult(void *data, int dataSize);


		bool on_sub_game_Admin_finish(void* data, int dataSize);

	public:
		// 时间校验
		void send_time_check(bool is_game_status);

		//清理任务信息
		void clear_task_info();
        
        CGameScene* getGameScene(){return m_pGameScene;}

	public:
		struct round_bird_linear
		{
			uint8 bird_type;
			uint32 bird_count;
			uint32 start_id;
			xPoint pt_center;
		};

		//锁定过的鱼鱼
		BirdManager				bird_Lockanager_;
		BirdManager				bird_manager_;
		BulletManager			bullet_manager_;
		BirdDealCountManager	bird_deal_count_manager_;
		///< 单局奖励的钱
		int64					SingleGameTotalGold;

		SceneLayer*				scene_layer_;
		BirdLayer*				bird_layer_;
		NetLayer*				net_layer_;
		BulletLayer*			bullet_layer_;
		RoleLayer*				role_layer_;
		CoinLayer*				coin_layer_;
		/*	TouchLayer*		touch_layer_;*/
		TaskLayer*				task_layer_;
		FrameLayer*				frame_layer_;
		MeInfoLayer*			me_info_layer_;
		ChatLayer*				mChatLayer;
		CashShopLayer*			mCashShopLayer_;
		GameGuideLayer*			m_uiGameGuide;

		UIAdmin*				admin_layer_;

		GameStatus				status_;
		bool 					is_key_fire_;
		bool					is_touch_fire_;
		bool					is_game_pause_;
		int						netType;

	


		//上一次锁定的鱼鱼
		BirdNode *		        m_Lockbird;


		//单位兑换
		int						exchange_count;				
		//兑换比
		double					cash_ratio;				

		SCORE					mLocalScore;

		bool					mInitLocalScore;

		CoTimer					warning_timer_;

		// 		CSoundNode* warning_snd_node_;
		// 		CSoundNode* effect_snd_node_;
		//////////////////////////////////////////////////////////////////////////
		//震屏
		float					shake_screen_angle_;
		float					shake_screen_radius_;

		//< 监听器
		EventListenerTouchOneByOne * _listener;
		EventListenerMouse *		_mouseListener;

		//发送存储结构容器, 用来处理线程安全
		std::map<int, SendSavaStruct> sendSavaList;

		//前一个线程的id
		int pre_thread_id;

	protected:

		GoDataProxy			mDataProxy;
		//线程计数
		int					thread_count;
		//2个任务
		CMD_S_Task_Open *	mChairTask;

		CMD_S_Task_Open *	mRoomTask;

		CGameSceneEngine *	mGameScene;

		bool				mIsNetworkPrepared;
	};
}

#endif // _GameScene_H_
