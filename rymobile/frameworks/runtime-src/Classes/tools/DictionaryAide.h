#ifndef _DictionaryAide_H_
#define _DictionaryAide_H_

#include "cocos2d.h"

class DictionaryAide
{
public:
	DictionaryAide(cocos2d::CCDictionary* dic = 0)
	{
		_dic = dic;
		CC_SAFE_RETAIN(_dic);
	}

	~DictionaryAide()
	{
		CC_SAFE_RELEASE(_dic);
	}

	void setDictionary(cocos2d::CCDictionary* dic)
	{
		CC_SAFE_RETAIN(dic);
		CC_SAFE_RELEASE(_dic);
		_dic = dic;
	}
public:
	const char* stringFromKey(const std::string& key)
	{
		return _dic->valueForKey(key)->getCString();
	}

	int intFromKey(const std::string& key)
	{
		return _dic->valueForKey(key)->intValue();
	}

	float floatFromKey(const std::string& key)
	{
		return _dic->valueForKey(key)->floatValue();
	}

	bool booleanFromKey(const std::string& key)
	{
		return _dic->valueForKey(key)->boolValue();
	}

	cocos2d::Vec2 pointFromKey(const std::string& key)
	{
		return cocos2d::PointFromString(_dic->valueForKey(key)->getCString());
	}

	cocos2d::Rect rectFromKey(const std::string& key)
	{
		return cocos2d::RectFromString(_dic->valueForKey(key)->getCString());
	}

	cocos2d::Size sizeFromKey(const std::string& key)
	{
		return cocos2d::SizeFromString(_dic->valueForKey(key)->getCString());
	}

	cocos2d::CCArray* arrayFromKey(const std::string& key)
	{
		return (cocos2d::CCArray*)_dic->objectForKey(key);
	}
private:
	cocos2d::CCDictionary* _dic;
};
#endif // _DictionaryAide_H_