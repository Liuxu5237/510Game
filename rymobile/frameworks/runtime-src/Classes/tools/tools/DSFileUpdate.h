#ifndef __DSFILEUPDATE__
#define __DSFILEUPDATE__

#include "cocos2d.h"
#include "extensions/assets-manager/AssetsManager.h"
#include "extensions/cocos-ext.h" 
#include <fstream>
#include <vector>
#include "platform/df/types.h"
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
#include <dirent.h>
#include <sys/stat.h>
#endif

#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_LINUX
#include "pthread.h"
#endif

#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
#include "pthread.h"
#endif

USING_NS_CC;
USING_NS_CC_EXT;
using namespace std;

// 更新状态
enum DSUpdateStatus
{
	DSUpdateUnKnowed = -1,
	DSUpdateNetError = 0,
	DSUpdateDownLoad = 1,
	DSUpdateFinish = 2,
	DSUpdateNoNewVersion = 3,
	DSUpdateNeed = 4,
	DSUpdateNeedSmall = 5,
	DSUpdateNeedMust = 6,
	DSUpdateClientAPK = 7,
	DSUpdateClientIPA = 8,
};

// 更新类型
enum DSUpdateType
{
	UT_ERROR = -1,

	UT_DONT_NEED_UPDATE = 0,

	UT_UPDATE_APK = 1,
	UT_UPDATE_IPA = 2,

	UT_HOT_WINDOWS = 3,
	UT_HOT_IOS_UPDATE = 4,
	UT_HOT_ANDROID_UPDATE = 5,

	UT_GAME = 6,
};


//信息
class DSUpdateData : public Object
{
public:
	DSUpdateStatus m_status;
	std::string m_data;
	std::string m_strCurrentVersion;
	std::string m_strNewestVersion;

	DSUpdateData(DSUpdateStatus status, string data)
	{
		m_status = status;
		m_data = data;
	}

	void SetCurrentVersion(std::string & version){ m_strCurrentVersion = version; }

	void SetNewestVersion(std::string & version){ m_strNewestVersion = version; }
	
};

class DSFileUpdate : public AssetsManager
{
protected:
	// 构造函数
	DSFileUpdate(const char* packageUrl = NULL, const char* versionFileUrl = NULL, const char* storagePath = NULL);

	// 析构函数
	virtual ~DSFileUpdate();

public:

	// 检测版本
	virtual bool CheckVersion() = 0;

	// 更新版本
	virtual void UpdateVersion() = 0;

protected:

	// 得到更新类型
	virtual DSUpdateType getUpdateType(std::string newVerson, std::string currentVersion) = 0;

public:
	
	// 设置下载文件路径
	void setDownFileUrl(string url);

	// 设置版本文件名字
	void setVersionList(string iniName);

	// 注册版本更新回调函数
	void registerFileUpdateCallBack(string func);

	// 设置保存路径名
	void setSaveKey(string key);

	// 创建下载目录
	void createDownloadedDir(const char *Path);

	// 设置搜索路径
	virtual void SetSearchFilePath();

	// 删除下载目录
	void DeleteOldResourceDirAndCreateDir();

public:

	// 文件更新检测
	static void runVersionCheck(DSFileUpdate * pFileUpdate);

	// 启动文件更新
	static void runFileUpdate(DSFileUpdate * pFileUpdate);

	// 将字符串转化为整形的版本号
	static dword CheStringToInt(const char *strVer);

protected:

	// 检测线程
	static void* networkCheckThread(void *data);

	// 更新线程
	static void* networkUpdateThread(void *data);

	// 下载进度处理
	static int progressFunc(void *ptr, double totalToDownload, double nowDownloaded, double totalToUpLoad, double nowUpLoaded);

	
	
	// 比较版本的差异
	static bool determineVersion(string version1, string verson2);

	// 是否强制更新
	static bool IsMustUpdate(string version1, string version2);

	// 下载包
	static size_t downLoadPackage(void *ptr, size_t size, size_t nmemb, void *userdata);

protected:

	// 运行版本检测
	void runVersionCheck();

	// 对外接口 启动文件更新
	void runFileUpdate();

protected:

	// 下载并更新版本文件
	void UpdateAndLoadVersionHistoryFile();

	//心跳函数
	bool UpdateAndLoadVersionFile();

	//得到下载文件的航渡
	long GetDownloadFileLenth(const char *url);

private:

	// 下载文件
	bool downLoad(string outPath,string PackageUrl);

	// 移除文件
	void removeDownFile(string fileName);

	// 检查下载文件
	virtual bool checkUpdate();

	//下载回调函数
	void DSUpdateCallLuaFunc(float delta);

protected:
	// 保存的路径
	string				m_sPathToSave;

	// 下载文件的路径
	string				m_sDownFileUrl;

	// 版本文件的路径
	string				m_sVersionList;
	
	// 当前的版本号
	string				m_sCurVersion;

	// 保存的文件名
	string				m_save_file_key;

	//下载的列表
	vector<string>		m_vVersionList;

	//  lua回到函数的名字
	string				m_sCallBackFunc;

	// 文件下载的大小
    vector<float>		m_vListLenth;

	// 当前下载了计数
    int					m_nListCount;

	// 下载的类型
	DSUpdateType		m_updateType;

protected:

	// 总下载文件大小
	static long			s_lTotalFileLenth;

	// 当前下载文件大小
	static long			s_lCurFileLenth;

	// 先前下载的百分比
	static string		s_PreData;

	// 是否在下载版本列表
	static bool			s_isdownList;

	// 是否需要更新
	static bool			s_needUpdate;

protected:

	static DSFileUpdate *	s_pFileUpdate;
	static Array *			s_updateData;
};

#endif //__DSFILEUPDATE__

