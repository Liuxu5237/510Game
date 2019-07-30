#ifndef _Dntg_UIStrengthen_H_
#define _Dntg_UIStrengthen_H_

#include "cocos2d.h"
#include "cocos-ext.h"
#include "ui/UIScale9Sprite.h"
#include "DntgCMD_CatchBird.h"
namespace  Dntg
{
	class ShieldLayer;

	class UIStrengthen
		: public cocos2d::Layer
	{
	public:
		CREATE_FUNC(UIStrengthen);
	private:
		UIStrengthen();
		~UIStrengthen();
		bool init();

		bool onTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
		//void registerWithTouchDispatcher(void);

	private:
		void setWeaponLevel(int level);
		void onBtnClick(cocos2d::Ref* obj, cocos2d::extension::Control::EventType);
		void onSkillClick(cocos2d::Ref* obj);

		void onStrengthenConfirm(cocos2d::Node* obj);

		void onWeaponLevelNotify(cocos2d::Ref* obj);
		void onResultNotify(cocos2d::Ref* obj);
		void onDataTreasureNotify(cocos2d::Ref* obj);
		void onUserScoreNotify(cocos2d::Ref* obj);

	private:
		cocos2d::Label*		mLbGold;
		cocos2d::Label*		mLbCost;
		cocos2d::Label*		mLbRate;

		cocos2d::Label*		mLbPower;
		cocos2d::Sprite*			mImgName;
		cocos2d::Sprite*			mImgCannon;

		cocos2d::Sprite*			mImgSkills[MAX_WEAPON_SUB_LEVEL];
		cocos2d::extension::Control* mBtConfirm;

		cocos2d::Sprite*					mSptSkillEffects[MAX_WEAPON_SUB_LEVEL];
		cocos2d::Sprite*					mSptStars[MAX_WEAPON_SUB_LEVEL];
		cocos2d::Sprite*					mSptHalo;

		cocos2d::ui::Scale9Sprite* mSkillTipsBg;

		int mWeaponLevel;
		bool mIsResultShow;

	};
}
#endif // _UIStrengthen_H_