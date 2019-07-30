//{future header message}
#ifndef __FvSingleton_H__
#define __FvSingleton_H__
#include "cocos2d.h"

template <class T>
class FvSingleton
{
protected:
	static T *ms_pkInstance;

public:
	FvSingleton()
	{
		CCASSERT(ms_pkInstance == NULL,"");
		ms_pkInstance = static_cast< T * >( this );
	}

	~FvSingleton()
	{
		ms_pkInstance = 0;
	}

	static T &Instance()
	{
		if (ms_pkInstance == nullptr)
		{
			new T;
		}
		return *ms_pkInstance;
	}

	static T *pInstance()
	{
		return ms_pkInstance;
	}

	//static void destory()
	//{
	//	if(ms_pkInstance)
	//	{
	//		delete ms_pkInstance;
	//		ms_pkInstance = 0;
	//	}
	//}
};

#define FV_SINGLETON_STORAGE( TYPE )						\
template <>													\
TYPE * FvSingleton< TYPE >::ms_pkInstance = 0;			\


#define FV_SINGLETON_NEW( TYPE )						\
if(TYPE::pInstance() == NULL)							\
{														\
	new TYPE();											\
}														\

#endif // __FvSingleton_H__
