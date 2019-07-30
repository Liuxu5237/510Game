#include "DntgGameHeader.h"
#include "tools/ViewHeader.h"
#include "DntgUIStrengthen.h"
#include "tools/tools/MTNotification.h"
#include "DntgGoDataProxy.h"
#include "DntgGameScene.h"
#include "DntgRoleLayer.h"
#include "DntgRoleNode.h"
#include "ui/UIScale9Sprite.h"
#include "tools/Manager/SpriteHelper.h"
#include "kernel/game/IClientKernel.h"
#include "tools/ViewHeader.h"
#include "tools/tools/StaticData.h"
#include "tools/tools/StringData.h"
#include "DntgActionCustom.h"
#include "DntgWeaponConfig.h"
#include "kernel/game/CGameFrameEngine.h"
#include "kernel/game/IGameFrameEngineSink.h"
USING_NS_CC;
USING_NS_CC_EXT;
using namespace Dntg;


//////////////////////////////////////////////////////////////////////////
#define Dntg_PLIST_PATH					"gamescene/strengthen/strengthen.plist"
#define Dntg_TEXTURE_PATH				"gamescene/strengthen/strengthen.pvr.ccz"

#define Dntg_IMG_STRENGTHEN_BG			"strengthen_bg.png"
#define Dntg_IMG_STRENGTHEN_CLOSE		"strengthen_bt_close.png"
#define Dntg_IMG_STRENGTHEN_CONFIRM		"strengthen_bt_confirm.png"
#define Dntg_IMG_STRENGTHEN_FAIL			"strengten_fail.png"
#define Dntg_IMG_STRENGTHEN_SUCCESS		"strengten_success.png"

#define Dntg_ANI_STRENGTHEN_HALO			"gamescene/strengthen/halo.ani"
#define Dntg_ANI_STRENGTHEN_STAR			"gamescene/strengthen/star.ani"
#define Dntg_ANI_STRENGTHEN_QIANGHUA		"gamescene/strengthen/qianghua.ani"
#define Dntg_ANI_STRENGTHEN_SKILL		"gamescene/strengthen/skill.ani"

const char* Dntg_IMG_STRENGTHEN_SKILLS[] = {
	"SkillIcon10.png",
	"SkillIcon20.png",
	"SkillIcon21.png",
	"SkillIcon30.png",
	"SkillIcon31.png",
	"SkillIcon32.png",
	"SkillIcon40.png",
	"SkillIcon41.png",
	"SkillIcon42.png",
	"SkillIcon43.png",
	"SkillIcon50.png",
	"SkillIcon51.png",
	"SkillIcon52.png",
	"SkillIcon53.png",
	"SkillIcon54.png"
};
int Dntg_getSkillIndex(int skill)
{
	switch (skill)
	{
	case 20:	return 1;
	case 21:	return 2;
	case 30:	return 3;
	case 31:	return 4;
	case 32:	return 5;
	case 40:	return 6;
	case 41:	return 7;
	case 42:	return 8;
	case 43:	return 9;
	case 50:	return 10;
	case 51:	return 11;
	case 52:	return 12;
	case 53:	return 13;
	case 54:	return 14;
	default:
		break;
	}
	return 0;
}

//static int SKILL_COUNT = sizeof(Dntg_IMG_STRENGTHEN_SKILLS)/sizeof(char*);

const char* Dntg_IMG_STRENGTHEN_BOWS[] = {
	"StrengthenBow1.png",
	"StrengthenBow2.png",
	"StrengthenBow3.png",
	"StrengthenBow4.png",
	"StrengthenBow5.png",
};

//static int BOW_COUNT = sizeof(Dntg_IMG_STRENGTHEN_BOWS)/sizeof(char*);

//////////////////////////////////////////////////////////////////////////

static ControlButton* createButton(const char* normal, const char* selected, const char* disable, cocos2d::Ref* target, cocos2d::extension::Control::Handler selector)
{
	// 	ui::Button * btn_now = ui::Button::create(normal, selected, disable);
	// 	btn_now->addTouchEventListener(target, selector);

	ui::Scale9Sprite* sptNormal = ui::Scale9Sprite::createWithSpriteFrameName(normal);
	ui::Scale9Sprite* sptSelected = selected == 0 ? 0 : ui::Scale9Sprite::createWithSpriteFrameName(selected);
	ui::Scale9Sprite* sptDisable = disable == 0 ? 0 : ui::Scale9Sprite::createWithSpriteFrameName(disable);

	//关闭按钮
	ControlButton* bt = ControlButton::create();
	bt->setBackgroundSpriteForState(sptNormal, Control::State::NORMAL);
	if (sptSelected)
		bt->setBackgroundSpriteForState(sptSelected, Control::State::SELECTED);
	if (sptDisable)
		bt->setBackgroundSpriteForState(sptDisable, Control::State::DISABLED);
	bt->setPreferredSize(sptNormal->getPreferredSize());
	bt->addTargetWithActionForControlEvents(target, selector, Control::EventType::TOUCH_UP_INSIDE);

	return bt;
}

class CCEnable : public CCActionInstant
{
public:
	static CCEnable * create(bool isEnabled)
	{
		CCEnable *pRet = new CCEnable(isEnabled);

		if (pRet)
		{
			pRet->autorelease();
		}

		return pRet;
	}

public:
	CCEnable(bool isEnabled) :mIsEnabled(isEnabled){}
	virtual ~CCEnable(){}
	virtual void update(float time)
	{
		CC_UNUSED_PARAM(time);
		((Control*)_target)->setEnabled(mIsEnabled);
	}

	virtual CCFiniteTimeAction * reverse(void)
	{
		return (CCFiniteTimeAction*)(CCEnable::create(!mIsEnabled));
	}

	virtual cocos2d::Ref* clone() {
		// 		CCZone *pNewZone = NULL;
		// 		CCEnable *pRet = NULL;
		// 
		// 		if (pZone && pZone->m_pCopyObject) {
		// 			pRet = (CCEnable*) (pZone->m_pCopyObject);
		// 		} else {
		// 			pRet = new CCEnable(mIsEnabled);
		// 		}
		// 
		// 		CCActionInstant::copyWithZone(pZone);
		CCActionInstant::clone();
		CCEnable *pRet = new CCEnable(mIsEnabled);

		//CC_SAFE_DELETE(pNewZone);
		return pRet;
	}

private:
	bool mIsEnabled;
};

//////////////////////////////////////////////////////////////////////////
UIStrengthen::UIStrengthen()
{
	mSkillTipsBg = 0;
	mIsResultShow = false;
}

UIStrengthen::~UIStrengthen()
{
	G_NOTIFY_UNREG("STRENGTHEN_RESULT");
	G_NOTIFY_UNREG("WEAPON_LEVEL");
	G_NOTIFY_UNREG("DATA_TREASURE_CHANGED");
	G_NOTIFY_UNREG("EVENT_USER_SCORE");
	CC_SAFE_RELEASE(mSkillTipsBg);
	setTouchEnabled(false);

	CCSpriteFrameCache::sharedSpriteFrameCache()->removeSpriteFramesFromFile(Dntg_PLIST_PATH);
	CCTextureCache::sharedTextureCache()->removeTextureForKey(Dntg_TEXTURE_PATH);

	SpriteHelper::removeAnimation(Dntg_ANI_STRENGTHEN_HALO);
	SpriteHelper::removeAnimation(Dntg_ANI_STRENGTHEN_STAR);
	SpriteHelper::removeAnimation(Dntg_ANI_STRENGTHEN_QIANGHUA);
	SpriteHelper::removeAnimation(Dntg_ANI_STRENGTHEN_SKILL);
}

//初始化方法
bool UIStrengthen::init()
{
	do
	{
		CC_BREAK_IF(!CCLayer::init());
		setTouchEnabled(true);
		CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(Dntg_PLIST_PATH);

		float cx = kGameRevolutionWidth / 2;
		float cy = kGameRevolutionHeight / 2;
		CCSprite* bg = CCSprite::createWithSpriteFrameName(Dntg_IMG_STRENGTHEN_BG);
		bg->setPosition(cocos2d::Vec2(cx, cy));
		addChild(bg);

		float x = bg->getPositionX() - bg->getContentSize().width / 2;
		float y = bg->getPositionY() + bg->getContentSize().height / 2;

		ControlButton* bt = createButton(Dntg_IMG_STRENGTHEN_CLOSE, 0, 0, this, cccontrol_selector(UIStrengthen::onBtnClick));
		bt->setTag(100);
		bt->setPosition(cocos2d::Vec2(x + 702, y - 38));
		addChild(bt);

		mBtConfirm = createButton(Dntg_IMG_STRENGTHEN_CONFIRM, 0, 0, this, cccontrol_selector(UIStrengthen::onBtnClick));
		mBtConfirm->setTag(101);
		mBtConfirm->setPosition(cocos2d::Vec2(x + 535, y - 345));
		addChild(mBtConfirm);

		SpriteHelper::cacheAnimation(Dntg_ANI_STRENGTHEN_HALO);
		SpriteHelper::cacheAnimation(Dntg_ANI_STRENGTHEN_STAR);
		SpriteHelper::cacheAnimation(Dntg_ANI_STRENGTHEN_QIANGHUA);
		SpriteHelper::cacheAnimation(Dntg_ANI_STRENGTHEN_SKILL);

		mSptHalo = CCSprite::create();
		mSptHalo->runAction(CCRepeatForever::create(SpriteHelper::createAnimate("Halo")));
		mSptHalo->setPosition(cocos2d::Vec2(x + 182, y - 215));
		addChild(mSptHalo);

		for (int i = 0; i < MAX_WEAPON_SUB_LEVEL; ++i)
		{
			mSptStars[i] = CCSprite::create();
			mSptStars[i]->runAction(CCRepeatForever::create(SpriteHelper::createAnimate("Star")));
			mSptStars[i]->setPosition(cocos2d::Vec2(x + 70 + i * 57, y - 83));
			addChild(mSptStars[i]);

			mImgSkills[i] = CCSprite::createWithSpriteFrameName(Dntg_IMG_STRENGTHEN_SKILLS[0]);
			mImgSkills[i]->setTag(0);
			mImgSkills[i]->setPosition(cocos2d::Vec2(x + 414 + i * 58, y - 205));
			addChild(mImgSkills[i]);

			mSptSkillEffects[i] = CCSprite::create();
			mSptSkillEffects[i]->runAction(CCRepeatForever::create(SpriteHelper::createAnimate("Skill")));
			mSptSkillEffects[i]->setPosition(mImgSkills[i]->getPosition() + cocos2d::Vec2(5, 5));
			addChild(mSptSkillEffects[i]);
		}

		mLbGold = Label::create("0123456789", "Arial", 12, cocos2d::Size(80, 25), kCCTextAlignmentLeft, kCCVerticalTextAlignmentCenter);
		mLbGold->setPosition(cocos2d::Vec2(x + 435, y - 280));
		addChild(mLbGold);

		mLbCost = Label::create("0123456789", "Arial", 12, cocos2d::Size(60, 25), kCCTextAlignmentLeft, kCCVerticalTextAlignmentCenter);
		mLbCost->setPosition(cocos2d::Vec2(x + 435 + 140, y - 280));
		addChild(mLbCost);

		mLbRate = Label::create("100%", "Arial", 12, cocos2d::Size(30, 25), kCCTextAlignmentLeft, kCCVerticalTextAlignmentCenter);
		mLbRate->setPosition(cocos2d::Vec2(x + 435 + 140 + 120, y - 280));
		addChild(mLbRate);

		mLbPower = Label::create("100%", "Arial", 12, cocos2d::Size(80, 25), kCCTextAlignmentCenter, kCCVerticalTextAlignmentCenter);
		mLbPower->setPosition(cocos2d::Vec2(x + 190, y - 355));
		addChild(mLbPower);

		mImgName = CCSprite::createWithSpriteFrameName("BowType1.png");
		mImgName->setPosition(cocos2d::Vec2(x + 180, y - 290));
		addChild(mImgName);

		mImgCannon = CCSprite::createWithSpriteFrameName(Dntg_IMG_STRENGTHEN_BOWS[0]);
		mImgCannon->setPosition(cocos2d::Vec2(x + 182, y - 215));
		addChild(mImgCannon);

		int level = 0;
		IClientKernel* kernel = IClientKernel::get();
		CGameSceneEngine* pGameSceneSink = (CGameSceneEngine*)(CGameFrameEngine::Get()->GetGameFrameEngineSink()->GetGameSceneSink());
		if (pGameSceneSink)
		{
			level = pGameSceneSink->role_layer_->get_role(kernel->GetMeChairID())->get_level();
		}
		
		onDataTreasureNotify(0);
		setWeaponLevel(level);

		G_NOTIFY_REG("WEAPON_LEVEL", UIStrengthen::onWeaponLevelNotify);
		G_NOTIFY_REG("STRENGTHEN_RESULT", UIStrengthen::onResultNotify);
		G_NOTIFY_REG("DATA_TREASURE_CHANGED", UIStrengthen::onDataTreasureNotify);
		G_NOTIFY_REG("EVENT_USER_SCORE", UIStrengthen::onUserScoreNotify);
		return true;
	} while (0);

	return false;
}

bool UIStrengthen::onTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
	if (mSkillTipsBg && mSkillTipsBg->getParent())
	{
		mSkillTipsBg->removeFromParentAndCleanup(false);
	}

	CCPoint pt = CCDirector::getInstance()->convertToGL(pTouch->getLocationInView());

	for (int i = 0; i < MAX_WEAPON_SUB_LEVEL; ++i)
	{
		if (mImgSkills[i]->boundingBox().containsPoint(pt))
		{
			onSkillClick(mImgSkills[i]);
			break;
		}
	}


	return true;
}

// void UIStrengthen::registerWithTouchDispatcher(void)
// {
// 	CCDirector::getInstance()->getTouchDispatcher()->addTargetedDelegate(this, -130, true);
// }

void UIStrengthen::setWeaponLevel(int level)
{
	mWeaponLevel = level;
	int main = level / MAX_WEAPON_SUB_LEVEL;
	int sub = level % MAX_WEAPON_SUB_LEVEL;

	if (main >= MAX_WEAPON_MAIN_LEVEL)
		main = MAX_WEAPON_MAIN_LEVEL - 1;

	if (sub >= MAX_WEAPON_SUB_LEVEL)
		sub = MAX_WEAPON_SUB_LEVEL - 1;

	const WeaponInfo* weapon = WeaponConfig::getInstance().getWeapon(main);

	char sBuf[32] = { 0 };

	CCSpriteFrameCache* cache = CCSpriteFrameCache::sharedSpriteFrameCache();
	mImgCannon->setDisplayFrame(cache->spriteFrameByName(Dntg_IMG_STRENGTHEN_BOWS[main]));

	sprintf(sBuf, "BowType%d.png", main + 1);
	mImgName->setDisplayFrame(cache->spriteFrameByName(sBuf));

	mLbPower->setString(toString(weapon->powers[sub]));

	for (int i = 0; i < MAX_WEAPON_SUB_LEVEL; ++i)
	{
		mSptStars[i]->setVisible(i <= sub);
		mImgSkills[i]->setVisible(i <= sub && weapon->skills[i] != 0);
		mSptSkillEffects[i]->setVisible(i <= sub && weapon->skills[i] != 0);
		mImgSkills[i]->setTag(weapon->skills[i]);

		if (weapon->skills[i] != 0)
		{
			const char* sTex = Dntg_IMG_STRENGTHEN_SKILLS[Dntg_getSkillIndex(weapon->skills[i])];
			mImgSkills[i]->setDisplayFrame(cache->spriteFrameByName(sTex));
		}
	}

	if (main == MAX_WEAPON_MAIN_LEVEL - 1 && sub == MAX_WEAPON_SUB_LEVEL - 1)
	{
		mLbRate->setString("---");
		mLbCost->setString("---");
		mBtConfirm->setEnabled(false);
	}
	else
	{
		sprintf(sBuf, "%d%%", weapon->qh_success_show);
		mLbRate->setString(sBuf);
		mLbCost->setString(toString(weapon->qh_cost));

		if (CGameFrameEngine::Get()->GetGameFrameEngineSink())
		{
			CGameSceneEngine* pGameSceneSink = (CGameSceneEngine*)(CGameFrameEngine::Get()->GetGameFrameEngineSink()->GetGameSceneSink());
			if (pGameSceneSink && pGameSceneSink->getTreasure() >= (int64)weapon->qh_cost)
			{
				if (mIsResultShow)
				{
					mBtConfirm->setEnabled(false);
					mBtConfirm->runAction(CCSequence::create(CCDelayTime::create(1.0f), CCEnable::create(true), 0));
				}
				else
				{
					mBtConfirm->setEnabled(true);
				}
				mIsResultShow = false;
				return;
			}
		}
		mBtConfirm->setEnabled(false);
	}
}


void UIStrengthen::onBtnClick(cocos2d::Ref* obj, cocos2d::extension::Control::EventType)
{
	Control* ctr = (Control*)obj;
	switch (ctr->getTag())
	{
	case 100:
		removeFromParentAndCleanup(true);
		break;
	case 101:
		{// 强化
				int main = mWeaponLevel / MAX_WEAPON_SUB_LEVEL;
				int sub = mWeaponLevel % MAX_WEAPON_SUB_LEVEL;

				if (main >= MAX_WEAPON_MAIN_LEVEL)
					main = MAX_WEAPON_MAIN_LEVEL - 1;

				const WeaponInfo* weapon = WeaponConfig::getInstance().getWeapon(main);

				if (main == MAX_WEAPON_MAIN_LEVEL - 1 && sub == MAX_WEAPON_SUB_LEVEL - 1)
				{
					//popup(SSTRING("strengten_result"), SSTRING("strengten_result_max"));
					break;
				}

				if (CGameFrameEngine::Get()->GetGameFrameEngineSink())
				{
					CGameSceneEngine* pGameSceneSink = (CGameSceneEngine*)(CGameFrameEngine::Get()->GetGameFrameEngineSink()->GetGameSceneSink());
					if (pGameSceneSink && pGameSceneSink->getTreasure() < (int64)weapon->qh_cost)
					{
						//popup(SSTRING("strengten_result"), SSTRING("strengten_result_gold_nenough"));
						break;
					}
				}
				
				mBtConfirm->setEnabled(false);
				mSptHalo->setVisible(false);
				CCSprite* spt = CCSprite::create();
				addChild(spt);
				spt->setPosition(mImgCannon->getPosition());
				spt->runAction(CCSequence::create(
					SpriteHelper::createAnimate("QiangHua"),
					CCCallFuncN::create(this, callfuncN_selector(UIStrengthen::onStrengthenConfirm)),
					RemoveAction::create(),
					0));
		}
		break;
	}
}

std::string Dntg_replace(const std::string& source, const std::string& pattern, const std::string& dstPattern)
{
	std::string result;
	std::string::size_type pos;


	std::string::size_type lenSource = source.length();
	std::string::size_type i = 0;
	for (i = 0; i < lenSource; ++i)
	{
		pos = source.find(pattern, i);
		if (std::string::npos == pos)
			break;


		if (pos < lenSource)
		{
			std::string s = source.substr(i, pos - i);
			result += s;
			result += dstPattern;
			i = pos + pattern.length() - 1;
		}
	}
	result += source.substr(i);
	return result;
}

void UIStrengthen::onSkillClick(cocos2d::Ref* obj)
{
	CCSprite* spt = (CCSprite*)obj;
	if (spt == 0 || spt->getTag() == 0)
		return;

	if (mSkillTipsBg == 0)
	{
		CCSpriteFrame* frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("frame1.png");
		CCSize size = frame->getRect().size;
		CCRect insetRect = CCRectMake(25, 30, size.width - 25 * 2, size.height - 30 - 40);
		mSkillTipsBg = Scale9Sprite::createWithSpriteFrame(frame, insetRect);
		mSkillTipsBg->setAnchorPoint(cocos2d::Vec2(0, 1));
		mSkillTipsBg->retain();
	}

	if (mSkillTipsBg->getParent() == 0)
		this->addChild(mSkillTipsBg);

	if (mSkillTipsBg->getChildByTag(1111))
		mSkillTipsBg->removeChildByTag(1111);

	char sSkillDesc[64] = { 0 };
	sprintf(sSkillDesc, "strengten_skill_%d", spt->getTag());
	std::string result = Dntg_replace(SSTRING(sSkillDesc), std::string("\\n"), std::string("\n"));
	Label* label = Label::create(result.c_str(), "Arial", 24, cocos2d::Size(280, 0), kCCTextAlignmentLeft);
	label->setColor(ccc3(0, 0, 0));
	label->setTag(1111);

	CCSize contentSize = label->getContentSize();
	contentSize.width += 50;
	contentSize.height += 60;
	mSkillTipsBg->setContentSize(contentSize);

	float x = spt->getPosition().x + spt->getContentSize().width / 2;
	float y = spt->getPosition().y + spt->getContentSize().height / 2;
	mSkillTipsBg->setPosition(cocos2d::Vec2(x, y));

	label->setPosition(cocos2d::Vec2(contentSize.width / 2, contentSize.height / 2 + 5));
	mSkillTipsBg->addChild(label);
}

void UIStrengthen::onStrengthenConfirm(cocos2d::Node* obj)
{
	G_NOTIFY_D("STRENGTHEN_CONFIRM", 0);
}

void UIStrengthen::onWeaponLevelNotify(cocos2d::Ref* obj)
{
	EventCustom *event_ = (EventCustom*)obj;
	if (event_ == 0){
		return;
	}

	MTData* data = (MTData*)event_->getUserData();
	if (data == 0)
		return;

	IClientKernel* kernel = IClientKernel::get();

	if (kernel->GetMeChairID() != data->mData1)
		return;
	setWeaponLevel(data->mData2);
}

void UIStrengthen::onResultNotify(cocos2d::Ref* obj)
{
	EventCustom *event_ = (EventCustom*)obj;
	if (event_ == 0){
		return;
	}

	MTData* data = (MTData*)event_->getUserData();
	if (data == 0)
		return;

	//-1:未知错误,无法强化 0:成功,1:强化失败 2:满级不需要强化 3:金币不足
	mIsResultShow = true;

	float delayShow = 0;

	switch ((int)data->mData1)
	{
	case 0:
	{
			  //SoundManager::shared()->playSound("strengthen_success");

			  CCSize si = getContentSize();
			  CCSprite* spt = CCSprite::createWithSpriteFrameName(Dntg_IMG_STRENGTHEN_SUCCESS);
			  addChild(spt);
			  spt->setScale(0);
			  spt->setPosition(cocos2d::Vec2(si.width / 2, si.height / 2));
			  spt->runAction(CCSequence::create(
				  CCEaseExponentialOut::create(CCScaleTo::create(0.2f, 1)),
				  CCDelayTime::create(0.5f),
				  CCFadeOut::create(0.3f),
				  RemoveAction::create(),
				  0));
	}
		//popup(SSTRING("strengten_result"), SSTRING("strengten_result_success"), 0, delayShow);
		break;
	case 1:
	{
			  //SoundManager::shared()->playSound("strengthen_fail");

			  CCSize si = getContentSize();
			  CCSprite* spt = CCSprite::createWithSpriteFrameName(Dntg_IMG_STRENGTHEN_FAIL);
			  addChild(spt);
			  spt->setScale(0);
			  spt->setPosition(cocos2d::Vec2(si.width / 2, si.height / 2));
			  spt->runAction(CCSequence::create(
				  CCEaseExponentialOut::create(CCScaleTo::create(0.2f, 1)),
				  CCDelayTime::create(0.5f),
				  CCFadeOut::create(0.3f),
				  RemoveAction::create(),
				  0));
	}
		//popup(SSTRING("strengten_result"), SSTRING("strengten_result_failed"), 0, delayShow);
		break;
	case 2:
		//popup(SSTRING("strengten_result"), SSTRING("strengten_result_max"), 0, delayShow);
		break;
	case 3:
		//popup(SSTRING("strengten_result"), SSTRING("strengten_result_gold_nenough"), 0, delayShow);
		break;
	default:
		//popup(SSTRING("strengten_result"), SSTRING("strengten_result_unknown"), 0, delayShow);
		break;
	}

	mSptHalo->setVisible(true);
	onDataTreasureNotify(0);
}


void UIStrengthen::onDataTreasureNotify(cocos2d::Ref* obj)
{
	if (CGameFrameEngine::Get()->GetGameFrameEngineSink())
	{
		CGameSceneEngine* pGameSceneSink = (CGameSceneEngine*)(CGameFrameEngine::Get()->GetGameFrameEngineSink()->GetGameSceneSink());
		if (pGameSceneSink )
		{
			mLbGold->setString(toString(pGameSceneSink->getTreasure()));
		}
	}

	
}

void UIStrengthen::onUserScoreNotify(cocos2d::Ref* obj)
{
	EventCustom *event_ = (EventCustom*)obj;
	if (event_ == 0){
		return;
	}

	MTData* data = (MTData*)event_->getUserData();
	if (data == 0)
		return;

	IClientUserItem* pIClientUserItem = (IClientUserItem*)data->mPData;
	IClientKernel* kernel = IClientKernel::get();

	if (pIClientUserItem == kernel->GetMeUserItem())
	{
		onDataTreasureNotify(0);
	}
}
