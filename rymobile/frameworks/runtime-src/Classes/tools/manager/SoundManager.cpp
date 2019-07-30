#include "SoundManager.h"
#include "SimpleAudioEngine.h"
#include "../core/CCUserDefault.h"
#include "../../platform/GlobalConfig.h"
#include "AudioEngine.h"
USING_NS_CC;

using namespace std;
using namespace CocosDenshion;


//定义SoundManager对象
static SoundManager* _sharedSoundManager = 0;

//得到SoundManager单例对象
SoundManager* SoundManager::shared()
{
	if(_sharedSoundManager == 0){
		_sharedSoundManager = new SoundManager();
		_sharedSoundManager->init();
	}
	return _sharedSoundManager;
}

//当内存不足时调用
void SoundManager::purge()
{
	CC_SAFE_RELEASE_NULL(_sharedSoundManager);
}


SoundManager::SoundManager() : mPastTime(0.0f), mOccupy(false),m_audid(0)
{
    //大厅的音乐停掉
    cocos2d::experimental::AudioEngine::stopAll();
}

SoundManager::~SoundManager()
{
	auto scheduler = Director::getInstance()->getScheduler();
	scheduler->unschedule(SEL_SCHEDULE(&SoundManager::update), this);

    cocos2d::experimental::AudioEngine::stopAll();
    
    
//	SimpleAudioEngine::sharedEngine()->stopBackgroundMusic(true);
//	SimpleAudioEngine::sharedEngine()->stopAllEffects();
//	SimpleAudioEngine::sharedEngine()->end();

	mPastTime = 0.0F;
	mOccupy = false;

	saveSettings();

	CC_SAFE_RELEASE_NULL(_dict);
}

//初始化
bool SoundManager::init()
{
	_dict = CCDictionary::createWithContentsOfFile("sounds.plist");
	CC_SAFE_RETAIN(_dict);
	
	mMusicVolume = MyUserDefault::getInstance()->getFloatForKey("audio", "music", 1);
	mSoundVolume = MyUserDefault::getInstance()->getFloatForKey("audio", "sound", 1);
	setMusicVolume(mMusicVolume);
	setSoundVolume(mSoundVolume);

	const char* sound_file = stringFromKey("jinbi");
	preloadEffect(sound_file);

	sound_file = stringFromKey("superarm");
	preloadEffect(sound_file);

	sound_file = stringFromKey("catch");
	preloadEffect(sound_file);

	sound_file = stringFromKey("catch");
	preloadEffect(sound_file);

	sound_file = stringFromKey("cannon_add");
	preloadEffect(sound_file);

	sound_file = stringFromKey("bingo");
	preloadEffect(sound_file);

	for (int i = 0; i < 3; i++)
	{
		std::string str = StringUtils::format("fire%d", i);
		preloadEffect(str.c_str());
	}

	for (int i = 0; i < 10; i++)
	{
		std::string str = StringUtils::format("smallFish_%d", i);
		preloadEffect(str.c_str());
	}

	for (int i = 0; i < 7; i++)
	{
		std::string str = StringUtils::format("bigFish_%d", i);
		preloadEffect(str.c_str());
	}


	auto scheduler = Director::getInstance()->getScheduler();
	scheduler->schedule(SEL_SCHEDULE(&SoundManager::update), this, 0.5f, false);
	return true;
}

void SoundManager::saveSettings()
{
	MyUserDefault::getInstance()->setFloatForKey("audio", "music", mMusicVolume);
	MyUserDefault::getInstance()->setFloatForKey("audio", "sound", mSoundVolume);
}

//根据键值得到String类型数据
const char* SoundManager::stringFromKey(const std::string& key)
{
	const CCString* str = _dict->valueForKey(key);

	return str == 0 ? 0 : str->getCString();
}

void SoundManager::preloadEffect(const char* name)
{

	const char* sound_file = stringFromKey(name);

	if (sound_file != 0 && sound_file[0] != 0)
	{
        
		//SimpleAudioEngine::sharedEngine()->preloadEffect(sound_file);
        cocos2d::experimental::AudioEngine::preload(sound_file);
	}
}

void SoundManager::playSound(const char* sound, bool bLoop)
{
	//return; 被占据,并且上一个也在被占据,并且时间不为为0
	bool canPlay = GlobalConfig::getInstance()->getIsPlayEffect();
	if (!canPlay) return;
	const char* sound_file = stringFromKey(sound);

//	log("music path is %s", sound_file);
	if (sound_file != 0 && sound_file[0] != 0)
	{
		//unsigned int effect = SimpleAudioEngine::sharedEngine()->playEffect(sound_file, bLoop);
        unsigned int effect = cocos2d::experimental::AudioEngine::play2d(sound_file,bLoop);
		if (bLoop)
		{
			stopSound(sound);
			_dictSound[sound]= effect;
		}
	}
}


void SoundManager::playFishSound(const char* sound, bool occupy, bool bLoop /*= false*/)
{
	if (mOccupy &&  mPastTime != 0.0f)
	{
		//log("music no play!! %s ", sound);
		return;
	}
	if (mPastTime == 0.0f)
	{
		mOccupy = occupy;
		mPastTime = 0.1f;
	}
		

	playSound(sound, bLoop);
}


void SoundManager::playFishSound(int bird_type)
{
	///<高分鱼声音特效
	if (bird_type >= 14)
	{
		char sCatch_1[16] = { 0 };
		sprintf(sCatch_1, "bigFish_%d", rand() % 7);
		playFishSound(sCatch_1, true);
		playSound("superarm");
	}
	else if (bird_type >= 8 && bird_type < 14)
	{
		if (rand() % 3 == 1)
		{
			char sCatch_2[16] = { 0 };
			sprintf(sCatch_2, "smallFish_%d", rand() % 10);
			playFishSound(sCatch_2, true);
		}
		playSound("catch");
	}
	else
	{
		playSound("catch");
	}
}

void SoundManager::stopSound(const char* sound)
{
	//return;
	const char* sound_file = stringFromKey(sound);

	if (sound_file != 0 && sound_file[0] != 0)
	{
		std::map<std::string, unsigned int>::iterator it = _dictSound.find(sound);
		if (it != _dictSound.end())
		{
			SimpleAudioEngine::sharedEngine()->stopEffect(it->second);
			_dictSound.erase(it);
		}
	}
}
void SoundManager::stopAllSound()
{
    cocos2d::experimental::AudioEngine::stopAll();
	//SimpleAudioEngine::getInstance()->stopAllEffects();
	//SimpleAudioEngine::sharedEngine()->stopBackgroundMusic(true);
}
void SoundManager::playMusic(const char* music)
{
	//return;
	bool canPlay = GlobalConfig::getInstance()->getIsPlayMusic();
	if (!canPlay) return;
	const char* sound_file = stringFromKey(music);

    cocos2d::experimental::AudioEngine::stop(m_audid);
	if (sound_file != 0 && sound_file[0] != 0)
	{
        m_audid = cocos2d::experimental::AudioEngine::play2d(sound_file,true);
//		SimpleAudioEngine::sharedEngine()->stopBackgroundMusic(true);
//		SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic(sound_file);
//		SimpleAudioEngine::sharedEngine()->playBackgroundMusic(sound_file, true);
	}
}


void SoundManager::stopMusic()
{
	//SimpleAudioEngine::sharedEngine()->stopBackgroundMusic(true);
}


float SoundManager::getMusicVolume() const
{
	return mMusicVolume;
}

float SoundManager::getSoundVolume() const
{
	return mSoundVolume;
}

void SoundManager::setMusicVolume(float volume)
{
	mMusicVolume = volume;
    cocos2d::experimental::AudioEngine::setVolume(m_audid,volume);
    
	//SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(volume);
}

void SoundManager::setSoundVolume(float volume)
{
	mSoundVolume = volume;
	SimpleAudioEngine::sharedEngine()->setEffectsVolume(volume);
}

void SoundManager::update(float dt)
{
	///< 没有被占用, 不计时
	if (!mOccupy) return;
	mPastTime += dt;
	if (mPastTime >= 3.5f)
	{
		mPastTime = 0.0f;
		mOccupy = !mOccupy;
	}

}

void SoundManager::stopAllEffect()
{
    cocos2d::experimental::AudioEngine::stopAll();
	//SimpleAudioEngine::getInstance()->stopAllEffects();
}

void SoundManager::resumeAllEffects()
{

}

void SoundManager::preloadMusic(const char* name)
{
	const char* sound_file = stringFromKey(name);

	if (sound_file != 0 && sound_file[0] != 0)
	{
         cocos2d::experimental::AudioEngine::preload(sound_file);
		//SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic(sound_file);
	}
}
