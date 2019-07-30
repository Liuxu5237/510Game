#pragma once


#include "cocos2d.h"

class GameScriptData
{
public:
	// 获取脚本数据接口
	static GameScriptData* getInterface();


	static GameScriptData* s_pInterface;

public:
	// 构造函数
	GameScriptData(void);

	// 析构函数
	~GameScriptData(void);

public:
	// 加载游戏数据
	void loadGameScriptData(std::string kFileName);

public:
	
	template<class T>
	static void addValue(std::string kKey, const T& iValue)
	{
		std::map<std::string, T>& kList = S_LIST<T>();
		typename std::map<std::string, T>::iterator itor = kList.find(kKey);
		if (itor != kList.end())
		{
			cocos2d::log("have already Value %s", kKey.c_str());
			return;
		}
		kList.insert(std::pair<std::string, T>(kKey, iValue));
	}

	template<class T>
	static std::map<std::string, T>& S_LIST();

public:

	std::map<std::string, float> & getFloatMap()
	{
		return m_mapValueFloat;
	}

	std::map<std::string, int> & getIntMap()
	{
		return m_mapValueInt;
	}

	std::map<std::string, std::string> & getStringMap()
	{
		return m_mapValueStr;
	}

	std::map<std::string, cocos2d::Point> & getPointMap()
	{
		return m_mapValuePoint;
	}

	std::map<std::string, cocos2d::Size> & getSizeMap()
	{
		return m_mapValueSize;
	}

	std::map<std::string, cocos2d::Rect> & getRectMap()
	{
		return m_mapValueRect;
	}
protected:
	std::map<std::string, int>				m_mapValueInt;
	std::map<std::string, float>			m_mapValueFloat;
	std::map<std::string, std::string>		m_mapValueStr;
	std::map<std::string, cocos2d::Point>	m_mapValuePoint;
	std::map<std::string, cocos2d::Size>	m_mapValueSize;
	std::map<std::string, cocos2d::Rect>	m_mapValueRect;
};


class GameScriptDataMananger
{
public:

	static void loadGameScriptData(std::string fileName)
	{
		GameScriptData::getInterface()->loadGameScriptData(fileName);
	}

	static int getInt(std::string & key)
	{
		std::map<std::string, int>& kList = GameScriptData::getInterface()->getIntMap();
		std::map<std::string, int>::const_iterator iter = kList.find(key);
		if (iter != kList.end())
		{
			return (*iter).second;
		}
		else
		{
			return 0;
		}
	}

	static float getFloat(std::string & key)
	{
		std::map<std::string, float>& kList = GameScriptData::getInterface()->getFloatMap();
		std::map<std::string, float>::const_iterator iter = kList.find(key);
		if (iter != kList.end())
		{
			return (*iter).second;
		}
		else
		{
			return 0;
		}
	}

	static std::string strEmpy;
	static const std::string & getString(std::string & key)
	{
		std::map<std::string, std::string>& kList = GameScriptData::getInterface()->getStringMap();
		std::map<std::string, std::string>::const_iterator iter = kList.find(key);
		if (iter != kList.end())
		{
			return iter->second;
		}
		else
		{
			return strEmpy;
		}
	}

	static cocos2d::Point getPoint(std::string & key)
	{
		std::map<std::string, cocos2d::Point>& kList = GameScriptData::getInterface()->getPointMap();
		std::map<std::string, cocos2d::Point>::const_iterator iter = kList.find(key);
		if (iter != kList.end())
		{
			return iter->second;
		}
		else
		{
			return cocos2d::Point();
		}
	}

	static cocos2d::Size getSize(std::string & key)
	{
		std::map<std::string, cocos2d::Size>& kList = GameScriptData::getInterface()->getSizeMap();
		std::map<std::string, cocos2d::Size>::const_iterator iter = kList.find(key);
		if (iter != kList.end())
		{
			return iter->second;
		}
		else
		{
			return cocos2d::Size();
		}
	}

	static cocos2d::Rect getRect(std::string & key)
	{
		std::map<std::string, cocos2d::Rect>& kList = GameScriptData::getInterface()->getRectMap();
		std::map<std::string, cocos2d::Rect>::const_iterator iter = kList.find(key);
		if (iter != kList.end())
		{
			return iter->second;
		}
		else
		{
			return cocos2d::Rect();
		}
	}
};





