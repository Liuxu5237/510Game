#ifndef _DNTG_SIMPLETOOLS_H_
#define _DNTG_SIMPLETOOLS_H_

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "tools/manager/Move_Point_Manager.h"
USING_NS_CC;
using namespace ui;

namespace Dntg
{
///< 闪电类型
enum LINETYPE
{
	PINK = 0,
	BLUE,
	YELLOW,
	ALLTYPE
};
///< 简单的工具类
class SimpleTools
{
public:
	SimpleTools();
	~SimpleTools();

	//static const char * getHeadImageById(int head_id);

	static float calcRotate(int char_id, const xPoint& pt_offset);
	
	///< 获得圆的坐标
	static cocos2d::CCActionInterval * getCircularAction(const Vec2 & start_pos, float radius);

	///< 闪电的动作
	static cocos2d::Sprite * getLightAction(float duration, const Vec2 & base_pos, std::vector<Vec2> other_pos, LINETYPE sType = LINETYPE::PINK);


	///< 大闹天宫
	///< 鱼的类型
	static bool isDntgSpecialBird(int birdType);
	///< 是圆盘鱼
	static bool isDntgSpecialRoundBird(int birdType);
	///< 是需要直走的鱼
	static bool isDntgNeedGoStraightBird(int birdType);
	///< 是否反向,值为1或者-1
	static bool isDntgReverseAtGoStraightBird(const Vec2 & start_p, const Vec2 & end_p);
	///< 是龙王
	static bool isDntgDragonKing(int birdType);
};
}
// ///< 缩放由数字构成的文本
// #define DIGIT_SCALE(target, cond) if((cond) > (2 << 22)) target->setScale(0.7f); \
// 			else target->setScale(0.8f);

#endif
