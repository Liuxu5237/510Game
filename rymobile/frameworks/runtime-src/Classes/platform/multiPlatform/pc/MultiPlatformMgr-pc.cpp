#include "MultiPlatformMgr-pc.h"


#if  CC_TARGET_PLATFORM == CC_PLATFORM_WIN32

MultiPlatformMgr_PC::MultiPlatformMgr_PC()
{
    
}

MultiPlatformMgr_PC::~MultiPlatformMgr_PC()
{
    
}

MultiPlatformMgr* MultiPlatformMgr::getInstance()
{
    if (nullptr == s_multiInstance)
    {
		s_multiInstance = new MultiPlatformMgr_PC();
    }
    return s_multiInstance;
}

#endif
