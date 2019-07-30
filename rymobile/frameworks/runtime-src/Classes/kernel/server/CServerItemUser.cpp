#include "CServerItem.h"

#include "../game/IClientKernel.h"

#include "tools/tools/PacketReadAide.h"
#include "tools/tools/PacketWriteAide.h"

USING_NS_CC;
//////////////////////////////////////////////////////////////////////////
//用户接口

/************************************************************************/
/* 自己位置                                                             */
/************************************************************************/
WORD CServerItem::GetMeChairID()
{
	if (mMeUserItem == 0) return INVALID_CHAIR;
	return mMeUserItem->GetChairID();
}

/************************************************************************/
/* 自己位置                                                             */
/************************************************************************/
IClientUserItem * CServerItem::GetMeUserItem()
{
	return mMeUserItem;
}

/************************************************************************/
/* 游戏用户                                                             */
/************************************************************************/
IClientUserItem * CServerItem::GetTableUserItem(WORD wChairID)
{
	return mUserManager->EnumUserItem(wChairID);
}

/************************************************************************/
/* 查找用户                                                             */
/************************************************************************/
IClientUserItem * CServerItem::SearchUserByUserID(dword dwUserID)
{
	return mUserManager->SearchUserByUserID(dwUserID);
}

/************************************************************************/
/* 查找用户                                                             */
/************************************************************************/
IClientUserItem * CServerItem::SearchUserByGameID(dword dwGameID)
{
	return mUserManager->SearchUserByGameID(dwGameID);
}

//查找用户
IClientUserItem * CServerItem::SearchUserByNickName(const char* szNickName)
{
	return mUserManager->SearchUserByNickName(szNickName);
}
///< 获取用户数
dword CServerItem::GetActiveUserCount()
{
	return mUserManager->GetActiveUserCount();
}

//获取对应桌子是否锁的状态
bool CServerItem::GetTableLockState(int tableId)
{
	return mTableViewFrame.GetLockerFlag(tableId);
}

//获取对应桌子的游戏状态
bool CServerItem::GetTableGameState(int tableId)
{
	return mTableViewFrame.GetPlayFlag(tableId);
}

//////////////////////////////////////////////////////////////////////////
// IUserManagerSink
//////////////////////////////////////////////////////////////////////////
void CServerItem::OnUserItemAcitve(IClientUserItem* pIClientUserItem)
{
	//判断自己
	if (mMeUserItem == 0)
	{
		mMeUserItem = pIClientUserItem;
	}

	//设置桌子
	BYTE cbUserStatus = pIClientUserItem->GetUserStatus();
	if ((cbUserStatus >= US_SIT) && (cbUserStatus != US_LOOKON))
	{
		WORD wTableID = pIClientUserItem->GetTableID();
		WORD wChairID = pIClientUserItem->GetChairID();
		mTableViewFrame.SetClientUserItem(wTableID,wChairID,pIClientUserItem);
	}

	//提示信息
	CParameterGlobal * pParameterGlobal = CParameterGlobal::shared();
	if (pParameterGlobal->m_bNotifyUserInOut && mServiceStatus == ServiceStatus_ServiceIng)
	{
		if (mIStringMessageSink)
			mIStringMessageSink->InsertUserEnter(pIClientUserItem->GetNickName());
	}

 	if (mIServerItemSink)
 		mIServerItemSink->OnGRUserEnter(pIClientUserItem);
}

/************************************************************************/
/*                                                                      */
/************************************************************************/
void CServerItem::OnUserItemDelete(IClientUserItem* pIClientUserItem)
{
	WORD wLastTableID	= pIClientUserItem->GetTableID();
	WORD wLastChairID	= pIClientUserItem->GetChairID();

	dword dwLeaveUserID = pIClientUserItem->GetUserID();

	tagUserInfo * pMeUserInfo = mMeUserItem->GetUserInfo();

	//变量定义
	ASSERT(CParameterGlobal::shared());
	// 离开处理
	CParameterGlobal * pParameterGlobal = CParameterGlobal::shared();
	if ( wLastTableID != INVALID_TABLE && wLastChairID != INVALID_CHAIR )
	{
		//获取用户
		IClientUserItem * pITableUserItem = mTableViewFrame.GetClientUserItem(wLastTableID,wLastChairID);
		if (pITableUserItem == pIClientUserItem) 
			mTableViewFrame.SetClientUserItem(wLastTableID,wLastChairID,0);

		//离开通知
		if (pIClientUserItem == mMeUserItem || wLastTableID == pMeUserInfo->wTableID)
		{
			tagUserStatus userStatus;
			userStatus.cbUserStatus	= US_NULL;
			userStatus.wTableID		= INVALID_TABLE;
			userStatus.wChairID		= INVALID_CHAIR;

			if (IClientKernel::get())
				IClientKernel::get()->OnGFUserStatus(pIClientUserItem->GetUserID(), userStatus);
		}
	}

	if (mIServerItemSink)
		mIServerItemSink->OnGRUserDelete(pIClientUserItem);

	// 提示信息
	if ( pParameterGlobal->m_bNotifyUserInOut && mServiceStatus == ServiceStatus_ServiceIng )
	{
		if (mIStringMessageSink)
			mIStringMessageSink->InsertUserLeave(pIClientUserItem->GetNickName());
	}

}

/************************************************************************/
/* 玩家的face                                                           */
/************************************************************************/
void CServerItem::OnUserFaceUpdate(IClientUserItem * pIClientUserItem)
{
	tagUserInfo * pUserInfo				= pIClientUserItem->GetUserInfo();
	tagCustomFaceInfo * pCustomFaceInfo	= pIClientUserItem->GetCustomFaceInfo();

	if (mIServerItemSink)
		mIServerItemSink->OnGRUserUpdate(pIClientUserItem);

	// 更新桌子
	if ( pUserInfo->wTableID != INVALID_TABLE && pUserInfo->cbUserStatus!=US_LOOKON )
	{
		mTableViewFrame.UpdateTableView(pUserInfo->wTableID);
	}

	// 更新游戏
	if (pUserInfo->wTableID != INVALID_TABLE && mMeUserItem->GetTableID() == pUserInfo->wTableID)
	{
		if (IClientKernel::get())
			IClientKernel::get()->OnGFUserCustomFace(pUserInfo->dwUserID,pUserInfo->dwCustomID,*pCustomFaceInfo);
	}
}


/************************************************************************/
/*玩家分数更新                                                          */
/************************************************************************/
void CServerItem::OnUserItemUpdate(IClientUserItem* pIClientUserItem, const tagUserScore& LastScore)
{
	//变量定义
	tagUserInfo * pUserInfo		= pIClientUserItem->GetUserInfo();
	tagUserInfo * pMeUserInfo	= mMeUserItem->GetUserInfo();

	//房间界面通知
	if (pIClientUserItem == mMeUserItem)
	{
		// 变量定义
		CGlobalUserInfo *	pGlobalUserInfo	= CGlobalUserInfo::GetInstance();
	

		// 设置变量
		pGlobalUserInfo->lUserScore += pIClientUserItem->GetUserScore() - LastScore.lScore;
		pGlobalUserInfo->lUserInsure += pIClientUserItem->GetUserInsure() - LastScore.lInsure;

		pGlobalUserInfo->lUserScore = pIClientUserItem->GetUserScore();
		pGlobalUserInfo->lUserIngot = LastScore.lIngot;
		pGlobalUserInfo->lHouseCard = LastScore.lHouseCard;
	}

	if (mIServerItemSink)
		mIServerItemSink->OnGRUserUpdate(pIClientUserItem);

	//游戏通知
	if (pMeUserInfo->wTableID != INVALID_TABLE && pUserInfo->wTableID == pMeUserInfo->wTableID )
	{
		tagUserScore UserScore;
		zeromemory(&UserScore,sizeof(UserScore));

		//设置变量
		UserScore.lScore		= pUserInfo->lScore;
		UserScore.lGrade		= pUserInfo->lGrade;
		UserScore.lInsure		= pUserInfo->lInsure;
		UserScore.lIngot		= pUserInfo->lIngot;
		UserScore.lHouseCard	= pUserInfo->lHouseCard;
		UserScore.dwWinCount	= pUserInfo->dwWinCount;
		UserScore.dwLostCount	= pUserInfo->dwLostCount;
		UserScore.dwDrawCount	= pUserInfo->dwDrawCount;
		UserScore.dwFleeCount	= pUserInfo->dwFleeCount;
//		UserScore.dwUserMedal	= pUserInfo->dwUserMedal;
		UserScore.dwExperience	= pUserInfo->dwExperience;
		UserScore.lLoveLiness	= pUserInfo->lLoveLiness;

		//发送数据
		if (IClientKernel::get())
			IClientKernel::get()->OnGFUserScore(pUserInfo->dwUserID,UserScore);

		// 暂时注释掉 by liuzhen 有可能把别的玩家的数据赋给了pGlobalUserData
		//CGlobalUserInfo * pGlobalUserInfo	= CGlobalUserInfo::GetInstance();
		//tagGlobalUserData * pGlobalUserData = pGlobalUserInfo->GetGlobalUserData();
		//pGlobalUserData->lUserScore = pUserInfo->lScore;	
	}
}

/************************************************************************/
/*玩家状态更新                                                          */
/************************************************************************/
void CServerItem::OnUserItemUpdate(IClientUserItem* pIClientUserItem, const tagUserStatus& LastStatus)
{
	tagUserInfo * pUserInfo		= pIClientUserItem->GetUserInfo();
	tagUserInfo * pMeUserInfo	= mMeUserItem->GetUserInfo();

	WORD wNowTableID	= pIClientUserItem->GetTableID(),		wLastTableID	= LastStatus.wTableID;
	WORD wNowChairID	= pIClientUserItem->GetChairID(),		wLastChairID	= LastStatus.wChairID;
	BYTE cbNowStatus	= pIClientUserItem->GetUserStatus(),	cbLastStatus	= LastStatus.cbUserStatus;
	
	if (mIServerItemSink)
	{
		mIServerItemSink->OnGRUserUpdate(pIClientUserItem);
	}
		
	// 桌子离开
	if ((wLastTableID != INVALID_TABLE) && ((wLastTableID != wNowTableID)||(wLastChairID != wNowChairID)))
	{
		IClientUserItem * pITableUserItem = mTableViewFrame.GetClientUserItem(wLastTableID,wLastChairID);
		if (NULL != pITableUserItem && pITableUserItem == pIClientUserItem) 
			mTableViewFrame.SetClientUserItem(wLastTableID,wLastChairID,NULL);
	}
	
	//分组启动游戏处理 
	if (IsDistributionTable() && US_WAITING == cbNowStatus)
	{
		ASSERT(wNowTableID == INVALID_TABLE);
		ASSERT(wNowChairID == INVALID_CHAIR);
		if (mMeUserItem == pIClientUserItem && 0 == IClientKernel::get())
		{
			if (!mIServerItemSink || !mIServerItemSink->StartGame())
			{
				SendStandUpPacket(wNowTableID, wNowChairID, FALSE);
			}
			return;
		}
	}

	//桌子加入
	if (wNowTableID != INVALID_TABLE && 
		cbNowStatus!=US_LOOKON &&
		(wNowTableID != wLastTableID || wNowChairID != wLastChairID) )
	{
		if( pUserInfo->dwUserID != pMeUserInfo->dwUserID && 
			cbNowStatus == US_SIT && 
			pMeUserInfo->wTableID == wNowTableID )
		{
			//厌恶玩家
			ASSERT(CParameterGlobal::shared()!=0);
			CParameterGlobal * pParameterGlobal = CParameterGlobal::shared();
			if (pParameterGlobal->m_bLimitDetest && pIClientUserItem->GetUserCompanion() == CP_DETEST)
			{
				PACKET_AIDE_SIZE();
				packet.write2Byte(wNowTableID);
				packet.write2Byte(wNowChairID);
				packet.write4Byte(pMeUserInfo->dwUserID);
				packet.write4Byte(pUserInfo->dwUserID);
				SendSocketData(MDM_GR_USER, SUB_GR_USER_REPULSE_SIT, packet.getBufferData(), packet.getPosition());
			}
		}
		mTableViewFrame.SetClientUserItem(wNowTableID,wNowChairID,pIClientUserItem);
	}
	
	//桌子状态
	if (mTableViewFrame.GetChairCount() < MAX_CHAIR &&
		wNowTableID != INVALID_TABLE &&
		wNowTableID == wLastTableID &&
		wNowChairID == wLastChairID )
	{
		mTableViewFrame.UpdateTableView(wNowTableID);
	}
	
	//离开通知
	if ( wLastTableID != INVALID_TABLE &&
		(wNowTableID != wLastTableID || wNowChairID != wLastChairID))
	{
		if ( pIClientUserItem == mMeUserItem || wLastTableID == pMeUserInfo->wTableID)
		{
			tagUserStatus UserStatus;
			UserStatus.wTableID = wNowTableID;
			UserStatus.wChairID = wNowChairID;
			UserStatus.cbUserStatus = cbNowStatus;

			if ( (mGameServer.wServerType & GAME_GENRE_EDUCATE) > 0  && pIClientUserItem == mMeUserItem)
			{
				OnGFGameClose(GameExitCode_Normal);
			}
			else
			{
				if (IClientKernel::get())
				{
					IClientKernel::get()->OnGFUserStatus(pUserInfo->dwUserID, UserStatus);
				}
			}
		}
		return;
	}
	
	//加入处理
	if ( wNowTableID != INVALID_TABLE &&
		(wNowTableID != wLastTableID || wNowChairID != wLastChairID) )
	{
		// 自己判断
		if (mMeUserItem == pIClientUserItem)
		{
			mReqTableID = INVALID_TABLE;
			mReqChairID = INVALID_CHAIR;
			if (IClientKernel::get()==0)
			{
				// 启动进程
				if (!mIServerItemSink || !mIServerItemSink->StartGame())
				{
					OnGFGameClose(GameExitCode_CreateFailed);
					return;
				}

			}
			else
			{
				if (CServerRule::IsAllowAvertCheatMode(mServerAttribute.dwServerRule))
				{
					IServerItem::get()->AvertGameEnter();
					return;
				}
				else if (IsDistributionTable())
				{
					IServerItem::get()->OnGFGameReady(IClientKernel::get() != NULL? true : false);
					return;
				}

				if (IServerItem::get())
				{
					IServerItem::get()->OnGFGameReady(IClientKernel::get() != NULL ? true : false);
				}
			}
		}
		
		// 游戏通知
		if (mMeUserItem != pIClientUserItem && pMeUserInfo->wTableID == wNowTableID)
		{
			if (IClientKernel::get())
				IClientKernel::get()->OnGFUserEnter(pIClientUserItem);
		}

		return;
	}
	
	//状态改变
	if (wNowTableID != INVALID_TABLE &&
		wNowTableID == wLastTableID &&
		pMeUserInfo->wTableID == wNowTableID)
	{
		//游戏通知
		tagUserStatus userStatus;
		userStatus.wTableID		= wNowTableID;
		userStatus.wChairID		= wNowChairID;
		userStatus.cbUserStatus	= cbNowStatus;

		if (IClientKernel::get())
			IClientKernel::get()->OnGFUserStatus(pUserInfo->dwUserID,userStatus);

		return;
	}
	
	return;
}

/************************************************************************/
/* 用户属性更新                                                         */
/************************************************************************/
void CServerItem::OnUserItemUpdate(IClientUserItem * pIClientUserItem, const tagUserAttrib & UserAttrib)
{
	if (mIServerItemSink)
		mIServerItemSink->OnGRUserUpdate(pIClientUserItem);

	//通知游戏
	WORD wMeTableID		= mMeUserItem->GetTableID();
	WORD wUserTableID	= pIClientUserItem->GetTableID();
	if (wMeTableID!=INVALID_TABLE && wMeTableID == wUserTableID)
	{
		//变量定义
		tagUserAttrib userAttrib;
		userAttrib.cbCompanion = pIClientUserItem->GetUserCompanion();

		if (IClientKernel::get())
			IClientKernel::get()->OnGFUserAttrib(pIClientUserItem->GetUserID(),userAttrib);
	}
}
