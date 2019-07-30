#ifndef __PLATFORM_VERSION_UPDATE__
#define __PLATFORM_VERSION_UPDATE__

#include "DSFileUpdate.h"

class PlatformVersionUpdate : public DSFileUpdate
{
private:
	// 构造函数
	PlatformVersionUpdate();

public:
	// 析构函数
	virtual ~PlatformVersionUpdate();

public:

	// 得到下载模块的实例
	static PlatformVersionUpdate * getInstance();

	// 销毁下载模块的实例
	static void destroyInstance();

public:

	// 检测版本
	virtual bool CheckVersion();

	// 更新版本
	virtual void UpdateVersion();

	// 设置搜索路径
	virtual void SetSearchFilePath();

protected:

	// 得到更新的类型
	virtual DSUpdateType getUpdateType(std::string newVerson, std::string currentVersion);
};

#endif //__DSFILEUPDATE__

