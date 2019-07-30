#ifndef _I_GAME_TOUCH_SINK_H_
#define _I_GAME_TOUCH_SINK_H_

#include "cocos2d.h"

USING_NS_CC;

class IGameTouchSink
{
public:
	virtual ~IGameTouchSink(){};

public:

	/************************************************************************/
	/* 触摸移动开始                                                         */
	/************************************************************************/
	virtual bool onTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent) = 0;

	/************************************************************************/
	/* 触摸移动                                                             */
	/************************************************************************/
	virtual void onTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent) = 0;

	/************************************************************************/
	/* 触摸移动结束                                                         */
	/************************************************************************/
	virtual void onTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent) = 0;

};

#endif