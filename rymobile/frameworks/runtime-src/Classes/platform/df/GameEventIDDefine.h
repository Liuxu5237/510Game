#ifndef _GAME_EVENT_ID_DEFINE_FILE
#define _GAME_EVENT_ID_DEFINE_FILE

// 关闭游戏场景
#define GAME_EVENT_ID_CLOSE_GAME_CLIENT		(1)

// 游戏从后台切入到前台
#define GAME_EVENT_ID_ENTER_FOREGROUND		(2)

// 进入重连状态
#define GAME_EVENT_ID_DETECT_NET_DOWN		(3)

// 游戏关闭
#define GAME_EVENT_ID_GAME_CLOSE			(4)

// 离开游戏确认
#define GAME_EVENT_ID_CLOSE_GAME_CONFIRM	(5)

// 游戏金币不够
#define GAME_EVENT_ID_GOLD_NOT_ENOUGH		(6)

// 重连发生错误
#define GAME_EVENT_ID_RECONNECT_NET_ERROR		(7)

// 重连未知错误
#define GAME_EVENT_ID_RECONNECT_UNKNOWN		(8)

// 重新检测到网络
#define GAME_EVENT_ID_DETECT_NET_AGAIN		(9)

// 连接网络超时
#define GAME_EVENT_ID_DETECT_NET_TIME_OUT	(10)

// 显示充值界面
#define	GAME_EVENT_ID_SHOW_PAY				(11)

// 服务器通知关闭客户端
#define GAME_EVENT_ID_SERVER_NOTIFY_CLOSE_CLIENT	(12)

// 发送系统消息
#define GAME_EVENT_ID_SYSTEM_MSG			(13)

//收到房间的系统消息
#define GAME_EVENT_ID_SUB_SYSTEM_MSG		(14)

//下载头像
#define GAME_EVENT_ID_DOWN_HTTPIMG			(15)

#endif