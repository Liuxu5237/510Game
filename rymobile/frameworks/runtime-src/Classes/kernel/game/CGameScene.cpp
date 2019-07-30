#include "CGameScene.h"
#include "CGameFrameEngine.h"
#include "IGameSceneSink.h"

#include "tools/tools/MTNotification.h"
#include "tools/tools/StaticData.h"
#include "tools/tools/StringData.h"
#include "tools/tools/MTNotification.h"
#include "tools/global.h"
#include "script/UtilityFun.h"
#include "script/ArmFun.h"
#include "platform/df/GameEventIDDefine.h"
#include "platform/multiPlatform/MultiPlatformMgr.h"

#include "script/SoundFun.h"

#include "../game/IClientKernel.h"
#include "../server/IServerItem.h"
#include "../server/IServerItemSink.h"
#include "../gameCenter/GameCenterManager.h"

#include "CCLuaEngine.h"
#include "lua/LuaStackEx.h"

/************************************************************************/
/* ���캯��                                                             */
/************************************************************************/
CGameScene::CGameScene()
{
	m_gameSceneSink = NULL;
	m_GameFrameEngine		= NULL;

	m_haveNotifyUserOnHaveNet	= false;
	m_haveNotifyUserOnNoNet		= false;

	m_nReconnetFlag = false;
}

/************************************************************************/
/* ��������                                                             */
/************************************************************************/
CGameScene::~CGameScene()
{
	_eventDispatcher->removeEventListener(_touchListener);
}

/************************************************************************/
/* ��ʼ������                                                           */
/************************************************************************/
bool CGameScene::init()
{
	//Director * director = Director::getInstance();
	//auto glview = director->getOpenGLView();
	//if(glview) {
	//	glview->setDesignResolutionSize(kPlatformRevolutionWidth, kPlatformRevolutionHeight, kResolutionShowAll);
	//}
	//else
	//{
	//	CCLOG("setDesignResolutionSize error");
	//}

	if (!CCLayer::init())
	{
		return false;
	}

	this->setName("GameScene");
	this->setTag(DF::shared()->GetGameKindID());

    CCLOG("--1-- CGameScene::init()  m_gameSceneSink=%p",m_gameSceneSink);
	if (m_gameSceneSink)
	{
		m_gameSceneSink->init(this);
	}
	else
	{
		LuaEngine * pEngine = LuaEngine::defaultEngine();
		if (pEngine){

			LuaStackEx * luaStack = static_cast<LuaStackEx*>(pEngine->getLuaStack());
			luaStack->call_script_fun("game.Init", (CCObject *)this);
		}
	}

	G_NOTIFY_REG("ON_RESUME_GAME", CGameScene::OnReconnectResumeGame);

	G_NOTIFY_REG("GAME_PAUSE", CGameScene::OnGameEnterBackground);
	G_NOTIFY_REG("GAME_RESUME",CGameScene::OnGameEnterForeground);

	G_NOTIFY_REG("RECONNECT_ON_LOSS", CGameScene::OnDetectNetDown);

	G_NOTIFY_REG("ON_GAME_WAIT_DISTRIBUTE", CGameScene::OnSubWaitBack);

	// Adds touch event listener
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);

	listener->onTouchBegan = CC_CALLBACK_2(CGameScene::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(CGameScene::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(CGameScene::onTouchEnded, this);

	_eventDispatcher->addEventListenerWithFixedPriority(listener, 1);

	_touchListener = listener;

	return true;
}

/************************************************************************/
/* ������Ϸ                                                             */
/************************************************************************/
bool CGameScene::SetupGameClient()
{	
	IClientKernel::get()->SetChatSink((IChatSink*)this);
	IClientKernel::get()->SetStringMessageSink((IStringMessageSink *)this);

	if (m_gameSceneSink)
	{
		m_gameSceneSink->SetupGameClient();
	}
	else
	{
		LuaEngine * pEngine = LuaEngine::defaultEngine();
		if (pEngine){

			LuaStackEx * luaStack = static_cast<LuaStackEx*>(pEngine->getLuaStack());
			luaStack->call_script_fun("game.SetupGameClientView");
		}
	}

	m_haveNotifyUserOnHaveNet = false;
	m_haveNotifyUserOnNoNet = false;
	m_nReconnetFlag = false;
	unschedule(SEL_SCHEDULE(&CGameScene::reconnect_on_loss));
	return true;
}

/************************************************************************/
/* ������Ϸ                                                             */
/************************************************************************/
void CGameScene::ResetGameClient()
{
	if (m_gameSceneSink)
	{
		m_gameSceneSink->ResetGameClient();
	}
	else
	{
		LuaEngine * pEngine = LuaEngine::defaultEngine();
		if (pEngine){

			LuaStackEx * luaStack = static_cast<LuaStackEx*>(pEngine->getLuaStack());
			luaStack->call_script_fun("game.ResetGameClientView");
		}
	}

	m_haveNotifyUserOnHaveNet = false;
	m_haveNotifyUserOnNoNet = false; 
	m_nReconnetFlag = false;
}


/************************************************************************/
/* �ر���Ϸ                                                             */
/************************************************************************/
void CGameScene::CloseGameClient()
{
	IClientKernel::get()->SetChatSink(NULL);
	IClientKernel::get()->SetStringMessageSink(NULL);

	SoundFun::Instance()->stopBackMusic();

	if (m_gameSceneSink)
	{
		m_gameSceneSink->CloseGameClient();
	}
	else
	{
		LuaEngine * pEngine = LuaEngine::defaultEngine();
		if (pEngine){

			LuaStackEx * luaStack = static_cast<LuaStackEx*>(pEngine->getLuaStack());
			luaStack->call_script_fun("game.CloseGameClientView");
		}
	}

	G_NOTIFY_D("game_event", MTData::create(GAME_EVENT_ID_CLOSE_GAME_CLIENT));

	Director::getInstance()->getActionManager()->removeAllActions();
	//StaticData::LoadGameHallRes();

	//delete by liuzhen have to add 2016.09.19
	CGameCenterManager::Instance()->setCanCreateTable(true);
	G_NOTIFY_UNREG("ON_RESUME_GAME");

	G_NOTIFY_UNREG("GAME_PAUSE");
	G_NOTIFY_UNREG("GAME_RESUME");

	G_NOTIFY_UNREG("RECONNECT_ON_LOSS");

	G_NOTIFY_UNREG("ON_GAME_WAIT_DISTRIBUTE");

	unscheduleAllCallbacks();

	this->removeFromParent();
}

/************************************************************************/
/* ������Ϸ�������                                                      */
/************************************************************************/
void CGameScene::onEnterTransitionDidFinish()
{
	if (m_gameSceneSink)
	{
		m_gameSceneSink->onEnterTransitionDidFinish();
	}
	else
	{
		LuaEngine * pEngine = LuaEngine::defaultEngine();
		if (pEngine){

			LuaStackEx * luaStack = static_cast<LuaStackEx*>(pEngine->getLuaStack());
			luaStack->call_script_fun("game.onEnterTransitionDidFinish");
		}
	}
}

/************************************************************************/
/* ��������                                                              */
/************************************************************************/
void CGameScene::update(float delta)
{
	CCLayer::update(delta);

	if (m_gameSceneSink)
	{
		m_gameSceneSink->update(delta);
	}
	else
	{
		LuaEngine * pEngine = LuaEngine::defaultEngine();
		if (pEngine){

			LuaStackEx * luaStack = static_cast<LuaStackEx*>(pEngine->getLuaStack());
			luaStack->call_script_fun("game.update", delta);
		}
	}
}

/************************************************************************/
/* �û�����                                                             */
/************************************************************************/
void CGameScene::OnEventUserEnter(IClientUserItem * pIClientUserItem, bool bLookonUser)
{
	if (m_gameSceneSink)
	{
		m_gameSceneSink->OnEventUserEnter(pIClientUserItem, bLookonUser);
		LuaEngine * pEngine = LuaEngine::defaultEngine();
		if (pEngine){

			LuaStackEx * luaStack = static_cast<LuaStackEx*>(pEngine->getLuaStack());
			luaStack->call_script_fun("game.OnEventUserEnter", (CCObject *)pIClientUserItem, bLookonUser);
		}
	}
	else
	{
		LuaEngine * pEngine = LuaEngine::defaultEngine();
		if (pEngine){

			LuaStackEx * luaStack = static_cast<LuaStackEx*>(pEngine->getLuaStack());
			luaStack->call_script_fun("game.OnEventUserEnter", (CCObject *)pIClientUserItem, bLookonUser);
		}
	}
}

/************************************************************************/
/* �û��뿪                                                             */
/************************************************************************/
void CGameScene::OnEventUserLeave(IClientUserItem * pIClientUserItem, bool bLookonUser)
{
	if (m_gameSceneSink)
	{
		m_gameSceneSink->OnEventUserLeave(pIClientUserItem, bLookonUser);

		LuaEngine * pEngine = LuaEngine::defaultEngine();
		if (pEngine){

			LuaStackEx * luaStack = static_cast<LuaStackEx*>(pEngine->getLuaStack());
			luaStack->call_script_fun("game.OnEventUserLeave", (CCObject *)pIClientUserItem, bLookonUser);
		}
	}
	else
	{
		LuaEngine * pEngine = LuaEngine::defaultEngine();
		if (pEngine){

			LuaStackEx * luaStack = static_cast<LuaStackEx*>(pEngine->getLuaStack());
			luaStack->call_script_fun("game.OnEventUserLeave", (CCObject *)pIClientUserItem, bLookonUser);
		}
	}
}

/************************************************************************/
/* �û��뿪                                                              */
/************************************************************************/
void CGameScene::OnEventUserStatus(IClientUserItem * pIClientUserItem, bool bLookonUser)
{
	if (m_gameSceneSink)
	{
		m_gameSceneSink->OnEventUserStatus(pIClientUserItem, bLookonUser);

	}
	else
	{
		LuaEngine * pEngine = LuaEngine::defaultEngine();
		if (pEngine){

			LuaStackEx * luaStack = static_cast<LuaStackEx*>(pEngine->getLuaStack());
			luaStack->call_script_fun("game.OnEventUserStatus", (CCObject *)pIClientUserItem, bLookonUser);
		}
	}
}

/************************************************************************/
/* �û�����                                                              */
/************************************************************************/
void CGameScene::OnEventUserScore(IClientUserItem * pIClientUserItem, bool bLookonUser)
{
	if (m_gameSceneSink)
	{
		m_gameSceneSink->OnEventUserScore(pIClientUserItem, bLookonUser);

		LuaEngine * pEngine = LuaEngine::defaultEngine();
		if (pEngine){

			LuaStackEx * luaStack = static_cast<LuaStackEx*>(pEngine->getLuaStack());
			luaStack->call_script_fun("game.OnEventUserScore", (CCObject *)pIClientUserItem, bLookonUser);
		}
	}
	else
	{
		LuaEngine * pEngine = LuaEngine::defaultEngine();
		if (pEngine){

			LuaStackEx * luaStack = static_cast<LuaStackEx*>(pEngine->getLuaStack());
			luaStack->call_script_fun("game.OnEventUserScore", (CCObject *)pIClientUserItem, bLookonUser);
		}
	}
}

/************************************************************************/
/* �û�����                                                              */
/************************************************************************/
void CGameScene::OnEventUserAttrib(IClientUserItem * pIClientUserItem, bool bLookonUser)
{
	if (m_gameSceneSink)
	{
		m_gameSceneSink->OnEventUserAttrib(pIClientUserItem, bLookonUser);
	}
	else
	{
		LuaEngine * pEngine = LuaEngine::defaultEngine();
		if (pEngine){

			LuaStackEx * luaStack = static_cast<LuaStackEx*>(pEngine->getLuaStack());
			luaStack->call_script_fun("game.OnEventUserAttrib", (CCObject *)pIClientUserItem, bLookonUser);
		}
	}
}

/************************************************************************/
/* �����������������Ϸ������Ϣ                                           */
/************************************************************************/
bool CGameScene::OnEventSceneMessage(BYTE cbGameStatus, bool bLookonUser, void* data, int dataSize)
{
	if (m_gameSceneSink)
	{
		return m_gameSceneSink->OnEventSceneMessage(cbGameStatus, bLookonUser, data, dataSize);
	}

	return false;
}

/************************************************************************/
/* ������Ϸ��Ϣ                                                          */
/************************************************************************/
bool CGameScene::OnEventGameMessage(int sub, void* data, int dataSize)
{
	if (m_gameSceneSink)
	{
		return m_gameSceneSink->OnEventGameMessage(sub, data, dataSize);
	}
	
	return false;
}

/************************************************************************/
/* ��Ϸ��ͣ                                                             */
/************************************************************************/
void CGameScene::OnGameEnterBackground(cocos2d::Ref* obj)
{
	if (m_gameSceneSink)
	{
		m_gameSceneSink->OnGameEnterBackground();
	}
	else
	{
		LuaEngine * pEngine = LuaEngine::defaultEngine();
		if (pEngine){

			LuaStackEx * luaStack = static_cast<LuaStackEx*>(pEngine->getLuaStack());
			luaStack->call_script_fun("game.OnGameEnterBackground");
		}
	}

	unscheduleAllCallbacks();

	if (IServerItem::get())
	{
		IServerItem::get()->TerminConnect();
	}

	m_haveNotifyUserOnHaveNet = false;
	m_haveNotifyUserOnNoNet = false;
	m_nReconnetFlag = false;
}

/************************************************************************/
/* ��Ϸ�ָ�                                                             */
/************************************************************************/
void CGameScene::OnGameEnterForeground(cocos2d::Ref* obj)
{
	if (m_gameSceneSink)
	{
		m_gameSceneSink->OnGameEnterForeground();
	}
	else
	{
		LuaEngine * pEngine = LuaEngine::defaultEngine();
		if (pEngine){

			LuaStackEx * luaStack = static_cast<LuaStackEx*>(pEngine->getLuaStack());
			luaStack->call_script_fun("game.OnGameEnterForeground");
		}
	}

	if (IServerItem::get())
	{
		G_NOTIFY_D("game_event", MTData::create(GAME_EVENT_ID_ENTER_FOREGROUND));
		IServerItem::get()->ResumeConnect();
	}
}

/************************************************************************/
/* ��������ӿ�                                                          */
/************************************************************************/
void CGameScene::OnReconnectResumeGame(cocos2d::Ref * obj)
{
	if (m_gameSceneSink)
	{
		m_gameSceneSink->OnReconnectResumeGame();

		LuaEngine * pEngine = LuaEngine::defaultEngine();
		if (pEngine){

			LuaStackEx * luaStack = static_cast<LuaStackEx*>(pEngine->getLuaStack());
			luaStack->call_script_fun("game.OnReconnectResumeGame");
		}
	}
	else
	{
		LuaEngine * pEngine = LuaEngine::defaultEngine();
		if (pEngine){

			LuaStackEx * luaStack = static_cast<LuaStackEx*>(pEngine->getLuaStack());
			luaStack->call_script_fun("game.OnReconnectResumeGame");
		}
	}
}

/************************************************************************/
/* ������ʼ                                                             */
/************************************************************************/
bool CGameScene::onTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent) 
{ 
	if (m_gameSceneSink)
	{
		return m_gameSceneSink->ccTouchBegan(pTouch, pEvent);
	}
	else
	{
		LuaEngine * pEngine = LuaEngine::defaultEngine();
		if (pEngine){

			LuaStackEx * luaStack = static_cast<LuaStackEx*>(pEngine->getLuaStack());
			luaStack->call_script_fun("game.ccTouchBegan", (CCObject *)pTouch, (CCObject *)pEvent);
		}
	}
	return true; 
}

/************************************************************************/
/* �����ƶ�                                                             */
/************************************************************************/
void CGameScene::onTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent) 
{
	if (m_gameSceneSink)
	{
		m_gameSceneSink->ccTouchMoved(pTouch, pEvent);
	}
	else
	{
		LuaEngine * pEngine = LuaEngine::defaultEngine();
		if (pEngine){

			LuaStackEx * luaStack = static_cast<LuaStackEx*>(pEngine->getLuaStack());
			luaStack->call_script_fun("game.ccTouchMoved", (CCObject *)pTouch, (CCObject *)pEvent);
		}
	}
}

/************************************************************************/
/* ��������                                                              */
/************************************************************************/
void CGameScene::onTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
	if (m_gameSceneSink)
	{
		m_gameSceneSink->ccTouchEnded(pTouch, pEvent);
	}
	else
	{
		LuaEngine * pEngine = LuaEngine::defaultEngine();
		if (pEngine){

			LuaStackEx * luaStack = static_cast<LuaStackEx*>(pEngine->getLuaStack());
			luaStack->call_script_fun("game.ccTouchEnded", (CCObject *)pTouch, (CCObject *)pEvent);
		}
	}
}

/************************************************************************/
/* ����ʧ�ܴ���                                                         */
/************************************************************************/
void CGameScene::OnDetectNetDown(cocos2d::Ref * obj)
{
	IClientKernel* kernel = IClientKernel::get();
	if (kernel == nullptr)
	{
		G_NOTIFY_D("game_event", MTData::create(GAME_EVENT_ID_RECONNECT_UNKNOWN));
		return;
	}

	if (m_nReconnetFlag){

		G_NOTIFY_D("game_event", MTData::create(GAME_EVENT_ID_RECONNECT_NET_ERROR));
	}
	else
	{
		if (m_gameSceneSink)
		{
			m_gameSceneSink->OnDetectNetDown();
		}
		else
		{
			LuaEngine * pEngine = LuaEngine::defaultEngine();
			if (pEngine){

				LuaStackEx * luaStack = static_cast<LuaStackEx*>(pEngine->getLuaStack());
				luaStack->call_script_fun("game.OnDetectNetDown");
			}
		}

		if (!m_haveNotifyUserOnNoNet)
		{
			m_haveNotifyUserOnNoNet = true;
			G_NOTIFY_D("game_event", MTData::create(GAME_EVENT_ID_DETECT_NET_DOWN));
		}

		this->schedule(SEL_SCHEDULE(&CGameScene::reconnect_on_loss), 1.5f);
	}

}

/************************************************************************/
/* ��Ϸ����ʧ��                                                         */
/************************************************************************/
void CGameScene::reconnect_on_loss(float dt)
{
	static float total_time = 0;
	total_time += dt;

	bool isHaveNet = false;

	isHaveNet = MultiPlatformMgr::getInstance()->obtainNetWorkState();


#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	if( total_time > 10)
		isHaveNet = true;
#endif
	if (total_time > 30)
	{
		this->unschedule(SEL_SCHEDULE(&CGameScene::reconnect_on_loss));
		if (!isHaveNet)
		{
			G_NOTIFY_D("game_event", MTData::create(GAME_EVENT_ID_DETECT_NET_TIME_OUT));	
			total_time = 0.0f;
			return;
		}
		
	}

	if (isHaveNet)
	{
		if (total_time <= 30.0f)
			this->unschedule(SEL_SCHEDULE(&CGameScene::reconnect_on_loss));

		if(!m_haveNotifyUserOnHaveNet)
		{
			m_haveNotifyUserOnHaveNet = true;

			G_NOTIFY_D("game_event", MTData::create(GAME_EVENT_ID_DETECT_NET_AGAIN,0,0,"","","",(CCObject *)this));
		} 
		
		total_time = 0.0f;
	}
}

/************************************************************************/
/* �����������½�����Ϸ                                                  */
/************************************************************************/
void CGameScene::OnReEnterGame()
{
	m_haveNotifyUserOnHaveNet = false;
	m_haveNotifyUserOnNoNet = false;
	m_nReconnetFlag = false;
	unschedule(SEL_SCHEDULE(&CGameScene::reconnect_on_loss));
}

/************************************************************************/
/* �ڶ���������¼�⵽����                                               */
/************************************************************************/
void CGameScene::OnNetDetectedInNetLossState()
{
	m_nReconnetFlag = true;

	CGameCenterManager::Instance()->reconnectServer();

	if (m_gameSceneSink)
	{
		m_gameSceneSink->OnEnterReconnectState();
	}
	else
	{
		LuaEngine * pEngine = LuaEngine::defaultEngine();
		if (pEngine)
		{
			LuaStackEx * luaStack = static_cast<LuaStackEx*>(pEngine->getLuaStack());
			luaStack->call_script_fun("game.OnEnterReconnectState");
		}
	}
}

/************************************************************************/
/* �ȴ�����                                                              */
/************************************************************************/
void CGameScene::OnSubWaitBack(cocos2d::Ref * obj)
{
	if (m_gameSceneSink)
	{
		m_gameSceneSink->OnSubWaitBack();
	}
	else
	{
		LuaEngine * pEngine = LuaEngine::defaultEngine();
		if (pEngine){

			LuaStackEx * luaStack = static_cast<LuaStackEx*>(pEngine->getLuaStack());
			luaStack->call_script_fun("game.OnSubWaitBack");
		}
	}
}


/************************************************************************/
/* �л�����                                                             */
/************************************************************************/
WORD CGameScene::SwitchViewChairID(WORD wChairID)
{
	//�����ж�
	if(wChairID==INVALID_CHAIR || NULL == IClientKernel::get())
	{
		return INVALID_CHAIR;
	}
	WORD wMeChair = IClientKernel::get()->GetMeChairID();
	if(wMeChair==INVALID_CHAIR)
	{
		return INVALID_CHAIR;
	}

	WORD wChairCount = DF::shared()->GetGamePlayer();
	if(wChairCount == 0)
		return INVALID_CHAIR;

	WORD wViewChairID=(wChairID - wMeChair + wChairCount) % wChairCount;

	return wViewChairID;
}

/************************************************************************/
/*�û�����                                                               */
/************************************************************************/
bool CGameScene::InsertExpression(const char* pszSendUser, unsigned int index)
{
	
	return true;
}

/************************************************************************/
/* �û�����                                                              */
/************************************************************************/
bool CGameScene::InsertExpression(const char* pszSendUser, unsigned int index, bool bMyselfString)
{
	return true;
}

/************************************************************************/
/* �û�����                                                              */
/************************************************************************/
bool CGameScene::InsertExpression(const char* pszSendUser, const char* pszRecvUser, unsigned int index)
{
	return true;
}

/************************************************************************/
/* �û�����                                                             */
/************************************************************************/
bool CGameScene::InsertUserChat(const char* pszSendUser, const char* pszString, unsigned int crColor)
{
	//PLAZZ_PRINTF(t8("%s ˵:%s\n"), pszSendUser, pszString);
	return true;
}

/************************************************************************/
/* �û�����                                                             */
/************************************************************************/
bool CGameScene::InsertUserChat(const char* pszSendUser, const char* pszRecvUser, const char* pszString, unsigned int crColor)
{
	//PLAZZ_PRINTF(t8("%s �� %s ˵:%s\n"), pszSendUser, pszRecvUser, pszString);
	return true;
}

/************************************************************************/
/* �û�˽��                                                              */
/************************************************************************/
bool CGameScene::InsertWhisperChat(const char* pszSendUser, const char* pszString, unsigned int crColor, bool bMyselfString)
{
	//PLAZZ_PRINTF(t8("%s ����˵:%s\n"), pszSendUser, pszString);
	return true;
}

/************************************************************************/
/* �û�����                                                              */
/************************************************************************/
bool CGameScene::InsertUserTrumpet(const char* pszSendUser, const char* pszString, unsigned int crColor)
{
	//PLAZZ_PRINTF(t8("%s ����Trumpet����:%s\n"), pszSendUser, pszString);
	return true;
}

/************************************************************************/
/* �û�����                                                             */
/************************************************************************/
bool CGameScene::InsertUserTyphon(const char* pszSendUser, const char* pszString, unsigned int crColor)
{
	//PLAZZ_PRINTF(t8("%s ����Typhon����:%s\n"), pszSendUser, pszString);
	return true;
}

/************************************************************************/
/*ϵͳ��Ϣ                                                               */
/************************************************************************/
bool CGameScene::InsertSystemChat(const char* pszString)
{
	PLAZZ_PRINTF("ChatLayer::InsertSystemChat");
	return true;
}

/************************************************************************/
/* �����¼�                                                             */
/************************************************************************/
bool CGameScene::InsertUserEnter(const char* pszUserName)
{
	PLAZZ_PRINTF("ChatLayer::InsertUserEnter");
	//PLAZZ_PRINTF(t8("%s ���뷿��\n"), pszUserName);
	return true;
}

/************************************************************************/
/* �뿪�¼�                                                             */
/************************************************************************/
bool CGameScene::InsertUserLeave(const char* pszUserName)
{
	PLAZZ_PRINTF("ChatLayer::InsertUserLeave");
	//PLAZZ_PRINTF(t8("%s �뿪����\n"), pszUserName);
	return true;
}

/************************************************************************/
/* �����¼�                                                              */
/************************************************************************/
bool CGameScene::InsertUserOffLine(const char* pszUserName)
{
	PLAZZ_PRINTF("ChatLayer::InsertUserOffLine");
	//PLAZZ_PRINTF(t8("%s ����\n"), pszUserName);
	return true;
}

/************************************************************************/
/* ��ͨ��Ϣ                                                             */
/************************************************************************/
bool CGameScene::InsertNormalString(const char* pszString)
{
	PLAZZ_PRINTF("ChatLayer::InsertNormalString");
	//PLAZZ_PRINTF(t8("��ͨ��Ϣ:%s\n"), pszString);
	return true;
}

/************************************************************************/
/* ϵͳ��Ϣ(�������)                                                    */
/************************************************************************/
bool CGameScene::InsertSystemString(const char* pszString)
{
	PLAZZ_PRINTF("ChatLayer::InsertSystemString");
	log("message is %s ", pszString);

	G_NOTIFY_D("game_event", MTData::create(GAME_EVENT_ID_SYSTEM_MSG, 0, 0, pszString, "", "", NULL));
	//PLAZZ_PRINTF(t8("ϵͳ��Ϣ:%s\n"), pszString);
	//	G_NOTIFY_D("GLAD_MSG", MTData::create(0, 0, 0, pszString, "", ""));
	return true;
}

/************************************************************************/
/* ��ʾ��Ϣ(�Ի���ʽ??)                                                */
/************************************************************************/
int CGameScene::InsertPromptString(const char* pszString, int iButtonType)
{
	PLAZZ_PRINTF("ChatLayer::InsertPromptString");
	//PLAZZ_PRINTF(t8("��ʾ��Ϣ:%s[%s]\n"), pszString, iButtonType == 0 ? t8("ȷ��"):t8("ȷ��,ȡ��"));
	return 0;
}

/************************************************************************/
/* ������Ϣ(�������)                                                    */
/************************************************************************/
bool CGameScene::InsertAfficheString(const char* pszString)
{
	PLAZZ_PRINTF("ChatLayer::InsertAfficheString");
	//PLAZZ_PRINTF(t8("������Ϣ:%s\n"), pszString);
	return true;
}

/************************************************************************/
/* ������������                                                          */
/************************************************************************/
void CGameScene::RecvTalk(void* data, int dataSize)
{
	tagUserTalk* pNetInfo = (tagUserTalk*)data;
	if (pNetInfo->cbType == CMD_GR_C_TableTalk::TYPE_FILE)
	{
		RevTalk_File(pNetInfo);
	}
	if (pNetInfo->cbType == CMD_GR_C_TableTalk::TYPE_WORD)
	{
		RevTalk_String(pNetInfo);
	}
	if (pNetInfo->cbType == CMD_GR_C_TableTalk::TYPE_DEFINE)
	{
		RevTalk_TalkIdex(pNetInfo);
	}
	if (pNetInfo->cbType == CMD_GR_C_TableTalk::TYPE_BIAOQING)
	{
		RevTalk_BiaoQing(pNetInfo);
	}
}

/************************************************************************/
/* ϲ����Ϣ                                                              */
/************************************************************************/
bool CGameScene::InsertGladString(const char * pszContent, const char * pszNickName, const char* pszNum, dword colText, dword colName, dword colNum)
{
	return true;
}

/************************************************************************/
/* ���������ļ�                                                          */
/************************************************************************/
void CGameScene::sendTalkFile(int iChair, std::string kFile)
{
	if (kFile.empty() || "" == kFile)
	{
		cocos2d::log("sendTalkFile kfile is null");
		return;
	}
	ssize_t iSize = 0;
	std::string kDestFile = kFile;
#if CC_TARGET_PLATFORM != CC_PLATFORM_ANDROID
	kDestFile = cocos2d::CCFileUtils::getInstance()->getWritablePath() + utility::toString(time(NULL), ".arm");
	ArmFun::WavToArm(kFile.c_str(), kDestFile.c_str());
#endif
	tagUserTalk kNetInfo;
	kNetInfo.cbChairID = iChair;
	kNetInfo.cbType = CMD_GR_C_TableTalk::TYPE_FILE;
	unsigned char* pData = cocos2d::CCFileUtils::sharedFileUtils()->getFileData(kDestFile, "rb", &iSize);
	if (!pData)
	{
		return;
	}
	kNetInfo.cbChairID = iChair;
	memcpy(kNetInfo.strTalkData, pData, iSize);
	free(pData);
	kNetInfo.strTalkSize = iSize;

	int iNetSize = sizeof(kNetInfo)-sizeof(kNetInfo.strTalkData);

	IServerItem::get()->SendSocketData(MDM_GF_FRAME, SUB_GR_TABLE_TALK, (char *)&kNetInfo, iNetSize + iSize);
}

/************************************************************************/
/* ��������                                                              */
/************************************************************************/
void CGameScene::sendTalkString(int iChair, std::string strString)
{
	tagUserTalk kNetInfo;
	kNetInfo.cbChairID = iChair;
	kNetInfo.cbType = CMD_GR_C_TableTalk::TYPE_WORD;
	utility::StringToChar(strString, kNetInfo.strString, 128);
	int iNetSize = sizeof(kNetInfo)-sizeof(kNetInfo.strTalkData);
	IServerItem::get()->SendSocketData(MDM_GF_FRAME, SUB_GR_TABLE_TALK, (char *)&kNetInfo, iNetSize);
}

/************************************************************************/
/* ���ͳ�����                                                            */
/************************************************************************/
void CGameScene::sendTalkDefine(int iChair, std::string strSoundPath)
{
	tagUserTalk kNetInfo;
	kNetInfo.cbChairID = iChair;
	kNetInfo.cbType = CMD_GR_C_TableTalk::TYPE_DEFINE;
	utility::StringToChar(strSoundPath, kNetInfo.strString, 128);
	int iNetSize = sizeof(kNetInfo)-sizeof(kNetInfo.strTalkData);
	IServerItem::get()->SendSocketData(MDM_GF_FRAME, SUB_GR_TABLE_TALK, (char *)&kNetInfo, iNetSize);
}

/************************************************************************/
/* ���ͱ���                                                                     */
/************************************************************************/
void CGameScene::sendTalkBiaoQing(int iChair, std::string strFilePath)
{
	tagUserTalk kNetInfo;
	kNetInfo.cbChairID = iChair;
	kNetInfo.cbType = CMD_GR_C_TableTalk::TYPE_BIAOQING;
	utility::StringToChar(strFilePath, kNetInfo.strString, 128);
	int iNetSize = sizeof(kNetInfo)-sizeof(kNetInfo.strTalkData);
	IServerItem::get()->SendSocketData(MDM_GF_FRAME, SUB_GR_TABLE_TALK, (char *)&kNetInfo, iNetSize);
}

/************************************************************************/
/* ���������ļ�                                                          */
/************************************************************************/
bool CGameScene::RevTalk_File(tagUserTalk* pNetInfo)
{
	if (pNetInfo->strTalkSize == 0)
	{
		return true;
	}
	static int iIdex = 0;
	iIdex++;
	std::string kFile = utility::toString(cocos2d::CCFileUtils::sharedFileUtils()->getWritablePath(), "TableTalk", iIdex, ".arm");
	FILE *fp = fopen(kFile.c_str(), "wb");

	fseek(fp, 0, SEEK_END);
	fseek(fp, 0, SEEK_SET);
	fwrite(&pNetInfo->strTalkData, sizeof(unsigned char), pNetInfo->strTalkSize, fp);
	fclose(fp);
	int iAddTime = pNetInfo->strTalkSize / 1200 + 2.0f;
	if (iAddTime > 10)
	{
		iAddTime = 10;
	}
	std::string kDestFile = kFile;
	utility::StringReplace(kDestFile, "arm", "wav");
	ArmFun::ArmToWav(kFile.c_str(), kDestFile.c_str());

	SoundFun::Instance()->PauseBackMusic();
	SoundFun::Instance()->ResumeBackMusic(iAddTime);
	SoundFun::Instance()->PaseEffectMusic();
	SoundFun::Instance()->ResumeEffectMusic(iAddTime);

	SoundFun::Instance()->playEffectDirect(kDestFile);

	CMD_GR_C_TableTalk netInfo;

	netInfo.cbChairID = pNetInfo->cbChairID;
	netInfo.cbType = pNetInfo->cbType;
	memcpy(netInfo.strString,pNetInfo->strString,128);
	netInfo.strTalkSize = pNetInfo->strTalkSize;
	memcpy(netInfo.strTalkData,pNetInfo->strTalkData,pNetInfo->strTalkSize);

	G_NOTIFY_D("game_talk", MTData::create(0, 0, 0, "", "", "", &netInfo));

	return true;
}

/************************************************************************/
/* ������������                                                          */
/************************************************************************/
bool CGameScene::RevTalk_String(tagUserTalk * pNetInfo)
{
	CMD_GR_C_TableTalk netInfo;
	netInfo.cbChairID = pNetInfo->cbChairID;
	netInfo.cbType = pNetInfo->cbType;
	netInfo.strTalkSize = pNetInfo->strTalkSize;
	memcpy(netInfo.strString, pNetInfo->strString, 128);

	G_NOTIFY_D("game_talk", MTData::create(0, 0, 0, "", "", "", &netInfo));
	
	return true;
}

/************************************************************************/
/* �������쳣��                                                          */
/************************************************************************/
bool CGameScene::RevTalk_TalkIdex(tagUserTalk* pNetInfo)
{
	CMD_GR_C_TableTalk netInfo;
	netInfo.cbChairID = pNetInfo->cbChairID;
	netInfo.cbType = pNetInfo->cbType;
	netInfo.strTalkSize = pNetInfo->strTalkSize;
	memcpy(netInfo.strString, pNetInfo->strString, 128);

	SoundFun::Instance()->PauseBackMusic();
	SoundFun::Instance()->ResumeBackMusic(5.0f);

	G_NOTIFY_D("game_talk", MTData::create(0, 0, 0, "", "", "", &netInfo));
	return true;
}

/************************************************************************/
/* �����������                                                                     */
/************************************************************************/
bool CGameScene::RevTalk_BiaoQing(tagUserTalk* pNetInfo)
{
	CMD_GR_C_TableTalk netInfo;
	netInfo.cbChairID = pNetInfo->cbChairID;
	netInfo.cbType = pNetInfo->cbType;
	netInfo.strTalkSize = pNetInfo->strTalkSize;
	memcpy(netInfo.strString, pNetInfo->strString, 128);

	G_NOTIFY_D("game_talk", MTData::create(0, 0, 0, "", "", "", &netInfo));
	return true;
}
