#include "DntgRoleNode.h"
#include "DntgRoleLayer.h"
#include "kernel/game/IClientKernel.h"
#include "DntgBirdDefine.h"
#include "kernel/game/CGameFrameEngine.h"
#include "kernel/game/IGameFrameEngineSink.h"
#include "DntgGameScene.h"

USING_NS_CC;
using namespace Dntg;
//////////////////////////////////////////////////////////////////////////
RoleLayer::RoleLayer()
: mIsTouchEnabled(false)
{
    for (int i = 0; i < GAME_PLAYER; ++i)
    {
        mRoleNode[i] = nullptr;
    }
    CCLOG("--1-- RoleLayer = %p", this);
}

RoleLayer::~RoleLayer()
{
}

//初始化方法
bool RoleLayer::init()
{
	do
	{
		CC_BREAK_IF(!CCLayer::init());

		for (int i = 0; i < GAME_PLAYER; ++i)
		{
			mRoleNode[i] = RoleNode::create(i);
            CCLOG("--1-- RoleNode chair %d  p=%p  this=%p   parent=%p",i,mRoleNode[i], this, getParent());
			this->addChild(mRoleNode[i]);
		}

		return true;
	} while (0);

	return false;
}

RoleNode* RoleLayer::get_role(int chair_id)
{
	CCAssert(chair_id < GAME_PLAYER, "invalid chair_id");
    CGameSceneEngine* pGameSceneSink = dynamic_cast<CGameSceneEngine*>(CGameFrameEngine::Get()->GetGameFrameEngineSink()->GetGameSceneSink());
    auto pRoleLayer = pGameSceneSink->role_layer_;
    //CCLOG("--1-- pRoleLayer=%p  roleLayer=%p  bulletLayer=%p  gameSceneEngine=%p   m_pGameScene=%p", pRoleLayer, pGameSceneSink->role_layer_, pGameSceneSink->bullet_layer_, pGameSceneSink, pGameSceneSink->getGameScene());
//    for (int i = 0; i < GAME_PLAYER; ++i)
//    {
//        CCLOG("--1-- 2 RoleNode chair %d  p=%p  this=%p  parent=%p",i,mRoleNode[i], this, getParent());
//    }
	return mRoleNode[chair_id];
}

void RoleLayer::set_gold(int chair_id, longlong gold)
{
	CCAssert(chair_id < GAME_PLAYER, "invalid chair_id");
	mRoleNode[chair_id]->set_gold(gold);
}

void RoleLayer::add_gold(int chair_id, longlong gold)
{
	CCAssert(chair_id < GAME_PLAYER, "invalid chair_id");
	mRoleNode[chair_id]->set_gold(mRoleNode[chair_id]->get_gold() + gold);
}

void RoleLayer::set_cannon(int chair_id, int cannon_type)
{
	CCAssert(chair_id < GAME_PLAYER, "invalid chair_id");
	mRoleNode[chair_id]->set_cannon(cannon_type);
}

void RoleLayer::set_cannon_mulriple(int chair_id, int cannon_mulriple)
{
	CCAssert(chair_id < GAME_PLAYER, "invalid chair_id");
	mRoleNode[chair_id]->set_cannon_mulriple(cannon_mulriple);
}

void RoleLayer::set_level(int chair_id, int level)
{
	CCAssert(chair_id < GAME_PLAYER, "invalid chair_id");
	mRoleNode[chair_id]->set_level(level);
}

void RoleLayer::bullet_send(int chair_id, int cannon_mulriple, float rotation, int trad)
{
	CCAssert(chair_id < GAME_PLAYER, "invalid chair_id");

	IClientKernel* kernel = IClientKernel::get();

	RoleNode* role = mRoleNode[chair_id];

	int64 gold = role->get_gold();
	int64 fire_gold = cannon_mulriple;
	int64 final_gold = 0;

	if (gold > fire_gold)
		final_gold = gold - fire_gold;
	else
		final_gold = 0;

	role->set_gold(final_gold);
	if (!role->getLockBird())
		role->set_bow_angle(rotation);
	role->set_cannon_mulriple(cannon_mulriple);
	role->fire(false);

	if (chair_id != kernel->GetMeChairID())
		role->set_net_state(trad / 2);

}
