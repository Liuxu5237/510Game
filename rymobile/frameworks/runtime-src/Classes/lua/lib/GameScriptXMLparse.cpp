#include "GameScriptXMLparse.h"
#include "script/UtilityFun.h"
#include "GameScriptData.h"
#include "script/utilityFun.h"
#include "tools/tools/Convert.h"

USING_NS_CC;

GameScriptXMLparse::GameScriptXMLparse(std::string xmlFileName)
{
	SAXParser parser;
	parser.setDelegator(this);
	std::string kFullPath = utility::FullPath(xmlFileName);
	parser.parse(kFullPath.c_str());
}

void GameScriptXMLparse::startElement(void *ctx, const char *name, const char **atts)
{
	std::string elementName = (char*)name;
	std::map<std::string, std::string> attributeDict;
	utility::createAttributeDict(attributeDict,atts);

	if(elementName == "ScriptValueInt")
	{
		std::string kName = utility::valueForKey("Key", attributeDict);
		int iValue = (utility::valueForInt("Value", attributeDict));
		GameScriptData::addValue<int>(kName, iValue);
	}
	if(elementName == "ScriptValueStr")
	{
		std::string kName = utility::valueForKey("Key", attributeDict);
		std::string iValue = (utility::valueForKey("Value", attributeDict));
		GameScriptData::addValue<std::string>(kName, a_u8(iValue.c_str()));
		
	}
	if(elementName == "ScriptValueFloat")
	{
		std::string kName = utility::valueForKey("Key", attributeDict);
		float fValue = (utility::valueForFloat("Value", attributeDict));
		GameScriptData::addValue<float>(kName, fValue);
	}
	if(elementName == "ScriptValuePoint")
	{
		std::string kName = utility::valueForKey("Key", attributeDict);
		cocos2d::Point kValue = (utility::valueForPoint("Value", attributeDict));
		GameScriptData::addValue<cocos2d::Point>(kName, kValue);
	}
	if(elementName == "ScriptValueSize")
	{
		std::string kName = utility::valueForKey("Key", attributeDict);
		cocos2d::Size kValue = (utility::valueForSize("Value", attributeDict));
		GameScriptData::addValue<cocos2d::Size>(kName, kValue);
	}
	if (elementName == "ScriptValueRect")
	{
		std::string kName = utility::valueForKey("Key", attributeDict);
		cocos2d::Rect kValue = (utility::valueForRect("Value", attributeDict));
		GameScriptData::addValue<cocos2d::Rect>(kName, kValue);
	}
}

void GameScriptXMLparse::endElement(void *ctx, const char *name)
{

}

void GameScriptXMLparse::textHandler(void *ctx, const char *s, int len)
{

}
