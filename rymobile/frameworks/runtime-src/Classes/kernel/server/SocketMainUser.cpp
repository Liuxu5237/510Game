#include "CServerItem.h"
#include "tools/tools/StringData.h"
#include "tools/tools/PacketReadAide.h"
#include "tools/tools/PacketWriteAide.h"
#include "tools/tools/MTNotification.h"
#include "tools/StringUtility.h""
/*--------kyb-----modify-----------*/
//#include "platform/PFView/LoadScene/WaitingLayer.h"


/************************************************************************/
/* 用户处理                                                             */
/************************************************************************/
bool CServerItem::OnSocketMainUser(int sub, char * data, int dataSize)
{
	switch (sub)
	{
		//请求坐下失败
		case SUB_GR_REQUEST_FAILURE:
		{
			return OnSocketSubRequestFailure(data, dataSize);
		}
		//邀请玩家
		case SUB_GR_USER_INVITE:
		{
			return OnSocketSubUserInvite(data, dataSize);
		}
		//等待分配
		case SUB_GR_USER_WAIT_DISTRIBUTE:
		{
			return OnSocketSubWaitDistribute(data, dataSize);
		}
		//用户进入
		case SUB_GR_USER_ENTER:
		{
			return OnSocketSubUserEnter(data, dataSize);
		}
		//用户进入（完整）
		case SUB_GR_USER_ENTER_SIMPLE:
		{
			return OnSocketSubUserEnterSimple(data, dataSize);
		}
		//用户积分
		case SUB_GR_USER_SCORE:
		{
			return OnSocketSubUserScore(data, dataSize);
		}
		//用户状态
		case SUB_GR_USER_STATUS:
		{
			return OnSocketSubUserStatus(data, dataSize);
		}
		//用户聊天
		case SUB_GR_USER_CHAT:
		{
			return OnSocketSubUserChat(data, dataSize);
		}
		//用户表情
		case SUB_GR_USER_EXPRESSION:
		{
			return OnSocketSubExpression(data, dataSize);
		}
		//用户私聊
		case SUB_GR_WISPER_CHAT:
		{
			return OnSocketSubWisperUserChat(data, dataSize);
		}
		//私聊表情
		case SUB_GR_WISPER_EXPRESSION:
		{
			return OnSocketSubWisperExpression(data, dataSize);
		}
		//道具成功							 
		case SUB_GR_PROPERTY_SUCCESS:
		{
			return OnSocketSubPropertySuccess(data, dataSize);							
		}
		//道具失败
		case SUB_GR_PROPERTY_FAILURE:
		{
			return OnSocketSubPropertyFailure(data, dataSize);
		}
		//道具效应
		case SUB_GR_PROPERTY_EFFECT:
		{
			return OnSocketSubPropertyEffect(data, dataSize);
		}
		//礼物消息
		case SUB_GR_PROPERTY_MESSAGE:
		{
			return OnSocketSubPropertyMessage(data, dataSize);
		}
		//喇叭消息
		case SUB_GR_PROPERTY_TRUMPET:
		{
			return OnSocketSubPropertyTrumpet(data, dataSize);
		}
		//喜报消息
		case SUB_GR_GLAD_MESSAGE:
		{
			return OnSocketSubGladMessage(data, dataSize);
		}
	}
	return false;
}

/************************************************************************/
/* 桌子状态                                                             */
/************************************************************************/
bool CServerItem::OnSocketSubRequestFailure(char * data, int dataSize)
{
	PACKET_AIDE_DATA(data);
	int32 lErrorCode = packet.read4Byte();

	// delete by liuzhen have to add 2016.09.19
	//WaitingLayer::getInstance()->dismiss();

	// 这个里面有可能弹出两次提示  以后在测试的时候要注意 add by liuzhen
	//if(lErrorCode == 2)
	//{
	//	NewDialog::create(SSTRING("gold_noenough_sitdown"), NewDialog::NONEBUTTON);
	//}

	int len=(dataSize-4)/2;
	const std::string sString = packet.readString(len);

	// 变量定义
	IClientUserItem * pITableUserItem=0;
	WORD wMeTableID = mMeUserItem->GetTableID();
	WORD wMeChairID = mMeUserItem->GetChairID();

	// 界面还原
	if ((mReqTableID != INVALID_TABLE) &&
		(mReqChairID != INVALID_TABLE) &&
		(mReqChairID != MAX_CHAIR))
	{
		IClientUserItem * pITableUserItem = mTableViewFrame.GetClientUserItem(mReqTableID,mReqChairID);
		if (pITableUserItem == mMeUserItem) 
			mTableViewFrame.SetClientUserItem(mReqTableID,mReqChairID,0);
	}

	PLAZZ_PRINTF("OnSocketSubRequestFailure %d : %d\n error code = %d", mServiceStatus, ServiceStatus_ServiceIng,lErrorCode);

	//设置变量
	mReqTableID = INVALID_TABLE;
	mReqChairID = INVALID_CHAIR;
	if (mIsQuickSitDown)
	{
		mIsQuickSitDown = false;

		// 防作弊模式  这个地方没有理解 add by liuzhen 
		if (CServerRule::IsAllowQuickMode(mServerAttribute.dwServerRule))
		{
			IntermitConnect(true);

			if (mIServerItemSink)
				mIServerItemSink->OnGFServerClose(sString.c_str());
		}
		else
		{

		}
	}
	else 
	{
		//提示消息
		if (mIServerItemSink)
			mIServerItemSink->onGRRequestFailure(sString.c_str());
	}

	return true;
}

/************************************************************************/
/* 等待分配                                                           */
/************************************************************************/
bool CServerItem::OnSocketSubWaitDistribute(char *data, int dataSize)
{
	PACKET_AIDE_DATA(data);
	bool bFangzuobi = packet.readByte();//是否是防作弊场
	//更新桌面
	mTableViewFrame.SetTableStatus(true);
	//通知房间列表
	G_NOTIFY_D("ON_ROOM_WAIT_DISTRIBUTE", MTData::create((int)bFangzuobi));
	//通知游戏内部
	G_NOTIFY_D("ON_GAME_WAIT_DISTRIBUTE", MTData::create((int)bFangzuobi));

	return true;
}

/************************************************************************/
/* 邀请玩家  邀请功能没有实现后期需要对应 add by liuzhen                */
/************************************************************************/
bool CServerItem::OnSocketSubUserInvite(char * data, int dataSize)
{
	PACKET_AIDE_DATA(data);

	WORD	wTableID = packet.read2Byte();
	dword	dwUserID = packet.read4Byte();

	ASSERT(wTableID<mTableViewFrame.GetTableCount());
	if (mTableViewFrame.GetPlayFlag(wTableID)==true) 
		return true;

	//寻找用户
	IClientUserItem * pIUserItem=mUserManager->SearchUserByUserID(dwUserID);
	if (pIUserItem == 0)
	{
		return true;
	}
	if (pIUserItem->GetTableID() == INVALID_TABLE)
	{
		return true;
	}
	//变量定义
	ASSERT(CParameterGlobal::shared()!=0);
	CParameterGlobal * pParameterGlobal=CParameterGlobal::shared();

	//用户过虑
	if (pIUserItem->GetUserCompanion() == CP_DETEST)
		return true;

	if (pParameterGlobal->m_cbInviteMode == INVITE_MODE_NONE)														
		return true;

	if ((pParameterGlobal->m_cbInviteMode == INVITE_MODE_FRIEND) && 
		(pIUserItem->GetUserCompanion() != CP_FRIEND))	
		return true;

	// 提示消息
	char szMessage[256]={0};
	sprintf(szMessage, SSTRING("System_Tips_13"),pIUserItem->GetNickName(),wTableID+1);

	//提示消息
	if (mIServerItemSink)
	{
		//PLAZZ_PRINTF(SSTRING("System_Tips_14"));
	}

	return true;
}

//////////////////////////////////////////////////////////////////////////
//用户信息
#define READ_PACKET(szOut)														\
	int len = wDataSize / 2;														\
	std::string strIn = packet.readString(len);									\
strncpy(szOut, strIn.c_str(), countarray(szOut))

/************************************************************************/
/* 用户进入                                                             */
/************************************************************************/
bool CServerItem::OnSocketSubUserEnter(char * data, int dataSize)
{
	//变量定义
	tagUserInfo UserInfo;

	tagCustomFaceInfo CustomFaceInfo;
	zeromemory(&UserInfo, sizeof(UserInfo));
	zeromemory(&CustomFaceInfo,sizeof(CustomFaceInfo));

	//变量定义
	CGlobalUserInfo * pGlobalUserInfo =CGlobalUserInfo::GetInstance();
	

	PACKET_AIDE_DATA(data);
	
	{
		//tagUserInfoHead
		UserInfo.dwGameID		= packet.read4Byte();
		UserInfo.dwUserID		= packet.read4Byte();


		UserInfo.wFaceID		= packet.read2Byte();
		UserInfo.dwCustomID		= packet.read4Byte();

		//用户状态
		UserInfo.cbGender		= packet.readByte();
		UserInfo.cbMemberOrder	= packet.readByte();


		//用户属性
		UserInfo.wTableID		= packet.read2Byte();
		UserInfo.wChairID		= packet.read2Byte();
		UserInfo.cbUserStatus	= packet.readByte();


		//用户积分
		UserInfo.lScore			= packet.read8Byte();
		UserInfo.lIngot			= packet.read8Byte();
		packet.read8Byte();


		UserInfo.dwWinCount		= packet.read4Byte();
		UserInfo.dwLostCount	= packet.read4Byte();
		UserInfo.dwDrawCount	= packet.read4Byte();
		UserInfo.dwFleeCount	= packet.read4Byte();
		UserInfo.dwExperience	= packet.read4Byte();
		packet.read8Byte();
		packet.read4Byte();
		UserInfo.dwClientAddr = packet.read4Byte();

		//packet.readString(LEN_WEBCHAT_PROFILEURL);

		//扩展信息
		while (dataSize > packet.getPosition())
		{

			word wDataSize = packet.read2Byte();
			word wDataDescribe = packet.read2Byte();
			if (wDataDescribe == 0) 
				break;
			switch (wDataDescribe)
			{
				//用户昵称
				case DTP_GR_NICK_NAME:		
				{
					READ_PACKET(UserInfo.szNickName);
					break;
				}
				//用户社团
				case DTP_GR_GROUP_NAME:		
				{
					READ_PACKET(UserInfo.szGroupName);
					break;
				}
				//个性签名
				case DTP_GR_UNDER_WRITE:	
				{
					READ_PACKET(UserInfo.szUnderWrite);
					break;
				}
					//机器码
				case DTP_GR_MACHINE_ID:
				{
										  READ_PACKET(UserInfo.szMachineID);
										  break;
				}
					//微信头像
				case DTP_GR_PROFILEURL:
				{
					READ_PACKET(UserInfo.szProfileUrl);
					//去掉空格
					std::string tmp = UserInfo.szProfileUrl;
					utility::trim(tmp);
					int nSize = strlen(tmp.c_str());
					if (nSize > sizeof(UserInfo.szProfileUrl))
					{
						nSize = sizeof(UserInfo.szProfileUrl);
					}
					memset(UserInfo.szProfileUrl, 0, sizeof(UserInfo.szProfileUrl));
					memcpy(UserInfo.szProfileUrl, tmp.c_str(), nSize);
					break;
				}
				default:
				{
						   std::string str = "CServerItem::OnSocketSubUserEnter error wDataDescribe = ";
						   str += utility::toString(wDataDescribe);
						   //cocos2d::log(str.c_str());
						   ASSERT(FALSE);
				}
			}
		}
	}

	//变量定义
	bool bHideUserInfo = CServerRule::IsAllowAvertCheatMode(mServerAttribute.dwServerRule);
	bool bMySelfUserItem = pGlobalUserInfo->dwUserID == UserInfo.dwUserID;
	bool bMasterUserOrder = ((UserInfo.cbMasterOrder > 0) || ((mMeUserItem != 0) && (mMeUserItem->GetMasterOrder() > 0)));

	//隐藏信息
	if (!((bHideUserInfo == false) || (bMySelfUserItem == true)||(bMasterUserOrder == true)))
	{
		strncpy(UserInfo.szNickName, a_u8("游戏玩家"), countarray(UserInfo.szNickName));
	}

	//激活用户
	IClientUserItem * pIClientUserItem = mUserManager->SearchUserByUserID(UserInfo.dwUserID);
	if (pIClientUserItem == 0)
	{
		pIClientUserItem = mUserManager->ActiveUserItem(UserInfo, CustomFaceInfo);
	}
	else
	{
		memcpy(pIClientUserItem->GetUserInfo(), &UserInfo, sizeof(UserInfo));
		memcpy(pIClientUserItem->GetCustomFaceInfo(), &CustomFaceInfo, sizeof(CustomFaceInfo));
	}
	//人数更新
	CServerListData * pServerListData=CServerListData::shared();
	if (pServerListData)
		pServerListData->SetServerOnLineCount(mServerAttribute.wServerID,mUserManager->GetActiveUserCount());

	//变量定义
	ASSERT(CParameterGlobal::shared()!=0);
	CParameterGlobal * pParameterGlobal=CParameterGlobal::shared();

	//好友提示
	if (((bHideUserInfo==false)&&(bMySelfUserItem==false))||(bMasterUserOrder==true))
	{
		if( pParameterGlobal->m_bNotifyFriendCome && 
			pIClientUserItem->GetUserCompanion() == CP_FRIEND )
		{
			char szMessage[256] = {0};
			sprintf(szMessage, a_u8("您的好友 [%s] 进来了！"), pIClientUserItem->GetNickName());
			if (mIChatSink)
				mIChatSink->InsertSystemChat(szMessage);
		}
	}

	return true;
}
/************************************************************************/
/* 用户进入                                                             */
/************************************************************************/
bool CServerItem::OnSocketSubUserEnterSimple(char * data, int dataSize)
{
	//变量定义
	tagUserInfo UserInfo;

	tagCustomFaceInfo CustomFaceInfo;
	zeromemory(&UserInfo, sizeof(UserInfo));
	zeromemory(&CustomFaceInfo, sizeof(CustomFaceInfo));

	//变量定义
	CGlobalUserInfo * pGlobalUserInfo = CGlobalUserInfo::GetInstance();

	PACKET_AIDE_DATA(data);
	{
		//tagMobileUserInfoHead
		//用户属性
		UserInfo.dwGameID = packet.read4Byte();
		UserInfo.dwUserID = packet.read4Byte();
		//UserInfo.dwGroupID = packet.read4Byte();

		//头像信息
		UserInfo.wFaceID = packet.read2Byte();
		UserInfo.dwCustomID = packet.read4Byte();

		//用户属性
		UserInfo.cbGender = packet.readByte();
		UserInfo.cbMemberOrder = packet.readByte();

		//用户状态
		UserInfo.wTableID = packet.read2Byte();
		UserInfo.wChairID = packet.read2Byte();
		UserInfo.cbUserStatus = packet.readByte();

		//用户积分
		UserInfo.lScore = packet.read8Byte();
		UserInfo.lIngot = packet.read8Byte();
		UserInfo.lGrade = packet.read8Byte();
		//用户局数
		UserInfo.dwWinCount = packet.read4Byte();
		UserInfo.dwLostCount = packet.read4Byte();
		UserInfo.dwDrawCount = packet.read4Byte();
		UserInfo.dwFleeCount = packet.read4Byte();
		UserInfo.dwExperience = packet.read4Byte();

		//扩展信息
		while (dataSize > packet.getPosition())
		{
			WORD wDataSize = packet.read2Byte();
			WORD wDataDescribe = packet.read2Byte();

			if (wDataDescribe == 0)
				break;

			switch (wDataDescribe)
			{
				//用户昵称
			case DTP_GR_NICK_NAME:
			{
									 READ_PACKET(UserInfo.szNickName);
									 break;
			}
				//用户社团
			case DTP_GR_GROUP_NAME:
			{
									  READ_PACKET(UserInfo.szGroupName);
									  break;
			}
				//个性签名
			case DTP_GR_UNDER_WRITE:
			{
									   READ_PACKET(UserInfo.szUnderWrite);
									   break;
			}
				//微信头像
			case DTP_GR_PROFILEURL:
			{
									  READ_PACKET(UserInfo.szProfileUrl);
									  //去掉空格
									  //std::string tmp = "http://wx.qlogo.cn/mmopen/xIfL2Lk6z9wCaqojVYGVT0wZx1QNJeDJkibwaewPfyEKafib451KQAlRwrm6cib98jwuRAQDr4q72YvFJT7ydI5fUa78n6Y7YSN/0                                                                                                                                 ";
									  std::string tmp = UserInfo.szProfileUrl;
									  //cocos2d::log("DTP_GR_PROFILEURL %s size1 = %d", UserInfo.szProfileUrl,sizeof(UserInfo.szProfileUrl));
									  utility::trim(tmp);
									  //cocos2d::log("DTP_GR_PROFILEURL  size2 = %d",  strlen(tmp.c_str()));
									  //memcpy(UserInfo.szProfileUrl, tmp.c_str(), sizeof(UserInfo.szProfileUrl));
									  int nSize = strlen(tmp.c_str());
									  if (nSize > sizeof(UserInfo.szProfileUrl))
									  {
										  nSize = sizeof(UserInfo.szProfileUrl);
									  }
									  memset(UserInfo.szProfileUrl, 0, sizeof(UserInfo.szProfileUrl));
									  memcpy(UserInfo.szProfileUrl, tmp.c_str(), nSize);
									  break;
			}
			default:
			{
					   std::string str = "CServerItem::OnSocketSubUserEnter error wDataDescribe = ";
					   str += utility::toString(wDataDescribe);
					   //cocos2d::log(str.c_str());
					   ASSERT(FALSE);
			}
			}
		}
	}

	//变量定义
	bool bHideUserInfo = CServerRule::IsAllowAvertCheatMode(mServerAttribute.dwServerRule);
	bool bMySelfUserItem = pGlobalUserInfo->dwUserID == UserInfo.dwUserID;
	bool bMasterUserOrder = ((UserInfo.cbMasterOrder > 0) || ((mMeUserItem != 0) && (mMeUserItem->GetMasterOrder() > 0)));

	//隐藏信息
	if (!((bHideUserInfo == false) || (bMySelfUserItem == true) || (bMasterUserOrder == true)))
	{
		strncpy(UserInfo.szNickName, a_u8("游戏玩家"), countarray(UserInfo.szNickName));
	}

	//激活用户
	IClientUserItem * pIClientUserItem = mUserManager->SearchUserByUserID(UserInfo.dwUserID);
	if (pIClientUserItem == 0)
	{
		pIClientUserItem = mUserManager->ActiveUserItem(UserInfo, CustomFaceInfo);
	}
	else
	{
		memcpy(pIClientUserItem->GetUserInfo(), &UserInfo, sizeof(UserInfo));
		memcpy(pIClientUserItem->GetCustomFaceInfo(), &CustomFaceInfo, sizeof(CustomFaceInfo));
	}
	//人数更新
	CServerListData * pServerListData = CServerListData::shared();
	if (pServerListData)
		pServerListData->SetServerOnLineCount(mServerAttribute.wServerID, mUserManager->GetActiveUserCount());

	//变量定义
	ASSERT(CParameterGlobal::shared() != 0);
	CParameterGlobal * pParameterGlobal = CParameterGlobal::shared();

	//好友提示
	if (((bHideUserInfo == false) && (bMySelfUserItem == false)) || (bMasterUserOrder == true))
	{
		if (pParameterGlobal->m_bNotifyFriendCome &&
			pIClientUserItem->GetUserCompanion() == CP_FRIEND)
		{
			char szMessage[256] = { 0 };
			sprintf(szMessage, a_u8("您的好友 [%s] 进来了！"), pIClientUserItem->GetNickName());
			if (mIChatSink)
				mIChatSink->InsertSystemChat(szMessage);
		}
	}

	return true;
}

/************************************************************************/
/* 用户积分(网络层接收消息，然后通知玩家管理器保存数据)                 */
/************************************************************************/
bool CServerItem::OnSocketSubUserScore(char * data, int dataSize)
{
	tagUserScore UserScore;

	PACKET_AIDE_DATA(data);

	dword dwUserID			= packet.read4Byte();

	UserScore.lScore		= packet.read8Byte();
	UserScore.lGrade		= packet.read8Byte();
	UserScore.lInsure		= packet.read8Byte();
	UserScore.lIngot		= packet.read8Byte();
	UserScore.lHouseCard	= packet.read8Byte();
	UserScore.dwWinCount	= packet.read4Byte();
	UserScore.dwLostCount	= packet.read4Byte();
	UserScore.dwDrawCount	= packet.read4Byte();
	UserScore.dwFleeCount	= packet.read4Byte();
	
	UserScore.dwExperience	= packet.read4Byte();
	UserScore.lLoveLiness	= packet.read4Byte();

	//寻找用户
	IClientUserItem * pIClientUserItem = mUserManager->SearchUserByUserID(dwUserID);

	//用户判断
	//ASSERT(pIClientUserItem!=0);
	if (pIClientUserItem==0) 
		return true;

	//变量定义
	CGlobalUserInfo * pGlobalUserInfo	= CGlobalUserInfo::GetInstance();

	
	//变量定义
	bool bMySelfUserItem = pGlobalUserInfo->dwUserID == dwUserID;
	bool bAvertCheatMode	= CServerRule::IsAllowAvertCheatMode(mServerAttribute.dwServerRule);
	bool bMasterUserOrder	= (pIClientUserItem->GetMasterOrder() > 0 || mMeUserItem->GetMasterOrder() > 0);
	
	//更新用户
	if (!bAvertCheatMode || bMySelfUserItem || bMasterUserOrder)
	{
		mUserManager->UpdateUserItemScore(pIClientUserItem,&UserScore);
	}

	return true;
}

/************************************************************************/
/* 用户状态(网络层接收消息，然后通知玩家管理器保存数据)                 */
/************************************************************************/
bool CServerItem::OnSocketSubUserStatus(char * data, int dataSize)
{
	PACKET_AIDE_DATA(data);
	dword dwUserID			= packet.read4Byte();

	tagUserStatus UserStatus;
	UserStatus.wTableID		= packet.read2Byte();
	UserStatus.wChairID		= packet.read2Byte();
	UserStatus.cbUserStatus = packet.readByte();

	//寻找用户
	IClientUserItem * pIClientUserItem = mUserManager->SearchUserByUserID(dwUserID);
	//用户判断
	//ASSERT(pIClientUserItem!=0);
	if (pIClientUserItem == 0)
	{
		return true;
	}
	//设置状态
	if (UserStatus.cbUserStatus == US_NULL) 
	{
		//删除用户
		mUserManager->DeleteUserItem(pIClientUserItem);

		//人数更新
		CServerListData * pServerListData = CServerListData::shared();
		pServerListData->SetServerOnLineCount(mServerAttribute.wServerID,mUserManager->GetActiveUserCount());
	}
	else
	{
		// 更新用户
		mUserManager->UpdateUserItemStatus(pIClientUserItem,&UserStatus);
	}

	return true;
}

/************************************************************************/
/* 用户聊天                                                             */
/************************************************************************/
bool CServerItem::OnSocketSubUserChat(char * data, int dataSize)
{
	if (mIChatSink == 0)
		return true;

	PACKET_AIDE_DATA(data);
	WORD wChatLength		= packet.read2Byte();
	dword dwChatColor		= packet.read4Byte();
	dword dwSendUserID		= packet.read4Byte();
	dword dwTargetUserID	= packet.read4Byte();

	const std::string sString = packet.readString(wChatLength);

	dwChatColor = ((dwChatColor & 0xFF) << 16) | (dwChatColor >> 8);

	//获取用户
	IClientUserItem * pISendUserItem=mUserManager->SearchUserByUserID(dwSendUserID);
	if (pISendUserItem == 0)
	{
		return true;
	}
	//消息过虑
	if (pISendUserItem != mMeUserItem)
	{
		// 社团变量
		dword dwUserGroupID		= pISendUserItem->GetGroupID();
		dword dwMySelfGroupID	= mMeUserItem->GetGroupID();

		//社团判断
		bool bSameGroup = false;
		if ((dwMySelfGroupID != 0L) && (dwMySelfGroupID == dwUserGroupID)) 
			bSameGroup=true;

		//变量定义
		byte cbUserCompanion = pISendUserItem->GetUserCompanion();
		CParameterGlobal * pParameterGlobal = CParameterGlobal::shared();

		// 好友模式
		if ( (pParameterGlobal->m_cbMessageMode == MESSAGE_MODE_FRIEND) && 
			 (cbUserCompanion != CP_FRIEND) && 
			 (bSameGroup==false))
		{
			return true;
		}

		// 厌恶模式
		if ((pParameterGlobal->m_cbMessageMode == MESSAGE_MODE_DETEST) && 
			(cbUserCompanion == CP_DETEST) && 
			(bSameGroup==false) )
		{
			return true;
		}
	}

	//显示消息
	if (dwTargetUserID != 0L)
	{
		//获取用户
		IClientUserItem * pIRecvUserItem = mUserManager->SearchUserByUserID(dwTargetUserID);
		if (pIRecvUserItem == 0) return true;

		mIChatSink->InsertUserChat(
			pISendUserItem->GetNickName(),
			pIRecvUserItem->GetNickName(),
			sString.c_str(),
			dwChatColor);
	}
	else 
	{
		mIChatSink->InsertUserChat(pISendUserItem->GetNickName(), sString.c_str(), dwChatColor);
	}

	return true;
}

/************************************************************************/
/* 用户表情                                                             */
/************************************************************************/
bool CServerItem::OnSocketSubExpression(char * data, int dataSize)
{
	if (mIChatSink==0)
		return true;

	PACKET_AIDE_DATA(data);
	WORD wItemIndex			= packet.read2Byte();
	dword dwSendUserID		= packet.read4Byte();
	dword dwTargetUserID	= packet.read4Byte();

	//获取用户
	IClientUserItem * pISendUserItem = mUserManager->SearchUserByUserID(dwSendUserID);
	if (pISendUserItem==0) return true;

	//消息过虑
	if (pISendUserItem != mMeUserItem)
	{
		// 社团变量
		dword dwUserGroupID		= pISendUserItem->GetGroupID();
		dword dwMySelfGroupID	= mMeUserItem->GetGroupID();

		//社团判断
		bool bSameGroup = false;
		if ((dwMySelfGroupID != 0L) && (dwMySelfGroupID == dwUserGroupID)) 
			bSameGroup=true;

		//变量定义
		BYTE cbUserCompanion = pISendUserItem->GetUserCompanion();
		CParameterGlobal * pParameterGlobal = CParameterGlobal::shared();

		// 好友模式
		if ((pParameterGlobal->m_cbMessageMode == MESSAGE_MODE_FRIEND) && 
			(cbUserCompanion != CP_FRIEND) && 
			(bSameGroup==false))
		{
			return true;
		}

		// 厌恶模式
		if ((pParameterGlobal->m_cbMessageMode == MESSAGE_MODE_DETEST) && 
			(cbUserCompanion == CP_DETEST) &&
			(bSameGroup==false) )
		{
			return true;
		}
	}

	// 公聊消息
	if (dwTargetUserID==0L)
	{
		mIChatSink->InsertExpression(pISendUserItem->GetNickName(), wItemIndex);
		return true;
	}

	// 私聊消息
	if (dwTargetUserID!=0L)
	{
		//获取用户
		IClientUserItem * pIRecvUserItem=mUserManager->SearchUserByUserID(dwTargetUserID);
		if (pIRecvUserItem==0) return true;

		//显示消息
		mIChatSink->InsertExpression(pISendUserItem->GetNickName(),pIRecvUserItem->GetNickName(),wItemIndex);
	}

	return true;
}

/************************************************************************/
/* 用户私聊                                                             */
/************************************************************************/
bool CServerItem::OnSocketSubWisperUserChat(char * data, int dataSize)
{
	if (mIChatSink == 0)
		return true;

	PACKET_AIDE_DATA(data);
	WORD wChatLength		= packet.read2Byte();
	dword dwChatColor		= packet.read4Byte();
	dword dwSendUserID		= packet.read4Byte();
	dword dwTargetUserID	= packet.read4Byte();

	const std::string sString = packet.readString(wChatLength);

	dwChatColor = ((dwChatColor & 0xFF) << 16) | (dwChatColor >> 8);

	//获取用户
	IClientUserItem * pISendUserItem = mUserManager->SearchUserByUserID(dwSendUserID);
	if (pISendUserItem==0) return true;

	//接收用户
	IClientUserItem * pIRecvUserItem = mUserManager->SearchUserByUserID(dwTargetUserID);
	if (pIRecvUserItem==0) return true;

	//消息过虑
	if (pISendUserItem != mMeUserItem)
	{
		// 社团变量
		dword dwUserGroupID		= pISendUserItem->GetGroupID();
		dword dwMySelfGroupID	= mMeUserItem->GetGroupID();

		//社团判断
		bool bSameGroup = false;
		if ((dwMySelfGroupID != 0L) && (dwMySelfGroupID == dwUserGroupID)) 
			bSameGroup=true;

		//变量定义
		BYTE cbUserCompanion = pISendUserItem->GetUserCompanion();
		CParameterGlobal * pParameterGlobal = CParameterGlobal::shared();

		// 好友模式
		if ((pParameterGlobal->m_cbMessageMode == MESSAGE_MODE_FRIEND) && 
			(cbUserCompanion != CP_FRIEND) && 
			(bSameGroup==false))
		{
			return true;
		}

		// 厌恶模式
		if ((pParameterGlobal->m_cbMessageMode == MESSAGE_MODE_DETEST) && 
			(cbUserCompanion == CP_DETEST) && 
			(bSameGroup==false) )
		{
			return true;
		}

		//屏蔽用户
		if(cbUserCompanion == CP_SHIELD) 
			return true;
	}

	mIChatSink->InsertWhisperChat(pISendUserItem->GetNickName(), sString.c_str(), dwChatColor, pISendUserItem == mMeUserItem);
	return true;
}

/************************************************************************/
/* 私聊表情                                                             */
/************************************************************************/
bool CServerItem::OnSocketSubWisperExpression(char * data, int dataSize)
{
	if (mIChatSink==0)
		return true;
	PACKET_AIDE_DATA(data);
	WORD wItemIndex			= packet.read2Byte();
	dword dwSendUserID		= packet.read4Byte();
	dword dwTargetUserID	= packet.read4Byte();

	//获取用户
	IClientUserItem * pISendUserItem=mUserManager->SearchUserByUserID(dwSendUserID);
	if (pISendUserItem==0) return true;

	//接收用户
	IClientUserItem * pIRecvUserItem=mUserManager->SearchUserByUserID(dwTargetUserID);
	if (pIRecvUserItem==0) return true;

	// 消息过虑
	if (pISendUserItem != mMeUserItem)
	{
		// 社团变量
		dword dwUserGroupID		= pISendUserItem->GetGroupID();
		dword dwMySelfGroupID	= mMeUserItem->GetGroupID();

		//社团判断
		bool bSameGroup = false;
		if ((dwMySelfGroupID != 0L) && (dwMySelfGroupID == dwUserGroupID)) 
			bSameGroup=true;

		//变量定义
		BYTE cbUserCompanion = pISendUserItem->GetUserCompanion();
		CParameterGlobal * pParameterGlobal = CParameterGlobal::shared();

		// 好友模式
		if ((pParameterGlobal->m_cbMessageMode == MESSAGE_MODE_FRIEND) && 
			(cbUserCompanion != CP_FRIEND) && 
			(bSameGroup==false))
		{
			return true;
		}

		// 厌恶模式
		if ((pParameterGlobal->m_cbMessageMode == MESSAGE_MODE_DETEST) && 
			(cbUserCompanion == CP_DETEST) && 
			(bSameGroup==false) )
		{
			return true;
		}

		//屏蔽用户
		if(cbUserCompanion == CP_SHIELD) 
			return true;
	}

	mIChatSink->InsertExpression(pISendUserItem->GetNickName(), pIRecvUserItem->GetNickName(), wItemIndex);

	return true;
}

/************************************************************************/
/* 道具成功                                                             */
/************************************************************************/
bool CServerItem::OnSocketSubPropertySuccess(char * data, int dataSize)
{
	PACKET_AIDE_DATA(data);

	BYTE cbRequestArea		= packet.readByte();
	WORD wItemCount			= packet.read2Byte();
	WORD wPropertyIndex		= packet.read2Byte();
	dword dwSourceUserID	= packet.read4Byte();
	dword dwTargetUserID	= packet.read4Byte();

	// 获取用户
	IClientUserItem * pISendUserItem=mUserManager->SearchUserByUserID(dwSourceUserID);
	if (pISendUserItem == 0) return true;

	// 获取用户
	IClientUserItem * pTargetUserItem=mUserManager->SearchUserByUserID(dwTargetUserID);
	if (pTargetUserItem == 0) return true;

	//使用范围
	if(cbRequestArea == PT_ISSUE_AREA_GAME)
	{
		return true;
	}
	return true;
}

/************************************************************************/
/* 道具失败                                                             */
/************************************************************************/
bool CServerItem::OnSocketSubPropertyFailure(char * data, int dataSize)
{
	//变量定义
	PACKET_AIDE_DATA(data);
	WORD wRequestArea = packet.read2Byte();
	int lErrorCode = packet.read4Byte();

	int len = (dataSize-packet.getPosition())/2;
	const std::string sString = packet.readString(len);
	
	//使用范围
	if(wRequestArea==PT_ISSUE_AREA_GAME)
	{
		
		return true;
	}
	return true;
}

/************************************************************************/
/* 道具效应                                                             */
/************************************************************************/
bool CServerItem::OnSocketSubPropertyEffect(char * data, int dataSize)
{
	PACKET_AIDE_DATA(data);
	dword dwUserID = packet.read4Byte();
	byte cbMemberOrder = packet.readByte();

	//查找用户
	IClientUserItem * pISendUserItem=mUserManager->SearchUserByUserID(dwUserID);
	if(pISendUserItem==0) return true;

	//设置变量
	tagUserInfo * pUserInfo = pISendUserItem->GetUserInfo();
	pUserInfo->cbMemberOrder=cbMemberOrder;

	////更新信息
	//m_UserListControl.UpdateDataItem(pISendUserItem);

	return true;
}

/************************************************************************/
/* 道具消息                                                             */
/************************************************************************/
bool CServerItem::OnSocketSubPropertyMessage(char * data, int dataSize)
{
	return true;
}

/************************************************************************/
/* 道具喇叭                                                             */
/************************************************************************/
bool CServerItem::OnSocketSubPropertyTrumpet(char* data, int dataSize)
{
	return true;
}

/************************************************************************/
/* 喜报消息                                                             */
/************************************************************************/
bool CServerItem::OnSocketSubGladMessage(char * data, int dataSize)
{
	PACKET_AIDE_DATA(data);

	std::string sContent	= packet.readString(128);
	std::string sNickName	= packet.readString(32);
	std::string sNum		= packet.readString(16);

	dword colText = COL_N2G(packet.read4Byte());
	dword colName = COL_N2G(packet.read4Byte());
	dword colNum  = COL_N2G(packet.read4Byte());
	
	if (mIStringMessageSink)
		mIStringMessageSink->InsertGladString(sContent.c_str(), sNickName.c_str(), sNum.c_str(), colText, colName, colNum);

	return true;
}
