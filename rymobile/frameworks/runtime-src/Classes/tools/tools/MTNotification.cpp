#include "MTNotification.h"

#include "../ViewHeader.h"

#include "../tools/StringData.h"
#include "../tools/gPlatform.h"

#include "../../kernel/socket/Socket.h"
#include "../../platform/data/GlobalUserInfo.h"
#include "lua/LuaStackEx.h"
#include "CCLuaEngine.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_LINUX
#include "pthread.h"
#endif

#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
#include "pthread.h"
#endif

USING_NS_CC;

//////////////////////////////////////////////////////////////////////////
// 多线程共享消息队列

//////////////////////////////////////////////////////////////////////////
// 队列锁
class MTQueueLocker  
{  
	pthread_mutex_t* mutex;  

public:  
	MTQueueLocker(pthread_mutex_t* aMutex) : mutex(aMutex)  
	{  
		pthread_mutex_lock(mutex);  
	}  
	~MTQueueLocker()
	{  
		pthread_mutex_unlock(mutex);  
	}  
}; // MTQueueLocker

#define MTQueueLock(mutex) MTQueueLocker __locker__(mutex) 

//////////////////////////////////////////////////////////////////////////

MyNotification * MyNotification::g_instance;


/************************************************************************/
/* 构造函数                                                             */
/************************************************************************/
MyNotification::MyNotification()
{
	
}

/************************************************************************/
/* 析构函数                                                             */
/************************************************************************/
MyNotification::~MyNotification()
{
	if (g_instance != nullptr)
		delete g_instance;
}

/************************************************************************/
/* 得到通知管理器实例                                                   */
/************************************************************************/
MyNotification * MyNotification::getInstance(){
	
	if (g_instance){
		return g_instance;
	}

	g_instance = new MyNotification();
	g_instance->initMTNotificationImp();
	return g_instance;
}

/************************************************************************/
/* 初始化通知接口                                                       */
/************************************************************************/
void MyNotification::initMTNotificationImp()
{

}

/************************************************************************/
/* 注册通知的回调函数                                                   */
/************************************************************************/
bool MyNotification::registerEvent(const std::string &name_, const std::function<void(EventCustom*)>& callback)
{
	Director::getInstance()->getEventDispatcher()->addCustomEventListener(name_, callback);
	return true;
}

/************************************************************************/
/* 注册lua回调                                                           */
/************************************************************************/
bool MyNotification::registerLuaEventCallBack(const std::string &name_, LUA_FUNCTION luaCallBack)
{
	auto func = [luaCallBack](EventCustom* eventCustom){
		auto engine = LuaEngine::getInstance();
		LuaStackEx * luaStack = static_cast<LuaStackEx*>(engine->getLuaStack());
		if (eventCustom->getUserData())
		{
			luaStack->call_script_int_fun(luaCallBack, (cocos2d::Ref *)(eventCustom->getUserData()));
		}
		else
		{
			luaStack->call_script_int_fun(luaCallBack);
		}
	};

	Director::getInstance()->getEventDispatcher()->addCustomEventListener(name_, func);
	return true;
}

/************************************************************************/
/* 注销通知                                                             */
/************************************************************************/
bool MyNotification::unRegisterEventListener(const std::string& customEventName)
{
	Director::getInstance()->getEventDispatcher()->removeCustomEventListeners(customEventName);

	return true;
}

/************************************************************************/
/* 分发事件                                                             */
/************************************************************************/
void MyNotification::dispatchEvent(const std::string &name, MTData * data)
{
	Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(name, data);
	return;
}

/************************************************************************/
/*                                                                      */
/************************************************************************/
void MyNotification::post(float dt)
{
	CSocket::post();
}

