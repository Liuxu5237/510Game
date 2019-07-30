#include "ImagicDownManager.h"
#include "script/UtilityFun.h"
#include "platform/multiPlatform/MultiPlatformMgr.h"
#include "tools/tools/MTNotification.h"
#include "platform/df/RoomEventIDDefine.h"
#include "tools/tools/MTNotification.h"
#include "platform/df/GameEventIDDefine.h"
#include "tools/StringUtility.h"
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
#include <sys/stat.h>
#include <dirent.h>
#endif

using namespace ui;

ImagicDownManager *	ImagicDownManager::m_ImagicDownManager = NULL;

ImagicDownManager::ImagicDownManager()
	
{
	cocos2d::Director::getInstance()->getScheduler()->schedule(CC_SCHEDULE_SELECTOR(ImagicDownManager::upTime), this, 0.0f, false);
	m_strSavePath = "userface";
}
ImagicDownManager::~ImagicDownManager(void)
{
	cocos2d::Director::getInstance()->getScheduler()->unschedule(CC_SCHEDULE_SELECTOR(ImagicDownManager::upTime),this);
}
std::string DownImagicGetFileName(std::string kName)
{
	std::string::size_type iStart = 0;
	while (true)
	{
		std::string::size_type iTempPos = kName.find("/",iStart);
		if (iTempPos == std::string::npos)
		{
			break;
		}
		iStart = iTempPos;
		iStart++;
	}
	size_t iEnd = kName.size();
	return kName.substr(iStart,iEnd-iStart);
}
void ImagicDownManager::GetImagic(cocos2d::network::HttpClient *sender, cocos2d::network::HttpResponse *response)
{
	response->retain();
	m_pGetList.push_back(response);
}
void ImagicDownManager::OnImagic()
{
	if (m_pGetList.size() == 0)
	{
		return;
	}
	cocos2d::network::HttpResponse *response = m_pGetList[0];
	m_pGetList.erase(m_pGetList.begin());
	int statusCode = response->getResponseCode();
	//log("ImagicDownManager::OnImagic response code: %d", statusCode);
	if (!response->isSucceed())
	{
		log("ImagicDownManager::OnImagic error response buffer: %s", response->getErrorBuffer());
		return;
	}
	std::string kUrl = response->getHttpRequest()->getUrl();
	std::string kImagicName = cocos2d::FileUtils::getInstance()->getWritablePath()+"test.png";

	ImagicDownInfoList::iterator itor1 = m_pDownList.begin();
	while(itor1 != m_pDownList.end())
	{
		ImagicDownInfo& kInfo = *itor1;
		if (kInfo.kUrl.find(kUrl.c_str()) != std::string::npos)
		{
			kImagicName = kInfo.kImagicName;
			break;
		}
		itor1++;
	}
	std::vector<char> *buffer = response->getResponseData();
	if (buffer->size() == 0)
	{
		return;
	}
	cocos2d::CCImage* img = new cocos2d::CCImage;
	img->initWithImageData((unsigned char*)buffer->data(),buffer->size());
	bool bSucess = false;
	if (img->getData())
	{
		bSucess = img->saveToFile(kImagicName, false);
	}
	delete img;

	ImagicDownInfoList::iterator itor2 = m_pDownList.begin();
	while(itor2 != m_pDownList.end())
	{
		ImagicDownInfo& kInfo = *itor2;
        if (kInfo.kUrl.find(kUrl.c_str()) != std::string::npos)
		{	
			if (bSucess)
			{
				if (kInfo.iType == eDownType_Game)
				{
					G_NOTIFY_D("LoadProfileUrl", MTData::create(0, kInfo.iUserId, 0, kImagicName));
				}
				else if (kInfo.iType == eDownType_HALL)
				{
					//G_NOTIFY_D("room_event", MTData::create(0, kInfo.iUserId, 0, kImagicName));
				}if (eDownType_CHAIR_ID == kInfo.iType)
				{
					std::string str = utility::toString("LoadProfileUrl", kInfo.iChairId);
					G_NOTIFY_D(str, MTData::create(0, kInfo.iUserId, kInfo.iChairId, kImagicName));
				}
				else
				{
					log("ImagicDownManager::OnImagic error type %d %s", kInfo.iType, kInfo.kImagicName.c_str());
				}
			}
			else
			{
				log("ImagicDownManager::OnImagic error down %s", kInfo.kImagicName.c_str());
			}
			
			itor2 = m_pDownList.erase(itor2);
		}
		else
		{
			++itor2;
		}
	}
	response->release();
}
cocos2d::Texture2D* ImagicDownManager::getDownTexture(std::string kFile)
{
	cocos2d::Texture2D* pTexture = cocos2d::CCTextureCache::sharedTextureCache()->addImage(kFile.c_str());
	if (pTexture)
	{
		return pTexture;
	}
	pTexture = cocos2d::CCTextureCache::sharedTextureCache()->addImage(utility::toString("head/",kFile.c_str()));
	if (pTexture)
	{
		return pTexture;
	}
	
	std::string kImagicName = DownImagicGetFileName(kFile);
	kImagicName = cocos2d::FileUtils::getInstance()->getWritablePath()+kImagicName;
	std::string StrSavePath = kImagicName;
	pTexture = cocos2d::CCTextureCache::sharedTextureCache()->addImage(StrSavePath.c_str());
	if (pTexture)
	{
		return pTexture;
	}
	return NULL;
}
std::string ImagicDownManager::addDown(int Type, std::string kUrl, int iUserID, bool bSameSize,int chairId)
{
	utility::trim(kUrl);
	//做下面的工作，主要是考虑如果有玩家的头像改变了，下面的总值就会改变
	int iIdex = GetUrlId(kUrl);
	std::string downPath = GetDownFilePath();
	//判断下载路径是否存在
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
	DIR *pDir = NULL;
	pDir = opendir(downPath.c_str());
	if (!pDir)
	{
		int nResult = mkdir(downPath.c_str(), S_IRWXU | S_IRWXG | S_IRWXO);
		if (0!= nResult)
		{
			//cocos2d::log("ImagicDownManager::addDown create fail1 %s", downPath.c_str());
			return "";
		}
	}
#else
	if ((GetFileAttributesA(downPath.c_str())) == INVALID_FILE_ATTRIBUTES)
	{
		int bSuccess = CreateDirectoryA(downPath.c_str(), 0);
		if (0 == bSuccess)
		{
			//cocos2d::log("ImagicDownManager::addDown create fail2 %s", downPath.c_str());
			return "";
		}
	}
#endif

	std::string strFullName = GetDownFullFileName(iUserID, iIdex);
	//判断此文件是否存在
	if (FileUtils::getInstance()->isFileExist(strFullName))
	{
		return strFullName;
	}
	std::string kFileName = GetDownFileName(iUserID, iIdex);
	bool bHaveGet = false;
	for (int i = 0;i<(int)m_pDownList.size();i++)
	{
		ImagicDownInfo& kInfo = m_pDownList[i];
		if (kInfo.kImagicName == kFileName)
		{
			bHaveGet = true;
			break;
		}		
	}
	if (bHaveGet)
	{
		return "";
	}
	ImagicDownInfo kInfo = {};

	kInfo.kImagicName = strFullName;
	kInfo.kUrl = kUrl;
	kInfo.iType = Type;
	kInfo.iUserId = iUserID;
	kInfo.iChairId = chairId;

	cocos2d::network::HttpRequest* pRequest = getFile(kUrl,	CC_CALLBACK_2(ImagicDownManager::GetImagic, this));
	kInfo.pRequest = pRequest;

	m_pDownList.push_back(kInfo);	
	
	return "";
}
void ImagicDownManager::upTime(float fTime)
{
	OnImagic();
	ImagicDownInfoList::iterator itor = m_pDownList.begin();
	while (itor != m_pDownList.end())
	{
		ImagicDownInfo& kInfo = *itor;
		kInfo.fActTime += fTime;
		if (kInfo.fActTime > 20.0f)
		{
			itor = m_pDownList.erase(itor);
		}
		else
		{
			++itor;
		}
	}
}

//void ImagicDownManager::setImagic(std::string kImagic, int bSame)
//{
//	CCAssert(widget, "");
//
//	Size sz = widget->getContentSize();
//	float fx = widget->getScaleX()*sz.width;
//	float fy = widget->getScaleY()*sz.height;
//	if (m_fitsz.width == 0 && m_fitsz.height == 0)
//	{
//		m_fitsz = CCSizeMake(fx, fy);
//	}
//	widget->loadTexture(kImagic);
//	if (bSame)
//	{
//		utility::setSpriteScaleBySize(widget, m_fitsz);
//	}
//}


cocos2d::network::HttpRequest* ImagicDownManager::getFile(std::string kUrl, const cocos2d::network::ccHttpRequestCallback &callback)
{
	cocos2d::network::HttpRequest *request = new cocos2d::network::HttpRequest();
	request->setUrl(kUrl.c_str());
	//log(kUrl.c_str());
	request->setResponseCallback(callback);
	request->setRequestType(cocos2d::network::HttpRequest::Type::GET);
	cocos2d::network::HttpClient *httpClient = cocos2d::network::HttpClient::getInstance();
	httpClient->setTimeoutForConnect(10);
	httpClient->setTimeoutForRead(10);
	httpClient->sendImmediate(request);
	request->release();
	return request;
}
/*
void ImagicDownManager::addDownCallBack(cocos2d::Ref * obj)
{
	EventCustom *event_ = (EventCustom*)obj;
	if (event_ == 0){
		return;
	}

	MTData* data = (MTData*)event_->getUserData();
	if (data == 0)
		return;
	std::string str_url = data->getStr1();
	int  type = data->getData1();
	int  userid = data->getData2();
	addDown(type, str_url, userid);


}
*/

std::string ImagicDownManager::GetDownFullFileName(int nUserId, int nIndex)
{
	/*std::string kFileName = utility::toString(nUserId, "Idex", nType);
	kFileName = GetDownFilePath() + kFileName + ".png";
	std::string StrSavePath = kFileName;*/
	std::string kFileName = GetDownFilePath() + GetDownFileName(nUserId, nIndex);
	return kFileName;
}

std::string ImagicDownManager::GetDownFileName(int nUserId, int nIndex)
{
	std::string kFileName = utility::toString("index",nUserId, "_", nIndex);
	kFileName  += ".png";
	return kFileName;
}

std::string ImagicDownManager::GetDownFilePath()
{
	std::string curPath = cocos2d::FileUtils::getInstance()->getWritablePath();
	curPath += m_strSavePath + "/";
	return curPath;
}

std::string ImagicDownManager::ExistDownFile(eDownType nType, std::string kUrl, int iUserID)
{
	int iIdex = GetUrlId(kUrl);
	std::string strFullName = GetDownFullFileName(iUserID, iIdex);
	if (FileUtils::getInstance()->isFileExist(strFullName))
	{
		return strFullName;
	} 
	else
	{
		return "";
	}
}

int ImagicDownManager::GetUrlId(std::string url)
{
	int iIdex = 0;
	for (int i = 0; i < url.size(); i++)
	{
		iIdex += url[i];
	}
	return iIdex;
}