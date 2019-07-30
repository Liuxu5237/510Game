#include "CServerItem.h"
#include "tools/tools/StringData.h"
#include "tools/tools/PacketReadAide.h"
#include "tools/tools/PacketWriteAide.h"
#include "tools/tools/MTNotification.h"
#include "../game/IClientKernel.h"
//////////////////////////////////////////////////////////////////////////
//
int __gServerItemRefCount = 0;
IServerItem* __gServerItem = 0;

IServerItem* IServerItem::create()
{
	if (__gServerItemRefCount == 0)
	{
		__gServerItem = new CServerItem();
	}

	__gServerItemRefCount++;
	PLAZZ_PRINTF("IServerItem::create ref:%d\n", __gServerItemRefCount);
	return __gServerItem;
}

void IServerItem::destory()
{
	if (__gServerItemRefCount > 0)
	{
		__gServerItemRefCount--;
		if (__gServerItemRefCount <= 0)
		{
			__gServerItemRefCount = 0;
			delete __gServerItem;
			__gServerItem = 0;
		}
	}
	PLAZZ_PRINTF("IServerItem::destory ref:%d\n", __gServerItemRefCount);

}

IServerItem* IServerItem::get()
{
	return __gServerItem;
}

//////////////////////////////////////////////////////////////////////////
CServerItem::CServerItem() 
	: mReqTableID(INVALID_TABLE)
	, mReqChairID(INVALID_CHAIR)
	, mFindTableID(INVALID_TABLE)
	, mLastJoinTableID(-1)
	, mIsGameReady(false)
	, mMeUserItem(0)
	, mIServerItemSink(0)
	, mIChatSink(0)
	, mNullchaircount(0)
	, mIStringMessageSink(0)
	, mSocketEngine(0)
	, mServiceStatus(ServiceStatus_Unknow)
{
	mIsQuickSitDown=false;
	//memset(&mUserAttribute,   0, sizeof(mUserAttribute));
	//memset(&mServerAttribute, 0, sizeof(mServerAttribute));

	mSocketEngine = ISocketEngine::create();
	mUserManager  = new CPlazaUserManager();
	mUserManager->SetUserManagerSink(this);
	mSocketEngine->setSocketEngineSink(this);
}

CServerItem::~CServerItem()
{
	mLastJoinTableID = INVALID_TABLE;
	IntermitConnect(true);
	mIServerItemSink=0;
	if (mUserManager)
		mUserManager->SetUserManagerSink(0);
	if (mSocketEngine)
		mSocketEngine->setSocketEngineSink(0);
// 	delete mUserManager;
// 	delete mSocketEngine;
	ISocketEngine::destory(mSocketEngine);
	mSocketEngine = 0;
	SafeDelete(mUserManager);
	mUserManager  = 0;
}

//////////////////////////////////////////////////////////////////////////
//配置接口

//设置接口
bool CServerItem::SetServerItemSink(IServerItemSink* pIServerItemSink)
{
	mIServerItemSink = pIServerItemSink;
	return true;
}

//设置接口
bool CServerItem::SetChatSink(IChatSink* pIChatSink)
{
	PLAZZ_PRINTF("CServerItem::SetChatSink\n");
	mIChatSink = pIChatSink;
	return true;
}

//设置接口
bool CServerItem::SetStringMessageSink(IStringMessageSink* pIStringMessageSink)
{
	mIStringMessageSink = pIStringMessageSink;
	return true;
}

//////////////////////////////////////////////////////////////////////////
//属性接口
//用户属性
tagUserAttribute *CServerItem::GetUserAttribute() 
{
	return & mUserAttribute;
}

//房间属性
tagServerAttribute * CServerItem::GetServerAttribute() 
{
	return &mServerAttribute;
}

//服务状态
enServiceStatus CServerItem::GetServiceStatus()
{
	return mServiceStatus;
}

//是否服务状态
bool CServerItem::IsService()
{
	return GetServiceStatus() == ServiceStatus_ServiceIng;
}

//自己状态
bool CServerItem::IsPlayingMySelf()
{
	return ((mMeUserItem!=0)&&(mMeUserItem->GetUserStatus()==US_PLAYING));
}

//设置状态
void CServerItem::SetServiceStatus(enServiceStatus ServiceStatus)
{
	//设置变量
	mServiceStatus=ServiceStatus;
	return;
}

//配置房间
bool CServerItem::SetServerAttribute(CGameServerItem * pGameServerItem,word wAVServerPort,dword dwAVServerAddr)
{
	//房间属性
	CGameKindItem * pGameKindItem=pGameServerItem->m_pGameKindItem;
	memcpy(&mGameKind,&pGameKindItem->m_GameKind,sizeof(mGameKind));
	memcpy(&mGameServer,&pGameServerItem->m_GameServer,sizeof(mGameServer));

	mServerAttribute.wKindID		= mGameServer.wKindID;
	mServerAttribute.wServerID		= mGameServer.wServerID;
	
	mServerAttribute.wServerType	= mGameServer.wServerType;
	mServerAttribute.dwServerRule	= mGameServer.dwServerRule;
	
	mServerAttribute.wAVServerPort	= wAVServerPort;
	mServerAttribute.dwAVServerAddr	= dwAVServerAddr;
	strncpy(mServerAttribute.szServerName, mGameServer.szServerName, LEN_SERVER);

	CParameterGlobal * pParameterGlobal=CParameterGlobal::shared();
	//加载配置
	mParameterGame=pParameterGlobal->GetParameterGame(&mGameKind);
	mParameterServer=pParameterGlobal->GetParameterServer(&mGameServer);

	return true;
}

//////////////////////////////////////////////////////////////////////////
//连接接口

//配置房间
bool CServerItem::ConnectServer(CGameServerItem * pGameServerItem,word wAVServerPort,dword dwAVServerAddr)
{
	//IntermitConnect(true);
	if (mServiceStatus != ServiceStatus_Unknow &&
		mServiceStatus != ServiceStatus_NetworkDown)
	{
		if (mIStringMessageSink)
			mIStringMessageSink->InsertPromptString(SSTRING("System_Tips_1"),DLG_MB_OK);
		return false;
	}

	//房间属性
	SetServerAttribute(pGameServerItem, wAVServerPort, dwAVServerAddr);

	//关闭判断
	ASSERT(mServerAttribute.wServerID!=0);
	if (mServerAttribute.wServerID==0)
	{
		SetServiceStatus(ServiceStatus_Unknow);
		if (mIStringMessageSink)
			mIStringMessageSink->InsertPromptString(SSTRING("System_Tips_2"), DLG_MB_OK);
		return false;
	}

	//变量定义
	//CGlobalUserInfo * pGlobalUserInfo=CGlobalUserInfo::GetInstance();
	//tagGlobalUserData * pGlobalUserData=pGlobalUserInfo->GetGlobalUserData();

	//创建组件
	if (!mSocketEngine->connect(mGameServer.szServerAddr, mGameServer.wServerPort))
	{
		if (mIStringMessageSink)
			mIStringMessageSink->InsertPromptString(SSTRING("System_Tips_3"), DLG_MB_OK);
		return false;
	}

	//设置状态
	SetServiceStatus(ServiceStatus_Entering);
	return true;
}

bool CServerItem::ReconnectServer(CGameServerItem * pGameServerItem,word wAVServerPort,dword dwAVServerAddr)
{
	try
	{

		if (mSocketEngine)
		{
			mSocketEngine->disconnect();
		}

		if (mUserManager)
		{
			mUserManager->ResetUserItem();
		}

	}
	catch (...)
	{
		//log("yezhizhen, huozheyijinbeishanchu");
	}

	mReqTableID		= INVALID_TABLE;
	mReqChairID		= INVALID_CHAIR;
	mFindTableID	= INVALID_TABLE;
	mIsGameReady	= false;
	mMeUserItem		= 0;

	//设置状态
	SetServiceStatus(ServiceStatus_NetworkDown);

	//房间属性
	SetServerAttribute(pGameServerItem, wAVServerPort, dwAVServerAddr);

	//关闭判断
	ASSERT(mServerAttribute.wServerID!=0);
	if (mServerAttribute.wServerID==0)
	{
		SetServiceStatus(ServiceStatus_Unknow);
		if (mIStringMessageSink)
			mIStringMessageSink->InsertPromptString(SSTRING("System_Tips_2"), DLG_MB_OK);
		return false;
	}

	if (!mSocketEngine->connect(mGameServer.szServerAddr, mGameServer.wServerPort))
	{
		if (mIStringMessageSink)
			mIStringMessageSink->InsertPromptString(SSTRING("System_Tips_3"), DLG_MB_OK);
		return false;
	}

	//设置状态
	SetServiceStatus(ServiceStatus_Entering);
	return true;
}

//中断连接
bool CServerItem::IntermitConnect(bool force)
{	
	if (mServiceStatus==ServiceStatus_Unknow ||
		mServiceStatus==ServiceStatus_NetworkDown)
		return false;

	if (IsService())
	{
		if(IClientKernel::get())
		{
			IClientKernel::get()->Intermit(GameExitCode_Client_Active);
		}
	}

	//设置状态
	SetServiceStatus(ServiceStatus_NetworkDown);

	try
	{
		
		if (mSocketEngine)
		{
			mSocketEngine->disconnect();
		}
			
		if (mUserManager)
		{
			mUserManager->ResetUserItem();
		}

	}
	catch (...)
	{
		//log("yezhizhen, huozheyijinbeishanchu");
	}
	
	mReqTableID		= INVALID_TABLE;
	mReqChairID		= INVALID_CHAIR;
	mFindTableID	= INVALID_TABLE;
	mIsGameReady	= false;
	mMeUserItem		= 0;
	
	return true;
}

void CServerItem::TerminConnect()
{
	

	try
	{

		if (mSocketEngine)
		{
			mSocketEngine->disconnect();
		}

		if (mUserManager)
		{
			mUserManager->ResetUserItem();
		}

	}
	catch (...)
	{
		//log("yezhizhen, huozheyijinbeishanchu");
	}

	mReqTableID		= INVALID_TABLE;
	mReqChairID		= INVALID_CHAIR;
	mFindTableID	= INVALID_TABLE;
	mIsGameReady	= false;
	mMeUserItem		= 0;

	mUserAttribute.wChairID = INVALID_CHAIR;
	mUserAttribute.wTableID = INVALID_TABLE;
	//设置状态
	SetServiceStatus(ServiceStatus_NetworkDown);
	mTableViewFrame.SetTableStatus(false);
}

//恢复链接
void CServerItem::ResumeConnect()
{
	if (IClientKernel::get())
	{
		G_NOTIFY_D("RECONNECT_ON_LOSS", MTData::create());
	}
}

//////////////////////////////////////////////////////////////////////////
//网络接口

//发送函数
bool CServerItem::SendSocketData(WORD wMainCmdID, WORD wSubCmdID)
{
	return SendSocketData(wMainCmdID, wSubCmdID, 0, 0);
}

//发送函数
bool CServerItem::SendSocketData(WORD wMainCmdID, WORD wSubCmdID, const char * data, WORD dataSize)
{
	return mSocketEngine->send(wMainCmdID, wSubCmdID, data, dataSize);
}

//发送函数
bool CServerItem::SendSocketDataLua(word wMainCmdID, word wSubCmdID, const cocos2d::Ref * data)
{
	const PacketWriteAide * pWirteAide = (const PacketWriteAide *)data;
	return mSocketEngine->send(wMainCmdID, wSubCmdID, pWirteAide->getBufferData(), pWirteAide->getPosition());
}


//发送登录
bool CServerItem::SendLogonPacket()
{
	//变量定义
	CGlobalUserInfo * pGlobalUserInfo=CGlobalUserInfo::GetInstance();
	
	
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

	//变量定义
	PACKET_AIDE_SIZE();

	packet.write2Byte(pGlobalUserInfo->dwGameID);
	packet.write4Byte(DF::shared()->GetGameVersion());
	packet.writeByte(DF::shared()->GetDeviceType());
	packet.write2Byte(VIEW_MODE_ALL);   // 先随便写一个
	packet.write2Byte( 50 );
	packet.write4Byte(pGlobalUserInfo->dwUserID);
	packet.writeString(pGlobalUserInfo->szDynamicPass, LEN_PASSWORD);
	packet.writeString(DF::shared()->GetMachineID(), LEN_MACHINE_ID);
	

// 	packet.write4Byte(DF::shared()->GetPlazaVersion());
// 	packet.write4Byte(DF::shared()->GetFrameVersion());
// 	packet.write4Byte(DF::shared()->GetGameVersion());
// 	packet.write4Byte(pGlobalUserData->dwUserID);
// 	packet.writeUTF16(u8_2(pGlobalUserData->szPassword), LEN_PASSWORD);
// 	packet.writeUTF16(u8_2(DF::shared()->GetMachineID()), LEN_MACHINE_ID);
// 	packet.write2Byte(mServerAttribute.wKindID);

	//发送数据
	//SendSocketData(MDM_GR_LOGON, SUB_GR_LOGON_MOBILE, packet.getBufferData(), packet.getPosition());

	////变量定义
	//CMD_GR_LogonUserID LogonUserID;
	//zeromemory(&LogonUserID,sizeof(LogonUserID));

	////变量定义
	//CGlobalUserInfo * pGlobalUserInfo=CGlobalUserInfo::GetInstance();
	//tagGlobalUserData * pGlobalUserData=pGlobalUserInfo->GetGlobalUserData();

	////游戏版本
	//LogonUserID.dwProcessVersion=DF::shared()->GetGameVersion();

	////附加信息
	//LogonUserID.dwPlazaVersion=DF::shared()->GetPlazaVersion();
	//LogonUserID.dwFrameVersion=DF::shared()->GetFrameVersion();

	////登录信息
	//LogonUserID.dwUserID=pGlobalUserData->dwUserID;
	//tstrcpyn(LogonUserID.szPassword,pGlobalUserData->szPassword,countarray(LogonUserID.szPassword));
	//LogonUserID.wKindID=mServerAttribute.wKindID;

	////机器标识
	//DF::shared()->GetMachineID(LogonUserID.szMachineID);
	////发送数据
	//SendSocketData(MDM_GR_LOGON,SUB_GR_LOGON_USERID,&LogonUserID,sizeof(LogonUserID));
	return true;
}

//发送配置
bool CServerItem::SendUserRulePacket()
{	
	//变量定义
	CParameterGlobal * pParameterGlobal=CParameterGlobal::shared();
	//变量定义
	BYTE cbRuleMask=0x00;

	//限制地址
	if (pParameterGlobal->m_bLimitSameIP==true)
		cbRuleMask|=UR_LIMIT_SAME_IP;

	//限制胜率
	if (mParameterGame->m_bLimitWinRate==true)
		cbRuleMask|=UR_LIMIT_WIN_RATE;
	

	//限制逃率
	if (mParameterGame->m_bLimitFleeRate==true)
		cbRuleMask|=UR_LIMIT_FLEE_RATE;
	
	//限制积分
	if (mParameterGame->m_bLimitGameScore==true)
		cbRuleMask|=UR_LIMIT_GAME_SCORE;

	PACKET_AIDE_SIZE();
	packet.writeByte(cbRuleMask);
	packet.write2Byte(mParameterGame->m_wMinWinRate);
	packet.write2Byte(mParameterGame->m_wMaxFleeRate);
	packet.write4Byte(mParameterGame->m_lMaxGameScore);
	packet.write4Byte(mParameterGame->m_lMinGameScore);

	//携带密码
 	if ((CServerRule::IsForfendLockTable(mServerAttribute.dwServerRule)==false)&&(mParameterServer->m_bTakePassword==true))
 	{
 		const unsigned short* ucs2 = u8_2(mParameterServer->m_szPassword);
 		int ucs2len = ucs2_len(ucs2);
 		packet.write2Byte(ucs2len);
 		packet.write2Byte(DTP_GR_TABLE_PASSWORD);
		packet.writeString(mParameterServer->m_szPassword);
 	}

	//发送数据
	SendSocketData(MDM_GR_USER, SUB_GR_USER_RULE, packet.getBufferData(), packet.getPosition());
	return true;
}

//发送旁观
bool CServerItem::SendLookonPacket(WORD wTableID, WORD wChairID)
{
	PACKET_AIDE_SIZE();
	packet.write2Byte(wTableID);
	packet.write2Byte(wChairID);

	//发送数据
	SendSocketData(MDM_GR_USER, SUB_GR_USER_LOOKON, packet.getBufferData(), packet.getPosition());

	return true;
}

//发送坐下
bool CServerItem::SendSitDownPacket(WORD wTableID, WORD wChairID, const char* lpszPassword)
{
	//const unsigned short* ucs2 = ;

	//变量定义
	PACKET_AIDE_SIZE();
	packet.write2Byte(wTableID);
	packet.write2Byte(wChairID);
	packet.writeString(lpszPassword, LEN_PASSWORD);
		
	//发送数据
	SendSocketData(MDM_GR_USER, SUB_GR_USER_SITDOWN, packet.getBufferData(), packet.getPosition());

	return true;
}

//发送报名
bool CServerItem::SendFullApply(SCORE fee)
{
	SendSocketData(MDM_GR_MATCH,SUB_GR_MATCH_FEE,(char *)(&fee),sizeof(fee));
	//SendSocketData(MDM_GR_USER,SUB_GR_USER_SITDOWN, packet.getBuffer(), packet.getPosition());
	return true;
}

bool CServerItem::SendStandUp()
{
	SendSocketData(MDM_GR_MATCH,SUB_GR_LEAVE_MATCH);
	return true;
}

//发送起立
bool CServerItem::SendStandUpPacket(WORD wTableID, WORD wChairID, BYTE cbForceLeave)
{
	PACKET_AIDE_SIZE();
	packet.write2Byte(wTableID);
	packet.write2Byte(wChairID);
	packet.writeByte(cbForceLeave);

	//发送数据
	SendSocketData(MDM_GR_USER, SUB_GR_USER_STANDUP, packet.getBufferData(), packet.getPosition());

	return true;
}

//发送聊天
bool CServerItem::SendUserChatPacket(dword dwTargetUserID, const char* pszChatString, dword dwColor)
{
	const unsigned short* ucs2 = u8_2(pszChatString);
	int ucs2len = ucs2_len(ucs2);

	//构造信息
	PACKET_AIDE_SIZE();
	packet.write2Byte(ucs2len);
	packet.write4Byte((dwColor&0xFFFF<<8)|(dwColor&0xFF0000>>16));
	packet.write4Byte(dwTargetUserID);
	//packet.writeUTF16(ucs2, ucs2len);
	packet.writeString(pszChatString);
	//发送命令
	SendSocketData(MDM_GR_USER, SUB_GR_USER_CHAT, packet.getBufferData(), packet.getPosition());

	return true;
}

//发送表情
bool CServerItem::SendExpressionPacket(dword dwTargetUserID, word wItemIndex)
{
	PACKET_AIDE_SIZE();
	packet.write2Byte(wItemIndex);
	packet.write4Byte(dwTargetUserID);

	//发送命令
	SendSocketData(MDM_GR_USER, SUB_GR_USER_EXPRESSION, packet.getBufferData(), packet.getPosition());

	return true;
}

//////////////////////////////////////////////////////////////////////////
//内部函数

//聊天效验
bool CServerItem::EfficacyUserChat(const char* pszChatString, word wExpressionIndex)
{
	//变量定义
	ASSERT(mMeUserItem!=0);
	byte cbMemberOrder=mMeUserItem->GetMemberOrder();
	byte cbMasterOrder=mMeUserItem->GetMasterOrder();

	//长度比较
	if(pszChatString != 0)
	{
		if(utf8_len(pszChatString) >= (LEN_USER_CHAT/2))
		{
			if (mIChatSink)
				mIChatSink->InsertSystemChat(SSTRING("System_Tips_8"));
			return false;
		}
	}

	//房间配置
	if (CServerRule::IsForfendRoomChat(mServerAttribute.dwServerRule)&&(cbMasterOrder==0))
	{
		//原始消息
		if (wExpressionIndex==INVALID_WORD)
		{
			char szChatString[256]={0};
			sprintf(szChatString, SSTRING("System_Tips_9"), pszChatString);

			if (mIChatSink)
				mIChatSink->InsertSystemChat(szChatString);
		}

		if (mIChatSink)
			mIChatSink->InsertSystemChat(SSTRING("System_Tips_10"));

		return false;
	}

	//权限判断
	if (CUserRight::CanRoomChat(mUserAttribute.dwUserRight)==false)
	{
		//原始消息
		if (wExpressionIndex==INVALID_WORD)
		{
			char szChatString[256]={0};
			sprintf(szChatString, SSTRING("System_Tips_9"), pszChatString);

			if (mIChatSink)
				mIChatSink->InsertSystemChat(szChatString);
		}

		//插入消息
		if (mIChatSink)
			mIChatSink->InsertSystemChat(SSTRING("System_Tips_11"));

		return false;
	}

	//速度判断
	static dword dwChatTime=0;
	dword dwCurrentTime=(dword)time(0);
	if ((cbMasterOrder==0)&&((dwCurrentTime-dwChatTime)<=TIME_USER_CHAT))
	{
		//原始消息
		if (wExpressionIndex==INVALID_WORD)
		{
			char szChatString[256]={0};
			sprintf(szChatString, SSTRING("System_Tips_9"), pszChatString);

			if (mIChatSink)
				mIChatSink->InsertSystemChat(szChatString);
		}

		//插入消息
		if (mIChatSink)
			mIChatSink->InsertSystemChat(SSTRING("System_Tips_12"));

		return false;
	}

	//设置变量
	dwChatTime=dwCurrentTime;
	return true;
}

/************************************************************************/
/* 桌子效验                                                             */
/************************************************************************/
bool CServerItem::EfficacyTableRule(word wTableID, word wChairID, bool bReqLookon, char strDescribe[256])
{
	// 效验参数
	ASSERT(wTableID < mTableViewFrame.GetTableCount());
	ASSERT(wChairID < mTableViewFrame.GetChairCount());

	// 状态过滤
	if (mServiceStatus != ServiceStatus_ServiceIng) return false;
	if (wTableID >= mTableViewFrame.GetTableCount()) return false;
	if (wChairID >= mTableViewFrame.GetChairCount()) return false;

	// 变量定义
	ASSERT(CParameterGlobal::shared()!=0);
	CParameterGlobal * pParameterGlobal = CParameterGlobal::shared();

	// 变量定义
	ITableView * pITableView = mTableViewFrame.GetTableViewItem(wTableID);
	//IClientUserItem * pITableUserItem=pITableView->GetClientUserItem(wChairID);

	// 变量定义
	bool bGameStart = pITableView->GetPlayFlag();
	bool bDynamicJoin = CServerRule::IsAllowDynamicJoin(mServerAttribute.dwServerRule);

	// 游戏状态
	if (bGameStart && !bDynamicJoin && !bReqLookon )
	{
		//sprintf(strDescribe, SSTRING("System_Tips_35"));
		return false;
	}

	//其他判断
	if ( !bReqLookon && mMeUserItem->GetMasterOrder() == 0 )
	{
		//规则判断
		for (WORD i = 0; i < mTableViewFrame.GetChairCount();i++)
		{
			//获取用户
			IClientUserItem * pITableUserItem=pITableView->GetClientUserItem(i);
			if (pITableUserItem == 0 || pITableUserItem == mMeUserItem) 
				continue;

			//厌恶玩家
			if (pParameterGlobal->m_bLimitDetest)
			{
				if (pITableUserItem->GetUserCompanion() == CP_DETEST)
				{
					//设置提示
					sprintf(strDescribe, SSTRING("System_Tips_15"), pITableUserItem->GetNickName());
					return false;
				}
			}

			//胜率效验
			if (mParameterGame->m_bLimitWinRate)
			{
				if (((WORD)(pITableUserItem->GetUserWinRate()*1000L)) < mParameterGame->m_wMinWinRate)
				{
					sprintf(strDescribe, SSTRING("System_Tips_16"), pITableUserItem->GetNickName());
					return false;
				}
			}

			//逃率效验
			if (mParameterGame->m_bLimitFleeRate)
			{
				if (((WORD)(pITableUserItem->GetUserFleeRate()*1000L)) < mParameterGame->m_wMaxFleeRate)
				{
					sprintf(strDescribe, SSTRING("System_Tips_17"), pITableUserItem->GetNickName());
					return false;
				}
			}

			//积分效验
			if (mParameterGame->m_bLimitGameScore)
			{
				//最高积分
				if (pITableUserItem->GetUserScore() > mParameterGame->m_lMaxGameScore)
				{
					sprintf(strDescribe, SSTRING("System_Tips_18"), pITableUserItem->GetNickName());
					return false;
				}

				//最低积分
				if (pITableUserItem->GetUserScore() < mParameterGame->m_lMinGameScore)
				{
					sprintf(strDescribe, SSTRING("System_Tips_19"), pITableUserItem->GetNickName());
					return false;
				}
			}
		}
	}

	return true;
}

/************************************************************************/
/* 得到空的座位                                                         */
/************************************************************************/
WORD CServerItem::GetSpaceTableId(WORD iTableid)
{
	int tableCount = mTableViewFrame.GetTableCount();
	int firstNullTable = -1;//第一个空桌号
	for (int i = 0; i < tableCount-1; i++)
	{
		if (i == iTableid)
			continue;
		WORD tableid = (i + mLastJoinTableID + 1) % tableCount;
		ITableView * tableView = mTableViewFrame.GetTableViewItem(tableid);
		if (tableView)
		{
			WORD spaceChairID = INVALID_CHAIR;
			mNullchaircount = tableView->GetNullChairCount(spaceChairID);
			if (mNullchaircount == mTableViewFrame.GetChairCount())
			{
				if (-1 == firstNullTable)
				{
					firstNullTable = tableid;
				}
				continue;
			}
			if (spaceChairID != INVALID_CHAIR)
			{
				mLastJoinTableID = tableid;
				return tableid;
			}
		}
	}
	if (-1 != firstNullTable)
	{
		mLastJoinTableID = firstNullTable;
		return firstNullTable;
	}
	return INVALID_TABLE;
}

/************************************************************************/
/* 得到某个桌子上空的座位                                               */
/************************************************************************/
WORD CServerItem::GetSpaceChairId(WORD tableId)
{
	ITableView * tableView = mTableViewFrame.GetTableViewItem(tableId);
	if (tableView)
	{
		int chairCount = mTableViewFrame.GetChairCount();
		for (WORD j = 0; j < chairCount; j++)
		{
			IClientUserItem * userItem = tableView->GetClientUserItem(j);
			
			 if (!userItem)
			{
				return j;
			}
		}
	}
	return INVALID_CHAIR;
}

/************************************************************************/
/* 得到桌子的个数                                                       */
/************************************************************************/
WORD CServerItem::GetTotalTableCount()
{
	return mTableViewFrame.GetTableCount();
}

/************************************************************************/
/* 得到桌子的管理器                                                     */
/************************************************************************/
CTableViewFrame* CServerItem::GetTableItem()
{
	return &mTableViewFrame;
}




//ITableView * CServerItem::GetTableItem( int tableId )
//{
//	return mTableViewFrame.GetTableViewItem(tableId);
//}
