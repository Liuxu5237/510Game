#include "SoundFun.h"
#include "SimpleAudioEngine.h"
#include "utilityFun.h"
#include "platform/data/GlobalUserInfo.h"
#include "platform/data/PlatformGameConfig.h"
#include "platform/df/DF.h"
#include "tools/tools/MyConfigureData.h"

USING_NS_CC;
using namespace std;
//static const std::string s_soundPath = "Eqw3/raw/";
bool SoundFun::s_bMute = false;
float SoundFun::s_fSound1 = 100;
float SoundFun::s_fSound2 = 100;
bool  SoundFun::m_bIsPlayMusic = true;
bool SoundFun::m_bIsPlayEffect = true;

SoundFun * SoundFun::ms_pkInstance = NULL;

void SoundFun::SetSoundBackground(float fValue)
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume( fValue*(!s_bMute));
	s_fSound1 = fValue;
}

void SoundFun::SetSoundEffect(float fValue)
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->setEffectsVolume(fValue *(!s_bMute));
	s_fSound2 = fValue;
}

void SoundFun::playBackMusic(std::string kName)
{
	stringstream stream;
	stream << DF::shared()->GetGameKindID();
	string path = CPlatformGameConfig::shared()->getValue(DF::shared()->GetGameKindID(), "sound_path");
	kName = path + kName;
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic(kName.c_str(), true);
}

void SoundFun::stopBackMusic()
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
}

void SoundFun::playEffect(std::string kName, bool bPreload)
{
	bool IsPlayEffect = UserDefault::getInstance()->getBoolForKey("canPlayEffect", true);
	if (s_bMute || IsPlayEffect == false)
	{
		return;
	}

	stringstream stream;
	stream << DF::shared()->GetGameKindID();
	string path = CPlatformGameConfig::shared()->getValue(DF::shared()->GetGameKindID(), "sound_path");;
	kName = path + kName;
	if (bPreload)
	{
		CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect(kName.c_str());
	} 
	else
	{
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(kName.c_str());
	}
}

void SoundFun::playEffectDirect(std::string kName, bool bPreload)
{
	bool IsPlayEffect = UserDefault::getInstance()->getBoolForKey("canPlayEffect", true);
	if (s_bMute|| IsPlayEffect == false)
	{
		return;
	}
	if (bPreload)
	{
		CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect(kName.c_str());
	} else
	{
		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(kName.c_str());
	}
}

float SoundFun::GetSoundBackground()
{
	return CocosDenshion::SimpleAudioEngine::sharedEngine()->getBackgroundMusicVolume();
}


void SoundFun::PlaySoundEffect(int sex, int idx)
{
	//传进来从0开始，资源文件又从1开始的
	idx = idx + 1;
	std::string kName;
	if (sex)
	{
		kName = StringUtils::format("joker/fmale/%d.wav", idx);
	} else
	{
		kName = StringUtils::format("joker/male/%d.wav", idx);
	}
	playEffect(kName, false);
}

void SoundFun::playCardByGender(int iGender, std::string kName, bool bPreload)
{
	if (iGender)
	{
		kName = "F_" + kName;
	} else
	{
		kName = "M_" + kName;
	}
	playEffect(kName, bPreload);
}

void SoundFun::PreloadEffectByGender(std::string kName)
{
	playCardByGender(0, kName, true);
	playCardByGender(1, kName, true);
}

void SoundFun::setMute(bool bMute)
{
	if (s_bMute == bMute)
	{
		return;
	}
	SetSoundBackground(s_fSound1);
	SetSoundEffect(s_fSound2);
	s_bMute = bMute;
	cocos2d::UserDefault::sharedUserDefault()->setBoolForKey("Mute", bMute);
}

void SoundFun::playCustomEffect(std::string kName)
{
	if (s_bMute)
	{
		return;
	}

	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(kName.c_str());
}

void SoundFun::PauseBackMusic()
{
	TimeManager::Instance().removeByFun(TIME_CALLBACK(SoundFun::OnResumeBackMusic,this));
	CocosDenshion::SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

void SoundFun::OnResumeBackMusic()
{
	TimeManager::Instance().removeByFun(TIME_CALLBACK(SoundFun::OnResumeBackMusic, this));
	CocosDenshion::SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}

void SoundFun::ResumeBackMusic(float fTime)
{
	float fTempValue = s_fSound2*10.0f;
	if (fTempValue > 1.0f)
	{
		fTempValue = 1.0f;
	}
	CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(fTempValue*(!s_bMute));
	TimeManager::Instance().removeByFun(TIME_CALLBACK(SoundFun::OnResumeBackMusic, this));
	if (fTime > 0.01f)
	{
		TimeManager::Instance().addCerterTimeCB(TIME_CALLBACK(SoundFun::OnResumeBackMusic, this), fTime);
	} else
	{
		OnResumeBackMusic();
	}
}

void SoundFun::PaseEffectMusic()
{
	TimeManager::Instance().removeByFun(TIME_CALLBACK(SoundFun::OnResumeEffectMusic, this));
	CocosDenshion::SimpleAudioEngine::getInstance()->pauseAllEffects();
}

void SoundFun::OnResumeEffectMusic()
{
	TimeManager::Instance().removeByFun(TIME_CALLBACK(SoundFun::OnResumeEffectMusic, this));
	CocosDenshion::SimpleAudioEngine::getInstance()->resumeAllEffects();
}

void SoundFun::ResumeEffectMusic(float fTime)
{
	TimeManager::Instance().removeByFun(TIME_CALLBACK(SoundFun::OnResumeEffectMusic, this));
	if (fTime > 0.01f)
	{
		TimeManager::Instance().addCerterTimeCB(TIME_CALLBACK(SoundFun::OnResumeEffectMusic, this), fTime);
	} else
	{
		OnResumeEffectMusic();
	}
}

void SoundFun::setUseSoudType(int iType)
{

}

void SoundFun::SetPlayMusic(bool bplay)
{
	//m_bIsPlayMusic = bplay;
	UserDefault::getInstance()->setBoolForKey("canPlayMusic", bplay);
	if (bplay == false)
	{
		CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
	} else
	{
		CocosDenshion::SimpleAudioEngine::sharedEngine()->rewindBackgroundMusic();
	}
}

void SoundFun::SetEffect(bool bplay)
{
	UserDefault::getInstance()->setBoolForKey("canPlayEffect", bplay);
	//m_bIsPlayEffect = bplay;
}

bool SoundFun::GetIsPalyMusic()
{
	bool IsPlayMusic = UserDefault::getInstance()->getBoolForKey("canPlayMusic", true);
	return IsPlayMusic;
}

bool SoundFun::GetIsPlayEffect()
{
	bool IsPlayEffect = UserDefault::getInstance()->getBoolForKey("canPlayEffect", true);
	return IsPlayEffect;
}

float SoundFun::GetSoundEffect()
{
	return CocosDenshion::SimpleAudioEngine::sharedEngine()->getEffectsVolume();
}

bool SoundFun::getMute()
{
	return s_bMute;
}



