#pragma once


#include "cocos2d.h"
#include "json/writer.h"
#include "json/stringbuffer.h"
#include "json/document.h"
#include "network/HttpRequest.h"
#include "network/HttpClient.h"
#include "platform/df/RoomEventIDDefine.h"

using namespace cocos2d;

//http 请求
class NewCurl
{
public:
	//http post请求
	static std::string HttpPost(std::string url, std::string postData,int seconds = 10000, std::string callbackType = "");

	//http get请求
	static std::string HttpGet(std::string url,  int seconds = 10000, std::string callbackType = "");
	//文档解析
	//static rapidjson::Document& GetJsonObjFromString(rapidjson::Document &dc, std::string strJson);
	/*加载网络图片
	url:网络路径
	newImageName:新图片的名字
	*/
	static int LoadUrlImage(std::string url, std::string newImageName);
	
	static std::string getCallBackType(){return m_CallbackType;}
protected:
	static std::string m_CallbackType;

};

