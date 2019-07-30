#include "DntgFrameLayer.h"
#include "cocos-ext.h"
#include "DntgGameScene.h"
#include "tools/tools/MTNotification.h"
#include "kernel/game/IClientKernel.h"
#include "DntgHeader.h"
#include "kernel/game/CGameFrameEngine.h"
#include "kernel/game/IGameFrameEngineSink.h"
#include "kernel/server/IServerItem.h"



#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"


USING_NS_CC;
USING_NS_CC_EXT;

using namespace ui;
using namespace Dntg;


//////////////////////////////////////////////////////////////////////////
FrameLayer::FrameLayer()
// m_admin_item(0)
: admin_ui_item_call_obj(0)
, admin_ui_item_callfun(0)
, isLock(false)
, menuvisible(true)
, isAutoFire(false)
, m_pAdminContor(nullptr)
, m_bWinContorl(true)
, m_listView(nullptr)
, m_pProbability(nullptr)
, m_plimit(nullptr)
, m_pUserIdEdit(nullptr)
, m_btnMingDan(nullptr)

{
	m_RoomPt.x = 95;
	m_RoomPt.y = 715;

	m_CurGameID = 0;
}

FrameLayer::~FrameLayer()
{
	// 	if (this->isScheduled(SEL_SCHEDULE(&FrameLayer::fun_exit_balance_time)))
	// 	{
	// 		this->unschedule(SEL_SCHEDULE(&FrameLayer::fun_exit_balance_time));
	// 	}
	this->unscheduleAllCallbacks();
}

//初始化方法
bool FrameLayer::init()
{
	do
	{
		CC_BREAK_IF(!Layer::init());

		Size winSize = Director::getInstance()->getWinSize();

		SpriteFrameCache* cache = SpriteFrameCache::getInstance();

	/*	const tagUserAttribute *userattr_ = IServerItem::get()->GetUserAttribute();
		if (CUserRight::IsGameCheatUser(userattr_->dwUserRight)){

		}*/

		auto guide = MenuItemSprite::create(Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("Admin.png")),
			Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("Admin.png")));

		auto pGuide = MenuItemToggle::createWithTarget(this, menu_selector(FrameLayer::clickGuide), guide, guide, NULL);
		pGuide->setPosition(cocos2d::Vec2(winSize.width / 13, winSize.height / 7 * 5.5f + 50));

		const tagUserAttribute *userattr_ = IServerItem::get()->GetUserAttribute();
		bool bShowAdmin = CUserRight::IsGameCheatUser(userattr_->dwUserRight) == true ? true : false;
		guide->setVisible(bShowAdmin);

		auto lock = MenuItemSprite::create(Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("lock.png")),
			Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("lock_d.png")));
		auto unlock = MenuItemSprite::create(Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("unlock.png")),
			Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("unlock_d.png")));

		lockMenu = MenuItemToggle::createWithTarget(this, menu_selector(FrameLayer::lockCallback), lock, unlock, NULL);
		lockMenu->setPosition(cocos2d::Vec2(winSize.width / 13, winSize.height / 7 * 4.0f + 50));
		auto autofire = MenuItemSprite::create(Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("autofire_d.png")),
			Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("autofire.png")));
		auto unautofire = MenuItemSprite::create(Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("autofire.png")),
			Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("autofire_d.png")));

		autofireMenu = MenuItemToggle::createWithTarget(this, menu_selector(FrameLayer::autofireCallback), autofire, unautofire, NULL);
		autofireMenu->setPosition(cocos2d::Vec2(winSize.width / 13 * 12, winSize.height / 7 * 2.5f + 50));

		Sprite* addCannonItemNormal = Sprite::createWithSpriteFrame(cache->spriteFrameByName("addcannon.png"));
		Sprite* addCannonItemSelected = Sprite::createWithSpriteFrame(cache->spriteFrameByName("addcannon_d.png"));
		addCannonItem = MenuItemSprite::create(addCannonItemNormal, addCannonItemSelected, nullptr, this, menu_selector(FrameLayer::addCannonCallback));
		addCannonItem->setPosition(cocos2d::Vec2(winSize.width / 13, winSize.height / 7 * 2.5f + 50));

		Sprite* subCannonItemNormal = Sprite::createWithSpriteFrame(cache->spriteFrameByName("subcannon.png"));
		Sprite* subCannonItemSelected = Sprite::createWithSpriteFrame(cache->spriteFrameByName("subcannon_d.png"));
		subCannonItem = MenuItemSprite::create(subCannonItemNormal, subCannonItemSelected, nullptr, this, menu_selector(FrameLayer::subCannonCallback));
		subCannonItem->setPosition(cocos2d::Vec2(winSize.width / 13, winSize.height / 7 * 1 + 50));

		Sprite* sptCloseNormal = Sprite::createWithSpriteFrame(cache->spriteFrameByName("quit.png"));
		Sprite* sptCloseSelected = Sprite::createWithSpriteFrame(cache->spriteFrameByName("quit_d.png"));
		pCloseItem = MenuItemSprite::create(sptCloseNormal, sptCloseSelected, nullptr, this, menu_selector(FrameLayer::menuCloseCallback));
		pCloseItem->setPosition(cocos2d::Vec2(winSize.width / 13 * 12, winSize.height / 7 * 4.0f + 50));

		pMenu = Menu::create(addCannonItem, subCannonItem, pCloseItem, lockMenu, autofireMenu,pGuide, NULL);
		pMenu->setAnchorPoint(cocos2d::Vec2(0, 0));
		pMenu->setPosition(0, 0);
		this->addChild(pMenu);

		auto hide = MenuItemSprite::create(Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("hide.png")),
			Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("hide_d.png")));
		auto show = MenuItemSprite::create(Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("show.png")),
			Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("show_d.png")));

		hideMenu = MenuItemToggle::createWithTarget(this, menu_selector(FrameLayer::hideItemCallback), hide, show, NULL);
		hideMenu->setPosition(cocos2d::Vec2(winSize.width / 13 * 12, winSize.height / 7 * 1 + 50));

		Menu* pMenu_hideItem = Menu::create(hideMenu, 0);
		pMenu_hideItem->setAnchorPoint(cocos2d::Vec2(0, 0));
		pMenu_hideItem->setPosition(0, 0);
		this->addChild(pMenu_hideItem);

		createExitBalancePanel();




		return true;
	} while (0);

	return false;
}
//
//void FrameLayer::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
//{
//	if (keyCode == EventKeyboard::KeyCode::KEY_SPACE)
//	{
//
//	
//		isLock = !isLock;
//		int nIndex = isLock == true ? 1 : 0;
//		lockMenu->setSelectedIndex(nIndex);
//
//		if (!isLock)
//		{
//			IClientKernel* kernel = IClientKernel::get();
//			int char_id = kernel->GetMeChairID();
//			int value = char_id;
//			G_NOTIFY_D("GAME_BIRD_LOCK_CANCEL", MTData::create(value, 1));
//		}
//		
//	}
//}


void FrameLayer::addAdminButton()
{
	Size winSize = Director::getInstance()->getWinSize();

	SpriteFrameCache* cache = SpriteFrameCache::getInstance();

	Sprite* sptCloseNormal = Sprite::createWithSpriteFrame(cache->spriteFrameByName("bt_settings_1.png"));
	Sprite* sptCloseSelected = Sprite::createWithSpriteFrame(cache->spriteFrameByName("bt_settings_1.png"));
	MenuItemSprite *pAdminItem = MenuItemSprite::create(sptCloseNormal, sptCloseSelected, nullptr, this, menu_selector(FrameLayer::adminItemCallBack));
	pAdminItem->setAnchorPoint(cocos2d::Vec2(1, 1));
	pAdminItem->setPosition(cocos2d::Vec2(winSize.width - 50, winSize.height));

	//pAdminItem->setVisible(false);
	//m_admin_item = pAdminItem;

	Menu* pMenu = Menu::create(pAdminItem, 0);
	pMenu->setAnchorPoint(cocos2d::Vec2(0, 0));
	pMenu->setPosition(0, 0);
	this->addChild(pMenu);
}

void FrameLayer::setCloseDialogInfo(cocos2d::Ref* target, cocos2d::SEL_CallFuncN callfun, const std::string& title, const std::string& content)
{
	mTarget = target;
	mCallback = callfun;
	mTitle = title;
	mContent = content;
}

void FrameLayer::menuCloseCallback(cocos2d::Ref* pSender)
{
	//popup(mTitle.c_str(), mContent.c_str(), DLG_MB_OK|DLG_MB_CANCEL, 0, mTarget, mCallback);
	G_NOTIFY("HIDE_EXCHANGE");
	mBalancePanel->setVisible(true);
	pMenu->setVisible(false);
	flushExitBalancePanelData();
}
void FrameLayer::addCannonCallback(cocos2d::Ref* pSender)
{
	G_NOTIFY_D("CANNON_ADD", 0);
}
void FrameLayer::subCannonCallback(cocos2d::Ref* pSender)
{
	G_NOTIFY_D("CANNON_SUB", 0);
}
void FrameLayer::autofireCallback(cocos2d::Ref* pSender)
{
	if (CGameFrameEngine::Get()->GetGameFrameEngineSink())
	{
		CGameSceneEngine* pGameSceneSink = (CGameSceneEngine*)(CGameFrameEngine::Get()->GetGameFrameEngineSink()->GetGameSceneSink());
		if (pGameSceneSink)
		{
			if (!isAutoFire)
			{
				isAutoFire = true;
				pGameSceneSink->autoFire();
			}
			else
			{
				isAutoFire = false;
				pGameSceneSink->setIsFire(false);
			}
		}
	}	
}
void FrameLayer::lockCallback(cocos2d::Ref* pSender)
{
	// 	if (isAutoFire)
	// 	{
	// 		isAutoFire = false;
	// 	}

	isLock = !isLock;
	if (!isLock)
	{
		IClientKernel* kernel = IClientKernel::get();
		int char_id = kernel->GetMeChairID();
		int value =char_id;
		G_NOTIFY_D("GAME_BIRD_LOCK_CANCEL", MTData::create(value, 1));
	}
}
void FrameLayer::hideItemCallback(cocos2d::Ref* pSender)
{
	if (menuvisible)
	{
		pMenu->setVisible(false);
		menuvisible = false;
	}
	else
	{
		pMenu->setVisible(true);
		menuvisible = true;
	}
}
void FrameLayer::hideMenuButton()
{
	//pMenu->setVisible(false);
	//menuvisible = false;
	//hideMenu->setSelectedIndex(1);
}
void FrameLayer::setAdminItemCallBack(cocos2d::Ref* target_, cocos2d::SEL_CallFunc callfun_)
{
	admin_ui_item_call_obj = target_;
	admin_ui_item_callfun = callfun_;
}

void FrameLayer::adminItemCallBack(cocos2d::Ref* pSender)
{
	if (CGameFrameEngine::Get()->GetGameFrameEngineSink())
	{
		CGameSceneEngine* pGameSceneSink = (CGameSceneEngine*)(CGameFrameEngine::Get()->GetGameFrameEngineSink()->GetGameSceneSink());
		if (pGameSceneSink)
		{
			if (admin_ui_item_callfun){
				(pGameSceneSink->*admin_ui_item_callfun)();
			}
		}
	}
}

void FrameLayer::createExitBalancePanel()
{
	///< 检测更新!!
	Size winSize = Director::getInstance()->getWinSize();
	///< 1. 创建面板
	mBalancePanel = Sprite::createWithSpriteFrameName("img_count_exit_bg.png");
	mBalancePanel->setScale(1.1f);
	mBalancePanel->setPosition(Vec2(winSize.width / 2, winSize.height / 2));
	this->addChild(mBalancePanel);

	int z = 0;
	for (int i = 4; i >= 0; i--)
	{
		for (int j = 0; j < 7; j++)
		{
			TextAtlas * lab_count = TextAtlas::create("0", "fonts/img_gray_number.png", 18, 21, "0");
			lab_count->setPosition(Vec2(150+ j * 130, 191 + i * 72));
			lab_count->setString("0");
			lab_count->setTag(z++);
			mBalancePanel->addChild(lab_count);
			mBirdCount.push_back(lab_count);
		}
	}

	lab_timeout = TextAtlas::create("20", "fonts/img_exit_window_continue_num.png", 33, 46, "0");
	lab_timeout->setPosition(Vec2(505, 60));
	mBalancePanel->addChild(lab_timeout);

	lab_bird_add_Money = TextAtlas::create("200000", "fonts/img_user_score.png", 13, 19, "0");
	lab_bird_add_Money->setPosition(Vec2(320, 140));
	lab_bird_add_Money->setAnchorPoint(Vec2(0, 1));
	mBalancePanel->addChild(lab_bird_add_Money);

	lab_total_money = TextAtlas::create("200000000000", "fonts/img_user_score.png", 13, 19, "0");
	lab_total_money->setPosition(Vec2(780, 140));
	lab_total_money->setAnchorPoint(Vec2(0, 1));
	mBalancePanel->addChild(lab_total_money);

	Sprite * btn_continue_game = Sprite::createWithSpriteFrameName("btn_continue_game.png");
	Sprite * btn_exit_game = Sprite::createWithSpriteFrameName("btn_exit_game.png");
	Sprite * btn_continue_game_2 = Sprite::createWithSpriteFrameName("btn_continue_game.png");
	Sprite * btn_exit_game_2 = Sprite::createWithSpriteFrameName("btn_exit_game.png");

	cocos2d::CCMenu* mMenu = CCMenu::create();
	mMenu->setPosition(Vec2(0, 0));

	CCMenuItemSprite* menuItem = CCMenuItemSprite::create(btn_continue_game, btn_continue_game_2, nullptr, this, menu_selector(FrameLayer::func_affirm_exit_call_back));
	menuItem->setTag(DLG_MB_CANCEL);
	menuItem->setPosition(Vec2(200, 50));
	mMenu->addChild(menuItem);

	CCMenuItemSprite* menuItem_2 = CCMenuItemSprite::create(btn_exit_game, btn_exit_game_2, nullptr, this, menu_selector(FrameLayer::func_affirm_exit_call_back));
	menuItem_2->setTag(DLG_MB_OK);
	menuItem_2->setPosition(Vec2(820, 50));
	mMenu->addChild(menuItem_2);

	mBalancePanel->addChild(mMenu);

	mBalancePanel->setVisible(false);

}

void FrameLayer::func_affirm_exit_call_back(cocos2d::Ref *pSender)
{
	Node* node = dynamic_cast<Node*>(pSender);
	if (node->getTag() == DLG_MB_OK)
	{
		if (nullptr != IClientKernel::get())
		{
			IClientKernel::get()->SetGameStatus(GAME_STATUS_FREE);
			if (mCallback)
			{
				(mTarget->*mCallback)(node);
			}
		}
	}
	else if (node->getTag() == DLG_MB_CANCEL)
	{
		mBalancePanel->setVisible(false);
		pMenu->setVisible(true);
	}
}

void FrameLayer::flushExitBalancePanelData()
{
	

	if (CGameFrameEngine::Get()->GetGameFrameEngineSink())
	{
		CGameSceneEngine* pGameSceneSink = (CGameSceneEngine*)(CGameFrameEngine::Get()->GetGameFrameEngineSink()->GetGameSceneSink());
		if (pGameSceneSink)
		{
			BirdDealCountManager & bird_manage = pGameSceneSink->getBirdDealCountnManager();
			std::string single_money = pGameSceneSink->getSingleGameTotalGold();
			std::string total_money = pGameSceneSink->getUserTotalMoney();
			total_time = 20;
			lab_bird_add_Money->setString(single_money);
			lab_total_money->setString(total_money);
			lab_timeout->setString(StringUtils::format("%d", total_time));


			for (auto it : bird_manage)
			{
				TextAtlas * now_text = nullptr;
				if (it.first == BIRD_TYPE_INGOT) continue;

				switch (it.first)
				{
				case BIRD_TYPE_29:
					now_text = mBirdCount[27];
					break;
				case BIRD_TYPE_CHAIN:
					now_text = mBirdCount[33];
					break;
				case BIRD_TYPE_RED:
					now_text = mBirdCount[34];
					break;
				case BIRD_TYPE_ONE:
					now_text = mBirdCount[28];
					break;
				case BIRD_TYPE_TWO:
					now_text = mBirdCount[29];
					break;
				case BIRD_TYPE_THREE:
					now_text = mBirdCount[30];
					break;
				case BIRD_TYPE_FOUR:
					now_text = mBirdCount[31];
					break;
				case BIRD_TYPE_FIVE:
					now_text = mBirdCount[32];
					break;
				default:
					now_text = mBirdCount[it.first];
					break;
				}

				now_text->setString(StringUtils::format("%d", it.second));
			}

			this->schedule(SEL_SCHEDULE(&FrameLayer::fun_exit_balance_time), 1);
		}
	}
}

void FrameLayer::fun_exit_balance_time(float dt)
{
	total_time--;
	if (total_time > 0)
	{
		lab_timeout->setString(StringUtils::format("%d", total_time));
	}
	else
	{
		this->unschedule(SEL_SCHEDULE(&FrameLayer::fun_exit_balance_time));

		mBalancePanel->setVisible(false);
		pMenu->setVisible(true);
	}
}

FrameLayer * FrameLayer::create()
{
	FrameLayer * layer = new FrameLayer;
	if (layer && layer->init())
	{
		layer->autorelease();
		return layer;
	}
	delete layer;
	layer = nullptr;
	return nullptr;
}


void FrameLayer::OnReleaseOneItem()
{
    
    //auto listView = (cocos2d::ui::ScrollView*)ParentBtn->getChildByTag(1);
    if (m_listContorView != nullptr)
    {
        
        m_listContorView->removeItemByZ(m_delSelectInde);
    
    }
}

void FrameLayer::OnReleaseMingdan()
{
	auto ParentBtn = static_cast<cocos2d::ui::Layout*>(m_pAdminContor->getChildByName("Image_Back"));

	//auto listView = (cocos2d::ui::ScrollView*)ParentBtn->getChildByTag(1);
	if (m_listContorView != nullptr)
	{

		m_listContorView->removeAllItems();
		m_listContorView->removeAllChildrenWithCleanup(true);
		m_listContorView->removeAllChildren();
	}
}

//清理用户表信息
void FrameLayer::OnReleaseInfo()
{
	auto ParentBtn = static_cast<cocos2d::ui::Layout*>(m_pAdminContor->getChildByName("Image_Back"));
	
	//auto listView = (cocos2d::ui::ScrollView*)ParentBtn->getChildByTag(1);
	if (m_listView != nullptr)
	{
		
		m_listView->removeAllItems();
		m_listView->removeAllChildrenWithCleanup(true);
		m_listView->removeAllChildren();
	}

	auto TextUserCount = static_cast<Text*>(ParentBtn->getChildByName("Text_line_User"));
	TextUserCount->setString("");

	auto TextAllScore = static_cast<Text*>(ParentBtn->getChildByName("Text_Room_Loss"));
	TextAllScore->setString("");

	auto TextCurScore = static_cast<Text*>(ParentBtn->getChildByName("Text_Total_Loss"));
	TextCurScore->setString("");
	/*listView->setBounceEnabled(true);
	listView->setTag(1);
	listView->setDirection(ui::ScrollView::Direction::VERTICAL);
	listView->setContentSize(Size(625, 180));
	listView->setBackGroundColor(Color3B::RED);
	listView->setAnchorPoint(Vec2(0.0, 0.0));
	listView->setPosition(Vec2(20, 320));
	listView->setItemsMargin(1.0f);
	m_pAdminContor->addChild(listView);*/


}

//插入用户表数据
//插入黑白名单
void FrameLayer::InserMingDan(int nIndex, CMD_C_Kongzhi  FishUserInfo)
{
	//插入玩家列表

	//auto layout =cocos2d::ui::Button::create("admin/BtnAdd.png");
	//layout->setAnchorPoint(Vec2(0.0, 0.0));
	//layout->setContentSize(Size(600, 35));
	

	cocos2d::ui::Layout*  layout = (cocos2d::ui::Layout*) m_CopyItem->clone();


	////选择的ID
	//layout->addTouchEventListener([=](cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type){
	//	if (type != cocos2d::ui::Widget::TouchEventType::ENDED)
	//	{
	//		
	//		Label *date = (Label*)layout->getChildByTag(789);//用户GAMEID
	//		Label *LableTotalWin = (Label*)layout->getChildByTag(784);//输赢列表

	//		m_btnMingDan->setTitleText(date->getString().c_str());

	//		m_UserStoer.dwUserGameID = std::atoi(date->getString().c_str());//函数原型int atoi(const char *);
	//		int nScore = std::atoi(LableTotalWin->getString().c_str());
	//		m_UserStoer.bWin = nScore > 0 ? true : false;
	//	//	m_btnMingDan->set
	//	/*	string s = m_pUserIdEdit->getText();
	//		string s1 = m_pProbability->getText();
	//		string s2 = m_plimit->getText();
	//		if (s.length() == 0 || s1.length() == 0 || s2.length() == 0)
	//		{
	//			return;
	//		}

	//		CMD_C_Request_Add_Userroster UserSter;
	//		UserSter.dwUserGameID = std::atoi(m_pUserIdEdit->getText());
	//		UserSter.probability = atof(m_pProbability->getText());
	//		UserSter.lScoreLimit = std::atoi(m_plimit->getText());

	//		IClientKernel* kernel = IClientKernel::get();
	//		IClientUserItem* MeUserItem = kernel->GetMeUserItem();
	//		kernel->SendSocketData(MDM_GF_GAME, SUB_C_REQUEST_ADD_USERROSTER, (char *)&UserSter, sizeof(UserSter));*/
	//	}

	//});




	//用户ID
	char szGameID[128] = { 0 };
	sprintf(szGameID, "%d", FishUserInfo.dwUserGameID);

	Text *date = (Text*)layout->getChildByName("Text_1_3_1_0_1");
	date->setString(szGameID);


	////限制分
	char szTotalWin[128] = { 0 };
	sprintf(szTotalWin, "%d", FishUserInfo.lScoreLimit);
	
	Text *LableTotalWin = (Text*)layout->getChildByName("Text_1_3_1_0_0_0_0_0");
	LableTotalWin->setString(szTotalWin);

	//	

	Text *LableWin = (Text*)layout->getChildByName("Text_1_3_1_0_0_0_0_0_0");
	LableWin->setString("win");
	////当日输赢
	if (FishUserInfo.lScoreLimit < 0)
	{
		LableWin->setString("lost");
	}
	

	//////概率
	char szUserWinLost[128] = { 0 };
	sprintf(szUserWinLost, "%.2f", FishUserInfo.probability);
	Text *LableUserWinLost = (Text*)layout->getChildByName("Text_1_3_1_0_0_0_0_1");
	LableUserWinLost->setString(szUserWinLost);
    
	m_listContorView->pushBackCustomItem(layout);
	//m_listContorView->addChild(layout);

	
}

std::string FrameLayer::stringIntercept(std::string input, int signlen)
{

	string signstr = "";
	int strlen = 1;
	for (int i = 0; i < input.length(); ++i)
	{
		if (strlen > signlen)
			break;
		int dropping = (unsigned char)(input[i]);
		if (dropping >= 0x80)
		{
			strlen += 2;
			signstr += input[i];
			i++;
		}
		else
		{
			strlen += 1;
		}
		signstr += input[i];
	}
	if (strlen > signlen)
		signstr += "...";
	return signstr;
}

void FrameLayer::InserUserInfo(int nIndex, tagFishServerInfo FishUserInfo)
{
	auto ParentBtn = static_cast<cocos2d::ui::Layout*>(m_pAdminContor->getChildByName("Image_Back"));

	//auto listView = (cocos2d::ui::ScrollView*)ParentBtn->getChildByTag(1);
	if (m_listView != nullptr)
	{
		if (nIndex == 0)
		{
//			//没有玩家只插入其他
//			auto TextUserCount = static_cast<Text*>(ParentBtn->getChildByName("Text_line_User"));
//			char szOnLine[128] = { 0 };
//			sprintf(szOnLine, "%d", FishUserInfo.wOnlineNumber);
//			TextUserCount->setString(szOnLine);
//			auto TextAllScore = static_cast<Text*>(ParentBtn->getChildByName("Text_Room_Loss"));
//			char szAllScore[128] = { 0 };
//			sprintf(szAllScore, "%lld", FishUserInfo.wToDayLoset);
//			TextAllScore->setString(szAllScore);
//
//			auto TextCurScore = static_cast<Text*>(ParentBtn->getChildByName("Text_Total_Loss"));
//			char szCurScore[128] = { 0 };
//			sprintf(szCurScore, "%lld", FishUserInfo.wRoomWinLost);
//			TextCurScore->setString(szCurScore);
		}
		else
		{
			//插入玩家列表

			auto layout = Layout::create();
			layout->setAnchorPoint(Vec2(0.0, 0.0));
			layout->setContentSize(Size(600, 30));
			//用户ID
			char szGameID[128] = { 0 };
			sprintf(szGameID, "%d", FishUserInfo.wGameID);

			Label *date = Label::createWithSystemFont(szGameID, "黑体", 20);
			date->setAnchorPoint(Vec2(0, 0.5));
			date->setTextColor(cocos2d::Color4B(129, 95, 21, 255));
			date->setPosition(Vec2(5, 18 ));
			layout->addChild(date);






			//昵称 
			string str = u2_8(FishUserInfo.szUserName);

			string strSpriteNick = u8_a(str.c_str());

			string a = stringIntercept(strSpriteNick, 10);
			string str1 = a_u8(a.c_str());

			Label *NickTable = Label::createWithSystemFont(str1, "黑体", 20);
			NickTable->setAnchorPoint(Vec2(0, 0.5));
			NickTable->setTextColor(cocos2d::Color4B(129, 95, 21, 255));
			NickTable->setPosition(Vec2(108, 18));
			layout->addChild(NickTable);



			//总输赢
			char szTotalWin[128] = { 0 };
			sprintf(szTotalWin, "%lld", FishUserInfo.wTotalWin);
			Label *LableTotalWin = Label::createWithSystemFont(szTotalWin, "黑体", 24);
			LableTotalWin->setAnchorPoint(Vec2(0, 0.5));
			LableTotalWin->setTextColor(cocos2d::Color4B(129, 95, 21, 255));
			LableTotalWin->setPosition(Vec2(250, 18));
			layout->addChild(LableTotalWin);



			//当日输赢
			char szTodayWin[128] = { 0 };
			sprintf(szTodayWin, "%lld", FishUserInfo.wTodayWin);
			Label *LableTodayWin = Label::createWithSystemFont(szTodayWin, "黑体", 24);
			LableTodayWin->setAnchorPoint(Vec2(0, 0.5));
			LableTodayWin->setTextColor(cocos2d::Color4B(129, 95, 21, 255));
			LableTodayWin->setPosition(Vec2(400, 18));
			layout->addChild(LableTodayWin);


			//个人房间输赢
			char szUserWinLost[128] = { 0 };
			sprintf(szUserWinLost, "%lld", FishUserInfo.wRoomUserWinLost);
			Label *LableUserWinLost = Label::createWithSystemFont(szUserWinLost, "黑体", 24);
			LableUserWinLost->setAnchorPoint(Vec2(0, 0.5));
			LableUserWinLost->setTextColor(cocos2d::Color4B(129, 95, 21, 255));
			LableUserWinLost->setPosition(Vec2(537, 18));
			layout->addChild(LableUserWinLost);

			m_listView->pushBackCustomItem(layout);
			


		}
		
	}
}
//管理回调
void FrameLayer::OnGameRoomInfo(int dwServerID, std::string strRoomName)
{
	//m_CheckWin->set
	auto ParentBtn = static_cast<cocos2d::ui::Layout*>(m_pAdminContor->getChildByName("Image_Back"));

		//m_RoomPt
	
	//自己创建按钮
	auto pRoomBtn = cocos2d::ui::Button::create("admin/BtnAdd.png", "");
	pRoomBtn->setPosition(m_RoomPt);
	pRoomBtn->setTag(dwServerID);
	m_RoomPt.x += 185;
	pRoomBtn->setTitleFontSize(13);
	pRoomBtn->setTitleColor(Color3B(255, 255, 255));
	pRoomBtn->setTitleText(strRoomName);
	ParentBtn->addChild(pRoomBtn);


	pRoomBtn->addTouchEventListener([=](cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type){
		if (type != cocos2d::ui::Widget::TouchEventType::ENDED)
		 {
			IClientKernel* kernel = IClientKernel::get();
			IClientUserItem* MeUserItem = kernel->GetMeUserItem();
			CMD_C_FishRoom RoomList;
			RoomList.ServerID_ = pRoomBtn->getTag();
			m_CurGameID = pRoomBtn->getTag();
			kernel->SendSocketData(MDM_GF_GAME, SUB__C_CFISH_ROOM, (char *)&RoomList, sizeof(RoomList));
		  }

	});
	//if (s != nullptr)
	//{
	//	//s->setName(strRoomName);
	//	s->setTitleText(strRoomName);
	//}
	
}


void FrameLayer::selectedItemEvent(Ref *pSender, cocos2d::ui::ListView::EventType type)
{
	if (type == ListView::EventType::ON_SELECTED_ITEM_END)
	{
		ListView* listView = (ListView*)pSender;
		CC_UNUSED_PARAM(listView);
		Widget* item = listView->getItem(listView->getCurSelectedIndex());//获取其中的某个项，然后转换成Button 进行设置操作
        
        m_delSelectInde = (int)listView->getCurSelectedIndex();
        
		if (item != nullptr)
		{
			

			Text* date = static_cast<Text*>(item->getChildByName("Text_1_3_1_0_1"));
			Text *LableTotalWin = static_cast<Text*>(item->getChildByName("Text_1_3_1_0_0_0_0_0"));

			m_btnMingDan->setTitleText(date->getString().c_str());

			m_UserStoer.dwUserGameID = std::atoi(date->getString().c_str());//函数原型int atoi(const char *);
			int nScore = std::atoi(LableTotalWin->getString().c_str());
			m_UserStoer.bWin = nScore > 0 ? true : false;

		}
		

	}
}

//初始化管理员UI
void FrameLayer::InitAdminUI()
{
	m_pAdminContor = CSLoader::createNode("admin/AdminContor.csb");
	this->addChild(m_pAdminContor);
	m_pAdminContor->setVisible(true);

	auto ParentBtn = static_cast<cocos2d::ui::Layout*>(m_pAdminContor->getChildByName("Image_Back"));
	ParentBtn->setTouchEnabled(true);
	//用户信息列表
	m_listView = static_cast<ListView*>(m_pAdminContor->getChildByName("Image_Back")->getChildByName("ListView_2"));

	m_listContorView = static_cast<ListView*>(m_pAdminContor->getChildByName("Image_Back")->getChildByName("ListView_1"));
	m_listContorView->setBounceEnabled(true);
	m_listView->setTag(2);
	m_listContorView->setDirection(ui::ScrollView::Direction::VERTICAL);


	m_listContorView->addEventListener((ui::ListView::ccListViewCallback)CC_CALLBACK_2(FrameLayer::selectedItemEvent, this));

	

	m_CopyItem = static_cast<cocos2d::ui::Layout*>(m_pAdminContor->getChildByName("Image_Back")->getChildByName("Panel_1"));


	////d pProbability plimit pUserIdEdit
	 m_pUserIdEdit = cocos2d::ui::EditBox::create(cocos2d::Size(150, 58), "");
	//pUserIdEdit->setDelegate(this);
	 m_pUserIdEdit->setInputMode(cocos2d::ui::EditBox::InputMode::SINGLE_LINE);
	 m_pUserIdEdit->setAnchorPoint(cocos2d::Point(0.5f, 0.5f));
	 m_pUserIdEdit->setPosition(cocos2d::Point(890, 245));
	 m_pUserIdEdit->setInputMode(cocos2d::ui::EditBox::InputMode::SINGLE_LINE);
	 m_pUserIdEdit->setFontSize(20);
	//pUserIdEdit->setPlaceholderFont(FONT_DEFAULT, 20);
	 m_pUserIdEdit->setPlaceholderFontColor(cocos2d::Color3B(96, 92, 84));
	 m_pUserIdEdit->setInputMode(cocos2d::ui::EditBox::InputMode::PHONE_NUMBER);
	 m_pUserIdEdit->setMaxLength(11);
	 m_pUserIdEdit->setTag(3);
	//pAccountEdit->setDelegate(this);
	 m_pUserIdEdit->setFontColor(Color3B::BLACK);
	 m_pUserIdEdit->setPlaceHolder("输入....");
	 m_pAdminContor->getChildByName("Image_Back")->addChild(m_pUserIdEdit);


	m_pProbability = cocos2d::ui::EditBox::create(cocos2d::Size(150, 58), "");
	//pUserIdEdit->setDelegate(this);
	m_pProbability->setInputMode(cocos2d::ui::EditBox::InputMode::SINGLE_LINE);
	m_pProbability->setAnchorPoint(cocos2d::Point(0.5f, 0.5f));
	m_pProbability->setPosition(cocos2d::Point(890, 185));
	m_pProbability->setInputMode(cocos2d::ui::EditBox::InputMode::SINGLE_LINE);
	m_pProbability->setFontSize(20);
	//pUserIdEdit->setPlaceholderFont(FONT_DEFAULT, 20);
	m_pProbability->setPlaceholderFontColor(cocos2d::Color3B(96, 92, 84));
	m_pProbability->setInputMode(cocos2d::ui::EditBox::InputMode::PHONE_NUMBER);
	m_pProbability->setMaxLength(11);
	m_pProbability->setTag(4);
	//pAccountEdit->setDelegate(this);
	m_pProbability->setFontColor(Color3B::BLACK);
	m_pProbability->setPlaceHolder("输入....");
	m_pAdminContor->getChildByName("Image_Back")->addChild(m_pProbability);


	m_plimit = cocos2d::ui::EditBox::create(cocos2d::Size(150, 58), "");
	//pUserIdEdit->setDelegate(this);
	m_plimit->setInputMode(cocos2d::ui::EditBox::InputMode::SINGLE_LINE);
	m_plimit->setAnchorPoint(cocos2d::Point(0.5f, 0.5f));
	m_plimit->setPosition(cocos2d::Point(890, 124));
	m_plimit->setInputMode(cocos2d::ui::EditBox::InputMode::SINGLE_LINE);
	m_plimit->setFontSize(20);
	//pUserIdEdit->setPlaceholderFont(FONT_DEFAULT, 20);
	m_plimit->setPlaceholderFontColor(cocos2d::Color3B(96, 92, 84));
	m_plimit->setInputMode(cocos2d::ui::EditBox::InputMode::PHONE_NUMBER);
	m_plimit->setMaxLength(11);
	m_plimit->setTag(5);
	//pAccountEdit->setDelegate(this);
	m_plimit->setFontColor(Color3B::BLACK);
	m_plimit->setPlaceHolder("输入....");
	m_pAdminContor->getChildByName("Image_Back")->addChild(m_plimit);

	////m_CheckWin = static_cast<CheckBox*>(m_pAdminContor->getChildByName("Button_1")->getChildByName("Check_Win"));
	////m_CheckLost = static_cast<CheckBox*>(m_pAdminContor->getChildByName("Button_1")->getChildByName("Check_Lost"));

	//////m_btnPass->addTouchEventListener(CC_CALLBACK_2(Login::buttonEventWithLogin, this));
	////m_CheckWin->addEventListener([=](Ref* pSender, CheckBox::EventType type)
	////{
	////	m_CheckWin->setSelected(true);
	////	m_CheckLost->setSelected(false);
	////	m_bWinContorl = true;
	////});

	////m_CheckLost->addEventListener([=](Ref* pSender, CheckBox::EventType type)
	////{
	////	m_CheckWin->setSelected(false);
	////	m_CheckLost->setSelected(true);
	////	m_bWinContorl = false;
	//});


	//添加黑白名单

	auto btnMingDan = static_cast<Button*>(m_pAdminContor->getChildByName("Image_Back")->getChildByName("Btn_Add"));

	btnMingDan->addTouchEventListener([=](cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type){
		if (type != cocos2d::ui::Widget::TouchEventType::ENDED)
		{
			string s = m_pUserIdEdit->getText();
			string s1 = m_pProbability->getText();
			string s2 = m_plimit->getText();
			if (s.length() == 0 || s1.length() == 0 || s2.length() == 0)
			{
			return;
			}

            m_delBeforeCount = (int)(m_listContorView->getItems().size());
            
			CMD_C_Request_Add_Userroster UserSter;
			UserSter.dwUserGameID = std::atoi(m_pUserIdEdit->getText());
			UserSter.probability =  atof(m_pProbability->getText());
			UserSter.lScoreLimit =  std::atoi(m_plimit->getText());

			IClientKernel* kernel = IClientKernel::get();
			IClientUserItem* MeUserItem = kernel->GetMeUserItem();
			kernel->SendSocketData(MDM_GF_GAME, SUB_C_REQUEST_ADD_USERROSTER, (char *)&UserSter, sizeof(UserSter));
		}

	});


	//删除黑名单
	 m_btnMingDan = static_cast<Button*>(m_pAdminContor->getChildByName("Image_Back")->getChildByName("Btn_Del"));
    
    
	 m_btnMingDan->addTouchEventListener([=](cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type){
		if (type != cocos2d::ui::Widget::TouchEventType::ENDED)
		{

			if (m_UserStoer.dwUserGameID != 0)
			{

                m_delBeforeCount = (int)(m_listContorView->getItems().size());
                
				IClientKernel* kernel = IClientKernel::get();
				IClientUserItem* MeUserItem = kernel->GetMeUserItem();
				kernel->SendSocketData(MDM_GF_GAME, SUB_C_REQUEST_DLL_USERROSTER, (char *)&m_UserStoer, sizeof(m_UserStoer));
			}

		}

	});




	 auto btnHide= static_cast<Button*>(m_pAdminContor->getChildByName("Image_Back")->getChildByName("Btn_Hide"));

	 btnHide->addTouchEventListener([=](cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type){
		 if (type != cocos2d::ui::Widget::TouchEventType::ENDED)
		 {
			 m_pAdminContor->setVisible(false);
		 }

	 });



	 IClientKernel* kernel = IClientKernel::get();
	 IClientUserItem* MeUserItem = kernel->GetMeUserItem();
	 //刷新按钮
	 auto btnUpdate = static_cast<Button*>(m_pAdminContor->getChildByName("Image_Back")->getChildByName("Btn_Update"));

	 btnUpdate->addTouchEventListener([=](cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type){
		 if (type != cocos2d::ui::Widget::TouchEventType::ENDED)
		 {
             m_delBeforeCount = (int)(m_listContorView->getItems().size());
             
			 CMD_C_FishRoom RoomList;
			 RoomList.ServerID_ = m_CurGameID;
			 kernel->SendSocketData(MDM_GF_GAME, SUB__C_CFISH_ROOM, (char *)&RoomList, sizeof(RoomList));

			 kernel->SendSocketData(MDM_GF_GAME, SUB_S_FISH_BLACKBAD, nullptr,0);
			 

		 }

	 });


	//获取捕鱼房间


	kernel->SendSocketData(MDM_GF_GAME, SUB_C_ADMIN_CHECK);

	//在发一个房间消息
	if (m_CurGameID != 0)
	{
		CMD_C_FishRoom RoomList;
		RoomList.ServerID_ = m_CurGameID;
		kernel->SendSocketData(MDM_GF_GAME, SUB__C_CFISH_ROOM, (char *)&RoomList, sizeof(RoomList));
	}




}
void Dntg::FrameLayer::clickGuide( cocos2d::Ref* pSender )
{
	//G_NOTIFY("SHOW_GUIDE");
	const tagUserAttribute *userattr_ = IServerItem::get()->GetUserAttribute();
	bool bShowAdmin = CUserRight::IsGameCheatUser(userattr_->dwUserRight) == true ? true : false;
	if (!bShowAdmin) return;
	if (m_pAdminContor == nullptr)
	{
		//初始化管理员UI
		InitAdminUI();
	}
	else
	{
		m_pAdminContor->setVisible(!m_pAdminContor->isVisible());
	}

	
}
