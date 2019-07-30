#include <iostream>   
#include <map>
#include "cocos2d.h"
#include "Socket.h"
#include "CCLuaEngine.h"
#include "lua/LuaStackEx.h"


#include "../../tools/tools/Convert.h"

#if (CC_TARGET_PLATFORM==CC_PLATFORM_WIN32)
	#include <WinSock2.h>  
	#pragma comment (lib,"WS2_32.Lib")  
    #include <ws2tcpip.h>
	#define LHS_EAGAIN          WSAEWOULDBLOCK    
	#define LHS_EWOULDBLOCK     WSAEWOULDBLOCK  
#else
	#include <signal.h>  
	#include <sys/socket.h>  
	#include <netinet/in.h>  
	#include<netinet/tcp.h>  
	#include <netdb.h>  
	#include <errno.h>  
	#include <fcntl.h>  
	#include <unistd.h>  
	#include <sys/stat.h>  
	#include <sys/types.h>  
	#include <arpa/inet.h>
	typedef int					SOCKET;  
	#define INVALID_SOCKET		(SOCKET)(~0)  
	#define SOCKET_ERROR		(-1)  
	#define LHS_EAGAIN          EAGAIN              //此操作会令线程阻塞,但socket为不可阻塞的
	#define LHS_EWOULDBLOCK     EWOULDBLOCK         //资源暂时不可用
#endif

USING_NS_CC;
using namespace std;   

#define SOCKET_PRINTF log

//////////////////////////////////////////////////////////////////////////
static bool					__isSetSig		= true; 
static int					__SocketIndex	= 1;
static map<int, CSocket*>	__SocketMap;

//////////////////////////////////////////////////////////////////////////
void socket_close(int s)
{
#if (CC_TARGET_PLATFORM==CC_PLATFORM_WIN32)  
	shutdown(s, SD_BOTH);
	closesocket(s);
#else 
	shutdown(s, 2);
	shutdown(s,2);
	close(s);  
#endif 
}

int socket_send(int s, const char* data, int size)
{
	unsigned int flags = 0;
#if (CC_TARGET_PLATFORM==CC_PLATFORM_ANDROID)  
	flags=MSG_NOSIGNAL;  
#endif  
	return send(s, data, size, flags);
}

int socket_recv(int s, char* data, int size)
{
	unsigned int flags=0;  
#if (CC_TARGET_PLATFORM==CC_PLATFORM_ANDROID)  
	flags=MSG_NOSIGNAL;  
#endif  
	return recv(s, data, size, flags);
}

int socket_error()
{
#if (CC_TARGET_PLATFORM==CC_PLATFORM_WIN32)
	return WSAGetLastError();
#else
	return errno;
#endif
}

void socket_sleep(unsigned int delay)
{
#if (CC_TARGET_PLATFORM==CC_PLATFORM_WIN32)
	Sleep(delay);
#else
	usleep(delay*1000); 
#endif
}
//////////////////////////////////////////////////////////////////////////
class CInitSock
{
public:
	CInitSock()
	{
		#if (CC_TARGET_PLATFORM==CC_PLATFORM_WIN32)
			//WSADATA对象，用于存储Socket动态库的信息
			WSADATA wsaData;
			//调用Windows Sockets DLL
			if(WSAStartup(0x0110,&wsaData))
			{
				//初始化DLL错误，显示错误提示，程序退出
				SOCKET_PRINTF("Initialize socket failed.\n");
			}
		#endif

		#if (CC_TARGET_PLATFORM==CC_PLATFORM_IOS)
			if (__isSetSig)
			{
				__isSetSig=false;
				struct sigaction Sa;
				Sa.sa_handler = SIG_IGN;
				sigaction(SIGPIPE,&Sa,0);
			}  
		#endif 
	}

	~CInitSock()
	{
		#if (CC_TARGET_PLATFORM==CC_PLATFORM_WIN32)
			WSACleanup();
		#endif
	}
};

CInitSock __InitSock;

//////////////////////////////////////////////////////////////////////////
// 多线程共享消息队列

//////////////////////////////////////////////////////////////////////////
// 队列锁
class MTSocketQueueLocker
{  
	pthread_mutex_t* mutex; 

public:  
	MTSocketQueueLocker(pthread_mutex_t* aMutex) : mutex(aMutex)  
	{  
	    int ret = pthread_mutex_lock(mutex);  
		//log( "MTSocketQueueLocker ret is %d ", ret );
	}  
	~MTSocketQueueLocker()
	{  
		int ret = pthread_mutex_unlock(mutex);  
		//log("~MTSocketQueueLocker ret is %d ", ret);
	}  
}; // MTSocketQueueLocker

#define MTSocketQueueLock(mutex) MTSocketQueueLocker __locker__(mutex) 

//////////////////////////////////////////////////////////////////////////
// 循环消息处理
class MTSocketQueue
{
public:
	static MTSocketQueue* shared();
	static void purge();

public:
	void push(unsigned int onwer, int cmd, char* data, int dataSize);
	void post();

private:
	MTSocketQueue();
	~MTSocketQueue();

private:
	struct MTData
	{
		unsigned int	onwer;		//数据拥有者
		int				cmd;		//命令:0关闭连接 1:错误码(dataSize) 2:消息
		char*			data;
		int				dataSize;
	}; // MTData

	std::list<MTData>	mDataQueues;
	pthread_mutex_t		mMutex;

	static MTSocketQueue*	msInstance;
}; // MTSocketQueue

//////////////////////////////////////////////////////////////////////////
MTSocketQueue* MTSocketQueue::msInstance = 0;

MTSocketQueue* MTSocketQueue::shared()
{
	if (msInstance == 0)
		msInstance = new MTSocketQueue();

	return msInstance;
}

void MTSocketQueue::purge()
{
	if (msInstance)
		delete msInstance;
	msInstance = 0;
}

//////////////////////////////////////////////////////////////////////////

MTSocketQueue::MTSocketQueue()
{
	pthread_mutex_init(&mMutex, 0);  
}

MTSocketQueue::~MTSocketQueue()
{
	{
		MTSocketQueueLock(&mMutex);

		while (!mDataQueues.empty())
		{
			MTData& mtData = mDataQueues.front();
			if (mtData.data)
				delete []mtData.data;
			mDataQueues.pop_front();
		}
	}

	pthread_mutex_destroy(&mMutex);
}

void MTSocketQueue::push(unsigned int owner, int cmd, char* data, int dataSize)
{
	//log(" MTSocketQueue::push------------0 dataSize =  %d ", dataSize);

	if (__SocketMap[owner] == 0)
		return;	


	MTData mtData;
	memset(&mtData, 0, sizeof(mtData));
	mtData.onwer	= owner;
	mtData.cmd		= cmd;
	mtData.dataSize = dataSize;

	if (data != 0)
	{
		mtData.data = new char[dataSize];
		if (mtData.data == 0)
			return;
		memcpy(mtData.data, data, dataSize);
	}
	
	//log( "MTSocketQueue::push --- %d --- ", mtData.cmd );

	//socket_sleep(10);

	MTSocketQueueLock(&mMutex);

	mDataQueues.push_back(mtData);

	//log(" MTSocketQueue::push------------dataSize =  %d   mDataQueues.size() = %d owner = %d", dataSize, mDataQueues.size(), owner);
}

void MTSocketQueue::post()
{
	//log(" MTSocketQueue::post !!!!!!!!!0");
	static std::list<MTData> TempMTData;
	{
		//Sleep(50);
		MTSocketQueueLock(&mMutex);
		while (!mDataQueues.empty())
		{
			TempMTData.push_back(  mDataQueues.front() );
			mDataQueues.pop_front();
		}
	}
	//log(" MTSocketQueue::post!!!!!!!!!!");
	while (!TempMTData.empty())
	{
		const MTData& mtData = TempMTData.front();
		CSocket* owner = __SocketMap[mtData.onwer];
		if (owner)
		{
			switch (mtData.cmd)
			{
			case 0:
				owner->disconnect();
				break;
			case 1:
				owner->onSocketError(mtData.dataSize);
				break;
			case 2:
				owner->onSocketData(mtData.data, mtData.dataSize);
				break;
			}
		}

			//log(" MTSocketQueue::post end!!!!!!!!!  mDataQueues.size() = %d  dataSize = %d  owner = %d ", mDataQueues.size(), mtData.dataSize, mtData.onwer);

		if (mtData.data)
			delete[]mtData.data;
		TempMTData.pop_front();
	}
	
}

//////////////////////////////////////////////////////////////////////////

CSocket::CSocket()
	: mSocket(INVALID_SOCKET)
	, mSocketSink(0)
{
	mSocketIndex=-1;
	memset(&mThreadPid, 0, sizeof(mThreadPid));
}

CSocket::~CSocket()
{
	if (mSocketIndex >= 0)
		__SocketMap[mSocketIndex]=0;
	mSocketSink = 0;
	disconnect();
	
}

void CSocket::setSocketSink(ISocketSink* pISocketSink)
{
	if (pISocketSink == nullptr) return;

	LuaEngine * pEngine = LuaEngine::defaultEngine();
	if (pEngine) {

		LuaStackEx * luaStack = static_cast<LuaStackEx*>(pEngine->getLuaStack());
		luaStack->call_script_fun("game.setSocketSink", (CCObject *)pISocketSink);
	}
	//mSocketSink = pISocketSink;
}

bool CSocket::isAlive() const
{
	return mSocket != INVALID_SOCKET;
}

int CSocket::send(const char* data, int size)
{
	if (!isAlive())
		return -1;

	return socket_send(mSocket, data, size);
}

int CSocket::connect(const char* url, int port)
{
	disconnect();
	
	hostent* hp = gethostbyname(url);
	if (!hp)
	{
		SOCKET_PRINTF("socket gethostbyname error 1\n");
		onSocketError(socket_error());
		return -1;
	}
	sockaddr_in local;
	memset(&local, 0, sizeof(local));
	//连接的服务器IP地址
	memcpy((char*)&local.sin_addr, hp->h_addr, hp->h_length);
	
	SOCKET s;
	
	//获取网络协议
	struct addrinfo *result;
	getaddrinfo(inet_ntoa(local.sin_addr), NULL, NULL, &result);
	const struct sockaddr *sa = result->ai_addr;

	bool bRet = false;
	switch (sa->sa_family)
	{
		case AF_INET6://ipv6
		{
			void* svraddr = nullptr;
			int error = -1, svraddr_len;
			struct sockaddr_in6 svraddr_6;
			socklen_t maxlen = 128;
			char ip[128];
			strcpy(ip, inet_ntoa(local.sin_addr));
			if ((s = socket(AF_INET6, SOCK_STREAM, 0)) < 0)
			{
				break;
			}
			inet_ntop(AF_INET6, &(((struct sockaddr_in6 *)sa)->sin6_addr), ip, maxlen);
		
			memset(&svraddr_6, 0, sizeof(svraddr_6));
			svraddr_6.sin6_family = AF_INET6;
			svraddr_6.sin6_port = htons(port);
		
			if (inet_pton(AF_INET6, ip, &svraddr_6.sin6_addr) < 0)
			{
				SOCKET_PRINTF("inet_pton failed !!!");
				return -1;
			}

			mSocket = (int)s;
		
			svraddr_len = sizeof(svraddr_6);
			svraddr = &svraddr_6;
		
			freeaddrinfo(result);

			bRet = SetNonblocking(false);
			if (!bRet)
			{
				socket_close(s);
				onSocketError(1);
			}

			bRet = SetKeepLive();
			if (!bRet)
			{
				socket_close(s);
				onSocketError(1);
				return -1;
			}

			setSocketTimeout(SO_RCVTIMEO, 500);
			setSocketOptions();
		
			int nret = ::connect(s, (struct sockaddr*)svraddr, svraddr_len);
			if (nret == SOCKET_ERROR)
			{
				SOCKET_PRINTF("connect failed 3");
				int errCode = socket_error();
				socket_close(s);
				onSocketError(errCode);
				return -1;
			}
		}

		break;
		default:
		{
			//创建SOCKET
			s = socket(AF_INET, SOCK_STREAM, 0);
			
			if (s == INVALID_SOCKET)
			{
				PLAZZ_PRINTF("create socket failed 2\n");
				onSocketError(socket_error());
				return -1;
			}
			//连接的协议类型
			local.sin_family = hp->h_addrtype;
			//连接的服务器端口
			local.sin_port = htons(port);
			SOCKET_PRINTF("socket connect ip=%s port=%d socket = %u\n", url, port, s);
			
			mSocket = (int)s;
			bRet = SetNonblocking(false);
			if (!bRet)
			{
				socket_close(s);
				onSocketError(1);
				return -1;
			}

			bRet = SetKeepLive();
			if (!bRet)
			{
				socket_close(s);
				onSocketError(1);
				return -1;
			}
			setSocketTimeout(SO_RCVTIMEO, 500);
			setSocketOptions();
			//连接服务器
			if (::connect(s, (const sockaddr*)&local, sizeof(local)) < 0)
			{
				SOCKET_PRINTF("connect failed 3");
				int errCode = socket_error();
				socket_close(s);
				onSocketError(errCode);
				return -1;
			}
		}
		break;
	}

	bRet = SetNonblocking(true);
	if (!bRet)
	{
		socket_close(s);
		onSocketError(1);
		return -1;
	}

	bRet = SetLinger(false, 0);
	if (!bRet)
	{
		socket_close(s);
		onSocketError(1);
		return -1;
	}
	bRet = SetReuse(true);
	if (!bRet)
	{
		socket_close(s);
		onSocketError(1);
		return -1;
	}

	SOCKET_PRINTF("connect ok.\n");

	if (mSocketIndex == -1)
	{
		mSocketIndex = __SocketIndex++;
		__SocketMap[mSocketIndex]=this;
	}
	
	mSocket	= (int)s;
	
	// 创建线程
	pthread_attr_t attr;
	pthread_attr_init (&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
	int ret = pthread_create(&mThreadPid, &attr, recv_thread, &mSocketIndex);
	pthread_attr_destroy (&attr);
	//SOCKET_PRINTF("connect 1.\n");
	
	if (ret != 0)
	{
		SOCKET_PRINTF("connect error 4\n");
		socket_close(s);
		mSocket=INVALID_SOCKET;
		__SocketMap[mSocketIndex]=0;
		mSocketIndex=-1;
		onSocketError(10000 + ret);
		return -1;
	}
	
	//SOCKET_PRINTF("connect 3.\n");
	onSocketLink();
	SOCKET_PRINTF("connect success 5\n");
	return 0;
}

int CSocket::setSocketTimeout(int aType, int aTimeout)
{
#ifdef _WIN32
	dword timeout = (dword)aTimeout;
#else
	struct timeval timeout;
	timeout.tv_sec = aTimeout / 1000;
	timeout.tv_usec = (aTimeout % 1000) * 1000;
#endif
	return setsockopt(mSocket, SOL_SOCKET, aType, (const char *)&timeout, sizeof(timeout));
}

void CSocket::setSocketOptions()
{
	int rc = 0;
	// turn off the Nagle algorithm as this socket is used for small requests which are
	// subject to delays otherwise. On Windows this can introduce delays of up to 200ms
	// for a remote server (local servers are on the same TCP stack have no delay).
	int nodelay = 1;
	rc = setsockopt(mSocket, IPPROTO_TCP, TCP_NODELAY, (const char*)&nodelay, sizeof(nodelay));
	if (rc != 0)
	{
	}

	rc = setSocketTimeout(SO_RCVTIMEO, 2000);
	if (rc != 0) {
	}

	rc = setSocketTimeout(SO_SNDTIMEO, 2000);
	if (rc != 0) {
	}
}

bool CSocket::SetNonblocking(bool bSet)
{
	//_AUTOMUTEX(&m_mutex);
#ifdef _WIN32
	u_long nonBlock = bSet;
	if (ioctlsocket(mSocket, FIONBIO, &nonBlock) == SOCKET_ERROR)
	{
		return false;
	}
#else
	if (bSet)
	{
		if (fcntl(mSocket, F_SETFL, fcntl(mSocket, F_GETFD, 0) | O_NONBLOCK) == -1)
		{
			return false;
		}
	}
	else
	{
		if (fcntl(mSocket, F_SETFL, fcntl(mSocket, F_GETFD, 0)&~O_NONBLOCK) == -1)
		{
			return false;
		}
	}

#endif
	return true;
}


bool CSocket::SetKeepLive()
{
	int     optval = 1;
	if (setsockopt(mSocket, SOL_SOCKET, SO_KEEPALIVE, (char *)&optval, sizeof(optval)))
	{
		return false;
	}

	return true;
}

bool CSocket::SetLinger(bool bUse, dword time)
{
	linger lg;
	lg.l_onoff = bUse;
	lg.l_linger = time;
	if (0 != setsockopt(mSocket, SOL_SOCKET, SO_LINGER, (const char*)&lg, sizeof(lg)))
	{
		return false;
	}
	return true;
}

bool CSocket::SetReuse(bool bUse)
{
	int bReuseaddr = bUse;
	if (setsockopt(mSocket, SOL_SOCKET, SO_REUSEADDR,
		(const char*)&bReuseaddr, sizeof(int)) != 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void CSocket::disconnect()
{
	if (!isAlive())
		return;
    socket_close(mSocket);
	mSocket = INVALID_SOCKET;
	void* iresult = nullptr;
	pthread_join(mThreadPid, &iresult);
	memset(&mThreadPid, 0, sizeof(mThreadPid));

	if (mSocketIndex > 0)
	{
		__SocketMap[mSocketIndex] = 0;
		mSocketIndex = -1;
	}

	onSocketShut();
}

//////////////////////////////////////////////////////////////////////////
// 辅助函数
void CSocket::onSocketLink()
{
	if (mSocketSink)
		mSocketSink->onSocketLink();
}

void CSocket::onSocketShut()
{
	SOCKET_PRINTF("CSocket::onSocketShut %s.\n", mSocketSink == 0 ? "null" : "no null");
	if (mSocketSink)
		mSocketSink->onSocketShut();
}

void CSocket::onSocketError(int errorCode)
{
	if (mSocketSink)
		mSocketSink->onSocketError(errorCode);
}

void CSocket::onSocketData(void* data, int dataSize)
{
	if (mSocketSink)
		mSocketSink->onSocketData(data, dataSize);
}

//////////////////////////////////////////////////////////////////////////
// 客户端处理线程
void* CSocket::recv_thread(void* p)
{
	const int MAX_BUF = 16384;


	int socketIndex = *(int*)p;
	char dataBuffer[MAX_BUF]={0};

	while (__SocketMap[socketIndex] && __SocketMap[socketIndex]->isAlive())
	{
		int dataSize = socket_recv(__SocketMap[socketIndex]->mSocket, dataBuffer, MAX_BUF);

		if(dataSize==SOCKET_ERROR)  
		{  
			int errCode =socket_error();  

			if(errCode==LHS_EWOULDBLOCK)  
			{  
				socket_sleep(20);
				continue; 
			} 
			else if(errCode==LHS_EAGAIN)
			{
				continue;
			}
			

		//	SOCKET_PRINTF("recv error:%d\n", errCode);

			if (errCode == 10004) // 中断连接
				break;

			if (__SocketMap[socketIndex] && MTSocketQueue::shared())
				MTSocketQueue::shared()->push(socketIndex, 1, 0, errCode);
			break;
		}

		if (dataSize == 0)
		{
		//	log("recv_thread dataSize == 0, break while.");
			break;
		}


		if (__SocketMap[socketIndex] && MTSocketQueue::shared()){
			MTSocketQueue::shared()->push(socketIndex, 2, dataBuffer, dataSize);
		//	log("recv_thread   dataSize == %d", dataSize );
		}
	}


	if (__SocketMap[socketIndex] && MTSocketQueue::shared()){
	//	log( "recv_thread   push 0, close socket." );
		MTSocketQueue::shared()->push(socketIndex, 0, 0, 0);
	}
	return 0;
}

// 分发数据队列
void CSocket::post()
{
	if (MTSocketQueue::shared())
		MTSocketQueue::shared()->post();
}

void CSocket::purge()
{
	MTSocketQueue::purge();
}
