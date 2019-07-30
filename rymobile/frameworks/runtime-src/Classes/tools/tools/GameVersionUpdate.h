#ifndef __GAME_VERSION_UPDATE__
#define __GAME_VERSION_UPDATE__

#include "DSFileUpdate.h"

class GameVersionUpdate : public DSFileUpdate
{
private:
	// ���캯��
	GameVersionUpdate();

public:
	// ��������
	virtual ~GameVersionUpdate();

public:

	// �õ�����ģ���ʵ��
	static GameVersionUpdate * getInstance();

	// ��������ģ���ʵ��
	static void destroyInstance();

public:

	// ���汾
	virtual bool CheckVersion();

	// ���°汾
	virtual void UpdateVersion();

protected:

	virtual DSUpdateType getUpdateType(std::string newVerson, std::string currentVersion);
};

#endif //__DSFILEUPDATE__

