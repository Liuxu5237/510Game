//
//  MyConfigureData.hpp
//  qipaicocos
//
//  Created by keven on 16/8/10.
//
//

#ifndef MyConfigureData_h
#define MyConfigureData_h

#include "cocos2d.h"
//////////////////////////////////////////////////////////////////////////

#define MCSTRING(key) MyConfigureData::shared()->stringFromKey(key)
#define MCINT(key) MyConfigureData::shared()->intFromKey(key)

//////////////////////////////////////////////////////////////////////////


class MyConfigureData : public cocos2d::Ref
{
public:
    static MyConfigureData* shared();
    static void purge();
    
public:
    const char*	stringFromKey(const std::string& key);
    int	intFromKey(const std::string& key);
private:
    MyConfigureData();
    ~MyConfigureData();
    bool init();
    
private:
    cocos2d::CCDictionary* _dictionary;
};

#endif /* MyConfigureData_h */
