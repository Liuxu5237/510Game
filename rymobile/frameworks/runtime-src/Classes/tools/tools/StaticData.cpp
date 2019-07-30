#include "StaticData.h"

USING_NS_CC;

using namespace std;

//file path
#define  STATIC_DATA_PATH "static_data.plist"

//定义StaticData对象
static StaticData* _sharedStaticData = 0;

//得到StaticData单例对象
StaticData* StaticData::shared()
{
	if(_sharedStaticData == 0){
		_sharedStaticData = new StaticData();
		_sharedStaticData->init();
	}
	return _sharedStaticData;
}


void StaticData::purge()
{
	CC_SAFE_RELEASE_NULL(_sharedStaticData);
}


StaticData::StaticData()
{
}

StaticData::~StaticData()
{
	CC_SAFE_RELEASE_NULL(_dictionary);
}

bool StaticData::init()
{
	_dictionary = CCDictionary::createWithContentsOfFile(STATIC_DATA_PATH);
	CC_SAFE_RETAIN(_dictionary);
	return true;
}
//根据键值得到String类型数据
const char* StaticData::stringFromKey(const std::string& key)
{
	return _dictionary->valueForKey(key)->getCString();
}

//根据键值得到int类型数据
int StaticData::intFromKey(const std::string& key)
{
	return _dictionary->valueForKey(key)->intValue();
}


unsigned int StaticData::colorFromKey(const std::string& key)
{
	const char* str = _dictionary->valueForKey(key)->getCString();
	unsigned int val=0;
	sscanf(str, "%x", &val);
	return val;
}

//根据键值得到float类型数据
float StaticData::floatFromKey(const std::string& key)
{
	return _dictionary->valueForKey(key)->floatValue();
}

//根据键值得到bool类型数据
bool StaticData::booleanFromKey(const std::string& key)
{
	return _dictionary->valueForKey(key)->boolValue();
}

//根据键值得到point类型数据
cocos2d::Vec2 StaticData::pointFromKey(const std::string& key)
{
	return PointFromString(_dictionary->valueForKey(key)->getCString());
}

//根据键值得到rect类型数据
cocos2d::Rect StaticData::rectFromKey(const std::string& key)
{
	return RectFromString(_dictionary->valueForKey(key)->getCString());
}

//根据键值得到size类型数据
cocos2d::Size StaticData::sizeFromKey(const std::string& key)
{
	return SizeFromString(_dictionary->valueForKey(key)->getCString());
}

//根据键值得到size类型数据
cocos2d::CCArray* StaticData::arrayFromKey(const std::string& key)
{
	return (CCArray*)_dictionary->objectForKey(key);
}

void StaticData::LoadGameHallRes()
{
	//SpriteFrameCache::getInstance()->addSpriteFramesWithFile("cocos_ui/NewUI/global/global.plist","cocos_ui/NewUI/global/global.png");
	//SpriteFrameCache::getInstance()->addSpriteFramesWithFile("cocos_ui/NewUI/gameui/GameUI.plist","cocos_ui/NewUI/gameui/GameUI.png");
}

void StaticData::requestGoodsImageFromWeb(std::string strUrl,int callback,int tag)
{
	/*
	if (strUrl.length()==0 || callback==0)
	{
		return;
	}
	
	cocos2d::network::HttpRequest* request = new cocos2d::network::HttpRequest();
	request->setRequestType(cocos2d::network::HttpRequest::Type::GET);
	request->setUrl(strUrl.c_str());
	request->setResponseCallback(std::bind(&StaticData::onHttpRequestCompleted_head,std::placeholders::_1,std::placeholders::_2,callback,tag));
	
	cocos2d::network::HttpClient::getInstance()->send(request);
	request->release();*/
}


void StaticData::onHttpRequestCompleted_head(cocos2d::network::HttpClient *sender, cocos2d::network::HttpResponse *response,int callback,int tag)
{
	/*
	if (response && response->isSucceed())
	{
		log("response code: %ld", response->getResponseCode());
		
		// 打印接收到的字符串
		std::vector<char> *buffer = response->getResponseData();
		std::string bufffff(buffer->begin(),buffer->end());
		log("%s", bufffff.c_str());
		
		if (callback!=0) {
			LuaStack *stack = LuaEngine::getInstance()->getLuaStack();
			stack->pushInt(200);
			stack->pushInt(tag);
			auto img=new Image;
			img->autorelease();
			img->initWithImageData((const unsigned char *)buffer->data(), buffer->size());
			stack->pushObject(img, "Image");
			stack->executeFunctionByHandler(callback, 3);  //执行lua函数
			stack->clean();
			
		}
		
		return;
	}
	
	
	if (response){
		log("response code: %ld", response->getResponseCode());
		log("error buffer: %s", response->getErrorBuffer());
	}
	
	if (callback!=0) {
		LuaStack *stack = LuaEngine::getInstance()->getLuaStack();
		stack->pushInt(0);
		stack->pushInt(tag);
		stack->executeFunctionByHandler(callback, 2);  //执行lua函数
		stack->clean();
		
	}*/
	
}


