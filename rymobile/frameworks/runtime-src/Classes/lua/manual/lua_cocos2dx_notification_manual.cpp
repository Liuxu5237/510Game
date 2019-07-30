#include "lua_cocos2dx_notification_manual.hpp"
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC || CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
#include "../../tools/tools/MTNotification.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"



int lua_cocos2dx_notification_MTData_setPData(lua_State* tolua_S)
{
    int argc = 0;
    MTData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MTData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MTData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_notification_MTData_setPData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Ref* arg0;

        ok &= luaval_to_object<cocos2d::Ref>(tolua_S, 2, "cc.Ref",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_notification_MTData_setPData'", nullptr);
            return 0;
        }
        cobj->setPData(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MTData:setPData",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_notification_MTData_setPData'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_notification_MTData_setStr1(lua_State* tolua_S)
{
    int argc = 0;
    MTData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MTData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MTData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_notification_MTData_setStr1'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "MTData:setStr1");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_notification_MTData_setStr1'", nullptr);
            return 0;
        }
        cobj->setStr1(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MTData:setStr1",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_notification_MTData_setStr1'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_notification_MTData_setStr2(lua_State* tolua_S)
{
    int argc = 0;
    MTData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MTData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MTData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_notification_MTData_setStr2'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "MTData:setStr2");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_notification_MTData_setStr2'", nullptr);
            return 0;
        }
        cobj->setStr2(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MTData:setStr2",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_notification_MTData_setStr2'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_notification_MTData_setStr3(lua_State* tolua_S)
{
    int argc = 0;
    MTData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MTData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MTData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_notification_MTData_setStr3'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "MTData:setStr3");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_notification_MTData_setStr3'", nullptr);
            return 0;
        }
        cobj->setStr3(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MTData:setStr3",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_notification_MTData_setStr3'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_notification_MTData_getData1(lua_State* tolua_S)
{
    int argc = 0;
    MTData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MTData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MTData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_notification_MTData_getData1'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_notification_MTData_getData1'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getData1();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MTData:getData1",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_notification_MTData_getData1'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_notification_MTData_getData2(lua_State* tolua_S)
{
    int argc = 0;
    MTData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MTData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MTData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_notification_MTData_getData2'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_notification_MTData_getData2'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getData2();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MTData:getData2",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_notification_MTData_getData2'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_notification_MTData_getData3(lua_State* tolua_S)
{
    int argc = 0;
    MTData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MTData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MTData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_notification_MTData_getData3'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_notification_MTData_getData3'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getData3();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MTData:getData3",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_notification_MTData_getData3'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_notification_MTData_setData1(lua_State* tolua_S)
{
    int argc = 0;
    MTData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MTData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MTData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_notification_MTData_setData1'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "MTData:setData1");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_notification_MTData_setData1'", nullptr);
            return 0;
        }
        cobj->setData1(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MTData:setData1",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_notification_MTData_setData1'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_notification_MTData_setData2(lua_State* tolua_S)
{
    int argc = 0;
    MTData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MTData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MTData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_notification_MTData_setData2'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "MTData:setData2");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_notification_MTData_setData2'", nullptr);
            return 0;
        }
        cobj->setData2(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MTData:setData2",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_notification_MTData_setData2'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_notification_MTData_setData3(lua_State* tolua_S)
{
    int argc = 0;
    MTData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MTData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MTData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_notification_MTData_setData3'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "MTData:setData3");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_notification_MTData_setData3'", nullptr);
            return 0;
        }
        cobj->setData3(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MTData:setData3",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_notification_MTData_setData3'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_notification_MTData_getStr2(lua_State* tolua_S)
{
    int argc = 0;
    MTData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MTData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MTData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_notification_MTData_getStr2'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_notification_MTData_getStr2'", nullptr);
            return 0;
        }
        const std::string& ret = cobj->getStr2();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MTData:getStr2",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_notification_MTData_getStr2'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_notification_MTData_getStr3(lua_State* tolua_S)
{
    int argc = 0;
    MTData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MTData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MTData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_notification_MTData_getStr3'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_notification_MTData_getStr3'", nullptr);
            return 0;
        }
        const std::string& ret = cobj->getStr3();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MTData:getStr3",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_notification_MTData_getStr3'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_notification_MTData_getStr1(lua_State* tolua_S)
{
    int argc = 0;
    MTData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MTData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MTData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_notification_MTData_getStr1'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_notification_MTData_getStr1'", nullptr);
            return 0;
        }
        const std::string& ret = cobj->getStr1();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MTData:getStr1",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_notification_MTData_getStr1'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_notification_MTData_getPData(lua_State* tolua_S)
{
    int argc = 0;
    MTData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MTData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MTData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_notification_MTData_getPData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_notification_MTData_getPData'", nullptr);
            return 0;
        }
        cocos2d::Ref* ret = cobj->getPData();
        object_to_luaval<cocos2d::Ref>(tolua_S, "cc.Ref",(cocos2d::Ref*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MTData:getPData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_notification_MTData_getPData'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_notification_MTData_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"MTData",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_notification_MTData_create'", nullptr);
            return 0;
        }
        MTData* ret = MTData::create();
        object_to_luaval<MTData>(tolua_S, "MTData",(MTData*)ret);
        return 1;
    }
    if (argc == 1)
    {
        unsigned int arg0;
        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "MTData:create");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_notification_MTData_create'", nullptr);
            return 0;
        }
        MTData* ret = MTData::create(arg0);
        object_to_luaval<MTData>(tolua_S, "MTData",(MTData*)ret);
        return 1;
    }
    if (argc == 2)
    {
        unsigned int arg0;
        unsigned int arg1;
        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "MTData:create");
        ok &= luaval_to_uint32(tolua_S, 3,&arg1, "MTData:create");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_notification_MTData_create'", nullptr);
            return 0;
        }
        MTData* ret = MTData::create(arg0, arg1);
        object_to_luaval<MTData>(tolua_S, "MTData",(MTData*)ret);
        return 1;
    }
    if (argc == 3)
    {
        unsigned int arg0;
        unsigned int arg1;
        unsigned int arg2;
        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "MTData:create");
        ok &= luaval_to_uint32(tolua_S, 3,&arg1, "MTData:create");
        ok &= luaval_to_uint32(tolua_S, 4,&arg2, "MTData:create");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_notification_MTData_create'", nullptr);
            return 0;
        }
        MTData* ret = MTData::create(arg0, arg1, arg2);
        object_to_luaval<MTData>(tolua_S, "MTData",(MTData*)ret);
        return 1;
    }
    if (argc == 4)
    {
        unsigned int arg0;
        unsigned int arg1;
        unsigned int arg2;
        std::string arg3;
        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "MTData:create");
        ok &= luaval_to_uint32(tolua_S, 3,&arg1, "MTData:create");
        ok &= luaval_to_uint32(tolua_S, 4,&arg2, "MTData:create");
        ok &= luaval_to_std_string(tolua_S, 5,&arg3, "MTData:create");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_notification_MTData_create'", nullptr);
            return 0;
        }
        MTData* ret = MTData::create(arg0, arg1, arg2, arg3);
        object_to_luaval<MTData>(tolua_S, "MTData",(MTData*)ret);
        return 1;
    }
    if (argc == 5)
    {
        unsigned int arg0;
        unsigned int arg1;
        unsigned int arg2;
        std::string arg3;
        std::string arg4;
        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "MTData:create");
        ok &= luaval_to_uint32(tolua_S, 3,&arg1, "MTData:create");
        ok &= luaval_to_uint32(tolua_S, 4,&arg2, "MTData:create");
        ok &= luaval_to_std_string(tolua_S, 5,&arg3, "MTData:create");
        ok &= luaval_to_std_string(tolua_S, 6,&arg4, "MTData:create");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_notification_MTData_create'", nullptr);
            return 0;
        }
        MTData* ret = MTData::create(arg0, arg1, arg2, arg3, arg4);
        object_to_luaval<MTData>(tolua_S, "MTData",(MTData*)ret);
        return 1;
    }
    if (argc == 6)
    {
        unsigned int arg0;
        unsigned int arg1;
        unsigned int arg2;
        std::string arg3;
        std::string arg4;
        std::string arg5;
        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "MTData:create");
        ok &= luaval_to_uint32(tolua_S, 3,&arg1, "MTData:create");
        ok &= luaval_to_uint32(tolua_S, 4,&arg2, "MTData:create");
        ok &= luaval_to_std_string(tolua_S, 5,&arg3, "MTData:create");
        ok &= luaval_to_std_string(tolua_S, 6,&arg4, "MTData:create");
        ok &= luaval_to_std_string(tolua_S, 7,&arg5, "MTData:create");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_notification_MTData_create'", nullptr);
            return 0;
        }
        MTData* ret = MTData::create(arg0, arg1, arg2, arg3, arg4, arg5);
        object_to_luaval<MTData>(tolua_S, "MTData",(MTData*)ret);
        return 1;
    }
    if (argc == 7)
    {
        unsigned int arg0;
        unsigned int arg1;
        unsigned int arg2;
        std::string arg3;
        std::string arg4;
        std::string arg5;
        cocos2d::Ref* arg6;
        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "MTData:create");
        ok &= luaval_to_uint32(tolua_S, 3,&arg1, "MTData:create");
        ok &= luaval_to_uint32(tolua_S, 4,&arg2, "MTData:create");
        ok &= luaval_to_std_string(tolua_S, 5,&arg3, "MTData:create");
        ok &= luaval_to_std_string(tolua_S, 6,&arg4, "MTData:create");
        ok &= luaval_to_std_string(tolua_S, 7,&arg5, "MTData:create");
        ok &= luaval_to_object<cocos2d::Ref>(tolua_S, 8, "cc.Ref",&arg6);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_notification_MTData_create'", nullptr);
            return 0;
        }
        MTData* ret = MTData::create(arg0, arg1, arg2, arg3, arg4, arg5, arg6);
        object_to_luaval<MTData>(tolua_S, "MTData",(MTData*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "MTData:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_notification_MTData_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_notification_MTData_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (MTData)");
    return 0;
}

int lua_register_cocos2dx_notification_MTData(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"MTData");
    tolua_cclass(tolua_S,"MTData","MTData","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"MTData");
        tolua_function(tolua_S,"setPData",lua_cocos2dx_notification_MTData_setPData);
        tolua_function(tolua_S,"setStr1",lua_cocos2dx_notification_MTData_setStr1);
        tolua_function(tolua_S,"setStr2",lua_cocos2dx_notification_MTData_setStr2);
        tolua_function(tolua_S,"setStr3",lua_cocos2dx_notification_MTData_setStr3);
        tolua_function(tolua_S,"getData1",lua_cocos2dx_notification_MTData_getData1);
        tolua_function(tolua_S,"getData2",lua_cocos2dx_notification_MTData_getData2);
        tolua_function(tolua_S,"getData3",lua_cocos2dx_notification_MTData_getData3);
        tolua_function(tolua_S,"setData1",lua_cocos2dx_notification_MTData_setData1);
        tolua_function(tolua_S,"setData2",lua_cocos2dx_notification_MTData_setData2);
        tolua_function(tolua_S,"setData3",lua_cocos2dx_notification_MTData_setData3);
        tolua_function(tolua_S,"getStr2",lua_cocos2dx_notification_MTData_getStr2);
        tolua_function(tolua_S,"getStr3",lua_cocos2dx_notification_MTData_getStr3);
        tolua_function(tolua_S,"getStr1",lua_cocos2dx_notification_MTData_getStr1);
        tolua_function(tolua_S,"getPData",lua_cocos2dx_notification_MTData_getPData);
        tolua_function(tolua_S,"create", lua_cocos2dx_notification_MTData_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(MTData).name();
    g_luaType[typeName] = "MTData";
    g_typeCast["MTData"] = "MTData";
    return 1;
}

int lua_cocos2dx_notification_MyNotification_registerLuaEventCallBack(lua_State* tolua_S)
{
    int argc = 0;
    MyNotification* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MyNotification",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MyNotification*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_notification_MyNotification_registerLuaEventCallBack'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
     
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "MyNotification:registerLuaEventCallBack");
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_cocos2dx_notification_MyNotification_registerLuaEventCallBack'", nullptr);
			return 0;
		}
#if COCOS2D_DEBUG >= 1
		if (!toluafix_isfunction(tolua_S, 3, "LUA_FUNCTION", 0, &tolua_err))
		{
			goto tolua_lerror;
		}
#endif

		LUA_FUNCTION handler = (toluafix_ref_function(tolua_S, 3, 0));

		bool ret = cobj->registerLuaEventCallBack(arg0, handler);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MyNotification:registerLuaEventCallBack",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_notification_MyNotification_registerLuaEventCallBack'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_notification_MyNotification_unRegisterEventListener(lua_State* tolua_S)
{
    int argc = 0;
    MyNotification* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MyNotification",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MyNotification*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_notification_MyNotification_unRegisterEventListener'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "MyNotification:unRegisterEventListener");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_notification_MyNotification_unRegisterEventListener'", nullptr);
            return 0;
        }
        bool ret = cobj->unRegisterEventListener(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MyNotification:unRegisterEventListener",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_notification_MyNotification_unRegisterEventListener'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_notification_MyNotification_dispatchEvent(lua_State* tolua_S)
{
    int argc = 0;
    MyNotification* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MyNotification",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MyNotification*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_notification_MyNotification_dispatchEvent'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "MyNotification:dispatchEvent");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_notification_MyNotification_dispatchEvent'", nullptr);
            return 0;
        }
        cobj->dispatchEvent(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 2) 
    {
        std::string arg0;
        MTData* arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "MyNotification:dispatchEvent");

        ok &= luaval_to_object<MTData>(tolua_S, 3, "MTData",&arg1);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_notification_MyNotification_dispatchEvent'", nullptr);
            return 0;
        }
        cobj->dispatchEvent(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MyNotification:dispatchEvent",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_notification_MyNotification_dispatchEvent'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_notification_MyNotification_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"MyNotification",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_notification_MyNotification_getInstance'", nullptr);
            return 0;
        }
        MyNotification* ret = MyNotification::getInstance();
        object_to_luaval<MyNotification>(tolua_S, "MyNotification",(MyNotification*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "MyNotification:getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_notification_MyNotification_getInstance'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_notification_MyNotification_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (MyNotification)");
    return 0;
}

int lua_register_cocos2dx_notification_MyNotification(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"MyNotification");
    tolua_cclass(tolua_S,"MyNotification","MyNotification","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"MyNotification");
        tolua_function(tolua_S,"registerLuaEventCallBack",lua_cocos2dx_notification_MyNotification_registerLuaEventCallBack);
        tolua_function(tolua_S,"unRegisterEventListener",lua_cocos2dx_notification_MyNotification_unRegisterEventListener);
        tolua_function(tolua_S,"dispatchEvent",lua_cocos2dx_notification_MyNotification_dispatchEvent);
        tolua_function(tolua_S,"getInstance", lua_cocos2dx_notification_MyNotification_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(MyNotification).name();
    g_luaType[typeName] = "MyNotification";
    g_typeCast["MyNotification"] = "MyNotification";
    return 1;
}
TOLUA_API int register_all_cocos2dx_notification(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"ds",0);
	tolua_beginmodule(tolua_S,"ds");

	lua_register_cocos2dx_notification_MTData(tolua_S);
	lua_register_cocos2dx_notification_MyNotification(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

#endif
