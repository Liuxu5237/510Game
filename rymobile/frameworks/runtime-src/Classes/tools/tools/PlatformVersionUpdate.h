#ifndef __PLATFORM_VERSION_UPDATE__
#define __PLATFORM_VERSION_UPDATE__

#include "DSFileUpdate.h"

class PlatformVersionUpdate : public DSFileUpdate
{
private:
	// ���캯��
	PlatformVersionUpdate();

public:
	// ��������
	virtual ~PlatformVersionUpdate();

public:

	// �õ�����ģ���ʵ��
	static PlatformVersionUpdate * getInstance();

	// ��������ģ���ʵ��
	static void destroyInstance();

public:

	// ���汾
	virtual bool CheckVersion();

	// ���°汾
	virtual void UpdateVersion();

	// ��������·��
	virtual void SetSearchFilePath();

protected:

	// �õ����µ�����
	virtual DSUpdateType getUpdateType(std::string newVerson, std::string currentVersion);
};

#endif //__DSFILEUPDATE__

