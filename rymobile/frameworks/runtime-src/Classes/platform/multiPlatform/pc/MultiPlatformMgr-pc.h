//
//  MultiPlatformMgr-android.hpp
//  NiuNiu
//
//  Created by zhong on 1/4/16.
//
//

#ifndef MultiPlatformMgr_android_hpp
#define MultiPlatformMgr_android_hpp

#include "cocos2d.h"

#include <stdio.h>
#if  CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
#include "../MultiPlatformMgr.h"

class MultiPlatformMgr_PC : public MultiPlatformMgr
{
    friend class MultiPlatformMgr;
public:
	MultiPlatformMgr_PC();
	~MultiPlatformMgr_PC();

};
#endif

#endif /* MultiPlatformMgr_android_hpp */
