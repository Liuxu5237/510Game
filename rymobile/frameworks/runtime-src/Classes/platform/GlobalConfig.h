#ifndef GLOBALCONFIG_H_
#define GLOBALCONFIG_H_

#include "cocos2d.h"

USING_NS_CC;
///< 全局配置..
class GlobalConfig
{
public:
	GlobalConfig() : isPlayMusic(true),
		isPlayEffect(true),
		isShake(true),
		isSpecialEffect(true),
		isChat(true)
	{
		loadGlobalConfig();
	}

	~GlobalConfig()
	{
		
	}

	static GlobalConfig * getInstance(){
		static GlobalConfig _instance;
		
		return &_instance;
	}

	void setIsPlayMusic(bool playmusic) {
		isPlayMusic = playmusic;
	}
	bool getIsPlayMusic() {
		return isPlayMusic;
	}

	void setIsPlayEffect(bool playeffect){
		isPlayEffect = playeffect;
	}
	bool getIsPlayEffect(){
		return isPlayEffect;
	}

	void setIsShake(bool shake){
		isShake = shake;
	}
	bool getIsShake(){
		return isShake;
	}

	void setIsSpecialEffect(bool specialeffect){
		isSpecialEffect = specialeffect;
	}
	bool getIsSpecialEffect(){
		return isSpecialEffect;
	}

	void setIsChat(bool chat){
		isChat = chat;
	}
	bool getIsChat(){
		return isChat;
	}

	bool saveGlobalConfig()
	{
		auto userDefault = UserDefault::getInstance();

		userDefault->setBoolForKey("canPlayMusic", isPlayMusic);
		userDefault->setBoolForKey("canPlayEffect", isPlayEffect);
		userDefault->setBoolForKey("canShake", isShake);
		userDefault->setBoolForKey("canSpecialEffect", isSpecialEffect);
		userDefault->setBoolForKey("canChat", isChat);

		userDefault->flush();

		return true;
	}

private:
	void loadGlobalConfig()
	{
		auto userDefault = UserDefault::getInstance();

		isPlayMusic = userDefault->getBoolForKey("canPlayMusic", isPlayMusic);
		isPlayEffect = userDefault->getBoolForKey("canPlayEffect", isPlayMusic);
		isShake = userDefault->getBoolForKey("canShake", isPlayMusic);
		isSpecialEffect = userDefault->getBoolForKey("canSpecialEffect", isPlayMusic);
		isSpecialEffect = userDefault->getBoolForKey("canChat", isChat);
	}
protected:
	
	///< 是播放音乐
	bool isPlayMusic;
	///< 是播放音效
	bool isPlayEffect;
	///< 是震动
	bool isShake;
	///< 是显示特效
	bool isSpecialEffect;
	///< 是聊天
	bool isChat;
};


#endif
