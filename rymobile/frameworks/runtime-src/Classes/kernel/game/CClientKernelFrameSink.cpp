#include "CClientKernel.h"
#include "CGameFrameEngine.h"
#include "tools/tools/PacketReadAide.h"
#include "tools/tools/PacketWriteAide.h"
#include "../server/IServerItemSink.h"
#include "../server/CServerItem.h"
#include "CCLuaEngine.h"
#include "lua/LuaStackEx.h"


IGameFrameSink* IGameFrameSink::getInterface()
{
	return (IGameFrameSink*)IClientKernel::get();
}

//房间配置
void CGameClientKernel::OnGFConfigServer(const tagUserAttribute * UserAttribute, const tagServerAttribute * ServerAttribute)
{
	//PLAZZ_PRINTF("flow->CGameClientKernel::OnGFConfigServer\n");

	memcpy(&mUserAttribute, UserAttribute, sizeof(mUserAttribute));
	memcpy(&mServerAttribute, ServerAttribute, sizeof(mServerAttribute));
}

//配置完成
void CGameClientKernel::OnGFConfigFinish()
{
	//PLAZZ_PRINTF("flow->CGameClientKernel::OnGFConfigFinish\n")
	if (CGameFrameEngine::Get()->SetupGameClient())
		return;
}

bool CGameClientKernel::OnGFEventSocket(int main, int sub, void* data, int dataSize)
{
	//PLAZZ_PRINTF("flow->CGameClientKernel::OnGFEventSocket\n");


	if (sub == 50)
	{
		int x = 100;
	}
	
	//游戏消息和 管理员消息 都走游戏消息 别问我为什么
	if (main == MDM_GF_GAME)
	{
		//效验状态
		return CGameFrameEngine::Get()->OnEventGameMessage(sub, data, dataSize);
	}
	//游戏消息
	if (main==MDM_GR_INSURE)
	{
		PLAZZ_PRINTF("flow->CGameClientKernel::OnGFEventSocket MDM_GR_INSURE\n");
		//if(mIClientKernelSink)
		//	mIClientKernelSink->OnEventInsureMessage(sub,data,dataSize);

		return true;
	}

	//内核处理
	if (main==MDM_GF_FRAME)
	{
		if (sub >= SUB_MATCH_CMD_START && sub < SUB_MATCH_CMD_END)
		{
			LuaEngine * pEngine = LuaEngine::defaultEngine();
			if (pEngine){

				LuaStackEx * luaStack = static_cast<LuaStackEx*>(pEngine->getLuaStack());

				PACKET_AIDE_DATA(data);
				return luaStack->call_script_fun("gameMatchInterface.OnSocketFrameMatch", sub, (cocos2d::Ref *)&packet, dataSize) > 0 ? true : false;
			}
		}


		switch (sub)
		{
		case SUB_GF_USER_CHAT:			//用户聊天
			{
				return OnSocketSubUserChat(data,dataSize);
			}
		case SUB_GR_TABLE_TALK:
			{
				return OnSocketSubUserTalk(data,dataSize);
			}
		case SUB_GF_USER_EXPRESSION:	//用户表情
			{
				return OnSocketSubExpression(data,dataSize);
			}
		case SUB_GF_GAME_STATUS:		//游戏状态
			{
				return OnSocketSubGameStatus(data,dataSize);
			}
		case SUB_GF_GAME_SCENE:			//游戏场景
			{
				return OnSocketSubGameScene(data,dataSize);
			}
		case SUB_GF_LOOKON_STATUS:		//旁观状态
			{
				return OnSocketSubLookonStatus(data,dataSize);
			}
		case SUB_GF_SYSTEM_MESSAGE:		//系统消息
			{
				return OnSocketSubSystemMessage(data,dataSize);
			}
		case SUB_GF_ACTION_MESSAGE:		//动作消息
			{
				return OnSocketSubActionMessage(data,dataSize);
			}
		case SUB_GF_USER_READY:			//用户准备
			{
				if(mMeClientUserItem ==0 || mMeClientUserItem->GetUserStatus()>=US_READY)
					return true;
				SendUserReady();

				//CGameFrameEngine::Get()->OnGFMatchWaitTips(0);
				return true;
			}
		//case SUB_GR_USER_WAIT_DISTRIBUTE:   //等待提示
		//	{
		//		if (mIClientKernelSink)
		//			mIClientKernelSink->OnGFWaitTips(true);
		//		return true;
		//	}

			default:
			{
				ASSERT(FALSE);
			}
		}

		return false;
	}

	return false;
}

bool CGameClientKernel::OnSocketSubUserTalk(void* data, int dataSize)
{
	return CGameFrameEngine::Get()->RecvTalk(data,dataSize);
}


//用户聊天
bool CGameClientKernel::OnSocketSubUserChat(void* data, int dataSize)
{
	PLAZZ_PRINTF("flow->CGameClientKernel::OnSocketSubUserChat\n");

	int baseSize=2+4+4+4;
	ASSERT(dataSize>=baseSize)
	if(dataSize<baseSize) return false;

	//显示消息
	if (mIChatSink==0) return true;

	//变量定义
	PACKET_AIDE_DATA(data);
	word wChatLength = packet.read2Byte();
	dword dwChatColor = packet.read4Byte();
	dword dwSendUserID = packet.read4Byte();
	dword dwTargetUserID = packet.read4Byte();

	int len = (dataSize-baseSize)/2;

	dwChatColor = ((dwChatColor & 0xFF) << 16) | (dwChatColor >> 8);

	//获取用户
	IClientUserItem * pISendUserItem=mUserManager->SearchUserByUserID(dwSendUserID);
	if (pISendUserItem == 0)
	{
		return true;
	}
	//消息过虑
	if (pISendUserItem!=mMeClientUserItem)
	{
		//社团变量
		dword dwUserGroupID=pISendUserItem->GetGroupID();
		dword dwMySelfGroupID=mMeClientUserItem->GetGroupID();

		//社团判断
		bool bSameGroup=false;
		if ((dwMySelfGroupID!=0L)&&(dwMySelfGroupID==dwUserGroupID)) bSameGroup=true;

		//变量定义
		byte cbUserCompanion=pISendUserItem->GetUserCompanion();

		//好友模式
		if ((gGlobalUnits.m_cbMessageMode==MESSAGE_MODE_FRIEND)&&(cbUserCompanion!=CP_FRIEND)&&(bSameGroup==false))
			return true;

		//厌恶模式
		if ((gGlobalUnits.m_cbMessageMode==MESSAGE_MODE_DETEST)&&(cbUserCompanion==CP_DETEST)&&(bSameGroup==false))
			return true;
	}

	//插入消息
	if (dwTargetUserID!=0L)
	{
		//获取用户
		IClientUserItem * pIRecvUserItem=mUserManager->SearchUserByUserID(dwTargetUserID);

		if (pIRecvUserItem!=0)
		{
			//插入消息
			mIChatSink->InsertUserChat(
				pISendUserItem->GetNickName(), pIRecvUserItem->GetNickName(),
				packet.readString(len).c_str(), dwChatColor);
		}
	}
	else 
	{
		//插入消息
		mIChatSink->InsertUserChat(pISendUserItem->GetNickName(), packet.readString(len).c_str(), dwChatColor);
	}

	return true;

	////变量定义
	//CMD_GF_S_UserChat * pUserChat=(CMD_GF_S_UserChat *)data;

	////效验参数
	//ASSERT(dataSize>=(sizeof(CMD_GF_S_UserChat)-sizeof(pUserChat->szChatString)));
	//ASSERT(dataSize==(sizeof(CMD_GF_S_UserChat)-sizeof(pUserChat->szChatString)+pUserChat->wChatLength*sizeof(pUserChat->szChatString[0])));

	////效验参数
	//if (dataSize<(sizeof(CMD_GF_S_UserChat)-sizeof(pUserChat->szChatString))) return false;
	//if (dataSize!=(sizeof(CMD_GF_S_UserChat)-sizeof(pUserChat->szChatString)+pUserChat->wChatLength*sizeof(pUserChat->szChatString[0]))) return false;

	////显示消息
	//if (mIChatSink==0) return true;

	////获取用户
	//IClientUserItem * pISendUserItem=mUserManager->SearchUserByUserID(pUserChat->dwSendUserID);
	//if (pISendUserItem==0) return true;

	////消息过虑
	//if (pISendUserItem!=mMeClientUserItem)
	//{
	//	//社团变量
	//	dword dwUserGroupID=pISendUserItem->GetGroupID();
	//	dword dwMySelfGroupID=mMeClientUserItem->GetGroupID();

	//	//社团判断
	//	bool bSameGroup=false;
	//	if ((dwMySelfGroupID!=0L)&&(dwMySelfGroupID==dwUserGroupID)) bSameGroup=true;

	//	//变量定义
	//	byte cbUserCompanion=pISendUserItem->GetUserCompanion();
	//		
	//	//好友模式
	//	if ((gGlobalUnits.m_cbMessageMode==MESSAGE_MODE_FRIEND)&&(cbUserCompanion!=CP_FRIEND)&&(bSameGroup==false))
	//	{
	//		return true;
	//	}

	//	//厌恶模式
	//	if ((gGlobalUnits.m_cbMessageMode==MESSAGE_MODE_DETEST)&&(cbUserCompanion==CP_DETEST)&&(bSameGroup==false))
	//	{
	//		return true;
	//	}
	//}

	////插入消息
	//if (pUserChat->dwTargetUserID!=0L)
	//{
	//	//获取用户
	//	IClientUserItem * pIRecvUserItem=mUserManager->SearchUserByUserID(pUserChat->dwTargetUserID);

	//	if (pIRecvUserItem!=0)
	//	{
	//		//插入消息
	//		const tchar* pszSendUser=pISendUserItem->GetNickName();
	//		const tchar* pszRecvUser=pIRecvUserItem->GetNickName();
	//		dword dwColor = ((pUserChat->dwChatColor & 0xFF) << 16) | (pUserChat->dwChatColor >> 8);
	//		mIChatSink->InsertUserChat(pszSendUser,pszRecvUser,pUserChat->szChatString,dwColor);
	//	}
	//}
	//else 
	//{
	//	//插入消息
	//	const tchar* pszSendUser=pISendUserItem->GetNickName();
	//	dword dwColor = ((pUserChat->dwChatColor & 0xFF) << 16) | (pUserChat->dwChatColor >> 8);
	//	mIChatSink->InsertUserChat(pszSendUser,pUserChat->szChatString,dwColor);
	//}

	//return true;
}


//用户表情
bool CGameClientKernel::OnSocketSubExpression(void* data, int dataSize)
{
	PLAZZ_PRINTF("flow->CGameClientKernel::OnSocketSubExpression\n");

	//效验参数
	ASSERT(dataSize==9);
	if (dataSize!=9) return false;

	//显示消息
	if (mIChatSink==0) return true;

	PACKET_AIDE_DATA(data);
	word wItemIndex=packet.read2Byte();
	dword dwSendUserID=packet.read4Byte();
	dword dwTargetUserID=packet.read4Byte();

	//获取用户
	IClientUserItem * pISendUserItem=mUserManager->SearchUserByUserID(dwSendUserID);
	if (pISendUserItem==0) return true;

	//消息过虑
	if (pISendUserItem!=mMeClientUserItem)
	{
		//社团变量
		dword dwUserGroupID=pISendUserItem->GetGroupID();
		dword dwMySelfGroupID=mMeClientUserItem->GetGroupID();

		//社团判断
		bool bSameGroup=false;
		if ((dwMySelfGroupID!=0L)&&(dwMySelfGroupID==dwUserGroupID)) bSameGroup=true;

		//变量定义
		byte cbUserCompanion=pISendUserItem->GetUserCompanion();

		//好友模式
		if ((gGlobalUnits.m_cbMessageMode==MESSAGE_MODE_FRIEND)&&(cbUserCompanion!=CP_FRIEND)&&(bSameGroup==false))
		{
			return true;
		}

		//厌恶模式
		if ((gGlobalUnits.m_cbMessageMode==MESSAGE_MODE_DETEST)&&(cbUserCompanion==CP_DETEST)&&(bSameGroup==false))
		{
			return true;
		}
	}

	//插入消息
	if (dwTargetUserID!=0L)
	{
		//获取用户
		IClientUserItem * pIRecvUserItem=mUserManager->SearchUserByUserID(dwTargetUserID);

		//插入消息
		if (pIRecvUserItem!=0)
		{
			mIChatSink->InsertExpression(pISendUserItem->GetNickName(), pIRecvUserItem->GetNickName(),wItemIndex);
		}
	}
	else
	{
		//插入消息
		mIChatSink->InsertExpression(pISendUserItem->GetNickName(),wItemIndex);
	}

	return true;

	////效验参数
	//ASSERT(dataSize==sizeof(CMD_GF_S_UserExpression));
	//if (dataSize!=sizeof(CMD_GF_S_UserExpression)) return false;

	////显示消息
	//if (mIChatSink==0) return true;

	////变量定义
	//CMD_GF_S_UserExpression * pUserExpression=(CMD_GF_S_UserExpression *)data;

	////获取用户
	//IClientUserItem * pISendUserItem=mUserManager->SearchUserByUserID(pUserExpression->dwSendUserID);
	//if (pISendUserItem==0) return true;

	////消息过虑
	//if (pISendUserItem!=mMeClientUserItem)
	//{
	//	//社团变量
	//	dword dwUserGroupID=pISendUserItem->GetGroupID();
	//	dword dwMySelfGroupID=mMeClientUserItem->GetGroupID();

	//	//社团判断
	//	bool bSameGroup=false;
	//	if ((dwMySelfGroupID!=0L)&&(dwMySelfGroupID==dwUserGroupID)) bSameGroup=true;

	//	//变量定义
	//	byte cbUserCompanion=pISendUserItem->GetUserCompanion();
	//	
	//	//好友模式
	//	if ((gGlobalUnits.m_cbMessageMode==MESSAGE_MODE_FRIEND)&&(cbUserCompanion!=CP_FRIEND)&&(bSameGroup==false))
	//	{
	//		return true;
	//	}

	//	//厌恶模式
	//	if ((gGlobalUnits.m_cbMessageMode==MESSAGE_MODE_DETEST)&&(cbUserCompanion==CP_DETEST)&&(bSameGroup==false))
	//	{
	//		return true;
	//	}
	//}

	////插入消息
	//if (pUserExpression->dwTargetUserID!=0L)
	//{
	//	//获取用户
	//	IClientUserItem * pIRecvUserItem=mUserManager->SearchUserByUserID(pUserExpression->dwTargetUserID);

	//	//插入消息
	//	if (pIRecvUserItem!=0)
	//	{
	//		const tchar* pszSendUser=pISendUserItem->GetNickName();
	//		const tchar* pszRecvUser=pIRecvUserItem->GetNickName();
	//		mIChatSink->InsertExpression(pszSendUser,pszRecvUser,pUserExpression->wItemIndex);
	//	}
	//}
	//else
	//{
	//	//插入消息
	//	const tchar* pszSendUser=pISendUserItem->GetNickName();
	//	mIChatSink->InsertExpression(pszSendUser,pUserExpression->wItemIndex);
	//}

	//return true;
}

//游戏状态
bool CGameClientKernel::OnSocketSubGameStatus(void* data, int dataSize)
{
	PLAZZ_PRINTF("flow->CGameClientKernel::OnSocketSubGameStatus\n");

	PACKET_AIDE_DATA(data);

	//设置变量
	mGameStatus=packet.readByte();
	mAllowLookon=packet.readByte()!=0;

	return true;

	////效验参数
	//ASSERT(dataSize==sizeof(CMD_GF_GameStatus));
	//if (dataSize!=sizeof(CMD_GF_GameStatus)) return false;

	////消息处理
	//CMD_GF_GameStatus * pGameStatus=(CMD_GF_GameStatus *)data;

	////设置变量
	//mGameStatus=pGameStatus->cbGameStatus;
	//mAllowLookon=pGameStatus->cbAllowLookon?true:false;

	//return true;
}

//游戏场景
bool CGameClientKernel::OnSocketSubGameScene(void* data, int dataSize)
{
	PLAZZ_PRINTF("flow->CGameClientKernel::OnSocketSubGameScene\n");

	//效验状态
	ASSERT(mMeClientUserItem!=0);
	if (mMeClientUserItem==0) return true;

	//场景处理
	bool bLookonUser=(mMeClientUserItem->GetUserStatus()==US_LOOKON);
	return CGameFrameEngine::Get()->OnEventSceneMessage(mGameStatus, bLookonUser, data, dataSize);
}

//旁观状态
bool CGameClientKernel::OnSocketSubLookonStatus(void* data, int dataSize)
{
	PLAZZ_PRINTF("flow->CGameClientKernel::OnSocketSubLookonStatus\n");

	//消息处理
	if (IsLookonMode()==true)
	{
		byte cbAllowLookon = ((unsigned char*)data)[0];
		
		//事件处理
		mAllowLookon=cbAllowLookon!=0;

		//事件通知
		ASSERT(mMeClientUserItem!=0);

		CGameFrameEngine::Get()->OnEventLookonMode(data, dataSize);

		//提示消息
		if (mAllowLookon==true)
		{
			if (mIStringMessageSink!=0)
				mIStringMessageSink->InsertNormalString(a_u8("您被允许观看玩家游戏"));
		}
		else
		{
			if (mIStringMessageSink!=0)
				mIStringMessageSink->InsertNormalString(a_u8("您被禁止观看玩家游戏"));
		}
	}

	return true;

	////效验参数
	//ASSERT(dataSize==sizeof(CMD_GF_LookonStatus));
	//if (dataSize!=sizeof(CMD_GF_LookonStatus)) return false;

	////消息处理
	//if (IsLookonMode()==true)
	//{
	//	//变量定义
	//	CMD_GF_LookonStatus * pLookonStatus=(CMD_GF_LookonStatus *)data;

	//	//事件处理
	//	mAllowLookon=(pLookonStatus->cbAllowLookon==TRUE)?true:false;

	//	//事件通知
	//	ASSERT(mMeClientUserItem!=0);

	//	if (mIClientKernelSink)
	//		mIClientKernelSink->OnEventLookonMode(data,dataSize);

	//	//提示消息
	//	if (mAllowLookon==true)
	//	{
	//		if (mIStringMessageSink!=0)
	//			mIStringMessageSink->InsertNormalString(T_T("您被允许观看玩家游戏"));
	//	}
	//	else
	//	{
	//		if (mIStringMessageSink!=0)
	//			mIStringMessageSink->InsertNormalString(T_T("您被禁止观看玩家游戏"));
	//	}
	//}

	//return true;
}

//系统消息
bool CGameClientKernel::OnSocketSubSystemMessage(void* data, int dataSize)
{
	PLAZZ_PRINTF("flow->CGameClientKernel::OnSocketSubSystemMessage\n");

	PACKET_AIDE_DATA(data);
	word wType = packet.read2Byte();
	word wLength = packet.read2Byte();

	int len=(dataSize-4)/2;
	std::string sString;
	sString = packet.readString(len);

	//滚动消息
	if((wType&SMT_TABLE_ROLL))
	{
		//tstring str = pSystemMessage->szString;
		//if(str.find(T_T("系统配桌"))>=0)
		//	mIClientKernelSink->OnGFWaitTips(true);

		CGameFrameEngine::Get()->OnGFTableMessage(sString.c_str());

		if((wType|~SMT_TABLE_ROLL)==0)
			return true;
	}
	//显示消息
	if (wType&SMT_CHAT)
	{	
		if (mIStringMessageSink!=0)
			mIStringMessageSink->InsertSystemString(sString.c_str());
	}
	
	//弹出消息
	if (wType&SMT_EJECT)
	{
		if (mIStringMessageSink != 0)
		{
			mIStringMessageSink->InsertPromptString(sString.c_str(), DLG_MB_OK);
		}
	}

	//关闭处理
	if (wType & SMT_CLOSE_GAME)
	{
		//中断连接
		Intermit(GameExitCode_Server_Notify_Close_Client);
		return true;
	}
	return true;

	////变量定义
	//CMD_CM_SystemMessage * pSystemMessage=(CMD_CM_SystemMessage *)data;
	//word wHeadSize=sizeof(CMD_CM_SystemMessage)-sizeof(pSystemMessage->szString);

	////效验参数
	//ASSERT((dataSize>wHeadSize)&&(dataSize==(wHeadSize+pSystemMessage->wLength*sizeof(tchar))));
	//if ((dataSize<=wHeadSize)||(dataSize!=(wHeadSize+pSystemMessage->wLength*sizeof(tchar)))) return false;

	////滚动消息
	//if((pSystemMessage->wType&SMT_TABLE_ROLL)!=0)
	//{
	//	tstring str = pSystemMessage->szString;
	//	if(str.find(T_T("系统配桌"))>=0)
	//		mIClientKernelSink->OnGFWaitTips(true);

	//	if (mIClientKernelSink)
	//		mIClientKernelSink->OnGFTableMessage(pSystemMessage->szString);

	//	if((pSystemMessage->wType|~SMT_TABLE_ROLL)==0)
	//		return true;
	//}
	//	
	////关闭处理
	//if ((pSystemMessage->wType&SMT_CLOSE_GAME)!=0)
	//{
	//	//中断连接
	//	Intermit(0);
	//}

	////显示消息
	//if (pSystemMessage->wType&SMT_CHAT)
	//{
	//	if (mIStringMessageSink!=0)
	//		mIStringMessageSink->InsertSystemString(pSystemMessage->szString);
	//}

	////弹出消息
	//if (pSystemMessage->wType&SMT_EJECT)
	//{
	//	if (mIStringMessageSink!=0)
	//		mIStringMessageSink->InsertPromptString(pSystemMessage->szString, DLG_MB_OK);
	//}

	////关闭房间
	//if (pSystemMessage->wType&SMT_CLOSE_GAME)
	//{
	//	Intermit(GameExitCode_Normal);
	//}

	//return true;
}

//动作消息
bool CGameClientKernel::OnSocketSubActionMessage(void* data, int dataSize)
{
	PLAZZ_PRINTF("flow->CGameClientKernel::OnSocketSubActionMessage\n");

	PACKET_AIDE_DATA(data);
	word wType = packet.read2Byte();
	word wLength = packet.read2Byte();
	uint nButtonType = packet.read2Byte();
	std::string sString = packet.readString(wLength);

	//关闭处理
	if ((wType&SMT_CLOSE_GAME)!=0)
	{
		//中断连接
		Intermit(GameExitCode_Normal);
	}

	return true;
	////变量定义
	//CMD_CM_ActionMessage * pActionMessage=(CMD_CM_ActionMessage *)data;
	//word wHeadSize=sizeof(CMD_CM_ActionMessage)-sizeof(pActionMessage->szString);

	////效验参数
	//ASSERT((dataSize>wHeadSize)&&(dataSize>=(wHeadSize+pActionMessage->wLength*sizeof(tchar))));
	//if ((dataSize<=wHeadSize)||(dataSize<(wHeadSize+pActionMessage->wLength*sizeof(tchar)))) return false;

	////关闭处理
	//if ((pActionMessage->wType&SMT_CLOSE_GAME)!=0)
	//{
	//	//中断连接
	//	IntermitConnect();
	//}

	////弹出消息
	//int nResultCode=ShowInformation(pActionMessage->szString,pActionMessage->nButtonType,0);

	////变量定义
	//word wExcursion=wHeadSize+pActionMessage->wLength*sizeof(tchar);

	////提取动作
	//while (wExcursion<dataSize)
	//{
	//	//变量定义
	//	tagActionHead * pActionHead=(tagActionHead *)((byte *)data+wExcursion);

	//	//效验参数
	//	ASSERT((wExcursion+sizeof(tagActionHead))<=dataSize);
	//	ASSERT((wExcursion+sizeof(tagActionHead)+pActionHead->wAppendSize)<=dataSize);

	//	//效验参数
	//	if ((wExcursion+sizeof(tagActionHead))>dataSize) return false;
	//	if ((wExcursion+sizeof(tagActionHead)+pActionHead->wAppendSize)>dataSize) return false;

	//	//动作出来
	//	if (nResultCode==pActionHead->uResponseID)
	//	{
	//		switch (pActionHead->cbActionType)
	//		{
	//		case ACT_BROWSE:	//浏览动作
	//			{
	//				//变量定义
	//				word wDataPos=wExcursion+sizeof(tagActionHead);
	//				tagActionBrowse * pActionBrowse=(tagActionBrowse *)((byte *)data+wDataPos);

	//				//I E 浏览
	//				if (pActionBrowse->cbBrowseType&BRT_IE)
	//				{
	//					ShellExecute(0,T_T("open"),pActionBrowse->szBrowseUrl,0,0,SW_NORMAL);
	//				}

	//				//大厅浏览
	//				if (pActionBrowse->cbBrowseType&BRT_PLAZA)
	//				{
	//					//						CPlatformFrame::GetInstance()->WebBrowse(pActionBrowse->szBrowseUrl,true,true);
	//				}

	//				break;
	//			}
	//		case ACT_DOWN_LOAD:	//下载动作
	//			{
	//				//变量定义
	//				word wDataPos=wExcursion+sizeof(tagActionHead);
	//				tagActionDownLoad * pActionDownLoad=(tagActionDownLoad *)((byte *)data+wDataPos);

	//				//I E 下载
	//				if (pActionDownLoad->cbDownLoadMode&DLT_IE)
	//				{
	//					ShellExecute(0,T_T("open"),pActionDownLoad->szDownLoadUrl,0,0,SW_NORMAL);
	//				}

	//				//下载模块
	//				if (pActionDownLoad->cbDownLoadMode&DLT_MODULE)
	//				{
	//					ShellExecute(0,T_T("open"),pActionDownLoad->szDownLoadUrl,0,0,SW_NORMAL);
	//				}

	//				break;
	//			}
	//		}
	//	}

	//	//增加偏移
	//	wExcursion+=(sizeof(tagActionHead)+pActionHead->wAppendSize);
	//}

	////关闭房间
	//if (pActionMessage->wType&SMT_CLOSE_GAME) m_pIClientKernelSink->CloseGameClient();

	//return true;
}

//////////////////////////////////////////////////////////////////////////
// 捕鱼前控交互
bool CGameClientKernel::onOperateStock(uint8_t operate_code_, int range_)
{
	IClientKernel * kernel = IClientKernel::get();

	if (kernel == 0)
		return false;

// 	Shlw::CMD_C_StockOperate st_op_;
// 	st_op_.operate_code = operate_code_;
// 	st_op_.range_index = range_;
// 
// 	kernel->SendSocketData(MDM_GF_GAME, SUB_C_STOCK_OPERATE, &st_op_, sizeof(Shlw::CMD_C_StockOperate));

	return true;
}

bool CGameClientKernel::onOperateRBL(uint8_t code_, uint8_t rbl_, dword game_id, uint64_t limit_score)
{
	IClientKernel * kernel = IClientKernel::get();

	if (kernel == 0)
		return false;

// 	Shlw::CMD_C_RBL_Control st_name_;
// 	st_name_.operate_code = code_;
// 	st_name_.game_id = game_id;
// 	st_name_.limit_score = limit_score;
// 	st_name_.operate_RBL = rbl_;
// 	kernel->SendSocketData(MDM_GF_GAME, SUB_C_RBL_CONTROL, &st_name_, sizeof(Shlw::CMD_C_RBL_Control));

	return true;
}

bool CGameClientKernel::onGiveFish(dword game_id_, uint8_t bird_type_[], int type_count_, int catch_count_, float catch_probability_)
{
	IClientKernel * kernel = IClientKernel::get();

	if (kernel == 0)
		return false;


// 	Shlw::CMD_C_GiveAway_Control st_give_;
// 	st_give_.game_id = game_id_;
// 
// 	memcpy(st_give_.bird_type, bird_type_, sizeof(uint8_t)*type_count_);
// 
// 	st_give_.type_count = type_count_;
// 	st_give_.catch_count = catch_count_;
// 	st_give_.catch_probability = catch_probability_;
// 	kernel->SendSocketData(MDM_GF_GAME, SUB_C_GIVEAWAY_CONTROL, &st_give_, sizeof(Shlw::CMD_C_GiveAway_Control));

	return true;
}

bool CGameClientKernel::onSetDifficulty(int difficulty_, dword game_id_, uint8_t operate_code_)
{
	IClientKernel * kernel = IClientKernel::get();

	if (kernel == 0)
		return false;

// 	Shlw::CMD_C_Difficulty st_diff_;
// 	st_diff_.difficulty = difficulty_;
// 	st_diff_.game_id = game_id_;
// 	st_diff_.operate_code = operate_code_;
// 	kernel->SendSocketData(MDM_GF_GAME, SUB_C_DIFFICULTY, &st_diff_, sizeof(Shlw::CMD_C_Difficulty));

	return true;
}
