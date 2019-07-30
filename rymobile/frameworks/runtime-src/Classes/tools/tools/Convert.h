#ifndef _Convert_H_
#define _Convert_H_
#include <vector>
#include <string>

#include "cocos2d.h"
#include "platform/df/types.h"
typedef std::vector<unsigned short> u2string;
typedef std::vector<unsigned char>  u1stringEx;
typedef std::string					u1string;

class StringConvert
{
public:
	/**
	* 将gbk字符串转换为utf8字符串
	* @param gbk 待转换的gbk字符串
	* @return 转换后utf8字符串
	*/
	static std::string gbk_utf8(const char* gbk);

	/**
	* 将utf8字符串转换为gbk字符串
	* @param utf8 待转换的utf8字符串
	* @return 转换后gbk字符串
	*/
	static std::string utf8_gbk(const char* utf8);


	/**@字符转int
	*/
	static int StringToInt(const std::string & str);

	/**@int转字符
	*/
	static  std::string IntToString(int i);

	/**@字符转float
	*/
	static float StringTofloat(const std::string& str);

	/**@float转string
	*/
	static std::string floatToString(float f);

	/**@字符转Dword
	*/
	static long StringToLong(const std::string& str);

	/**@long转字符
	*/
	static  std::string LongToString(long i);

	//取utf8子串
	static std::string subUTF8(const std::string &str, int from, int to);

	//得到字符串长度
	static int strGBKLength(const std::string &str);

	//简化玩家金币显示
	static std::string SimpleScore(LONGLONG Score);
	

	//得到u8的长度
	static int lenghOfU8Str(const char * pStr);

	/*电话号码验证
	str >=0 成功
	str < 0 失败
	*/
	static LONGLONG ConvertPhoneNumber(const std::string & str);
	/**@string转long long
	*/
	static LONGLONG StringToLongLong(const std::string& str);

	//判断是否是字数 不检查小数点
	// true 是数字 false 不是数字
	static bool IsNumber(const std::string& str);

private:
	static std::vector<std::string> parseUTF8(const std::string &str);
};

/**
 * 计算utf8字符串长度
 * @param utf8 utf8字符串 
 * @return 字符串长度
 */
int utf8_len(const char *utf8);

int utf8_cmp(const char* str1, const char* str2);

/**
 * 计算ucs2字符串长度
 * @param ucs2 ucs2字符串 
 * @return 字符串长度
 */
int ucs2_len(const unsigned short* ucs2);

/**
 * 将utf8字符串转换为ucs2字符串
 * @param utf8 待转换的utf8字符串
 * @return 转换后ucs2字符串
 */
u2string utf8_ucs2(const char* utf8);

/**
 * 将ucs2字符串转换为utf8字符串
 * @param ucs2 待转换的ucs2字符串
 * @return 转换后utf8字符串
 */
u1string ucs2_utf8(const unsigned short *ucs2);
u1string ucs1_utf8(const unsigned char *ucs1,const int len);


//////////////////////////////////////////////////////////////////////////
// 辅助函数

#define a_u8(str)	StringConvert::gbk_utf8(str).c_str()
#define u8_a(str)	StringConvert::utf8_gbk(str).c_str()

#define u2_8(ucs2)	ucs2_utf8((const unsigned short*)ucs2).c_str()
#define u8_2(utf8)	&utf8_ucs2(utf8)[0]
#define u8_2s(utf8)	utf8_ucs2(utf8)

#endif // _Convert_H_