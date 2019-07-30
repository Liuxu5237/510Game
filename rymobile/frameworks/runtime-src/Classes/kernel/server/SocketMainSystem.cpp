#include "CServerItem.h"
#include "tools/tools/PacketReadAide.h"
#include "tools/tools/PacketWriteAide.h"
#include "../game/IClientKernel.h"
#include "tools/tools/MTNotification.h"
#include "platform/df/GameEventIDDefine.h"
//系统消息
bool CServerItem::OnSocketMainSystem(int sub, char * data, int dataSize)
{
	switch (sub)
	{
		//系统消息
		case SUB_CM_SYSTEM_MESSAGE:	return OnSocketSubSystemMessage(data,dataSize);
		//动作消息
		case SUB_CM_ACTION_MESSAGE:	return OnSocketSubActionMessage(data,dataSize);
	}

	//错误断言
	ASSERT(FALSE);

	return false;
}

/************************************************************************/
/* 系统消息                                                             */
/************************************************************************/
bool CServerItem::OnSocketSubSystemMessage(char * data, int dataSize)
{
	PACKET_AIDE_DATA(data);
	WORD wType		= packet.read2Byte();
	WORD wLength	= packet.read2Byte();

	int len=(dataSize-4)/2;
	const std::string sString = packet.readString(len);

	bool isQuickMode = CServerRule::IsAllowQuickMode(mServerAttribute.dwServerRule);

	if (IClientKernel::get())
	{
		G_NOTIFY_D("game_event", MTData::create(GAME_EVENT_ID_SUB_SYSTEM_MSG, wType, isQuickMode ? 1 : 0, sString, "", "", NULL));
	}
	else
	{
		if (wType & (SMT_CLOSE_ROOM | SMT_CLOSE_LINK | SMT_CLOSE_GAME))
		{
			IntermitConnect(true);
		}

		if (wType & SMT_CHAT)
		{
			if (mIChatSink)
				mIChatSink->InsertSystemChat(sString.c_str());
		}

		// 弹出消息
		if (wType & SMT_EJECT)
		{
			if (mIStringMessageSink)
				mIStringMessageSink->InsertPromptString(sString.c_str(), DLG_MB_OK);
		}
	}
	//// 关闭房间 中断连接 关闭游戏
	//if (wType & (SMT_CLOSE_ROOM | SMT_CLOSE_LINK | SMT_CLOSE_GAME))
	//{
	//	if (IClientKernel::get())
	//		IClientKernel::get()->Intermit(GameExitCode_Client_Active);

	//	// 关闭房间 中断连接
	//	if (wType & (SMT_CLOSE_ROOM | SMT_CLOSE_LINK))
	//	{
	//		IntermitConnect(true);
	//	}

	//	// 显示消息
	//	if (wType & SMT_CHAT)
	//	{
	//		if (mIChatSink)
	//			mIChatSink->InsertSystemChat(sString.c_str());
	//	}

	//	// 弹出消息
	//	if (wType & SMT_EJECT)
	//	{
	//		if (mIStringMessageSink)
	//			mIStringMessageSink->InsertPromptString(sString.c_str(), DLG_MB_OK);
	//	}

	//	//关闭处理 时间延迟
	//	if ((wType & (SMT_CLOSE_ROOM | SMT_CLOSE_LINK)) != 0)
	//	{
	//		if (mIServerItemSink)
	//			mIServerItemSink->OnGFServerClose(sString);
	//	}
	//	else if (wType&SMT_CLOSE_GAME)
	//	{
	//		//只是关闭游戏时判断是否快速模式
	//		if (CServerRule::IsAllowQuickMode(mServerAttribute.dwServerRule))
	//		{
	//			//时间延迟
	//			IntermitConnect(true);
	//			if (mIServerItemSink)
	//				mIServerItemSink->OnGFServerClose(sString);
	//		}
	//	}
	//}
	//else
	//{
	//	// 显示消息
	//	if (wType & SMT_CHAT)
	//	{
	//		if (mIChatSink)
	//			mIChatSink->InsertSystemChat(sString.c_str());
	//	}

	//	// 弹出消息
	//	if (wType & SMT_EJECT)
	//	{
	//		if (mIStringMessageSink)
	//			mIStringMessageSink->InsertPromptString(sString.c_str(), DLG_MB_OK);
	//	}
	//}

	return true;
}

/************************************************************************/
/* 动作消息                                                             */
/************************************************************************/
bool CServerItem::OnSocketSubActionMessage(char * data, int dataSize)
{
	PACKET_AIDE_DATA(data);
	WORD wType			= packet.read2Byte();
	WORD wLength		= packet.read2Byte();
	uint16 nButtonType	= packet.read2Byte();

	const std::string sString = packet.readString(wLength);

	// 关闭处理
	if ((wType&(SMT_CLOSE_ROOM|SMT_CLOSE_LINK))!=0)
	{
		IntermitConnect(true);
	}

	return true;
}
