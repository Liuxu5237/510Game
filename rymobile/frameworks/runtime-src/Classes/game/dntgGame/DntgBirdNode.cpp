#include "DntgBirdNode.h"
#include "tools/manager/SpriteHelper.h"
#include "tools/tools/MTNotification.h"


USING_NS_CC;
using namespace Dntg;

BirdNode* BirdNode::create(int type)
{
	BirdNode* bird = new BirdNode();
	if (bird && bird->init(type))
	{
		bird->autorelease();
		return bird;
	}

	delete bird;
	return 0;
}

//////////////////////////////////////////////////////////////////////////
BirdNode::BirdNode() : birdMove(nullptr), _BirdSize(0, 0), pause_time(false)
{
	mLock[0] = false;
	mLock[2] = false;
	mLock[3] = false;
	mLock[4] = false;
	mLock[5] = false;
	mLock[1] = false;

	m_CurColor = this->getColor();
	m_bClickFish = false;
}

BirdNode::~BirdNode()
{
	pause_time = false;
	this->autoCallBack();
}

bool BirdNode::init(int type)
{
	do
	{
		///< 特殊情况,显示炮台锁定的鱼的
		if (type == -1)
		{
			CC_BREAK_IF(!CCSprite::init());
		}
		else if (type <= 19)
		{
			CC_BREAK_IF(!CCSprite::initWithSpriteFrameName("img_toumingdian_1.png"));
		}
		else
		{
			CC_BREAK_IF(!CCSprite::initWithSpriteFrameName("Bird20_01.png"));
		}

		mType = type;

		//CCAnimate* animate = SpriteHelper::createBirdAnimate(type);
		//CCSprite* spt = CCSprite::create();
		//this->addChild(spt);
		//spt->setTag(100);
		//this->runAction(CCRepeatForever::create(animate));
		return true;
	} while (0);

	return false;
}

int BirdNode::getType() const
{
	return mType;
}

void BirdNode::SetBitStatus()
{
	if (!m_bClickFish)
	{

		this->setColor(Color3B::RED);
		//bird->node_
		auto delayTime = DelayTime::create(0.25f);
		auto callFunc = CallFunc::create([=]()
		{
			this->setColor(Color3B(255,255,255));
			m_bClickFish = false;
		});
		m_bClickFish = true;

		auto sequence = Sequence::create(delayTime, callFunc, nullptr);
		this->runAction(sequence);
		

	}
	
	

}

void BirdNode::born(bool isShadow)
{
	this->stopAllActions();
	CCAnimate* animate = SpriteHelper::createBirdAnimate(mType);
	_BirdSize = animate->getAnimation()->getFrames().at(0)->getSpriteFrame()->getRect().size;
	this->runAction(RepeatForever::create(animate));

	int opacity = 0;

	if (isShadow)
	{
		setColor(ccc3(0, 0, 0));
		opacity = 100;
	}
	else
	{
		setColor(ccc3(255, 255, 255));
		opacity = 255;
	}

	setOpacity(0);
	this->runAction(CCFadeTo::create(1, opacity));
}


void BirdNode::death()
{
	this->stopAllActions();
	this->setTag(-1);
	if (birdMove)
	{
		birdMove->release();
	}
	birdMove = nullptr;

	CCAnimate* animate = SpriteHelper::createBirdDeadAnimate(mType);
	animate->setDuration(animate->getDuration() / 5);
	this->runAction(CCRepeatForever::create(animate));

}


void BirdNode::setRed()
{
	this->stopAllActions();
	CCAnimate* animate = SpriteHelper::createBirdAnimate(mType);
	this->runAction(CCRepeatForever::create(animate));

	setColor(ccc3(255, 0, 0));

	setOpacity(0);
	this->runAction(CCFadeTo::create(1, 255));
}

void BirdNode::setLock(bool isLock, int chair_id)
{
	mLock[chair_id] = isLock;
	if (isLock)
	{
		this->scheduleUpdate();
	}
	else
	{
		this->unscheduleUpdate();
	}
}

bool BirdNode::getLock(int chair_id) const
{
	return mLock[chair_id];
}

void BirdNode::autoCallBack()
{

	///< 发送一条消息给游戏界面, 告诉游戏界面绑定了这个鱼的椅子需要取消掉锁定
	unsigned int value = 0;

	for (int i = 0; i < 6; i++)
	{
		int tValue = mLock[i] ? 1 : 0;
		value += (tValue << i);
		mLock[i] = false;
	}
	if (value != 0)
	{
		G_NOTIFY_D("GAME_BIRD_LOCK_CANCEL", MTData::create(value, 2));
	}



}



void BirdNode::update(float delta)
{
	//	log("leftAchinod is %f, leftAchinod is %f, rightAchnod is %f, rightAchnod is %f", leftAchinod.x, leftAchinod.y, rightAchnod.x, rightAchnod.y);
	if (isOutWindow())
	{
		this->autoCallBack();
		this->unscheduleUpdate();
	}
}


bool BirdNode::isOutWindow()
{
	bool isVis = isVisible();
	if (!isVis)
	{
		return !isVis;
	}
	Size winSize = Director::getInstance()->getWinSize();
	Rect winRect = Rect(0, 0, winSize.width, winSize.height);
	Size birdSize = this->getContentSize();
	Vec2 leftAchinod = this->getPosition() - this->getAnchorPointInPoints();
	Vec2 rightAchnod = leftAchinod + birdSize;
	bool left_contact = winRect.containsPoint(leftAchinod);
	bool right_contact = winRect.containsPoint(rightAchnod);

	return !left_contact && !right_contact;
	//	return !isVis;
}


const Size BirdNode::getSize() const
{
	Size old_size = _BirdSize;
	old_size = Size(old_size.width * 0.75f, old_size.height * 0.75f);
	return old_size;
}

void BirdNode::pauseBird(bool p_t)
{
	pause_time = p_t;
}

void BirdNode::autoScale()
{

	Sprite::setScale(0.75f);
}

// void BirdNode::draw(cocos2d::Renderer *renderer, const cocos2d::Mat4 &transform, uint32_t flags)
// {
// 	Sprite::draw(renderer, transform, flags);
// 
// // 	glEnable(GL_LINE_SMOOTH);
// // 	glLineWidth(2);
// 
// 	CHECK_GL_ERROR_DEBUG();
// 	// 画4个点的正方形
// 	Vec2 now_p = this->getPosition();
// 	xSize bird_p = BIRD_SIZES[mType];
// 	
// 	CCPoint points[] = { now_p, ccp(now_p.x + bird_p.width_, now_p.y + bird_p.height_), ccp(now_p.x, now_p.y + bird_p.width_), ccp(now_p.x + bird_p.height_, now_p.y) };//四个点位置
// 	ccPointSize(80);
// 	ccDrawColor4B(0, 255, 255, 255);
// 	ccDrawPoints(points, 4);
// 
// }




SpecialBirdNode* SpecialBirdNode::create(int type)
{
	SpecialBirdNode* bird = new SpecialBirdNode();
	if (bird && bird->init(type))
	{
		bird->autorelease();
		return bird;
	}

	delete bird;
	return 0;
}

bool SpecialBirdNode::init(int type)
{
	return BirdNode::init(type);

}

void SpecialBirdNode::born(bool isShadow)
{
	this->stopAllActions();
	///< 清理容器
	for (size_t i = 0; i < mBirdList.size(); i++)
	{
		mBirdList[i]->removeFromParentAndCleanup(true);
	}
	mBirdList.clear();

	for (int i = 0; i < mBirdNum; i++)
	{
		Sprite * bird = Sprite::create();

		//log("born pos is %f, %f", bird_pos.x, bird_pos.y);

		mBirdList.push_back(bird);
		CCAnimate* animate = SpriteHelper::createBirdAnimate(mType);
		bird->runAction(CCRepeatForever::create(animate));

		Vec2 father_pos = this->getAnchorPointInPoints();
		Vec2 bird_pos = father_pos + getBirdPostion(i);
		bird->setPosition(bird_pos);
		this->addChild(bird);
		
		int opacity = 0;

		if (isShadow)
		{
			bird->setColor(ccc3(0, 0, 0));
			opacity = 100;
		}
		else
		{
			bird->setColor(ccc3(255, 255, 255));
			opacity = 255;
		}

		bird->setOpacity(0);
		bird->runAction(CCFadeTo::create(1, opacity));
	}


}

cocos2d::Vec2 SpecialBirdNode::getBirdPostion(int bird_rank)
{
	///< 鱼的数量
	Vec2 now_p(0, 0);
	float angle = 0;
	float radian;
	float length = 95;
	if (mBirdNum == 1)
	{
		return now_p;
	}
	else if (mBirdNum == 2)
	{
		angle = 180 * bird_rank;
		length = 80;
	}
	else if (mBirdNum == 3)
	{
		angle = 120 * bird_rank;
		length = 85;
	}
	else if (mBirdNum == 4)
	{
		angle = 90 * bird_rank;
	}
	else if (mBirdNum == 5 && bird_rank != 4)
	{
		angle = 90 * bird_rank;
	}
	else if (mBirdNum == 5 && bird_rank == 4)
	{
		return now_p;
	}


	radian = CC_DEGREES_TO_RADIANS(angle);
	now_p.x = length * cos(radian);
	now_p.y = length * sin(radian);

	return now_p;
}

SpecialBirdNode::SpecialBirdNode() : mBirdNum(0)
{

}

void SpecialBirdNode::setEffect(cocos2d::Sprite * father, cocos2d::Animate * animate)
{
	///< 不是阴影加特效
	for (int i = 0; i < mBirdNum; i++)
	{
		Sprite * effect_bird = Sprite::create();
		//Sprite * bird_ = mBirdList[i];
		Vec2 bird_pos = getBirdPostion(i);
		//log("effect pos is %f, %f", bird_pos.x, bird_pos.y);
		Vec2 father_pos = father->getAnchorPointInPoints();
		Vec2 end_p = bird_pos + father_pos;
		effect_bird->setPosition(end_p);
		father->addChild(effect_bird, 0);

		CCAnimate* new_animate = animate->clone();
		effect_bird->runAction(CCRepeatForever::create(new_animate));
	}

}

SpecialBirdNode::~SpecialBirdNode()
{

}

//嗯哼 就是要你自己膨胀吧
void SpecialBirdNode::SetPanZiScale()
{
	for (size_t i = 0; i < mBirdList.size(); i++)
	{
		auto FishYuan = mBirdList[i];
		if (FishYuan != nullptr)
		{
			float CurFish = FishYuan->getScale();
			FishYuan->setScale(CurFish*1.25);
		}
	}
}
void SpecialBirdNode::SetBitStatus()
{
	BirdNode::SetBitStatus();

	this->setColor(Color3B::RED);
	///< 清理容器
	for (size_t i = 0; i < mBirdList.size(); i++)
	{
		auto FishYuan = mBirdList[i];
		if (FishYuan != nullptr)
		{

				FishYuan->setColor(Color3B::RED);
				//bird->node_
				auto delayTime = DelayTime::create(0.25f);
				auto callFunc = CallFunc::create([=]()
				{
					FishYuan->setColor(Color3B(255, 255, 255));
					this->setColor(Color3B(255, 255, 255));
				});

				auto sequence = Sequence::create(delayTime, callFunc, nullptr);
				this->runAction(sequence);


		}
	}



}

void SpecialBirdNode::death()
{
	this->setTag(-1);
	this->stopAllActions();
	if (birdMove)
	{
		birdMove->release();
	}
	birdMove = nullptr;
	///< 清理容器
	for (size_t i = 0; i < mBirdList.size(); i++)
	{
		mBirdList[i]->removeFromParentAndCleanup(true);
	}
	mBirdList.clear();

	for (int i = 0; i < mBirdNum; i++)
	{
		Sprite * bird = Sprite::create();

		//log("born pos is %f, %f", bird_pos.x, bird_pos.y);

		mBirdList.push_back(bird);
		CCAnimate* animate = SpriteHelper::createBirdDeadAnimate(mType);
		animate->setDuration(animate->getDuration() / 2);

		bird->runAction(CCRepeatForever::create(animate));

		Vec2 father_pos = this->getAnchorPointInPoints();
		Vec2 bird_pos = father_pos + getBirdPostion(i);
		bird->setPosition(bird_pos);
		this->addChild(bird);

	}
}
