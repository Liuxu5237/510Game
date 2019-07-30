#include "uploadFile.h"
#include "curl/curl.h"
#include "tools/tools/StaticData.h"
#include "tools/tools/MTNotification.h"
#include "platform/multiPlatform/MultiPlatformMgr.h"
uploadFile* uploadFile::m_inst = NULL;
string uploadFile::m_photoPath = "";

uploadFile* uploadFile::GetInst()
{
    if (!m_inst)
    {
        m_inst = new uploadFile();
        return m_inst;
    }
	else
	{
		return m_inst;
	}
		
    return NULL;
}

bool uploadFile::GetUpLoadFileSuccess(string photoPath)
{
	G_NOTIFY_D("SelectImageSuccess", MTData::create(2, 0, 0, photoPath));
	return true;
}

bool uploadFile::UpLoadFile(string photoPath)
{
	m_photoPath = photoPath;
    CCLOG("IN uploadFile::UpLoadFile str = %s",photoPath.c_str());
    CURLcode cURLcode;
    
    CURL *cURL;
	//MultiPlatformMgr::getInstance()->ShowToast("upload 0");
    cURLcode = curl_global_init(CURL_GLOBAL_SSL);
    if(CURLE_OK != cURLcode)
    {
		//MultiPlatformMgr::getInstance()->ShowToast("upload 1");
		G_NOTIFY_D("Login_Event", MTData::create(2, 0, 0, "", ""));
        curl_global_cleanup();
        return false;
    }
    
    cURL = curl_easy_init();
    if(!cURL)
    {
		//MultiPlatformMgr::getInstance()->ShowToast("upload 2");
		G_NOTIFY_D("Login_Event", MTData::create(2, 0, 0, "", ""));
        curl_easy_cleanup(cURL);
        curl_global_cleanup();
        return false;
    }
    
    curl_httppost *post = NULL;
    curl_httppost *last = NULL;
	
	std::string url = StaticData::shared()->stringFromKey("url_upLoadPicture");
    
    curl_formadd(&post, &last,CURLFORM_COPYNAME,"photo",CURLFORM_FILE,photoPath.c_str(),CURLFORM_CONTENTTYPE,"Image/png",CURLFORM_END);
    
    curl_easy_setopt(cURL, CURLOPT_URL, url.c_str());
    curl_easy_setopt(cURL, CURLOPT_TIMEOUT,20);//超时时间10秒
    curl_easy_setopt(cURL, CURLOPT_HTTPPOST,post);//请求方式POST
    curl_easy_setopt(cURL, CURLOPT_WRITEFUNCTION,write_data); //设置回调
    curl_easy_setopt(cURL, CURLOPT_VERBOSE,1); //非零值表示你想CURL报告每一件意外的事情
    
    curl_easy_perform(cURL);
    
    curl_easy_cleanup(cURL);
    
    curl_global_cleanup();

	return true;
}

size_t uploadFile::write_data(uint8_t *dataBack, size_t size, size_t nmemb, void *user_p)
{
	//MultiPlatformMgr::getInstance()->ShowToast("upload 3");
    string szData = string((char*)dataBack); //返回的结果
    CCLOG("uploadFile::write_data src:%s result:%s",m_photoPath.c_str(),szData.c_str());
	G_NOTIFY_D("upImageSuccess", MTData::create(2, 0, 0, szData));
	//G_NOTIFY_D("Login_Event", MTData::create(2, 0, 0, szData));
	//MultiPlatformMgr::getInstance()->ShowToast(szData);
    return 0;
}
