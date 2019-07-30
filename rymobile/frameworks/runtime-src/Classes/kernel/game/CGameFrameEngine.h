#ifndef _I_GAME_FRAME_ENGINE_H_
#define	_I_GAME_FRAME_ENGINE_H_

#include "IClientKernelSink.h"


class CGameScene;
class IGameFrameEngineSink;

class  CGameFrameEngine : public IClientKernelSink
{
protected:
	// 单体实例
	static CGameFrameEngine * ms_pkInstance;

public:
	// 单体函数
	static CGameFrameEngine * Get()
	{
		if (ms_pkInstance == nullptr)
		{
			ms_pkInstance = new CGameFrameEngine;
		}
		return ms_pkInstance;
	}

	static void Destroy()
	{
		if (ms_pkInstance)
		{
			delete ms_pkInstance;
			ms_pkInstance = NULL;
		}
	}

protected:
	// 构造函数
	CGameFrameEngine();

	// 析构函数
	virtual ~CGameFrameEngine();

public:
	// 设置c++游戏框架引擎接口
	void SetGameFrameEngineSink(IGameFrameEngineSink * pGameFrameEngineSink)
	{ 
		m_gameFrameEngineSink = pGameFrameEngineSink; 
	}

	IGameFrameEngineSink * GetGameFrameEngineSink()
	{
		return m_gameFrameEngineSink;
	}

	void Clear();
	

	
public:

	//启动游戏
	virtual bool SetupGameClient();

	//重置游戏
	virtual void ResetGameClient();

	//关闭游戏
	virtual void CloseGameClient();

	//游戏事件
public:

	//旁观消息
	virtual bool OnEventLookonMode(void* data, int dataSize);

	//场景消息
	virtual bool OnEventSceneMessage(BYTE cbGameStatus, bool bLookonUser, void* data, int dataSize);

	//场景消息
	virtual bool OnEventGameMessage(int sub, void * data, int dataSize);

	//框架事件
public:
	//系统滚动消息
	virtual bool OnGFTableMessage(const char* szMessage);

	//等待提示
	virtual bool OnGFWaitTips(bool bWait);

	//用户事件
public:

	//用户进入
	virtual void OnEventUserEnter(IClientUserItem * pIClientUserItem, bool bLookonUser);

	//用户离开
	virtual void OnEventUserLeave(IClientUserItem * pIClientUserItem, bool bLookonUser);

	//用户积分
	virtual void OnEventUserScore(IClientUserItem * pIClientUserItem, bool bLookonUser);

	//用户状态
	virtual void OnEventUserStatus(IClientUserItem * pIClientUserItem, bool bLookonUser);

	//用户属性
	virtual void OnEventUserAttrib(IClientUserItem * pIClientUserItem, bool bLookonUser);

	//用户头像
	virtual void OnEventCustomFace(IClientUserItem * pIClientUserItem, bool bLookonUser);

public:

	// 接收聊天数据
	bool RecvTalk(void* data,int dataSize);

public:

	// 重新进入游戏
	virtual void OnReEnterGame();

protected:

	// 游戏场景渲染框架
	CGameScene *	m_gameScene;

protected:
	// c++游戏框架引起接口
	IGameFrameEngineSink * m_gameFrameEngineSink;
};


#endif // !_GAME_FRAME_ENGINE_H_
