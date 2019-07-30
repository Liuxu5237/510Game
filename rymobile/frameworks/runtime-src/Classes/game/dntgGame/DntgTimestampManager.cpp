#include "tools/dialog/Timer.h"
#include "DntgTimestampManager.h"
#include "DntgHeader.h"

using namespace Dntg;
TimestampManager gDntgTimestampManager;


TimestampManager::TimestampManager()
{
	time_local_ = 0;
	current_tick_ = 0;
	time_trad_ = 0;
	server_time_ = 0;
	sc_diffrence_ = 0;
}

uint32 TimestampManager::getTimeCheck() const
{
	return CoTimer::getCurrentTime();
}

void TimestampManager::timeCheck(uint32 clientTime, uint32 serverTime)
{
	if (clientTime != 0)
		time_local_ = clientTime;
	else
		time_local_ = getTimeCheck();

	clientTime = getTimeCheck();
	if (clientTime > time_local_)
		time_trad_ = (clientTime - time_local_) / 2;
	else
		time_trad_ = 0;

	server_time_ = serverTime + time_trad_;
	sc_diffrence_ = server_time_ - clientTime;


	time_ = getTimeCheck();
}

uint32 TimestampManager::get_unified_time() const
{
	return server_time_ + (getTimeCheck() - time_);
}

uint32 TimestampManager::get_trad() const
{
	return time_trad_;
}

uint32 TimestampManager::get_time_difference(uint32 packet_time)
{
	//int32 myTrad1 = packet_time + time_trad_;
	int32 myTrad1 = get_server_tick() - packet_time;
	if (myTrad1 < 0)
		myTrad1 = 0;
	if (myTrad1 > MAX_DIFFERENCE)
		myTrad1 = MAX_DIFFERENCE;
	return myTrad1;
}

uint32 TimestampManager::get_server_tick()
{
	return getTimeCheck() + sc_diffrence_;
}


void TimestampManager::tick(float dt)
{
	current_tick_ += dt;
}