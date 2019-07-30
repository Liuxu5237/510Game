#ifndef _StringData_H_
#define _StringData_H_

#include "cocos2d.h"
//////////////////////////////////////////////////////////////////////////

#define SSTRING(key) StringData::shared()->stringFromKey(key)

//////////////////////////////////////////////////////////////////////////


class StringData : public cocos2d::Ref
{
public:
	static StringData* shared();
	static void purge();

public:
    const char*	stringFromKey(const std::string& key);   
private:
	StringData();
	~StringData();
	bool init();

private:
	cocos2d::CCDictionary* _dictionary;
};

#endif // _StringData_H_
