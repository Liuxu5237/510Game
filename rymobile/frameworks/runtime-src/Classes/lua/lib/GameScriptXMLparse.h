#ifndef __XML_Game_Parse_H__
#define __XML_Game_Parse_H__

#include "platform/CCSAXParser.h"

#include <map>
#include <vector>

NS_CC_BEGIN;

class GameScriptXMLparse : public cocos2d::SAXDelegator
{
public:

	GameScriptXMLparse(std::string xmlFileName);
	~GameScriptXMLparse()
	{
	}
	virtual void startElement(void *ctx, const char *name, const char **atts);
	virtual void endElement(void *ctx, const char *name);
	virtual void textHandler(void *ctx, const char *s, int len);

private:
};
NS_CC_END;
#endif // __XMLParse_H__