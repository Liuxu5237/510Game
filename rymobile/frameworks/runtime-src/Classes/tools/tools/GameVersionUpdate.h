#ifndef __GAME_VERSION_UPDATE__
#define __GAME_VERSION_UPDATE__

#include "DSFileUpdate.h"

class GameVersionUpdate : public DSFileUpdate
{
private:
	// 构造函数
	GameVersionUpdate();

public:
	// 析构函数
	virtual ~GameVersionUpdate();

public:

	// 得到下载模块的实例
	static GameVersionUpdate * getInstance();

	// 销毁下载模块的实例
	static void destroyInstance();

public:

	// 检测版本
	virtual bool CheckVersion();

	// 更新版本
	virtual void UpdateVersion();

protected:

	virtual DSUpdateType getUpdateType(std::string newVerson, std::string currentVersion);
};

#endif //__DSFILEUPDATE__

