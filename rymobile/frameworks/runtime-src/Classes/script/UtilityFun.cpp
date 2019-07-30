#include "UtilityFun.h"
#include "ScriptData.h"
#include "tools/tools/Convert.h"
#include "../widget/WidgetFun.h"
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#include "external\win32-specific\icon\include\iconv.h"
#pragma comment(lib,"libiconv.lib")
#else
//#include <iconv.h>

#endif

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "bugly/CrashReport.h"
#include "bugly/lua/BuglyLuaAgent.h"
#endif

namespace utility
{
	static std::string s_kDebugFileName = "";
	static std::string s_kTime = "";
	//==============中文编码转换===============================================================

	std::string getScriptString(std::string kName)
	{
		ScriptData<std::string> kTxt(kName);
		return kTxt.Value();
	}

	void setPaseTime(std::string kTime)
	{
		s_kTime = kTime;
	}
	void setDebugFileName(std::string kName)
	{
		s_kDebugFileName = kName+".txt";
	}
	std::string getDebugFileName()
	{
		return utility::toString(cocos2d::FileUtils::getInstance()->getWritablePath(),s_kDebugFileName);
	}
	void log(const char * format, ...)
	{
		va_list args;
		va_start(args, format); 

		const int iMaxLenght = 1024;
		char buf[iMaxLenght];
		vsnprintf(buf, iMaxLenght-3, format, args);
		strcat(buf, "\n");	
		strcat(buf, "\0");

		std::string kStr = utility::toString(s_kTime," ",buf);
		if (s_kDebugFileName != "")
		{
			std::string kPathTxt = getDebugFileName();
			FILE* file = fopen(kPathTxt.c_str(), "rb+"); 
			if (!file)
			{
				file = fopen(kPathTxt.c_str(), "wb+");   
			}
			if (file) {   
				fseek(file, 0L, SEEK_END);
				fwrite(kStr.c_str(), sizeof(char), strlen(kStr.c_str()), file);  
				fclose(file);    
			}

		}
		cocos2d::log("%s",buf);
		
		va_end(args);
	}
	void saveFilePath(std::string kStr)
	{
		kStr += "|";
		static std::vector<std::string> kStrV;
		for (int i = 0;i<(int)kStrV.size();i++)
		{
			if (kStrV[i] == kStr)
			{
				return;
			}
		}
		kStrV.push_back(kStr);
		std::string kPathTxt = "FilePath";
		FILE* file = fopen(kPathTxt.c_str(), "rb+"); 
		if (!file)
		{
			file = fopen(kPathTxt.c_str(), "wb+");   
		}
		if (file) {   
			fseek(file, 0L, SEEK_END);
			fwrite(kStr.c_str(), sizeof(char), strlen(kStr.c_str()), file);  
			fclose(file);    
		}
	}
	std::vector<std::string> getFilePath()
	{
		std::string kPathTxt = "FilePath";
		ssize_t iSize = 0;
		char* pChar = (char*)cocos2d::FileUtils::sharedFileUtils()->getFileData(
			cocos2d::FileUtils::sharedFileUtils()->fullPathForFilename(kPathTxt),"rb",&iSize);
		if (!pChar)
		{
			return std::vector<std::string>();
		}
		std::string kStr = pChar;
		return utility::split(kStr,"|");
	}
	std::string FullPath(std::string kName)
	{
		return cocos2d::FileUtils::getInstance()->fullPathForFilename(kName.c_str());
	}
	std::string getFileName(std::string kName)
	{
		std::string::size_type pos = kName.find_last_of('/');
		if (pos != std::string::npos)
		{
			return kName.substr(pos + 1);
		}
		return "";
	}
	cocos2d::Point parsePoint(std::string kValue)
	{
		cocos2d::Point kPoint;
		std::vector<std::string> kStr = split(kValue," ");
		if(kStr.size() == 2)
		{
			kPoint.x = parseFloat(kStr[0]);
			kPoint.y = parseFloat(kStr[1]);
		}
		return kPoint;
	}

	void StringToChar(std::string kStringValue, char* pChar, int iSize)
	{
		CCASSERT(kStringValue.size() < iSize, "");
		strcpy(pChar, kStringValue.c_str());
	}
	cocos2d::Rect parseRect(std::string kValue)
	{
		cocos2d::Rect kRect;
		std::vector<std::string> kStr = split(kValue," ");
		if(kStr.size() == 4)
		{
			kRect.origin.x = parseFloat(kStr[0]);
			kRect.origin.y = parseFloat(kStr[1]);
			kRect.size.width = parseFloat(kStr[2]);
			kRect.size.height = parseFloat(kStr[3]);
		}
		else
		{
			//	utility::CCAssertWithDes(false,kValue," parseRect Error");
		}
		return kRect;
	}

	std::string paseInt(int iValue, int iCout)
	{
		char kTxt[12];
		std::string kTemp = utility::toString("%0", iCout, "d");
		sprintf(kTxt, kTemp.c_str(), iValue);
		return kTxt;
	}

	RandFloat parseRandFloat(std::string kStr)
	{
		RandFloat kValue;
		std::vector<std::string> kVec = utility::split(kStr,":");
		if (kVec.size() && kVec[0] == "Key")
		{
			kValue.kUserKey = kVec[1];
		}
		else if (kVec.size() == 1)
		{
			float fTemp = utility::parseFloat(kVec[0]);
			kValue.fMin = fTemp;
			kValue.fMax = fTemp;
		}
		else if(kVec.size() == 2)
		{
			kValue.fMin = utility::parseFloat(kVec[0]);
			kValue.fMax = utility::parseFloat(kVec[1]);
		}
		else
		{
			CCASSERT(false,"");
		}
		return kValue;
	}
	RandPos parseRandPos(std::string kStr)
	{
		RandPos kValue;
		std::vector<std::string> kVec = utility::split(kStr,":");
		if (kVec.size() && kVec[0] == "Key")
		{
			kValue.kUserKey = kVec[1];
		}
		else if (kVec.size() == 1)
		{
			cocos2d::Vec2 kPos = utility::parsePoint(kVec[0]);
			kValue.kRandX.fMin = kPos.x;
			kValue.kRandX.fMax = kPos.x;
			kValue.kRandY.fMin = kPos.y;
			kValue.kRandY.fMax = kPos.y;
		}
		else if(kVec.size() == 2)
		{
			cocos2d::Vec2 kPos1 = utility::parsePoint(kVec[0]);
			cocos2d::Vec2 kPos2 = utility::parsePoint(kVec[1]);
			kValue.kRandX.fMin = kPos1.x;
			kValue.kRandX.fMax = kPos2.x;
			kValue.kRandY.fMin = kPos1.y;
			kValue.kRandY.fMax = kPos2.y;
		}
		else
		{
			CCASSERT(false,"");
		}
		return kValue;
	}
	cocos2d::Size parseSize(std::string kValue)
	{
		cocos2d::Size kSize;
		std::vector<std::string> kStr = split(kValue," ");
		if(kStr.size() == 2)
		{
			kSize.width = parseFloat(kStr[0]);
			kSize.height = parseFloat(kStr[1]);
		}
		else
		{
		}
		return kSize;
	}
	cocos2d::Color3B parseColour(std::string kValue)
	{
		cocos2d::Color3B kColour = cocos2d::ccc3(255,255,255);
		cocos2d::Size kSize;
		std::vector<std::string> kStr = split(kValue," ");
		if(kStr.size() == 3)
		{
			kColour.r = parseFloat(kStr[0]);
			kColour.g = parseFloat(kStr[1]);
			kColour.b = parseFloat(kStr[2]);
		}
		else
		{
			utility::CCAssertWithDes(false,kValue," parseColour Error");
		}
		return kColour;
	}
	cocos2d::Color4B parseColour4(std::string kValue)
	{
		cocos2d::Color4B kColour = cocos2d::ccc4(255,255,255,255);
		cocos2d::Size kSize;
		std::vector<std::string> kStr = split(kValue," ");
		if(kStr.size() == 4)
		{
			kColour.r = parseFloat(kStr[0]);
			kColour.g = parseFloat(kStr[1]);
			kColour.b = parseFloat(kStr[2]);
			kColour.a = parseFloat(kStr[3]);
		}
		else
		{
			utility::CCAssertWithDes(false,kValue," parseColour Error");
		}
		return kColour;
	}
	float fAbs(const float& fValue)
	{
		if(fValue < 0.f)
		{
			return -fValue;
		}
		return fValue;
	}
	float fMin(const float& fValue1,const float& fValue2)
	{
		if(fValue1 < fValue2)
		{
			return fValue1;
		}
		return fValue2;
	}
	float fMax(const float& fValue1,const float& fValue2)
	{
		if(fValue1 < fValue2)
		{
			return fValue2;
		}
		return fValue1;
	}
	float toDest(const float& fSart,const float& fDest,const float& fAdd)
	{
		float fReturn = fSart;
		if(fSart < fDest)
		{
			fReturn = fSart + fAbs(fAdd);
			fReturn = fMin(fDest,fReturn);
		}
		else
		{
			fReturn = fSart - fAbs(fAdd);
			fReturn = fMax(fDest,fReturn);
		}
		return fReturn;
	}

	bool CCPtInRect(const cocos2d::Rect& rect,const cocos2d::Point& point)
	{
		if (point.x > rect.origin.x - rect.size.width/2 && point.x < rect.origin.x + rect.size.width/2 &&
			point.y > rect.origin.y - rect.size.height/2 && point.y < rect.origin.y + rect.size.height/2)
		{
			return true;
		}
		return false;
	}
	cocos2d::CCTexture2D* addTexture(std::string kTextureName)
	{
		return cocos2d::CCTextureCache::sharedTextureCache()->addImage(kTextureName.c_str());
	}


	//#define QYGetRValue(rgb)      (LOBYTE(rgb))
	//#define QYGetGValue(rgb)      (LOBYTE(((WORD)(rgb)) >> 8))
	//#define QYGetBValue(rgb)      (LOBYTE((rgb)>>16))
	//#define QYGetAValue(rgb)      (LOBYTE((rgb)>>24))
	//void saveJpgWidthAple(std::string kTextureName)
	//{
	//	std::string kSaveName = getFileName(kTextureName);
	//	cocos2d::CCImage kTexture;
	//	cocos2d::CCImage kAple;
	//	kTexture.initWithImageFile(kTextureName.c_str(),cocos2d::CCImage::kFmtPng);
	//	kAple.initWithImageFile(kTextureName.c_str(),cocos2d::CCImage::kFmtPng);
	//	kTexture.saveToFile((kSaveName+"JpgWithAple"+".jpg").c_str(),false);

	//	int iWidth = kAple.getWidth();
	//	int iHeight = kAple.getHeight();
	//	unsigned char *   m_pDataAple = kAple.getData();
	//	for (int y = 0; y < iHeight; ++y)
	//	{
	//		for (int x = 0; x < iWidth; ++x)
	//		{
	//			int iIdex = y*iWidth+x;
	//			m_pDataAple[iIdex*4] = m_pDataAple[iIdex*4+3];
	//			m_pDataAple[iIdex*4+1] = m_pDataAple[iIdex*4+3];
	//			m_pDataAple[iIdex*4+2] = m_pDataAple[iIdex*4+3];
	//		}
	//	}
	//	kAple.saveToFile((kSaveName+"JpgWithApleAple"+".jpg").c_str(),false);
	//}
	void createAttributeDict(std::map<std::string, std::string>& attributeDict,const char **atts)
	{
		if(atts && atts[0])
		{
			for(int i = 0; atts[i]; i += 2) 
			{
				std::string key = (char*)atts[i];
				
				std::string value = u8_a((char*)atts[i + 1]);
				attributeDict.insert(std::pair<std::string, std::string>(key, value));
			}
		}
	}
	std::string  valueForKey(const char *key, std::map<std::string, std::string>& dict)
	{
		std::map<std::string, std::string>::iterator it = dict.find(key);
		return it!=dict.end() ? it->second.c_str() : "";
	}
	int  valueForInt(const char *key, std::map<std::string, std::string>& dict)
	{
		return parseInt(valueForKey(key,dict));
	}
	float  valueForFloat(const char *key, std::map<std::string, std::string>& dict)
	{
		return parseFloat(valueForKey(key,dict));
	}
	bool  valueForBool(const char *key, std::map<std::string, std::string>& dict)
	{
		return parseBool(valueForKey(key,dict));
	}
	cocos2d::Point valueForPoint(const char *key, std::map<std::string, std::string>& dict)
	{
		return parsePoint(valueForKey(key,dict));
	}
	cocos2d::Size valueForSize(const char *key, std::map<std::string, std::string>& dict)
	{
		return parseSize(valueForKey(key,dict));
	}
	cocos2d::Rect valueForRect(const char *key, std::map<std::string, std::string>& dict)
	{
		return parseRect(valueForKey(key,dict));
	}
	RandFloat valueForRandFloat(const char *key, std::map<std::string, std::string>& dict)
	{
		return parseRandFloat(valueForKey(key,dict));
	}
	RandPos valueForRandPos(const char *key, std::map<std::string, std::string>& dict)
	{
		return parseRandPos(valueForKey(key,dict));
	}
	void valueForFloat4(float* fValue,const char *key, std::map<std::string, std::string>& dict)
	{
		std::string kStr = valueForKey(key,dict);
		std::vector<std::string> kVec = utility::split(kStr,":");
		float fTempValue = 0;
		int iIdex = 0;
		for (iIdex = 0;iIdex<4 && iIdex<(int)kVec.size();iIdex++)
		{
			fValue[iIdex] = parseInt(kVec[iIdex]);
			fTempValue = fValue[iIdex];
		}
		for (;iIdex<4;iIdex++)
		{
			fValue[iIdex] = fTempValue;
		}
	}
	void valueForInt4(int* iValue,const char *key, std::map<std::string, std::string>& dict)
	{
		std::string kStr = valueForKey(key,dict);
		std::vector<std::string> kVec = utility::split(kStr,":");
		CCAssert(kVec.size() != 0,"");
		int iTempValue = 0;
		int iIdex = 0;
		for (iIdex = 0;iIdex<4 && iIdex<(int)kVec.size();iIdex++)
		{
			iValue[iIdex] = parseInt(kVec[iIdex]);
			iTempValue = iValue[iIdex];
		}
		for (;iIdex<4;iIdex++)
		{
			iValue[iIdex] = iTempValue;
		}
	}

	cocos2d::CCTexture2D* createJpgTextureWithAple(std::string kTextureName,std::string kApleName)
	{
		CCAssert(false,"未完成");
		if (std::string::npos == kTextureName.find(".jpg") && 
			std::string::npos == kTextureName.find(".jpeg"))
		{
			return NULL;
		}
		std::string pathKey = cocos2d::FileUtils::getInstance()->fullPathForFilename(kTextureName.c_str());
		if (cocos2d::CCTextureCache::sharedTextureCache()->textureForKey(pathKey.c_str()))
		{
			return cocos2d::CCTextureCache::sharedTextureCache()->textureForKey(pathKey.c_str());
		}
		cocos2d::CCImage kTexture;
		cocos2d::CCImage kAple;
		kTexture.initWithImageFile(kTextureName.c_str());
		kAple.initWithImageFile(kApleName.c_str());
		unsigned char *   m_pDataTexture = kTexture.getData();
		unsigned char *   m_pDataAple = kAple.getData();
		if(kTexture.getWidth() != kAple.getWidth() || kTexture.getHeight() != kAple.getHeight())
		{
			CCLOG("Not Match");
			return NULL;
		}
		int iWidth = kTexture.getWidth();
		int iHeight = kTexture.getHeight();

		unsigned char * pGetData = new unsigned char[iWidth * iHeight * 4];
		memset(pGetData, 0, (int)(iWidth * iHeight * 4));
		for (int y = 0; y < iHeight; ++y)
		{
			for (int x = 0; x < iWidth; ++x)
			{
				int iIdex = y*iWidth+x;
				pGetData[iIdex*4+0] = m_pDataTexture[iIdex*3+0];
				pGetData[iIdex*4+1] = m_pDataTexture[iIdex*3+1];
				pGetData[iIdex*4+2] = m_pDataTexture[iIdex*3+2];
				pGetData[iIdex*4+3] = m_pDataAple[iIdex*3];
			}
		}
		cocos2d::Size kSize;
		kSize.width = iWidth;
		kSize.height = iHeight;
		cocos2d::CCTexture2D* texture = new cocos2d::CCTexture2D();
		//texture->initWithData(pGetData,cocos2d::kCCTexture2DPixelFormat_RGBA8888,kSize.width,kSize.height,kSize);
		//((cocos2d::CCTextureCacheEX*)cocos2d::CCTextureCache::sharedTextureCache())->addTextureForKey(pathKey.c_str(),texture);
		delete pGetData;
		return texture;
	}

	void setSpriteScaleBySize(cocos2d::Node* pSprite,cocos2d::Size kSize)
	{
		if (!pSprite)
		{
			return;
		}
		float fScaleX = 0;
		float fScaleY = 0;
		fScaleX = kSize.width/(float)pSprite->getContentSize().width;
		fScaleY = kSize.height/(float)pSprite->getContentSize().height;
		pSprite->setScaleX(fScaleX);
		pSprite->setScaleY(fScaleY);
	}
	void StringReplace(std::string &strBase, std::string strSrc, std::string strDes)  
	{  
		std::string::size_type pos = 0;  
		std::string::size_type srcLen = strSrc.size();  
		std::string::size_type desLen = strDes.size();  
		pos=strBase.find(strSrc, pos);   
		if ((pos != std::string::npos))  
		{  
			strBase.replace(pos, srcLen, strDes);  
			pos=strBase.find(strSrc, (pos+desLen));  
		}  
	}
	void CCAssertWithDes(bool bAssert,std::string kDes1,std::string kDes2)
	{
		if (bAssert)
		{
			return;
		}
		std::string kDes = kDes1 + kDes2;
		CCAssert(bAssert,kDes.c_str());
	}
	float getMoveTime(cocos2d::Point kSrc,cocos2d::Point kDest,float fSpd)
	{
		if (fSpd <= 0.00f)
		{
			return 0.f;
		}
		return ccpDistance(kSrc,kDest)/fSpd;
	}

	float getMoveTime(float fSrc,float fDest,float fSpd)
	{
		if (fSpd <= 0.00f)
		{
			return 0.f;
		}
		return fAbs(fSrc-fDest)/fSpd;
	}
	cocos2d::Point getDistancePos(cocos2d::Point kSrc,cocos2d::Point kDest,float fDistance)
	{
		if (kSrc.x == kDest.x && kSrc.y == kDest.y)
		{
			return kSrc;
		}
		if (fDistance < 0.001f)
		{
			return kSrc;
		}
		cocos2d::Point kDistance = (kDest - kSrc);
		float fTempDistacne = kDistance.getLength();
		if (fTempDistacne < 0.001f)
		{
			return kSrc;
		}
		cocos2d::Point kReturn = kSrc;
		kReturn.x += kDistance.x/fTempDistacne*fDistance;
		kReturn.y += kDistance.y/fTempDistacne*fDistance;

		return kReturn;
	}
	bool MoveTo(float fSrc,float fDest,float& fkOut,float fDistance)
	{
		float fDis = fAbs(fSrc - fDest);
		if (fDis < 0.001f)
		{
			return true;
		}
		float fPercent = fDistance/fDis;
		if (fPercent>=1.0f)
		{
			fkOut = fDest;
			return true;
		}
		fkOut = fSrc + (fDest - fSrc)*fPercent;
		return false;
	}
	bool MoveTo(cocos2d::Point kSrc,cocos2d::Point kDest,cocos2d::Point& kOut,float fDistance)
	{
		float fDis = kSrc.getDistance(kDest);
		float fPercent = fDistance/fDis;
		if (fPercent>=1.0f)
		{
			kOut = kDest;
			return true;
		}
		kOut.x = kSrc.x + (kDest.x - kSrc.x)*fPercent;
		kOut.y = kSrc.y + (kDest.y - kSrc.y)*fPercent;
		return false;
	}
	cocos2d::Point getAnglePos(cocos2d::Point kSrc,cocos2d::Point kDest,float fAngle)
	{
		if (kSrc.x == kDest.x && kSrc.y == kDest.y)
		{
			return kSrc;
		}
		cocos2d::Point kDistance = (kDest - kSrc);
		float fDistance = kDistance.getLength();
		float fTempAngle = kDistance.getAngle() - fAngle;
		cocos2d::Point kReturn = kSrc;
		kReturn.x += fDistance*cos(fTempAngle);
		kReturn.y += fDistance*sin(fTempAngle);
		return kReturn;
	}
	cocos2d::Point getPosByDistanceAngle(float fDistance,float fRoata)
	{
		cocos2d::Point kReturn;
		kReturn.x = fDistance*cos((90 - fRoata)/180.f*3.14f);
		kReturn.y = fDistance*sin((90 - fRoata)/180.f*3.14f);
		return kReturn;
	}
	cocos2d::Point getPosByAngle(cocos2d::Point kDest,float fRoata)
	{
		float fDistance = kDest.getLength();
		float fAngle = kDest.getAngle();
		cocos2d::Point kReturn;
		kReturn.x = fDistance*cos((90 - fRoata)/180.f*3.14f + fAngle - 3.14/2.0f);
		kReturn.y = fDistance*sin((90 - fRoata)/180.f*3.14f + fAngle - 3.14/2.0f);
		return kReturn;
	}
	bool haveInVector(const std::vector<int>& kList,int iIdex)
	{
		std::vector<int>::const_iterator itor = kList.begin();
		for (;itor != kList.end();itor++)
		{
			if (*itor == iIdex)
			{
				return true;
			}
		}
		return false;
	}
	void saveFile(const char *pContent, std::string pFileName, int length){    
		std::string path = pFileName;    
		FILE* file = fopen(path.c_str(), "wb");   

		if (file) {   
			
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
			std::string str = "savefile pfilename = ";
			str += pFileName;
			str += " pocntent = ";
			str += pContent;
			CrashReport::log(CrashReport::Error,"test",str.c_str());
			cocos2d::log("%s",str.c_str());
#endif
			fwrite(pContent, sizeof(char), length, file);  			
			fclose(file);    
		}     
	}  
	std::string AddFuHao(int iNum)
	{
		if (iNum > 0)
		{
			return utility::toString("+",iNum);
		}
		return utility::toString(iNum);

	}
	void DelIntVectorByIdex(int iIdex,std::vector<int>& kVectors)
	{
		if (iIdex >= (int)kVectors.size())
		{
			CCAssert(false,"");
			return;
		}
		std::vector<int>::iterator itor = kVectors.begin();
		for (;itor != kVectors.end();itor++)
		{
			if (iIdex == 0)
			{
				kVectors.erase(itor);
				break;
			}
			iIdex--;
		}
	}
	void DelIntVectorByValue(int iValue,std::vector<int>& kVectors)
	{
		std::vector<int>::iterator itor = kVectors.begin();
		while (itor != kVectors.end())
		{
			if (iValue == *itor)
			{
				itor = kVectors.erase(itor);
			}
			else
			{
				itor++;
			}
		}
	}

	float getOffectByLR(bool bLeft,float fDistance)
	{
		if (bLeft)
		{
			return -fDistance;
		}
		return fDistance;
	}

	std::string EncodeURL(const std::string &URL )
	{
		std::string src = URL;
		char hex[] = "0123456789ABCDEF";
		std::string dst;


		for (size_t i = 0; i < src.size(); ++i)
		{
			unsigned char cc = src[i];
			if ( cc >= 'A' && cc <= 'Z' 
				|| cc >='a' && cc <= 'z'
				|| cc >='0' && cc <= '9'
				|| cc == '.'
				|| cc == '_'
				|| cc == '-'
				|| cc == '*')
			{
				if (cc == ' ')
				{
					dst += "+";
				}
				else
					dst += cc;
			}
			else
			{
				unsigned char c = static_cast<unsigned char>(src[i]);
				dst += '%';
				dst += hex[c / 16];
				dst += hex[c % 16];
			}
		}
		return dst;

	}
	std::string DecodeURL(const std::string &URL)
	{
		std::string result;  
		int hex = 0;  
		for (size_t i = 0; i < URL.length(); ++i)  
		{  
			switch (URL[i])  
			{  
			case '+':  
				result += ' ';  
				break;  
			case '%':  
				if (isxdigit(URL[i + 1]) && isxdigit(URL[i + 2]))  
				{  
					std::string hexStr = URL.substr(i + 1, 2);  
					hex = strtol(hexStr.c_str(), 0, 16);  
					//字母和数字[0-9a-zA-Z]、一些特殊符号[$-_.+!*'(),] 、以及某些保留字[$&+,/:;=?@]  
					//可以不经过编码直接用于URL  
					if (!((hex >= 48 && hex <= 57) || //0-9  
						(hex >=97 && hex <= 122) ||   //a-z  
						(hex >=65 && hex <= 90) ||    //A-Z  
						//一些特殊符号及保留字[$-_.+!*'(),]  [$&+,/:;=?@]  
						hex == 0x21 || hex == 0x24 || hex == 0x26 || hex == 0x27 || hex == 0x28 || hex == 0x29  
						|| hex == 0x2a || hex == 0x2b|| hex == 0x2c || hex == 0x2d || hex == 0x2e || hex == 0x2f  
						|| hex == 0x3A || hex == 0x3B|| hex == 0x3D || hex == 0x3f || hex == 0x40 || hex == 0x5f  
						))  
					{  
						result += char(hex);  
						i += 2;  
					}  
					else result += '%';  
				}else {  
					result += '%';  
				}  
				break;  
			default:  
				result += URL[i];  
				break;  
			}  
		}  
		return result;  
	}
	int getVectorIdex(std::vector<int>& kVector,int iValue)
	{
		for (int i = 0;i<(int)kVector.size();i++)
		{
			if (kVector[i] == iValue)
			{
				return i;
			}
		}
		return -1;
	}

	std::string lineFeeds( const std::string &str, int iCurrentIndex )
	{
		if (typeid(str) == typeid(std::string) && str.length() > 0 &&iCurrentIndex > 0) {
			std::stringstream result;
			std::vector<std::string> temp;
			temp = parseUTF8(str); 
			int iStringLength = temp.size();
			for (int i = 0;i < iStringLength;i++) {
				result<<temp[i];
				if (iCurrentIndex == i)
					result<<"\n";
			}
			return result.str();
		} else {
			return "";
		}
	}

	std::vector<std::string> parseUTF8( const std::string &str )
	{
		int l = str.length();
		std::vector<std::string> ret;
		ret.clear();
		for(int p = 0; p < l; ) {
			int size;
			unsigned char c = str[p];
			if(c < 0x80) {
				size = 1;
			} else if(c < 0xc2) {
			} else if(c < 0xe0) {
				size = 2;
			} else if(c < 0xf0) {
				size = 3;
			} else if(c < 0xf8) {
				size = 4;
			} else if (c < 0xfc) {
				size = 5;
			} else if (c < 0xfe) {
				size = 6;
			}
			std::string temp = "";
			temp = str.substr(p, size);
			ret.push_back(temp);
			p += size;
		}
		return ret;
	}

	int getUTF8ByCout( const std::string& str )
	{
		int iCout = 0;
		int iActCout = 0;
		int l = str.length();
		for(int p = 0; p < l; ) 
		{
			int size = 0;
			unsigned char c = str[p];
			if(c < 0x80) 
			{
				size = 1;
				iActCout+=1;
			} 
			
			else if(c < 0xc2) 
			{
				iActCout+=1;
			} 
			else if(c < 0xe0) 
			{
				iActCout+=2;
				size = 2;
			} 
			else if(c < 0xf0) 
			{
				iActCout+=2;
				size = 3;
			} 
			else if(c < 0xf8) 
			{
				iActCout+=2;
				size = 4;
			} 
			else if (c < 0xfc) 
			{
				iActCout+=2;
				size = 5;
			} 
			else if (c < 0xfe) 
			{
				iActCout+=2;
				size = 6;
			}
			p += size;
			iCout++;
		}
		return iCout;
	}
	bool isNumAZ( const std::string& str)
	{
		int l = str.length();
		for(int p = 0; p < l;p++) 
		{
			if ((str[p] >= '0' && str[p] <= '9') ||
				(str[p] >= 'a' && str[p] <= 'z') ||
				(str[p] >= 'A' && str[p] <= 'Z'))
			{
				continue;
			}
			return false;
		}
		return true;
	}
	std::string subUTF8( const std::string &str,int from, int to )
	{
		if(from > to) return "";
		std::vector<std::string> test = parseUTF8(str);
		if ((int)test.size() < to) return str;
		std::vector<std::string>::iterator iter = test.begin();
		std::string res;
		std::string result;
		for(iter=(test.begin() + from); iter != (test.begin() + to); iter++)
		{
			res += *iter;

		}
		return res;
	}

	std::string getSameSizeValue10(int iValue)
	{
		if (iValue < 10)
		{
			return utility::toString("0",iValue);
		}
		return utility::toString(iValue);
	}

	UserString valueForUserString(const char *key, std::map<std::string, std::string>& dict)
	{
		return parseUserString(valueForKey(key, dict));
	}

	UserString parseUserString(std::string kStr)
	{
		UserString kValue;
		std::vector<std::string> kVec = utility::split(kStr, ":");
		if (kVec.size() && kVec[0] == "Key")
		{
			kValue.kUserKey = kVec[1];
		} else if (kVec.size() == 1)
		{
			kValue.kUserValue = kVec[0];
		} else
		{
			CCASSERT(false, "");
		}
		return kValue;
	}
	std::string getUserString(const UserString& kUserString, cocos2d::Node* pNode)
	{
		if (kUserString.kUserKey != "")
		{
			return WidgetFun::getWidgetUserInfo(pNode, kUserString.kUserKey);
		}
		return kUserString.kUserValue;
	}

	cocos2d::Vec2 getRandPos(const RandPos& kRand, cocos2d::Node* pNode)
	{
		if (kRand.kUserKey != "")
		{
			return utility::parsePoint(WidgetFun::getWidgetUserInfo(pNode, kRand.kUserKey));
		}
		float fValueX = getRandFloat(kRand.kRandX, pNode);
		float fValueY = getRandFloat(kRand.kRandY, pNode);
		return cocos2d::Vec2(fValueX, fValueY);
	}

	std::string getScriptReplaceValueStr(std::string kSrc, std::string kValue1, std::string kValue2, std::string kValue3)
	{
		std::string kScriptStr = ScriptData<std::string>(kSrc.c_str()).Value();
		if (kValue1 != "")
		{
			utility::StringReplace(kScriptStr, "#", kValue1);
		}
		if (kValue2 != "")
		{
			utility::StringReplace(kScriptStr, "#", kValue2);
		}
		if (kValue3 != "")
		{
			utility::StringReplace(kScriptStr, "#", kValue3);
		}
		return kScriptStr;
	}
	bool IsSpriteInTouch(cocos2d::Vec2 kWorldPos, cocos2d::Sprite *pSrite)
	{
		kWorldPos = pSrite->convertToNodeSpace(kWorldPos);
		cocos2d::Size elementSize = pSrite->getContentSize();
		cocos2d::Rect elementRect;

		cocos2d::Vec2 kAnchor = pSrite->getAnchorPoint();

		elementRect = cocos2d::Rect(
			0, 0,
			elementSize.width,
			elementSize.height
			);

		return elementRect.containsPoint(kWorldPos);
	}

	bool isAllVisible(cocos2d::Node* pNode)
	{
		while (pNode)
		{
			if (!pNode->isVisible())
			{
				return false;
			}
			pNode = pNode->getParent();
		}
		return true;
	}
	float getRandFloat(const RandFloat& kRand, cocos2d::Node* pNode)
	{
		if (kRand.kUserKey != "")
		{
			return utility::parseFloat(WidgetFun::getWidgetUserInfo(pNode, kRand.kUserKey));
		}
		int iRand = (int)((kRand.fMax - kRand.fMin) * 10);
		if (iRand == 0)
		{
			return kRand.fMin;
		}
		if (iRand < 0)
		{
			return kRand.fMax + (float)(rand() % (-iRand) / 10.0f);
		}

		return kRand.fMin + (float)(rand() % (iRand) / 10.0f);
	}


	float getRotation(cocos2d::Point kSrcPos,cocos2d::Point kDestPoint)
	{
		cocos2d::CCPoint kDestTance = kDestPoint - kSrcPos;
		float fAngle = kDestTance.getAngle();
		return (-fAngle*180.0f/3.14f);
	}
	cocos2d::Point getOffectParentPos(cocos2d::Node* pNode,cocos2d::Point kOffect)
	{
		cocos2d::Mat4 tmp = pNode->getNodeToParentTransform();
		tmp.m[12] = 0;
		tmp.m[13] = 0;
		cocos2d::Vec3 vec3(kOffect.x, kOffect.y, 0);
		cocos2d::Vec3 ret;
		tmp.transformPoint(vec3,&ret);
		return cocos2d::Vec2(ret.x, ret.y);

	}
	cocos2d::BezierToEx* createBezierAction(float fTime,cocos2d::Point kStartPos,cocos2d::Point kEndPos)
	{
		float fDistance = kEndPos.x - kStartPos.x;
		int		iBezierY = abs((fDistance))/2.f+100;
		cocos2d::ccBezierConfig bezier;
		bezier.controlPoint_1 = cocos2d::Vec2(kStartPos.x, kStartPos.y);
		bezier.controlPoint_2 = cocos2d::Vec2(kStartPos.x+fDistance/2, kStartPos.y+iBezierY);
		bezier.endPosition = cocos2d::Vec2(kEndPos.x,kEndPos.y);

		return cocos2d::BezierToEx::create(fTime, bezier);
	}

	void schedule(cocos2d::SEL_SCHEDULE selector,cocos2d::Ref* pTarget)
	{
		cocos2d::Director::getInstance()->getScheduler()->schedule(
			selector,pTarget,0.0f,false);
	}
	void unschedule(cocos2d::SEL_SCHEDULE selector,cocos2d::Ref* pTarget)
	{
		cocos2d::Director::getInstance()->getScheduler()->unschedule(selector,pTarget);
	}
	void scheduleOnce(cocos2d::SEL_SCHEDULE selector,cocos2d::Ref* pTarget,float interval)
	{
		cocos2d::Director::getInstance()->getScheduler()->schedule(selector, pTarget, interval, 0, 0.0f, false);
	}
	std::string getScriptReplaceValue(std::string kSrc,std::string kValue1,std::string kValue2,std::string kValue3)
	{
		std::string kScriptStr = ScriptData<std::string>(kSrc.c_str()).Value();
		if (kValue1 != "")
		{
			utility::StringReplace(kScriptStr,"#",kValue1);
		}
		if (kValue2 != "")
		{
			utility::StringReplace(kScriptStr,"#",kValue2);
		}
		if (kValue3 != "")
		{
			utility::StringReplace(kScriptStr,"#",kValue3);
		}
		return kScriptStr;
	}
	std::string getShortGoldValue(int iGold)
	{
		std::string kFuHao = "";
		if (iGold < 0)
		{
			iGold = -iGold;
			kFuHao = "-";
		}
		std::string kTempTxt;
		std::string kGoldStr = utility::toString(iGold);
		int iCout = 0;
		int iTempGold = iGold;
		int iLastValue = 0;
		while (iTempGold >= 10)
		{
			iTempGold = iTempGold/10;
			iCout ++;
		}
		if (iCout > 7)
		{
			iTempGold = iGold/100000000;
			iLastValue = (iGold/10000)%10000;
			static ScriptData<std::string> s_kTxt("PlayerGoldTxt2");
			kTempTxt = s_kTxt.Value();
		}
		else if (iCout > 3)
		{
			iTempGold = iGold/10000;
			iLastValue = iGold%10000;
			static ScriptData<std::string> s_kTxt("PlayerGoldTxt3");
			kTempTxt = s_kTxt.Value();
		}
		else
		{
			return utility::toString(kFuHao,iGold);
		}
		std::string kTxt1 = utility::toString(iTempGold);
		std::string kTxt2 = utility::toString(iLastValue);
		if (iLastValue == 0)
		{
			kTxt1.push_back('.');
			kTxt1.push_back('0');
		}
		else
		{
			int iSize = kTxt2.size();
			for (int i = 0;i<4-iSize;i++)
			{
				kTxt2 = utility::toString("0",kTxt2);
			}
			int iTempCout1 = kTxt1.size();
			if (iTempCout1 < 4)
			{
				kTxt1.push_back('.');
				for (int i = 0;i<4-iTempCout1 && i < (int)kTxt2.size();i++)
				{
					kTxt1.push_back(kTxt2[i]);
				}
			}
		}
		return utility::toString(kFuHao,kTxt1,kTempTxt);
	}


	long  getCurrentTime()
	{
		struct  timeval tv;
		gettimeofday(&tv, NULL);
		return  tv.tv_sec * 1000 + tv.tv_usec / 1000;
	}

} 
