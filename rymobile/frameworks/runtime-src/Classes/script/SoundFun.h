
#ifndef __SoundFun_FUN_H__
#define __SoundFun_FUN_H__

#include "cocos2d.h"
#include "TimeNode.h"
#include "../fv/FvSingleton.h"

class SoundFun : public TimeNode
{
public:

	static SoundFun *Instance()
	{
		if (ms_pkInstance == nullptr)
		{
			ms_pkInstance = new SoundFun;
		}
		return ms_pkInstance;
	}

protected:
	static SoundFun *ms_pkInstance;

public:
	void playBackMusic(std::string kName);
	void stopBackMusic();
	void playEffect(std::string kName, bool bPreload = false);
	void playCardByGender(int iGender, std::string kName, bool bPreload = false);
	void PreloadEffectByGender(std::string kName);
	void SetSoundBackground(float fValue);
	void SetSoundEffect(float fValue);
	void setMute(bool bMute);
	bool getMute();

	void playEffectDirect(std::string kName, bool bPreload= false);
	void playCustomEffect(std::string kName);

	void SetPlayMusic(bool bplay);
	void SetEffect(bool bplay);

	bool GetIsPalyMusic();
	bool GetIsPlayEffect();

	void PlaySoundEffect(int sex, int idx);

	void PauseBackMusic();
	void OnResumeBackMusic();
	void ResumeBackMusic(float fTime = 0.f);

	void PaseEffectMusic();
	void OnResumeEffectMusic();
	void ResumeEffectMusic(float fTime = 0.f);

	float GetSoundBackground();

	void setUseSoudType(int iType);

	float GetSoundEffect();
public:

	static bool s_bMute;
	static float s_fSound1;
	static float s_fSound2;
	static bool  m_bIsPlayMusic;
	static bool m_bIsPlayEffect;
};

#endif // 
