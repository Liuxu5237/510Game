#include "StringData.h"

USING_NS_CC;

using namespace std;


//定义StringData对象
static StringData* _sharedStringData = 0;

//得到StringData单例对象
StringData* StringData::shared()
{
	if(_sharedStringData == 0){
		_sharedStringData = new StringData();
		_sharedStringData->init();
	}
	return _sharedStringData;
}

//当内存不足时调用
void StringData::purge()
{
	CC_SAFE_RELEASE_NULL(_sharedStringData);
}


StringData::StringData()
{
}

StringData::~StringData()
{
	CC_SAFE_RELEASE_NULL(_dictionary);
}

///<

bool StringData::init()
{
	//相对路径
	const char* plistpath = "strings.plist";
	//通过CCFileUtils的fullPathFromFile方法获取绝对路径
	FileUtils* fileutils = FileUtils::getInstance();
	std::string pfullpath = fileutils->fullPathForFilename(plistpath);
	const char* cfullpath = pfullpath.c_str();

	_dictionary = CCDictionary::createWithContentsOfFile(cfullpath);

	CC_SAFE_RETAIN(_dictionary);
	int count = _dictionary->getReferenceCount();
	//cocos2d::log("count is %d", count);
	return true;
}

//根据键值得到String类型数据
const char* StringData::stringFromKey(const std::string& key)
{
	//_dictionary->setObject
	//int _len = _dictionary->allKeys()->count();

	//for(int i=0;i<_len;i++)
	//{
	//	log("aaaaaaa = %s",(char*)_dictionary->allKeys()->objectAtIndex(i));
	//}
	const __String* tmpStr = _dictionary->valueForKey(key);
	if (NULL == tmpStr || 0 == tmpStr->length())
	{
		std::string tmpStr = std::string("stringFromKey find key error ") + key;
		//cocos2d::log(tmpStr.c_str());
		assert(false);
		return key.c_str();
	}

	return tmpStr->getCString();
}
