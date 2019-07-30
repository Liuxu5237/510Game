#include "lua_cocos2dx_game_auto.hpp"
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC || CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
#include "lua/lib/BitLib.h"
#include "lua/lib/GameScriptData.h"
#include "game/dntgGame/DntgClientKernelSink.h"
//#include "game/lkpyGame/LkpyClientKernelSink.h"
//#include "game/mj/JNCMJGameEngine.h"
//#include "game/betcar/GameFrameEngineBetcar.h"
//#include "game/jsys/GameFrameEngineJsys.h"
//#include "game/jamj/JAMJGameEngine.h"

#include "tolua_fix.h"
#include "LuaBasicConversions.h"



int lua_cocos2dx_game_LuaBitLib_bAnd(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"LuaBitLib",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        int arg0;
        int arg1;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "LuaBitLib:bAnd");
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "LuaBitLib:bAnd");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_game_LuaBitLib_bAnd'", nullptr);
            return 0;
        }
        int ret = LuaBitLib::bAnd(arg0, arg1);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "LuaBitLib:bAnd",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_game_LuaBitLib_bAnd'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_game_LuaBitLib_bOr(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"LuaBitLib",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        int arg0;
        int arg1;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "LuaBitLib:bOr");
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "LuaBitLib:bOr");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_game_LuaBitLib_bOr'", nullptr);
            return 0;
        }
        int ret = LuaBitLib::bOr(arg0, arg1);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "LuaBitLib:bOr",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_game_LuaBitLib_bOr'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_game_LuaBitLib_rShift(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"LuaBitLib",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        int arg0;
        int arg1;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "LuaBitLib:rShift");
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "LuaBitLib:rShift");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_game_LuaBitLib_rShift'", nullptr);
            return 0;
        }
        int ret = LuaBitLib::rShift(arg0, arg1);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "LuaBitLib:rShift",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_game_LuaBitLib_rShift'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_game_LuaBitLib_bNot(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"LuaBitLib",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "LuaBitLib:bNot");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_game_LuaBitLib_bNot'", nullptr);
            return 0;
        }
        int ret = LuaBitLib::bNot(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "LuaBitLib:bNot",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_game_LuaBitLib_bNot'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_game_LuaBitLib_lShift(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"LuaBitLib",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        int arg0;
        int arg1;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "LuaBitLib:lShift");
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "LuaBitLib:lShift");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_game_LuaBitLib_lShift'", nullptr);
            return 0;
        }
        int ret = LuaBitLib::lShift(arg0, arg1);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "LuaBitLib:lShift",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_game_LuaBitLib_lShift'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_game_LuaBitLib_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (LuaBitLib)");
    return 0;
}

int lua_register_cocos2dx_game_LuaBitLib(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"LuaBitLib");
    tolua_cclass(tolua_S,"LuaBitLib","LuaBitLib","",nullptr);

    tolua_beginmodule(tolua_S,"LuaBitLib");
        tolua_function(tolua_S,"bAnd", lua_cocos2dx_game_LuaBitLib_bAnd);
        tolua_function(tolua_S,"bOr", lua_cocos2dx_game_LuaBitLib_bOr);
        tolua_function(tolua_S,"rShift", lua_cocos2dx_game_LuaBitLib_rShift);
        tolua_function(tolua_S,"bNot", lua_cocos2dx_game_LuaBitLib_bNot);
        tolua_function(tolua_S,"lShift", lua_cocos2dx_game_LuaBitLib_lShift);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(LuaBitLib).name();
    g_luaType[typeName] = "LuaBitLib";
    g_typeCast["LuaBitLib"] = "LuaBitLib";
    return 1;
}

int lua_cocos2dx_game_GameScriptDataMananger_getFloat(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"GameScriptDataMananger",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "GameScriptDataMananger:getFloat");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_game_GameScriptDataMananger_getFloat'", nullptr);
            return 0;
        }
        double ret = GameScriptDataMananger::getFloat(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "GameScriptDataMananger:getFloat",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_game_GameScriptDataMananger_getFloat'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_game_GameScriptDataMananger_loadGameScriptData(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"GameScriptDataMananger",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "GameScriptDataMananger:loadGameScriptData");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_game_GameScriptDataMananger_loadGameScriptData'", nullptr);
            return 0;
        }
        GameScriptDataMananger::loadGameScriptData(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "GameScriptDataMananger:loadGameScriptData",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_game_GameScriptDataMananger_loadGameScriptData'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_game_GameScriptDataMananger_getString(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"GameScriptDataMananger",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "GameScriptDataMananger:getString");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_game_GameScriptDataMananger_getString'", nullptr);
            return 0;
        }
        const std::string& ret = GameScriptDataMananger::getString(arg0);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "GameScriptDataMananger:getString",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_game_GameScriptDataMananger_getString'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_game_GameScriptDataMananger_getRect(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"GameScriptDataMananger",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "GameScriptDataMananger:getRect");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_game_GameScriptDataMananger_getRect'", nullptr);
            return 0;
        }
        cocos2d::Rect ret = GameScriptDataMananger::getRect(arg0);
        rect_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "GameScriptDataMananger:getRect",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_game_GameScriptDataMananger_getRect'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_game_GameScriptDataMananger_getPoint(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"GameScriptDataMananger",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "GameScriptDataMananger:getPoint");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_game_GameScriptDataMananger_getPoint'", nullptr);
            return 0;
        }
        cocos2d::Point ret = GameScriptDataMananger::getPoint(arg0);
        point_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "GameScriptDataMananger:getPoint",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_game_GameScriptDataMananger_getPoint'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_game_GameScriptDataMananger_getSize(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"GameScriptDataMananger",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "GameScriptDataMananger:getSize");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_game_GameScriptDataMananger_getSize'", nullptr);
            return 0;
        }
        cocos2d::Size ret = GameScriptDataMananger::getSize(arg0);
        size_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "GameScriptDataMananger:getSize",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_game_GameScriptDataMananger_getSize'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_game_GameScriptDataMananger_getInt(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"GameScriptDataMananger",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "GameScriptDataMananger:getInt");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_game_GameScriptDataMananger_getInt'", nullptr);
            return 0;
        }
        int ret = GameScriptDataMananger::getInt(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "GameScriptDataMananger:getInt",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_game_GameScriptDataMananger_getInt'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_game_GameScriptDataMananger_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (GameScriptDataMananger)");
    return 0;
}

int lua_register_cocos2dx_game_GameScriptDataMananger(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"GameScriptDataMananger");
    tolua_cclass(tolua_S,"GameScriptDataMananger","GameScriptDataMananger","",nullptr);

    tolua_beginmodule(tolua_S,"GameScriptDataMananger");
        tolua_function(tolua_S,"getFloat", lua_cocos2dx_game_GameScriptDataMananger_getFloat);
        tolua_function(tolua_S,"loadGameScriptData", lua_cocos2dx_game_GameScriptDataMananger_loadGameScriptData);
        tolua_function(tolua_S,"getString", lua_cocos2dx_game_GameScriptDataMananger_getString);
        tolua_function(tolua_S,"getRect", lua_cocos2dx_game_GameScriptDataMananger_getRect);
        tolua_function(tolua_S,"getPoint", lua_cocos2dx_game_GameScriptDataMananger_getPoint);
        tolua_function(tolua_S,"getSize", lua_cocos2dx_game_GameScriptDataMananger_getSize);
        tolua_function(tolua_S,"getInt", lua_cocos2dx_game_GameScriptDataMananger_getInt);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(GameScriptDataMananger).name();
    g_luaType[typeName] = "GameScriptDataMananger";
    g_typeCast["GameScriptDataMananger"] = "GameScriptDataMananger";
    return 1;
}

int lua_cocos2dx_game_DntgClientKernelSink_Destroy(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ds.DntgClientKernelSink",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_game_DntgClientKernelSink_Destroy'", nullptr);
            return 0;
        }
        Dntg::DntgClientKernelSink::Destroy();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "ds.DntgClientKernelSink:Destroy",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_game_DntgClientKernelSink_Destroy'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_game_DntgClientKernelSink_Get(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ds.DntgClientKernelSink",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_game_DntgClientKernelSink_Get'", nullptr);
            return 0;
        }
        Dntg::DntgClientKernelSink* ret = Dntg::DntgClientKernelSink::Get();
        object_to_luaval<Dntg::DntgClientKernelSink>(tolua_S, "ds.DntgClientKernelSink",(Dntg::DntgClientKernelSink*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "ds.DntgClientKernelSink:Get",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_game_DntgClientKernelSink_Get'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_game_DntgClientKernelSink_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (DntgClientKernelSink)");
    return 0;
}

int lua_register_cocos2dx_game_DntgClientKernelSink(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"ds.DntgClientKernelSink");
    tolua_cclass(tolua_S,"DntgClientKernelSink","ds.DntgClientKernelSink","IGameFrameEngineSink",nullptr);

    tolua_beginmodule(tolua_S,"DntgClientKernelSink");
        tolua_function(tolua_S,"Destroy", lua_cocos2dx_game_DntgClientKernelSink_Destroy);
        tolua_function(tolua_S,"Get", lua_cocos2dx_game_DntgClientKernelSink_Get);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(Dntg::DntgClientKernelSink).name();
    g_luaType[typeName] = "ds.DntgClientKernelSink";
    g_typeCast["DntgClientKernelSink"] = "ds.DntgClientKernelSink";
    return 1;
}

//int lua_cocos2dx_game_LkpyClientKernelSink_Destroy(lua_State* tolua_S)
//{
//    int argc = 0;
//    bool ok  = true;
//
//#if COCOS2D_DEBUG >= 1
//    tolua_Error tolua_err;
//#endif
//
//#if COCOS2D_DEBUG >= 1
//    if (!tolua_isusertable(tolua_S,1,"ds.LkpyClientKernelSink",0,&tolua_err)) goto tolua_lerror;
//#endif
//
//    argc = lua_gettop(tolua_S) - 1;
//
//    if (argc == 0)
//    {
//        if(!ok)
//        {
//            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_game_LkpyClientKernelSink_Destroy'", nullptr);
//            return 0;
//        }
//        Lkpy::LkpyClientKernelSink::Destroy();
//        lua_settop(tolua_S, 1);
//        return 1;
//    }
//    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "ds.LkpyClientKernelSink:Destroy",argc, 0);
//    return 0;
//#if COCOS2D_DEBUG >= 1
//    tolua_lerror:
//    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_game_LkpyClientKernelSink_Destroy'.",&tolua_err);
//#endif
//    return 0;
//}
//int lua_cocos2dx_game_LkpyClientKernelSink_Get(lua_State* tolua_S)
//{
//    int argc = 0;
//    bool ok  = true;
//
//#if COCOS2D_DEBUG >= 1
//    tolua_Error tolua_err;
//#endif
//
//#if COCOS2D_DEBUG >= 1
//    if (!tolua_isusertable(tolua_S,1,"ds.LkpyClientKernelSink",0,&tolua_err)) goto tolua_lerror;
//#endif
//
//    argc = lua_gettop(tolua_S) - 1;
//
//    if (argc == 0)
//    {
//        if(!ok)
//        {
//            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_game_LkpyClientKernelSink_Get'", nullptr);
//            return 0;
//        }
//        Lkpy::LkpyClientKernelSink* ret = Lkpy::LkpyClientKernelSink::Get();
//        object_to_luaval<Lkpy::LkpyClientKernelSink>(tolua_S, "ds.LkpyClientKernelSink",(Lkpy::LkpyClientKernelSink*)ret);
//        return 1;
//    }
//    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "ds.LkpyClientKernelSink:Get",argc, 0);
//    return 0;
//#if COCOS2D_DEBUG >= 1
//    tolua_lerror:
//    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_game_LkpyClientKernelSink_Get'.",&tolua_err);
//#endif
//    return 0;
//}
//static int lua_cocos2dx_game_LkpyClientKernelSink_finalize(lua_State* tolua_S)
//{
//    printf("luabindings: finalizing LUA object (LkpyClientKernelSink)");
//    return 0;
//}
//
//int lua_register_cocos2dx_game_LkpyClientKernelSink(lua_State* tolua_S)
//{
//    tolua_usertype(tolua_S,"ds.LkpyClientKernelSink");
//    tolua_cclass(tolua_S,"LkpyClientKernelSink","ds.LkpyClientKernelSink","IGameFrameEngineSink",nullptr);
//
//    tolua_beginmodule(tolua_S,"LkpyClientKernelSink");
//        tolua_function(tolua_S,"Destroy", lua_cocos2dx_game_LkpyClientKernelSink_Destroy);
//        tolua_function(tolua_S,"Get", lua_cocos2dx_game_LkpyClientKernelSink_Get);
//    tolua_endmodule(tolua_S);
//    std::string typeName = typeid(Lkpy::LkpyClientKernelSink).name();
//    g_luaType[typeName] = "ds.LkpyClientKernelSink";
//    g_typeCast["LkpyClientKernelSink"] = "ds.LkpyClientKernelSink";
//    return 1;
//}
//
//int lua_cocos2dx_game_CGameFrameEngineMJ_Destroy(lua_State* tolua_S)
//{
//    int argc = 0;
//    bool ok  = true;
//
//#if COCOS2D_DEBUG >= 1
//    tolua_Error tolua_err;
//#endif
//
//#if COCOS2D_DEBUG >= 1
//    if (!tolua_isusertable(tolua_S,1,"ds.CGameFrameEngineMJ",0,&tolua_err)) goto tolua_lerror;
//#endif
//
//    argc = lua_gettop(tolua_S) - 1;
//
//    if (argc == 0)
//    {
//        if(!ok)
//        {
//            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_game_CGameFrameEngineMJ_Destroy'", nullptr);
//            return 0;
//        }
//        mj::CGameFrameEngineMJ::Destroy();
//        lua_settop(tolua_S, 1);
//        return 1;
//    }
//    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "ds.CGameFrameEngineMJ:Destroy",argc, 0);
//    return 0;
//#if COCOS2D_DEBUG >= 1
//    tolua_lerror:
//    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_game_CGameFrameEngineMJ_Destroy'.",&tolua_err);
//#endif
//    return 0;
//}
//int lua_cocos2dx_game_CGameFrameEngineMJ_Get(lua_State* tolua_S)
//{
//    int argc = 0;
//    bool ok  = true;
//
//#if COCOS2D_DEBUG >= 1
//    tolua_Error tolua_err;
//#endif
//
//#if COCOS2D_DEBUG >= 1
//    if (!tolua_isusertable(tolua_S,1,"ds.CGameFrameEngineMJ",0,&tolua_err)) goto tolua_lerror;
//#endif
//
//    argc = lua_gettop(tolua_S) - 1;
//
//    if (argc == 0)
//    {
//        if(!ok)
//        {
//            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_game_CGameFrameEngineMJ_Get'", nullptr);
//            return 0;
//        }
//        mj::CGameFrameEngineMJ* ret = mj::CGameFrameEngineMJ::Get();
//        object_to_luaval<mj::CGameFrameEngineMJ>(tolua_S, "ds.CGameFrameEngineMJ",(mj::CGameFrameEngineMJ*)ret);
//        return 1;
//    }
//    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "ds.CGameFrameEngineMJ:Get",argc, 0);
//    return 0;
//#if COCOS2D_DEBUG >= 1
//    tolua_lerror:
//    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_game_CGameFrameEngineMJ_Get'.",&tolua_err);
//#endif
//    return 0;
//}
//static int lua_cocos2dx_game_CGameFrameEngineMJ_finalize(lua_State* tolua_S)
//{
//    printf("luabindings: finalizing LUA object (CGameFrameEngineMJ)");
//    return 0;
//}
//
//int lua_register_cocos2dx_game_CGameFrameEngineMJ(lua_State* tolua_S)
//{
//    tolua_usertype(tolua_S,"ds.CGameFrameEngineMJ");
//    tolua_cclass(tolua_S,"CGameFrameEngineMJ","ds.CGameFrameEngineMJ","IGameFrameEngineSink",nullptr);
//
//    tolua_beginmodule(tolua_S,"CGameFrameEngineMJ");
//        tolua_function(tolua_S,"Destroy", lua_cocos2dx_game_CGameFrameEngineMJ_Destroy);
//        tolua_function(tolua_S,"Get", lua_cocos2dx_game_CGameFrameEngineMJ_Get);
//    tolua_endmodule(tolua_S);
//    std::string typeName = typeid(mj::CGameFrameEngineMJ).name();
//    g_luaType[typeName] = "ds.CGameFrameEngineMJ";
//    g_typeCast["CGameFrameEngineMJ"] = "ds.CGameFrameEngineMJ";
//    return 1;
//}

/* int lua_cocos2dx_game_CGameFrameEngineJAMJ_Destroy(lua_State* tolua_S)
{
	int argc = 0;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertable(tolua_S, 1, "ds.CGameFrameEngineJAMJ", 0, &tolua_err)) goto tolua_lerror;
#endif

	argc = lua_gettop(tolua_S) - 1;

	if (argc == 0)
	{
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_cocos2dx_game_CGameFrameEngineJAMJ_Destroy'", nullptr);
			return 0;
		}
		jamj::CGameFrameEngineJAMJ::Destroy();
		lua_settop(tolua_S, 1);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "ds.CGameFrameEngineJAMJ:Destroy", argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_cocos2dx_game_CGameFrameEngineJAMJ_Destroy'.", &tolua_err);
#endif
	return 0;
}
int lua_cocos2dx_game_CGameFrameEngineJAMJ_Get(lua_State* tolua_S)
{
	int argc = 0;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertable(tolua_S, 1, "ds.CGameFrameEngineJAMJ", 0, &tolua_err)) goto tolua_lerror;
#endif

	argc = lua_gettop(tolua_S) - 1;

	if (argc == 0)
	{
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_cocos2dx_game_CGameFrameEngineJAMJ_Get'", nullptr);
			return 0;
		}
		jamj::CGameFrameEngineJAMJ* ret = jamj::CGameFrameEngineJAMJ::Get();
		object_to_luaval<jamj::CGameFrameEngineJAMJ>(tolua_S, "ds.CGameFrameEngineJAMJ", (jamj::CGameFrameEngineJAMJ*)ret);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "ds.CGameFrameEngineJAMJ:Get", argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_cocos2dx_game_CGameFrameEngineJAMJ_Get'.", &tolua_err);
#endif
	return 0;
}
static int lua_cocos2dx_game_CGameFrameEngineJAMJ_finalize(lua_State* tolua_S)
{
	printf("luabindings: finalizing LUA object (CGameFrameEngineJAMJ)");
	return 0;
}

int lua_register_cocos2dx_game_CGameFrameEngineJAMJ(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "ds.CGameFrameEngineJAMJ");
	tolua_cclass(tolua_S, "CGameFrameEngineJAMJ", "ds.CGameFrameEngineJAMJ", "IGameFrameEngineSink", nullptr);

	tolua_beginmodule(tolua_S, "CGameFrameEngineJAMJ");
	tolua_function(tolua_S, "Destroy", lua_cocos2dx_game_CGameFrameEngineJAMJ_Destroy);
	tolua_function(tolua_S, "Get", lua_cocos2dx_game_CGameFrameEngineJAMJ_Get);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(jamj::CGameFrameEngineJAMJ).name();
	g_luaType[typeName] = "ds.CGameFrameEngineJAMJ";
	g_typeCast["CGameFrameEngineJAMJ"] = "ds.CGameFrameEngineJAMJ";
	return 1;
} */

//int lua_cocos2dx_game_CGameFrameEngineBetcar_Destroy(lua_State* tolua_S)
//{
//	int argc = 0;
//	bool ok = true;
//
//#if COCOS2D_DEBUG >= 1
//	tolua_Error tolua_err;
//#endif
//
//#if COCOS2D_DEBUG >= 1
//	if (!tolua_isusertable(tolua_S, 1, "ds.CGameFrameEngineBetcar", 0, &tolua_err)) goto tolua_lerror;
//#endif
//
//	argc = lua_gettop(tolua_S) - 1;
//
//	if (argc == 0)
//	{
//		if (!ok)
//		{
//			tolua_error(tolua_S, "invalid arguments in function 'lua_cocos2dx_game_CGameFrameEngineBetcar_Destroy'", nullptr);
//			return 0;
//		}
//		/*betcar::*/CGameFrameEngineBetcar::Destroy();
//		lua_settop(tolua_S, 1);
//		return 1;
//	}
//	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "ds.CGameFrameEngineBetcar:Destroy", argc, 0);
//	return 0;
//#if COCOS2D_DEBUG >= 1
//tolua_lerror:
//	tolua_error(tolua_S, "#ferror in function 'lua_cocos2dx_game_CGameFrameEngineBetcar_Destroy'.", &tolua_err);
//#endif
//	return 0;
//}
//int lua_cocos2dx_game_CGameFrameEngineBetcar_Get(lua_State* tolua_S)
//{
//	int argc = 0;
//	bool ok = true;
//
//#if COCOS2D_DEBUG >= 1
//	tolua_Error tolua_err;
//#endif
//
//#if COCOS2D_DEBUG >= 1
//	if (!tolua_isusertable(tolua_S, 1, "ds.CGameFrameEngineBetcar", 0, &tolua_err)) goto tolua_lerror;
//#endif
//
//	argc = lua_gettop(tolua_S) - 1;
//
//	if (argc == 0)
//	{
//		if (!ok)
//		{
//			tolua_error(tolua_S, "invalid arguments in function 'lua_cocos2dx_game_CGameFrameEngineBetcar_Get'", nullptr);
//			return 0;
//		}
//		/*betcar::*/CGameFrameEngineBetcar* ret = /*betcar::*/CGameFrameEngineBetcar::Get();
//		object_to_luaval</*betcar::*/CGameFrameEngineBetcar>(tolua_S, "ds.CGameFrameEngineBetcar", (/*betcar::*/CGameFrameEngineBetcar*)ret);
//		return 1;
//	}
//	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "ds.CGameFrameEngineBetcar:Get", argc, 0);
//	return 0;
//#if COCOS2D_DEBUG >= 1
//tolua_lerror:
//	tolua_error(tolua_S, "#ferror in function 'lua_cocos2dx_game_CGameFrameEngineBetcar_Get'.", &tolua_err);
//#endif
//	return 0;
//}
//static int lua_cocos2dx_game_CGameFrameEngineBetcar_finalize(lua_State* tolua_S)
//{
//	printf("luabindings: finalizing LUA object (CGameFrameEngineBetcar)");
//	return 0;
//}
//
//int lua_register_cocos2dx_game_CGameFrameEngineBetcar(lua_State* tolua_S)
//{
//	tolua_usertype(tolua_S, "ds.CGameFrameEngineBetcar");
//	tolua_cclass(tolua_S, "CGameFrameEngineBetcar", "ds.CGameFrameEngineBetcar", "IGameFrameEngineSink", nullptr);
//
//	tolua_beginmodule(tolua_S, "CGameFrameEngineBetcar");
//	tolua_function(tolua_S, "Destroy", lua_cocos2dx_game_CGameFrameEngineBetcar_Destroy);
//	tolua_function(tolua_S, "Get", lua_cocos2dx_game_CGameFrameEngineBetcar_Get);
//	tolua_endmodule(tolua_S);
//	std::string typeName = typeid(CGameFrameEngineBetcar).name();
//	g_luaType[typeName] = "ds.CGameFrameEngineBetcar";
//	g_typeCast["CGameFrameEngineBetcar"] = "ds.CGameFrameEngineBetcar";
//	return 1;
//}
/*
int lua_cocos2dx_game_GameFrameEngineJsys_Destroy(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"GameFrameEngineJsys",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_game_GameFrameEngineJsys_Destroy'", nullptr);
            return 0;
        }
        GameFrameEngineJsys::Destroy();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "GameFrameEngineJsys:Destroy",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_game_GameFrameEngineJsys_Destroy'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_game_GameFrameEngineJsys_Get(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"GameFrameEngineJsys",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_game_GameFrameEngineJsys_Get'", nullptr);
            return 0;
        }
        GameFrameEngineJsys* ret = GameFrameEngineJsys::Get();
        object_to_luaval<GameFrameEngineJsys>(tolua_S, "GameFrameEngineJsys",(GameFrameEngineJsys*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "GameFrameEngineJsys:Get",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_game_GameFrameEngineJsys_Get'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_game_GameFrameEngineJsys_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (GameFrameEngineJsys)");
    return 0;
}

int lua_register_cocos2dx_game_GameFrameEngineJsys(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"GameFrameEngineJsys");
    tolua_cclass(tolua_S,"GameFrameEngineJsys","GameFrameEngineJsys","IGameFrameEngineSink",nullptr);

    tolua_beginmodule(tolua_S,"GameFrameEngineJsys");
        tolua_function(tolua_S,"Destroy", lua_cocos2dx_game_GameFrameEngineJsys_Destroy);
        tolua_function(tolua_S,"Get", lua_cocos2dx_game_GameFrameEngineJsys_Get);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(GameFrameEngineJsys).name();
    g_luaType[typeName] = "GameFrameEngineJsys";
    g_typeCast["GameFrameEngineJsys"] = "GameFrameEngineJsys";
    return 1;
}
*/
TOLUA_API int register_all_cocos2dx_game(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"ds",0);
	tolua_beginmodule(tolua_S,"ds");

	lua_register_cocos2dx_game_LuaBitLib(tolua_S);
	lua_register_cocos2dx_game_GameScriptDataMananger(tolua_S);
	lua_register_cocos2dx_game_DntgClientKernelSink(tolua_S);
	//lua_register_cocos2dx_game_LkpyClientKernelSink(tolua_S);
	//lua_register_cocos2dx_game_CGameFrameEngineMJ(tolua_S);
	//lua_register_cocos2dx_game_CGameFrameEngineBetcar(tolua_S);
	//lua_register_cocos2dx_game_GameFrameEngineJsys(tolua_S);
	//lua_register_cocos2dx_game_CGameFrameEngineJAMJ(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

#endif
