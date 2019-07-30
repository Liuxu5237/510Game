#include "CClientKernel.h"
#include "CGameFrameEngine.h"
//用户进入
void CGameClientKernel::OnGFUserEnter(IClientUserItem* pIClientUserItem)
{
	PLAZZ_PRINTF("flow->CGameClientKernel::OnGFUserEnter\n");

	//用户判断
	ASSERT(pIClientUserItem!=0);
	if (pIClientUserItem==0) return;

	ASSERT(mUserManager!=0);
	if (mUserManager)
		mUserManager->ActiveUserItem(
		*pIClientUserItem->GetUserInfo(),
		*pIClientUserItem->GetCustomFaceInfo(),
		pIClientUserItem->GetUserCompanion(),
		pIClientUserItem->GetUserNoteInfo());
}

//用户积分
void CGameClientKernel::OnGFUserScore(dword dwUserID, const tagUserScore& UserScore)
{
	PLAZZ_PRINTF("flow->CGameClientKernel::OnGFUserScore\n");

	//寻找用户
	IClientUserItem * pIClientUserItem=mUserManager->SearchUserByUserID(dwUserID);

	//用户判断
	ASSERT(pIClientUserItem!=0);
	if (pIClientUserItem==0) return;

	ASSERT(mUserManager!=0);
	if (mUserManager)
		mUserManager->UpdateUserItemScore(pIClientUserItem,&UserScore);
}

//用户状态
void CGameClientKernel::OnGFUserStatus(dword dwUserID, const tagUserStatus& UserStatus)
{
	PLAZZ_PRINTF("flow->CGameClientKernel::OnGFUserStatus\n---%d", dwUserID );

	IClientUserItem* pIClientUserItem = mUserManager->SearchUserByUserID(dwUserID);

	//用户判断
	//ASSERT(pIClientUserItem!=0);
	if (pIClientUserItem==0) return;

	//状态定义
	BYTE cbUserStatus=UserStatus.cbUserStatus;

	//离开判断
	if ((cbUserStatus == US_NULL) || (cbUserStatus == US_FREE))
	{
		if (mMeClientUserItem == pIClientUserItem)
		{
			//设置变量
			mAllowLookon=false;
			mMeClientUserItem=0;
			mGameStatus=GAME_STATUS_FREE;
			zeromemory(&mUserAttribute,sizeof(mUserAttribute));

			//重置游戏
			CGameFrameEngine::Get()->ResetGameClient();

			//删除用户
			mUserManager->ResetUserItem();
		}
		else
		{
			//删除用户
			mUserManager->DeleteUserItem(pIClientUserItem);
		}

		return;
	}

	ASSERT(mUserManager!=0);
	if (mUserManager)
		mUserManager->UpdateUserItemStatus(pIClientUserItem, &UserStatus);
}

//用户属性
void CGameClientKernel::OnGFUserAttrib(dword dwUserID, const tagUserAttrib& UserAttrib)
{
	PLAZZ_PRINTF("flow->CGameClientKernel::OnGFUserAttrib\n");

	//寻找用户
	IClientUserItem * pIClientUserItem=mUserManager->SearchUserByUserID(dwUserID);

	//用户判断
	ASSERT(pIClientUserItem!=0);
	if (pIClientUserItem==0) return ;

	ASSERT(mUserManager!=0);
	if (mUserManager)
		mUserManager->UpdateUserItemAttrib(pIClientUserItem,&UserAttrib);
}

//用户自定义头像
void CGameClientKernel::OnGFUserCustomFace(dword dwUserID, dword dwCustomID, const tagCustomFaceInfo& CustomFaceInfo)
{
	PLAZZ_PRINTF("flow->CGameClientKernel::OnGFUserCustomFace\n");

	//寻找用户
	IClientUserItem * pIClientUserItem=mUserManager->SearchUserByUserID(dwUserID);

	//用户判断
	ASSERT(pIClientUserItem!=0);
	if (pIClientUserItem==0) return;

	ASSERT(mUserManager!=0);
	if (mUserManager)
		mUserManager->UpdateUserCustomFace(pIClientUserItem,dwCustomID,CustomFaceInfo);
}
