#ifndef YRCOMMON_H_
#define YRCOMMON_H_

#include "cocos2d.h"

/*
 *	公用资源
 */
//获取头像
const char * YRComGetHeadImageById(int head_id);

/*
 *	辅助函数
 */
//字符串是否全是数字
bool YRComStringIsNumber(const std::string strString);

///< 缩放由数字构成的文本
#define DIGIT_SCALE(target, cond) if((cond) > (2 << 22)) target->setScale(0.7f); \
			else target->setScale(0.8f);

///cocos2d::Vec2 YRComGetConfineToRandomVec2(cocos2d::Vec2 & oprign, int radius);

#endif //YRCOMMON_H_

