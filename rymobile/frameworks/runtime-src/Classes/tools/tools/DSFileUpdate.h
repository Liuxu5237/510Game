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

// ����״̬
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

// ��������
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


//��Ϣ
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
	// ���캯��
	DSFileUpdate(const char* packageUrl = NULL, const char* versionFileUrl = NULL, const char* storagePath = NULL);

	// ��������
	virtual ~DSFileUpdate();

public:

	// ���汾
	virtual bool CheckVersion() = 0;

	// ���°汾
	virtual void UpdateVersion() = 0;

protected:

	// �õ���������
	virtual DSUpdateType getUpdateType(std::string newVerson, std::string currentVersion) = 0;

public:
	
	// ���������ļ�·��
	void setDownFileUrl(string url);

	// ���ð汾�ļ�����
	void setVersionList(string iniName);

	// ע��汾���»ص�����
	void registerFileUpdateCallBack(string func);

	// ���ñ���·����
	void setSaveKey(string key);

	// ��������Ŀ¼
	void createDownloadedDir(const char *Path);

	// ��������·��
	virtual void SetSearchFilePath();

	// ɾ������Ŀ¼
	void DeleteOldResourceDirAndCreateDir();

public:

	// �ļ����¼��
	static void runVersionCheck(DSFileUpdate * pFileUpdate);

	// �����ļ�����
	static void runFileUpdate(DSFileUpdate * pFileUpdate);

	// ���ַ���ת��Ϊ���εİ汾��
	static dword CheStringToInt(const char *strVer);

protected:

	// ����߳�
	static void* networkCheckThread(void *data);

	// �����߳�
	static void* networkUpdateThread(void *data);

	// ���ؽ��ȴ���
	static int progressFunc(void *ptr, double totalToDownload, double nowDownloaded, double totalToUpLoad, double nowUpLoaded);

	
	
	// �Ƚϰ汾�Ĳ���
	static bool determineVersion(string version1, string verson2);

	// �Ƿ�ǿ�Ƹ���
	static bool IsMustUpdate(string version1, string version2);

	// ���ذ�
	static size_t downLoadPackage(void *ptr, size_t size, size_t nmemb, void *userdata);

protected:

	// ���а汾���
	void runVersionCheck();

	// ����ӿ� �����ļ�����
	void runFileUpdate();

protected:

	// ���ز����°汾�ļ�
	void UpdateAndLoadVersionHistoryFile();

	//��������
	bool UpdateAndLoadVersionFile();

	//�õ������ļ��ĺ���
	long GetDownloadFileLenth(const char *url);

private:

	// �����ļ�
	bool downLoad(string outPath,string PackageUrl);

	// �Ƴ��ļ�
	void removeDownFile(string fileName);

	// ��������ļ�
	virtual bool checkUpdate();

	//���ػص�����
	void DSUpdateCallLuaFunc(float delta);

protected:
	// �����·��
	string				m_sPathToSave;

	// �����ļ���·��
	string				m_sDownFileUrl;

	// �汾�ļ���·��
	string				m_sVersionList;
	
	// ��ǰ�İ汾��
	string				m_sCurVersion;

	// ������ļ���
	string				m_save_file_key;

	//���ص��б�
	vector<string>		m_vVersionList;

	//  lua�ص�����������
	string				m_sCallBackFunc;

	// �ļ����صĴ�С
    vector<float>		m_vListLenth;

	// ��ǰ�����˼���
    int					m_nListCount;

	// ���ص�����
	DSUpdateType		m_updateType;

protected:

	// �������ļ���С
	static long			s_lTotalFileLenth;

	// ��ǰ�����ļ���С
	static long			s_lCurFileLenth;

	// ��ǰ���صİٷֱ�
	static string		s_PreData;

	// �Ƿ������ذ汾�б�
	static bool			s_isdownList;

	// �Ƿ���Ҫ����
	static bool			s_needUpdate;

protected:

	static DSFileUpdate *	s_pFileUpdate;
	static Array *			s_updateData;
};

#endif //__DSFILEUPDATE__

