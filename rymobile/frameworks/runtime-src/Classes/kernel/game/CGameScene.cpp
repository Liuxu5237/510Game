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
/* 构造函数                                                             */
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
/* 析构函数                                                             */
/************************************************************************/
CGameScene::~CGameScene()
{
	_eventDispatcher->removeEventListener(_touchListener);
}

/************************************************************************/
/* 初始化函数                                                           */
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
/* 启动游戏                                                             */
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
/* 重置游戏                                                             */
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
/* 关闭游戏                                                             */
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
/* 进入游戏场景完成                                                      */
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
/* 心跳函数                                                              */
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
/* 用户进入                                                             */
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
/* 用户离开                                                             */
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
/* 用户离开                                                              */
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
/* 用户积分                                                              */
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
/* 用户属性                                                              */
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
/* 处理断线重连进入游戏场景消息                                           */
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
/* 处理游戏消息                                                          */
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
/* 游戏暂停                                                             */
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
/* 游戏恢复                                                             */
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
/* 重连进入接口                                                          */
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
/* 触摸开始                                                             */
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
/* 触摸移动                                                             */
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
/* 触摸结束                                                              */
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
/* 重连失败处理                                                         */
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
/* 游戏重连失败                                                         */
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
/* 断线重连重新进入游戏                                                  */
/************************************************************************/
void CGameScene::OnReEnterGame()
{
	m_haveNotifyUserOnHaveNet = false;
	m_haveNotifyUserOnNoNet = false;
	m_nReconnetFlag = false;
	unschedule(SEL_SCHEDULE(&CGameScene::reconnect_on_loss));
}

/************************************************************************/
/* 在断网的情况下检测到网络                                               */
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
/* 等待分组                                                              */
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
/* 切换椅子                                                             */
/************************************************************************/
WORD CGameScene::SwitchViewChairID(WORD wChairID)
{
	//参数判断
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
/*用户表情                                                               */
/************************************************************************/
bool CGameScene::InsertExpression(const char* pszSendUser, unsigned int index)
{
	
	return true;
}

/************************************************************************/
/* 用户表情                                                              */
/************************************************************************/
bool CGameScene::InsertExpression(const char* pszSendUser, unsigned int index, bool bMyselfString)
{
	return true;
}

/************************************************************************/
/* 用户表情                                                              */
/************************************************************************/
bool CGameScene::InsertExpression(const char* pszSendUser, const char* pszRecvUser, unsigned int index)
{
	return true;
}

/************************************************************************/
/* 用户聊天                                                             */
/************************************************************************/
bool CGameScene::InsertUserChat(const char* pszSendUser, const char* pszString, unsigned int crColor)
{
	//PLAZZ_PRINTF(t8("%s 说:%s\n"), pszSendUser, pszString);
	return true;
}

/************************************************************************/
/* 用户聊天                                                             */
/************************************************************************/
bool CGameScene::InsertUserChat(const char* pszSendUser, const char* pszRecvUser, const char* pszString, unsigned int crColor)
{
	//PLAZZ_PRINTF(t8("%s 对 %s 说:%s\n"), pszSendUser, pszRecvUser, pszString);
	return true;
}

/************************************************************************/
/* 用户私聊                                                              */
/************************************************************************/
bool CGameScene::InsertWhisperChat(const char* pszSendUser, const char* pszString, unsigned int crColor, bool bMyselfString)
{
	//PLAZZ_PRINTF(t8("%s 对你说:%s\n"), pszSendUser, pszString);
	return true;
}

/************************************************************************/
/* 用户喇叭                                                              */
/************************************************************************/
bool CGameScene::InsertUserTrumpet(const char* pszSendUser, const char* pszString, unsigned int crColor)
{
	//PLAZZ_PRINTF(t8("%s 发送Trumpet喇叭:%s\n"), pszSendUser, pszString);
	return true;
}

/************************************************************************/
/* 用户喇叭                                                             */
/************************************************************************/
bool CGameScene::InsertUserTyphon(const char* pszSendUser, const char* pszString, unsigned int crColor)
{
	//PLAZZ_PRINTF(t8("%s 发送Typhon喇叭:%s\n"), pszSendUser, pszString);
	return true;
}

/************************************************************************/
/*系统消息                                                               */
/************************************************************************/
bool CGameScene::InsertSystemChat(const char* pszString)
{
	PLAZZ_PRINTF("ChatLayer::InsertSystemChat");
	return true;
}

/************************************************************************/
/* 进入事件                                                             */
/************************************************************************/
bool CGameScene::InsertUserEnter(const char* pszUserName)
{
	PLAZZ_PRINTF("ChatLayer::InsertUserEnter");
	//PLAZZ_PRINTF(t8("%s 进入房间\n"), pszUserName);
	return true;
}

/************************************************************************/
/* 离开事件                                                             */
/************************************************************************/
bool CGameScene::InsertUserLeave(const char* pszUserName)
{
	PLAZZ_PRINTF("ChatLayer::InsertUserLeave");
	//PLAZZ_PRINTF(t8("%s 离开房间\n"), pszUserName);
	return true;
}

/************************************************************************/
/* 断线事件                                                              */
/************************************************************************/
bool CGameScene::InsertUserOffLine(const char* pszUserName)
{
	PLAZZ_PRINTF("ChatLayer::InsertUserOffLine");
	//PLAZZ_PRINTF(t8("%s 断线\n"), pszUserName);
	return true;
}

/************************************************************************/
/* 普通消息                                                             */
/************************************************************************/
bool CGameScene::InsertNormalString(const char* pszString)
{
	PLAZZ_PRINTF("ChatLayer::InsertNormalString");
	//PLAZZ_PRINTF(t8("普通消息:%s\n"), pszString);
	return true;
}

/************************************************************************/
/* 系统消息(窗口输出)                                                    */
/************************************************************************/
bool CGameScene::InsertSystemString(const char* pszString)
{
	PLAZZ_PRINTF("ChatLayer::InsertSystemString");
	log("message is %s ", pszString);

	G_NOTIFY_D("game_event", MTData::create(GAME_EVENT_ID_SYSTEM_MSG, 0, 0, pszString, "", "", NULL));
	//PLAZZ_PRINTF(t8("系统消息:%s\n"), pszString);
	//	G_NOTIFY_D("GLAD_MSG", MTData::create(0, 0, 0, pszString, "", ""));
	return true;
}

/************************************************************************/
/* 提示消息(对话框方式??)                                                */
/************************************************************************/
int CGameScene::InsertPromptString(const char* pszString, int iButtonType)
{
	PLAZZ_PRINTF("ChatLayer::InsertPromptString");
	//PLAZZ_PRINTF(t8("提示消息:%s[%s]\n"), pszString, iButtonType == 0 ? t8("确认"):t8("确认,取消"));
	return 0;
}

/************************************************************************/
/* 公告消息(窗口输出)                                                    */
/************************************************************************/
bool CGameScene::InsertAfficheString(const char* pszString)
{
	PLAZZ_PRINTF("ChatLayer::InsertAfficheString");
	//PLAZZ_PRINTF(t8("公告消息:%s\n"), pszString);
	return true;
}

/************************************************************************/
/* 接收聊天数据                                                          */
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
/* 喜报消息                                                              */
/************************************************************************/
bool CGameScene::InsertGladString(const char * pszContent, const char * pszNickName, const char* pszNum, dword colText, dword colName, dword colNum)
{
	return true;
}

/************************************************************************/
/* 发送语音文件                                                          */
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
/* 发送文字                                                              */
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
/* 发送常用语                                                            */
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
/* 发送表情                                                                     */
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
/* 接收聊天文件                                                          */
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
/* 接收聊天文字                                                          */
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
/* 接收聊天常用                                                          */
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
/* 接收聊天表情                                                                     */
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
