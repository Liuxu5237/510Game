#include "DntgClientKernelSink.h"
#include "DntgGameScene.h"


USING_NS_CC;
using namespace Dntg;

DntgClientKernelSink * DntgClientKernelSink::ms_pkInstance = NULL;

/************************************************************************/
/* 构造函数                                                             */
/************************************************************************/
DntgClientKernelSink::DntgClientKernelSink(void)
{
	this->SetGameSceneSink(new CGameSceneEngine());
}

/************************************************************************/
/* 析构函数                                                             */
/************************************************************************/
DntgClientKernelSink::~DntgClientKernelSink(void)
{
	
}

/************************************************************************/
/* 启动游戏                                                             */
/************************************************************************/
bool DntgClientKernelSink::SetupGameClient()
{
	return true;
}

/************************************************************************/
/* 重置游戏                                                             */
/************************************************************************/
void DntgClientKernelSink::ResetGameClient()
{
	
}

/************************************************************************/
/* 关闭游戏                                                             */
/************************************************************************/
void DntgClientKernelSink::CloseGameClient()
{
	
}

/************************************************************************/
/* 场景消息                                                             */
/************************************************************************/
bool DntgClientKernelSink::OnEventSceneMessage(byte cbGameStatus, bool bLookonUser, void* data, int dataSize)
{
	return false;
}

/************************************************************************/
/* 游戏消息                                                             */
/************************************************************************/
bool DntgClientKernelSink::OnEventGameMessage(int sub, void* data, int dataSize)
{
	return false;
}

/************************************************************************/
/* 旁观消息                                                              */
/************************************************************************/
bool DntgClientKernelSink::OnEventLookonMode(void* data, int dataSize)
{
	return true;
}




