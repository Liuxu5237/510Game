#include "lua_cocos2dx_kernel_auto.hpp"
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC || CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
#include "kernel/network/CSocketMission.h"
#include "kernel/gameCenter/GameCenterManager.h"
#include "kernel/server/CServerItem.h"
#include "kernel/server/IServerItem.h"
#include "kernel/user/IClientUserItem.h"
#include "kernel/game/IClientKernel.h"
#include "kernel/game/CGameScene.h"
#include "kernel/game/GameTouchScene.h"
#include "script/SoundFun.h"
#include "kernel/game/IGameTouchSink.h"
#include "kernel/user/ClientUserManager.h"
#include "kernel/game/CGameFrameEngine.h"
#include "kernel/network/ISocketSink.h"
#include "kernel/network/CSocketEngine.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"

int lua_cocos2dx_kernel_ISocketEngine_isAlive(lua_State* tolua_S)
{
    int argc = 0;
    ISocketEngine* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ISocketEngine",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ISocketEngine*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_ISocketEngine_isAlive'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_ISocketEngine_isAlive'", nullptr);
            return 0;
        }
        bool ret = cobj->isAlive();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ISocketEngine:isAlive",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_ISocketEngine_isAlive'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_ISocketEngine_setTCPValidate(lua_State* tolua_S)
{
    int argc = 0;
    ISocketEngine* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ISocketEngine",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ISocketEngine*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_ISocketEngine_setTCPValidate'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "ISocketEngine:setTCPValidate");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_ISocketEngine_setTCPValidate'", nullptr);
            return 0;
        }
        cobj->setTCPValidate(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ISocketEngine:setTCPValidate",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_ISocketEngine_setTCPValidate'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_ISocketEngine_send(lua_State* tolua_S)
{
    int argc = 0;
    ISocketEngine* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ISocketEngine",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ISocketEngine*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_ISocketEngine_send'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 4) 
    {
        int arg0;
        int arg1;
        const char* arg2;
        int arg3;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "ISocketEngine:send");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "ISocketEngine:send");

        std::string arg2_tmp; ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp, "ISocketEngine:send"); arg2 = arg2_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3, "ISocketEngine:send");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_ISocketEngine_send'", nullptr);
            return 0;
        }
        bool ret = cobj->send(arg0, arg1, arg2, arg3);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ISocketEngine:send",argc, 4);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_ISocketEngine_send'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_ISocketEngine_connect(lua_State* tolua_S)
{
    int argc = 0;
    ISocketEngine* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ISocketEngine",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ISocketEngine*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_ISocketEngine_connect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        int arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "ISocketEngine:connect"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "ISocketEngine:connect");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_ISocketEngine_connect'", nullptr);
            return 0;
        }
        bool ret = cobj->connect(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ISocketEngine:connect",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_ISocketEngine_connect'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_ISocketEngine_disconnect(lua_State* tolua_S)
{
    int argc = 0;
    ISocketEngine* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ISocketEngine",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ISocketEngine*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_ISocketEngine_disconnect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_ISocketEngine_disconnect'", nullptr);
            return 0;
        }
        bool ret = cobj->disconnect();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ISocketEngine:disconnect",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_ISocketEngine_disconnect'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_ISocketEngine_setSocketEngineSink(lua_State* tolua_S)
{
    int argc = 0;
    ISocketEngine* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ISocketEngine",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ISocketEngine*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_ISocketEngine_setSocketEngineSink'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        ISocketEngineSink* arg0;

        ok &= luaval_to_object<ISocketEngineSink>(tolua_S, 2, "ISocketEngineSink",&arg0, "ISocketEngine:setSocketEngineSink");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_ISocketEngine_setSocketEngineSink'", nullptr);
            return 0;
        }
        cobj->setSocketEngineSink(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ISocketEngine:setSocketEngineSink",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_ISocketEngine_setSocketEngineSink'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_ISocketEngine_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ISocketEngine",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_ISocketEngine_create'", nullptr);
            return 0;
        }
        ISocketEngine* ret = ISocketEngine::create();
        object_to_luaval<ISocketEngine>(tolua_S, "ISocketEngine",(ISocketEngine*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "ISocketEngine:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_ISocketEngine_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_kernel_ISocketEngine_destory(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ISocketEngine",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        ISocketEngine* arg0;
        ok &= luaval_to_object<ISocketEngine>(tolua_S, 2, "ISocketEngine",&arg0, "ISocketEngine:destory");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_ISocketEngine_destory'", nullptr);
            return 0;
        }
        ISocketEngine::destory(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "ISocketEngine:destory",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_ISocketEngine_destory'.",&tolua_err);
#endif
    return 0;
}

static int lua_cocos2dx_kernel_ISocketEngine_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ISocketEngine)");
    return 0;
}

int lua_register_cocos2dx_kernel_ISocketEngine(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"ISocketEngine");
    tolua_cclass(tolua_S,"ISocketEngine","ISocketEngine","",nullptr);

    tolua_beginmodule(tolua_S,"ISocketEngine");
        tolua_function(tolua_S,"isAlive",lua_cocos2dx_kernel_ISocketEngine_isAlive);
        tolua_function(tolua_S,"setTCPValidate",lua_cocos2dx_kernel_ISocketEngine_setTCPValidate);
        tolua_function(tolua_S,"send",lua_cocos2dx_kernel_ISocketEngine_send);
        tolua_function(tolua_S,"connect",lua_cocos2dx_kernel_ISocketEngine_connect);
        tolua_function(tolua_S,"disconnect",lua_cocos2dx_kernel_ISocketEngine_disconnect);
        tolua_function(tolua_S,"setSocketEngineSink",lua_cocos2dx_kernel_ISocketEngine_setSocketEngineSink);
        tolua_function(tolua_S,"create", lua_cocos2dx_kernel_ISocketEngine_create);
        tolua_function(tolua_S,"destory", lua_cocos2dx_kernel_ISocketEngine_destory);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(ISocketEngine).name();
    g_luaType[typeName] = "ISocketEngine";
    g_typeCast["ISocketEngine"] = "ISocketEngine";
    return 1;
}

int lua_cocos2dx_kernel_ISocketEngineSink_onEventTCPSocketError(lua_State* tolua_S)
{
    int argc = 0;
    ISocketEngineSink* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ISocketEngineSink",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ISocketEngineSink*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_ISocketEngineSink_onEventTCPSocketError'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "ISocketEngineSink:onEventTCPSocketError");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_ISocketEngineSink_onEventTCPSocketError'", nullptr);
            return 0;
        }
        cobj->onEventTCPSocketError(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ISocketEngineSink:onEventTCPSocketError",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_ISocketEngineSink_onEventTCPSocketError'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_ISocketEngineSink_onEventTCPSocketShut(lua_State* tolua_S)
{
    int argc = 0;
    ISocketEngineSink* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ISocketEngineSink",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ISocketEngineSink*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_ISocketEngineSink_onEventTCPSocketShut'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_ISocketEngineSink_onEventTCPSocketShut'", nullptr);
            return 0;
        }
        cobj->onEventTCPSocketShut();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ISocketEngineSink:onEventTCPSocketShut",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_ISocketEngineSink_onEventTCPSocketShut'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_ISocketEngineSink_onEventTCPSocketLink(lua_State* tolua_S)
{
    int argc = 0;
    ISocketEngineSink* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ISocketEngineSink",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ISocketEngineSink*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_ISocketEngineSink_onEventTCPSocketLink'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_ISocketEngineSink_onEventTCPSocketLink'", nullptr);
            return 0;
        }
        cobj->onEventTCPSocketLink();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ISocketEngineSink:onEventTCPSocketLink",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_ISocketEngineSink_onEventTCPSocketLink'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_ISocketEngineSink_onEventTCPSocketRead(lua_State* tolua_S)
{
    int argc = 0;
    ISocketEngineSink* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ISocketEngineSink",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ISocketEngineSink*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_ISocketEngineSink_onEventTCPSocketRead'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 4) 
    {
        int arg0;
        int arg1;
        char* arg2;
        int arg3;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "ISocketEngineSink:onEventTCPSocketRead");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "ISocketEngineSink:onEventTCPSocketRead");

        std::string arg2_tmp; ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp, "ISocketEngineSink:onEventTCPSocketRead"); arg2 = const_cast<char*>(arg2_tmp.c_str());

        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3, "ISocketEngineSink:onEventTCPSocketRead");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_ISocketEngineSink_onEventTCPSocketRead'", nullptr);
            return 0;
        }
        bool ret = cobj->onEventTCPSocketRead(arg0, arg1, arg2, arg3);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ISocketEngineSink:onEventTCPSocketRead",argc, 4);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_ISocketEngineSink_onEventTCPSocketRead'.",&tolua_err);
#endif

    return 0;
}
static int lua_cocos2dx_kernel_ISocketEngineSink_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ISocketEngineSink)");
    return 0;
}

int lua_register_cocos2dx_kernel_ISocketEngineSink(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"ISocketEngineSink");
    tolua_cclass(tolua_S,"ISocketEngineSink","ISocketEngineSink","",nullptr);

    tolua_beginmodule(tolua_S,"ISocketEngineSink");
        tolua_function(tolua_S,"onEventTCPSocketError",lua_cocos2dx_kernel_ISocketEngineSink_onEventTCPSocketError);
        tolua_function(tolua_S,"onEventTCPSocketShut",lua_cocos2dx_kernel_ISocketEngineSink_onEventTCPSocketShut);
        tolua_function(tolua_S,"onEventTCPSocketLink",lua_cocos2dx_kernel_ISocketEngineSink_onEventTCPSocketLink);
        tolua_function(tolua_S,"onEventTCPSocketRead",lua_cocos2dx_kernel_ISocketEngineSink_onEventTCPSocketRead);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(ISocketEngineSink).name();
    g_luaType[typeName] = "ISocketEngineSink";
    g_typeCast["ISocketEngineSink"] = "ISocketEngineSink";
    return 1;
}

int lua_cocos2dx_kernel_CSocketMission_setLinkSuccLuaCallBack(lua_State* tolua_S)
{
    int argc = 0;
    CSocketMission* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CSocketMission",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CSocketMission*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CSocketMission_setLinkSuccLuaCallBack'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "CSocketMission:setLinkSuccLuaCallBack");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CSocketMission_setLinkSuccLuaCallBack'", nullptr);
            return 0;
        }
        cobj->setLinkSuccLuaCallBack(std::move(arg0));
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CSocketMission:setLinkSuccLuaCallBack",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CSocketMission_setLinkSuccLuaCallBack'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CSocketMission_isAlive(lua_State* tolua_S)
{
    int argc = 0;
    CSocketMission* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CSocketMission",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CSocketMission*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CSocketMission_isAlive'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CSocketMission_isAlive'", nullptr);
            return 0;
        }
        bool ret = cobj->isAlive();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CSocketMission:isAlive",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CSocketMission_isAlive'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CSocketMission_stop(lua_State* tolua_S)
{
    int argc = 0;
    CSocketMission* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CSocketMission",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CSocketMission*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CSocketMission_stop'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CSocketMission_stop'", nullptr);
            return 0;
        }
        cobj->stop();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CSocketMission:stop",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CSocketMission_stop'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CSocketMission_setUrl(lua_State* tolua_S)
{
    int argc = 0;
    CSocketMission* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CSocketMission",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CSocketMission*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CSocketMission_setUrl'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        int arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "CSocketMission:setUrl");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "CSocketMission:setUrl");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CSocketMission_setUrl'", nullptr);
            return 0;
        }
        cobj->setUrl(std::move(arg0), arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CSocketMission:setUrl",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CSocketMission_setUrl'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CSocketMission_send(lua_State* tolua_S)
{
    int argc = 0;
    CSocketMission* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CSocketMission",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CSocketMission*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CSocketMission_send'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 4) {
            int arg0;
            ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "CSocketMission:send");

            if (!ok) { break; }
            int arg1;
            ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "CSocketMission:send");

            if (!ok) { break; }
            const cocos2d::Ref* arg2;
            ok &= luaval_to_object<const cocos2d::Ref>(tolua_S, 4, "cc.Ref",&arg2, "CSocketMission:send");

            if (!ok) { break; }
            int arg3;
            ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3, "CSocketMission:send");

            if (!ok) { break; }
            bool ret = cobj->send(arg0, arg1, arg2, arg3);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 2) {
            int arg0;
            ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "CSocketMission:send");

            if (!ok) { break; }
            int arg1;
            ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "CSocketMission:send");

            if (!ok) { break; }
            bool ret = cobj->send(arg0, arg1);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CSocketMission:send",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CSocketMission_send'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CSocketMission_start(lua_State* tolua_S)
{
    int argc = 0;
    CSocketMission* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CSocketMission",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CSocketMission*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CSocketMission_start'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CSocketMission_start'", nullptr);
            return 0;
        }
        cobj->start();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CSocketMission:start",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CSocketMission_start'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CSocketMission_setLinkErrorLuaCallBack(lua_State* tolua_S)
{
    int argc = 0;
    CSocketMission* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CSocketMission",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CSocketMission*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CSocketMission_setLinkErrorLuaCallBack'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "CSocketMission:setLinkErrorLuaCallBack");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CSocketMission_setLinkErrorLuaCallBack'", nullptr);
            return 0;
        }
        cobj->setLinkErrorLuaCallBack(std::move(arg0));
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CSocketMission:setLinkErrorLuaCallBack",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CSocketMission_setLinkErrorLuaCallBack'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CSocketMission_setLinkDownLuaCallBack(lua_State* tolua_S)
{
    int argc = 0;
    CSocketMission* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CSocketMission",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CSocketMission*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CSocketMission_setLinkDownLuaCallBack'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "CSocketMission:setLinkDownLuaCallBack");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CSocketMission_setLinkDownLuaCallBack'", nullptr);
            return 0;
        }
        cobj->setLinkDownLuaCallBack(std::move(arg0));
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CSocketMission:setLinkDownLuaCallBack",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CSocketMission_setLinkDownLuaCallBack'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CSocketMission_setLinkDataLuaCallBack(lua_State* tolua_S)
{
    int argc = 0;
    CSocketMission* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CSocketMission",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CSocketMission*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CSocketMission_setLinkDataLuaCallBack'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "CSocketMission:setLinkDataLuaCallBack");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CSocketMission_setLinkDataLuaCallBack'", nullptr);
            return 0;
        }
        cobj->setLinkDataLuaCallBack(std::move(arg0));
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CSocketMission:setLinkDataLuaCallBack",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CSocketMission_setLinkDataLuaCallBack'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CSocketMission_Instance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CSocketMission",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CSocketMission_Instance'", nullptr);
            return 0;
        }
        CSocketMission* ret = CSocketMission::Instance();
        object_to_luaval<CSocketMission>(tolua_S, "CSocketMission",(CSocketMission*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CSocketMission:Instance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CSocketMission_Instance'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_kernel_CSocketMission_Destroy(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CSocketMission",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        CSocketMission* arg0;
        ok &= luaval_to_object<CSocketMission>(tolua_S, 2, "CSocketMission",&arg0, "CSocketMission:Destroy");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CSocketMission_Destroy'", nullptr);
            return 0;
        }
        CSocketMission::Destroy(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CSocketMission:Destroy",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CSocketMission_Destroy'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_kernel_CSocketMission_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CSocketMission)");
    return 0;
}

int lua_register_cocos2dx_kernel_CSocketMission(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CSocketMission");
    tolua_cclass(tolua_S,"CSocketMission","CSocketMission","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"CSocketMission");
        tolua_function(tolua_S,"setLinkSuccLuaCallBack",lua_cocos2dx_kernel_CSocketMission_setLinkSuccLuaCallBack);
        tolua_function(tolua_S,"isAlive",lua_cocos2dx_kernel_CSocketMission_isAlive);
        tolua_function(tolua_S,"stop",lua_cocos2dx_kernel_CSocketMission_stop);
        tolua_function(tolua_S,"setUrl",lua_cocos2dx_kernel_CSocketMission_setUrl);
        tolua_function(tolua_S,"send",lua_cocos2dx_kernel_CSocketMission_send);
        tolua_function(tolua_S,"start",lua_cocos2dx_kernel_CSocketMission_start);
        tolua_function(tolua_S,"setLinkErrorLuaCallBack",lua_cocos2dx_kernel_CSocketMission_setLinkErrorLuaCallBack);
        tolua_function(tolua_S,"setLinkDownLuaCallBack",lua_cocos2dx_kernel_CSocketMission_setLinkDownLuaCallBack);
        tolua_function(tolua_S,"setLinkDataLuaCallBack",lua_cocos2dx_kernel_CSocketMission_setLinkDataLuaCallBack);
        tolua_function(tolua_S,"Instance", lua_cocos2dx_kernel_CSocketMission_Instance);
        tolua_function(tolua_S,"Destroy", lua_cocos2dx_kernel_CSocketMission_Destroy);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CSocketMission).name();
    g_luaType[typeName] = "CSocketMission";
    g_typeCast["CSocketMission"] = "CSocketMission";
    return 1;
}

int lua_cocos2dx_kernel_IClientUserItem_GetUserExperience(lua_State* tolua_S)
{
    int argc = 0;
    IClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IClientUserItem_GetUserExperience'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientUserItem_GetUserExperience'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->GetUserExperience();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IClientUserItem:GetUserExperience",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientUserItem_GetUserExperience'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IClientUserItem_GetUserID(lua_State* tolua_S)
{
    int argc = 0;
    IClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IClientUserItem_GetUserID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientUserItem_GetUserID'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->GetUserID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IClientUserItem:GetUserID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientUserItem_GetUserID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IClientUserItem_SetUserNoteInfo(lua_State* tolua_S)
{
    int argc = 0;
    IClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IClientUserItem_SetUserNoteInfo'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "IClientUserItem:SetUserNoteInfo"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientUserItem_SetUserNoteInfo'", nullptr);
            return 0;
        }
        cobj->SetUserNoteInfo(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IClientUserItem:SetUserNoteInfo",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientUserItem_SetUserNoteInfo'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IClientUserItem_GetProfileUrl(lua_State* tolua_S)
{
    int argc = 0;
    IClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IClientUserItem_GetProfileUrl'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientUserItem_GetProfileUrl'", nullptr);
            return 0;
        }
        const char* ret = cobj->GetProfileUrl();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IClientUserItem:GetProfileUrl",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientUserItem_GetProfileUrl'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IClientUserItem_GetUserLoveLiness(lua_State* tolua_S)
{
    int argc = 0;
    IClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IClientUserItem_GetUserLoveLiness'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientUserItem_GetUserLoveLiness'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->GetUserLoveLiness();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IClientUserItem:GetUserLoveLiness",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientUserItem_GetUserLoveLiness'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IClientUserItem_GetUserStatus(lua_State* tolua_S)
{
    int argc = 0;
    IClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IClientUserItem_GetUserStatus'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientUserItem_GetUserStatus'", nullptr);
            return 0;
        }
        uint16_t ret = cobj->GetUserStatus();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IClientUserItem:GetUserStatus",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientUserItem_GetUserStatus'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IClientUserItem_GetUserWinCount(lua_State* tolua_S)
{
    int argc = 0;
    IClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IClientUserItem_GetUserWinCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientUserItem_GetUserWinCount'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->GetUserWinCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IClientUserItem:GetUserWinCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientUserItem_GetUserWinCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IClientUserItem_GetUserFleeCount(lua_State* tolua_S)
{
    int argc = 0;
    IClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IClientUserItem_GetUserFleeCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientUserItem_GetUserFleeCount'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->GetUserFleeCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IClientUserItem:GetUserFleeCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientUserItem_GetUserFleeCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IClientUserItem_GetUserDrawCount(lua_State* tolua_S)
{
    int argc = 0;
    IClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IClientUserItem_GetUserDrawCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientUserItem_GetUserDrawCount'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->GetUserDrawCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IClientUserItem:GetUserDrawCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientUserItem_GetUserDrawCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IClientUserItem_SetUserCompanion(lua_State* tolua_S)
{
    int argc = 0;
    IClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IClientUserItem_SetUserCompanion'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        uint16_t arg0;

        ok &= luaval_to_uint16(tolua_S, 2,&arg0, "IClientUserItem:SetUserCompanion");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientUserItem_SetUserCompanion'", nullptr);
            return 0;
        }
        cobj->SetUserCompanion(std::move(arg0));
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IClientUserItem:SetUserCompanion",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientUserItem_SetUserCompanion'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IClientUserItem_GetUserDrawRate(lua_State* tolua_S)
{
    int argc = 0;
    IClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IClientUserItem_GetUserDrawRate'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientUserItem_GetUserDrawRate'", nullptr);
            return 0;
        }
        double ret = cobj->GetUserDrawRate();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IClientUserItem:GetUserDrawRate",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientUserItem_GetUserDrawRate'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IClientUserItem_GetCustomFaceInfo(lua_State* tolua_S)
{
    int argc = 0;
    IClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IClientUserItem_GetCustomFaceInfo'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientUserItem_GetCustomFaceInfo'", nullptr);
            return 0;
        }
        tagCustomFaceInfo* ret = cobj->GetCustomFaceInfo();
        object_to_luaval<tagCustomFaceInfo>(tolua_S, "tagCustomFaceInfo",(tagCustomFaceInfo*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IClientUserItem:GetCustomFaceInfo",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientUserItem_GetCustomFaceInfo'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IClientUserItem_GetUserGrade(lua_State* tolua_S)
{
    int argc = 0;
    IClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IClientUserItem_GetUserGrade'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientUserItem_GetUserGrade'", nullptr);
            return 0;
        }
        long long ret = cobj->GetUserGrade();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IClientUserItem:GetUserGrade",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientUserItem_GetUserGrade'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IClientUserItem_GetFaceID(lua_State* tolua_S)
{
    int argc = 0;
    IClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IClientUserItem_GetFaceID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientUserItem_GetFaceID'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->GetFaceID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IClientUserItem:GetFaceID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientUserItem_GetFaceID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IClientUserItem_GetUserLostRate(lua_State* tolua_S)
{
    int argc = 0;
    IClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IClientUserItem_GetUserLostRate'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientUserItem_GetUserLostRate'", nullptr);
            return 0;
        }
        double ret = cobj->GetUserLostRate();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IClientUserItem:GetUserLostRate",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientUserItem_GetUserLostRate'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IClientUserItem_GetGroupName(lua_State* tolua_S)
{
    int argc = 0;
    IClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IClientUserItem_GetGroupName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientUserItem_GetGroupName'", nullptr);
            return 0;
        }
        const char* ret = cobj->GetGroupName();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IClientUserItem:GetGroupName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientUserItem_GetGroupName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IClientUserItem_GetUserScore(lua_State* tolua_S)
{
    int argc = 0;
    IClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IClientUserItem_GetUserScore'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientUserItem_GetUserScore'", nullptr);
            return 0;
        }
        long long ret = cobj->GetUserScore();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IClientUserItem:GetUserScore",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientUserItem_GetUserScore'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IClientUserItem_GetImportOrder(lua_State* tolua_S)
{
    int argc = 0;
    IClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IClientUserItem_GetImportOrder'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientUserItem_GetImportOrder'", nullptr);
            return 0;
        }
        long ret = cobj->GetImportOrder();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IClientUserItem:GetImportOrder",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientUserItem_GetImportOrder'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IClientUserItem_GetUserInfo(lua_State* tolua_S)
{
    int argc = 0;
    IClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IClientUserItem_GetUserInfo'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientUserItem_GetUserInfo'", nullptr);
            return 0;
        }
        tagUserInfo* ret = cobj->GetUserInfo();
        object_to_luaval<tagUserInfo>(tolua_S, "tagUserInfo",(tagUserInfo*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IClientUserItem:GetUserInfo",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientUserItem_GetUserInfo'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IClientUserItem_GetTableID(lua_State* tolua_S)
{
    int argc = 0;
    IClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IClientUserItem_GetTableID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientUserItem_GetTableID'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->GetTableID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IClientUserItem:GetTableID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientUserItem_GetTableID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IClientUserItem_GetGroupID(lua_State* tolua_S)
{
    int argc = 0;
    IClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IClientUserItem_GetGroupID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientUserItem_GetGroupID'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->GetGroupID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IClientUserItem:GetGroupID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientUserItem_GetGroupID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IClientUserItem_GetUnderWrite(lua_State* tolua_S)
{
    int argc = 0;
    IClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IClientUserItem_GetUnderWrite'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientUserItem_GetUnderWrite'", nullptr);
            return 0;
        }
        const char* ret = cobj->GetUnderWrite();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IClientUserItem:GetUnderWrite",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientUserItem_GetUnderWrite'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IClientUserItem_GetUserFleeRate(lua_State* tolua_S)
{
    int argc = 0;
    IClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IClientUserItem_GetUserFleeRate'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientUserItem_GetUserFleeRate'", nullptr);
            return 0;
        }
        double ret = cobj->GetUserFleeRate();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IClientUserItem:GetUserFleeRate",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientUserItem_GetUserFleeRate'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IClientUserItem_GetPropertyPackage(lua_State* tolua_S)
{
    int argc = 0;
    IClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IClientUserItem_GetPropertyPackage'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientUserItem_GetPropertyPackage'", nullptr);
            return 0;
        }
        tagPropertyPackage* ret = cobj->GetPropertyPackage();
        object_to_luaval<tagPropertyPackage>(tolua_S, "tagPropertyPackage",(tagPropertyPackage*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IClientUserItem:GetPropertyPackage",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientUserItem_GetPropertyPackage'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IClientUserItem_GetUserCompanion(lua_State* tolua_S)
{
    int argc = 0;
    IClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IClientUserItem_GetUserCompanion'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientUserItem_GetUserCompanion'", nullptr);
            return 0;
        }
        uint16_t ret = cobj->GetUserCompanion();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IClientUserItem:GetUserCompanion",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientUserItem_GetUserCompanion'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IClientUserItem_GetUserNoteInfo(lua_State* tolua_S)
{
    int argc = 0;
    IClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IClientUserItem_GetUserNoteInfo'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientUserItem_GetUserNoteInfo'", nullptr);
            return 0;
        }
        const char* ret = cobj->GetUserNoteInfo();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IClientUserItem:GetUserNoteInfo",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientUserItem_GetUserNoteInfo'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IClientUserItem_GetGameID(lua_State* tolua_S)
{
    int argc = 0;
    IClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IClientUserItem_GetGameID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientUserItem_GetGameID'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->GetGameID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IClientUserItem:GetGameID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientUserItem_GetGameID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IClientUserItem_GetCustomID(lua_State* tolua_S)
{
    int argc = 0;
    IClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IClientUserItem_GetCustomID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientUserItem_GetCustomID'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->GetCustomID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IClientUserItem:GetCustomID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientUserItem_GetCustomID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IClientUserItem_GetChairID(lua_State* tolua_S)
{
    int argc = 0;
    IClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IClientUserItem_GetChairID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientUserItem_GetChairID'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->GetChairID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IClientUserItem:GetChairID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientUserItem_GetChairID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IClientUserItem_GetUserIngot(lua_State* tolua_S)
{
    int argc = 0;
    IClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IClientUserItem_GetUserIngot'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientUserItem_GetUserIngot'", nullptr);
            return 0;
        }
        long long ret = cobj->GetUserIngot();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IClientUserItem:GetUserIngot",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientUserItem_GetUserIngot'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IClientUserItem_GetUserLostCount(lua_State* tolua_S)
{
    int argc = 0;
    IClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IClientUserItem_GetUserLostCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientUserItem_GetUserLostCount'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->GetUserLostCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IClientUserItem:GetUserLostCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientUserItem_GetUserLostCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IClientUserItem_GetUserInsure(lua_State* tolua_S)
{
    int argc = 0;
    IClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IClientUserItem_GetUserInsure'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientUserItem_GetUserInsure'", nullptr);
            return 0;
        }
        long long ret = cobj->GetUserInsure();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IClientUserItem:GetUserInsure",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientUserItem_GetUserInsure'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IClientUserItem_GetUserWinRate(lua_State* tolua_S)
{
    int argc = 0;
    IClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IClientUserItem_GetUserWinRate'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientUserItem_GetUserWinRate'", nullptr);
            return 0;
        }
        double ret = cobj->GetUserWinRate();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IClientUserItem:GetUserWinRate",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientUserItem_GetUserWinRate'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IClientUserItem_GetGender(lua_State* tolua_S)
{
    int argc = 0;
    IClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IClientUserItem_GetGender'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientUserItem_GetGender'", nullptr);
            return 0;
        }
        uint16_t ret = cobj->GetGender();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IClientUserItem:GetGender",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientUserItem_GetGender'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IClientUserItem_GetNickName(lua_State* tolua_S)
{
    int argc = 0;
    IClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IClientUserItem_GetNickName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientUserItem_GetNickName'", nullptr);
            return 0;
        }
        const char* ret = cobj->GetNickName();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IClientUserItem:GetNickName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientUserItem_GetNickName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IClientUserItem_GetMasterOrder(lua_State* tolua_S)
{
    int argc = 0;
    IClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IClientUserItem_GetMasterOrder'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientUserItem_GetMasterOrder'", nullptr);
            return 0;
        }
        uint16_t ret = cobj->GetMasterOrder();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IClientUserItem:GetMasterOrder",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientUserItem_GetMasterOrder'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IClientUserItem_GetUserPlayCount(lua_State* tolua_S)
{
    int argc = 0;
    IClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IClientUserItem_GetUserPlayCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientUserItem_GetUserPlayCount'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->GetUserPlayCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IClientUserItem:GetUserPlayCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientUserItem_GetUserPlayCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IClientUserItem_GetMemberOrder(lua_State* tolua_S)
{
    int argc = 0;
    IClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IClientUserItem_GetMemberOrder'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientUserItem_GetMemberOrder'", nullptr);
            return 0;
        }
        uint16_t ret = cobj->GetMemberOrder();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IClientUserItem:GetMemberOrder",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientUserItem_GetMemberOrder'.",&tolua_err);
#endif

    return 0;
}
static int lua_cocos2dx_kernel_IClientUserItem_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (IClientUserItem)");
    return 0;
}

int lua_register_cocos2dx_kernel_IClientUserItem(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"IClientUserItem");
    tolua_cclass(tolua_S,"IClientUserItem","IClientUserItem","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"IClientUserItem");
        tolua_function(tolua_S,"GetUserExperience",lua_cocos2dx_kernel_IClientUserItem_GetUserExperience);
        tolua_function(tolua_S,"GetUserID",lua_cocos2dx_kernel_IClientUserItem_GetUserID);
        tolua_function(tolua_S,"SetUserNoteInfo",lua_cocos2dx_kernel_IClientUserItem_SetUserNoteInfo);
        tolua_function(tolua_S,"GetProfileUrl",lua_cocos2dx_kernel_IClientUserItem_GetProfileUrl);
        tolua_function(tolua_S,"GetUserLoveLiness",lua_cocos2dx_kernel_IClientUserItem_GetUserLoveLiness);
        tolua_function(tolua_S,"GetUserStatus",lua_cocos2dx_kernel_IClientUserItem_GetUserStatus);
        tolua_function(tolua_S,"GetUserWinCount",lua_cocos2dx_kernel_IClientUserItem_GetUserWinCount);
        tolua_function(tolua_S,"GetUserFleeCount",lua_cocos2dx_kernel_IClientUserItem_GetUserFleeCount);
        tolua_function(tolua_S,"GetUserDrawCount",lua_cocos2dx_kernel_IClientUserItem_GetUserDrawCount);
        tolua_function(tolua_S,"SetUserCompanion",lua_cocos2dx_kernel_IClientUserItem_SetUserCompanion);
        tolua_function(tolua_S,"GetUserDrawRate",lua_cocos2dx_kernel_IClientUserItem_GetUserDrawRate);
        tolua_function(tolua_S,"GetCustomFaceInfo",lua_cocos2dx_kernel_IClientUserItem_GetCustomFaceInfo);
        tolua_function(tolua_S,"GetUserGrade",lua_cocos2dx_kernel_IClientUserItem_GetUserGrade);
        tolua_function(tolua_S,"GetFaceID",lua_cocos2dx_kernel_IClientUserItem_GetFaceID);
        tolua_function(tolua_S,"GetUserLostRate",lua_cocos2dx_kernel_IClientUserItem_GetUserLostRate);
        tolua_function(tolua_S,"GetGroupName",lua_cocos2dx_kernel_IClientUserItem_GetGroupName);
        tolua_function(tolua_S,"GetUserScore",lua_cocos2dx_kernel_IClientUserItem_GetUserScore);
        tolua_function(tolua_S,"GetImportOrder",lua_cocos2dx_kernel_IClientUserItem_GetImportOrder);
        tolua_function(tolua_S,"GetUserInfo",lua_cocos2dx_kernel_IClientUserItem_GetUserInfo);
        tolua_function(tolua_S,"GetTableID",lua_cocos2dx_kernel_IClientUserItem_GetTableID);
        tolua_function(tolua_S,"GetGroupID",lua_cocos2dx_kernel_IClientUserItem_GetGroupID);
        tolua_function(tolua_S,"GetUnderWrite",lua_cocos2dx_kernel_IClientUserItem_GetUnderWrite);
        tolua_function(tolua_S,"GetUserFleeRate",lua_cocos2dx_kernel_IClientUserItem_GetUserFleeRate);
        tolua_function(tolua_S,"GetPropertyPackage",lua_cocos2dx_kernel_IClientUserItem_GetPropertyPackage);
        tolua_function(tolua_S,"GetUserCompanion",lua_cocos2dx_kernel_IClientUserItem_GetUserCompanion);
        tolua_function(tolua_S,"GetUserNoteInfo",lua_cocos2dx_kernel_IClientUserItem_GetUserNoteInfo);
        tolua_function(tolua_S,"GetGameID",lua_cocos2dx_kernel_IClientUserItem_GetGameID);
        tolua_function(tolua_S,"GetCustomID",lua_cocos2dx_kernel_IClientUserItem_GetCustomID);
        tolua_function(tolua_S,"GetChairID",lua_cocos2dx_kernel_IClientUserItem_GetChairID);
        tolua_function(tolua_S,"GetUserIngot",lua_cocos2dx_kernel_IClientUserItem_GetUserIngot);
        tolua_function(tolua_S,"GetUserLostCount",lua_cocos2dx_kernel_IClientUserItem_GetUserLostCount);
        tolua_function(tolua_S,"GetUserInsure",lua_cocos2dx_kernel_IClientUserItem_GetUserInsure);
        tolua_function(tolua_S,"GetUserWinRate",lua_cocos2dx_kernel_IClientUserItem_GetUserWinRate);
        tolua_function(tolua_S,"GetGender",lua_cocos2dx_kernel_IClientUserItem_GetGender);
        tolua_function(tolua_S,"GetNickName",lua_cocos2dx_kernel_IClientUserItem_GetNickName);
        tolua_function(tolua_S,"GetMasterOrder",lua_cocos2dx_kernel_IClientUserItem_GetMasterOrder);
        tolua_function(tolua_S,"GetUserPlayCount",lua_cocos2dx_kernel_IClientUserItem_GetUserPlayCount);
        tolua_function(tolua_S,"GetMemberOrder",lua_cocos2dx_kernel_IClientUserItem_GetMemberOrder);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(IClientUserItem).name();
    g_luaType[typeName] = "IClientUserItem";
    g_typeCast["IClientUserItem"] = "IClientUserItem";
    return 1;
}

int lua_cocos2dx_kernel_tagSearchTable_setOneNull(lua_State* tolua_S)
{
    int argc = 0;
    tagSearchTable* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagSearchTable",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagSearchTable*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_tagSearchTable_setOneNull'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "tagSearchTable:setOneNull");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_tagSearchTable_setOneNull'", nullptr);
            return 0;
        }
        cobj->setOneNull(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagSearchTable:setOneNull",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_tagSearchTable_setOneNull'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_tagSearchTable_getOneNull(lua_State* tolua_S)
{
    int argc = 0;
    tagSearchTable* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagSearchTable",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagSearchTable*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_tagSearchTable_getOneNull'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_tagSearchTable_getOneNull'", nullptr);
            return 0;
        }
        bool ret = cobj->getOneNull();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagSearchTable:getOneNull",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_tagSearchTable_getOneNull'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_tagSearchTable_getResultTableID(lua_State* tolua_S)
{
    int argc = 0;
    tagSearchTable* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagSearchTable",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagSearchTable*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_tagSearchTable_getResultTableID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_tagSearchTable_getResultTableID'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->getResultTableID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagSearchTable:getResultTableID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_tagSearchTable_getResultTableID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_tagSearchTable_setAllNull(lua_State* tolua_S)
{
    int argc = 0;
    tagSearchTable* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagSearchTable",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagSearchTable*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_tagSearchTable_setAllNull'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "tagSearchTable:setAllNull");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_tagSearchTable_setAllNull'", nullptr);
            return 0;
        }
        cobj->setAllNull(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagSearchTable:setAllNull",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_tagSearchTable_setAllNull'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_tagSearchTable_getStartTableID(lua_State* tolua_S)
{
    int argc = 0;
    tagSearchTable* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagSearchTable",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagSearchTable*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_tagSearchTable_getStartTableID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_tagSearchTable_getStartTableID'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->getStartTableID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagSearchTable:getStartTableID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_tagSearchTable_getStartTableID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_tagSearchTable_setStartTableID(lua_State* tolua_S)
{
    int argc = 0;
    tagSearchTable* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagSearchTable",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagSearchTable*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_tagSearchTable_setStartTableID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagSearchTable:setStartTableID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_tagSearchTable_setStartTableID'", nullptr);
            return 0;
        }
        cobj->setStartTableID(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagSearchTable:setStartTableID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_tagSearchTable_setStartTableID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_tagSearchTable_getFilterPass(lua_State* tolua_S)
{
    int argc = 0;
    tagSearchTable* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagSearchTable",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagSearchTable*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_tagSearchTable_getFilterPass'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_tagSearchTable_getFilterPass'", nullptr);
            return 0;
        }
        bool ret = cobj->getFilterPass();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagSearchTable:getFilterPass",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_tagSearchTable_getFilterPass'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_tagSearchTable_setNotFull(lua_State* tolua_S)
{
    int argc = 0;
    tagSearchTable* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagSearchTable",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagSearchTable*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_tagSearchTable_setNotFull'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "tagSearchTable:setNotFull");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_tagSearchTable_setNotFull'", nullptr);
            return 0;
        }
        cobj->setNotFull(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagSearchTable:setNotFull",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_tagSearchTable_setNotFull'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_tagSearchTable_setTwoNull(lua_State* tolua_S)
{
    int argc = 0;
    tagSearchTable* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagSearchTable",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagSearchTable*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_tagSearchTable_setTwoNull'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "tagSearchTable:setTwoNull");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_tagSearchTable_setTwoNull'", nullptr);
            return 0;
        }
        cobj->setTwoNull(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagSearchTable:setTwoNull",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_tagSearchTable_setTwoNull'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_tagSearchTable_getAllNull(lua_State* tolua_S)
{
    int argc = 0;
    tagSearchTable* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagSearchTable",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagSearchTable*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_tagSearchTable_getAllNull'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_tagSearchTable_getAllNull'", nullptr);
            return 0;
        }
        bool ret = cobj->getAllNull();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagSearchTable:getAllNull",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_tagSearchTable_getAllNull'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_tagSearchTable_getNotFull(lua_State* tolua_S)
{
    int argc = 0;
    tagSearchTable* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagSearchTable",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagSearchTable*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_tagSearchTable_getNotFull'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_tagSearchTable_getNotFull'", nullptr);
            return 0;
        }
        bool ret = cobj->getNotFull();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagSearchTable:getNotFull",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_tagSearchTable_getNotFull'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_tagSearchTable_getTwoNull(lua_State* tolua_S)
{
    int argc = 0;
    tagSearchTable* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagSearchTable",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagSearchTable*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_tagSearchTable_getTwoNull'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_tagSearchTable_getTwoNull'", nullptr);
            return 0;
        }
        bool ret = cobj->getTwoNull();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagSearchTable:getTwoNull",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_tagSearchTable_getTwoNull'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_tagSearchTable_setResultChairID(lua_State* tolua_S)
{
    int argc = 0;
    tagSearchTable* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagSearchTable",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagSearchTable*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_tagSearchTable_setResultChairID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagSearchTable:setResultChairID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_tagSearchTable_setResultChairID'", nullptr);
            return 0;
        }
        cobj->setResultChairID(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagSearchTable:setResultChairID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_tagSearchTable_setResultChairID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_tagSearchTable_setResultTableID(lua_State* tolua_S)
{
    int argc = 0;
    tagSearchTable* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagSearchTable",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagSearchTable*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_tagSearchTable_setResultTableID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagSearchTable:setResultTableID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_tagSearchTable_setResultTableID'", nullptr);
            return 0;
        }
        cobj->setResultTableID(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagSearchTable:setResultTableID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_tagSearchTable_setResultTableID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_tagSearchTable_setFilterPass(lua_State* tolua_S)
{
    int argc = 0;
    tagSearchTable* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagSearchTable",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagSearchTable*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_tagSearchTable_setFilterPass'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "tagSearchTable:setFilterPass");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_tagSearchTable_setFilterPass'", nullptr);
            return 0;
        }
        cobj->setFilterPass(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagSearchTable:setFilterPass",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_tagSearchTable_setFilterPass'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_tagSearchTable_getResultChairID(lua_State* tolua_S)
{
    int argc = 0;
    tagSearchTable* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagSearchTable",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagSearchTable*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_tagSearchTable_getResultChairID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_tagSearchTable_getResultChairID'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->getResultChairID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagSearchTable:getResultChairID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_tagSearchTable_getResultChairID'.",&tolua_err);
#endif

    return 0;
}
static int lua_cocos2dx_kernel_tagSearchTable_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (tagSearchTable)");
    return 0;
}

int lua_register_cocos2dx_kernel_tagSearchTable(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"tagSearchTable");
    tolua_cclass(tolua_S,"tagSearchTable","tagSearchTable","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"tagSearchTable");
        tolua_function(tolua_S,"setOneNull",lua_cocos2dx_kernel_tagSearchTable_setOneNull);
        tolua_function(tolua_S,"getOneNull",lua_cocos2dx_kernel_tagSearchTable_getOneNull);
        tolua_function(tolua_S,"getResultTableID",lua_cocos2dx_kernel_tagSearchTable_getResultTableID);
        tolua_function(tolua_S,"setAllNull",lua_cocos2dx_kernel_tagSearchTable_setAllNull);
        tolua_function(tolua_S,"getStartTableID",lua_cocos2dx_kernel_tagSearchTable_getStartTableID);
        tolua_function(tolua_S,"setStartTableID",lua_cocos2dx_kernel_tagSearchTable_setStartTableID);
        tolua_function(tolua_S,"getFilterPass",lua_cocos2dx_kernel_tagSearchTable_getFilterPass);
        tolua_function(tolua_S,"setNotFull",lua_cocos2dx_kernel_tagSearchTable_setNotFull);
        tolua_function(tolua_S,"setTwoNull",lua_cocos2dx_kernel_tagSearchTable_setTwoNull);
        tolua_function(tolua_S,"getAllNull",lua_cocos2dx_kernel_tagSearchTable_getAllNull);
        tolua_function(tolua_S,"getNotFull",lua_cocos2dx_kernel_tagSearchTable_getNotFull);
        tolua_function(tolua_S,"getTwoNull",lua_cocos2dx_kernel_tagSearchTable_getTwoNull);
        tolua_function(tolua_S,"setResultChairID",lua_cocos2dx_kernel_tagSearchTable_setResultChairID);
        tolua_function(tolua_S,"setResultTableID",lua_cocos2dx_kernel_tagSearchTable_setResultTableID);
        tolua_function(tolua_S,"setFilterPass",lua_cocos2dx_kernel_tagSearchTable_setFilterPass);
        tolua_function(tolua_S,"getResultChairID",lua_cocos2dx_kernel_tagSearchTable_getResultChairID);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(tagSearchTable).name();
    g_luaType[typeName] = "tagSearchTable";
    g_typeCast["tagSearchTable"] = "tagSearchTable";
    return 1;
}

int lua_cocos2dx_kernel_IServerItem_IsService(lua_State* tolua_S)
{
    int argc = 0;
    IServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IServerItem_IsService'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IServerItem_IsService'", nullptr);
            return 0;
        }
        bool ret = cobj->IsService();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IServerItem:IsService",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IServerItem_IsService'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IServerItem_AvertGameEnter(lua_State* tolua_S)
{
    int argc = 0;
    IServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IServerItem_AvertGameEnter'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IServerItem_AvertGameEnter'", nullptr);
            return 0;
        }
        cobj->AvertGameEnter();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IServerItem:AvertGameEnter",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IServerItem_AvertGameEnter'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IServerItem_SendSocketData(lua_State* tolua_S)
{
    int argc = 0;
    IServerItem* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IServerItem",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (IServerItem*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IServerItem_SendSocketData'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 4) {
            unsigned short arg0;
            ok &= luaval_to_ushort(tolua_S, 2, &arg0, "IServerItem:SendSocketData");

            if (!ok) { break; }
            unsigned short arg1;
            ok &= luaval_to_ushort(tolua_S, 3, &arg1, "IServerItem:SendSocketData");

            if (!ok) { break; }
            const char* arg2;
            std::string arg2_tmp; ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp, "IServerItem:SendSocketData"); arg2 = arg2_tmp.c_str();

            if (!ok) { break; }
            unsigned short arg3;
            ok &= luaval_to_ushort(tolua_S, 5, &arg3, "IServerItem:SendSocketData");

            if (!ok) { break; }
            bool ret = cobj->SendSocketData(arg0, arg1, arg2, arg3);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 2) {
            unsigned short arg0;
            ok &= luaval_to_ushort(tolua_S, 2, &arg0, "IServerItem:SendSocketData");

            if (!ok) { break; }
            unsigned short arg1;
            ok &= luaval_to_ushort(tolua_S, 3, &arg1, "IServerItem:SendSocketData");

            if (!ok) { break; }
            bool ret = cobj->SendSocketData(arg0, arg1);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "IServerItem:SendSocketData",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IServerItem_SendSocketData'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IServerItem_TerminConnect(lua_State* tolua_S)
{
    int argc = 0;
    IServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IServerItem_TerminConnect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IServerItem_TerminConnect'", nullptr);
            return 0;
        }
        cobj->TerminConnect();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IServerItem:TerminConnect",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IServerItem_TerminConnect'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IServerItem_GetTableUserItem(lua_State* tolua_S)
{
    int argc = 0;
    IServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IServerItem_GetTableUserItem'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "IServerItem:GetTableUserItem");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IServerItem_GetTableUserItem'", nullptr);
            return 0;
        }
        IClientUserItem* ret = cobj->GetTableUserItem(arg0);
        object_to_luaval<IClientUserItem>(tolua_S, "IClientUserItem",(IClientUserItem*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IServerItem:GetTableUserItem",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IServerItem_GetTableUserItem'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IServerItem_SearchUserByNickName(lua_State* tolua_S)
{
    int argc = 0;
    IServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IServerItem_SearchUserByNickName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "IServerItem:SearchUserByNickName"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IServerItem_SearchUserByNickName'", nullptr);
            return 0;
        }
        IClientUserItem* ret = cobj->SearchUserByNickName(arg0);
        object_to_luaval<IClientUserItem>(tolua_S, "IClientUserItem",(IClientUserItem*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IServerItem:SearchUserByNickName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IServerItem_SearchUserByNickName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IServerItem_SetChatSink(lua_State* tolua_S)
{
    int argc = 0;
    IServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IServerItem_SetChatSink'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        IChatSink* arg0;

        ok &= luaval_to_object<IChatSink>(tolua_S, 2, "IChatSink",&arg0, "IServerItem:SetChatSink");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IServerItem_SetChatSink'", nullptr);
            return 0;
        }
        bool ret = cobj->SetChatSink(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IServerItem:SetChatSink",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IServerItem_SetChatSink'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IServerItem_SetStringMessageSink(lua_State* tolua_S)
{
    int argc = 0;
    IServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IServerItem_SetStringMessageSink'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        IStringMessageSink* arg0;

        ok &= luaval_to_object<IStringMessageSink>(tolua_S, 2, "IStringMessageSink",&arg0, "IServerItem:SetStringMessageSink");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IServerItem_SetStringMessageSink'", nullptr);
            return 0;
        }
        bool ret = cobj->SetStringMessageSink(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IServerItem:SetStringMessageSink",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IServerItem_SetStringMessageSink'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IServerItem_GetSpaceChairId(lua_State* tolua_S)
{
    int argc = 0;
    IServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IServerItem_GetSpaceChairId'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "IServerItem:GetSpaceChairId");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IServerItem_GetSpaceChairId'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->GetSpaceChairId(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IServerItem:GetSpaceChairId",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IServerItem_GetSpaceChairId'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IServerItem_ConnectServer(lua_State* tolua_S)
{
    int argc = 0;
    IServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IServerItem_ConnectServer'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        CGameServerItem* arg0;
        unsigned short arg1;
        unsigned int arg2;

        ok &= luaval_to_object<CGameServerItem>(tolua_S, 2, "CGameServerItem",&arg0, "IServerItem:ConnectServer");

        ok &= luaval_to_ushort(tolua_S, 3, &arg1, "IServerItem:ConnectServer");

        ok &= luaval_to_uint32(tolua_S, 4,&arg2, "IServerItem:ConnectServer");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IServerItem_ConnectServer'", nullptr);
            return 0;
        }
        bool ret = cobj->ConnectServer(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IServerItem:ConnectServer",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IServerItem_ConnectServer'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IServerItem_GetUserAttribute(lua_State* tolua_S)
{
    int argc = 0;
    IServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IServerItem_GetUserAttribute'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IServerItem_GetUserAttribute'", nullptr);
            return 0;
        }
        tagUserAttribute* ret = cobj->GetUserAttribute();
        object_to_luaval<tagUserAttribute>(tolua_S, "tagUserAttribute",(tagUserAttribute*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IServerItem:GetUserAttribute",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IServerItem_GetUserAttribute'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IServerItem_IsPlayingMySelf(lua_State* tolua_S)
{
    int argc = 0;
    IServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IServerItem_IsPlayingMySelf'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IServerItem_IsPlayingMySelf'", nullptr);
            return 0;
        }
        bool ret = cobj->IsPlayingMySelf();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IServerItem:IsPlayingMySelf",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IServerItem_IsPlayingMySelf'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IServerItem_SearchUserByUserID(lua_State* tolua_S)
{
    int argc = 0;
    IServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IServerItem_SearchUserByUserID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "IServerItem:SearchUserByUserID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IServerItem_SearchUserByUserID'", nullptr);
            return 0;
        }
        IClientUserItem* ret = cobj->SearchUserByUserID(arg0);
        object_to_luaval<IClientUserItem>(tolua_S, "IClientUserItem",(IClientUserItem*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IServerItem:SearchUserByUserID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IServerItem_SearchUserByUserID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IServerItem_PerformQuickSitDown(lua_State* tolua_S)
{
    int argc = 0;
    IServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IServerItem_PerformQuickSitDown'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IServerItem_PerformQuickSitDown'", nullptr);
            return 0;
        }
        bool ret = cobj->PerformQuickSitDown();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IServerItem:PerformQuickSitDown",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IServerItem_PerformQuickSitDown'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IServerItem_PerformSitDownAction(lua_State* tolua_S)
{
    int argc = 0;
    IServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IServerItem_PerformSitDownAction'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        unsigned short arg0;
        unsigned short arg1;
        bool arg2;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "IServerItem:PerformSitDownAction");

        ok &= luaval_to_ushort(tolua_S, 3, &arg1, "IServerItem:PerformSitDownAction");

        ok &= luaval_to_boolean(tolua_S, 4,&arg2, "IServerItem:PerformSitDownAction");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IServerItem_PerformSitDownAction'", nullptr);
            return 0;
        }
        bool ret = cobj->PerformSitDownAction(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    if (argc == 4) 
    {
        unsigned short arg0;
        unsigned short arg1;
        bool arg2;
        const char* arg3;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "IServerItem:PerformSitDownAction");

        ok &= luaval_to_ushort(tolua_S, 3, &arg1, "IServerItem:PerformSitDownAction");

        ok &= luaval_to_boolean(tolua_S, 4,&arg2, "IServerItem:PerformSitDownAction");

        std::string arg3_tmp; ok &= luaval_to_std_string(tolua_S, 5, &arg3_tmp, "IServerItem:PerformSitDownAction"); arg3 = arg3_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IServerItem_PerformSitDownAction'", nullptr);
            return 0;
        }
        bool ret = cobj->PerformSitDownAction(arg0, arg1, arg2, arg3);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IServerItem:PerformSitDownAction",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IServerItem_PerformSitDownAction'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IServerItem_SearchUserByGameID(lua_State* tolua_S)
{
    int argc = 0;
    IServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IServerItem_SearchUserByGameID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "IServerItem:SearchUserByGameID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IServerItem_SearchUserByGameID'", nullptr);
            return 0;
        }
        IClientUserItem* ret = cobj->SearchUserByGameID(arg0);
        object_to_luaval<IClientUserItem>(tolua_S, "IClientUserItem",(IClientUserItem*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IServerItem:SearchUserByGameID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IServerItem_SearchUserByGameID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IServerItem_ResumeConnect(lua_State* tolua_S)
{
    int argc = 0;
    IServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IServerItem_ResumeConnect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IServerItem_ResumeConnect'", nullptr);
            return 0;
        }
        cobj->ResumeConnect();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IServerItem:ResumeConnect",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IServerItem_ResumeConnect'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IServerItem_SetServiceStatus(lua_State* tolua_S)
{
    int argc = 0;
    IServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IServerItem_SetServiceStatus'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        enServiceStatus arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "IServerItem:SetServiceStatus");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IServerItem_SetServiceStatus'", nullptr);
            return 0;
        }
        cobj->SetServiceStatus(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IServerItem:SetServiceStatus",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IServerItem_SetServiceStatus'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IServerItem_SetServerItemSink(lua_State* tolua_S)
{
    int argc = 0;
    IServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IServerItem_SetServerItemSink'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        IServerItemSink* arg0;

        ok &= luaval_to_object<IServerItemSink>(tolua_S, 2, "IServerItemSink",&arg0, "IServerItem:SetServerItemSink");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IServerItem_SetServerItemSink'", nullptr);
            return 0;
        }
        bool ret = cobj->SetServerItemSink(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IServerItem:SetServerItemSink",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IServerItem_SetServerItemSink'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IServerItem_IntermitConnect(lua_State* tolua_S)
{
    int argc = 0;
    IServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IServerItem_IntermitConnect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "IServerItem:IntermitConnect");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IServerItem_IntermitConnect'", nullptr);
            return 0;
        }
        bool ret = cobj->IntermitConnect(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IServerItem:IntermitConnect",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IServerItem_IntermitConnect'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IServerItem_PerformBuyProperty(lua_State* tolua_S)
{
    int argc = 0;
    IServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IServerItem_PerformBuyProperty'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 4) 
    {
        uint16_t arg0;
        const char* arg1;
        unsigned short arg2;
        unsigned short arg3;

        ok &= luaval_to_uint16(tolua_S, 2,&arg0, "IServerItem:PerformBuyProperty");

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "IServerItem:PerformBuyProperty"); arg1 = arg1_tmp.c_str();

        ok &= luaval_to_ushort(tolua_S, 4, &arg2, "IServerItem:PerformBuyProperty");

        ok &= luaval_to_ushort(tolua_S, 5, &arg3, "IServerItem:PerformBuyProperty");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IServerItem_PerformBuyProperty'", nullptr);
            return 0;
        }
        bool ret = cobj->PerformBuyProperty(std::move(arg0), arg1, arg2, arg3);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IServerItem:PerformBuyProperty",argc, 4);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IServerItem_PerformBuyProperty'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IServerItem_GetTotalTableCount(lua_State* tolua_S)
{
    int argc = 0;
    IServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IServerItem_GetTotalTableCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IServerItem_GetTotalTableCount'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->GetTotalTableCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IServerItem:GetTotalTableCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IServerItem_GetTotalTableCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IServerItem_PerformStandUpAction(lua_State* tolua_S)
{
    int argc = 0;
    IServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IServerItem_PerformStandUpAction'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        unsigned short arg0;
        unsigned short arg1;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "IServerItem:PerformStandUpAction");

        ok &= luaval_to_ushort(tolua_S, 3, &arg1, "IServerItem:PerformStandUpAction");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IServerItem_PerformStandUpAction'", nullptr);
            return 0;
        }
        bool ret = cobj->PerformStandUpAction(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IServerItem:PerformStandUpAction",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IServerItem_PerformStandUpAction'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IServerItem_GFSendData(lua_State* tolua_S)
{
    int argc = 0;
    IServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IServerItem_GFSendData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 4) 
    {
        int arg0;
        int arg1;
        const char* arg2;
        int arg3;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "IServerItem:GFSendData");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "IServerItem:GFSendData");

        std::string arg2_tmp; ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp, "IServerItem:GFSendData"); arg2 = arg2_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3, "IServerItem:GFSendData");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IServerItem_GFSendData'", nullptr);
            return 0;
        }
        bool ret = cobj->GFSendData(arg0, arg1, arg2, arg3);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IServerItem:GFSendData",argc, 4);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IServerItem_GFSendData'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IServerItem_PerformLookonAction(lua_State* tolua_S)
{
    int argc = 0;
    IServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IServerItem_PerformLookonAction'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        unsigned short arg0;
        unsigned short arg1;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "IServerItem:PerformLookonAction");

        ok &= luaval_to_ushort(tolua_S, 3, &arg1, "IServerItem:PerformLookonAction");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IServerItem_PerformLookonAction'", nullptr);
            return 0;
        }
        bool ret = cobj->PerformLookonAction(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IServerItem:PerformLookonAction",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IServerItem_PerformLookonAction'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IServerItem_PerformAutoJoin(lua_State* tolua_S)
{
    int argc = 0;
    IServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IServerItem_PerformAutoJoin'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IServerItem_PerformAutoJoin'", nullptr);
            return 0;
        }
        bool ret = cobj->PerformAutoJoin();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IServerItem:PerformAutoJoin",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IServerItem_PerformAutoJoin'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IServerItem_OnGFGameReady(lua_State* tolua_S)
{
    int argc = 0;
    IServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IServerItem_OnGFGameReady'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "IServerItem:OnGFGameReady");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IServerItem_OnGFGameReady'", nullptr);
            return 0;
        }
        cobj->OnGFGameReady(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IServerItem:OnGFGameReady",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IServerItem_OnGFGameReady'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IServerItem_OnGFGameClose(lua_State* tolua_S)
{
    int argc = 0;
    IServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IServerItem_OnGFGameClose'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "IServerItem:OnGFGameClose");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IServerItem_OnGFGameClose'", nullptr);
            return 0;
        }
        cobj->OnGFGameClose(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IServerItem:OnGFGameClose",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IServerItem_OnGFGameClose'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IServerItem_GetServerAttribute(lua_State* tolua_S)
{
    int argc = 0;
    IServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IServerItem_GetServerAttribute'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IServerItem_GetServerAttribute'", nullptr);
            return 0;
        }
        tagServerAttribute* ret = cobj->GetServerAttribute();
        object_to_luaval<tagServerAttribute>(tolua_S, "tagServerAttribute",(tagServerAttribute*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IServerItem:GetServerAttribute",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IServerItem_GetServerAttribute'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IServerItem_GetSpaceTableId(lua_State* tolua_S)
{
    int argc = 0;
    IServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IServerItem_GetSpaceTableId'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "IServerItem:GetSpaceTableId");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IServerItem_GetSpaceTableId'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->GetSpaceTableId(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IServerItem:GetSpaceTableId",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IServerItem_GetSpaceTableId'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IServerItem_SendSocketDataLua(lua_State* tolua_S)
{
    int argc = 0;
    IServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IServerItem_SendSocketDataLua'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        unsigned short arg0;
        unsigned short arg1;
        const cocos2d::Ref* arg2;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "IServerItem:SendSocketDataLua");

        ok &= luaval_to_ushort(tolua_S, 3, &arg1, "IServerItem:SendSocketDataLua");

        ok &= luaval_to_object<const cocos2d::Ref>(tolua_S, 4, "cc.Ref",&arg2, "IServerItem:SendSocketDataLua");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IServerItem_SendSocketDataLua'", nullptr);
            return 0;
        }
        bool ret = cobj->SendSocketDataLua(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IServerItem:SendSocketDataLua",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IServerItem_SendSocketDataLua'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IServerItem_ReconnectServer(lua_State* tolua_S)
{
    int argc = 0;
    IServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IServerItem_ReconnectServer'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        CGameServerItem* arg0;
        unsigned short arg1;
        unsigned int arg2;

        ok &= luaval_to_object<CGameServerItem>(tolua_S, 2, "CGameServerItem",&arg0, "IServerItem:ReconnectServer");

        ok &= luaval_to_ushort(tolua_S, 3, &arg1, "IServerItem:ReconnectServer");

        ok &= luaval_to_uint32(tolua_S, 4,&arg2, "IServerItem:ReconnectServer");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IServerItem_ReconnectServer'", nullptr);
            return 0;
        }
        bool ret = cobj->ReconnectServer(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IServerItem:ReconnectServer",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IServerItem_ReconnectServer'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IServerItem_GetServiceStatus(lua_State* tolua_S)
{
    int argc = 0;
    IServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IServerItem_GetServiceStatus'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IServerItem_GetServiceStatus'", nullptr);
            return 0;
        }
        int ret = (int)cobj->GetServiceStatus();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IServerItem:GetServiceStatus",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IServerItem_GetServiceStatus'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IServerItem_GetMeUserItem(lua_State* tolua_S)
{
    int argc = 0;
    IServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IServerItem_GetMeUserItem'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IServerItem_GetMeUserItem'", nullptr);
            return 0;
        }
        IClientUserItem* ret = cobj->GetMeUserItem();
        object_to_luaval<IClientUserItem>(tolua_S, "IClientUserItem",(IClientUserItem*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IServerItem:GetMeUserItem",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IServerItem_GetMeUserItem'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IServerItem_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"IServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IServerItem_create'", nullptr);
            return 0;
        }
        IServerItem* ret = IServerItem::create();
        object_to_luaval<IServerItem>(tolua_S, "IServerItem",(IServerItem*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "IServerItem:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IServerItem_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_kernel_IServerItem_get(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"IServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IServerItem_get'", nullptr);
            return 0;
        }
        IServerItem* ret = IServerItem::get();
        object_to_luaval<IServerItem>(tolua_S, "IServerItem",(IServerItem*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "IServerItem:get",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IServerItem_get'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_kernel_IServerItem_destory(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"IServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IServerItem_destory'", nullptr);
            return 0;
        }
        IServerItem::destory();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "IServerItem:destory",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IServerItem_destory'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_kernel_IServerItem_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (IServerItem)");
    return 0;
}

int lua_register_cocos2dx_kernel_IServerItem(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"IServerItem");
    tolua_cclass(tolua_S,"IServerItem","IServerItem","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"IServerItem");
        tolua_function(tolua_S,"IsService",lua_cocos2dx_kernel_IServerItem_IsService);
        tolua_function(tolua_S,"AvertGameEnter",lua_cocos2dx_kernel_IServerItem_AvertGameEnter);
        tolua_function(tolua_S,"SendSocketData",lua_cocos2dx_kernel_IServerItem_SendSocketData);
        tolua_function(tolua_S,"TerminConnect",lua_cocos2dx_kernel_IServerItem_TerminConnect);
        tolua_function(tolua_S,"GetTableUserItem",lua_cocos2dx_kernel_IServerItem_GetTableUserItem);
        tolua_function(tolua_S,"SearchUserByNickName",lua_cocos2dx_kernel_IServerItem_SearchUserByNickName);
        tolua_function(tolua_S,"SetChatSink",lua_cocos2dx_kernel_IServerItem_SetChatSink);
        tolua_function(tolua_S,"SetStringMessageSink",lua_cocos2dx_kernel_IServerItem_SetStringMessageSink);
        tolua_function(tolua_S,"GetSpaceChairId",lua_cocos2dx_kernel_IServerItem_GetSpaceChairId);
        tolua_function(tolua_S,"ConnectServer",lua_cocos2dx_kernel_IServerItem_ConnectServer);
        tolua_function(tolua_S,"GetUserAttribute",lua_cocos2dx_kernel_IServerItem_GetUserAttribute);
        tolua_function(tolua_S,"IsPlayingMySelf",lua_cocos2dx_kernel_IServerItem_IsPlayingMySelf);
        tolua_function(tolua_S,"SearchUserByUserID",lua_cocos2dx_kernel_IServerItem_SearchUserByUserID);
        tolua_function(tolua_S,"PerformQuickSitDown",lua_cocos2dx_kernel_IServerItem_PerformQuickSitDown);
        tolua_function(tolua_S,"PerformSitDownAction",lua_cocos2dx_kernel_IServerItem_PerformSitDownAction);
        tolua_function(tolua_S,"SearchUserByGameID",lua_cocos2dx_kernel_IServerItem_SearchUserByGameID);
        tolua_function(tolua_S,"ResumeConnect",lua_cocos2dx_kernel_IServerItem_ResumeConnect);
        tolua_function(tolua_S,"SetServiceStatus",lua_cocos2dx_kernel_IServerItem_SetServiceStatus);
        tolua_function(tolua_S,"SetServerItemSink",lua_cocos2dx_kernel_IServerItem_SetServerItemSink);
        tolua_function(tolua_S,"IntermitConnect",lua_cocos2dx_kernel_IServerItem_IntermitConnect);
        tolua_function(tolua_S,"PerformBuyProperty",lua_cocos2dx_kernel_IServerItem_PerformBuyProperty);
        tolua_function(tolua_S,"GetTotalTableCount",lua_cocos2dx_kernel_IServerItem_GetTotalTableCount);
        tolua_function(tolua_S,"PerformStandUpAction",lua_cocos2dx_kernel_IServerItem_PerformStandUpAction);
        tolua_function(tolua_S,"GFSendData",lua_cocos2dx_kernel_IServerItem_GFSendData);
        tolua_function(tolua_S,"PerformLookonAction",lua_cocos2dx_kernel_IServerItem_PerformLookonAction);
        tolua_function(tolua_S,"PerformAutoJoin",lua_cocos2dx_kernel_IServerItem_PerformAutoJoin);
        tolua_function(tolua_S,"OnGFGameReady",lua_cocos2dx_kernel_IServerItem_OnGFGameReady);
        tolua_function(tolua_S,"OnGFGameClose",lua_cocos2dx_kernel_IServerItem_OnGFGameClose);
        tolua_function(tolua_S,"GetServerAttribute",lua_cocos2dx_kernel_IServerItem_GetServerAttribute);
        tolua_function(tolua_S,"GetSpaceTableId",lua_cocos2dx_kernel_IServerItem_GetSpaceTableId);
        tolua_function(tolua_S,"SendSocketDataLua",lua_cocos2dx_kernel_IServerItem_SendSocketDataLua);
        tolua_function(tolua_S,"ReconnectServer",lua_cocos2dx_kernel_IServerItem_ReconnectServer);
        tolua_function(tolua_S,"GetServiceStatus",lua_cocos2dx_kernel_IServerItem_GetServiceStatus);
        tolua_function(tolua_S,"GetMeUserItem",lua_cocos2dx_kernel_IServerItem_GetMeUserItem);
        tolua_function(tolua_S,"create", lua_cocos2dx_kernel_IServerItem_create);
        tolua_function(tolua_S,"get", lua_cocos2dx_kernel_IServerItem_get);
        tolua_function(tolua_S,"destory", lua_cocos2dx_kernel_IServerItem_destory);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(IServerItem).name();
    g_luaType[typeName] = "IServerItem";
    g_typeCast["IServerItem"] = "IServerItem";
    return 1;
}

int lua_cocos2dx_kernel_CClientUserItem_GetUserExperience(lua_State* tolua_S)
{
    int argc = 0;
    CClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CClientUserItem_GetUserExperience'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CClientUserItem_GetUserExperience'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->GetUserExperience();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CClientUserItem:GetUserExperience",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CClientUserItem_GetUserExperience'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CClientUserItem_GetUserID(lua_State* tolua_S)
{
    int argc = 0;
    CClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CClientUserItem_GetUserID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CClientUserItem_GetUserID'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->GetUserID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CClientUserItem:GetUserID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CClientUserItem_GetUserID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CClientUserItem_SetUserNoteInfo(lua_State* tolua_S)
{
    int argc = 0;
    CClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CClientUserItem_SetUserNoteInfo'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CClientUserItem:SetUserNoteInfo"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CClientUserItem_SetUserNoteInfo'", nullptr);
            return 0;
        }
        cobj->SetUserNoteInfo(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CClientUserItem:SetUserNoteInfo",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CClientUserItem_SetUserNoteInfo'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CClientUserItem_GetProfileUrl(lua_State* tolua_S)
{
    int argc = 0;
    CClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CClientUserItem_GetProfileUrl'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CClientUserItem_GetProfileUrl'", nullptr);
            return 0;
        }
        const char* ret = cobj->GetProfileUrl();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CClientUserItem:GetProfileUrl",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CClientUserItem_GetProfileUrl'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CClientUserItem_GetUserLoveLiness(lua_State* tolua_S)
{
    int argc = 0;
    CClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CClientUserItem_GetUserLoveLiness'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CClientUserItem_GetUserLoveLiness'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->GetUserLoveLiness();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CClientUserItem:GetUserLoveLiness",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CClientUserItem_GetUserLoveLiness'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CClientUserItem_GetUserStatus(lua_State* tolua_S)
{
    int argc = 0;
    CClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CClientUserItem_GetUserStatus'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CClientUserItem_GetUserStatus'", nullptr);
            return 0;
        }
        uint16_t ret = cobj->GetUserStatus();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CClientUserItem:GetUserStatus",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CClientUserItem_GetUserStatus'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CClientUserItem_GetUserWinCount(lua_State* tolua_S)
{
    int argc = 0;
    CClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CClientUserItem_GetUserWinCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CClientUserItem_GetUserWinCount'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->GetUserWinCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CClientUserItem:GetUserWinCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CClientUserItem_GetUserWinCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CClientUserItem_GetUserFleeCount(lua_State* tolua_S)
{
    int argc = 0;
    CClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CClientUserItem_GetUserFleeCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CClientUserItem_GetUserFleeCount'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->GetUserFleeCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CClientUserItem:GetUserFleeCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CClientUserItem_GetUserFleeCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CClientUserItem_GetUserDrawCount(lua_State* tolua_S)
{
    int argc = 0;
    CClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CClientUserItem_GetUserDrawCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CClientUserItem_GetUserDrawCount'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->GetUserDrawCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CClientUserItem:GetUserDrawCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CClientUserItem_GetUserDrawCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CClientUserItem_SetUserCompanion(lua_State* tolua_S)
{
    int argc = 0;
    CClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CClientUserItem_SetUserCompanion'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        uint16_t arg0;

        ok &= luaval_to_uint16(tolua_S, 2,&arg0, "CClientUserItem:SetUserCompanion");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CClientUserItem_SetUserCompanion'", nullptr);
            return 0;
        }
        cobj->SetUserCompanion(std::move(arg0));
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CClientUserItem:SetUserCompanion",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CClientUserItem_SetUserCompanion'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CClientUserItem_GetUserDrawRate(lua_State* tolua_S)
{
    int argc = 0;
    CClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CClientUserItem_GetUserDrawRate'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CClientUserItem_GetUserDrawRate'", nullptr);
            return 0;
        }
        double ret = cobj->GetUserDrawRate();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CClientUserItem:GetUserDrawRate",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CClientUserItem_GetUserDrawRate'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CClientUserItem_GetCustomFaceInfo(lua_State* tolua_S)
{
    int argc = 0;
    CClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CClientUserItem_GetCustomFaceInfo'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CClientUserItem_GetCustomFaceInfo'", nullptr);
            return 0;
        }
        tagCustomFaceInfo* ret = cobj->GetCustomFaceInfo();
        object_to_luaval<tagCustomFaceInfo>(tolua_S, "tagCustomFaceInfo",(tagCustomFaceInfo*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CClientUserItem:GetCustomFaceInfo",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CClientUserItem_GetCustomFaceInfo'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CClientUserItem_GetUserGrade(lua_State* tolua_S)
{
    int argc = 0;
    CClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CClientUserItem_GetUserGrade'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CClientUserItem_GetUserGrade'", nullptr);
            return 0;
        }
        long long ret = cobj->GetUserGrade();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CClientUserItem:GetUserGrade",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CClientUserItem_GetUserGrade'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CClientUserItem_GetFaceID(lua_State* tolua_S)
{
    int argc = 0;
    CClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CClientUserItem_GetFaceID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CClientUserItem_GetFaceID'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->GetFaceID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CClientUserItem:GetFaceID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CClientUserItem_GetFaceID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CClientUserItem_GetUserLostRate(lua_State* tolua_S)
{
    int argc = 0;
    CClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CClientUserItem_GetUserLostRate'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CClientUserItem_GetUserLostRate'", nullptr);
            return 0;
        }
        double ret = cobj->GetUserLostRate();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CClientUserItem:GetUserLostRate",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CClientUserItem_GetUserLostRate'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CClientUserItem_GetGroupName(lua_State* tolua_S)
{
    int argc = 0;
    CClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CClientUserItem_GetGroupName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CClientUserItem_GetGroupName'", nullptr);
            return 0;
        }
        const char* ret = cobj->GetGroupName();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CClientUserItem:GetGroupName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CClientUserItem_GetGroupName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CClientUserItem_GetUserScore(lua_State* tolua_S)
{
    int argc = 0;
    CClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CClientUserItem_GetUserScore'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CClientUserItem_GetUserScore'", nullptr);
            return 0;
        }
        long long ret = cobj->GetUserScore();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CClientUserItem:GetUserScore",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CClientUserItem_GetUserScore'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CClientUserItem_GetImportOrder(lua_State* tolua_S)
{
    int argc = 0;
    CClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CClientUserItem_GetImportOrder'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CClientUserItem_GetImportOrder'", nullptr);
            return 0;
        }
        long ret = cobj->GetImportOrder();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CClientUserItem:GetImportOrder",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CClientUserItem_GetImportOrder'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CClientUserItem_GetUserInfo(lua_State* tolua_S)
{
    int argc = 0;
    CClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CClientUserItem_GetUserInfo'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CClientUserItem_GetUserInfo'", nullptr);
            return 0;
        }
        tagUserInfo* ret = cobj->GetUserInfo();
        object_to_luaval<tagUserInfo>(tolua_S, "tagUserInfo",(tagUserInfo*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CClientUserItem:GetUserInfo",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CClientUserItem_GetUserInfo'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CClientUserItem_GetTableID(lua_State* tolua_S)
{
    int argc = 0;
    CClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CClientUserItem_GetTableID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CClientUserItem_GetTableID'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->GetTableID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CClientUserItem:GetTableID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CClientUserItem_GetTableID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CClientUserItem_GetGroupID(lua_State* tolua_S)
{
    int argc = 0;
    CClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CClientUserItem_GetGroupID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CClientUserItem_GetGroupID'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->GetGroupID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CClientUserItem:GetGroupID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CClientUserItem_GetGroupID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CClientUserItem_GetUnderWrite(lua_State* tolua_S)
{
    int argc = 0;
    CClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CClientUserItem_GetUnderWrite'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CClientUserItem_GetUnderWrite'", nullptr);
            return 0;
        }
        const char* ret = cobj->GetUnderWrite();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CClientUserItem:GetUnderWrite",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CClientUserItem_GetUnderWrite'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CClientUserItem_GetUserFleeRate(lua_State* tolua_S)
{
    int argc = 0;
    CClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CClientUserItem_GetUserFleeRate'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CClientUserItem_GetUserFleeRate'", nullptr);
            return 0;
        }
        double ret = cobj->GetUserFleeRate();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CClientUserItem:GetUserFleeRate",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CClientUserItem_GetUserFleeRate'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CClientUserItem_GetPropertyPackage(lua_State* tolua_S)
{
    int argc = 0;
    CClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CClientUserItem_GetPropertyPackage'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CClientUserItem_GetPropertyPackage'", nullptr);
            return 0;
        }
        tagPropertyPackage* ret = cobj->GetPropertyPackage();
        object_to_luaval<tagPropertyPackage>(tolua_S, "tagPropertyPackage",(tagPropertyPackage*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CClientUserItem:GetPropertyPackage",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CClientUserItem_GetPropertyPackage'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CClientUserItem_GetUserCompanion(lua_State* tolua_S)
{
    int argc = 0;
    CClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CClientUserItem_GetUserCompanion'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CClientUserItem_GetUserCompanion'", nullptr);
            return 0;
        }
        uint16_t ret = cobj->GetUserCompanion();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CClientUserItem:GetUserCompanion",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CClientUserItem_GetUserCompanion'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CClientUserItem_GetUserNoteInfo(lua_State* tolua_S)
{
    int argc = 0;
    CClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CClientUserItem_GetUserNoteInfo'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CClientUserItem_GetUserNoteInfo'", nullptr);
            return 0;
        }
        const char* ret = cobj->GetUserNoteInfo();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CClientUserItem:GetUserNoteInfo",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CClientUserItem_GetUserNoteInfo'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CClientUserItem_GetGameID(lua_State* tolua_S)
{
    int argc = 0;
    CClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CClientUserItem_GetGameID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CClientUserItem_GetGameID'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->GetGameID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CClientUserItem:GetGameID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CClientUserItem_GetGameID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CClientUserItem_GetCustomID(lua_State* tolua_S)
{
    int argc = 0;
    CClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CClientUserItem_GetCustomID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CClientUserItem_GetCustomID'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->GetCustomID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CClientUserItem:GetCustomID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CClientUserItem_GetCustomID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CClientUserItem_GetChairID(lua_State* tolua_S)
{
    int argc = 0;
    CClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CClientUserItem_GetChairID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CClientUserItem_GetChairID'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->GetChairID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CClientUserItem:GetChairID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CClientUserItem_GetChairID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CClientUserItem_GetUserIngot(lua_State* tolua_S)
{
    int argc = 0;
    CClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CClientUserItem_GetUserIngot'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CClientUserItem_GetUserIngot'", nullptr);
            return 0;
        }
        long long ret = cobj->GetUserIngot();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CClientUserItem:GetUserIngot",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CClientUserItem_GetUserIngot'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CClientUserItem_GetUserLostCount(lua_State* tolua_S)
{
    int argc = 0;
    CClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CClientUserItem_GetUserLostCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CClientUserItem_GetUserLostCount'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->GetUserLostCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CClientUserItem:GetUserLostCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CClientUserItem_GetUserLostCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CClientUserItem_GetUserInsure(lua_State* tolua_S)
{
    int argc = 0;
    CClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CClientUserItem_GetUserInsure'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CClientUserItem_GetUserInsure'", nullptr);
            return 0;
        }
        long long ret = cobj->GetUserInsure();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CClientUserItem:GetUserInsure",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CClientUserItem_GetUserInsure'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CClientUserItem_GetUserWinRate(lua_State* tolua_S)
{
    int argc = 0;
    CClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CClientUserItem_GetUserWinRate'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CClientUserItem_GetUserWinRate'", nullptr);
            return 0;
        }
        double ret = cobj->GetUserWinRate();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CClientUserItem:GetUserWinRate",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CClientUserItem_GetUserWinRate'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CClientUserItem_GetGender(lua_State* tolua_S)
{
    int argc = 0;
    CClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CClientUserItem_GetGender'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CClientUserItem_GetGender'", nullptr);
            return 0;
        }
        uint16_t ret = cobj->GetGender();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CClientUserItem:GetGender",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CClientUserItem_GetGender'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CClientUserItem_GetNickName(lua_State* tolua_S)
{
    int argc = 0;
    CClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CClientUserItem_GetNickName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CClientUserItem_GetNickName'", nullptr);
            return 0;
        }
        const char* ret = cobj->GetNickName();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CClientUserItem:GetNickName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CClientUserItem_GetNickName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CClientUserItem_GetMasterOrder(lua_State* tolua_S)
{
    int argc = 0;
    CClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CClientUserItem_GetMasterOrder'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CClientUserItem_GetMasterOrder'", nullptr);
            return 0;
        }
        uint16_t ret = cobj->GetMasterOrder();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CClientUserItem:GetMasterOrder",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CClientUserItem_GetMasterOrder'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CClientUserItem_GetUserPlayCount(lua_State* tolua_S)
{
    int argc = 0;
    CClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CClientUserItem_GetUserPlayCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CClientUserItem_GetUserPlayCount'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->GetUserPlayCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CClientUserItem:GetUserPlayCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CClientUserItem_GetUserPlayCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CClientUserItem_GetMemberOrder(lua_State* tolua_S)
{
    int argc = 0;
    CClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CClientUserItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CClientUserItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CClientUserItem_GetMemberOrder'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CClientUserItem_GetMemberOrder'", nullptr);
            return 0;
        }
        uint16_t ret = cobj->GetMemberOrder();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CClientUserItem:GetMemberOrder",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CClientUserItem_GetMemberOrder'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CClientUserItem_constructor(lua_State* tolua_S)
{
    int argc = 0;
    CClientUserItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CClientUserItem_constructor'", nullptr);
            return 0;
        }
        cobj = new CClientUserItem();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"CClientUserItem");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CClientUserItem:CClientUserItem",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CClientUserItem_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_kernel_CClientUserItem_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CClientUserItem)");
    return 0;
}

int lua_register_cocos2dx_kernel_CClientUserItem(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CClientUserItem");
    tolua_cclass(tolua_S,"CClientUserItem","CClientUserItem","IClientUserItem",nullptr);

    tolua_beginmodule(tolua_S,"CClientUserItem");
        tolua_function(tolua_S,"new",lua_cocos2dx_kernel_CClientUserItem_constructor);
        tolua_function(tolua_S,"GetUserExperience",lua_cocos2dx_kernel_CClientUserItem_GetUserExperience);
        tolua_function(tolua_S,"GetUserID",lua_cocos2dx_kernel_CClientUserItem_GetUserID);
        tolua_function(tolua_S,"SetUserNoteInfo",lua_cocos2dx_kernel_CClientUserItem_SetUserNoteInfo);
        tolua_function(tolua_S,"GetProfileUrl",lua_cocos2dx_kernel_CClientUserItem_GetProfileUrl);
        tolua_function(tolua_S,"GetUserLoveLiness",lua_cocos2dx_kernel_CClientUserItem_GetUserLoveLiness);
        tolua_function(tolua_S,"GetUserStatus",lua_cocos2dx_kernel_CClientUserItem_GetUserStatus);
        tolua_function(tolua_S,"GetUserWinCount",lua_cocos2dx_kernel_CClientUserItem_GetUserWinCount);
        tolua_function(tolua_S,"GetUserFleeCount",lua_cocos2dx_kernel_CClientUserItem_GetUserFleeCount);
        tolua_function(tolua_S,"GetUserDrawCount",lua_cocos2dx_kernel_CClientUserItem_GetUserDrawCount);
        tolua_function(tolua_S,"SetUserCompanion",lua_cocos2dx_kernel_CClientUserItem_SetUserCompanion);
        tolua_function(tolua_S,"GetUserDrawRate",lua_cocos2dx_kernel_CClientUserItem_GetUserDrawRate);
        tolua_function(tolua_S,"GetCustomFaceInfo",lua_cocos2dx_kernel_CClientUserItem_GetCustomFaceInfo);
        tolua_function(tolua_S,"GetUserGrade",lua_cocos2dx_kernel_CClientUserItem_GetUserGrade);
        tolua_function(tolua_S,"GetFaceID",lua_cocos2dx_kernel_CClientUserItem_GetFaceID);
        tolua_function(tolua_S,"GetUserLostRate",lua_cocos2dx_kernel_CClientUserItem_GetUserLostRate);
        tolua_function(tolua_S,"GetGroupName",lua_cocos2dx_kernel_CClientUserItem_GetGroupName);
        tolua_function(tolua_S,"GetUserScore",lua_cocos2dx_kernel_CClientUserItem_GetUserScore);
        tolua_function(tolua_S,"GetImportOrder",lua_cocos2dx_kernel_CClientUserItem_GetImportOrder);
        tolua_function(tolua_S,"GetUserInfo",lua_cocos2dx_kernel_CClientUserItem_GetUserInfo);
        tolua_function(tolua_S,"GetTableID",lua_cocos2dx_kernel_CClientUserItem_GetTableID);
        tolua_function(tolua_S,"GetGroupID",lua_cocos2dx_kernel_CClientUserItem_GetGroupID);
        tolua_function(tolua_S,"GetUnderWrite",lua_cocos2dx_kernel_CClientUserItem_GetUnderWrite);
        tolua_function(tolua_S,"GetUserFleeRate",lua_cocos2dx_kernel_CClientUserItem_GetUserFleeRate);
        tolua_function(tolua_S,"GetPropertyPackage",lua_cocos2dx_kernel_CClientUserItem_GetPropertyPackage);
        tolua_function(tolua_S,"GetUserCompanion",lua_cocos2dx_kernel_CClientUserItem_GetUserCompanion);
        tolua_function(tolua_S,"GetUserNoteInfo",lua_cocos2dx_kernel_CClientUserItem_GetUserNoteInfo);
        tolua_function(tolua_S,"GetGameID",lua_cocos2dx_kernel_CClientUserItem_GetGameID);
        tolua_function(tolua_S,"GetCustomID",lua_cocos2dx_kernel_CClientUserItem_GetCustomID);
        tolua_function(tolua_S,"GetChairID",lua_cocos2dx_kernel_CClientUserItem_GetChairID);
        tolua_function(tolua_S,"GetUserIngot",lua_cocos2dx_kernel_CClientUserItem_GetUserIngot);
        tolua_function(tolua_S,"GetUserLostCount",lua_cocos2dx_kernel_CClientUserItem_GetUserLostCount);
        tolua_function(tolua_S,"GetUserInsure",lua_cocos2dx_kernel_CClientUserItem_GetUserInsure);
        tolua_function(tolua_S,"GetUserWinRate",lua_cocos2dx_kernel_CClientUserItem_GetUserWinRate);
        tolua_function(tolua_S,"GetGender",lua_cocos2dx_kernel_CClientUserItem_GetGender);
        tolua_function(tolua_S,"GetNickName",lua_cocos2dx_kernel_CClientUserItem_GetNickName);
        tolua_function(tolua_S,"GetMasterOrder",lua_cocos2dx_kernel_CClientUserItem_GetMasterOrder);
        tolua_function(tolua_S,"GetUserPlayCount",lua_cocos2dx_kernel_CClientUserItem_GetUserPlayCount);
        tolua_function(tolua_S,"GetMemberOrder",lua_cocos2dx_kernel_CClientUserItem_GetMemberOrder);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CClientUserItem).name();
    g_luaType[typeName] = "CClientUserItem";
    g_typeCast["CClientUserItem"] = "CClientUserItem";
    return 1;
}

int lua_cocos2dx_kernel_CServerItem_IsService(lua_State* tolua_S)
{
    int argc = 0;
    CServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CServerItem_IsService'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CServerItem_IsService'", nullptr);
            return 0;
        }
        bool ret = cobj->IsService();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerItem:IsService",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CServerItem_IsService'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CServerItem_SearchGameTable(lua_State* tolua_S)
{
    int argc = 0;
    CServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CServerItem_SearchGameTable'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        tagSearchTable* arg0;

        ok &= luaval_to_object<tagSearchTable>(tolua_S, 2, "tagSearchTable",&arg0, "CServerItem:SearchGameTable");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CServerItem_SearchGameTable'", nullptr);
            return 0;
        }
        bool ret = cobj->SearchGameTable(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerItem:SearchGameTable",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CServerItem_SearchGameTable'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CServerItem_SendSocketData(lua_State* tolua_S)
{
    int argc = 0;
    CServerItem* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerItem",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CServerItem*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CServerItem_SendSocketData'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 4) {
            unsigned short arg0;
            ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CServerItem:SendSocketData");

            if (!ok) { break; }
            unsigned short arg1;
            ok &= luaval_to_ushort(tolua_S, 3, &arg1, "CServerItem:SendSocketData");

            if (!ok) { break; }
            const char* arg2;
            std::string arg2_tmp; ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp, "CServerItem:SendSocketData"); arg2 = arg2_tmp.c_str();

            if (!ok) { break; }
            unsigned short arg3;
            ok &= luaval_to_ushort(tolua_S, 5, &arg3, "CServerItem:SendSocketData");

            if (!ok) { break; }
            bool ret = cobj->SendSocketData(arg0, arg1, arg2, arg3);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 2) {
            unsigned short arg0;
            ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CServerItem:SendSocketData");

            if (!ok) { break; }
            unsigned short arg1;
            ok &= luaval_to_ushort(tolua_S, 3, &arg1, "CServerItem:SendSocketData");

            if (!ok) { break; }
            bool ret = cobj->SendSocketData(arg0, arg1);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CServerItem:SendSocketData",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CServerItem_SendSocketData'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CServerItem_TerminConnect(lua_State* tolua_S)
{
    int argc = 0;
    CServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CServerItem_TerminConnect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CServerItem_TerminConnect'", nullptr);
            return 0;
        }
        cobj->TerminConnect();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerItem:TerminConnect",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CServerItem_TerminConnect'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CServerItem_SendSocketDataLua(lua_State* tolua_S)
{
    int argc = 0;
    CServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CServerItem_SendSocketDataLua'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        unsigned short arg0;
        unsigned short arg1;
        const cocos2d::Ref* arg2;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CServerItem:SendSocketDataLua");

        ok &= luaval_to_ushort(tolua_S, 3, &arg1, "CServerItem:SendSocketDataLua");

        ok &= luaval_to_object<const cocos2d::Ref>(tolua_S, 4, "cc.Ref",&arg2, "CServerItem:SendSocketDataLua");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CServerItem_SendSocketDataLua'", nullptr);
            return 0;
        }
        bool ret = cobj->SendSocketDataLua(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerItem:SendSocketDataLua",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CServerItem_SendSocketDataLua'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CServerItem_AvertGameEnter(lua_State* tolua_S)
{
    int argc = 0;
    CServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CServerItem_AvertGameEnter'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CServerItem_AvertGameEnter'", nullptr);
            return 0;
        }
        cobj->AvertGameEnter();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerItem:AvertGameEnter",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CServerItem_AvertGameEnter'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CServerItem_GetMeChairID(lua_State* tolua_S)
{
    int argc = 0;
    CServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CServerItem_GetMeChairID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CServerItem_GetMeChairID'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->GetMeChairID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerItem:GetMeChairID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CServerItem_GetMeChairID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CServerItem_SendUserRulePacket(lua_State* tolua_S)
{
    int argc = 0;
    CServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CServerItem_SendUserRulePacket'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CServerItem_SendUserRulePacket'", nullptr);
            return 0;
        }
        bool ret = cobj->SendUserRulePacket();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerItem:SendUserRulePacket",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CServerItem_SendUserRulePacket'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CServerItem_SetChatSink(lua_State* tolua_S)
{
    int argc = 0;
    CServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CServerItem_SetChatSink'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        IChatSink* arg0;

        ok &= luaval_to_object<IChatSink>(tolua_S, 2, "IChatSink",&arg0, "CServerItem:SetChatSink");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CServerItem_SetChatSink'", nullptr);
            return 0;
        }
        bool ret = cobj->SetChatSink(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerItem:SetChatSink",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CServerItem_SetChatSink'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CServerItem_SetStringMessageSink(lua_State* tolua_S)
{
    int argc = 0;
    CServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CServerItem_SetStringMessageSink'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        IStringMessageSink* arg0;

        ok &= luaval_to_object<IStringMessageSink>(tolua_S, 2, "IStringMessageSink",&arg0, "CServerItem:SetStringMessageSink");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CServerItem_SetStringMessageSink'", nullptr);
            return 0;
        }
        bool ret = cobj->SetStringMessageSink(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerItem:SetStringMessageSink",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CServerItem_SetStringMessageSink'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CServerItem_SendExpressionPacket(lua_State* tolua_S)
{
    int argc = 0;
    CServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CServerItem_SendExpressionPacket'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        unsigned int arg0;
        unsigned short arg1;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "CServerItem:SendExpressionPacket");

        ok &= luaval_to_ushort(tolua_S, 3, &arg1, "CServerItem:SendExpressionPacket");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CServerItem_SendExpressionPacket'", nullptr);
            return 0;
        }
        bool ret = cobj->SendExpressionPacket(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerItem:SendExpressionPacket",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CServerItem_SendExpressionPacket'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CServerItem_OnUserFaceUpdate(lua_State* tolua_S)
{
    int argc = 0;
    CServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CServerItem_OnUserFaceUpdate'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        IClientUserItem* arg0;

        ok &= luaval_to_object<IClientUserItem>(tolua_S, 2, "IClientUserItem",&arg0, "CServerItem:OnUserFaceUpdate");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CServerItem_OnUserFaceUpdate'", nullptr);
            return 0;
        }
        cobj->OnUserFaceUpdate(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerItem:OnUserFaceUpdate",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CServerItem_OnUserFaceUpdate'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CServerItem_PerformSitDownAction(lua_State* tolua_S)
{
    int argc = 0;
    CServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CServerItem_PerformSitDownAction'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        unsigned short arg0;
        unsigned short arg1;
        bool arg2;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CServerItem:PerformSitDownAction");

        ok &= luaval_to_ushort(tolua_S, 3, &arg1, "CServerItem:PerformSitDownAction");

        ok &= luaval_to_boolean(tolua_S, 4,&arg2, "CServerItem:PerformSitDownAction");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CServerItem_PerformSitDownAction'", nullptr);
            return 0;
        }
        bool ret = cobj->PerformSitDownAction(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    if (argc == 4) 
    {
        unsigned short arg0;
        unsigned short arg1;
        bool arg2;
        const char* arg3;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CServerItem:PerformSitDownAction");

        ok &= luaval_to_ushort(tolua_S, 3, &arg1, "CServerItem:PerformSitDownAction");

        ok &= luaval_to_boolean(tolua_S, 4,&arg2, "CServerItem:PerformSitDownAction");

        std::string arg3_tmp; ok &= luaval_to_std_string(tolua_S, 5, &arg3_tmp, "CServerItem:PerformSitDownAction"); arg3 = arg3_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CServerItem_PerformSitDownAction'", nullptr);
            return 0;
        }
        bool ret = cobj->PerformSitDownAction(arg0, arg1, arg2, arg3);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerItem:PerformSitDownAction",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CServerItem_PerformSitDownAction'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CServerItem_GFSendData(lua_State* tolua_S)
{
    int argc = 0;
    CServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CServerItem_GFSendData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 4) 
    {
        int arg0;
        int arg1;
        const char* arg2;
        int arg3;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "CServerItem:GFSendData");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "CServerItem:GFSendData");

        std::string arg2_tmp; ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp, "CServerItem:GFSendData"); arg2 = arg2_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3, "CServerItem:GFSendData");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CServerItem_GFSendData'", nullptr);
            return 0;
        }
        bool ret = cobj->GFSendData(arg0, arg1, arg2, arg3);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerItem:GFSendData",argc, 4);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CServerItem_GFSendData'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CServerItem_ConnectServer(lua_State* tolua_S)
{
    int argc = 0;
    CServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CServerItem_ConnectServer'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        CGameServerItem* arg0;
        unsigned short arg1;
        unsigned int arg2;

        ok &= luaval_to_object<CGameServerItem>(tolua_S, 2, "CGameServerItem",&arg0, "CServerItem:ConnectServer");

        ok &= luaval_to_ushort(tolua_S, 3, &arg1, "CServerItem:ConnectServer");

        ok &= luaval_to_uint32(tolua_S, 4,&arg2, "CServerItem:ConnectServer");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CServerItem_ConnectServer'", nullptr);
            return 0;
        }
        bool ret = cobj->ConnectServer(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerItem:ConnectServer",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CServerItem_ConnectServer'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CServerItem_GetUserAttribute(lua_State* tolua_S)
{
    int argc = 0;
    CServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CServerItem_GetUserAttribute'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CServerItem_GetUserAttribute'", nullptr);
            return 0;
        }
        tagUserAttribute* ret = cobj->GetUserAttribute();
        object_to_luaval<tagUserAttribute>(tolua_S, "tagUserAttribute",(tagUserAttribute*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerItem:GetUserAttribute",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CServerItem_GetUserAttribute'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CServerItem_IsPlayingMySelf(lua_State* tolua_S)
{
    int argc = 0;
    CServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CServerItem_IsPlayingMySelf'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CServerItem_IsPlayingMySelf'", nullptr);
            return 0;
        }
        bool ret = cobj->IsPlayingMySelf();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerItem:IsPlayingMySelf",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CServerItem_IsPlayingMySelf'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CServerItem_SearchUserByUserID(lua_State* tolua_S)
{
    int argc = 0;
    CServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CServerItem_SearchUserByUserID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "CServerItem:SearchUserByUserID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CServerItem_SearchUserByUserID'", nullptr);
            return 0;
        }
        IClientUserItem* ret = cobj->SearchUserByUserID(arg0);
        object_to_luaval<IClientUserItem>(tolua_S, "IClientUserItem",(IClientUserItem*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerItem:SearchUserByUserID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CServerItem_SearchUserByUserID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CServerItem_PerformQuickSitDown(lua_State* tolua_S)
{
    int argc = 0;
    CServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CServerItem_PerformQuickSitDown'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CServerItem_PerformQuickSitDown'", nullptr);
            return 0;
        }
        bool ret = cobj->PerformQuickSitDown();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerItem:PerformQuickSitDown",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CServerItem_PerformQuickSitDown'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CServerItem_SendSitDownPacket(lua_State* tolua_S)
{
    int argc = 0;
    CServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CServerItem_SendSitDownPacket'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        unsigned short arg0;
        unsigned short arg1;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CServerItem:SendSitDownPacket");

        ok &= luaval_to_ushort(tolua_S, 3, &arg1, "CServerItem:SendSitDownPacket");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CServerItem_SendSitDownPacket'", nullptr);
            return 0;
        }
        bool ret = cobj->SendSitDownPacket(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    if (argc == 3) 
    {
        unsigned short arg0;
        unsigned short arg1;
        const char* arg2;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CServerItem:SendSitDownPacket");

        ok &= luaval_to_ushort(tolua_S, 3, &arg1, "CServerItem:SendSitDownPacket");

        std::string arg2_tmp; ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp, "CServerItem:SendSitDownPacket"); arg2 = arg2_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CServerItem_SendSitDownPacket'", nullptr);
            return 0;
        }
        bool ret = cobj->SendSitDownPacket(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerItem:SendSitDownPacket",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CServerItem_SendSitDownPacket'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CServerItem_SearchUserByGameID(lua_State* tolua_S)
{
    int argc = 0;
    CServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CServerItem_SearchUserByGameID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "CServerItem:SearchUserByGameID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CServerItem_SearchUserByGameID'", nullptr);
            return 0;
        }
        IClientUserItem* ret = cobj->SearchUserByGameID(arg0);
        object_to_luaval<IClientUserItem>(tolua_S, "IClientUserItem",(IClientUserItem*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerItem:SearchUserByGameID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CServerItem_SearchUserByGameID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CServerItem_IsDistributionTable(lua_State* tolua_S)
{
    int argc = 0;
    CServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CServerItem_IsDistributionTable'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CServerItem_IsDistributionTable'", nullptr);
            return 0;
        }
        bool ret = cobj->IsDistributionTable();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerItem:IsDistributionTable",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CServerItem_IsDistributionTable'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CServerItem_GetTableLockState(lua_State* tolua_S)
{
    int argc = 0;
    CServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CServerItem_GetTableLockState'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "CServerItem:GetTableLockState");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CServerItem_GetTableLockState'", nullptr);
            return 0;
        }
        bool ret = cobj->GetTableLockState(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerItem:GetTableLockState",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CServerItem_GetTableLockState'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CServerItem_GetActiveUserCount(lua_State* tolua_S)
{
    int argc = 0;
    CServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CServerItem_GetActiveUserCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CServerItem_GetActiveUserCount'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->GetActiveUserCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerItem:GetActiveUserCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CServerItem_GetActiveUserCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CServerItem_SendStandUp(lua_State* tolua_S)
{
    int argc = 0;
    CServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CServerItem_SendStandUp'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CServerItem_SendStandUp'", nullptr);
            return 0;
        }
        bool ret = cobj->SendStandUp();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerItem:SendStandUp",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CServerItem_SendStandUp'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CServerItem_ResumeConnect(lua_State* tolua_S)
{
    int argc = 0;
    CServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CServerItem_ResumeConnect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CServerItem_ResumeConnect'", nullptr);
            return 0;
        }
        cobj->ResumeConnect();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerItem:ResumeConnect",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CServerItem_ResumeConnect'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CServerItem_SetServiceStatus(lua_State* tolua_S)
{
    int argc = 0;
    CServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CServerItem_SetServiceStatus'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        enServiceStatus arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "CServerItem:SetServiceStatus");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CServerItem_SetServiceStatus'", nullptr);
            return 0;
        }
        cobj->SetServiceStatus(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerItem:SetServiceStatus",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CServerItem_SetServiceStatus'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CServerItem_SetServerAttribute(lua_State* tolua_S)
{
    int argc = 0;
    CServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CServerItem_SetServerAttribute'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        CGameServerItem* arg0;
        unsigned short arg1;
        unsigned int arg2;

        ok &= luaval_to_object<CGameServerItem>(tolua_S, 2, "CGameServerItem",&arg0, "CServerItem:SetServerAttribute");

        ok &= luaval_to_ushort(tolua_S, 3, &arg1, "CServerItem:SetServerAttribute");

        ok &= luaval_to_uint32(tolua_S, 4,&arg2, "CServerItem:SetServerAttribute");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CServerItem_SetServerAttribute'", nullptr);
            return 0;
        }
        bool ret = cobj->SetServerAttribute(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerItem:SetServerAttribute",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CServerItem_SetServerAttribute'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CServerItem_SetServerItemSink(lua_State* tolua_S)
{
    int argc = 0;
    CServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CServerItem_SetServerItemSink'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        IServerItemSink* arg0;

        ok &= luaval_to_object<IServerItemSink>(tolua_S, 2, "IServerItemSink",&arg0, "CServerItem:SetServerItemSink");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CServerItem_SetServerItemSink'", nullptr);
            return 0;
        }
        bool ret = cobj->SetServerItemSink(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerItem:SetServerItemSink",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CServerItem_SetServerItemSink'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CServerItem_IntermitConnect(lua_State* tolua_S)
{
    int argc = 0;
    CServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CServerItem_IntermitConnect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "CServerItem:IntermitConnect");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CServerItem_IntermitConnect'", nullptr);
            return 0;
        }
        bool ret = cobj->IntermitConnect(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerItem:IntermitConnect",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CServerItem_IntermitConnect'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CServerItem_PerformBuyProperty(lua_State* tolua_S)
{
    int argc = 0;
    CServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CServerItem_PerformBuyProperty'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 4) 
    {
        uint16_t arg0;
        const char* arg1;
        unsigned short arg2;
        unsigned short arg3;

        ok &= luaval_to_uint16(tolua_S, 2,&arg0, "CServerItem:PerformBuyProperty");

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "CServerItem:PerformBuyProperty"); arg1 = arg1_tmp.c_str();

        ok &= luaval_to_ushort(tolua_S, 4, &arg2, "CServerItem:PerformBuyProperty");

        ok &= luaval_to_ushort(tolua_S, 5, &arg3, "CServerItem:PerformBuyProperty");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CServerItem_PerformBuyProperty'", nullptr);
            return 0;
        }
        bool ret = cobj->PerformBuyProperty(std::move(arg0), arg1, arg2, arg3);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerItem:PerformBuyProperty",argc, 4);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CServerItem_PerformBuyProperty'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CServerItem_SendStandUpPacket(lua_State* tolua_S)
{
    int argc = 0;
    CServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CServerItem_SendStandUpPacket'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        unsigned short arg0;
        unsigned short arg1;
        uint16_t arg2;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CServerItem:SendStandUpPacket");

        ok &= luaval_to_ushort(tolua_S, 3, &arg1, "CServerItem:SendStandUpPacket");

        ok &= luaval_to_uint16(tolua_S, 4,&arg2, "CServerItem:SendStandUpPacket");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CServerItem_SendStandUpPacket'", nullptr);
            return 0;
        }
        bool ret = cobj->SendStandUpPacket(arg0, arg1, std::move(arg2));
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerItem:SendStandUpPacket",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CServerItem_SendStandUpPacket'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CServerItem_SearchUserByNickName(lua_State* tolua_S)
{
    int argc = 0;
    CServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CServerItem_SearchUserByNickName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CServerItem:SearchUserByNickName"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CServerItem_SearchUserByNickName'", nullptr);
            return 0;
        }
        IClientUserItem* ret = cobj->SearchUserByNickName(arg0);
        object_to_luaval<IClientUserItem>(tolua_S, "IClientUserItem",(IClientUserItem*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerItem:SearchUserByNickName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CServerItem_SearchUserByNickName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CServerItem_SendFullApply(lua_State* tolua_S)
{
    int argc = 0;
    CServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CServerItem_SendFullApply'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        long long arg0;

        ok &= luaval_to_long_long(tolua_S, 2,&arg0, "CServerItem:SendFullApply");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CServerItem_SendFullApply'", nullptr);
            return 0;
        }
        bool ret = cobj->SendFullApply(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerItem:SendFullApply",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CServerItem_SendFullApply'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CServerItem_PerformStandUpAction(lua_State* tolua_S)
{
    int argc = 0;
    CServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CServerItem_PerformStandUpAction'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        unsigned short arg0;
        unsigned short arg1;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CServerItem:PerformStandUpAction");

        ok &= luaval_to_ushort(tolua_S, 3, &arg1, "CServerItem:PerformStandUpAction");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CServerItem_PerformStandUpAction'", nullptr);
            return 0;
        }
        bool ret = cobj->PerformStandUpAction(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerItem:PerformStandUpAction",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CServerItem_PerformStandUpAction'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CServerItem_SendUserChatPacket(lua_State* tolua_S)
{
    int argc = 0;
    CServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CServerItem_SendUserChatPacket'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        unsigned int arg0;
        const char* arg1;
        unsigned int arg2;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "CServerItem:SendUserChatPacket");

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "CServerItem:SendUserChatPacket"); arg1 = arg1_tmp.c_str();

        ok &= luaval_to_uint32(tolua_S, 4,&arg2, "CServerItem:SendUserChatPacket");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CServerItem_SendUserChatPacket'", nullptr);
            return 0;
        }
        bool ret = cobj->SendUserChatPacket(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerItem:SendUserChatPacket",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CServerItem_SendUserChatPacket'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CServerItem_PerformLookonAction(lua_State* tolua_S)
{
    int argc = 0;
    CServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CServerItem_PerformLookonAction'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        unsigned short arg0;
        unsigned short arg1;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CServerItem:PerformLookonAction");

        ok &= luaval_to_ushort(tolua_S, 3, &arg1, "CServerItem:PerformLookonAction");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CServerItem_PerformLookonAction'", nullptr);
            return 0;
        }
        bool ret = cobj->PerformLookonAction(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerItem:PerformLookonAction",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CServerItem_PerformLookonAction'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CServerItem_PerformAutoJoin(lua_State* tolua_S)
{
    int argc = 0;
    CServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CServerItem_PerformAutoJoin'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CServerItem_PerformAutoJoin'", nullptr);
            return 0;
        }
        bool ret = cobj->PerformAutoJoin();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerItem:PerformAutoJoin",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CServerItem_PerformAutoJoin'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CServerItem_OnGFGameReady(lua_State* tolua_S)
{
    int argc = 0;
    CServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CServerItem_OnGFGameReady'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "CServerItem:OnGFGameReady");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CServerItem_OnGFGameReady'", nullptr);
            return 0;
        }
        cobj->OnGFGameReady(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerItem:OnGFGameReady",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CServerItem_OnGFGameReady'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CServerItem_OnGFGameClose(lua_State* tolua_S)
{
    int argc = 0;
    CServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CServerItem_OnGFGameClose'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "CServerItem:OnGFGameClose");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CServerItem_OnGFGameClose'", nullptr);
            return 0;
        }
        cobj->OnGFGameClose(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerItem:OnGFGameClose",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CServerItem_OnGFGameClose'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CServerItem_GetServerAttribute(lua_State* tolua_S)
{
    int argc = 0;
    CServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CServerItem_GetServerAttribute'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CServerItem_GetServerAttribute'", nullptr);
            return 0;
        }
        tagServerAttribute* ret = cobj->GetServerAttribute();
        object_to_luaval<tagServerAttribute>(tolua_S, "tagServerAttribute",(tagServerAttribute*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerItem:GetServerAttribute",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CServerItem_GetServerAttribute'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CServerItem_GetTableItem(lua_State* tolua_S)
{
    int argc = 0;
    CServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CServerItem_GetTableItem'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CServerItem_GetTableItem'", nullptr);
            return 0;
        }
        CTableViewFrame* ret = cobj->GetTableItem();
        object_to_luaval<CTableViewFrame>(tolua_S, "CTableViewFrame",(CTableViewFrame*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerItem:GetTableItem",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CServerItem_GetTableItem'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CServerItem_GetTableUserItem(lua_State* tolua_S)
{
    int argc = 0;
    CServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CServerItem_GetTableUserItem'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CServerItem:GetTableUserItem");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CServerItem_GetTableUserItem'", nullptr);
            return 0;
        }
        IClientUserItem* ret = cobj->GetTableUserItem(arg0);
        object_to_luaval<IClientUserItem>(tolua_S, "IClientUserItem",(IClientUserItem*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerItem:GetTableUserItem",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CServerItem_GetTableUserItem'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CServerItem_ReconnectServer(lua_State* tolua_S)
{
    int argc = 0;
    CServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CServerItem_ReconnectServer'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        CGameServerItem* arg0;
        unsigned short arg1;
        unsigned int arg2;

        ok &= luaval_to_object<CGameServerItem>(tolua_S, 2, "CGameServerItem",&arg0, "CServerItem:ReconnectServer");

        ok &= luaval_to_ushort(tolua_S, 3, &arg1, "CServerItem:ReconnectServer");

        ok &= luaval_to_uint32(tolua_S, 4,&arg2, "CServerItem:ReconnectServer");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CServerItem_ReconnectServer'", nullptr);
            return 0;
        }
        bool ret = cobj->ReconnectServer(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerItem:ReconnectServer",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CServerItem_ReconnectServer'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CServerItem_GetServiceStatus(lua_State* tolua_S)
{
    int argc = 0;
    CServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CServerItem_GetServiceStatus'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CServerItem_GetServiceStatus'", nullptr);
            return 0;
        }
        int ret = (int)cobj->GetServiceStatus();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerItem:GetServiceStatus",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CServerItem_GetServiceStatus'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CServerItem_SendLookonPacket(lua_State* tolua_S)
{
    int argc = 0;
    CServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CServerItem_SendLookonPacket'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        unsigned short arg0;
        unsigned short arg1;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CServerItem:SendLookonPacket");

        ok &= luaval_to_ushort(tolua_S, 3, &arg1, "CServerItem:SendLookonPacket");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CServerItem_SendLookonPacket'", nullptr);
            return 0;
        }
        bool ret = cobj->SendLookonPacket(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerItem:SendLookonPacket",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CServerItem_SendLookonPacket'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CServerItem_SendLogonPacket(lua_State* tolua_S)
{
    int argc = 0;
    CServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CServerItem_SendLogonPacket'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CServerItem_SendLogonPacket'", nullptr);
            return 0;
        }
        bool ret = cobj->SendLogonPacket();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerItem:SendLogonPacket",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CServerItem_SendLogonPacket'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CServerItem_GetTableGameState(lua_State* tolua_S)
{
    int argc = 0;
    CServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CServerItem_GetTableGameState'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "CServerItem:GetTableGameState");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CServerItem_GetTableGameState'", nullptr);
            return 0;
        }
        bool ret = cobj->GetTableGameState(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerItem:GetTableGameState",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CServerItem_GetTableGameState'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CServerItem_GetMeUserItem(lua_State* tolua_S)
{
    int argc = 0;
    CServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CServerItem_GetMeUserItem'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CServerItem_GetMeUserItem'", nullptr);
            return 0;
        }
        IClientUserItem* ret = cobj->GetMeUserItem();
        object_to_luaval<IClientUserItem>(tolua_S, "IClientUserItem",(IClientUserItem*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerItem:GetMeUserItem",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CServerItem_GetMeUserItem'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CServerItem_constructor(lua_State* tolua_S)
{
    int argc = 0;
    CServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CServerItem_constructor'", nullptr);
            return 0;
        }
        cobj = new CServerItem();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"CServerItem");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerItem:CServerItem",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CServerItem_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_kernel_CServerItem_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CServerItem)");
    return 0;
}

int lua_register_cocos2dx_kernel_CServerItem(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CServerItem");
    tolua_cclass(tolua_S,"CServerItem","CServerItem","IServerItem",nullptr);

    tolua_beginmodule(tolua_S,"CServerItem");
        tolua_function(tolua_S,"new",lua_cocos2dx_kernel_CServerItem_constructor);
        tolua_function(tolua_S,"IsService",lua_cocos2dx_kernel_CServerItem_IsService);
        tolua_function(tolua_S,"SearchGameTable",lua_cocos2dx_kernel_CServerItem_SearchGameTable);
        tolua_function(tolua_S,"SendSocketData",lua_cocos2dx_kernel_CServerItem_SendSocketData);
        tolua_function(tolua_S,"TerminConnect",lua_cocos2dx_kernel_CServerItem_TerminConnect);
        tolua_function(tolua_S,"SendSocketDataLua",lua_cocos2dx_kernel_CServerItem_SendSocketDataLua);
        tolua_function(tolua_S,"AvertGameEnter",lua_cocos2dx_kernel_CServerItem_AvertGameEnter);
        tolua_function(tolua_S,"GetMeChairID",lua_cocos2dx_kernel_CServerItem_GetMeChairID);
        tolua_function(tolua_S,"SendUserRulePacket",lua_cocos2dx_kernel_CServerItem_SendUserRulePacket);
        tolua_function(tolua_S,"SetChatSink",lua_cocos2dx_kernel_CServerItem_SetChatSink);
        tolua_function(tolua_S,"SetStringMessageSink",lua_cocos2dx_kernel_CServerItem_SetStringMessageSink);
        tolua_function(tolua_S,"SendExpressionPacket",lua_cocos2dx_kernel_CServerItem_SendExpressionPacket);
        tolua_function(tolua_S,"OnUserFaceUpdate",lua_cocos2dx_kernel_CServerItem_OnUserFaceUpdate);
        tolua_function(tolua_S,"PerformSitDownAction",lua_cocos2dx_kernel_CServerItem_PerformSitDownAction);
        tolua_function(tolua_S,"GFSendData",lua_cocos2dx_kernel_CServerItem_GFSendData);
        tolua_function(tolua_S,"ConnectServer",lua_cocos2dx_kernel_CServerItem_ConnectServer);
        tolua_function(tolua_S,"GetUserAttribute",lua_cocos2dx_kernel_CServerItem_GetUserAttribute);
        tolua_function(tolua_S,"IsPlayingMySelf",lua_cocos2dx_kernel_CServerItem_IsPlayingMySelf);
        tolua_function(tolua_S,"SearchUserByUserID",lua_cocos2dx_kernel_CServerItem_SearchUserByUserID);
        tolua_function(tolua_S,"PerformQuickSitDown",lua_cocos2dx_kernel_CServerItem_PerformQuickSitDown);
        tolua_function(tolua_S,"SendSitDownPacket",lua_cocos2dx_kernel_CServerItem_SendSitDownPacket);
        tolua_function(tolua_S,"SearchUserByGameID",lua_cocos2dx_kernel_CServerItem_SearchUserByGameID);
        tolua_function(tolua_S,"IsDistributionTable",lua_cocos2dx_kernel_CServerItem_IsDistributionTable);
        tolua_function(tolua_S,"GetTableLockState",lua_cocos2dx_kernel_CServerItem_GetTableLockState);
        tolua_function(tolua_S,"GetActiveUserCount",lua_cocos2dx_kernel_CServerItem_GetActiveUserCount);
        tolua_function(tolua_S,"SendStandUp",lua_cocos2dx_kernel_CServerItem_SendStandUp);
        tolua_function(tolua_S,"ResumeConnect",lua_cocos2dx_kernel_CServerItem_ResumeConnect);
        tolua_function(tolua_S,"SetServiceStatus",lua_cocos2dx_kernel_CServerItem_SetServiceStatus);
        tolua_function(tolua_S,"SetServerAttribute",lua_cocos2dx_kernel_CServerItem_SetServerAttribute);
        tolua_function(tolua_S,"SetServerItemSink",lua_cocos2dx_kernel_CServerItem_SetServerItemSink);
        tolua_function(tolua_S,"IntermitConnect",lua_cocos2dx_kernel_CServerItem_IntermitConnect);
        tolua_function(tolua_S,"PerformBuyProperty",lua_cocos2dx_kernel_CServerItem_PerformBuyProperty);
        tolua_function(tolua_S,"SendStandUpPacket",lua_cocos2dx_kernel_CServerItem_SendStandUpPacket);
        tolua_function(tolua_S,"SearchUserByNickName",lua_cocos2dx_kernel_CServerItem_SearchUserByNickName);
        tolua_function(tolua_S,"SendFullApply",lua_cocos2dx_kernel_CServerItem_SendFullApply);
        tolua_function(tolua_S,"PerformStandUpAction",lua_cocos2dx_kernel_CServerItem_PerformStandUpAction);
        tolua_function(tolua_S,"SendUserChatPacket",lua_cocos2dx_kernel_CServerItem_SendUserChatPacket);
        tolua_function(tolua_S,"PerformLookonAction",lua_cocos2dx_kernel_CServerItem_PerformLookonAction);
        tolua_function(tolua_S,"PerformAutoJoin",lua_cocos2dx_kernel_CServerItem_PerformAutoJoin);
        tolua_function(tolua_S,"OnGFGameReady",lua_cocos2dx_kernel_CServerItem_OnGFGameReady);
        tolua_function(tolua_S,"OnGFGameClose",lua_cocos2dx_kernel_CServerItem_OnGFGameClose);
        tolua_function(tolua_S,"GetServerAttribute",lua_cocos2dx_kernel_CServerItem_GetServerAttribute);
        tolua_function(tolua_S,"GetTableItem",lua_cocos2dx_kernel_CServerItem_GetTableItem);
        tolua_function(tolua_S,"GetTableUserItem",lua_cocos2dx_kernel_CServerItem_GetTableUserItem);
        tolua_function(tolua_S,"ReconnectServer",lua_cocos2dx_kernel_CServerItem_ReconnectServer);
        tolua_function(tolua_S,"GetServiceStatus",lua_cocos2dx_kernel_CServerItem_GetServiceStatus);
        tolua_function(tolua_S,"SendLookonPacket",lua_cocos2dx_kernel_CServerItem_SendLookonPacket);
        tolua_function(tolua_S,"SendLogonPacket",lua_cocos2dx_kernel_CServerItem_SendLogonPacket);
        tolua_function(tolua_S,"GetTableGameState",lua_cocos2dx_kernel_CServerItem_GetTableGameState);
        tolua_function(tolua_S,"GetMeUserItem",lua_cocos2dx_kernel_CServerItem_GetMeUserItem);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CServerItem).name();
    g_luaType[typeName] = "CServerItem";
    g_typeCast["CServerItem"] = "CServerItem";
    return 1;
}

int lua_cocos2dx_kernel_CGameCenterManager_loadGameBaseData(lua_State* tolua_S)
{
    int argc = 0;
    CGameCenterManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGameCenterManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CGameCenterManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CGameCenterManager_loadGameBaseData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CGameCenterManager_loadGameBaseData'", nullptr);
            return 0;
        }
        cobj->loadGameBaseData();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameCenterManager:loadGameBaseData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CGameCenterManager_loadGameBaseData'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CGameCenterManager_AvertGameEnter(lua_State* tolua_S)
{
    int argc = 0;
    CGameCenterManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGameCenterManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CGameCenterManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CGameCenterManager_AvertGameEnter'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CGameCenterManager_AvertGameEnter'", nullptr);
            return 0;
        }
        cobj->AvertGameEnter();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameCenterManager:AvertGameEnter",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CGameCenterManager_AvertGameEnter'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CGameCenterManager_InsertUserLeave(lua_State* tolua_S)
{
    int argc = 0;
    CGameCenterManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGameCenterManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CGameCenterManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CGameCenterManager_InsertUserLeave'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CGameCenterManager:InsertUserLeave"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CGameCenterManager_InsertUserLeave'", nullptr);
            return 0;
        }
        bool ret = cobj->InsertUserLeave(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameCenterManager:InsertUserLeave",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CGameCenterManager_InsertUserLeave'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CGameCenterManager_GetGameServerItem(lua_State* tolua_S)
{
    int argc = 0;
    CGameCenterManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGameCenterManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CGameCenterManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CGameCenterManager_GetGameServerItem'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CGameCenterManager_GetGameServerItem'", nullptr);
            return 0;
        }
        CGameServerItem* ret = cobj->GetGameServerItem();
        object_to_luaval<CGameServerItem>(tolua_S, "CGameServerItem",(CGameServerItem*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameCenterManager:GetGameServerItem",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CGameCenterManager_GetGameServerItem'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CGameCenterManager_OnGRUserUpdate(lua_State* tolua_S)
{
    int argc = 0;
    CGameCenterManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGameCenterManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CGameCenterManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CGameCenterManager_OnGRUserUpdate'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        IClientUserItem* arg0;

        ok &= luaval_to_object<IClientUserItem>(tolua_S, 2, "IClientUserItem",&arg0, "CGameCenterManager:OnGRUserUpdate");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CGameCenterManager_OnGRUserUpdate'", nullptr);
            return 0;
        }
        cobj->OnGRUserUpdate(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameCenterManager:OnGRUserUpdate",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CGameCenterManager_OnGRUserUpdate'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CGameCenterManager_InsertUserEnter(lua_State* tolua_S)
{
    int argc = 0;
    CGameCenterManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGameCenterManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CGameCenterManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CGameCenterManager_InsertUserEnter'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CGameCenterManager:InsertUserEnter"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CGameCenterManager_InsertUserEnter'", nullptr);
            return 0;
        }
        bool ret = cobj->InsertUserEnter(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameCenterManager:InsertUserEnter",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CGameCenterManager_InsertUserEnter'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CGameCenterManager_InsertExpression(lua_State* tolua_S)
{
    int argc = 0;
    CGameCenterManager* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGameCenterManager",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CGameCenterManager*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CGameCenterManager_InsertExpression'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 3) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CGameCenterManager:InsertExpression"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            unsigned int arg1;
            ok &= luaval_to_uint32(tolua_S, 3,&arg1, "CGameCenterManager:InsertExpression");

            if (!ok) { break; }
            bool arg2;
            ok &= luaval_to_boolean(tolua_S, 4,&arg2, "CGameCenterManager:InsertExpression");

            if (!ok) { break; }
            bool ret = cobj->InsertExpression(arg0, arg1, arg2);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 2) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CGameCenterManager:InsertExpression"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            unsigned int arg1;
            ok &= luaval_to_uint32(tolua_S, 3,&arg1, "CGameCenterManager:InsertExpression");

            if (!ok) { break; }
            bool ret = cobj->InsertExpression(arg0, arg1);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 3) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CGameCenterManager:InsertExpression"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            const char* arg1;
            std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "CGameCenterManager:InsertExpression"); arg1 = arg1_tmp.c_str();

            if (!ok) { break; }
            unsigned int arg2;
            ok &= luaval_to_uint32(tolua_S, 4,&arg2, "CGameCenterManager:InsertExpression");

            if (!ok) { break; }
            bool ret = cobj->InsertExpression(arg0, arg1, arg2);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CGameCenterManager:InsertExpression",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CGameCenterManager_InsertExpression'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CGameCenterManager_getMatcState(lua_State* tolua_S)
{
    int argc = 0;
    CGameCenterManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGameCenterManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CGameCenterManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CGameCenterManager_getMatcState'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CGameCenterManager_getMatcState'", nullptr);
            return 0;
        }
        uint16_t ret = cobj->getMatcState();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameCenterManager:getMatcState",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CGameCenterManager_getMatcState'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CGameCenterManager_disconnectServer(lua_State* tolua_S)
{
    int argc = 0;
    CGameCenterManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGameCenterManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CGameCenterManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CGameCenterManager_disconnectServer'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CGameCenterManager_disconnectServer'", nullptr);
            return 0;
        }
        cobj->disconnectServer();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameCenterManager:disconnectServer",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CGameCenterManager_disconnectServer'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CGameCenterManager_OnGFServerClose(lua_State* tolua_S)
{
    int argc = 0;
    CGameCenterManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGameCenterManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CGameCenterManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CGameCenterManager_OnGFServerClose'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "CGameCenterManager:OnGFServerClose");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CGameCenterManager_OnGFServerClose'", nullptr);
            return 0;
        }
        cobj->OnGFServerClose(std::move(arg0));
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameCenterManager:OnGFServerClose",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CGameCenterManager_OnGFServerClose'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CGameCenterManager_setMatcState(lua_State* tolua_S)
{
    int argc = 0;
    CGameCenterManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGameCenterManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CGameCenterManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CGameCenterManager_setMatcState'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        uint16_t arg0;

        ok &= luaval_to_uint16(tolua_S, 2,&arg0, "CGameCenterManager:setMatcState");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CGameCenterManager_setMatcState'", nullptr);
            return 0;
        }
        cobj->setMatcState(std::move(arg0));
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameCenterManager:setMatcState",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CGameCenterManager_setMatcState'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CGameCenterManager_OnGFUserInviteFailure(lua_State* tolua_S)
{
    int argc = 0;
    CGameCenterManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGameCenterManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CGameCenterManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CGameCenterManager_OnGFUserInviteFailure'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "CGameCenterManager:OnGFUserInviteFailure");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CGameCenterManager_OnGFUserInviteFailure'", nullptr);
            return 0;
        }
        cobj->OnGFUserInviteFailure(std::move(arg0));
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameCenterManager:OnGFUserInviteFailure",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CGameCenterManager_OnGFUserInviteFailure'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CGameCenterManager_InsertUserChat(lua_State* tolua_S)
{
    int argc = 0;
    CGameCenterManager* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGameCenterManager",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CGameCenterManager*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CGameCenterManager_InsertUserChat'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 4) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CGameCenterManager:InsertUserChat"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            const char* arg1;
            std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "CGameCenterManager:InsertUserChat"); arg1 = arg1_tmp.c_str();

            if (!ok) { break; }
            const char* arg2;
            std::string arg2_tmp; ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp, "CGameCenterManager:InsertUserChat"); arg2 = arg2_tmp.c_str();

            if (!ok) { break; }
            unsigned int arg3;
            ok &= luaval_to_uint32(tolua_S, 5,&arg3, "CGameCenterManager:InsertUserChat");

            if (!ok) { break; }
            bool ret = cobj->InsertUserChat(arg0, arg1, arg2, arg3);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 3) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CGameCenterManager:InsertUserChat"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            const char* arg1;
            std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "CGameCenterManager:InsertUserChat"); arg1 = arg1_tmp.c_str();

            if (!ok) { break; }
            unsigned int arg2;
            ok &= luaval_to_uint32(tolua_S, 4,&arg2, "CGameCenterManager:InsertUserChat");

            if (!ok) { break; }
            bool ret = cobj->InsertUserChat(arg0, arg1, arg2);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CGameCenterManager:InsertUserChat",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CGameCenterManager_InsertUserChat'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CGameCenterManager_OnGRConfigFinish(lua_State* tolua_S)
{
    int argc = 0;
    CGameCenterManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGameCenterManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CGameCenterManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CGameCenterManager_OnGRConfigFinish'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CGameCenterManager_OnGRConfigFinish'", nullptr);
            return 0;
        }
        cobj->OnGRConfigFinish();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameCenterManager:OnGRConfigFinish",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CGameCenterManager_OnGRConfigFinish'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CGameCenterManager_InsertUserOffLine(lua_State* tolua_S)
{
    int argc = 0;
    CGameCenterManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGameCenterManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CGameCenterManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CGameCenterManager_InsertUserOffLine'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CGameCenterManager:InsertUserOffLine"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CGameCenterManager_InsertUserOffLine'", nullptr);
            return 0;
        }
        bool ret = cobj->InsertUserOffLine(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameCenterManager:InsertUserOffLine",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CGameCenterManager_InsertUserOffLine'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CGameCenterManager_init(lua_State* tolua_S)
{
    int argc = 0;
    CGameCenterManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGameCenterManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CGameCenterManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CGameCenterManager_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        CGameServerItem* arg0;

        ok &= luaval_to_object<CGameServerItem>(tolua_S, 2, "CGameServerItem",&arg0, "CGameCenterManager:init");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CGameCenterManager_init'", nullptr);
            return 0;
        }
        bool ret = cobj->init(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameCenterManager:init",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CGameCenterManager_init'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CGameCenterManager_InsertAfficheString(lua_State* tolua_S)
{
    int argc = 0;
    CGameCenterManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGameCenterManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CGameCenterManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CGameCenterManager_InsertAfficheString'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CGameCenterManager:InsertAfficheString"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CGameCenterManager_InsertAfficheString'", nullptr);
            return 0;
        }
        bool ret = cobj->InsertAfficheString(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameCenterManager:InsertAfficheString",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CGameCenterManager_InsertAfficheString'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CGameCenterManager_OnGFUserInvite(lua_State* tolua_S)
{
    int argc = 0;
    CGameCenterManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGameCenterManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CGameCenterManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CGameCenterManager_OnGFUserInvite'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "CGameCenterManager:OnGFUserInvite");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CGameCenterManager_OnGFUserInvite'", nullptr);
            return 0;
        }
        cobj->OnGFUserInvite(std::move(arg0));
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameCenterManager:OnGFUserInvite",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CGameCenterManager_OnGFUserInvite'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CGameCenterManager_InsertGladString(lua_State* tolua_S)
{
    int argc = 0;
    CGameCenterManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGameCenterManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CGameCenterManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CGameCenterManager_InsertGladString'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 6) 
    {
        const char* arg0;
        const char* arg1;
        const char* arg2;
        unsigned int arg3;
        unsigned int arg4;
        unsigned int arg5;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CGameCenterManager:InsertGladString"); arg0 = arg0_tmp.c_str();

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "CGameCenterManager:InsertGladString"); arg1 = arg1_tmp.c_str();

        std::string arg2_tmp; ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp, "CGameCenterManager:InsertGladString"); arg2 = arg2_tmp.c_str();

        ok &= luaval_to_uint32(tolua_S, 5,&arg3, "CGameCenterManager:InsertGladString");

        ok &= luaval_to_uint32(tolua_S, 6,&arg4, "CGameCenterManager:InsertGladString");

        ok &= luaval_to_uint32(tolua_S, 7,&arg5, "CGameCenterManager:InsertGladString");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CGameCenterManager_InsertGladString'", nullptr);
            return 0;
        }
        bool ret = cobj->InsertGladString(arg0, arg1, arg2, arg3, arg4, arg5);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameCenterManager:InsertGladString",argc, 6);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CGameCenterManager_InsertGladString'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CGameCenterManager_getCanCreateTable(lua_State* tolua_S)
{
    int argc = 0;
    CGameCenterManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGameCenterManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CGameCenterManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CGameCenterManager_getCanCreateTable'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CGameCenterManager_getCanCreateTable'", nullptr);
            return 0;
        }
        bool ret = cobj->getCanCreateTable();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameCenterManager:getCanCreateTable",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CGameCenterManager_getCanCreateTable'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CGameCenterManager_GetServerItem(lua_State* tolua_S)
{
    int argc = 0;
    CGameCenterManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGameCenterManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CGameCenterManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CGameCenterManager_GetServerItem'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CGameCenterManager_GetServerItem'", nullptr);
            return 0;
        }
        CServerItem* ret = cobj->GetServerItem();
        object_to_luaval<CServerItem>(tolua_S, "CServerItem",(CServerItem*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameCenterManager:GetServerItem",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CGameCenterManager_GetServerItem'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CGameCenterManager_InsertUserTrumpet(lua_State* tolua_S)
{
    int argc = 0;
    CGameCenterManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGameCenterManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CGameCenterManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CGameCenterManager_InsertUserTrumpet'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        const char* arg0;
        const char* arg1;
        unsigned int arg2;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CGameCenterManager:InsertUserTrumpet"); arg0 = arg0_tmp.c_str();

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "CGameCenterManager:InsertUserTrumpet"); arg1 = arg1_tmp.c_str();

        ok &= luaval_to_uint32(tolua_S, 4,&arg2, "CGameCenterManager:InsertUserTrumpet");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CGameCenterManager_InsertUserTrumpet'", nullptr);
            return 0;
        }
        bool ret = cobj->InsertUserTrumpet(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameCenterManager:InsertUserTrumpet",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CGameCenterManager_InsertUserTrumpet'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CGameCenterManager_OnConnectServerError(lua_State* tolua_S)
{
    int argc = 0;
    CGameCenterManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGameCenterManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CGameCenterManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CGameCenterManager_OnConnectServerError'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "CGameCenterManager:OnConnectServerError");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CGameCenterManager_OnConnectServerError'", nullptr);
            return 0;
        }
        cobj->OnConnectServerError(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameCenterManager:OnConnectServerError",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CGameCenterManager_OnConnectServerError'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CGameCenterManager_OnGRUserDelete(lua_State* tolua_S)
{
    int argc = 0;
    CGameCenterManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGameCenterManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CGameCenterManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CGameCenterManager_OnGRUserDelete'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        IClientUserItem* arg0;

        ok &= luaval_to_object<IClientUserItem>(tolua_S, 2, "IClientUserItem",&arg0, "CGameCenterManager:OnGRUserDelete");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CGameCenterManager_OnGRUserDelete'", nullptr);
            return 0;
        }
        cobj->OnGRUserDelete(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameCenterManager:OnGRUserDelete",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CGameCenterManager_OnGRUserDelete'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CGameCenterManager_setChangDesk(lua_State* tolua_S)
{
    int argc = 0;
    CGameCenterManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGameCenterManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CGameCenterManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CGameCenterManager_setChangDesk'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "CGameCenterManager:setChangDesk");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CGameCenterManager_setChangDesk'", nullptr);
            return 0;
        }
        cobj->setChangDesk(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameCenterManager:setChangDesk",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CGameCenterManager_setChangDesk'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CGameCenterManager_OnGRConfigServer(lua_State* tolua_S)
{
    int argc = 0;
    CGameCenterManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGameCenterManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CGameCenterManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CGameCenterManager_OnGRConfigServer'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CGameCenterManager_OnGRConfigServer'", nullptr);
            return 0;
        }
        cobj->OnGRConfigServer();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameCenterManager:OnGRConfigServer",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CGameCenterManager_OnGRConfigServer'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CGameCenterManager_InsertSystemChat(lua_State* tolua_S)
{
    int argc = 0;
    CGameCenterManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGameCenterManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CGameCenterManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CGameCenterManager_InsertSystemChat'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CGameCenterManager:InsertSystemChat"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CGameCenterManager_InsertSystemChat'", nullptr);
            return 0;
        }
        bool ret = cobj->InsertSystemChat(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameCenterManager:InsertSystemChat",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CGameCenterManager_InsertSystemChat'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CGameCenterManager_InsertWhisperChat(lua_State* tolua_S)
{
    int argc = 0;
    CGameCenterManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGameCenterManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CGameCenterManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CGameCenterManager_InsertWhisperChat'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 4) 
    {
        const char* arg0;
        const char* arg1;
        unsigned int arg2;
        bool arg3;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CGameCenterManager:InsertWhisperChat"); arg0 = arg0_tmp.c_str();

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "CGameCenterManager:InsertWhisperChat"); arg1 = arg1_tmp.c_str();

        ok &= luaval_to_uint32(tolua_S, 4,&arg2, "CGameCenterManager:InsertWhisperChat");

        ok &= luaval_to_boolean(tolua_S, 5,&arg3, "CGameCenterManager:InsertWhisperChat");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CGameCenterManager_InsertWhisperChat'", nullptr);
            return 0;
        }
        bool ret = cobj->InsertWhisperChat(arg0, arg1, arg2, arg3);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameCenterManager:InsertWhisperChat",argc, 4);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CGameCenterManager_InsertWhisperChat'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CGameCenterManager_OnGameClose(lua_State* tolua_S)
{
    int argc = 0;
    CGameCenterManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGameCenterManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CGameCenterManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CGameCenterManager_OnGameClose'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "CGameCenterManager:OnGameClose");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CGameCenterManager_OnGameClose'", nullptr);
            return 0;
        }
        bool ret = cobj->OnGameClose(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameCenterManager:OnGameClose",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CGameCenterManager_OnGameClose'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CGameCenterManager_OnGRConfigProperty(lua_State* tolua_S)
{
    int argc = 0;
    CGameCenterManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGameCenterManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CGameCenterManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CGameCenterManager_OnGRConfigProperty'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CGameCenterManager_OnGRConfigProperty'", nullptr);
            return 0;
        }
        cobj->OnGRConfigProperty();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameCenterManager:OnGRConfigProperty",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CGameCenterManager_OnGRConfigProperty'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CGameCenterManager_QuickSitdown(lua_State* tolua_S)
{
    int argc = 0;
    CGameCenterManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGameCenterManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CGameCenterManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CGameCenterManager_QuickSitdown'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        unsigned short arg0;
        unsigned short arg1;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CGameCenterManager:QuickSitdown");

        ok &= luaval_to_ushort(tolua_S, 3, &arg1, "CGameCenterManager:QuickSitdown");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CGameCenterManager_QuickSitdown'", nullptr);
            return 0;
        }
        cobj->QuickSitdown(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameCenterManager:QuickSitdown",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CGameCenterManager_QuickSitdown'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CGameCenterManager_InsertUserTyphon(lua_State* tolua_S)
{
    int argc = 0;
    CGameCenterManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGameCenterManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CGameCenterManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CGameCenterManager_InsertUserTyphon'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        const char* arg0;
        const char* arg1;
        unsigned int arg2;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CGameCenterManager:InsertUserTyphon"); arg0 = arg0_tmp.c_str();

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "CGameCenterManager:InsertUserTyphon"); arg1 = arg1_tmp.c_str();

        ok &= luaval_to_uint32(tolua_S, 4,&arg2, "CGameCenterManager:InsertUserTyphon");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CGameCenterManager_InsertUserTyphon'", nullptr);
            return 0;
        }
        bool ret = cobj->InsertUserTyphon(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameCenterManager:InsertUserTyphon",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CGameCenterManager_InsertUserTyphon'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CGameCenterManager_InsertNormalString(lua_State* tolua_S)
{
    int argc = 0;
    CGameCenterManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGameCenterManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CGameCenterManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CGameCenterManager_InsertNormalString'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CGameCenterManager:InsertNormalString"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CGameCenterManager_InsertNormalString'", nullptr);
            return 0;
        }
        bool ret = cobj->InsertNormalString(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameCenterManager:InsertNormalString",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CGameCenterManager_InsertNormalString'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CGameCenterManager_getChangDesk(lua_State* tolua_S)
{
    int argc = 0;
    CGameCenterManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGameCenterManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CGameCenterManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CGameCenterManager_getChangDesk'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CGameCenterManager_getChangDesk'", nullptr);
            return 0;
        }
        bool ret = cobj->getChangDesk();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameCenterManager:getChangDesk",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CGameCenterManager_getChangDesk'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CGameCenterManager_OnGRConfigColumn(lua_State* tolua_S)
{
    int argc = 0;
    CGameCenterManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGameCenterManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CGameCenterManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CGameCenterManager_OnGRConfigColumn'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CGameCenterManager_OnGRConfigColumn'", nullptr);
            return 0;
        }
        cobj->OnGRConfigColumn();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameCenterManager:OnGRConfigColumn",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CGameCenterManager_OnGRConfigColumn'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CGameCenterManager_connectServer(lua_State* tolua_S)
{
    int argc = 0;
    CGameCenterManager* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGameCenterManager",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CGameCenterManager*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CGameCenterManager_connectServer'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            CGameServerItem* arg0;
            ok &= luaval_to_object<CGameServerItem>(tolua_S, 2, "CGameServerItem",&arg0, "CGameCenterManager:connectServer");

            if (!ok) { break; }
            cobj->connectServer(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            cobj->connectServer();
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CGameCenterManager:connectServer",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CGameCenterManager_connectServer'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CGameCenterManager_reconnectServer(lua_State* tolua_S)
{
    int argc = 0;
    CGameCenterManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGameCenterManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CGameCenterManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CGameCenterManager_reconnectServer'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CGameCenterManager_reconnectServer'", nullptr);
            return 0;
        }
        cobj->reconnectServer();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameCenterManager:reconnectServer",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CGameCenterManager_reconnectServer'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CGameCenterManager_OnGRConfigUserRight(lua_State* tolua_S)
{
    int argc = 0;
    CGameCenterManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGameCenterManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CGameCenterManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CGameCenterManager_OnGRConfigUserRight'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CGameCenterManager_OnGRConfigUserRight'", nullptr);
            return 0;
        }
        cobj->OnGRConfigUserRight();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameCenterManager:OnGRConfigUserRight",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CGameCenterManager_OnGRConfigUserRight'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CGameCenterManager_setCanCreateTable(lua_State* tolua_S)
{
    int argc = 0;
    CGameCenterManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGameCenterManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CGameCenterManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CGameCenterManager_setCanCreateTable'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "CGameCenterManager:setCanCreateTable");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CGameCenterManager_setCanCreateTable'", nullptr);
            return 0;
        }
        cobj->setCanCreateTable(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameCenterManager:setCanCreateTable",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CGameCenterManager_setCanCreateTable'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CGameCenterManager_OnGRUserEnter(lua_State* tolua_S)
{
    int argc = 0;
    CGameCenterManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGameCenterManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CGameCenterManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CGameCenterManager_OnGRUserEnter'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        IClientUserItem* arg0;

        ok &= luaval_to_object<IClientUserItem>(tolua_S, 2, "IClientUserItem",&arg0, "CGameCenterManager:OnGRUserEnter");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CGameCenterManager_OnGRUserEnter'", nullptr);
            return 0;
        }
        cobj->OnGRUserEnter(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameCenterManager:OnGRUserEnter",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CGameCenterManager_OnGRUserEnter'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CGameCenterManager_InsertPromptString(lua_State* tolua_S)
{
    int argc = 0;
    CGameCenterManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGameCenterManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CGameCenterManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CGameCenterManager_InsertPromptString'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        int arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CGameCenterManager:InsertPromptString"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "CGameCenterManager:InsertPromptString");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CGameCenterManager_InsertPromptString'", nullptr);
            return 0;
        }
        int ret = cobj->InsertPromptString(arg0, arg1);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameCenterManager:InsertPromptString",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CGameCenterManager_InsertPromptString'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CGameCenterManager_StartGame(lua_State* tolua_S)
{
    int argc = 0;
    CGameCenterManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGameCenterManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CGameCenterManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CGameCenterManager_StartGame'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CGameCenterManager_StartGame'", nullptr);
            return 0;
        }
        bool ret = cobj->StartGame();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameCenterManager:StartGame",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CGameCenterManager_StartGame'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CGameCenterManager_InsertSystemString(lua_State* tolua_S)
{
    int argc = 0;
    CGameCenterManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGameCenterManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CGameCenterManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CGameCenterManager_InsertSystemString'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CGameCenterManager:InsertSystemString"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CGameCenterManager_InsertSystemString'", nullptr);
            return 0;
        }
        bool ret = cobj->InsertSystemString(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameCenterManager:InsertSystemString",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CGameCenterManager_InsertSystemString'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CGameCenterManager_CreateKernel(lua_State* tolua_S)
{
    int argc = 0;
    CGameCenterManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGameCenterManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CGameCenterManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CGameCenterManager_CreateKernel'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CGameCenterManager_CreateKernel'", nullptr);
            return 0;
        }
        bool ret = cobj->CreateKernel();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameCenterManager:CreateKernel",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CGameCenterManager_CreateKernel'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CGameCenterManager_Instance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CGameCenterManager",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CGameCenterManager_Instance'", nullptr);
            return 0;
        }
        CGameCenterManager* ret = CGameCenterManager::Instance();
        object_to_luaval<CGameCenterManager>(tolua_S, "CGameCenterManager",(CGameCenterManager*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CGameCenterManager:Instance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CGameCenterManager_Instance'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_kernel_CGameCenterManager_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CGameCenterManager)");
    return 0;
}

int lua_register_cocos2dx_kernel_CGameCenterManager(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CGameCenterManager");
    tolua_cclass(tolua_S,"CGameCenterManager","CGameCenterManager","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"CGameCenterManager");
        tolua_function(tolua_S,"loadGameBaseData",lua_cocos2dx_kernel_CGameCenterManager_loadGameBaseData);
        tolua_function(tolua_S,"AvertGameEnter",lua_cocos2dx_kernel_CGameCenterManager_AvertGameEnter);
        tolua_function(tolua_S,"InsertUserLeave",lua_cocos2dx_kernel_CGameCenterManager_InsertUserLeave);
        tolua_function(tolua_S,"GetGameServerItem",lua_cocos2dx_kernel_CGameCenterManager_GetGameServerItem);
        tolua_function(tolua_S,"OnGRUserUpdate",lua_cocos2dx_kernel_CGameCenterManager_OnGRUserUpdate);
        tolua_function(tolua_S,"InsertUserEnter",lua_cocos2dx_kernel_CGameCenterManager_InsertUserEnter);
        tolua_function(tolua_S,"InsertExpression",lua_cocos2dx_kernel_CGameCenterManager_InsertExpression);
        tolua_function(tolua_S,"getMatcState",lua_cocos2dx_kernel_CGameCenterManager_getMatcState);
        tolua_function(tolua_S,"disconnectServer",lua_cocos2dx_kernel_CGameCenterManager_disconnectServer);
        tolua_function(tolua_S,"OnGFServerClose",lua_cocos2dx_kernel_CGameCenterManager_OnGFServerClose);
        tolua_function(tolua_S,"setMatcState",lua_cocos2dx_kernel_CGameCenterManager_setMatcState);
        tolua_function(tolua_S,"OnGFUserInviteFailure",lua_cocos2dx_kernel_CGameCenterManager_OnGFUserInviteFailure);
        tolua_function(tolua_S,"InsertUserChat",lua_cocos2dx_kernel_CGameCenterManager_InsertUserChat);
        tolua_function(tolua_S,"OnGRConfigFinish",lua_cocos2dx_kernel_CGameCenterManager_OnGRConfigFinish);
        tolua_function(tolua_S,"InsertUserOffLine",lua_cocos2dx_kernel_CGameCenterManager_InsertUserOffLine);
        tolua_function(tolua_S,"init",lua_cocos2dx_kernel_CGameCenterManager_init);
        tolua_function(tolua_S,"InsertAfficheString",lua_cocos2dx_kernel_CGameCenterManager_InsertAfficheString);
        tolua_function(tolua_S,"OnGFUserInvite",lua_cocos2dx_kernel_CGameCenterManager_OnGFUserInvite);
        tolua_function(tolua_S,"InsertGladString",lua_cocos2dx_kernel_CGameCenterManager_InsertGladString);
        tolua_function(tolua_S,"getCanCreateTable",lua_cocos2dx_kernel_CGameCenterManager_getCanCreateTable);
        tolua_function(tolua_S,"GetServerItem",lua_cocos2dx_kernel_CGameCenterManager_GetServerItem);
        tolua_function(tolua_S,"InsertUserTrumpet",lua_cocos2dx_kernel_CGameCenterManager_InsertUserTrumpet);
        tolua_function(tolua_S,"OnConnectServerError",lua_cocos2dx_kernel_CGameCenterManager_OnConnectServerError);
        tolua_function(tolua_S,"OnGRUserDelete",lua_cocos2dx_kernel_CGameCenterManager_OnGRUserDelete);
        tolua_function(tolua_S,"setChangDesk",lua_cocos2dx_kernel_CGameCenterManager_setChangDesk);
        tolua_function(tolua_S,"OnGRConfigServer",lua_cocos2dx_kernel_CGameCenterManager_OnGRConfigServer);
        tolua_function(tolua_S,"InsertSystemChat",lua_cocos2dx_kernel_CGameCenterManager_InsertSystemChat);
        tolua_function(tolua_S,"InsertWhisperChat",lua_cocos2dx_kernel_CGameCenterManager_InsertWhisperChat);
        tolua_function(tolua_S,"OnGameClose",lua_cocos2dx_kernel_CGameCenterManager_OnGameClose);
        tolua_function(tolua_S,"OnGRConfigProperty",lua_cocos2dx_kernel_CGameCenterManager_OnGRConfigProperty);
        tolua_function(tolua_S,"QuickSitdown",lua_cocos2dx_kernel_CGameCenterManager_QuickSitdown);
        tolua_function(tolua_S,"InsertUserTyphon",lua_cocos2dx_kernel_CGameCenterManager_InsertUserTyphon);
        tolua_function(tolua_S,"InsertNormalString",lua_cocos2dx_kernel_CGameCenterManager_InsertNormalString);
        tolua_function(tolua_S,"getChangDesk",lua_cocos2dx_kernel_CGameCenterManager_getChangDesk);
        tolua_function(tolua_S,"OnGRConfigColumn",lua_cocos2dx_kernel_CGameCenterManager_OnGRConfigColumn);
        tolua_function(tolua_S,"connectServer",lua_cocos2dx_kernel_CGameCenterManager_connectServer);
        tolua_function(tolua_S,"reconnectServer",lua_cocos2dx_kernel_CGameCenterManager_reconnectServer);
        tolua_function(tolua_S,"OnGRConfigUserRight",lua_cocos2dx_kernel_CGameCenterManager_OnGRConfigUserRight);
        tolua_function(tolua_S,"setCanCreateTable",lua_cocos2dx_kernel_CGameCenterManager_setCanCreateTable);
        tolua_function(tolua_S,"OnGRUserEnter",lua_cocos2dx_kernel_CGameCenterManager_OnGRUserEnter);
        tolua_function(tolua_S,"InsertPromptString",lua_cocos2dx_kernel_CGameCenterManager_InsertPromptString);
        tolua_function(tolua_S,"StartGame",lua_cocos2dx_kernel_CGameCenterManager_StartGame);
        tolua_function(tolua_S,"InsertSystemString",lua_cocos2dx_kernel_CGameCenterManager_InsertSystemString);
        tolua_function(tolua_S,"CreateKernel",lua_cocos2dx_kernel_CGameCenterManager_CreateKernel);
        tolua_function(tolua_S,"Instance", lua_cocos2dx_kernel_CGameCenterManager_Instance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CGameCenterManager).name();
    g_luaType[typeName] = "CGameCenterManager";
    g_typeCast["CGameCenterManager"] = "CGameCenterManager";
    return 1;
}

int lua_cocos2dx_kernel_IClientKernel_SendSocketData(lua_State* tolua_S)
{
    int argc = 0;
    IClientKernel* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IClientKernel",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (IClientKernel*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IClientKernel_SendSocketData'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 4) {
            unsigned short arg0;
            ok &= luaval_to_ushort(tolua_S, 2, &arg0, "IClientKernel:SendSocketData");

            if (!ok) { break; }
            unsigned short arg1;
            ok &= luaval_to_ushort(tolua_S, 3, &arg1, "IClientKernel:SendSocketData");

            if (!ok) { break; }
            const char* arg2;
            std::string arg2_tmp; ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp, "IClientKernel:SendSocketData"); arg2 = arg2_tmp.c_str();

            if (!ok) { break; }
            unsigned short arg3;
            ok &= luaval_to_ushort(tolua_S, 5, &arg3, "IClientKernel:SendSocketData");

            if (!ok) { break; }
            bool ret = cobj->SendSocketData(arg0, arg1, arg2, arg3);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 2) {
            unsigned short arg0;
            ok &= luaval_to_ushort(tolua_S, 2, &arg0, "IClientKernel:SendSocketData");

            if (!ok) { break; }
            unsigned short arg1;
            ok &= luaval_to_ushort(tolua_S, 3, &arg1, "IClientKernel:SendSocketData");

            if (!ok) { break; }
            bool ret = cobj->SendSocketData(arg0, arg1);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "IClientKernel:SendSocketData",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientKernel_SendSocketData'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IClientKernel_GetGameStatus(lua_State* tolua_S)
{
    int argc = 0;
    IClientKernel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IClientKernel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IClientKernel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IClientKernel_GetGameStatus'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientKernel_GetGameStatus'", nullptr);
            return 0;
        }
        uint16_t ret = cobj->GetGameStatus();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IClientKernel:GetGameStatus",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientKernel_GetGameStatus'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IClientKernel_SendSocketDataLua(lua_State* tolua_S)
{
    int argc = 0;
    IClientKernel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IClientKernel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IClientKernel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IClientKernel_SendSocketDataLua'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 4) 
    {
        unsigned short arg0;
        unsigned short arg1;
        const cocos2d::Ref* arg2;
        unsigned short arg3;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "IClientKernel:SendSocketDataLua");

        ok &= luaval_to_ushort(tolua_S, 3, &arg1, "IClientKernel:SendSocketDataLua");

        ok &= luaval_to_object<const cocos2d::Ref>(tolua_S, 4, "cc.Ref",&arg2, "IClientKernel:SendSocketDataLua");

        ok &= luaval_to_ushort(tolua_S, 5, &arg3, "IClientKernel:SendSocketDataLua");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientKernel_SendSocketDataLua'", nullptr);
            return 0;
        }
        bool ret = cobj->SendSocketDataLua(arg0, arg1, arg2, arg3);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IClientKernel:SendSocketDataLua",argc, 4);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientKernel_SendSocketDataLua'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IClientKernel_SwitchViewChairID(lua_State* tolua_S)
{
    int argc = 0;
    IClientKernel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IClientKernel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IClientKernel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IClientKernel_SwitchViewChairID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "IClientKernel:SwitchViewChairID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientKernel_SwitchViewChairID'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->SwitchViewChairID(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IClientKernel:SwitchViewChairID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientKernel_SwitchViewChairID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IClientKernel_GetMeChairID(lua_State* tolua_S)
{
    int argc = 0;
    IClientKernel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IClientKernel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IClientKernel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IClientKernel_GetMeChairID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientKernel_GetMeChairID'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->GetMeChairID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IClientKernel:GetMeChairID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientKernel_GetMeChairID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IClientKernel_Init(lua_State* tolua_S)
{
    int argc = 0;
    IClientKernel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IClientKernel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IClientKernel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IClientKernel_Init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientKernel_Init'", nullptr);
            return 0;
        }
        bool ret = cobj->Init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IClientKernel:Init",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientKernel_Init'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IClientKernel_SetChatSink(lua_State* tolua_S)
{
    int argc = 0;
    IClientKernel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IClientKernel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IClientKernel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IClientKernel_SetChatSink'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        IChatSink* arg0;

        ok &= luaval_to_object<IChatSink>(tolua_S, 2, "IChatSink",&arg0, "IClientKernel:SetChatSink");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientKernel_SetChatSink'", nullptr);
            return 0;
        }
        bool ret = cobj->SetChatSink(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IClientKernel:SetChatSink",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientKernel_SetChatSink'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IClientKernel_SetStringMessageSink(lua_State* tolua_S)
{
    int argc = 0;
    IClientKernel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IClientKernel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IClientKernel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IClientKernel_SetStringMessageSink'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        IStringMessageSink* arg0;

        ok &= luaval_to_object<IStringMessageSink>(tolua_S, 2, "IStringMessageSink",&arg0, "IClientKernel:SetStringMessageSink");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientKernel_SetStringMessageSink'", nullptr);
            return 0;
        }
        bool ret = cobj->SetStringMessageSink(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IClientKernel:SetStringMessageSink",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientKernel_SetStringMessageSink'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IClientKernel_Intermit(lua_State* tolua_S)
{
    int argc = 0;
    IClientKernel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IClientKernel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IClientKernel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IClientKernel_Intermit'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "IClientKernel:Intermit");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientKernel_Intermit'", nullptr);
            return 0;
        }
        bool ret = cobj->Intermit(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IClientKernel:Intermit",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientKernel_Intermit'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IClientKernel_SetGameStatus(lua_State* tolua_S)
{
    int argc = 0;
    IClientKernel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IClientKernel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IClientKernel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IClientKernel_SetGameStatus'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        uint16_t arg0;

        ok &= luaval_to_uint16(tolua_S, 2,&arg0, "IClientKernel:SetGameStatus");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientKernel_SetGameStatus'", nullptr);
            return 0;
        }
        cobj->SetGameStatus(std::move(arg0));
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IClientKernel:SetGameStatus",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientKernel_SetGameStatus'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IClientKernel_SendGameOption(lua_State* tolua_S)
{
    int argc = 0;
    IClientKernel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IClientKernel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IClientKernel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IClientKernel_SendGameOption'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientKernel_SendGameOption'", nullptr);
            return 0;
        }
        bool ret = cobj->SendGameOption();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IClientKernel:SendGameOption",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientKernel_SendGameOption'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IClientKernel_SendUserReady(lua_State* tolua_S)
{
    int argc = 0;
    IClientKernel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IClientKernel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IClientKernel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IClientKernel_SendUserReady'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientKernel_SendUserReady'", nullptr);
            return 0;
        }
        bool ret = cobj->SendUserReady();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IClientKernel:SendUserReady",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientKernel_SendUserReady'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IClientKernel_GetUserAttribute(lua_State* tolua_S)
{
    int argc = 0;
    IClientKernel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IClientKernel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IClientKernel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IClientKernel_GetUserAttribute'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientKernel_GetUserAttribute'", nullptr);
            return 0;
        }
        tagUserAttribute* ret = cobj->GetUserAttribute();
        object_to_luaval<tagUserAttribute>(tolua_S, "tagUserAttribute",(tagUserAttribute*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IClientKernel:GetUserAttribute",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientKernel_GetUserAttribute'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IClientKernel_IsMatchRoom(lua_State* tolua_S)
{
    int argc = 0;
    IClientKernel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IClientKernel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IClientKernel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IClientKernel_IsMatchRoom'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientKernel_IsMatchRoom'", nullptr);
            return 0;
        }
        bool ret = cobj->IsMatchRoom();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IClientKernel:IsMatchRoom",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientKernel_IsMatchRoom'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IClientKernel_SearchUserByUserID(lua_State* tolua_S)
{
    int argc = 0;
    IClientKernel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IClientKernel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IClientKernel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IClientKernel_SearchUserByUserID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "IClientKernel:SearchUserByUserID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientKernel_SearchUserByUserID'", nullptr);
            return 0;
        }
        IClientUserItem* ret = cobj->SearchUserByUserID(arg0);
        object_to_luaval<IClientUserItem>(tolua_S, "IClientUserItem",(IClientUserItem*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IClientKernel:SearchUserByUserID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientKernel_SearchUserByUserID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IClientKernel_SendUserExpression(lua_State* tolua_S)
{
    int argc = 0;
    IClientKernel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IClientKernel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IClientKernel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IClientKernel_SendUserExpression'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        unsigned int arg0;
        unsigned short arg1;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "IClientKernel:SendUserExpression");

        ok &= luaval_to_ushort(tolua_S, 3, &arg1, "IClientKernel:SendUserExpression");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientKernel_SendUserExpression'", nullptr);
            return 0;
        }
        bool ret = cobj->SendUserExpression(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IClientKernel:SendUserExpression",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientKernel_SendUserExpression'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IClientKernel_SearchUserByGameID(lua_State* tolua_S)
{
    int argc = 0;
    IClientKernel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IClientKernel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IClientKernel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IClientKernel_SearchUserByGameID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "IClientKernel:SearchUserByGameID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientKernel_SearchUserByGameID'", nullptr);
            return 0;
        }
        IClientUserItem* ret = cobj->SearchUserByGameID(arg0);
        object_to_luaval<IClientUserItem>(tolua_S, "IClientUserItem",(IClientUserItem*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IClientKernel:SearchUserByGameID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientKernel_SearchUserByGameID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IClientKernel_GetGameAttribute(lua_State* tolua_S)
{
    int argc = 0;
    IClientKernel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IClientKernel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IClientKernel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IClientKernel_GetGameAttribute'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientKernel_GetGameAttribute'", nullptr);
            return 0;
        }
        tagGameAttribute* ret = cobj->GetGameAttribute();
        object_to_luaval<tagGameAttribute>(tolua_S, "tagGameAttribute",(tagGameAttribute*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IClientKernel:GetGameAttribute",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientKernel_GetGameAttribute'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IClientKernel_ActiveGameFrame(lua_State* tolua_S)
{
    int argc = 0;
    IClientKernel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IClientKernel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IClientKernel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IClientKernel_ActiveGameFrame'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientKernel_ActiveGameFrame'", nullptr);
            return 0;
        }
        cobj->ActiveGameFrame();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IClientKernel:ActiveGameFrame",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientKernel_ActiveGameFrame'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IClientKernel_IsSingleMode(lua_State* tolua_S)
{
    int argc = 0;
    IClientKernel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IClientKernel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IClientKernel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IClientKernel_IsSingleMode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientKernel_IsSingleMode'", nullptr);
            return 0;
        }
        bool ret = cobj->IsSingleMode();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IClientKernel:IsSingleMode",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientKernel_IsSingleMode'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IClientKernel_setGameServerItem(lua_State* tolua_S)
{
    int argc = 0;
    IClientKernel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IClientKernel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IClientKernel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IClientKernel_setGameServerItem'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        CGameServerItem* arg0;

        ok &= luaval_to_object<CGameServerItem>(tolua_S, 2, "CGameServerItem",&arg0, "IClientKernel:setGameServerItem");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientKernel_setGameServerItem'", nullptr);
            return 0;
        }
        cobj->setGameServerItem(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IClientKernel:setGameServerItem",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientKernel_setGameServerItem'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IClientKernel_IntermitConnect(lua_State* tolua_S)
{
    int argc = 0;
    IClientKernel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IClientKernel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IClientKernel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IClientKernel_IntermitConnect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "IClientKernel:IntermitConnect");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientKernel_IntermitConnect'", nullptr);
            return 0;
        }
        bool ret = cobj->IntermitConnect(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IClientKernel:IntermitConnect",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientKernel_IntermitConnect'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IClientKernel_SendUserLookon(lua_State* tolua_S)
{
    int argc = 0;
    IClientKernel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IClientKernel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IClientKernel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IClientKernel_SendUserLookon'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        unsigned int arg0;
        bool arg1;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "IClientKernel:SendUserLookon");

        ok &= luaval_to_boolean(tolua_S, 3,&arg1, "IClientKernel:SendUserLookon");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientKernel_SendUserLookon'", nullptr);
            return 0;
        }
        bool ret = cobj->SendUserLookon(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IClientKernel:SendUserLookon",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientKernel_SendUserLookon'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IClientKernel_SearchUserByNickName(lua_State* tolua_S)
{
    int argc = 0;
    IClientKernel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IClientKernel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IClientKernel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IClientKernel_SearchUserByNickName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "IClientKernel:SearchUserByNickName"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientKernel_SearchUserByNickName'", nullptr);
            return 0;
        }
        IClientUserItem* ret = cobj->SearchUserByNickName(arg0);
        object_to_luaval<IClientUserItem>(tolua_S, "IClientUserItem",(IClientUserItem*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IClientKernel:SearchUserByNickName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientKernel_SearchUserByNickName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IClientKernel_EnumLookonUserItem(lua_State* tolua_S)
{
    int argc = 0;
    IClientKernel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IClientKernel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IClientKernel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IClientKernel_EnumLookonUserItem'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "IClientKernel:EnumLookonUserItem");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientKernel_EnumLookonUserItem'", nullptr);
            return 0;
        }
        IClientUserItem* ret = cobj->EnumLookonUserItem(arg0);
        object_to_luaval<IClientUserItem>(tolua_S, "IClientUserItem",(IClientUserItem*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IClientKernel:EnumLookonUserItem",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientKernel_EnumLookonUserItem'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IClientKernel_GetServerAttribute(lua_State* tolua_S)
{
    int argc = 0;
    IClientKernel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IClientKernel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IClientKernel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IClientKernel_GetServerAttribute'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientKernel_GetServerAttribute'", nullptr);
            return 0;
        }
        tagServerAttribute* ret = cobj->GetServerAttribute();
        object_to_luaval<tagServerAttribute>(tolua_S, "tagServerAttribute",(tagServerAttribute*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IClientKernel:GetServerAttribute",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientKernel_GetServerAttribute'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IClientKernel_SendUserChatMessage(lua_State* tolua_S)
{
    int argc = 0;
    IClientKernel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IClientKernel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IClientKernel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IClientKernel_SendUserChatMessage'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        unsigned int arg0;
        const char* arg1;
        unsigned int arg2;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "IClientKernel:SendUserChatMessage");

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "IClientKernel:SendUserChatMessage"); arg1 = arg1_tmp.c_str();

        ok &= luaval_to_uint32(tolua_S, 4,&arg2, "IClientKernel:SendUserChatMessage");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientKernel_SendUserChatMessage'", nullptr);
            return 0;
        }
        bool ret = cobj->SendUserChatMessage(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IClientKernel:SendUserChatMessage",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientKernel_SendUserChatMessage'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IClientKernel_GetTableUserItem(lua_State* tolua_S)
{
    int argc = 0;
    IClientKernel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IClientKernel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IClientKernel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IClientKernel_GetTableUserItem'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "IClientKernel:GetTableUserItem");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientKernel_GetTableUserItem'", nullptr);
            return 0;
        }
        IClientUserItem* ret = cobj->GetTableUserItem(arg0);
        object_to_luaval<IClientUserItem>(tolua_S, "IClientUserItem",(IClientUserItem*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IClientKernel:GetTableUserItem",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientKernel_GetTableUserItem'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IClientKernel_getGameServerItem(lua_State* tolua_S)
{
    int argc = 0;
    IClientKernel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IClientKernel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IClientKernel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IClientKernel_getGameServerItem'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientKernel_getGameServerItem'", nullptr);
            return 0;
        }
        CGameServerItem* ret = cobj->getGameServerItem();
        object_to_luaval<CGameServerItem>(tolua_S, "CGameServerItem",(CGameServerItem*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IClientKernel:getGameServerItem",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientKernel_getGameServerItem'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IClientKernel_IsLookonMode(lua_State* tolua_S)
{
    int argc = 0;
    IClientKernel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IClientKernel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IClientKernel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IClientKernel_IsLookonMode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientKernel_IsLookonMode'", nullptr);
            return 0;
        }
        bool ret = cobj->IsLookonMode();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IClientKernel:IsLookonMode",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientKernel_IsLookonMode'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IClientKernel_IsAllowLookon(lua_State* tolua_S)
{
    int argc = 0;
    IClientKernel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IClientKernel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IClientKernel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IClientKernel_IsAllowLookon'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientKernel_IsAllowLookon'", nullptr);
            return 0;
        }
        bool ret = cobj->IsAllowLookon();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IClientKernel:IsAllowLookon",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientKernel_IsAllowLookon'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IClientKernel_GetMeUserItem(lua_State* tolua_S)
{
    int argc = 0;
    IClientKernel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IClientKernel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IClientKernel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IClientKernel_GetMeUserItem'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientKernel_GetMeUserItem'", nullptr);
            return 0;
        }
        IClientUserItem* ret = cobj->GetMeUserItem();
        object_to_luaval<IClientUserItem>(tolua_S, "IClientUserItem",(IClientUserItem*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IClientKernel:GetMeUserItem",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientKernel_GetMeUserItem'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IClientKernel_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"IClientKernel",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientKernel_create'", nullptr);
            return 0;
        }
        IClientKernel* ret = IClientKernel::create();
        object_to_luaval<IClientKernel>(tolua_S, "IClientKernel",(IClientKernel*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "IClientKernel:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientKernel_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_kernel_IClientKernel_get(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"IClientKernel",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientKernel_get'", nullptr);
            return 0;
        }
        IClientKernel* ret = IClientKernel::get();
        object_to_luaval<IClientKernel>(tolua_S, "IClientKernel",(IClientKernel*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "IClientKernel:get",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientKernel_get'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_kernel_IClientKernel_destory(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"IClientKernel",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IClientKernel_destory'", nullptr);
            return 0;
        }
        IClientKernel::destory();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "IClientKernel:destory",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IClientKernel_destory'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_kernel_IClientKernel_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (IClientKernel)");
    return 0;
}

int lua_register_cocos2dx_kernel_IClientKernel(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"IClientKernel");
    tolua_cclass(tolua_S,"IClientKernel","IClientKernel","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"IClientKernel");
        tolua_function(tolua_S,"SendSocketData",lua_cocos2dx_kernel_IClientKernel_SendSocketData);
        tolua_function(tolua_S,"GetGameStatus",lua_cocos2dx_kernel_IClientKernel_GetGameStatus);
        tolua_function(tolua_S,"SendSocketDataLua",lua_cocos2dx_kernel_IClientKernel_SendSocketDataLua);
        tolua_function(tolua_S,"SwitchViewChairID",lua_cocos2dx_kernel_IClientKernel_SwitchViewChairID);
        tolua_function(tolua_S,"GetMeChairID",lua_cocos2dx_kernel_IClientKernel_GetMeChairID);
        tolua_function(tolua_S,"Init",lua_cocos2dx_kernel_IClientKernel_Init);
        tolua_function(tolua_S,"SetChatSink",lua_cocos2dx_kernel_IClientKernel_SetChatSink);
        tolua_function(tolua_S,"SetStringMessageSink",lua_cocos2dx_kernel_IClientKernel_SetStringMessageSink);
        tolua_function(tolua_S,"Intermit",lua_cocos2dx_kernel_IClientKernel_Intermit);
        tolua_function(tolua_S,"SetGameStatus",lua_cocos2dx_kernel_IClientKernel_SetGameStatus);
        tolua_function(tolua_S,"SendGameOption",lua_cocos2dx_kernel_IClientKernel_SendGameOption);
        tolua_function(tolua_S,"SendUserReady",lua_cocos2dx_kernel_IClientKernel_SendUserReady);
        tolua_function(tolua_S,"GetUserAttribute",lua_cocos2dx_kernel_IClientKernel_GetUserAttribute);
        tolua_function(tolua_S,"IsMatchRoom",lua_cocos2dx_kernel_IClientKernel_IsMatchRoom);
        tolua_function(tolua_S,"SearchUserByUserID",lua_cocos2dx_kernel_IClientKernel_SearchUserByUserID);
        tolua_function(tolua_S,"SendUserExpression",lua_cocos2dx_kernel_IClientKernel_SendUserExpression);
        tolua_function(tolua_S,"SearchUserByGameID",lua_cocos2dx_kernel_IClientKernel_SearchUserByGameID);
        tolua_function(tolua_S,"GetGameAttribute",lua_cocos2dx_kernel_IClientKernel_GetGameAttribute);
        tolua_function(tolua_S,"ActiveGameFrame",lua_cocos2dx_kernel_IClientKernel_ActiveGameFrame);
        tolua_function(tolua_S,"IsSingleMode",lua_cocos2dx_kernel_IClientKernel_IsSingleMode);
        tolua_function(tolua_S,"setGameServerItem",lua_cocos2dx_kernel_IClientKernel_setGameServerItem);
        tolua_function(tolua_S,"IntermitConnect",lua_cocos2dx_kernel_IClientKernel_IntermitConnect);
        tolua_function(tolua_S,"SendUserLookon",lua_cocos2dx_kernel_IClientKernel_SendUserLookon);
        tolua_function(tolua_S,"SearchUserByNickName",lua_cocos2dx_kernel_IClientKernel_SearchUserByNickName);
        tolua_function(tolua_S,"EnumLookonUserItem",lua_cocos2dx_kernel_IClientKernel_EnumLookonUserItem);
        tolua_function(tolua_S,"GetServerAttribute",lua_cocos2dx_kernel_IClientKernel_GetServerAttribute);
        tolua_function(tolua_S,"SendUserChatMessage",lua_cocos2dx_kernel_IClientKernel_SendUserChatMessage);
        tolua_function(tolua_S,"GetTableUserItem",lua_cocos2dx_kernel_IClientKernel_GetTableUserItem);
        tolua_function(tolua_S,"getGameServerItem",lua_cocos2dx_kernel_IClientKernel_getGameServerItem);
        tolua_function(tolua_S,"IsLookonMode",lua_cocos2dx_kernel_IClientKernel_IsLookonMode);
        tolua_function(tolua_S,"IsAllowLookon",lua_cocos2dx_kernel_IClientKernel_IsAllowLookon);
        tolua_function(tolua_S,"GetMeUserItem",lua_cocos2dx_kernel_IClientKernel_GetMeUserItem);
        tolua_function(tolua_S,"create", lua_cocos2dx_kernel_IClientKernel_create);
        tolua_function(tolua_S,"get", lua_cocos2dx_kernel_IClientKernel_get);
        tolua_function(tolua_S,"destory", lua_cocos2dx_kernel_IClientKernel_destory);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(IClientKernel).name();
    g_luaType[typeName] = "IClientKernel";
    g_typeCast["IClientKernel"] = "IClientKernel";
    return 1;
}

int lua_cocos2dx_kernel_IGameTouchSink_onTouchMoved(lua_State* tolua_S)
{
    int argc = 0;
    IGameTouchSink* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IGameTouchSink",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IGameTouchSink*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IGameTouchSink_onTouchMoved'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Touch* arg0;
        cocos2d::Event* arg1;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0, "IGameTouchSink:onTouchMoved");

        ok &= luaval_to_object<cocos2d::Event>(tolua_S, 3, "cc.Event",&arg1, "IGameTouchSink:onTouchMoved");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IGameTouchSink_onTouchMoved'", nullptr);
            return 0;
        }
        cobj->onTouchMoved(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IGameTouchSink:onTouchMoved",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IGameTouchSink_onTouchMoved'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IGameTouchSink_onTouchEnded(lua_State* tolua_S)
{
    int argc = 0;
    IGameTouchSink* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IGameTouchSink",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IGameTouchSink*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IGameTouchSink_onTouchEnded'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Touch* arg0;
        cocos2d::Event* arg1;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0, "IGameTouchSink:onTouchEnded");

        ok &= luaval_to_object<cocos2d::Event>(tolua_S, 3, "cc.Event",&arg1, "IGameTouchSink:onTouchEnded");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IGameTouchSink_onTouchEnded'", nullptr);
            return 0;
        }
        cobj->onTouchEnded(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IGameTouchSink:onTouchEnded",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IGameTouchSink_onTouchEnded'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_IGameTouchSink_onTouchBegan(lua_State* tolua_S)
{
    int argc = 0;
    IGameTouchSink* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"IGameTouchSink",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (IGameTouchSink*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_IGameTouchSink_onTouchBegan'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Touch* arg0;
        cocos2d::Event* arg1;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0, "IGameTouchSink:onTouchBegan");

        ok &= luaval_to_object<cocos2d::Event>(tolua_S, 3, "cc.Event",&arg1, "IGameTouchSink:onTouchBegan");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_IGameTouchSink_onTouchBegan'", nullptr);
            return 0;
        }
        bool ret = cobj->onTouchBegan(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IGameTouchSink:onTouchBegan",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_IGameTouchSink_onTouchBegan'.",&tolua_err);
#endif

    return 0;
}
static int lua_cocos2dx_kernel_IGameTouchSink_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (IGameTouchSink)");
    return 0;
}

int lua_register_cocos2dx_kernel_IGameTouchSink(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"IGameTouchSink");
    tolua_cclass(tolua_S,"IGameTouchSink","IGameTouchSink","",nullptr);

    tolua_beginmodule(tolua_S,"IGameTouchSink");
        tolua_function(tolua_S,"onTouchMoved",lua_cocos2dx_kernel_IGameTouchSink_onTouchMoved);
        tolua_function(tolua_S,"onTouchEnded",lua_cocos2dx_kernel_IGameTouchSink_onTouchEnded);
        tolua_function(tolua_S,"onTouchBegan",lua_cocos2dx_kernel_IGameTouchSink_onTouchBegan);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(IGameTouchSink).name();
    g_luaType[typeName] = "IGameTouchSink";
    g_typeCast["IGameTouchSink"] = "IGameTouchSink";
    return 1;
}

int lua_cocos2dx_kernel_CGameScene_onTouchEnded(lua_State* tolua_S)
{
    int argc = 0;
    CGameScene* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGameScene",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CGameScene*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CGameScene_onTouchEnded'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Touch* arg0;
        cocos2d::Event* arg1;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0, "CGameScene:onTouchEnded");

        ok &= luaval_to_object<cocos2d::Event>(tolua_S, 3, "cc.Event",&arg1, "CGameScene:onTouchEnded");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CGameScene_onTouchEnded'", nullptr);
            return 0;
        }
        cobj->onTouchEnded(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameScene:onTouchEnded",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CGameScene_onTouchEnded'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CGameScene_sendTalkFile(lua_State* tolua_S)
{
    int argc = 0;
    CGameScene* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGameScene",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CGameScene*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CGameScene_sendTalkFile'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        int arg0;
        std::string arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "CGameScene:sendTalkFile");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "CGameScene:sendTalkFile");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CGameScene_sendTalkFile'", nullptr);
            return 0;
        }
        cobj->sendTalkFile(arg0, std::move(arg1));
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameScene:sendTalkFile",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CGameScene_sendTalkFile'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CGameScene_SwitchViewChairID(lua_State* tolua_S)
{
    int argc = 0;
    CGameScene* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGameScene",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CGameScene*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CGameScene_SwitchViewChairID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CGameScene:SwitchViewChairID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CGameScene_SwitchViewChairID'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->SwitchViewChairID(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameScene:SwitchViewChairID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CGameScene_SwitchViewChairID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CGameScene_sendTalkBiaoQing(lua_State* tolua_S)
{
    int argc = 0;
    CGameScene* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGameScene",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CGameScene*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CGameScene_sendTalkBiaoQing'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        int arg0;
        std::string arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "CGameScene:sendTalkBiaoQing");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "CGameScene:sendTalkBiaoQing");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CGameScene_sendTalkBiaoQing'", nullptr);
            return 0;
        }
        cobj->sendTalkBiaoQing(arg0, std::move(arg1));
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameScene:sendTalkBiaoQing",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CGameScene_sendTalkBiaoQing'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CGameScene_SetGameSceneSink(lua_State* tolua_S)
{
    int argc = 0;
    CGameScene* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGameScene",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CGameScene*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CGameScene_SetGameSceneSink'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        IGameSceneSink* arg0;

        ok &= luaval_to_object<IGameSceneSink>(tolua_S, 2, "IGameSceneSink",&arg0, "CGameScene:SetGameSceneSink");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CGameScene_SetGameSceneSink'", nullptr);
            return 0;
        }
        cobj->SetGameSceneSink(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameScene:SetGameSceneSink",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CGameScene_SetGameSceneSink'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CGameScene_SetGameFrameEngine(lua_State* tolua_S)
{
    int argc = 0;
    CGameScene* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGameScene",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CGameScene*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CGameScene_SetGameFrameEngine'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        CGameFrameEngine* arg0;

        ok &= luaval_to_object<CGameFrameEngine>(tolua_S, 2, "CGameFrameEngine",&arg0, "CGameScene:SetGameFrameEngine");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CGameScene_SetGameFrameEngine'", nullptr);
            return 0;
        }
        cobj->SetGameFrameEngine(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameScene:SetGameFrameEngine",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CGameScene_SetGameFrameEngine'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CGameScene_init(lua_State* tolua_S)
{
    int argc = 0;
    CGameScene* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGameScene",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CGameScene*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CGameScene_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CGameScene_init'", nullptr);
            return 0;
        }
        bool ret = cobj->init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameScene:init",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CGameScene_init'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CGameScene_sendTalkDefine(lua_State* tolua_S)
{
    int argc = 0;
    CGameScene* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGameScene",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CGameScene*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CGameScene_sendTalkDefine'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        int arg0;
        std::string arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "CGameScene:sendTalkDefine");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "CGameScene:sendTalkDefine");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CGameScene_sendTalkDefine'", nullptr);
            return 0;
        }
        cobj->sendTalkDefine(arg0, std::move(arg1));
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameScene:sendTalkDefine",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CGameScene_sendTalkDefine'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CGameScene_onTouchMoved(lua_State* tolua_S)
{
    int argc = 0;
    CGameScene* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGameScene",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CGameScene*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CGameScene_onTouchMoved'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Touch* arg0;
        cocos2d::Event* arg1;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0, "CGameScene:onTouchMoved");

        ok &= luaval_to_object<cocos2d::Event>(tolua_S, 3, "cc.Event",&arg1, "CGameScene:onTouchMoved");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CGameScene_onTouchMoved'", nullptr);
            return 0;
        }
        cobj->onTouchMoved(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameScene:onTouchMoved",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CGameScene_onTouchMoved'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CGameScene_onTouchBegan(lua_State* tolua_S)
{
    int argc = 0;
    CGameScene* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGameScene",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CGameScene*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CGameScene_onTouchBegan'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Touch* arg0;
        cocos2d::Event* arg1;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0, "CGameScene:onTouchBegan");

        ok &= luaval_to_object<cocos2d::Event>(tolua_S, 3, "cc.Event",&arg1, "CGameScene:onTouchBegan");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CGameScene_onTouchBegan'", nullptr);
            return 0;
        }
        bool ret = cobj->onTouchBegan(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameScene:onTouchBegan",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CGameScene_onTouchBegan'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CGameScene_OnNetDetectedInNetLossState(lua_State* tolua_S)
{
    int argc = 0;
    CGameScene* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGameScene",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CGameScene*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CGameScene_OnNetDetectedInNetLossState'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CGameScene_OnNetDetectedInNetLossState'", nullptr);
            return 0;
        }
        cobj->OnNetDetectedInNetLossState();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameScene:OnNetDetectedInNetLossState",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CGameScene_OnNetDetectedInNetLossState'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CGameScene_sendTalkString(lua_State* tolua_S)
{
    int argc = 0;
    CGameScene* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGameScene",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CGameScene*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CGameScene_sendTalkString'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        int arg0;
        std::string arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "CGameScene:sendTalkString");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "CGameScene:sendTalkString");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CGameScene_sendTalkString'", nullptr);
            return 0;
        }
        cobj->sendTalkString(arg0, std::move(arg1));
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameScene:sendTalkString",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CGameScene_sendTalkString'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CGameScene_onEnterTransitionDidFinish(lua_State* tolua_S)
{
    int argc = 0;
    CGameScene* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGameScene",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CGameScene*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CGameScene_onEnterTransitionDidFinish'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CGameScene_onEnterTransitionDidFinish'", nullptr);
            return 0;
        }
        cobj->onEnterTransitionDidFinish();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameScene:onEnterTransitionDidFinish",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CGameScene_onEnterTransitionDidFinish'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CGameScene_constructor(lua_State* tolua_S)
{
    int argc = 0;
    CGameScene* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CGameScene_constructor'", nullptr);
            return 0;
        }
        cobj = new CGameScene();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"CGameScene");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameScene:CGameScene",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CGameScene_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_kernel_CGameScene_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CGameScene)");
    return 0;
}

int lua_register_cocos2dx_kernel_CGameScene(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CGameScene");
    tolua_cclass(tolua_S,"CGameScene","CGameScene","cc.Layer",nullptr);

    tolua_beginmodule(tolua_S,"CGameScene");
        tolua_function(tolua_S,"new",lua_cocos2dx_kernel_CGameScene_constructor);
        tolua_function(tolua_S,"onTouchEnded",lua_cocos2dx_kernel_CGameScene_onTouchEnded);
        tolua_function(tolua_S,"sendTalkFile",lua_cocos2dx_kernel_CGameScene_sendTalkFile);
        tolua_function(tolua_S,"SwitchViewChairID",lua_cocos2dx_kernel_CGameScene_SwitchViewChairID);
        tolua_function(tolua_S,"sendTalkBiaoQing",lua_cocos2dx_kernel_CGameScene_sendTalkBiaoQing);
        tolua_function(tolua_S,"SetGameSceneSink",lua_cocos2dx_kernel_CGameScene_SetGameSceneSink);
        tolua_function(tolua_S,"SetGameFrameEngine",lua_cocos2dx_kernel_CGameScene_SetGameFrameEngine);
        tolua_function(tolua_S,"init",lua_cocos2dx_kernel_CGameScene_init);
        tolua_function(tolua_S,"sendTalkDefine",lua_cocos2dx_kernel_CGameScene_sendTalkDefine);
        tolua_function(tolua_S,"onTouchMoved",lua_cocos2dx_kernel_CGameScene_onTouchMoved);
        tolua_function(tolua_S,"onTouchBegan",lua_cocos2dx_kernel_CGameScene_onTouchBegan);
        tolua_function(tolua_S,"OnNetDetectedInNetLossState",lua_cocos2dx_kernel_CGameScene_OnNetDetectedInNetLossState);
        tolua_function(tolua_S,"sendTalkString",lua_cocos2dx_kernel_CGameScene_sendTalkString);
        tolua_function(tolua_S,"onEnterTransitionDidFinish",lua_cocos2dx_kernel_CGameScene_onEnterTransitionDidFinish);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CGameScene).name();
    g_luaType[typeName] = "CGameScene";
    g_typeCast["CGameScene"] = "CGameScene";
    return 1;
}

int lua_cocos2dx_kernel_GameTouchScene_onTouchMoved(lua_State* tolua_S)
{
    int argc = 0;
    GameTouchScene* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameTouchScene",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GameTouchScene*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_GameTouchScene_onTouchMoved'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Touch* arg0;
        cocos2d::Event* arg1;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0, "GameTouchScene:onTouchMoved");

        ok &= luaval_to_object<cocos2d::Event>(tolua_S, 3, "cc.Event",&arg1, "GameTouchScene:onTouchMoved");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_GameTouchScene_onTouchMoved'", nullptr);
            return 0;
        }
        cobj->onTouchMoved(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GameTouchScene:onTouchMoved",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_GameTouchScene_onTouchMoved'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_GameTouchScene_onTouchEnded(lua_State* tolua_S)
{
    int argc = 0;
    GameTouchScene* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameTouchScene",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GameTouchScene*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_GameTouchScene_onTouchEnded'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Touch* arg0;
        cocos2d::Event* arg1;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0, "GameTouchScene:onTouchEnded");

        ok &= luaval_to_object<cocos2d::Event>(tolua_S, 3, "cc.Event",&arg1, "GameTouchScene:onTouchEnded");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_GameTouchScene_onTouchEnded'", nullptr);
            return 0;
        }
        cobj->onTouchEnded(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GameTouchScene:onTouchEnded",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_GameTouchScene_onTouchEnded'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_GameTouchScene_onTouchBegan(lua_State* tolua_S)
{
    int argc = 0;
    GameTouchScene* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameTouchScene",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GameTouchScene*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_GameTouchScene_onTouchBegan'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Touch* arg0;
        cocos2d::Event* arg1;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0, "GameTouchScene:onTouchBegan");

        ok &= luaval_to_object<cocos2d::Event>(tolua_S, 3, "cc.Event",&arg1, "GameTouchScene:onTouchBegan");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_GameTouchScene_onTouchBegan'", nullptr);
            return 0;
        }
        bool ret = cobj->onTouchBegan(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GameTouchScene:onTouchBegan",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_GameTouchScene_onTouchBegan'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_GameTouchScene_init(lua_State* tolua_S)
{
    int argc = 0;
    GameTouchScene* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameTouchScene",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GameTouchScene*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_GameTouchScene_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_GameTouchScene_init'", nullptr);
            return 0;
        }
        bool ret = cobj->init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GameTouchScene:init",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_GameTouchScene_init'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_GameTouchScene_setGameTouchSink(lua_State* tolua_S)
{
    int argc = 0;
    GameTouchScene* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameTouchScene",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GameTouchScene*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_GameTouchScene_setGameTouchSink'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        CGameScene* arg0;

        ok &= luaval_to_object<CGameScene>(tolua_S, 2, "CGameScene",&arg0, "GameTouchScene:setGameTouchSink");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_GameTouchScene_setGameTouchSink'", nullptr);
            return 0;
        }
        cobj->setGameTouchSink(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GameTouchScene:setGameTouchSink",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_GameTouchScene_setGameTouchSink'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_GameTouchScene_onEnter(lua_State* tolua_S)
{
    int argc = 0;
    GameTouchScene* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameTouchScene",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GameTouchScene*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_GameTouchScene_onEnter'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_GameTouchScene_onEnter'", nullptr);
            return 0;
        }
        cobj->onEnter();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GameTouchScene:onEnter",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_GameTouchScene_onEnter'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_GameTouchScene_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"GameTouchScene",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_GameTouchScene_create'", nullptr);
            return 0;
        }
        GameTouchScene* ret = GameTouchScene::create();
        object_to_luaval<GameTouchScene>(tolua_S, "GameTouchScene",(GameTouchScene*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "GameTouchScene:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_GameTouchScene_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_kernel_GameTouchScene_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (GameTouchScene)");
    return 0;
}

int lua_register_cocos2dx_kernel_GameTouchScene(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"GameTouchScene");
    tolua_cclass(tolua_S,"GameTouchScene","GameTouchScene","cc.Layer",nullptr);

    tolua_beginmodule(tolua_S,"GameTouchScene");
        tolua_function(tolua_S,"onTouchMoved",lua_cocos2dx_kernel_GameTouchScene_onTouchMoved);
        tolua_function(tolua_S,"onTouchEnded",lua_cocos2dx_kernel_GameTouchScene_onTouchEnded);
        tolua_function(tolua_S,"onTouchBegan",lua_cocos2dx_kernel_GameTouchScene_onTouchBegan);
        tolua_function(tolua_S,"init",lua_cocos2dx_kernel_GameTouchScene_init);
        tolua_function(tolua_S,"setGameTouchSink",lua_cocos2dx_kernel_GameTouchScene_setGameTouchSink);
        tolua_function(tolua_S,"onEnter",lua_cocos2dx_kernel_GameTouchScene_onEnter);
        tolua_function(tolua_S,"create", lua_cocos2dx_kernel_GameTouchScene_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(GameTouchScene).name();
    g_luaType[typeName] = "GameTouchScene";
    g_typeCast["GameTouchScene"] = "GameTouchScene";
    return 1;
}

int lua_cocos2dx_kernel_SoundFun_SetSoundBackground(lua_State* tolua_S)
{
    int argc = 0;
    SoundFun* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundFun",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SoundFun*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_SoundFun_SetSoundBackground'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "SoundFun:SetSoundBackground");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_SoundFun_SetSoundBackground'", nullptr);
            return 0;
        }
        cobj->SetSoundBackground(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SoundFun:SetSoundBackground",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_SoundFun_SetSoundBackground'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_SoundFun_GetSoundBackground(lua_State* tolua_S)
{
    int argc = 0;
    SoundFun* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundFun",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SoundFun*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_SoundFun_GetSoundBackground'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_SoundFun_GetSoundBackground'", nullptr);
            return 0;
        }
        double ret = cobj->GetSoundBackground();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SoundFun:GetSoundBackground",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_SoundFun_GetSoundBackground'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_SoundFun_PaseEffectMusic(lua_State* tolua_S)
{
    int argc = 0;
    SoundFun* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundFun",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SoundFun*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_SoundFun_PaseEffectMusic'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_SoundFun_PaseEffectMusic'", nullptr);
            return 0;
        }
        cobj->PaseEffectMusic();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SoundFun:PaseEffectMusic",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_SoundFun_PaseEffectMusic'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_SoundFun_PlaySoundEffect(lua_State* tolua_S)
{
    int argc = 0;
    SoundFun* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundFun",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SoundFun*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_SoundFun_PlaySoundEffect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        int arg0;
        int arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "SoundFun:PlaySoundEffect");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "SoundFun:PlaySoundEffect");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_SoundFun_PlaySoundEffect'", nullptr);
            return 0;
        }
        cobj->PlaySoundEffect(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SoundFun:PlaySoundEffect",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_SoundFun_PlaySoundEffect'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_SoundFun_GetIsPlayEffect(lua_State* tolua_S)
{
    int argc = 0;
    SoundFun* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundFun",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SoundFun*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_SoundFun_GetIsPlayEffect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_SoundFun_GetIsPlayEffect'", nullptr);
            return 0;
        }
        bool ret = cobj->GetIsPlayEffect();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SoundFun:GetIsPlayEffect",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_SoundFun_GetIsPlayEffect'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_SoundFun_playCustomEffect(lua_State* tolua_S)
{
    int argc = 0;
    SoundFun* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundFun",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SoundFun*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_SoundFun_playCustomEffect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "SoundFun:playCustomEffect");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_SoundFun_playCustomEffect'", nullptr);
            return 0;
        }
        cobj->playCustomEffect(std::move(arg0));
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SoundFun:playCustomEffect",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_SoundFun_playCustomEffect'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_SoundFun_ResumeBackMusic(lua_State* tolua_S)
{
    int argc = 0;
    SoundFun* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundFun",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SoundFun*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_SoundFun_ResumeBackMusic'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_SoundFun_ResumeBackMusic'", nullptr);
            return 0;
        }
        cobj->ResumeBackMusic();
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "SoundFun:ResumeBackMusic");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_SoundFun_ResumeBackMusic'", nullptr);
            return 0;
        }
        cobj->ResumeBackMusic(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SoundFun:ResumeBackMusic",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_SoundFun_ResumeBackMusic'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_SoundFun_playBackMusic(lua_State* tolua_S)
{
    int argc = 0;
    SoundFun* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundFun",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SoundFun*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_SoundFun_playBackMusic'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "SoundFun:playBackMusic");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_SoundFun_playBackMusic'", nullptr);
            return 0;
        }
        cobj->playBackMusic(std::move(arg0));
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SoundFun:playBackMusic",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_SoundFun_playBackMusic'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_SoundFun_stopBackMusic(lua_State* tolua_S)
{
    int argc = 0;
    SoundFun* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundFun",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SoundFun*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_SoundFun_stopBackMusic'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_SoundFun_stopBackMusic'", nullptr);
            return 0;
        }
        cobj->stopBackMusic();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SoundFun:stopBackMusic",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_SoundFun_stopBackMusic'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_SoundFun_GetSoundEffect(lua_State* tolua_S)
{
    int argc = 0;
    SoundFun* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundFun",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SoundFun*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_SoundFun_GetSoundEffect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_SoundFun_GetSoundEffect'", nullptr);
            return 0;
        }
        double ret = cobj->GetSoundEffect();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SoundFun:GetSoundEffect",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_SoundFun_GetSoundEffect'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_SoundFun_SetSoundEffect(lua_State* tolua_S)
{
    int argc = 0;
    SoundFun* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundFun",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SoundFun*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_SoundFun_SetSoundEffect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "SoundFun:SetSoundEffect");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_SoundFun_SetSoundEffect'", nullptr);
            return 0;
        }
        cobj->SetSoundEffect(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SoundFun:SetSoundEffect",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_SoundFun_SetSoundEffect'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_SoundFun_playEffectDirect(lua_State* tolua_S)
{
    int argc = 0;
    SoundFun* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundFun",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SoundFun*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_SoundFun_playEffectDirect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "SoundFun:playEffectDirect");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_SoundFun_playEffectDirect'", nullptr);
            return 0;
        }
        cobj->playEffectDirect(std::move(arg0));
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 2) 
    {
        std::string arg0;
        bool arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "SoundFun:playEffectDirect");

        ok &= luaval_to_boolean(tolua_S, 3,&arg1, "SoundFun:playEffectDirect");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_SoundFun_playEffectDirect'", nullptr);
            return 0;
        }
        cobj->playEffectDirect(std::move(arg0), arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SoundFun:playEffectDirect",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_SoundFun_playEffectDirect'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_SoundFun_GetIsPalyMusic(lua_State* tolua_S)
{
    int argc = 0;
    SoundFun* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundFun",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SoundFun*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_SoundFun_GetIsPalyMusic'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_SoundFun_GetIsPalyMusic'", nullptr);
            return 0;
        }
        bool ret = cobj->GetIsPalyMusic();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SoundFun:GetIsPalyMusic",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_SoundFun_GetIsPalyMusic'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_SoundFun_OnResumeEffectMusic(lua_State* tolua_S)
{
    int argc = 0;
    SoundFun* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundFun",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SoundFun*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_SoundFun_OnResumeEffectMusic'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_SoundFun_OnResumeEffectMusic'", nullptr);
            return 0;
        }
        cobj->OnResumeEffectMusic();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SoundFun:OnResumeEffectMusic",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_SoundFun_OnResumeEffectMusic'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_SoundFun_setUseSoudType(lua_State* tolua_S)
{
    int argc = 0;
    SoundFun* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundFun",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SoundFun*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_SoundFun_setUseSoudType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "SoundFun:setUseSoudType");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_SoundFun_setUseSoudType'", nullptr);
            return 0;
        }
        cobj->setUseSoudType(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SoundFun:setUseSoudType",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_SoundFun_setUseSoudType'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_SoundFun_playCardByGender(lua_State* tolua_S)
{
    int argc = 0;
    SoundFun* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundFun",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SoundFun*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_SoundFun_playCardByGender'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        int arg0;
        std::string arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "SoundFun:playCardByGender");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "SoundFun:playCardByGender");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_SoundFun_playCardByGender'", nullptr);
            return 0;
        }
        cobj->playCardByGender(arg0, std::move(arg1));
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 3) 
    {
        int arg0;
        std::string arg1;
        bool arg2;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "SoundFun:playCardByGender");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "SoundFun:playCardByGender");

        ok &= luaval_to_boolean(tolua_S, 4,&arg2, "SoundFun:playCardByGender");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_SoundFun_playCardByGender'", nullptr);
            return 0;
        }
        cobj->playCardByGender(arg0, std::move(arg1), arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SoundFun:playCardByGender",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_SoundFun_playCardByGender'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_SoundFun_SetEffect(lua_State* tolua_S)
{
    int argc = 0;
    SoundFun* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundFun",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SoundFun*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_SoundFun_SetEffect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "SoundFun:SetEffect");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_SoundFun_SetEffect'", nullptr);
            return 0;
        }
        cobj->SetEffect(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SoundFun:SetEffect",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_SoundFun_SetEffect'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_SoundFun_OnResumeBackMusic(lua_State* tolua_S)
{
    int argc = 0;
    SoundFun* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundFun",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SoundFun*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_SoundFun_OnResumeBackMusic'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_SoundFun_OnResumeBackMusic'", nullptr);
            return 0;
        }
        cobj->OnResumeBackMusic();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SoundFun:OnResumeBackMusic",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_SoundFun_OnResumeBackMusic'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_SoundFun_PreloadEffectByGender(lua_State* tolua_S)
{
    int argc = 0;
    SoundFun* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundFun",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SoundFun*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_SoundFun_PreloadEffectByGender'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "SoundFun:PreloadEffectByGender");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_SoundFun_PreloadEffectByGender'", nullptr);
            return 0;
        }
        cobj->PreloadEffectByGender(std::move(arg0));
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SoundFun:PreloadEffectByGender",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_SoundFun_PreloadEffectByGender'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_SoundFun_SetPlayMusic(lua_State* tolua_S)
{
    int argc = 0;
    SoundFun* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundFun",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SoundFun*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_SoundFun_SetPlayMusic'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "SoundFun:SetPlayMusic");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_SoundFun_SetPlayMusic'", nullptr);
            return 0;
        }
        cobj->SetPlayMusic(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SoundFun:SetPlayMusic",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_SoundFun_SetPlayMusic'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_SoundFun_ResumeEffectMusic(lua_State* tolua_S)
{
    int argc = 0;
    SoundFun* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundFun",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SoundFun*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_SoundFun_ResumeEffectMusic'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_SoundFun_ResumeEffectMusic'", nullptr);
            return 0;
        }
        cobj->ResumeEffectMusic();
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "SoundFun:ResumeEffectMusic");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_SoundFun_ResumeEffectMusic'", nullptr);
            return 0;
        }
        cobj->ResumeEffectMusic(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SoundFun:ResumeEffectMusic",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_SoundFun_ResumeEffectMusic'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_SoundFun_playEffect(lua_State* tolua_S)
{
    int argc = 0;
    SoundFun* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundFun",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SoundFun*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_SoundFun_playEffect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "SoundFun:playEffect");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_SoundFun_playEffect'", nullptr);
            return 0;
        }
        cobj->playEffect(std::move(arg0));
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 2) 
    {
        std::string arg0;
        bool arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "SoundFun:playEffect");

        ok &= luaval_to_boolean(tolua_S, 3,&arg1, "SoundFun:playEffect");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_SoundFun_playEffect'", nullptr);
            return 0;
        }
        cobj->playEffect(std::move(arg0), arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SoundFun:playEffect",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_SoundFun_playEffect'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_SoundFun_getMute(lua_State* tolua_S)
{
    int argc = 0;
    SoundFun* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundFun",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SoundFun*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_SoundFun_getMute'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_SoundFun_getMute'", nullptr);
            return 0;
        }
        bool ret = cobj->getMute();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SoundFun:getMute",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_SoundFun_getMute'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_SoundFun_setMute(lua_State* tolua_S)
{
    int argc = 0;
    SoundFun* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundFun",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SoundFun*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_SoundFun_setMute'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "SoundFun:setMute");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_SoundFun_setMute'", nullptr);
            return 0;
        }
        cobj->setMute(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SoundFun:setMute",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_SoundFun_setMute'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_SoundFun_PauseBackMusic(lua_State* tolua_S)
{
    int argc = 0;
    SoundFun* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SoundFun",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SoundFun*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_SoundFun_PauseBackMusic'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_SoundFun_PauseBackMusic'", nullptr);
            return 0;
        }
        cobj->PauseBackMusic();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SoundFun:PauseBackMusic",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_SoundFun_PauseBackMusic'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_SoundFun_Instance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"SoundFun",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_SoundFun_Instance'", nullptr);
            return 0;
        }
        SoundFun* ret = SoundFun::Instance();
        object_to_luaval<SoundFun>(tolua_S, "SoundFun",(SoundFun*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "SoundFun:Instance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_SoundFun_Instance'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_kernel_SoundFun_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (SoundFun)");
    return 0;
}

int lua_register_cocos2dx_kernel_SoundFun(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"SoundFun");
    tolua_cclass(tolua_S,"SoundFun","SoundFun","TimeNode",nullptr);

    tolua_beginmodule(tolua_S,"SoundFun");
        tolua_function(tolua_S,"SetSoundBackground",lua_cocos2dx_kernel_SoundFun_SetSoundBackground);
        tolua_function(tolua_S,"GetSoundBackground",lua_cocos2dx_kernel_SoundFun_GetSoundBackground);
        tolua_function(tolua_S,"PaseEffectMusic",lua_cocos2dx_kernel_SoundFun_PaseEffectMusic);
        tolua_function(tolua_S,"PlaySoundEffect",lua_cocos2dx_kernel_SoundFun_PlaySoundEffect);
        tolua_function(tolua_S,"GetIsPlayEffect",lua_cocos2dx_kernel_SoundFun_GetIsPlayEffect);
        tolua_function(tolua_S,"playCustomEffect",lua_cocos2dx_kernel_SoundFun_playCustomEffect);
        tolua_function(tolua_S,"ResumeBackMusic",lua_cocos2dx_kernel_SoundFun_ResumeBackMusic);
        tolua_function(tolua_S,"playBackMusic",lua_cocos2dx_kernel_SoundFun_playBackMusic);
        tolua_function(tolua_S,"stopBackMusic",lua_cocos2dx_kernel_SoundFun_stopBackMusic);
        tolua_function(tolua_S,"GetSoundEffect",lua_cocos2dx_kernel_SoundFun_GetSoundEffect);
        tolua_function(tolua_S,"SetSoundEffect",lua_cocos2dx_kernel_SoundFun_SetSoundEffect);
        tolua_function(tolua_S,"playEffectDirect",lua_cocos2dx_kernel_SoundFun_playEffectDirect);
        tolua_function(tolua_S,"GetIsPalyMusic",lua_cocos2dx_kernel_SoundFun_GetIsPalyMusic);
        tolua_function(tolua_S,"OnResumeEffectMusic",lua_cocos2dx_kernel_SoundFun_OnResumeEffectMusic);
        tolua_function(tolua_S,"setUseSoudType",lua_cocos2dx_kernel_SoundFun_setUseSoudType);
        tolua_function(tolua_S,"playCardByGender",lua_cocos2dx_kernel_SoundFun_playCardByGender);
        tolua_function(tolua_S,"SetEffect",lua_cocos2dx_kernel_SoundFun_SetEffect);
        tolua_function(tolua_S,"OnResumeBackMusic",lua_cocos2dx_kernel_SoundFun_OnResumeBackMusic);
        tolua_function(tolua_S,"PreloadEffectByGender",lua_cocos2dx_kernel_SoundFun_PreloadEffectByGender);
        tolua_function(tolua_S,"SetPlayMusic",lua_cocos2dx_kernel_SoundFun_SetPlayMusic);
        tolua_function(tolua_S,"ResumeEffectMusic",lua_cocos2dx_kernel_SoundFun_ResumeEffectMusic);
        tolua_function(tolua_S,"playEffect",lua_cocos2dx_kernel_SoundFun_playEffect);
        tolua_function(tolua_S,"getMute",lua_cocos2dx_kernel_SoundFun_getMute);
        tolua_function(tolua_S,"setMute",lua_cocos2dx_kernel_SoundFun_setMute);
        tolua_function(tolua_S,"PauseBackMusic",lua_cocos2dx_kernel_SoundFun_PauseBackMusic);
        tolua_function(tolua_S,"Instance", lua_cocos2dx_kernel_SoundFun_Instance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(SoundFun).name();
    g_luaType[typeName] = "SoundFun";
    g_typeCast["SoundFun"] = "SoundFun";
    return 1;
}

int lua_cocos2dx_kernel_CGameFrameEngine_RecvTalk(lua_State* tolua_S)
{
    int argc = 0;
    CGameFrameEngine* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGameFrameEngine",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CGameFrameEngine*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CGameFrameEngine_RecvTalk'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        void* arg0;
        int arg1;

        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "CGameFrameEngine:RecvTalk");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CGameFrameEngine_RecvTalk'", nullptr);
            return 0;
        }
        bool ret = cobj->RecvTalk(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameFrameEngine:RecvTalk",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CGameFrameEngine_RecvTalk'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CGameFrameEngine_Clear(lua_State* tolua_S)
{
    int argc = 0;
    CGameFrameEngine* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGameFrameEngine",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CGameFrameEngine*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CGameFrameEngine_Clear'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CGameFrameEngine_Clear'", nullptr);
            return 0;
        }
        cobj->Clear();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameFrameEngine:Clear",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CGameFrameEngine_Clear'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CGameFrameEngine_SetGameFrameEngineSink(lua_State* tolua_S)
{
    int argc = 0;
    CGameFrameEngine* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGameFrameEngine",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CGameFrameEngine*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CGameFrameEngine_SetGameFrameEngineSink'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        IGameFrameEngineSink* arg0;

        ok &= luaval_to_object<IGameFrameEngineSink>(tolua_S, 2, "IGameFrameEngineSink",&arg0, "CGameFrameEngine:SetGameFrameEngineSink");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CGameFrameEngine_SetGameFrameEngineSink'", nullptr);
            return 0;
        }
        cobj->SetGameFrameEngineSink(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameFrameEngine:SetGameFrameEngineSink",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CGameFrameEngine_SetGameFrameEngineSink'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CGameFrameEngine_Destroy(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CGameFrameEngine",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CGameFrameEngine_Destroy'", nullptr);
            return 0;
        }
        CGameFrameEngine::Destroy();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CGameFrameEngine:Destroy",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CGameFrameEngine_Destroy'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_kernel_CGameFrameEngine_Get(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CGameFrameEngine",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CGameFrameEngine_Get'", nullptr);
            return 0;
        }
        CGameFrameEngine* ret = CGameFrameEngine::Get();
        object_to_luaval<CGameFrameEngine>(tolua_S, "CGameFrameEngine",(CGameFrameEngine*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CGameFrameEngine:Get",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CGameFrameEngine_Get'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_kernel_CGameFrameEngine_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CGameFrameEngine)");
    return 0;
}

int lua_register_cocos2dx_kernel_CGameFrameEngine(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CGameFrameEngine");
    tolua_cclass(tolua_S,"CGameFrameEngine","CGameFrameEngine","IClientKernelSink",nullptr);

    tolua_beginmodule(tolua_S,"CGameFrameEngine");
        tolua_function(tolua_S,"RecvTalk",lua_cocos2dx_kernel_CGameFrameEngine_RecvTalk);
        tolua_function(tolua_S,"Clear",lua_cocos2dx_kernel_CGameFrameEngine_Clear);
        tolua_function(tolua_S,"SetGameFrameEngineSink",lua_cocos2dx_kernel_CGameFrameEngine_SetGameFrameEngineSink);
        tolua_function(tolua_S,"Destroy", lua_cocos2dx_kernel_CGameFrameEngine_Destroy);
        tolua_function(tolua_S,"Get", lua_cocos2dx_kernel_CGameFrameEngine_Get);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CGameFrameEngine).name();
    g_luaType[typeName] = "CGameFrameEngine";
    g_typeCast["CGameFrameEngine"] = "CGameFrameEngine";
    return 1;
}

int lua_cocos2dx_kernel_ISocketSink_onSocketData(lua_State* tolua_S)
{
    int argc = 0;
    ISocketSink* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ISocketSink",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ISocketSink*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_ISocketSink_onSocketData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        void* arg0;
        int arg1;

        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "ISocketSink:onSocketData");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_ISocketSink_onSocketData'", nullptr);
            return 0;
        }
        cobj->onSocketData(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ISocketSink:onSocketData",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_ISocketSink_onSocketData'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_ISocketSink_onSocketShut(lua_State* tolua_S)
{
    int argc = 0;
    ISocketSink* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ISocketSink",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ISocketSink*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_ISocketSink_onSocketShut'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_ISocketSink_onSocketShut'", nullptr);
            return 0;
        }
        cobj->onSocketShut();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ISocketSink:onSocketShut",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_ISocketSink_onSocketShut'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_ISocketSink_onSocketLink(lua_State* tolua_S)
{
    int argc = 0;
    ISocketSink* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ISocketSink",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ISocketSink*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_ISocketSink_onSocketLink'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_ISocketSink_onSocketLink'", nullptr);
            return 0;
        }
        cobj->onSocketLink();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ISocketSink:onSocketLink",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_ISocketSink_onSocketLink'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_ISocketSink_onSocketCallBack(lua_State* tolua_S)
{
    int argc = 0;
    ISocketSink* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ISocketSink",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ISocketSink*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_ISocketSink_onSocketCallBack'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Ref* arg0;

        ok &= luaval_to_object<cocos2d::Ref>(tolua_S, 2, "cc.Ref",&arg0, "ISocketSink:onSocketCallBack");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_ISocketSink_onSocketCallBack'", nullptr);
            return 0;
        }
        cobj->onSocketCallBack(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ISocketSink:onSocketCallBack",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_ISocketSink_onSocketCallBack'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_ISocketSink_onSocketError(lua_State* tolua_S)
{
    int argc = 0;
    ISocketSink* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ISocketSink",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ISocketSink*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_ISocketSink_onSocketError'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "ISocketSink:onSocketError");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_ISocketSink_onSocketError'", nullptr);
            return 0;
        }
        cobj->onSocketError(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ISocketSink:onSocketError",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_ISocketSink_onSocketError'.",&tolua_err);
#endif

    return 0;
}
static int lua_cocos2dx_kernel_ISocketSink_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ISocketSink)");
    return 0;
}

int lua_register_cocos2dx_kernel_ISocketSink(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"ISocketSink");
    tolua_cclass(tolua_S,"ISocketSink","ISocketSink","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"ISocketSink");
        tolua_function(tolua_S,"onSocketData",lua_cocos2dx_kernel_ISocketSink_onSocketData);
        tolua_function(tolua_S,"onSocketShut",lua_cocos2dx_kernel_ISocketSink_onSocketShut);
        tolua_function(tolua_S,"onSocketLink",lua_cocos2dx_kernel_ISocketSink_onSocketLink);
        tolua_function(tolua_S,"onSocketCallBack",lua_cocos2dx_kernel_ISocketSink_onSocketCallBack);
        tolua_function(tolua_S,"onSocketError",lua_cocos2dx_kernel_ISocketSink_onSocketError);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(ISocketSink).name();
    g_luaType[typeName] = "ISocketSink";
    g_typeCast["ISocketSink"] = "ISocketSink";
    return 1;
}

int lua_cocos2dx_kernel_CSocketEngine_onSocketLink(lua_State* tolua_S)
{
    int argc = 0;
    CSocketEngine* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CSocketEngine",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CSocketEngine*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CSocketEngine_onSocketLink'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CSocketEngine_onSocketLink'", nullptr);
            return 0;
        }
        cobj->onSocketLink();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CSocketEngine:onSocketLink",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CSocketEngine_onSocketLink'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CSocketEngine_isAlive(lua_State* tolua_S)
{
    int argc = 0;
    CSocketEngine* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CSocketEngine",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CSocketEngine*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CSocketEngine_isAlive'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CSocketEngine_isAlive'", nullptr);
            return 0;
        }
        bool ret = cobj->isAlive();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CSocketEngine:isAlive",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CSocketEngine_isAlive'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CSocketEngine_onSocketError(lua_State* tolua_S)
{
    int argc = 0;
    CSocketEngine* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CSocketEngine",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CSocketEngine*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CSocketEngine_onSocketError'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "CSocketEngine:onSocketError");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CSocketEngine_onSocketError'", nullptr);
            return 0;
        }
        cobj->onSocketError(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CSocketEngine:onSocketError",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CSocketEngine_onSocketError'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CSocketEngine_onSocketShut(lua_State* tolua_S)
{
    int argc = 0;
    CSocketEngine* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CSocketEngine",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CSocketEngine*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CSocketEngine_onSocketShut'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CSocketEngine_onSocketShut'", nullptr);
            return 0;
        }
        cobj->onSocketShut();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CSocketEngine:onSocketShut",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CSocketEngine_onSocketShut'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CSocketEngine_setTCPValidate(lua_State* tolua_S)
{
    int argc = 0;
    CSocketEngine* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CSocketEngine",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CSocketEngine*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CSocketEngine_setTCPValidate'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "CSocketEngine:setTCPValidate");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CSocketEngine_setTCPValidate'", nullptr);
            return 0;
        }
        cobj->setTCPValidate(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CSocketEngine:setTCPValidate",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CSocketEngine_setTCPValidate'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CSocketEngine_send(lua_State* tolua_S)
{
    int argc = 0;
    CSocketEngine* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CSocketEngine",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CSocketEngine*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CSocketEngine_send'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 4) 
    {
        int arg0;
        int arg1;
        const char* arg2;
        int arg3;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "CSocketEngine:send");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "CSocketEngine:send");

        std::string arg2_tmp; ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp, "CSocketEngine:send"); arg2 = arg2_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3, "CSocketEngine:send");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CSocketEngine_send'", nullptr);
            return 0;
        }
        bool ret = cobj->send(arg0, arg1, arg2, arg3);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CSocketEngine:send",argc, 4);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CSocketEngine_send'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CSocketEngine_onSocketCallBack(lua_State* tolua_S)
{
    int argc = 0;
	ISocketSink* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CSocketEngine",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ISocketSink*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CSocketEngine_onSocketCallBack'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Ref* arg0;

        ok &= luaval_to_object<cocos2d::Ref>(tolua_S, 2, "cc.Ref",&arg0, "CSocketEngine:onSocketCallBack");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CSocketEngine_onSocketCallBack'", nullptr);
            return 0;
        }
        cobj->onSocketCallBack(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CSocketEngine:onSocketCallBack",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CSocketEngine_onSocketCallBack'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CSocketEngine_connect(lua_State* tolua_S)
{
    int argc = 0;
    CSocketEngine* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CSocketEngine",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CSocketEngine*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CSocketEngine_connect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        int arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CSocketEngine:connect"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "CSocketEngine:connect");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CSocketEngine_connect'", nullptr);
            return 0;
        }
        bool ret = cobj->connect(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CSocketEngine:connect",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CSocketEngine_connect'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CSocketEngine_disconnect(lua_State* tolua_S)
{
    int argc = 0;
    CSocketEngine* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CSocketEngine",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CSocketEngine*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CSocketEngine_disconnect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CSocketEngine_disconnect'", nullptr);
            return 0;
        }
        bool ret = cobj->disconnect();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CSocketEngine:disconnect",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CSocketEngine_disconnect'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CSocketEngine_setSocketEngineSink(lua_State* tolua_S)
{
    int argc = 0;
    CSocketEngine* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CSocketEngine",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CSocketEngine*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CSocketEngine_setSocketEngineSink'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        ISocketEngineSink* arg0;

        ok &= luaval_to_object<ISocketEngineSink>(tolua_S, 2, "ISocketEngineSink",&arg0, "CSocketEngine:setSocketEngineSink");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CSocketEngine_setSocketEngineSink'", nullptr);
            return 0;
        }
        cobj->setSocketEngineSink(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CSocketEngine:setSocketEngineSink",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CSocketEngine_setSocketEngineSink'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CSocketEngine_onSocketData(lua_State* tolua_S)
{
    int argc = 0;
    CSocketEngine* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CSocketEngine",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CSocketEngine*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_kernel_CSocketEngine_onSocketData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        void* arg0;
        int arg1;

        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "CSocketEngine:onSocketData");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CSocketEngine_onSocketData'", nullptr);
            return 0;
        }
        cobj->onSocketData(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CSocketEngine:onSocketData",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CSocketEngine_onSocketData'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_kernel_CSocketEngine_constructor(lua_State* tolua_S)
{
    int argc = 0;
    CSocketEngine* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_kernel_CSocketEngine_constructor'", nullptr);
            return 0;
        }
        cobj = new CSocketEngine();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"CSocketEngine");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CSocketEngine:CSocketEngine",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_kernel_CSocketEngine_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_kernel_CSocketEngine_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CSocketEngine)");
    return 0;
}

int lua_register_cocos2dx_kernel_CSocketEngine(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CSocketEngine");
    tolua_cclass(tolua_S,"CSocketEngine","CSocketEngine","ISocketEngine",nullptr);

    tolua_beginmodule(tolua_S,"CSocketEngine");
        tolua_function(tolua_S,"new",lua_cocos2dx_kernel_CSocketEngine_constructor);
        tolua_function(tolua_S,"onSocketLink",lua_cocos2dx_kernel_CSocketEngine_onSocketLink);
        tolua_function(tolua_S,"isAlive",lua_cocos2dx_kernel_CSocketEngine_isAlive);
        tolua_function(tolua_S,"onSocketError",lua_cocos2dx_kernel_CSocketEngine_onSocketError);
        tolua_function(tolua_S,"onSocketShut",lua_cocos2dx_kernel_CSocketEngine_onSocketShut);
        tolua_function(tolua_S,"setTCPValidate",lua_cocos2dx_kernel_CSocketEngine_setTCPValidate);
        tolua_function(tolua_S,"send",lua_cocos2dx_kernel_CSocketEngine_send);
        tolua_function(tolua_S,"onSocketCallBack",lua_cocos2dx_kernel_CSocketEngine_onSocketCallBack);
        tolua_function(tolua_S,"connect",lua_cocos2dx_kernel_CSocketEngine_connect);
        tolua_function(tolua_S,"disconnect",lua_cocos2dx_kernel_CSocketEngine_disconnect);
        tolua_function(tolua_S,"setSocketEngineSink",lua_cocos2dx_kernel_CSocketEngine_setSocketEngineSink);
        tolua_function(tolua_S,"onSocketData",lua_cocos2dx_kernel_CSocketEngine_onSocketData);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CSocketEngine).name();
    g_luaType[typeName] = "CSocketEngine";
    g_typeCast["CSocketEngine"] = "CSocketEngine";
    return 1;
}
TOLUA_API int register_all_cocos2dx_kernel(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"ds",0);
	tolua_beginmodule(tolua_S,"ds");

	lua_register_cocos2dx_kernel_IServerItem(tolua_S);
	lua_register_cocos2dx_kernel_ISocketEngineSink(tolua_S);
	lua_register_cocos2dx_kernel_CServerItem(tolua_S);
	lua_register_cocos2dx_kernel_ISocketSink(tolua_S);
	lua_register_cocos2dx_kernel_IClientUserItem(tolua_S);
	lua_register_cocos2dx_kernel_CGameFrameEngine(tolua_S);
	lua_register_cocos2dx_kernel_SoundFun(tolua_S);
	lua_register_cocos2dx_kernel_tagSearchTable(tolua_S);
	lua_register_cocos2dx_kernel_CGameCenterManager(tolua_S);
	lua_register_cocos2dx_kernel_IGameTouchSink(tolua_S);
	lua_register_cocos2dx_kernel_CGameScene(tolua_S);
	lua_register_cocos2dx_kernel_IClientKernel(tolua_S);
	lua_register_cocos2dx_kernel_ISocketEngine(tolua_S);
	lua_register_cocos2dx_kernel_CSocketEngine(tolua_S);
	lua_register_cocos2dx_kernel_GameTouchScene(tolua_S);
	lua_register_cocos2dx_kernel_CSocketMission(tolua_S);
	lua_register_cocos2dx_kernel_CClientUserItem(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

#endif
