#include "DSFileUpdate.h"
#include "cocos2d.h"
#include <curl/curl.h>
#include <curl/easy.h>
#include "scripting/lua-bindings/manual/CCLuaEngine.h"
#include "tools/StringUtility.h"
#include "platform/df/Module.h"
#include "lua/LuaStackEx.h"
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
#include <dirent.h>
#include <sys/stat.h>
#else
#include <curl/curl.h>
#include <curl/easy.h>
#endif
#define TEMP_PACKAGE_FILE_NAME    "cocos2dx-update-temp-package.zip"



static pthread_t        s_networkThread;
static pthread_mutex_t  s_FileUpdateMutex;

long		DSFileUpdate::s_lTotalFileLenth = 0;
long		DSFileUpdate::s_lCurFileLenth = 0;
string		DSFileUpdate::s_PreData = "";
bool		DSFileUpdate::s_isdownList = false;


DSFileUpdate *	DSFileUpdate::s_pFileUpdate = NULL;
Array *			DSFileUpdate::s_updateData = NULL;

/************************************************************************/
/* 构造函数                                                             */
/************************************************************************/
DSFileUpdate::DSFileUpdate(const char* packageUrl, const char * versionFileUrl, const char* storagePath) : 
AssetsManager(packageUrl,versionFileUrl,storagePath)
{
    m_sPathToSave = "";
    m_sDownFileUrl = "http://down.dushigame.com/download/AppResourceDownLoad/test/";
    m_sVersionList = "version.txt";
	m_save_file_key = "";
	curl_global_init(CURL_GLOBAL_ALL);
	m_vVersionList.clear();
    m_vListLenth.clear();
	m_updateType = UT_ERROR;

	CCDirector::sharedDirector()->getScheduler()->scheduleSelector(schedule_selector(DSFileUpdate::DSUpdateCallLuaFunc), this, 0, false);
    CCDirector::sharedDirector()->getScheduler()->pauseTarget(this);

	s_lTotalFileLenth = 0;
	s_lCurFileLenth = 0;
	s_PreData = "";
	s_isdownList = true;
}

/************************************************************************/
/* 析构函数                                                             */
/************************************************************************/
DSFileUpdate::~DSFileUpdate()
{
	curl_global_cleanup();

	CCDirector::sharedDirector()->getScheduler()->unscheduleAllForTarget(this);
}

/************************************************************************/
/* 设置下载文件路径                                                      */
/************************************************************************/
void DSFileUpdate::setDownFileUrl(string url)
{
	m_sDownFileUrl = url;
}

/************************************************************************/
/* 设置版本文件名字                                                      */
/************************************************************************/
void DSFileUpdate::setVersionList(string iniName)
{
	m_sVersionList = iniName;
}

/************************************************************************/
/* 注册版本更新回调函数                                                  */
/************************************************************************/
void DSFileUpdate::registerFileUpdateCallBack(string func)
{
	m_sCallBackFunc = func;
}

/************************************************************************/
/* 设置保存路径名                                                        */
/************************************************************************/
void DSFileUpdate::setSaveKey(string key)
{
	m_save_file_key = key;
}

/************************************************************************/
/* 创建下载路径                                                          */
/************************************************************************/
void DSFileUpdate::createDownloadedDir(const char *Path)
{
	m_sPathToSave = CCFileUtils::sharedFileUtils()->getWritablePath() + Path + "/";

	// Create the folder if it doesn't exist
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
	DIR *pDir = NULL;

	pDir = opendir(m_sPathToSave.c_str());
	if (!pDir)
	{
		mkdir(m_sPathToSave.c_str(), S_IRWXU | S_IRWXG | S_IRWXO);
	}
#else
	if ((GetFileAttributesA(m_sPathToSave.c_str())) == INVALID_FILE_ATTRIBUTES)
	{
		CreateDirectoryA(m_sPathToSave.c_str(), 0);
	}
#endif
}

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	
BOOL IsDirectory(const char *pDir)
{
	char szCurPath[500];
	ZeroMemory(szCurPath, 500);
	sprintf_s(szCurPath, 500, "%s//*", pDir);
	WIN32_FIND_DATAA FindFileData;
	ZeroMemory(&FindFileData, sizeof(WIN32_FIND_DATAA));

	HANDLE hFile = FindFirstFileA(szCurPath, &FindFileData); /**< find first file by given path. */

	if (hFile == INVALID_HANDLE_VALUE)
	{
		FindClose(hFile);
		return FALSE; /** 如果不能找到第一个文件，那么没有目录 */
	}
	else
	{
		FindClose(hFile);
		return TRUE;
	}

}

BOOL DeleteDirectory(const char * DirName)
{
	//  CFileFind tempFind;     //声明一个CFileFind类变量，以用来搜索  
	char szCurPath[MAX_PATH];       //用于定义搜索格式  
	_snprintf(szCurPath, MAX_PATH, "%s//*.*", DirName); //匹配格式为*.*,即该目录下的所有文件  
	WIN32_FIND_DATAA FindFileData;
	ZeroMemory(&FindFileData, sizeof(WIN32_FIND_DATAA));
	HANDLE hFile = FindFirstFileA(szCurPath, &FindFileData);
	BOOL IsFinded = TRUE;
	while (IsFinded)
	{
		IsFinded = FindNextFileA(hFile, &FindFileData); //递归搜索其他的文件  
		if (strcmp(FindFileData.cFileName, ".") && strcmp(FindFileData.cFileName, "..")) //如果不是"." ".."目录  
		{
			string strFileName = "";
			strFileName = strFileName + DirName + "//" + FindFileData.cFileName;
			string strTemp;
			strTemp = strFileName;
			if (IsDirectory(strFileName.c_str())) //如果是目录，则递归地调用  
			{
				printf("目录为:%s/n", strFileName.c_str());
				DeleteDirectory(strTemp.c_str());
			}
			else
			{
				DeleteFileA(strTemp.c_str());
			}
		}
	}
	FindClose(hFile);

	BOOL bRet = RemoveDirectoryA(DirName);
	if (bRet == 0) //删除目录  
	{
		printf("删除%s目录失败！/n", DirName);
		return FALSE;
	}
	return TRUE;
}

#endif

/************************************************************************/
/* 删除目录                                                              */
/************************************************************************/
void DSFileUpdate::DeleteOldResourceDirAndCreateDir()
{
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
	CCFileUtils::getInstance()->removeDirectory(m_sPathToSave);
	CCFileUtils::getInstance()->createDirectory(m_sPathToSave);
//#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
//	string command = "rm -r ";
//	// Path may include space.
//	command += m_sPathToSave;
//	system(command.c_str());
//	//string command = "rm ";
//	// Path may include space.
//	//command += "\"" + m_sPathToSave + "\"";
//	//system(command.c_str());
//	
//	//mkdir(m_sPathToSave.c_str(), S_IRWXU | S_IRWXG | S_IRWXO);
#else
	if ((GetFileAttributesA(m_sPathToSave.c_str())) != INVALID_FILE_ATTRIBUTES)
	{
		DeleteDirectory(m_sPathToSave.c_str());
	}

	if ((GetFileAttributesA(m_sPathToSave.c_str())) == INVALID_FILE_ATTRIBUTES)
	{
		CreateDirectoryA(m_sPathToSave.c_str(), 0);
	}
#endif
}

/************************************************************************/
/* 文件更新检测                                                          */
/************************************************************************/
void DSFileUpdate::runVersionCheck(DSFileUpdate * pFileUpdate)
{
	pthread_mutex_init(&s_FileUpdateMutex, NULL);
	pthread_create(&s_networkThread, NULL, networkCheckThread, pFileUpdate);
	pthread_detach(s_networkThread);
}

/************************************************************************/
/* 开启网络线程检测更新                                                   */
/************************************************************************/
void* DSFileUpdate::networkCheckThread(void * data)
{
	pthread_mutex_lock(&s_FileUpdateMutex);

	s_isdownList = true;

	DSFileUpdate * pdsFileUpdate = (DSFileUpdate *)data;
	if (pdsFileUpdate)
	{
		pdsFileUpdate->CheckVersion();
	}

	pthread_mutex_unlock(&s_FileUpdateMutex);
	pthread_mutex_destroy(&s_FileUpdateMutex);
	pthread_exit(NULL);

	
	return 0;
}

/************************************************************************/
/* 启动文件更新线程                                                      */
/************************************************************************/
void DSFileUpdate::runFileUpdate(DSFileUpdate * pFileUpdate)
{
	pthread_mutex_init(&s_FileUpdateMutex, NULL);
	pthread_create(&s_networkThread, NULL, networkUpdateThread, pFileUpdate);
	pthread_detach(s_networkThread);
}

/************************************************************************/
/* 开启网络线程                                                          */
/************************************************************************/
void* DSFileUpdate::networkUpdateThread(void * data)
{
	pthread_mutex_lock(&s_FileUpdateMutex);

	s_isdownList = false;
 	DSFileUpdate * pdsFileUpdate = (DSFileUpdate *)data;
 	if (pdsFileUpdate)
 	{
 		pdsFileUpdate->UpdateVersion();
 	}

	pthread_mutex_unlock(&s_FileUpdateMutex);
	pthread_mutex_destroy(&s_FileUpdateMutex);
	pthread_exit(NULL);

	return 0;
}

/************************************************************************/
/* 处理下载进度                                                          */
/************************************************************************/
int DSFileUpdate::progressFunc(void * ptr, double totalToDownload, double nowDownloaded, double totalToUpLoad, double nowUpLoaded)
{
	if (s_isdownList)
	{
		return 0;
	}

	if ((int)((s_lCurFileLenth + nowDownloaded) / s_lTotalFileLenth * 100) >= 0 && (int)((s_lCurFileLenth + nowDownloaded) / s_lTotalFileLenth * 100) <= 100)
	{
		int n = (int)((s_lCurFileLenth + nowDownloaded) / s_lTotalFileLenth * 100);
		std::stringstream ss;
		ss << n;

		std::string downPecent = ss.str();
		if (s_PreData != downPecent)
		{
			s_PreData = downPecent;
			DSUpdateData * updateData = new DSUpdateData(DSUpdateDownLoad, downPecent);
			if (updateData)
			{
				s_pFileUpdate->s_updateData->addObject(updateData);
				CCDirector::sharedDirector()->getScheduler()->resumeTarget(s_pFileUpdate);
			}
			

			CCLOG("downloading... %d", (int)((s_lCurFileLenth + nowDownloaded) / s_lTotalFileLenth * 100));
		}
	}
	return 0;
}

/************************************************************************/
/* 比较两个版本                                                          */
/************************************************************************/
bool DSFileUpdate::determineVersion(string version1, string version2)
{
	int nVersion1 = DSFileUpdate::CheStringToInt(version1.c_str());
	int nVersion2 = DSFileUpdate::CheStringToInt(version2.c_str());

	return 	nVersion1 > nVersion2;
}

/************************************************************************/
/* 比较两个版本                                                          */
/************************************************************************/
bool DSFileUpdate::IsMustUpdate(string newVersion, string oldVersion)
{
	int nNewVersion = DSFileUpdate::CheStringToInt(newVersion.c_str());
	int nOldVersion = DSFileUpdate::CheStringToInt(oldVersion.c_str());
	
	if (GetProductVer(nOldVersion) != GetProductVer(nNewVersion))	return true;
	if (GetMainVer(nOldVersion) != GetMainVer(nNewVersion))			return true;
	if (GetSubVer(nOldVersion) != GetSubVer(nNewVersion))			return true;
	

	//本地的版本不可能比服务器的版本新 所有这个语句
	//if (GetSubVer(nOldVersion) >= GetSubVer(nNewVersion))			return true;

	return false;
}

/************************************************************************/
/* 将字符串的版本号转化为数字的版本号                                     */
/************************************************************************/
dword DSFileUpdate::CheStringToInt(const char *strVer)
{
	string strVersion = strVer;
	vector<int> versionCodes;
	string_util::split_int(strVersion, ".", versionCodes);
	if (versionCodes.size() >= 3)
	{
		return PROCESS_VERSION(versionCodes[0], versionCodes[1], versionCodes[2]);
	}
	else
	{
		log("Version config error!");
		return 0;
	}
}

/************************************************************************/
/* 运行版本检测                                                          */
/************************************************************************/
void DSFileUpdate::runVersionCheck()
{
	DSFileUpdate::runVersionCheck(this);
}

/************************************************************************/
/* 启动文件更新                                                          */
/************************************************************************/
void DSFileUpdate::runFileUpdate()
{
	DSFileUpdate::runFileUpdate(this);
}

/************************************************************************/
/* 下载并加载版本文件                                                          */
/************************************************************************/
void DSFileUpdate::UpdateAndLoadVersionHistoryFile()
{
    m_vVersionList.clear();
	do{
		if(this->downLoad(m_sPathToSave + m_sVersionList,m_sDownFileUrl+m_sVersionList))
		{
			ifstream fin;
			string strLine;
			fin.open((m_sPathToSave + m_sVersionList).c_str());
			if(fin.fail())
			{
                return;
			}
			bool bError = false; //是否参正确读取到版本号
			while(!fin.eof())
			{
				getline(fin,strLine);
                if(strLine != "")
				{
                    string::iterator it;
					
                    for (it = strLine.begin(); it != strLine.end();)
                    {
						if (0xff < it[0] || 0 > it[0] )
						{
							it = strLine.erase(it);
							bError = true;//有错误
						}
                        else if( !isdigit(*it) && *it != '.')
                        {
                            it = strLine.erase(it);
                        }
                        else
                        {
                            ++it;
                        }
                    }
					m_vVersionList.push_back(strLine);
					
				}
			}
			fin.close();
			fin.clear();

			if (bError)
			{
				//cocos2d::log("DSFileUpdate::UpdateAndLoadVersionHistoryFile error download version");
				//cocos2d::log((m_sPathToSave + m_sVersionList).c_str());
			//	cocos2d::log((m_sDownFileUrl + m_sVersionList).c_str());
			}
		}
	}
	while(0);
}

/************************************************************************/
/* 心跳函数                                                             */
/************************************************************************/
bool DSFileUpdate::UpdateAndLoadVersionFile()
{
	if (m_updateType == UT_HOT_WINDOWS || m_updateType == UT_HOT_IOS_UPDATE || m_updateType == UT_HOT_ANDROID_UPDATE || m_updateType == UT_GAME)
	{
		// 1. Urls of package and version should be valid;
		// 2. Package should be a zip file.
		if (((string)this->getPackageUrl()).size() == 0 ||
			std::string::npos == ((string)this->getPackageUrl()).find(".zip"))
		{
			CCLOG("no version file url, or no package url, or the package is not a zip file");
			return false;
		}

		// Check if there is a new version.
		if (!checkUpdate())
			return false;

		string outPath = this->getStoragePath();
		outPath += TEMP_PACKAGE_FILE_NAME;
		if (!downLoad(outPath, this->getPackageUrl()))
			return false;

		//setPackageFileName(TEMP_PACKAGE_FILE_NAME);

		// 解压失败
		if (!uncompress()) 
			return false;

		// Set resource search path.
		SetSearchFilePath();

		// Delete unloaded zip file.
		string zipfileName = this->getStoragePath();
		zipfileName += TEMP_PACKAGE_FILE_NAME;
		if (remove(zipfileName.c_str()) != 0)
		{
			CCLOG("can not remove downloaded zip file");
		}
	}

	return true;
}

/************************************************************************/
/* 得到下载文件的长度                                                    */
/************************************************************************/
long DSFileUpdate::GetDownloadFileLenth(const char *url)
{
	double downloadFileLenth = 0;

	CURL *handle = curl_easy_init();
	curl_easy_setopt(handle, CURLOPT_URL, url);
	curl_easy_setopt(handle, CURLOPT_HTTPGET, 1);
	curl_easy_setopt(handle, CURLOPT_NOBODY, 1);
	curl_easy_setopt(handle, CURLOPT_TIMEOUT, 20);
	curl_easy_setopt(handle, CURLOPT_CONNECTTIMEOUT, 20);

	CURLcode res = curl_easy_perform(handle);
	if (res == CURLE_OK)
	{
		long responseCode;
		curl_easy_getinfo(handle, CURLINFO_RESPONSE_CODE, &responseCode);

		if (200 == responseCode)
		{
			curl_easy_getinfo(handle, CURLINFO_CONTENT_LENGTH_DOWNLOAD, &downloadFileLenth);
		}
		else
		{
			downloadFileLenth = -1;

			DSUpdateData *updateData = new DSUpdateData(DSUpdateNetError, m_sCurVersion);
			if (updateData)
			{
				s_updateData->addObject(updateData);
				CCDirector::sharedDirector()->getScheduler()->resumeTarget(this);
			}
			
			CCLOG("down failed!");
		}
	}
	else
	{
		downloadFileLenth = -1;
		DSUpdateData * updateData = new DSUpdateData(DSUpdateNetError, m_sCurVersion);
		if(updateData)
		{
			s_updateData->addObject(updateData);
			CCDirector::sharedDirector()->getScheduler()->resumeTarget(this);
		}
		
		CCLOG("down failed!");
	}
	curl_easy_cleanup(handle);

	return (long)downloadFileLenth;
}

/************************************************************************/
/* 设置搜索路径                                                          */
/************************************************************************/
void DSFileUpdate::SetSearchFilePath()
{
	vector<string> searchPaths = CCFileUtils::sharedFileUtils()->getSearchPaths();
	vector<string>::iterator itr = searchPaths.begin();

	while (itr != searchPaths.end())
	{
		CCLOG("%s", (*itr).c_str());
		if (*itr == m_sPathToSave)
		{
			//itr = searchPaths.erase(itr);
			return;
		}
		else
		{
			++itr;
		}
	}

	searchPaths.insert(searchPaths.begin(), m_sPathToSave);
	CCFileUtils::sharedFileUtils()->setSearchPaths(searchPaths);
}


/************************************************************************/
/* 下载文件                                                             */
/************************************************************************/
bool DSFileUpdate::downLoad(string outPath, string PackageUrl)
{
	// Create a file to save package.
	string outFileName = outPath;

	CURL *_curl = curl_easy_init();

	if (!_curl)
	{
		CCLOG("can not init curl");
		return false;
	}

	// Download pacakge
	FILE *fp = fopen(outPath.c_str(), "wb");
	if (!fp)
	{
		CCLOG("can not create file %s", outPath.c_str());
		return false;
	}

	CURLcode res;
	curl_easy_setopt(_curl, CURLOPT_URL, PackageUrl.c_str());
	curl_easy_setopt(_curl, CURLOPT_WRITEFUNCTION, downLoadPackage);
	curl_easy_setopt(_curl, CURLOPT_WRITEDATA, fp);
	curl_easy_setopt(_curl, CURLOPT_NOPROGRESS, false);
	curl_easy_setopt(_curl, CURLOPT_PROGRESSFUNCTION, progressFunc);
	curl_easy_setopt(_curl, CURLOPT_NOSIGNAL, 1L);
	curl_easy_setopt(_curl, CURLOPT_LOW_SPEED_LIMIT, 1L);
	curl_easy_setopt(_curl, CURLOPT_LOW_SPEED_TIME, 5L);
	curl_easy_setopt(_curl, CURLOPT_CONNECTTIMEOUT, 60);

	res = curl_easy_perform(_curl);

	if (res != 0)
	{
		CCLOG("error when download package");
		fclose(fp);
		if (s_isdownList)
		{
			this->removeDownFile(m_sVersionList);
		}

		if (_curl)
		{
			curl_easy_cleanup(_curl);
		}
		return false;
	}

	CCLOG("succeed downloading package %s", PackageUrl.c_str());

	fclose(fp);

	if (_curl)
	{
		curl_easy_cleanup(_curl);
	}

	return true;
}

/************************************************************************/
/* 检查更新                                                              */
/************************************************************************/
bool DSFileUpdate::checkUpdate()
{
	return true;
}

/************************************************************************/
/* 下载包                                                               */
/************************************************************************/
size_t DSFileUpdate::downLoadPackage(void *ptr, size_t size, size_t nmemb, void *userdata)
{
    FILE *fp = (FILE*)userdata;
    size_t written = fwrite(ptr, size, nmemb, fp);
    return written;
}

#if (CC_TARGET_PLATFORM != CC_PLATFORM_ANDROID)
#include <ftw.h>
#endif
namespace
{
#if (CC_TARGET_PLATFORM != CC_PLATFORM_ANDROID)
    int unlink_cb(const char *fpath, const struct stat *sb, int typeflag, struct FTW *ftwbuf)
    {
        int rv = remove(fpath);
        
        if (rv)
            perror(fpath);
        
        return rv;
    }
#endif
}

/************************************************************************/
/* 移除下载文件                                                          */
/************************************************************************/
void DSFileUpdate::removeDownFile(string fileName)
{
#if !defined(CC_TARGET_OS_TVOS)
#if (CC_TARGET_PLATFORM != CC_PLATFORM_ANDROID)
    nftw(fileName.c_str(), unlink_cb, 64, FTW_DEPTH | FTW_PHYS);
    
#else
 
	// Remove downloaded files
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
	string command = "rm ";
	// Path may include space.
	command += "\"" + m_sPathToSave +fileName + "\"";
	system(command.c_str());
#else
	std::string strFullPath = m_sPathToSave + fileName;
	if ((GetFileAttributesA(strFullPath.c_str())) != INVALID_FILE_ATTRIBUTES)
	{
		RemoveDirectoryA(strFullPath.c_str());
	}
#endif
    
#endif // (CC_TARGET_PLATFORM != CC_PLATFORM_ANDROID)
#endif // !defined(CC_TARGET_OS_TVOS
}

/************************************************************************/
/* 下载回调函数                                                          */
/************************************************************************/
void DSFileUpdate::DSUpdateCallLuaFunc(float delta)
{
	DSUpdateData* updateData = NULL;
    
	if (s_updateData->count())
    {
		updateData = dynamic_cast<DSUpdateData*>(s_updateData->objectAtIndex(0));
		s_updateData->removeObjectAtIndex(0);
    }
    
	int status = DSUpdateUnKnowed;
    if (updateData)
    {
		status = updateData->m_status;

		LuaEngine * pEngine = LuaEngine::defaultEngine();
		if (pEngine){

			LuaStackEx * luaStack = static_cast<LuaStackEx*>(pEngine->getLuaStack());
			luaStack->call_script_fun(m_sCallBackFunc, (int)updateData->m_status, updateData->m_data.c_str(), updateData->m_strCurrentVersion.c_str(), updateData->m_strNewestVersion.c_str());
		}

        updateData->release();
	}
    
	if (status == DSUpdateFinish || status == DSUpdateNoNewVersion || status == DSUpdateNetError)
	{
		CCDirector::sharedDirector()->getScheduler()->pauseTarget(this);
	}
	else
	{
		if (0 == s_updateData->count())
		{
			CCDirector::sharedDirector()->getScheduler()->pauseTarget(this);
		}
	}
	
}


