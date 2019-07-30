#include "DntgObjectPool.h"

#include "DntgBirdNode.h"
#include "DntgBulletNode.h"
#include "DntgHeader.h"


USING_NS_CC;
using namespace std;
using namespace Dntg;
//////////////////////////////////////////////////////////////////////////
ObjectPool* ObjectPool::msInstance = 0;

ObjectPool* ObjectPool::shared()
{
	if (msInstance == 0)
		msInstance = new ObjectPool();
	return msInstance;
}

void ObjectPool::purge()
{
	if (msInstance)
		delete msInstance;
	msInstance = 0;
}

//////////////////////////////////////////////////////////////////////////

ObjectPool::ObjectPool()
{
	mBirdNodes = CCDictionary::create();
	mBirdNodeUsing = CCArray::create();

	CC_SAFE_RETAIN(mBirdNodes);
	CC_SAFE_RETAIN(mBirdNodeUsing);

	mBulletNodes = CCDictionary::create();
	mBulletNodeUsing = CCArray::create();

	CC_SAFE_RETAIN(mBulletNodes);
	CC_SAFE_RETAIN(mBulletNodeUsing);

	mBulletCount = 0;
}

ObjectPool::~ObjectPool()
{
	list<Bird*>::iterator itBird = mBirds.begin();

	for (; itBird != mBirds.end(); ++itBird)
	{
		delete *itBird;
	}

	mBirds.clear();

	itBird = mBirdUsing.begin();

	for (; itBird != mBirdUsing.end(); ++itBird)
	{
		delete *itBird;
	}

	mBirdUsing.clear();

	list<Bullet*>::iterator itBullet = mBullets.begin();

	for (; itBullet != mBullets.end(); ++itBullet)
	{
		delete *itBullet;
	}

	mBullets.clear();

	itBullet = mBulletUsing.begin();

	for (; itBullet != mBulletUsing.end(); ++itBullet)
	{
		delete *itBullet;
	}

	mBulletUsing.clear();

	CC_SAFE_RELEASE(mBirdNodes);
	CC_SAFE_RELEASE(mBirdNodeUsing);

	CC_SAFE_RELEASE(mBulletNodes);
	CC_SAFE_RELEASE(mBulletNodeUsing);
}

Bird* ObjectPool::createBird()
{
	//return new Bird();

	Bird* bird;
	if (mBirds.empty())
	{
		bird = new Bird;
	}
	else
	{
		bird = mBirds.front();
		mBirds.pop_front();
	}

	bird->reset();
	mBirdUsing.push_back(bird);
	return bird;
}

void ObjectPool::destoryBird(Bird* bird)
{
	if (bird == 0)
		return;

	bird->node_ = nullptr;
	bird->shadow_ = nullptr;
	bird->effect_ = nullptr;
	mBirds.push_back(bird);
	mBirdUsing.remove(bird);
	// 	if (mBirdUsing.size() > 300)
	// 	{
	// 		Bird * bird = mBirdUsing.front();
	// 		CCLOG("bird->id_ %d-- birdpool first point is x--%f, y--%f",bird->id_, bird->position_.x_, bird->position_.y_);
	// 	}
}


BirdNode* ObjectPool::createBirdNode(int type, bool isSpecail)
{
	CCArray* nodes = dynamic_cast<CCArray*>(mBirdNodes->objectForKey(type));
	BirdNode* node = 0;

	if (nodes == 0 || nodes->count() == 0)
	{
		if (!isSpecail)
			node = BirdNode::create(type);
		else
			node = SpecialBirdNode::create(type);
	}
	else if (!isSpecail) ///< 特殊的还是不走这里面了.
	{
		node = dynamic_cast<BirdNode*>(nodes->objectAtIndex(0));
		SpecialBirdNode * tnode = dynamic_cast<SpecialBirdNode *>(node);
		///< 节点是特殊鱼,那么重新创建.并删除它
		if (tnode)
		{
			nodes->removeObjectAtIndex(0, true);
			return createBirdNode(type, false);
		}
		nodes->removeObjectAtIndex(0, false);

	}
	else
	{
		node = SpecialBirdNode::create(type);
	}

	if (node)
	{
		node->setVisible(true);
		node->bird = 0;
		mBirdNodeUsing->addObject(node);
	}
	else
	{
		createBirdNode(type, isSpecail);
	}

	node->setTag(-1);
	return node;
}

void ObjectPool::destroyBirdNode(BirdNode* node)
{
	if (node == 0)
		return;

	int key = node->getType();
	CCArray* nodes = dynamic_cast<CCArray*>(mBirdNodes->objectForKey(key));

	if (nodes == 0)
	{
		nodes = CCArray::create();
		mBirdNodes->setObject(nodes, key);
	}

	node->birdMove = nullptr;
	nodes->addObject(node);
	mBirdNodeUsing->removeObject(node, false);
	node->bird = 0;
	node->autoCallBack();
	node->stopAllActions();

	node->removeFromParentAndCleanup(false);
}


Bullet* ObjectPool::createBullet()
{
	Bullet* bullet = 0;

	if (mBullets.empty())
	{
		bullet = new Bullet;
	}
	else
	{
		bullet = mBullets.front();
		mBullets.pop_front();
	}

	mBulletUsing.push_back(bullet);
	return bullet;
}

void ObjectPool::destoryBullet(Bullet* bullet)
{
	if (bullet == 0)
		return;

	bullet->shadow_ = nullptr;
	bullet->node_ = nullptr;
	mBullets.push_back(bullet);
	//CCLOG("delete bullet id is %d", bullet->id_);
	mBulletUsing.remove(bullet);
}

BulletNode* ObjectPool::createBulletNode(int chair_id, int type, bool isSpecail)
{

	int key = (chair_id + 1) * 10000 + type;

	CCArray* nodes = dynamic_cast<CCArray*>(mBulletNodes->objectForKey(key));
	BulletNode* node = 0;

	if (nodes == 0 || nodes->count() == 0)
	{
		if (!isSpecail)
			node = BulletNode::create(chair_id, type);
		else
			node = EnergyBulletNode::create(chair_id, type);
	}
	else if (!isSpecail) ///< 特殊的还是不走这里面了.
	{
		node = dynamic_cast<BulletNode*>(nodes->objectAtIndex(0));
		nodes->removeObjectAtIndex(0, false);
		EnergyBulletNode * sNode = dynamic_cast<EnergyBulletNode*>(node);

		if (sNode)
		{
			sNode->release();
			createBulletNode(chair_id, type, isSpecail);
		}
	}
	else
	{
		node = EnergyBulletNode::create(chair_id, type);
	}

	if (node)
	{
		mBulletNodeUsing->addObject(node);
	}
	node->setVisible(true);
	return node;
}

void ObjectPool::destoryBulletNode(BulletNode* node)
{
	if (node == 0)
		return;

	int key = (node->getChairID() + 1) * 10000 + node->getBulletType();

	CCArray* nodes = dynamic_cast<CCArray*>(mBulletNodes->objectForKey(key));

	if (nodes == 0)
	{
		nodes = CCArray::create();
		mBulletNodes->setObject(nodes, key);
	}

	nodes->addObject(node);
	mBulletNodeUsing->removeObject(node, false);

	node->stopAllActions();
	node->setVisible(false);
	node->removeFromParentAndCleanup(false);

}

bool ObjectPool::bulletCountAdd()
{
	if (mBulletCount < 40)
	{
		mBulletCount++;
		CCLOG("add --- now bullet count is %d", mBulletCount);
		return true;
	}

	return false;
}

bool ObjectPool::bulletCountSub()
{
	if (mBulletCount > 0)
	{
		mBulletCount--;
		CCLOG("sub --- now bullet count is %d", mBulletCount);
		return true;
	}

	return false;
}

int ObjectPool::getBulletCount()
{
	return mBulletCount;
}

bool ObjectPool::clearBulletCount()
{
	mBulletCount = 0;
	return true;
}

void ObjectPool::pauseBulletSend()
{
	mBulletCount += 40;
}

void ObjectPool::resumeBulletSend()
{
	mBulletCount -= 40;
}
