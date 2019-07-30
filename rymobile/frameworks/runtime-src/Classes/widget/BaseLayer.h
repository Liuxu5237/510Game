#ifndef __BASE_LAYER__H__
#define __BASE_LAYER__H__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "editor-support/cocostudio/CocoStudio.h"
#include "ui/UIHelper.h"
USING_NS_CC;

class BaseLayer : public Layer
{
public:
	BaseLayer()
	{
		m_root_widget = nullptr;
		m_second_widget = nullptr;
	}

	virtual ~BaseLayer()
	{
	}

public:
	bool initWithJsonFile(const char*filename_)
	{
		if (!filename_ || strlen(filename_) < 1 )
		{
			return false;
		}
		cocos2d::ui::Widget *widget_ = cocostudio::GUIReader::getInstance()->widgetFromJsonFile(filename_);
		if (!widget_)
		{
			return false;
		}
		m_root_widget = widget_;
		addChild(widget_);
		//cocos2d::ui::Widget * panel_main = dynamic_cast<cocos2d::ui::Widget *>(widget_->getChildByName("Panel_Main"));

		//cocos2d::ui::Widget * panel_main = dynamic_cast<ui::Widget *>(Helper::seekWidgetByName(widget_,"Panel_Main"));

		//cocos2d::ui::Widget * panel_main = dynamic_cast<ui::Widget *>(cocos2d::ui::Helper::seekWidgetByName(widget_,"Panel_Main"));
		//// 	if (panel_main) ///< 存在
		//// 	{
		//// 		m_root_widget = panel_main;
		//// 	}
		//// 	else ///< 根目录
		//// 	{
		//// 		m_root_widget = widget_;
		//// 	}
		//m_root_widget = panel_main;
		return true;
	}

	bool initWithJsonFile(const char*filename_main, const char*filename_second, const cocos2d::Vec2 & second_pos = cocos2d::Vec2(0, 0))
	{
		bool isSucceed = this->initWithJsonFile(filename_main);
		ui::Widget *widget_ = cocostudio::GUIReader::getInstance()->widgetFromJsonFile(filename_second);
		if (!widget_){
			return false;
		}
		widget_->setPosition(second_pos);
		widget_->setTouchEnabled(false);
		this->addChild(widget_, 2);

		ui::Widget * panel_main = dynamic_cast<ui::Widget *>(widget_->getChildByName("Panel_Main"));
		if (panel_main) ///< 存在
			m_second_widget = panel_main;
		else ///< 根目录
			m_second_widget = widget_;

		return true == isSucceed;
	}
protected:
	///< 根文件
	cocos2d::ui::Widget *m_root_widget;
	///<加载在次一级的根文件
	cocos2d::ui::Widget *m_second_widget;
};




#endif //  __BASE_LAYER__H__