#include "GameTouchScene.h"
#include "IGameTouchSink.h"
#include "ui/UIWidget.h"
/************************************************************************/
/* 触摸场景初始化                                                       */
/************************************************************************/
bool GameTouchScene::init()
{
	if ( !CCLayer::init() )
	{
		return false;
	}
	setTouchEnabled(true);
	setTouchMode(kCCTouchesOneByOne);
	m_gameTouchSink = NULL;
	return true;
}


/************************************************************************/
/* 触摸场景进入                                                         */
/************************************************************************/
void GameTouchScene::onEnter()
{
	CCLayer::onEnter();
}


/************************************************************************/
/* 触摸进入                                                             */
/************************************************************************/
bool GameTouchScene::onTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
	if (pTouch->getID() != 0)
	{
		return false;
	}

	if(m_gameTouchSink)	return m_gameTouchSink->onTouchBegan(pTouch,pEvent);
	return false;
}

/************************************************************************/
/* 触摸移动                                                             */
/************************************************************************/
void GameTouchScene::onTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
	if (pTouch->getID() != 0)
	{
		return;
	}

	if(m_gameTouchSink)	m_gameTouchSink->onTouchMoved(pTouch,pEvent);
}

/************************************************************************/
/* 触摸离开                                                             */
/************************************************************************/
void GameTouchScene::onTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
	if (pTouch->getID() != 0)
	{
		return;
	}

	if(m_gameTouchSink)	m_gameTouchSink->onTouchEnded(pTouch,pEvent);
}