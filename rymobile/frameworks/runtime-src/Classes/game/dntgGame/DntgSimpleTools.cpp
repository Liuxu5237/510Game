#include "DntgSimpleTools.h"
#include "platform/PlatformHeader.h"
#include "tools/manager/SpriteHelper.h"
#include "DntgBirdDefine.h"
#include "DntgCMD_CatchBird.h"

using namespace Dntg;



cocos2d::CCActionInterval * SimpleTools::getCircularAction(const Vec2 & start_pos, float radius)
{
	///< 创建样条插值运动
	CCPointArray * array = CCPointArray::create(20);
	Vec2 base_pos = start_pos;
	/*array->addControlPoint(base_pos + Vec2(0, 0));*/
	array->addControlPoint(base_pos + Vec2(radius, 0));
	float x_ = CC_DEGREES_TO_RADIANS(45);
	array->addControlPoint(base_pos + Vec2(radius * cos(x_), radius * sin(x_)));
	array->addControlPoint(base_pos + Vec2(0, radius));
	x_ = CC_DEGREES_TO_RADIANS(135);
	array->addControlPoint(base_pos + Vec2(radius * cos(x_), radius * sin(x_)));
	array->addControlPoint(base_pos + Vec2(-radius, 0));
	x_ = CC_DEGREES_TO_RADIANS(225);
	array->addControlPoint(base_pos + Vec2(radius * cos(x_), radius * sin(x_)));
	array->addControlPoint(base_pos + Vec2(0, -radius));
	x_ = CC_DEGREES_TO_RADIANS(315);
	array->addControlPoint(base_pos + Vec2(radius * cos(x_), radius * sin(x_)));
	array->addControlPoint(base_pos + Vec2(radius, 0));
	CCActionInterval  * CardinalSplineTo = CCCardinalSplineTo::create(2, array, 0);
	CCFiniteTimeAction*seq = CCSequence::create(CardinalSplineTo, NULL);
	CCActionInterval * repeatForever = CCRepeatForever::create((CCActionInterval*)seq);

	return repeatForever;
}


///< 服务闪电线Action
const char * getNameByLineType(LINETYPE sType)
{

	int random_value =rand();
	switch (sType)
	{
	case PINK:
		return "PinkLine";
		break;
	case BLUE:
		return "BlueLine";
		break;
	case YELLOW:
		return "YellowLine";
		break;
	case ALLTYPE:
		random_value = random_value % 3;
		return getNameByLineType(LINETYPE(random_value));
	default:
		break;
	}
	return "PinkLine";
}

cocos2d::Sprite * SimpleTools::getLightAction(float duration, const Vec2 & base_pos, std::vector<Vec2> other_pos, LINETYPE sType)
{

	Sprite * fatherSprite = Sprite::create();
	for (int i = 0; i < (int)other_pos.size(); i++)
	{
		const char * name = getNameByLineType(sType);
		Sprite * show_text = Sprite::create();
		show_text->setAnchorPoint(Vec2(0, 0.5f));
		show_text->setPosition(base_pos);
		Animate * animate = SpriteHelper::createAnimate(name);
		show_text->runAction(RepeatForever::create(animate));
		show_text->setScale(0.01f);
		Vec2 tOther = other_pos[i];
		Vec2 now_p = ccpSub(tOther, base_pos);
		float angle = ccpToAngle(now_p);
		float degrees = 360 - CC_RADIANS_TO_DEGREES(angle);
		show_text->setRotation(degrees);
		Rect tsize = animate->getAnimation()->getFrames().at(0)->getSpriteFrame()->getRect();

		float distance = now_p.getLength();
		///< 计算X轴缩放率
		float xScale = distance / tsize.size.width;
		///< 计算Y轴缩放率
		float yScale = /*0.1 + distance / 100 / 10*/1;
		//	log("yScale is %f", yScale);
		ScaleTo * s_to = ScaleTo::create(duration, xScale, yScale);
		show_text->runAction(CCEaseSineOut::create(s_to));
		fatherSprite->addChild(show_text);
	}
	// 	Sprite * show_text = Sprite::create();
	// 	show_text->setAnchorPoint(Vec2(0, 0.5f));
	// 	show_text->setPosition(base_pos);
	// 	show_text->runAction(RepeatForever::create(SpriteHelper::createAnimate("PinkLine")));
	// 	show_text->setScale(0.1f);
	// 	ScaleTo * s_to = ScaleTo::create(2, 2, 1);
	// 	show_text->runAction(s_to);
	// 	show_text->setPosition(Vec2(400, 400));

	return fatherSprite;
}


bool SimpleTools::isDntgSpecialBird(int birdType)
{
	switch (birdType)
	{
	case BIRD_TYPE_CHAIN:
	case BIRD_TYPE_RED:
	case BIRD_TYPE_ONE:
	case BIRD_TYPE_TWO:
	case BIRD_TYPE_THREE:
	case BIRD_TYPE_FOUR:
	case BIRD_TYPE_FIVE:
	case BIRD_TYPE_INGOT:
		return true;
		break;
	default:
		return false;
		break;
	}
}

bool SimpleTools::isDntgSpecialRoundBird(int birdType)
{
	switch (birdType)
	{
	case BIRD_TYPE_ONE:
	case BIRD_TYPE_TWO:
	case BIRD_TYPE_THREE:
	case BIRD_TYPE_FOUR:
	case BIRD_TYPE_FIVE:
		return true;
		break;
	default:
		return false;
		break;
	}
}

bool SimpleTools::isDntgNeedGoStraightBird(int birdType)
{
	switch (birdType)
	{
	case BIRD_TYPE_23:
	case BIRD_TYPE_24:
	case BIRD_TYPE_26:
	case BIRD_TYPE_27:
	case BIRD_TYPE_28:
	case BIRD_TYPE_29:
		return true;
		break;
	default:
		return false;
		break;
	}
}

bool SimpleTools::isDntgReverseAtGoStraightBird(const Vec2 & start_p, const Vec2 & end_p)
{
	Vec2 result_p = end_p - start_p;
	if (result_p.x >= 0.0f)
	{
		return false;
	}
	else if (result_p.x < 0.0f)
	{
		return true;
	}

	return true;
}

bool SimpleTools::isDntgDragonKing(int birdType)
{
	return false;
}

float SimpleTools::calcRotate(int char_id, const xPoint& pt_offset)
{
	float rorate = 0.0f;
	xPoint pt_bow = xPoint(Dntg::CANNON_POSITION[char_id][0], Dntg::CANNON_POSITION[char_id][1]);
	xPoint pt_rorate;

	if (char_id == 0 || char_id == 1 || char_id == 2)
	{
		pt_rorate = pt_offset - pt_bow;

		if (pt_rorate.y_ >= 0)
		{
			rorate = std::atan2(pt_rorate.y_, pt_rorate.x_) + M_PI_2;
		}
		else
		{
			if (pt_rorate.x_ >= 0)
				rorate = (float)M_PI_2;
			else
				rorate = (float)(M_PI_2 + M_PI);
		}
	}
	else if (char_id == 3 || char_id == 4 || char_id == 5)
	{
		pt_rorate = pt_offset - pt_bow;

		if (pt_rorate.y_ <= 0)
		{
			rorate = std::atan2(pt_rorate.y_, pt_rorate.x_) + M_PI_2;
		}
		else
		{
			if (pt_rorate.x_ >= 0)
				rorate = (float)M_PI_2;
			else
				rorate = (float)(M_PI_2 + M_PI);
		}
	}

	return rorate;
}
