#include "CServerItem.h"
#include "tools/tools/Convert.h"
#include "CCLuaEngine.h"
#include "lua/LuaStackEx.h"
#include "tools/tools/PacketWriteAide.h"
#include "tools/tools/PacketReadAide.h"
//////////////////////////////////////////////////////////////////////////
// ISocketEngineSink
//////////////////////////////////////////////////////////////////////////


/************************************************************************/
/* 游戏服务器链接成功                                                   */
/************************************************************************/
void CServerItem::onEventTCPSocketLink()
{
	PLAZZ_PRINTF("CServerItem::onEventTCPSocketLink\n");
	SendLogonPacket();
}

/************************************************************************/
/* 游戏服务器链接中断                                                   */
/************************************************************************/
void CServerItem::onEventTCPSocketShut()
{
	PLAZZ_PRINTF("CServerItem::onEventTCPSocketShut\n");

	if (mServiceStatus != ServiceStatus_NetworkDown)
	{
		if (mIServerItemSink)
			mIServerItemSink->OnGFServerClose(a_u8("连接中断"));
	}
}

/************************************************************************/
/* 游戏服务器链接错误                                                   */
/************************************************************************/
void CServerItem::onEventTCPSocketError(int errorCode)
{
	PLAZZ_PRINTF("CServerItem::onEventTCPSocketError err:%d\n", errorCode);

	if (mIServerItemSink)
		mIServerItemSink->OnConnectServerError(errorCode);

}

/************************************************************************/
/* 读取来自服务器消息                                                   */
/************************************************************************/
bool CServerItem::onEventTCPSocketRead(int main, int sub, char* data, int dataSize)
{
	//是否已经处理过此消息
	bool bSuccess = false;
	switch (main)
	{
		//登录消息
	case MDM_GR_LOGON:
		bSuccess = OnSocketMainLogon(sub, data, dataSize);
		break;
		//配置信息
	case MDM_GR_CONFIG:
		bSuccess = OnSocketMainConfig(sub, data, dataSize);
		break;
		//用户信息
	case MDM_GR_USER:
    //case 8:
		bSuccess = OnSocketMainUser(sub, data, dataSize);
		break;
		//状态信息
	case MDM_GR_STATUS:
		bSuccess = OnSocketMainStatus(sub, data, dataSize);
		break;
		//银行消息
	case MDM_GR_INSURE:
		bSuccess = OnSocketMainInsure(sub, data, dataSize);
		break;
		//管理消息
    case MDM_GR_MANAGE:
        //case 123456:
		bSuccess = OnSocketMainManager(sub, data, dataSize);
		break;
		//系统命令
	case MDM_CM_SYSTEM:
		bSuccess = OnSocketMainSystem(sub, data, dataSize);
		break;
		//游戏消息
	case MDM_GF_GAME:
		//框架消息
	case MDM_GF_FRAME:
		bSuccess = OnSocketMainGameFrame(main, sub, data, dataSize);
		break;
		//比赛消息
	case MDM_GR_MATCH:
		bSuccess = OnSocketMainMatch(sub, data, dataSize);
		break;
		//私人场消息
	case MDM_GR_PRIVATE:
		bSuccess = OnSocketMainPrivate(sub, data, dataSize);
		break;
	}

	if (!bSuccess)
	{
		LuaEngine * pEngine = LuaEngine::defaultEngine();
		if (pEngine){

			LuaStackEx * luaStack = static_cast<LuaStackEx*>(pEngine->getLuaStack());

			PACKET_AIDE_DATA(data);
			bSuccess = luaStack->call_script_fun("serverItemEventSocket.onEventTCPSocketRead", main, sub, (cocos2d::Ref *)&packet, dataSize);
		}
	}
	if (!bSuccess)
	{
		cocos2d::log("CServerItem::onEventTCPSocketRead return false main = %d sub =%d datasize = %d", main, sub, dataSize);
	}
	return true;
}

//////////////////////////////////////////////////////////////////////////
