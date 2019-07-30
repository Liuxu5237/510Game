#ifndef _Dntg_ClientKernelSink_H_
#define _Dntg_ClientKernelSink_H_

#include "cocos2d.h"

#include "kernel/game/IGameFrameEngineSink.h"


namespace Dntg
{
	//游戏引擎
	class DntgClientKernelSink : public IGameFrameEngineSink, public cocos2d::Ref
	{
	protected:
		// 单体实例
		static DntgClientKernelSink * ms_pkInstance;

	public:

		// 单体函数
		static DntgClientKernelSink * Get()
		{
			if (ms_pkInstance == nullptr)
			{
				ms_pkInstance = new DntgClientKernelSink;
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

	private:
		//构造函数
		DntgClientKernelSink();

		//析构函数
		virtual ~DntgClientKernelSink();

	public:

		//启动游戏
		virtual bool SetupGameClient();

		//重置游戏
		virtual void ResetGameClient();

		//关闭游戏
		virtual void CloseGameClient();

		//游戏事件
	public:
		
		//场景消息
		virtual bool OnEventSceneMessage(byte cbGameStatus, bool bLookonUser, void* data, int dataSize);
		
		//游戏消息
		virtual bool OnEventGameMessage(int sub, void* data, int dataSize);

		//旁观消息
		virtual bool OnEventLookonMode(void* data, int dataSize);
	};
}


#endif // _ClientKernelSink_H_