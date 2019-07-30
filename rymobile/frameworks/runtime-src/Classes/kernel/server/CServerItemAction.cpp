#include "CServerItem.h"
#include "tools/tools/Convert.h"
#include "tools/tools/StringData.h"

/************************************************************************/
/* 查找桌子                                                             */
/************************************************************************/
bool CServerItem::SearchGameTable(tagSearchTable * SearchTable)
{
	//变量定义
	WORD wNullCount	= 0;
	WORD wChairUser	= mTableViewFrame.GetChairCount();
	WORD wMeTableID	= mMeUserItem->GetTableID();

	//百人游戏
	if (CServerRule::IsAllowDynamicJoin(mServerAttribute.dwServerRule)==true)
	{
		if(mTableViewFrame.GetChairCount() >= MAX_CHAIR)
		{
			SearchTable->wResultTableID = 0;
			SearchTable->wResultChairID = MAX_CHAIR;
			return true;
		}
	}

	//搜索桌子
	for (word i = 0;i < mTableViewFrame.GetTableCount();i++)
	{
		//设置索引
		SearchTable->wResultTableID = (SearchTable->wStartTableID + i) % mTableViewFrame.GetTableCount();

		//搜索处理
		if (wMeTableID != SearchTable->wResultTableID)
		{
			//获取桌子
			ITableView * pITableView = mTableViewFrame.GetTableViewItem(SearchTable->wResultTableID);

			//搜索过虑
			if (pITableView->GetPlayFlag()==true) 
				continue;

			if (SearchTable->bFilterPass && pITableView->GetLockerFlag())
				continue;

			//寻找空位置
			wNullCount = pITableView->GetNullChairCount(SearchTable->wResultChairID);

			//判断数目
			if (wNullCount > 0)
			{
				//效验规则
				char strDescribe[256];
				if (EfficacyTableRule(SearchTable->wResultTableID, SearchTable->wResultChairID, false, strDescribe) == false)
				{
					continue;
				}

				//数目判断
				if (SearchTable->bOneNull && (wNullCount == 1))			return true;
				if (SearchTable->bTwoNull && (wNullCount == 2))			return true;
				if (SearchTable->bNotFull && (wNullCount < wChairUser))	return true;
				if (SearchTable->bAllNull && (wNullCount == wChairUser)) return true;
			}
		}
	}

	//设置数据
	SearchTable->wResultTableID = INVALID_TABLE;
	SearchTable->wResultChairID = INVALID_CHAIR;

	return false;
}

/************************************************************************/
/* 快速加入                                                             */
/************************************************************************/
bool CServerItem::PerformQuickSitDown()
{
	return SendSocketData(MDM_GR_USER, SUB_GR_USER_CHAIR_REQ);
} 

/************************************************************************/
/* 自动加入                                                             */
/************************************************************************/
bool CServerItem::PerformAutoJoin()
{
	if (!IsService())
	{
		if (mIStringMessageSink)
		{
			std::string strinfo = (SSTRING("net_service_is_not_in_runstate"));
			enServiceStatus status = GetServiceStatus();
			switch (status)
			{
			case 	ServiceStatus_Unknow:
				strinfo.append("_ServiceStatus_Unknow");
				break;
			case		ServiceStatus_Entering:
				strinfo.append("_ServiceStatus_Entering");
				break;
			case		ServiceStatus_Validate:
				strinfo.append("_ServiceStatus_Validate");
				break;
			case		ServiceStatus_RecvInfo:
				strinfo.append("_ServiceStatus_RecvInfo");
				break;
			case		ServiceStatus_ServiceIng:
				strinfo.append("_ServiceStatus_ServiceIng");
				break;
			case		ServiceStatus_NetworkDown:
				strinfo.append("_ServiceStatus_NetworkDown");
				break;
			default:
				strinfo.append("_default");

			}
			mIStringMessageSink->InsertSystemString(strinfo.c_str());
		}
		return false;
	}
	//变量定义
	tagSearchTable SearchTable;
	memset(&SearchTable, 0, sizeof(SearchTable));

	//搜索条件
	SearchTable.bNotFull = true;
	SearchTable.bOneNull = true;
	SearchTable.bTwoNull = (mTableViewFrame.GetChairCount()!=2);
	SearchTable.bAllNull = false;
	SearchTable.bFilterPass = true;
	
	//搜索结果
	SearchTable.wResultTableID	= INVALID_TABLE;
	SearchTable.wResultChairID	= INVALID_CHAIR;
	SearchTable.wStartTableID	=0;

	//重入判断
	WORD meTableID = mMeUserItem->GetTableID();
	WORD meChairID = mMeUserItem->GetChairID();
	if (meTableID == INVALID_TABLE && meChairID == INVALID_CHAIR)
	{
		//搜索桌子
		SearchGameTable(&SearchTable);
	}
	else
	{
		SearchTable.wResultTableID = meTableID;
		SearchTable.wResultChairID = meChairID;
	}
	mFindTableID = SearchTable.wResultTableID;

	//搜索桌子
	if (mFindTableID == INVALID_TABLE)
	{
		//搜索条件
		SearchTable.bAllNull	= true;
		SearchTable.bNotFull	= true;
		SearchTable.bOneNull	= true;
		SearchTable.bFilterPass	= true;
		SearchTable.bTwoNull=(mTableViewFrame.GetChairCount()!=2);

		//搜索结果
		SearchTable.wResultTableID	= INVALID_TABLE;
		SearchTable.wResultChairID	= INVALID_CHAIR;
		SearchTable.wStartTableID	= mFindTableID + 1;

		//搜索桌子
		SearchGameTable(&SearchTable);
		mFindTableID=SearchTable.wResultTableID;
	}

	//结果判断
	if (mFindTableID!=INVALID_TABLE)
	{
		//效验数据
		ASSERT(SearchTable.wResultTableID!=INVALID_TABLE);
		ASSERT(SearchTable.wResultChairID!=INVALID_CHAIR);

		//设置数据
		word wChairID=SearchTable.wResultChairID;
		mTableViewFrame.VisibleTable(mFindTableID);
		mTableViewFrame.FlashGameChair(mFindTableID,wChairID);

		//自动坐下
		CParameterGlobal * pParameterGlobal=CParameterGlobal::shared();
		if (pParameterGlobal->m_bAutoSitDown==true) 
			PerformSitDownAction(mFindTableID,wChairID,true);
	}
	else
	{
		// 提示消息
		if (mIStringMessageSink)
			mIStringMessageSink->InsertPromptString(SSTRING("perform_auto_join_failue_hint"), DLG_MB_OK);
	}

	return false;
}

/************************************************************************/
/* 执行旁观                                                             */
/************************************************************************/
bool CServerItem::PerformLookonAction(WORD wTableID, WORD wChairID)
{
	if (!IsService()){

		if (mIStringMessageSink)
			mIStringMessageSink->InsertSystemString(SSTRING("net_service_is_not_in_runstate"));
		return false;
	}

	//效验数据
	ASSERT(wTableID!=INVALID_TABLE);
	ASSERT(wChairID!=INVALID_CHAIR);

	//状态过滤
	if (mServiceStatus!=ServiceStatus_ServiceIng) return false;
	if ((mReqTableID==wTableID)&&(mReqChairID==wChairID)) return false;

	//自己状态
	if (mMeUserItem->GetUserStatus() >= US_PLAYING)
	{
		//提示消息
		if (mIStringMessageSink)
			mIStringMessageSink->InsertPromptString(SSTRING("perform_lookon_failure_you_are_in_game"), DLG_MB_OK);
		return false;
	}

	//权限判断
	if (CUserRight::CanLookon(mUserAttribute.dwUserRight)==false)
	{
		//提示消息
		if (mIStringMessageSink)
			mIStringMessageSink->InsertPromptString(SSTRING("perform_lookon_failure_have_no_right"), DLG_MB_OK);
		return false;
		return false;
	}

	//清理界面
	if ((mReqTableID != INVALID_TABLE) && 
		(mReqChairID != INVALID_CHAIR) &&
		(mReqChairID != MAX_CHAIR))
	{
		IClientUserItem * pIClientUserItem = mTableViewFrame.GetClientUserItem(mReqTableID,mReqChairID);
		if (pIClientUserItem == mMeUserItem) 
			mTableViewFrame.SetClientUserItem(mReqTableID,mReqChairID,0);
	}

	//设置变量
	mReqTableID		= wTableID;
	mReqChairID		= wChairID;
	mFindTableID	= INVALID_TABLE;

	//设置界面
	mTableViewFrame.VisibleTable(wTableID);

	//发送命令
	SendLookonPacket(wTableID,wChairID);

	return true;
}

/************************************************************************/
/* 执行起立                                                             */
/************************************************************************/
bool CServerItem::PerformStandUpAction(WORD wTableID, WORD wChairID)
{
	if (!IsService()){

		if (mIStringMessageSink)
		{
			std::string strinfo = (SSTRING("net_service_is_not_in_runstate"));
			enServiceStatus status = GetServiceStatus();
			switch (status)
			{
			case 	ServiceStatus_Unknow:
				strinfo.append("_ServiceStatus_Unknow");
				break;
			case		ServiceStatus_Entering:
				strinfo.append("_ServiceStatus_Entering");
				break;
			case		ServiceStatus_Validate:
				strinfo.append("_ServiceStatus_Validate");
				break;
			case		ServiceStatus_RecvInfo:
				strinfo.append("_ServiceStatus_RecvInfo");
				break;
			case		ServiceStatus_ServiceIng:
				strinfo.append("_ServiceStatus_ServiceIng");
				break;
			case		ServiceStatus_NetworkDown:
				strinfo.append("_ServiceStatus_NetworkDown");
				break;
			default:
				strinfo.append("_default");

			}

			mIStringMessageSink->InsertSystemString(strinfo.c_str());
		}
	
		return false;
	}
		

	//效验数据
	ASSERT(wTableID != INVALID_TABLE);
	ASSERT(wChairID != INVALID_CHAIR);

	if ((mReqTableID == wTableID) && (mReqChairID == wChairID))		
		return false;

	//自己状态
	if (mMeUserItem->GetUserStatus() >= US_PLAYING)
	{
		//提示消息
		if (mIStringMessageSink)
			mIStringMessageSink->InsertPromptString("perform_stand_up_failure_you_are_in_game", DLG_MB_OK);

		return false;
	}

	//设置变量
	mReqTableID		= INVALID_TABLE;
	mReqChairID		= INVALID_CHAIR;
	mFindTableID	= INVALID_TABLE;

	//设置界面
	mTableViewFrame.VisibleTable(wTableID);

	//发送命令
	SendStandUpPacket(wTableID,wChairID,FALSE);

	return true;
}

/************************************************************************/
/* 执行坐下                                                             */
/************************************************************************/
bool CServerItem::PerformSitDownAction(WORD wTableID, WORD wChairID, bool bEfficacyPass, const char * psw)
{
	if (!IsService()){

		if (mIStringMessageSink)
		{
			std::string strinfo = (SSTRING("net_service_is_not_in_runstate"));
			enServiceStatus status = GetServiceStatus();
			switch (status)
			{
			case 	ServiceStatus_Unknow:			
				strinfo.append("_ServiceStatus_Unknow");
				break;
			case		ServiceStatus_Entering:			
				strinfo.append("_ServiceStatus_Entering");
				break;
			case		ServiceStatus_Validate:			
				strinfo.append("_ServiceStatus_Validate");
				break;
			case		ServiceStatus_RecvInfo:			
				strinfo.append("_ServiceStatus_RecvInfo");
				break;
			case		ServiceStatus_ServiceIng:		
				strinfo.append("_ServiceStatus_ServiceIng");
				break;
			case		ServiceStatus_NetworkDown:		
				strinfo.append("_ServiceStatus_NetworkDown");
				break;
			default:
				strinfo.append("_default");

			}
			
			mIStringMessageSink->InsertSystemString(strinfo.c_str());
		}
		return false;
	}

	//状态过滤
	if ((mReqTableID != INVALID_TABLE) && (mReqTableID == wTableID)) return false;
	if ((mReqChairID != INVALID_CHAIR) && (mReqChairID == wChairID)) return false;

	//自己状态
	if (mMeUserItem->GetUserStatus() >= US_PLAYING)
	{
		//提示消息
		if (wTableID != mMeUserItem->GetTableID() && wChairID != mMeUserItem->GetChairID())
		{
			if (mIStringMessageSink)
				mIStringMessageSink->InsertPromptString(SSTRING("sit_down_err_in_game"), DLG_MB_OK);
			return false;
		}
	}

	//权限判断
	if (CUserRight::CanPlay(mUserAttribute.dwUserRight)==false)
	{
		//提示消息
		if (mIStringMessageSink)
			mIStringMessageSink->InsertPromptString(SSTRING("sit_down_err_no_right"), DLG_MB_OK);

		return false;
	}

	//桌子效验
	if ((wTableID != INVALID_TABLE)&&(wChairID != INVALID_CHAIR))
	{
		char strDescribe[256]={0};
		if ((wChairID != MAX_CHAIR) && (EfficacyTableRule(wTableID,wChairID,false,strDescribe)==false))
		{
			//提示消息
			if (mIStringMessageSink)
				mIStringMessageSink->InsertPromptString(strDescribe, DLG_MB_OK);

			return false;
		}
	}

	//密码判断
	char szPassword[LEN_PASSWORD] = {0};
	if ((mMeUserItem->GetMasterOrder()==0)&&(bEfficacyPass==true)&&(wTableID!=INVALID_TABLE)&&(wChairID!=INVALID_CHAIR)&&(wChairID!=MAX_CHAIR))
	{
		//变量定义
		bool bLocker=mTableViewFrame.GetLockerFlag(wTableID);

		memcpy(szPassword, psw, strlen(psw));
		
		// 输入桌子密码功能没有实现  add by liuzhen  2016/8/13
		if (mIStringMessageSink)
			mIStringMessageSink->InsertPromptString(SSTRING("sit_down_err_no_password"), DLG_MB_OK);

		return false;
	}

	//清理界面
	if ((mReqTableID!=INVALID_TABLE)&&(mReqChairID!=INVALID_CHAIR)&&(mReqChairID!=MAX_CHAIR))
	{
		IClientUserItem * pIClientUserItem = mTableViewFrame.GetClientUserItem(mReqTableID,mReqChairID);
		if (pIClientUserItem == mMeUserItem) 
			mTableViewFrame.SetClientUserItem(mReqTableID,mReqChairID,0);
	}

	//设置界面
	if ((wChairID != MAX_CHAIR) &&
		(wTableID != INVALID_TABLE) && 
		(wChairID != INVALID_CHAIR))
	{
		mTableViewFrame.VisibleTable(wTableID);
		if (!mTableViewFrame.GetClientUserItem(wTableID, wChairID))
		{
 			mTableViewFrame.SetClientUserItem(wTableID, wChairID, mMeUserItem);
		}
	}

	//设置变量
	mReqTableID=wTableID;
	mReqChairID=wChairID;
	mFindTableID=INVALID_TABLE;

	//发送命令
	SendSitDownPacket(wTableID,wChairID,szPassword);

	return true;
}

/************************************************************************/
/* 执行购买                                                             */
/************************************************************************/
bool CServerItem::PerformBuyProperty(byte cbRequestArea,const char* pszNickName, word wItemCount, word wPropertyIndex)
{
	if (!IsService())
		return false;

	return true;
}

//是否是分组房间
bool CServerItem::IsDistributionTable()
{
#if 0//xyt
	if (EQW_KINDID == mGameKind.wKindID ||
		FOUR_PERSON_KING == mGameKind.wKindID ||
		DOU_DIZHU == mGameKind.wKindID)
		{
		return true;
		}
		else
		{
		return false;
		}
#else
	return CServerRule::IsQueuingGame(mServerAttribute.dwServerRule);
#endif
}

