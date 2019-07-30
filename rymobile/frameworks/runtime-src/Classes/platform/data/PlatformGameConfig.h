#ifndef		_PLATFORM_GAME_CONFIG_H_
#define		_PLATFORM_GAME_CONFIG_H_

#include "cocos2d.h"
USING_NS_CC;
class CPlatformGameConfig : public cocos2d::Ref
{
private:
	// ���캯��
	CPlatformGameConfig();

	// ��������
	~CPlatformGameConfig();

public:
	static CPlatformGameConfig * st_platformGameConfig;
	//��ȡ����
	static CPlatformGameConfig * shared();

	//���ٶ���
	static void purge();

public:

	// ���������ļ�
	void loadConfig();
	
	// �õ���ǰ���ַ���
	std::string getValue(int gameID, const char * key);


protected:

	CCArray * m_configData;
};

#endif