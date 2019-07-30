#include "CServerItem.h"
#include "../game/IClientKernel.h"

IRoomFrameSink* IRoomFrameSink::getInterface()
{
	return (IRoomFrameSink*)IServerItem::get();
}

//////////////////////////////////////////////////////////////////////////
// 框架消息

/************************************************************************/
/* 游戏已准备好                                                         */
/************************************************************************/
void CServerItem::OnGFGameReady(bool bInited)
{    
	PLAZZ_PRINTF("CServerItem::OnGFGameReady\n");

	//变量定义
	WORD wTableID = mMeUserItem->GetTableID();
	WORD wChairID = mMeUserItem->GetChairID();
	
	mUserAttribute.wChairID = wChairID;
	mUserAttribute.wTableID = wTableID;
	//房间信息
	IClientKernel::get()->OnGFConfigServer(&mUserAttribute, &mServerAttribute);

	//配置完成
	if (!bInited)
	{
		IClientKernel::get()->OnGFConfigFinish();
	}

	IClientKernel::get()->SendGameOption();

	//发送用户
	if (wTableID!=INVALID_TABLE && wChairID!=INVALID_CHAIR)
	{
		//变量定义
		WORD wEnumIndex=0;
		
		//发送玩家
		while (true)
		{
			//获取用户
			IClientUserItem * pIClientUserItem=mUserManager->EnumUserItem(wEnumIndex++);
			if (pIClientUserItem==0) break;

			//发送判断
			if (pIClientUserItem->GetTableID()!=wTableID)		continue;
			if (pIClientUserItem->GetUserStatus()==US_LOOKON)	continue;

			//发送用户
			IClientKernel::get()->OnGFUserEnter(pIClientUserItem);
		};

		//旁观用户
		wEnumIndex=0;
		while (true)
		{
			//获取用户
			IClientUserItem * pIClientUserItem=mUserManager->EnumUserItem(wEnumIndex++);
			if (pIClientUserItem==0) break;

			//发送判断
			if (pIClientUserItem->GetTableID()!=wTableID)		continue;
			if (pIClientUserItem->GetUserStatus()!=US_LOOKON)	continue;

			//发送用户
			IClientKernel::get()->OnGFUserEnter(pIClientUserItem);
		};
	}

	mIsGameReady = true;
}

/************************************************************************/
/* 游戏关闭                                                             */
/************************************************************************/
void CServerItem::OnGFGameClose(int iExitCode)
{
	PLAZZ_PRINTF("CServerItem::OnGFGameClose\n");

	//效验状态
	if(mMeUserItem){

		// 变量定义
		WORD wTableID		= mMeUserItem->GetTableID();
		WORD wChairID		= mMeUserItem->GetChairID();
		BYTE cbUserStatus	= mMeUserItem->GetUserStatus();

		mUserAttribute.wChairID = INVALID_CHAIR;
		mUserAttribute.wTableID = INVALID_TABLE;

		//退出游戏
		if (wTableID != INVALID_TABLE)
		{
			SendStandUpPacket(wTableID,wChairID,TRUE);
		}
	}

	if (mSocketEngine)
	{
		mSocketEngine->disconnect();
	}

	if (mUserManager)
	{
		mUserManager->ResetUserItem();
	}

	mReqTableID = INVALID_TABLE;
	mReqChairID = INVALID_CHAIR;
	mFindTableID = INVALID_TABLE;
	mIsGameReady = false;
	mMeUserItem = 0;

	mUserAttribute.wChairID = INVALID_CHAIR;
	mUserAttribute.wTableID = INVALID_TABLE;
	mServiceStatus = ServiceStatus_NetworkDown;
	
	mTableViewFrame.SetTableStatus(false);

	if (IClientKernel::get())
	{
		IClientKernel::destory();
	}

	if (mIServerItemSink)
		mIServerItemSink->OnGameClose(iExitCode);
}

/************************************************************************/
/* 放作弊场通知玩家进入新的游戏                                           */
/************************************************************************/
void CServerItem::AvertGameEnter()
{
	mReqTableID		= INVALID_TABLE;
	mReqChairID		= INVALID_CHAIR;
	mFindTableID	= INVALID_TABLE;
	mIsGameReady	= false;
	
	if(mIServerItemSink)
		mIServerItemSink->AvertGameEnter();
}

//////////////////////////////////////////////////////////////////////////
// Socket消息

// 发送数据
bool CServerItem::GFSendData(int main, int sub, const char * data, int size)
{
	return SendSocketData(main, sub, data, size);
}