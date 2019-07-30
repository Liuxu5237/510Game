#ifndef __StaticData_H_
#define __StaticData_H_

#include "cocos2d.h"
#include "network/HttpRequest.h"
#include "network/HttpClient.h"
//#include "scripting/lua-bindings/manual/CCLuaEngine.h"

#include <string>
using namespace std;

//////////////////////////////////////////////////////////////////////////

#define STATIC_DATA_STRING(key)		StaticData::shared()->stringFromKey(key)
#define STATIC_DATA_INT(key)		StaticData::shared()->intFromKey(key)
#define STATIC_DATA_FLOAT(key)		StaticData::shared()->floatFromKey(key)
#define STATIC_DATA_BOOLEAN(key)	StaticData::shared()->booleanFromKey(key)
#define STATIC_DATA_POINT(key)		StaticData::shared()->pointFromKey(key)
#define STATIC_DATA_RECT(key)		StaticData::shared()->rectFromKey(key)
#define STATIC_DATA_SIZE(key)		StaticData::shared()->sizeFromKey(key)
#define STATIC_DATA_ARRAY(key)		StaticData::shared()->arrayFromKey(key)
#define STATIC_DATA_COLOR(key)		StaticData::shared()->colorFromKey(key);
//////////////////////////////////////////////////////////////////////////

class StaticData : public cocos2d::Ref
{
public:
	static StaticData* shared();
	static void purge();
	static void LoadGameHallRes();
	static void requestGoodsImageFromWeb(std::string strUrl,int callback,int tag);
	
public:
    const char*			stringFromKey(const std::string& key);
    int					intFromKey(const std::string& key);
	unsigned int		colorFromKey(const std::string& key);
	float				floatFromKey(const std::string& key);
    bool				booleanFromKey(const std::string& key);
    cocos2d::Vec2	pointFromKey(const std::string& key);
    cocos2d::Rect		rectFromKey(const std::string& key);
    cocos2d::Size		sizeFromKey(const std::string& key);
	cocos2d::CCArray*	arrayFromKey(const std::string& key);

private:
    StaticData();
    ~StaticData();
    bool init();
	void onHttpRequestCompleted_head(cocos2d::network::HttpClient *sender, cocos2d::network::HttpResponse *response,int callback,int tag);

private:
	cocos2d::CCDictionary* _dictionary;
};

#endif // __StaticData_H_
