#include "tools/manager/SpriteHelper.h"
#include "DntgBulletNode.h"

using namespace Dntg;

BulletNode* BulletNode::create(int chair_id, int bullet_type, int bird_id)
{
	BulletNode* bird = new BulletNode();
	if (bird && bird->init(chair_id, bullet_type, bird_id))
	{
		bird->autorelease();
		return bird;
	}

	delete bird;
	return 0;
}

//////////////////////////////////////////////////////////////////////////
BulletNode::BulletNode()
{

}

BulletNode::~BulletNode()
{
}
bool BulletNode::init(int chair_id, int bullet_type, int bird_id)
{
	do
	{
		mChairId = chair_id;
		mBulletType = bullet_type;
		mNetType = 0;
		mBirdId = bird_id;
		char name[64] = { 0 };

		sprintf(name, "Bullet%d_%02d.png", bullet_type, 1);
		return initWithSpriteFrameName(name);
	} while (0);

	return false;
}

void BulletNode::born(bool isShadow)
{
	if (isShadow)
	{
		setColor(ccc3(0, 0, 0));
		setOpacity(100);
	}
	else
	{
		setColor(ccc3(255, 255, 255));
		setOpacity(255);
	}
}

////////////////////////////////////////////////////////////////////////////////////////
EnergyBulletNode * EnergyBulletNode::create(int chair_id, int bullet_type, int bird_id /*= -1*/)
{
	EnergyBulletNode* bird = new EnergyBulletNode();
	if (bird && bird->init(chair_id, bullet_type, bird_id))
	{
		bird->autorelease();
		return bird;
	}

	delete bird;
	return 0;
}

bool EnergyBulletNode::init(int chair_id, int bullet_type, int bird_id)
{
	do
	{
		mChairId = chair_id;
		mBulletType = bullet_type;
		mNetType = 0;
		mBirdId = bird_id;

		//Sprite * laserHead = Sprite::createWithSpriteFrameName("laserHead.png");
		//this->addChild(laserHead);

		laser = ui::Scale9Sprite::createWithSpriteFrameName("Laser.png");
		laser->setContentSize(Size(114, 900));
		this->setPosition(Vec2(0, 168));
		this->addChild(laser);
		// 		char name[64] = { 0 };
		// 
		// 		sprintf(name, "Bullet%d_%02d.png", bullet_type, 1);
		return initWithSpriteFrameName("laserHead.png");
	} while (0);

	return false;
}

void EnergyBulletNode::setRotation(float rotation)
{
	BulletNode::setRotation(rotation);

	laser->setRotation(rotation);
}
