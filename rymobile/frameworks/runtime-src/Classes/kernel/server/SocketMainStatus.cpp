#include "CServerItem.h"
#include "tools/tools/PacketReadAide.h"
#include "tools/tools/PacketWriteAide.h"


/************************************************************************/
/* 状态信息                                                             */
/************************************************************************/
bool CServerItem::OnSocketMainStatus(int sub, char * data, int dataSize)
{
	switch (sub)
	{
		//桌子信息
		case SUB_GR_TABLE_INFO:		return OnSocketSubStatusTableInfo(data, dataSize);
		//桌子状态
		case SUB_GR_TABLE_STATUS:	return OnSocketSubStatusTableStatus(data, dataSize);
	}

	return false;
}

/************************************************************************/
/* 桌子信息                                                            */
/************************************************************************/
bool CServerItem::OnSocketSubStatusTableInfo(char * data, int dataSize)
{
	//变量定义
	PACKET_AIDE_DATA(data);
	WORD wTableCount = packet.read2Byte();

	for (WORD i = 0; i < wTableCount; i++)
	{
		BYTE cbTableLock	= packet.readByte();
		BYTE cbPlayStatus	= packet.readByte();
		dword lCellScore	= packet.read4Byte();

		mTableViewFrame.SetTableStatus(i,cbPlayStatus > 0,cbTableLock > 0);
	}

	return true;
}

/************************************************************************/
/* 桌子状态                                                             */
/************************************************************************/
bool CServerItem::OnSocketSubStatusTableStatus(char * data, int dataSize)
{
	PACKET_AIDE_DATA(data);
	WORD wTableID		= packet.read2Byte();
	BYTE cbTableLock	= packet.readByte();
	BYTE cbPlayStatus	= packet.readByte();
	//设置桌子
	mTableViewFrame.SetTableStatus(wTableID,cbPlayStatus > 0,cbTableLock > 0);

	//设置桌子
	if(cbPlayStatus && mMeUserItem &&
		mMeUserItem->GetTableID() == wTableID && 
		CServerRule::IsAllowAvertCheatMode(mServerAttribute.dwServerRule))
	{
		mTableViewFrame.SetTableStatus(false);
	}

	return true;
}