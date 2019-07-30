#ifndef _GAME_TOUCH_SCENE_H_
#define	_GAME_TOUCH_SCENE_H_

#include "cocos2d.h"

USING_NS_CC;
using namespace ui;

#include "kernel/game/IGameTouchSink.h"
#include "kernel/game/CGameScene.h"

class CGameScene;

class GameTouchScene : public cocos2d::Layer
{
protected:

	IGameTouchSink * m_gameTouchSink;

public:
	// 触摸场景初始化 
	virtual bool init();

	// 触摸场景进入
	virtual void onEnter();

public:
	// 设置触摸事件响应接口
	void setGameTouchSink(CGameScene * pGameScene){
		m_gameTouchSink = dynamic_cast<IGameTouchSink *>(pGameScene);
	}

public:

	CREATE_FUNC(GameTouchScene);

public:

	/************************************************************************/
	/* 触摸进入                                                             */
	/************************************************************************/
	virtual bool onTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);

	/************************************************************************/
	/* 触摸移动                                                             */
	/************************************************************************/
	virtual void onTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);

	/************************************************************************/
	/*触摸离开	                                                            */
	/************************************************************************/
	virtual void onTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
};


#endif
