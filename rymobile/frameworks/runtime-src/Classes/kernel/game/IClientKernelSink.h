#ifndef _IClientKernelSink_H_
#define _IClientKernelSink_H_

#include "platform/df/types.h"

class IClientUserItem;

class tagMatchInfo;
class tagMatchWaitTip;
class tagMatchResult;

class IClientKernelSink
{
public:
	virtual ~IClientKernelSink(){};

	//控制接口
public:
	//启动游戏
	virtual bool SetupGameClient()=0;
	//重置游戏
	virtual void ResetGameClient()=0;
	//关闭游戏
	virtual void CloseGameClient()=0;

	//框架事件
public:
	//系统滚动消息
	virtual bool OnGFTableMessage(const char* szMessage)=0;
	
	//游戏事件
public:
	//旁观消息
	virtual bool OnEventLookonMode(void* data, int dataSize)=0;
	//场景消息
	virtual bool OnEventSceneMessage(BYTE cbGameStatus, bool bLookonUser, void* data, int dataSize)=0;
	//场景消息
	virtual bool OnEventGameMessage(int sub, void* data, int dataSize)=0;
	//用户事件
public:
	//用户进入
	virtual void OnEventUserEnter(IClientUserItem * pIClientUserItem, bool bLookonUser)=0;
	//用户离开
	virtual void OnEventUserLeave(IClientUserItem * pIClientUserItem, bool bLookonUser)=0;
	//用户积分
	virtual void OnEventUserScore(IClientUserItem * pIClientUserItem, bool bLookonUser)=0;
	//用户状态
	virtual void OnEventUserStatus(IClientUserItem * pIClientUserItem, bool bLookonUser)=0;
	//用户属性
	virtual void OnEventUserAttrib(IClientUserItem * pIClientUserItem, bool bLookonUser)=0;
	//用户头像
	virtual void OnEventCustomFace(IClientUserItem * pIClientUserItem, bool bLookonUser)=0;

public:
	// 重新进入游戏
	virtual void OnReEnterGame() = 0;
};

#endif // _IClientKernelSink_H_