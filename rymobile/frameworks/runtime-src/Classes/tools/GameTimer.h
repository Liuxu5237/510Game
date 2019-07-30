/****************************************************************************
 定时器
 彭龙华
 2015-11-17
 （引擎帧率降低会导致引擎定时器失效，因此增加该定时器）
 ****************************************************************************/

#pragma once
#include <time.h>

class CGameTimer
{
public:
	CGameTimer();
	~CGameTimer();

	void				StartTimer();
	double				GetTimeElapsed();
	void				EndTimer();
	inline bool			IsStarted() const { return m_bStart; }

private:
	time_t				m_timeStart;
	time_t				m_timeNow;
	bool				m_bStart;
};