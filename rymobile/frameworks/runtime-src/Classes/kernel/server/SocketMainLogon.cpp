#include "CServerItem.h"
#include "tools/tools/StringData.h"
#include "tools/tools/PacketReadAide.h"
#include "tools/tools/PacketWriteAide.h"


//登录消息
bool CServerItem::OnSocketMainLogon(int sub, char * data, int dataSize)
{
	switch (sub)
	{
		//登录成功
		case SUB_GR_LOGON_SUCCESS:	return OnSocketSubLogonSuccess(data,dataSize);
		//登录失败
		case SUB_GR_LOGON_FAILURE:	return OnSocketSubLogonFailure(data,dataSize);
		//登录完成
		case SUB_GR_LOGON_FINISH:	return OnSocketSubLogonFinish(data,dataSize);
		//更新提示
		case SUB_GR_UPDATE_NOTIFY:	return OnSocketSubUpdateNotify(data,dataSize);
	}

	return false;
}

/************************************************************************/
/* 登录成功                                                             */
/************************************************************************/
bool CServerItem::OnSocketSubLogonSuccess(char * data, int dataSize)
{
	mIsQuickSitDown = false;

	PACKET_AIDE_DATA(data);

	//玩家属性
	mUserAttribute.dwUserRight		= packet.read4Byte();
	mUserAttribute.dwMasterRight	= packet.read4Byte();

	// 设置状态
	SetServiceStatus(ServiceStatus_RecvInfo);

	if (mIServerItemSink)
		mIServerItemSink->OnGRLogonSuccess();

	return true;
}

/************************************************************************/
/* 登录失败                                                             */
/************************************************************************/
bool CServerItem::OnSocketSubLogonFailure(char * data, int dataSize)
{
	//效验数据
	ASSERT(dataSize>=4);
	if (dataSize<4) return false;

	PACKET_AIDE_DATA(data);
	int lErrorCode = packet.read4Byte();
	int len=(dataSize-4)/2;
	std::string sString = packet.readString(len);

	PLAZZ_PRINTF(a_u8("OnSocketSubLogonFailure 登录失败:%s\n"), sString.c_str());

	//关闭连接
	IntermitConnect(true);

	if (mIServerItemSink)
		mIServerItemSink->OnGRLogonFailure(lErrorCode, sString);

	if (mIServerItemSink)
		mIServerItemSink->OnGFServerClose(sString);

	return true;
}

/************************************************************************/
/* 登录完成                                                             */
/************************************************************************/
bool CServerItem::OnSocketSubLogonFinish(char * data, int dataSize)
{
	//设置状态
	SetServiceStatus(ServiceStatus_ServiceIng);
		
	mUserAttribute.dwUserID=mMeUserItem->GetUserID();
	mUserAttribute.wChairID=INVALID_CHAIR;
	mUserAttribute.wTableID=INVALID_TABLE;

	//规则判断
	//if (CServerRule::IsForfendGameRule(mServerAttribute.dwServerRule)==false)
	//{
	//	//发送规则
	//	SendUserRulePacket();
	//}

	if (mIServerItemSink)
		mIServerItemSink->OnGRLogonFinish();

	return true;
}

/************************************************************************/
/* 更新提示                                                             */
/************************************************************************/
bool CServerItem::OnSocketSubUpdateNotify(char * data, int dataSize)
{
	if (mIServerItemSink)
		mIServerItemSink->OnGRUpdateNotify(1, SSTRING("System_Tips_5"));

	return true;	

	///< 手机端不接更新消息
	PACKET_AIDE_DATA(data);
	//升级标志
	byte cbMustUpdatePlaza = packet.readByte();
	byte cbMustUpdateClient = packet.readByte();
	byte cbAdviceUpdateClient = packet.readByte();

	//当前版本
	dword dwCurrentPlazaVersion = packet.read4Byte();
	dword dwCurrentFrameVersion = packet.read4Byte();
	dword dwCurrentClientVersion = packet.read4Byte();

	//大厅更新
	if (cbMustUpdatePlaza)
	{
		IntermitConnect(true);

		if (mIServerItemSink)
			mIServerItemSink->OnGRUpdateNotify(1, SSTRING("System_Tips_5"));
		return true;
	}

	//游戏更新
	if (cbMustUpdateClient)
	{
		IntermitConnect(true);

		if (mIServerItemSink)
			mIServerItemSink->OnGRUpdateNotify(1, SSTRING("System_Tips_6"));
		return true;
	}

	//构造提示
	if (cbAdviceUpdateClient != TRUE)
		return true;

	//构造提示
	char szDescribe[512]={0};
	sprintf(szDescribe, SSTRING("System_Tips_7"), mGameKind.szKindName);

	IntermitConnect(true);

	if (mIServerItemSink)
		mIServerItemSink->OnGRUpdateNotify(0, szDescribe);

	return true;
}

