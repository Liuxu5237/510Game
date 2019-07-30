#ifndef _Socket_H_
#define _Socket_H_

#include "Platform/CCPlatformConfig.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_LINUX
#include "pthread.h"
#else
#include "pthread.h"

#endif

//#include "CMutex.h"
#include <list>
#include "../../platform/PlatformHeader.h"
#include "kernel/network/ISocketSink.h"

class CSocket
{
public:
	CSocket();
	~CSocket();
	void setSocketSink(ISocketSink* pISocketSink);
	bool isAlive() const;
	int  connect(const char* url, int port);
	void disconnect();
	int send(const char* data, int size);

	//////////////////////////////////////////////////////////////////////////
	// 辅助函数
private:
	void onSocketLink();
	void onSocketShut();
	void onSocketError(int errorCode);
	void onSocketData(void* data, int dataSize);

	int setSocketTimeout(int aType, int aTimeout);
	void setSocketOptions();
	bool SetNonblocking(bool bSet);
	bool SetLinger(bool bUse, dword time);
	bool SetReuse(bool bUse);
	bool SetKeepLive();
	//////////////////////////////////////////////////////////////////////////
	// 处理线程
private:
	// 接收数据线程
	static void* recv_thread(void* p);
public:
	// 分发数据队列
	static void post();
	static void purge();

private:
	int				mSocket;
	ISocketSink*	mSocketSink;
	int				mSocketIndex;
	pthread_t		mThreadPid;
	//互斥锁
	//CCMutex			m_mutex;
	friend class MTSocketQueue;
};

#endif // _Socket_H_
