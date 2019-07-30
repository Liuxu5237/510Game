
#ifndef __UTILITY_FUN_H__
#define __UTILITY_FUN_H__

#include "cocos2d.h"
#include "tools/StringUtility.h"
#include "StructType.h"
#include "ActionEx.h"

namespace utility
{

	std::string getScriptString(std::string kName);

	//utf8字符串换行重组
	std::string lineFeeds(const std::string &str, int iCurrentIndex);
	//utf8字符解析
	std::vector<std::string>  parseUTF8(const std::string &str);
	int getUTF8ByCout( const std::string& str);
	bool isNumAZ( const std::string& str);
	//截取UTF8字符串
	std::string subUTF8(const std::string &str,int from, int to);

	void setPaseTime(std::string kTime);
	void setDebugFileName(std::string kName);
	std::string getDebugFileName();
	void log(const char * format, ...);
	void saveFilePath(std::string kStr);
	std::vector<std::string> getFilePath();
	std::string FullPath(std::string kName);
	std::string getFileName(std::string kName);
	cocos2d::Point parsePoint(std::string kValue);
	cocos2d::Size parseSize(std::string kValue);
	cocos2d::Rect parseRect(std::string kValue);
	std::string paseInt(int iValue, int iCout);
	cocos2d::Vec2 getRandPos(const RandPos& kRand,cocos2d::Node* pNode);
	float getRandFloat(const RandFloat& kRand,cocos2d::Node* pNode);
	UserString valueForUserString(const char *key, std::map<std::string, std::string>& dict);
	UserString parseUserString(std::string kStr);
	std::string getUserString(const UserString& kUserString, cocos2d::Node* pNode);
	RandPos parseRandPos(std::string kStr);
	RandFloat parseRandFloat(std::string kStr);
	cocos2d::CCTexture2D* addTexture(std::string kTextureName);
	cocos2d::Color3B parseColour(std::string kValue);
	cocos2d::Color4B parseColour4(std::string kValue);
	float fAbs(const float& fValue);
	float fMin(const float& fValue1,const float& fValue2);
	float fMax(const float& fValue1,const float& fValue2);
	float toDest(const float& fSart,const float& fDest,const float& fAdd);
	bool CCPtInRect(const cocos2d::Rect& rect,const cocos2d::Point& point);
	void createAttributeDict(std::map<std::string, std::string>& attributeDict,const char **atts);
	std::string  valueForKey(const char *key, std::map<std::string, std::string>& dict);
	int  valueForInt(const char *key, std::map<std::string, std::string>& dict);
	float  valueForFloat(const char *key, std::map<std::string, std::string>& dict);
	bool  valueForBool(const char *key, std::map<std::string, std::string>& dict);
	cocos2d::Point valueForPoint(const char *key, std::map<std::string, std::string>& dict);
	cocos2d::Size valueForSize(const char *key, std::map<std::string, std::string>& dict);
	cocos2d::Rect valueForRect(const char *key, std::map<std::string, std::string>& dict);
	RandFloat valueForRandFloat(const char *key, std::map<std::string, std::string>& dict);
	RandPos valueForRandPos(const char *key, std::map<std::string, std::string>& dict);
	void valueForFloat4(float* fValue,const char *key, std::map<std::string, std::string>& dict);
	void valueForInt4(int* iValue,const char *key, std::map<std::string, std::string>& dict);
	//void saveJpgWidthAple(std::string kTextureName);
	void createTextPicFun(std::string kTextureName);
	cocos2d::CCTexture2D* createJpgTextureWithAple(std::string kTexture,std::string kAple);
	void setSpriteScaleBySize(cocos2d::Node* pSprite,cocos2d::Size kSize);
	void StringReplace(std::string &strBase, std::string strSrc, std::string strDes);
	void CCAssertWithDes(bool bAssert,std::string kDes1,std::string kDes2);
	float getMoveTime(cocos2d::Point kSrc,cocos2d::Point kDest,float fSpd);
	float getMoveTime(float fSrc,float fDest,float fSpd);
	cocos2d::Point getDistancePos(cocos2d::Point kSrc,cocos2d::Point kDest,float fDistance);
	cocos2d::Point getAnglePos(cocos2d::Point kSrc,cocos2d::Point kDest,float fAngle);
	cocos2d::Point getPosByDistanceAngle(float fDistance,float fRoata);
	cocos2d::Point getPosByAngle(cocos2d::Point kDest,float fRoata);
	bool haveInVector(const std::vector<int>& kList,int iIdex);
	bool MoveTo(cocos2d::Point kSrc,cocos2d::Point kDest,cocos2d::Point& kOut,float fDistance);
	bool MoveTo(float fSrc,float fDest,float& fkOut,float fDistance);
	void StringToChar(std::string kStringValue, char* pChar, int iSize);
	void saveFile(const char *pContent, std::string pFileName, int length);
	std::string AddFuHao(int iNum);
	void DelIntVectorByIdex(int iIdex,std::vector<int>& kVectors);
	void DelIntVectorByValue(int iValue,std::vector<int>& kVectors);

	float getOffectByLR(bool bLeft,float fDistance);

	std::string EncodeURL(const std::string &URL);
	std::string DecodeURL(const std::string &URL);

	int getVectorIdex(std::vector<int>& kVector,int iValue);

	std::string getSameSizeValue10(int iValue);

	float getRotation(cocos2d::Point kSrcPos,cocos2d::Point kDestPoint);

	cocos2d::Point getOffectParentPos(cocos2d::Node* pNode,cocos2d::Point kOffect);

	cocos2d::BezierToEx* createBezierAction(float fTime,cocos2d::Point kStartPos,cocos2d::Point kEndPos);
	void schedule(cocos2d::SEL_SCHEDULE selector,cocos2d::Ref* pTarget);
	void unschedule(cocos2d::SEL_SCHEDULE selector,cocos2d::Ref* pTarget);
	void scheduleOnce(cocos2d::SEL_SCHEDULE selector,cocos2d::Ref* pTarget,float interval);

	template<typename T1>
	std::string getScriptReplaceValue (std::string kSrc,T1 p1)
	{
		return getScriptReplaceValue(kSrc,toString(p1));
	}
	bool IsSpriteInTouch(cocos2d::Vec2 kWorldPos, cocos2d::Sprite *pSrite);
	std::string getScriptReplaceValueStr(std::string kSrc, std::string kValue1, std::string kValue2 = "",std::string kValue3 = "");
	bool isAllVisible(cocos2d::Node* pNode);
	template<typename T1,  typename T2>
	std::string getScriptReplaceValue (std::string kSrc,T1 p1, T2 p2)
	{
		return getScriptReplaceValue(kSrc,toString(p1),toString(p2));
	}

	template<typename T1,  typename T2,  typename T3>
	std::string getScriptReplaceValue (std::string kSrc,T1 p1, T2 p2, T3 p3)
	{
		return getScriptReplaceValue(kSrc,toString(p1),toString(p2),toString(p3));
	}
	std::string getScriptReplaceValue(std::string kSrc,std::string kValue1,std::string kValue2 = "",std::string kValue3 = "");

	std::string getShortGoldValue(int iGold);
	//得到当前毫秒时间
	long getCurrentTime();
} 

#endif // 
