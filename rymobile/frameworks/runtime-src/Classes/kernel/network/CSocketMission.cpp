#include <iostream>
#include "CSocketMission.h"
#include "CCLuaEngine.h"
#include "lua/LuaStackEx.h"
#include "tools/tools/PacketWriteAide.h"
#include "tools/tools/PacketReadAide.h"
USING_NS_CC;

/************************************************************************/
/* ���캯��                                                             */
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
/* ��������                                                             */
/************************************************************************/
CSocketMission::~CSocketMission()
{
	mSocketEngine->setSocketEngineSink(0);
	ISocketEngine::destory(mSocketEngine);
	mSocketEngine = 0;
}

/************************************************************************/
/* ��������url                                                          */
/************************************************************************/
void CSocketMission::setUrl(const std::string & url, int port)
{
	mUrl = url;
	mPort = port;
}

/************************************************************************/
/* ��������������                                                        */
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
/* ֹͣ����������                                                        */
/************************************************************************/
void CSocketMission::stop()
{
	mSocketEngine->disconnect();
}

/************************************************************************/
/* �жϷ�����������״̬                                                  */
/************************************************************************/
bool CSocketMission::isAlive() const
{
	return mSocketEngine->isAlive();
}

/************************************************************************/
/* ����������Ϣ                                                          */
/************************************************************************/
bool CSocketMission::send(int main, int sub)
{
	return send(main, sub, 0, 0);
}

/************************************************************************/
/* ����������Ϣ                                                          */
/************************************************************************/
bool CSocketMission::send(int main, int sub, const cocos2d::Ref * data, int size)
{
	const PacketWriteAide * pWirteAide = (const PacketWriteAide *)data;
	return mSocketEngine->send(main, sub, pWirteAide->getBufferData(), size);
}

/************************************************************************/
/* ���÷��������ӳɹ�lua�ص�                                             */
/************************************************************************/
void CSocketMission::setLinkSuccLuaCallBack(const std::string & strLinkSuccLuaCallBack)
{
	if (strLinkSuccLuaCallBack.length() > 0)
	{
		m_strLinkSuccLuaCallBack = strLinkSuccLuaCallBack;
	}
}

/************************************************************************/
/* ���÷��������ӹر�lua�ص�                                             */
/************************************************************************/
void CSocketMission::setLinkDownLuaCallBack(const std::string & strLinkDownLuaCallBack)
{
	if (strLinkDownLuaCallBack.length() > 0)
	{
		m_strLinkDownLuaCallBack = strLinkDownLuaCallBack;
	}
}

/************************************************************************/
/* ���÷��������Ӵ���lua�ص�                                              */
/************************************************************************/
void CSocketMission::setLinkErrorLuaCallBack(const std::string & strLinkErrorLuaCallBack)
{
	if (strLinkErrorLuaCallBack.length() > 0)
	{
		m_strLinkErrorLuaCallBack = strLinkErrorLuaCallBack;
	}
}

/************************************************************************/
/* ���÷��������ݷ���lua�ص�                                              */
/************************************************************************/
void CSocketMission::setLinkDataLuaCallBack(const std::string & strLinkDataLuaCallBack)
{
	if (strLinkDataLuaCallBack.length() > 0)
	{
		m_strLinkDataLuaCallBack = strLinkDataLuaCallBack;
	}
}

/************************************************************************/
/* ���������ӳɹ�                                                        */
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
/* ���������ӹر�                                                        */
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
/* ����������ʧ��                                                        */
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
/* ���������ݷ���                                                        */
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
