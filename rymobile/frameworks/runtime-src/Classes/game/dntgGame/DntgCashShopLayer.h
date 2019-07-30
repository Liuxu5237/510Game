#ifndef _DntgCashShopLayer_H_
#define _DntgCashShopLayer_H_

#include "platform/df/Define.h"
#include "platform/df/types.h"
#include "widget/BaseLayer.h"
#include "ui/CocosGUI.h"
#include "cocos2d.h"

USING_NS_CC;
using namespace ui;

namespace  Dntg
{
	class CashShopLayer
		: public BaseLayer
	{
	public:
		CREATE_FUNC(CashShopLayer);

		CashShopLayer();
		~CashShopLayer();
		bool init();
		///< ������
		void initMainPanel();
		void updateValue(SCORE user_all_Gold, double cash_ratio);
	protected:
		Slider * mSlider;
		Button * btn_minus;
		Button * btn_add;
		Button * btn_max;
		Button * btn_confirm;
		Button * btn_cancel;
		TextAtlas * cashLable;
		TextAtlas * goldLable;
		SCORE fishCashNum;		//�������
		SCORE userGoldNum;		//�������
		SCORE userAllGold;		//�û�ȫ�����
		double cashRatio;		//�һ�����
	private:
		void btnMinusTouchEvent(CCObject * obj, cocos2d::ui::TouchEventType eType);
		void btnAddTouchEvent(CCObject * obj, cocos2d::ui::TouchEventType eType);
		void btnMaxTouchEvent(CCObject * obj, cocos2d::ui::TouchEventType eType);
		void btnConfirmTouchEvent(CCObject * obj, cocos2d::ui::TouchEventType eType);
		void btnCancelTouchEvent(CCObject * obj, cocos2d::ui::TouchEventType eType);
		void sliderTouchEvent(CCObject * obj, cocos2d::ui::SliderEventType  eType);
		void refreshValueString();

	};
}
#endif //_DntgCashShopLayer_H_
