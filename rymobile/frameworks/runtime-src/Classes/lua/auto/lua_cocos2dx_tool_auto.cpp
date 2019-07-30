#include "lua_cocos2dx_tool_auto.hpp"
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC || CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
#include "tools/tools/StaticData.h"
#include "tools/tools/StringData.h"
#include "tools/tools/MyConfigureData.h"
#include "tools/tools/PacketReadAide.h"
#include "tools/tools/PacketWriteAide.h"
#include "tools/tools/Convert.h"
#include "tools/tools/DSFileUpdate.h"
#include "tools/tools/GameVersionUpdate.h"
#include "tools/tools/PlatformVersionUpdate.h"
#include "tools/tools/newcurl.h"
#include "tools/tools/ImagicDownManager.h"
#include "tools/tools/uploadFile.h"
#include "tools/NickReadInfo.h"

#include "tools/manager/Game_Path_Manager.h"
#include "tools/manager/SpriteHelper.h"
#include "tools/manager/SoundManager.h"
#include "tools/manager/DntgActionCustom6.h"

#include "tools/dialog/Timer.h"

#include "tools/core/CCUserDefault.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"



int lua_cocos2dx_tool_StaticData_arrayFromKey(lua_State* tolua_S)
{
    int argc = 0;
    StaticData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"StaticData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (StaticData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_StaticData_arrayFromKey'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "StaticData:arrayFromKey");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_StaticData_arrayFromKey'", nullptr);
            return 0;
        }
        cocos2d::__Array* ret = cobj->arrayFromKey(arg0);
        object_to_luaval<cocos2d::__Array>(tolua_S, "cc.__Array",(cocos2d::__Array*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "StaticData:arrayFromKey",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_StaticData_arrayFromKey'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_StaticData_sizeFromKey(lua_State* tolua_S)
{
    int argc = 0;
    StaticData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"StaticData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (StaticData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_StaticData_sizeFromKey'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "StaticData:sizeFromKey");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_StaticData_sizeFromKey'", nullptr);
            return 0;
        }
        cocos2d::Size ret = cobj->sizeFromKey(arg0);
        size_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "StaticData:sizeFromKey",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_StaticData_sizeFromKey'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_StaticData_colorFromKey(lua_State* tolua_S)
{
    int argc = 0;
    StaticData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"StaticData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (StaticData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_StaticData_colorFromKey'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "StaticData:colorFromKey");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_StaticData_colorFromKey'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->colorFromKey(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "StaticData:colorFromKey",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_StaticData_colorFromKey'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_StaticData_rectFromKey(lua_State* tolua_S)
{
    int argc = 0;
    StaticData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"StaticData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (StaticData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_StaticData_rectFromKey'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "StaticData:rectFromKey");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_StaticData_rectFromKey'", nullptr);
            return 0;
        }
        cocos2d::Rect ret = cobj->rectFromKey(arg0);
        rect_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "StaticData:rectFromKey",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_StaticData_rectFromKey'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_StaticData_stringFromKey(lua_State* tolua_S)
{
    int argc = 0;
    StaticData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"StaticData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (StaticData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_StaticData_stringFromKey'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "StaticData:stringFromKey");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_StaticData_stringFromKey'", nullptr);
            return 0;
        }
        const char* ret = cobj->stringFromKey(arg0);
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "StaticData:stringFromKey",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_StaticData_stringFromKey'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_StaticData_intFromKey(lua_State* tolua_S)
{
    int argc = 0;
    StaticData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"StaticData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (StaticData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_StaticData_intFromKey'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "StaticData:intFromKey");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_StaticData_intFromKey'", nullptr);
            return 0;
        }
        int ret = cobj->intFromKey(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "StaticData:intFromKey",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_StaticData_intFromKey'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_StaticData_floatFromKey(lua_State* tolua_S)
{
    int argc = 0;
    StaticData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"StaticData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (StaticData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_StaticData_floatFromKey'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "StaticData:floatFromKey");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_StaticData_floatFromKey'", nullptr);
            return 0;
        }
        double ret = cobj->floatFromKey(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "StaticData:floatFromKey",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_StaticData_floatFromKey'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_StaticData_pointFromKey(lua_State* tolua_S)
{
    int argc = 0;
    StaticData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"StaticData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (StaticData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_StaticData_pointFromKey'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "StaticData:pointFromKey");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_StaticData_pointFromKey'", nullptr);
            return 0;
        }
        cocos2d::Vec2 ret = cobj->pointFromKey(arg0);
        vec2_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "StaticData:pointFromKey",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_StaticData_pointFromKey'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_StaticData_booleanFromKey(lua_State* tolua_S)
{
    int argc = 0;
    StaticData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"StaticData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (StaticData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_StaticData_booleanFromKey'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "StaticData:booleanFromKey");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_StaticData_booleanFromKey'", nullptr);
            return 0;
        }
        bool ret = cobj->booleanFromKey(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "StaticData:booleanFromKey",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_StaticData_booleanFromKey'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_StaticData_purge(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"StaticData",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_StaticData_purge'", nullptr);
            return 0;
        }
        StaticData::purge();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "StaticData:purge",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_StaticData_purge'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tool_StaticData_shared(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"StaticData",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_StaticData_shared'", nullptr);
            return 0;
        }
        StaticData* ret = StaticData::shared();
        object_to_luaval<StaticData>(tolua_S, "StaticData",(StaticData*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "StaticData:shared",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_StaticData_shared'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tool_StaticData_LoadGameHallRes(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"StaticData",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_StaticData_LoadGameHallRes'", nullptr);
            return 0;
        }
        StaticData::LoadGameHallRes();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "StaticData:LoadGameHallRes",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_StaticData_LoadGameHallRes'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tool_StaticData_requestGoodsImageFromWeb(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"StaticData",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 3)
    {
        std::string arg0;
        int arg1;
        int arg2;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "StaticData:requestGoodsImageFromWeb");
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "StaticData:requestGoodsImageFromWeb");
        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "StaticData:requestGoodsImageFromWeb");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_StaticData_requestGoodsImageFromWeb'", nullptr);
            return 0;
        }
        StaticData::requestGoodsImageFromWeb(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "StaticData:requestGoodsImageFromWeb",argc, 3);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_StaticData_requestGoodsImageFromWeb'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_tool_StaticData_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (StaticData)");
    return 0;
}

int lua_register_cocos2dx_tool_StaticData(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"StaticData");
    tolua_cclass(tolua_S,"StaticData","StaticData","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"StaticData");
        tolua_function(tolua_S,"arrayFromKey",lua_cocos2dx_tool_StaticData_arrayFromKey);
        tolua_function(tolua_S,"sizeFromKey",lua_cocos2dx_tool_StaticData_sizeFromKey);
        tolua_function(tolua_S,"colorFromKey",lua_cocos2dx_tool_StaticData_colorFromKey);
        tolua_function(tolua_S,"rectFromKey",lua_cocos2dx_tool_StaticData_rectFromKey);
        tolua_function(tolua_S,"stringFromKey",lua_cocos2dx_tool_StaticData_stringFromKey);
        tolua_function(tolua_S,"intFromKey",lua_cocos2dx_tool_StaticData_intFromKey);
        tolua_function(tolua_S,"floatFromKey",lua_cocos2dx_tool_StaticData_floatFromKey);
        tolua_function(tolua_S,"pointFromKey",lua_cocos2dx_tool_StaticData_pointFromKey);
        tolua_function(tolua_S,"booleanFromKey",lua_cocos2dx_tool_StaticData_booleanFromKey);
        tolua_function(tolua_S,"purge", lua_cocos2dx_tool_StaticData_purge);
        tolua_function(tolua_S,"shared", lua_cocos2dx_tool_StaticData_shared);
        tolua_function(tolua_S,"LoadGameHallRes", lua_cocos2dx_tool_StaticData_LoadGameHallRes);
        tolua_function(tolua_S,"requestGoodsImageFromWeb", lua_cocos2dx_tool_StaticData_requestGoodsImageFromWeb);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(StaticData).name();
    g_luaType[typeName] = "StaticData";
    g_typeCast["StaticData"] = "StaticData";
    return 1;
}

int lua_cocos2dx_tool_ImagicDownManager_addDown(lua_State* tolua_S)
{
    int argc = 0;
    ImagicDownManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ImagicDownManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ImagicDownManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_ImagicDownManager_addDown'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        int arg0;
        std::string arg1;
        int arg2;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "ImagicDownManager:addDown");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "ImagicDownManager:addDown");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "ImagicDownManager:addDown");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_ImagicDownManager_addDown'", nullptr);
            return 0;
        }
        std::string ret = cobj->addDown(arg0, arg1, arg2);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    if (argc == 4) 
    {
        int arg0;
        std::string arg1;
        int arg2;
        bool arg3;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "ImagicDownManager:addDown");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "ImagicDownManager:addDown");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "ImagicDownManager:addDown");

        ok &= luaval_to_boolean(tolua_S, 5,&arg3, "ImagicDownManager:addDown");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_ImagicDownManager_addDown'", nullptr);
            return 0;
        }
        std::string ret = cobj->addDown(arg0, arg1, arg2, arg3);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    if (argc == 5) 
    {
        int arg0;
        std::string arg1;
        int arg2;
        bool arg3;
        int arg4;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "ImagicDownManager:addDown");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "ImagicDownManager:addDown");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "ImagicDownManager:addDown");

        ok &= luaval_to_boolean(tolua_S, 5,&arg3, "ImagicDownManager:addDown");

        ok &= luaval_to_int32(tolua_S, 6,(int *)&arg4, "ImagicDownManager:addDown");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_ImagicDownManager_addDown'", nullptr);
            return 0;
        }
        std::string ret = cobj->addDown(arg0, arg1, arg2, arg3, arg4);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ImagicDownManager:addDown",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_ImagicDownManager_addDown'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_ImagicDownManager_ExistDownFile(lua_State* tolua_S)
{
    int argc = 0;
    ImagicDownManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ImagicDownManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ImagicDownManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_ImagicDownManager_ExistDownFile'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        eDownType arg0;
        std::string arg1;
        int arg2;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "ImagicDownManager:ExistDownFile");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "ImagicDownManager:ExistDownFile");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "ImagicDownManager:ExistDownFile");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_ImagicDownManager_ExistDownFile'", nullptr);
            return 0;
        }
        std::string ret = cobj->ExistDownFile(arg0, arg1, arg2);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ImagicDownManager:ExistDownFile",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_ImagicDownManager_ExistDownFile'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_ImagicDownManager_GetInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ImagicDownManager",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_ImagicDownManager_GetInstance'", nullptr);
            return 0;
        }
        ImagicDownManager* ret = ImagicDownManager::GetInstance();
        object_to_luaval<ImagicDownManager>(tolua_S, "ImagicDownManager",(ImagicDownManager*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "ImagicDownManager:GetInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_ImagicDownManager_GetInstance'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_tool_ImagicDownManager_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ImagicDownManager)");
    return 0;
}

int lua_register_cocos2dx_tool_ImagicDownManager(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"ImagicDownManager");
    tolua_cclass(tolua_S,"ImagicDownManager","ImagicDownManager","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"ImagicDownManager");
        tolua_function(tolua_S,"addDown",lua_cocos2dx_tool_ImagicDownManager_addDown);
        tolua_function(tolua_S,"ExistDownFile",lua_cocos2dx_tool_ImagicDownManager_ExistDownFile);
        tolua_function(tolua_S,"GetInstance", lua_cocos2dx_tool_ImagicDownManager_GetInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(ImagicDownManager).name();
    g_luaType[typeName] = "ImagicDownManager";
    g_typeCast["ImagicDownManager"] = "ImagicDownManager";
    return 1;
}

int lua_cocos2dx_tool_StringConvert_StringToLongLong(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"StringConvert",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "StringConvert:StringToLongLong");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_StringConvert_StringToLongLong'", nullptr);
            return 0;
        }
        long long ret = StringConvert::StringToLongLong(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "StringConvert:StringToLongLong",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_StringConvert_StringToLongLong'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tool_StringConvert_floatToString(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"StringConvert",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        double arg0;
        ok &= luaval_to_number(tolua_S, 2,&arg0, "StringConvert:floatToString");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_StringConvert_floatToString'", nullptr);
            return 0;
        }
        std::string ret = StringConvert::floatToString(arg0);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "StringConvert:floatToString",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_StringConvert_floatToString'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tool_StringConvert_strGBKLength(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"StringConvert",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "StringConvert:strGBKLength");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_StringConvert_strGBKLength'", nullptr);
            return 0;
        }
        int ret = StringConvert::strGBKLength(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "StringConvert:strGBKLength",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_StringConvert_strGBKLength'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tool_StringConvert_ConvertPhoneNumber(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"StringConvert",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "StringConvert:ConvertPhoneNumber");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_StringConvert_ConvertPhoneNumber'", nullptr);
            return 0;
        }
        long long ret = StringConvert::ConvertPhoneNumber(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "StringConvert:ConvertPhoneNumber",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_StringConvert_ConvertPhoneNumber'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tool_StringConvert_SimpleScore(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"StringConvert",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        long long arg0;
        ok &= luaval_to_long_long(tolua_S, 2,&arg0, "StringConvert:SimpleScore");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_StringConvert_SimpleScore'", nullptr);
            return 0;
        }
        std::string ret = StringConvert::SimpleScore(arg0);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "StringConvert:SimpleScore",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_StringConvert_SimpleScore'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tool_StringConvert_IntToString(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"StringConvert",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "StringConvert:IntToString");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_StringConvert_IntToString'", nullptr);
            return 0;
        }
        std::string ret = StringConvert::IntToString(arg0);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "StringConvert:IntToString",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_StringConvert_IntToString'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tool_StringConvert_lenghOfU8Str(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"StringConvert",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "StringConvert:lenghOfU8Str"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_StringConvert_lenghOfU8Str'", nullptr);
            return 0;
        }
        int ret = StringConvert::lenghOfU8Str(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "StringConvert:lenghOfU8Str",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_StringConvert_lenghOfU8Str'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tool_StringConvert_utf8_gbk(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"StringConvert",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "StringConvert:utf8_gbk"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_StringConvert_utf8_gbk'", nullptr);
            return 0;
        }
        std::string ret = StringConvert::utf8_gbk(arg0);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "StringConvert:utf8_gbk",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_StringConvert_utf8_gbk'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tool_StringConvert_subUTF8(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"StringConvert",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 3)
    {
        std::string arg0;
        int arg1;
        int arg2;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "StringConvert:subUTF8");
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "StringConvert:subUTF8");
        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "StringConvert:subUTF8");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_StringConvert_subUTF8'", nullptr);
            return 0;
        }
        std::string ret = StringConvert::subUTF8(arg0, arg1, arg2);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "StringConvert:subUTF8",argc, 3);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_StringConvert_subUTF8'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tool_StringConvert_StringToInt(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"StringConvert",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "StringConvert:StringToInt");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_StringConvert_StringToInt'", nullptr);
            return 0;
        }
        int ret = StringConvert::StringToInt(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "StringConvert:StringToInt",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_StringConvert_StringToInt'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tool_StringConvert_LongToString(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"StringConvert",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        long arg0;
        ok &= luaval_to_long(tolua_S, 2, &arg0, "StringConvert:LongToString");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_StringConvert_LongToString'", nullptr);
            return 0;
        }
        std::string ret = StringConvert::LongToString(arg0);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "StringConvert:LongToString",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_StringConvert_LongToString'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tool_StringConvert_IsNumber(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"StringConvert",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "StringConvert:IsNumber");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_StringConvert_IsNumber'", nullptr);
            return 0;
        }
        bool ret = StringConvert::IsNumber(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "StringConvert:IsNumber",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_StringConvert_IsNumber'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tool_StringConvert_gbk_utf8(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"StringConvert",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "StringConvert:gbk_utf8"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_StringConvert_gbk_utf8'", nullptr);
            return 0;
        }
        std::string ret = StringConvert::gbk_utf8(arg0);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "StringConvert:gbk_utf8",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_StringConvert_gbk_utf8'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tool_StringConvert_StringTofloat(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"StringConvert",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "StringConvert:StringTofloat");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_StringConvert_StringTofloat'", nullptr);
            return 0;
        }
        double ret = StringConvert::StringTofloat(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "StringConvert:StringTofloat",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_StringConvert_StringTofloat'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tool_StringConvert_StringToLong(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"StringConvert",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "StringConvert:StringToLong");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_StringConvert_StringToLong'", nullptr);
            return 0;
        }
        long ret = StringConvert::StringToLong(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "StringConvert:StringToLong",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_StringConvert_StringToLong'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_tool_StringConvert_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (StringConvert)");
    return 0;
}

int lua_register_cocos2dx_tool_StringConvert(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"StringConvert");
    tolua_cclass(tolua_S,"StringConvert","StringConvert","",nullptr);

    tolua_beginmodule(tolua_S,"StringConvert");
        tolua_function(tolua_S,"StringToLongLong", lua_cocos2dx_tool_StringConvert_StringToLongLong);
        tolua_function(tolua_S,"floatToString", lua_cocos2dx_tool_StringConvert_floatToString);
        tolua_function(tolua_S,"strGBKLength", lua_cocos2dx_tool_StringConvert_strGBKLength);
        tolua_function(tolua_S,"ConvertPhoneNumber", lua_cocos2dx_tool_StringConvert_ConvertPhoneNumber);
        tolua_function(tolua_S,"SimpleScore", lua_cocos2dx_tool_StringConvert_SimpleScore);
        tolua_function(tolua_S,"IntToString", lua_cocos2dx_tool_StringConvert_IntToString);
        tolua_function(tolua_S,"lenghOfU8Str", lua_cocos2dx_tool_StringConvert_lenghOfU8Str);
        tolua_function(tolua_S,"utf8_gbk", lua_cocos2dx_tool_StringConvert_utf8_gbk);
        tolua_function(tolua_S,"subUTF8", lua_cocos2dx_tool_StringConvert_subUTF8);
        tolua_function(tolua_S,"StringToInt", lua_cocos2dx_tool_StringConvert_StringToInt);
        tolua_function(tolua_S,"LongToString", lua_cocos2dx_tool_StringConvert_LongToString);
        tolua_function(tolua_S,"IsNumber", lua_cocos2dx_tool_StringConvert_IsNumber);
        tolua_function(tolua_S,"gbk_utf8", lua_cocos2dx_tool_StringConvert_gbk_utf8);
        tolua_function(tolua_S,"StringTofloat", lua_cocos2dx_tool_StringConvert_StringTofloat);
        tolua_function(tolua_S,"StringToLong", lua_cocos2dx_tool_StringConvert_StringToLong);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(StringConvert).name();
    g_luaType[typeName] = "StringConvert";
    g_typeCast["StringConvert"] = "StringConvert";
    return 1;
}

int lua_cocos2dx_tool_PacketReadAide_readInt32(lua_State* tolua_S)
{
    int argc = 0;
    PacketReadAide* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"PacketReadAide",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (PacketReadAide*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_PacketReadAide_readInt32'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_PacketReadAide_readInt32'", nullptr);
            return 0;
        }
        int ret = cobj->readInt32();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "PacketReadAide:readInt32",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_PacketReadAide_readInt32'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_PacketReadAide_readu8Byte(lua_State* tolua_S)
{
    int argc = 0;
    PacketReadAide* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"PacketReadAide",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (PacketReadAide*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_PacketReadAide_readu8Byte'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_PacketReadAide_readu8Byte'", nullptr);
            return 0;
        }
        unsigned long long ret = cobj->readu8Byte();
        #pragma warning NO CONVERSION FROM NATIVE FOR unsigned long long;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "PacketReadAide:readu8Byte",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_PacketReadAide_readu8Byte'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_PacketReadAide_readStdString(lua_State* tolua_S)
{
    int argc = 0;
    PacketReadAide* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"PacketReadAide",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (PacketReadAide*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_PacketReadAide_readStdString'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "PacketReadAide:readStdString");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_PacketReadAide_readStdString'", nullptr);
            return 0;
        }
        std::string ret = cobj->readStdString(arg0);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "PacketReadAide:readStdString",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_PacketReadAide_readStdString'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_PacketReadAide_read4Byte(lua_State* tolua_S)
{
    int argc = 0;
    PacketReadAide* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"PacketReadAide",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (PacketReadAide*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_PacketReadAide_read4Byte'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_PacketReadAide_read4Byte'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->read4Byte();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "PacketReadAide:read4Byte",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_PacketReadAide_read4Byte'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_PacketReadAide_readInt16(lua_State* tolua_S)
{
    int argc = 0;
    PacketReadAide* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"PacketReadAide",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (PacketReadAide*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_PacketReadAide_readInt16'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_PacketReadAide_readInt16'", nullptr);
            return 0;
        }
        int32_t ret = cobj->readInt16();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "PacketReadAide:readInt16",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_PacketReadAide_readInt16'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_PacketReadAide_readLong(lua_State* tolua_S)
{
    int argc = 0;
    PacketReadAide* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"PacketReadAide",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (PacketReadAide*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_PacketReadAide_readLong'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_PacketReadAide_readLong'", nullptr);
            return 0;
        }
        long ret = cobj->readLong();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "PacketReadAide:readLong",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_PacketReadAide_readLong'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_PacketReadAide_read2Byte(lua_State* tolua_S)
{
    int argc = 0;
    PacketReadAide* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"PacketReadAide",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (PacketReadAide*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_PacketReadAide_read2Byte'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_PacketReadAide_read2Byte'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->read2Byte();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "PacketReadAide:read2Byte",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_PacketReadAide_read2Byte'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_PacketReadAide_readByte(lua_State* tolua_S)
{
    int argc = 0;
    PacketReadAide* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"PacketReadAide",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (PacketReadAide*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_PacketReadAide_readByte'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_PacketReadAide_readByte'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->readByte();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "PacketReadAide:readByte",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_PacketReadAide_readByte'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_PacketReadAide_read8Byte(lua_State* tolua_S)
{
    int argc = 0;
    PacketReadAide* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"PacketReadAide",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (PacketReadAide*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_PacketReadAide_read8Byte'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_PacketReadAide_read8Byte'", nullptr);
            return 0;
        }
        long long ret = cobj->read8Byte();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "PacketReadAide:read8Byte",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_PacketReadAide_read8Byte'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_PacketReadAide_setPosition(lua_State* tolua_S)
{
    int argc = 0;
    PacketReadAide* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"PacketReadAide",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (PacketReadAide*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_PacketReadAide_setPosition'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "PacketReadAide:setPosition");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_PacketReadAide_setPosition'", nullptr);
            return 0;
        }
        cobj->setPosition(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "PacketReadAide:setPosition",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_PacketReadAide_setPosition'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_PacketReadAide_getBuffer(lua_State* tolua_S)
{
    int argc = 0;
    PacketReadAide* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"PacketReadAide",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (PacketReadAide*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_PacketReadAide_getBuffer'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_PacketReadAide_getBuffer'", nullptr);
            return 0;
        }
        cocos2d::Ref* ret = cobj->getBuffer();
        object_to_luaval<cocos2d::Ref>(tolua_S, "cc.Ref",(cocos2d::Ref*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "PacketReadAide:getBuffer",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_PacketReadAide_getBuffer'.",&tolua_err);
#endif

    return 0;
}

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS )
#include "bugly/CrashReport.h"
#endif

int lua_cocos2dx_tool_PacketReadAide_readString(lua_State* tolua_S)
{
    int argc = 0;
    PacketReadAide* cobj = nullptr;
    bool ok  = true;
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS )
	int stacklevel = lua_gettop(tolua_S);
	lua_getglobal(tolua_S, "debug");
	lua_getfield(tolua_S, -1, "traceback");
	int iError = lua_pcall(tolua_S,//VMachine    
		0,//Argument Count    
		1,//Return Value Count    
		0);
	const char* sz = lua_tostring(tolua_S, -1);
	lua_settop(tolua_S, stacklevel);
	cocos2d::log("lua stack setvisible = %s", sz);
#endif

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"PacketReadAide",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (PacketReadAide*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_PacketReadAide_readString'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "PacketReadAide:readString");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_PacketReadAide_readString'", nullptr);
            return 0;
        }
        std::string ret = cobj->readString(arg0);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "PacketReadAide:readString",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_PacketReadAide_readString'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_PacketReadAide_getPosition(lua_State* tolua_S)
{
    int argc = 0;
    PacketReadAide* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"PacketReadAide",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (PacketReadAide*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_PacketReadAide_getPosition'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_PacketReadAide_getPosition'", nullptr);
            return 0;
        }
        int ret = cobj->getPosition();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "PacketReadAide:getPosition",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_PacketReadAide_getPosition'.",&tolua_err);
#endif

    return 0;
}
static int lua_cocos2dx_tool_PacketReadAide_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (PacketReadAide)");
    return 0;
}

int lua_register_cocos2dx_tool_PacketReadAide(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"PacketReadAide");
    tolua_cclass(tolua_S,"PacketReadAide","PacketReadAide","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"PacketReadAide");
        tolua_function(tolua_S,"readInt32",lua_cocos2dx_tool_PacketReadAide_readInt32);
        tolua_function(tolua_S,"readu8Byte",lua_cocos2dx_tool_PacketReadAide_readu8Byte);
        tolua_function(tolua_S,"readStdString",lua_cocos2dx_tool_PacketReadAide_readStdString);
        tolua_function(tolua_S,"read4Byte",lua_cocos2dx_tool_PacketReadAide_read4Byte);
        tolua_function(tolua_S,"readInt16",lua_cocos2dx_tool_PacketReadAide_readInt16);
        tolua_function(tolua_S,"readLong",lua_cocos2dx_tool_PacketReadAide_readLong);
        tolua_function(tolua_S,"read2Byte",lua_cocos2dx_tool_PacketReadAide_read2Byte);
        tolua_function(tolua_S,"readByte",lua_cocos2dx_tool_PacketReadAide_readByte);
        tolua_function(tolua_S,"read8Byte",lua_cocos2dx_tool_PacketReadAide_read8Byte);
        tolua_function(tolua_S,"setPosition",lua_cocos2dx_tool_PacketReadAide_setPosition);
        tolua_function(tolua_S,"getBuffer",lua_cocos2dx_tool_PacketReadAide_getBuffer);
        tolua_function(tolua_S,"readString",lua_cocos2dx_tool_PacketReadAide_readString);
        tolua_function(tolua_S,"getPosition",lua_cocos2dx_tool_PacketReadAide_getPosition);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(PacketReadAide).name();
    g_luaType[typeName] = "PacketReadAide";
    g_typeCast["PacketReadAide"] = "PacketReadAide";
    return 1;
}

int lua_cocos2dx_tool_PacketWriteAide_write4Byte(lua_State* tolua_S)
{
    int argc = 0;
    PacketWriteAide* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"PacketWriteAide",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (PacketWriteAide*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_PacketWriteAide_write4Byte'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "PacketWriteAide:write4Byte");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_PacketWriteAide_write4Byte'", nullptr);
            return 0;
        }
        cobj->write4Byte(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "PacketWriteAide:write4Byte",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_PacketWriteAide_write4Byte'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_PacketWriteAide_writeString(lua_State* tolua_S)
{
    int argc = 0;
    PacketWriteAide* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"PacketWriteAide",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (PacketWriteAide*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_PacketWriteAide_writeString'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "PacketWriteAide:writeString"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            cobj->writeString(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 2) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "PacketWriteAide:writeString"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            int arg1;
            ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "PacketWriteAide:writeString");

            if (!ok) { break; }
            cobj->writeString(arg0, arg1);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "PacketWriteAide:writeString",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_PacketWriteAide_writeString'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_PacketWriteAide_write2Byte(lua_State* tolua_S)
{
    int argc = 0;
    PacketWriteAide* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"PacketWriteAide",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (PacketWriteAide*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_PacketWriteAide_write2Byte'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "PacketWriteAide:write2Byte");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_PacketWriteAide_write2Byte'", nullptr);
            return 0;
        }
        cobj->write2Byte(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "PacketWriteAide:write2Byte",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_PacketWriteAide_write2Byte'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_PacketWriteAide_write8Byte(lua_State* tolua_S)
{
    int argc = 0;
    PacketWriteAide* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"PacketWriteAide",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (PacketWriteAide*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_PacketWriteAide_write8Byte'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        long long arg0;

        ok &= luaval_to_long_long(tolua_S, 2,&arg0, "PacketWriteAide:write8Byte");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_PacketWriteAide_write8Byte'", nullptr);
            return 0;
        }
        cobj->write8Byte(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "PacketWriteAide:write8Byte",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_PacketWriteAide_write8Byte'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_PacketWriteAide_writeStdString(lua_State* tolua_S)
{
    int argc = 0;
    PacketWriteAide* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"PacketWriteAide",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (PacketWriteAide*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_PacketWriteAide_writeStdString'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        int arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "PacketWriteAide:writeStdString"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "PacketWriteAide:writeStdString");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_PacketWriteAide_writeStdString'", nullptr);
            return 0;
        }
        cobj->writeStdString(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "PacketWriteAide:writeStdString",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_PacketWriteAide_writeStdString'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_PacketWriteAide_writeByte(lua_State* tolua_S)
{
    int argc = 0;
    PacketWriteAide* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"PacketWriteAide",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (PacketWriteAide*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_PacketWriteAide_writeByte'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "PacketWriteAide:writeByte");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_PacketWriteAide_writeByte'", nullptr);
            return 0;
        }
        cobj->writeByte(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "PacketWriteAide:writeByte",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_PacketWriteAide_writeByte'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_PacketWriteAide_setPosition(lua_State* tolua_S)
{
    int argc = 0;
    PacketWriteAide* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"PacketWriteAide",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (PacketWriteAide*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_PacketWriteAide_setPosition'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "PacketWriteAide:setPosition");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_PacketWriteAide_setPosition'", nullptr);
            return 0;
        }
        cobj->setPosition(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "PacketWriteAide:setPosition",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_PacketWriteAide_setPosition'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_PacketWriteAide_getBuffer(lua_State* tolua_S)
{
    int argc = 0;
    PacketWriteAide* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"PacketWriteAide",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (PacketWriteAide*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_PacketWriteAide_getBuffer'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_PacketWriteAide_getBuffer'", nullptr);
            return 0;
        }
        cocos2d::Ref* ret = cobj->getBuffer();
        object_to_luaval<cocos2d::Ref>(tolua_S, "cc.Ref",(cocos2d::Ref*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "PacketWriteAide:getBuffer",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_PacketWriteAide_getBuffer'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_PacketWriteAide_getPosition(lua_State* tolua_S)
{
    int argc = 0;
    PacketWriteAide* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"PacketWriteAide",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (PacketWriteAide*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_PacketWriteAide_getPosition'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_PacketWriteAide_getPosition'", nullptr);
            return 0;
        }
        int ret = cobj->getPosition();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "PacketWriteAide:getPosition",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_PacketWriteAide_getPosition'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_PacketWriteAide_constructor(lua_State* tolua_S)
{
    int argc = 0;
    PacketWriteAide* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_PacketWriteAide_constructor'", nullptr);
            return 0;
        }
        cobj = new PacketWriteAide();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"PacketWriteAide");
        return 1;
    }
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "PacketWriteAide:PacketWriteAide");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_PacketWriteAide_constructor'", nullptr);
            return 0;
        }
        cobj = new PacketWriteAide(arg0);
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"PacketWriteAide");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "PacketWriteAide:PacketWriteAide",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_PacketWriteAide_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_tool_PacketWriteAide_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (PacketWriteAide)");
    return 0;
}

int lua_register_cocos2dx_tool_PacketWriteAide(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"PacketWriteAide");
    tolua_cclass(tolua_S,"PacketWriteAide","PacketWriteAide","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"PacketWriteAide");
        tolua_function(tolua_S,"new",lua_cocos2dx_tool_PacketWriteAide_constructor);
        tolua_function(tolua_S,"write4Byte",lua_cocos2dx_tool_PacketWriteAide_write4Byte);
        tolua_function(tolua_S,"writeString",lua_cocos2dx_tool_PacketWriteAide_writeString);
        tolua_function(tolua_S,"write2Byte",lua_cocos2dx_tool_PacketWriteAide_write2Byte);
        tolua_function(tolua_S,"write8Byte",lua_cocos2dx_tool_PacketWriteAide_write8Byte);
        tolua_function(tolua_S,"writeStdString",lua_cocos2dx_tool_PacketWriteAide_writeStdString);
        tolua_function(tolua_S,"writeByte",lua_cocos2dx_tool_PacketWriteAide_writeByte);
        tolua_function(tolua_S,"setPosition",lua_cocos2dx_tool_PacketWriteAide_setPosition);
        tolua_function(tolua_S,"getBuffer",lua_cocos2dx_tool_PacketWriteAide_getBuffer);
        tolua_function(tolua_S,"getPosition",lua_cocos2dx_tool_PacketWriteAide_getPosition);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(PacketWriteAide).name();
    g_luaType[typeName] = "PacketWriteAide";
    g_typeCast["PacketWriteAide"] = "PacketWriteAide";
    return 1;
}

int lua_cocos2dx_tool_StringData_stringFromKey(lua_State* tolua_S)
{
    int argc = 0;
    StringData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"StringData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (StringData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_StringData_stringFromKey'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "StringData:stringFromKey");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_StringData_stringFromKey'", nullptr);
            return 0;
        }
        const char* ret = cobj->stringFromKey(arg0);
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "StringData:stringFromKey",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_StringData_stringFromKey'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_StringData_purge(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"StringData",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_StringData_purge'", nullptr);
            return 0;
        }
        StringData::purge();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "StringData:purge",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_StringData_purge'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tool_StringData_shared(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"StringData",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_StringData_shared'", nullptr);
            return 0;
        }
        StringData* ret = StringData::shared();
        object_to_luaval<StringData>(tolua_S, "StringData",(StringData*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "StringData:shared",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_StringData_shared'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_tool_StringData_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (StringData)");
    return 0;
}

int lua_register_cocos2dx_tool_StringData(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"StringData");
    tolua_cclass(tolua_S,"StringData","StringData","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"StringData");
        tolua_function(tolua_S,"stringFromKey",lua_cocos2dx_tool_StringData_stringFromKey);
        tolua_function(tolua_S,"purge", lua_cocos2dx_tool_StringData_purge);
        tolua_function(tolua_S,"shared", lua_cocos2dx_tool_StringData_shared);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(StringData).name();
    g_luaType[typeName] = "StringData";
    g_typeCast["StringData"] = "StringData";
    return 1;
}

int lua_cocos2dx_tool_MyConfigureData_intFromKey(lua_State* tolua_S)
{
    int argc = 0;
    MyConfigureData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MyConfigureData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MyConfigureData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_MyConfigureData_intFromKey'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "MyConfigureData:intFromKey");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_MyConfigureData_intFromKey'", nullptr);
            return 0;
        }
        int ret = cobj->intFromKey(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MyConfigureData:intFromKey",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_MyConfigureData_intFromKey'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_MyConfigureData_stringFromKey(lua_State* tolua_S)
{
    int argc = 0;
    MyConfigureData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MyConfigureData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MyConfigureData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_MyConfigureData_stringFromKey'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "MyConfigureData:stringFromKey");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_MyConfigureData_stringFromKey'", nullptr);
            return 0;
        }
        const char* ret = cobj->stringFromKey(arg0);
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MyConfigureData:stringFromKey",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_MyConfigureData_stringFromKey'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_MyConfigureData_purge(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"MyConfigureData",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_MyConfigureData_purge'", nullptr);
            return 0;
        }
        MyConfigureData::purge();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "MyConfigureData:purge",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_MyConfigureData_purge'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tool_MyConfigureData_shared(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"MyConfigureData",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_MyConfigureData_shared'", nullptr);
            return 0;
        }
        MyConfigureData* ret = MyConfigureData::shared();
        object_to_luaval<MyConfigureData>(tolua_S, "MyConfigureData",(MyConfigureData*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "MyConfigureData:shared",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_MyConfigureData_shared'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_tool_MyConfigureData_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (MyConfigureData)");
    return 0;
}

int lua_register_cocos2dx_tool_MyConfigureData(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"MyConfigureData");
    tolua_cclass(tolua_S,"MyConfigureData","MyConfigureData","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"MyConfigureData");
        tolua_function(tolua_S,"intFromKey",lua_cocos2dx_tool_MyConfigureData_intFromKey);
        tolua_function(tolua_S,"stringFromKey",lua_cocos2dx_tool_MyConfigureData_stringFromKey);
        tolua_function(tolua_S,"purge", lua_cocos2dx_tool_MyConfigureData_purge);
        tolua_function(tolua_S,"shared", lua_cocos2dx_tool_MyConfigureData_shared);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(MyConfigureData).name();
    g_luaType[typeName] = "MyConfigureData";
    g_typeCast["MyConfigureData"] = "MyConfigureData";
    return 1;
}

int lua_cocos2dx_tool_Game_Path_Manager_initialise_paths(lua_State* tolua_S)
{
    int argc = 0;
    Game_Path_Manager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Game_Path_Manager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (Game_Path_Manager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_Game_Path_Manager_initialise_paths'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "Game_Path_Manager:initialise_paths");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_Game_Path_Manager_initialise_paths'", nullptr);
            return 0;
        }
        bool ret = cobj->initialise_paths(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "Game_Path_Manager:initialise_paths",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_Game_Path_Manager_initialise_paths'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_Game_Path_Manager_purge(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"Game_Path_Manager",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_Game_Path_Manager_purge'", nullptr);
            return 0;
        }
        Game_Path_Manager::purge();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "Game_Path_Manager:purge",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_Game_Path_Manager_purge'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tool_Game_Path_Manager_shared(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"Game_Path_Manager",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_Game_Path_Manager_shared'", nullptr);
            return 0;
        }
        Game_Path_Manager* ret = Game_Path_Manager::shared();
        object_to_luaval<Game_Path_Manager>(tolua_S, "Game_Path_Manager",(Game_Path_Manager*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "Game_Path_Manager:shared",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_Game_Path_Manager_shared'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_tool_Game_Path_Manager_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (Game_Path_Manager)");
    return 0;
}

int lua_register_cocos2dx_tool_Game_Path_Manager(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"Game_Path_Manager");
    tolua_cclass(tolua_S,"Game_Path_Manager","Game_Path_Manager","",nullptr);

    tolua_beginmodule(tolua_S,"Game_Path_Manager");
        tolua_function(tolua_S,"initialise_paths",lua_cocos2dx_tool_Game_Path_Manager_initialise_paths);
        tolua_function(tolua_S,"purge", lua_cocos2dx_tool_Game_Path_Manager_purge);
        tolua_function(tolua_S,"shared", lua_cocos2dx_tool_Game_Path_Manager_shared);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(Game_Path_Manager).name();
    g_luaType[typeName] = "Game_Path_Manager";
    g_typeCast["Game_Path_Manager"] = "Game_Path_Manager";
    return 1;
}

int lua_cocos2dx_tool_Action_Bullet_Move6_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"Action_Bullet_Move6",0,&tolua_err)) goto tolua_lerror;
#endif
    
    argc = lua_gettop(tolua_S) - 1;
    
    if (argc == 2)
    {
        float arg0;
        float arg1;
        
        double arg0_tmp;
        double arg1_tmp;
        
        
        ok &= luaval_to_number(tolua_S, 2, &arg0_tmp, "Action_Bullet_Move6:create");
        ok &= luaval_to_number(tolua_S, 3, &arg1_tmp, "Action_Bullet_Move6:create");
        
        
        arg0 = arg0_tmp;
        arg1 = arg1_tmp;
        
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_Action_Bullet_Move6_create'", nullptr);
            return 0;
        }
        
        Action* ret = Dntg::Action_Bullet_Move6::create(arg0, arg1);
        CCActionInterval* act = CCSequence::create(
                                                   CCDelayTime::create(0),
                                                   ret,
                                                   nullptr);
        CCAction* actSpeed = CCSpeed::create(act, 1);
        
        object_to_luaval<cocos2d::Action>(tolua_S, "cc.Action",(cocos2d::Action*)act);
        
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "Action_Bullet_Move6:create",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_Action_Bullet_Move6_create'.",&tolua_err);
#endif
    return 0;
}

int lua_register_cocos2dx_tool_Action_Bullet_Move6(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"Action_Bullet_Move6");
    tolua_cclass(tolua_S,"Action_Bullet_Move6","Action_Bullet_Move6","",nullptr);
    
    tolua_beginmodule(tolua_S,"Action_Bullet_Move6");
    tolua_function(tolua_S,"create",lua_cocos2dx_tool_Action_Bullet_Move6_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(Dntg::Action_Bullet_Move6).name();
    g_luaType[typeName] = "Action_Bullet_Move6";
    g_typeCast["Action_Bullet_Move6"] = "Action_Bullet_Move6";
    return 1;
}

int lua_cocos2dx_tool_Action_Move_Point6_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"Action_Move_Point6",0,&tolua_err)) goto tolua_lerror;
#endif
    
    argc = lua_gettop(tolua_S) - 1;
    
    if (argc == 3)
    {
        std::string arg0;
        double arg1;
        std::string arg2;
        std::string arg0_tmp;
        std::string arg2_tmp;
        ok &= luaval_to_number(tolua_S, 2,&arg1, "Action_Move_Point6:create");
        
        ok &= luaval_to_std_string(tolua_S, 3, &arg0_tmp, "Action_Move_Point6:create");
        ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp, "Action_Move_Point6:create");
        
        
        arg0 = arg0_tmp;
        arg2 = arg2_tmp;
        
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_Action_Move_Point6_create'", nullptr);
            return 0;
        }
        
        Action* ret = Dntg::Action_Move_Point6::create(arg1, arg0,arg2);
        CCActionInterval* act = CCSequence::create(
                                                   CCDelayTime::create(0),
                                                   ret,
                                                    nullptr);
        CCAction* actSpeed = CCSpeed::create(act, 1);
        
        object_to_luaval<cocos2d::Action>(tolua_S, "cc.Action",(cocos2d::Action*)actSpeed);
        
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "Action_Move_Point:create",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_Action_Move_Point6_create'.",&tolua_err);
#endif
    return 0;
}

int lua_register_cocos2dx_tool_Action_Move_Point6(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"Action_Move_Point6");
    tolua_cclass(tolua_S,"Action_Move_Point6","Action_Move_Point6","",nullptr);
    
    tolua_beginmodule(tolua_S,"Action_Move_Point6");
    tolua_function(tolua_S,"create",lua_cocos2dx_tool_Action_Move_Point6_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(Dntg::Action_Move_Point6).name();
    g_luaType[typeName] = "Action_Move_Point6";
    g_typeCast["Action_Move_Point6"] = "Action_Move_Point6";
    return 1;
}


int lua_cocos2dx_tool_Action_Bird_Move_Linear6_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"Action_Bird_Move_Linear6",0,&tolua_err)) goto tolua_lerror;
#endif
    
    argc = lua_gettop(tolua_S) - 1;
    
    if (argc == 3)
    {
        std::string arg0;
        double arg1;
        std::string arg2;
        std::string arg0_tmp;
        std::string arg2_tmp;
        ok &= luaval_to_number(tolua_S, 2,&arg1, "Action_Bird_Move_Linear6:create");
        
        ok &= luaval_to_std_string(tolua_S, 3, &arg0_tmp, "Action_Bird_Move_Linear6:create");
        ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp, "Action_Bird_Move_Linear6:create");
        
        arg0 = arg0_tmp;
        arg2 = arg2_tmp;
        
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_Action_Bird_Move_Linear6_create'", nullptr);
            return 0;
        }
        
        Action* ret = Dntg::Action_Bird_Move_Linear6::create(arg1, arg0,arg2);
        CCActionInterval* act = CCSequence::create(
                                                   CCDelayTime::create(0),
                                                   ret,
                                                   nullptr);
        CCAction* actSpeed = CCSpeed::create(act, 1);
        
        object_to_luaval<cocos2d::Action>(tolua_S, "cc.Action",(cocos2d::Action*)actSpeed);
        
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "Action_Bird_Move_Linear6:create",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_Action_Bird_Move_Linear6_create'.",&tolua_err);
#endif
    return 0;
}

int lua_register_cocos2dx_tool_Action_Bird_Move_Linear6(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"Action_Bird_Move_Linear6");
    tolua_cclass(tolua_S,"Action_Bird_Move_Linear6","Action_Bird_Move_Linear6","",nullptr);
    
    tolua_beginmodule(tolua_S,"Action_Bird_Move_Linear6");
    tolua_function(tolua_S,"create",lua_cocos2dx_tool_Action_Bird_Move_Linear6_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(Dntg::Action_Bird_Move_Linear6).name();
    g_luaType[typeName] = "Action_Bird_Move_Linear6";
    g_typeCast["Action_Bird_Move_Linear6"] = "Action_Bird_Move_Linear6";
    return 1;
}


int lua_cocos2dx_tool_Action_Bird_Round_Move6_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"Action_Bird_Round_Move6",0,&tolua_err)) goto tolua_lerror;
#endif
    
    argc = lua_gettop(tolua_S) - 1;
    
    if (argc == 8)
    {
        std::string arg0;
        float arg1;
        float arg2;
        float arg3;
        float arg4;
        float arg5;
        float arg6;
        bool  arg7;
        
        
        std::string arg0_tmp;
        double arg1_tmp;
        double arg2_tmp;
        double arg3_tmp;
        double arg4_tmp;
        double arg5_tmp;
        double arg6_tmp;
        bool arg7_tmp;
        
        ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "Action_Bird_Round_Move6:create");

        ok &= luaval_to_number(tolua_S, 3, &arg1_tmp, "Action_Bird_Round_Move6:create");
        
        ok &= luaval_to_number(tolua_S, 4, &arg2_tmp, "Action_Bird_Round_Move6:create");
        ok &= luaval_to_number(tolua_S, 5, &arg3_tmp, "Action_Bird_Round_Move6:create");
        ok &= luaval_to_number(tolua_S, 6, &arg4_tmp, "Action_Bird_Round_Move6:create");
        ok &= luaval_to_number(tolua_S, 7, &arg5_tmp, "Action_Bird_Round_Move6:create");
        ok &= luaval_to_number(tolua_S, 8, &arg6_tmp, "Action_Bird_Round_Move6:create");
        ok &= luaval_to_boolean(tolua_S, 9, &arg7_tmp, "Action_Bird_Round_Move6:create");
        
        
        arg0 = arg0_tmp;
        arg1 = arg1_tmp;
        arg2 = arg2_tmp;
        arg3 = arg3_tmp;
        arg4 = arg4_tmp;
        arg5 = arg5_tmp;
        arg6 = arg6_tmp;
        arg7 = arg7_tmp;
        
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_Action_Bird_Round_Move6_create'", nullptr);
            return 0;
        }
        
                Action* ret = Dntg::Action_Bird_Round_Move6::create(arg0, arg1,arg2,arg3,arg4,arg5,arg6,arg7);
                CCActionInterval* act = CCSequence::create(
                                                           CCDelayTime::create(0),
                                                           ret,
                                                           nullptr);
                CCAction* actSpeed = CCSpeed::create(act, 3.7);
        
                object_to_luaval<cocos2d::Action>(tolua_S, "cc.Action",(cocos2d::Action*)actSpeed);
        
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "Action_Bird_Round_Move6:create",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_Action_Bird_Round_Move6_create'.",&tolua_err);
#endif
    return 0;
}

int lua_register_cocos2dx_tool_Action_Bird_Round_Move6(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"Action_Bird_Round_Move6");
    tolua_cclass(tolua_S,"Action_Bird_Round_Move6","Action_Bird_Round_Move6","",nullptr);
    
    tolua_beginmodule(tolua_S,"Action_Bird_Round_Move6");
    tolua_function(tolua_S,"create",lua_cocos2dx_tool_Action_Bird_Round_Move6_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(Dntg::Action_Bird_Move_Linear6).name();
    g_luaType[typeName] = "Action_Bird_Round_Move6";
    g_typeCast["Action_Bird_Round_Move6"] = "Action_Bird_Round_Move6";
    return 1;
}


int lua_cocos2dx_tool_Action_Action_Bird_Move_Pause_Linear6_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"Action_Bird_Move_Pause_Linear6",0,&tolua_err)) goto tolua_lerror;
#endif
    
    argc = lua_gettop(tolua_S) - 1;
    
    if (argc == 5)
    {
        double arg0;
        double arg1;
        std::string arg2;
         std::string arg3;
         std::string arg4;
        
        
        double arg0_tmp;
        double arg1_tmp;
        std::string arg2_tmp;
        std::string arg3_tmp;
        std::string arg4_tmp;
        
        ok &= luaval_to_number(tolua_S, 2,&arg0_tmp, "Action_Bird_Move_Pause_Linear6:create");
        ok &= luaval_to_number(tolua_S, 3,&arg1_tmp, "Action_Bird_Move_Pause_Linear6:create");
        
        ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp, "Action_Bird_Move_Pause_Linear6:create");
        ok &= luaval_to_std_string(tolua_S, 5, &arg3_tmp, "Action_Bird_Move_Pause_Linear6:create");
        ok &= luaval_to_std_string(tolua_S, 6, &arg4_tmp, "Action_Bird_Move_Pause_Linear6:create");
        
        
        arg0 = arg0_tmp;
         arg1 = arg1_tmp;
         arg2 = arg2_tmp;
         arg3 = arg3_tmp;
        arg4 = arg4_tmp;
        
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_Action_Bird_Move_Pause_Linear6_create'", nullptr);
            return 0;
        }
        
                Action* ret = Dntg::Action_Bird_Move_Pause_Linear6::create(arg0, arg1,arg2,arg3,arg4);
                CCActionInterval* act = CCSequence::create(
                                                           CCDelayTime::create(0),
                                                           ret,
                                                           nullptr);
                CCAction* actSpeed = CCSpeed::create(act, 3.7);
        
                object_to_luaval<cocos2d::Action>(tolua_S, "cc.Action",(cocos2d::Action*)actSpeed);
        
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "Action_Bird_Move_Pause_Linear6:create",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_Action_Bird_Move_Pause_Linear6_create'.",&tolua_err);
#endif
    return 0;
}

int lua_register_cocos2dx_tool_Action_Bird_Move_Pause_Linear6(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"Action_Bird_Move_Pause_Linear6");
    tolua_cclass(tolua_S,"Action_Bird_Move_Pause_Linear6","Action_Bird_Move_Pause_Linear6","",nullptr);
    
    tolua_beginmodule(tolua_S,"Action_Bird_Move_Pause_Linear6");
    tolua_function(tolua_S,"create",lua_cocos2dx_tool_Action_Action_Bird_Move_Pause_Linear6_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(Dntg::Action_Bird_Move_Pause_Linear6).name();
    g_luaType[typeName] = "Action_Bird_Move_Pause_Linear6";
    g_typeCast["Action_Bird_Move_Pause_Linear6"] = "Action_Bird_Move_Pause_Linear6";
    return 1;
}



int lua_cocos2dx_tool_SpriteHelper_createBirdDeadAnimate(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"SpriteHelper",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "SpriteHelper:createBirdDeadAnimate");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_SpriteHelper_createBirdDeadAnimate'", nullptr);
            return 0;
        }
        cocos2d::Animate* ret = SpriteHelper::createBirdDeadAnimate(arg0);
        object_to_luaval<cocos2d::Animate>(tolua_S, "cc.Animate",(cocos2d::Animate*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "SpriteHelper:createBirdDeadAnimate",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_SpriteHelper_createBirdDeadAnimate'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tool_SpriteHelper_cacheAnimations(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"SpriteHelper",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "SpriteHelper:cacheAnimations");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_SpriteHelper_cacheAnimations'", nullptr);
            return 0;
        }
        bool ret = SpriteHelper::cacheAnimations(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "SpriteHelper:cacheAnimations",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_SpriteHelper_cacheAnimations'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tool_SpriteHelper_removeAnimations(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"SpriteHelper",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "SpriteHelper:removeAnimations");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_SpriteHelper_removeAnimations'", nullptr);
            return 0;
        }
        SpriteHelper::removeAnimations(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "SpriteHelper:removeAnimations",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_SpriteHelper_removeAnimations'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tool_SpriteHelper_cacheAnimation(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"SpriteHelper",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "SpriteHelper:cacheAnimation"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_SpriteHelper_cacheAnimation'", nullptr);
            return 0;
        }
        bool ret = SpriteHelper::cacheAnimation(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "SpriteHelper:cacheAnimation",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_SpriteHelper_cacheAnimation'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tool_SpriteHelper_createEffectAnimate(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"SpriteHelper",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        const char* arg0;
        double arg1;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "SpriteHelper:createEffectAnimate"); arg0 = arg0_tmp.c_str();
        ok &= luaval_to_number(tolua_S, 3,&arg1, "SpriteHelper:createEffectAnimate");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_SpriteHelper_createEffectAnimate'", nullptr);
            return 0;
        }
        cocos2d::Animate* ret = SpriteHelper::createEffectAnimate(arg0, arg1);
        object_to_luaval<cocos2d::Animate>(tolua_S, "cc.Animate",(cocos2d::Animate*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "SpriteHelper:createEffectAnimate",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_SpriteHelper_createEffectAnimate'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tool_SpriteHelper_createAnimate(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"SpriteHelper",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "SpriteHelper:createAnimate"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_SpriteHelper_createAnimate'", nullptr);
            return 0;
        }
        cocos2d::Animate* ret = SpriteHelper::createAnimate(arg0);
        object_to_luaval<cocos2d::Animate>(tolua_S, "cc.Animate",(cocos2d::Animate*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "SpriteHelper:createAnimate",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_SpriteHelper_createAnimate'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tool_SpriteHelper_removeAnimation(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"SpriteHelper",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "SpriteHelper:removeAnimation"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_SpriteHelper_removeAnimation'", nullptr);
            return 0;
        }
        SpriteHelper::removeAnimation(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "SpriteHelper:removeAnimation",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_SpriteHelper_removeAnimation'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tool_SpriteHelper_createJdbyBirdDeadAnimate(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"SpriteHelper",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "SpriteHelper:createJdbyBirdDeadAnimate");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_SpriteHelper_createJdbyBirdDeadAnimate'", nullptr);
            return 0;
        }
        cocos2d::Animate* ret = SpriteHelper::createJdbyBirdDeadAnimate(arg0);
        object_to_luaval<cocos2d::Animate>(tolua_S, "cc.Animate",(cocos2d::Animate*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "SpriteHelper:createJdbyBirdDeadAnimate",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_SpriteHelper_createJdbyBirdDeadAnimate'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tool_SpriteHelper_createBirdAnimate(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"SpriteHelper",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "SpriteHelper:createBirdAnimate");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_SpriteHelper_createBirdAnimate'", nullptr);
            return 0;
        }
        cocos2d::Animate* ret = SpriteHelper::createBirdAnimate(arg0);
        object_to_luaval<cocos2d::Animate>(tolua_S, "cc.Animate",(cocos2d::Animate*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "SpriteHelper:createBirdAnimate",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_SpriteHelper_createBirdAnimate'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_tool_SpriteHelper_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (SpriteHelper)");
    return 0;
}

int lua_register_cocos2dx_tool_SpriteHelper(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"SpriteHelper");
    tolua_cclass(tolua_S,"SpriteHelper","SpriteHelper","",nullptr);

    tolua_beginmodule(tolua_S,"SpriteHelper");
        tolua_function(tolua_S,"createBirdDeadAnimate", lua_cocos2dx_tool_SpriteHelper_createBirdDeadAnimate);
        tolua_function(tolua_S,"cacheAnimations", lua_cocos2dx_tool_SpriteHelper_cacheAnimations);
        tolua_function(tolua_S,"removeAnimations", lua_cocos2dx_tool_SpriteHelper_removeAnimations);
        tolua_function(tolua_S,"cacheAnimation", lua_cocos2dx_tool_SpriteHelper_cacheAnimation);
        tolua_function(tolua_S,"createEffectAnimate", lua_cocos2dx_tool_SpriteHelper_createEffectAnimate);
        tolua_function(tolua_S,"createAnimate", lua_cocos2dx_tool_SpriteHelper_createAnimate);
        tolua_function(tolua_S,"removeAnimation", lua_cocos2dx_tool_SpriteHelper_removeAnimation);
        tolua_function(tolua_S,"createJdbyBirdDeadAnimate", lua_cocos2dx_tool_SpriteHelper_createJdbyBirdDeadAnimate);
        tolua_function(tolua_S,"createBirdAnimate", lua_cocos2dx_tool_SpriteHelper_createBirdAnimate);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(SpriteHelper).name();
    g_luaType[typeName] = "SpriteHelper";
    g_typeCast["SpriteHelper"] = "SpriteHelper";
    return 1;
}

int lua_cocos2dx_tool_SoundManager_stopMusic(lua_State* tolua_S)
{
    int argc = 0;
    SoundManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SoundManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_SoundManager_stopMusic'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_SoundManager_stopMusic'", nullptr);
            return 0;
        }
        cobj->stopMusic();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SoundManager:stopMusic",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_SoundManager_stopMusic'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_SoundManager_preloadMusic(lua_State* tolua_S)
{
    int argc = 0;
    SoundManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SoundManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_SoundManager_preloadMusic'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "SoundManager:preloadMusic"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_SoundManager_preloadMusic'", nullptr);
            return 0;
        }
        cobj->preloadMusic(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SoundManager:preloadMusic",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_SoundManager_preloadMusic'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_SoundManager_stopAllSound(lua_State* tolua_S)
{
    int argc = 0;
    SoundManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SoundManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_SoundManager_stopAllSound'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_SoundManager_stopAllSound'", nullptr);
            return 0;
        }
        cobj->stopAllSound();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SoundManager:stopAllSound",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_SoundManager_stopAllSound'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_SoundManager_playFishSound(lua_State* tolua_S)
{
    int argc = 0;
    SoundManager* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundManager",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SoundManager*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_SoundManager_playFishSound'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            int arg0;
            ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "SoundManager:playFishSound");

            if (!ok) { break; }
            cobj->playFishSound(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 2) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "SoundManager:playFishSound"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            bool arg1;
            ok &= luaval_to_boolean(tolua_S, 3,&arg1, "SoundManager:playFishSound");

            if (!ok) { break; }
            cobj->playFishSound(arg0, arg1);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 3) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "SoundManager:playFishSound"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            bool arg1;
            ok &= luaval_to_boolean(tolua_S, 3,&arg1, "SoundManager:playFishSound");

            if (!ok) { break; }
            bool arg2;
            ok &= luaval_to_boolean(tolua_S, 4,&arg2, "SoundManager:playFishSound");

            if (!ok) { break; }
            cobj->playFishSound(arg0, arg1, arg2);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "SoundManager:playFishSound",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_SoundManager_playFishSound'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_SoundManager_getMusicVolume(lua_State* tolua_S)
{
    int argc = 0;
    SoundManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SoundManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_SoundManager_getMusicVolume'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_SoundManager_getMusicVolume'", nullptr);
            return 0;
        }
        double ret = cobj->getMusicVolume();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SoundManager:getMusicVolume",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_SoundManager_getMusicVolume'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_SoundManager_stopAllEffect(lua_State* tolua_S)
{
    int argc = 0;
    SoundManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SoundManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_SoundManager_stopAllEffect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_SoundManager_stopAllEffect'", nullptr);
            return 0;
        }
        cobj->stopAllEffect();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SoundManager:stopAllEffect",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_SoundManager_stopAllEffect'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_SoundManager_setMusicVolume(lua_State* tolua_S)
{
    int argc = 0;
    SoundManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SoundManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_SoundManager_setMusicVolume'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "SoundManager:setMusicVolume");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_SoundManager_setMusicVolume'", nullptr);
            return 0;
        }
        cobj->setMusicVolume(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SoundManager:setMusicVolume",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_SoundManager_setMusicVolume'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_SoundManager_saveSettings(lua_State* tolua_S)
{
    int argc = 0;
    SoundManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SoundManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_SoundManager_saveSettings'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_SoundManager_saveSettings'", nullptr);
            return 0;
        }
        cobj->saveSettings();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SoundManager:saveSettings",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_SoundManager_saveSettings'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_SoundManager_update(lua_State* tolua_S)
{
    int argc = 0;
    SoundManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SoundManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_SoundManager_update'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "SoundManager:update");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_SoundManager_update'", nullptr);
            return 0;
        }
        cobj->update(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SoundManager:update",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_SoundManager_update'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_SoundManager_getSoundVolume(lua_State* tolua_S)
{
    int argc = 0;
    SoundManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SoundManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_SoundManager_getSoundVolume'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_SoundManager_getSoundVolume'", nullptr);
            return 0;
        }
        double ret = cobj->getSoundVolume();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SoundManager:getSoundVolume",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_SoundManager_getSoundVolume'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_SoundManager_playMusic(lua_State* tolua_S)
{
    int argc = 0;
    SoundManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SoundManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_SoundManager_playMusic'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "SoundManager:playMusic"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_SoundManager_playMusic'", nullptr);
            return 0;
        }
        cobj->playMusic(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SoundManager:playMusic",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_SoundManager_playMusic'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_SoundManager_stopSound(lua_State* tolua_S)
{
    int argc = 0;
    SoundManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SoundManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_SoundManager_stopSound'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "SoundManager:stopSound"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_SoundManager_stopSound'", nullptr);
            return 0;
        }
        cobj->stopSound(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SoundManager:stopSound",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_SoundManager_stopSound'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_SoundManager_resumeAllEffects(lua_State* tolua_S)
{
    int argc = 0;
    SoundManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SoundManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_SoundManager_resumeAllEffects'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_SoundManager_resumeAllEffects'", nullptr);
            return 0;
        }
        cobj->resumeAllEffects();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SoundManager:resumeAllEffects",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_SoundManager_resumeAllEffects'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_SoundManager_playSound(lua_State* tolua_S)
{
    int argc = 0;
    SoundManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SoundManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_SoundManager_playSound'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "SoundManager:playSound"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_SoundManager_playSound'", nullptr);
            return 0;
        }
        cobj->playSound(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 2) 
    {
        const char* arg0;
        bool arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "SoundManager:playSound"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_boolean(tolua_S, 3,&arg1, "SoundManager:playSound");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_SoundManager_playSound'", nullptr);
            return 0;
        }
        cobj->playSound(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SoundManager:playSound",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_SoundManager_playSound'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_SoundManager_setSoundVolume(lua_State* tolua_S)
{
    int argc = 0;
    SoundManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SoundManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_SoundManager_setSoundVolume'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "SoundManager:setSoundVolume");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_SoundManager_setSoundVolume'", nullptr);
            return 0;
        }
        cobj->setSoundVolume(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SoundManager:setSoundVolume",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_SoundManager_setSoundVolume'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_SoundManager_purge(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"SoundManager",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_SoundManager_purge'", nullptr);
            return 0;
        }
        SoundManager::purge();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "SoundManager:purge",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_SoundManager_purge'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tool_SoundManager_shared(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"SoundManager",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_SoundManager_shared'", nullptr);
            return 0;
        }
        SoundManager* ret = SoundManager::shared();
        object_to_luaval<SoundManager>(tolua_S, "SoundManager",(SoundManager*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "SoundManager:shared",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_SoundManager_shared'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_tool_SoundManager_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (SoundManager)");
    return 0;
}

int lua_register_cocos2dx_tool_SoundManager(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"SoundManager");
    tolua_cclass(tolua_S,"SoundManager","SoundManager","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"SoundManager");
        tolua_function(tolua_S,"stopMusic",lua_cocos2dx_tool_SoundManager_stopMusic);
        tolua_function(tolua_S,"preloadMusic",lua_cocos2dx_tool_SoundManager_preloadMusic);
        tolua_function(tolua_S,"stopAllSound",lua_cocos2dx_tool_SoundManager_stopAllSound);
        tolua_function(tolua_S,"playFishSound",lua_cocos2dx_tool_SoundManager_playFishSound);
        tolua_function(tolua_S,"getMusicVolume",lua_cocos2dx_tool_SoundManager_getMusicVolume);
        tolua_function(tolua_S,"stopAllEffect",lua_cocos2dx_tool_SoundManager_stopAllEffect);
        tolua_function(tolua_S,"setMusicVolume",lua_cocos2dx_tool_SoundManager_setMusicVolume);
        tolua_function(tolua_S,"saveSettings",lua_cocos2dx_tool_SoundManager_saveSettings);
        tolua_function(tolua_S,"update",lua_cocos2dx_tool_SoundManager_update);
        tolua_function(tolua_S,"getSoundVolume",lua_cocos2dx_tool_SoundManager_getSoundVolume);
        tolua_function(tolua_S,"playMusic",lua_cocos2dx_tool_SoundManager_playMusic);
        tolua_function(tolua_S,"stopSound",lua_cocos2dx_tool_SoundManager_stopSound);
        tolua_function(tolua_S,"resumeAllEffects",lua_cocos2dx_tool_SoundManager_resumeAllEffects);
        tolua_function(tolua_S,"playSound",lua_cocos2dx_tool_SoundManager_playSound);
        tolua_function(tolua_S,"setSoundVolume",lua_cocos2dx_tool_SoundManager_setSoundVolume);
        tolua_function(tolua_S,"purge", lua_cocos2dx_tool_SoundManager_purge);
        tolua_function(tolua_S,"shared", lua_cocos2dx_tool_SoundManager_shared);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(SoundManager).name();
    g_luaType[typeName] = "SoundManager";
    g_typeCast["SoundManager"] = "SoundManager";
    return 1;
}

int lua_cocos2dx_tool_CNickReadInfo_RandNick(lua_State* tolua_S)
{
    int argc = 0;
    CNickReadInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CNickReadInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CNickReadInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_CNickReadInfo_RandNick'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_CNickReadInfo_RandNick'", nullptr);
            return 0;
        }
        std::string ret = cobj->RandNick();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CNickReadInfo:RandNick",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_CNickReadInfo_RandNick'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_CNickReadInfo_Release(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CNickReadInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_CNickReadInfo_Release'", nullptr);
            return 0;
        }
        CNickReadInfo::Release();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CNickReadInfo:Release",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_CNickReadInfo_Release'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tool_CNickReadInfo_shared(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CNickReadInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_CNickReadInfo_shared'", nullptr);
            return 0;
        }
        CNickReadInfo* ret = CNickReadInfo::shared();
        object_to_luaval<CNickReadInfo>(tolua_S, "CNickReadInfo",(CNickReadInfo*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CNickReadInfo:shared",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_CNickReadInfo_shared'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_tool_CNickReadInfo_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CNickReadInfo)");
    return 0;
}

int lua_register_cocos2dx_tool_CNickReadInfo(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CNickReadInfo");
    tolua_cclass(tolua_S,"CNickReadInfo","CNickReadInfo","",nullptr);

    tolua_beginmodule(tolua_S,"CNickReadInfo");
        tolua_function(tolua_S,"RandNick",lua_cocos2dx_tool_CNickReadInfo_RandNick);
        tolua_function(tolua_S,"Release", lua_cocos2dx_tool_CNickReadInfo_Release);
        tolua_function(tolua_S,"shared", lua_cocos2dx_tool_CNickReadInfo_shared);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CNickReadInfo).name();
    g_luaType[typeName] = "CNickReadInfo";
    g_typeCast["CNickReadInfo"] = "CNickReadInfo";
    return 1;
}

int lua_cocos2dx_tool_CHarmonyString_CheckString(lua_State* tolua_S)
{
    int argc = 0;
    CHarmonyString* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CHarmonyString",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CHarmonyString*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_CHarmonyString_CheckString'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "CHarmonyString:CheckString");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_CHarmonyString_CheckString'", nullptr);
            return 0;
        }
        bool ret = cobj->CheckString(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CHarmonyString:CheckString",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_CHarmonyString_CheckString'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_CHarmonyString_Release(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CHarmonyString",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_CHarmonyString_Release'", nullptr);
            return 0;
        }
        CHarmonyString::Release();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CHarmonyString:Release",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_CHarmonyString_Release'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tool_CHarmonyString_shared(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CHarmonyString",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_CHarmonyString_shared'", nullptr);
            return 0;
        }
        CHarmonyString* ret = CHarmonyString::shared();
        object_to_luaval<CHarmonyString>(tolua_S, "CHarmonyString",(CHarmonyString*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CHarmonyString:shared",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_CHarmonyString_shared'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_tool_CHarmonyString_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CHarmonyString)");
    return 0;
}

int lua_register_cocos2dx_tool_CHarmonyString(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CHarmonyString");
    tolua_cclass(tolua_S,"CHarmonyString","CHarmonyString","",nullptr);

    tolua_beginmodule(tolua_S,"CHarmonyString");
        tolua_function(tolua_S,"CheckString",lua_cocos2dx_tool_CHarmonyString_CheckString);
        tolua_function(tolua_S,"Release", lua_cocos2dx_tool_CHarmonyString_Release);
        tolua_function(tolua_S,"shared", lua_cocos2dx_tool_CHarmonyString_shared);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CHarmonyString).name();
    g_luaType[typeName] = "CHarmonyString";
    g_typeCast["CHarmonyString"] = "CHarmonyString";
    return 1;
}

int lua_cocos2dx_tool_DSFileUpdate_CheckVersion(lua_State* tolua_S)
{
    int argc = 0;
    DSFileUpdate* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"DSFileUpdate",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (DSFileUpdate*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_DSFileUpdate_CheckVersion'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_DSFileUpdate_CheckVersion'", nullptr);
            return 0;
        }
        bool ret = cobj->CheckVersion();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "DSFileUpdate:CheckVersion",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_DSFileUpdate_CheckVersion'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_DSFileUpdate_registerFileUpdateCallBack(lua_State* tolua_S)
{
    int argc = 0;
    DSFileUpdate* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"DSFileUpdate",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (DSFileUpdate*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_DSFileUpdate_registerFileUpdateCallBack'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "DSFileUpdate:registerFileUpdateCallBack");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_DSFileUpdate_registerFileUpdateCallBack'", nullptr);
            return 0;
        }
        cobj->registerFileUpdateCallBack(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "DSFileUpdate:registerFileUpdateCallBack",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_DSFileUpdate_registerFileUpdateCallBack'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_DSFileUpdate_SetSearchFilePath(lua_State* tolua_S)
{
    int argc = 0;
    DSFileUpdate* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"DSFileUpdate",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (DSFileUpdate*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_DSFileUpdate_SetSearchFilePath'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_DSFileUpdate_SetSearchFilePath'", nullptr);
            return 0;
        }
        cobj->SetSearchFilePath();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "DSFileUpdate:SetSearchFilePath",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_DSFileUpdate_SetSearchFilePath'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_DSFileUpdate_setSaveKey(lua_State* tolua_S)
{
    int argc = 0;
    DSFileUpdate* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"DSFileUpdate",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (DSFileUpdate*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_DSFileUpdate_setSaveKey'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "DSFileUpdate:setSaveKey");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_DSFileUpdate_setSaveKey'", nullptr);
            return 0;
        }
        cobj->setSaveKey(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "DSFileUpdate:setSaveKey",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_DSFileUpdate_setSaveKey'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_DSFileUpdate_createDownloadedDir(lua_State* tolua_S)
{
    int argc = 0;
    DSFileUpdate* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"DSFileUpdate",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (DSFileUpdate*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_DSFileUpdate_createDownloadedDir'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "DSFileUpdate:createDownloadedDir"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_DSFileUpdate_createDownloadedDir'", nullptr);
            return 0;
        }
        cobj->createDownloadedDir(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "DSFileUpdate:createDownloadedDir",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_DSFileUpdate_createDownloadedDir'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_DSFileUpdate_DeleteOldResourceDirAndCreateDir(lua_State* tolua_S)
{
    int argc = 0;
    DSFileUpdate* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"DSFileUpdate",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (DSFileUpdate*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_DSFileUpdate_DeleteOldResourceDirAndCreateDir'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_DSFileUpdate_DeleteOldResourceDirAndCreateDir'", nullptr);
            return 0;
        }
        cobj->DeleteOldResourceDirAndCreateDir();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "DSFileUpdate:DeleteOldResourceDirAndCreateDir",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_DSFileUpdate_DeleteOldResourceDirAndCreateDir'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_DSFileUpdate_setDownFileUrl(lua_State* tolua_S)
{
    int argc = 0;
    DSFileUpdate* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"DSFileUpdate",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (DSFileUpdate*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_DSFileUpdate_setDownFileUrl'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "DSFileUpdate:setDownFileUrl");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_DSFileUpdate_setDownFileUrl'", nullptr);
            return 0;
        }
        cobj->setDownFileUrl(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "DSFileUpdate:setDownFileUrl",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_DSFileUpdate_setDownFileUrl'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_DSFileUpdate_setVersionList(lua_State* tolua_S)
{
    int argc = 0;
    DSFileUpdate* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"DSFileUpdate",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (DSFileUpdate*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_DSFileUpdate_setVersionList'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "DSFileUpdate:setVersionList");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_DSFileUpdate_setVersionList'", nullptr);
            return 0;
        }
        cobj->setVersionList(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "DSFileUpdate:setVersionList",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_DSFileUpdate_setVersionList'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_DSFileUpdate_UpdateVersion(lua_State* tolua_S)
{
    int argc = 0;
    DSFileUpdate* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"DSFileUpdate",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (DSFileUpdate*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_DSFileUpdate_UpdateVersion'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_DSFileUpdate_UpdateVersion'", nullptr);
            return 0;
        }
        cobj->UpdateVersion();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "DSFileUpdate:UpdateVersion",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_DSFileUpdate_UpdateVersion'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_DSFileUpdate_runFileUpdate(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"DSFileUpdate",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        DSFileUpdate* arg0;
        ok &= luaval_to_object<DSFileUpdate>(tolua_S, 2, "DSFileUpdate",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_DSFileUpdate_runFileUpdate'", nullptr);
            return 0;
        }
        DSFileUpdate::runFileUpdate(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "DSFileUpdate:runFileUpdate",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_DSFileUpdate_runFileUpdate'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tool_DSFileUpdate_runVersionCheck(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"DSFileUpdate",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        DSFileUpdate* arg0;
        ok &= luaval_to_object<DSFileUpdate>(tolua_S, 2, "DSFileUpdate",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_DSFileUpdate_runVersionCheck'", nullptr);
            return 0;
        }
        DSFileUpdate::runVersionCheck(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "DSFileUpdate:runVersionCheck",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_DSFileUpdate_runVersionCheck'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tool_DSFileUpdate_CheStringToInt(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"DSFileUpdate",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "DSFileUpdate:CheStringToInt"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_DSFileUpdate_CheStringToInt'", nullptr);
            return 0;
        }
        unsigned int ret = DSFileUpdate::CheStringToInt(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "DSFileUpdate:CheStringToInt",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_DSFileUpdate_CheStringToInt'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_tool_DSFileUpdate_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (DSFileUpdate)");
    return 0;
}

int lua_register_cocos2dx_tool_DSFileUpdate(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"DSFileUpdate");
    tolua_cclass(tolua_S,"DSFileUpdate","DSFileUpdate","cc.AssetsManager",nullptr);

    tolua_beginmodule(tolua_S,"DSFileUpdate");
        tolua_function(tolua_S,"CheckVersion",lua_cocos2dx_tool_DSFileUpdate_CheckVersion);
        tolua_function(tolua_S,"registerFileUpdateCallBack",lua_cocos2dx_tool_DSFileUpdate_registerFileUpdateCallBack);
        tolua_function(tolua_S,"SetSearchFilePath",lua_cocos2dx_tool_DSFileUpdate_SetSearchFilePath);
        tolua_function(tolua_S,"setSaveKey",lua_cocos2dx_tool_DSFileUpdate_setSaveKey);
        tolua_function(tolua_S,"createDownloadedDir",lua_cocos2dx_tool_DSFileUpdate_createDownloadedDir);
        tolua_function(tolua_S,"DeleteOldResourceDirAndCreateDir",lua_cocos2dx_tool_DSFileUpdate_DeleteOldResourceDirAndCreateDir);
        tolua_function(tolua_S,"setDownFileUrl",lua_cocos2dx_tool_DSFileUpdate_setDownFileUrl);
        tolua_function(tolua_S,"setVersionList",lua_cocos2dx_tool_DSFileUpdate_setVersionList);
        tolua_function(tolua_S,"UpdateVersion",lua_cocos2dx_tool_DSFileUpdate_UpdateVersion);
        tolua_function(tolua_S,"runFileUpdate", lua_cocos2dx_tool_DSFileUpdate_runFileUpdate);
        tolua_function(tolua_S,"runVersionCheck", lua_cocos2dx_tool_DSFileUpdate_runVersionCheck);
        tolua_function(tolua_S,"CheStringToInt", lua_cocos2dx_tool_DSFileUpdate_CheStringToInt);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(DSFileUpdate).name();
    g_luaType[typeName] = "DSFileUpdate";
    g_typeCast["DSFileUpdate"] = "DSFileUpdate";
    return 1;
}

int lua_cocos2dx_tool_GameVersionUpdate_CheckVersion(lua_State* tolua_S)
{
    int argc = 0;
    GameVersionUpdate* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameVersionUpdate",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GameVersionUpdate*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_GameVersionUpdate_CheckVersion'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_GameVersionUpdate_CheckVersion'", nullptr);
            return 0;
        }
        bool ret = cobj->CheckVersion();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GameVersionUpdate:CheckVersion",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_GameVersionUpdate_CheckVersion'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_GameVersionUpdate_UpdateVersion(lua_State* tolua_S)
{
    int argc = 0;
    GameVersionUpdate* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameVersionUpdate",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GameVersionUpdate*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_GameVersionUpdate_UpdateVersion'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_GameVersionUpdate_UpdateVersion'", nullptr);
            return 0;
        }
        cobj->UpdateVersion();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GameVersionUpdate:UpdateVersion",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_GameVersionUpdate_UpdateVersion'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_GameVersionUpdate_destroyInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"GameVersionUpdate",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_GameVersionUpdate_destroyInstance'", nullptr);
            return 0;
        }
        GameVersionUpdate::destroyInstance();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "GameVersionUpdate:destroyInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_GameVersionUpdate_destroyInstance'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tool_GameVersionUpdate_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"GameVersionUpdate",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_GameVersionUpdate_getInstance'", nullptr);
            return 0;
        }
        GameVersionUpdate* ret = GameVersionUpdate::getInstance();
        object_to_luaval<GameVersionUpdate>(tolua_S, "GameVersionUpdate",(GameVersionUpdate*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "GameVersionUpdate:getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_GameVersionUpdate_getInstance'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_tool_GameVersionUpdate_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (GameVersionUpdate)");
    return 0;
}

int lua_register_cocos2dx_tool_GameVersionUpdate(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"GameVersionUpdate");
    tolua_cclass(tolua_S,"GameVersionUpdate","GameVersionUpdate","DSFileUpdate",nullptr);

    tolua_beginmodule(tolua_S,"GameVersionUpdate");
        tolua_function(tolua_S,"CheckVersion",lua_cocos2dx_tool_GameVersionUpdate_CheckVersion);
        tolua_function(tolua_S,"UpdateVersion",lua_cocos2dx_tool_GameVersionUpdate_UpdateVersion);
        tolua_function(tolua_S,"destroyInstance", lua_cocos2dx_tool_GameVersionUpdate_destroyInstance);
        tolua_function(tolua_S,"getInstance", lua_cocos2dx_tool_GameVersionUpdate_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(GameVersionUpdate).name();
    g_luaType[typeName] = "GameVersionUpdate";
    g_typeCast["GameVersionUpdate"] = "GameVersionUpdate";
    return 1;
}

int lua_cocos2dx_tool_PlatformVersionUpdate_CheckVersion(lua_State* tolua_S)
{
    int argc = 0;
    PlatformVersionUpdate* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"PlatformVersionUpdate",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (PlatformVersionUpdate*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_PlatformVersionUpdate_CheckVersion'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_PlatformVersionUpdate_CheckVersion'", nullptr);
            return 0;
        }
        bool ret = cobj->CheckVersion();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "PlatformVersionUpdate:CheckVersion",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_PlatformVersionUpdate_CheckVersion'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_PlatformVersionUpdate_SetSearchFilePath(lua_State* tolua_S)
{
    int argc = 0;
    PlatformVersionUpdate* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"PlatformVersionUpdate",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (PlatformVersionUpdate*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_PlatformVersionUpdate_SetSearchFilePath'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_PlatformVersionUpdate_SetSearchFilePath'", nullptr);
            return 0;
        }
        cobj->SetSearchFilePath();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "PlatformVersionUpdate:SetSearchFilePath",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_PlatformVersionUpdate_SetSearchFilePath'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_PlatformVersionUpdate_UpdateVersion(lua_State* tolua_S)
{
    int argc = 0;
    PlatformVersionUpdate* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"PlatformVersionUpdate",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (PlatformVersionUpdate*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_PlatformVersionUpdate_UpdateVersion'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_PlatformVersionUpdate_UpdateVersion'", nullptr);
            return 0;
        }
        cobj->UpdateVersion();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "PlatformVersionUpdate:UpdateVersion",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_PlatformVersionUpdate_UpdateVersion'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_PlatformVersionUpdate_destroyInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"PlatformVersionUpdate",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_PlatformVersionUpdate_destroyInstance'", nullptr);
            return 0;
        }
        PlatformVersionUpdate::destroyInstance();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "PlatformVersionUpdate:destroyInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_PlatformVersionUpdate_destroyInstance'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tool_PlatformVersionUpdate_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"PlatformVersionUpdate",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_PlatformVersionUpdate_getInstance'", nullptr);
            return 0;
        }
        PlatformVersionUpdate* ret = PlatformVersionUpdate::getInstance();
        object_to_luaval<PlatformVersionUpdate>(tolua_S, "PlatformVersionUpdate",(PlatformVersionUpdate*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "PlatformVersionUpdate:getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_PlatformVersionUpdate_getInstance'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_tool_PlatformVersionUpdate_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (PlatformVersionUpdate)");
    return 0;
}

int lua_register_cocos2dx_tool_PlatformVersionUpdate(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"PlatformVersionUpdate");
    tolua_cclass(tolua_S,"PlatformVersionUpdate","PlatformVersionUpdate","DSFileUpdate",nullptr);

    tolua_beginmodule(tolua_S,"PlatformVersionUpdate");
        tolua_function(tolua_S,"CheckVersion",lua_cocos2dx_tool_PlatformVersionUpdate_CheckVersion);
        tolua_function(tolua_S,"SetSearchFilePath",lua_cocos2dx_tool_PlatformVersionUpdate_SetSearchFilePath);
        tolua_function(tolua_S,"UpdateVersion",lua_cocos2dx_tool_PlatformVersionUpdate_UpdateVersion);
        tolua_function(tolua_S,"destroyInstance", lua_cocos2dx_tool_PlatformVersionUpdate_destroyInstance);
        tolua_function(tolua_S,"getInstance", lua_cocos2dx_tool_PlatformVersionUpdate_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(PlatformVersionUpdate).name();
    g_luaType[typeName] = "PlatformVersionUpdate";
    g_typeCast["PlatformVersionUpdate"] = "PlatformVersionUpdate";
    return 1;
}

int lua_cocos2dx_tool_CoTimer_init(lua_State* tolua_S)
{
    int argc = 0;
    CoTimer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CoTimer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CoTimer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_CoTimer_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "CoTimer:init");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_CoTimer_init'", nullptr);
            return 0;
        }
        cobj->init(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CoTimer:init",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_CoTimer_init'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_CoTimer_isTimeUp(lua_State* tolua_S)
{
    int argc = 0;
    CoTimer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CoTimer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CoTimer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_CoTimer_isTimeUp'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_CoTimer_isTimeUp'", nullptr);
            return 0;
        }
        bool ret = cobj->isTimeUp();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CoTimer:isTimeUp",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_CoTimer_isTimeUp'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_CoTimer_getElapsed(lua_State* tolua_S)
{
    int argc = 0;
    CoTimer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CoTimer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CoTimer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_CoTimer_getElapsed'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_CoTimer_getElapsed'", nullptr);
            return 0;
        }
        unsigned long ret = cobj->getElapsed();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CoTimer:getElapsed",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_CoTimer_getElapsed'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_CoTimer_getGameWorldTimeStr(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CoTimer",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_CoTimer_getGameWorldTimeStr'", nullptr);
            return 0;
        }
        const std::string ret = CoTimer::getGameWorldTimeStr();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CoTimer:getGameWorldTimeStr",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_CoTimer_getGameWorldTimeStr'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tool_CoTimer_getLocalDateStr(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CoTimer",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_CoTimer_getLocalDateStr'", nullptr);
            return 0;
        }
        const std::string ret = CoTimer::getLocalDateStr();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CoTimer:getLocalDateStr",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_CoTimer_getLocalDateStr'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tool_CoTimer_getLocalTimeStr(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CoTimer",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_CoTimer_getLocalTimeStr'", nullptr);
            return 0;
        }
        const std::string ret = CoTimer::getLocalTimeStr();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CoTimer:getLocalTimeStr",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_CoTimer_getLocalTimeStr'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tool_CoTimer_getCurrentTime(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CoTimer",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_CoTimer_getCurrentTime'", nullptr);
            return 0;
        }
        unsigned int ret = CoTimer::getCurrentTime();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CoTimer:getCurrentTime",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_CoTimer_getCurrentTime'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tool_CoTimer_getsystemtomillisecond(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CoTimer",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_CoTimer_getsystemtomillisecond'", nullptr);
            return 0;
        }
        long long ret = CoTimer::getsystemtomillisecond();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CoTimer:getsystemtomillisecond",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_CoTimer_getsystemtomillisecond'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tool_CoTimer_getTimeStr(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CoTimer",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        long long arg0;
        ok &= luaval_to_long_long(tolua_S, 2,&arg0, "CoTimer:getTimeStr");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_CoTimer_getTimeStr'", nullptr);
            return 0;
        }
        const std::string ret = CoTimer::getTimeStr(arg0);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CoTimer:getTimeStr",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_CoTimer_getTimeStr'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tool_CoTimer_getGameWorldTime(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CoTimer",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_CoTimer_getGameWorldTime'", nullptr);
            return 0;
        }
        long long ret = CoTimer::getGameWorldTime();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CoTimer:getGameWorldTime",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_CoTimer_getGameWorldTime'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tool_CoTimer_getDataStr(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CoTimer",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        long long arg0;
        ok &= luaval_to_long_long(tolua_S, 2,&arg0, "CoTimer:getDataStr");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_CoTimer_getDataStr'", nullptr);
            return 0;
        }
        const std::string ret = CoTimer::getDataStr(arg0);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CoTimer:getDataStr",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_CoTimer_getDataStr'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tool_CoTimer_setGameWorldTime(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CoTimer",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        long long arg0;
        ok &= luaval_to_long_long(tolua_S, 2,&arg0, "CoTimer:setGameWorldTime");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_CoTimer_setGameWorldTime'", nullptr);
            return 0;
        }
        CoTimer::setGameWorldTime(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CoTimer:setGameWorldTime",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_CoTimer_setGameWorldTime'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tool_CoTimer_constructor(lua_State* tolua_S)
{
    int argc = 0;
    CoTimer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_CoTimer_constructor'", nullptr);
            return 0;
        }
        cobj = new CoTimer();
        tolua_pushusertype(tolua_S,(void*)cobj,"CoTimer");
        tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        return 1;
    }
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "CoTimer:CoTimer");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_CoTimer_constructor'", nullptr);
            return 0;
        }
        cobj = new CoTimer(arg0);
        tolua_pushusertype(tolua_S,(void*)cobj,"CoTimer");
        tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CoTimer:CoTimer",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_CoTimer_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_tool_CoTimer_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CoTimer)");
    return 0;
}

int lua_register_cocos2dx_tool_CoTimer(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CoTimer");
    tolua_cclass(tolua_S,"CoTimer","CoTimer","",nullptr);

    tolua_beginmodule(tolua_S,"CoTimer");
        tolua_function(tolua_S,"new",lua_cocos2dx_tool_CoTimer_constructor);
        tolua_function(tolua_S,"init",lua_cocos2dx_tool_CoTimer_init);
        tolua_function(tolua_S,"isTimeUp",lua_cocos2dx_tool_CoTimer_isTimeUp);
        tolua_function(tolua_S,"getElapsed",lua_cocos2dx_tool_CoTimer_getElapsed);
        tolua_function(tolua_S,"getGameWorldTimeStr", lua_cocos2dx_tool_CoTimer_getGameWorldTimeStr);
        tolua_function(tolua_S,"getLocalDateStr", lua_cocos2dx_tool_CoTimer_getLocalDateStr);
        tolua_function(tolua_S,"getLocalTimeStr", lua_cocos2dx_tool_CoTimer_getLocalTimeStr);
        tolua_function(tolua_S,"getCurrentTime", lua_cocos2dx_tool_CoTimer_getCurrentTime);
        tolua_function(tolua_S,"getsystemtomillisecond", lua_cocos2dx_tool_CoTimer_getsystemtomillisecond);
        tolua_function(tolua_S,"getTimeStr", lua_cocos2dx_tool_CoTimer_getTimeStr);
        tolua_function(tolua_S,"getGameWorldTime", lua_cocos2dx_tool_CoTimer_getGameWorldTime);
        tolua_function(tolua_S,"getDataStr", lua_cocos2dx_tool_CoTimer_getDataStr);
        tolua_function(tolua_S,"setGameWorldTime", lua_cocos2dx_tool_CoTimer_setGameWorldTime);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CoTimer).name();
    g_luaType[typeName] = "CoTimer";
    g_typeCast["CoTimer"] = "CoTimer";
    return 1;
}

int lua_cocos2dx_tool_MyUserDefault_setIntegerForKey(lua_State* tolua_S)
{
    int argc = 0;
    MyUserDefault* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MyUserDefault",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MyUserDefault*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_MyUserDefault_setIntegerForKey'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        const char* arg0;
        const char* arg1;
        int arg2;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "MyUserDefault:setIntegerForKey"); arg0 = arg0_tmp.c_str();

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "MyUserDefault:setIntegerForKey"); arg1 = arg1_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "MyUserDefault:setIntegerForKey");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_MyUserDefault_setIntegerForKey'", nullptr);
            return 0;
        }
        cobj->setIntegerForKey(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MyUserDefault:setIntegerForKey",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_MyUserDefault_setIntegerForKey'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_MyUserDefault_getFloatForKey(lua_State* tolua_S)
{
    int argc = 0;
    MyUserDefault* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MyUserDefault",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (MyUserDefault*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_MyUserDefault_getFloatForKey'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 3) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "MyUserDefault:getFloatForKey"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            const char* arg1;
            std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "MyUserDefault:getFloatForKey"); arg1 = arg1_tmp.c_str();

            if (!ok) { break; }
            double arg2;
            ok &= luaval_to_number(tolua_S, 4,&arg2, "MyUserDefault:getFloatForKey");

            if (!ok) { break; }
            double ret = cobj->getFloatForKey(arg0, arg1, arg2);
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 2) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "MyUserDefault:getFloatForKey"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            const char* arg1;
            std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "MyUserDefault:getFloatForKey"); arg1 = arg1_tmp.c_str();

            if (!ok) { break; }
            double ret = cobj->getFloatForKey(arg0, arg1);
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "MyUserDefault:getFloatForKey",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_MyUserDefault_getFloatForKey'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_MyUserDefault_getBoolForKey(lua_State* tolua_S)
{
    int argc = 0;
    MyUserDefault* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MyUserDefault",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (MyUserDefault*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_MyUserDefault_getBoolForKey'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 3) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "MyUserDefault:getBoolForKey"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            const char* arg1;
            std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "MyUserDefault:getBoolForKey"); arg1 = arg1_tmp.c_str();

            if (!ok) { break; }
            bool arg2;
            ok &= luaval_to_boolean(tolua_S, 4,&arg2, "MyUserDefault:getBoolForKey");

            if (!ok) { break; }
            bool ret = cobj->getBoolForKey(arg0, arg1, arg2);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 2) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "MyUserDefault:getBoolForKey"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            const char* arg1;
            std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "MyUserDefault:getBoolForKey"); arg1 = arg1_tmp.c_str();

            if (!ok) { break; }
            bool ret = cobj->getBoolForKey(arg0, arg1);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "MyUserDefault:getBoolForKey",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_MyUserDefault_getBoolForKey'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_MyUserDefault_setDoubleForKey(lua_State* tolua_S)
{
    int argc = 0;
    MyUserDefault* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MyUserDefault",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MyUserDefault*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_MyUserDefault_setDoubleForKey'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        const char* arg0;
        const char* arg1;
        double arg2;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "MyUserDefault:setDoubleForKey"); arg0 = arg0_tmp.c_str();

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "MyUserDefault:setDoubleForKey"); arg1 = arg1_tmp.c_str();

        ok &= luaval_to_number(tolua_S, 4,&arg2, "MyUserDefault:setDoubleForKey");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_MyUserDefault_setDoubleForKey'", nullptr);
            return 0;
        }
        cobj->setDoubleForKey(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MyUserDefault:setDoubleForKey",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_MyUserDefault_setDoubleForKey'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_MyUserDefault_setFloatForKey(lua_State* tolua_S)
{
    int argc = 0;
    MyUserDefault* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MyUserDefault",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MyUserDefault*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_MyUserDefault_setFloatForKey'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        const char* arg0;
        const char* arg1;
        double arg2;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "MyUserDefault:setFloatForKey"); arg0 = arg0_tmp.c_str();

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "MyUserDefault:setFloatForKey"); arg1 = arg1_tmp.c_str();

        ok &= luaval_to_number(tolua_S, 4,&arg2, "MyUserDefault:setFloatForKey");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_MyUserDefault_setFloatForKey'", nullptr);
            return 0;
        }
        cobj->setFloatForKey(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MyUserDefault:setFloatForKey",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_MyUserDefault_setFloatForKey'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_MyUserDefault_getStringForKey(lua_State* tolua_S)
{
    int argc = 0;
    MyUserDefault* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MyUserDefault",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (MyUserDefault*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_MyUserDefault_getStringForKey'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 3) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "MyUserDefault:getStringForKey"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            const char* arg1;
            std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "MyUserDefault:getStringForKey"); arg1 = arg1_tmp.c_str();

            if (!ok) { break; }
            std::string arg2;
            ok &= luaval_to_std_string(tolua_S, 4,&arg2, "MyUserDefault:getStringForKey");

            if (!ok) { break; }
            std::string ret = cobj->getStringForKey(arg0, arg1, arg2);
            tolua_pushcppstring(tolua_S,ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 2) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "MyUserDefault:getStringForKey"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            const char* arg1;
            std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "MyUserDefault:getStringForKey"); arg1 = arg1_tmp.c_str();

            if (!ok) { break; }
            std::string ret = cobj->getStringForKey(arg0, arg1);
            tolua_pushcppstring(tolua_S,ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "MyUserDefault:getStringForKey",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_MyUserDefault_getStringForKey'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_MyUserDefault_setStringForKey(lua_State* tolua_S)
{
    int argc = 0;
    MyUserDefault* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MyUserDefault",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MyUserDefault*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_MyUserDefault_setStringForKey'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        const char* arg0;
        const char* arg1;
        std::string arg2;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "MyUserDefault:setStringForKey"); arg0 = arg0_tmp.c_str();

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "MyUserDefault:setStringForKey"); arg1 = arg1_tmp.c_str();

        ok &= luaval_to_std_string(tolua_S, 4,&arg2, "MyUserDefault:setStringForKey");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_MyUserDefault_setStringForKey'", nullptr);
            return 0;
        }
        cobj->setStringForKey(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MyUserDefault:setStringForKey",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_MyUserDefault_setStringForKey'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_MyUserDefault_setValueForKey(lua_State* tolua_S)
{
    int argc = 0;
    MyUserDefault* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MyUserDefault",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MyUserDefault*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_MyUserDefault_setValueForKey'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        const char* arg0;
        const char* arg1;
        const char* arg2;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "MyUserDefault:setValueForKey"); arg0 = arg0_tmp.c_str();

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "MyUserDefault:setValueForKey"); arg1 = arg1_tmp.c_str();

        std::string arg2_tmp; ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp, "MyUserDefault:setValueForKey"); arg2 = arg2_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_MyUserDefault_setValueForKey'", nullptr);
            return 0;
        }
        cobj->setValueForKey(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MyUserDefault:setValueForKey",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_MyUserDefault_setValueForKey'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_MyUserDefault_getIntegerForKey(lua_State* tolua_S)
{
    int argc = 0;
    MyUserDefault* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MyUserDefault",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (MyUserDefault*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_MyUserDefault_getIntegerForKey'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 3) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "MyUserDefault:getIntegerForKey"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            const char* arg1;
            std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "MyUserDefault:getIntegerForKey"); arg1 = arg1_tmp.c_str();

            if (!ok) { break; }
            int arg2;
            ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "MyUserDefault:getIntegerForKey");

            if (!ok) { break; }
            int ret = cobj->getIntegerForKey(arg0, arg1, arg2);
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 2) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "MyUserDefault:getIntegerForKey"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            const char* arg1;
            std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "MyUserDefault:getIntegerForKey"); arg1 = arg1_tmp.c_str();

            if (!ok) { break; }
            int ret = cobj->getIntegerForKey(arg0, arg1);
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "MyUserDefault:getIntegerForKey",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_MyUserDefault_getIntegerForKey'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_MyUserDefault_getDoubleForKey(lua_State* tolua_S)
{
    int argc = 0;
    MyUserDefault* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MyUserDefault",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (MyUserDefault*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_MyUserDefault_getDoubleForKey'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 3) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "MyUserDefault:getDoubleForKey"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            const char* arg1;
            std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "MyUserDefault:getDoubleForKey"); arg1 = arg1_tmp.c_str();

            if (!ok) { break; }
            double arg2;
            ok &= luaval_to_number(tolua_S, 4,&arg2, "MyUserDefault:getDoubleForKey");

            if (!ok) { break; }
            double ret = cobj->getDoubleForKey(arg0, arg1, arg2);
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 2) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "MyUserDefault:getDoubleForKey"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            const char* arg1;
            std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "MyUserDefault:getDoubleForKey"); arg1 = arg1_tmp.c_str();

            if (!ok) { break; }
            double ret = cobj->getDoubleForKey(arg0, arg1);
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "MyUserDefault:getDoubleForKey",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_MyUserDefault_getDoubleForKey'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_MyUserDefault_setBoolForKey(lua_State* tolua_S)
{
    int argc = 0;
    MyUserDefault* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MyUserDefault",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MyUserDefault*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_MyUserDefault_setBoolForKey'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        const char* arg0;
        const char* arg1;
        bool arg2;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "MyUserDefault:setBoolForKey"); arg0 = arg0_tmp.c_str();

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "MyUserDefault:setBoolForKey"); arg1 = arg1_tmp.c_str();

        ok &= luaval_to_boolean(tolua_S, 4,&arg2, "MyUserDefault:setBoolForKey");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_MyUserDefault_setBoolForKey'", nullptr);
            return 0;
        }
        cobj->setBoolForKey(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MyUserDefault:setBoolForKey",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_MyUserDefault_setBoolForKey'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_MyUserDefault_destroyInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"MyUserDefault",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_MyUserDefault_destroyInstance'", nullptr);
            return 0;
        }
        MyUserDefault::destroyInstance();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "MyUserDefault:destroyInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_MyUserDefault_destroyInstance'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tool_MyUserDefault_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"MyUserDefault",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_MyUserDefault_getInstance'", nullptr);
            return 0;
        }
        MyUserDefault* ret = MyUserDefault::getInstance();
        object_to_luaval<MyUserDefault>(tolua_S, "MyUserDefault",(MyUserDefault*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "MyUserDefault:getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_MyUserDefault_getInstance'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_tool_MyUserDefault_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (MyUserDefault)");
    return 0;
}

int lua_register_cocos2dx_tool_MyUserDefault(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"MyUserDefault");
    tolua_cclass(tolua_S,"MyUserDefault","MyUserDefault","",nullptr);

    tolua_beginmodule(tolua_S,"MyUserDefault");
        tolua_function(tolua_S,"setIntegerForKey",lua_cocos2dx_tool_MyUserDefault_setIntegerForKey);
        tolua_function(tolua_S,"getFloatForKey",lua_cocos2dx_tool_MyUserDefault_getFloatForKey);
        tolua_function(tolua_S,"getBoolForKey",lua_cocos2dx_tool_MyUserDefault_getBoolForKey);
        tolua_function(tolua_S,"setDoubleForKey",lua_cocos2dx_tool_MyUserDefault_setDoubleForKey);
        tolua_function(tolua_S,"setFloatForKey",lua_cocos2dx_tool_MyUserDefault_setFloatForKey);
        tolua_function(tolua_S,"getStringForKey",lua_cocos2dx_tool_MyUserDefault_getStringForKey);
        tolua_function(tolua_S,"setStringForKey",lua_cocos2dx_tool_MyUserDefault_setStringForKey);
        tolua_function(tolua_S,"setValueForKey",lua_cocos2dx_tool_MyUserDefault_setValueForKey);
        tolua_function(tolua_S,"getIntegerForKey",lua_cocos2dx_tool_MyUserDefault_getIntegerForKey);
        tolua_function(tolua_S,"getDoubleForKey",lua_cocos2dx_tool_MyUserDefault_getDoubleForKey);
        tolua_function(tolua_S,"setBoolForKey",lua_cocos2dx_tool_MyUserDefault_setBoolForKey);
        tolua_function(tolua_S,"destroyInstance", lua_cocos2dx_tool_MyUserDefault_destroyInstance);
        tolua_function(tolua_S,"getInstance", lua_cocos2dx_tool_MyUserDefault_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(MyUserDefault).name();
    g_luaType[typeName] = "MyUserDefault";
    g_typeCast["MyUserDefault"] = "MyUserDefault";
    return 1;
}

int lua_cocos2dx_tool_NewCurl_LoadUrlImage(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"NewCurl",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        std::string arg0;
        std::string arg1;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "NewCurl:LoadUrlImage");
        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "NewCurl:LoadUrlImage");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_NewCurl_LoadUrlImage'", nullptr);
            return 0;
        }
        int ret = NewCurl::LoadUrlImage(arg0, arg1);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "NewCurl:LoadUrlImage",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_NewCurl_LoadUrlImage'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tool_NewCurl_HttpGet(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"NewCurl",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "NewCurl:HttpGet");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_NewCurl_HttpGet'", nullptr);
            return 0;
        }
        std::string ret = NewCurl::HttpGet(arg0);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    if (argc == 2)
    {
        std::string arg0;
        int arg1;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "NewCurl:HttpGet");
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "NewCurl:HttpGet");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_NewCurl_HttpGet'", nullptr);
            return 0;
        }
        std::string ret = NewCurl::HttpGet(arg0, arg1);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    if (argc == 3)
    {
        std::string arg0;
        int arg1;
        std::string arg2;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "NewCurl:HttpGet");
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "NewCurl:HttpGet");
        ok &= luaval_to_std_string(tolua_S, 4,&arg2, "NewCurl:HttpGet");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_NewCurl_HttpGet'", nullptr);
            return 0;
        }
        std::string ret = NewCurl::HttpGet(arg0, arg1, arg2);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "NewCurl:HttpGet",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_NewCurl_HttpGet'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tool_NewCurl_getCallBackType(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"NewCurl",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_NewCurl_getCallBackType'", nullptr);
            return 0;
        }
        std::string ret = NewCurl::getCallBackType();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "NewCurl:getCallBackType",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_NewCurl_getCallBackType'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tool_NewCurl_HttpPost(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"NewCurl",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        std::string arg0;
        std::string arg1;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "NewCurl:HttpPost");
        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "NewCurl:HttpPost");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_NewCurl_HttpPost'", nullptr);
            return 0;
        }
        std::string ret = NewCurl::HttpPost(arg0, arg1);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    if (argc == 3)
    {
        std::string arg0;
        std::string arg1;
        int arg2;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "NewCurl:HttpPost");
        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "NewCurl:HttpPost");
        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "NewCurl:HttpPost");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_NewCurl_HttpPost'", nullptr);
            return 0;
        }
        std::string ret = NewCurl::HttpPost(arg0, arg1, arg2);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    if (argc == 4)
    {
        std::string arg0;
        std::string arg1;
        int arg2;
        std::string arg3;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "NewCurl:HttpPost");
        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "NewCurl:HttpPost");
        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "NewCurl:HttpPost");
        ok &= luaval_to_std_string(tolua_S, 5,&arg3, "NewCurl:HttpPost");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_NewCurl_HttpPost'", nullptr);
            return 0;
        }
        std::string ret = NewCurl::HttpPost(arg0, arg1, arg2, arg3);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "NewCurl:HttpPost",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_NewCurl_HttpPost'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_tool_NewCurl_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (NewCurl)");
    return 0;
}

int lua_register_cocos2dx_tool_NewCurl(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"NewCurl");
    tolua_cclass(tolua_S,"NewCurl","NewCurl","",nullptr);

    tolua_beginmodule(tolua_S,"NewCurl");
        tolua_function(tolua_S,"LoadUrlImage", lua_cocos2dx_tool_NewCurl_LoadUrlImage);
        tolua_function(tolua_S,"HttpGet", lua_cocos2dx_tool_NewCurl_HttpGet);
        tolua_function(tolua_S,"getCallBackType", lua_cocos2dx_tool_NewCurl_getCallBackType);
        tolua_function(tolua_S,"HttpPost", lua_cocos2dx_tool_NewCurl_HttpPost);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(NewCurl).name();
    g_luaType[typeName] = "NewCurl";
    g_typeCast["NewCurl"] = "NewCurl";
    return 1;
}

int lua_cocos2dx_tool_uploadFile_GetUpLoadFileSuccess(lua_State* tolua_S)
{
    int argc = 0;
    uploadFile* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"uploadFile",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (uploadFile*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_uploadFile_GetUpLoadFileSuccess'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "uploadFile:GetUpLoadFileSuccess");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_uploadFile_GetUpLoadFileSuccess'", nullptr);
            return 0;
        }
        bool ret = cobj->GetUpLoadFileSuccess(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "uploadFile:GetUpLoadFileSuccess",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_uploadFile_GetUpLoadFileSuccess'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_uploadFile_UpLoadFile(lua_State* tolua_S)
{
    int argc = 0;
    uploadFile* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"uploadFile",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (uploadFile*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tool_uploadFile_UpLoadFile'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "uploadFile:UpLoadFile");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_uploadFile_UpLoadFile'", nullptr);
            return 0;
        }
        bool ret = cobj->UpLoadFile(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "uploadFile:UpLoadFile",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_uploadFile_UpLoadFile'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tool_uploadFile_write_data(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"uploadFile",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 4)
    {
        unsigned char* arg0;
        unsigned int arg1;
        unsigned int arg2;
        void* arg3;
        #pragma warning NO CONVERSION TO NATIVE FOR unsigned char*
		ok = false;
        ok &= luaval_to_uint32(tolua_S, 3,&arg1, "uploadFile:write_data");
        ok &= luaval_to_uint32(tolua_S, 4,&arg2, "uploadFile:write_data");
        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_uploadFile_write_data'", nullptr);
            return 0;
        }
        unsigned int ret = uploadFile::write_data(arg0, arg1, arg2, arg3);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "uploadFile:write_data",argc, 4);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_uploadFile_write_data'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tool_uploadFile_GetInst(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"uploadFile",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_tool_uploadFile_GetInst'", nullptr);
            return 0;
        }
        uploadFile* ret = uploadFile::GetInst();
        object_to_luaval<uploadFile>(tolua_S, "uploadFile",(uploadFile*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "uploadFile:GetInst",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tool_uploadFile_GetInst'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_tool_uploadFile_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (uploadFile)");
    return 0;
}

int lua_register_cocos2dx_tool_uploadFile(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"uploadFile");
    tolua_cclass(tolua_S,"uploadFile","uploadFile","cc.CCObject",nullptr);

    tolua_beginmodule(tolua_S,"uploadFile");
        tolua_function(tolua_S,"GetUpLoadFileSuccess",lua_cocos2dx_tool_uploadFile_GetUpLoadFileSuccess);
        tolua_function(tolua_S,"UpLoadFile",lua_cocos2dx_tool_uploadFile_UpLoadFile);
        tolua_function(tolua_S,"write_data", lua_cocos2dx_tool_uploadFile_write_data);
        tolua_function(tolua_S,"GetInst", lua_cocos2dx_tool_uploadFile_GetInst);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(uploadFile).name();
    g_luaType[typeName] = "uploadFile";
    g_typeCast["uploadFile"] = "uploadFile";
    return 1;
}
TOLUA_API int register_all_cocos2dx_tool(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"ds",0);
	tolua_beginmodule(tolua_S,"ds");

	lua_register_cocos2dx_tool_CNickReadInfo(tolua_S);
	lua_register_cocos2dx_tool_CHarmonyString(tolua_S);
	lua_register_cocos2dx_tool_ImagicDownManager(tolua_S);
	lua_register_cocos2dx_tool_StringConvert(tolua_S);
	lua_register_cocos2dx_tool_PacketWriteAide(tolua_S);
	lua_register_cocos2dx_tool_NewCurl(tolua_S);
	lua_register_cocos2dx_tool_PacketReadAide(tolua_S);
	lua_register_cocos2dx_tool_DSFileUpdate(tolua_S);
	lua_register_cocos2dx_tool_StaticData(tolua_S);
	lua_register_cocos2dx_tool_StringData(tolua_S);
	lua_register_cocos2dx_tool_SoundManager(tolua_S);
	lua_register_cocos2dx_tool_CoTimer(tolua_S);
	lua_register_cocos2dx_tool_MyConfigureData(tolua_S);
	lua_register_cocos2dx_tool_SpriteHelper(tolua_S);
	lua_register_cocos2dx_tool_GameVersionUpdate(tolua_S);
	lua_register_cocos2dx_tool_PlatformVersionUpdate(tolua_S);
	lua_register_cocos2dx_tool_uploadFile(tolua_S);
	lua_register_cocos2dx_tool_Game_Path_Manager(tolua_S);
	lua_register_cocos2dx_tool_MyUserDefault(tolua_S);
    lua_register_cocos2dx_tool_Action_Move_Point6(tolua_S);
    lua_register_cocos2dx_tool_Action_Bird_Move_Linear6(tolua_S);
    lua_register_cocos2dx_tool_Action_Bird_Round_Move6(tolua_S);
    lua_register_cocos2dx_tool_Action_Bird_Move_Pause_Linear6(tolua_S);
    lua_register_cocos2dx_tool_Action_Bullet_Move6(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

#endif
