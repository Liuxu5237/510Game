#ifndef _Dntg_FrameLayer_H_
#define _Dntg_FrameLayer_H_

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "DntgCMD_CatchBird.h"

USING_NS_CC;
namespace  Dntg
{
	class FrameLayer
		: public cocos2d::Layer
	{
	public:
		//CREATE_FUNC(FrameLayer);
		static FrameLayer * create();
	public:
		FrameLayer();
		~FrameLayer();
		bool init();

		void setCloseDialogInfo(cocos2d::Ref* target, cocos2d::SEL_CallFuncN callfun, const std::string& title, const std::string& content);

		void setAdminItemCallBack(cocos2d::Ref* target_, cocos2d::SEL_CallFunc callfun_);

		void addAdminButton();

		///< 返回是否锁定
		bool getLock() const { return isLock; }
		///< 返回是否自动开火
		bool getAutoFire() const { return isAutoFire; }
		//隐藏菜单按钮
		void hideMenuButton();

		//我无处不在哈 我 不封装呢
		std::string stringIntercept(std::string input, int signlen);
	public:
		void menuCloseCallback(cocos2d::Ref* pSender);
		void addCannonCallback(cocos2d::Ref* pSender);
		void subCannonCallback(cocos2d::Ref* pSender);
		void hideItemCallback(cocos2d::Ref* pSender);
		void autofireCallback(cocos2d::Ref* pSender);
		void lockCallback(cocos2d::Ref* pSender);
		void clickGuide(cocos2d::Ref* pSender);

		void adminItemCallBack(cocos2d::Ref* pSender);

		///< 创建退出结算面板
		void createExitBalancePanel();
		///< 刷新结束面板数据
		void flushExitBalancePanelData();
		///< 退出结算面板计时
		void fun_exit_balance_time(float dt);
		///< 确认按钮点击回调
		void func_affirm_exit_call_back(cocos2d::Ref *pSender);

		//初始化管理员UI
		void InitAdminUI();

		//管理回调
		void OnGameRoomInfo(int  dwServerID, std::string strRoomName);
		//清理用户表信息
		void OnReleaseInfo();

		//清理名单表
		void OnReleaseMingdan();
        //删除某一个
        void OnReleaseOneItem();
		//插入用户表数据
		void InserUserInfo(int nIndex, tagFishServerInfo FishUserInfo);

		void selectedItemEvent(Ref *pSender, cocos2d::ui::ListView::EventType type);


		//插入黑白名单
		void InserMingDan(int nIndex, CMD_C_Kongzhi  FishUserInfo);

		//设置ID
		void SetGameID(uint32 unitGame){ m_CurGameID = unitGame; }
        
        int getDelBeforeCount() { return m_delBeforeCount;}
	private:
		cocos2d::Ref*		mTarget;
		cocos2d::SEL_CallFuncN	mCallback;
		std::string				mTitle;
		std::string				mContent;
		Vec2					m_RoomPt;
		bool								m_bWinContorl;					//黑白控制
		CCNode								*m_pAdminContor;				//管理员控制器
		cocos2d::ui::CheckBox				*m_CheckWin;
		cocos2d::ui::CheckBox				*m_CheckLost;

		cocos2d::ui::ListView				*m_listView;
		cocos2d::ui::ListView				*m_listContorView;
		cocos2d::ui::Layout					*m_CopyItem;

		cocos2d::ui::EditBox				*m_pProbability;
		cocos2d::ui::EditBox				*m_plimit;
		cocos2d::ui::EditBox				*m_pUserIdEdit;
		 
		cocos2d::ui::Button				   *m_btnMingDan;
        
        int m_delSelectInde  ; 
        int m_delBeforeCount  = 0;
        
		uint32								m_CurGameID;

		CMD_C_Request_DLL_Userroster   m_UserStoer;		//当前选择数据
		

		MenuItemSprite *pCloseItem;
		MenuItemSprite *addCannonItem;
		MenuItemSprite *subCannonItem;
		Menu* pMenu;
		MenuItemToggle* lockMenu;
		MenuItemToggle* autofireMenu;
		MenuItemToggle* hideMenu;
		bool menuvisible;
		bool isLock;
		///< 是自动开火
		bool isAutoFire;
		//CCMenuItem *m_admin_item;
		cocos2d::Ref* admin_ui_item_call_obj;
		cocos2d::SEL_CallFunc admin_ui_item_callfun;

		///< 结算面板,总面板
		cocos2d::Sprite * mBalancePanel;
		///< 各个数字,由小到大
		std::vector<cocos2d::ui::TextAtlas *> mBirdCount;
		///<  时间计数
		cocos2d::ui::TextAtlas * lab_timeout;
		///< 打死鱼加的钱
		cocos2d::ui::TextAtlas * lab_bird_add_Money;
		///<  总钱数
		cocos2d::ui::TextAtlas * lab_total_money;
		///< 时间间隔
		int total_time;
	};
}
#endif // _FrameLayer_H_
