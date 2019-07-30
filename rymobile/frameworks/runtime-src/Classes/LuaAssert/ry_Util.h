//
//  ry_Util.hpp
//  GloryProject
//
//  Created by chunyong chen on 2017/9/15.
//
//

#ifndef ry_Util_hpp
#define ry_Util_hpp

#include "cocos2d.h"

USING_NS_CC;

int register_all_RyUtil();

class ryUtil {
    
public:
    static ryUtil* getIns();
    
    std::string getSign1(const char* userid, const char* key, const char* time);
    std::string getUnixTime();
    void trimSpace(std::string *s);
};

#endif /* ry_Util_hpp */
