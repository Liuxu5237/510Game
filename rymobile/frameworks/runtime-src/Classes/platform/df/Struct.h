#ifndef STRUCT_HEAD_FILE
#define STRUCT_HEAD_FILE

#include "cocos2d.h"

using namespace cocos2d;
#pragma pack(push)
#pragma pack(1)

#include "types.h"
#include "Define.h"


//最大排行榜显示数量
#define MAX_MATCH_SHOW_NUMBER 10	
//////////////////////////////////////////////////////////////////////////////////
//游戏列表

//用户属性
class tagUserAttribute : public cocos2d::Ref
{
public:
	tagUserAttribute()
	{
		dwUserID = 0;
		wTableID = INVALID_TABLE;
		wChairID = INVALID_CHAIR;
		dwUserRight = 0;
		dwMasterRight = 0;
	}
	//用户属性
	CC_SET_AND_GET(dword, dwUserID, UserID)								//用户标识
	CC_SET_AND_GET(WORD, wTableID, TableID)								//桌子号码
	CC_SET_AND_GET(WORD, wChairID, ChairID)								//椅子号码
	
	//权限属性
	CC_SET_AND_GET(dword, dwUserRight, UserRight)						//用户权限
	CC_SET_AND_GET(dword, dwMasterRight, MasterRight)					//管理权限
};

//游戏属性
class tagGameAttribute : public cocos2d::Ref
{
	CC_SET_AND_GET(WORD, wKindID, KindID)								//类型标识
	CC_SET_AND_GET(WORD, wChairCount, ChairCount)						//椅子数目
	CC_SET_AND_GET(dword, dwClientVersion, ClientVersion)				//游戏版本
	CC_SET_AND_GET_CHAR_ARRAY(LEN_KIND, szGameName, GameName)			//游戏名字
};

//房间属性
class tagServerAttribute : public cocos2d::Ref
{
public:
	tagServerAttribute()
	{
		wKindID = 0;
		wServerID = 0;
		wServerType = 0;
		dwServerRule = 0;
		memset(szServerName, 0, sizeof(szServerName));
		wAVServerPort = 0;
		dwAVServerAddr = 0;
		wTableCount = 0;
		wChairCount = 0;
	}
	CC_SET_AND_GET(WORD, wKindID, KindID)								//类型标识
	CC_SET_AND_GET(WORD, wServerID, ServerID)							//房间标识
	CC_SET_AND_GET(WORD, wServerType, ServerType)						//游戏类型	

	CC_SET_AND_GET(dword, dwServerRule, ServerRule)						//房间规则	
	CC_SET_AND_GET_CHAR_ARRAY(LEN_SERVER, szServerName, ServerName)	//房间名称
	CC_SET_AND_GET(WORD, wAVServerPort, AVServerPort)					//视频端口
	CC_SET_AND_GET(dword, dwAVServerAddr, AVServerAddr)					//视频地址	

	CC_SET_AND_GET(WORD, wTableCount, TableCount)						//桌子数目
	CC_SET_AND_GET(WORD, wChairCount, ChairCount)						//椅子数目
};


//游戏类型
class tagGameType : public cocos2d::Ref
{
public:
	tagGameType()
	{

	}
	CC_SET_AND_GET(WORD, wJoinID, JoinID)								//挂接索引
	CC_SET_AND_GET(WORD, wSortID, SortID)								//排序索引
	CC_SET_AND_GET(WORD, wTypeID, TypeID)								//类型索引
	CC_SET_AND_GET_CHAR_ARRAY(LEN_TYPE, szTypeName, TypeName)			//种类名字
};

//游戏种类
class tagGameKind : public cocos2d::Ref
{
public:
	tagGameKind()
	{

	}
	CC_SET_AND_GET(WORD,wTypeID,TypeID)									//类型索引
	CC_SET_AND_GET(WORD, wJoinID, JoinID)								//挂接索引
	CC_SET_AND_GET(WORD, wSortID, SortID)								//排序索引
	CC_SET_AND_GET(WORD, wKindID, KindID)								//类型索引
	CC_SET_AND_GET(WORD, wGameID, GameID)								//模块索引

	CC_SET_AND_GET(dword, dwOnLineCount, OnLineCount)					//在线人数
	CC_SET_AND_GET(dword, dwAndroidCount, AndroidCount)					//机器人数
	CC_SET_AND_GET(dword, dwFullCount, FullCount)						//满员人数

	CC_SET_AND_GET_CHAR_ARRAY(LEN_KIND, szKindName, KindName)			//游戏名字
	CC_SET_AND_GET_CHAR_ARRAY(LEN_PROCESS, szProcessName, ProcessName)	//进程名字
};

//游戏节点
class tagGameNode : public cocos2d::Ref
{
public:
	tagGameNode()
	{

	}
	CC_SET_AND_GET(WORD, wKindID, KindID)								//名称索引
	CC_SET_AND_GET(WORD, wJoinID, JoinID)								//挂接索引
	CC_SET_AND_GET(WORD, wSortID, SortID)								//排序索引
	CC_SET_AND_GET(WORD, wNodeID, NodeID)								//节点索引
	CC_SET_AND_GET_CHAR_ARRAY(LEN_NODE, szNodeName, NodeName)			//节点名称
};

//定制类型
class tagGamePage : public cocos2d::Ref
{
public:
	tagGamePage()
	{

	}
	CC_SET_AND_GET(WORD, wPageID, PageID)								//页面索引
	CC_SET_AND_GET(WORD, wKindID, KindID)								//名称索引
	CC_SET_AND_GET(WORD, wNodeID, NodeID)								//节点索引
	CC_SET_AND_GET(WORD, wSortID, SortID)								//排序索引
	CC_SET_AND_GET(WORD, wOperateType, OperateType)						//控制类型

	CC_SET_AND_GET_CHAR_ARRAY(LEN_PAGE, szDisplayName, DisplayName)	//显示名称
};

//游戏房间
class tagGameServer : public cocos2d::Ref
{
public:
	tagGameServer(){

	}
	CC_SET_AND_GET(WORD, wKindID, KindID)								//名称索引
	CC_SET_AND_GET(WORD, wNodeID, NodeID)								//节点索引
	CC_SET_AND_GET(WORD, wSortID, SortID)								//排序索引
	CC_SET_AND_GET(WORD, wServerID, ServerID)							//房间索引
	CC_SET_AND_GET(WORD, wServerKind, ServerKind)						//房间类型（是否比赛）
	CC_SET_AND_GET(WORD, wServerType, ServerType)						//房间类型
	CC_SET_AND_GET(WORD, wServerPort, ServerPort)						//房间端口
	CC_SET_AND_GET(SCORE, lCellScore, CellScore)						//房间类型
	CC_SET_AND_GET(SCORE, lEnterScore, EnterScore)						//房间端口
	CC_SET_AND_GET(dword, dwServerRule, ServerRule)						//房间规则
	CC_SET_AND_GET(dword, dwOnLineCount, OnLineCount)					//在线人数
	CC_SET_AND_GET(dword, dwAndroidCount, AndroidCount)					//机器人数
	CC_SET_AND_GET(dword, dwFullCount, FullCount)						//满员人数
	CC_SET_AND_GET_CHAR_ARRAY(LEN_SERVERADDR, szServerAddr, ServerAddr)	//房间地址
	CC_SET_AND_GET_CHAR_ARRAY(LEN_SERVER, szServerName, ServerName)		//房间名称
};


//比赛信息
class tagGameMatch : public cocos2d::Ref
{
public:
	tagGameMatch(){

	}
	CC_SET_AND_GET(WORD, wServerID, ServerID)				//房间标识
	CC_SET_AND_GET(dword, dwMatchID, MatchID)				//比赛标识
	CC_SET_AND_GET(dword, dwMatchNO, MatchNO)				//比赛场次
	CC_SET_AND_GET(BYTE, cbMatchType, MatchType)			//比赛类型
	CC_SET_AND_GET_CHAR_ARRAY(32, szMatchName, MatchName)	//比赛名称

	CC_SET_AND_GET(BYTE, cbMemberOrder, MemberOrder)		//会员等级
	CC_SET_AND_GET(BYTE, cbMatchFeeType, MatchFeeType)		//扣费类型
	CC_SET_AND_GET(longlong, lMatchFee, MatchFee)				//比赛费用

	CC_SET_AND_GET(WORD, wStartUserCount, StartUserCount)	//开赛人数
	CC_SET_AND_GET(WORD, wMatchPlayCount, MatchPlayCount)	//比赛局数

	CC_SET_AND_GET(WORD, wRewardCount, RewardCount)			//奖励人数

	CC_SET_AND_GET(longlong, llMatchStartTime, MatchStartTime)	//开始时间
	CC_SET_AND_GET(longlong, llMatchEndTime, MatchEndTime)		//结束时间

	CC_SET_AND_GET(WORD, wCountDown, CountDown)					//倒计时
};


//视频配置
struct tagAVServerOption
{
	WORD							wAVServerPort;						//视频端口
	dword							dwAVServerAddr;						//视频地址
};

//在线信息
struct tagOnLineInfoKind
{
	WORD							wKindID;							//类型标识
	dword							dwOnLineCount;						//在线人数
};

//在线信息
struct tagOnLineInfoServer
{
	WORD							wServerID;							//房间标识
	dword							dwOnLineCount;						//在线人数
};

//////////////////////////////////////////////////////////////////////////////////
//用户信息

//桌子状态
struct tagTableStatus
{
	BYTE							cbTableLock;						//锁定标志
	BYTE							cbPlayStatus;						//游戏标志
};

//用户状态
class tagUserStatus : public cocos2d::Ref
{
	CC_SET_AND_GET(WORD, wTableID, TableID);							//桌子索引
	CC_SET_AND_GET(WORD, wChairID, ChairID);							//椅子位置
	CC_SET_AND_GET(BYTE, cbUserStatus, UserStatus);						//用户状态
};

//用户属性
class tagUserAttrib : public cocos2d::Ref
{
	CC_SET_AND_GET(BYTE, cbCompanion, Companion);						//用户关系
};

//用户积分
class tagUserScore : public cocos2d::Ref
{
	//积分信息
	CC_SET_AND_GET(SCORE, lScore, Score);								//用户分数
	CC_SET_AND_GET(SCORE, lGrade, Grade);								//用户成绩
	CC_SET_AND_GET(SCORE, lInsure, Insure);								//用户银行
	CC_SET_AND_GET(SCORE, lIngot, Ingot);								//用户元宝
	CC_SET_AND_GET(SCORE, lHouseCard,HouseCard);								//用户元宝

	//输赢信息
	CC_SET_AND_GET(dword, dwWinCount, WinCount);						//胜利盘数
	CC_SET_AND_GET(dword, dwLostCount, LostCount);						//失败盘数
	CC_SET_AND_GET(dword, dwDrawCount, DrawCount);						//和局盘数
	CC_SET_AND_GET(dword, dwFleeCount, FleeCount);						//逃跑盘数					

	//全局信息
	CC_SET_AND_GET(dword, dwExperience, Experience);					//用户经验
	CC_SET_AND_GET(dword, lLoveLiness, LoveLiness);						//用户魅力
};

////用户积分
//struct tagMobileUserScore
//{
//	//积分信息
//	SCORE							lScore;								//用户分数
//
//	//输赢信息
//	dword							dwWinCount;							//胜利盘数
//	dword							dwLostCount;						//失败盘数
//	dword							dwDrawCount;						//和局盘数
//	dword							dwFleeCount;						//逃跑盘数
//
//	//全局信息
//	dword							dwExperience;						//用户经验
//};


//道具使用
struct tagUsePropertyInfo
{
	WORD                            wPropertyCount;                     //道具数目
	WORD                            dwValidNum;						    //有效数字
	dword                           dwEffectTime;                       //生效时间
};


//用户道具
struct tagUserProperty
{
	WORD                            wPropertyUseMark;                   //道具标示
	tagUsePropertyInfo              PropertyInfo[MAX_PT_MARK];			//使用信息   
};

//道具包裹
class tagPropertyPackage : public cocos2d::Ref
{
	CC_SET_AND_GET(WORD, wTrumpetCount, TrumpetCount);					//小喇叭数
	CC_SET_AND_GET(WORD, wTyphonCount, TyphonCount);					//大喇叭数                    
};

//时间信息
class tagTimeInfo : public cocos2d::Ref
{
	CC_SET_AND_GET(dword, dwEnterTableTimer, EnterTableTimer);			//进出桌子时间
	CC_SET_AND_GET(dword, dwLeaveTableTimer, LeaveTableTimer);			//离开桌子时间
	CC_SET_AND_GET(dword, dwStartGameTimer, StartGameTimer);			//开始游戏时间
	CC_SET_AND_GET(dword, dwEndGameTimer, EndGameTimer);				//离开游戏时间
};

//用户信息
class tagUserInfo : public cocos2d::Ref
{
	//基本属性
	CC_SET_AND_GET(dword, dwUserID, UserID);							//用户 I D
	CC_SET_AND_GET(dword, dwGameID, GameID);							//游戏 I D
	CC_SET_AND_GET(dword, dwGroupID, GroupID);							//社团 I D
	CC_SET_AND_GET_CHAR_ARRAY(LEN_NICKNAME, szNickName, NickName);		//用户昵称
	CC_SET_AND_GET_CHAR_ARRAY(LEN_GROUP_NAME, szGroupName, GroupName);	//社团名字	
	CC_SET_AND_GET_CHAR_ARRAY(LEN_UNDER_WRITE, szUnderWrite, UnderWrite);	//个性签名

	//头像信息
	CC_SET_AND_GET(WORD, wFaceID, FaceID);								//头像索引
	CC_SET_AND_GET(dword, dwCustomID, CustomID);						//自定标识			
	CC_SET_AND_GET_CHAR_ARRAY(LEN_WEBCHAT_PROFILEURL, szProfileUrl, ProfileUrl)	//头像url

	//用户资料
	CC_SET_AND_GET(BYTE, cbGender, Gender);								//用户性别
	CC_SET_AND_GET(BYTE, cbMemberOrder, MemberOrder);					//会员等级
	CC_SET_AND_GET(BYTE, cbMasterOrder, MasterOrder);					//管理等级

	//用户状态
	CC_SET_AND_GET(WORD, wTableID, TableID);							//桌子索引
	CC_SET_AND_GET(WORD, wLastTableID, LastTableID);					//游戏桌子
	CC_SET_AND_GET(WORD, wChairID, ChairID);							//椅子索引
	CC_SET_AND_GET(BYTE, cbUserStatus, UserStatus);						//用户状态

	//积分信息
	CC_SET_AND_GET(SCORE, lScore, Score);								//用户分数
	CC_SET_AND_GET(SCORE, lGrade, Grade);								//用户成绩
	CC_SET_AND_GET(SCORE, lInsure, Insure);								//用户银行
	CC_SET_AND_GET(SCORE, lIngot, Ingot);								//用户元宝
	CC_SET_AND_GET(SCORE, lHouseCard, HouseCard);						//用户房卡

	CC_SET_AND_GET(bool, bIsAndroid, IsAndroid);						//是否机器人
	CC_SET_AND_GET(dword, dwClientAddr, ClientAddr);					//连接地址
	CC_SET_AND_GET_CHAR_ARRAY(LEN_MACHINE_ID, szMachineID, MachineID);
	
	//转账记录
	CC_SET_AND_GET(SCORE, lTransInScore, TransInScore);					//转入金币
	CC_SET_AND_GET(SCORE, lTransOutScore, TransOutScore);				//转出金币
	CC_SET_AND_GET(SCORE, lRechargeScore, RechargeScore);				//充值金额
	
	//游戏信息
	CC_SET_AND_GET(dword, dwWinCount, WinCount);						//胜利盘数
	CC_SET_AND_GET(dword, dwLostCount, LostCount);						//失败盘数
	CC_SET_AND_GET(dword, dwDrawCount, DrawCount);						//和局盘数
	CC_SET_AND_GET(dword, dwFleeCount, FleeCount);						//逃跑盘数
	CC_SET_AND_GET(dword, dwExperience, Experience);					//用户经验
	CC_SET_AND_GET(dword, lLoveLiness, LoveLiness);						//用户魅力

	//时间信息
	CC_SET_AND_GET_POINT(tagTimeInfo, TimerInfo, TimerInfo);				//时间信息
};

//用户信息
//CMD_GR_UserInfo
struct tagUserInfoHead
{
	//用户属性
	dword							dwGameID;							//游戏 I D
	dword							dwUserID;							//用户 I D
	dword							dwGroupID;							//社团 I D

	//头像信息
	WORD							wFaceID;							//头像索引
	dword							dwCustomID;							//自定标识

	//用户属性
	bool							bIsAndroid;							//机器标识
	BYTE							cbGender;							//用户性别
	BYTE							cbMemberOrder;						//会员等级
	BYTE							cbMasterOrder;						//管理等级

	//用户状态
	WORD							wTableID;							//桌子索引
	WORD							wChairID;							//椅子索引
	BYTE							cbUserStatus;						//用户状态

	//积分信息
	SCORE							lScore;								//用户分数
	SCORE							lGrade;								//用户成绩
	SCORE							lInsure;							//用户银行
	SCORE							lIngot;								//用户元宝
	//转账记录
	SCORE							lTransInScore;						 //转入金币
	SCORE							lTransOutScore;						 //转出金币
	SCORE							lRechargeScore;						 //充值金额

	dword							dwClientAddr;							//IP地址


	//游戏信息
	dword							dwWinCount;							//胜利盘数
	dword							dwLostCount;						//失败盘数
	dword							dwDrawCount;						//和局盘数
	dword							dwFleeCount;						//逃跑盘数
	//dword							dwUserMedal;						//用户奖牌
	dword							dwExperience;						//用户经验
	dword							lLoveLiness;						//用户魅力
	tchar							szProfileUrl[LEN_WEBCHAT_PROFILEURL];	//头像url
	//tchar							szMachineID[LEN_MACHINE_ID];
};

//额外信息
struct tagUserExtraInfo
{
	bool							bIsAndroid;
	dword							dwClientAddr;						//连接地址
	TCHAR							szMachineID[LEN_MACHINE_ID];
	//转账记录
	SCORE							lTransInScore;						//转入金币
	SCORE							lTransOutScore;						//转出金币
	SCORE							lRechargeScore;						//充值金额
};

//头像信息
class tagCustomFaceInfo : public cocos2d::Ref
{
	CC_SET_AND_GET(dword, dwDataSize, DataSize);								//数据大小
	CC_SET_AND_GET_ARRAY(dword, FACE_CX*FACE_CY, dwCustomFace, CustomFace);		//图片信息
};

//用户信息
struct tagUserRemoteInfo
{
	//用户信息
	dword							dwUserID;							//用户标识
	dword							dwGameID;							//游戏标识
	char							szNickName[LEN_NICKNAME];			//用户昵称

	//等级信息
	BYTE							cbGender;							//用户性别
	BYTE							cbMemberOrder;						//会员等级
	BYTE							cbMasterOrder;						//管理等级

	//位置信息
	WORD							wKindID;							//类型标识
	WORD							wServerID;							//房间标识
	char							szGameServer[LEN_SERVER];			//房间位置
};


//等级配置
struct tagGrowLevelConfig
{
	WORD              wLevelID;             //等级 I D
	dword             dwExperience;           //相应经验
};


//////////////////////////////////////////////////////////////////////////////////

//广场子项
struct tagGamePlaza
{
	WORD							wPlazaID;							//广场标识
	char							szServerAddr[32];					//服务地址
	char							szServerName[32];					//服务器名
};

//级别子项
struct tagLevelItem
{
	WORD							lLevelScore;						//级别积分
	char							szLevelName[16];					//级别描述
};

//会员子项
struct tagMemberItem
{
	BYTE							cbMemberOrder;						//等级标识
	char							szMemberName[16];					//等级名字
};

//管理子项
struct tagMasterItem
{
	BYTE							cbMasterOrder;						//等级标识
	char							szMasterName[16];					//等级名字
};

//列表子项
struct tagColumnItem
{
	BYTE							cbColumnWidth;						//列表宽度
	BYTE							cbDataDescribe;						//字段类型
	char							szColumnName[16];					//列表名字
};

//地址信息
struct tagAddressInfo
{
	char							szAddress[32];						//服务地址
};

//数据信息
struct tagDataBaseParameter
{
	WORD							wDataBasePort;						//数据库端口
	char							szDataBaseAddr[32];					//数据库地址
	char							szDataBaseUser[32];					//数据库用户
	char							szDataBasePass[32];					//数据库密码
	char							szDataBaseName[32];					//数据库名字
};

//房间配置
struct tagServerOptionInfo
{
	//挂接属性
	WORD							wKindID;							//挂接类型
	WORD							wNodeID;							//挂接节点
	WORD							wSortID;							//排列标识

	//税收配置
	WORD							wRevenueRatio;						//税收比例
	SCORE							lServiceScore;						//服务费用

	//房间配置
	SCORE							lRestrictScore;						//限制积分
	SCORE							lMinTableScore;						//最低积分
	SCORE							lMinEnterScore;						//最低积分
	SCORE							lMaxEnterScore;						//最高积分

	//会员限制
	BYTE							cbMinEnterMember;					//最低会员
	BYTE							cbMaxEnterMember;					//最高会员

	//房间属性
	dword							dwServerRule;						//房间规则
	char							szServerName[LEN_SERVER];			//房间名称
};

//用户信息
struct tagMobileUserInfoHead
{
	//用户属性
	dword							dwGameID;							//游戏 I D
	dword							dwUserID;							//用户 I D

	//头像信息
	WORD							wFaceID;							//头像索引
	dword							dwCustomID;							//自定标识

	//用户属性
	BYTE							cbGender;							//用户性别
	BYTE							cbMemberOrder;						//会员等级

	//用户状态
	WORD							wTableID;							//桌子索引
	WORD							wChairID;							//椅子索引
	BYTE							cbUserStatus;						//用户状态

	//积分信息
	SCORE							lScore;								//用户分数
	SCORE							lIngot;				//用户元宝
	SCORE							lGrade;				//用户成绩
	//游戏信息
	dword							dwWinCount;							//胜利盘数
	dword							dwLostCount;						//失败盘数
	dword							dwDrawCount;						//和局盘数
	dword							dwFleeCount;						//逃跑盘数
	dword							dwExperience;						//用户经验
};

//////////////////////////////////////////////////////////////////////////////////
//比赛信息

//赛事信息
class tagMatchInfo : public cocos2d::Ref
{
	CC_SET_AND_GET(WORD, wGameCount, GameCount)							//游戏局数

public:
	char * getTitle(int index){
		return szTitle[index];
	}
public:
	char							szTitle[4][64];						//信息标题
	
};

//提示信息
class tagMatchWaitTip : public cocos2d::Ref
{
	CC_SET_AND_GET(SCORE, lScore, Score)								//当前积分

	CC_SET_AND_GET(WORD, wRank, Rank)									//当前名次
	CC_SET_AND_GET(WORD, wCurTableRank, CurTableRank)					//本桌名次
	CC_SET_AND_GET(WORD, wUserCount, UserCount)							//当前人数
	CC_SET_AND_GET(WORD, wPlayingTable, PlayingTable)					//游戏桌数

	CC_SET_AND_GET_CHAR_ARRAY(LEN_SERVER, szMatchName, MatchName)		//比赛名称
};

//比赛结果
class tagMatchResult : public cocos2d::Ref
{
	CC_SET_AND_GET(WORD, wGameType, GameType)							//游戏类型
	CC_SET_AND_GET(SCORE, lGold, Gold)									//金币奖励
	CC_SET_AND_GET(dword, dwIngot, Ingot)								//元宝奖励
	CC_SET_AND_GET(dword, dwExperience, Experience)						//经验奖励
	CC_SET_AND_GET_CHAR_ARRAY(32, szUserName, UserName)				//玩家名字
	CC_SET_AND_GET_CHAR_ARRAY(32, szMatchName, MatchName)				//比赛名字
	CC_SET_AND_GET(WORD, wUserRank, UserRank)							//玩家排名
	CC_SET_AND_GET(WORD, wUserCount, UserCount)							//玩家人数
};

//比赛排名小结构体
struct tagMatchSubRankList
{
	SCORE				lGrade;						//当前成绩
	SCORE				lGold;						//金币奖励
	dword				dwIngot;					//元宝奖励
	dword				dwExperience;				//经验奖励
	dword				dwGameID;				//游戏id
	unsigned short		szUserName[LEN_NICKNAME];				//玩家名字
	unsigned short		szMatchName[LEN_NICKNAME];			//比赛名字
};

//比赛排名信息
struct tagMatchRankList
{
	word				wCount;			//当前的总人数
	tagMatchSubRankList sRankData[MAX_MATCH_SHOW_NUMBER];	//排名信息
};

//比赛描述
struct tagMatchDesc
{
	char							szTitle[4][16];						//信息标题
	char							szDescribe[4][64];					//描述内容
	dword							crTitleColor;						//标题颜色
	dword							crDescribeColor;					//描述颜色
};

//////////////////////////////////////////////////////////////////////////////////
//排行榜
//排行榜项
struct tagRankItem
{
	dword							dwUserID;							//用户ID
	SCORE							lScore;								//用户积分
	uint16							szNickname[LEN_NICKNAME];			//用户昵称
};

#pragma pack(pop)

#endif