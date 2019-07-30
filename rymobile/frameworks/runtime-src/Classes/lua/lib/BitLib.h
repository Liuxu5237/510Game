#ifndef		_LUA_LIB_BITLIB_H_
#define		_LUA_LIB_BITLIB_H_

class LuaBitLib
{
public:
	static int bAnd(int a, int b);
	static int bOr(int a, int b);
	static int lShift(int a, int b);
	static int rShift(int a, int b);
	static int bNot(int a);
	
};
#endif
