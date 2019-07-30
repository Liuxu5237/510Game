#ifndef I_GAME_FRAME_ENGINE_SINK_H__
#define I_GAME_FRAME_ENGINE_SINK_H__

#include "IClientKernelSink.h"
#include "IGameSceneSink.h"

class IGameFrameEngineSink
{
public:
	IGameFrameEngineSink()
	{
		m_gameSceneSink = NULL;
        CCLOG("--1-- IGameFrameEngineSink()=%p",this);
	}
	virtual ~IGameFrameEngineSink(){
		
		if (m_gameSceneSink)
		{
			delete m_gameSceneSink;
			m_gameSceneSink = NULL;
		}
	};

public:
	void SetGameSceneSink(IGameSceneSink * pGameSceneSink){
        CCLOG("--1-- SetGameSceneSink last=%p currr=%p",m_gameSceneSink, pGameSceneSink);
		m_gameSceneSink = pGameSceneSink;
	}

	IGameSceneSink * GetGameSceneSink()
	{
		return m_gameSceneSink;
	}
	//控制接口
public:

	//启动游戏
	virtual bool SetupGameClient() = 0;

	//重置游戏
	virtual void ResetGameClient() = 0;

	//关闭游戏
	virtual void CloseGameClient() = 0;

	//游戏事件
public:

	//旁观消息
	virtual bool OnEventLookonMode(void* data, int dataSize) = 0;

	//场景消息
	virtual bool OnEventSceneMessage(BYTE cbGameStatus, bool bLookonUser, void * data, int dataSize) = 0;

	//场景消息
	virtual bool OnEventGameMessage(int sub, void* data, int dataSize) = 0;

	//框架事件
public:

	//系统滚动消息
	virtual bool OnGFTableMessage(const char* szMessage){ return true; }

	//等待提示
	virtual bool OnGFWaitTips(bool bWait){ return true; }

	//用户事件
public:

	//用户进入
	virtual void OnEventUserEnter(IClientUserItem * pIClientUserItem, bool bLookonUser){}

	//用户离开
	virtual void OnEventUserLeave(IClientUserItem * pIClientUserItem, bool bLookonUser){}

	//用户积分
	virtual void OnEventUserScore(IClientUserItem * pIClientUserItem, bool bLookonUser){}

	//用户状态
	virtual void OnEventUserStatus(IClientUserItem * pIClientUserItem, bool bLookonUser){}

	//用户属性
	virtual void OnEventUserAttrib(IClientUserItem * pIClientUserItem, bool bLookonUser){}

	//用户头像
	virtual void OnEventCustomFace(IClientUserItem * pIClientUserItem, bool bLookonUser){}

protected:

	IGameSceneSink * m_gameSceneSink;
};

#endif
