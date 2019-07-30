#ifndef _Lkpy_Timer_H_
#define _Lkpy_Timer_H_

#include "platform/df/types.h"

class CoTimer
{
public:
	/**
		* 获取当前系统时间(单位:毫秒)
		* @return int
		*/
	static unsigned int getCurrentTime();

public:

	static LONGLONG getsystemtomillisecond();

	// 设置游戏世界事件
	static void setGameWorldTime(SCORE timesec);

	//得到游戏世界的时间
	static LONGLONG getGameWorldTime();

	// 得到当前游戏世界时间字符串
	static const std::string getGameWorldTimeStr();

	//将秒时间转化为时间字符串
	static const std::string getTimeStr(SCORE timesec);

	//将秒事件转化为日期字符串
	static const std::string getDataStr(SCORE timesec);

	//得到本地的时间字符串
	static const std::string getLocalTimeStr();

	//得到本地的日期字符串
	static const std::string getLocalDateStr();
public:
	/**
		* 构造函数
		* @param delay:int 毫秒数
		*/
	CoTimer(int delay = 0);

	/**
		* 设置延迟时间
		* @param delay:int 毫秒数
		*/
	void init(int delay);

	/**
		* 是否时间到了
		* @return bool
		*/
	bool isTimeUp() const;

	/**
		* 获取流逝时间
		*/
	unsigned long getElapsed() const;
protected:
	unsigned long mStart;
	unsigned long mDelay;

protected:
	static SCORE s_llGameWorldServer;		//服务器的时间，以秒为单位，需要服务器设置之后才有效
	static SCORE s_llRecvGameWorldSecond;
};


#endif // _Timer_H_
