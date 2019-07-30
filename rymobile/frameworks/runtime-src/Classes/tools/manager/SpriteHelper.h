#ifndef _SpriteHelper_H_
#define _SpriteHelper_H_
#include "cocos2d.h"


class SpriteHelper
{
public:
	static bool cacheAnimations(std::string rootName);
	static void removeAnimations(std::string rootName);

	static bool cacheAnimation(const char* plist);
	static void removeAnimation(const char* plist);
	static cocos2d::CCAnimate* createAnimate(const char* name);
	static cocos2d::CCAnimate* createEffectAnimate(const char* name, float time);
	static cocos2d::CCAnimate* createBirdAnimate(int type);
	static cocos2d::CCAnimate* createBirdDeadAnimate(int type);
	static cocos2d::CCAnimate* createJdbyBirdDeadAnimate(int type);

}; // SpriteHelper
#endif // _SpriteHelper_H_