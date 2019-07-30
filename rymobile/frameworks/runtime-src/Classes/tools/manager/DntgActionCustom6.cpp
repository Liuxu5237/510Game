 //#include "ViewHeader.h"
#include "game/dntgGame/DntgBirdNode.h"
#include "DntgActionCustom6.h"
#include "game/dntgGame/DntgSimpleTools.h"
#include "game/dntgGame/DntgBird.h"
#include "game/dntgGame/DntgGameHeader.h"
#include "game/dntgGame/DntgCMD_CatchBird.h"

#include <tinyxml2/tinyxml2.h>
#include <json/rapidjson.h>
#include <json/document.h>
#include <json/stringbuffer.h>
#include <json/prettywriter.h>
#include <unistd.h>

USING_NS_CC;
using namespace Dntg;
/////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////

Action_Move_Point6* Action_Move_Point6::create(float d, std::string points, std::string offse)
{
	Action_Move_Point6* act = new Action_Move_Point6();
	if (act && act->init(d, points, offse))
	{
		act->autorelease();
		return act;
	}

	delete act;
	return 0;
}

bool Action_Move_Point6::init(float d, std::string points, std::string offset)
{
    //log("%s", points.c_str());
    //log("%s", offset.c_str());
    
    std::string data = points;
    rapidjson::Document doc;
    
    doc.Parse<rapidjson::kParseDefaultFlags>(data.c_str());
    
    if (doc.HasParseError()) {
        log("sss");
    }
    
    rapidjson::Value& arry1 =  doc[0];
    //log("%s",arry1["_positionX"].GetString());
    //log( "%d",doc.Size());
    
    auto s1 =offset.find("(",0);
    auto s2 = offset.find(",",0);
    auto s3 = offset.find(")",0);
//    log("%s",offset.substr(s1+1,s2-1).c_str());
//    log("%s",offset.substr(s2+1,s3-5).c_str());
    
    auto x1 = atof(offset.substr(s1+1,s2).c_str());
    auto y1 = atof(offset.substr(s2+1,s3-1).c_str());
    xPoint offest_ =xPoint(x1, y1);
    
    for (int i = 0 ; i< doc.Size() ; i++)
    {
        rapidjson::Value& arry1 =  doc[i];
        
        float x = atof(arry1["_positionX"].GetString());
        float y = atof(arry1["_positionY"].GetString());
        double angle =atof(arry1["_angle"].GetString());
        xPoint pos = xPoint(x, y);
        Move_Point move_point = Move_Point(pos, angle);
        
        if (offest_.x_ != 0 || offest_.y_ != 0 )
        {
            move_point.position_  += offest_;
            move_points_.push_back(move_point);
        }
        else
        {
            move_points_.push_back(move_point);
        }
        
    }
    
	setDuration(d*move_points_.size());
	return true;
}



void Action_Move_Point6::update(float time)
{
	_elapsed = time * _duration;
	///< 3. 在进行计算.
	//log("node id is %d,now time is %f, _elapsed is %f", 0, time, _elapsed);
	//Action_Base_Bird_Move::update(time);
	//_elapsed += time;
	//_bird_move = time * _duration;
	float fDiff;
	float fIndex = time * move_points_.size();
	int index = fIndex;

	fDiff = fIndex - index;

	if (index >= (int)move_points_.size())
	{
		index = move_points_.size() - 1;
	}

	Move_Point move_point;

	if (index<(int)move_points_.size() - 1)
	{
		Move_Point move_point1 = move_points_.at(index);
		Move_Point move_point2 = move_points_.at(index + 1);

		move_point.position_ = move_point1.position_*(1.0f - fDiff) + move_point2.position_*fDiff;
		move_point.angle_ = move_point1.angle_*(1.0f - fDiff) + move_point2.angle_*fDiff;

		if (std::abs(move_point1.angle_ - move_point2.angle_) > 180.0)
		{
			move_point.angle_ = move_point1.angle_;
		}
	}
	else
	{
		move_point = move_points_.at(index);
	}

    Node* node  = (Node*)_target;
//	Bird *bird = ((BirdNode*)_target)->bird;
//	BirdNode* spr_shadow = (BirdNode*)bird->shadow_;
//	BirdNode* spr_effect = (BirdNode*)bird->effect_;

	float angle = 90 - move_point.angle_;

//	if (bird->item_ != -1 && !SimpleTools::isDntgSpecialBird(bird->type_))
//	{
//		switch (bird->item_)
//		{
//		case BIRD_ITEM_SPECIAL_SMALL_PURSE:
//		case BIRD_ITEM_SPECIAL_MIDDLE_PURSE:
//		case BIRD_ITEM_SPECIAL_BIG_PURSE:
//		case BIRD_ITEM_SPECIAL_GOLDX2:
//		case BIRD_ITEM_SPECIAL_LUCKY:
			//angle = 0;
//			break;
//		}
//	}

	bool dragon_value = SimpleTools::isDntgReverseAtGoStraightBird(_target->getPosition(), toCCP(move_point.position_));
	_target->setPosition(toCCP(move_point.position_));
    //_target->setPosition(cocos2d::Vec2(move_point.position_.x_,  move_point.position_.y_));

	// PLAZZ_PRINTF("Action_Move_Point::update  m_pTarget->setPosition x == %.0f  y == %.0f ", toCCP(move_point.position_).x, toCCP(move_point.position_).y);

	//m_pTarget->setPosition(move_point.position_.x_, move_point.position_.y_);
    
//	if (!SimpleTools::isDntgNeedGoStraightBird(bird->type_))
		_target->setRotation(angle);
//	else
//	{
		//_target->setRotation(180);
		//dynamic_cast<Sprite *>(_target)->setFlippedX(dragon_value);
	//}


//	if (spr_shadow)
//	{
//		spr_shadow->setPosition(toCCP(move_point.position_.x_ + 20, move_point.position_.y_ + 20));
//		if (!SimpleTools::isDntgNeedGoStraightBird(bird->type_))
//			spr_shadow->setRotation(_target->getRotation());
//		else
//		{
//			spr_shadow->setRotation(180);
//			dynamic_cast<Sprite *>(spr_shadow)->setFlippedX(dragon_value);
//		}
//
//	}
//
//	if (spr_effect)
//	{
//		if (bird->type_ == BIRD_TYPE_INGOT)
//		{
//			Size bird_size = spr_shadow->getSize();
//			Vec2 bird_pos = _target->getPosition();
//			float angle = _target->getRotation();
//			bool big_angle = angle > 180 || angle < -180 ? true : false;
//			angle = angle > 180 ? angle - 180 : angle < -180 ? angle + 180 : angle;
//			angle = -angle;
//			float dregress = CC_DEGREES_TO_RADIANS(angle);
//
//			Vec2 effect_pos;
//			if (big_angle)
//			{
//				effect_pos = Vec2(bird_pos.x - 30 * cos(dregress), bird_pos.y - 30 * sin(dregress));
//			}
//			else
//			{
//				effect_pos = Vec2(bird_pos.x + 30 * cos(dregress), bird_pos.y + 30 * sin(dregress));
//			}
//			spr_effect->setPosition(effect_pos);
//			// 			if (dragon_value)
//			// 				spr_effect->setRotation(_target->getRotation() - 90);
//			// 			else
//			spr_effect->setRotation(_target->getRotation() + 90);
//		}
//		else if (!SimpleTools::isDntgSpecialRoundBird(bird->type_))
//		{
//			spr_effect->setPosition(_target->getPosition());
//			spr_effect->setRotation(spr_effect->getRotation() + 1);
//		}
//		else
//		{
//			spr_effect->setRotation(angle);
//			Vec2 now_p_1 = _target->getPosition();
//
//			spr_effect->setPosition(now_p_1);
//			auto nodes = spr_effect->getChildren();
//			for (int i = 0; i < nodes.size(); i++)
//			{
//				Node * node = nodes.at(i);
//				node->setRotation(node->getRotation() + 1);
//			}
//		}
//	}

	if (_target)
	{
		if (_elapsed >= _duration)
		{
			//CCLOG("bird id is %d", bird->id_);
			_target->setVisible(false);
		}
		else
		{
			_target->setVisible(true);
		}
	}

	//log("tims is %f, pos is %f, %f", time, _target->getPositionX(), _target->getPositionY());
}

xPoint Action_Move_Point6::BirdMoveTo(float elapsed)
{
	float time = std::min(1.0f, (_elapsed + elapsed) / _duration);
	if (time < 0) time = 1.0f;
	float fDiff; ///< 可能产生的偏移
	float fIndex = time * move_points_.size();
	int index = fIndex;

	fDiff = fIndex - index;

	if (index >= (int)move_points_.size())
	{
		index = move_points_.size() - 1;
	}

	Move_Point move_point;

	if (index<(int)move_points_.size() - 1)
	{
		Move_Point move_point1 = move_points_.at(index);
		Move_Point move_point2 = move_points_.at(index + 1);

		move_point.position_ = move_point1.position_*(1.0f - fDiff) + move_point2.position_*fDiff;

	}
	else
	{
		move_point = move_points_.at(index);
	}
	Vec2 target_pos = toCCP(move_point.getPostion());
	//log("BirdMoveTo tims is %f, pos is %f, %f", time, target_pos.x, target_pos.y);
	return move_point.getPostion();
}



///////////////////////////////////////////////////////////////////////////
Action_Bullet_Move6 * Action_Bullet_Move6::create(float angle, float speed)
{
	Action_Bullet_Move6* act = new Action_Bullet_Move6();
	if (act && act->init(angle, speed))
	{
		act->autorelease();
		return act;
	}

	delete act;
	return 0;
}

bool Action_Bullet_Move6::init(float angle, float speed)
{
	ActionInterval::initWithDuration(100);
	angle_ = angle;
	bullet_speed_ = speed;
	dx_ = std::cos(angle_ - M_PI_2);
	dy_ = std::sin(angle_ - M_PI_2);
	return true;
}

void Action_Bullet_Move6::step(float dt)
{
	//	ActionInterval::step(dt);
	///< 这个是原版内容
	if (_firstTick)
	{
		_firstTick = false;
		_elapsed = 0;
	}
	else
	{
		_elapsed += dt;
	}

	if (_target)
	{
		xPoint pt(toNetPoint(_target->getPosition()));

		pt.x_ += bullet_speed_ * dx_ * dt;
		pt.y_ += bullet_speed_ * dy_ * dt;

		if (pt.x_ < 0.0f) { pt.x_ = 0 + (0 - pt.x_); dx_ = -dx_; angle_ = -angle_; }
		if (pt.x_ > kGameRevolutionWidth)  { pt.x_ = kGameRevolutionWidth - (pt.x_ - kGameRevolutionWidth); dx_ = -dx_; angle_ = -angle_; }

		if (pt.y_ < 0.0f) { pt.y_ = 0 + (0 - pt.y_); dy_ = -dy_; angle_ = M_PI - angle_; }
		if (pt.y_ > kGameRevolutionHeight)  { pt.y_ = kGameRevolutionHeight - (pt.y_ - kGameRevolutionHeight); dy_ = -dy_; angle_ = M_PI - angle_; }

		//log("old angle is %f", angle_);
		_target->setPosition(toCCP(pt));
		//log("point x = %f,point y = %f, time is %f", pt.x_, pt.y_, dt);
		_target->setRotation((angle_ - M_PI_2) * 180 / M_PI);
	}
	else
	{
		log("tagget is no nonentity");
	}

	if (_target)
	{
		if (_elapsed >= _duration)
		{
			_target->setVisible(false);
		}
		else
		{
			_target->setVisible(true);
		}
	}

}

void Action_Bullet_Move6::startWithTarget(Node *target)
{
	ActionInterval::startWithTarget(target);
}



////////////////////////////////////////////////////////////////////////////////////////////
Action_Bullet_Move_To6 * Action_Bullet_Move_To6::create(const xPoint & start, const xPoint & end, float angle, float speed)
{
	Action_Bullet_Move_To6* act = new Action_Bullet_Move_To6();
	if (act && act->init(start, end, angle, speed))
	{
		act->autorelease();
		return act;
	}

	delete act;
	return 0;
}

bool Action_Bullet_Move_To6::init(const xPoint & start, const xPoint & end, float angle, float speed)
{
	Action_Bullet_Move6::init(angle, speed);
	angle_ = angle;
	bullet_speed_ = speed;
	start_ = start;

	delta_ = end - start;
	float length = std::sqrt(delta_.x_ * delta_.x_ + delta_.y_ * delta_.y_);
	_length = length;
	_duration = 100;
	_Bduration = length / bullet_speed_;

	// 	log("target postion is %f, %f. angle is %f, maxlength is %f", start.x_, start.y_, angle_, _length);
	// 
	// 	log("target postion is %f, %f. angle is %f, maxlength is %f", end.x_, end.y_, angle_, _length);

	return true;
}

// void Action_Bullet_Move_To::update(float dt)
// {
// 	///< 计算时间
// 	float time = dt * _duration;
// 	//static float _preTime = dt;
// 	if (time <= _Bduration/* && !isAutoMove*/)
// 	{		
// 		xPoint pt;
// 
// 		pt.x_ = start_.x_ + delta_.x_ * (time);
// 		pt.y_ = start_.y_ + delta_.y_ * (time);
// 
// 		//log("old angle is %f", angle_);
// 		_target->setPosition(toCCP(pt));
// 		//log("point x = %f,point y = %f, time is %f", pt.x_, pt.y_, dt);
// 		//log("Line is %d ----point x = %f,point y = %f, time is %f",count, pt.x_, pt.y_, dt);
// 		_target->setRotation((angle_ - M_PI_2) * 180 / M_PI);
// 	}
// 	else
// 	{
// 
// 	}
// 
// }

void Action_Bullet_Move_To6::step(float dt)
{
	///< 这个是原版内容
	if (_firstTick)
	{
		_firstTick = false;
		_elapsed = 0;
	}
	else
	{
		_elapsed += dt;
	}

	float time = _elapsed;
	//static float _preTime = dt;
	if (_target && time <= _Bduration/* && !isAutoMove*/)
	{
		xPoint pt;
		///<  求百分比
		float precent = time / _Bduration;
		///< 求现在因走的距离
		float now_length = precent * _length;
		///< 现在应到的位置
		pt.x_ = start_.x_ + now_length * dx_;
		pt.y_ = start_.y_ + now_length * dy_;

		// 		time =MIN(1, _elapsed /
		// 			MAX(_duration, FLT_EPSILON)   // division by 0
		// 			);


		// 		pt.x_ = start_.x_ + delta_.x_ * (time);
		// 		pt.y_ = start_.y_ + delta_.y_ * (time);
		_target->setPosition(toCCP(pt));
		_target->setRotation((angle_ - M_PI_2) * 180 / M_PI);
	}
	else
	{
		Action_Bullet_Move6::step(dt);
	}
}

/*
void Action_Bullet_Move_To::step(float dt)
{
if (_firstTick)
{
_firstTick = false;
_elapsed = 0;
}
else
{
_elapsed += dt;
}

if (_elapsed < _Bduration)
{
this->update(MAX(0,                                  // needed for rewind. elapsed could be negative
MIN(1, _elapsed /
MAX(_duration, FLT_EPSILON)   // division by 0
)
)
);
return;
}
else
{
Action_Bullet_Move::step(dt);
}
}
*/





////////////////////////////////////////////////////////////////////////////////////////////
static float CalculateRotateAngle(xPoint pntBegin, xPoint pntNext)
{
	float dRotateAngle = atan2(fabs((float)pntBegin.x_ - pntNext.x_), fabs((float)pntBegin.y_ - pntNext.y_));

	//如果下一点的横坐标大于前一点(在第一和第四象限)
	if (pntNext.x_ >= pntBegin.x_)
	{
		if (pntNext.y_ >= pntBegin.y_)
			//不做任何处理
		{
			dRotateAngle = M_PI - dRotateAngle;
		}
	}
	else
	{
		//第二象限
		if (pntNext.y_ >= pntBegin.y_)
			dRotateAngle = M_PI + dRotateAngle;
		else//第三象限
			dRotateAngle = 2 * M_PI - dRotateAngle;
	}
	dRotateAngle = dRotateAngle * 180 / M_PI +90;
	return dRotateAngle;
}

void Action_Bird_Move6::move_angle()
{
	float temp_value = 0.f;
	temp_value = CalculateRotateAngle(m_ptCurrent, m_ptLast);

	_target->setRotation(temp_value);

//	Bird *bird = ((BirdNode*)_target)->bird;
//	BirdNode* spr_shadow = (BirdNode*)bird->shadow_;
//	BirdNode* spr_effect = (BirdNode*)bird->effect_;
//	if (spr_shadow)
//	{
//		spr_shadow->setRotation(_target->getRotation());
//	}
//
//	if (spr_effect)
//	{
//		spr_effect->setRotation(_target->getRotation());
//	}

	//bool dragon_value = SimpleTools::isDntgReverseAtGoStraightBird(_target->getPosition(), toCCP(m_ptLast));

	//if (!SimpleTools::isDntgNeedGoStraightBird(bird->type_))
	//	_target->setRotation(temp_value);
	//else
	//{
		//target->setRotation(180);
		//dynamic_cast<Sprite *>(_target)->setFlippedX(!dragon_value);
	//}


//	if (spr_shadow)
//	{
//		if (!SimpleTools::isDntgNeedGoStraightBird(bird->type_))
//			spr_shadow->setRotation(_target->getRotation());
//		else
//		{
//			spr_shadow->setRotation(180);
//			dynamic_cast<Sprite *>(spr_shadow)->setFlippedX(!dragon_value);
//		}
//
//	}
}

////////////////////////////////////////////////////////////////////////////////////////////
Action_Bird_Round_Move6* Action_Bird_Round_Move6::create(std::string center, float radius, float rotate_duration, float start_angle, float rotate_angle, float move_duration, float bird_speed, bool is_centre_bird)
{
	Action_Bird_Round_Move6* act = new Action_Bird_Round_Move6();
	if (act && act->init(center, radius, rotate_duration, start_angle, rotate_angle, move_duration, bird_speed, is_centre_bird))
	{
		act->autorelease();
		return act;
	}

	delete act;
	return 0;
}

bool Action_Bird_Round_Move6::init(std::string center, float radius, float rotate_duration, float start_angle, float rotate_angle, float move_duration, float bird_speed, bool is_centre_bird)
{
    
    auto s1 =center.find("(",0);
    auto s2 = center.find(",",0);
    auto s3 = center.find(")",0);
    auto x1 = atof(center.substr(s1+1,s2).c_str());
    auto y1 = atof(center.substr(s2+1,s3-1).c_str());
    xPoint center1 =xPoint(x1, y1);
    
	center_ = center1;
	radius_ = radius;
	rotate_duration_ = rotate_duration;
	start_angle_ = start_angle;
	move_duration_ = move_duration;
	bird_speed_ = bird_speed;
	stage_ = 0;
	angle_ = M_PI_2 + start_angle_;
	_duration = rotate_duration + move_duration;
	rotate_angle_ = rotate_angle;
	is_centre_bird_ = is_centre_bird;

	return true;
}

void Action_Bird_Round_Move6::update(float time)
{
	_elapsed = time * _duration;

	if (stage_ == 0 && time * _duration >= rotate_duration_)
	{
		//散开
		stage_ = 1;
		delta_.x_ = std::cos(angle_);
		delta_.y_ = std::sin(angle_);
	}

	if (stage_ == 0)
	{
		//位置
		float angle = start_angle_ + rotate_angle_ * time;
		xPoint pt;
		pt.x_ = center_.x_ + radius_ * std::cos(angle);
		pt.y_ = center_.y_ + radius_ * std::sin(angle);
		_target->setPosition(toCCP(pt));

//		//阴影特效
//		Bird *bird = ((BirdNode*)_target)->bird;
//		BirdNode* spr_shadow = (BirdNode*)bird->shadow_;
//		BirdNode* spr_effect = (BirdNode*)bird->effect_;
//		if (spr_shadow)
//		{
//			spr_shadow->setPosition(toCCP(pt.x_ + 20, pt.y_ + 20));
//		}
//		if (spr_effect)
//		{
//			spr_effect->setPosition(_target->getPosition());
//			spr_effect->setRotation(spr_effect->getRotation() + 1);
//		}

		//角度
		m_ptCurrent = pt;
		if (is_centre_bird_)
		{
			_target->setRotation(angle * 180 / M_PI);
//			if (spr_shadow)
//				spr_shadow->setRotation(_target->getRotation());
//			if (spr_effect)
//			{
//				spr_effect->setPosition(_target->getPosition());
//				spr_effect->setRotation(spr_effect->getRotation() + 1);
//			}
		}
		else
			move_angle();
		m_ptLast = pt;
	}
	else
	{
		//散开
		xPoint pt(toNetPoint(_target->getPosition()));
		pt.x_ += bird_speed_ * (time / 4) * delta_.x_;
		pt.y_ += bird_speed_ * (time / 4) * delta_.y_;
		_target->setPosition(toCCP(pt));

//		Bird *bird = ((BirdNode*)_target)->bird;
//		BirdNode* spr_shadow = (BirdNode*)bird->shadow_;
//		BirdNode* spr_effect = (BirdNode*)bird->effect_;
//		if (spr_shadow)
//			spr_shadow->setPosition(toCCP(pt.x_ + 20, pt.y_ + 20));
//
//		if (spr_effect)
//		{
//			spr_effect->setPosition(_target->getPosition());
//			spr_effect->setRotation(spr_effect->getRotation() + 1);
//		}

		m_ptCurrent = pt;
		move_angle();
		m_ptLast = pt;
	}
}

xPoint Action_Bird_Round_Move6::BirdMoveTo(float elapsed)
{
	///< 到达的时候的时间
	float time = std::min(1.0f, (_elapsed + elapsed) / _duration);
	if (stage_ == 0)
	{
		//位置
		float angle = start_angle_ + rotate_angle_ * time;
		xPoint pt;
		pt.x_ = center_.x_ + radius_ * std::cos(angle);
		pt.y_ = center_.y_ + radius_ * std::sin(angle);

		return pt;
	}
	else
	{
		xPoint pt = _target ? toNetPoint(_target->getPosition()) : xPoint(0, 0);
		//xPoint pt(toNetPoint(_target->getPosition()));
		pt.x_ += bird_speed_ * (time / 4) * delta_.x_;
		pt.y_ += bird_speed_ * (time / 4) * delta_.y_;

		return pt;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////
Action_Bird_Move_Linear6* Action_Bird_Move_Linear6::create(float bird_speed, std::string start, std::string end)
{
	Action_Bird_Move_Linear6* act = new Action_Bird_Move_Linear6();
	if (act && act->init(bird_speed, start, end))
	{
		act->autorelease();
		return act;
	}
	delete act;
	return 0;
}

bool Action_Bird_Move_Linear6::init(float bird_speed, std::string start, std::string end)
{
    auto s1 =start.find("(",0);
    auto s2 = start.find(",",0);
    auto s3 = start.find(")",0);
    auto x1 = atof(start.substr(s1+1,s2).c_str());
    auto y1 = atof(start.substr(s2+1,s3-1).c_str());
    xPoint start1 =xPoint(x1, y1);
    
    auto d1 =end.find("(",0);
    auto d2 = end.find(",",0);
    auto d3 = end.find(")",0);
    auto x2 = atof(end.substr(d1+1,d2).c_str());
    auto y2 = atof(end.substr(d2+1,d3-1).c_str());
    xPoint end1 =xPoint(x2, y2);
    

	start_ = start1;
	end_ = end1;
	bird_speed_ = bird_speed;
	delta_ = end_ - start_;
	float length = std::sqrt(delta_.x_ * delta_.x_ + delta_.y_ * delta_.y_);
	_duration = length / bird_speed_;

	return true;
}

void Action_Bird_Move_Linear6::update(float time)
{
	_elapsed = _duration * time;

	//位置
	xPoint pt(start_.x_ + delta_.x_ * time, start_.y_ + delta_.y_ * time);
	_target->setPosition(toCCP(pt));

//	//阴影特效
//	Bird *bird = ((BirdNode*)_target)->bird;
//	BirdNode* spr_shadow = (BirdNode*)bird->shadow_;
//	BirdNode* spr_effect = (BirdNode*)bird->effect_;
//	if (spr_shadow)
//	{
//		spr_shadow->setPosition(toCCP(pt.x_ + 20, pt.y_ + 20));
//	}
//
//	float angle = CalculateRotateAngle(m_ptCurrent, m_ptLast);
//	if (spr_effect)
//	{
//		///< 这里是有问题的!!!
//		if (bird->type_ == BIRD_TYPE_INGOT)
//		{
//			Size bird_size = spr_shadow->getSize();
//			Vec2 bird_pos = _target->getPosition();
//			float angle = _target->getRotation();
//			bool big_angle = angle > 180 || angle < -180 ? true : false;
//			angle = angle > 180 ? angle - 180 : angle < -180 ? angle + 180 : angle;
//			angle = -angle;
//			float dregress = CC_DEGREES_TO_RADIANS(angle);
//
//			Vec2 effect_pos;
//			if (big_angle)
//			{
//				effect_pos = Vec2(bird_pos.x - 30 * cos(dregress), bird_pos.y - 30 * sin(dregress));
//			}
//			else
//			{
//				effect_pos = Vec2(bird_pos.x + 30 * cos(dregress), bird_pos.y + 30 * sin(dregress));
//			}
//			spr_effect->setPosition(effect_pos);
//			spr_effect->setRotation(_target->getRotation() + 90);
//		}
//		else if (!SimpleTools::isDntgSpecialRoundBird(bird->type_))
//		{
//			spr_effect->setPosition(_target->getPosition());
//			spr_effect->setRotation(spr_effect->getRotation() + 1);
//		}
//		else
//		{
//			spr_effect->setRotation(angle);
//			Vec2 now_p_1 = _target->getPosition();
//
//			spr_effect->setPosition(now_p_1);
//			auto nodes = spr_effect->getChildren();
//			for (int i = 0; i < nodes.size(); i++)
//			{
//				Node * node = nodes.at(i);
//				node->setRotation(node->getRotation() + 1);
//			}
//		}
//	}
	//角度
	m_ptCurrent = pt;
	move_angle();
	m_ptLast = pt;
}

xPoint Action_Bird_Move_Linear6::BirdMoveTo(float elapsed)
{
	///< 这个时间是有可能下一帧的时间大于了持续总时间.所以比较一下
	float time = std::min(1.0f, (_elapsed + elapsed) / _duration);
	return  xPoint(start_.x_ + delta_.x_ * time, start_.y_ + delta_.y_ * time);
}

//------------------------------------------------------------------------------------------
Action_Bird_Move_Pause_Linear6* Action_Bird_Move_Pause_Linear6::create(float bird_speed, float pause_time, std::string start, std::string pause, std::string end, float start_angle /* = 0.f */)
{
	Action_Bird_Move_Pause_Linear6* act = new Action_Bird_Move_Pause_Linear6();
	if (act && act->init(bird_speed, pause_time, start, pause, end, start_angle))
	{
		act->autorelease();
		return act;
	}
	delete act;
	return 0;
}

bool Action_Bird_Move_Pause_Linear6::init(float bird_speed, float pause_time, std::string start, std::string pause, std::string end, float start_angle /* = 0.f */)
{
    auto s1 =start.find("(",0);
    auto s2 = start.find(",",0);
    auto s3 = start.find(")",0);
    auto x1 = atof(start.substr(s1+1,s2).c_str());
    auto y1 = atof(start.substr(s2+1,s3-1).c_str());
    xPoint start1 =xPoint(x1, y1);
    
    auto d1 =end.find("(",0);
    auto d2 = end.find(",",0);
    auto d3 = end.find(")",0);
    auto x2 = atof(end.substr(d1+1,d2).c_str());
    auto y2 = atof(end.substr(d2+1,d3-1).c_str());
    xPoint end1 =xPoint(x2, y2);
    
    auto p1 =pause.find("(",0);
    auto p2 = pause.find(",",0);
    auto p3 = pause.find(")",0);
    auto x3 = atof(pause.substr(p1+1,p2).c_str());
    auto y3 = atof(pause.substr(p2+1,p3-1).c_str());
    xPoint pause1 =xPoint(x3, y3);
    
    
	start_ = start1;
	pause_ = pause1;
	end_ = end1;
	bird_speed_ = bird_speed;
	pause_time_ = pause_time;
	start_angle_ = start_angle;

	front_delta_ = pause_ - start_;
	float length = std::sqrt(front_delta_.x_ * front_delta_.x_ + front_delta_.y_ * front_delta_.y_);
	front_time_ = length / bird_speed_;
	back_delta_ = end_ - pause_;
	length = std::sqrt(back_delta_.x_ * back_delta_.x_ + back_delta_.y_ * back_delta_.y_);
	back_time_ = length / bird_speed_;
	_duration = front_time_ + pause_time_ + back_time_;

	return true;
}

void Action_Bird_Move_Pause_Linear6::update(float time)
{
	_elapsed = _duration * time;

	//位置
	xPoint pt(_target->getPositionX(), _target->getPositionY());
	if (_elapsed <= front_time_)
	{
		time = _elapsed / front_time_;
		pt.x_ = start_.x_ + front_delta_.x_ * time;
		pt.y_ = start_.y_ + front_delta_.y_ * time;
		_target->setPosition(toCCP(pt));

		//角度
		m_ptCurrent = pt;
		move_angle();
		m_ptLast = pt;
	}
	else if (_elapsed > front_time_ + pause_time_)
	{
		time = (_elapsed - (front_time_ + pause_time_)) / back_time_;
		pt.x_ = pause_.x_ + back_delta_.x_ * time;
		pt.y_ = pause_.y_ + back_delta_.y_ * time;
		_target->setPosition(toCCP(pt));

		//角度
		m_ptCurrent = pt;
		move_angle();
		m_ptLast = pt;
	}
	else if (start_ == pause_)
	{
		pt = pause_;
		_target->setPosition(toCCP(pt));
		_target->setRotation((start_angle_ - M_PI_2) * 180 / M_PI);
	}
}

xPoint Action_Bird_Move_Pause_Linear6::BirdMoveTo(float elapsed)
{
	float time = 0.0;
	if ((_elapsed + elapsed) <= front_time_)
	{
		time = std::min<float>(1.0, (_elapsed + elapsed) / _duration);
		return xPoint(start_.x_ + front_delta_.x_ * time, start_.y_ + front_delta_.y_ * time);
	}
	else if ((_elapsed + elapsed) > front_time_ + pause_time_)
	{
		time = std::min<float>(1.0, ((_elapsed + elapsed) - (front_time_ + pause_time_)) / back_time_);
		return xPoint(pause_.x_ + back_delta_.x_ * time, pause_.y_ + back_delta_.y_ * time);
	}

	return xPoint(pause_.x_, pause_.y_);
}

//------------------------------------------------------------------------------------------

Shake6::Shake6() : _strength_x(0), _strength_y(0), _initial_x(0), _initial_y(0)
{
}

Shake6* Shake6::create(float d, float strength)
{
	// call other construction method with twice the same strength  
	return create(d, strength, strength);
}

Shake6* Shake6::create(float duration, float strength_x, float strength_y)
{
	Shake6 *p_action = new Shake6();
	if (p_action &&  p_action->initWithDuration(duration, strength_x, strength_y))
	{
		p_action->autorelease();

		return p_action;
	}
	delete p_action;
	return nullptr;
}

bool Shake6::initWithDuration(float duration, float strength_x, float strength_y)
{
	if (CCActionInterval::initWithDuration(duration))
	{
		_strength_x = strength_x;
		_strength_y = strength_y;

		return true;
	}

	return false;
}

// Helper function. I included it here so that you can compile the whole file  
// it returns a random value between min and max included  
float Shake6::fgRangeRand(float min, float max)
{
	float rnd = ((float)rand() / (float)RAND_MAX);
	return rnd*(max - min) + min;
}

void Shake6::update(float time)
{
	float randx = fgRangeRand(-_strength_x, _strength_x);
	float randy = fgRangeRand(-_strength_y, _strength_y);

	// move the target to a shaked position  
	_target->setPosition(Vec2(_initial_x + randx,
		_initial_y + randy));
}

Shake6* Shake6::clone(void) const
{
	auto a = new Shake6();
	a->initWithDuration(_duration, _strength_x, _strength_y);
	a->autorelease();
	return a;
}

Shake6* Shake6::reverse() const
{
	return Shake6::create(_duration, -_strength_x, -_strength_y);
}

void Shake6::startWithTarget(Node *target)
{
	CCActionInterval::startWithTarget(target);

	// save the initial position  
	_initial_x = target->getPosition().x;
	_initial_y = target->getPosition().y;
}

void Shake6::stop(void)
{
	// Action is done, reset clip position  
	_target->setPosition(Vec2(_initial_x, _initial_y));

	CCActionInterval::stop();
}


////////////////////////////////////////////////////////////////////////

BirdDeathAction6::BirdDeathAction6()
{
	for (int i = 0; i < 8; i++)
	{
		isRun[i] = false;
	}
	mNumber = 0;
	mSignDregress = 45;
}

BirdDeathAction6* BirdDeathAction6::create(float d)
{
	BirdDeathAction6 *p_action = new BirdDeathAction6();
	if (p_action && p_action->initWithDuration(d))
	{
		p_action->autorelease();
		return p_action;
	}
	delete p_action;
	return nullptr;

}

bool BirdDeathAction6::initWithDuration(float d)
{
	_duration = d;


	return true;
}

void BirdDeathAction6::startWithTarget(Node *target)
{
	CCActionInterval::startWithTarget(target);
}

void BirdDeathAction6::update(float time)
{
	///, 现在已经走过的时间
	float now_time = time * _duration;

	float rotate_ = _target->getRotation();
	if (now_time == 0.0f)
	{
		mOldRotate = rotate_;
		rotate_ = ((int)(rotate_ / 90) + 1) * 90;
		mSignDregress = -mSignDregress;
	}

	if (now_time > 0.08f * mNumber)
	{
		rotate_ += mSignDregress;
		bool isFilpped = dynamic_cast<Sprite *>(_target)->isFlippedX();
		dynamic_cast<Sprite *>(_target)->setFlippedX(!isFilpped);
		if (mNumber > 7 && mNumber < 13)
		{
			if (rotate_ > 180) rotate_ -= 180 - mSignDregress;
			else
			{
				rotate_ += 180 - mSignDregress;

			}
		}
		else if (rotate_ > 360)
		{
			rotate_ -= 180;
			mSignDregress = -mSignDregress;
			// dynamic_cast<Sprite *>(_target)->setFlippedX(true);
		}
		else if (rotate_ < 0)
		{
			rotate_ += 180;
			mSignDregress = -mSignDregress;
			// dynamic_cast<Sprite *>(_target)->setFlippedX(false);
		}


		mNumber++;
	}

	if (time == 1.0f)
	{
		rotate_ = mOldRotate;
		dynamic_cast<Sprite *>(_target)->setFlippedX(false);
	}
	_target->setRotation(rotate_);

}

