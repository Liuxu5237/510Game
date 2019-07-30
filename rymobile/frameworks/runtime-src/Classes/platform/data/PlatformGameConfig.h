#ifndef		_PLATFORM_GAME_CONFIG_H_
#define		_PLATFORM_GAME_CONFIG_H_

#include "cocos2d.h"
USING_NS_CC;
class CPlatformGameConfig : public cocos2d::Ref
{
private:
	// 构造函数
	CPlatformGameConfig();

	// 析构函数
	~CPlatformGameConfig();

public:
	static CPlatformGameConfig * st_platformGameConfig;
	//获取对象
	static CPlatformGameConfig * shared();

	//销毁对象
	static void purge();

public:

	// 加载配置文件
	void loadConfig();
	
	// 得到当前的字符串
	std::string getValue(int gameID, const char * key);


protected:

	CCArray * m_configData;
};

#endif