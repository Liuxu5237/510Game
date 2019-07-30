#ifndef _ISocketSink_
#define _ISocketSink_

#include "platform/PlatformHeader.h"

class ISocketSink : public cocos2d::Ref
{
public:
	virtual ~ISocketSink() {}
	virtual void onSocketLink() = 0;
	virtual void onSocketShut() = 0;
	virtual void onSocketError(int errorCode) = 0;
	virtual void onSocketData(void* data, int dataSize) = 0;
	virtual void onSocketCallBack(CCObject* pData) = 0;

};
#endif
