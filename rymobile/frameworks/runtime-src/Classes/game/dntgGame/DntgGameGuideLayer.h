#ifndef _DntgGameGuideLayer_H_
#define _DntgGameGuideLayer_H_

#include "platform/df/Define.h"
#include "platform/df/types.h"
#include "widget/BaseLayer.h"
#include "ui/CocosGUI.h"
#include "cocos2d.h"

USING_NS_CC;
using namespace ui;

namespace  Dntg
{
	class GameGuideLayer
		: public BaseLayer
	{
		typedef enum _guideType
		{
			GuideType_Operate,	//操作介绍
			GuideType_Fish,		//鱼类介绍
			GuideType_Key,		//按键介绍
			GuideType_Cannon,	//鱼炮介绍
			GuideType_Max
		}GuideType;

	public:
		CREATE_FUNC(GameGuideLayer);

		GameGuideLayer();
		~GameGuideLayer();
		bool init();

		//显示子界面
		void showSubUI(GuideType type);

		//显示And隐藏,不想吐槽这代码了
		inline void show() { setPosition(CCPoint(0, 0)); }
		inline void hide() { setPosition(CCPoint(kPlatformRevolutionWidth, kPlatformRevolutionHeight)); }

	private:
		//菜单
		CheckBox*	m_pCBMenu[GuideType_Max];
		Text*		m_pCBTitle[GuideType_Max];
		//子界面
		Widget*		m_pSubUI[GuideType_Max];
	};
}
#endif //_DntgCashShopLayer_H_
