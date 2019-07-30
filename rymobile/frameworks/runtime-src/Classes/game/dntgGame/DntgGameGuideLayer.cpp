#include "DntgGameScene.h"
#include "DntgGameGuideLayer.h"
#include "editor-support/cocostudio/CocoStudio.h"
#include "tools/core/CCUserDefault.h"
#include "tools/global.h"

USING_NS_CC;
using namespace cocos2d::ui;
using namespace cocostudio;
using namespace Dntg;
//////////////////////////////////////////////////////////////////////////

GameGuideLayer::GameGuideLayer()
{
	for (int i=0; i<GuideType_Max; ++i)
	{
		m_pCBMenu[i] = nullptr;
		m_pCBTitle[i] = nullptr;
		m_pSubUI[i] = nullptr;
	}
}

GameGuideLayer::~GameGuideLayer()
{
}

//初始化方法
bool GameGuideLayer::init()
{
	do
	{
		CC_BREAK_IF(!CCLayer::init());
		CC_BREAK_IF(!BaseLayer::initWithJsonFile("ui/GameGuide.json"));

		//关闭按钮
		Button* pBtnClose = dynamic_cast<Button*>(Helper::seekWidgetByName(m_root_widget,"BtnClose"));
		CC_BREAK_IF(!pBtnClose);
		pBtnClose->addTouchEventListener([this](Ref* pRefClicked,Widget::TouchEventType type){
			hide();
		});

		//启动时是否显示
		CheckBox* pCBIsStartShow = dynamic_cast<CheckBox*>(Helper::seekWidgetByName(m_root_widget,"CBIsStartShow"));
		CC_BREAK_IF(!pCBIsStartShow);
		pCBIsStartShow->addEventListener([](Ref* pRefClicked,CheckBox::EventType type){
			CCUserDefault::getInstance()->setBoolForKey(KEY_FOR_GUIDE_SHOW_SET,type==CheckBox::EventType::SELECTED);
		});
		pCBIsStartShow->setSelected(CCUserDefault::getInstance()->getBoolForKey(KEY_FOR_GUIDE_SHOW_SET));

		//菜单
		string strMenuName[GuideType_Max] = {"CBOprateGuide","CBFishGuide","CBKeyGuide","CBCannonGuide"};
		for (int i=0; i<GuideType_Max; i++)
		{
			m_pCBMenu[i] = dynamic_cast<CheckBox*>(Helper::seekWidgetByName(m_root_widget,strMenuName[i].c_str()));
			CC_BREAK_IF(!m_pCBMenu[i]);
			m_pCBMenu[i]->setTag(i);
			m_pCBMenu[i]->addEventListener([this](Ref* pRefClicked,CheckBox::EventType type){

				Widget* pWidgetClicked = dynamic_cast<Widget*>(pRefClicked);
				if(!pWidgetClicked) return;
				if(PLATFROM_VERSION==0x01)
				{
					if(pWidgetClicked->getTag()!=GuideType_Fish)
					{
						return ;
					}
				}
				showSubUI((GuideType)pWidgetClicked->getTag());
			});
			m_pCBTitle[i] = dynamic_cast<Text*>(Helper::seekWidgetByName(m_pCBMenu[i],"CBTitle"));
			CC_BREAK_IF(!m_pCBTitle[i]);
		}

		//子界面
		string strSubUIName[GuideType_Max] = {"OprateGuide","FishKindGuide","KeyGuide","CannonGuide"};
		for (int i=0; i<GuideType_Max; i++)
		{
			m_pSubUI[i] = Helper::seekWidgetByName(m_root_widget,strSubUIName[i].c_str());
			CC_BREAK_IF(!m_pSubUI[i]);
		}

		if(PLATFROM_VERSION==0x01)
		{
			showSubUI(GuideType_Cannon);
		}
		else
		{
			showSubUI(GuideType_Fish);
		}

		return true;
	} while (0);

	return false;
}

void Dntg::GameGuideLayer::showSubUI( GuideType type )
{
	if(GuideType_Max == type) return;

	for (int i=0; i<GuideType_Max; ++i)
	{
		m_pCBMenu[i]->setSelectedState(false);
		m_pCBTitle[i]->setTextColor(Color4B(0xff,0xff,0xff,0xff));
		m_pSubUI[i]->setVisible(false);
		m_pSubUI[i]->setTouchEnabled(false);
	}

	m_pCBMenu[type]->setSelectedState(true);
	m_pCBTitle[type]->setTextColor(Color4B(0x0,0x0,0x0,0xff));
	m_pSubUI[type]->setVisible(true);
	m_pSubUI[type]->setTouchEnabled(true);
}
