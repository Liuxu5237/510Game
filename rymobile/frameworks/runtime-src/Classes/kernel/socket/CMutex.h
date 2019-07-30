
#ifndef CCMUTEX_H_
#define CCMUTEX_H_

#ifdef _WIN32
#include <winsock2.h> 
#include <Windows.h>
#else
#include <pthread.h>
#include <signal.h>
#endif

class CCMutex
{
private:
    #ifdef _WIN32
		HANDLE	m_handle;
    #else
        pthread_mutex_t     m_handle;
    #endif
public:
	CCMutex(void);
	~CCMutex(void);
public:
		
	//上锁
	bool Lock();
	//解锁
	bool UnLock();

private:
	//建立
	bool Create(const char * name = 0);
	//关闭
	void Close();
};


class  CCAutoMutex
{
	CCMutex*   m_pMutex;
public:
	CCAutoMutex(CCMutex* t)
	{
		m_pMutex = t;
		m_pMutex->Lock();
	}
	~CCAutoMutex()
	{
		m_pMutex->UnLock();
	}

};

#define  _AUTOMUTEX(t)   CCAutoMutex _mutex(t)
#endif


















