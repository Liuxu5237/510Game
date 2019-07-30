#include "GameTouchScene.h"
#include "IGameTouchSink.h"
#include "ui/UIWidget.h"
/************************************************************************/
/* ����������ʼ��                                                       */
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
/* ������������                                                         */
/************************************************************************/
void GameTouchScene::onEnter()
{
	CCLayer::onEnter();
}


/************************************************************************/
/* ��������                                                             */
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
/* �����ƶ�                                                             */
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
/* �����뿪                                                             */
/************************************************************************/
void GameTouchScene::onTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
	if (pTouch->getID() != 0)
	{
		return;
	}

	if(m_gameTouchSink)	m_gameTouchSink->onTouchEnded(pTouch,pEvent);
}