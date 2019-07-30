#ifndef _ROOM_EVENT_ID_DEFINE_FILE
#define _ROOM_EVENT_ID_DEFINE_FILE

// 请求失败
#define ROOM_EVENT_ID_REQUEST_FAILURE		(1)
// 登陆成功
#define ROOM_EVENT_ID_LOGON_SUCCESS			(2)
// 登陆失败
#define ROOM_EVENT_ID_LOGON_FAILURE			(3)
// 登陆完成
#define ROOM_EVENT_ID_LOGON_FINISH			(4)
// 更新通知
#define ROOM_EVENT_ID_UPDATE_NOTIFY			(5)

// 列表配置
#define ROOM_EVENT_ID_CONFIG_COLUMN			(6)
// 房间配置
#define ROOM_EVENT_ID_CONFIG_SERVER			(7)
// 道具配置
#define ROOM_EVENT_ID_CONFIG_PROPERTY		(8)
// 玩家权限配置
#define ROOM_EVENT_ID_CONFIG_USER_RIGHT		(9)
// 配置完成
#define ROOM_EVENT_ID_CONFIG_FINISH			(10)

// 用户进入
#define ROOM_EVENT_ID_USER_ENTER			(11)
// 用户更新 玩家自己
#define ROOM_EVENT_ID_USER_ME_UPDATE		(12)
// 用户更新 
#define ROOM_EVENT_ID_USER_OTHER_UPDATE		(13)
// 用户删除
#define ROOM_EVENT_ID_USER_DELETE			(14)
// 用户邀请
#define ROOM_EVENT_ID_USER_INVITE			(15)

// 用户邀请失败
#define ROOM_EVENT_ID_USER_INVITE_FAILURE	(16)
// 服务器关闭
#define ROOM_EVENT_ID_SERVER_CLOSE			(17)
// 链接服务器失败
#define ROOM_EVENT_ID_CONNECT_SERVER_ERROR	(18)
// 游戏初始化成功
#define ROOM_EVENT_ID_GAME_INIT_SUCC		(19)
// 游戏初始化失败
#define ROOM_EVENT_ID_GAME_INIT_FAILURE		(20)

// 开始游戏
#define ROOM_EVENT_ID_START_GAME			(21)
// 游戏关闭 正常
#define ROOM_EVENT_ID_GAME_CLOSE			(22)
// 比赛人数更新
#define ROOM_EVENT_ID_MATCH_NUM				(23)
// 比赛状态
#define ROOM_EVENT_ID_MATCH_STATUS			(24)
// 比赛报名费用
#define ROOM_EVENT_ID_MATCH_SIGN_FEE		(25)

// 插入系统字符
#define ROOM_EVENT_ID_INSERT_SYSTEM_STR		(26)
// 插入提示字符
#define ROOM_EVENT_ID_PROMPT_STR			(27)
// 公告消息
#define ROOM_EVENT_ID_AFFICHE_STR			(28)
// 插入喜宝字符
#define ROOM_EVENT_ID_GLAD_STRING			(29)
// 链接服务器
#define ROOM_EVENT_ID_ON_CONNECT_SERVER		(30)

//快速坐下椅子处理 
#define ROOM_EVENT_ID_QUICK_SIT_DOWN		(31)

// 支付回调
#define ROOM_EVENT_ID_PAY_RESULT			(32)

// 创建commonui
#define ROOM_EVENT_ID_CREATE_COMMON_UI		(33)

// 微信登录
#define ROOM_EVENT_ID_WEBCHATLOGIN			(34)

// 微信绑定
#define ROOM_EVENT_ID_WEBCHATBIND			(35)

// 下载网络图片
#define ROOM_EVENT_ID_LOADURLIMAGE			(36)

//创建房卡模式的共通的ui
#define ROOM_EVENT_ID_PRIVATE_COMMON_UI      (37)

#define ROOM_EVENT_ID_RECHARGE				(38)

#endif