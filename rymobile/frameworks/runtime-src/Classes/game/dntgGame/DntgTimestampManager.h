#ifndef _Dntg_TimestampManager_H_
#define _Dntg_TimestampManager_H_

#include "platform/PlatformHeader.h"
namespace  Dntg
{
	class TimestampManager
	{
	public:
		TimestampManager();

		uint32 getTimeCheck() const;
		void timeCheck(uint32 clientTime, uint32 serverTime);

		uint32 get_unified_time() const;
		uint32 get_trad() const;
		uint32 get_time_difference(uint32 packet_time);
		uint32 get_server_tick();

		void tick(float dt);
	private:
		uint32 time_local_;
		uint32 time_trad_;
		uint32 server_time_;
		double current_tick_;
		uint32 time_;
		uint32 sc_diffrence_;

	};
}
extern Dntg::TimestampManager gDntgTimestampManager;
#endif //_TimestampManager_H_