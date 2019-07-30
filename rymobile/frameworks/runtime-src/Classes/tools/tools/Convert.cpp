/************************************************************************/
/* http://blog.csdn.net/coollofty/article/details/8058859               */
/************************************************************************/
#include "Convert.h"
#include "tools/tools/StringData.h"


#if(CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#include "../iconv/iconv.h"
#endif


#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)

// #include "../../../../libiconv/include/iconv.h"
//#include "iconv/iconv.h"
#include "../../libiconv/include/iconv.h"

#include <Jni.h>
#include "cocos/platform/android/jni/JniHelper.h"

#endif

#if(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#include <iconv.h>
#endif

USING_NS_CC;

//////////////////////////////////////////////////////////////////////////

/**
 * 计算utf8字符串长度
 * @param utf8 utf8字符串 
 * @return 字符串长度
 */
int utf8_len(const char *utf8) 
{
	int i = 0, j = 0;
	while (utf8[i]) 
	{
		if ((utf8[i] & 0xc0) != 0x80)
		{
			j++;
		}
		i++;
	}
	return j;
}

int utf8_cmp(const char* str1, const char* str2)
{
    unsigned int len1=(unsigned int)strlen((char*)str1);   
    unsigned int len2=(unsigned int)strlen((char*)str2);   
    unsigned int len = (len1<len2) ? len1 : len2;   
   
    int ret = memcmp(str1,str2,len);   
    if(ret == 0){   
        if(len1 > len2) ret = 1;   
        else if(len1 < len2) ret = -1;   
    }   
    return ret;   
}

/**
 * 计算ucs2字符串长度
 * @param ucs2 ucs2字符串 
 * @return 字符串长度
 */
int ucs2_len(const unsigned short* ucs2)
{
	int i = 0;
	while (ucs2[i] != 0)
	{
		char c0 = ucs2[i]&0xff;
		char c1 = ucs2[i]>>8&0xff;

		if (c0 == '\0' && c1 == '\0')
			break;
		++i;
	}

	return i;
}

/////////////////////////////////////////////////////////////////////////////
int code_convert(const char *from_charset, const char *to_charset, const char *inbuf, size_t inlen, char *outbuf, size_t outlen)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	iconv_t cd;
    const char *temp = inbuf;
    const char **pin = &temp;
    char **pout = &outbuf;
    //memset(outbuf,0,outlen);
    cd = iconv_open(to_charset,from_charset);
    if(cd==0) return -1;
    if(-1==iconv(cd,pin,&inlen,pout,&outlen)) return -1;
    iconv_close(cd);
    return 0;
#endif
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	iconv_t cd;
	const char *temp = inbuf;
	const char **pin = &temp;
	char **pout = &outbuf;
	//memset(outbuf,0,outlen);
	cd = iconv_open(to_charset,from_charset);
	if(cd==0) return -1;
	if(-1==iconv(cd, (char **)(pin),&inlen,pout,&outlen)) return -1;
	iconv_close(cd);
	return 0;
#endif
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
//	iconv_t cd;
//	const char *temp = inbuf;
//	const char **pin = &temp;
//	char **pout = &outbuf;
//	//memset(outbuf,0,outlen);
//	cd = iconv_open(to_charset,from_charset);
//	if(cd==0) return -1;
//	if(-1==iconv(cd,(char**)(pin),&inlen,pout,&outlen)) return -1;
//	iconv_close(cd);
//	return 0;
#endif
    return -1;
}
     
/*UTF8转为gbk*/
std::string u2a(const char *inbuf)
{
    size_t inlen = strlen(inbuf);
	std::string strRet;
    strRet.resize(inlen * 2 + 2);

   if(code_convert("utf-8", "gbk", inbuf, inlen, &strRet[0], strRet.size()))
       return inbuf;

    return strRet;
}

/*gbk转为UTF8*/
std::string a2u(const char *inbuf)
{
	size_t inlen = strlen(inbuf);
	std::string strRet;
    strRet.resize(inlen * 2 + 2);

    if(code_convert("gbk", "utf-8", inbuf, inlen, &strRet[0], strRet.size()))
       return inbuf;
    return strRet;
}

/*gbk转为UTF16*/
std::string a2l(const char *inbuf)
{
	size_t inlen = strlen(inbuf);
	std::string strRet;
	strRet.resize(inlen * 2 + 2);

	if(code_convert("gbk", "UTF-16LE", inbuf, inlen, &strRet[0], strRet.size()))
		return inbuf;
	return strRet;
}


/*utf16转为UTF8*/
std::string l2u(const char *inbuf)
{
	size_t inlen = ucs2_len((const unsigned short*)&inbuf[0]);
	std::string strRet;
    strRet.resize(inlen * 2 + 2);

    if(code_convert("UTF-16LE", "utf-8", inbuf, inlen*2, &strRet[0], strRet.size()))
       return inbuf;

    return strRet;
}

///*UTF8转为utf16*/
//std::string u2l(const char *inbuf)
//{
//	size_t inlen = ucs2_len((const unsigned short*)&inbuf[0]);
//	std::string strRet;
//    strRet.resize(inlen * 2 + 2);
//
//    if(!code_convert("utf-8", "UTF-16LE", inbuf, inlen, &strRet[0], strRet.size()) == 0)
//    {
//       return "";
//    }
//	return strRet;
//}

/*UTF8转为utf16*/
std::string u2l(const char *inbuf)
{
	return a2l(u8_a(inbuf));
}

/////////////////////////////////////////////////////////////////////////////
/**
 * 将utf8字符转换成ucs2字符
 * @param utf8	待转换的utf8字符串
 * @param wchar	转换后的ucs2字符
 * @return int 转换所需utf8字符个数
 */
inline int utf8_ucs2_one(const char* utf8, unsigned short& wchar)
{
	//首字符的Ascii码大于0xC0才需要向后判断，否则，就肯定是单个ANSI字符了
	unsigned char firstCh = utf8[0];
	if (firstCh >= 0xC0)
	{
		//根据首字符的高位判断这是几个字母的UTF8编码
		int afters, code;
		if ((firstCh & 0xE0) == 0xC0)
		{
			afters = 2;
			code = firstCh & 0x1F;
		}
		else if ((firstCh & 0xF0) == 0xE0)
		{
			afters = 3;
			code = firstCh & 0xF;
		}
		else if ((firstCh & 0xF8) == 0xF0)
		{
			afters = 4;
			code = firstCh & 0x7;
		}
		else if ((firstCh & 0xFC) == 0xF8)
		{
			afters = 5;
			code = firstCh & 0x3;
		}
		else if ((firstCh & 0xFE) == 0xFC)
		{
			afters = 6;
			code = firstCh & 0x1;
		}
		else
		{
			wchar = firstCh;
			return 1;
		}

		//知道了字节数量之后，还需要向后检查一下，如果检查失败，就简单的认为此UTF8编码有问题，或者不是UTF8编码，于是当成一个ANSI来返回处理
		for(int k = 1; k < afters; ++ k)
		{
			if ((utf8[k] & 0xC0) != 0x80)
			{
				//判断失败，不符合UTF8编码的规则，直接当成一个ANSI字符返回
				wchar = firstCh;
				return 1;
			}

			code <<= 6;
			code |= (unsigned char)utf8[k] & 0x3F;
		}

		wchar = code;
		return afters;
	}
	else if (firstCh == 0 || firstCh == '\0')
	{
		wchar = '\0'<<8|'\0';
		return 0;
	}
	
	wchar = firstCh;
	return 1;
}

/**
 * 将utf8字符串转换为ucs2字符串
 * @param utf8 待转换的utf8字符串
 * @return 转换后ucs2字符串
 */
u2string utf8_ucs2(const char* utf8)
{	
	u2string ret;
	int utf8len = utf8_len(utf8);

	ret.resize(utf8len*2+1, '\0');

	u1string xx = u2l(utf8);
	int size = xx.size();
	memcpy(&ret[0], &xx[0], size);
	return ret;
}

/**
 * 将ucs2字符转换成utf8字符
 * @param wchar	待转换的ucs2字符串
 * @param utf8	转换后的utf8字符数组
 * @return int 转换所得utf8字符个数
 */
inline int ucs2_utf8_one(unsigned short wchar, char *utf8)
{
	if (wchar == 0)
	{
		*utf8 = '\0';
		return 0;
	}

	int len = 0;
	if (wchar < 0xC0)
	{ 
		utf8[len ++] = (char)wchar;
	}
	else if (wchar < 0x800)
	{
		utf8[len ++] = 0xc0 | (wchar >> 6);
		utf8[len ++] = 0x80 | (wchar & 0x3f);
	}
	else
	{
		utf8[len ++] = 0xe0 | (wchar >> 12);
		utf8[len ++] = 0x80 | ((wchar >> 6) & 0x3f);
		utf8[len ++] = 0x80 | (wchar & 0x3f);
	}

	return len;
}

/**
 * 将ucs2字符串转换为utf8字符串
 * @param ucs2 待转换的ucs2字符串
 * @return 转换后utf8字符串
 */
u1string ucs2_utf8(const unsigned short *ucs2)
{	
	static u1string ret;
	int ucs2len = ucs2_len(ucs2);

	ret.resize(ucs2len*4+1, '\0');

	int count = 0;
	for (int i = 0; i < ucs2len; ++i)
	{
		int len = ucs2_utf8_one(ucs2[i], &ret[count]);
		if (len == 0)
			break;
		count+=len;
	}

	ret[count] = '\0';
	return ret;
}

u1string ucs1_utf8(const unsigned char *ucs1,const int len)
{
	static u1string ret;
	ret.resize(len + 1);

	for (int i = 0;i < len; i++)
	{
		ret[i] = ucs1[i];
	}

	ret[len] = '\0';
	return ret;
}

/**
 * 将gbk字符串转换为utf8字符串
 * @param gbk 待转换的mbcs字符串
 * @return 转换后utf8字符串
 */
u1string StringConvert::gbk_utf8(const char* gbk)
{
	return a2u(gbk);
}

/**
 * 将utf8字符串转换为mbcs字符串
 * @param utf8 待转换的utf8字符串
 * @return 转换后mbcs字符串
 */
u1string StringConvert::utf8_gbk(const char* utf8)
{
	return u2a(utf8);
}


int StringConvert::StringToInt(const std::string& str)
{
	std::stringstream ss;
	ss << str.c_str();
	int i = 0;
	ss >> i;
	return i;
}


//-----------------------------------------------------------
std::string StringConvert::IntToString(int i)
{
	char buff[128] = {};
	std::stringstream ss;
	ss << i;
	ss >> buff;
	return std::string(buff);

}


//-----------------------------------------------------------
float StringConvert::StringTofloat(const std::string& str)
{

	std::stringstream ss;
	ss << str.c_str();
	float f = 0.0f;
	ss >> f;
	return f;
}

//-----------------------------------------------------------
std::string StringConvert::floatToString(float f)
{
	char buff[128] = {};
	std::stringstream ss;
	ss << f;
	ss >> buff;
	return std::string(buff);
}


long StringConvert::StringToLong(const std::string& str)
{
	std::stringstream ss;
	ss << str.c_str();
	long i = 0;
	ss >> i;
	return i;
}


//#if (CC_TARGET_PLATFORM==CC_PLATFORM_ANDROID)
//long SimpleTools::StringToLongLong(const std::string& str)
//{
//	std::stringstream ss;
//	ss << str.c_str();
//	long i = 0;
//	ss >> i;
//	return i;
//}
//#else
LONGLONG StringConvert::StringToLongLong(const std::string& str)
{
	std::stringstream ss;
	ss << str.c_str();
	LONGLONG i = 0;
	ss >> i;
	return i;
}

//#endif

//std::string SimpleTools::LongLongToString(LONGLONG i)
//{
//	char buff[128] = {};
//	std::stringstream ss;
//	ss << i;
//	ss >> buff;
//	return std::string(buff);
//
//}


//-----------------------------------------------------------
std::string StringConvert::LongToString(long i)
{
	char buff[128] = {};
	std::stringstream ss;
	ss << i;
	ss >> buff;
	return std::string(buff);

}

std::vector<std::string> StringConvert::parseUTF8(const std::string &str)
{
	int l = str.length();
	std::vector<std::string> ret;
	ret.clear();
	for (int p = 0; p < l;)
	{
		int size = 0;
		unsigned char c = str[p];
		if (0x00 == c)
		{
			break;
		}
		if (c < 0x80) {
			size = 1;
		}
		else if (c < 0xc2)
		{
			size = 2;
		}
		else if (c < 0xe0)
		{
			size = 2;
		}
		else if (c < 0xf0)
		{
			size = 3;
		}
		else if (c < 0xf8)
		{
			size = 4;
		}
		else if (c < 0xfc)
		{
			size = 5;
		}
		else if (c < 0xfe)
		{
			size = 6;
		}
		else
		{
			size = 7;
		}			
		std::string temp = "";
		temp = str.substr(p, size);
		ret.push_back(temp);
		p += size;
	}
	return ret;
}

std::string StringConvert::subUTF8(const std::string &str, int from, int to)
{
	if (from > to) return "";

	if (str.length() < to) return "";
	std::vector<std::string> vstr = parseUTF8(str);
	
	std::vector<std::string>::iterator iter = vstr.begin();	
//#ifdef _DEBUG
	//分析之后的字比from小，直接返回
	if (from > vstr.size())
	{
		assert(false);
		return "";
	}
	if (to > vstr.size())
	{
		assert(false);
		return "";
	}
//#endif
	
	std::string res;
	std::string result;
	
	for (iter = (vstr.begin() + from); iter != (vstr.begin() + to); iter++)
	{
		res += *iter;
	}
	return res;
}


std::string StringConvert::SimpleScore(LONGLONG  Score)
{
	char tmpSrc[20] = {};
	std::string str = "";
	float  simplescore = 0;
	if (Score > 100000000)
	{
		 simplescore = Score / 100000000.0f;
		 str = SSTRING("big_num5");
	}
	else if (Score>10000)
	{
		 simplescore = Score / 10000.0f;
		 str =  SSTRING("big_num4");
		
	}
	else
	{

		return  str = StringUtils::format("%lld", Score);
	}
	
	sprintf(tmpSrc, "%.4f", simplescore);
	std::string tmpS = tmpSrc;
	int length = tmpS.length();
	if (length > 5)
	{
		tmpS = tmpS.substr(0, 5);
	}
	int nFind = tmpS.find(".");

	int nLength = 0;
	for (int n = tmpS.length(); n >= nFind && n >= 1; --n)
	{
		if ('0' == tmpS[n - 1])
		{
			++nLength;
		}
		else
		{
			if ('.' == tmpS[n - 1])
			{
				++nLength;
			}
			break;
		}
	}
	tmpS = tmpS.substr(0, tmpS.length() - nLength);
	tmpS = tmpS + str;
	return tmpS;

}








int StringConvert::strGBKLength(const std::string &str)
{
	return parseUTF8(str).size();
}

int StringConvert::lenghOfU8Str(const char * pStr)
{
	u2string ucs2 = u8_2s(pStr);
	return ucs2_len(&ucs2[0]);
}



LONGLONG StringConvert::ConvertPhoneNumber(const std::string &str)
{
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	if ("" == str || "0" == str)
	{
		return 0;
	}
	JniMethodInfo minfo;
	//isMobileNO 是有效的返回 true
	jboolean isMobile = false;
	bool ret = JniHelper::getStaticMethodInfo(minfo, "org/cocos2dx/lua/Tools", "isMobileNO", "(Ljava/lang/String;)Z");
	//std::string tempStr = "str1 = "+str+"mobile = "+isMobile;
	//ShowToast("str1");
	if (ret)
	{
		jstring jStrAccounts = minfo.env->NewStringUTF(str.c_str());
		log("isMobileNO ...............");
		//锟斤拷锟斤拷锟斤拷ID锟酵凤拷锟斤拷ID锟斤拷小锟侥凤拷锟斤拷锟斤拷写锟?锟斤拷一锟斤拷锟斤拷母锟角达拷写
		isMobile = minfo.env->CallStaticBooleanMethod(minfo.classID, minfo.methodID, jStrAccounts);
		//cocos2d::log("ConvertPhoneNumber ib mobile %d",isMobile);
		//ShowToast("str2 = "+str+"mobile = "+isMobile);
		//ShowToast("str2");
	}
	LONGLONG num = -1;
	if (isMobile)
	{
		num = StringToLongLong(str);
		//ShowToast("str4");
	} 
	//ShowToast("str3 = " + str + "mobile = " + isMobile+" num = "+num);
	//ShowToast("str3");
	return num;
#else
	LONGLONG num = 0;
	do
	{
		if ("" == str || "0" == str)
		{
			break;
		}
		try
		{
			num = StringToLongLong(str);
			//num = strtoll(str.c_str(), NULL, 10);
		}
		catch (...)
		{
			num = -1; //格式不对
			break;
		}
		//第一个数字要为1
		if (10000000000 > num || 20000000000 < num)
		{
			num = -2;//格式不对
			break;
		}
	} while (0);

	return num;
#endif
}

bool StringConvert::IsNumber(const std::string& str)
{
	for (int i = 0; i<str.size(); i++)
	{
		if ((str.at(i)>'9') || (str.at(i) < '0'))
		{
			return   false;
		}
	}
	return   true;
}

