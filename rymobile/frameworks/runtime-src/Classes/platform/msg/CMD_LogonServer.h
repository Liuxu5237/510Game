#ifndef CMD_LONGON_HEAD_FILE
#define CMD_LONGON_HEAD_FILE
#pragma pack(push)
#pragma pack(1)

//////////////////////////////////////////////////////////////////////////

struct systemtime {
	WORD wYear;
	WORD wMonth;
	WORD wDayOfWeek;
	WORD wDay;
	WORD wHour;
	WORD wMinute;
	WORD wSecond;
	WORD wMilliseconds;
};

//////////////////////////////////////////////////////////////////////////////////
//登录命令

#define MDM_GP_LOGON				1									//广场登录

//登录模式
#define SUB_GP_LOGON_GAMEID			1									//I D 登录
#define SUB_GP_LOGON_ACCOUNTS		2									//帐号登录
#define SUB_GP_REGISTER_ACCOUNTS	3									//注册帐号

//登录结果
#define SUB_GP_LOGON_SUCCESS    100										//登录成功
#define SUB_GP_LOGON_FAILURE    101										//登录失败
#define SUB_GP_LOGON_FINISH     102										//登录完成
#define SUB_GP_VALIDATE_MBCARD      103                                 //登录失败
#define SUB_GP_VALIDATE_PASSPORT  104									//登录失败  
#define SUB_GP_VERIFY_RESULT    105										//验证结果
#define SUB_GP_MATCH_SIGNUPINFO   106									//报名信息
#define SUB_GP_GROWLEVEL_CONFIG   107									//等级配置

//升级提示
#define SUB_GP_UPDATE_NOTIFY		200									//升级提示

//////////////////////////////////////////////////////////////////////////////////
//

#define MB_VALIDATE_FLAGS           0x01                                //效验密保
#define LOW_VER_VALIDATE_FLAGS      0x02                                //效验低版本
//
////I D 登录
//struct CMD_GP_LogonGameID
//{
//	//系统信息
//	byte                            cbDeviceType;                       //设备类型
//	word							wModuleID;							//模块标识(KindID)
//	dword							dwPlazaVersion;						//广场版本
//	tchar							szMachineID[LEN_MACHINE_ID];		//机器序列
//	tchar							szMobilePhone[LEN_MOBILE_PHONE];	//电话号码(手机用)
//
//	//登录信息
//	dword							dwGameID;							//游戏 I D
//	tchar							szPassword[LEN_MD5];				//登录密码
//	byte							cbValidateFlags;			        //校验标识(手机没有密保)
//};
//
////帐号登录
//struct CMD_GP_LogonAccounts
//{
//	//系统信息
//	byte                            cbDeviceType;                       //设备类型
//	word							wModuleID;							//模块标识(KindID)
//	dword							dwPlazaVersion;						//广场版本
//	tchar							szMachineID[LEN_MACHINE_ID];		//机器序列
//	tchar							szMobilePhone[LEN_MOBILE_PHONE];	//电话号码(手机用)
//
//	//登录信息
//	tchar							szPassword[LEN_MD5];				//登录密码
//	tchar							szAccounts[LEN_ACCOUNTS];			//登录帐号
//	byte							cbValidateFlags;			        //校验标识(手机没有密保)
//};
//
//
////注册帐号
//struct CMD_GP_RegisterAccounts
//{
//	//系统信息
//	byte                            cbDeviceType;                       //设备类型
//	word							wModuleID;							//模块标识(KindID)
//	dword							dwPlazaVersion;						//广场版本
//	tchar							szMachineID[LEN_MACHINE_ID];		//机器序列
//	tchar							szMobilePhone[LEN_MOBILE_PHONE];	//电话号码(手机用)
//
//	//密码变量
//	tchar							szLogonPass[LEN_MD5];				//登录密码
//	tchar							szInsurePass[LEN_MD5];				//银行密码
//
//	//注册信息
//	word							wFaceID;							//头像标识
//	byte							cbGender;							//用户性别
//	tchar							szAccounts[LEN_ACCOUNTS];			//登录帐号
//	tchar							szNickName[LEN_NICKNAME];			//用户昵称
//	tchar							szSpreader[LEN_ACCOUNTS];			//推荐帐号(手机目前没有)
//	tchar							szPassPortID[LEN_PASS_PORT_ID];		//证件号码(手机目前没有)
//	tchar							szCompellation[LEN_COMPELLATION];	//真实名字(手机目前没有)
//	byte							cbValidateFlags;			        //校验标识(手机目前没有)
//};
//
//
////登录成功
//struct CMD_GP_LogonSuccess
//{
//	//属性资料
//	word							wFaceID;							//头像标识
//	dword							dwUserID;							//用户 I D
//	dword							dwGameID;							//游戏 I D
//	dword							dwGroupID;							//社团标识
//	dword							dwCustomID;							//自定标识
//	dword							dwUserMedal;						//用户奖牌
//	dword							dwExperience;						//经验数值
//	dword							dwLoveLiness;						//用户魅力
//
//	//用户成绩
//	SCORE							lUserScore;							//用户金币
//	SCORE							lUserInsure;						//用户银行
//
//	//用户信息
//	byte							cbGender;							//用户性别
//	byte							cbMoorMachine;						//锁定机器
//	tchar							szAccounts[LEN_ACCOUNTS];			//登录帐号
//	tchar							szNickName[LEN_ACCOUNTS];			//用户昵称
//	tchar							szGroupName[LEN_GROUP_NAME];		//社团名字
//
//	//配置信息
//	byte                            cbShowServerStatus;                 //显示服务器状态
//};
//
////登录失败
//struct CMD_GP_LogonFailure
//{
//	long							lResultCode;						//错误代码
//	tchar							szDescribeString[128];				//描述消息
//};
//
////登陆完成
//struct CMD_GP_LogonFinish
//{
//	word							wIntermitTime;						//中断时间
//	word							wOnLineCountTime;					//更新时间
//};
//
////登录失败
//struct CMD_GP_ValidateMBCard
//{
//	uint								uMBCardID;						//机器序列
//};
//
////升级提示
//struct CMD_GP_UpdateNotify
//{
//	byte							cbMustUpdate;						//强行升级
//	byte							cbAdviceUpdate;						//建议升级
//	dword							dwCurrentVersion;					//当前版本
//};

//////////////////////////////////////////////////////////////////////////////////
//携带信息 CMD_GP_LogonSuccess

#define DTP_GP_GROUP_INFO			1									//社团信息
#define DTP_GP_MEMBER_INFO			2									//会员信息
#define	DTP_GP_UNDER_WRITE			3									//个性签名
#define DTP_GP_STATION_URL			4									//主页信息

////社团信息
//struct DTP_GP_GroupInfo
//{
//	dword							dwGroupID;							//社团索引
//	tchar							szGroupName[LEN_GROUP_NAME];		//社团名字
//};
//
////会员信息
//struct DTP_GP_MemberInfo
//{
//	byte							cbMemberOrder;						//会员等级
//	systemtime						MemberOverDate;						//到期时间
//};

//////////////////////////////////////////////////////////////////////////////////
//列表命令

#define MDM_GP_SERVER_LIST			2									//列表信息

//获取命令
#define SUB_GP_GET_LIST				1									//获取列表
#define SUB_GP_GET_SERVER			2									//获取房间
#define SUB_GP_GET_ONLINE			3									//获取在线
#define SUB_GP_GET_COLLECTION		4									//获取收藏

//列表信息
#define SUB_GP_LIST_TYPE			100									//类型列表
#define SUB_GP_LIST_KIND			101									//种类列表
#define SUB_GP_LIST_NODE			102									//节点列表
#define SUB_GP_LIST_PAGE			103									//定制列表
#define SUB_GP_LIST_SERVER			104									//房间列表
#define SUB_GP_VIDEO_OPTION			105									//视频配置

//完成信息
#define SUB_GP_LIST_FINISH			200									//发送完成
#define SUB_GP_SERVER_FINISH		201									//房间完成

//在线信息
#define SUB_GR_KINE_ONLINE			300									//类型在线
#define SUB_GR_SERVER_ONLINE		301									//房间在线
#define SUB_GR_ONLINE_FINISH		302									//在线完成

//////////////////////////////////////////////////////////////////////////////////
//
////获取在线
//struct CMD_GP_GetOnline
//{
//	word							wServerCount;						//房间数目
//	word							wOnLineServerID[MAX_SERVER];		//房间标识
//};
//
////类型在线
//struct CMD_GP_KindOnline
//{
//	word							wKindCount;							//类型数目
//	tagOnLineInfoKind				OnLineInfoKind[MAX_KIND];			//类型在线
//};
//
////房间在线
//struct CMD_GP_ServerOnline
//{
//	word							wServerCount;						//房间数目
//	tagOnLineInfoServer				OnLineInfoServer[MAX_SERVER];		//房间在线
//};

//////////////////////////////////////////////////////////////////////////////////
//服务命令

#define MDM_GP_USER_SERVICE			3									//用户服务

//账号服务
#define SUB_GP_MODIFY_MACHINE		100									//修改机器
#define SUB_GP_MODIFY_LOGON_PASS	101									//修改密码
#define SUB_GP_MODIFY_INSURE_PASS	102									//修改密码
#define SUB_GP_MODIFY_UNDER_WRITE	103									//修改签名

#define SUB_GP_BIND_MOBILE			110					                //绑定手机

//修改头像
#define SUB_GP_USER_FACE_INFO		120									//头像信息
#define SUB_GP_SYSTEM_FACE_INFO		122									//系统头像
#define SUB_GP_CUSTOM_FACE_INFO		123									//自定头像

//个人资料
#define SUB_GP_USER_INDIVIDUAL		140									//个人资料
#define	SUB_GP_QUERY_INDIVIDUAL		141									//查询信息
#define SUB_GP_MODIFY_INDIVIDUAL	152									//修改资料

//银行服务
#define SUB_GP_USER_ENABLE_INSURE	160									//开通银行
#define SUB_GP_USER_SAVE_SCORE		161									//存款操作
#define SUB_GP_USER_TAKE_SCORE		162									//取款操作
#define SUB_GP_USER_TRANSFER_SCORE	163									//转账操作
#define SUB_GP_USER_INSURE_INFO		164									//银行资料
#define SUB_GP_QUERY_INSURE_INFO	165									//查询银行
#define SUB_GP_USER_INSURE_SUCCESS	166									//银行成功
#define SUB_GP_USER_INSURE_FAILURE	167									//银行失败
#define SUB_GP_QUERY_USER_INFO_REQUEST	168								//查询用户
#define SUB_GP_QUERY_USER_INFO_RESULT	169								//用户信息
#define	SUB_GP_USER_INSURE_ENABLE_RESULT 170							//开通结果
#define SUB_GP_USER_RECHARGE	   181									//用户充值
#define SUB_GP_RECHARGE_SUCCESS			182					 //充值成功

#define SUB_GP_BANK_PASSWD_REQUEST	   183									//银行密码请求
#define SUB_GP_BANK_PASSWD_SUCCESS	   184									//银行密码返回

//签到服务
#define SUB_GP_CHECKIN_QUERY      220									//查询签到
#define SUB_GP_CHECKIN_INFO       221									//签到信息
#define SUB_GP_CHECKIN_DONE       222									//执行签到
#define SUB_GP_CHECKIN_RESULT     223									//签到结果

#define	SUB_GP_SHARE_DONE		  230									//分享完成
#define	SUB_GP_SHARE_AWARD		  231									//分享奖励

//低保服务
#define SUB_GP_BASEENSURE_LOAD      260									//加载低保
#define SUB_GP_BASEENSURE_TAKE      261									//领取低保
#define SUB_GP_BASEENSURE_PARAMETER   262								//低保参数
#define SUB_GP_BASEENSURE_RESULT    263									//低保结果

//等级服务
#define SUB_GP_GROWLEVEL_QUERY      300									//查询等级
#define SUB_GP_GROWLEVEL_PARAMETER    301								//等级参数
#define SUB_GP_GROWLEVEL_UPGRADE    302									//等级升级


//兑换道具
#define SUB_GP_EXCHANGE				500									//兑换道具
#define SUB_GP_EXCHANGE_RESULT		501									//兑换结果

//客服信息
#define SUB_GP_KEFU					600									//客服信息
#define SUB_GP_KEFU_RESULT			601									//客服信息结果

//邮件信息
#define SUB_GP_MESSAGE_LIST			700									//邮件列表
#define SUB_GP_MESSAGE_LIST_RESULT	701									//邮件列表返回
#define SUB_GP_MESSAGE_AWARD		702									//获取排行榜奖励
#define SUB_GP_MESSAGE_AWARD_RESULT	703									//获取排行榜结果

//操作结果
#define SUB_GP_OPERATE_SUCCESS		900									//操作成功
#define SUB_GP_OPERATE_FAILURE		901									//操作失败

//////////////////////////////////////////////////////////////////////////////////
//
////修改密码
//struct CMD_GP_ModifyLogonPass
//{
//	dword							dwUserID;							//用户 I D
//	tchar							szDesPassword[LEN_PASSWORD];		//用户密码
//	tchar							szScrPassword[LEN_PASSWORD];		//用户密码
//};
//
////修改密码
//struct CMD_GP_ModifyInsurePass
//{
//	dword							dwUserID;							//用户 I D
//	tchar							szDesPassword[LEN_PASSWORD];		//用户密码
//	tchar							szScrPassword[LEN_PASSWORD];		//用户密码
//};
//
////修改签名
//struct CMD_GP_ModifyUnderWrite
//{
//	dword							dwUserID;							//用户 I D
//	tchar							szPassword[LEN_PASSWORD];			//用户密码
//	tchar							szUnderWrite[LEN_UNDER_WRITE];		//个性签名
//};

//////////////////////////////////////////////////////////////////////////////////
//
////用户头像
//struct CMD_GP_UserFaceInfo
//{
//	word							wFaceID;							//头像标识
//	dword							dwCustomID;							//自定标识
//};
//
////修改头像
//struct CMD_GP_SystemFaceInfo
//{
//	word							wFaceID;							//头像标识
//	dword							dwUserID;							//用户 I D
//	tchar							szPassword[LEN_PASSWORD];			//用户密码
//	tchar							szMachineID[LEN_MACHINE_ID];		//机器序列
//};
//
////修改头像
//struct CMD_GP_CustomFaceInfo
//{
//	dword							dwUserID;							//用户 I D
//	tchar							szPassword[LEN_PASSWORD];			//用户密码
//	tchar							szMachineID[LEN_MACHINE_ID];		//机器序列
//	dword							dwCustomFace[FACE_CX*FACE_CY];		//图片信息
//};
//
////////////////////////////////////////////////////////////////////////////////////
//
////绑定机器
//struct CMD_GP_ModifyMachine
//{
//	byte							cbBind;								//绑定标志
//	dword							dwUserID;							//用户标识
//	tchar							szPassword[LEN_PASSWORD];			//用户密码
//	tchar							szMachineID[LEN_MACHINE_ID];		//机器序列
//};
//
////////////////////////////////////////////////////////////////////////////////////
//
////个人资料
//struct CMD_GP_UserIndividual
//{
//	dword							dwUserID;							//用户 I D
//};
//
////查询信息
//struct CMD_GP_QueryIndividual
//{
//	dword							dwUserID;							//用户 I D
//};
//
////修改资料
//struct CMD_GP_ModifyIndividual
//{
//	byte							cbGender;							//用户性别
//	dword							dwUserID;							//用户 I D
//	tchar							szPassword[LEN_PASSWORD];			//用户密码
//};

//////////////////////////////////////////////////////////////////////////////////
//携带信息 CMD_GP_UserIndividual
#define DTP_GP_UI_ACCOUNTS      1                 //用户账号 
#define DTP_GP_UI_NICKNAME			2									//用户昵称
#define DTP_GP_UI_USER_NOTE			3									//用户说明
#define DTP_GP_UI_UNDER_WRITE		4									//个性签名
#define DTP_GP_UI_QQ				5									//Q Q 号码
#define DTP_GP_UI_EMAIL				6									//电子邮件
#define DTP_GP_UI_SEAT_PHONE		7									//固定电话
#define DTP_GP_UI_MOBILE_PHONE		8									//移动电话
#define DTP_GP_UI_COMPELLATION		9									//真实名字
#define DTP_GP_UI_DWELLING_PLACE	10									//联系地址

//////////////////////////////////////////////////////////////////////////////////
//
////银行资料
//struct CMD_GP_UserInsureInfo
//{
//	word							wRevenueTake;						//税收比例
//	word							wRevenueTransfer;					//税收比例
//	word							wServerID;							//房间标识
//	SCORE							lUserScore;							//用户金币
//	SCORE							lUserInsure;						//银行金币
//	SCORE							lTransferPrerequisite;				//转账条件
//};
//
////存入金币
//struct CMD_GP_UserSaveScore
//{
//	dword							dwUserID;							//用户 I D
//	SCORE							lSaveScore;							//存入金币
//	tchar							szMachineID[LEN_MACHINE_ID];		//机器序列
//};
//
////提取金币
//struct CMD_GP_UserTakeScore
//{
//	dword							dwUserID;							//用户 I D
//	SCORE							lTakeScore;							//提取金币
//	tchar							szPassword[LEN_MD5];				//银行密码
//	tchar							szMachineID[LEN_MACHINE_ID];		//机器序列
//};
//
////转账金币
//struct CMD_GP_UserTransferScore
//{
//	dword							dwUserID;							//用户 I D
//	byte                            cbByNickName;                       //昵称赠送
//	SCORE							lTransferScore;						//转账金币
//	tchar							szPassword[LEN_MD5];				//银行密码
//	tchar							szNickName[LEN_NICKNAME];			//目标用户
//	tchar							szMachineID[LEN_MACHINE_ID];		//机器序列
//};
//
////银行成功
//struct CMD_GP_UserInsureSuccess
//{
//	dword							dwUserID;							//用户 I D
//	SCORE							lUserScore;							//用户金币
//	SCORE							lUserInsure;						//银行金币
//	tchar							szDescribeString[128];				//描述消息
//};
//
////银行失败
//struct CMD_GP_UserInsureFailure
//{
//	long							lResultCode;						//错误代码
//	tchar							szDescribeString[128];				//描述消息
//};
//
////提取结果
//struct CMD_GP_UserTakeResult
//{
//	dword							dwUserID;							//用户 I D
//	SCORE							lUserScore;							//用户金币
//	SCORE							lUserInsure;						//银行金币
//};
//
////查询银行
//struct CMD_GP_QueryInsureInfo
//{
//	dword							dwUserID;							//用户 I D
//};
//
////查询用户
//struct CMD_GP_QueryUserInfoRequest
//{
//	byte                            cbByNickName;                       //昵称赠送
//	tchar							szNickName[LEN_NICKNAME];			//目标用户
//};
//
////用户信息
//struct CMD_GP_UserTransferUserInfo
//{
//	dword							dwTargetGameID;						//目标用户
//	tchar							szNickName[LEN_NICKNAME];			//目标用户
//};

//////////////////////////////////////////////////////////////////////////////////
//
////操作失败
//struct CMD_GP_OperateFailure
//{
//	long							lResultCode;						//错误代码
//	tchar							szDescribeString[128];				//描述消息
//};
//
////操作成功
//struct CMD_GP_OperateSuccess
//{
//	long							lResultCode;						//操作代码
//	tchar							szDescribeString[128];				//成功消息
//};

//////////////////////////////////////////////////////////////////////////////////
// 查询签到
// struct CMD_GP_CheckInQueryInfo
// {
// 	dword             dwUserID;             //用户标识
// 	TCHAR             szPassword[LEN_PASSWORD];     //登录密码
// };
// 
// 签到信息
// struct CMD_GP_CheckInInfo
// {
// 	WORD              wSeriesDate;            //连续日期
// 	bool              bTodayChecked;            //签到标识
// 	SCORE             lRewardGold[LEN_WEEK];        //奖励金币
// };
// 
// 执行签到
// struct CMD_GP_CheckInDone
// {
// 	dword             dwUserID;             //用户标识
// 	TCHAR             szPassword[LEN_PASSWORD];     //登录密码
// 	TCHAR             szMachineID[LEN_MACHINE_ID];    //机器序列
// };
// 
// 签到结果
// struct CMD_GP_CheckInResult
// {
// 	bool              bSuccessed;             //成功标识
// 	SCORE             lScore;               //当前金币
// 	TCHAR             szNotifyContent[128];       //提示内容
// };

//////////////////////////////////////////////////////////////////////////////////
// 低保服务
// 
// 领取低保
// struct CMD_GP_BaseEnsureTake
// {
// 	dword             dwUserID;             //用户 I D
// 	TCHAR             szPassword[LEN_PASSWORD];     //登录密码
// 	TCHAR             szMachineID[LEN_MACHINE_ID];    //机器序列
// };
// 
// 低保参数
// struct CMD_GP_BaseEnsureParamter
// {
// 	SCORE             lScoreCondition;          //游戏币条件
// 	SCORE             lScoreAmount;           //游戏币数量
// 	BYTE              cbTakeTimes;            //领取次数
// };
// 
// 低保结果
// struct CMD_GP_BaseEnsureResult
// {
// 	bool              bSuccessed;             //成功标识
// 	SCORE             lGameScore;             //当前游戏币
// 	TCHAR             szNotifyContent[128];       //提示内容
// };

// 签到奖励
struct CMD_GP_ShareAwardResult
{
	bool              bSuccessed;             //成功标识
	SCORE             lGameScore;             //当前游戏币
};

//////////////////////////////////////////////////////////////////////////////////
//远程服务

#define MDM_GP_REMOTE_SERVICE		4									//远程服务

//查找服务
#define SUB_GP_C_SEARCH_DATABASE	100									//数据查找
#define SUB_GP_C_SEARCH_CORRESPOND	101									//协调查找

//时间奖励
#define SUB_GP_C_TIME_AWARD_CHECK	110									//时间奖励信息查询
#define SUB_GP_C_TIME_AWARD_GET		111									//时间奖励领取

//查找服务
#define SUB_GP_S_SEARCH_DATABASE	200									//数据查找
#define SUB_GP_S_SEARCH_CORRESPOND	201									//协调查找


//时间奖励
#define SUB_GP_S_TIME_AWARD_CHECK	210									//时间奖励信息查询结果
#define SUB_GP_S_TIME_AWARD_GET		211									//时间奖励领取结果

//////////////////////////////////////////////////////////////////////////////////
//
////协调查找
//struct CMD_GP_C_SearchCorrespond
//{
//	dword							dwGameID;							//游戏标识
//	tchar							szNickName[LEN_NICKNAME];			//用户昵称
//};
//
////协调查找
//struct CMD_GP_S_SearchCorrespond
//{
//	word							wUserCount;							//用户数目
//	tagUserRemoteInfo				UserRemoteInfo[16];					//用户信息
//};

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////

//登录命令
#define MDM_MB_LOGON				100									//广场登录

//登录模式
#define SUB_MB_LOGON_GAMEID			1									//I D 登录
#define SUB_MB_LOGON_ACCOUNTS		2									//帐号登录
#define SUB_MB_REGISTER_ACCOUNTS	3									//注册帐号
#define SUB_MB_LOGON_VISITOR		4									//游客登录

//登录结果
#define SUB_MB_LOGON_SUCCESS		100									//登录成功
#define SUB_MB_LOGON_FAILURE		101									//登录失败
#define SUB_MB_LOGON_FINISH			102									//登陆完成

//升级提示
#define SUB_MB_UPDATE_NOTIFY		200									//升级提示

//////////////////////////////////////////////////////////////////////////////////

// I D 登录
// struct CMD_MB_LogonGameID
// {
// 	//系统信息
// 	WORD							wModuleID;							//模块标识
// 	dword							dwPlazaVersion;						//广场版本
// 	BYTE                            cbDeviceType;                       //设备类型
// 
// 	//登录信息
// 	dword							dwGameID;							//游戏 I D
// 	TCHAR							szPassword[LEN_MD5];				//登录密码
// 
// 	//连接信息
// 	TCHAR							szMachineID[LEN_MACHINE_ID];		//机器标识
// 	TCHAR							szMobilePhone[LEN_MOBILE_PHONE];	//电话号码
// };
// 
// 帐号登录
// struct CMD_MB_LogonAccounts
// {
// 	//系统信息
// 	WORD							wModuleID;							//模块标识
// 	dword							dwPlazaVersion;						//广场版本
// 	BYTE                            cbDeviceType;                       //设备类型
// 
// 	//登录信息
// 	TCHAR							szPassword[LEN_MD5];				//登录密码
// 	TCHAR							szAccounts[LEN_ACCOUNTS];			//登录帐号
// 
// 	//连接信息
// 	TCHAR							szMachineID[LEN_MACHINE_ID];		//机器标识
// 	TCHAR							szMobilePhone[LEN_MOBILE_PHONE];	//电话号码
// };
// 
// 注册帐号
// struct CMD_MB_RegisterAccounts
// {
// 	//系统信息
// 	WORD							wModuleID;							//模块标识
// 	dword							dwPlazaVersion;						//广场版本
// 	BYTE                            cbDeviceType;                       //设备类型
// 
// 	//密码变量
// 	TCHAR							szLogonPass[LEN_MD5];				//登录密码
// 	TCHAR							szInsurePass[LEN_MD5];				//银行密码
// 
// 	//注册信息
// 	WORD							wFaceID;							//头像标识
// 	BYTE							cbGender;							//用户性别
// 	TCHAR							szAccounts[LEN_ACCOUNTS];			//登录帐号
// 	TCHAR							szNickName[LEN_NICKNAME];			//用户昵称
// 
// 	//连接信息
// 	TCHAR							szMachineID[LEN_MACHINE_ID];		//机器标识
// 	TCHAR							szMobilePhone[LEN_MOBILE_PHONE];	//电话号码
// };
// 
// 登录成功
// struct CMD_MB_LogonSuccess
// {
// 	WORD							wFaceID;							//头像标识
// 	BYTE							cbGender;							//用户性别
// 	dword							dwUserID;							//用户 I D
// 	dword							dwGameID;							//游戏 I D
// 	dword							dwExperience;						//经验数值
// 	dword							dwLoveLiness;						//用户魅力
// 	TCHAR							szNickName[LEN_NICKNAME];			//用户昵称
// };
// 
// 登录失败
//struct CMD_MB_LogonFailure
//{
//	LONG							lResultCode;						//错误代码
//	TCHAR							szDescribeString[128];				//描述消息
//};

// 升级提示
// struct CMD_MB_UpdateNotify
// {
// 	BYTE							cbMustUpdate;						//强行升级
// 	BYTE							cbAdviceUpdate;						//建议升级
// 	dword							dwCurrentVersion;					//当前版本
// };

//////////////////////////////////////////////////////////////////////////////////
//列表命令

#define MDM_MB_SERVER_LIST			101									//列表信息

//列表信息
#define SUB_MB_LIST_TYPE			100									//游戏类型
#define SUB_MB_LIST_KIND			101									//种类列表
#define SUB_MB_LIST_NODE			102									//节点列表
#define SUB_MB_LIST_PAGE			103									//定制列表
#define SUB_MB_LIST_SERVER			104									//房间列表
#define SUB_MB_LIST_MATCH			105									//比赛列表
#define SUB_MB_LIST_FINISH			200									//列表完成

//////////////////////////////////////////////////////////////////////////////////




#pragma pack(pop)

#endif
