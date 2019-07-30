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
	/* �����ƶ���ʼ                                                         */
	/************************************************************************/
	virtual bool onTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent) = 0;

	/************************************************************************/
	/* �����ƶ�                                                             */
	/************************************************************************/
	virtual void onTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent) = 0;

	/************************************************************************/
	/* �����ƶ�����                                                         */
	/************************************************************************/
	virtual void onTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent) = 0;

};

#endif