#include "DntgGameScene.h"
#include "DntgCashShopLayer.h"
#include "editor-support/cocostudio/CocoStudio.h"
#include "tools/tools/MTNotification.h"

USING_NS_CC;
using namespace cocos2d::ui;
using namespace cocostudio;
using namespace Dntg;
//////////////////////////////////////////////////////////////////////////
CashShopLayer::CashShopLayer() :
fishCashNum(0),
userGoldNum(0),
cashRatio(0)
{
}

CashShopLayer::~CashShopLayer()
{
}

//初始化方法
bool CashShopLayer::init()
{
	do
	{
		CC_BREAK_IF(!CCLayer::init());
		CC_BREAK_IF(!BaseLayer::initWithJsonFile("ui/CashShopLayer.json"));
		initMainPanel();

		return true;
	} while (0);

	return false;
}

void CashShopLayer::initMainPanel()
{
	mSlider = dynamic_cast<Slider *>(m_root_widget->getChildByName("Slider_1"));
	mSlider->addEventListenerSlider(this, sliderpercentchangedselector(CashShopLayer::sliderTouchEvent));

	btn_minus = dynamic_cast<Button *>(m_root_widget->getChildByName("btn_minus"));
	btn_minus->addTouchEventListener(this, SEL_TouchEvent(&CashShopLayer::btnMinusTouchEvent));

	btn_add = dynamic_cast<Button *>(m_root_widget->getChildByName("btn_add"));
	btn_add->addTouchEventListener(this, SEL_TouchEvent(&CashShopLayer::btnAddTouchEvent));

	btn_max = dynamic_cast<Button *>(m_root_widget->getChildByName("btn_max"));
	btn_max->addTouchEventListener(this, SEL_TouchEvent(&CashShopLayer::btnMaxTouchEvent));

	btn_confirm = dynamic_cast<Button *>(m_root_widget->getChildByName("btn_confirm"));
	btn_confirm->addTouchEventListener(this, SEL_TouchEvent(&CashShopLayer::btnConfirmTouchEvent));

	btn_cancel = dynamic_cast<Button *>(m_root_widget->getChildByName("btn_cancel"));
	btn_cancel->addTouchEventListener(this, SEL_TouchEvent(&CashShopLayer::btnCancelTouchEvent));

	cashLable = dynamic_cast<TextAtlas *>(m_root_widget->getChildByName("al_cashNum"));
	goldLable = dynamic_cast<TextAtlas *>(m_root_widget->getChildByName("al_goldNum"));

	refreshValueString();
}

void CashShopLayer::btnMinusTouchEvent(CCObject * obj, TouchEventType eType)
{
	if (eType == TouchEventType::TOUCH_EVENT_ENDED)
	{
		if (mSlider->getPercent() <= 0) return;

		mSlider->setPercent(mSlider->getPercent() - 1);
		userGoldNum = userAllGold * mSlider->getPercent() / 100;
		fishCashNum = userGoldNum * cashRatio;

		refreshValueString();
	}
}

void CashShopLayer::btnAddTouchEvent(CCObject * obj, TouchEventType eType)
{
	if (eType == TouchEventType::TOUCH_EVENT_ENDED)
	{
		if (mSlider->getPercent() >= 100) return;

		mSlider->setPercent(mSlider->getPercent() + 1);
		userGoldNum = userAllGold * mSlider->getPercent() / 100;
		fishCashNum = userGoldNum * cashRatio;

		refreshValueString();
	}
}

void CashShopLayer::btnMaxTouchEvent(CCObject * obj, TouchEventType eType)
{
	if (eType == TouchEventType::TOUCH_EVENT_ENDED)
	{
		if (mSlider->getPercent() >= 100) return;


		//int ex_ratio_userscore_;							//兑换比例  金币 = 鱼币 * ex_ratio_userscore_ / ex_ratio_birdscore_
		//int ex_ratio_birdscore_;
		userGoldNum = userAllGold;
		fishCashNum = userGoldNum * cashRatio;

		mSlider->setPercent(100);
		refreshValueString();
	}
}

void CashShopLayer::btnConfirmTouchEvent(CCObject * obj, TouchEventType eType)
{
	if (eType == TouchEventType::TOUCH_EVENT_ENDED)
	{
		G_NOTIFY_D("BUY_BULLET", MTData::create(fishCashNum));
		
		this->setPosition(CCPoint(1420, 800));
	}
}

void CashShopLayer::btnCancelTouchEvent(CCObject * obj, TouchEventType eType)
{
	if (eType == TouchEventType::TOUCH_EVENT_ENDED)
	{
		this->setPosition(CCPoint(1420, 800));
	}
}

void CashShopLayer::refreshValueString()
{
	cashLable->setStringValue(CCString::createWithFormat("%lld", fishCashNum)->getCString());
	goldLable->setStringValue(CCString::createWithFormat("%lld", userGoldNum)->getCString());
}

void CashShopLayer::sliderTouchEvent(CCObject * obj, SliderEventType  eType)
{

	if (eType == SLIDER_PERCENTCHANGED)
	{
		userGoldNum = userAllGold * mSlider->getPercent() / 100;
		fishCashNum = userGoldNum * cashRatio;
		refreshValueString();
	}
}

void CashShopLayer::updateValue(SCORE user_all_Gold, double cash_ratio)
{
	userAllGold = user_all_Gold;
	cashRatio = cash_ratio;
	fishCashNum = 0;
	userGoldNum = 0;
	mSlider->setPercent(0);
	refreshValueString();
}

