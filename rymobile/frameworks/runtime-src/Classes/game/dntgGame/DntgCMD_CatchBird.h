#ifndef _Dntg_CMD_CATCH_BIRD_HEAD_FILE
#define _Dntg_CMD_CATCH_BIRD_HEAD_FILE
#pragma once


#include "tools/manager/Move_Point_Manager.h"
#include "platform/df/Define.h"
#include "platform/df/Struct.h"
#include "../GlobalDefine/Define.h"
namespace  Dntg
{

	//////////////////////////////////////////////////////////////////////////

#define KIND_ID						601									    //游戏 I D
#define GAME_PLAYER					6									    //游戏人数

#define VERSION_SERVER				PROCESS_VERSION(6,0,3)					//程序版本
#define VERSION_CLIENT				PROCESS_VERSION(7,0,1)					//程序版本

#define GAME_NAME					TEXT("大闹天宫")						//游戏名字

	//////////////////////////////////////////////////////////////6/////////////
#define IDI_GAME_LOOP                 1
#define TIME_GAME_LOOP                 50

	const int kFPS = 30;				//帧率
	const float kSpeed = 2.f / kFPS;	//速度

	const int kMaxRangeCount = 10;		//库存最大数量

	//////////////////////////////////////////////////////////////////////////
#define MAX_BIRD_IN_MANAGER              2048
#define MAX_BULLET_IN_MANAGER            2048
#define SCENE_TIME_END                   600
#define MAX_SMALL_PATH				     208
#define MAX_BIG_PATH					 130
#define MAX_HUGE_PATH					 62
#define MAX_SPECIAL_PATH				 24
#define MAX_SCENE_PATH                    4
	///< 场景鱼阵数量
#define MAX_SCENE_SHAPE                   6
#define MAX_BIRD_CATCH                    6
#define MAX_BIRD_CATCH_CHAIN			  6
#define MAX_DIFFERENCE                    2000

#define SCENE_TYPE_0                      0
#define SCENE_TYPE_1                      1
#define SCENE_TYPE_2                      2
#define SCENE_TYPE_3                      3
#define SCENE_TYPE_4                      4
#define SCENE_TYPE_NULL                   -1
#define MAX_SCENE_TYPE                    5

	//配置
	///< 鱼类型
#define BIRD_TYPE_0                      0
#define BIRD_TYPE_1                      1
#define BIRD_TYPE_2                      2
#define BIRD_TYPE_3                      3
#define BIRD_TYPE_4                      4
#define BIRD_TYPE_5                      5
#define BIRD_TYPE_6                      6
#define BIRD_TYPE_7                      7
#define BIRD_TYPE_8                      8
#define BIRD_TYPE_9                      9
#define BIRD_TYPE_10                     10
#define BIRD_TYPE_11                     11
#define BIRD_TYPE_12                     12
#define BIRD_TYPE_13                     13
#define BIRD_TYPE_14                     14
#define BIRD_TYPE_15                     15
#define BIRD_TYPE_16                     16
#define BIRD_TYPE_17                     17
#define BIRD_TYPE_18                     18
#define BIRD_TYPE_19                     19
#define BIRD_TYPE_20                     20
#define BIRD_TYPE_21                     21
#define BIRD_TYPE_22                     22
#define BIRD_TYPE_23                     23
#define BIRD_TYPE_24                     24
#define BIRD_TYPE_25                     25
#define BIRD_TYPE_26                     26
#define BIRD_TYPE_27                     27
#define BIRD_TYPE_28                     28
#define BIRD_TYPE_29                     29

#define BIRD_TYPE_NULL                   -1
#define MAX_BIRD_TYPE                    30

	//特殊鱼
#define BIRD_TYPE_CHAIN					 40		//闪电鱼
#define BIRD_TYPE_RED					 41		//红鱼
#define BIRD_TYPE_INGOT					 42		//元宝鱼
	//一箭多雕
#define BIRD_TYPE_ONE					 50
#define BIRD_TYPE_TWO					 51
#define BIRD_TYPE_THREE					 52
#define BIRD_TYPE_FOUR					 53
#define BIRD_TYPE_FIVE					 54
	// 圆盘鱼
	// #define BIRD_TYPE_ONE					 32		//一圆盘
	// #define BIRD_TYPE_TWO					 33		//二圆盘
	// #define BIRD_TYPE_THREE					 34		//三圆盘
	// #define BIRD_TYPE_FOUR					 35		//四圆盘
	// #define BIRD_TYPE_FIVE					 36		//五圆盘


	//#define MAX_BIRD_TYPE						28

#define ITEM_TYPE_NULL                   -1

	///< 子弹类型
#define CANNON_TYPE_0                      0
#define CANNON_TYPE_1                      1
#define CANNON_TYPE_2                      2
#define CANNON_TYPE_3                      3
#define CANNON_TYPE_4                      4
#define CANNON_TYPE_5                      5
#define CANNON_TYPE_6                      6
#define CANNON_TYPE_7                      7
#define CANNON_TYPE_8                      8
#define CANNON_TYPE_9                      9
#define CANNON_TYPE_10                     10
#define CANNON_TYPE_11                     11
#define CANNON_TYPE_12                     12
#define CANNON_TYPE_13                     13
#define CANNON_TYPE_14                     14
#define CANNON_TYPE_15                     15
#define CANNON_TYPE_16                     16
#define CANNON_TYPE_17                     17
#define CANNON_TYPE_18                     18
#define CANNON_TYPE_19                     19
#define CANNON_TYPE_20                     20
#define CANNON_TYPE_NULL                   -1
#define MAX_CANNON_TYPE                    40

#define PATH_TYPE_SMALL                    0
#define PATH_TYPE_BIG                      1
#define PATH_TYPE_HUGE                     2
#define PATH_TYPE_SPECIAL                  3
#define PATH_TYPE_SCENE                    4

#define MAX_BOMB                           3
#define ENERGY_CANNON_CREATE               12

	// 鱼效果类型
	//////////////////////////////////////////////////////////////////////////
#define BIRD_ITEM_NULL						0
#define BIRD_ITEM_SPECIAL_BOMB_1			1
#define BIRD_ITEM_SPECIAL_BOMB_2			2
#define BIRD_ITEM_SPECIAL_BOMB_3			3
#define BIRD_ITEM_SPECIAL_DING				4
#define BIRD_ITEM_SPECIAL_LUCKY				5
#define BIRD_ITEM_SPECIAL_GOLDX2			6
#define BIRD_ITEM_SPECIAL_TOR				7	//音效
#define BIRD_ITEM_SPECIAL_EEL				8   //音效
#define BIRD_ITEM_SPECIAL_SMALL_PURSE		9
#define BIRD_ITEM_SPECIAL_MIDDLE_PURSE		10
#define BIRD_ITEM_SPECIAL_BIG_PURSE			11

	//子弹种类
#define BULLET_KIND_COUNT					6

	//////////////////////////////////////////////////////////////////////////
	// 鱼特效
	//////////////////////////////////////////////////////////////////////////
#define BIRD_EFFECT_NULL					0
#define BIRD_EFFECT_GOLDX2					1
#define BIRD_EFFECT_LUCKY					2
#define BIRD_EFFECT_DING					3
#define BIRD_EFFECT_EEL						4
#define BIRD_EFFECT_TOR						5

	//鱼阵类型
#define YUZHEN_NORMAL						0
#define YUZHEN_LINEAR						1
#define YUZHEN_ROUND						2
#define YUZHEN_PAUSE_LINEAR					3

	///< 任务类型
#define TASK_PERSONAL_GOLD					0		//个人金币任务
#define TASK_PERSONAL_INGOT					1		//个人元宝任务
#define TASK_EVERYONE_GOLD					2		//全场金币任务
#define TASK_EVERYONE_INGOT					3		//全场元宝任务
#define TASK_DRAGON_GOLD					4		//四海龙王金币任务
#define TASK_DRAGON_INGOT					5		//四海龙王元宝任务

	//游戏消息
	//////////////////////////////////////////////////////////////////////////

#define SUB_C_ISANDUSER_QILIMESS            510
    
#define SUB_S_BUYSOCK_CHAID                 512     //进入消息
    
#define SUB_C_ISANDUSER_ACCOUNTS			508
    
#define SUB_S_CHANGE_SCENE	                100
#define SUB_S_BUY_BULLET_SUCCESS			101
#define SUB_S_BUY_BULLET_FAILED				102
#define SUB_S_FIRE_FAILED					104
#define SUB_S_CATCH_BIRD                    105
#define SUB_S_CHANGE_CANNON					106
#define SUB_S_SEND_BIRD				        107
#define SUB_S_SEND_BULLET                   109
#define SUB_S_ACCOUNT						110
#define SUB_S_TIME_CHECK					111
#define SUB_S_ORDER_TIME_CHECK              112
#define SUB_S_CATCH_BIRD_GROUP              113
#define SUB_S_BIRD_EFFECT                   114
#define	SUB_S_PLAY_BIRD						129
#define	SUB_S_PLAY_BULLET					130
#define SUB_S_ENERGY_CANNON                 131
#define SUB_S_SEND_BIRD_LINEAR				132		//发送特殊鱼阵
#define SUB_S_SEND_BIRD_ROUND				133
#define SUB_S_SEND_BIRD_PAUSE_LINEAR		137
#define SUB_S_CATCH_BIRD_CHAIN				134		//闪电鱼
///< 任务
#define SUB_S_TASK_OPEN						135		//开启任务
#define SUB_S_TASK_FINISH					136		//任务完成

	//新加前控
#define SUB_S_STOCK_OPERATE_RESULT			140
#define SUB_S_RBL_CONTROL					141
#define SUB_S_DIFFICULTY					142

	//******* 客户端消息
#define SUB_C_BUY_BULLET					200		//兑换鱼币
#define SUB_C_FIRE							201		//开炮
#define SUB_C_CHANGE_CANNON					202		//加减炮（未使用）
#define SUB_C_ACCOUNT						203		//前控（未使用）
#define SUB_C_TIME_CHECK					204		//时间校验

	//新加前控
#define SUB_C_STOCK_OPERATE                 220		//库存操作
#define SUB_C_RBL_CONTROL					221		//黑白名单操作
#define SUB_C_GIVEAWAY_CONTROL				222		//赠送鱼
#define	SUB_C_DIFFICULTY					223		//难度查询

	///< 下面是最新版中没有对到的消息...




#define MDM_GR_USER						   3


#define SUB_GR_FISH_SEND_OUT        50            //控制名单

    
#define SUB_C_ADMIN_CHECK                   205	    //捕鱼控制
#define SUB_S_ADMIN_CHECK					305		//控制返回

#define SUB__C_CFISH_ROOM					405    //控制数据
#define SUB_S_CFISH_ROOM					406    //数据回调
    
#define SUB_S_FISH_BLACKBAD					509    //刷新列表


#define SUB_C_REQUEST_ADD_USERROSTER        505     //添加黑白名单
#define	SUB_C_REQUEST_S_USERROSTER			507		//黑白名单
#define SUB_C_REQUEST_DLL_USERROSTER        506     //删除黑白名单


#define SUB_S_BIRD_BOSS                     115

#define SUB_S_RANK_INFO						116
#define SUB_S_RANK_LIST						117

#define SUB_S_FRAME_MOVE					119
#define SUB_S_TASK_REWARD					120
#define SUB_S_TASK							121
#define SUB_S_TASK_COUNT					122
#define SUB_S_TASK_COMPLETE					123
#define SUB_S_SKILL							124
#define SUB_S_WEAPON_INFO					125
#define SUB_S_STRENGTHEN_RESULT				126
#define SUB_S_TREASURE						127
#define SUB_S_WEAPON_LEVEL					128


#define SUB_S_ADMIN_CONTROL					141

#define SUB_C_STRENGTHEN					209
#define SUB_C_RANK_LIST						210

	// 控制
#define SUB_S_BLACK_WHITE					400
#define SUB_S_STORAGE                       401

#define SUB_C_USER_FILTER                   300
#define SUB_C_STORAGE                       301
#define SUB_C_CONFIG_RELOAD                 302



#pragma pack(push)
#pragma pack(1)
	//////////////////////////////////////////////////////////////////////////


struct CMD_S_Buy_Chaid
{
	bool   buy_chaid[GAME_PLAYER];
};


struct CMD_C_Request_DLL_Userroster
{
	uint32           dwUserGameID;
	bool            bWin;
};



struct CMD_C_Request_Add_Userroster
{
	uint32           dwUserGameID;
	uint64        lScoreLimit;
	double          probability;
};


struct CMD_C_FishRoom
{
	uint32   ServerID_;
};

//捕鱼列表
struct tagListoffishing
{
	WORD											wServerID;                           //房间ID
	TCHAR											szServerName[32];			//房间名称
};	


struct CMD_GR_FishingServer
{
	
	BYTE							cbColumnCount;						//列表数目
	tagListoffishing                Listoffishing[8]; //列表信息
};



struct CMD_C_Kongzhi
{
	int				lScoreLimit;
	uint32          dwUserGameID;
	double          probability;
};

//请求数据
struct CMD_S_Kongzhi
{
	byte             Counent;
	CMD_C_Kongzhi    Kongzhi[500];
};




struct tagFishServerInfo
{
	DWORD                           wGameID;                             //用户ID
	TCHAR							 szUserName[16];			     //用户名称
	SCORE                           wTotalWin;                           //总输赢
	SCORE                           wTodayWin;                           //当日输赢
	SCORE                           wRoomUserWinLost;                    //个人房间输赢
//	WORD                           wOnlineNumber;                       //房间人数
//	SCORE                           wRoomWinLost;                        //房间总输赢（全部）
//	SCORE                           wToDayLoset;                         //房间总输赢（当前）

};
//请求数据
struct CMD_GR_FishingServerInfo
{
	BYTE							cbColumnCount;						//列表数目
	tagFishServerInfo               FishServerInfo[UD_IMAGE];          //列表信息
};



	struct Role_Net_Object
	{
		uint16 chair_id_;				///< 椅子id
		uint64 catch_gold_;				///< 捕获金币
		uint16 cannon_type_;			///< 捕获类型
		uint32 cannon_mulriple_;		///< 大炮倍数
	};
	//子弹配置
	struct Bullet_Config{
		float speed;				//速度
		float bounding_radius;		//半径
		float fire_interval;		//开炮间隔
	};

	//////////////////////////////////////////////////////////////////////////
	struct CMD_S_StatusFree
	{
		uint8 scene_;										//场景
		int ex_ratio_userscore_;							//兑换比例  金币 = 鱼币 * ex_ratio_userscore_ / ex_ratio_birdscore_
		int ex_ratio_birdscore_;
		int exchange_count_;								//单位兑换
		uint32 cannon_mulriple_[MAX_CANNON_TYPE];			//大炮倍数
		uint32 mulriple_count_;								//倍数
		uint16 scene_special_time_;							//特殊鱼阵时间（未使用 禁止开炮）
		Role_Net_Object role_objects_[GAME_PLAYER];			//玩家信息
		Bullet_Config bullet_config_[BULLET_KIND_COUNT];	//子弹配置
		uint16 energy_value_[MAX_BIRD_TYPE];				//每条鱼的能量值
		uint16 energy_countdown_;							//能量炮发射倒计时
		uint32    wServerID;                                 //房间ID


	};


	struct CMD_S_TimeCheck
	{
		uint16 chair_id_;	///< 椅子od
		uint32 client_time_; ///< 链接时间(用户)
		uint32 server_time_; ///< 服务器时间
	};

	struct CMD_C_TimeCheck
	{
		uint16 chair_id_;
		uint32 time_;
		bool is_game_status_; ///< 游戏状态
	};

	struct CMD_S_OrderTimeCheck
	{
		uint16 chair_id_;
	};

	struct CMD_S_Send_Bullet
	{
		uint32 id_;   ///< id
		uint8 scened_; ///< 场景
		float rotation_; ///< 角度
		xPoint position_;  ///< 位置
		uint16 cannon_type_; ///< 大炮类型
		uint16 chair_id_; ///< 椅子id

		uint32 time_;	///< 时间
		float speed_;	///< 速度
		uint32 bullet_mulriple;	//当前子弹赔率
		int lock_bird_id_; ///< 锁定的鱼
	};

	struct CMD_S_Send_Bird
	{
		uint32	id_; ///< id
		uint8		type_;  ///< 类型
		uint8		item_; ///< 特效 如果是闪电鱼 红鱼 此项代表鱼类型
		uint16	path_id_;	///< 路径id
		uint8		path_type_; ///< 路径类型
		float		path_delay_; ///< 路径延长
		xPoint		path_offset_; ///< 路径偏移
		float		elapsed_; ///< 逝去时间
		float		speed_; ///< 速度

		uint32		time_; ///< 时间
		uint32	gold_; ///< 金币
	};


	struct CMD_S_Send_Bird_Linear
	{
		uint32 id_;	///< id
		uint8 type_; ///< 类型
		uint8 item_; ///< 特效
		float path_delay_; ///< 路径延迟
		float elapsed_; ///< 逝去的时间
		float speed_; ///< 速度

		xPoint start_; ///< 开始位置
		xPoint end_; ///< 结束位置

		uint32 time_; ///< 时间
		uint32 gold_; ///< 金币
	};

	struct CMD_S_Send_Bird_Pause_Linear
	{
		uint32 id_;
		uint8 type_;
		uint8 item_;
		float path_delay_;
		float elapsed_;
		float speed_;
		float start_angle_;

		xPoint start_;
		xPoint pause_;
		xPoint end_;
		float pause_time_;

		uint32 time_;
		uint32 gold_;
	};

	struct CMD_S_Send_Bird_Round
	{
		uint32 id_; ///< id
		uint8 type_; ///< 鱼类型
		uint8 item_; ///< 鱼特效
		float path_delay_; ///< 路径延迟
		float elapsed_; ///< 时间延迟
		float speed_; ///< 速度

		xPoint center_; ///< 中心店
		float radius_; ///< 半径
		float rotate_duration_; ///< 旋转时间
		float start_angle_; ///< 开始角度
		float rotate_angle_; ///< 旋转角度
		float move_duration_; ///< 移动时间

		uint32 time_; ///< 时间
		uint32 gold_; ///< 金币
	};

	// 鱼特效
	struct CMD_S_Bird_Effect
	{
		//uint16	chair_id_;
		uint8		effect_;	// 1:金币x2 2:Lucky概率加成
		uint8		bird_id_;	// 非0打中的鱼id, 0:特效结束
		//xPoint		pt_brid_;	// 位置
	};


	struct CMD_C_Buy_Bullet
	{
		int64 count_;
	};

	struct CMD_S_Buy_Bullet_Success
	{
		int64 count_;
		uint16 chair_id_;
	};

	struct CMD_S_Buy_Bullet_Failed
	{
		uint16 chair_id_;
		char reason_[32];
	};

	struct CMD_C_Fire
	{
		float rote_;  ///< 开火, 角度

		uint32 time_; ///< 时间
		float speed_; ///< 速度
		uint32 bullet_mulriple_; ///< 子弹倍数
		int lock_bird_id_;			//锁定鱼id
		uint16 bullet_type; ///< 子弹类型
	};

	struct CMD_S_Fire_Failed
	{
		uint16 chair_id_;
	};

	///< 抓住鱼
	struct CMD_S_Catch_Bird
	{
		uint16 chair_id_;	///< 椅子id
		uint16 cannon_type_; ///< 大炮类型
		uint32 catch_gold_; ///< 抓住金钱
		uint32 bird_id_; ///< 鱼id
		uint16 award_type_; ///< 奖励类型
		uint16 award_count_; ///< 奖励数量
		uint32 medal_; ///< 奖章
		//	uint32 link_bird_id_; ///< 链接鱼的id
	};

	///< 抓住特殊鱼,只在普通类里面使用.
	struct CMD_S_Special_Catch_Bird
	{
		uint16 chair_id_;	///< 椅子id
		uint16 cannon_type_; ///< 大炮类型
		uint32 catch_gold_; ///< 抓住金钱
		uint32 bird_id_; ///< 鱼id
		uint16 award_type_; ///< 奖励类型
		uint16 award_count_; ///< 奖励数量
		uint32 medal_; ///< 奖章
		int link_bird_id_; ///< 链接鱼的id
		uint32 thread_id; ///< 线程id
	};

	struct Catch_Bird
	{
		uint32 catch_gold_; ///< 抓住金币
		uint32 bird_id_; ///< 抓住鱼id
		uint16 award_type_; ///< 奖励类型
		uint16 award_count_; ///< 奖励数量
		uint32 medal_; ///< 奖章
		int link_bird_id_; ///< 链接的鱼id
	};





	struct CMD_S_FishAndisNick
	{

		WORD    szChairID;                  //ID
		TCHAR	szNickName[32];			//用户昵称

	};


	struct CMD_S_Catch_Bird_Group
	{
		uint8 count_; //对齐
		uint8 chair_id_; ///< 椅子id
		uint16 cannon_type_; ///< 大炮类型

		Catch_Bird catch_bird_[MAX_BIRD_CATCH]; ///< 抓住鱼的集合
		uint32 bullet_id; ///< 子弹id
	};

	//闪电鱼
	struct CMD_S_Catch_Bird_Chain
	{
		uint8 count_;	///< 数量
		uint16 chair_id_; ///< 椅子id
		uint16 cannon_type_; ///< 大炮类型
		Catch_Bird catch_bird_[MAX_BIRD_CATCH_CHAIN];
		uint32 bullet_id_; ///< 子弹id
	};

	struct CMD_C_Change_Cannon
	{
		uint16 cannon_type_; ///< 大炮类型
	};


	struct CMD_S_Change_Cannon
	{
		uint16 chair_id_;	///< 椅子类型
		uint16 cannon_type_; ///< 大炮类型
		uint16 level_;
		xPoint pt_brid_; ///< 射的鱼位置?
	};


	struct CMD_S_Change_Energy_Cannon
	{
		uint16 chair_id_;	///< 椅子id
		uint8 energy_cannon_; ///< 能量大炮
		xPoint pt_brid_;	///< 鱼位置
	};

	struct CMD_C_Account
	{
		uint16 chair_id_; ///< 椅子id
	};

	struct CMD_S_Account
	{
		uint16 chair_id_; ///< 椅子id
		int64 gold_left; ///< 左边的金币(错误的金币?)
	};

	struct CMD_S_Change_Scene
	{
		uint8 scene_;	///< 场景
		uint16 special_time;   //特殊鱼阵时间
	};


	//新加前控
	struct CMD_C_StockOperate
	{
		uint8 operate_code;			//0 查询   1增加  2减少  3清零
		int range_index;				//  标记 增加减少的是哪一个
	};

	struct CMD_S_StockOperateResult {
		int stock_range[kMaxRangeCount];
		int range_count;
		uint64 stock_score[kMaxRangeCount + 1];
	};

	struct CMD_C_RBL_Control
	{
		uint8 operate_RBL;				//0黑名单 1白名单
		dword game_id;						//玩家id
		uint64 limit_score;				//限制分数
		uint8 operate_code;				//0查询 1设置  2 删除
	};

	//查询返回
	struct CMD_S_RBL_Control {
		uint8 operate_RBL;			// 0 黑名单 1 白名单
		dword game_id[30];				//名单列表
		int id_count;					//名单数量 最大30
	};

	struct CMD_C_GiveAway_Control
	{
		dword game_id;
		uint8 bird_type[MAX_BIRD_TYPE];		//赠送鱼的类型
		int type_count;							//类型数量
		int	catch_count;						//鱼数量
		float catch_probability;				//捕获概率
	};

	struct CMD_C_Difficulty
	{
		uint8 operate_code;			//0 查询 1设置
		dword game_id;
		int difficulty;					//难度
	};

	struct CMD_S_Difficulty {
		int dificulty;
	};

	//--------任务
	//任务开启
	struct CMD_S_Task_Open
	{
		uint16 type_;					//任务类型 （个人金币/元宝 全场金币/元宝）
		uint16 bird_type;				//鱼种
		uint16 capture_count;			//需要捕获的数量
		uint16 chair_id_;				//玩家
		uint16 time_;					//个人任务倒计时时间
		dword reward_;					//任务奖励
	};

	struct CMD_S_Task_Finish
	{
		uint16 type_;					//任务类型 （个人金币/元宝 全场金币/元宝）
		//uint16 bird_type;				//鱼种
		uint16 chair_id_;				//玩家
		dword reward_;					//任务奖励	为0时表示任务没有完成，但是时间到了
	};


	///< 完成鱼的数量,只在本地使用
	struct CMD_S_TaskCount
	{
		int		type;		//0:房间任务 1:个人任务 2:桌子任务
		int		bird_type;		// 鱼种类(-1, 没任务)
		int		count;		// 所抓鱼数量
	};




































	///< 下面的都是没有出现的结构,服务器上面

	struct CMD_S_Bird_Boss
	{
		int bird_item_; // 出现的boss
	};










	////////////////////////////////////////////////////////////////////////////////
#define MAX_WEAPON_MAIN_LEVEL	5
#define MAX_WEAPON_SUB_LEVEL	5

	struct WeaponInfo
	{
		//强化成功概率
		int qh_success_show;
		//强化游戏币消耗
		int qh_cost;
		//触发时间
		int cast_time;
		//效果时间
		int effect_time;
		//技能类型
		int skills[5];
		//概率加成
		int adds[5];
		//战斗力
		int powers[5];
	};

	struct CMD_S_WeaponInfo
	{
		WeaponInfo weapons_[MAX_WEAPON_MAIN_LEVEL];
	};

	struct CMD_S_WeaponLevel
	{
		uint16 chair_id_;
		uint16 level_;
	};

	struct CMD_S_Treasure
	{
		int64 treasure_;
	};

	struct CMD_S_Skill
	{
		uint16 chair_id_;
		uint8  cast_;
		uint8  skill_;
	};

	struct CMD_S_StrengthenResult
	{
		uint8 iResult;	//-1:未知错误,无法强化 0:成功,1:强化失败 2:满级不需要强化 3:金币不足
	};

	////////////////////////////////////////////////////////////////////////////////

	struct CMD_C_UserFilter {
		dword user_id; // 0 获取列表
		unsigned char operate_code; // 0 黑名单 1 白名单 2 清除
	};


	struct CMD_S_Black_White
	{
		dword user_id;
		int code;
	};

	struct CMD_C_Stroage {
		int iMode;	// 0:查询 1:设置
		longlong lValue;
	};

	struct CMD_S_Stroage {
		longlong lValue;
	};

	// 配置重载
	struct CMD_C_ConfigReload
	{
		int type;
	};

	/////////////////////////////////////////////////////////////////////////////
	// 悬赏任务
	struct CMD_S_TaskReward
	{
		int AwardType[MAX_BIRD_TYPE];
		int AwardCount[MAX_BIRD_TYPE];
	};

	struct CMD_S_Task
	{
		int		type;		//0:房间任务 1:个人任务 2:桌子任务

		int		startTime;	// 开始时间
		int		curTime;	// 当前时间

		// 任务信息
		int		taskId;		// 任务ID
		int		kind;		// 鱼种类(-1, 没任务)
		int		time;		// 任务时间(秒)
		int		count;		// 所需鱼数量
		int		award;		// 奖励类型,0:活力 1:奖牌 2:星豆
		int		awardCount;	// 奖励数量
	};


	struct CMD_S_TaskComplete
	{
		int		type;		//0:房间任务 1:个人任务 2:桌子任务
		int		awardType;	//奖励类型
		int		awardCount;	//奖励数量
		int		data;		//其它数据
	};

	///////////////////////////////////////////////////////////////////////////
	struct CMD_S_RankInfo
	{
		SCORE catch_score_;
		SCORE score_;
	};

	struct CMD_S_RankList
	{
		dword		dwRefreshTime;	//刷新间隔
		word		wRanks;			//个数
		tagRankItem	items[10];	    //最多10个
		SCORE		lScores[10];	//奖励
	};



#pragma pack(pop)
	//////////////////////////////////////////////////////////////////////////
}
#endif
