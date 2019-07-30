#include "GameTimer.h"

CGameTimer::CGameTimer()
{
	EndTimer();
}

CGameTimer::~CGameTimer()
{

}

void CGameTimer::StartTimer()
{
	EndTimer();
	time(&m_timeStart);
	m_bStart = true;
}

double CGameTimer::GetTimeElapsed()
{
	time(&m_timeNow);
	return difftime(m_timeNow,m_timeStart);
}

void CGameTimer::EndTimer()
{
	m_timeStart = 0;
	m_timeNow = 0;
	m_bStart = false;
}

