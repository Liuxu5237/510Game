#include "GameScriptData.h"
#include "GameScriptXMLparse.h"


GameScriptData* GameScriptData::s_pInterface = NULL;

GameScriptData* GameScriptData::getInterface()
{
	if (s_pInterface == NULL)
	{
		s_pInterface = new GameScriptData();
	}
	return s_pInterface;
}


/************************************************************************/
/* 构造函数                                                              */
/************************************************************************/
GameScriptData::GameScriptData(void)
{

}

/************************************************************************/
/* 析构函数                                                              */
/************************************************************************/
GameScriptData::~GameScriptData(void)
{
	m_mapValueInt.clear();
	m_mapValueFloat.clear();
	m_mapValueStr.clear();
	m_mapValuePoint.clear();
	m_mapValueSize.clear();
}

/************************************************************************/
/* 加载游戏数据                                                          */
/************************************************************************/
void GameScriptData::loadGameScriptData(std::string kFileName)
{
	m_mapValueInt.clear();
	m_mapValueFloat.clear();
	m_mapValueStr.clear();
	m_mapValuePoint.clear();
	m_mapValueSize.clear();

	cocos2d::GameScriptXMLparse kXml1(kFileName);
}

template<>
std::map<std::string, float>& GameScriptData::S_LIST<float>()
{
	return getInterface()->m_mapValueFloat;
}
template<>
std::map<std::string, int>& GameScriptData::S_LIST<int>()
{
	return getInterface()->m_mapValueInt;
}

template<>
std::map<std::string, std::string>& GameScriptData::S_LIST<std::string>()
{
	return getInterface()->m_mapValueStr;
}

template<>
std::map<std::string, cocos2d::Point>& GameScriptData::S_LIST<cocos2d::Point>()
{
	return getInterface()->m_mapValuePoint;
}
template<>
std::map<std::string, cocos2d::Size>& GameScriptData::S_LIST<cocos2d::Size>()
{
	return getInterface()->m_mapValueSize;
}

template<>
std::map<std::string, cocos2d::Rect>& GameScriptData::S_LIST<cocos2d::Rect>()
{
	return getInterface()->m_mapValueRect;
}

std::string GameScriptDataMananger::strEmpy = "";