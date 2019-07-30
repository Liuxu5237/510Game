#ifndef _types_H_
#define _types_H_
#include "cocos2d.h"

#ifdef CC_TARGET_PLATFORM 

#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID||CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#define _UNICODE
#endif

#endif // CC_TARGET_PLATFORM 


//////////////////////////////////////////////////////////////
#include <assert.h>
#include <stdio.h>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <deque>
#include <iomanip>
#include <list>
#include <sstream>

#include <stdlib.h>

//#include <basetyps.h>
#include <assert.h>
//#include <tchar.h>

#ifndef ASSERT
#define ASSERT(f) 
#endif

///////////////////////////////////////////////////////////////////////////////////////

typedef signed char			int8;
typedef signed short		int16;
typedef signed int			int32;
typedef long long			int64;

typedef unsigned char		uint8;
typedef unsigned char		byte;
typedef unsigned char		BYTE;

typedef unsigned int		uint;
typedef unsigned int		UINT;
typedef unsigned int		uint32;

typedef unsigned short		word;
typedef unsigned short		uint16;
typedef unsigned short		WORD;

typedef unsigned int		dword;
//typedef unsigned int		DWORD;

typedef long long			longlong;
typedef long long			LONGLONG;
typedef unsigned long long	uint64;
typedef longlong			SCORE;


;
typedef BYTE *				LPBYTE;


#define TRUE				1
#define FALSE				0

typedef wchar_t				wchar;


#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID||CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	#ifdef  _UNICODE
		typedef std::wstring	tstring;
		typedef wchar			tchar;
		typedef unsigned short	TCHAR;
	#else
		typedef std::string	tstring;
		typedef char			tchar;
		typedef unsigned short			TCHAR;
	#endif
#else
	#ifdef  _UNICODE
		typedef std::wstring	tstring;
		typedef wchar			tchar;
		typedef wchar			TCHAR;
	#else
		typedef std::string		tstring;
		typedef char			tchar;
		typedef wchar			TCHAR;
	#endif
#endif

#ifdef _WIN32
#define LLSTRING "%I64d"
#else
#define LLSTRING "%lld"
#endif

//////////////////////////////////////////////////////////////////////////
// 功能函数
inline const char* toString(int value)
{
	static std::string str;
	str.resize(128, '\0');
	sprintf(&str[0], "%d", value);
	return str.c_str();
}

inline const char* toString(int64 value)
{
	static std::string str;
	str.resize(128, '\0');
	sprintf(&str[0], LLSTRING, value);
	return str.c_str();
}

template<typename T>
inline T tmin(const T& a, const T& b)
{
	return a < b ? a : b;
}

template<typename T>
inline T tmax(const T& a, const T& b)
{
	return a < b ? b : a;
}

//////////////////////////////////////////////////////////////////////////
// 宏定义
#define countarray(ary)		(sizeof(ary)/sizeof(ary[0]))
#define zeromemory(x, size)	memset(x, 0, size)


#define CC_SET_AND_GET(varType, varName, funName)					\
public: varType varName;											\
public: varType get##funName(void) const { return varName; }		\
public: void set##funName(varType var){ varName = var; }

#define CC_SET_AND_GET_REF(varType, varName, funName)					\
public: varType varName;											\
public: const varType & get##funName(void) const { return varName; }		\
public: void set##funName(const varType & var){ varName = var; }

#define CC_SET_AND_GET_POINT(varType, varName, funName)					\
public: varType varName;											\
public:  varType * get##funName(void) { return &varName; }		

#define CC_SET_AND_GET_ARRAY(varType, varLen, varName, funName)		\
public:																\
	varType varName[varLen];									\
public: const varType * get##funName(void) const { return varName; }		\
public: void set##funName(const varType * varParam, int lenParam)			\
{\
	int len = lenParam;	\
if (len > varLen) \
{ \
	len = varLen; \
}\
	memcpy(varName, varParam, len * sizeof(varType)); \
}

#define CC_SET_AND_GET_CHAR_ARRAY(varLen, varName, funName)		\
public:																\
	char varName[varLen];									\
public: const char * get##funName(void) const { return varName; }		\
public: void set##funName(const std::string & strValue, int lenParam)			\
{\
	zeromemory(varName, varLen);	\
	int len = strValue.length();	\
if (len > lenParam) \
{ \
	len = lenParam; \
}\
	strncpy(varName, strValue.c_str(), len);	\
}

///////////////////////////////////////////////////////////////////////////////////////

#endif // _types_H_