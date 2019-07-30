#include "lua_cocos2dx_game_cocos_extention_manual.hpp"
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC || CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
#include "script/ActionEx.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"
#include "tools/tools/newcurl.h"


int lua_cocos2dx_game_cocos_extention_MoveExTxtTime_update(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::MoveExTxtTime* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.MoveExTxtTime",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::MoveExTxtTime*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_game_cocos_extention_MoveExTxtTime_update'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "cc.MoveExTxtTime:update");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_game_cocos_extention_MoveExTxtTime_update'", nullptr);
            return 0;
        }
        cobj->update(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.MoveExTxtTime:update",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_game_cocos_extention_MoveExTxtTime_update'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_game_cocos_extention_MoveExTxtTime_initWithDuration(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::MoveExTxtTime* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.MoveExTxtTime",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::MoveExTxtTime*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_game_cocos_extention_MoveExTxtTime_initWithDuration'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        double arg0;
        double arg1;
        double arg2;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "cc.MoveExTxtTime:initWithDuration");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "cc.MoveExTxtTime:initWithDuration");

        ok &= luaval_to_number(tolua_S, 4,&arg2, "cc.MoveExTxtTime:initWithDuration");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_game_cocos_extention_MoveExTxtTime_initWithDuration'", nullptr);
            return 0;
        }
        bool ret = cobj->initWithDuration(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.MoveExTxtTime:initWithDuration",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_game_cocos_extention_MoveExTxtTime_initWithDuration'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_game_cocos_extention_MoveExTxtTime_setStrType(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::MoveExTxtTime* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.MoveExTxtTime",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::MoveExTxtTime*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_game_cocos_extention_MoveExTxtTime_setStrType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::MoveExTxtTime::Type arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "cc.MoveExTxtTime:setStrType");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_game_cocos_extention_MoveExTxtTime_setStrType'", nullptr);
            return 0;
        }
        cobj->setStrType(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.MoveExTxtTime:setStrType",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_game_cocos_extention_MoveExTxtTime_setStrType'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_game_cocos_extention_MoveExTxtTime_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.MoveExTxtTime",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 3)
    {
        double arg0;
        double arg1;
        double arg2;
        ok &= luaval_to_number(tolua_S, 2,&arg0, "cc.MoveExTxtTime:create");
        ok &= luaval_to_number(tolua_S, 3,&arg1, "cc.MoveExTxtTime:create");
        ok &= luaval_to_number(tolua_S, 4,&arg2, "cc.MoveExTxtTime:create");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_game_cocos_extention_MoveExTxtTime_create'", nullptr);
            return 0;
        }
        cocos2d::MoveExTxtTime* ret = cocos2d::MoveExTxtTime::create(arg0, arg1, arg2);
        object_to_luaval<cocos2d::MoveExTxtTime>(tolua_S, "cc.MoveExTxtTime",(cocos2d::MoveExTxtTime*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.MoveExTxtTime:create",argc, 3);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_game_cocos_extention_MoveExTxtTime_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_game_cocos_extention_MoveExTxtTime_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (MoveExTxtTime)");
    return 0;
}

int lua_register_cocos2dx_game_cocos_extention_MoveExTxtTime(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.MoveExTxtTime");
    tolua_cclass(tolua_S,"MoveExTxtTime","cc.MoveExTxtTime","cc.ActionInterval",nullptr);

    tolua_beginmodule(tolua_S,"MoveExTxtTime");
        tolua_function(tolua_S,"update",lua_cocos2dx_game_cocos_extention_MoveExTxtTime_update);
        tolua_function(tolua_S,"initWithDuration",lua_cocos2dx_game_cocos_extention_MoveExTxtTime_initWithDuration);
        tolua_function(tolua_S,"setStrType",lua_cocos2dx_game_cocos_extention_MoveExTxtTime_setStrType);
        tolua_function(tolua_S,"create", lua_cocos2dx_game_cocos_extention_MoveExTxtTime_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::MoveExTxtTime).name();
    g_luaType[typeName] = "cc.MoveExTxtTime";
    g_typeCast["MoveExTxtTime"] = "cc.MoveExTxtTime";
    return 1;
}

int lua_cocos2dx_game_cocos_extention_CCVisibleAction_startWithTarget(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCVisibleAction* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCVisibleAction",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCVisibleAction*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_game_cocos_extention_CCVisibleAction_startWithTarget'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Node* arg0;

        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_game_cocos_extention_CCVisibleAction_startWithTarget'", nullptr);
            return 0;
        }
        cobj->startWithTarget(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.CCVisibleAction:startWithTarget",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_game_cocos_extention_CCVisibleAction_startWithTarget'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_game_cocos_extention_CCVisibleAction_reverse(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCVisibleAction* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCVisibleAction",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocos2d::CCVisibleAction*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_game_cocos_extention_CCVisibleAction_reverse'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 0) {
			cocos2d::CCVisibleAction* ret = (cocos2d::CCVisibleAction*)cobj->reverse();
            object_to_luaval<cocos2d::CCVisibleAction>(tolua_S, "cc.CCVisibleAction",(cocos2d::CCVisibleAction*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            cocos2d::ActionInterval* ret = cobj->reverse();
            object_to_luaval<cocos2d::ActionInterval>(tolua_S, "cc.ActionInterval",(cocos2d::ActionInterval*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "cc.CCVisibleAction:reverse",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_game_cocos_extention_CCVisibleAction_reverse'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_game_cocos_extention_CCVisibleAction_initWithDuration(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCVisibleAction* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCVisibleAction",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCVisibleAction*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_game_cocos_extention_CCVisibleAction_initWithDuration'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        bool arg1;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "cc.CCVisibleAction:initWithDuration");

        ok &= luaval_to_boolean(tolua_S, 3,&arg1, "cc.CCVisibleAction:initWithDuration");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_game_cocos_extention_CCVisibleAction_initWithDuration'", nullptr);
            return 0;
        }
        bool ret = cobj->initWithDuration(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.CCVisibleAction:initWithDuration",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_game_cocos_extention_CCVisibleAction_initWithDuration'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_game_cocos_extention_CCVisibleAction_clone(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCVisibleAction* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCVisibleAction",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCVisibleAction*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_game_cocos_extention_CCVisibleAction_clone'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_game_cocos_extention_CCVisibleAction_clone'", nullptr);
            return 0;
        }
        cocos2d::CCVisibleAction* ret = cobj->clone();
        object_to_luaval<cocos2d::CCVisibleAction>(tolua_S, "cc.CCVisibleAction",(cocos2d::CCVisibleAction*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.CCVisibleAction:clone",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_game_cocos_extention_CCVisibleAction_clone'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_game_cocos_extention_CCVisibleAction_stop(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCVisibleAction* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCVisibleAction",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCVisibleAction*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_game_cocos_extention_CCVisibleAction_stop'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_game_cocos_extention_CCVisibleAction_stop'", nullptr);
            return 0;
        }
        cobj->stop();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.CCVisibleAction:stop",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_game_cocos_extention_CCVisibleAction_stop'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_game_cocos_extention_CCVisibleAction_update(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCVisibleAction* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCVisibleAction",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCVisibleAction*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_game_cocos_extention_CCVisibleAction_update'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "cc.CCVisibleAction:update");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_game_cocos_extention_CCVisibleAction_update'", nullptr);
            return 0;
        }
        cobj->update(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.CCVisibleAction:update",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_game_cocos_extention_CCVisibleAction_update'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_game_cocos_extention_CCVisibleAction_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.CCVisibleAction",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        double arg0;
        bool arg1;
        ok &= luaval_to_number(tolua_S, 2,&arg0, "cc.CCVisibleAction:create");
        ok &= luaval_to_boolean(tolua_S, 3,&arg1, "cc.CCVisibleAction:create");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_game_cocos_extention_CCVisibleAction_create'", nullptr);
            return 0;
        }
        cocos2d::CCVisibleAction* ret = cocos2d::CCVisibleAction::create(arg0, arg1);
        object_to_luaval<cocos2d::CCVisibleAction>(tolua_S, "cc.CCVisibleAction",(cocos2d::CCVisibleAction*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.CCVisibleAction:create",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_game_cocos_extention_CCVisibleAction_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_game_cocos_extention_CCVisibleAction_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CCVisibleAction)");
    return 0;
}

int lua_register_cocos2dx_game_cocos_extention_CCVisibleAction(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.CCVisibleAction");
    tolua_cclass(tolua_S,"CCVisibleAction","cc.CCVisibleAction","cc.ActionInterval",nullptr);

    tolua_beginmodule(tolua_S,"CCVisibleAction");
        tolua_function(tolua_S,"startWithTarget",lua_cocos2dx_game_cocos_extention_CCVisibleAction_startWithTarget);
        tolua_function(tolua_S,"reverse",lua_cocos2dx_game_cocos_extention_CCVisibleAction_reverse);
        tolua_function(tolua_S,"initWithDuration",lua_cocos2dx_game_cocos_extention_CCVisibleAction_initWithDuration);
        tolua_function(tolua_S,"clone",lua_cocos2dx_game_cocos_extention_CCVisibleAction_clone);
        tolua_function(tolua_S,"stop",lua_cocos2dx_game_cocos_extention_CCVisibleAction_stop);
        tolua_function(tolua_S,"update",lua_cocos2dx_game_cocos_extention_CCVisibleAction_update);
        tolua_function(tolua_S,"create", lua_cocos2dx_game_cocos_extention_CCVisibleAction_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::CCVisibleAction).name();
    g_luaType[typeName] = "cc.CCVisibleAction";
    g_typeCast["CCVisibleAction"] = "cc.CCVisibleAction";
    return 1;
}

int lua_cocos2dx_game_cocos_extention_CCRemoveAction_startWithTarget(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCRemoveAction* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCRemoveAction",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCRemoveAction*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_game_cocos_extention_CCRemoveAction_startWithTarget'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Node* arg0;

        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_game_cocos_extention_CCRemoveAction_startWithTarget'", nullptr);
            return 0;
        }
        cobj->startWithTarget(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.CCRemoveAction:startWithTarget",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_game_cocos_extention_CCRemoveAction_startWithTarget'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_game_cocos_extention_CCRemoveAction_reverse(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCRemoveAction* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCRemoveAction",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocos2d::CCRemoveAction*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_game_cocos_extention_CCRemoveAction_reverse'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 0) {
			cocos2d::CCRemoveAction* ret = (cocos2d::CCRemoveAction*)cobj->reverse();
            object_to_luaval<cocos2d::CCRemoveAction>(tolua_S, "cc.CCRemoveAction",(cocos2d::CCRemoveAction*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            cocos2d::ActionInterval* ret = cobj->reverse();
            object_to_luaval<cocos2d::ActionInterval>(tolua_S, "cc.ActionInterval",(cocos2d::ActionInterval*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "cc.CCRemoveAction:reverse",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_game_cocos_extention_CCRemoveAction_reverse'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_game_cocos_extention_CCRemoveAction_initWithDuration(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCRemoveAction* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCRemoveAction",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCRemoveAction*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_game_cocos_extention_CCRemoveAction_initWithDuration'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "cc.CCRemoveAction:initWithDuration");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_game_cocos_extention_CCRemoveAction_initWithDuration'", nullptr);
            return 0;
        }
        bool ret = cobj->initWithDuration(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.CCRemoveAction:initWithDuration",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_game_cocos_extention_CCRemoveAction_initWithDuration'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_game_cocos_extention_CCRemoveAction_clone(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCRemoveAction* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCRemoveAction",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCRemoveAction*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_game_cocos_extention_CCRemoveAction_clone'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_game_cocos_extention_CCRemoveAction_clone'", nullptr);
            return 0;
        }
        cocos2d::CCRemoveAction* ret = cobj->clone();
        object_to_luaval<cocos2d::CCRemoveAction>(tolua_S, "cc.CCRemoveAction",(cocos2d::CCRemoveAction*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.CCRemoveAction:clone",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_game_cocos_extention_CCRemoveAction_clone'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_game_cocos_extention_CCRemoveAction_stop(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCRemoveAction* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCRemoveAction",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCRemoveAction*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_game_cocos_extention_CCRemoveAction_stop'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_game_cocos_extention_CCRemoveAction_stop'", nullptr);
            return 0;
        }
        cobj->stop();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.CCRemoveAction:stop",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_game_cocos_extention_CCRemoveAction_stop'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_game_cocos_extention_CCRemoveAction_update(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCRemoveAction* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCRemoveAction",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCRemoveAction*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_game_cocos_extention_CCRemoveAction_update'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "cc.CCRemoveAction:update");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_game_cocos_extention_CCRemoveAction_update'", nullptr);
            return 0;
        }
        cobj->update(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.CCRemoveAction:update",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_game_cocos_extention_CCRemoveAction_update'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_game_cocos_extention_CCRemoveAction_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.CCRemoveAction",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        double arg0;
        ok &= luaval_to_number(tolua_S, 2,&arg0, "cc.CCRemoveAction:create");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_game_cocos_extention_CCRemoveAction_create'", nullptr);
            return 0;
        }
        cocos2d::CCRemoveAction* ret = cocos2d::CCRemoveAction::create(arg0);
        object_to_luaval<cocos2d::CCRemoveAction>(tolua_S, "cc.CCRemoveAction",(cocos2d::CCRemoveAction*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.CCRemoveAction:create",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_game_cocos_extention_CCRemoveAction_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_game_cocos_extention_CCRemoveAction_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CCRemoveAction)");
    return 0;
}

int lua_register_cocos2dx_game_cocos_extention_CCRemoveAction(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.CCRemoveAction");
    tolua_cclass(tolua_S,"CCRemoveAction","cc.CCRemoveAction","cc.ActionInterval",nullptr);

    tolua_beginmodule(tolua_S,"CCRemoveAction");
        tolua_function(tolua_S,"startWithTarget",lua_cocos2dx_game_cocos_extention_CCRemoveAction_startWithTarget);
        tolua_function(tolua_S,"reverse",lua_cocos2dx_game_cocos_extention_CCRemoveAction_reverse);
        tolua_function(tolua_S,"initWithDuration",lua_cocos2dx_game_cocos_extention_CCRemoveAction_initWithDuration);
        tolua_function(tolua_S,"clone",lua_cocos2dx_game_cocos_extention_CCRemoveAction_clone);
        tolua_function(tolua_S,"stop",lua_cocos2dx_game_cocos_extention_CCRemoveAction_stop);
        tolua_function(tolua_S,"update",lua_cocos2dx_game_cocos_extention_CCRemoveAction_update);
        tolua_function(tolua_S,"create", lua_cocos2dx_game_cocos_extention_CCRemoveAction_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::CCRemoveAction).name();
    g_luaType[typeName] = "cc.CCRemoveAction";
    g_typeCast["CCRemoveAction"] = "cc.CCRemoveAction";
    return 1;
}

int lua_cocos2dx_game_cocos_extention_CCTire_startWithTarget(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCTire* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCTire",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCTire*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_game_cocos_extention_CCTire_startWithTarget'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Node* arg0;

        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_game_cocos_extention_CCTire_startWithTarget'", nullptr);
            return 0;
        }
        cobj->startWithTarget(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.CCTire:startWithTarget",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_game_cocos_extention_CCTire_startWithTarget'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_game_cocos_extention_CCTire_reverse(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCTire* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCTire",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocos2d::CCTire*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_game_cocos_extention_CCTire_reverse'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 0) {
			cocos2d::CCTire* ret = (cocos2d::CCTire*)cobj->reverse();
            object_to_luaval<cocos2d::CCTire>(tolua_S, "cc.CCTire",(cocos2d::CCTire*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            cocos2d::ActionInterval* ret = cobj->reverse();
            object_to_luaval<cocos2d::ActionInterval>(tolua_S, "cc.ActionInterval",(cocos2d::ActionInterval*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "cc.CCTire:reverse",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_game_cocos_extention_CCTire_reverse'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_game_cocos_extention_CCTire_initWithDuration(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCTire* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCTire",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCTire*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_game_cocos_extention_CCTire_initWithDuration'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        double arg0;
        std::string arg1;
        cocos2d::Node* arg2;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "cc.CCTire:initWithDuration");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "cc.CCTire:initWithDuration");

        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 4, "cc.Node",&arg2);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_game_cocos_extention_CCTire_initWithDuration'", nullptr);
            return 0;
        }
        bool ret = cobj->initWithDuration(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.CCTire:initWithDuration",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_game_cocos_extention_CCTire_initWithDuration'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_game_cocos_extention_CCTire_clone(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCTire* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCTire",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCTire*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_game_cocos_extention_CCTire_clone'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_game_cocos_extention_CCTire_clone'", nullptr);
            return 0;
        }
        cocos2d::CCTire* ret = cobj->clone();
        object_to_luaval<cocos2d::CCTire>(tolua_S, "cc.CCTire",(cocos2d::CCTire*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.CCTire:clone",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_game_cocos_extention_CCTire_clone'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_game_cocos_extention_CCTire_stop(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCTire* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCTire",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCTire*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_game_cocos_extention_CCTire_stop'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_game_cocos_extention_CCTire_stop'", nullptr);
            return 0;
        }
        cobj->stop();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.CCTire:stop",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_game_cocos_extention_CCTire_stop'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_game_cocos_extention_CCTire_update(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCTire* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCTire",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCTire*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_game_cocos_extention_CCTire_update'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "cc.CCTire:update");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_game_cocos_extention_CCTire_update'", nullptr);
            return 0;
        }
        cobj->update(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.CCTire:update",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_game_cocos_extention_CCTire_update'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_game_cocos_extention_CCTire_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.CCTire",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 3)
    {
        double arg0;
        std::string arg1;
        cocos2d::Node* arg2;
        ok &= luaval_to_number(tolua_S, 2,&arg0, "cc.CCTire:create");
        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "cc.CCTire:create");
        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 4, "cc.Node",&arg2);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_game_cocos_extention_CCTire_create'", nullptr);
            return 0;
        }
        cocos2d::CCTire* ret = cocos2d::CCTire::create(arg0, arg1, arg2);
        object_to_luaval<cocos2d::CCTire>(tolua_S, "cc.CCTire",(cocos2d::CCTire*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.CCTire:create",argc, 3);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_game_cocos_extention_CCTire_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_game_cocos_extention_CCTire_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CCTire)");
    return 0;
}

int lua_register_cocos2dx_game_cocos_extention_CCTire(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.CCTire");
    tolua_cclass(tolua_S,"CCTire","cc.CCTire","cc.ActionInterval",nullptr);

    tolua_beginmodule(tolua_S,"CCTire");
        tolua_function(tolua_S,"startWithTarget",lua_cocos2dx_game_cocos_extention_CCTire_startWithTarget);
        tolua_function(tolua_S,"reverse",lua_cocos2dx_game_cocos_extention_CCTire_reverse);
        tolua_function(tolua_S,"initWithDuration",lua_cocos2dx_game_cocos_extention_CCTire_initWithDuration);
        tolua_function(tolua_S,"clone",lua_cocos2dx_game_cocos_extention_CCTire_clone);
        tolua_function(tolua_S,"stop",lua_cocos2dx_game_cocos_extention_CCTire_stop);
        tolua_function(tolua_S,"update",lua_cocos2dx_game_cocos_extention_CCTire_update);
        tolua_function(tolua_S,"create", lua_cocos2dx_game_cocos_extention_CCTire_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::CCTire).name();
    g_luaType[typeName] = "cc.CCTire";
    g_typeCast["CCTire"] = "cc.CCTire";
    return 1;
}

int lua_cocos2dx_game_cocos_extention_CCAutoRotation_update(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCAutoRotation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCAutoRotation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCAutoRotation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_game_cocos_extention_CCAutoRotation_update'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "cc.CCAutoRotation:update");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_game_cocos_extention_CCAutoRotation_update'", nullptr);
            return 0;
        }
        cobj->update(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.CCAutoRotation:update",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_game_cocos_extention_CCAutoRotation_update'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_game_cocos_extention_CCAutoRotation_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.CCAutoRotation",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_game_cocos_extention_CCAutoRotation_create'", nullptr);
            return 0;
        }
        cocos2d::CCAutoRotation* ret = cocos2d::CCAutoRotation::create();
        object_to_luaval<cocos2d::CCAutoRotation>(tolua_S, "cc.CCAutoRotation",(cocos2d::CCAutoRotation*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.CCAutoRotation:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_game_cocos_extention_CCAutoRotation_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_game_cocos_extention_CCAutoRotation_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CCAutoRotation)");
    return 0;
}

int lua_register_cocos2dx_game_cocos_extention_CCAutoRotation(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.CCAutoRotation");
    tolua_cclass(tolua_S,"CCAutoRotation","cc.CCAutoRotation","cc.ActionInterval",nullptr);

    tolua_beginmodule(tolua_S,"CCAutoRotation");
        tolua_function(tolua_S,"update",lua_cocos2dx_game_cocos_extention_CCAutoRotation_update);
        tolua_function(tolua_S,"create", lua_cocos2dx_game_cocos_extention_CCAutoRotation_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::CCAutoRotation).name();
    g_luaType[typeName] = "cc.CCAutoRotation";
    g_typeCast["CCAutoRotation"] = "cc.CCAutoRotation";
    return 1;
}

int lua_cocos2dx_game_cocos_extention_MoveToEx_setDestPos(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::MoveToEx* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.MoveToEx",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::MoveToEx*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_game_cocos_extention_MoveToEx_setDestPos'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Point arg0;

        ok &= luaval_to_point(tolua_S, 2, &arg0, "cc.MoveToEx:setDestPos");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_game_cocos_extention_MoveToEx_setDestPos'", nullptr);
            return 0;
        }
        cobj->setDestPos(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.MoveToEx:setDestPos",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_game_cocos_extention_MoveToEx_setDestPos'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_game_cocos_extention_MoveToEx_setCallFun(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::MoveToEx* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.MoveToEx",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::MoveToEx*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_game_cocos_extention_MoveToEx_setCallFun'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::function<void (const cocos2d::Vec2 &)> arg0;

        do {
			// Lambda binding for lua is not supported.
			assert(false);
		} while(0)
		;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_game_cocos_extention_MoveToEx_setCallFun'", nullptr);
            return 0;
        }
        cobj->setCallFun(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.MoveToEx:setCallFun",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_game_cocos_extention_MoveToEx_setCallFun'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_game_cocos_extention_MoveToEx_setDest(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::MoveToEx* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.MoveToEx",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::MoveToEx*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_game_cocos_extention_MoveToEx_setDest'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        NodeEx* arg0;
        cocos2d::Point arg1;

        ok &= luaval_to_object<NodeEx>(tolua_S, 2, "NodeEx",&arg0);

        ok &= luaval_to_point(tolua_S, 3, &arg1, "cc.MoveToEx:setDest");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_game_cocos_extention_MoveToEx_setDest'", nullptr);
            return 0;
        }
        cobj->setDest(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.MoveToEx:setDest",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_game_cocos_extention_MoveToEx_setDest'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_game_cocos_extention_MoveToEx_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.MoveToEx",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        double arg0;
        cocos2d::Point arg1;
        ok &= luaval_to_number(tolua_S, 2,&arg0, "cc.MoveToEx:create");
        ok &= luaval_to_point(tolua_S, 3, &arg1, "cc.MoveToEx:create");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_game_cocos_extention_MoveToEx_create'", nullptr);
            return 0;
        }
        cocos2d::MoveToEx* ret = cocos2d::MoveToEx::create(arg0, arg1);
        object_to_luaval<cocos2d::MoveToEx>(tolua_S, "cc.MoveToEx",(cocos2d::MoveToEx*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.MoveToEx:create",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_game_cocos_extention_MoveToEx_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_game_cocos_extention_MoveToEx_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (MoveToEx)");
    return 0;
}

int lua_register_cocos2dx_game_cocos_extention_MoveToEx(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.MoveToEx");
    tolua_cclass(tolua_S,"MoveToEx","cc.MoveToEx","cc.ActionInterval",nullptr);

    tolua_beginmodule(tolua_S,"MoveToEx");
        tolua_function(tolua_S,"setDestPos",lua_cocos2dx_game_cocos_extention_MoveToEx_setDestPos);
        tolua_function(tolua_S,"setCallFun",lua_cocos2dx_game_cocos_extention_MoveToEx_setCallFun);
        tolua_function(tolua_S,"setDest",lua_cocos2dx_game_cocos_extention_MoveToEx_setDest);
        tolua_function(tolua_S,"create", lua_cocos2dx_game_cocos_extention_MoveToEx_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::MoveToEx).name();
    g_luaType[typeName] = "cc.MoveToEx";
    g_typeCast["MoveToEx"] = "cc.MoveToEx";
    return 1;
}

int lua_cocos2dx_game_cocos_extention_BlurTo_setDestBlur(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::BlurTo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.BlurTo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::BlurTo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_game_cocos_extention_BlurTo_setDestBlur'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "cc.BlurTo:setDestBlur");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_game_cocos_extention_BlurTo_setDestBlur'", nullptr);
            return 0;
        }
        cobj->setDestBlur(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.BlurTo:setDestBlur",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_game_cocos_extention_BlurTo_setDestBlur'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_game_cocos_extention_BlurTo_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.BlurTo",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        double arg0;
        double arg1;
        ok &= luaval_to_number(tolua_S, 2,&arg0, "cc.BlurTo:create");
        ok &= luaval_to_number(tolua_S, 3,&arg1, "cc.BlurTo:create");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_game_cocos_extention_BlurTo_create'", nullptr);
            return 0;
        }
        cocos2d::BlurTo* ret = cocos2d::BlurTo::create(arg0, arg1);
        object_to_luaval<cocos2d::BlurTo>(tolua_S, "cc.BlurTo",(cocos2d::BlurTo*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.BlurTo:create",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_game_cocos_extention_BlurTo_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_game_cocos_extention_BlurTo_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (BlurTo)");
    return 0;
}

int lua_register_cocos2dx_game_cocos_extention_BlurTo(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.BlurTo");
    tolua_cclass(tolua_S,"BlurTo","cc.BlurTo","cc.ActionInterval",nullptr);

    tolua_beginmodule(tolua_S,"BlurTo");
        tolua_function(tolua_S,"setDestBlur",lua_cocos2dx_game_cocos_extention_BlurTo_setDestBlur);
        tolua_function(tolua_S,"create", lua_cocos2dx_game_cocos_extention_BlurTo_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::BlurTo).name();
    g_luaType[typeName] = "cc.BlurTo";
    g_typeCast["BlurTo"] = "cc.BlurTo";
    return 1;
}

int lua_cocos2dx_game_cocos_extention_SizeTo_setSize(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::SizeTo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.SizeTo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::SizeTo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_game_cocos_extention_SizeTo_setSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Size arg0;

        ok &= luaval_to_size(tolua_S, 2, &arg0, "cc.SizeTo:setSize");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_game_cocos_extention_SizeTo_setSize'", nullptr);
            return 0;
        }
        cobj->setSize(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.SizeTo:setSize",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_game_cocos_extention_SizeTo_setSize'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_game_cocos_extention_SizeTo_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.SizeTo",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        double arg0;
        cocos2d::Size arg1;
        ok &= luaval_to_number(tolua_S, 2,&arg0, "cc.SizeTo:create");
        ok &= luaval_to_size(tolua_S, 3, &arg1, "cc.SizeTo:create");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_game_cocos_extention_SizeTo_create'", nullptr);
            return 0;
        }
        cocos2d::SizeTo* ret = cocos2d::SizeTo::create(arg0, arg1);
        object_to_luaval<cocos2d::SizeTo>(tolua_S, "cc.SizeTo",(cocos2d::SizeTo*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.SizeTo:create",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_game_cocos_extention_SizeTo_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_game_cocos_extention_SizeTo_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (SizeTo)");
    return 0;
}

int lua_register_cocos2dx_game_cocos_extention_SizeTo(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.SizeTo");
    tolua_cclass(tolua_S,"SizeTo","cc.SizeTo","cc.ActionInterval",nullptr);

    tolua_beginmodule(tolua_S,"SizeTo");
        tolua_function(tolua_S,"setSize",lua_cocos2dx_game_cocos_extention_SizeTo_setSize);
        tolua_function(tolua_S,"create", lua_cocos2dx_game_cocos_extention_SizeTo_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::SizeTo).name();
    g_luaType[typeName] = "cc.SizeTo";
    g_typeCast["SizeTo"] = "cc.SizeTo";
    return 1;
}

int lua_cocos2dx_game_cocos_extention_GravityAction_setGravity(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::GravityAction* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.GravityAction",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::GravityAction*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_game_cocos_extention_GravityAction_setGravity'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "cc.GravityAction:setGravity");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_game_cocos_extention_GravityAction_setGravity'", nullptr);
            return 0;
        }
        cobj->setGravity(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.GravityAction:setGravity",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_game_cocos_extention_GravityAction_setGravity'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_game_cocos_extention_GravityAction_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.GravityAction",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        double arg0;
        double arg1;
        ok &= luaval_to_number(tolua_S, 2,&arg0, "cc.GravityAction:create");
        ok &= luaval_to_number(tolua_S, 3,&arg1, "cc.GravityAction:create");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_game_cocos_extention_GravityAction_create'", nullptr);
            return 0;
        }
        cocos2d::GravityAction* ret = cocos2d::GravityAction::create(arg0, arg1);
        object_to_luaval<cocos2d::GravityAction>(tolua_S, "cc.GravityAction",(cocos2d::GravityAction*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.GravityAction:create",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_game_cocos_extention_GravityAction_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_game_cocos_extention_GravityAction_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::GravityAction* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_game_cocos_extention_GravityAction_constructor'", nullptr);
            return 0;
        }
        cobj = new cocos2d::GravityAction();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.GravityAction");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.GravityAction:GravityAction",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_game_cocos_extention_GravityAction_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_game_cocos_extention_GravityAction_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (GravityAction)");
    return 0;
}

int lua_register_cocos2dx_game_cocos_extention_GravityAction(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.GravityAction");
    tolua_cclass(tolua_S,"GravityAction","cc.GravityAction","cc.ActionInterval",nullptr);

    tolua_beginmodule(tolua_S,"GravityAction");
        tolua_function(tolua_S,"new",lua_cocos2dx_game_cocos_extention_GravityAction_constructor);
        tolua_function(tolua_S,"setGravity",lua_cocos2dx_game_cocos_extention_GravityAction_setGravity);
        tolua_function(tolua_S,"create", lua_cocos2dx_game_cocos_extention_GravityAction_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::GravityAction).name();
    g_luaType[typeName] = "cc.GravityAction";
    g_typeCast["GravityAction"] = "cc.GravityAction";
    return 1;
}

int lua_cocos2dx_game_NewCurl_HttpPost(lua_State* tolua_S)
{
	int argc = 0;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertable(tolua_S, 1, "NewCurl", 0, &tolua_err)) goto tolua_lerror;
#endif

	argc = lua_gettop(tolua_S) - 1;

	if (argc == 2)
	{
		std::string arg0;
		std::string arg1;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, "NewCurl:HttpPost");
		ok &= luaval_to_std_string(tolua_S, 3, &arg1, "NewCurl:HttpPost");
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_cocos2dx_game_NewCurl_HttpPost'", nullptr);
			return 0;
		}
		std::string ret = NewCurl::HttpPost(arg0, arg1);
		tolua_pushcppstring(tolua_S, ret);
		return 1;
	}
	if (argc == 3)
	{
		std::string arg0;
		std::string arg1;
		int arg2;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, "NewCurl:HttpPost");
		ok &= luaval_to_std_string(tolua_S, 3, &arg1, "NewCurl:HttpPost");
		ok &= luaval_to_int32(tolua_S, 4, (int *)&arg2, "NewCurl:HttpPost");
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_cocos2dx_game_NewCurl_HttpPost'", nullptr);
			return 0;
		}
		std::string ret = NewCurl::HttpPost(arg0, arg1, arg2);
		tolua_pushcppstring(tolua_S, ret);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "NewCurl:HttpPost", argc, 2);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_cocos2dx_game_NewCurl_HttpPost'.", &tolua_err);
#endif
	return 0;
}
int lua_cocos2dx_game_NewCurl_constructor(lua_State* tolua_S)
{
	int argc = 0;
	NewCurl* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif



	argc = lua_gettop(tolua_S) - 1;
	if (argc == 0)
	{
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_cocos2dx_game_NewCurl_constructor'", nullptr);
			return 0;
		}
		cobj = new NewCurl();
		tolua_pushusertype(tolua_S, (void*)cobj, "NewCurl");
		tolua_register_gc(tolua_S, lua_gettop(tolua_S));
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "NewCurl:NewCurl", argc, 0);
	return 0;

#if COCOS2D_DEBUG >= 1
	tolua_error(tolua_S, "#ferror in function 'lua_cocos2dx_game_NewCurl_constructor'.", &tolua_err);
#endif

	return 0;
}

static int lua_cocos2dx_game_NewCurl_finalize(lua_State* tolua_S)
{
	printf("luabindings: finalizing LUA object (NewCurl)");
	return 0;
}

int lua_register_cocos2dx_game_NewCurl(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "NewCurl");
	tolua_cclass(tolua_S, "NewCurl", "NewCurl", "", nullptr);

	tolua_beginmodule(tolua_S, "NewCurl");
	tolua_function(tolua_S, "new", lua_cocos2dx_game_NewCurl_constructor);
	tolua_function(tolua_S, "HttpPost", lua_cocos2dx_game_NewCurl_HttpPost);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(NewCurl).name();
	g_luaType[typeName] = "NewCurl";
	g_typeCast["NewCurl"] = "NewCurl";
	return 1;
}

TOLUA_API int register_all_cocos2dx_game_cocos_extention(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"cc",0);
	tolua_beginmodule(tolua_S,"cc");
	lua_register_cocos2dx_game_cocos_extention_CCVisibleAction(tolua_S);
	lua_register_cocos2dx_game_cocos_extention_CCTire(tolua_S);
	lua_register_cocos2dx_game_cocos_extention_MoveExTxtTime(tolua_S);
	lua_register_cocos2dx_game_cocos_extention_MoveToEx(tolua_S);
	lua_register_cocos2dx_game_cocos_extention_BlurTo(tolua_S);
	lua_register_cocos2dx_game_cocos_extention_GravityAction(tolua_S);
	lua_register_cocos2dx_game_cocos_extention_SizeTo(tolua_S);
	lua_register_cocos2dx_game_cocos_extention_CCRemoveAction(tolua_S);
	lua_register_cocos2dx_game_cocos_extention_CCAutoRotation(tolua_S);
	lua_register_cocos2dx_game_NewCurl(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

#endif
