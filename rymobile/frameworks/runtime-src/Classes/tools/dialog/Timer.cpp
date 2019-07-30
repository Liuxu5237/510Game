#include "cocos2d.h"

#include "Timer.h"

#if (CC_TARGET_PLATFORM==CC_PLATFORM_WIN32)
#include <Windows.h>
#else

#endif	


SCORE CoTimer::s_llGameWorldServer = 0;
SCORE CoTimer::s_llRecvGameWorldSecond = 0;

USING_NS_CC;
#if (CC_TARGET_PLATFORM!=CC_PLATFORM_WIN32)

//#include <sys/time.h>
#include <unistd.h>
#include <sys/times.h>

unsigned int GetTickCount()
{
	static unsigned int s_mode = 0;
	static unsigned int s_tt = 0;
	if (s_mode == 0)
	{
		unsigned int tps = (unsigned int)sysconf(_SC_CLK_TCK);
		if (1000 % tps == 0)
		{
			s_tt = 1000 / tps;
			s_mode = 1;
		}
		else
		{
			s_tt = tps;
			s_mode = 2;
		}
	}
	struct tms t;
	const unsigned int dw = (unsigned int)times(&t);
	return (s_mode == 1 ? (dw * s_tt) : (unsigned int)(dw * 1000LL / s_tt));
}
#endif	
//////////////////////////////////////////////////////////////////////////
unsigned int CoTimer::getCurrentTime()
{
#if (CC_TARGET_PLATFORM==CC_PLATFORM_WIN32)
	return GetTickCount();
#else
	return GetTickCount();
#endif
}


// 设置游戏世界事件
void CoTimer::setGameWorldTime(SCORE timesec)
{
	s_llGameWorldServer = timesec;

	struct timeval tv;
	memset(&tv, 0, sizeof(tv));
	gettimeofday(&tv, NULL);

	s_llRecvGameWorldSecond = tv.tv_sec;
}

/************************************************************************/
/* 得到游戏世界的时间                                                    */
/************************************************************************/
LONGLONG CoTimer::getGameWorldTime()
{
	struct timeval tv;
	memset(&tv, 0, sizeof(tv));
	gettimeofday(&tv, NULL);

	SCORE nowLocal = tv.tv_sec;
	SCORE nowServer = s_llGameWorldServer + nowLocal - s_llRecvGameWorldSecond;

	return nowServer;
}


/************************************************************************/
/* 得到当前游戏世界时间字符串                                             */
/************************************************************************/
const std::string CoTimer::getGameWorldTimeStr()
{
	struct timeval tv;
	memset(&tv, 0, sizeof(tv));
	gettimeofday(&tv, NULL);

	SCORE nowLocal = tv.tv_sec;
	SCORE nowServer = s_llGameWorldServer + nowLocal - s_llRecvGameWorldSecond;

	time_t _time = nowServer;
	struct tm* ptime;
	ptime = localtime(&_time);

	if (ptime)
	{
		return cocos2d::__String::createWithFormat("%02d:%02d", ptime->tm_hour, ptime->tm_min)->getCString();
	}
	else
	{
		return "";
	}
}

/************************************************************************/
/* 得到系统毫秒事件                                                      */
/************************************************************************/
SCORE CoTimer::getsystemtomillisecond()
{
	struct timeval tv;
	memset(&tv, 0, sizeof(tv));
	gettimeofday(&tv, NULL);

	LONGLONG time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return time;
}

/************************************************************************/
/* 将秒时间转化为时间字符串                                               */
/************************************************************************/
const std::string CoTimer::getTimeStr(SCORE timesec)
{
	time_t _time = timesec;
	struct tm* ptime;
	ptime = localtime(&_time);

	if (ptime)
	{
		return cocos2d::__String::createWithFormat("%02d:%02d", ptime->tm_hour, ptime->tm_min)->getCString();
	}
	else
	{
		return "";
	}
}

/************************************************************************/
/* 将秒事件转化为日期字符串                                               */
/************************************************************************/
const std::string CoTimer::getDataStr(SCORE timesec)
{
	time_t _time = timesec;
	struct tm* ptime;
	ptime = localtime(&_time);
	std::string timestr = cocos2d::__String::createWithFormat("%d/%02d/%02d", ptime->tm_year + 1900, ptime->tm_mon + 1, ptime->tm_mday)->getCString();
	return timestr;
}

/************************************************************************/
/* 得到本地的时间字符串                                                  */
/************************************************************************/
const std::string CoTimer::getLocalTimeStr()
{
	struct timeval tv;
	memset(&tv, 0, sizeof(tv));
	gettimeofday(&tv, NULL);

	struct tm* ptime;
	ptime = localtime((time_t *)&tv.tv_sec);
	if (ptime)
	{
		return cocos2d::__String::createWithFormat("%02d:%02d", ptime->tm_hour, ptime->tm_min)->getCString();
	}
	else
	{
		return "";
	}
}

/************************************************************************/
/* 得到本地的日期字符串                                                  */
/************************************************************************/
const std::string CoTimer::getLocalDateStr()
{
	struct timeval tv;
	memset(&tv, 0, sizeof(tv));
	gettimeofday(&tv, NULL);

	struct tm* ptime;
	ptime = localtime((time_t *)&tv.tv_sec);
	std::string timestr = cocos2d::__String::createWithFormat("%d/%02d/%02d", ptime->tm_year + 1900, ptime->tm_mon + 1, ptime->tm_mday)->getCString();
	return timestr;
}



//////////////////////////////////////////////////////////////////////////
CoTimer::CoTimer(int delay)
{
	init(delay);
}

void CoTimer::init(int delay)
{
	mStart = CoTimer::getCurrentTime();
	mDelay = delay;
}

bool CoTimer::isTimeUp() const
{
	return CoTimer::getCurrentTime() - mStart >= mDelay;
}


unsigned long CoTimer::getElapsed() const
{
	return CoTimer::getCurrentTime() - mStart;
}
