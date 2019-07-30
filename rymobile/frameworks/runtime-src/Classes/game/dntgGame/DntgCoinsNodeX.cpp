#include "tools/manager/SpriteHelper.h"
#include "DntgCoinsNodeX.h"

USING_NS_CC;

#define MAX_COIN_POS 3
using namespace Dntg;
//////////////////////////////////////////////////////////////////////////
CoinsNodeX::CoinsNodeX()
{
}

CoinsNodeX::~CoinsNodeX()
{
}

bool CoinsNodeX::init()
{
	do
	{
		CC_BREAK_IF(!Node::init());

		for (int i = 0; i < MAX_COIN_POS; i++)
		{
			CoinsNode* coin = CoinsNode::create();
			addChild(coin);
			coin->setVisible(false);
			coins_.push_back(coin);
		}

		return true;
	} while (0);

	return false;
}

void CoinsNodeX::show_coin_animtion(int count, int score, int chair_id_)
{
	CoinsNode* node;
	float delayShow = 0.001f;

	if (coins_.empty())
	{
		pop_front();
		delayShow = 0.3f;
	}

	node = coins_.front();
	coins_.pop_front();
	using_.push_back(node);

	int pos = using_.size() - 1;

	node->show_coin(count, score, chair_id_);
	node->setPosition(cocos2d::Vec2(get_coin_offset(pos), 0));

	if (pos == 0)
	{
		node->setVisible(true);
		node->runAction(CCSequence::create(
			CCDelayTime::create(3),
			CCCallFuncND::create(this, callfuncND_selector(CoinsNodeX::func_show_pos_animtion_end), 0),
			0));
	}
	else
	{
		node->setVisible(false);
		node->runAction(CCSequence::create(
			CCDelayTime::create(delayShow),
			CCShow::create(),
			0));
	}
}

void CoinsNodeX::pop_front()
{
	if (using_.empty())
		return;

	CoinsNode* node = using_.front();
	using_.pop_front();
	node->stopAllActions();
	node->setVisible(false);
	coins_.push_back(node);

	int pos = 0;
	NodeListIter it = using_.begin();

	for (; it != using_.end(); ++it)
	{
		CoinsNode* tmp = *it;
		tmp->stopAllActions();
		tmp->setVisible(true);
		int offset = get_coin_offset(pos);
		if (pos == 0)
		{
			tmp->runAction(CCSequence::create(
				CCMoveTo::create(0.3f, cocos2d::Vec2(offset, 0)),
				CCDelayTime::create(3),
				CCCallFuncND::create(this, callfuncND_selector(CoinsNodeX::func_show_pos_animtion_end), 0),
				0));
		}
		else
		{
			tmp->runAction(CCMoveTo::create(0.3f, cocos2d::Vec2(offset, 0)));
		}

		++pos;
	}
}

void CoinsNodeX::func_show_pos_animtion_end(cocos2d::Node* node, void* data)
{
	pop_front();
}

int CoinsNodeX::get_coin_offset(int pos)
{
	if (getRotation() != 0)
	{
		switch (pos)
		{
		case 0:	return -40;
		case 2: return 40;
		}
		return 0;
	}

	switch (pos)
	{
	case 0:	return 40;
	case 2: return -40;
	}
	return 0;
}