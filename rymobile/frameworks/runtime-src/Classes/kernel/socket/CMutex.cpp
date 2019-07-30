
#include "CMutex.h"
#include <cassert>

CCMutex::CCMutex(void)
{
	bool ret = Create();
	assert(ret == true);
}

CCMutex::~CCMutex(void)
{
	Close();
}

//
bool CCMutex::Create(const char * name)
{
#ifdef _WIN32

	WCHAR wszClassName[256];
	memset(wszClassName, 0, sizeof(wszClassName));
	if (name != NULL)
	{
		MultiByteToWideChar(CP_ACP, 0, name, strlen(name) + 1, wszClassName,
			sizeof(wszClassName)/sizeof(wszClassName[0])); 
	}
	m_handle = CreateMutex(0, false, wszClassName);
	return m_handle  != 0;
#else
        pthread_mutexattr_t mutexattr;
        pthread_mutexattr_init(&mutexattr);
        pthread_mutexattr_settype(&mutexattr, PTHREAD_MUTEX_RECURSIVE);
        bool   ret =  pthread_mutex_init(&m_handle, &mutexattr);
        return ret == 0;
#endif
	
}

//��
bool CCMutex::Lock()
{
#ifdef _WIN32
	DWORD ret = WaitForSingleObject(m_handle, INFINITE);
	return  ret != WAIT_FAILED;

#else
        return pthread_mutex_lock(&m_handle) == 0;
#endif

}

//�ͷ�
bool CCMutex::UnLock()
{
#ifdef _WIN32
	return ReleaseMutex(m_handle)  != WAIT_FAILED;

#else

        return pthread_mutex_unlock(&m_handle) == 0;
#endif	
}

//�ر�
void CCMutex::Close()
{
#ifdef _WIN32
	CloseHandle(m_handle);

#else
        pthread_mutex_destroy(&m_handle);
#endif
}





