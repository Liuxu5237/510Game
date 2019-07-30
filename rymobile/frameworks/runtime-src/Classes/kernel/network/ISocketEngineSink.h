#ifndef _ISocketEngineSink_
#define _ISocketEngineSink_

#include "../../platform/df/types.h"

class ISocketEngineSink
{
public:
	virtual ~ISocketEngineSink(){}
	virtual void onEventTCPSocketLink() = 0;
	virtual void onEventTCPSocketShut() = 0;
	virtual void onEventTCPSocketError(int errorCode) = 0;
	virtual bool onEventTCPSocketRead(int main, int sub, char * data, int dataSize) = 0;
}; // ISocketEngineSink

#endif // _ISocketEngineSink_