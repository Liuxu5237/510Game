/*!
@file
@author		Albert Semenov
@date		11/2007
*/
/*
This file is part of MyGUI.

MyGUI is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

MyGUI is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with MyGUI.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef __MYGUI_STRING_UTILITY_H__
#define __MYGUI_STRING_UTILITY_H__

#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
#include "cocos2d.h"
#include <string>
#include "DictionaryAide.h"
using namespace std;

USING_NS_CC;

namespace utility
{
	typedef std::vector<std::string> VectorString;
	typedef std::map<std::string, VectorString> MapVectorString;
	inline void trim(std::string& _str, bool _left = true, bool _right = true)
	{
		if (_right) _str.erase(_str.find_last_not_of(" \t\r") + 1);
		if (_left) _str.erase(0, _str.find_first_not_of(" \t\r"));
	}
	// конвертирование в строку
	template<typename T>
	inline std::string toString (T p)
	{
		std::ostringstream stream;
		stream << p;
		return stream.str();
	}

	template<typename T>
	bool haveInVector(const std::vector<T>& pVector,T pValue)
	{
		typename std::vector<T>::const_iterator itor = pVector.begin();
		for(;itor != pVector.end();itor++)
		{
			if (*itor == pValue)
			{
				return true;
			}
		}
		return false;
	}

	template<typename T>
	bool removeInVector(const std::vector<T>& pVector,T pValue)
	{
		typename std::vector<T>::const_iterator itor = pVector.begin();
		for(;itor != pVector.end();itor++)
		{
			if (*itor == pValue)
			{
				pVector.erase(pValue);
				return true;
			}
		}
		return false;
	}

	inline const std::string& toString (const std::string& _value)
	{
		return _value;
	}


	template<typename T>
	inline T InRang (const T& iValue,const T& iMax)
	{
		T kTemp = iValue;
		if (kTemp < 0)
		{
			kTemp = 0;
		}
		if (kTemp > iMax)
		{
			kTemp = iMax;
		}
		return kTemp;
	}

	template<typename T>
	inline T Max (const T& iValue1,const T& iValue2)
	{
		return  (((iValue1) > (iValue2)) ? (iValue1) : (iValue2));
	}

	template<typename T>
	inline T Min (const T& iValue1,const T& iValue2)
	{
		return  (((iValue1) < (iValue2)) ? (iValue1) : (iValue2));
	}

	template<typename T>
	inline bool IsInRang (const T& iValue,const T& iValue1,const T& iValue2)
	{
		if (iValue1 < iValue2)
		{
			if (iValue >= iValue1 && iValue <= iValue2)
			{
				return true;
			}
			return false;
		}
		if (iValue >= iValue2 && iValue <= iValue1)
		{
			return true;
		}
		return false;
	}

	template<typename T>
	inline T InRang (const T& iValue,const T& iMin,const T& iMax)
	{
		T kTemp = iValue;
		if (kTemp < iMin)
		{
			kTemp = iMin;
		}
		if (kTemp > iMax)
		{
			kTemp = iMax;
		}
		return kTemp;
	}

	template<typename T>
	inline T Abs (const T& iValue)
	{
		return iValue > 0?iValue:-iValue;
	}


	template<typename T1,  typename T2>
	inline std::string toString (T1 p1, T2 p2)
	{
		std::ostringstream stream;
		stream << p1 << p2;
		return stream.str();
	}

	template<typename T1,  typename T2,  typename T3>
	inline std::string toString (T1 p1, T2 p2, T3 p3)
	{
		std::ostringstream stream;
		stream << p1 << p2 << p3;
		return stream.str();
	}

	template<typename T1,  typename T2,  typename T3, typename T4>
	inline std::string toString (T1 p1, T2 p2, T3 p3, T4 p4)
	{
		std::ostringstream stream;
		stream << p1 << p2 << p3 << p4;
		return stream.str();
	}

	template<typename T1,  typename T2,  typename T3, typename T4, typename T5>
	inline std::string toString (T1 p1, T2 p2, T3 p3, T4 p4, T5 p5)
	{
		std::ostringstream stream;
		stream << p1 << p2 << p3 << p4 << p5;
		return stream.str();
	}

	template<typename T1,  typename T2,  typename T3, typename T4, typename T5, typename T6>
	inline std::string toString (T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6)
	{
		std::ostringstream stream;
		stream << p1 << p2 << p3 << p4 << p5 << p6;
		return stream.str();
	}

	template<typename T1,  typename T2,  typename T3, typename T4, typename T5, typename T6, typename T7>
	inline std::string toString (T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7)
	{
		std::ostringstream stream;
		stream << p1 << p2 << p3 << p4 << p5 << p6 << p7;
		return stream.str();
	}

	template<typename T1,  typename T2,  typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
	inline std::string toString (T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7, T8 p8)
	{
		std::ostringstream stream;
		stream << p1 << p2 << p3 << p4 << p5 << p6 << p7 << p8;
		return stream.str();
	}

	template<typename T1,  typename T2,  typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9>
	inline std::string toString (T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7, T8 p8, T9 p9)
	{
		std::ostringstream stream;
		stream << p1 << p2 << p3 << p4 << p5 << p6 << p7 << p8 << p9;
		return stream.str();
	}

	template<>
	inline std::string toString<bool> (bool _value)
	{
		return _value ? "true" : "false";
	}


	inline std::string toString(cocos2d::Point p)
	{
		return toString(p.x," ",p.y);
	} 
	inline std::string toString(cocos2d::Size p)
	{
		return toString(p.width," ",p.height);
	} 

	// утилиты для парсинга
	template<typename T>
	inline T parseValue( const std::string& _value )
	{
		std::istringstream stream(_value);
		T result;
		stream >> result;
		if (stream.fail())
			return T();
		else
		{
			int item = stream.get();
			while (item != -1)
			{
				if (item != ' ' && item != '\t')
					return T();
				item = stream.get();
			}
		}
		return result;
	}

	// отдельная имплементация под bool
	template<>
	inline bool parseValue(const std::string& _value)
	{
		if (_value == "True" || _value == "true" || _value == "1")
			return true;
		return false;
	}

	// отдельная имплементация под char
	template<>
	inline char parseValue(const std::string& _value)
	{
		return (char)parseValue<short>(_value);
	}

	// отдельная имплементация под unsigned char
	template<>
	inline unsigned char parseValue(const std::string& _value)
	{
		return (unsigned char)parseValue<unsigned short>(_value);
	}


	inline short parseShort(const std::string& _value)
	{
		return parseValue<short>(_value);
	}

	inline unsigned short parseUShort(const std::string& _value)
	{
		return parseValue<unsigned short>(_value);
	}

	inline int parseInt(const std::string& _value)
	{
		return parseValue<int>(_value);
	}

	inline unsigned int parseUInt(const std::string& _value)
	{
		return parseValue<unsigned int>(_value);
	}

	inline size_t parseSizeT(const std::string& _value)
	{
		return parseValue<size_t>(_value);
	}

	inline float parseFloat(const std::string& _value)
	{
		return parseValue<float>(_value);
	}

	inline double parseDouble(const std::string& _value)
	{
		return parseValue<double>(_value);
	}

	inline bool parseBool(const std::string& _value)
	{
		return parseValue<bool>(_value);
	}

	inline char parseChar(const std::string& _value)
	{
		return parseValue<char>(_value);
	}

	inline unsigned char parseUChar(const std::string& _value)
	{
		return parseValue<unsigned char>(_value);
	}

	// для парсинга сложных типов, состоящих из простых
	template<typename T1, typename T2>
	inline T1 parseValueEx2(const std::string& _value)
	{
		T2 p1, p2;
		std::istringstream stream(_value);
		stream >> p1 >> p2;
		if (stream.fail())
			return T1();
		else
		{
			int item = stream.get();
			while (item != -1)
			{
				if (item != ' ' && item != '\t')
					return T1();
				item = stream.get();
			}
		}
		return T1(p1, p2);
	}

	template<typename T1, typename T2>
	inline T1 parseValueEx3(const std::string& _value)
	{
		T2 p1, p2, p3;
		std::istringstream stream(_value);
		stream >> p1 >> p2 >> p3;
		if (stream.fail())
			return T1();
		else
		{
			int item = stream.get();
			while (item != -1)
			{
				if (item != ' ' && item != '\t')
					return T1();
				item = stream.get();
			}
		}
		return T1(p1, p2, p3);
	}

	template<typename T1, typename T2>
	inline T1 parseValueEx4(const std::string& _value)
	{
		T2 p1, p2, p3, p4;
		std::istringstream stream(_value);
		stream >> p1 >> p2 >> p3 >> p4;
		if (stream.fail())
			return T1();
		else
		{
			int item = stream.get();
			while (item != -1)
			{
				if (item != ' ' && item != '\t')
					return T1();
				item = stream.get();
			}
		}
		return T1(p1, p2, p3, p4);
	}

	namespace templates
	{
		template<typename T>
		inline void split(std::vector<std::string>& _ret, const std::string& _source, const std::string& _delims)
		{
			if (_source == "")
			{
				return;
			}
			size_t start = 0;
			size_t end = _source.find(_delims);
			while (start != _source.npos)
			{
				if (end != _source.npos)
					_ret.push_back(_source.substr(start, end - start));
				else
				{
					_ret.push_back(_source.substr(start));
					break;
				}
				start = end;
				if (start != _source.npos)
				{
					start+=_delims.size();
				}
				end = _source.find(_delims, start);
			}
		}
	} // namespace templates

	inline std::vector<std::string> split(const std::string& _source, const std::string& _delims = "\t\n ")
	{
		std::vector<std::string> result;
		templates::split<void>(result, _source, _delims);
		return result;
	}

	inline std::string standardisePath(const std::string& origin)
	{
		std::string path = origin;

		std::replace( path.begin(), path.end(), '\\', '/' );
		return path;
	}

	template<typename T1, typename T2, typename T3, typename T4>
	inline bool parseComplex(const std::string& _value, T1& _p1, T2& _p2, T3& _p3, T4& _p4)
	{
		std::istringstream stream(_value);

		stream >> _p1 >> _p2 >> _p3 >> _p4;

		if (stream.fail())
			return false;
		int item = stream.get();
		while (item != -1)
		{
			if (item != ' ' && item != '\t')
				return false;
			item = stream.get();
		}

		return true;
	}

	template<typename T1, typename T2, typename T3>
	inline bool parseComplex(const std::string& _value, T1& _p1, T2& _p2, T3& _p3)
	{
		std::istringstream stream(_value);

		stream >> _p1 >> _p2 >> _p3;

		if (stream.fail())
			return false;
		int item = stream.get();
		while (item != -1)
		{
			if (item != ' ' && item != '\t')
				return false;
			item = stream.get();
		}

		return true;
	}

	template<typename T1, typename T2>
	inline bool parseComplex(const std::string& _value, T1& _p1, T2& _p2)
	{
		std::istringstream stream(_value);

		stream >> _p1 >> _p2;

		if (stream.fail())
			return false;
		int item = stream.get();
		while (item != -1)
		{
			if (item != ' ' && item != '\t')
				return false;
			item = stream.get();
		}

		return true;
	}

	template<typename T1>
	inline bool parseComplex(const std::string& _value, T1& _p1)
	{
		std::istringstream stream(_value);

		stream >> _p1;

		if (stream.fail())
			return false;
		int item = stream.get();
		while (item != -1)
		{
			if (item != ' ' && item != '\t')
				return false;
			item = stream.get();
		}

		return true;
	}

	template<>
	inline bool parseComplex<bool>(const std::string& _value, bool& _p1)
	{
		std::string value(_value);
		trim(value);
		if ((value == "True") || (value == "true") || (value == "1"))
		{
			_p1 = true;
			return true;
		}
		else if ((value == "False") || (value == "false") || (value == "0"))
		{
			_p1 = false;
			return true;
		}

		return false;
	}

	inline bool startWith(const std::string& _source, const std::string& _value)
	{
		size_t count = _value.size();
		if (_source.size() < count)
			return false;
		for (size_t index = 0; index < count; ++ index)
		{
			if (_source[index] != _value[index])
				return false;
		}
		return true;
	}

	inline bool endWith(const std::string& _source, const std::string& _value)
	{
		size_t count = _value.size();
		if (_source.size() < count)
			return false;
		size_t offset = _source.size() - count;
		for (size_t index = 0; index < count; ++ index)
		{
			if (_source[index + offset] != _value[index])
				return false;
		}
		return true;
	}
	inline void PushMapVectorString(MapVectorString& _str,const std::string& _key,const std::string& _value)
	{
		MapVectorString::iterator itor = _str.find(_key);
		if (itor!=_str.end())
		{
			itor->second.push_back(_value);
		}
		else
		{
			VectorString kString;
			kString.push_back(_value);
			_str.insert(std::map<std::string, VectorString>::value_type(_key,kString));
		}
	}

	static __Array* visitArray(const ValueVector& array);
	static __Dictionary* visitDict(const ValueMap & dict)
	{
		__Dictionary* ret = new __Dictionary();
		ret->init();

		for (auto iter = dict.begin(); iter != dict.end(); ++iter)
		{
			if (iter->second.getType() == Value::Type::MAP)
			{
				const ValueMap & subDict = iter->second.asValueMap();
				auto sub = visitDict(subDict);
				ret->setObject(sub, iter->first);
				sub->release();
			}
			else if (iter->second.getType() == Value::Type::VECTOR)
			{
				const ValueVector & arr = iter->second.asValueVector();
				auto sub = visitArray(arr);
				ret->setObject(sub, iter->first);
				sub->release();
			}
			else
			{
				auto str = new __String(iter->second.asString());
				ret->setObject(str, iter->first);
				str->release();
			}
		}
		return ret;
	}


	static __Array* visitArray(const ValueVector& array)
	{
		__Array* ret = new __Array();
		ret->init();

		for (const auto &value : array) {
			if (value.getType() == Value::Type::MAP)
			{
				const ValueMap& subDict = value.asValueMap();
				auto sub = visitDict(subDict);
				ret->addObject(sub);
				sub->release();
			}
			else if (value.getType() == Value::Type::VECTOR)
			{
				const ValueVector& arr = value.asValueVector();
				auto sub = visitArray(arr);
				ret->addObject(sub);
				sub->release();
			}
			else
			{
				auto str = new __String(value.asString());
				ret->addObject(str);
				str->release();
			}
		}

		return ret;
	}

	


} // namespace utility

/* Name		：string_util
 * Author	：YueLiangYou
 * Date		: 2015-06-24
 * Desc		: 字符常用处理函数
 */
class string_util
{
public:
	static std::string format(const char* fmt, ... )
	{
		char buf[2048] = {0};
		va_list l;
		va_start(l,fmt);
		vsnprintf(buf,2048,fmt,l);
		va_end(l);

		return buf;
	}

	static std::string format(int val)
	{
		return format("%d",val);
	}

	static std::string format(long long val)
	{
		return format("%lld",val);
	}

	static std::string format(float val)
	{
		return format("%f",val);
	}

	static int to_int(const std::string& val)
	{
		return atoi(val.c_str());
	}

	static long long to_int64(const std::string& val)
	{
#ifdef WIN32
#define atoll _atoi64
#endif
		return atoll(val.c_str());
	}

	static float to_float(const std::string& val)
	{
		return (float)atof(val.c_str());
	}

	static std::string to_lower(const std::string& str )
	{
		std::string ret = str;
		for (std::string::iterator iter=ret.begin();iter!=ret.end();iter++)
		{
			*iter=tolower(*iter);
		}
		return ret;
	}

	static std::string to_uper(const std::string& str )
	{
		std::string ret = str;
		for (std::string::iterator iter=ret.begin();iter!=ret.end();iter++)
		{
			*iter=toupper(*iter);
		}
		return ret;
	}
	/* Name		：split
	 * Author	：YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: 字符串拆分
	 * Param	: str 源字符串，delimd 分离字符串，des 目标vector
	 * Return	: 分离的字符串个数
	 */
	static int split( const std::string& str,const std::string& delimd,vector<std::string>& des )
	{
		des.clear();

		if (str.empty())
		{
			return 0;
		}

		size_t start = 0;
		size_t pos = 0;
		size_t len = str.length();

		while ( pos != string::npos )
		{
			pos = str.find(delimd,start);
			if( pos != str.npos )
			{
				string item = str.substr(start, pos-start);
				if ( !item.empty() )
				{
					des.push_back(item);
				}
				start = pos+delimd.size();
			}
			else
			{
				string item = str.substr(start, len-start);
				if ( !item.empty() )
				{
					des.push_back(item);
				}
				break;
			}
		}
		
		return (int)des.size();
	}

	/* Name		：split_int
	 * Author	：YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: 字符串拆分
	 * Param	: str 源字符串，delimd 分离字符串，des 目标vector
	 * Return	: 分离的字符串个数
	 */
	static int split_int( const string& str,const string& delimd,vector<int>& des )
	{
		des.clear();
		vector<string> items;
		split(str,delimd,items);
		for ( size_t i = 0;i<items.size();++i )
		{
			des.push_back(atoi(items[i].c_str()));
		}
		return des.size();
	}

	/* Name		：connect_int
	 * Author	：Liyang
	 * Date		: 2016-01-29
	 * Desc		: 字符串拼接
	 * Param	: str 源字符串，delimd 拼接字符串
	 * Return	: 分离的字符串个数
	 */
	static string connect_int( const string& str,const string& delimd,const string& sub_str)
	{
		string result_str = str + delimd + sub_str;
		return result_str;
	}

	/* Name		：trim
	 * Author	：YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: 字符串拆除
	 * Param	: str 源字符串，ch 要拆除的字符串
	 * Return	: 返回拆除后的新的字符串
	 */
	static std::string trim(const std::string& str,const std::string& ch)
	{
		std::string ret = str;
		size_t pos = ret.find(ch);
		while( pos != string::npos )
		{
			std::string s1 = ret.substr(0,pos);
			std::string s2 = ret.substr(pos+ch.length(),ret.length());
			ret = s1+s2;
			pos = ret.find(ch);

		}
		return ret;
	}

	/* Name		：replace
	 * Author	：PengLongHua
	 * Date		: 2016-04-12
	 * Desc		: 字符串替换
	 * Param	: str 源字符串，oldCh 被替换的字符串 newChe 替换字符串
	 * Return	: 返回替换后的新字符串
	 */
	static std::string replace(const std::string& str,const std::string& oldCh,const std::string& newCh)
	{
		//新字符串不能包含旧字符串
		if (newCh.find(oldCh) != string::npos)
		{
			return str;
		}

		std::string ret = str;
		size_t pos = ret.find(oldCh);
		while( pos != string::npos )
		{
			std::string s1 = ret.substr(0,pos);
			std::string s2 = ret.substr(pos+oldCh.length(),ret.length());
			ret = s1+newCh+s2;
			pos = ret.find(oldCh);

		}
		return ret;
	}

	/* Name		：suffix
	 * Author	：YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: 取文件名后缀
	 * Param	: file_name 源字符串
	 * Return	: 文件后缀名
	 */
	static std::string suffix(const std::string& file_name)
	{
		size_t pos = file_name.find_last_of(".");

		if ( pos == std::string::npos )
		{
			return "";
		}
	
		std::string ret = file_name.substr(pos+1,file_name.length());

		return ret;
	}

	/* Name		：suffix_none
	 * Author	：YueLiangYou
	 * Date		: 2015-06-24
	 * Desc		: 去掉文件名后缀
	 * Param	: none
	 * Return	: 文件名不带后缀
	 */
	static std::string suffix_none(const std::string& file_name)
	{
		size_t pos1 = file_name.find_last_of("/\\");
		size_t pos2 = file_name.find_last_of(".");

		size_t len = 0;
		if ( pos1 == std::string::npos )
		{
			pos1 = 0;
		}
		if ( pos2 == std::string::npos )
		{
			len = file_name.length()-pos1-1;
		}
		else
		{
			len = pos2 - pos1 -1 > 0 ? pos2 - pos1 -1 : 0;
		}

		std::string ret = file_name.substr(pos1+1,len);

		return ret;
	}
};

#endif // __MYGUI_STRING_UTILITY_H__
