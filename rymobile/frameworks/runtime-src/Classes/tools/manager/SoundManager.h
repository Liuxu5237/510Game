#ifndef _SoundManager_H_
#define _SoundManager_H_

#include "cocos2d.h"

class SoundManager : public cocos2d::Ref
{
public:
	static SoundManager* shared();
	static void purge();

public:
	void playSound(const char* sound, bool bLoop = false);
	void playFishSound(const char* sound, bool occupy, bool bLoop = false);
	void stopSound(const char* sound);
	void playMusic(const char* music);
	void stopMusic();
	void stopAllSound();
	void stopAllEffect();
	void resumeAllEffects();
	///<播放鱼声音特效
	void playFishSound(int bird_type);

	float getMusicVolume() const;
	float getSoundVolume() const;
	void setMusicVolume(float volume);
	void setSoundVolume(float volume);

	void saveSettings();
	virtual void update(float dt);
private:
    SoundManager();
    ~SoundManager();
    bool init();

	const char*	stringFromKey(const std::string& key);  
	void preloadEffect(const char* name);
public:
	void preloadMusic(const char* name);

private:
	cocos2d::CCDictionary* _dict;
	std::map<std::string, unsigned int> _dictSound;

	float mMusicVolume;
	float mSoundVolume;
	///< 逝去的时间
	float mPastTime;
	///< 是否被占用
	bool mOccupy;
	///< 切换场景暂停音效
    
    int m_audid; //音乐id
    int m_effAudid; //音效id

};

#define PLAY_BUTTON_CLICK_EFFECT SoundManager::shared()->playSound("platform_Btn_Click");
#define PLAY_BUTTON_CLOSE_EFFECT SoundManager::shared()->playSound("platform_Btn_Close");
#define PLAY_PLATFORM_BG_MUSIC SoundManager::shared()->playMusic("platform_BG");
#endif // _SoundManager_H_
