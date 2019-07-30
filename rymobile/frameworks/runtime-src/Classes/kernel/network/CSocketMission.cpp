#include <iostream>
#include "CSocketMission.h"
#include "CCLuaEngine.h"
#include "lua/LuaStackEx.h"
#include "tools/tools/PacketWriteAide.h"
#include "tools/tools/PacketReadAide.h"
USING_NS_CC;

/************************************************************************/
/* 构造函数                                                             */
/************************************************************************/

//CSocketMission * CSocketMission::ms_pkInstance = 0;

CSocketMission::CSocketMission()
{
	mSocketEngine = ISocketEngine::create();
	mSocketEngine->setTCPValidate(false);
	mSocketEngine->setSocketEngineSink(this);

	//setUrl(url, port);
}

/************************************************************************/
/* 析构函数                                                             */
/************************************************************************/
CSocketMission::~CSocketMission()
{
	mSocketEngine->setSocketEngineSink(0);
	ISocketEngine::destory(mSocketEngine);
	mSocketEngine = 0;
}

/************************************************************************/
/* 设置链接url                                                          */
/************************************************************************/
void CSocketMission::setUrl(const std::string & url, int port)
{
	mUrl = url;
	mPort = port;
}

/************************************************************************/
/* 开启服务器请求                                                        */
/************************************************************************/
void CSocketMission::start()
{
	if (isAlive())
	{
		onEventTCPSocketLink();
	}
	else
	{
		mSocketEngine->connect(mUrl.c_str(), mPort);
	}
}

/************************************************************************/
/* 停止服务器请求                                                        */
/************************************************************************/
void CSocketMission::stop()
{
	mSocketEngine->disconnect();
}

/************************************************************************/
/* 判断服务器的链接状态                                                  */
/************************************************************************/
bool CSocketMission::isAlive() const
{
	return mSocketEngine->isAlive();
}

/************************************************************************/
/* 发送网络消息                                                          */
/************************************************************************/
bool CSocketMission::send(int main, int sub)
{
	return send(main, sub, 0, 0);
}

/************************************************************************/
/* 发送网络消息                                                          */
/************************************************************************/
bool CSocketMission::send(int main, int sub, const cocos2d::Ref * data, int size)
{
	const PacketWriteAide * pWirteAide = (const PacketWriteAide *)data;
	return mSocketEngine->send(main, sub, pWirteAide->getBufferData(), size);
}

/************************************************************************/
/* 设置服务器链接成功lua回调                                             */
/************************************************************************/
void CSocketMission::setLinkSuccLuaCallBack(const std::string & strLinkSuccLuaCallBack)
{
	if (strLinkSuccLuaCallBack.length() > 0)
	{
		m_strLinkSuccLuaCallBack = strLinkSuccLuaCallBack;
	}
}

/************************************************************************/
/* 设置服务器链接关闭lua回调                                             */
/************************************************************************/
void CSocketMission::setLinkDownLuaCallBack(const std::string & strLinkDownLuaCallBack)
{
	if (strLinkDownLuaCallBack.length() > 0)
	{
		m_strLinkDownLuaCallBack = strLinkDownLuaCallBack;
	}
}

/************************************************************************/
/* 设置服务器链接错误lua回调                                              */
/************************************************************************/
void CSocketMission::setLinkErrorLuaCallBack(const std::string & strLinkErrorLuaCallBack)
{
	if (strLinkErrorLuaCallBack.length() > 0)
	{
		m_strLinkErrorLuaCallBack = strLinkErrorLuaCallBack;
	}
}

/************************************************************************/
/* 设置服务器数据返回lua回调                                              */
/************************************************************************/
void CSocketMission::setLinkDataLuaCallBack(const std::string & strLinkDataLuaCallBack)
{
	if (strLinkDataLuaCallBack.length() > 0)
	{
		m_strLinkDataLuaCallBack = strLinkDataLuaCallBack;
	}
}

/************************************************************************/
/* 服务器链接成功                                                        */
/************************************************************************/
void CSocketMission::onEventTCPSocketLink()
{
	LuaEngine * pEngine = LuaEngine::defaultEngine();
	if (pEngine && m_strLinkSuccLuaCallBack.length() > 0){

		LuaStackEx * luaStack = static_cast<LuaStackEx*>(pEngine->getLuaStack());
		luaStack->call_script_fun(m_strLinkSuccLuaCallBack);
	}
}

/************************************************************************/
/* 服务器链接关闭                                                        */
/************************************************************************/
void CSocketMission::onEventTCPSocketShut()
{
	LuaEngine * pEngine = LuaEngine::defaultEngine();
	if (pEngine && m_strLinkDownLuaCallBack.length() > 0){

		LuaStackEx * luaStack = static_cast<LuaStackEx*>(pEngine->getLuaStack());
		luaStack->call_script_fun(m_strLinkDownLuaCallBack);
	}
}

/************************************************************************/
/* 服务器链接失败                                                        */
/************************************************************************/
void CSocketMission::onEventTCPSocketError(int errorCode)
{
	LuaEngine * pEngine = LuaEngine::defaultEngine();
	if (pEngine && m_strLinkErrorLuaCallBack.length() > 0){

		LuaStackEx * luaStack = static_cast<LuaStackEx*>(pEngine->getLuaStack());
		luaStack->call_script_fun(m_strLinkErrorLuaCallBack, errorCode);
	}
}
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS )
#include "bugly/CrashReport.h"
#endif
/************************************************************************/
/* 服务器数据返回                                                        */
/************************************************************************/
bool CSocketMission::onEventTCPSocketRead(int main, int sub, char * data, int dataSize)
{
	LuaEngine * pEngine = LuaEngine::defaultEngine();
	if (pEngine && m_strLinkDataLuaCallBack.length() > 0)
	{
		LuaStackEx * luaStack = static_cast<LuaStackEx*>(pEngine->getLuaStack());

		cocos2d::log("callback = %s main = %d sub = %d", m_strLinkDataLuaCallBack.c_str(), main, sub);
		PACKET_AIDE_DATA(data);
		luaStack->call_script_fun(m_strLinkDataLuaCallBack, main, sub, (cocos2d::Ref *)&packet, dataSize);
	}

	return true;
}
