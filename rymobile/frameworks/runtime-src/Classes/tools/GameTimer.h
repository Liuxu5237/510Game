/****************************************************************************
 ��ʱ��
 ������
 2015-11-17
 ������֡�ʽ��ͻᵼ�����涨ʱ��ʧЧ��������Ӹö�ʱ����
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