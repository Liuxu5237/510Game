#ifndef __CC_LUA_STACKEX_H_
#define __CC_LUA_STACKEX_H_

#include "CCLuaStack.h"

NS_CC_BEGIN
USING_NS_CC;

class LuaStackEx : public LuaStack
{
public:

	int call_script_int_fun(LUA_FUNCTION luaCallBack)
	{
		int ret = 0;

		if (pushFunctionByHandler(luaCallBack))                                /* L: ... arg1 arg2 ... func */
		{
			ret = executeFunction(0);
		}
		
		lua_settop(_state, 0);
		return ret;
	}

	template<typename... Args>
	int call_script_int_fun(LUA_FUNCTION luaCallBack, Args... args)
	{
		int ret = 0;

		int argAmount = sizeof...(args);
		split_args(args...);

		if (pushFunctionByHandler(luaCallBack))                                /* L: ... arg1 arg2 ... func */
		{
			if (argAmount > 0)
			{
				lua_insert(_state, -(argAmount + 1));						   /* L: ... func arg1 arg2 ... */
			}
			ret = executeFunction(argAmount);
		}

		lua_settop(_state, 0);
		return ret;
	}

	int call_script_fun(const std::string & callFunc)
	{
		if (callFunc == "")
		{
			CCLOG("[LUA ERROR] The list without the callback function");
			return 0;
		}

		size_t pos = -1;
		pos = callFunc.find(".", 0);

		if (pos == -1)
		{
			lua_getglobal(_state, callFunc.c_str());
			if (!lua_isfunction(_state, -1))
			{
				CCLOG("[LUA ERROR] name '%s' does not represent a Lua function", callFunc.c_str());
				lua_pop(_state, 1);
				return 0;
			}
		}
		else
		{
			std::string moduleName = callFunc.substr(0, pos);

			std::string funcName = callFunc.substr(pos + 1, callFunc.size());
            
            //CCLOG("call script fun 1 module name %s , func name %s",moduleName.c_str(), funcName.c_str());

			lua_getglobal(_state, "_G");

			lua_pushfstring(_state, moduleName.c_str());
			lua_gettable(_state, -2);

			int istable = lua_istable(_state, -1);

			if (!istable)
			{
				CCLOG("[LUA ERROR] name '%s' does not represent a Lua module", moduleName.c_str());
				return 0;
			}

			lua_pushfstring(_state, funcName.c_str());
			lua_gettable(_state, -2);

			int isfunc = lua_isfunction(_state, -1);
			if (!isfunc)
			{
				CCLOG("[LUA ERROR] name '%s' does not represent a Lua function", funcName.c_str());
				lua_pop(_state, 1);
				return 0;
			}
		}

		int functionIndex = -1;

		int traceback = 0;
		lua_getglobal(_state, "__G__TRACKBACK__");                         /* L: ... func  G */
		if (!lua_isfunction(_state, -1))
		{
			lua_pop(_state, 1);                                            /* L: ... func */
		}
		else
		{
			lua_insert(_state, functionIndex - 1);                         /* L: ... G func */
			traceback = functionIndex - 1;
		}

		++_callFromLua;
		int error = lua_pcall(_state, 0, 1, traceback);
		--_callFromLua;


		if (error)
		{
			if (traceback == 0)
			{
				CCLOG("[LUA ERROR] %s", lua_tostring(_state, -1));
				lua_pop(_state, 1);										/* L: ... error */
			}
			else                                                        /* L: ... G error */
			{
				lua_pop(_state, 2); // remove __G__TRACKBACK__ and error message from stack
			}
		}

		int ret = 0;
		if (lua_isnumber(_state, -1))
		{
			ret = (int)lua_tointeger(_state, -1);
		}
		else if (lua_isboolean(_state, -1))
		{
			ret = (int)lua_toboolean(_state, -1);
		}

		lua_pop(_state, 1);			 /* L: ... [G] */

		if (traceback)
		{
			lua_pop(_state, 1); // remove __G__TRACKBACK__ from stack      /* L: ... */
		}

		return ret;
	}

	template<typename... Args>
	int call_script_fun(const std::string & callFunc, Args... args)
	{
		if (callFunc == "")
		{
			CCLOG("[LUA ERROR] The list without the callback function");
			return 0;
		}

		size_t pos = -1;
		pos = callFunc.find(".", 0);

		if (pos == -1)
		{
			lua_getglobal(_state, callFunc.c_str());
			if (!lua_isfunction(_state, -1))
			{
				CCLOG("[LUA ERROR] name '%s' does not represent a Lua function", callFunc.c_str());
				lua_pop(_state, 1);
				return 0;
			}
		}
		else
		{
			std::string moduleName = callFunc.substr(0, pos);
			std::string funcName = callFunc.substr(pos + 1, callFunc.size());
            //CCLOG("call script fun 2 module name %s , func name %s",moduleName.c_str(), funcName.c_str());

			lua_getglobal(_state, "_G");

			lua_pushfstring(_state, moduleName.c_str());
			lua_gettable(_state, -2);

			int istable = lua_istable(_state, -1);

			if (!istable)
			{
				CCLOG("[LUA ERROR] name '%s' does not represent a Lua module", moduleName.c_str());
				return 0;
			}

			lua_pushfstring(_state, funcName.c_str());
			lua_gettable(_state, -2);

			int isfunc = lua_isfunction(_state, -1);
			if (!isfunc)
			{
				CCLOG("[LUA ERROR] name '%s' does not represent a Lua function", funcName.c_str());
				lua_pop(_state, 1);
				return 0;
			}
		}

		int argAmount = sizeof...(args);
		split_args(args...);

		int functionIndex = -(argAmount + 1);

		int traceback = 0;
		lua_getglobal(_state, "__G__TRACKBACK__");                         /* L: ... func arg1 arg2 ... G */
		if (!lua_isfunction(_state, -1))
		{
			lua_pop(_state, 1);                                            /* L: ... func arg1 arg2 ... */
		}
		else
		{
			lua_insert(_state, functionIndex - 1);                         /* L: ... G func arg1 arg2 ... */
			traceback = functionIndex - 1;
		}


		++_callFromLua;
		int error = lua_pcall(_state, argAmount, 1, traceback);
		--_callFromLua;
		if (error)
		{
			if (traceback == 0)
			{
				CCLOG("[LUA ERROR] %s", lua_tostring(_state, -1));
				lua_pop(_state, 1);										/* L: ... error */
			}
			else                                                        /* L: ... G error */
			{
				lua_pop(_state, 2); // remove __G__TRACKBACK__ and error message from stack
			}

			return 0;
		}

		int ret = 0;
		if (lua_isnumber(_state, -1))
		{
			ret = (int)lua_tointeger(_state, -1);
		}
		else if (lua_isboolean(_state, -1))
		{
			ret = (int)lua_toboolean(_state, -1);
		}

		lua_pop(_state, 1);			 /* L: ... [G] */

		if (traceback)
		{
			lua_pop(_state, 1); // remove __G__TRACKBACK__ from stack      /* L: ... */
		}

		return ret;
	}

protected:

	template<typename T>
	void split_args(const T & data)
	{
		push_data(data);
	}
	template<typename T, typename... Args>
	void split_args(const T & data, Args... args)
	{        
		push_data(data);
		split_args(args...);
	}

protected:
	template<typename T>
	void push_data(T data)
	{
		CCLOG("存在未定义类型的数据, 无法传参到lua脚本.");
	}

	void push_data(int data) { pushInt(data); }
	void push_data(long data) { pushLong(data); }
	void push_data(float data) { pushFloat(data); }
	void push_data(std::string str) { pushString(str.c_str()); }
	void push_data(const std::string& str) { pushString(str.c_str()); }
	void push_data(const char* str) { pushString(str); }
	void push_data(bool data) { pushBoolean(data); }
	void push_data(CCObject * pTarget){ pushObject(pTarget, "CCObject");}
	//, 传指针
	void push_data(void* udata) { lua_pushlightuserdata(_state, udata); }
};

NS_CC_END

#endif // __CC_LUA_STACKEX_H_
