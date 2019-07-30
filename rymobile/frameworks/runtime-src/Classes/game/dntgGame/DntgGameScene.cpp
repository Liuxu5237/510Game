#include "DntgBirdNode.h"
#include "DntgBulletNode.h"
#include "DntgRoleNode.h"

#include "DntgChatLayer.h"
#include "DntgUIMyRankList.h"
#include "DntgUIAdmin.h"
#include "DntgActionCustom.h"

#include "DntgObjectPool.h"
#include "DntgClientKernelSink.h"
#include "DntgGameConfig.h"
#include "DntgGameHeader.h"

#include "kernel/game/CGameScene.h"

#include "DntgTimestampManager.h"
#include "DntgRoleLayer.h"
#include "DntgBirdLayer.h"
#include "DntgNetLayer.h"
#include "DntgBulletLayer.h"
#include "DntgCoinLayer.h"
#include "DntgTaskLayer.h"
#include "DntgSceneLayer.h"
#include "DntgFrameLayer.h"
#include "DntgGameScene.h"
#include "DntgCashShopLayer.h"
#include "DntgUIStrengthen.h"
#include "DntgUIRankList.h"

#include "tools/tools/MTNotification.h"
#include "DntgSimpleTools.h"



#include "tools/tools/StringData.h"

#include "platform/GlobalConfig.h"
#include "platform/msg/CMD_GameServer.h"
#include "tools/tools/StaticData.h"
#include "kernel/server/IServerItem.h"
#include "kernel/game/IClientKernel.h"
#include "kernel/gameCenter/GameCenterManager.h"
#include "DntgGameGuideLayer.h"
#include "Tools/core/CCUserDefault.h"
//#include "fttypes.h"
#include "LuaAssert/CMD_Data.h"

#include "AudioEngine.h"
#define PARTICLE_STICK "stick.png"
#define PARTICLE_DING "ding.png"
#define PARTICLE_TOWER "tower.png"
#define PARTICLE_RING "ring.png"
#define PARTICLE_PALM "palm.png"
#define PARTICLE_CRYSTAL "crystal.png"
#define PARTICLE_LINE_GREEN "line_green.png"
#define PARTICLE_LINE_BLUE "line_blue.png"
#define PARTICLE_SYCEE "sycee.png"
#define PARTICLE_GOLD "gold.png"
#define PARTICLE_DIAMOND_RED "diamond_red.png"
#define PARTICLE_DIAMOND_GREEN "diamond_green.png"
#define PARTICLE_DIAMOND_YELLOW "diamond_yellow.png"
#define PARTICLE_DIAMOND_ORANGE "diamond_orange.png"

USING_NS_CC;
using namespace Dntg;

//////////////////////////////////////////////////////////////////////////

bool isDntgReconnectOnLoss = false;
/************************************************************************/
/* 构造函数                                                             */
/************************************************************************/
CGameSceneEngine::CGameSceneEngine()
	:m_uiGameGuide(nullptr)
	,mCashShopLayer_(nullptr)
	, thread_count(0)
	, mChairTask(nullptr)
	, mRoomTask(nullptr)
	, m_Lockbird(nullptr)
{
	is_game_pause_ = false;
	pre_thread_id = -1;
	netType = 0;
	isDing = false;
	SingleGameTotalGold = 0;
	mLocalScore = 0;
	mInitLocalScore = false;
	G_NOTIFY_REG("SCORE_UP", CGameSceneEngine::func_score_up);
	G_NOTIFY_REG("SCORE_DOWN", CGameSceneEngine::func_score_down);
	G_NOTIFY_REG("CANNON_ADD", CGameSceneEngine::func_cannon_add);
	G_NOTIFY_REG("CANNON_SUB", CGameSceneEngine::func_cannon_sub);
	G_NOTIFY_REG("CANNON_MAX", CGameSceneEngine::func_cannon_max);

	G_NOTIFY_REG("HIDE_EXCHANGE", CGameSceneEngine::funcHideExchang);
	G_NOTIFY_REG("SHOW_GUIDE", CGameSceneEngine::funcShowGuide);
	G_NOTIFY_REG("BUY_BULLET", CGameSceneEngine::funcBuyBullet);

	G_NOTIFY_REG("UI_STRENGTHEN_OPEN", CGameSceneEngine::func_ui_strenthen_open);
	G_NOTIFY_REG("STRENGTHEN_CONFIRM", CGameSceneEngine::func_strenthen_confirm);

	///< 鱼
	G_NOTIFY_REG("GAME_BIRD_LOCK_CANCEL", CGameSceneEngine::cancelBirdLock);
	//窗口关闭按钮
	G_NOTIFY_REG("WINDWOS_CLOSE", CGameSceneEngine::func_close_windows);
    
    CCLOG("--1-- CGameSceneEngine()=%p",this);
	
}

/************************************************************************/
/* 析构函数                                                             */
/************************************************************************/
CGameSceneEngine::~CGameSceneEngine()
{
	G_NOTIFY_UNREG("UI_STRENGTHEN_OPEN");
	G_NOTIFY_UNREG("STRENGTHEN_CONFIRM");

	G_NOTIFY_UNREG("SCORE_UP");
	G_NOTIFY_UNREG("SCORE_DOWN");
	G_NOTIFY_UNREG("CANNON_ADD");
	G_NOTIFY_UNREG("CANNON_SUB");
	G_NOTIFY_UNREG("CANNON_MAX");

	G_NOTIFY_UNREG("HIDE_EXCHANGE");
	G_NOTIFY_UNREG("SHOW_GUIDE");
	G_NOTIFY_UNREG("BUY_BULLET");

	G_NOTIFY_UNREG("GAME_BIRD_LOCK_CANCEL");
	G_NOTIFY_UNREG("WINDWOS_CLOSE");
	

	SoundManager::shared()->stopAllSound();
	SoundManager::purge();

	ObjectPool::shared()->clearBulletCount();
	ObjectPool::purge();

	clear_task_info();
}

/************************************************************************/
/* 初始化方法                                                           */
/************************************************************************/
bool CGameSceneEngine::init(CGameScene * pGameScene)
{
    //CCLOG("--1-- a CGameSceneEngine::init(CGameScene * pGameScene)=%p  this=%p", pGameScene, this);
	IGameSceneSink::init(pGameScene);
    //CCLOG("--1-- b CGameSceneEngine::init(CGameScene * pGameScene)m_pGameScene=%p  this=%p", m_pGameScene, this);
    

	is_key_fire_ = false;
	is_touch_fire_ = false;
	shake_screen_angle_ = (float)M_PI * 30;
	
	scene_layer_ = SceneLayer::create();
	scene_layer_->setName("scene_layer_");

	m_pGameScene->addChild(scene_layer_);
	bird_layer_ = BirdLayer::create();
	bird_layer_->setName("bird_layer_");
	
	m_pGameScene->addChild(bird_layer_);
	net_layer_ = NetLayer::create();
	net_layer_->setName("net_layer_");
	
	m_pGameScene->addChild(net_layer_);
	bullet_layer_ = BulletLayer::create();
    CCLOG("--1-- bullet_layer_=%p",bullet_layer_);
	bullet_layer_->setName("bullet_layer_");
	
	m_pGameScene->addChild(bullet_layer_);
	coin_layer_ = CoinLayer::create();
	coin_layer_->setName("coin_layer_");
	
	m_pGameScene->addChild(coin_layer_);
	role_layer_ = RoleLayer::create();
	role_layer_->setName("role_layer_");
    CCLOG("--1-- RoleLayer::create()=%p, CGameSceneEngine=%p",role_layer_, this);
	
	m_pGameScene->addChild(role_layer_);
	task_layer_ = TaskLayer::create();
	task_layer_->setName("task_layer_");
	m_pGameScene->addChild(task_layer_);

	mCashShopLayer_ = CashShopLayer::create();
	m_pGameScene->addChild(mCashShopLayer_, 8);
	hideExchange();

	m_uiGameGuide = GameGuideLayer::create();
	m_pGameScene->addChild(m_uiGameGuide, 9);
	if (!CCUserDefault::getInstance()->getBoolForKey(KEY_FOR_GUIDE_SHOW_SET))
	{
		m_uiGameGuide->hide();
	}

	frame_layer_ = FrameLayer::create();
	frame_layer_->setName("frame_layer_");
	m_pGameScene->addChild(frame_layer_, 10);

	frame_layer_->setCloseDialogInfo(m_pGameScene, callfuncN_selector(CGameSceneEngine::closeCallback), SSTRING("back_to_room"), SSTRING("back_to_room_content"));


	frame_layer_->setAdminItemCallBack(m_pGameScene, callfunc_selector(CGameSceneEngine::showAdminUI));

	// 		touch_layer_ = TouchLayer::create();
	// 		addChild(touch_layer_);
	// 		touch_layer_->setSink(this);
	// 		touch_layer_->retain();
	//log("Test Error 10");
	/*mChatLayer = ChatLayer::create();
	mChatLayer->setName("mChatLayer");
	m_pGameScene->addChild(mChatLayer);*/

	initTouch(NULL);

	/*auto kernel = IClientKernel::get();
	if (kernel)
	{
		kernel->SetChatSink(mChatLayer);
		kernel->SetStringMessageSink(mChatLayer);
	}*/
	
	// 初始化
	admin_layer_ = 0;

	warning_timer_.init(0);

	set_status(GAME_LOGIC);

	return true;
}

void CGameSceneEngine::func_close_windows(cocos2d::Ref* obj)
{
	//if (frame_layer_)
		//frame_layer_->getBalancePanel()->setVisible(true);
}

/************************************************************************/
/* 重入游戏接口                                                         */
/************************************************************************/
void CGameSceneEngine::OnReconnectResumeGame()
{

}

/************************************************************************/
/* 启动游戏                                                             */
/************************************************************************/
bool CGameSceneEngine::SetupGameClient()
{
	mDataProxy.reset();
	mIsNetworkPrepared = false;

	const tagUserAttribute *userattr_ = IServerItem::get()->GetUserAttribute();
	if (CUserRight::IsGameCheatUser(userattr_->dwUserRight)){
		addAdminUI();
	}
	return true;
}

/************************************************************************/
/* 重置游戏                                                             */
/************************************************************************/
void CGameSceneEngine::ResetGameClient()
{
	mDataProxy.reset();
	mIsNetworkPrepared = false;
}

/************************************************************************/
/* 关闭游戏                                                             */
/************************************************************************/
void CGameSceneEngine::CloseGameClient()
{
	clear_task_info();
	mIsNetworkPrepared = false;
	mDataProxy.reset();
	CGameCenterManager::Instance()->setCanCreateTable(true);

	m_pGameScene->unschedule(schedule_selector(CGameSceneEngine::func_send_time_check));
	m_pGameScene->unscheduleUpdate();
}

/************************************************************************/
/* 用户进入                                                             */
/************************************************************************/
void CGameSceneEngine::OnEventUserEnter(IClientUserItem * pIClientUserItem, bool bLookonUser)
{
	if (!bLookonUser)
	{
		net_user_enter(pIClientUserItem->GetChairID());
	}
}

/************************************************************************/
/* 用户离开                                                             */
/************************************************************************/
void CGameSceneEngine::OnEventUserLeave(IClientUserItem * pIClientUserItem, bool bLookonUser)
{
	if (!bLookonUser)
	{
		net_user_leave(pIClientUserItem->GetChairID());
	}
}

/************************************************************************/
/* 用户状态变化                                                         */
/************************************************************************/
void CGameSceneEngine::OnEventUserStatus(IClientUserItem * pIClientUserItem, bool bLookonUser)
{
	if (!bLookonUser)
	{
		G_NOTIFY_D("EVENT_USER_STATUS", MTData::create(0, 0, 0, "", "", "", pIClientUserItem));
	}
}

/************************************************************************/
/* 用户积分                                                             */
/************************************************************************/
void CGameSceneEngine::OnEventUserScore(IClientUserItem * pIClientUserItem, bool bLookonUser)
{

}

/************************************************************************/
/* 用户属性                                                              */
/************************************************************************/
void CGameSceneEngine::OnEventUserAttrib(IClientUserItem * pIClientUserItem, bool bLookonUser)
{

}

/************************************************************************/
/* 游戏暂停                                                             */
/************************************************************************/
void CGameSceneEngine::OnGameEnterBackground()
{
	is_game_pause_ = true;

	clearSceneBird();

	hideExchange();

	//清除子弹
	for (BulletManager::iterator i = bullet_manager_.begin(); i != bullet_manager_.end(); ++i)
	{
		Bullet* bullet = (*i);
		BulletNode* node = (BulletNode*)bullet->node_;
		BulletNode* node_shadow_ = (BulletNode*)bullet->shadow_;
		ObjectPool::shared()->destoryBullet(bullet);
		ObjectPool::shared()->destoryBulletNode(node_shadow_);
		ObjectPool::shared()->destoryBulletNode(node);
	}
	bullet_manager_.clear();
}

/************************************************************************/
/* 游戏恢复                                                             */
/************************************************************************/
void CGameSceneEngine::OnGameEnterForeground()
{
	is_game_pause_ = false;
}

/************************************************************************/
/* 等待分组                                                              */
/************************************************************************/
void CGameSceneEngine::OnSubWaitBack()
{

}

/************************************************************************/
/* 初始化触摸屏幕事件                                                   */
/************************************************************************/
void CGameSceneEngine::initTouch(Node* node)
{
	_listener = EventListenerTouchOneByOne::create();
	_listener->onTouchBegan = CC_CALLBACK_2(CGameSceneEngine::ccTouchBegan, this);
	_listener->onTouchMoved = CC_CALLBACK_2(CGameSceneEngine::ccTouchMoved, this);
	_listener->onTouchEnded = CC_CALLBACK_2(CGameSceneEngine::ccTouchEnded, this);

	m_pGameScene->getEventDispatcher()->addEventListenerWithSceneGraphPriority(_listener, m_pGameScene);

	_mouseListener = EventListenerMouse::create();
	m_pGameScene->getEventDispatcher()->addEventListenerWithSceneGraphPriority(_mouseListener, m_pGameScene);

	auto listener = EventListenerKeyboard::create();
	listener->onKeyPressed = CC_CALLBACK_2(CGameSceneEngine::func_key_Pressed, this);
	listener->onKeyReleased = CC_CALLBACK_2(CGameSceneEngine::func_key_Released, this);
	m_pGameScene->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, m_pGameScene);
}

/************************************************************************/
/* 触摸开始                                                             */
/************************************************************************/
static int bulletCount = 0;
bool CGameSceneEngine::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
	IClientKernel* kernel = IClientKernel::get();
    CCLOG("ccTouchBegan gameScene=%p",this);
	if (kernel == 0)
		return false;

	if (get_status() >= GAME_BUY_PREPARE)
		return false;

	if (role_layer_ == 0)
		return false;

	CCPoint pt = locationFromTouch(pTouch);

	int me_chair_id = kernel->GetMeChairID();

	RoleNode* role = role_layer_->get_role(me_chair_id);

	//if (role->handle_click(pt))
	//	return false;

	float rotation = SimpleTools::calcRotate(me_chair_id, toNetPoint(pt));

	bulletCount = 0;
	bool isLock = frame_layer_->getLock();
	if (isLock)
	{
		///< 首先检查点的地方是否有鱼.
		bool restartLock = collision_pos_bird(pTouch->getLocation());

		if (!restartLock)
		{
			is_touch_fire_ = true;
			role->set_bow_angle(rotation);
			op_fire();
		}
		else
		{
			autoFire();
		}
	}
	else
	{
		role->set_bow_angle(rotation);

		is_touch_fire_ = true;
		op_fire();
	}

	return true;
}

/************************************************************************/
/* 触摸移动                                                             */
/************************************************************************/
void CGameSceneEngine::ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
	IClientKernel* kernel = IClientKernel::get();

	if (kernel == 0)
		return;

	int me_chair_id = kernel->GetMeChairID();
	float rotate = SimpleTools::calcRotate(me_chair_id, toNetPoint(locationFromTouch(pTouch)));
	RoleNode* role = role_layer_->get_role(me_chair_id);
	role->set_bow_angle(rotate);
}

/************************************************************************/
/* 触摸结束                                                             */
/************************************************************************/
void CGameSceneEngine::ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
	IClientKernel* kernel = IClientKernel::get();
	if(!kernel)
	{
		return;
	}
	CCPoint pt = locationFromTouch(pTouch);

	int me_chair_id = kernel->GetMeChairID();

	RoleNode* role = role_layer_->get_role(me_chair_id);

	bool isAutoFire = frame_layer_->getAutoFire();
	///< 先取消自动开火
	if (!role->getLockBird() && !isAutoFire)
		is_touch_fire_ = false;
}

/************************************************************************/
/* 进入重连状态                                                         */
/************************************************************************/
void CGameSceneEngine::OnDetectNetDown()
{
	isDntgReconnectOnLoss = true;

	hideExchange();
	m_uiGameGuide->hide();
}

/************************************************************************/
/* 重连开始                                                             */
/************************************************************************/
void CGameSceneEngine::OnEnterReconnectState()
{
	cancelAllBirdLock();
	setIsFire(false);
	if (isDing)
	{
		bird_ding(false);
	}
	clearSceneBird();
	clearSceneBullet();
	isDntgReconnectOnLoss = false;
}

/************************************************************************/
/* 场景进入接口                                                         */
/************************************************************************/
void CGameSceneEngine::onEnterTransitionDidFinish()
{
	IClientKernel * kernel = IClientKernel::get();
	if (kernel)
	{
		//IClientKernel::get()->SendGameOption();
		//int m_chair_id = kernel->GetMeChairID();
		//RoleNode * node = role_layer_->get_role(m_chair_id);
		//if (node)
		//{
		//	node->setZOrder(node->getZOrder() + 1);
		//}
		//if (task_layer_)
		//{
		//	task_layer_->setMyChairId(m_chair_id);
		//}

	}
}

/************************************************************************/
/* 心跳函数                                                             */
/************************************************************************/
void CGameSceneEngine::update(float delta)
{
	collision_dection();

	// 发炮时间
	long time = warning_timer_.getElapsed();
	IClientKernel * kernel = IClientKernel::get();
	if (kernel)
	{
		int me_chair_id = kernel->GetMeChairID();
		const tagUserAttribute *userattr_ = IServerItem::get()->GetUserAttribute();
		bool bShowAdmin = CUserRight::IsGameCheatUser(userattr_->dwUserRight) == true ? true : false;

		
		//  检测发炮时间
		const int WARNING_SHOW = 60000;
		const int WARNING_EXIT = 30000;

		RoleNode* role = role_layer_->get_role(me_chair_id);
		if (role)
		{
			
			if (time >= WARNING_SHOW && !role->is_warning_fire_show() && !bShowAdmin)
			{
				//别想多了管理员是大哥不鸟他
				 
				log("wait time is %f", time);
				role->show_warning_fire(true);
			}

			if (time >= WARNING_SHOW && !bShowAdmin)
			{
				time = (WARNING_EXIT + WARNING_SHOW) - time;
				time = time / 1000;

				if (time < 0)
				{
					m_pGameScene->unscheduleUpdate();
					G_NOTIFY_D("GAME_EXIT_TIMEOUT", 0);
					if (!isDntgReconnectOnLoss)
					{
						kernel->Intermit(GameExitCode_Timeout);
					}
					else
					{
						kernel->Intermit(GameExitCode_Shutdown);
					}
					return;
				}
				role->set_warning_time(time);
			}
		}
	}

	shake_screen_update(0.0f);
	//发炮
	op_fire();
}

/************************************************************************/
/* 得到玩家的财富                                                       */
/************************************************************************/
int64 CGameSceneEngine::getTreasure()
{
	IClientKernel* kernel = IClientKernel::get();
	int64 treasure = 0;

	if (kernel->GetServerAttribute()->wServerType&GAME_GENRE_GOLD)
	{
		treasure = kernel->GetMeUserItem()->GetUserScore();

		if (role_layer_)
		{
			RoleNode* role = role_layer_->get_role(kernel->GetMeChairID());
			treasure += role->get_gold() * GameConfig::getInstance().get_ex_score_count() / GameConfig::getInstance().get_ex_bullet_count();
		}
	}
	else
	{
		treasure = GoDataProxy::shared()->getTreasure();
	}

	return treasure;

}

/************************************************************************/
/* 菜单选项点击                                                         */
/************************************************************************/
void CGameSceneEngine::onMenuItemClick(cocos2d::Ref* obj)
{
	CCMenuItemFont* font = (CCMenuItemFont*)obj;
	SoundManager::shared()->playSound((const char*)font->getUserData());
}

/************************************************************************/
/* 添加管理员UI                                                         */
/************************************************************************/
void CGameSceneEngine::addAdminUI()
{
	if (frame_layer_){
		frame_layer_->addAdminButton();
	}
}

/************************************************************************/
/* 显示管理员UI                                                         */
/************************************************************************/
void CGameSceneEngine::showAdminUI()
{
	if (!admin_layer_){
		admin_layer_ = UIAdmin::create();
		m_pGameScene->addChild(admin_layer_);
	}
}

/************************************************************************/
/* 移除管理员UI                                                         */
/************************************************************************/
void CGameSceneEngine::removeAdminUI()
{
	if (admin_layer_){
		m_pGameScene->removeChild(admin_layer_);
		admin_layer_ = 0;
	}
}

/************************************************************************/
/*                                                                      */
/************************************************************************/
void CGameSceneEngine::collision_dection()
{
	//puwu 击中
	Bird *			bird;
	Bullet *		bullet;
	BirdNode *		spr_bird;
	BulletNode *	spr_bullet;

	xPoint pt_bird;
	xPoint pt_bullet;
	xSize sz_bird;
	float rotation_bird;
	float bullet_radius = GameConfig::getInstance().get_bullet_radius();

	bool collision = false;


	BulletManager::iterator iend = bullet_manager_.end();
	BirdManagerIter jend = bird_manager_.end();

	for (BulletManager::iterator i = bullet_manager_.begin(); !bullet_manager_.empty() && i != iend;)
	{
		collision = false;

		bullet = (*i);
		spr_bullet = (BulletNode*)bullet->node_;
		if (!spr_bullet)
		{
			i++;
			continue;
		}
		pt_bullet = toNetPoint(spr_bullet->getPosition());
		int bird_id = spr_bullet->getBirdId();
		int lock_bird_id = bullet->lock_bird_id_;
		bool searchLockBird = false;
		for (BirdManagerIter j = bird_manager_.begin(); j != jend; ++j)
		{
			bird = j->second;
			RoleNode * role_node = role_layer_->get_role(bullet->chair_id_);
			if (bird->live_ == 0)
				continue;

			spr_bird = (BirdNode*)bird->node_;
			pt_bird = toNetPoint(spr_bird->getPosition());
			if (SimpleTools::isDntgSpecialRoundBird(bird->type_))
			{
				int special_id = bird->type_ - BIRD_TYPE_ONE;
				sz_bird = GameConfig::getInstance().get_special_bird_size(special_id);
			}
			else if (SimpleTools::isDntgSpecialBird(bird->type_))
				sz_bird = GameConfig::getInstance().get_bird_size(bird->item_);
			else
				sz_bird = GameConfig::getInstance().get_bird_size(bird->type_);

			rotation_bird = toNetRotation(spr_bird->getRotation());

			// 不是锁定的状态,没有锁定的鱼puwu 击中
			if (lock_bird_id == -1 && compute_collision(pt_bird.x_, pt_bird.y_, 
														sz_bird.width_, sz_bird.height_,rotation_bird, 
														pt_bullet.x_, pt_bullet.y_, bullet_radius))
			{

				collision = true;



				
					//dynamic_cast<SpecialBirdNode *>(spr_bird)->SetBitStatus();
				
					SpecialBirdNode * waitBirdNode = (SpecialBirdNode*)spr_bird;
					waitBirdNode->SetBitStatus();

				





			//	Bullet *		bullet;
				//BirdNode *		spr_bird;


				if (netType >= 15)		spr_bullet->setNetType(3);
				else if (netType >= 5)	spr_bullet->setNetType(2);	
				else
				{
					spr_bullet->setNetType(1);		
				}
				break;
			}

			//
			if (lock_bird_id != -1 && bird_id == bird->id_)
			{
				searchLockBird = true;
				if (compute_collision(pt_bird.x_, pt_bird.y_, 
									  sz_bird.width_, sz_bird.height_,rotation_bird, 
									  pt_bullet.x_, pt_bullet.y_, bullet_radius))
				{
					collision = true;
					SpecialBirdNode * waitBirdNode = (SpecialBirdNode*)spr_bird;
					waitBirdNode->SetBitStatus();
					

					if (netType >= 15)		spr_bullet->setNetType(3);
					else if (netType >= 5)	spr_bullet->setNetType(2);
					else
					{
						spr_bullet->setNetType(1);
					}
					break;
				}
			}


		}
		// 锁定的鱼的id不为空,但是鱼已经消失
		if (lock_bird_id != -1 && !searchLockBird)
		{
			bullet->lock_bird_id_ = -1;
		}

		if (collision)
		{
			open_net(bullet);
			i = bullet_manager_.erase(i);
		}
		else
		{
			++i;
		}
	}
}

/************************************************************************/
/* 现在始终锁定最大鱼                                                   */
/************************************************************************/
bool CGameSceneEngine::collision_pos_bird(cocos2d::Vec2 touch_pos)
{
	Bird *		bird;
	BirdNode *	spr_bird = nullptr;
	//最大类型的鱼
	BirdNode *	maxTypeBird = nullptr;
	xPoint	pt_bird;
	xPoint	pt_bullet;
	xSize	sz_bird;

	float rotation_bird;
	float bullet_radius = GameConfig::getInstance().get_bullet_radius();


	//获取炮台锁定的鱼
	int chair_id = IClientKernel::get()->GetMeChairID();
	RoleNode * node = role_layer_->get_role(chair_id);

	BirdManagerIter jend = bird_manager_.end();

	pt_bullet = toNetPoint(touch_pos);

	for (BirdManagerIter j = bird_manager_.begin(); j != jend; ++j)
	{
		bird = j->second;

		if (bird->live_ == 0)
			continue;

		spr_bird = (BirdNode*)bird->node_;
		pt_bird = toNetPoint(spr_bird->getPosition());
		if (SimpleTools::isDntgSpecialRoundBird(bird->type_))
		{
			int special_id = bird->type_ - BIRD_TYPE_ONE;
			sz_bird = GameConfig::getInstance().get_special_bird_size(special_id);
		}
		else if (SimpleTools::isDntgSpecialBird(bird->type_))
			sz_bird = GameConfig::getInstance().get_bird_size(bird->item_);
		else
			sz_bird = GameConfig::getInstance().get_bird_size(bird->type_);
		rotation_bird = toNetRotation(spr_bird->getRotation());

		if (compute_collision(pt_bird.x_, pt_bird.y_, 
							  sz_bird.width_, sz_bird.height_,
							  rotation_bird, 
							  pt_bullet.x_, pt_bullet.y_, 
							  bullet_radius))
		{
			

			SpecialBirdNode * waitBirdNode = (SpecialBirdNode*)spr_bird;
			waitBirdNode->SetBitStatus();

			if (spr_bird == node->getLockBird())
				return false;

			if (maxTypeBird == nullptr)
			{
				maxTypeBird = spr_bird;
				continue;
			}
			else
			{
				///< 鱼类型大!替换
				if (spr_bird->bird->type_ > maxTypeBird->bird->type_)
					maxTypeBird = spr_bird;
			}
		}
	}

	if (maxTypeBird)
	{
		// 锁定鱼
		maxTypeBird->setLock(true, chair_id);

		if (node->getLockBird() != nullptr)
		{
			node->getLockBird()->setLock(false, chair_id);
		}

		node->setLockBird(maxTypeBird);

		return true;
	}

	return false;
}

/************************************************************************/
/*                                                                      */
/************************************************************************/
bool CGameSceneEngine::collision_pos_bird()
{
	// 最大类型的鱼

	Bird *		bird;
	BirdNode *	spr_bird = nullptr;
	BirdNode *	maxTypeBird = nullptr;

	xPoint	pt_bird;
	xSize	sz_bird;

	float bullet_radius = GameConfig::getInstance().get_bullet_radius();

	//获取炮台锁定的鱼
	int chair_id = IClientKernel::get()->GetMeChairID();
	RoleNode * node = role_layer_->get_role(chair_id);

	BirdManagerIter jend = bird_manager_.end();

	for (BirdManagerIter j = bird_manager_.begin(); j != jend; ++j)
	{
		bird = j->second;

		if (bird->live_ == 0)
			continue;

		if (bird->type_ < 15 || SimpleTools::isDntgSpecialBird(bird->type_))
			continue;

		spr_bird = (BirdNode*)bird->node_;
		if (spr_bird->isOutWindow())
			continue;

		pt_bird = toNetPoint(spr_bird->getPosition());

		if (spr_bird == node->getLockBird())
			return false;

		if (maxTypeBird == nullptr)
		{
			maxTypeBird = spr_bird;
			break;
		}
	}

	if (maxTypeBird)
	{
		//锁定鱼
		maxTypeBird->setLock(true, chair_id);

		if (node->getLockBird() != nullptr)
		{
			node->getLockBird()->setLock(false, chair_id);
		}

		node->setLockBird(maxTypeBird);
		return true;
	}

	return false;
}

void CGameSceneEngine::collision_change_bird()
{
	Bird *		bird;
	BirdNode *	spr_bird = nullptr;
	BirdNode *	maxTypeBird = nullptr;

	xPoint	pt_bird;
	xSize	sz_bird;

	float bullet_radius = GameConfig::getInstance().get_bullet_radius();

	//获取炮台锁定的鱼
	int chair_id = IClientKernel::get()->GetMeChairID();
	RoleNode * node = role_layer_->get_role(chair_id);
	//maxTypeBird = node->getLockBird();
		
	BirdManagerIter jend = bird_manager_.end();

	for (BirdManagerIter j = bird_manager_.begin(); j != jend; ++j)
	{
		bird = j->second;

		if (bird->live_ == 0)
			continue;

		if (bird->type_ < 15 )
			continue;

		spr_bird = (BirdNode*)bird->node_;
		if (spr_bird->isOutWindow())
			continue;
		//锁定过的鱼
		if (isHistoryLockBird(bird->id_)) continue;

		pt_bird = toNetPoint(spr_bird->getPosition());
		
	    maxTypeBird = spr_bird;

		//锁定鱼
		maxTypeBird->setLock(true, chair_id);

		if (node->getLockBird() != nullptr)
		{
			node->getLockBird()->setLock(false, chair_id);
		}

		//添加锁定鱼
	    bird_Lockanager_.insert(BirdManager::value_type(bird->id_, bird));
		node->setLockBird(maxTypeBird);
		return;
	}

}

bool CGameSceneEngine::isHistoryLockBird(int FishId)
{
	Bird *		bird;
	BirdManagerIter jend = bird_Lockanager_.end();
	for (BirdManagerIter j = bird_Lockanager_.begin(); j != jend; ++j)
	{
		bird = j->second;
		if (bird->id_ == FishId) return true;
	}
  return false;
}


/************************************************************************/
/* 计算碰撞                                                             */
/************************************************************************/
bool CGameSceneEngine::compute_collision(float bird_x, float bird_y, 
										float bird_width, float bird_height, float bird_rotation,
										float bullet_x, float bullet_y, float bullet_radius)
{
	float sint, cost;
	float w, h, rx, ry, r;

	cost = std::cos(bird_rotation);
	sint = std::sin(bird_rotation);

	w = bird_width;
	h = bird_height;
	r = bullet_radius;
	rx = (bullet_x - bird_x) * cost + (bullet_y - bird_y) * sint;
	ry = -(bullet_x - bird_x) * sint + (bullet_y - bird_y) * cost;

	float dx = tmin(rx, w*0.5f);
	dx = tmax(dx, -w*0.5f);

	float dy = tmin(ry, h*0.5f);
	dy = tmax(dy, -h*0.5f);

	return (rx - dx)*(rx - dx) + (ry - dy)*(ry - dy) <= r*r;
}

/************************************************************************/
/*                                                                      */
/************************************************************************/
int CGameSceneEngine::bullet_index_factroy()
{
	static int local_index_ = 0;
	local_index_++;

	if (local_index_ < MAX_BULLET_IN_MANAGER)
		local_index_ = MAX_BULLET_IN_MANAGER;

	return local_index_;
}

/************************************************************************/
/* 打开鱼网                                                             */
/************************************************************************/
void CGameSceneEngine::open_net(Bullet *bullet)
{
	BulletNode* node			= (BulletNode*)bullet->node_;
	BulletNode* node_shadow_	= (BulletNode*)bullet->shadow_;

	net_layer_->net_open(node->getChairID(), node->getNetType(), node->getPosition());

	IClientKernel* kernel = IClientKernel::get();
	if (!kernel) 
		return;

	if (bullet->chair_id_ == kernel->GetMeChairID())
		ObjectPool::shared()->bulletCountSub();

	ObjectPool::shared()->destoryBullet(bullet);
	ObjectPool::shared()->destoryBulletNode(node_shadow_);
	ObjectPool::shared()->destoryBulletNode(node);
}


/************************************************************************/
/* 设置自动开火                                                         */
/************************************************************************/
void CGameSceneEngine::autoFire()
{
	IClientKernel* kernel = IClientKernel::get();

	if (kernel == 0)
		return;

	if (get_status() >= GAME_BUY_PREPARE)
		return;

	if (role_layer_ == 0)
		return;

	int me_chair_id = kernel->GetMeChairID();

	RoleNode * role = role_layer_->get_role(me_chair_id);

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	HWND gWnd = 0;
	static POINT pt;
	GetCursorPos(&pt);
	POINT pt2;
	pt2.x = pt.x;
	pt2.y = pt.y;
	ScreenToClient(gWnd, &pt2);
#endif

	is_touch_fire_ = true;
	op_fire();
}



/************************************************************************/
/* 用户进入                                                             */
/************************************************************************/
void CGameSceneEngine::net_user_enter(int chair_id)
{
	IClientKernel* kernel = IClientKernel::get();
	RoleNode* role = role_layer_->get_role(chair_id);
	role->show(true,false);
	auto userName = kernel->GetTableUserItem(chair_id);
	if (userName)
		role->set_nickname((userName->GetNickName()));

	if (kernel->GetMeChairID() != chair_id)
	{
		role->set_net_state(gDntgTimestampManager.get_trad());
	}
	else
	{
		if (!mInitLocalScore)
		{
			mInitLocalScore = true;
			mLocalScore = kernel->GetTableUserItem(chair_id)->GetUserScore();
		}
	}
}

/************************************************************************/
/* 用户离开                                                             */
/************************************************************************/
void CGameSceneEngine::net_user_leave(int chair_id)
{
	RoleNode* role = role_layer_->get_role(chair_id);
	role->show(false,false);
}

/************************************************************************/
/* 用户分数                                                             */
/************************************************************************/
void CGameSceneEngine::net_user_score(int chair_id)
{
	IClientKernel* kernel = IClientKernel::get();
	if (chair_id == kernel->GetMeChairID())
	{
		const tagUserInfo *pUserData = kernel->GetMeUserItem()->GetUserInfo();
	}
}

/************************************************************************/
/* 场景消息                                                             */
/************************************************************************/
void CGameSceneEngine::on_scene_message(byte cbGameStatus, bool bLookonUser, void* data, int dataSize)
{
	CMD_S_StatusFree * status_free = (CMD_S_StatusFree *)data;

	IClientKernel* kernel = IClientKernel::get();

	scene_layer_->set_scene(status_free->scene_);
	GameConfig::getInstance().init(status_free);

	if (frame_layer_){
		frame_layer_->SetGameID(status_free->wServerID);
	}



	RoleNode* role = role_layer_->get_role(kernel->GetMeChairID());
	if(role){
		role->fire(true,false);
		role->show(true,true);	
	}

	for (int i = 0; i < GAME_PLAYER; i++)
	{
		uint16 chair_id = status_free->role_objects_[i].chair_id_;

		if (chair_id != INVALID_CHAIR)
		{
			RoleNode* role = role_layer_->get_role(chair_id);
			net_user_enter(chair_id);
			role->set_gold(status_free->role_objects_[i].catch_gold_);
			role->set_cannon(status_free->role_objects_[i].cannon_type_);
			exchange_count = status_free->exchange_count_;
			double ratio_birdscore_ = status_free->ex_ratio_birdscore_;
			double ratio_userscore_ = status_free->ex_ratio_userscore_;
			cash_ratio = ratio_birdscore_ / ratio_userscore_;
			int cannon_type = role->get_cannon() / (GameConfig::getInstance().get_mulriple_count() / BULLET_KIND_COUNT);
			//子弹速度
			role->set_cannon_speed(GameConfig::getInstance().get_bullet_config(cannon_type).speed);
		}
	}

	const tagUserInfo *pUserData = kernel->GetMeUserItem()->GetUserInfo();
	if (pUserData){

		m_pGameScene->schedule(schedule_selector(CGameSceneEngine::func_send_time_check), 3);
	}	

	m_pGameScene->scheduleUpdate();


	char sSound[16] = { 0 };
    int tmp_scene = 0;
    if (scene_layer_->get_scene() == 0) {
        tmp_scene=1;
    }else
    {
        tmp_scene = scene_layer_->get_scene();
    }
	sprintf(sSound, "scene%d", tmp_scene);
    
    SoundManager::shared()->setMusicVolume(50);
    SoundManager::shared()->playMusic(sSound);
    

    
	SCORE fishCashNum = pUserData->lScore *cash_ratio;
	this->op_buy_bullet(fishCashNum);

}


// 管理员控制
void CGameSceneEngine::net_buy_Admin_Room(void* data, int dataSize)
{


	//for (int index = 0; index<count; index++)
	//{
	//

	//	HallDataMgr::getInstance()->m_roomList.push_back(pServer);
	//	std::sort(HallDataMgr::getInstance()->m_roomList.begin(), HallDataMgr::getInstance()->m_roomList.end(), [](const tagGameServer *s1, const tagGameServer *s2){
	//		return s1->wSortID < s2->wSortID;
	//	});
	//}



	int size = sizeof(tagListoffishing);
	int count = dataSize / size;
	CMD_GR_FishingServer *pRoomList = (CMD_GR_FishingServer*)data;
	for (int i = 0; i < pRoomList->cbColumnCount; i++)
	{

		//tagListoffishing *pServer = new tagListoffishing();
		//memset(pServer, 0, sizeof(tagListoffishing));
		//char *pVector = (char *)data + i*size;
		//memcpy(pServer, pVector, size);

		int  dwGameServer = pRoomList->Listoffishing[i].wServerID;


		if (frame_layer_){
			frame_layer_->OnGameRoomInfo(dwGameServer, u2_8(pRoomList->Listoffishing[i].szServerName));
		}
	}
}
// 房间收益列表
void CGameSceneEngine::net_buy_Admin_UserInfo(void* data, int dataSize)
{

	CMD_GR_FishingServerInfo *pRoomList = (CMD_GR_FishingServerInfo*)data;
	if (frame_layer_){
		frame_layer_->OnReleaseInfo();
	}

	for (int i = 0; i < pRoomList->cbColumnCount; i++)
	{
		frame_layer_->InserUserInfo(i, pRoomList->FishServerInfo[i]);
	}
	
}



// 名单表
void CGameSceneEngine::net_buy_Admin_MingList(void* data, int dataSize)
{

	CMD_S_Kongzhi *pRoomList = (CMD_S_Kongzhi*)data;
    if (pRoomList->Counent < frame_layer_->getDelBeforeCount())
    {
        printf("%d\n",(int)pRoomList->Counent);
        printf("%d",frame_layer_->getDelBeforeCount());
        //是删除操作
        frame_layer_->OnReleaseOneItem();
        return;
    }
    
	if (frame_layer_){
		frame_layer_->OnReleaseMingdan();
	}

	for (int i = 0; i < pRoomList->Counent; i++)
	{
		frame_layer_->InserMingDan(i, pRoomList->Kongzhi[i]);
	}

}


/************************************************************************/
/* 购买子弹成功                                                         */
/************************************************************************/
void CGameSceneEngine::net_buy_bullet_success(int chair_id, uint64 count)
{
	IClientKernel* kernel = IClientKernel::get();

	if (chair_id == kernel->GetMeChairID())
		set_status(GAME_LOGIC);
	if (role_layer_)
		role_layer_->add_gold(chair_id, count);

	mLocalScore -= count / cash_ratio;
	//SoundManager::shared()->playSound("exchange_gold");

	

	RoleNode* role = role_layer_->get_role(chair_id);
	if (role){
		role->fire(true, false);
		role->set_gold(count);
	}


}

// 我想操作机器人
void CGameSceneEngine::net_buy_jiqirmomoda(CMD_S_FishAndisNick *FishAndir)
{
	IClientKernel* kernel = IClientKernel::get();

	if (FishAndir->szChairID != kernel->GetMeChairID())
	{
		RoleNode* role = role_layer_->get_role(FishAndir->szChairID);
		role->show(true, true);
		/*auto userName = kernel->GetTableUserItem(FishAndir->szChairID);
		if (userName)*/


		role->set_nickname(u2_8(FishAndir->szNickName));

		if (kernel->GetMeChairID() != FishAndir->szChairID)
		{
			role->set_net_state(gDntgTimestampManager.get_trad());
		}


	}
		
}


/************************************************************************/
/* 购买子弹失败                                                         */
/************************************************************************/
void CGameSceneEngine::net_buy_bullet_failed(int chair_id)
{
	IClientKernel* kernel = IClientKernel::get();

	if (chair_id == kernel->GetMeChairID())
		set_status(GAME_LOGIC);
}

/************************************************************************/
/* 开火失败                                                             */
/************************************************************************/
void CGameSceneEngine::net_fire_failed(CMD_S_Fire_Failed *pFireFailed)
{

}

/************************************************************************/
/* 改变炮弹                                                             */
/************************************************************************/
bool CGameSceneEngine::net_change_cannon(void* data, int dataSize)
{
	if (dataSize != sizeof(CMD_S_Change_Cannon))
		return false;

	CMD_S_Change_Cannon * change_cannon = (CMD_S_Change_Cannon *)data;

	IClientKernel* kernel = IClientKernel::get();

	if (change_cannon->chair_id_ != kernel->GetMeChairID())
	{
		if (change_cannon->cannon_type_ > role_layer_->get_role(change_cannon->chair_id_)->get_cannon())
			SoundManager::shared()->playSound("cannon_add");
		else
			SoundManager::shared()->playSound("cannon_sub");

		role_layer_->set_cannon(change_cannon->chair_id_, change_cannon->cannon_type_);
		role_layer_->set_level(change_cannon->chair_id_, change_cannon->level_);
	}

	return true;
}

/************************************************************************/
/* 子弹生成                                                             */
/************************************************************************/
void CGameSceneEngine::net_send_bullet(CMD_S_Send_Bullet* send_bullet)
{
	if (is_game_pause_)
		return;

	IClientKernel* kernel = IClientKernel::get();

	if (send_bullet->chair_id_ == kernel->GetMeChairID())
		return;

	RoleNode* role = role_layer_->get_role(send_bullet->chair_id_);

	Bullet *bullet = ObjectPool::shared()->createBullet();
	bullet->id_				= send_bullet->id_;
	bullet->chair_id_		= send_bullet->chair_id_;
	bullet->cannon_type_	= send_bullet->cannon_type_;
	bullet->rotation_		= send_bullet->rotation_;
	bullet->speed_			= send_bullet->speed_;
	bullet->lock_bird_id_	= send_bullet->lock_bird_id_;
	bullet->bullet_type_	= role->get_bullet_index_by(role->get_level());
	bullet->net_type_		= role->get_net_index_by(role->get_level());

	int trad = gDntgTimestampManager.get_time_difference(send_bullet->time_);

	//炮台类型
	int cannon_type = 0;
	GameConfig::getInstance().get_bullet_config(bullet->speed_, cannon_type);

	if (bullet->chair_id_ != kernel->GetMeChairID())
	{
		bullet_manager_.push_back(bullet);
		bullet_layer_->send_bullet(bullet, toCCP(send_bullet->position_*0.9f), trad);
	}
	//log("server angle is %f", bullet->rotation_);
	if (send_bullet->scened_ == 0)
	{
		if (bullet->chair_id_ != kernel->GetMeChairID())
		{
			role_layer_->bullet_send(bullet->chair_id_, send_bullet->bullet_mulriple, bullet->rotation_, trad);
		}
	}
}

/************************************************************************/
/* 鱼生成                                                               */
/************************************************************************/
void CGameSceneEngine::net_send_bird(CMD_S_Send_Bird* send_bird)
{
//    CMD_S_Send_Bird* data;
//    data = (struct CMD_S_Send_Bird*)malloc(sizeof(struct CMD_S_Send_Bird));
//    memset(data, 0, sizeof(struct CMD_S_Send_Bird));
//    memcpy(data, &send_bird, sizeof(CMD_S_Send_Bird));
	if (is_game_pause_)
		return;
	BirdManagerIter i = bird_manager_.find(send_bird->id_);

	if (i != bird_manager_.end())
	{
		PLAZZ_PRINTF("bird is in mananger");
		return;
	}

	int trad = gDntgTimestampManager.get_time_difference(send_bird->time_);

	Bird *bird = ObjectPool::shared()->createBird();
	bird->id_			= send_bird->id_;
	bird->type_			= send_bird->type_;
	bird->item_			= send_bird->item_; ///< 特效
	bird->path_id_		= send_bird->path_id_;
	bird->path_type_	= send_bird->path_type_;
	bird->path_delay_	= send_bird->path_delay_;
	bird->path_offset_	= send_bird->path_offset_;
	bird->elapsed_		= send_bird->elapsed_ + (float)(trad) / 1000.0f;
	bird->speed_		= send_bird->speed_;

	if (SimpleTools::isDntgNeedGoStraightBird(bird->type_))
	{
		bird->rotation_ = 0.0f;
	}

	bird_manager_.insert(BirdManager::value_type(bird->id_, bird));
	bird_layer_->send_bird(bird);
}

/************************************************************************/
/* 特殊鱼阵生成                                                         */
/************************************************************************/
void CGameSceneEngine::net_send_bird_linear(CMD_S_Send_Bird_Linear* send_bird)
{
	if (is_game_pause_)
		return;

	BirdManagerIter i = bird_manager_.find(send_bird->id_);
	if (i != bird_manager_.end())
	{
		PLAZZ_PRINTF("bird is in mananger");
		return;
	}

	int trad = gDntgTimestampManager.get_time_difference(send_bird->time_);
	Action_Bird_Move* action = NULL;

	Bird* bird = ObjectPool::shared()->createBird();
	bird->id_			= send_bird->id_;
	bird->item_			= send_bird->item_;
	bird->type_			= send_bird->type_;
	bird->position_		= send_bird->start_;
	bird->path_delay_	= send_bird->path_delay_;
	bird->elapsed_		= send_bird->elapsed_ + (float)(trad) / 1000.0f;
	action = Action_Bird_Move_Linear::create(send_bird->speed_, send_bird->start_, send_bird->end_);
	bird_manager_.insert(BirdManager::value_type(bird->id_, bird));
	bird_layer_->send_scene_bird(bird, action);
}

/************************************************************************/
/* 特殊鱼阵生成                                                         */
/************************************************************************/
void CGameSceneEngine::net_send_bird_round(CMD_S_Send_Bird_Round* send_bird)
{
	if (is_game_pause_)
		return;

	BirdManagerIter i = bird_manager_.find(send_bird->id_);
	if (i != bird_manager_.end())
	{
		PLAZZ_PRINTF("bird is in manager");
		return;
	}

	int trad = gDntgTimestampManager.get_time_difference(send_bird->time_);
	Action_Bird_Move* action = NULL;
	Bird* bird = ObjectPool::shared()->createBird();

	bird->id_			= send_bird->id_;
	bird->item_			= send_bird->item_;
	bird->type_			= send_bird->type_;
	bird->elapsed_		= send_bird->elapsed_ + (float)(trad) / 1000.0f;
	bird->path_delay_	= send_bird->path_delay_;
	//bird->is_red_ = false;

	action = Action_Bird_Round_Move::create(send_bird->center_, send_bird->radius_, send_bird->rotate_duration_, 
											send_bird->start_angle_, send_bird->rotate_angle_, send_bird->move_duration_, 
											send_bird->speed_, send_bird->radius_ == 0 ? true : false);

	bird_manager_.insert(BirdManager::value_type(bird->id_, bird));
	bird_layer_->send_scene_bird(bird, action);

	return;
}

/************************************************************************/
/* 特殊鱼阵生成                                                         */
/************************************************************************/
void CGameSceneEngine::net_send_bird_pause_linear(CMD_S_Send_Bird_Pause_Linear* send_bird)
{
	if (is_game_pause_)
		return;

	BirdManagerIter i = bird_manager_.find(send_bird->id_);
	if (i != bird_manager_.end())
	{
		PLAZZ_PRINTF("bird is in manager");
		return;
	}

	int tard = gDntgTimestampManager.get_time_difference(send_bird->time_);
	Action_Bird_Move* action = NULL;
	Bird* bird = ObjectPool::shared()->createBird();
	bird->id_			= send_bird->id_;
	bird->item_			= send_bird->item_;
	bird->type_			= send_bird->type_;
	bird->elapsed_		= send_bird->elapsed_ + (float)tard / 1000.0f;
	bird->path_delay_	= send_bird->path_delay_;

	action = Action_Bird_Move_Pause_Linear::create(send_bird->speed_, send_bird->pause_time_, send_bird->start_, 
												   send_bird->pause_, send_bird->end_, send_bird->start_angle_);
	bird_manager_.insert(BirdManager::value_type(bird->id_, bird));
	bird_layer_->send_scene_bird(bird, action);
	return;
}

/************************************************************************/
/* 圆阵                                                                 */
/************************************************************************/
void CGameSceneEngine::net_send_scene_round()
{
	if (is_game_pause_)
		return;

	const float kBirdSpeed = 150.f;
	int bird_id = 0;
	Action_Bird_Move* action = NULL;
	const xPoint center(kGameRevolutionWidth / 2.f, kGameRevolutionHeight / 2.f);
	double radius;
	double cell_radian;
	double angle;
	Bird *bird = NULL;

	xPoint pt(center.x_, center.y_);
	action = Action_Bird_Round_Move::create(center, 0.0f, 28.f, 0.0f, (float)(4 * M_PI + M_PI_2), 5.f, kBirdSpeed, true);
	bird = ObjectPool::shared()->createBird();
	bird->id_ = bird_id;
	bird->position_ = pt;
	bird->item_ = (rand() % (BIRD_ITEM_SPECIAL_BOMB_3)+1);
	bird->type_ = BIRD_TYPE_18;
	bird_manager_.insert(BirdManager::value_type(bird->id_, bird));
	bird_layer_->send_scene_bird(bird, action);
	++bird_id;

	radius = 150.f;
	cell_radian = 2 * M_PI / 10;
	for (int i = 0; i < 10; i++)
	{
		angle = i * cell_radian;
		action = Action_Bird_Round_Move::create(center, (float)radius, 27.f, (float)angle, (float)(4 * M_PI), 5.f, kBirdSpeed);
		bird = ObjectPool::shared()->createBird();
		bird->id_ = bird_id + i;
		bird->item_ = -1;
		bird->type_ = BIRD_TYPE_4;

		pt.x_ = center.x_ + radius * std::cos(4 * M_PI);
		pt.y_ = center.y_ + radius * std::sin(4 * M_PI);
		bird_manager_.insert(BirdManager::value_type(bird->id_, bird));
		bird_layer_->send_scene_bird(bird, action);
	}
	bird_id += 10;

	radius = 150.f + 52.f;//+ 42.f;
	cell_radian = 2 * M_PI / 18;
	for (int i = 0; i < 18; i++)
	{
		angle = i * cell_radian;
		action = Action_Bird_Round_Move::create(center, (float)radius, 26.f, (float)angle, (float)(4 * M_PI), 5.f, kBirdSpeed);
		bird = ObjectPool::shared()->createBird();
		bird->id_ = bird_id + i;
		bird->item_ = -1;
		bird->type_ = BIRD_TYPE_3;
		bird_manager_.insert(BirdManager::value_type(bird->id_, bird));
		bird_layer_->send_scene_bird(bird, action);
	}
	bird_id += 18;

	radius = 150.f /*+ 52.f*/ + 42.f * 2 + 30;
	cell_radian = 2 * M_PI / 30;
	for (int i = 0; i < 30; i++)
	{
		angle = i * cell_radian;
		action = Action_Bird_Round_Move::create(center, (float)radius, 25.f, (float)angle, (float)(4 * M_PI/* * 2*/), 5.f, kBirdSpeed);
		bird = ObjectPool::shared()->createBird();
		bird->id_ = bird_id + i;
		bird->item_ = -1;
		bird->type_ = BIRD_TYPE_2;
		bird_manager_.insert(BirdManager::value_type(bird->id_, bird));
		bird_layer_->send_scene_bird(bird, action);
	}
	bird_id += 30;

	radius = 150.f + /*52.f*/ +42.f * 2 + 30 * 2 + 35;
	cell_radian = 2 * M_PI / 30;
	for (int i = 0; i < 30; i++)
	{
		angle = i * cell_radian;
		action = Action_Bird_Round_Move::create(center, (float)radius, 24.f, (float)angle, (float)(4 * M_PI/* * 3*/), 5.f, kBirdSpeed);
		bird = ObjectPool::shared()->createBird();
		bird->id_ = bird_id + i;
		bird->item_ = -1;
		bird->type_ = BIRD_TYPE_1;
		bird_manager_.insert(BirdManager::value_type(bird->id_, bird));
		bird_layer_->send_scene_bird(bird, action);
	}
	bird_id += 30;
}

/************************************************************************/
/* 一圈一圈鼓出的鱼                                                     */
/************************************************************************/
void CGameSceneEngine::net_send_scene_bloating()
{
	round_bird_linear* birds;
	int bird_id = 0;
	const int kBirdCount[10] = { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 };
	const xPoint center(kGameRevolutionWidth / 2.f, kGameRevolutionHeight / 2.f);
	for (int i = 0; i < 10; i++)
	{
		birds = new round_bird_linear;

		birds->bird_type	= BIRD_TYPE_4;
		birds->bird_count	= kBirdCount[i];
		birds->start_id		= bird_id;
		birds->pt_center	= center;

		m_pGameScene->runAction(CCSequence::create(CCDelayTime::create(1.0f * (i + 1)),
			CCCallFuncND::create(this, callfuncND_selector(CGameSceneEngine::round_linear), birds),
			nullptr));
		bird_id += kBirdCount[i];
	}
}

/************************************************************************/
/*                                                                      */
/************************************************************************/
void CGameSceneEngine::round_linear(cocos2d::Node* node, void* data)
{
	round_bird_linear* birds = (round_bird_linear*)data;

	Bird* bird;
	Action_Bird_Move* action = NULL;
	float cell_radian = 2 * M_PI / birds->bird_count;
	const float kRadius = 1800.f;
	xPoint pt;
	for (int i = 0; i < (int)birds->bird_count; i++)
	{
		bird = ObjectPool::shared()->createBird();
		bird->id_		= birds->start_id + i;
		bird->item_		= -1;
		bird->type_		= birds->bird_type;
		bird->position_ = birds->pt_center;
		pt.x_			= birds->pt_center.x_ + kRadius * std::cos(i * cell_radian);
		pt.y_			= birds->pt_center.y_ + kRadius * std::sin(i * cell_radian);
		action			= Action_Bird_Move_Linear::create(80, birds->pt_center, pt);

		bird_manager_.insert(BirdManager::value_type(bird->id_, bird));
		bird_layer_->send_scene_bird(bird, action);
	}

	delete birds;
}

/************************************************************************/
/* 通过鱼的ID得到鱼的类型                                               */
/************************************************************************/
int  CGameSceneEngine::getBirdTypeByBirdId(int bird_id)
{
	BirdManagerIter i = bird_manager_.find(bird_id);

	if (i == bird_manager_.end())
	{
		PLAZZ_PRINTF("bird is not in mananger");
		return -1;
	}

	Bird *bird = i->second;

	return (int)bird->type_;
}
/************************************************************************/
/* 鱼死亡                                                               */
/************************************************************************/
void CGameSceneEngine::net_bird_dead(CMD_S_Special_Catch_Bird* catch_bird)
{
	if (is_game_pause_)
		return;

	//uint32 bird_id		= catch_bird->bird_id_;
	uint16 chair_id_	= catch_bird->chair_id_;
	uint16 cannon_type_ = catch_bird->cannon_type_;
	uint32 catch_gold	= catch_bird->catch_gold_;
	uint32 medal		= catch_bird->medal_;

	RoleNode* role = role_layer_->get_role(chair_id_);

	if (catch_gold != 0)
	{
		role->set_gold(role->get_gold() + catch_gold);
		float mult_type = GameConfig::getInstance().get_cannon_mulriple(cannon_type_) * 2;
		role->show_coin(catch_gold / mult_type, catch_gold,chair_id_);
	}

	BirdManagerIter i = bird_manager_.find(catch_bird->bird_id_);

	if (i == bird_manager_.end())
	{
		PLAZZ_PRINTF("bird is not in mananger");
		return;
	}

	Bird *bird = i->second;
	bird->live_ = 0;
	BirdNode* node = (BirdNode*)bird->node_;

	xPoint ptRole(CANNON_POSITION[chair_id_][0], CANNON_POSITION[chair_id_][1]);
	xPoint ptBird = toNetPoint(node->getPosition());

	coin_layer_->add_award(chair_id_, ptBird, catch_bird->award_type_, catch_bird->award_count_);

	if (medal != 0)
	{
		coin_layer_->add_award(chair_id_, ptBird, 1, medal);
	}

	IClientKernel* kernel = IClientKernel::get();

	if (catch_gold != 0)
	{
		if (!chair_id_ == kernel->GetMeChairID())
		{
			int x  = 100;
		}
		coin_layer_->coin_move(chair_id_, bird->type_, ptBird, ptRole);
		coin_layer_->coin_label(ptBird, (bird->type_ < 0 ? 1 : 2), catch_gold, chair_id_ == kernel->GetMeChairID());
	}

	SoundManager::shared()->playFishSound(bird->type_);

	if (bird->type_ >= 16 && bird->type_ <= 25 && !SimpleTools::isDntgSpecialBird(bird->type_))
	{
		xPoint pt(CANNON_POSITION[chair_id_][0], CANNON_POSITION[chair_id_][1]);
		if (chair_id_ < 3)
			pt.offset(0, 150);
		else
			pt.offset(0, -150);
		coin_layer_->big_fish_flash(pt, catch_gold);
	}

	if (bird->type_ >= 16 && bird->type_ <= 25)
	{
		switch (rand() % 8)
		{
		case 0:
			coin_layer_->ParSma_paly(ptBird, PARTICLE_SYCEE, 48);
			coin_layer_->Explosion_paly(ptBird, PARTICLE_LINE_GREEN, 16, 0, 1);
			coin_layer_->Explosion_paly(ptBird, PARTICLE_LINE_BLUE, 16, 0, 1);
			break;
		case 1:
			coin_layer_->Explosion_paly(ptBird, PARTICLE_CRYSTAL, 48, 0, 0);
			coin_layer_->Explosion_paly(ptBird, PARTICLE_LINE_GREEN, 16, 0, 1);
			coin_layer_->Explosion_paly(ptBird, PARTICLE_LINE_BLUE, 16, 0, 1);
			coin_layer_->effect_play(ptBird, 1, 0.5, 0, 2.5);
			break;
		case 2:
			coin_layer_->ParSma_paly(ptBird, PARTICLE_DIAMOND_RED, 12, 200);
			coin_layer_->ParSma_paly(ptBird, PARTICLE_DIAMOND_YELLOW, 12);
			coin_layer_->ParSma_paly(ptBird, PARTICLE_DIAMOND_GREEN, 12);
			coin_layer_->ParSma_paly(ptBird, PARTICLE_DIAMOND_ORANGE, 12);
			coin_layer_->Explosion_paly(ptBird, PARTICLE_LINE_GREEN, 16, 0, 1);
			coin_layer_->Explosion_paly(ptBird, PARTICLE_LINE_BLUE, 16, 0, 1);
			break;
		case 3:
			coin_layer_->ParSma_paly(ptBird, PARTICLE_DIAMOND_RED, 16, 200);
			coin_layer_->ParSma_paly(ptBird, PARTICLE_SYCEE, 16);
			coin_layer_->ParSma_paly(ptBird, PARTICLE_GOLD, 16);
			coin_layer_->Explosion_paly(ptBird, PARTICLE_LINE_GREEN, 16, 0, 1);
			coin_layer_->Explosion_paly(ptBird, PARTICLE_LINE_BLUE, 16, 0, 1);
			break;
		case 4:
			coin_layer_->effect_play(ptBird, 0, 0.5, 0, 2.5);
			break;
		case 5:
			coin_layer_->effect_play(ptBird, 1, 0.5, 0, 2.5);
			break;
		case 6:
			coin_layer_->effect_play(ptBird, 2, 0.5, 0, 2.5);
			break;
		case 7:
			auto * particleSystem = ParticleSystemQuad::create("particle/jinbi_baozha.plist");
			particleSystem->setPosition(node->getPositionX(), node->getPositionY());
			m_pGameScene->addChild(particleSystem);
			CCSequence* act = CCSequence::create(
				CCDelayTime::create(particleSystem->getLife() + 1.0f),
				CCCallFuncND::create(this, callfuncND_selector(CGameSceneEngine::func_bomb_effect_end), 0),
				0);
			particleSystem->runAction(act);
			break;
		}
	}
	if (bird->type_ >= 26)
	{
		switch ( bird->type_ )
		{
		case 26:
			coin_layer_->Ding_paly(ptBird, 5, PARTICLE_DING);
			coin_layer_->Particle_paly(ptBird, 3, PARTICLE_STICK);
			coin_layer_->effect_play(ptBird, 3, 3);
			coin_layer_->effect_play(ptBird, 4, 4, 3);
			break;
		case 27:
			coin_layer_->Particle_paly(ptBird, 6, PARTICLE_RING);
			coin_layer_->effect_play(ptBird, 7, 6);
			coin_layer_->effect_play(ptBird, 8, 4, 6);
			break;
		case 28:
			coin_layer_->Particle_paly(ptBird, 5, PARTICLE_TOWER);
			coin_layer_->effect_play(ptBird, 5, 5);
			coin_layer_->effect_play(ptBird, 6, 4, 5);
			break;
		case 29:
			coin_layer_->Particle_paly(ptBird, 0, PARTICLE_PALM);
			break;
		default:
			break;
		}
	}

	// 高分鱼震屏特效
	if (bird->type_ >= 16 || SimpleTools::isDntgSpecialBird(bird->type_))
	{
		this->stop_shake_screen();
		this->start_shake_screen(6);
	}

	// 计算死去的鱼,最后做界面显示,总结算需要!!
	if (IClientKernel::get()->GetMeChairID() == chair_id_)
	{
		SingleGameTotalGold += catch_gold;
		bird_deal_count_manager_[bird->type_] = bird_deal_count_manager_[bird->type_] + 1;
	}

	///< 检测是否是四海龙王
	if (SimpleTools::isDntgDragonKing(bird->type_))
	{
		role->showDeadDragonKingSmallHead(bird->type_);
	}

	bird_layer_->bird_dead(bird);
	destoryBird(bird);
}

/************************************************************************/
/* 抓住鱼,可以计算所有的特殊效果,计算红鱼                               */
/************************************************************************/
void CGameSceneEngine::net_bird_group_dead(CMD_S_Catch_Bird_Group* catch_group, int thread_id, bool isEndWave)
{
	if (is_game_pause_)
		return;

	uint16 chair_id_	= catch_group->chair_id_;
	uint16 cannon_type_ = catch_group->cannon_type_;
	int count = catch_group->count_;
	int bomb_price = 0;
	bool has_bomb = false;

	for (int i = 0; i < count; i++)
	{
		Catch_Bird & catch_bird = catch_group->catch_bird_[i];
		BirdManagerIter j = bird_manager_.find(catch_bird.bird_id_);

		if (j == bird_manager_.end())
		{
			PLAZZ_PRINTF("bird is not in mananger");
			continue;
		}

		Bird *bird = j->second;
		BirdNode * node = (BirdNode *)(bird->node_);
		Vec2 bird_pos = node->getPosition();
		if (SimpleTools::isDntgSpecialBird(bird->type_))
		{
			//红鱼效果 闪电鱼效果
			sendSavaList[thread_id].startList[bird->id_] = bird_pos;
			sendSavaList[thread_id].type_value[bird->id_] = bird->type_;
			sendSavaList[thread_id].total_price += catch_bird.catch_gold_;

		}

		if (catch_bird.link_bird_id_ != BIRD_TYPE_NULL)
		{
			bird->link_bird_id_ = catch_bird.link_bird_id_;
			sendSavaList[thread_id].otherList[catch_bird.link_bird_id_].push_back(bird_pos);
			sendSavaList[thread_id].total_price += catch_bird.catch_gold_;
			//log("thread id is %d, otheryu money is %d",thread_id, catch_bird.catch_gold_);
		}

		if (bird->item_ != -1 && !SimpleTools::isDntgSpecialBird(bird->type_))
		{
			switch (bird->item_)
			{
				// 钱袋不给金币
			case BIRD_ITEM_SPECIAL_SMALL_PURSE:
			case BIRD_ITEM_SPECIAL_MIDDLE_PURSE:
			case BIRD_ITEM_SPECIAL_BIG_PURSE:
				break;
			case BIRD_ITEM_SPECIAL_BOMB_1:
			case BIRD_ITEM_SPECIAL_BOMB_2:
			case BIRD_ITEM_SPECIAL_BOMB_3:
				has_bomb = true;
			default:
				bomb_price += catch_bird.catch_gold_;
				break;
			}
		}
	}


	if (isEndWave)
	{
		if (!sendSavaList[thread_id].startList.empty())
		{
			//
			if (sendSavaList[thread_id].total_price != 0)
			{
				xPoint pt(CANNON_POSITION[chair_id_][0], CANNON_POSITION[chair_id_][1]);

				if (chair_id_ < 3)
					pt.offset(0, 150);
				else
					pt.offset(0, -150);
				coin_layer_->big_fish_flash(pt, sendSavaList[thread_id].total_price);
			}
		
			for (auto it : sendSavaList[thread_id].startList)
			{

				int bird_id = it.first;
				Vec2 start_p = it.second;
				int value = sendSavaList[thread_id].type_value[bird_id];
				auto find_vale = sendSavaList[thread_id].otherList.find(bird_id);
				if (find_vale != sendSavaList[thread_id].otherList.end())
				{
					std::vector<Vec2> other_list = sendSavaList[thread_id].otherList[bird_id];

					bird_layer_->showLightLineConnection(start_p, other_list, value);

					///< 清理该内存,每次清理前一个
					if (pre_thread_id != -1)
					{
						sendSavaList[pre_thread_id].startList.clear();
						sendSavaList[pre_thread_id].otherList.clear();
						sendSavaList[pre_thread_id].type_value.clear();
						pre_thread_id = thread_id;
					}
					else
						pre_thread_id = thread_id;
				}
				else
				{
					
				}
			}
		}
	}
}

/************************************************************************/
/* 计算闪电鱼                                                           */
/************************************************************************/
void CGameSceneEngine::net_bird_group_dead(CMD_S_Catch_Bird_Chain* catch_group, int thread_id, bool isEndWave)
{
	if (is_game_pause_)
		return;

	uint16 chair_id_	= catch_group->chair_id_;
	uint16 cannon_type_ = catch_group->cannon_type_;
	int count			= catch_group->count_;
	int bomb_price		= 0;
	bool has_bomb		= false;

	for (int i = 0; i < count; i++)
	{
		Catch_Bird& catch_bird = catch_group->catch_bird_[i];
		BirdManagerIter j = bird_manager_.find(catch_bird.bird_id_);

		if (j == bird_manager_.end())
		{
			PLAZZ_PRINTF("bird is not in mananger");
			continue;
		}

		Bird *bird = j->second;
		BirdNode * node = (BirdNode *)(bird->node_);
		Vec2 bird_pos = node->getPosition();
		if (SimpleTools::isDntgSpecialBird(bird->type_))
		{
			///< 红鱼效果///< 闪电鱼效果
			sendSavaList[thread_id].startList[bird->id_] = bird_pos;
			sendSavaList[thread_id].type_value[bird->id_] = bird->type_;
			sendSavaList[thread_id].total_price += catch_bird.catch_gold_;
			//log("thread_id is %d --- shandianyu money is %d",thread_id, catch_bird.catch_gold_);
		}

		if (catch_bird.link_bird_id_ != BIRD_TYPE_NULL)
		{
			bird->link_bird_id_ = catch_bird.link_bird_id_;
			sendSavaList[thread_id].otherList[catch_bird.link_bird_id_].push_back(bird_pos);
			sendSavaList[thread_id].total_price += catch_bird.catch_gold_;
			//log("thread_id is %d --- othershandianyu money is %d",thread_id, catch_bird.catch_gold_);
		}

		if (bird->item_ != -1 && !SimpleTools::isDntgSpecialBird(bird->type_))
		{
			switch (bird->item_)
			{
				// 钱袋不给金币
			case BIRD_ITEM_SPECIAL_SMALL_PURSE:
			case BIRD_ITEM_SPECIAL_MIDDLE_PURSE:
			case BIRD_ITEM_SPECIAL_BIG_PURSE:
				break;
			case BIRD_ITEM_SPECIAL_BOMB_1:
			case BIRD_ITEM_SPECIAL_BOMB_2:
			case BIRD_ITEM_SPECIAL_BOMB_3:
				has_bomb = true;
			default:
				bomb_price += catch_bird.catch_gold_;
				break;
			}
		}
	}

	if (bomb_price && has_bomb)
	{
		xPoint pt(CANNON_POSITION[chair_id_][0], CANNON_POSITION[chair_id_][1]);

		if (chair_id_ < 3)
			pt.offset(0, 150);
		else
			pt.offset(0, -150);

		coin_layer_->big_fish_flash(pt, bomb_price);
	}

	//下面这个是显示闪电效果 是最后一波的时候在发送数据
	if (isEndWave)
	{

		if (!sendSavaList[thread_id].startList.empty())
		{
			// 触发爆炸
			if (sendSavaList[thread_id].total_price != 0)
			{
				xPoint pt(CANNON_POSITION[chair_id_][0], CANNON_POSITION[chair_id_][1]);

				if (chair_id_ < 3)		
					pt.offset(0, 150);
				else
					pt.offset(0, -150);
			
				coin_layer_->big_fish_flash(pt, sendSavaList[thread_id].total_price);
			}

			///< 下面是闪电效果
			for (auto it : sendSavaList[thread_id].startList)
			{
				int bird_id = it.first;
				Vec2 start_p = it.second;
				int value = sendSavaList[thread_id].type_value[bird_id];
				auto find_vale = sendSavaList[thread_id].otherList.find(bird_id);
				if (find_vale != sendSavaList[thread_id].otherList.end())
				{
					std::vector<Vec2> other_list = sendSavaList[thread_id].otherList[bird_id];

					bird_layer_->showLightLineConnection(start_p, other_list, value);

					///< 发送数据后,清空列表
					if (pre_thread_id != -1)
					{
						sendSavaList[pre_thread_id].startList.clear();
						sendSavaList[pre_thread_id].otherList.clear();
						sendSavaList[pre_thread_id].type_value.clear();
						///< 删除前一个点
						sendSavaList.erase(pre_thread_id);
						pre_thread_id = thread_id;
					}
					else
						pre_thread_id = thread_id;

				}
				else
				{
					///< 没有找到后续的鱼...意思就是说.只有一个红鱼,其他的鱼都没有了...
					///< 红鱼爆炸效果要添加
				}
			}
		}
	}

}

/************************************************************************/
/* 切换场景                                                             */
/************************************************************************/
void CGameSceneEngine::net_change_scene(int scene)
{
	bird_speed_up(true);

	scene_layer_->chang_scene(scene);

	// 切换场景不能有音效
	SoundManager::shared()->stopAllEffect();
	SoundManager::shared()->playMusic("WaveEnter");
	SoundManager::shared()->setMusicVolume(100);

	///< 切换场景不能发炮
	ObjectPool::shared()->pauseBulletSend();

	char sSound[16] = { 0 };
	sprintf(sSound, "scene%d", scene_layer_->get_scene());
	//SoundManager::shared()->preloadMusic(sSound);

	clearSceneBird();
	m_pGameScene->unschedule("changeSceneMusicPlay");
	auto changeSceneMusicPlay = [=](float f)
	{
		char sSound[16] = { 0 };
		sprintf(sSound, "scene%d", scene_layer_->get_scene());

		///< 恢复发炮
		ObjectPool::shared()->resumeBulletSend();

		SoundManager::shared()->setMusicVolume(50);
		SoundManager::shared()->playMusic(sSound);
	};

	m_pGameScene->scheduleOnce(changeSceneMusicPlay, 7,"changeSceneMusicPlay");
}


/************************************************************************/
/* 清空场景的鱼                                                         */
/************************************************************************/
void CGameSceneEngine::clearSceneBird()
{
	//清除鱼
	log("come in clear bird!!");
	for (BirdManagerIter i = bird_manager_.begin(); i != bird_manager_.end();)
	{
		BirdManagerIter cur = i++;

		Bird *bird = cur->second;
		bird->live_ = 0;
		//BirdNode* node = (BirdNode*)bird->node_;

		bird_layer_->bird_dead(bird, true);
		destoryBird(bird);
	}

	bird_manager_.clear();
}

/************************************************************************/
/* 清空场景的子弹                                                       */
/************************************************************************/
void CGameSceneEngine::clearSceneBullet()
{
	//清除子弹
	IClientKernel * kernel = IClientKernel::get();

	BulletManagerIter it = bullet_manager_.begin();

	for (; it != bullet_manager_.end(); it++)
	{
		Bullet * bullet = (*it);
		if (bullet->shadow_)
		{
			BulletNode * node_shadow_ = (BulletNode *)bullet->shadow_;
			ObjectPool::shared()->destoryBulletNode(node_shadow_);
		}
		if (bullet->node_)
		{
			BulletNode * node = (BulletNode *)bullet->node_;
			ObjectPool::shared()->destoryBulletNode(node);
		}

		if (kernel && kernel->GetMeChairID() == bullet->chair_id_)
		{
			ObjectPool::shared()->bulletCountSub();
		}

		ObjectPool::shared()->destoryBullet(bullet);

	}

	bullet_manager_.clear();
}

/************************************************************************/
/* 上下分                                                               */
/************************************************************************/
void CGameSceneEngine::net_account(CMD_S_Account* account)
{
	IClientKernel* kernel = IClientKernel::get();

	RoleNode* role = role_layer_->get_role(account->chair_id_);
	role->set_gold(account->gold_left);

	if (account->chair_id_ == kernel->GetMeChairID())
	{
		set_status(GAME_LOGIC);
	}
}

/************************************************************************/
/* 鱼特效                                                               */
/************************************************************************/
void CGameSceneEngine::net_bird_effect(CMD_S_Bird_Effect* bird_effect)
{
	if (bird_effect->effect_ == BIRD_EFFECT_DING)
	{
		bird_ding(bird_effect->bird_id_ > 0);
		return;
	}
}

/************************************************************************/
/* 网络时间校                                                           */
/************************************************************************/
void CGameSceneEngine::net_time_check()
{
	IClientKernel* kernel = IClientKernel::get();
	RoleNode* role = role_layer_->get_role(kernel->GetMeChairID());
	role->set_net_state(gDntgTimestampManager.get_trad());
}

/************************************************************************/
/* 武器信息                                                             */
/************************************************************************/
bool CGameSceneEngine::net_weapon_level(void* data, int dataSize)
{
	//效验数据
	if (dataSize != sizeof(CMD_S_WeaponLevel))
		return false;
	CMD_S_WeaponLevel * WeaponLevel = (CMD_S_WeaponLevel *)data;

	role_layer_->set_level(WeaponLevel->chair_id_, WeaponLevel->level_);

	G_NOTIFY_D("WEAPON_LEVEL", MTData::create(WeaponLevel->chair_id_, WeaponLevel->level_));

	return true;
}

/************************************************************************/
/* 技能                                                                 */
/************************************************************************/
bool CGameSceneEngine::net_skill(void* data, int dataSize)
{
	//效验数据
	ASSERT(dataSize == sizeof(CMD_S_Skill));
	if (dataSize != sizeof(CMD_S_Skill))
		return false;
	CMD_S_Skill * cmd_skill = (CMD_S_Skill *)data;
	role_layer_->get_role(cmd_skill->chair_id_)->net_skill(cmd_skill->skill_, cmd_skill->cast_);

	return true;
}

/************************************************************************/
/* 强化效果                                                             */
/************************************************************************/
bool CGameSceneEngine::net_strengthen_result(void* data, int dataSize)
{
	//效验数据
	ASSERT(dataSize == sizeof(CMD_S_StrengthenResult));
	if (dataSize != sizeof(CMD_S_StrengthenResult))
		return false;

	warning_timer_.init(0);
	if (IClientKernel::get())
	{
		RoleNode* role = role_layer_->get_role(IClientKernel::get()->GetMeChairID());
		if (role)
			role->show_warning_fire(false);
	}

	CMD_S_StrengthenResult* pStrengthenResult = (CMD_S_StrengthenResult *)data;

	G_NOTIFY_D("STRENGTHEN_RESULT", MTData::create(pStrengthenResult->iResult));
	return true;
}

/************************************************************************/
/* 任务                                                                 */
/************************************************************************/
void CGameSceneEngine::net_task(CMD_S_Task_Open* task)
{
	/*if (task_layer_)
		task_layer_->task_start(task);
	if (frame_layer_)
	{
		frame_layer_->hideMenuButton();
	}*/
}

/************************************************************************/
/* 任务数量                                                             */
/************************************************************************/
void CGameSceneEngine::net_task_count(CMD_S_TaskCount* taskCount)
{
	if (task_layer_)
		task_layer_->task_count(taskCount);
}

/************************************************************************/
/* 任务完成                                                             */
/************************************************************************/
void CGameSceneEngine::net_task_complete(CMD_S_Task_Finish* taskComplete)
{
	if (task_layer_)
		task_layer_->task_complete(taskComplete);
}

/************************************************************************/
/* 设置是否可开火                                                       */
/************************************************************************/
void CGameSceneEngine::set_fire_enable(bool isEanbled)
{
	// 	if (touch_layer_)
	// 		touch_layer_->setTouchEnabled(isEanbled);
}
/************************************************************************/
/* 定                                                                   */
/************************************************************************/
void CGameSceneEngine::bird_ding(bool ding)
{
	if (bird_layer_ == 0)
		return;
	isDing = ding;
	PLAZZ_PRINTF("bird_ding ..... %s ", ding ? "ding" : "bu ding");
	static int Tcount = 0;
	CCLOG("ding count %d", ++Tcount);

	bird_layer_->set_ding_bird(ding);

	BirdManagerIter istart = bird_manager_.begin();
	BirdManagerIter iend = bird_manager_.end();

	int count = 1;
	for (BirdManagerIter i = istart; i != iend; ++i)
	{
		Bird *bird = i->second;

		if (bird == 0 || bird->live_ == 0)
			continue;
		BirdNode* birdNode = (BirdNode*)bird->node_;

		if (ding)
		{
			birdNode->setTag(0xFFFFFFF + count);
			birdNode->pauseSchedulerAndActions();
		}
		else
		{
			birdNode->setTag(0xFFF + count);
			birdNode->resumeSchedulerAndActions();
		}
		count++;
	}
}

/************************************************************************/
/*  加速                                                                */
/************************************************************************/
void CGameSceneEngine::bird_speed_up(bool speed_up)
{
	if (bird_layer_ == 0)
		return;

	BirdManagerIter istart = bird_manager_.begin();
	BirdManagerIter iend = bird_manager_.end();

	for (BirdManagerIter i = istart; i != iend; ++i)
	{
		Bird *bird = i->second;

		if (bird == 0 || bird->live_ == 0)
			continue;

		//加速游动
		BirdNode* birdNode = (BirdNode*)bird->node_;
		CCSpeed *act = dynamic_cast<CCSpeed *>(birdNode->getActionByTag(bird->move_action_id_));
		if (act)
		{
			bird->speed_ = (speed_up ? BIRD_MOVE_RUN_AWAY : BIRD_MOVE_NORMAL);
			act->setSpeed((speed_up ? BIRD_MOVE_RUN_AWAY : BIRD_MOVE_NORMAL));
		}

	}
}




/************************************************************************/
/* 定时时间校准                                                         */
/************************************************************************/
void CGameSceneEngine::func_send_time_check(float dt)
{
	send_time_check(false);
	///< 下面是校验是否还有网络
}

/************************************************************************/
/* 删除爆炸                                                             */
/************************************************************************/
void CGameSceneEngine::func_bomb_effect_end(cocos2d::Node * node, void * data)
{
	node->stopAllActions();
	node->removeFromParentAndCleanup(true);
}

/************************************************************************/
/* 是否可以开炮                                                         */
/************************************************************************/
bool CGameSceneEngine::getIsFire(){
	return is_touch_fire_;
}

/************************************************************************/
/* 设置是否可以开火                                                     */
/************************************************************************/
void CGameSceneEngine::setIsFire(bool isCanFire)
{
	is_touch_fire_ = isCanFire;
}

/************************************************************************/
/* 把点从UI坐标系转到GL坐标系                                           */
/************************************************************************/
CCPoint CGameSceneEngine::locationFromTouch(CCTouch* touch)
{
	return CCDirector::getInstance()->convertToGL(touch->getLocationInView());
}


/************************************************************************/
/* 销毁鱼                                                               */
/************************************************************************/
void CGameSceneEngine::destoryBird(Bird* bird)
{
	bird_manager_.erase(bird->id_);

	bird_Lockanager_.erase(bird->id_); 

	CCLOG("bird_manager size is %d", bird_manager_.size());
	ObjectPool::shared()->destoryBird(bird);
}
/************************************************************************/
/* 震屏                                                                 */
/************************************************************************/
void CGameSceneEngine::start_shake_screen(float shake_radius)
{
	if (!GlobalConfig::getInstance()->getIsShake()) return;
	shake_screen_angle_ = 0.0f;
	shake_screen_radius_ = shake_radius*0.75f;
}

/************************************************************************/
/* 停止震屏幕                                                           */
/************************************************************************/
void CGameSceneEngine::stop_shake_screen()
{
	if (!GlobalConfig::getInstance()->getIsShake()) return;
	scene_layer_->setPosition(0, 0);
	bird_layer_->setPosition(0, 0);
	net_layer_->setPosition(0, 0);
	bullet_layer_->setPosition(0, 0);
	coin_layer_->setPosition(0, 0);

	shake_screen_angle_ = (float)M_PI * 30;
}

/************************************************************************/
/* 震屏心跳                                                             */
/************************************************************************/
void CGameSceneEngine::shake_screen_update(float dt)
{
	return;
	if (!GlobalConfig::getInstance()->getIsShake()) return;
	if (shake_screen_angle_ < (float)M_PI * 24)
	{
		float x = shake_screen_radius_*std::cos(shake_screen_angle_);
		float y = shake_screen_radius_*std::sin(shake_screen_angle_);
		scene_layer_->setPosition(x, y);

		shake_screen_angle_ = shake_screen_angle_ + 1.9f*0.8f;

		if (shake_screen_angle_ >= M_PI * 24)
		{
			stop_shake_screen();
		}
	}
}

/************************************************************************/
/* 购买子弹                                                             */
/************************************************************************/
void CGameSceneEngine::op_buy_bullet(SCORE fishCoins)
{
	/*	set_status(GAME_BUY_SEND);*/

	// 购买子弹
	IClientKernel* kernel = IClientKernel::get();
	IClientUserItem* MeUserItem = kernel->GetMeUserItem();

	CMD_C_Buy_Bullet buy_bullet;
	buy_bullet.count_ = fishCoins;
	kernel->SendSocketData(MDM_GF_GAME, SUB_C_BUY_BULLET, (char *)&buy_bullet, sizeof(CMD_C_Buy_Bullet));
}

/************************************************************************/
/* 下分                                                                 */
/************************************************************************/
void CGameSceneEngine::op_account()
{
	set_status(GAME_ACCOUNT);
	IClientKernel* kernel = IClientKernel::get();
	CMD_C_Account account;
	account.chair_id_ = kernel->GetMeChairID();
	kernel->SendSocketData(MDM_GF_GAME, SUB_C_ACCOUNT, (char *)&account, sizeof(CMD_C_Account));
}

/************************************************************************/
/* 最大分                                                               */
/************************************************************************/
void CGameSceneEngine::op_buy_max()
{
	IClientKernel* kernel = IClientKernel::get();
	CMD_C_Buy_Bullet buy_bullet;
	buy_bullet.count_ = -2;
	kernel->SendSocketData(MDM_GF_GAME, SUB_C_BUY_BULLET, (char *)&buy_bullet, sizeof(CMD_C_Buy_Bullet));
}

/************************************************************************/
/* 增加炮类型                                                           */
/************************************************************************/
void CGameSceneEngine::op_cannon_add()
{
	IClientKernel* kernel = IClientKernel::get();
	int me_chair_id = kernel->GetMeChairID();
	RoleNode* role = role_layer_->get_role(me_chair_id);

	// 改变炮台
	if (role->get_cannon() >= GameConfig::getInstance().get_mulriple_count() - 1)
		return;
	SoundManager::shared()->playSound("cannon_add");
	int can = role->get_cannon();
	role->set_cannon(role->get_cannon() + 1);

	role->set_level(role->get_level() + 1);
	////炮台类型 由子弹种类确定
	int mc = GameConfig::getInstance().get_mulriple_count();
	can = role->get_cannon();
	int cannon_type = role->get_cannon() / (GameConfig::getInstance().get_mulriple_count() / (BULLET_KIND_COUNT - 1));
	netType = role->get_cannon();
	//子弹速度
	role->set_cannon_speed(GameConfig::getInstance().get_bullet_config(cannon_type).speed);
}

/************************************************************************/
/* 减少炮                                                               */
/************************************************************************/
void CGameSceneEngine::op_cannon_sub()
{
	IClientKernel* kernel = IClientKernel::get();
	int me_chair_id = kernel->GetMeChairID();
	RoleNode* role = role_layer_->get_role(me_chair_id);

	// 改变炮台
	if (role->get_cannon() == 0)
		return;

	SoundManager::shared()->playSound("cannon_sub");
	role->set_cannon(role->get_cannon() - 1);

	role->set_level(role->get_level() - 1);
	//炮台类型 由子弹种类确定
	int cannon_type = role->get_cannon() / (GameConfig::getInstance().get_mulriple_count() / (BULLET_KIND_COUNT - 1));
	netType = role->get_cannon();
	//子弹速度
	role->set_cannon_speed(GameConfig::getInstance().get_bullet_config(cannon_type).speed);
}

/************************************************************************/
/* 最大炮                                                               */
/************************************************************************/
void CGameSceneEngine::op_cannon_max()
{
	IClientKernel* kernel = IClientKernel::get();
	int me_chair_id = kernel->GetMeChairID();
	RoleNode* role = role_layer_->get_role(me_chair_id);

	// 改变炮台
	if (role->get_cannon() == GameConfig::getInstance().get_mulriple_count()-1)
		return;
	SoundManager::shared()->playSound("cannon_add");

	role->set_cannon(GameConfig::getInstance().get_mulriple_count()-1);

	//炮台类型 由子弹种类确定
	int cannon_type = role->get_cannon() / (GameConfig::getInstance().get_mulriple_count() / BULLET_KIND_COUNT);
	//子弹速度
	role->set_cannon_speed(GameConfig::getInstance().get_bullet_config(cannon_type).speed);
}

/************************************************************************/
/*发炮                                                                  */
/************************************************************************/
void CGameSceneEngine::op_fire()
{
	if (0 == GameConfig::getInstance().get_mulriple_count())
	{
		return;
	}
	if (!is_key_fire_ && !is_touch_fire_)
		return;

	static CoTimer fire_timer;

	if (!fire_timer.isTimeUp())
		return;





	IClientKernel* kernel = IClientKernel::get();
	if (!kernel) return;
	int me_chair_id = kernel->GetMeChairID();
	RoleNode* role = role_layer_->get_role(me_chair_id);

	//没钱你打锤子炮

	if (role->get_gold() < role->get_cannon_mulriple())
	{
		return;
	}





	int resou = (GameConfig::getInstance().get_mulriple_count() / (BULLET_KIND_COUNT - 1));
	int cannon_type = role->get_cannon() / (GameConfig::getInstance().get_mulriple_count() / (BULLET_KIND_COUNT - 1));
	//子弹间隔
	int fire_interval_ = GameConfig::getInstance().get_bullet_config(cannon_type).fire_interval;
	if (!role->can_fire())
	{
		is_key_fire_ = false;
		is_touch_fire_ = false;
		//防止过快出现提示
		fire_timer.init(1000);

		//showExchange();
		return;
	}

	///< 增加计数!!!!!
	bool needFire = ObjectPool::shared()->bulletCountAdd();
	if (!needFire) return;

	fire_timer.init(fire_interval_);

	warning_timer_.init(0);
	role->show_warning_fire(false);
	role->fire(true);

	Bullet *bullet = ObjectPool::shared()->createBullet();
	bullet->id_				= bullet_index_factroy();
	bullet->rotation_		= role->get_bow_angle();
	bullet->chair_id_		= role->get_chair_id();
	bullet->cannon_type_	= role->get_cannon();
	bullet->bullet_type_	= role->get_bullet_index_by(role->get_level());
	bullet->net_type_		= role->get_net_index_by(role->get_level());
	bullet->speed_			= role->get_cannon_speed();
	bullet->node_			= 0;
	bullet->move_action_id_ = -1;
	int bird_id = !role->getLockBird() || !role->getLockBird()->bird ? -1 : role->getLockBird()->bird->id_;
	bullet->lock_bird_id_ = bird_id;

	bullet_manager_.push_back(bullet);
	float angle_1 = CC_RADIANS_TO_DEGREES(bullet->rotation_);
	//发送子弹
	bullet->rotation_ = bullet_layer_->fire(bullet, gDntgTimestampManager.get_trad());

	float angle_2 = CC_RADIANS_TO_DEGREES(bullet->rotation_);
	send_op_fire(bullet);

	//测试用
	bulletCount++;
}

/************************************************************************/
/* 想服务器发送子弹                                                     */
/************************************************************************/
void CGameSceneEngine::send_op_fire(Bullet * bullet)
{
	IClientKernel* kernel = IClientKernel::get();
	if (!kernel) return;
	int me_chair_id = kernel->GetMeChairID();
	RoleNode* role = role_layer_->get_role(me_chair_id);


	//发送消息
	CMD_C_Fire fire;
	fire.rote_				= bullet->rotation_;
	fire.time_				= gDntgTimestampManager.get_server_tick();
	fire.speed_				= bullet->speed_;
	fire.bullet_mulriple_	= role->get_cannon_mulriple();
	fire.bullet_type		= 1;
	
	if (role->getLockBird())
		fire.lock_bird_id_ = role->getLockBird()->bird->id_;
	else
		fire.lock_bird_id_ = -1;

    log("bullet %d",bullet->chair_id_ );
    
	kernel->SendSocketData(MDM_GF_GAME, SUB_C_FIRE, (char *)&fire, sizeof(CMD_C_Fire));
}

/************************************************************************/
/* 关闭响应函数                                                         */
/************************************************************************/
void CGameSceneEngine::closeCallback(cocos2d::Node *pNode)
{
	switch (pNode->getTag())
	{
		case DLG_MB_OK:
		{
			if (IClientKernel::get())
				IClientKernel::get()->Intermit(GameExitCode_Normal);
		}
		break;
	}
}

/************************************************************************/
/* 强化确认                                                             */
/************************************************************************/
void CGameSceneEngine::func_strenthen_confirm(cocos2d::Ref* obj)
{
	if (IClientKernel::get())
		IClientKernel::get()->SendSocketData(MDM_GF_GAME, SUB_C_STRENGTHEN, 0, 0);
}

/************************************************************************/
/* 打开强化面板                                                         */
/************************************************************************/
void CGameSceneEngine::func_ui_strenthen_open(cocos2d::Ref* obj)
{
	m_pGameScene->addChild(UIStrengthen::create());
}

/************************************************************************/
/* 上分                                                                 */
/************************************************************************/
void CGameSceneEngine::func_score_up(cocos2d::Ref* obj)
{
	op_buy_max();
}

/************************************************************************/
/*下分                                                                  */
/************************************************************************/
void CGameSceneEngine::func_score_down(cocos2d::Ref* obj)
{
	op_account();
}

/************************************************************************/
/* 更换炮类型                                                           */
/************************************************************************/
void CGameSceneEngine::func_cannon_add(cocos2d::Ref* obj)
{
	op_cannon_add();
}

/************************************************************************/
/* 更换炮类型                                                           */
/************************************************************************/
void CGameSceneEngine::func_cannon_sub(cocos2d::Ref* obj)
{
	op_cannon_sub();
}

/************************************************************************/
/* 最大炮类型                                                           */
/************************************************************************/
void CGameSceneEngine::func_cannon_max(cocos2d::Ref* obj)
{
	op_cannon_max();
}

/************************************************************************/
/* 键盘消息                                                             */
/************************************************************************/
void CGameSceneEngine::func_keyboard(cocos2d::Ref* obj)
{
#if(CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)	
	static int skills[] = { 10, 20, 21, 30, 31, 32, 40, 41, 42, 43, 50, 51, 52, 53, 54 };
	static int skill_count = sizeof(skills) / sizeof(int);
	static int skill = 0;

	MTData* data = (MTData*)obj;
	switch (data->mData1)
	{
		case WM_KEYDOWN:
		{
			switch (data->mData2)
			{
				case '1': op_buy_bullet(-1);	break;
				case '2': op_account();			break;
				case '6': op_buy_max();			break;
				case '3': op_cannon_add();		break;
				case '4': op_cannon_sub();		break;
				case '5': op_cannon_max();		break;
				case VK_SPACE:
					if (!is_key_fire_)
					{
						is_key_fire_ = true;
						op_fire();
					}
					break;
				case VK_LEFT:
					if (skill > 0)
						skill -= 1;
					break;
				case VK_RIGHT:
					skill = (skill + 1) % skill_count;
					break;
				case VK_UP:
				{
					IClientKernel* kernel = IClientKernel::get();

					if (kernel)
					{
						int me_chair_id = kernel->GetMeChairID();
						RoleNode* role = role_layer_->get_role(me_chair_id);
						role->net_skill(skills[skill], 1);

					}
				}
				break;
				case VK_DOWN:
					{
						IClientKernel* kernel = IClientKernel::get();

						if (kernel)
						{
							int me_chair_id = kernel->GetMeChairID();
							RoleNode* role = role_layer_->get_role(me_chair_id);
							role->net_skill(skills[skill], 0);

						}
					}
					break;
			}
		}
		break;
		case WM_KEYUP:
			switch (data->mData2)
			{
			case VK_RETURN:
				{
					IClientKernel* kernel = IClientKernel::get();
					if (kernel)
						kernel->SendSocketData(MDM_GF_GAME, SUB_C_RANK_LIST, 0, 0);
				}
				break;
			case VK_SPACE:
				if (is_key_fire_)
				{
					is_key_fire_ = false;
				}
				break;
			}
			break;
		case WM_CHAR:
			break;
	}
#endif
}

//win32键盘按下消息
void CGameSceneEngine::func_key_Pressed(EventKeyboard::KeyCode keyCode, Event * event)
{
	switch (keyCode)
	{
	case EventKeyboard::KeyCode::KEY_SPACE:
		if (!is_key_fire_)
		{
			is_key_fire_ = true;
			op_fire();
		}
	break;
	default:
		break;
	}
}

//win32键盘抬起消息
void CGameSceneEngine::func_key_Released(EventKeyboard::KeyCode keyCode, Event * event)
{
	switch (keyCode)
	{
		case EventKeyboard::KeyCode::KEY_SPACE:
			if (is_key_fire_)
				{
					is_key_fire_ = false;
				}
			break;
		case EventKeyboard::KeyCode::KEY_UP_ARROW:		
			op_cannon_add();
			break;
		case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
			op_cannon_sub();
			break;
		case EventKeyboard::KeyCode::KEY_F10:
			autoFire();
			break;
		case EventKeyboard::KeyCode::KEY_CAPITAL_S:
		case EventKeyboard::KeyCode::KEY_S:
			collision_change_bird();
			break;
		case EventKeyboard::KeyCode::KEY_CAPITAL_Q:
		case EventKeyboard::KeyCode::KEY_Q:
			role_layer_->get_role(IClientKernel::get()->GetMeChairID())->setLockBird(nullptr);
			break;
	default:
		break;
	}
}



/************************************************************************/
/* 取消鱼的锁定的回调                                                   */
/************************************************************************/
void CGameSceneEngine::cancelBirdLock(cocos2d::Ref * obj)
{
	EventCustom *event_ = (EventCustom*)obj;
	if (event_ == 0){
		return;
	}

	MTData* data = (MTData*)event_->getUserData();
	if (data == 0)
		return;

	IClientKernel* kernel = IClientKernel::get();
	if (kernel == nullptr) return;
	int value = data->mData1;
	bool isSelf = false;
	for (int i = 0; i < 6; i++)
	{
		if (value == kernel->GetMeChairID())
		{
			///< 1号椅子
			RoleNode * role = role_layer_->get_role(i);
			role->cancelBirdLock(obj);

			// 如果是自己,那么取消掉自动开火
			// 如果是鱼被击杀,那么重新锁定别的鱼
			// 如果是取消鱼的锁定,那么自动停止锁定,并做下面的检测
			int my_id = kernel->GetMeChairID();
			if (i == my_id)
			{
				if (data->mData2 == 1)
				{
					///<如果锁定的同时又自动开火,那么击杀锁定鱼后,仍然保持自动开火状态
					if (!frame_layer_->getAutoFire())
					{
						this->setIsFire(false);
					}
				}
				isSelf = true;
			}
		}
	}

	//
	if (frame_layer_->getLock())
	{
		if (data->mData2 == 2 && isSelf)
		{
			collision_pos_bird();
		}
	}

}

/************************************************************************/
/*取消全部鱼的锁定                                                      */
/************************************************************************/
void CGameSceneEngine::cancelAllBirdLock()
{
	for (int i = 0; i < 6; i++)
	{

		///< 1号椅子
		RoleNode * role = role_layer_->get_role(i);
		role->setLockBird(nullptr);
	}
}

/************************************************************************/
/* 让鱼知道自己被那个玩家锁定了                                         */
/************************************************************************/
void CGameSceneEngine::setBirdLock(int char_id, int bird_id)
{
	///< 取消锁定鱼
	if (bird_id == -1)
	{
		role_layer_->get_role(char_id)->setLockBird(nullptr);
		return;
	}
	BirdNode * spr_bird;
	BirdManagerIter jend = bird_manager_.end();

	for (BirdManagerIter j = bird_manager_.begin(); j != jend; ++j)
	{
		Bird * bird = j->second;

		if (bird->live_ == 0)
			continue;

		spr_bird = (BirdNode*)bird->node_;
		if (bird->id_ == bird_id)
		{
			role_layer_->get_role(char_id)->setLockBird(spr_bird);
			spr_bird->setLock(true, char_id);
		}
	}
}

/************************************************************************/
/* 是断线重连                                                           */
/************************************************************************/
bool CGameSceneEngine::is_Reconnect_on_loss()
{
	return isDntgReconnectOnLoss;
}

/************************************************************************/
/* 获得单局获得总金币                                                   */
/************************************************************************/
std::string CGameSceneEngine::getSingleGameTotalGold()
{
	return StringUtils::format("%lld", SingleGameTotalGold);
}

/************************************************************************/
/* 获得对应总钱数                                                       */
/************************************************************************/
std::string CGameSceneEngine::getUserTotalMoney()
{
	IClientKernel* kernel = IClientKernel::get();
	RoleNode * node = role_layer_->get_role(kernel->GetMeChairID());

	return StringUtils::format("%lld", node->get_gold());
}



/************************************************************************/
/* 显示介绍                                                             */
/************************************************************************/
void CGameSceneEngine::showGuide()
{
	if (m_uiGameGuide)
	{
		m_uiGameGuide->show();
	}
}

/************************************************************************/
/* 显示兑换界面                                                         */
/************************************************************************/
void CGameSceneEngine::showExchange()
{
	IClientKernel* kernel = IClientKernel::get();
	if (!kernel) return;
	int me_chair_id = kernel->GetMeChairID();
	//longlong changnum = mCashShopLayer_->GetLastChangGoldNum();
	IClientUserItem* pClientUserItem = kernel->GetTableUserItem(me_chair_id);
#if 0
	SCORE score = pClientUserItem->GetUserScore();
#else
	SCORE score = mLocalScore;
#endif
	mCashShopLayer_->updateValue(score, cash_ratio);
	mCashShopLayer_->setPosition(CCPoint(0, 0));
}

/************************************************************************/
/* 隐藏兑换界面                                                         */
/************************************************************************/
void CGameSceneEngine::hideExchange()
{
	mCashShopLayer_->setPosition(CCPoint(kPlatformRevolutionWidth, kPlatformRevolutionHeight));
}

/************************************************************************/
/* 显示排名                                                             */
/************************************************************************/
bool CGameSceneEngine::showRankList(void* data, int dataSize)
{
	tagMatchRankList* pData = (tagMatchRankList*)data;
	if (NULL == pData)
	{
		//MessageBoxA(NULL, "c", "b", 0);
		ASSERT(FALSE);
		return false;
	}
	word receiveDataSize = sizeof(tagMatchRankList) + sizeof(tagMatchSubRankList)*(pData->wCount - MAX_MATCH_SHOW_NUMBER);
	if (dataSize != receiveDataSize)
	{
		//MessageBoxA(NULL, "d", "b", 0);
		ASSERT(FALSE);
		return false;
	}
	if (pData->wCount >= MAX_MATCH_SHOW_NUMBER)
	{
		//MessageBoxA(NULL, "e", "b", 0);
		ASSERT(FALSE);
		//return false;
	}
	UIMyRankList* uiMyRanklist = UIMyRankList::create();
	uiMyRanklist->openShowTimeSchedule();//打开定时器
	for (word i = 0; i < pData->wCount; ++i)
	{
		//MessageBoxA(NULL, "f", "b", 0);
		uiMyRanklist->onShowInfo(i, pData->sRankData[i]);
	}
	m_pGameScene->addChild(uiMyRanklist);
	return true;
}

/************************************************************************/
/* 时间校验                                                             */
/************************************************************************/
void CGameSceneEngine::send_time_check(bool is_game_status)
{
	if (IClientKernel::get() == 0)
		return;

	CMD_C_TimeCheck time_check;
	time_check.chair_id_ = IClientKernel::get()->GetMeChairID();
	time_check.time_ = gDntgTimestampManager.getTimeCheck();
	time_check.is_game_status_ = is_game_status;

	IClientKernel::get()->SendSocketData(MDM_GF_GAME, SUB_C_TIME_CHECK, (char *)&time_check, sizeof(CMD_C_TimeCheck));
}

/************************************************************************/
/* 清楚任务                                                             */
/************************************************************************/
void CGameSceneEngine::clear_task_info()
{
	if (mRoomTask) delete mRoomTask;
	if (mChairTask) delete mChairTask;
	mRoomTask = nullptr;
	mChairTask = nullptr;
}

/************************************************************************/
/* 场景消息                                                             */
/************************************************************************/
bool CGameSceneEngine::OnEventSceneMessage(byte cbGameStatus, bool bLookonUser, void* data, int dataSize)
{
	switch (cbGameStatus)
	{
	case GAME_STATUS_FREE:
	case GAME_STATUS_PLAY:
	{
		//效验数据
		if (dataSize != sizeof(CMD_S_StatusFree)) return false;

		CMD_S_StatusFree * status_free = (CMD_S_StatusFree *)data;

		gDntgTimestampManager.timeCheck(0, 0);

		on_scene_message(cbGameStatus, bLookonUser, data, dataSize);
		send_time_check(true);
		return true;
	}
	}
	return true;
}

/************************************************************************/
/* 游戏消息                                                             */
/************************************************************************/


bool CGameSceneEngine::OnEventGameMessage(int sub, void* data, int dataSize)
{
	bool isSuc = false;
	switch (sub)
	{
		//购买子弹成功
	case SUB_S_BUY_BULLET_SUCCESS:
		isSuc = on_sub_buy_bullet_success(data, dataSize);
		break;
	case SUB_C_ISANDUSER_ACCOUNTS:
		isSuc = on_sub_buy_AndirInfo(data, dataSize);
		break;

		//购买子弹失败
	case SUB_S_BUY_BULLET_FAILED:
		isSuc = on_sub_buy_bullet_failed(data, dataSize);
		break;
		//改变炮类型
	case SUB_S_CHANGE_CANNON:
		isSuc = on_sub_change_cannon(data, dataSize);
		break;
		//鱼生成
	case SUB_S_SEND_BIRD:
		isSuc = on_sub_send_bird(data, dataSize);
		break;
		//子弹生成
	case SUB_S_SEND_BULLET:
		isSuc = on_sub_send_bullet(data, dataSize);
		break;
		//开火失败
	case SUB_S_FIRE_FAILED:
		isSuc = on_sub_fire_failed(data, dataSize);
		break;
		//抓住鱼
	case SUB_S_CATCH_BIRD:
		isSuc = on_sub_catch_bird(data, dataSize);
		break;
		//抓住鱼
	case SUB_S_CATCH_BIRD_GROUP:
		isSuc = on_sub_catch_bird_group(data, dataSize);
		break;
		//闪电鱼
	case SUB_S_CATCH_BIRD_CHAIN:
		isSuc = on_sub_catch_bird_chain(data, dataSize);
		break;
		//改变场景
	case SUB_S_CHANGE_SCENE:
		isSuc = on_sub_scene_change(data, dataSize);
		break;
		// 上下分
	case SUB_S_ACCOUNT:
		isSuc = on_sub_game_account(data, dataSize);
		break;
		//时间校准
	case SUB_S_TIME_CHECK:
		isSuc = on_sub_time_check(data, dataSize);
		break;
		//时间校准
	case SUB_S_ORDER_TIME_CHECK:
		isSuc = on_sub_order_time_check(data, dataSize);
		break;
		//鱼特效
	case SUB_S_BIRD_EFFECT:
		isSuc = on_sub_bird_effect(data, dataSize);
		break;
		//鱼boss
	case SUB_S_BIRD_BOSS:
		isSuc = on_sub_bird_boss(data, dataSize);
		break;
		//武器信息
	case SUB_S_WEAPON_INFO:
		isSuc = on_sub_weapon_info(data, dataSize);
		break;
		//武器等级
	case SUB_S_WEAPON_LEVEL:
		isSuc = on_sub_weapon_level(data, dataSize);
		break;
		//财富信息
	case SUB_S_TREASURE:
		isSuc = on_sub_treasure(data, dataSize);
		break;
		//技能
	case SUB_S_SKILL:
		isSuc = on_sub_skill(data, dataSize);
		break;
		//强化结果
	case SUB_S_STRENGTHEN_RESULT:
		isSuc = on_sub_strengthen_result(data, dataSize);
		break;
		//任务悬赏
	case  SUB_S_TASK_REWARD:
		isSuc = on_sub_task_reward(data, dataSize);
		break;
		//任务
	case SUB_S_TASK:
		isSuc = on_sub_task(data, dataSize);
		break;
		//任务数量
	case SUB_S_TASK_COUNT:
		isSuc = on_sub_task_count(data, dataSize);
		break;
		//任务完成
	case SUB_S_TASK_COMPLETE:
		isSuc = on_sub_task_complete(data, dataSize);
		break;
		//排行榜自己信息
	case SUB_S_RANK_INFO:
		isSuc = on_sub_rank_info(data, dataSize);
		break;
		//排行榜列表
	case SUB_S_RANK_LIST:
		isSuc = on_sub_rank_list(data, dataSize);
		break;
		//游戏状态 所有鱼
	case SUB_S_PLAY_BIRD:
		isSuc = on_sub_play_bird(data, dataSize);
		break;
		//游戏状态 所有子弹
	case SUB_S_PLAY_BULLET:
		isSuc = on_sub_play_bullet(data, dataSize);
		break;
		//库存操作
	case SUB_S_STORAGE:
		isSuc = on_sub_storage(data, dataSize);
		break;
		//黑白名单
	case SUB_S_BLACK_WHITE:
		isSuc = on_sub_black_white(data, dataSize);
		break;
		//发送特殊鱼阵
	case SUB_S_SEND_BIRD_LINEAR:
		isSuc = on_sub_bird_linear(data, dataSize);
		break;
		//
	case SUB_S_SEND_BIRD_ROUND:
		isSuc = on_sub_bird_round(data, dataSize);
		break;
		//
	case SUB_S_SEND_BIRD_PAUSE_LINEAR:
		isSuc = on_sub_bird_pause_linear(data, dataSize);
		break;
		//新加前控
	case SUB_S_STOCK_OPERATE_RESULT:
		isSuc = onSockOperateResult(data, dataSize);
		break;
		//管理员控制
	case SUB_S_ADMIN_CONTROL:
		isSuc = onRBLControlResult(data, dataSize);
		break;
		//难度设置
	case SUB_S_DIFFICULTY:
		isSuc = onDifficultOperateResult(data, dataSize);
		break;
		//任务打开
	case SUB_S_TASK_OPEN:
		isSuc = true;//on_sub_game_task_open(data, dataSize);
		break;
		//任务完成
	case SUB_S_TASK_FINISH:
		isSuc = true;// on_sub_game_task_finish(data, dataSize);
		break;
	case SUB_S_ADMIN_CHECK:
		isSuc = on_sub_buy_Admin_success(data, dataSize);
		break;
	case SUB_S_CFISH_ROOM:
		isSuc = on_sub_buy_Admin_UserInfo(data, dataSize);
		break;
	case SUB_C_REQUEST_S_USERROSTER:
		isSuc = on_sub_buy_Admin_MingDan(data, dataSize);
		break;
	}

	if (isSuc)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/************************************************************************/
/* 隐藏兑换                                                             */
/************************************************************************/
void CGameSceneEngine::funcHideExchang(cocos2d::Ref* obj)
{
	hideExchange();
}

/************************************************************************/
/* 显示管理员了引导你妹                                                            */
/************************************************************************/
void CGameSceneEngine::funcShowGuide(cocos2d::Ref* obj)
{
	showGuide();
}

/************************************************************************/
/* 显示引导                                                             */
/************************************************************************/
void CGameSceneEngine::funcBuyBullet(cocos2d::Ref* obj)
{
	EventCustom *event_ = (EventCustom*)obj;
	if (event_ == 0){
		return;
	}

	MTData* data = (MTData*)event_->getUserData();
	if (data == 0)
		return;

	this->op_buy_bullet(data->getData1());
}


