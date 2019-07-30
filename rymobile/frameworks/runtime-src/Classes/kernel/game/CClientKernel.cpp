#include "CClientKernel.h"
#include "CGameFrameEngine.h"

#include "../server/CServerItem.h"
#include "cocos/base/CCDirector.h"

#include "platform/PlatformHeader.h"
#include "platform/df/GameEventIDDefine.h"

#include "tools/tools/PacketReadAide.h"
#include "tools/tools/PacketWriteAide.h"
#include "tools/tools/StaticData.h"
#include "tools/tools/StringData.h"
#include "tools/tools/MTNotification.h"


//////////////////////////////////////////////////////////////////////////
//
USING_NS_CC;
int __gClentKernelRefCount = 0;
IClientKernel* __gClientKernel = 0;

IClientKernel* IClientKernel::create()
{
	if (__gClentKernelRefCount == 0)
	{
		__gClientKernel = new CGameClientKernel();
	}
	__gClentKernelRefCount++;

	PLAZZ_PRINTF("IClientKernel::create ref:%d\n", __gClentKernelRefCount);
	return __gClientKernel;
}

void IClientKernel::destory()
{
	if (__gClentKernelRefCount > 0)
	{
		__gClentKernelRefCount--;
		if (__gClentKernelRefCount <= 0)
		{
			__gClentKernelRefCount = 0;
			delete __gClientKernel;
			__gClientKernel = 0;
		}
	}

	PLAZZ_PRINTF("IClientKernel::destory ref:%d\n", __gClentKernelRefCount);

}

IClientKernel* IClientKernel::get()
{
	return __gClientKernel;
}

//////////////////////////////////////////////////////////////////////////
CGameClientKernel::CGameClientKernel() 
: mAllowLookon(false)
, mGameStatus(GAME_STATUS_FREE)
, mMeClientUserItem(0)
, mIChatSink(0)
, mIStringMessageSink(0)
, m_bInit(false)
{
	memset(&mUserAttribute,   0, sizeof(mUserAttribute));
	memset(&mGameAttribute,   0, sizeof(mGameAttribute));
	memset(&mServerAttribute, 0, sizeof(mServerAttribute));

	mUserManager  = new CGameUserManager();
	mUserManager->SetUserManagerSink(this);
	//IServerItem::create();
	PLAZZ_PRINTF("flow->CGameClientKernel::CGameClientKernel\n");
	gGlobalUnits.InitGlobalUnits();
}

CGameClientKernel::~CGameClientKernel()
{
	CGameFrameEngine::Get()->CloseGameClient();
	CGameFrameEngine::Get()->Clear();
	mUserManager->SetUserManagerSink(0);
	SafeDelete(mUserManager);
	mUserManager  = 0;
	mIChatSink=0;
	mIStringMessageSink=0;

	//IServerItem::destory();
	gGlobalUnits.UnInitGlobalUnits();

	m_bInit = false;

	PLAZZ_PRINTF("flow->CGameClientKernel::~CGameClientKernel\n");
}

//////////////////////////////////////////////////////////////////////////
// IClientKernel
//////////////////////////////////////////////////////////////////////////

//设置接口
bool CGameClientKernel::SetChatSink(IChatSink* pIChatSink)
{
	PLAZZ_PRINTF("flow->CGameClientKernel::SetChatSink\n");
	mIChatSink = pIChatSink;
	return true;
}

//设置接口
bool CGameClientKernel::SetStringMessageSink(IStringMessageSink* pIStringMessageSink)
{
	PLAZZ_PRINTF("flow->CGameClientKernel::SetStringMessageSink\n");
	mIStringMessageSink = pIStringMessageSink;
	return true;
}

//内核配置
bool CGameClientKernel::Init()
{
	PLAZZ_PRINTF("flow->CGameClientKernel::Init\n");

	mGameAttribute.wKindID = DF::shared()->GetGameKindID();
	mGameAttribute.dwClientVersion = DF::shared()->GetGameVersion();
	mGameAttribute.wChairCount = DF::shared()->GetGamePlayer();
	
	DF::shared()->GetGameName(mGameAttribute.szGameName);

	if(mUserManager)	
		mUserManager->ResetUserItem();

	mMeClientUserItem = 0;

	if (IServerItem::get())
		IServerItem::get()->OnGFGameReady(m_bInit);

	if (!m_bInit)
	{
		m_bInit = true;
	}
	return true;
}

//游戏界面关闭
bool CGameClientKernel::Intermit(int iExitCode)
{
	PLAZZ_PRINTF("flow->CGameClientKernel::Intermit\n");

	if( GameExitCode_Normal == iExitCode){

		if(GetGameStatus() == GAME_STATUS_PLAY){

			G_NOTIFY_D("game_event", MTData::create(GAME_EVENT_ID_CLOSE_GAME_CONFIRM));
		}
		else
		{
			if (IServerItem::get())
			{
				IServerItem::get()->OnGFGameClose(iExitCode);
			}
			else
			{
				IClientKernel::destory();
			}
		}
	}
	else if(GameExitCode_Shutdown == iExitCode ||GameExitCode_Timeout == iExitCode){

		if (IServerItem::get())
		{
			IServerItem::get()->OnGFGameClose(iExitCode);
		}
		else
		{
			IClientKernel::destory();
		}
	}
	else if(GameExitCode_Client_Active == iExitCode)
	{
		IClientKernel::destory();
	}
	else if (GameExitCode_Gold_lack == iExitCode)
	{
		G_NOTIFY_D("game_event", MTData::create(GAME_EVENT_ID_GOLD_NOT_ENOUGH));
	}
	else if (GameExitCode_Server_Notify_Close_Client == iExitCode)
	{
		G_NOTIFY_D("game_event", MTData::create(GAME_EVENT_ID_SERVER_NOTIFY_CLOSE_CLIENT));
	}


	return true;
}

//关闭连接
bool CGameClientKernel::IntermitConnect(int iExitCode)
{
	PLAZZ_PRINTF("flow->CGameClientKernel::IntermitConnect\n %d ", iExitCode);

	if (IServerItem::get())
	{
		IServerItem::get()->IntermitConnect(true);
	}

	return true;
}

//////////////////////////////////////////////////////////////////////////
//属性接口

//用户属性
tagUserAttribute * CGameClientKernel::GetUserAttribute()
{
	return &mUserAttribute;
}

//游戏属性
tagGameAttribute * CGameClientKernel::GetGameAttribute()
{
	return &mGameAttribute;
}

//房间属性
tagServerAttribute * CGameClientKernel::GetServerAttribute()
{
	return &mServerAttribute;
}

//////////////////////////////////////////////////////////////////////////
//模式接口

//单机模式
bool CGameClientKernel::IsSingleMode()
{
	return false;
}

//旁观状态
bool CGameClientKernel::IsLookonMode()
{
	if (mMeClientUserItem == 0) return true;
	return mMeClientUserItem->GetUserStatus() == US_LOOKON;
}

//允许状态
bool CGameClientKernel::IsAllowLookon()
{
	return mAllowLookon;

}

// 是否是比赛房间
bool CGameClientKernel::IsMatchRoom()
{
	if((mServerAttribute.wServerType&GAME_GENRE_FULL) ||  (mServerAttribute.wServerType&GAME_GENRE_TIME))
	{
		return true;
	}

	return false;
}

//////////////////////////////////////////////////////////////////////////
//状态接口

//获取状态
byte CGameClientKernel::GetGameStatus()
{
	return mGameStatus;
}

//设置状态
void CGameClientKernel::SetGameStatus(byte cbGameStatus)
{
	mGameStatus = cbGameStatus;
}


//////////////////////////////////////////////////////////////////////////
//用户接口

//自己位置
word CGameClientKernel::GetMeChairID()
{
	if (mMeClientUserItem == 0) return INVALID_CHAIR;
	return mMeClientUserItem->GetChairID();
}

//自己位置
IClientUserItem * CGameClientKernel::GetMeUserItem()
{
	return mMeClientUserItem;
}

//游戏用户
IClientUserItem * CGameClientKernel::GetTableUserItem(word wChairID)
{
	return mUserManager->GetTableUserItem(wChairID);
}

//查找用户
IClientUserItem * CGameClientKernel::SearchUserByUserID(dword dwUserID)
{
	return mUserManager->SearchUserByUserID(dwUserID);
}

//查找用户
IClientUserItem * CGameClientKernel::SearchUserByGameID(dword dwGameID)
{
	return mUserManager->SearchUserByGameID(dwGameID);
}

//查找用户
IClientUserItem * CGameClientKernel::SearchUserByNickName(const char* szNickName)
{
	return mUserManager->SearchUserByNickName(szNickName);
}

//旁观用户
IClientUserItem * CGameClientKernel::EnumLookonUserItem(word wEnumIndex)
{
	return mUserManager->EnumLookonUserItem(wEnumIndex);
}


//////////////////////////////////////////////////////////////////////////
//网络接口

//发送函数
bool CGameClientKernel::SendSocketData(word wMainCmdID, word wSubCmdID)
{
	return SendSocketData(wMainCmdID, wSubCmdID, 0, 0);
}

//发送函数
bool CGameClientKernel::SendSocketData(word wMainCmdID, word wSubCmdID, const char * data, word dataSize)
{
	if (!IServerItem::get())
		return false;

	return IServerItem::get()->GFSendData(wMainCmdID, wSubCmdID, data, dataSize);
}

//发送函数
bool CGameClientKernel::SendSocketDataLua(word wMainCmdID, word wSubCmdID, const cocos2d::Ref * data, word dataSize)
{
	const PacketWriteAide * pWirteAide = (const PacketWriteAide *)data;
	return IServerItem::get()->GFSendData(wMainCmdID, wSubCmdID, pWirteAide->getBufferData(), dataSize);
}

//////////////////////////////////////////////////////////////////////////
//功能接口
//发送进入场景
bool CGameClientKernel::SendGameOption()
{
	PLAZZ_PRINTF("CGameClientKernel::SendGameOption ..");
	//发送场景消息
	//变量定义
	PACKET_AIDE_SIZE();
	packet.writeByte(gGlobalUnits.m_bAllowLookon);
	packet.write4Byte(DF::shared()->GetFrameVersion());
	packet.write4Byte(mGameAttribute.dwClientVersion);

	PLAZZ_PRINTF("CGameClientKernel::SendGameOption ok");

	//发送数据
	return SendSocketData(MDM_GF_FRAME, SUB_GF_GAME_OPTION, packet.getBufferData(), packet.getPosition());

	////发送场景消息
	////变量定义
	//CMD_GF_GameOption GameOption;
	//zeromemory(&GameOption,sizeof(GameOption));

	////构造数据
	//GameOption.dwFrameVersion=DF::shared()->GetFrameVersion();
	//GameOption.cbAllowLookon=gGlobalUnits.m_bAllowLookon;
	//GameOption.dwClientVersion=mGameAttribute.dwClientVersion;

	////发送数据
	//return SendSocketData(MDM_GF_FRAME,SUB_GF_GAME_OPTION,&GameOption,sizeof(GameOption));
}

//发送准备
bool CGameClientKernel::SendUserReady()
{
	if (mMeClientUserItem == 0) return false;
	return SendSocketData(MDM_GF_FRAME, SUB_GF_USER_READY, 0, 0);
}

//旁观控制
bool CGameClientKernel::SendUserLookon(dword dwUserID, bool bAllowLookon)
{
	if (!IsLookonMode()) {
		PACKET_AIDE_SIZE();
		packet.write4Byte(dwUserID);
		packet.writeByte(bAllowLookon?1:0);
		return SendSocketData(MDM_GF_FRAME, SUB_GF_LOOKON_CONFIG, packet.getBufferData(), packet.getPosition());

		//CMD_GF_LookonConfig lookon_config;
		//lookon_config.dwUserID = dwUserID;
		//lookon_config.cbAllowLookon = bAllowLookon ? TRUE : FALSE;
		//return SendSocketData(MDM_GF_FRAME, SUB_GF_LOOKON_CONFIG, &lookon_config, sizeof(lookon_config));
	}
	return true;
}

//发送表情
bool CGameClientKernel::SendUserExpression(dword dwTargetUserID, word wItemIndex)
{
	//变量定义
	PACKET_AIDE_SIZE();
	packet.write2Byte(wItemIndex);
	packet.write4Byte(dwTargetUserID);
	//发送命令
	SendSocketData(MDM_GF_FRAME, SUB_GF_USER_EXPRESSION, packet.getBufferData(), packet.getPosition());

	////变量定义
	//CMD_GF_C_UserExpression UserExpression;
	//zeromemory(&UserExpression,sizeof(UserExpression));

	////构造信息
	//UserExpression.wItemIndex=wItemIndex;
	//UserExpression.dwTargetUserID=dwTargetUserID;

	////发送命令
	//SendSocketData(MDM_GF_FRAME,SUB_GF_USER_EXPRESSION,&UserExpression,sizeof(UserExpression));

	return true;
}

//发送聊天
bool CGameClientKernel::SendUserChatMessage(dword dwTargetUserID, const char* pszChatString, dword crColor)
{
	if (mMeClientUserItem == 0) return false;

	const unsigned short* ucs2 = u8_2(pszChatString);
	int ucs2len = ucs2_len(ucs2);
	PACKET_AIDE_SIZE();
	packet.writeByte(ucs2len);
	packet.write4Byte((crColor<<8)|(crColor>>24&0xff));
	packet.write4Byte(dwTargetUserID);
	packet.writeString(pszChatString);
	
	return SendSocketData(MDM_GF_FRAME, SUB_GF_USER_CHAT, packet.getBufferData(), packet.getPosition());

	//CMD_GF_C_UserChat user_chat;
	//tstrcpyn(user_chat.szChatString, pszChatString, countarray(user_chat.szChatString));
	//user_chat.dwChatColor		= crColor;
	//user_chat.dwTargetUserID	= dwTargetUserID;
	//user_chat.wChatLength		= CountStringBuffer(user_chat.szChatString);
	//word head_size				= sizeof(user_chat) - sizeof(user_chat.szChatString);
	//return SendSocketData(MDM_GF_FRAME, SUB_GF_USER_CHAT, &user_chat, head_size + user_chat.wChatLength * sizeof(tchar));
}


//////////////////////////////////////////////////////////////////////////
//辅助接口

//激活框架
void CGameClientKernel::ActiveGameFrame()
{
	PLAZZ_PRINTF("flow->CGameClientKernel::ActiveGameFrame\n");

}

//切换椅子
word CGameClientKernel::SwitchViewChairID(word wChairID)
{
	return wChairID;
}


//////////////////////////////////////////////////////////////////////////
// IUserManagerSink
//////////////////////////////////////////////////////////////////////////
void CGameClientKernel::OnUserItemAcitve(IClientUserItem* pIClientUserItem)
{
	PLAZZ_PRINTF("flow->CGameClientKernel::OnUserItemAcitve\n");

	if (pIClientUserItem == 0) 
		return;
	if (mMeClientUserItem == 0 && mUserAttribute.dwUserID == pIClientUserItem->GetUserID()) 
	{
		mMeClientUserItem = pIClientUserItem;
		CGameFrameEngine::Get()->OnGFWaitTips(false);
	}
	//assert(0 != mMeClientUserItem);
	CGameFrameEngine::Get()->OnEventUserEnter(pIClientUserItem, pIClientUserItem->GetUserStatus() == US_LOOKON);
}

void CGameClientKernel::OnUserItemDelete(IClientUserItem* pIClientUserItem)
{
	PLAZZ_PRINTF("flow->CGameClientKernel::OnUserItemDelete\n");

	if (pIClientUserItem == 0) 
		return;

	CGameFrameEngine::Get()->OnEventUserLeave(pIClientUserItem, pIClientUserItem->GetUserStatus() == US_LOOKON);
}


//用户更新
void CGameClientKernel::OnUserFaceUpdate(IClientUserItem* pIClientUserItem)
{
	PLAZZ_PRINTF("flow->CGameClientKernel::OnUserFaceUpdate\n");

	////效验状态
	//ASSERT((m_UserEventSinkArray.GetCount()>0L)&&(pIClientUserItem!=0));
	//if ((m_UserEventSinkArray.GetCount()==0L)||(pIClientUserItem==0)) return;

	////变量定义
	//IUserEventSink * pIUserEventSink=0;
	//bool bLookonUser=(pIClientUserItem->GetUserStatus()==US_LOOKON);

	////用户通知
	//for (INT_PTR i=0;i<m_UserEventSinkArray.GetCount();i++)
	//{
	//	pIUserEventSink=m_UserEventSinkArray[i];
	//	pIUserEventSink->OnEventCustomFace(pIClientUserItem,bLookonUser);
	//}

	if (pIClientUserItem == 0) 
		return;

	CGameFrameEngine::Get()->OnEventCustomFace(pIClientUserItem, pIClientUserItem->GetUserStatus() == US_LOOKON);

	return;
}

void CGameClientKernel::OnUserItemUpdate(IClientUserItem* pIClientUserItem, const tagUserScore& LastUserScore)
{
	if (pIClientUserItem == 0) 
		return;

	CGameFrameEngine::Get()->OnEventUserScore(pIClientUserItem, pIClientUserItem->GetUserStatus() == US_LOOKON);
}

void CGameClientKernel::OnUserItemUpdate(IClientUserItem* pIClientUserItem, const tagUserStatus& LastUserStatus)
{
	PLAZZ_PRINTF("flow->CGameClientKernel::OnUserItemUpdate tagUserStatus\n");

	if (pIClientUserItem == 0) 
		return;

	CGameFrameEngine::Get()->OnEventUserStatus(pIClientUserItem, pIClientUserItem->GetUserStatus() == US_LOOKON);
}


//用户更新
void CGameClientKernel::OnUserItemUpdate(IClientUserItem* pIClientUserItem, const tagUserAttrib & UserAttrib)
{
	PLAZZ_PRINTF("flow->CGameClientKernel::OnUserItemUpdate tagUserAttrib\n");

	if (pIClientUserItem == 0) 
		return;

	CGameFrameEngine::Get()->OnEventUserAttrib(pIClientUserItem, pIClientUserItem->GetUserStatus() == US_LOOKON);
	return;
}
