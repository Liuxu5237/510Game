//
//  MyConfigureData.cpp
//  qipaicocos
//
//  Created by keven on 16/8/10.
//
//

#include "MyConfigureData.h"
USING_NS_CC;

using namespace std;


//定义StringData对象
static MyConfigureData* _sharedStringData = 0;

//得到StringData单例对象
MyConfigureData* MyConfigureData::shared()
{
    if(_sharedStringData == 0){
        _sharedStringData = new MyConfigureData();
        _sharedStringData->init();
    }
    return _sharedStringData;
}

//当内存不足时调用
void MyConfigureData::purge()
{
    CC_SAFE_RELEASE_NULL(_sharedStringData);
}


MyConfigureData::MyConfigureData()
{
}

MyConfigureData::~MyConfigureData()
{
    CC_SAFE_RELEASE_NULL(_dictionary);
}

///<

bool MyConfigureData::init()
{
    //相对路径
    const char* plistpath = "myconfigure.plist";
    //通过CCFileUtils的fullPathFromFile方法获取绝对路径
    FileUtils* fileutils = FileUtils::getInstance();
    std::string pfullpath = fileutils->fullPathForFilename(plistpath);
    const char* cfullpath = pfullpath.c_str();
    
    _dictionary = CCDictionary::createWithContentsOfFile(cfullpath);
    
    CC_SAFE_RETAIN(_dictionary);
    int count = _dictionary->getReferenceCount();
   // cocos2d::log("count is %d", count);
    return true;
}

//根据键值得到String类型数据
const char* MyConfigureData::stringFromKey(const std::string& key)
{
    return _dictionary->valueForKey(key)->getCString();
}

//根据键值得到int类型数据
int MyConfigureData::intFromKey(const std::string& key)
{
    return _dictionary->valueForKey(key)->intValue();
}

