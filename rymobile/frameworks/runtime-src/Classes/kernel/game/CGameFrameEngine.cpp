#include "CGameFrameEngine.h"

#include "IClientKernel.h"
#include "CGameScene.h"
#include "IGameFrameEngineSink.h"

#include "CCLuaEngine.h"
#include "lua/LuaStackEx.h"

#include "tools/tools/MTNotification.h"
#include "tools/tools/MyConfigureData.h"
#include "tools/tools/PacketReadAide.h"

CGameFrameEngine * CGameFrameEngine::ms_pkInstance = NULL;

/************************************************************************/
/* ���캯��                                                             */
/************************************************************************/
CGameFrameEngine::CGameFrameEngine()
{
	m_gameScene = NULL;
	m_gameFrameEngineSink = NULL;
    CCLOG("--1-- CGameFrameEngine()=%p",this);
}


/************************************************************************/
/* ��������                                                             */
/************************************************************************/
CGameFrameEngine::~CGameFrameEngine()
{
	if (m_gameFrameEngineSink)
	{
		delete m_gameFrameEngineSink;
		m_gameFrameEngineSink = NULL;
	}
}

/************************************************************************/
/* �������                                                              */
/************************************************************************/
void CGameFrameEngine::Clear()
{
	//������õ�����ΪNULL,�ڴ��й¶����Ϊĳ��������Ϸ��sink����lua���ɵģ�����lua�ǿ�������
	m_gameFrameEngineSink = NULL;
}

/************************************************************************/
/* ������Ϸ                                                             */
/************************************************************************/
bool CGameFrameEngine::SetupGameClient()
{
	Director * director = Director::getInstance();
	Scene * pScene = director->getRunningScene();
	//if (pScene->getTag() == DF::shared()->GetGameKindID() && pScene->getName() == "GameScene")
	//{
	//	this->m_gameScene = dynamic_cast<CGameScene *>(pScene);
	//}
	//else
	{
		if (!m_gameScene){

			m_gameScene = new CGameScene();
			m_gameScene->autorelease();
			if (m_gameScene != NULL)
			{
				m_gameScene->SetGameFrameEngine(this);

				if (m_gameFrameEngineSink)
				{
					m_gameScene->SetGameSceneSink(m_gameFrameEngineSink->GetGameSceneSink());
				}
			
				if (!m_gameScene->init())
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
	}

	pScene->addChild(m_gameScene, 0XFFFF);
	//if (pScene != m_gameScene)
	//{
	//	director->replaceScene(this->m_gameScene);
	//}

	if (m_gameFrameEngineSink)
	{
		m_gameFrameEngineSink->SetupGameClient();
	}
	
	LuaEngine * pEngine = LuaEngine::defaultEngine();
	if (pEngine){

		LuaStackEx * luaStack = static_cast<LuaStackEx*>(pEngine->getLuaStack());
		luaStack->call_script_fun("game.SetupGameClientLogic");
	}
	
	m_gameScene->SetupGameClient();

	return true;
}

/************************************************************************/
/* ������Ϸ                                                             */
/************************************************************************/
void CGameFrameEngine::ResetGameClient()
{
	if (m_gameFrameEngineSink)
	{
		m_gameFrameEngineSink->ResetGameClient();
	}
	else
	{
		LuaEngine * pEngine = LuaEngine::defaultEngine();
		if (pEngine){

			LuaStackEx * luaStack = static_cast<LuaStackEx*>(pEngine->getLuaStack());
			luaStack->call_script_fun("game.ResetGameClientLogic");
		}
	}

	if (m_gameScene)
	{
		m_gameScene->ResetGameClient();
	}
}

/************************************************************************/
/* �ر���Ϸ                                                             */
/************************************************************************/
void CGameFrameEngine::CloseGameClient()
{
	if (m_gameScene)
	{
		m_gameScene->CloseGameClient();
	}

	if (m_gameFrameEngineSink)
	{
		m_gameFrameEngineSink->CloseGameClient();
	}
	
	LuaEngine * pEngine = LuaEngine::defaultEngine();
	if (pEngine){

		LuaStackEx * luaStack = static_cast<LuaStackEx*>(pEngine->getLuaStack());
		luaStack->call_script_fun("game.CloseGameClientLogic");
	}

	//DF::shared()->init(0, 0, "", "");

	m_gameScene = NULL;
}

/************************************************************************/
/* �Թ���Ϣ                                                              */
/************************************************************************/
bool CGameFrameEngine::OnEventLookonMode(void * data, int dataSize)
{ 
	if (m_gameFrameEngineSink)
	{
		return m_gameFrameEngineSink->OnEventLookonMode(data,dataSize);
	}
	else
	{
		LuaEngine * pEngine = LuaEngine::defaultEngine();
		if (pEngine){

			LuaStackEx * luaStack = static_cast<LuaStackEx*>(pEngine->getLuaStack());
			PACKET_AIDE_DATA(data);
			luaStack->call_script_fun("game.OnEventLookonMode", (cocos2d::Ref *)&packet, dataSize);
		}
	}
	return true; 
}

/************************************************************************/
/* ������Ϣ                                                              */
/************************************************************************/
bool CGameFrameEngine::OnEventSceneMessage(BYTE cbGameStatus, bool bLookonUser, void* data, int dataSize)
{
	if (m_gameFrameEngineSink)
	{
		bool bRet = m_gameFrameEngineSink->OnEventSceneMessage(cbGameStatus, bLookonUser, data, dataSize);
		if (bRet == false)
		{
			bRet = m_gameScene->OnEventSceneMessage(cbGameStatus, bLookonUser, data, dataSize);
		}
		return bRet;
	}
	else
	{
		LuaEngine * pEngine = LuaEngine::defaultEngine();
		if (pEngine)
		{
			LuaStackEx * luaStack = static_cast<LuaStackEx*>(pEngine->getLuaStack());
			PACKET_AIDE_DATA(data);
			luaStack->call_script_fun("game.OnEventSceneMessage", (int)cbGameStatus, bLookonUser, (cocos2d::Ref *)&packet, dataSize);
		}
	}
	return true;
}


/************************************************************************/
/* ������Ϣ                                                              */
/************************************************************************/
bool CGameFrameEngine::OnEventGameMessage(int sub, void * data, int dataSize)
{
	if (m_gameFrameEngineSink)
	{
		bool bRet = m_gameFrameEngineSink->OnEventGameMessage(sub, data, dataSize);
		if (!bRet)
		{
			bRet = m_gameScene->OnEventGameMessage(sub, data, dataSize);
		}
		return bRet;
	}
	else
	{
		LuaEngine * pEngine = LuaEngine::defaultEngine();
		if (pEngine){

			LuaStackEx * luaStack = static_cast<LuaStackEx*>(pEngine->getLuaStack());
			PACKET_AIDE_DATA(data);
			luaStack->call_script_fun("game.OnEventGameMessage", sub, (cocos2d::Ref *)&packet, dataSize);
		}
	}
	return true;
}

/************************************************************************/
/* ϵͳ������Ϣ                                                          */
/************************************************************************/
bool CGameFrameEngine::OnGFTableMessage(const char* szMessage)
{ 
	if (m_gameFrameEngineSink)
	{
		return m_gameFrameEngineSink->OnGFTableMessage(szMessage);
	}
	else
	{
		LuaEngine * pEngine = LuaEngine::defaultEngine();
		if (pEngine){

			LuaStackEx * luaStack = static_cast<LuaStackEx*>(pEngine->getLuaStack());
			luaStack->call_script_fun("game.OnGFTableMessage", szMessage);
		}
	}
	return true; 
}

/************************************************************************/
/* �ȴ���ʾ                                                             */
/************************************************************************/
bool CGameFrameEngine::OnGFWaitTips(bool bWait)
{ 
	if (m_gameFrameEngineSink)
	{
		return m_gameFrameEngineSink->OnGFWaitTips(bWait);
	}
	else
	{
		LuaEngine * pEngine = LuaEngine::defaultEngine();
		if (pEngine){

			LuaStackEx * luaStack = static_cast<LuaStackEx*>(pEngine->getLuaStack());
			luaStack->call_script_fun("game.OnGFWaitTips", bWait);
		}
	}
	return true; 
}

/************************************************************************/
/* �û�����                                                             */
/************************************************************************/
void CGameFrameEngine::OnEventUserEnter(IClientUserItem * pIClientUserItem, bool bLookonUser)
{
	if (m_gameScene){
		m_gameScene->OnEventUserEnter(pIClientUserItem, bLookonUser);
	}
}

/************************************************************************/
/* �û��뿪                                                             */
/************************************************************************/
void CGameFrameEngine::OnEventUserLeave(IClientUserItem * pIClientUserItem, bool bLookonUser)
{
	if (m_gameScene){
		m_gameScene->OnEventUserLeave(pIClientUserItem, bLookonUser);
	}
}

/************************************************************************/
/* �û�״̬                                                             */
/************************************************************************/
void CGameFrameEngine::OnEventUserStatus(IClientUserItem * pIClientUserItem, bool bLookonUser)
{
	if (m_gameScene){
		m_gameScene->OnEventUserStatus(pIClientUserItem, bLookonUser);
	}
}

/************************************************************************/
/* �û�����                                                             */
/************************************************************************/
void CGameFrameEngine::OnEventUserScore(IClientUserItem * pIClientUserItem, bool bLookonUser)
{
	if (m_gameScene){
		m_gameScene->OnEventUserScore(pIClientUserItem, bLookonUser);
	}
}

/************************************************************************/
/* �û�����                                                             */
/************************************************************************/
void CGameFrameEngine::OnEventUserAttrib(IClientUserItem * pIClientUserItem, bool bLookonUser)
{
	if (m_gameScene){
		m_gameScene->OnEventUserAttrib(pIClientUserItem, bLookonUser);
	}
}

/************************************************************************/
/* �û�ͷ��                                                             */
/************************************************************************/
void CGameFrameEngine::OnEventCustomFace(IClientUserItem * pIClientUserItem, bool bLookonUser)
{

}

/************************************************************************/
/* ������������                                                          */
/************************************************************************/
bool CGameFrameEngine::RecvTalk(void* data, int dataSize)
{
	if (m_gameScene){
		m_gameScene->RecvTalk(data, dataSize);
	}

	return true;
}

/************************************************************************/
/* ���½�����Ϸ                                                          */
/************************************************************************/
void CGameFrameEngine::OnReEnterGame()
{
	if (m_gameScene){
		m_gameScene->OnReEnterGame();
	}
}


