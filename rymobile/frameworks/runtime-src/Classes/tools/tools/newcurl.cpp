#include "newcurl.h"
#include "curl/curl.h"
#include "tools/global.h"
#include "json/document.h"
#include "platform/multiPlatform/MultiPlatformMgr.h"
#include "tools/tools/MTNotification.h"
#include "platform/df/RoomEventIDDefine.h"
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
#include <sys/stat.h>
#include <dirent.h>
#endif
#pragma  comment(lib,"libcurl_imp.lib")


struct MemoryStruct {
	char *memory;
	size_t size;
};

static size_t
WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
	size_t realsize = size * nmemb;
	struct MemoryStruct *mem = (struct MemoryStruct *)userp;

	mem->memory = (char*)realloc(mem->memory, mem->size + realsize + 1);
	if (mem->memory == NULL) {
		/* out of memory! */
		//cocos2d::log("WriteMemoryCallback error not enough memory (realloc returned NULL)\n");
		return 0;
	}

	memcpy(&(mem->memory[mem->size]), contents, realsize);
	mem->size += realsize;
	mem->memory[mem->size] = 0;
	std::string str = NewCurl::getCallBackType();
	if (str == "CallBackRecharge")
	{
		string szData = string((char*)contents); //返回的结果
		CCLOG("result:%s",szData.c_str());
		G_NOTIFY_D("room_event", MTData::create(ROOM_EVENT_ID_RECHARGE, 0, 0, szData));
		
	}
	else if (str != "")
	{
		string szData = string((char*)contents); //返回的结果
		CCLOG("result:%s",szData.c_str());
		G_NOTIFY_D(str, MTData::create(0, 0, 0, szData));
	}
	
	return realsize;
}
std::string NewCurl::m_CallbackType;

std::string  NewCurl::HttpPost(std::string url, std::string postData, int seconds, std::string callbackType)
{
	std::string str= "HttpPost url = ";
	str += url;
	str += " postData = ";
	str += postData;
	//cocos2d::log(str.c_str());
	
	m_CallbackType = callbackType;
	std::string  bResult = "";
	do 
	{
		CURL *curl;
		CURLcode res;
		char buffer[1024] = {};

		struct MemoryStruct chunk = {};

		chunk.memory = (char*)malloc(1);  /* will be grown as needed by the realloc above */
		chunk.size = 0;    /* no data at this point */
		curl = curl_easy_init();
		if (!curl)
		{
			MultiPlatformMgr::getInstance()->ShowToast("HttpPost no curl");
			break;
		}
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		//code from http://curl.haxx.se/libcurl/c/getinmemory.html
		//we pass our 'chunk' struct to the callback function 
		curl_easy_setopt(curl, CURLOPT_POST, true);
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postData.c_str());
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
		//If we don't provide a write function for curl, it will recieve error code 23 on windows.
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
		curl_easy_setopt(curl, CURLOPT_TIMEOUT_MS, seconds);    //设置连接超时时间    

		res = curl_easy_perform(curl);
		//always cleanup 
		curl_easy_cleanup(curl);
		if (CURLE_OK != res)
		{
			sprintf(buffer, "HttpPost error code: %i", res);
			//ShowToast(buffer);
			//cocos2d::log(buffer);
			break;
		}
		//ShowToast(StringUtils::format("Connect successfully!\n%s", chunk.memory));

		bResult = chunk.memory;
		break;

		
	} while (0);
	return bResult;
}


std::string  NewCurl::HttpGet(std::string url, int seconds, std::string callbackType)
{
	std::string str = "HttpGet url = ";
	str += url;
	//cocos2d::log(str.c_str());
	m_CallbackType = callbackType;
	std::string  bResult = "";
	do
	{
		CURL *curl;
		CURLcode res;
		char buffer[1024] = {};

		struct MemoryStruct chunk = {};

		chunk.memory = (char*)malloc(1);  /* will be grown as needed by the realloc above */
		chunk.size = 0;    /* no data at this point */
		curl = curl_easy_init();
		if (!curl)
		{
			MultiPlatformMgr::getInstance()->ShowToast("HttpGet no curl");
			break;
		}
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		//code from http://curl.haxx.se/libcurl/c/getinmemory.html
		//we pass our 'chunk' struct to the callback function 
		//curl_easy_setopt(curl, CURLOPT_HTTPGET, true);
		//curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
		//If we don't provide a write function for curl, it will recieve error code 23 on windows.
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
		curl_easy_setopt(curl, CURLOPT_TIMEOUT_MS, seconds);    //设置连接超时时间    

		res = curl_easy_perform(curl);
		//always cleanup 
		curl_easy_cleanup(curl);
		if (CURLE_OK != res)
		{
			sprintf(buffer, "HttpGet error code: %i", res);
			//ShowToast(buffer);
			//cocos2d::log(buffer);
			break;
		}
		//ShowToast(StringUtils::format("Connect successfully!\n%s", chunk.memory));

		bResult = chunk.memory;
		break;


	} while (0);
	return bResult;
}
//rapidjson::Document& NewCurl::GetJsonObjFromString(rapidjson::Document &dc, std::string strJson)
//{
//	bool bRet = false;
//	do
//	{
//		CC_BREAK_IF(strJson.empty());
//		dc.Parse<0>(strJson.c_str());
//		CC_BREAK_IF(dc.HasParseError());
//		//   
//		if (!dc.IsObject())
//			return dc;
//		// 
//		if (!dc.HasMember("Can"))
//			return dc;
//		if (!dc.HasMember("Data"))
//			return dc;
//		if (!dc.HasMember("Message"))
//			return dc;
//		bRet = true;
//
//	} while (0);
//
//	return dc;
//}


void onHttpRequestCompleted(network::HttpClient *sender, network::HttpResponse *response)
{
	bool bLoadSuccess = false;
	std::string urlName = "dushigamedefault.png";
	do 
	{	
		if (!response)
		{
			break;
		}

		// You can get original request type from: response->request->reqType
		if (0 != strlen(response->getHttpRequest()->getTag()))
		{
			log("%s completed", response->getHttpRequest()->getTag());
			urlName = response->getHttpRequest()->getTag();
		}
		int statusCode = response->getResponseCode();
		if (!response->isSucceed())
		{
			log("response failed");
			log("error buffer: %s", response->getErrorBuffer());
			break;
		}

		//get data
		std::vector<char> *buffer = response->getResponseData();

		//create image
		CCImage* img = new CCImage;
		img->initWithImageData((unsigned char*)buffer->data(), buffer->size());
		//create texture
		cocos2d::CCTexture2D* texture = new CCTexture2D();
		bool isImg = texture->initWithImage(img,img->getRenderFormat());
		img->release();

		//write file
		std::string path = CCFileUtils::sharedFileUtils()->getWritablePath();
		path += response->getHttpRequest()->getTag();

		int pos = path.find_last_of("/");

		std::string downPath = path.substr(0,pos+1);


#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
		DIR *pDir = NULL;
		pDir = opendir(downPath.c_str());
		if (!pDir)
		{
			int nResult = mkdir(downPath.c_str(), S_IRWXU | S_IRWXG | S_IRWXO);
			if (0 != nResult)
			{
				//cocos2d::log("ImagicDownManager::addDown create fail1 %s", downPath.c_str());
				return;
			}
		}
#else
		if ((GetFileAttributesA(downPath.c_str())) == INVALID_FILE_ATTRIBUTES)
		{
			int bSuccess = CreateDirectoryA(downPath.c_str(), 0);
			if (0 == bSuccess)
			{
				//cocos2d::log("ImagicDownManager::addDown create fail2 %s", downPath.c_str());
				return;
			}
		}
#endif
		FILE *fp = fopen(path.c_str(), "wb+");
		if (!fp)
		{
			break;
		}
		bLoadSuccess = true;
		fwrite(buffer->data(), 1, buffer->size(), fp);
		fclose(fp);

	} while (0);

	//下载成功，发出消息，把文件名传过去 0:失败 1：成功
	G_NOTIFY_D("room_event", MTData::create(ROOM_EVENT_ID_LOADURLIMAGE, bLoadSuccess, 0, urlName));
}

int NewCurl::LoadUrlImage(std::string url, std::string newImageName)
{
	if ("" == url)
	{
		return 1;
	}
	if ("" == newImageName)
	{
		newImageName = "dushigamedefault.png";
	}

	network::HttpRequest* request = new network::HttpRequest();
	request->setUrl(url.c_str());
	request->setRequestType(network::HttpRequest::Type::GET);
	request->setResponseCallback(onHttpRequestCompleted);
	request->setTag(newImageName.c_str());
	network::HttpClient::getInstance()->send(request);
	request->release();

	return 0;
}
