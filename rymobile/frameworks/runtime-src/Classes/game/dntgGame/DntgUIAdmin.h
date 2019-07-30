
#ifndef __Dntg_UI_ADMIN_H__
#define __Dntg_UI_ADMIN_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "platform/df/types.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;
using namespace ui;

using namespace cocos2d::ui;
namespace  Dntg
{
	class UIAdmin : public Layer
	{
	public:
		UIAdmin();
		virtual ~UIAdmin();

		CREATE_FUNC(UIAdmin);

	protected:
		bool init(void);

		//void registerWithTouchDispatcher(void);

		virtual void onExit();

		// default implements are used to call script callback if exist
		virtual bool onTouchBegan(Touch *pTouch, Event *pEvent);
		virtual void onTouchMoved(Touch *pTouch, Event *pEvent);
		virtual void onTouchEnded(Touch *pTouch, Event *pEvent);
		virtual void onTouchCancelled(Touch *pTouch, Event *pEvent);

		void checkBoxClickCallBack(cocos2d::Ref* obj_, CheckBoxEventType event_type_);
		void btnClickCallBack(cocos2d::Ref* btn_, TouchEventType event_type_);
		void enterCallBack(cocos2d::Ref* txt_, TextFiledEventType event_type_);
		void sliderCallBack(cocos2d::Ref* obj_, SliderEventType event_type_);

		///////////////////////////////////////////////////////////////
	public:
		bool updateWhiteNameList(dword *game_id_list_, int id_count_);
		bool updateBlackNameList(dword *game_id_list_, int id_count_);

		void list1TouchCallBack(cocos2d::Ref* obj_, TouchEventType event_type_);
		void list2TouchCallBack(cocos2d::Ref* obj_, TouchEventType event_type_);
		void list3TouchCallBack(cocos2d::Ref* obj_, TouchEventType event_type_);

		bool updateDifficultySlider(int difficulty_);
		bool updateStockList(int *stock_range_, int range_count_, long long* stock_score);


	private:
		//  控制模式选择
		CC_SYNTHESIZE_RETAIN(CheckBox*, m_check_name_white, _check_name_white);
		CC_SYNTHESIZE_RETAIN(CheckBox*, m_check_name_black, _check_name_black);
		CC_SYNTHESIZE_RETAIN(CheckBox*, m_check_give_fish, _check_give_fish);
		CC_SYNTHESIZE_RETAIN(CheckBox*, m_check_difficulty_setting, _check_difficulty_setting);
		CheckBox *m_cur_check;

		//  三个列表
		CC_SYNTHESIZE_RETAIN(ListView*, m_list1, _list1);
		CC_SYNTHESIZE_RETAIN(ListView*, m_list2, _list2);
		CC_SYNTHESIZE_RETAIN(ListView*, m_list3, _list3);

		//  库存相关操作按钮
		CC_SYNTHESIZE_RETAIN(Button*, m_btn_quiry, _btn_quiry);
		CC_SYNTHESIZE_RETAIN(Button*, m_btn_clear, _btn_clear);
		CC_SYNTHESIZE_RETAIN(Button*, m_btn_add, _btn_add);
		CC_SYNTHESIZE_RETAIN(Button*, m_btn_sub, _btn_sub);

		// 限制分数  输入
		CC_SYNTHESIZE_RETAIN(TextField*, m_stock_enter, _stock_enter);

		//  难度操作
		CC_SYNTHESIZE_RETAIN(Button*, m_btn_difficulty_quiry, _btn_difficulty_quiry);
		CC_SYNTHESIZE_RETAIN(Button*, m_btn_difficulty_set, _btn_difficulty_set);

		CC_SYNTHESIZE_RETAIN(Slider*, m_slider, _slider);

		//  黑白名单操作
		CC_SYNTHESIZE_RETAIN(Button*, m_btn_name_quiry, _btn_name_quiry);
		CC_SYNTHESIZE_RETAIN(Button*, m_btn_name_delete, _btn_name_delete);

		// 限制分数  输入
		CC_SYNTHESIZE_RETAIN(TextField*, m_limit_score_enter, _limit_score_enter);

		// 赠送鱼 输入
		CC_SYNTHESIZE_RETAIN(TextField*, m_catch_probablity_enter, _catch_probablity_enter);
		CC_SYNTHESIZE_RETAIN(TextField*, m_catch_num_enter, _catch_num_enter);

		// GameID  输入
		CC_SYNTHESIZE_RETAIN(TextField*, m_game_id_enter, _game_id_enter);

		//  确定按钮
		CC_SYNTHESIZE_RETAIN(Button*, m_btn_ensure, _btn_ensure);

		//  list 的单元cell
		CC_SYNTHESIZE_RETAIN(Layout*, m_cell1, _cell1);
		CC_SYNTHESIZE_RETAIN(Layout*, m_cell2, _cell2);
		CC_SYNTHESIZE_RETAIN(Layout*, m_cell3, _cell3);

		EventListener* _touchGroup;

		//  黑名单列表
		std::map< int, dword > m_game_id_list;

		//  白名单列表
		std::map< int, dword > m_game_id_white_list;


		// 选中的赠送鱼的类型
		std::vector<int> m_type_id_list;

		std::map< int, int > m_stock_list;
		int m_cur_stock_index;

		//	CCEditBox *m_edit_box_;
	};
}
#endif