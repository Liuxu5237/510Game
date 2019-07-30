#include "DntgUIAdmin.h"
#include "editor-support/cocostudio/CocoStudio.h"
#include "kernel/game/CClientKernel.h"
#include "tools/tools/Convert.h"
#include "DntgGameScene.h"
#include "tools/tools/StringData.h"

#include "kernel/game/CGameFrameEngine.h"
#include "kernel/game/IGameFrameEngineSink.h"

using namespace Dntg;
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
//	#include "ui/UIWidget.h"
#endif

using namespace cocos2d::extension;

struct FishKindStruct
{
	std::string name_;
	int kind;
	int mulriple;
};

///< UTF8格式的文件不能直接使用中文,我把这些中文都放到了String.xml中了
#define  MAX_FISH_KIND 25

FishKindStruct Dntgfishkind[MAX_FISH_KIND] = {
	{ ("Bird_Name_1"), 0, 2 },
	{ ("Bird_Name_2"), 1, 2 },
	{ ("Bird_Name_3"), 2, 3 },
	{ ("Bird_Name_4"), 3, 4 },
	{ ("Bird_Name_5"), 4, 5 },
	{ ("Bird_Name_6"), 5, 6 },
	{ ("Bird_Name_7"), 6, 7 },
	{ ("Bird_Name_8"), 7, 8 },
	{ ("Bird_Name_9"), 8, 9 },
	{ ("Bird_Name_10"), 9, 10 },
	{ ("Bird_Name_11"), 10, 12 },
	{ ("Bird_Name_12"), 11, 15 },
	{ ("Bird_Name_13"), 12, 18 },
	{ ("Bird_Name_14"), 13, 20 },
	{ ("Bird_Name_15"), 14, 25 },
	{ ("Bird_Name_16"), 15, 30 },
	{ ("Bird_Name_17"), 16, 35 },
	{ ("Bird_Name_18"), 17, 120 },
	{ ("Bird_Name_19"), 18, 150 },
	{ ("Bird_Name_20"), 19, 200 },
	{ ("Bird_Name_21"), 20, 250 },
	{ ("Bird_Name_22"), 21, 320 },
	{ ("Bird_Name_23"), 22, 300 },
	{ ("Bird_Name_24"), 23, 20 },
	{ ("Bird_Name_25"), 24, 20 }
};

UIAdmin::UIAdmin()
: m_list1(0)
, m_list2(0)
, m_list3(0)
, m_slider(0)
, m_btn_add(0)
, m_btn_clear(0)
, m_btn_quiry(0)
, m_btn_sub(0)

, m_stock_enter(0)

, m_catch_num_enter(0)
, m_catch_probablity_enter(0)
, m_game_id_enter(0)
, m_limit_score_enter(0)

, m_btn_name_delete(0)
, m_btn_name_quiry(0)

, m_btn_difficulty_quiry(0)
, m_btn_difficulty_set(0)

, m_btn_ensure(0)

, m_check_give_fish(0)
, m_check_name_black(0)
, m_check_name_white(0)
, m_check_difficulty_setting(0)
, m_cur_check(0)

, m_cell1(0)
, m_cell2(0)
, m_cell3(0)

//, m_edit_box_(0)
, _touchGroup(0)
, m_game_id_list(std::map<int, dword>())
, m_game_id_white_list(std::map<int, dword>())
, m_type_id_list(std::vector<int>())
, m_stock_list(std::map<int, int>())
, m_cur_stock_index(-1)
{

}

UIAdmin::~UIAdmin()
{
	CC_SAFE_RELEASE_NULL(m_list1);
	CC_SAFE_RELEASE_NULL(m_list2);
	CC_SAFE_RELEASE_NULL(m_list3);

	CC_SAFE_RELEASE_NULL(m_slider);
	CC_SAFE_RELEASE_NULL(m_btn_add);
	CC_SAFE_RELEASE_NULL(m_btn_clear);
	CC_SAFE_RELEASE_NULL(m_btn_quiry);
	CC_SAFE_RELEASE_NULL(m_btn_sub);

	CC_SAFE_RELEASE_NULL(m_stock_enter);

	CC_SAFE_RELEASE_NULL(m_catch_num_enter);
	CC_SAFE_RELEASE_NULL(m_catch_probablity_enter);
	CC_SAFE_RELEASE_NULL(m_game_id_enter);
	CC_SAFE_RELEASE_NULL(m_limit_score_enter);

	CC_SAFE_RELEASE_NULL(m_btn_name_delete);
	CC_SAFE_RELEASE_NULL(m_btn_name_quiry);

	CC_SAFE_RELEASE_NULL(m_btn_difficulty_quiry);
	CC_SAFE_RELEASE_NULL(m_btn_difficulty_set);

	CC_SAFE_RELEASE_NULL(m_btn_ensure);

	CC_SAFE_RELEASE_NULL(m_check_give_fish);
	CC_SAFE_RELEASE_NULL(m_check_name_black);
	CC_SAFE_RELEASE_NULL(m_check_name_white);
	CC_SAFE_RELEASE_NULL(m_check_difficulty_setting);

	CC_SAFE_RELEASE_NULL(m_cell1);
	CC_SAFE_RELEASE_NULL(m_cell2);
	CC_SAFE_RELEASE_NULL(m_cell3);

	//	m_edit_box_->release();
}

void UIAdmin::onExit()
{
	CCLayer::onExit();

	CCDirector::getInstance()->getEventDispatcher()->removeEventListener(_touchGroup);
}

bool UIAdmin::init(void)
{
	if (!CCLayer::init()){
		return false;
	}
	/// 注册触摸
	_touchGroup = EventListenerTouchOneByOne::create();
	_eventDispatcher->addEventListenerWithFixedPriority(_touchGroup, 0);
	/// 不行再加上
	//this->setTouchEnabled(true);

	cocostudio::GUIReader *reader_ = cocostudio::GUIReader::getInstance();
	Widget *widget_ = reader_->widgetFromJsonFile("cocos_ui/admin_ui/admin_ui.json");
	if (!widget_){
		return false;
	}

	this->addChild(widget_);

	Size screenSize = CCDirector::getInstance()->getWinSize();
	Size rootSize = widget_->getSize();
	this->setPosition(CCPoint((screenSize.width - rootSize.width) / 2,
		(screenSize.height - rootSize.height) / 2));

	Size design_size_ = Director::getInstance()->getWinSize();

	Widget *image_bg_ = dynamic_cast<Widget *>(widget_->getChildByName("image_bg"));
	if (image_bg_){
		// 		image_bg_->setScaleX(screenSize.width / design_size_.width  ); //image_bg_->getParent()->getScale() );
		// 		image_bg_->setScaleY(screenSize.height / design_size_.height );
	}

	Widget *btn_close_ = dynamic_cast<Widget *>(image_bg_->getChildByName("btn_close"));
	if (btn_close_){
		btn_close_->addTouchEventListener(this, SEL_TouchEvent(&UIAdmin::btnClickCallBack));
	}

	ListView *list_ = dynamic_cast<ListView*>(image_bg_->getChildByName("list1"));
	if (!list_){
		log("UIAdmin::init false list1 is null ");
	}
	else{
		set_list1(list_);
	}

	list_ = dynamic_cast<ListView*>(image_bg_->getChildByName("list_name"));
	if (!list_){
		log("UIAdmin::init false list_name is null ");
	}
	else{
		set_list2(list_);
	}

	list_ = dynamic_cast<ListView*>(image_bg_->getChildByName("list_catch"));
	if (!list_){
		log("UIAdmin::init false list_catch is null ");
	}
	else{
		set_list3(list_);
	}

	CheckBox *check_ = dynamic_cast<CheckBox*>(widget_->getChildByName("panel_name_black")->getChildByName("check_name_black"));
	if (!check_){
		log("UIAdmin::init false check_name_black is null ");
	}
	else{
		set_check_name_black(check_);
		check_->addEventListenerCheckBox(this, SEL_SelectedStateEvent(&UIAdmin::checkBoxClickCallBack));
	}

	check_ = dynamic_cast<CheckBox*>(widget_->getChildByName("panel_name_white")->getChildByName("check_name_white"));
	if (!check_){
		log("UIAdmin::init false check_name_white is null ");
	}
	else{
		set_check_name_white(check_);
		check_->addEventListenerCheckBox(this, SEL_SelectedStateEvent(&UIAdmin::checkBoxClickCallBack));
	}

	check_ = dynamic_cast<CheckBox*>(widget_->getChildByName("panel_difficulty_setting")->getChildByName("check_difficulty_setting"));
	if (!check_){
		log("UIAdmin::init false check_difficulty_setting is null ");
	}
	else{
		set_check_difficulty_setting(check_);
		check_->addEventListenerCheckBox(this, SEL_SelectedStateEvent(&UIAdmin::checkBoxClickCallBack));
	}

	check_ = dynamic_cast<CheckBox*>(widget_->getChildByName("panel_give")->getChildByName("check_give"));
	if (!check_){
		log("UIAdmin::init false check_give is null ");
	}
	else{
		set_check_give_fish(check_);
		check_->addEventListenerCheckBox(this, SEL_SelectedStateEvent(&UIAdmin::checkBoxClickCallBack));
	}

	Button *btn_ = dynamic_cast<Button*>(widget_->getChildByName("btn_quiry"));
	if (!btn_){
		log("UIAdmin::init false btn_quiry is null ");
	}
	else{
		set_btn_quiry(btn_);
		btn_->addTouchEventListener(this, SEL_TouchEvent(&UIAdmin::btnClickCallBack));
	}

	btn_ = dynamic_cast<Button*>(widget_->getChildByName("btn_clear"));
	if (!btn_){
		log("UIAdmin::init false btn_clear is null ");
	}
	else{
		set_btn_clear(btn_);
		btn_->addTouchEventListener(this, SEL_TouchEvent(&UIAdmin::btnClickCallBack));
	}

	btn_ = dynamic_cast<Button*>(widget_->getChildByName("btn_add"));
	if (!btn_){
		log("UIAdmin::init false btn_add is null ");
	}
	else{
		set_btn_add(btn_);
		btn_->addTouchEventListener(this, SEL_TouchEvent(&UIAdmin::btnClickCallBack));
	}

	btn_ = dynamic_cast<Button*>(widget_->getChildByName("btn_sub"));
	if (!btn_){
		log("UIAdmin::init false btn_sub is null ");
	}
	else{
		set_btn_sub(btn_);
		btn_->addTouchEventListener(this, SEL_TouchEvent(&UIAdmin::btnClickCallBack));
	}

	btn_ = dynamic_cast<Button*>(widget_->getChildByName("btn_name_quiry"));
	if (!btn_){
		log("UIAdmin::init false btn_name_quiry is null ");
	}
	else{
		set_btn_name_quiry(btn_);
		btn_->addTouchEventListener(this, SEL_TouchEvent(&UIAdmin::btnClickCallBack));
	}

	btn_ = dynamic_cast<Button*>(widget_->getChildByName("btn_name_delete"));
	if (!btn_){
		log("UIAdmin::init false btn_name_delete is null ");
	}
	else{
		set_btn_name_delete(btn_);
		btn_->addTouchEventListener(this, SEL_TouchEvent(&UIAdmin::btnClickCallBack));
	}

	btn_ = dynamic_cast<Button*>(widget_->getChildByName("btn_ensure"));
	if (!btn_){
		log("UIAdmin::init false btn_ensure is null ");
	}
	else{
		set_btn_ensure(btn_);
		btn_->addTouchEventListener(this, SEL_TouchEvent(&UIAdmin::btnClickCallBack));
	}

	TextField *txt_ = dynamic_cast<TextField*>(widget_->getChildByName("game_id_panel")->getChildByName("txt_gameid"));
	if (!txt_){
		log("UIAdmin::init false txt_game_id is null ");
	}
	else{
		set_game_id_enter(txt_);
		txt_->addEventListenerTextField(this, SEL_TextFieldEvent(&UIAdmin::enterCallBack));
	}

	txt_ = dynamic_cast<TextField*>(widget_->getChildByName("panel_limit_score")->getChildByName("txt_limit_score"));
	if (!txt_){
		log("UIAdmin::init false txt_limit_score is null ");
	}
	else{
		set_limit_score_enter(txt_);
		txt_->addEventListenerTextField(this, SEL_TextFieldEvent(&UIAdmin::enterCallBack));
	}

	txt_ = dynamic_cast<TextField*>(widget_->getChildByName("panel_catch_probality")->getChildByName("txt_catch_probality"));
	if (!txt_){
		log("UIAdmin::init false txt_catch_probality is null ");
	}
	else{
		set_catch_probablity_enter(txt_);
		txt_->addEventListenerTextField(this, SEL_TextFieldEvent(&UIAdmin::enterCallBack));
	}

	txt_ = dynamic_cast<TextField*>(widget_->getChildByName("panel_catch_num")->getChildByName("txt_catch_num"));
	if (!txt_){
		log("UIAdmin::init false txt_catch_num is null ");
	}
	else{
		set_catch_num_enter(txt_);
		txt_->addEventListenerTextField(this, SEL_TextFieldEvent(&UIAdmin::enterCallBack));
	}

	txt_ = dynamic_cast<TextField*>(widget_->getChildByName("panel_stock_num")->getChildByName("txt_stock_num"));
	if (!txt_){
		log("UIAdmin::init false txt_catch_num is null ");
	}
	else{
		set_stock_enter(txt_);
		txt_->addEventListenerTextField(this, SEL_TextFieldEvent(&UIAdmin::enterCallBack));
	}

	Slider *slider_ = dynamic_cast<Slider*>(widget_->getChildByName("slider"));
	if (!slider_){
		log("UIAdmin::init false slider_ is null ");
	}
	else{
		set_slider(slider_);
		slider_->setTouchEnabled(true);
		slider_->addEventListenerSlider(this, SEL_SlidPercentChangedEvent(&UIAdmin::sliderCallBack));
	}

	Layout *layout_ = dynamic_cast<Layout*>(widget_->getChildByName("cell1"));
	if (!layout_){
		log("UIAdmin::init false layout_ is null ");
	}
	else{
		set_cell1(layout_);
	}

	layout_ = dynamic_cast<Layout*>(widget_->getChildByName("cell2"));
	if (!layout_){
		log("UIAdmin::init false layout_ is null ");
	}
	else{
		set_cell2(layout_);
	}

	layout_ = dynamic_cast<Layout*>(widget_->getChildByName("cell3"));
	if (!layout_){
		log("UIAdmin::init false layout_ is null ");
	}
	else{
		set_cell3(layout_);
	}


	m_list3->removeAllItems();
	char num_[20];
	for (int i = 0; i < MAX_FISH_KIND; ++i)
	{
		Widget *layout_ = m_cell3->clone();
		Label *label_ = dynamic_cast<Label*> (layout_->getChildByName("num"));
		if (label_){
			label_->setString(StringConvert::gbk_utf8(SSTRING(Dntgfishkind[i].name_.c_str())));
			label_->setColor(ccc3(0, 255, 0));
		}

		sprintf(num_, "%d", Dntgfishkind[i].mulriple);
		label_ = dynamic_cast<Label*>(layout_->getChildByName("mid"));
		if (label_){
			label_->setString(num_);
			label_->setColor(ccc3(0, 255, 0));
		}

		layout_->setTag(i);
		m_list3->pushBackCustomItem(layout_);



		layout_->addTouchEventListener(this, SEL_TouchEvent(&UIAdmin::list3TouchCallBack));
		layout_->setTouchEnabled(true);
	}

	return true;
}

// void UIAdmin::registerWithTouchDispatcher(void)
// {
// 	//CCDirector::getInstance()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
// }

bool UIAdmin::onTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	return true;
}

void UIAdmin::onTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{

}

void UIAdmin::onTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{

}

void UIAdmin::onTouchCancelled(CCTouch *pTouch, CCEvent *pEvent)
{

}

void UIAdmin::checkBoxClickCallBack(cocos2d::Ref* obj_, CheckBoxEventType event_type_)
{
	if (!obj_){

		if (m_cur_check){
			m_cur_check->setSelectedState(false);
		}
		m_cur_check = 0;

		return;

	}

	CheckBox *check_ = dynamic_cast<CheckBox*>(obj_);
	if (!check_){
		return;
	}

	if (event_type_ == CHECKBOX_STATE_EVENT_UNSELECTED){
		check_->setSelectedState(true);
		return;
	}

	if (m_cur_check == check_){
		return;
	}

	if (m_cur_check){
		m_cur_check->setSelectedState(false);
	}
	m_cur_check = check_;
	check_->setSelectedState(true);
}

void UIAdmin::btnClickCallBack(cocos2d::Ref* btn_, TouchEventType event_type_)
{
	log(" UIAdmin::btnClickCallBack event_type_ = %d", event_type_);
	if (event_type_ != TOUCH_EVENT_ENDED){
		return;
	}

	Button *button_ = dynamic_cast<Button*>(btn_);

	switch (button_->getTag())  // UI 编辑器中设置的tag
	{
		case 1:  // 查询库存
		{
			CGameClientKernel *kernel_ = dynamic_cast<CGameClientKernel*>(IClientKernel::get());
			if (!kernel_){
				log("UIAdmin::btnClickCallBack  no kernel ???");
				return;
			}

			kernel_->onOperateStock(0, 0);  // code 为0  代表查询

			break;
		}
		case 2:  // 清零库存
		{
			CGameClientKernel *kernel_ = dynamic_cast<CGameClientKernel*>(IClientKernel::get());
			if (!kernel_){
				log("UIAdmin::btnClickCallBack  no kernel ???");
				return;
			}

			if (m_cur_stock_index == -1){
				log("UIAdmin::btnClickCallBack  no target"); ///<清零库存没有  选中 库存目标
				return;
			}

			kernel_->onOperateStock(3, m_cur_stock_index);  // code 为3  代表清零

			break;
		}

		case 3:  // 增加库存
		{
			CGameClientKernel *kernel_ = dynamic_cast<CGameClientKernel*>(IClientKernel::get());
			if (!kernel_){
				log("UIAdmin::btnClickCallBack  no kernel ???");
				return;
			}

			if (m_cur_stock_index == -1){
				log("UIAdmin::btnClickCallBack  no target."); ///<清零库存没有  选中 库存目标
				return;
			}

			kernel_->onOperateStock(1, m_cur_stock_index);  // code 为3  代表增加

			break;
		}

		case 4:  // 减少库存
		{
			CGameClientKernel *kernel_ = dynamic_cast<CGameClientKernel*>(IClientKernel::get());
			if (!kernel_){
				log("UIAdmin::btnClickCallBack  no kernel ???");
				return;
			}

			if (m_cur_stock_index == -1){
				log("UIAdmin::btnClickCallBack  no target."); ///< 清零库存没有  选中 库存目标
				return;
			}

			kernel_->onOperateStock(2, m_cur_stock_index);  // code 为3  代表减少

			break;
		}

		case 5:  // 查询黑白名单
		{
			CGameClientKernel *kernel_ = dynamic_cast<CGameClientKernel*>(IClientKernel::get());
			if (!kernel_){
				log("UIAdmin::btnClickCallBack  no kernel ???");
				return;
			}

			if (m_cur_check == m_check_name_white)
			{
				CCString str_(m_game_id_enter->getStringValue());


				kernel_->onOperateRBL(0, 1, 0, 0);  // rbl 为1  代表查询  白名单

			}
			else if (m_cur_check == m_check_name_black){
				CCString str_(m_game_id_enter->getStringValue());


				kernel_->onOperateRBL(0, 0, (dword)str_.intValue(), 0);  // rbl 为0  代表查询  黑名单
			}
			else{
				log("please select search black name or white name"); ///< 请 选择 查询 黑名单 还是白名单
			}
			break;
		}

		case 6:  // 删除黑白名单
		{
			CGameClientKernel *kernel_ = dynamic_cast<CGameClientKernel*>(IClientKernel::get());
			if (!kernel_){
				log("UIAdmin::btnClickCallBack  no kernel ???");
				return;
			}

			if (m_cur_check == m_check_name_white)
			{
				CCString str_(m_game_id_enter->getStringValue());
				kernel_->onOperateRBL(2, 1, str_.uintValue(), 0);  // code 为0  代表删除  白名单
			}
			else if (m_cur_check == m_check_name_black){
				CCString str_(m_game_id_enter->getStringValue());
				kernel_->onOperateRBL(2, 0, str_.uintValue(), 0);  // code 为0  代表删除  黑名单
			}
			else{
				log("please select search black name or white name"); ///<请 选择 设置 黑名单 还是白名单
			}
			break;
		}

		case 7:  // 查询难度
		{
					 CGameClientKernel *kernel_ = dynamic_cast<CGameClientKernel*>(IClientKernel::get());
					 if (!kernel_){
						 log("UIAdmin::btnClickCallBack  no kernel ???");
						 return;
					 }

					 CCString str_(m_game_id_enter->getStringValue());

					 kernel_->onSetDifficulty(0, str_.uintValue(), 0);

					 break;
		}

		case 8:  // 设置难度
		{
			CGameClientKernel *kernel_ = dynamic_cast<CGameClientKernel*>(IClientKernel::get());
			if (!kernel_){
				log("UIAdmin::btnClickCallBack  no kernel ???");
				return;
			}

			CCString str_(m_game_id_enter->getStringValue());

			int difficulty_ = m_slider->getPercent();   //  Slider 的范围是 0~100

			kernel_->onSetDifficulty(difficulty_, str_.uintValue(), 1);

			break;
		}

		case 9:  // 设置黑白名单
		{
			CGameClientKernel *kernel_ = dynamic_cast<CGameClientKernel*>(IClientKernel::get());
			if (!kernel_){
				log("UIAdmin::btnClickCallBack  no kernel ???");
				return;
			}

			if (m_cur_check == m_check_name_white)
			{
				CCString str_(m_game_id_enter->getStringValue());
				kernel_->onOperateRBL(1, 1, str_.uintValue(), 0);  // code 为0  代表设置  白名单
			}
			else if (m_cur_check == m_check_name_black){
				CCString str_(m_game_id_enter->getStringValue());
				kernel_->onOperateRBL(1, 0, str_.uintValue(), 0);  // code 为0  代表设置  黑名单
			}
			else{
				log("please select search black name or white name"); ///<请 选择 设置 黑名单 还是白名单
			}
			break;
		}

		case 100:  // 关闭按钮
		{
					   CGameSceneEngine* pGameSceneSink = (CGameSceneEngine*)(CGameFrameEngine::Get()->GetGameFrameEngineSink()->GetGameSceneSink());
					   if (pGameSceneSink)
					   {
						   pGameSceneSink->removeAdminUI();
					   }
				 
		}
	default:
		break;
	}
}

void UIAdmin::enterCallBack(cocos2d::Ref* txt_, TextFiledEventType event_type_)
{
	if (event_type_ == TEXTFIELD_EVENT_ATTACH_WITH_IME){

#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32

		TextField *txt_dest_ = dynamic_cast<TextField*>(txt_);
		if (!txt_dest_){
			log(" UIAdmin::enterCallBack  TextField is null!  ");

			return;
		}

		std::string text = txt_dest_->getStringValue();
		char pText[100] = { 0 };

		if (text.length()){
			strncpy(pText, text.c_str(), 100);
		}

		//bool didChange = CWin32InputBox::InputBox("Input", "enter", pText, 100, false, CCEGLView::sharedOpenGLView()->getHWnd()) == IDOK;

		// 		if (didChange){
		// 			txt_dest_->setText(pText);
		// 		}
		txt_dest_->setText(pText);
#endif
	}

}

void UIAdmin::sliderCallBack(cocos2d::Ref* obj_, SliderEventType event_type_)
{
	if (event_type_ == SLIDER_PERCENTCHANGED)
	{
		if (m_cur_check != m_check_difficulty_setting){   // 帮忙 选中  设置难度
			checkBoxClickCallBack(m_check_difficulty_setting, CHECKBOX_STATE_EVENT_SELECTED);
		}
	}
}

void UIAdmin::list1TouchCallBack(cocos2d::Ref* obj_, TouchEventType event_type_)
{
	if (event_type_ == TOUCH_EVENT_ENDED)
	{
		if (m_stock_list.size() == 0){
			return;
		}

		Widget *widget_ = dynamic_cast<Widget*>(obj_);
		if (!widget_){
			return;
		}

		int tag_ = widget_->getTag();

		m_cur_stock_index = m_stock_list[tag_];

		checkBoxClickCallBack(0, CHECKBOX_STATE_EVENT_SELECTED);

	}
}

void UIAdmin::list2TouchCallBack(cocos2d::Ref* obj_, TouchEventType event_type_)
{
	if (event_type_ == TOUCH_EVENT_ENDED)
	{
		Widget *layout_ = dynamic_cast<Widget*>(obj_);

		CCString *str_ = CCString::createWithFormat("%d", m_game_id_list[layout_->getTag()]);

		m_game_id_enter->setText(str_->getCString());
	}
}

template <typename T>
bool removeElem(std::vector<T> &vec_, T elem_)
{
	for (typename std::vector<T>::iterator iter = vec_.begin(); iter != vec_.end(); ++iter)
	{
		if (elem_ == *iter){
			vec_.erase(iter);
			return true;
		}
	}

	return false;
}

void UIAdmin::list3TouchCallBack(cocos2d::Ref* obj_, TouchEventType event_type_)
{
	if (event_type_ == TOUCH_EVENT_ENDED)
	{
		Widget *widget_ = dynamic_cast<Widget*>(obj_);
		if (widget_){

			int kind_ = Dntgfishkind[widget_->getTag()].kind;
			if (removeElem(m_type_id_list, kind_)){
				//widget_->setColor(ccc3(0xff, 0xff, 0xff));

				widget_->getChildByName("flag")->setVisible(false);

			}
			else{
				widget_->setColor(ccc3(0, 0, 0xff));
				m_type_id_list.push_back(kind_);

				widget_->getChildByName("flag")->setVisible(true);
			}
		}

		if (m_cur_check != m_check_give_fish){   // 帮忙 选中  赠送鱼
			checkBoxClickCallBack(m_check_give_fish, CHECKBOX_STATE_EVENT_SELECTED);
		}
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool UIAdmin::updateWhiteNameList(dword *game_id_list_, int id_count_)
{
	if (m_cur_check != m_check_name_white){
		return false;
	}

	m_list2->removeAllItems();
	m_game_id_white_list.clear();

	char game_id[20];
	for (int i = 0; i < id_count_; ++i)
	{
		Widget *layout_ = m_cell2->clone();

		sprintf(game_id, "%d", game_id_list_[i]);
		Label *label_ = dynamic_cast<Label*> (layout_->getChildByName("num"));
		if (label_){
			label_->setString(game_id);

			layout_->setTag(i);
			layout_->addTouchEventListener(this, SEL_TouchEvent(&UIAdmin::list2TouchCallBack));
			m_list2->pushBackCustomItem(layout_);

			m_game_id_white_list[i] = game_id_list_[i];
		}
	}

	return true;
}

bool UIAdmin::updateBlackNameList(dword *game_id_list_, int id_count_)
{
	if (m_cur_check != m_check_name_black){
		return false;
	}

	m_list2->removeAllItems();
	m_game_id_list.clear();

	char game_id[20];
	for (int i = 0; i < id_count_; ++i)
	{
		Widget *layout_ = m_cell2->clone();

		sprintf(game_id, "%d", game_id_list_[i]);
		Label *label_ = dynamic_cast<Label*> (layout_->getChildByName("num"));
		if (label_){
			label_->setString(game_id);

			layout_->setTag(i);
			layout_->addTouchEventListener(this, SEL_TouchEvent(&UIAdmin::list2TouchCallBack));
			m_list2->pushBackCustomItem(layout_);

			m_game_id_list[i] = game_id_list_[i];
		}
	}
	return true;
}

bool UIAdmin::updateDifficultySlider(int difficulty_)
{
	if (m_slider){
		m_slider->setPercent(difficulty_);
	}

	return true;
}

bool UIAdmin::updateStockList(int *stock_range_, int range_count_, long long* stock_score)
{
	m_list1->removeAllItems();
	m_stock_list.clear();

	char stock_score_str_[20];
	for (int i = 0; i < range_count_; ++i)
	{
		Widget *layout_ = m_cell1->clone();
		sprintf(stock_score_str_, "%d", stock_score[i]);
		Label *label_ = dynamic_cast<Label*> (layout_->getChildByName("num"));
		if (label_){
			label_->setString(stock_score_str_);
		}

		sprintf(stock_score_str_, "%d", stock_range_[i]);
		label_ = dynamic_cast<Label*>(layout_->getChildByName("left"));
		if (label_){
			label_->setString(stock_score_str_);
		}

		if (i < range_count_ - 1){
			sprintf(stock_score_str_, "%d", stock_range_[i + 1]);
			label_ = dynamic_cast<Label*>(layout_->getChildByName("right"));
			if (label_){
				label_->setString(stock_score_str_);
			}
		}
		else{
			label_ = dynamic_cast<Label*>(layout_->getChildByName("right"));
			if (label_){
				label_->setString(StringConvert::gbk_utf8(std::string("以上").c_str()));
			}

			label_ = dynamic_cast<Label*>(layout_->getChildByName("mid"));
			if (label_){
				label_->setString("");
			}
		}

		layout_->setTag(i);
		m_list1->pushBackCustomItem(layout_);
		layout_->addTouchEventListener(this, SEL_TouchEvent(&UIAdmin::list1TouchCallBack));
		m_stock_list[i] = stock_score[i];
	}


	return true;
}