#ifndef CMD_GAME_SERVER_HEAD_FILE
#define CMD_GAME_SERVER_HEAD_FILE

#include "../df/datastream.h"
#include "platform/msg/CMD_LogonServer.h"
#pragma pack(push)
#pragma pack(1)

//////////////////////////////////////////////////////////////////////////////////
//登录命令

#define MDM_GR_LOGON				1									//登录信息

//登录模式
#define SUB_GR_LOGON_USERID			1									//I D 登录
#define SUB_GR_LOGON_MOBILE			2									//手机登录
#define SUB_GR_LOGON_ACCOUNTS		3									//帐户登录

//登录结果
#define SUB_GR_LOGON_SUCCESS		100									//登录成功
#define SUB_GR_LOGON_FAILURE		101									//登录失败
#define SUB_GR_LOGON_FINISH			102									//登录完成

//升级提示
#define SUB_GR_UPDATE_NOTIFY		200									//升级提示

//最大排行榜显示数量
#define MAX_MATCH_SHOW_NUMBER 10	

//////////////////////////////////////////////////////////////////////////////////
//
////I D 登录
//struct CMD_GR_LogonUserID
//{
//	//版本信息
//	dword							dwPlazaVersion;						//广场版本
//	dword							dwFrameVersion;						//框架版本
//	dword							dwProcessVersion;					//进程版本
//
//	//登录信息
//	dword							dwUserID;							//用户 I D
//	tchar							szPassword[LEN_MD5];				//登录密码
//	tchar							szMachineID[LEN_MACHINE_ID];		//机器序列
//	word							wKindID;							//类型索引
//};
//
////手机登录
//struct CMD_GR_LogonMobile
//{
//	//版本信息
//	word							wGameID;							//游戏标识
//	dword							dwProcessVersion;					//进程版本
//
//	//桌子区域
//	byte                            cbDeviceType;                       //设备类型
//	word                            wBehaviorFlags;                     //行为标识
//	word                            wPageTableCount;                    //分页桌数
//
//	//登录信息
//	dword							dwUserID;							//用户 I D
//	tchar							szPassword[LEN_MD5];				//登录密码
//	tchar							szMachineID[LEN_MACHINE_ID];		//机器标识
//};
//
////帐号登录
//struct CMD_GR_LogonAccounts
//{
//	//版本信息
//	dword							dwPlazaVersion;						//广场版本
//	dword							dwFrameVersion;						//框架版本
//	dword							dwProcessVersion;					//进程版本
//
//	//登录信息
//	tchar							szPassword[LEN_MD5];				//登录密码
//	tchar							szAccounts[LEN_ACCOUNTS];			//登录帐号
//	tchar							szMachineID[LEN_MACHINE_ID];		//机器序列
//};
//
////登录成功
//struct CMD_GR_LogonSuccess
//{
//	dword							dwUserRight;						//用户权限
//	dword							dwMasterRight;						//管理权限
//};
//
////登录失败
//struct CMD_GR_LogonFailure
//{
//	long							lErrorCode;							//错误代码
//	tchar							szDescribeString[128];				//描述消息
//};
//
////升级提示
//struct CMD_GR_UpdateNotify
//{
//	//升级标志
//	byte							cbMustUpdatePlaza;					//强行升级
//	byte							cbMustUpdateClient;					//强行升级
//	byte							cbAdviceUpdateClient;				//建议升级
//
//	//当前版本
//	dword							dwCurrentPlazaVersion;				//当前版本
//	dword							dwCurrentFrameVersion;				//当前版本
//	dword							dwCurrentClientVersion;				//当前版本
//};

//////////////////////////////////////////////////////////////////////////////////
//配置命令

#define MDM_GR_CONFIG				2									//配置信息

#define SUB_GR_CONFIG_COLUMN		100									//列表配置
#define SUB_GR_CONFIG_SERVER		101									//房间配置
#define SUB_GR_CONFIG_PROPERTY		102									//道具配置
#define SUB_GR_CONFIG_FINISH		103									//配置完成
#define SUB_GR_CONFIG_USER_RIGHT	104									//玩家权限

//////////////////////////////////////////////////////////////////////////////////
//
////列表配置
//struct CMD_GR_ConfigColumn
//{
//	byte							cbColumnCount;						//列表数目
//	tagColumnItem					ColumnItem[MAX_COLUMN];				//列表描述
//};
//
////房间配置
//struct CMD_GR_ConfigServer
//{
//	//房间属性
//	word							wTableCount;						//桌子数目
//	word							wChairCount;						//椅子数目
//
//	//房间配置
//	word							wServerType;						//房间类型
//	dword							dwServerRule;						//房间规则
//};
//
////道具配置
//struct CMD_GR_ConfigProperty
//{
//	byte							cbPropertyCount;					//道具数目
//	tagPropertyInfo					PropertyInfo[MAX_PROPERTY];			//道具描述
//};
//
////玩家权限
//struct CMD_GR_ConfigUserRight
//{
//	dword							dwUserRight;						//玩家权限
//};
//////////////////////////////////////////////////////////////////////////////////
//用户命令

struct tagUserTalk
{
	byte	cbType;
	byte	cbChairID;
	char	strString[128];
	int		strTalkSize;
	char	strTalkData[20000];
};

//用户语音聊天
class CMD_GR_C_TableTalk : public cocos2d::Ref
{
public:
	enum TALK_TYPE
	{
		TYPE_FILE,        //语音
		TYPE_WORD,
		TYPE_DEFINE,		//系统语音
		TYPE_BIAOQING,
	};
	CMD_GR_C_TableTalk()
	{
		cbType = 0;
		cbChairID = (byte)(INVALID_CHAIR);
		strTalkSize = 0;
		zeromemory(strString,sizeof(strString));
		zeromemory(strTalkData,sizeof(strTalkData));
	}

	CC_SET_AND_GET(byte,cbType,Type)
	CC_SET_AND_GET(byte,cbChairID,ChairID)
	CC_SET_AND_GET_CHAR_ARRAY(128, strString, String)
	CC_SET_AND_GET(int,strTalkSize,TalkSize)
	CC_SET_AND_GET_CHAR_ARRAY(20000,strTalkData,TalkData)
};

#define MDM_GR_USER					3									//用户信息

//用户动作
#define SUB_GR_USER_RULE			1									//用户规则
#define SUB_GR_USER_LOOKON			2									//旁观请求
#define SUB_GR_USER_SITDOWN			3									//坐下请求
#define SUB_GR_USER_STANDUP			4									//起立请求
#define SUB_GR_USER_INVITE			5									//用户邀请
#define SUB_GR_USER_INVITE_REQ		6									//邀请请求
#define SUB_GR_USER_REPULSE_SIT  	7									//拒绝玩家坐下
#define SUB_GR_USER_KICK_USER       8                                   //踢出用户
#define SUB_GR_USER_INFO_REQ        9                                   //请求用户信息
#define SUB_GR_USER_CHAIR_REQ       10                                  //请求更换位置
#define SUB_GR_USER_CHAIR_INFO_REQ  11                                  //请求椅子用户信息
#define SUB_GR_USER_WAIT_DISTRIBUTE 12									//等待分配
#define SUB_GR_USER_UNDO_TRUSTEE		13                 //取消托管
#define SUB_GR_USER_MsgBack				14                 //取消托管
#define SUB_GR_USER_REQUEST_QUIT		15                 //请求退出
#define SUB_GR_USER_REQUEST_QUIT_HALL	16                 //请求退出,大厅请求

//用户状态
#define SUB_GR_USER_ENTER			100									//用户进入
#define SUB_GR_USER_SCORE			101									//用户分数
#define SUB_GR_USER_STATUS			102									//用户状态
#define SUB_GR_REQUEST_FAILURE		103									//请求失败
#define SUB_GR_USER_ENTER_SIMPLE		104								//用户进入

//聊天命令
#define SUB_GR_USER_CHAT			201									//聊天消息
#define SUB_GR_USER_EXPRESSION		202									//表情消息
#define SUB_GR_WISPER_CHAT			203									//私聊消息
#define SUB_GR_WISPER_EXPRESSION	204									//私聊表情
#define SUB_GR_COLLOQUY_CHAT		205									//会话消息
#define SUB_GR_COLLOQUY_EXPRESSION	206									//会话表情

//道具命令
#define SUB_GR_PROPERTY_BUY			300									//购买道具
#define SUB_GR_PROPERTY_SUCCESS		301									//道具成功
#define SUB_GR_PROPERTY_FAILURE		302									//道具失败
#define SUB_GR_PROPERTY_MESSAGE     303                                 //道具消息
#define SUB_GR_PROPERTY_EFFECT      304                                 //道具效应
#define SUB_GR_PROPERTY_TRUMPET		305                                 //喇叭消息

#define SUB_GR_GLAD_MESSAGE			400                                 //喜报消息

//////////////////////////////////////////////////////////////////////////////////
//
////旁观请求
//struct CMD_GR_UserLookon
//{
//	word							wTableID;							//桌子位置
//	word							wChairID;							//椅子位置
//};
//
//坐下请求
struct CMD_GR_UserSitDown
{
	word							wTableID;							//桌子位置
	word							wChairID;							//椅子位置
	tchar							szPassword[LEN_PASSWORD];			//桌子密码
};
//
//起立请求
struct CMD_GR_UserStandUp
{
	word							wTableID;							//桌子位置
	word							wChairID;							//椅子位置
	byte							cbForceLeave;						//强行离开
};
//
////邀请用户 
//struct CMD_GR_UserInvite
//{
//	word							wTableID;							//桌子号码
//	dword							dwUserID;							//用户 I D
//};
//
////邀请用户请求 
//struct CMD_GR_UserInviteReq
//{
//	word							wTableID;							//桌子号码
//	dword							dwUserID;							//用户 I D
//};
//
////用户分数
//struct CMD_GR_UserScore
//{
//	dword							dwUserID;							//用户标识
//	tagUserScore					UserScore;							//积分信息
//};
//
////用户分数
//struct CMD_GR_MobileUserScore
//{
//	dword							dwUserID;							//用户标识
//	tagMobileUserScore				UserScore;							//积分信息
//};
//
////用户状态
//struct CMD_GR_UserStatus
//{
//	dword							dwUserID;							//用户标识
//	tagUserStatus					UserStatus;							//用户状态
//};
//
////请求失败
//struct CMD_GR_RequestFailure
//{
//	long							lErrorCode;							//错误代码
//	tchar							szDescribeString[256];				//描述信息
//};
//
//
////用户聊天
//struct CMD_GR_C_UserChat
//{
//	word							wChatLength;						//信息长度
//	dword							dwChatColor;						//信息颜色
//	dword							dwTargetUserID;						//目标用户
//	tchar							szChatString[LEN_USER_CHAT];		//聊天信息
//};
//
////用户聊天
//struct CMD_GR_S_UserChat
//{
//	word							wChatLength;						//信息长度
//	dword							dwChatColor;						//信息颜色
//	dword							dwSendUserID;						//发送用户
//	dword							dwTargetUserID;						//目标用户
//	tchar							szChatString[LEN_USER_CHAT];		//聊天信息
//};
//
////用户表情
//struct CMD_GR_C_UserExpression
//{
//	word							wItemIndex;							//表情索引
//	dword							dwTargetUserID;						//目标用户
//};
//
////用户表情
//struct CMD_GR_S_UserExpression
//{
//	word							wItemIndex;							//表情索引
//	dword							dwSendUserID;						//发送用户
//	dword							dwTargetUserID;						//目标用户
//};
//
////用户私聊
//struct CMD_GR_C_WisperChat
//{
//	word							wChatLength;						//信息长度
//	dword							dwChatColor;						//信息颜色
//	dword							dwTargetUserID;						//目标用户
//	tchar							szChatString[LEN_USER_CHAT];		//聊天信息
//};
//
////用户私聊
//struct CMD_GR_S_WisperChat
//{
//	word							wChatLength;						//信息长度
//	dword							dwChatColor;						//信息颜色
//	dword							dwSendUserID;						//发送用户
//	dword							dwTargetUserID;						//目标用户
//	tchar							szChatString[LEN_USER_CHAT];		//聊天信息
//};
//
////私聊表情
//struct CMD_GR_C_WisperExpression
//{
//	word							wItemIndex;							//表情索引
//	dword							dwTargetUserID;						//目标用户
//};
//
////私聊表情
//struct CMD_GR_S_WisperExpression
//{
//	word							wItemIndex;							//表情索引
//	dword							dwSendUserID;						//发送用户
//	dword							dwTargetUserID;						//目标用户
//};
//
////用户会话
//struct CMD_GR_ColloquyChat
//{
//	word							wChatLength;						//信息长度
//	dword							dwChatColor;						//信息颜色
//	dword							dwSendUserID;						//发送用户
//	dword							dwConversationID;					//会话标识
//	dword							dwTargetUserID[16];					//目标用户
//	tchar							szChatString[LEN_USER_CHAT];		//聊天信息
//};
//
////邀请用户
//struct CMD_GR_C_InviteUser
//{
//	word							wTableID;							//桌子号码
//	dword							dwSendUserID;						//发送用户
//};
//
////邀请用户
//struct CMD_GR_S_InviteUser
//{
//	dword							dwTargetUserID;						//目标用户
//};
//
////购买道具
//struct CMD_GR_C_PropertyBuy
//{
//	byte                            cbRequestArea;						//请求范围
//	byte							cbConsumeScore;						//积分消费
//	word							wItemCount;							//购买数目
//	word							wPropertyIndex;						//道具索引	
//	dword							dwTargetUserID;						//使用对象
//};
//
////道具成功
//struct CMD_GR_S_PropertySuccess
//{
//	byte                            cbRequestArea;						//使用环境
//	word							wItemCount;							//购买数目
//	word							wPropertyIndex;						//道具索引
//	dword							dwSourceUserID;						//目标对象
//	dword							dwTargetUserID;						//使用对象
//};
//
////道具失败
//struct CMD_GR_PropertyFailure
//{
//	word                            wRequestArea;                       //请求区域
//	long							lErrorCode;							//错误代码
//	tchar							szDescribeString[256];				//描述信息
//};
//
////道具消息
//struct CMD_GR_S_PropertyMessage
//{
//	//道具信息
//	word                            wPropertyIndex;                     //道具索引
//	word                            wPropertyCount;                     //道具数目
//	dword                           dwSourceUserID;                     //目标对象
//	dword                           dwTargerUserID;                     //使用对象
//};
//
//
////道具效应
//struct CMD_GR_S_PropertyEffect
//{
//	dword                           wUserID;					        //用 户I D
//	byte							cbMemberOrder;						//会员等级
//};
//
////发送喇叭
//struct CMD_GR_C_SendTrumpet
//{
//	byte                           cbRequestArea;                        //请求范围 
//	word                           wPropertyIndex;                      //道具索引 
//	dword                          TrumpetColor;                        //喇叭颜色
//	tchar                          szTrumpetContent[TRUMPET_MAX_CHAR];  //喇叭内容
//};
//
////发送喇叭
//struct CMD_GR_S_SendTrumpet
//{
//	word                           wPropertyIndex;                      //道具索引 
//	dword                          dwSendUserID;                         //用户 I D
//	dword                          TrumpetColor;                        //喇叭颜色
//	tchar                          szSendNickName[32];				    //玩家昵称 
//	tchar                          szTrumpetContent[TRUMPET_MAX_CHAR];  //喇叭内容
//};
//
//
////用户拒绝黑名单坐下
//struct CMD_GR_UserRepulseSit
//{
//	word							wTableID;							//桌子号码
//	word							wChairID;							//椅子位置
//	dword							dwUserID;							//用户 I D
//	dword							dwRepulseUserID;					//用户 I D
//};

//////////////////////////////////////////////////////////////////////////////////

//规则标志
#define UR_LIMIT_SAME_IP			0x01								//限制地址
#define UR_LIMIT_WIN_RATE			0x02								//限制胜率
#define UR_LIMIT_FLEE_RATE			0x04								//限制逃率
#define UR_LIMIT_GAME_SCORE			0x08								//限制积分
//
////用户规则
//struct CMD_GR_UserRule
//{
//	byte							cbRuleMask;							//规则掩码
//	word							wMinWinRate;						//最低胜率
//	word							wMaxFleeRate;						//最高逃率
//	long							lMaxGameScore;						//最高分数 
//	long							lMinGameScore;						//最低分数
//};
//
////请求用户信息
//struct CMD_GR_UserInfoReq
//{
//	dword                           dwUserIDReq;                        //请求用户
//	word							wTablePos;							//桌子位置
//};
//
////请求用户信息
//struct CMD_GR_ChairUserInfoReq
//{
//	word							wTableID;							//桌子号码
//	word							wChairID;							//椅子位置
//};
//////////////////////////////////////////////////////////////////////////////////
//状态命令

#define MDM_GR_STATUS				4									//状态信息

#define SUB_GR_TABLE_INFO			100									//桌子信息
#define SUB_GR_TABLE_STATUS			101									//桌子状态

//////////////////////////////////////////////////////////////////////////////////
//
////桌子信息
//struct CMD_GR_TableInfo
//{
//	word							wTableCount;						//桌子数目
//	tagTableStatus					TableStatusArray[512];				//桌子状态
//};
//
////桌子状态
//struct CMD_GR_TableStatus
//{
//	word							wTableID;							//桌子号码
//	tagTableStatus					TableStatus;						//桌子状态
//};

//////////////////////////////////////////////////////////////////////////////////
//银行命令

#define MDM_GR_INSURE				5									//用户信息

//银行命令
#define SUB_GR_QUERY_INSURE_INFO	1									//查询银行
#define SUB_GR_SAVE_SCORE_REQUEST	2									//存款操作
#define SUB_GR_TAKE_SCORE_REQUEST	3									//取款操作
#define SUB_GR_TRANSFER_SCORE_REQUEST	4								//取款操作
#define SUB_GR_QUERY_USER_INFO_REQUEST	5								//查询用户

#define SUB_GR_USER_INSURE_INFO		100									//银行资料
#define SUB_GR_USER_INSURE_SUCCESS	101									//银行成功
#define SUB_GR_USER_INSURE_FAILURE	102									//银行失败
#define SUB_GR_USER_TRANSFER_USER_INFO	103								//用户资料

//////////////////////////////////////////////////////////////////////////////////
//
////查询银行
//struct CMD_GR_C_QueryInsureInfoRequest
//{
//	byte                            cbActivityGame;                     //游戏动作
//};
//
////存款请求
//struct CMD_GR_C_SaveScoreRequest
//{
//	byte                            cbActivityGame;                     //游戏动作
//	SCORE							lSaveScore;							//存款数目
//};
//
////取款请求
//struct CMD_GR_C_TakeScoreRequest
//{
//	byte                            cbActivityGame;                     //游戏动作
//	SCORE							lTakeScore;							//取款数目
//	tchar							szInsurePass[LEN_PASSWORD];			//银行密码
//};
//
////转账金币
//struct CMD_GP_C_TransferScoreRequest
//{
//	byte                            cbActivityGame;                     //游戏动作
//	byte                            cbByNickName;                       //昵称赠送
//	SCORE							lTransferScore;						//转账金币
//	tchar							szNickName[LEN_NICKNAME];			//目标用户
//	tchar							szInsurePass[LEN_PASSWORD];			//银行密码
//};
//
////查询用户
//struct CMD_GR_C_QueryUserInfoRequest
//{
//	byte                            cbActivityGame;                     //游戏动作
//	byte                            cbByNickName;                       //昵称赠送
//	tchar							szNickName[LEN_NICKNAME];			//目标用户
//};
//
////银行资料
//struct CMD_GR_S_UserInsureInfo
//{
//	byte                            cbActivityGame;                     //游戏动作
//	word							wRevenueTake;						//税收比例
//	word							wRevenueTransfer;					//税收比例
//	word							wServerID;							//房间标识
//	SCORE							lUserScore;							//用户金币
//	SCORE							lUserInsure;						//银行金币
//	SCORE							lTransferPrerequisite;				//转账条件
//};
//
////银行成功
//struct CMD_GR_S_UserInsureSuccess
//{
//	byte                            cbActivityGame;                     //游戏动作
//	SCORE							lUserScore;							//身上金币
//	SCORE							lUserInsure;						//银行金币
//	tchar							szDescribeString[128];				//描述消息
//};
//
////银行失败
//struct CMD_GR_S_UserInsureFailure
//{
//	byte                            cbActivityGame;                     //游戏动作
//	long							lErrorCode;							//错误代码
//	tchar							szDescribeString[128];				//描述消息
//};
//
////用户信息
//struct CMD_GR_S_UserTransferUserInfo
//{
//	byte                            cbActivityGame;                     //游戏动作
//	dword							dwTargetGameID;						//目标用户
//	tchar							szNickName[LEN_NICKNAME];			//目标用户
//};
//////////////////////////////////////////////////////////////////////////////////
//管理命令

#define MDM_GR_MANAGE				8									//管理命令

#define SUB_GR_SEND_WARNING			1									//发送警告
#define SUB_GR_SEND_MESSAGE			2									//发送消息
#define SUB_GR_LOOK_USER_IP			3									//查看地址
#define SUB_GR_KILL_USER			4									//踢出用户
#define SUB_GR_LIMIT_ACCOUNS		5									//禁用帐户
#define SUB_GR_SET_USER_RIGHT		6									//权限设置

//房间设置
#define SUB_GR_QUERY_OPTION			7									//查询设置
#define SUB_GR_OPTION_SERVER		8									//房间设置
#define SUB_GR_OPTION_CURRENT		9									//当前设置

#define SUB_GR_LIMIT_USER_CHAT		10									//限制聊天

#define SUB_GR_KICK_ALL_USER		11									//踢出用户
#define SUB_GR_DISMISSGAME		    12									//解散游戏

//////////////////////////////////////////////////////////////////////////////////
//
////发送警告
//struct CMD_GR_SendWarning
//{
//	word							wChatLength;						//信息长度
//	dword							dwTargetUserID;						//目标用户
//	tchar							szWarningMessage[LEN_USER_CHAT];	//警告消息
//};
//
////系统消息
//struct CMD_GR_SendMessage
//{
//	byte							cbGame;								//游戏消息
//	byte							cbRoom;								//游戏消息
//	byte							cbAllRoom;							//游戏消息
//	word							wChatLength;						//信息长度
//	tchar							szSystemMessage[LEN_USER_CHAT];		//系统消息
//};
//
////查看地址
//struct CMD_GR_LookUserIP
//{
//	dword							dwTargetUserID;						//目标用户
//};
//
////踢出用户
//struct CMD_GR_KickUser
//{
//	dword							dwTargetUserID;						//目标用户
//};
//
////禁用帐户
//struct CMD_GR_LimitAccounts
//{
//	dword							dwTargetUserID;						//目标用户
//};
//
////权限设置
//struct CMD_GR_SetUserRight
//{
//	//目标用户
//	dword							dwTargetUserID;						//目标用户
//
//	//绑定变量
//	byte							cbGameRight;						//帐号权限
//	byte							cbAccountsRight;					//帐号权限
//
//	//权限变化
//	byte							cbLimitRoomChat;					//大厅聊天
//	byte							cbLimitGameChat;					//游戏聊天
//	byte							cbLimitPlayGame;					//游戏权限
//	byte							cbLimitSendWisper;					//发送消息
//	byte							cbLimitLookonGame;					//旁观权限
//};
//
////房间设置
//struct CMD_GR_OptionCurrent
//{
//	dword							dwRuleMask;							//规则掩码
//	tagServerOptionInfo				ServerOptionInfo;					//房间配置
//};
//
////房间设置
//struct CMD_GR_ServerOption
//{
//	tagServerOptionInfo				ServerOptionInfo;					//房间配置
//};
//
////踢出所有用户
//struct CMD_GR_KickAllUser
//{
//	tchar							szKickMessage[LEN_USER_CHAT];		//踢出提示
//};
//
////解散游戏
//struct CMD_GR_DismissGame
//{
//	word							wDismissTableNum;		            //解散桌号
//};
//////////////////////////////////////////////////////////////////////////////////

//设置标志
#define OSF_ROOM_CHAT				1									//大厅聊天
#define OSF_GAME_CHAT				2									//游戏聊天
#define OSF_ROOM_WISPER				3									//大厅私聊
#define OSF_ENTER_TABLE				4									//进入游戏
#define OSF_ENTER_SERVER			5									//进入房间
#define OSF_SEND_BUGLE				12									//发送喇叭
//
////房间设置
//struct CMD_GR_OptionServer
//{
//	byte							cbOptionFlags;						//设置标志
//	byte							cbOptionValue;						//设置标志
//};
//
////限制聊天
//struct CMD_GR_LimitUserChat
//{
//	dword							dwTargetUserID;						//目标用户
//	byte							cbLimitFlags;						//限制标志
//	byte							cbLimitValue;						//限制与否
//};
//////////////////////////////////////////////////////////////////////////////////
//比赛命令

#define MDM_GR_MATCH				9                 //比赛命令

#define SUB_MATCH_CMD_START			400


#define SUB_GR_MATCH_FEE			400                 //报名费用
#define SUB_GR_MATCH_NUM			401                 //等待人数
#define SUB_GR_LEAVE_MATCH			402                 //退出比赛
#define SUB_GR_MATCH_INFO			403                 //比赛信息
#define SUB_GR_MATCH_WAIT_TIP		404                 //等待提示
#define SUB_GR_MATCH_RESULT			405                 //比赛结果
#define SUB_GR_MATCH_STATUS			406                 //比赛状态
#define SUB_GR_MATCH_DESC			408                 //比赛描述
#define SUB_GR_MATCH_GOLDUPDATE		409                 //金币更新
#define SUB_GR_MATCH_ELIMINATE		410                 //比赛淘汰
#define SUB_GR_MATCH_REWARD			411                 //比赛奖励
#define SUB_GR_MATCH_GETMATCHINFO	412                 //比赛信息
#define SUB_GR_MATCH_RankList		413                 //排行榜


#define SUB_MATCH_CMD_END			500

////////////////改动以下时 请将游戏里面CMD_GAME.H的同时改动////////////////////////////
//#define SUB_GR_MATCH_INFO_ER_SPARROWS	410									//比赛信息(2人麻将)
////赛事信息（2人麻将特有）
//struct CMD_GR_Match_ER_Sparrows
//{
//	word							wALLGameRound;						//总共游戏轮
//	word							wALLGameRoundFan;					//总共游戏翻
//	word							wCurGameRound;						//当前游戏轮
//	word							wCurGameRoundFan;					//当前游戏番
//	word							wLocalGameFan;						//本地游戏番
//	word							wOtherGameFan;						//对家游戏番
//	word							wNextGameRoundFan;					//下轮游戏番
//};
//


//费用提醒
struct CMD_GR_Match_Fee
{
	SCORE             lMatchFee;					//报名费用
	TCHAR             szNotifyContent[128];			//提示内容
};

//比赛人数
struct CMD_GR_Match_Num
{
	dword             dwWaitting;					//等待人数
	dword             dwTotal;						//开赛人数
};

//比赛奖励
struct CMD_GR_Match_Reward
{
	SCORE			lScore[3];		
	dword			dwIngot[3];
};

//赛事信息
struct CMD_GR_Match_Info
{
	TCHAR             szTitle[4][64];				//信息标题
	WORD              wGameCount;					//游戏局数
};


//提示信息
struct CMD_GR_Match_Wait_Tip
{
	SCORE             lScore;						//当前积分
	WORD              wRank;						//当前名次
	WORD              wCurTableRank;				//本桌名次
	WORD              wUserCount;					//当前人数
	WORD              wCurGameCount;				//当前局数
	WORD              wGameCount;					//总共局数
	WORD              wPlayingTable;				//游戏桌数
	WORD			  wOutUserCount;				//淘汰人数
	TCHAR             szMatchName[LEN_SERVER];      //比赛名称
};

//比赛结果
struct CMD_GR_MatchResult
{
	WORD				wGameType;					//游戏类型
	SCORE				lGold;						//金币奖励
	dword				dwIngot;					//元宝奖励
	dword				dwExperience;				//经验奖励
	TCHAR				szUserName[32];				//玩家名字
	TCHAR				szMatchName[32];			//比赛名字
	WORD				wUserRank;					//玩家排名
	WORD				wUserCount;					//玩家人数
};

//比赛排名小结构体
struct CMD_GR_MatchSubRankList
{
	SCORE				lGrade;						//当前成绩
	SCORE				lGold;						//金币奖励
	dword				dwIngot;					//元宝奖励
	dword				dwExperience;				//经验奖励
	TCHAR				szUserName[LEN_NICKNAME];	//玩家名字
	TCHAR				szMatchName[LEN_NICKNAME];	//比赛名字
};

//
#define MAX_MATCH_DESC				4				//最多描述


//比赛排名信息
struct CMD_GR_MatchRankList
{
	WORD					wCount;								//当前的总人数
	CMD_GR_MatchSubRankList sRankData[MAX_MATCH_SHOW_NUMBER];	//排名信息
};

//比赛描述
struct CMD_GR_MatchDesc
{
	TCHAR					szTitle[MAX_MATCH_DESC][16];		//信息标题
	TCHAR					szDescribe[MAX_MATCH_DESC][64];		//描述内容
	dword					crTitleColor;						//标题颜色
	dword					crDescribeColor;					//描述颜色
};

//金币更新
struct CMD_GR_MatchGoldUpdate
{
	SCORE					lCurrGold;					//当前金币
	SCORE					lCurrIngot;					//当前元宝
	dword					dwCurrExprience;			//当前经验
};


//////////////////////////////////////////////////////////////////////////////////
//私人场命令

#define MDM_GR_PRIVATE					10										//比赛命令

#define SUB_GR_PRIVATE_INFO				401									//私人场信息
#define SUB_GR_CREATE_PRIVATE			402									//创建私人场
#define SUB_GR_CREATE_PRIVATE_SUCESS	403									//创建私人场成功
#define SUB_GR_JOIN_PRIVATE				404									//加入私人场
#define SUB_GF_PRIVATE_ROOM_INFO		405									//私人场房间信息
#define SUB_GR_PRIVATE_DISMISS			406									//私人场请求解散
#define SUB_GF_PRIVATE_END				407									//私人场结算
#define SUB_GR_RIVATE_AGAIN				408									//创建私人场
#define SUB_GR_EXIT_SAVE				409									//离开但保存

//私人场信息
struct CMD_GR_Private_Info
{
	word							wKindID;
	SCORE							lCostGold;
	byte							bPlayCout[4];							//玩家局数
	SCORE							lPlayCost[4];							//消耗点数
};

enum RoomType
{
	Type_Private,
	Type_Public,
};

//创建房间
struct CMD_GR_Create_Private
{
	byte							cbGameType;								//游戏类型
	byte							bPlayCoutIdex;							//游戏局数
	byte							bGameTypeIdex;							//游戏类型
	dword							bGameRuleIdex;							//游戏规则
	char							stHttpChannel[LEN_NICKNAME];			//http获取
};

//创建房间
struct CMD_GR_Create_Private_Sucess
{
	SCORE							lCurSocre;								//当前剩余
	dword							dwRoomNum;								//房间ID
};

//创建房间
struct CMD_GR_Join_Private
{
	dword							dwRoomNum;								//房间ID
};

//私人场房间信息
struct CMD_GF_Private_Room_Info
{
	byte			bPlayCoutIdex;		//玩家局数0 1，  8 或者16局
	byte			bGameTypeIdex;		//游戏类型
	dword		bGameRuleIdex;		//游戏规则

	byte			bStartGame;
	dword			dwPlayCout;			//游戏局数
	dword			dwRoomNum;
	dword			dwCreateUserID;
	dword			dwPlayTotal;		//总局数

	byte			cbRoomType;

	std::vector<int>	kWinLoseScore;

	void StreamValue(datastream& kData, bool bSend)
	{
		Stream_VALUE(bPlayCoutIdex);
		Stream_VALUE(bGameTypeIdex);
		Stream_VALUE(bGameRuleIdex);
		Stream_VALUE(bStartGame);
		Stream_VALUE(dwPlayCout);
		Stream_VALUE(dwRoomNum);
		Stream_VALUE(dwCreateUserID);
		Stream_VALUE(dwPlayTotal);
		Stream_VECTOR(kWinLoseScore);
		Stream_VALUE(cbRoomType);
	}
};

//解散房间
struct CMD_GR_Dismiss_Private
{
	byte			bDismiss;			//解散
};

//重新加入
struct CMD_GR_Again_Private
{
	char							stHttpChannel[LEN_NICKNAME];
	CMD_GR_Again_Private()
	{
		zeromemory(stHttpChannel, sizeof(stHttpChannel));
	}
};


//私人场解散信息
struct CMD_GF_Private_Dismiss_Info
{
	CMD_GF_Private_Dismiss_Info()
	{
		zeromemory(this, sizeof(CMD_GF_Private_Dismiss_Info));
	}
	dword			dwDissUserCout;
	dword			dwDissChairID[MAX_CHAIR - 1];
	dword			dwValue1;
	dword			dwNotAgreeUserCout;
	dword			dwNotAgreeChairID[MAX_CHAIR - 1];
	dword			dwValue2;
};

#define MAX_PRIVATE_ACTION 8
//私人场结算信息
struct CMD_GF_Private_End_Info
{
	std::vector<SCORE> lPlayerWinLose;
	std::vector<byte> lPlayerAction;
	systemtime		kPlayTime;

	void StreamValue(datastream& kData, bool bSend)
	{
		Stream_VECTOR(lPlayerWinLose);
		Stream_VECTOR(lPlayerAction);
		Stream_VALUE_SYSTEMTIME(kPlayTime);
	}
};


//////////////////////////////////////////////////////////////////////////////////
//框架命令

#define MDM_GF_FRAME				100									//框架命令

//////////////////////////////////////////////////////////////////////////////////
//框架命令

//用户命令
#define SUB_GF_GAME_OPTION			1									//游戏配置
#define SUB_GF_USER_READY			2									//用户准备
#define SUB_GF_LOOKON_CONFIG		3									//旁观配置

//聊天命令
#define SUB_GF_USER_CHAT			10									//用户聊天
#define SUB_GF_USER_EXPRESSION		11									//用户表情
#define SUB_GR_TABLE_TALK			12									//用户聊天

//游戏信息
#define SUB_GF_GAME_STATUS			100									//游戏状态
#define SUB_GF_GAME_SCENE			101									//游戏场景
#define SUB_GF_LOOKON_STATUS		102									//旁观状态

//系统消息
#define SUB_GF_SYSTEM_MESSAGE		200									//系统消息
#define SUB_GF_ACTION_MESSAGE		201									//动作消息

//////////////////////////////////////////////////////////////////////////////////
//
////游戏配置
//struct CMD_GF_GameOption
//{
//	byte							cbAllowLookon;						//旁观标志
//	dword							dwFrameVersion;						//框架版本
//	dword							dwClientVersion;					//游戏版本
//};
//
////旁观配置
//struct CMD_GF_LookonConfig
//{
//	dword							dwUserID;							//用户标识
//	byte							cbAllowLookon;						//允许旁观
//};
//
////旁观状态
//struct CMD_GF_LookonStatus
//{
//	byte							cbAllowLookon;						//允许旁观
//};
//
////游戏环境
//struct CMD_GF_GameStatus
//{
//	byte							cbGameStatus;						//游戏状态
//	byte							cbAllowLookon;						//旁观标志
//};
//
////用户聊天
//struct CMD_GF_C_UserChat
//{
//	word							wChatLength;						//信息长度
//	dword							dwChatColor;						//信息颜色
//	dword							dwTargetUserID;						//目标用户
//	tchar							szChatString[LEN_USER_CHAT];		//聊天信息
//};
//
////用户聊天
//struct CMD_GF_S_UserChat
//{
//	word							wChatLength;						//信息长度
//	dword							dwChatColor;						//信息颜色
//	dword							dwSendUserID;						//发送用户
//	dword							dwTargetUserID;						//目标用户
//	tchar							szChatString[LEN_USER_CHAT];		//聊天信息
//};
//
////用户表情
//struct CMD_GF_C_UserExpression
//{
//	word							wItemIndex;							//表情索引
//	dword							dwTargetUserID;						//目标用户
//};
//
////用户表情
//struct CMD_GF_S_UserExpression
//{
//	word							wItemIndex;							//表情索引
//	dword							dwSendUserID;						//发送用户
//	dword							dwTargetUserID;						//目标用户
//};

//////////////////////////////////////////////////////////////////////////////////
//游戏命令

#define MDM_GF_GAME					200									//游戏命令




//////////////////////////////////////////////////////////////////////////////////
//携带信息

//其他信息
#define DTP_GR_TABLE_PASSWORD		1									//桌子密码

//用户属性
#define DTP_GR_NICK_NAME			10									//用户昵称
#define DTP_GR_GROUP_NAME			11									//社团名字
#define DTP_GR_UNDER_WRITE			12									//个性签名
#define DTP_GR_MACHINE_ID			13                  //机器码
#define DTP_GR_PROFILEURL			14                  //头像

//附加信息
#define DTP_GR_USER_NOTE			20									//用户备注
#define DTP_GR_CUSTOM_FACE			21									//自定头像

//////////////////////////////////////////////////////////////////////////////////

//请求错误
#define REQUEST_FAILURE_NORMAL		0									//常规原因
#define REQUEST_FAILURE_NOGOLD		1									//金币不足
#define REQUEST_FAILURE_NOSCORE		2									//积分不足
#define REQUEST_FAILURE_PASSWORD	3									//密码错误

//////////////////////////////////////////////////////////////////////////////////

#pragma pack(pop)

#endif