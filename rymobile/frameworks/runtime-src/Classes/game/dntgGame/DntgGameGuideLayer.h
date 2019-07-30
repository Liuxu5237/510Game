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
			GuideType_Operate,	//��������
			GuideType_Fish,		//�������
			GuideType_Key,		//��������
			GuideType_Cannon,	//���ڽ���
			GuideType_Max
		}GuideType;

	public:
		CREATE_FUNC(GameGuideLayer);

		GameGuideLayer();
		~GameGuideLayer();
		bool init();

		//��ʾ�ӽ���
		void showSubUI(GuideType type);

		//��ʾAnd����,�����²��������
		inline void show() { setPosition(CCPoint(0, 0)); }
		inline void hide() { setPosition(CCPoint(kPlatformRevolutionWidth, kPlatformRevolutionHeight)); }

	private:
		//�˵�
		CheckBox*	m_pCBMenu[GuideType_Max];
		Text*		m_pCBTitle[GuideType_Max];
		//�ӽ���
		Widget*		m_pSubUI[GuideType_Max];
	};
}
#endif //_DntgCashShopLayer_H_
