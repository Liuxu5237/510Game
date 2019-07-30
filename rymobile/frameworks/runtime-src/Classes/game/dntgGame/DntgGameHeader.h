#ifndef _Dntg_GameHeader_H_
#define _Dntg_GameHeader_H_
#pragma pack(push)
#pragma pack(1)

#include "cocos2d.h"
#include "DntgBirdDefine.h"
#include "tools/manager/Move_Point_Manager.h"
namespace  Dntg
{
	inline cocos2d::Vec2 toCCP(const xPoint& pt)
	{
		return cocos2d::Vec2(pt.x_, kGameRevolutionHeight - pt.y_);
	}

	inline cocos2d::Vec2 toCCP(float x, float y)
	{
		return cocos2d::Vec2(x, kGameRevolutionHeight - y);
	}

	inline cocos2d::Size  toCCS(const xSize& si)
	{
		return cocos2d::Size(si.width_, si.height_);
	}

	inline cocos2d::Rect  toCCR(const xRect& rt)
	{
		return cocos2d::Rect(rt.left_, kGameRevolutionHeight - rt.top_, rt.get_width(), rt.get_height());
	}

	inline float toCCRotation(float angle)
	{
		return angle * 180 / M_PI;
	}

	inline xPoint toNetPoint(const cocos2d::Vec2& pt)
	{
		return xPoint(pt.x, kGameRevolutionHeight - pt.y);
	}

	inline xPoint toNetPoint(float x, float y)
	{
		return xPoint(x, kGameRevolutionHeight - y);
	}

	inline xSize toNetSize(const cocos2d::Size& si)
	{
		return xSize(si.width, si.height);
	}

	inline xRect toNetRect(const cocos2d::Rect& rt)
	{
		return xRect(rt.origin.x, kGameRevolutionHeight - rt.origin.y, rt.size.width, rt.size.height);
	}

	inline float toNetRotation(float angle)
	{
		return angle*M_PI / 180;
	}

}

#pragma pack(pop)
#endif // _GameHeader_H_