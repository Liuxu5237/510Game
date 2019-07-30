#ifndef I_GAME_SCENE_SINK_H__
#define I_GAME_SCENE_SINK_H__

#include "cocos2d.h"
#include "platform/df/types.h"
USING_NS_CC;

class CGameScene;
class IClientUserItem;

class IGameSceneSink
{
public:
	IGameSceneSink()
	{
		m_pGameScene = NULL;
        CCLOG("--1-- IGameSceneSink() p=%p",this);
	}
	virtual ~IGameSceneSink(){};

public:
	// 初始化函数
	virtual bool init(CGameScene * pGameScene)
	{
		m_pGameScene = pGameScene;
        CCLOG("--1-- init(CGameScene * pGameScene)=%p",m_pGameScene);
		return true;
	}

public:

	//启动游戏
	virtual bool SetupGameClient() = 0;

	//重置游戏
	virtual void ResetGameClient() = 0;

	//关闭游戏
	virtual void CloseGameClient() = 0;

public:

	// 触摸开始
	virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent){ return true; }

	// 触摸移动
	virtual void ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent){}

	// 触摸结束
	virtual void ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent){}


public:
	// 处理场景消息
	virtual bool OnEventSceneMessage(BYTE cbGameStatus, bool bLookonUser, void* data, int dataSize)
	{
		return true;
	}

	//游戏消息
	virtual bool OnEventGameMessage(int sub, void* data, int dataSize)
	{
		return true;
	}

public:

	//进入游戏场景
	virtual void onEnterTransitionDidFinish() {}

	//心跳函数
	virtual void update(float delta){}
public:

	// 游戏暂停
	virtual void OnGameEnterBackground() = 0;

	// 游戏恢复
	virtual void OnGameEnterForeground() = 0;

	// 重连进入接口
	virtual void OnReconnectResumeGame() = 0;

	// 检测到网络断开
	virtual void OnDetectNetDown() = 0;

	// 网络已经可用，进入到断线重连状态
	virtual void OnEnterReconnectState() = 0;

public:

	//用户进入
	virtual void OnEventUserEnter(IClientUserItem * pIClientUserItem, bool bLookonUser) = 0;

	//用户离开
	virtual void OnEventUserLeave(IClientUserItem * pIClientUserItem, bool bLookonUser) = 0;

	//用户离开
	virtual void OnEventUserStatus(IClientUserItem * pIClientUserItem, bool bLookonUser) = 0;

	//用户积分
	virtual void OnEventUserScore(IClientUserItem * pIClientUserItem, bool bLookonUser) = 0;

	//用户属性
	virtual void OnEventUserAttrib(IClientUserItem * pIClientUserItem, bool bLookonUser) = 0;

public:

	//等待分组
	virtual void OnSubWaitBack() = 0;


protected:

	CGameScene * m_pGameScene;
};

#endif
