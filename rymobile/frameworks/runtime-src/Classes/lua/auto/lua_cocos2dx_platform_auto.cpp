#include "lua_cocos2dx_platform_auto.hpp"
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC || CC_TARGET_PLATFORM == CC_PLATFORM_WIN32

#include "platform/df/DF.h"
#include "platform/df/Struct.h"

#include "platform/data/GlobalUserInfo.h"
#include "platform/data/ServerListData.h"
#include "platform/data/OptionParameter.h"
#include "platform/data/PlatformGameConfig.h"
#include "platform/multiPlatform/MultiPlatformMgr.h"
#include "platform/msg/CMD_GameServer.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"



int lua_cocos2dx_platform_tagUserAttribute_setUserID(lua_State* tolua_S)
{
    int argc = 0;
    tagUserAttribute* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserAttribute",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserAttribute*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserAttribute_setUserID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "tagUserAttribute:setUserID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserAttribute_setUserID'", nullptr);
            return 0;
        }
        cobj->setUserID(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserAttribute:setUserID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserAttribute_setUserID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserAttribute_getTableID(lua_State* tolua_S)
{
    int argc = 0;
    tagUserAttribute* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserAttribute",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserAttribute*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserAttribute_getTableID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserAttribute_getTableID'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->getTableID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserAttribute:getTableID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserAttribute_getTableID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserAttribute_getChairID(lua_State* tolua_S)
{
    int argc = 0;
    tagUserAttribute* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserAttribute",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserAttribute*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserAttribute_getChairID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserAttribute_getChairID'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->getChairID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserAttribute:getChairID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserAttribute_getChairID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserAttribute_setMasterRight(lua_State* tolua_S)
{
    int argc = 0;
    tagUserAttribute* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserAttribute",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserAttribute*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserAttribute_setMasterRight'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "tagUserAttribute:setMasterRight");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserAttribute_setMasterRight'", nullptr);
            return 0;
        }
        cobj->setMasterRight(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserAttribute:setMasterRight",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserAttribute_setMasterRight'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserAttribute_getUserID(lua_State* tolua_S)
{
    int argc = 0;
    tagUserAttribute* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserAttribute",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserAttribute*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserAttribute_getUserID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserAttribute_getUserID'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getUserID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserAttribute:getUserID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserAttribute_getUserID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserAttribute_setUserRight(lua_State* tolua_S)
{
    int argc = 0;
    tagUserAttribute* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserAttribute",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserAttribute*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserAttribute_setUserRight'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "tagUserAttribute:setUserRight");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserAttribute_setUserRight'", nullptr);
            return 0;
        }
        cobj->setUserRight(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserAttribute:setUserRight",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserAttribute_setUserRight'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserAttribute_setChairID(lua_State* tolua_S)
{
    int argc = 0;
    tagUserAttribute* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserAttribute",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserAttribute*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserAttribute_setChairID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagUserAttribute:setChairID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserAttribute_setChairID'", nullptr);
            return 0;
        }
        cobj->setChairID(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserAttribute:setChairID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserAttribute_setChairID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserAttribute_getUserRight(lua_State* tolua_S)
{
    int argc = 0;
    tagUserAttribute* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserAttribute",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserAttribute*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserAttribute_getUserRight'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserAttribute_getUserRight'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getUserRight();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserAttribute:getUserRight",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserAttribute_getUserRight'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserAttribute_setTableID(lua_State* tolua_S)
{
    int argc = 0;
    tagUserAttribute* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserAttribute",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserAttribute*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserAttribute_setTableID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagUserAttribute:setTableID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserAttribute_setTableID'", nullptr);
            return 0;
        }
        cobj->setTableID(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserAttribute:setTableID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserAttribute_setTableID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserAttribute_getMasterRight(lua_State* tolua_S)
{
    int argc = 0;
    tagUserAttribute* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserAttribute",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserAttribute*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserAttribute_getMasterRight'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserAttribute_getMasterRight'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getMasterRight();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserAttribute:getMasterRight",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserAttribute_getMasterRight'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserAttribute_constructor(lua_State* tolua_S)
{
    int argc = 0;
    tagUserAttribute* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserAttribute_constructor'", nullptr);
            return 0;
        }
        cobj = new tagUserAttribute();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"tagUserAttribute");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserAttribute:tagUserAttribute",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserAttribute_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_platform_tagUserAttribute_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (tagUserAttribute)");
    return 0;
}

int lua_register_cocos2dx_platform_tagUserAttribute(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"tagUserAttribute");
    tolua_cclass(tolua_S,"tagUserAttribute","tagUserAttribute","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"tagUserAttribute");
        tolua_function(tolua_S,"new",lua_cocos2dx_platform_tagUserAttribute_constructor);
        tolua_function(tolua_S,"setUserID",lua_cocos2dx_platform_tagUserAttribute_setUserID);
        tolua_function(tolua_S,"getTableID",lua_cocos2dx_platform_tagUserAttribute_getTableID);
        tolua_function(tolua_S,"getChairID",lua_cocos2dx_platform_tagUserAttribute_getChairID);
        tolua_function(tolua_S,"setMasterRight",lua_cocos2dx_platform_tagUserAttribute_setMasterRight);
        tolua_function(tolua_S,"getUserID",lua_cocos2dx_platform_tagUserAttribute_getUserID);
        tolua_function(tolua_S,"setUserRight",lua_cocos2dx_platform_tagUserAttribute_setUserRight);
        tolua_function(tolua_S,"setChairID",lua_cocos2dx_platform_tagUserAttribute_setChairID);
        tolua_function(tolua_S,"getUserRight",lua_cocos2dx_platform_tagUserAttribute_getUserRight);
        tolua_function(tolua_S,"setTableID",lua_cocos2dx_platform_tagUserAttribute_setTableID);
        tolua_function(tolua_S,"getMasterRight",lua_cocos2dx_platform_tagUserAttribute_getMasterRight);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(tagUserAttribute).name();
    g_luaType[typeName] = "tagUserAttribute";
    g_typeCast["tagUserAttribute"] = "tagUserAttribute";
    return 1;
}

int lua_cocos2dx_platform_tagGameAttribute_getChairCount(lua_State* tolua_S)
{
    int argc = 0;
    tagGameAttribute* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameAttribute",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameAttribute*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameAttribute_getChairCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameAttribute_getChairCount'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->getChairCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameAttribute:getChairCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameAttribute_getChairCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameAttribute_getKindID(lua_State* tolua_S)
{
    int argc = 0;
    tagGameAttribute* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameAttribute",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameAttribute*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameAttribute_getKindID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameAttribute_getKindID'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->getKindID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameAttribute:getKindID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameAttribute_getKindID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameAttribute_setChairCount(lua_State* tolua_S)
{
    int argc = 0;
    tagGameAttribute* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameAttribute",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameAttribute*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameAttribute_setChairCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagGameAttribute:setChairCount");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameAttribute_setChairCount'", nullptr);
            return 0;
        }
        cobj->setChairCount(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameAttribute:setChairCount",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameAttribute_setChairCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameAttribute_getGameName(lua_State* tolua_S)
{
    int argc = 0;
    tagGameAttribute* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameAttribute",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameAttribute*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameAttribute_getGameName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameAttribute_getGameName'", nullptr);
            return 0;
        }
        const char* ret = cobj->getGameName();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameAttribute:getGameName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameAttribute_getGameName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameAttribute_setGameName(lua_State* tolua_S)
{
    int argc = 0;
    tagGameAttribute* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameAttribute",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameAttribute*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameAttribute_setGameName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        int arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "tagGameAttribute:setGameName"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "tagGameAttribute:setGameName");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameAttribute_setGameName'", nullptr);
            return 0;
        }
        cobj->setGameName(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameAttribute:setGameName",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameAttribute_setGameName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameAttribute_getClientVersion(lua_State* tolua_S)
{
    int argc = 0;
    tagGameAttribute* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameAttribute",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameAttribute*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameAttribute_getClientVersion'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameAttribute_getClientVersion'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getClientVersion();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameAttribute:getClientVersion",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameAttribute_getClientVersion'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameAttribute_setClientVersion(lua_State* tolua_S)
{
    int argc = 0;
    tagGameAttribute* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameAttribute",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameAttribute*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameAttribute_setClientVersion'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "tagGameAttribute:setClientVersion");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameAttribute_setClientVersion'", nullptr);
            return 0;
        }
        cobj->setClientVersion(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameAttribute:setClientVersion",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameAttribute_setClientVersion'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameAttribute_setKindID(lua_State* tolua_S)
{
    int argc = 0;
    tagGameAttribute* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameAttribute",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameAttribute*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameAttribute_setKindID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagGameAttribute:setKindID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameAttribute_setKindID'", nullptr);
            return 0;
        }
        cobj->setKindID(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameAttribute:setKindID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameAttribute_setKindID'.",&tolua_err);
#endif

    return 0;
}
static int lua_cocos2dx_platform_tagGameAttribute_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (tagGameAttribute)");
    return 0;
}

int lua_register_cocos2dx_platform_tagGameAttribute(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"tagGameAttribute");
    tolua_cclass(tolua_S,"tagGameAttribute","tagGameAttribute","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"tagGameAttribute");
        tolua_function(tolua_S,"getChairCount",lua_cocos2dx_platform_tagGameAttribute_getChairCount);
        tolua_function(tolua_S,"getKindID",lua_cocos2dx_platform_tagGameAttribute_getKindID);
        tolua_function(tolua_S,"setChairCount",lua_cocos2dx_platform_tagGameAttribute_setChairCount);
        tolua_function(tolua_S,"getGameName",lua_cocos2dx_platform_tagGameAttribute_getGameName);
        tolua_function(tolua_S,"setGameName",lua_cocos2dx_platform_tagGameAttribute_setGameName);
        tolua_function(tolua_S,"getClientVersion",lua_cocos2dx_platform_tagGameAttribute_getClientVersion);
        tolua_function(tolua_S,"setClientVersion",lua_cocos2dx_platform_tagGameAttribute_setClientVersion);
        tolua_function(tolua_S,"setKindID",lua_cocos2dx_platform_tagGameAttribute_setKindID);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(tagGameAttribute).name();
    g_luaType[typeName] = "tagGameAttribute";
    g_typeCast["tagGameAttribute"] = "tagGameAttribute";
    return 1;
}

int lua_cocos2dx_platform_tagServerAttribute_getServerType(lua_State* tolua_S)
{
    int argc = 0;
    tagServerAttribute* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagServerAttribute",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagServerAttribute*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagServerAttribute_getServerType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagServerAttribute_getServerType'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->getServerType();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagServerAttribute:getServerType",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagServerAttribute_getServerType'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagServerAttribute_getChairCount(lua_State* tolua_S)
{
    int argc = 0;
    tagServerAttribute* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagServerAttribute",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagServerAttribute*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagServerAttribute_getChairCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagServerAttribute_getChairCount'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->getChairCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagServerAttribute:getChairCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagServerAttribute_getChairCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagServerAttribute_getServerRule(lua_State* tolua_S)
{
    int argc = 0;
    tagServerAttribute* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagServerAttribute",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagServerAttribute*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagServerAttribute_getServerRule'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagServerAttribute_getServerRule'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getServerRule();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagServerAttribute:getServerRule",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagServerAttribute_getServerRule'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagServerAttribute_getKindID(lua_State* tolua_S)
{
    int argc = 0;
    tagServerAttribute* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagServerAttribute",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagServerAttribute*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagServerAttribute_getKindID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagServerAttribute_getKindID'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->getKindID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagServerAttribute:getKindID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagServerAttribute_getKindID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagServerAttribute_setChairCount(lua_State* tolua_S)
{
    int argc = 0;
    tagServerAttribute* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagServerAttribute",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagServerAttribute*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagServerAttribute_setChairCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagServerAttribute:setChairCount");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagServerAttribute_setChairCount'", nullptr);
            return 0;
        }
        cobj->setChairCount(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagServerAttribute:setChairCount",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagServerAttribute_setChairCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagServerAttribute_setServerType(lua_State* tolua_S)
{
    int argc = 0;
    tagServerAttribute* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagServerAttribute",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagServerAttribute*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagServerAttribute_setServerType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagServerAttribute:setServerType");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagServerAttribute_setServerType'", nullptr);
            return 0;
        }
        cobj->setServerType(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagServerAttribute:setServerType",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagServerAttribute_setServerType'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagServerAttribute_getServerID(lua_State* tolua_S)
{
    int argc = 0;
    tagServerAttribute* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagServerAttribute",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagServerAttribute*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagServerAttribute_getServerID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagServerAttribute_getServerID'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->getServerID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagServerAttribute:getServerID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagServerAttribute_getServerID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagServerAttribute_getAVServerAddr(lua_State* tolua_S)
{
    int argc = 0;
    tagServerAttribute* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagServerAttribute",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagServerAttribute*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagServerAttribute_getAVServerAddr'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagServerAttribute_getAVServerAddr'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getAVServerAddr();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagServerAttribute:getAVServerAddr",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagServerAttribute_getAVServerAddr'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagServerAttribute_setServerName(lua_State* tolua_S)
{
    int argc = 0;
    tagServerAttribute* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagServerAttribute",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagServerAttribute*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagServerAttribute_setServerName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        int arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "tagServerAttribute:setServerName"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "tagServerAttribute:setServerName");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagServerAttribute_setServerName'", nullptr);
            return 0;
        }
        cobj->setServerName(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagServerAttribute:setServerName",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagServerAttribute_setServerName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagServerAttribute_getTableCount(lua_State* tolua_S)
{
    int argc = 0;
    tagServerAttribute* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagServerAttribute",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagServerAttribute*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagServerAttribute_getTableCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagServerAttribute_getTableCount'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->getTableCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagServerAttribute:getTableCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagServerAttribute_getTableCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagServerAttribute_setAVServerAddr(lua_State* tolua_S)
{
    int argc = 0;
    tagServerAttribute* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagServerAttribute",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagServerAttribute*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagServerAttribute_setAVServerAddr'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "tagServerAttribute:setAVServerAddr");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagServerAttribute_setAVServerAddr'", nullptr);
            return 0;
        }
        cobj->setAVServerAddr(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagServerAttribute:setAVServerAddr",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagServerAttribute_setAVServerAddr'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagServerAttribute_setTableCount(lua_State* tolua_S)
{
    int argc = 0;
    tagServerAttribute* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagServerAttribute",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagServerAttribute*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagServerAttribute_setTableCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagServerAttribute:setTableCount");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagServerAttribute_setTableCount'", nullptr);
            return 0;
        }
        cobj->setTableCount(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagServerAttribute:setTableCount",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagServerAttribute_setTableCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagServerAttribute_getAVServerPort(lua_State* tolua_S)
{
    int argc = 0;
    tagServerAttribute* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagServerAttribute",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagServerAttribute*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagServerAttribute_getAVServerPort'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagServerAttribute_getAVServerPort'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->getAVServerPort();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagServerAttribute:getAVServerPort",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagServerAttribute_getAVServerPort'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagServerAttribute_getServerName(lua_State* tolua_S)
{
    int argc = 0;
    tagServerAttribute* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagServerAttribute",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagServerAttribute*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagServerAttribute_getServerName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagServerAttribute_getServerName'", nullptr);
            return 0;
        }
        const char* ret = cobj->getServerName();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagServerAttribute:getServerName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagServerAttribute_getServerName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagServerAttribute_setServerID(lua_State* tolua_S)
{
    int argc = 0;
    tagServerAttribute* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagServerAttribute",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagServerAttribute*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagServerAttribute_setServerID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagServerAttribute:setServerID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagServerAttribute_setServerID'", nullptr);
            return 0;
        }
        cobj->setServerID(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagServerAttribute:setServerID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagServerAttribute_setServerID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagServerAttribute_setServerRule(lua_State* tolua_S)
{
    int argc = 0;
    tagServerAttribute* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagServerAttribute",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagServerAttribute*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagServerAttribute_setServerRule'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "tagServerAttribute:setServerRule");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagServerAttribute_setServerRule'", nullptr);
            return 0;
        }
        cobj->setServerRule(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagServerAttribute:setServerRule",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagServerAttribute_setServerRule'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagServerAttribute_setKindID(lua_State* tolua_S)
{
    int argc = 0;
    tagServerAttribute* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagServerAttribute",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagServerAttribute*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagServerAttribute_setKindID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagServerAttribute:setKindID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagServerAttribute_setKindID'", nullptr);
            return 0;
        }
        cobj->setKindID(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagServerAttribute:setKindID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagServerAttribute_setKindID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagServerAttribute_setAVServerPort(lua_State* tolua_S)
{
    int argc = 0;
    tagServerAttribute* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagServerAttribute",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagServerAttribute*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagServerAttribute_setAVServerPort'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagServerAttribute:setAVServerPort");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagServerAttribute_setAVServerPort'", nullptr);
            return 0;
        }
        cobj->setAVServerPort(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagServerAttribute:setAVServerPort",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagServerAttribute_setAVServerPort'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagServerAttribute_constructor(lua_State* tolua_S)
{
    int argc = 0;
    tagServerAttribute* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagServerAttribute_constructor'", nullptr);
            return 0;
        }
        cobj = new tagServerAttribute();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"tagServerAttribute");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagServerAttribute:tagServerAttribute",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagServerAttribute_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_platform_tagServerAttribute_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (tagServerAttribute)");
    return 0;
}

int lua_register_cocos2dx_platform_tagServerAttribute(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"tagServerAttribute");
    tolua_cclass(tolua_S,"tagServerAttribute","tagServerAttribute","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"tagServerAttribute");
        tolua_function(tolua_S,"new",lua_cocos2dx_platform_tagServerAttribute_constructor);
        tolua_function(tolua_S,"getServerType",lua_cocos2dx_platform_tagServerAttribute_getServerType);
        tolua_function(tolua_S,"getChairCount",lua_cocos2dx_platform_tagServerAttribute_getChairCount);
        tolua_function(tolua_S,"getServerRule",lua_cocos2dx_platform_tagServerAttribute_getServerRule);
        tolua_function(tolua_S,"getKindID",lua_cocos2dx_platform_tagServerAttribute_getKindID);
        tolua_function(tolua_S,"setChairCount",lua_cocos2dx_platform_tagServerAttribute_setChairCount);
        tolua_function(tolua_S,"setServerType",lua_cocos2dx_platform_tagServerAttribute_setServerType);
        tolua_function(tolua_S,"getServerID",lua_cocos2dx_platform_tagServerAttribute_getServerID);
        tolua_function(tolua_S,"getAVServerAddr",lua_cocos2dx_platform_tagServerAttribute_getAVServerAddr);
        tolua_function(tolua_S,"setServerName",lua_cocos2dx_platform_tagServerAttribute_setServerName);
        tolua_function(tolua_S,"getTableCount",lua_cocos2dx_platform_tagServerAttribute_getTableCount);
        tolua_function(tolua_S,"setAVServerAddr",lua_cocos2dx_platform_tagServerAttribute_setAVServerAddr);
        tolua_function(tolua_S,"setTableCount",lua_cocos2dx_platform_tagServerAttribute_setTableCount);
        tolua_function(tolua_S,"getAVServerPort",lua_cocos2dx_platform_tagServerAttribute_getAVServerPort);
        tolua_function(tolua_S,"getServerName",lua_cocos2dx_platform_tagServerAttribute_getServerName);
        tolua_function(tolua_S,"setServerID",lua_cocos2dx_platform_tagServerAttribute_setServerID);
        tolua_function(tolua_S,"setServerRule",lua_cocos2dx_platform_tagServerAttribute_setServerRule);
        tolua_function(tolua_S,"setKindID",lua_cocos2dx_platform_tagServerAttribute_setKindID);
        tolua_function(tolua_S,"setAVServerPort",lua_cocos2dx_platform_tagServerAttribute_setAVServerPort);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(tagServerAttribute).name();
    g_luaType[typeName] = "tagServerAttribute";
    g_typeCast["tagServerAttribute"] = "tagServerAttribute";
    return 1;
}

int lua_cocos2dx_platform_tagGameType_setSortID(lua_State* tolua_S)
{
    int argc = 0;
    tagGameType* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameType",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameType*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameType_setSortID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagGameType:setSortID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameType_setSortID'", nullptr);
            return 0;
        }
        cobj->setSortID(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameType:setSortID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameType_setSortID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameType_getTypeID(lua_State* tolua_S)
{
    int argc = 0;
    tagGameType* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameType",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameType*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameType_getTypeID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameType_getTypeID'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->getTypeID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameType:getTypeID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameType_getTypeID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameType_setTypeName(lua_State* tolua_S)
{
    int argc = 0;
    tagGameType* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameType",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameType*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameType_setTypeName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        int arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "tagGameType:setTypeName"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "tagGameType:setTypeName");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameType_setTypeName'", nullptr);
            return 0;
        }
        cobj->setTypeName(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameType:setTypeName",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameType_setTypeName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameType_getSortID(lua_State* tolua_S)
{
    int argc = 0;
    tagGameType* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameType",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameType*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameType_getSortID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameType_getSortID'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->getSortID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameType:getSortID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameType_getSortID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameType_getJoinID(lua_State* tolua_S)
{
    int argc = 0;
    tagGameType* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameType",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameType*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameType_getJoinID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameType_getJoinID'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->getJoinID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameType:getJoinID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameType_getJoinID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameType_setTypeID(lua_State* tolua_S)
{
    int argc = 0;
    tagGameType* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameType",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameType*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameType_setTypeID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagGameType:setTypeID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameType_setTypeID'", nullptr);
            return 0;
        }
        cobj->setTypeID(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameType:setTypeID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameType_setTypeID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameType_setJoinID(lua_State* tolua_S)
{
    int argc = 0;
    tagGameType* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameType",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameType*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameType_setJoinID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagGameType:setJoinID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameType_setJoinID'", nullptr);
            return 0;
        }
        cobj->setJoinID(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameType:setJoinID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameType_setJoinID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameType_getTypeName(lua_State* tolua_S)
{
    int argc = 0;
    tagGameType* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameType",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameType*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameType_getTypeName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameType_getTypeName'", nullptr);
            return 0;
        }
        const char* ret = cobj->getTypeName();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameType:getTypeName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameType_getTypeName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameType_constructor(lua_State* tolua_S)
{
    int argc = 0;
    tagGameType* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameType_constructor'", nullptr);
            return 0;
        }
        cobj = new tagGameType();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"tagGameType");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameType:tagGameType",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameType_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_platform_tagGameType_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (tagGameType)");
    return 0;
}

int lua_register_cocos2dx_platform_tagGameType(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"tagGameType");
    tolua_cclass(tolua_S,"tagGameType","tagGameType","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"tagGameType");
        tolua_function(tolua_S,"new",lua_cocos2dx_platform_tagGameType_constructor);
        tolua_function(tolua_S,"setSortID",lua_cocos2dx_platform_tagGameType_setSortID);
        tolua_function(tolua_S,"getTypeID",lua_cocos2dx_platform_tagGameType_getTypeID);
        tolua_function(tolua_S,"setTypeName",lua_cocos2dx_platform_tagGameType_setTypeName);
        tolua_function(tolua_S,"getSortID",lua_cocos2dx_platform_tagGameType_getSortID);
        tolua_function(tolua_S,"getJoinID",lua_cocos2dx_platform_tagGameType_getJoinID);
        tolua_function(tolua_S,"setTypeID",lua_cocos2dx_platform_tagGameType_setTypeID);
        tolua_function(tolua_S,"setJoinID",lua_cocos2dx_platform_tagGameType_setJoinID);
        tolua_function(tolua_S,"getTypeName",lua_cocos2dx_platform_tagGameType_getTypeName);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(tagGameType).name();
    g_luaType[typeName] = "tagGameType";
    g_typeCast["tagGameType"] = "tagGameType";
    return 1;
}

int lua_cocos2dx_platform_tagGameKind_getGameID(lua_State* tolua_S)
{
    int argc = 0;
    tagGameKind* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameKind",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameKind*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameKind_getGameID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameKind_getGameID'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->getGameID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameKind:getGameID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameKind_getGameID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameKind_getProcessName(lua_State* tolua_S)
{
    int argc = 0;
    tagGameKind* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameKind",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameKind*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameKind_getProcessName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameKind_getProcessName'", nullptr);
            return 0;
        }
        const char* ret = cobj->getProcessName();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameKind:getProcessName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameKind_getProcessName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameKind_setSortID(lua_State* tolua_S)
{
    int argc = 0;
    tagGameKind* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameKind",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameKind*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameKind_setSortID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagGameKind:setSortID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameKind_setSortID'", nullptr);
            return 0;
        }
        cobj->setSortID(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameKind:setSortID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameKind_setSortID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameKind_getOnLineCount(lua_State* tolua_S)
{
    int argc = 0;
    tagGameKind* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameKind",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameKind*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameKind_getOnLineCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameKind_getOnLineCount'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getOnLineCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameKind:getOnLineCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameKind_getOnLineCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameKind_setAndroidCount(lua_State* tolua_S)
{
    int argc = 0;
    tagGameKind* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameKind",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameKind*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameKind_setAndroidCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "tagGameKind:setAndroidCount");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameKind_setAndroidCount'", nullptr);
            return 0;
        }
        cobj->setAndroidCount(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameKind:setAndroidCount",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameKind_setAndroidCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameKind_getKindID(lua_State* tolua_S)
{
    int argc = 0;
    tagGameKind* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameKind",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameKind*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameKind_getKindID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameKind_getKindID'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->getKindID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameKind:getKindID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameKind_getKindID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameKind_getTypeID(lua_State* tolua_S)
{
    int argc = 0;
    tagGameKind* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameKind",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameKind*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameKind_getTypeID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameKind_getTypeID'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->getTypeID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameKind:getTypeID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameKind_getTypeID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameKind_setKindName(lua_State* tolua_S)
{
    int argc = 0;
    tagGameKind* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameKind",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameKind*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameKind_setKindName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        int arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "tagGameKind:setKindName"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "tagGameKind:setKindName");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameKind_setKindName'", nullptr);
            return 0;
        }
        cobj->setKindName(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameKind:setKindName",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameKind_setKindName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameKind_setGameID(lua_State* tolua_S)
{
    int argc = 0;
    tagGameKind* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameKind",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameKind*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameKind_setGameID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagGameKind:setGameID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameKind_setGameID'", nullptr);
            return 0;
        }
        cobj->setGameID(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameKind:setGameID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameKind_setGameID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameKind_getSortID(lua_State* tolua_S)
{
    int argc = 0;
    tagGameKind* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameKind",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameKind*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameKind_getSortID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameKind_getSortID'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->getSortID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameKind:getSortID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameKind_getSortID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameKind_setFullCount(lua_State* tolua_S)
{
    int argc = 0;
    tagGameKind* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameKind",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameKind*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameKind_setFullCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "tagGameKind:setFullCount");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameKind_setFullCount'", nullptr);
            return 0;
        }
        cobj->setFullCount(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameKind:setFullCount",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameKind_setFullCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameKind_getAndroidCount(lua_State* tolua_S)
{
    int argc = 0;
    tagGameKind* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameKind",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameKind*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameKind_getAndroidCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameKind_getAndroidCount'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getAndroidCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameKind:getAndroidCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameKind_getAndroidCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameKind_getJoinID(lua_State* tolua_S)
{
    int argc = 0;
    tagGameKind* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameKind",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameKind*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameKind_getJoinID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameKind_getJoinID'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->getJoinID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameKind:getJoinID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameKind_getJoinID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameKind_getFullCount(lua_State* tolua_S)
{
    int argc = 0;
    tagGameKind* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameKind",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameKind*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameKind_getFullCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameKind_getFullCount'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getFullCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameKind:getFullCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameKind_getFullCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameKind_setTypeID(lua_State* tolua_S)
{
    int argc = 0;
    tagGameKind* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameKind",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameKind*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameKind_setTypeID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagGameKind:setTypeID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameKind_setTypeID'", nullptr);
            return 0;
        }
        cobj->setTypeID(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameKind:setTypeID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameKind_setTypeID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameKind_setJoinID(lua_State* tolua_S)
{
    int argc = 0;
    tagGameKind* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameKind",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameKind*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameKind_setJoinID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagGameKind:setJoinID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameKind_setJoinID'", nullptr);
            return 0;
        }
        cobj->setJoinID(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameKind:setJoinID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameKind_setJoinID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameKind_setOnLineCount(lua_State* tolua_S)
{
    int argc = 0;
    tagGameKind* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameKind",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameKind*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameKind_setOnLineCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "tagGameKind:setOnLineCount");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameKind_setOnLineCount'", nullptr);
            return 0;
        }
        cobj->setOnLineCount(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameKind:setOnLineCount",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameKind_setOnLineCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameKind_getKindName(lua_State* tolua_S)
{
    int argc = 0;
    tagGameKind* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameKind",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameKind*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameKind_getKindName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameKind_getKindName'", nullptr);
            return 0;
        }
        const char* ret = cobj->getKindName();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameKind:getKindName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameKind_getKindName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameKind_setProcessName(lua_State* tolua_S)
{
    int argc = 0;
    tagGameKind* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameKind",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameKind*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameKind_setProcessName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        int arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "tagGameKind:setProcessName"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "tagGameKind:setProcessName");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameKind_setProcessName'", nullptr);
            return 0;
        }
        cobj->setProcessName(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameKind:setProcessName",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameKind_setProcessName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameKind_setKindID(lua_State* tolua_S)
{
    int argc = 0;
    tagGameKind* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameKind",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameKind*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameKind_setKindID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagGameKind:setKindID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameKind_setKindID'", nullptr);
            return 0;
        }
        cobj->setKindID(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameKind:setKindID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameKind_setKindID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameKind_constructor(lua_State* tolua_S)
{
    int argc = 0;
    tagGameKind* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameKind_constructor'", nullptr);
            return 0;
        }
        cobj = new tagGameKind();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"tagGameKind");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameKind:tagGameKind",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameKind_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_platform_tagGameKind_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (tagGameKind)");
    return 0;
}

int lua_register_cocos2dx_platform_tagGameKind(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"tagGameKind");
    tolua_cclass(tolua_S,"tagGameKind","tagGameKind","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"tagGameKind");
        tolua_function(tolua_S,"new",lua_cocos2dx_platform_tagGameKind_constructor);
        tolua_function(tolua_S,"getGameID",lua_cocos2dx_platform_tagGameKind_getGameID);
        tolua_function(tolua_S,"getProcessName",lua_cocos2dx_platform_tagGameKind_getProcessName);
        tolua_function(tolua_S,"setSortID",lua_cocos2dx_platform_tagGameKind_setSortID);
        tolua_function(tolua_S,"getOnLineCount",lua_cocos2dx_platform_tagGameKind_getOnLineCount);
        tolua_function(tolua_S,"setAndroidCount",lua_cocos2dx_platform_tagGameKind_setAndroidCount);
        tolua_function(tolua_S,"getKindID",lua_cocos2dx_platform_tagGameKind_getKindID);
        tolua_function(tolua_S,"getTypeID",lua_cocos2dx_platform_tagGameKind_getTypeID);
        tolua_function(tolua_S,"setKindName",lua_cocos2dx_platform_tagGameKind_setKindName);
        tolua_function(tolua_S,"setGameID",lua_cocos2dx_platform_tagGameKind_setGameID);
        tolua_function(tolua_S,"getSortID",lua_cocos2dx_platform_tagGameKind_getSortID);
        tolua_function(tolua_S,"setFullCount",lua_cocos2dx_platform_tagGameKind_setFullCount);
        tolua_function(tolua_S,"getAndroidCount",lua_cocos2dx_platform_tagGameKind_getAndroidCount);
        tolua_function(tolua_S,"getJoinID",lua_cocos2dx_platform_tagGameKind_getJoinID);
        tolua_function(tolua_S,"getFullCount",lua_cocos2dx_platform_tagGameKind_getFullCount);
        tolua_function(tolua_S,"setTypeID",lua_cocos2dx_platform_tagGameKind_setTypeID);
        tolua_function(tolua_S,"setJoinID",lua_cocos2dx_platform_tagGameKind_setJoinID);
        tolua_function(tolua_S,"setOnLineCount",lua_cocos2dx_platform_tagGameKind_setOnLineCount);
        tolua_function(tolua_S,"getKindName",lua_cocos2dx_platform_tagGameKind_getKindName);
        tolua_function(tolua_S,"setProcessName",lua_cocos2dx_platform_tagGameKind_setProcessName);
        tolua_function(tolua_S,"setKindID",lua_cocos2dx_platform_tagGameKind_setKindID);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(tagGameKind).name();
    g_luaType[typeName] = "tagGameKind";
    g_typeCast["tagGameKind"] = "tagGameKind";
    return 1;
}

int lua_cocos2dx_platform_tagGameNode_setSortID(lua_State* tolua_S)
{
    int argc = 0;
    tagGameNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameNode_setSortID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagGameNode:setSortID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameNode_setSortID'", nullptr);
            return 0;
        }
        cobj->setSortID(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameNode:setSortID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameNode_setSortID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameNode_setNodeName(lua_State* tolua_S)
{
    int argc = 0;
    tagGameNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameNode_setNodeName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        int arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "tagGameNode:setNodeName"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "tagGameNode:setNodeName");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameNode_setNodeName'", nullptr);
            return 0;
        }
        cobj->setNodeName(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameNode:setNodeName",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameNode_setNodeName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameNode_getKindID(lua_State* tolua_S)
{
    int argc = 0;
    tagGameNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameNode_getKindID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameNode_getKindID'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->getKindID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameNode:getKindID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameNode_getKindID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameNode_getNodeName(lua_State* tolua_S)
{
    int argc = 0;
    tagGameNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameNode_getNodeName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameNode_getNodeName'", nullptr);
            return 0;
        }
        const char* ret = cobj->getNodeName();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameNode:getNodeName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameNode_getNodeName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameNode_setNodeID(lua_State* tolua_S)
{
    int argc = 0;
    tagGameNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameNode_setNodeID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagGameNode:setNodeID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameNode_setNodeID'", nullptr);
            return 0;
        }
        cobj->setNodeID(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameNode:setNodeID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameNode_setNodeID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameNode_getSortID(lua_State* tolua_S)
{
    int argc = 0;
    tagGameNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameNode_getSortID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameNode_getSortID'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->getSortID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameNode:getSortID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameNode_getSortID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameNode_getJoinID(lua_State* tolua_S)
{
    int argc = 0;
    tagGameNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameNode_getJoinID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameNode_getJoinID'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->getJoinID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameNode:getJoinID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameNode_getJoinID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameNode_getNodeID(lua_State* tolua_S)
{
    int argc = 0;
    tagGameNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameNode_getNodeID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameNode_getNodeID'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->getNodeID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameNode:getNodeID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameNode_getNodeID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameNode_setJoinID(lua_State* tolua_S)
{
    int argc = 0;
    tagGameNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameNode_setJoinID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagGameNode:setJoinID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameNode_setJoinID'", nullptr);
            return 0;
        }
        cobj->setJoinID(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameNode:setJoinID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameNode_setJoinID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameNode_setKindID(lua_State* tolua_S)
{
    int argc = 0;
    tagGameNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameNode_setKindID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagGameNode:setKindID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameNode_setKindID'", nullptr);
            return 0;
        }
        cobj->setKindID(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameNode:setKindID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameNode_setKindID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameNode_constructor(lua_State* tolua_S)
{
    int argc = 0;
    tagGameNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameNode_constructor'", nullptr);
            return 0;
        }
        cobj = new tagGameNode();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"tagGameNode");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameNode:tagGameNode",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameNode_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_platform_tagGameNode_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (tagGameNode)");
    return 0;
}

int lua_register_cocos2dx_platform_tagGameNode(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"tagGameNode");
    tolua_cclass(tolua_S,"tagGameNode","tagGameNode","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"tagGameNode");
        tolua_function(tolua_S,"new",lua_cocos2dx_platform_tagGameNode_constructor);
        tolua_function(tolua_S,"setSortID",lua_cocos2dx_platform_tagGameNode_setSortID);
        tolua_function(tolua_S,"setNodeName",lua_cocos2dx_platform_tagGameNode_setNodeName);
        tolua_function(tolua_S,"getKindID",lua_cocos2dx_platform_tagGameNode_getKindID);
        tolua_function(tolua_S,"getNodeName",lua_cocos2dx_platform_tagGameNode_getNodeName);
        tolua_function(tolua_S,"setNodeID",lua_cocos2dx_platform_tagGameNode_setNodeID);
        tolua_function(tolua_S,"getSortID",lua_cocos2dx_platform_tagGameNode_getSortID);
        tolua_function(tolua_S,"getJoinID",lua_cocos2dx_platform_tagGameNode_getJoinID);
        tolua_function(tolua_S,"getNodeID",lua_cocos2dx_platform_tagGameNode_getNodeID);
        tolua_function(tolua_S,"setJoinID",lua_cocos2dx_platform_tagGameNode_setJoinID);
        tolua_function(tolua_S,"setKindID",lua_cocos2dx_platform_tagGameNode_setKindID);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(tagGameNode).name();
    g_luaType[typeName] = "tagGameNode";
    g_typeCast["tagGameNode"] = "tagGameNode";
    return 1;
}

int lua_cocos2dx_platform_tagGamePage_setDisplayName(lua_State* tolua_S)
{
    int argc = 0;
    tagGamePage* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGamePage",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGamePage*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGamePage_setDisplayName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        int arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "tagGamePage:setDisplayName"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "tagGamePage:setDisplayName");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGamePage_setDisplayName'", nullptr);
            return 0;
        }
        cobj->setDisplayName(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGamePage:setDisplayName",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGamePage_setDisplayName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGamePage_setNodeID(lua_State* tolua_S)
{
    int argc = 0;
    tagGamePage* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGamePage",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGamePage*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGamePage_setNodeID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagGamePage:setNodeID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGamePage_setNodeID'", nullptr);
            return 0;
        }
        cobj->setNodeID(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGamePage:setNodeID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGamePage_setNodeID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGamePage_getPageID(lua_State* tolua_S)
{
    int argc = 0;
    tagGamePage* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGamePage",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGamePage*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGamePage_getPageID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGamePage_getPageID'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->getPageID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGamePage:getPageID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGamePage_getPageID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGamePage_getKindID(lua_State* tolua_S)
{
    int argc = 0;
    tagGamePage* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGamePage",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGamePage*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGamePage_getKindID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGamePage_getKindID'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->getKindID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGamePage:getKindID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGamePage_getKindID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGamePage_setPageID(lua_State* tolua_S)
{
    int argc = 0;
    tagGamePage* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGamePage",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGamePage*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGamePage_setPageID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagGamePage:setPageID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGamePage_setPageID'", nullptr);
            return 0;
        }
        cobj->setPageID(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGamePage:setPageID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGamePage_setPageID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGamePage_setSortID(lua_State* tolua_S)
{
    int argc = 0;
    tagGamePage* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGamePage",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGamePage*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGamePage_setSortID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagGamePage:setSortID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGamePage_setSortID'", nullptr);
            return 0;
        }
        cobj->setSortID(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGamePage:setSortID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGamePage_setSortID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGamePage_getNodeID(lua_State* tolua_S)
{
    int argc = 0;
    tagGamePage* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGamePage",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGamePage*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGamePage_getNodeID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGamePage_getNodeID'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->getNodeID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGamePage:getNodeID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGamePage_getNodeID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGamePage_getSortID(lua_State* tolua_S)
{
    int argc = 0;
    tagGamePage* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGamePage",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGamePage*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGamePage_getSortID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGamePage_getSortID'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->getSortID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGamePage:getSortID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGamePage_getSortID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGamePage_setOperateType(lua_State* tolua_S)
{
    int argc = 0;
    tagGamePage* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGamePage",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGamePage*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGamePage_setOperateType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagGamePage:setOperateType");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGamePage_setOperateType'", nullptr);
            return 0;
        }
        cobj->setOperateType(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGamePage:setOperateType",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGamePage_setOperateType'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGamePage_setKindID(lua_State* tolua_S)
{
    int argc = 0;
    tagGamePage* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGamePage",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGamePage*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGamePage_setKindID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagGamePage:setKindID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGamePage_setKindID'", nullptr);
            return 0;
        }
        cobj->setKindID(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGamePage:setKindID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGamePage_setKindID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGamePage_getDisplayName(lua_State* tolua_S)
{
    int argc = 0;
    tagGamePage* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGamePage",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGamePage*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGamePage_getDisplayName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGamePage_getDisplayName'", nullptr);
            return 0;
        }
        const char* ret = cobj->getDisplayName();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGamePage:getDisplayName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGamePage_getDisplayName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGamePage_getOperateType(lua_State* tolua_S)
{
    int argc = 0;
    tagGamePage* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGamePage",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGamePage*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGamePage_getOperateType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGamePage_getOperateType'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->getOperateType();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGamePage:getOperateType",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGamePage_getOperateType'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGamePage_constructor(lua_State* tolua_S)
{
    int argc = 0;
    tagGamePage* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGamePage_constructor'", nullptr);
            return 0;
        }
        cobj = new tagGamePage();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"tagGamePage");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGamePage:tagGamePage",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGamePage_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_platform_tagGamePage_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (tagGamePage)");
    return 0;
}

int lua_register_cocos2dx_platform_tagGamePage(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"tagGamePage");
    tolua_cclass(tolua_S,"tagGamePage","tagGamePage","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"tagGamePage");
        tolua_function(tolua_S,"new",lua_cocos2dx_platform_tagGamePage_constructor);
        tolua_function(tolua_S,"setDisplayName",lua_cocos2dx_platform_tagGamePage_setDisplayName);
        tolua_function(tolua_S,"setNodeID",lua_cocos2dx_platform_tagGamePage_setNodeID);
        tolua_function(tolua_S,"getPageID",lua_cocos2dx_platform_tagGamePage_getPageID);
        tolua_function(tolua_S,"getKindID",lua_cocos2dx_platform_tagGamePage_getKindID);
        tolua_function(tolua_S,"setPageID",lua_cocos2dx_platform_tagGamePage_setPageID);
        tolua_function(tolua_S,"setSortID",lua_cocos2dx_platform_tagGamePage_setSortID);
        tolua_function(tolua_S,"getNodeID",lua_cocos2dx_platform_tagGamePage_getNodeID);
        tolua_function(tolua_S,"getSortID",lua_cocos2dx_platform_tagGamePage_getSortID);
        tolua_function(tolua_S,"setOperateType",lua_cocos2dx_platform_tagGamePage_setOperateType);
        tolua_function(tolua_S,"setKindID",lua_cocos2dx_platform_tagGamePage_setKindID);
        tolua_function(tolua_S,"getDisplayName",lua_cocos2dx_platform_tagGamePage_getDisplayName);
        tolua_function(tolua_S,"getOperateType",lua_cocos2dx_platform_tagGamePage_getOperateType);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(tagGamePage).name();
    g_luaType[typeName] = "tagGamePage";
    g_typeCast["tagGamePage"] = "tagGamePage";
    return 1;
}

int lua_cocos2dx_platform_tagGameServer_getServerPort(lua_State* tolua_S)
{
    int argc = 0;
    tagGameServer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameServer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameServer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameServer_getServerPort'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameServer_getServerPort'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->getServerPort();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameServer:getServerPort",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameServer_getServerPort'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameServer_setServerKind(lua_State* tolua_S)
{
    int argc = 0;
    tagGameServer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameServer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameServer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameServer_setServerKind'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagGameServer:setServerKind");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameServer_setServerKind'", nullptr);
            return 0;
        }
        cobj->setServerKind(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameServer:setServerKind",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameServer_setServerKind'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameServer_getSortID(lua_State* tolua_S)
{
    int argc = 0;
    tagGameServer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameServer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameServer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameServer_getSortID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameServer_getSortID'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->getSortID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameServer:getSortID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameServer_getSortID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameServer_setEnterScore(lua_State* tolua_S)
{
    int argc = 0;
    tagGameServer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameServer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameServer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameServer_setEnterScore'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        long long arg0;

        ok &= luaval_to_long_long(tolua_S, 2,&arg0, "tagGameServer:setEnterScore");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameServer_setEnterScore'", nullptr);
            return 0;
        }
        cobj->setEnterScore(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameServer:setEnterScore",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameServer_setEnterScore'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameServer_getServerName(lua_State* tolua_S)
{
    int argc = 0;
    tagGameServer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameServer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameServer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameServer_getServerName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameServer_getServerName'", nullptr);
            return 0;
        }
        const char* ret = cobj->getServerName();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameServer:getServerName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameServer_getServerName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameServer_setServerRule(lua_State* tolua_S)
{
    int argc = 0;
    tagGameServer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameServer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameServer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameServer_setServerRule'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "tagGameServer:setServerRule");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameServer_setServerRule'", nullptr);
            return 0;
        }
        cobj->setServerRule(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameServer:setServerRule",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameServer_setServerRule'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameServer_getEnterScore(lua_State* tolua_S)
{
    int argc = 0;
    tagGameServer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameServer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameServer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameServer_getEnterScore'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameServer_getEnterScore'", nullptr);
            return 0;
        }
        long long ret = cobj->getEnterScore();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameServer:getEnterScore",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameServer_getEnterScore'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameServer_getServerType(lua_State* tolua_S)
{
    int argc = 0;
    tagGameServer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameServer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameServer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameServer_getServerType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameServer_getServerType'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->getServerType();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameServer:getServerType",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameServer_getServerType'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameServer_getOnLineCount(lua_State* tolua_S)
{
    int argc = 0;
    tagGameServer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameServer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameServer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameServer_getOnLineCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameServer_getOnLineCount'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getOnLineCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameServer:getOnLineCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameServer_getOnLineCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameServer_setAndroidCount(lua_State* tolua_S)
{
    int argc = 0;
    tagGameServer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameServer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameServer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameServer_setAndroidCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "tagGameServer:setAndroidCount");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameServer_setAndroidCount'", nullptr);
            return 0;
        }
        cobj->setAndroidCount(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameServer:setAndroidCount",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameServer_setAndroidCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameServer_getServerID(lua_State* tolua_S)
{
    int argc = 0;
    tagGameServer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameServer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameServer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameServer_getServerID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameServer_getServerID'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->getServerID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameServer:getServerID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameServer_getServerID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameServer_setServerPort(lua_State* tolua_S)
{
    int argc = 0;
    tagGameServer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameServer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameServer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameServer_setServerPort'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagGameServer:setServerPort");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameServer_setServerPort'", nullptr);
            return 0;
        }
        cobj->setServerPort(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameServer:setServerPort",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameServer_setServerPort'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameServer_setServerID(lua_State* tolua_S)
{
    int argc = 0;
    tagGameServer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameServer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameServer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameServer_setServerID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagGameServer:setServerID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameServer_setServerID'", nullptr);
            return 0;
        }
        cobj->setServerID(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameServer:setServerID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameServer_setServerID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameServer_getServerKind(lua_State* tolua_S)
{
    int argc = 0;
    tagGameServer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameServer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameServer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameServer_getServerKind'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameServer_getServerKind'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->getServerKind();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameServer:getServerKind",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameServer_getServerKind'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameServer_setCellScore(lua_State* tolua_S)
{
    int argc = 0;
    tagGameServer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameServer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameServer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameServer_setCellScore'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        long long arg0;

        ok &= luaval_to_long_long(tolua_S, 2,&arg0, "tagGameServer:setCellScore");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameServer_setCellScore'", nullptr);
            return 0;
        }
        cobj->setCellScore(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameServer:setCellScore",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameServer_setCellScore'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameServer_getServerAddr(lua_State* tolua_S)
{
    int argc = 0;
    tagGameServer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameServer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameServer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameServer_getServerAddr'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameServer_getServerAddr'", nullptr);
            return 0;
        }
        const char* ret = cobj->getServerAddr();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameServer:getServerAddr",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameServer_getServerAddr'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameServer_getServerRule(lua_State* tolua_S)
{
    int argc = 0;
    tagGameServer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameServer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameServer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameServer_getServerRule'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameServer_getServerRule'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getServerRule();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameServer:getServerRule",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameServer_getServerRule'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameServer_setServerType(lua_State* tolua_S)
{
    int argc = 0;
    tagGameServer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameServer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameServer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameServer_setServerType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagGameServer:setServerType");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameServer_setServerType'", nullptr);
            return 0;
        }
        cobj->setServerType(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameServer:setServerType",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameServer_setServerType'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameServer_setSortID(lua_State* tolua_S)
{
    int argc = 0;
    tagGameServer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameServer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameServer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameServer_setSortID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagGameServer:setSortID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameServer_setSortID'", nullptr);
            return 0;
        }
        cobj->setSortID(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameServer:setSortID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameServer_setSortID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameServer_setServerName(lua_State* tolua_S)
{
    int argc = 0;
    tagGameServer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameServer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameServer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameServer_setServerName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        int arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "tagGameServer:setServerName"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "tagGameServer:setServerName");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameServer_setServerName'", nullptr);
            return 0;
        }
        cobj->setServerName(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameServer:setServerName",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameServer_setServerName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameServer_setKindID(lua_State* tolua_S)
{
    int argc = 0;
    tagGameServer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameServer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameServer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameServer_setKindID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagGameServer:setKindID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameServer_setKindID'", nullptr);
            return 0;
        }
        cobj->setKindID(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameServer:setKindID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameServer_setKindID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameServer_setNodeID(lua_State* tolua_S)
{
    int argc = 0;
    tagGameServer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameServer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameServer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameServer_setNodeID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagGameServer:setNodeID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameServer_setNodeID'", nullptr);
            return 0;
        }
        cobj->setNodeID(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameServer:setNodeID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameServer_setNodeID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameServer_getAndroidCount(lua_State* tolua_S)
{
    int argc = 0;
    tagGameServer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameServer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameServer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameServer_getAndroidCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameServer_getAndroidCount'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getAndroidCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameServer:getAndroidCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameServer_getAndroidCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameServer_getKindID(lua_State* tolua_S)
{
    int argc = 0;
    tagGameServer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameServer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameServer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameServer_getKindID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameServer_getKindID'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->getKindID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameServer:getKindID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameServer_getKindID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameServer_getCellScore(lua_State* tolua_S)
{
    int argc = 0;
    tagGameServer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameServer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameServer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameServer_getCellScore'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameServer_getCellScore'", nullptr);
            return 0;
        }
        long long ret = cobj->getCellScore();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameServer:getCellScore",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameServer_getCellScore'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameServer_getNodeID(lua_State* tolua_S)
{
    int argc = 0;
    tagGameServer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameServer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameServer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameServer_getNodeID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameServer_getNodeID'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->getNodeID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameServer:getNodeID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameServer_getNodeID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameServer_setFullCount(lua_State* tolua_S)
{
    int argc = 0;
    tagGameServer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameServer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameServer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameServer_setFullCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "tagGameServer:setFullCount");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameServer_setFullCount'", nullptr);
            return 0;
        }
        cobj->setFullCount(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameServer:setFullCount",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameServer_setFullCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameServer_setServerAddr(lua_State* tolua_S)
{
    int argc = 0;
    tagGameServer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameServer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameServer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameServer_setServerAddr'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        int arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "tagGameServer:setServerAddr"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "tagGameServer:setServerAddr");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameServer_setServerAddr'", nullptr);
            return 0;
        }
        cobj->setServerAddr(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameServer:setServerAddr",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameServer_setServerAddr'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameServer_getFullCount(lua_State* tolua_S)
{
    int argc = 0;
    tagGameServer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameServer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameServer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameServer_getFullCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameServer_getFullCount'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getFullCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameServer:getFullCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameServer_getFullCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameServer_setOnLineCount(lua_State* tolua_S)
{
    int argc = 0;
    tagGameServer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameServer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameServer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameServer_setOnLineCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "tagGameServer:setOnLineCount");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameServer_setOnLineCount'", nullptr);
            return 0;
        }
        cobj->setOnLineCount(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameServer:setOnLineCount",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameServer_setOnLineCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameServer_constructor(lua_State* tolua_S)
{
    int argc = 0;
    tagGameServer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameServer_constructor'", nullptr);
            return 0;
        }
        cobj = new tagGameServer();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"tagGameServer");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameServer:tagGameServer",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameServer_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_platform_tagGameServer_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (tagGameServer)");
    return 0;
}

int lua_register_cocos2dx_platform_tagGameServer(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"tagGameServer");
    tolua_cclass(tolua_S,"tagGameServer","tagGameServer","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"tagGameServer");
        tolua_function(tolua_S,"new",lua_cocos2dx_platform_tagGameServer_constructor);
        tolua_function(tolua_S,"getServerPort",lua_cocos2dx_platform_tagGameServer_getServerPort);
        tolua_function(tolua_S,"setServerKind",lua_cocos2dx_platform_tagGameServer_setServerKind);
        tolua_function(tolua_S,"getSortID",lua_cocos2dx_platform_tagGameServer_getSortID);
        tolua_function(tolua_S,"setEnterScore",lua_cocos2dx_platform_tagGameServer_setEnterScore);
        tolua_function(tolua_S,"getServerName",lua_cocos2dx_platform_tagGameServer_getServerName);
        tolua_function(tolua_S,"setServerRule",lua_cocos2dx_platform_tagGameServer_setServerRule);
        tolua_function(tolua_S,"getEnterScore",lua_cocos2dx_platform_tagGameServer_getEnterScore);
        tolua_function(tolua_S,"getServerType",lua_cocos2dx_platform_tagGameServer_getServerType);
        tolua_function(tolua_S,"getOnLineCount",lua_cocos2dx_platform_tagGameServer_getOnLineCount);
        tolua_function(tolua_S,"setAndroidCount",lua_cocos2dx_platform_tagGameServer_setAndroidCount);
        tolua_function(tolua_S,"getServerID",lua_cocos2dx_platform_tagGameServer_getServerID);
        tolua_function(tolua_S,"setServerPort",lua_cocos2dx_platform_tagGameServer_setServerPort);
        tolua_function(tolua_S,"setServerID",lua_cocos2dx_platform_tagGameServer_setServerID);
        tolua_function(tolua_S,"getServerKind",lua_cocos2dx_platform_tagGameServer_getServerKind);
        tolua_function(tolua_S,"setCellScore",lua_cocos2dx_platform_tagGameServer_setCellScore);
        tolua_function(tolua_S,"getServerAddr",lua_cocos2dx_platform_tagGameServer_getServerAddr);
        tolua_function(tolua_S,"getServerRule",lua_cocos2dx_platform_tagGameServer_getServerRule);
        tolua_function(tolua_S,"setServerType",lua_cocos2dx_platform_tagGameServer_setServerType);
        tolua_function(tolua_S,"setSortID",lua_cocos2dx_platform_tagGameServer_setSortID);
        tolua_function(tolua_S,"setServerName",lua_cocos2dx_platform_tagGameServer_setServerName);
        tolua_function(tolua_S,"setKindID",lua_cocos2dx_platform_tagGameServer_setKindID);
        tolua_function(tolua_S,"setNodeID",lua_cocos2dx_platform_tagGameServer_setNodeID);
        tolua_function(tolua_S,"getAndroidCount",lua_cocos2dx_platform_tagGameServer_getAndroidCount);
        tolua_function(tolua_S,"getKindID",lua_cocos2dx_platform_tagGameServer_getKindID);
        tolua_function(tolua_S,"getCellScore",lua_cocos2dx_platform_tagGameServer_getCellScore);
        tolua_function(tolua_S,"getNodeID",lua_cocos2dx_platform_tagGameServer_getNodeID);
        tolua_function(tolua_S,"setFullCount",lua_cocos2dx_platform_tagGameServer_setFullCount);
        tolua_function(tolua_S,"setServerAddr",lua_cocos2dx_platform_tagGameServer_setServerAddr);
        tolua_function(tolua_S,"getFullCount",lua_cocos2dx_platform_tagGameServer_getFullCount);
        tolua_function(tolua_S,"setOnLineCount",lua_cocos2dx_platform_tagGameServer_setOnLineCount);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(tagGameServer).name();
    g_luaType[typeName] = "tagGameServer";
    g_typeCast["tagGameServer"] = "tagGameServer";
    return 1;
}

int lua_cocos2dx_platform_tagGameMatch_getMatchFeeType(lua_State* tolua_S)
{
    int argc = 0;
    tagGameMatch* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameMatch",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameMatch*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameMatch_getMatchFeeType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameMatch_getMatchFeeType'", nullptr);
            return 0;
        }
        uint16_t ret = cobj->getMatchFeeType();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameMatch:getMatchFeeType",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameMatch_getMatchFeeType'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameMatch_setMatchFee(lua_State* tolua_S)
{
    int argc = 0;
    tagGameMatch* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameMatch",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameMatch*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameMatch_setMatchFee'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        long long arg0;

        ok &= luaval_to_long_long(tolua_S, 2,&arg0, "tagGameMatch:setMatchFee");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameMatch_setMatchFee'", nullptr);
            return 0;
        }
        cobj->setMatchFee(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameMatch:setMatchFee",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameMatch_setMatchFee'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameMatch_setStartUserCount(lua_State* tolua_S)
{
    int argc = 0;
    tagGameMatch* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameMatch",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameMatch*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameMatch_setStartUserCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagGameMatch:setStartUserCount");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameMatch_setStartUserCount'", nullptr);
            return 0;
        }
        cobj->setStartUserCount(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameMatch:setStartUserCount",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameMatch_setStartUserCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameMatch_setMatchNO(lua_State* tolua_S)
{
    int argc = 0;
    tagGameMatch* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameMatch",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameMatch*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameMatch_setMatchNO'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "tagGameMatch:setMatchNO");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameMatch_setMatchNO'", nullptr);
            return 0;
        }
        cobj->setMatchNO(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameMatch:setMatchNO",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameMatch_setMatchNO'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameMatch_setMatchPlayCount(lua_State* tolua_S)
{
    int argc = 0;
    tagGameMatch* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameMatch",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameMatch*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameMatch_setMatchPlayCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagGameMatch:setMatchPlayCount");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameMatch_setMatchPlayCount'", nullptr);
            return 0;
        }
        cobj->setMatchPlayCount(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameMatch:setMatchPlayCount",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameMatch_setMatchPlayCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameMatch_getMemberOrder(lua_State* tolua_S)
{
    int argc = 0;
    tagGameMatch* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameMatch",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameMatch*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameMatch_getMemberOrder'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameMatch_getMemberOrder'", nullptr);
            return 0;
        }
        uint16_t ret = cobj->getMemberOrder();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameMatch:getMemberOrder",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameMatch_getMemberOrder'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameMatch_setMemberOrder(lua_State* tolua_S)
{
    int argc = 0;
    tagGameMatch* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameMatch",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameMatch*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameMatch_setMemberOrder'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        uint16_t arg0;

        ok &= luaval_to_uint16(tolua_S, 2,&arg0, "tagGameMatch:setMemberOrder");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameMatch_setMemberOrder'", nullptr);
            return 0;
        }
        cobj->setMemberOrder(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameMatch:setMemberOrder",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameMatch_setMemberOrder'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameMatch_setMatchName(lua_State* tolua_S)
{
    int argc = 0;
    tagGameMatch* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameMatch",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameMatch*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameMatch_setMatchName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        int arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "tagGameMatch:setMatchName"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "tagGameMatch:setMatchName");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameMatch_setMatchName'", nullptr);
            return 0;
        }
        cobj->setMatchName(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameMatch:setMatchName",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameMatch_setMatchName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameMatch_getMatchType(lua_State* tolua_S)
{
    int argc = 0;
    tagGameMatch* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameMatch",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameMatch*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameMatch_getMatchType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameMatch_getMatchType'", nullptr);
            return 0;
        }
        uint16_t ret = cobj->getMatchType();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameMatch:getMatchType",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameMatch_getMatchType'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameMatch_getMatchNO(lua_State* tolua_S)
{
    int argc = 0;
    tagGameMatch* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameMatch",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameMatch*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameMatch_getMatchNO'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameMatch_getMatchNO'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getMatchNO();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameMatch:getMatchNO",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameMatch_getMatchNO'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameMatch_getMatchPlayCount(lua_State* tolua_S)
{
    int argc = 0;
    tagGameMatch* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameMatch",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameMatch*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameMatch_getMatchPlayCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameMatch_getMatchPlayCount'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->getMatchPlayCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameMatch:getMatchPlayCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameMatch_getMatchPlayCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameMatch_getServerID(lua_State* tolua_S)
{
    int argc = 0;
    tagGameMatch* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameMatch",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameMatch*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameMatch_getServerID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameMatch_getServerID'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->getServerID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameMatch:getServerID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameMatch_getServerID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameMatch_getRewardCount(lua_State* tolua_S)
{
    int argc = 0;
    tagGameMatch* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameMatch",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameMatch*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameMatch_getRewardCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameMatch_getRewardCount'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->getRewardCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameMatch:getRewardCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameMatch_getRewardCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameMatch_setMatchFeeType(lua_State* tolua_S)
{
    int argc = 0;
    tagGameMatch* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameMatch",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameMatch*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameMatch_setMatchFeeType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        uint16_t arg0;

        ok &= luaval_to_uint16(tolua_S, 2,&arg0, "tagGameMatch:setMatchFeeType");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameMatch_setMatchFeeType'", nullptr);
            return 0;
        }
        cobj->setMatchFeeType(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameMatch:setMatchFeeType",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameMatch_setMatchFeeType'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameMatch_getMatchEndTime(lua_State* tolua_S)
{
    int argc = 0;
    tagGameMatch* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameMatch",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameMatch*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameMatch_getMatchEndTime'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameMatch_getMatchEndTime'", nullptr);
            return 0;
        }
        long long ret = cobj->getMatchEndTime();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameMatch:getMatchEndTime",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameMatch_getMatchEndTime'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameMatch_setServerID(lua_State* tolua_S)
{
    int argc = 0;
    tagGameMatch* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameMatch",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameMatch*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameMatch_setServerID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagGameMatch:setServerID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameMatch_setServerID'", nullptr);
            return 0;
        }
        cobj->setServerID(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameMatch:setServerID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameMatch_setServerID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameMatch_setMatchStartTime(lua_State* tolua_S)
{
    int argc = 0;
    tagGameMatch* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameMatch",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameMatch*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameMatch_setMatchStartTime'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        long long arg0;

        ok &= luaval_to_long_long(tolua_S, 2,&arg0, "tagGameMatch:setMatchStartTime");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameMatch_setMatchStartTime'", nullptr);
            return 0;
        }
        cobj->setMatchStartTime(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameMatch:setMatchStartTime",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameMatch_setMatchStartTime'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameMatch_setMatchEndTime(lua_State* tolua_S)
{
    int argc = 0;
    tagGameMatch* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameMatch",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameMatch*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameMatch_setMatchEndTime'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        long long arg0;

        ok &= luaval_to_long_long(tolua_S, 2,&arg0, "tagGameMatch:setMatchEndTime");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameMatch_setMatchEndTime'", nullptr);
            return 0;
        }
        cobj->setMatchEndTime(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameMatch:setMatchEndTime",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameMatch_setMatchEndTime'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameMatch_setMatchID(lua_State* tolua_S)
{
    int argc = 0;
    tagGameMatch* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameMatch",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameMatch*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameMatch_setMatchID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "tagGameMatch:setMatchID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameMatch_setMatchID'", nullptr);
            return 0;
        }
        cobj->setMatchID(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameMatch:setMatchID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameMatch_setMatchID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameMatch_getCountDown(lua_State* tolua_S)
{
    int argc = 0;
    tagGameMatch* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameMatch",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameMatch*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameMatch_getCountDown'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameMatch_getCountDown'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->getCountDown();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameMatch:getCountDown",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameMatch_getCountDown'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameMatch_setMatchType(lua_State* tolua_S)
{
    int argc = 0;
    tagGameMatch* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameMatch",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameMatch*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameMatch_setMatchType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        uint16_t arg0;

        ok &= luaval_to_uint16(tolua_S, 2,&arg0, "tagGameMatch:setMatchType");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameMatch_setMatchType'", nullptr);
            return 0;
        }
        cobj->setMatchType(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameMatch:setMatchType",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameMatch_setMatchType'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameMatch_setRewardCount(lua_State* tolua_S)
{
    int argc = 0;
    tagGameMatch* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameMatch",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameMatch*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameMatch_setRewardCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagGameMatch:setRewardCount");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameMatch_setRewardCount'", nullptr);
            return 0;
        }
        cobj->setRewardCount(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameMatch:setRewardCount",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameMatch_setRewardCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameMatch_getStartUserCount(lua_State* tolua_S)
{
    int argc = 0;
    tagGameMatch* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameMatch",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameMatch*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameMatch_getStartUserCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameMatch_getStartUserCount'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->getStartUserCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameMatch:getStartUserCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameMatch_getStartUserCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameMatch_getMatchID(lua_State* tolua_S)
{
    int argc = 0;
    tagGameMatch* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameMatch",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameMatch*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameMatch_getMatchID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameMatch_getMatchID'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getMatchID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameMatch:getMatchID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameMatch_getMatchID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameMatch_getMatchName(lua_State* tolua_S)
{
    int argc = 0;
    tagGameMatch* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameMatch",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameMatch*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameMatch_getMatchName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameMatch_getMatchName'", nullptr);
            return 0;
        }
        const char* ret = cobj->getMatchName();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameMatch:getMatchName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameMatch_getMatchName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameMatch_setCountDown(lua_State* tolua_S)
{
    int argc = 0;
    tagGameMatch* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameMatch",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameMatch*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameMatch_setCountDown'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagGameMatch:setCountDown");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameMatch_setCountDown'", nullptr);
            return 0;
        }
        cobj->setCountDown(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameMatch:setCountDown",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameMatch_setCountDown'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameMatch_getMatchStartTime(lua_State* tolua_S)
{
    int argc = 0;
    tagGameMatch* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameMatch",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameMatch*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameMatch_getMatchStartTime'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameMatch_getMatchStartTime'", nullptr);
            return 0;
        }
        long long ret = cobj->getMatchStartTime();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameMatch:getMatchStartTime",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameMatch_getMatchStartTime'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameMatch_getMatchFee(lua_State* tolua_S)
{
    int argc = 0;
    tagGameMatch* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameMatch",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameMatch*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGameMatch_getMatchFee'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameMatch_getMatchFee'", nullptr);
            return 0;
        }
        long long ret = cobj->getMatchFee();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameMatch:getMatchFee",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameMatch_getMatchFee'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGameMatch_constructor(lua_State* tolua_S)
{
    int argc = 0;
    tagGameMatch* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGameMatch_constructor'", nullptr);
            return 0;
        }
        cobj = new tagGameMatch();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"tagGameMatch");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameMatch:tagGameMatch",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGameMatch_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_platform_tagGameMatch_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (tagGameMatch)");
    return 0;
}

int lua_register_cocos2dx_platform_tagGameMatch(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"tagGameMatch");
    tolua_cclass(tolua_S,"tagGameMatch","tagGameMatch","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"tagGameMatch");
        tolua_function(tolua_S,"new",lua_cocos2dx_platform_tagGameMatch_constructor);
        tolua_function(tolua_S,"getMatchFeeType",lua_cocos2dx_platform_tagGameMatch_getMatchFeeType);
        tolua_function(tolua_S,"setMatchFee",lua_cocos2dx_platform_tagGameMatch_setMatchFee);
        tolua_function(tolua_S,"setStartUserCount",lua_cocos2dx_platform_tagGameMatch_setStartUserCount);
        tolua_function(tolua_S,"setMatchNO",lua_cocos2dx_platform_tagGameMatch_setMatchNO);
        tolua_function(tolua_S,"setMatchPlayCount",lua_cocos2dx_platform_tagGameMatch_setMatchPlayCount);
        tolua_function(tolua_S,"getMemberOrder",lua_cocos2dx_platform_tagGameMatch_getMemberOrder);
        tolua_function(tolua_S,"setMemberOrder",lua_cocos2dx_platform_tagGameMatch_setMemberOrder);
        tolua_function(tolua_S,"setMatchName",lua_cocos2dx_platform_tagGameMatch_setMatchName);
        tolua_function(tolua_S,"getMatchType",lua_cocos2dx_platform_tagGameMatch_getMatchType);
        tolua_function(tolua_S,"getMatchNO",lua_cocos2dx_platform_tagGameMatch_getMatchNO);
        tolua_function(tolua_S,"getMatchPlayCount",lua_cocos2dx_platform_tagGameMatch_getMatchPlayCount);
        tolua_function(tolua_S,"getServerID",lua_cocos2dx_platform_tagGameMatch_getServerID);
        tolua_function(tolua_S,"getRewardCount",lua_cocos2dx_platform_tagGameMatch_getRewardCount);
        tolua_function(tolua_S,"setMatchFeeType",lua_cocos2dx_platform_tagGameMatch_setMatchFeeType);
        tolua_function(tolua_S,"getMatchEndTime",lua_cocos2dx_platform_tagGameMatch_getMatchEndTime);
        tolua_function(tolua_S,"setServerID",lua_cocos2dx_platform_tagGameMatch_setServerID);
        tolua_function(tolua_S,"setMatchStartTime",lua_cocos2dx_platform_tagGameMatch_setMatchStartTime);
        tolua_function(tolua_S,"setMatchEndTime",lua_cocos2dx_platform_tagGameMatch_setMatchEndTime);
        tolua_function(tolua_S,"setMatchID",lua_cocos2dx_platform_tagGameMatch_setMatchID);
        tolua_function(tolua_S,"getCountDown",lua_cocos2dx_platform_tagGameMatch_getCountDown);
        tolua_function(tolua_S,"setMatchType",lua_cocos2dx_platform_tagGameMatch_setMatchType);
        tolua_function(tolua_S,"setRewardCount",lua_cocos2dx_platform_tagGameMatch_setRewardCount);
        tolua_function(tolua_S,"getStartUserCount",lua_cocos2dx_platform_tagGameMatch_getStartUserCount);
        tolua_function(tolua_S,"getMatchID",lua_cocos2dx_platform_tagGameMatch_getMatchID);
        tolua_function(tolua_S,"getMatchName",lua_cocos2dx_platform_tagGameMatch_getMatchName);
        tolua_function(tolua_S,"setCountDown",lua_cocos2dx_platform_tagGameMatch_setCountDown);
        tolua_function(tolua_S,"getMatchStartTime",lua_cocos2dx_platform_tagGameMatch_getMatchStartTime);
        tolua_function(tolua_S,"getMatchFee",lua_cocos2dx_platform_tagGameMatch_getMatchFee);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(tagGameMatch).name();
    g_luaType[typeName] = "tagGameMatch";
    g_typeCast["tagGameMatch"] = "tagGameMatch";
    return 1;
}

int lua_cocos2dx_platform_tagUserStatus_getTableID(lua_State* tolua_S)
{
    int argc = 0;
    tagUserStatus* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserStatus",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserStatus*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserStatus_getTableID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserStatus_getTableID'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->getTableID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserStatus:getTableID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserStatus_getTableID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserStatus_getChairID(lua_State* tolua_S)
{
    int argc = 0;
    tagUserStatus* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserStatus",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserStatus*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserStatus_getChairID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserStatus_getChairID'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->getChairID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserStatus:getChairID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserStatus_getChairID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserStatus_setUserStatus(lua_State* tolua_S)
{
    int argc = 0;
    tagUserStatus* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserStatus",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserStatus*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserStatus_setUserStatus'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        uint16_t arg0;

        ok &= luaval_to_uint16(tolua_S, 2,&arg0, "tagUserStatus:setUserStatus");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserStatus_setUserStatus'", nullptr);
            return 0;
        }
        cobj->setUserStatus(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserStatus:setUserStatus",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserStatus_setUserStatus'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserStatus_setChairID(lua_State* tolua_S)
{
    int argc = 0;
    tagUserStatus* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserStatus",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserStatus*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserStatus_setChairID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagUserStatus:setChairID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserStatus_setChairID'", nullptr);
            return 0;
        }
        cobj->setChairID(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserStatus:setChairID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserStatus_setChairID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserStatus_setTableID(lua_State* tolua_S)
{
    int argc = 0;
    tagUserStatus* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserStatus",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserStatus*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserStatus_setTableID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagUserStatus:setTableID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserStatus_setTableID'", nullptr);
            return 0;
        }
        cobj->setTableID(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserStatus:setTableID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserStatus_setTableID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserStatus_getUserStatus(lua_State* tolua_S)
{
    int argc = 0;
    tagUserStatus* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserStatus",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserStatus*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserStatus_getUserStatus'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserStatus_getUserStatus'", nullptr);
            return 0;
        }
        uint16_t ret = cobj->getUserStatus();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserStatus:getUserStatus",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserStatus_getUserStatus'.",&tolua_err);
#endif

    return 0;
}
static int lua_cocos2dx_platform_tagUserStatus_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (tagUserStatus)");
    return 0;
}

int lua_register_cocos2dx_platform_tagUserStatus(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"tagUserStatus");
    tolua_cclass(tolua_S,"tagUserStatus","tagUserStatus","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"tagUserStatus");
        tolua_function(tolua_S,"getTableID",lua_cocos2dx_platform_tagUserStatus_getTableID);
        tolua_function(tolua_S,"getChairID",lua_cocos2dx_platform_tagUserStatus_getChairID);
        tolua_function(tolua_S,"setUserStatus",lua_cocos2dx_platform_tagUserStatus_setUserStatus);
        tolua_function(tolua_S,"setChairID",lua_cocos2dx_platform_tagUserStatus_setChairID);
        tolua_function(tolua_S,"setTableID",lua_cocos2dx_platform_tagUserStatus_setTableID);
        tolua_function(tolua_S,"getUserStatus",lua_cocos2dx_platform_tagUserStatus_getUserStatus);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(tagUserStatus).name();
    g_luaType[typeName] = "tagUserStatus";
    g_typeCast["tagUserStatus"] = "tagUserStatus";
    return 1;
}

int lua_cocos2dx_platform_tagUserAttrib_setCompanion(lua_State* tolua_S)
{
    int argc = 0;
    tagUserAttrib* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserAttrib",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserAttrib*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserAttrib_setCompanion'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        uint16_t arg0;

        ok &= luaval_to_uint16(tolua_S, 2,&arg0, "tagUserAttrib:setCompanion");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserAttrib_setCompanion'", nullptr);
            return 0;
        }
        cobj->setCompanion(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserAttrib:setCompanion",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserAttrib_setCompanion'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserAttrib_getCompanion(lua_State* tolua_S)
{
    int argc = 0;
    tagUserAttrib* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserAttrib",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserAttrib*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserAttrib_getCompanion'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserAttrib_getCompanion'", nullptr);
            return 0;
        }
        uint16_t ret = cobj->getCompanion();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserAttrib:getCompanion",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserAttrib_getCompanion'.",&tolua_err);
#endif

    return 0;
}
static int lua_cocos2dx_platform_tagUserAttrib_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (tagUserAttrib)");
    return 0;
}

int lua_register_cocos2dx_platform_tagUserAttrib(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"tagUserAttrib");
    tolua_cclass(tolua_S,"tagUserAttrib","tagUserAttrib","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"tagUserAttrib");
        tolua_function(tolua_S,"setCompanion",lua_cocos2dx_platform_tagUserAttrib_setCompanion);
        tolua_function(tolua_S,"getCompanion",lua_cocos2dx_platform_tagUserAttrib_getCompanion);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(tagUserAttrib).name();
    g_luaType[typeName] = "tagUserAttrib";
    g_typeCast["tagUserAttrib"] = "tagUserAttrib";
    return 1;
}

int lua_cocos2dx_platform_tagUserScore_setFleeCount(lua_State* tolua_S)
{
    int argc = 0;
    tagUserScore* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserScore",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserScore*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserScore_setFleeCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "tagUserScore:setFleeCount");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserScore_setFleeCount'", nullptr);
            return 0;
        }
        cobj->setFleeCount(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserScore:setFleeCount",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserScore_setFleeCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserScore_setGrade(lua_State* tolua_S)
{
    int argc = 0;
    tagUserScore* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserScore",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserScore*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserScore_setGrade'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        long long arg0;

        ok &= luaval_to_long_long(tolua_S, 2,&arg0, "tagUserScore:setGrade");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserScore_setGrade'", nullptr);
            return 0;
        }
        cobj->setGrade(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserScore:setGrade",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserScore_setGrade'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserScore_setLoveLiness(lua_State* tolua_S)
{
    int argc = 0;
    tagUserScore* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserScore",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserScore*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserScore_setLoveLiness'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "tagUserScore:setLoveLiness");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserScore_setLoveLiness'", nullptr);
            return 0;
        }
        cobj->setLoveLiness(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserScore:setLoveLiness",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserScore_setLoveLiness'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserScore_getLostCount(lua_State* tolua_S)
{
    int argc = 0;
    tagUserScore* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserScore",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserScore*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserScore_getLostCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserScore_getLostCount'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getLostCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserScore:getLostCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserScore_getLostCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserScore_getGrade(lua_State* tolua_S)
{
    int argc = 0;
    tagUserScore* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserScore",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserScore*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserScore_getGrade'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserScore_getGrade'", nullptr);
            return 0;
        }
        long long ret = cobj->getGrade();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserScore:getGrade",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserScore_getGrade'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserScore_getScore(lua_State* tolua_S)
{
    int argc = 0;
    tagUserScore* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserScore",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserScore*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserScore_getScore'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserScore_getScore'", nullptr);
            return 0;
        }
        long long ret = cobj->getScore();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserScore:getScore",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserScore_getScore'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserScore_setLostCount(lua_State* tolua_S)
{
    int argc = 0;
    tagUserScore* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserScore",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserScore*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserScore_setLostCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "tagUserScore:setLostCount");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserScore_setLostCount'", nullptr);
            return 0;
        }
        cobj->setLostCount(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserScore:setLostCount",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserScore_setLostCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserScore_getFleeCount(lua_State* tolua_S)
{
    int argc = 0;
    tagUserScore* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserScore",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserScore*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserScore_getFleeCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserScore_getFleeCount'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getFleeCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserScore:getFleeCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserScore_getFleeCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserScore_setExperience(lua_State* tolua_S)
{
    int argc = 0;
    tagUserScore* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserScore",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserScore*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserScore_setExperience'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "tagUserScore:setExperience");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserScore_setExperience'", nullptr);
            return 0;
        }
        cobj->setExperience(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserScore:setExperience",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserScore_setExperience'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserScore_setInsure(lua_State* tolua_S)
{
    int argc = 0;
    tagUserScore* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserScore",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserScore*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserScore_setInsure'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        long long arg0;

        ok &= luaval_to_long_long(tolua_S, 2,&arg0, "tagUserScore:setInsure");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserScore_setInsure'", nullptr);
            return 0;
        }
        cobj->setInsure(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserScore:setInsure",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserScore_setInsure'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserScore_getDrawCount(lua_State* tolua_S)
{
    int argc = 0;
    tagUserScore* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserScore",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserScore*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserScore_getDrawCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserScore_getDrawCount'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getDrawCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserScore:getDrawCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserScore_getDrawCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserScore_setWinCount(lua_State* tolua_S)
{
    int argc = 0;
    tagUserScore* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserScore",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserScore*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserScore_setWinCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "tagUserScore:setWinCount");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserScore_setWinCount'", nullptr);
            return 0;
        }
        cobj->setWinCount(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserScore:setWinCount",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserScore_setWinCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserScore_getIngot(lua_State* tolua_S)
{
    int argc = 0;
    tagUserScore* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserScore",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserScore*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserScore_getIngot'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserScore_getIngot'", nullptr);
            return 0;
        }
        long long ret = cobj->getIngot();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserScore:getIngot",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserScore_getIngot'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserScore_setIngot(lua_State* tolua_S)
{
    int argc = 0;
    tagUserScore* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserScore",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserScore*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserScore_setIngot'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        long long arg0;

        ok &= luaval_to_long_long(tolua_S, 2,&arg0, "tagUserScore:setIngot");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserScore_setIngot'", nullptr);
            return 0;
        }
        cobj->setIngot(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserScore:setIngot",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserScore_setIngot'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserScore_getWinCount(lua_State* tolua_S)
{
    int argc = 0;
    tagUserScore* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserScore",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserScore*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserScore_getWinCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserScore_getWinCount'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getWinCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserScore:getWinCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserScore_getWinCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserScore_getLoveLiness(lua_State* tolua_S)
{
    int argc = 0;
    tagUserScore* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserScore",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserScore*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserScore_getLoveLiness'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserScore_getLoveLiness'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getLoveLiness();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserScore:getLoveLiness",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserScore_getLoveLiness'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserScore_getInsure(lua_State* tolua_S)
{
    int argc = 0;
    tagUserScore* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserScore",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserScore*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserScore_getInsure'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserScore_getInsure'", nullptr);
            return 0;
        }
        long long ret = cobj->getInsure();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserScore:getInsure",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserScore_getInsure'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserScore_getExperience(lua_State* tolua_S)
{
    int argc = 0;
    tagUserScore* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserScore",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserScore*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserScore_getExperience'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserScore_getExperience'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getExperience();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserScore:getExperience",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserScore_getExperience'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserScore_setScore(lua_State* tolua_S)
{
    int argc = 0;
    tagUserScore* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserScore",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserScore*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserScore_setScore'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        long long arg0;

        ok &= luaval_to_long_long(tolua_S, 2,&arg0, "tagUserScore:setScore");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserScore_setScore'", nullptr);
            return 0;
        }
        cobj->setScore(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserScore:setScore",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserScore_setScore'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserScore_setDrawCount(lua_State* tolua_S)
{
    int argc = 0;
    tagUserScore* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserScore",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserScore*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserScore_setDrawCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "tagUserScore:setDrawCount");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserScore_setDrawCount'", nullptr);
            return 0;
        }
        cobj->setDrawCount(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserScore:setDrawCount",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserScore_setDrawCount'.",&tolua_err);
#endif

    return 0;
}
static int lua_cocos2dx_platform_tagUserScore_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (tagUserScore)");
    return 0;
}

int lua_register_cocos2dx_platform_tagUserScore(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"tagUserScore");
    tolua_cclass(tolua_S,"tagUserScore","tagUserScore","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"tagUserScore");
        tolua_function(tolua_S,"setFleeCount",lua_cocos2dx_platform_tagUserScore_setFleeCount);
        tolua_function(tolua_S,"setGrade",lua_cocos2dx_platform_tagUserScore_setGrade);
        tolua_function(tolua_S,"setLoveLiness",lua_cocos2dx_platform_tagUserScore_setLoveLiness);
        tolua_function(tolua_S,"getLostCount",lua_cocos2dx_platform_tagUserScore_getLostCount);
        tolua_function(tolua_S,"getGrade",lua_cocos2dx_platform_tagUserScore_getGrade);
        tolua_function(tolua_S,"getScore",lua_cocos2dx_platform_tagUserScore_getScore);
        tolua_function(tolua_S,"setLostCount",lua_cocos2dx_platform_tagUserScore_setLostCount);
        tolua_function(tolua_S,"getFleeCount",lua_cocos2dx_platform_tagUserScore_getFleeCount);
        tolua_function(tolua_S,"setExperience",lua_cocos2dx_platform_tagUserScore_setExperience);
        tolua_function(tolua_S,"setInsure",lua_cocos2dx_platform_tagUserScore_setInsure);
        tolua_function(tolua_S,"getDrawCount",lua_cocos2dx_platform_tagUserScore_getDrawCount);
        tolua_function(tolua_S,"setWinCount",lua_cocos2dx_platform_tagUserScore_setWinCount);
        tolua_function(tolua_S,"getIngot",lua_cocos2dx_platform_tagUserScore_getIngot);
        tolua_function(tolua_S,"setIngot",lua_cocos2dx_platform_tagUserScore_setIngot);
        tolua_function(tolua_S,"getWinCount",lua_cocos2dx_platform_tagUserScore_getWinCount);
        tolua_function(tolua_S,"getLoveLiness",lua_cocos2dx_platform_tagUserScore_getLoveLiness);
        tolua_function(tolua_S,"getInsure",lua_cocos2dx_platform_tagUserScore_getInsure);
        tolua_function(tolua_S,"getExperience",lua_cocos2dx_platform_tagUserScore_getExperience);
        tolua_function(tolua_S,"setScore",lua_cocos2dx_platform_tagUserScore_setScore);
        tolua_function(tolua_S,"setDrawCount",lua_cocos2dx_platform_tagUserScore_setDrawCount);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(tagUserScore).name();
    g_luaType[typeName] = "tagUserScore";
    g_typeCast["tagUserScore"] = "tagUserScore";
    return 1;
}

int lua_cocos2dx_platform_tagPropertyPackage_getTyphonCount(lua_State* tolua_S)
{
    int argc = 0;
    tagPropertyPackage* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagPropertyPackage",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagPropertyPackage*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagPropertyPackage_getTyphonCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagPropertyPackage_getTyphonCount'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->getTyphonCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagPropertyPackage:getTyphonCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagPropertyPackage_getTyphonCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagPropertyPackage_getTrumpetCount(lua_State* tolua_S)
{
    int argc = 0;
    tagPropertyPackage* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagPropertyPackage",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagPropertyPackage*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagPropertyPackage_getTrumpetCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagPropertyPackage_getTrumpetCount'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->getTrumpetCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagPropertyPackage:getTrumpetCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagPropertyPackage_getTrumpetCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagPropertyPackage_setTyphonCount(lua_State* tolua_S)
{
    int argc = 0;
    tagPropertyPackage* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagPropertyPackage",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagPropertyPackage*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagPropertyPackage_setTyphonCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagPropertyPackage:setTyphonCount");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagPropertyPackage_setTyphonCount'", nullptr);
            return 0;
        }
        cobj->setTyphonCount(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagPropertyPackage:setTyphonCount",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagPropertyPackage_setTyphonCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagPropertyPackage_setTrumpetCount(lua_State* tolua_S)
{
    int argc = 0;
    tagPropertyPackage* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagPropertyPackage",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagPropertyPackage*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagPropertyPackage_setTrumpetCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagPropertyPackage:setTrumpetCount");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagPropertyPackage_setTrumpetCount'", nullptr);
            return 0;
        }
        cobj->setTrumpetCount(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagPropertyPackage:setTrumpetCount",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagPropertyPackage_setTrumpetCount'.",&tolua_err);
#endif

    return 0;
}
static int lua_cocos2dx_platform_tagPropertyPackage_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (tagPropertyPackage)");
    return 0;
}

int lua_register_cocos2dx_platform_tagPropertyPackage(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"tagPropertyPackage");
    tolua_cclass(tolua_S,"tagPropertyPackage","tagPropertyPackage","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"tagPropertyPackage");
        tolua_function(tolua_S,"getTyphonCount",lua_cocos2dx_platform_tagPropertyPackage_getTyphonCount);
        tolua_function(tolua_S,"getTrumpetCount",lua_cocos2dx_platform_tagPropertyPackage_getTrumpetCount);
        tolua_function(tolua_S,"setTyphonCount",lua_cocos2dx_platform_tagPropertyPackage_setTyphonCount);
        tolua_function(tolua_S,"setTrumpetCount",lua_cocos2dx_platform_tagPropertyPackage_setTrumpetCount);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(tagPropertyPackage).name();
    g_luaType[typeName] = "tagPropertyPackage";
    g_typeCast["tagPropertyPackage"] = "tagPropertyPackage";
    return 1;
}

int lua_cocos2dx_platform_tagTimeInfo_getStartGameTimer(lua_State* tolua_S)
{
    int argc = 0;
    tagTimeInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagTimeInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagTimeInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagTimeInfo_getStartGameTimer'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagTimeInfo_getStartGameTimer'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getStartGameTimer();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagTimeInfo:getStartGameTimer",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagTimeInfo_getStartGameTimer'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagTimeInfo_setEndGameTimer(lua_State* tolua_S)
{
    int argc = 0;
    tagTimeInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagTimeInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagTimeInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagTimeInfo_setEndGameTimer'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "tagTimeInfo:setEndGameTimer");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagTimeInfo_setEndGameTimer'", nullptr);
            return 0;
        }
        cobj->setEndGameTimer(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagTimeInfo:setEndGameTimer",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagTimeInfo_setEndGameTimer'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagTimeInfo_setLeaveTableTimer(lua_State* tolua_S)
{
    int argc = 0;
    tagTimeInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagTimeInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagTimeInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagTimeInfo_setLeaveTableTimer'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "tagTimeInfo:setLeaveTableTimer");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagTimeInfo_setLeaveTableTimer'", nullptr);
            return 0;
        }
        cobj->setLeaveTableTimer(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagTimeInfo:setLeaveTableTimer",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagTimeInfo_setLeaveTableTimer'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagTimeInfo_setStartGameTimer(lua_State* tolua_S)
{
    int argc = 0;
    tagTimeInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagTimeInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagTimeInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagTimeInfo_setStartGameTimer'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "tagTimeInfo:setStartGameTimer");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagTimeInfo_setStartGameTimer'", nullptr);
            return 0;
        }
        cobj->setStartGameTimer(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagTimeInfo:setStartGameTimer",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagTimeInfo_setStartGameTimer'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagTimeInfo_getEndGameTimer(lua_State* tolua_S)
{
    int argc = 0;
    tagTimeInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagTimeInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagTimeInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagTimeInfo_getEndGameTimer'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagTimeInfo_getEndGameTimer'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getEndGameTimer();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagTimeInfo:getEndGameTimer",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagTimeInfo_getEndGameTimer'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagTimeInfo_getLeaveTableTimer(lua_State* tolua_S)
{
    int argc = 0;
    tagTimeInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagTimeInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagTimeInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagTimeInfo_getLeaveTableTimer'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagTimeInfo_getLeaveTableTimer'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getLeaveTableTimer();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagTimeInfo:getLeaveTableTimer",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagTimeInfo_getLeaveTableTimer'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagTimeInfo_getEnterTableTimer(lua_State* tolua_S)
{
    int argc = 0;
    tagTimeInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagTimeInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagTimeInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagTimeInfo_getEnterTableTimer'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagTimeInfo_getEnterTableTimer'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getEnterTableTimer();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagTimeInfo:getEnterTableTimer",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagTimeInfo_getEnterTableTimer'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagTimeInfo_setEnterTableTimer(lua_State* tolua_S)
{
    int argc = 0;
    tagTimeInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagTimeInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagTimeInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagTimeInfo_setEnterTableTimer'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "tagTimeInfo:setEnterTableTimer");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagTimeInfo_setEnterTableTimer'", nullptr);
            return 0;
        }
        cobj->setEnterTableTimer(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagTimeInfo:setEnterTableTimer",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagTimeInfo_setEnterTableTimer'.",&tolua_err);
#endif

    return 0;
}
static int lua_cocos2dx_platform_tagTimeInfo_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (tagTimeInfo)");
    return 0;
}

int lua_register_cocos2dx_platform_tagTimeInfo(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"tagTimeInfo");
    tolua_cclass(tolua_S,"tagTimeInfo","tagTimeInfo","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"tagTimeInfo");
        tolua_function(tolua_S,"getStartGameTimer",lua_cocos2dx_platform_tagTimeInfo_getStartGameTimer);
        tolua_function(tolua_S,"setEndGameTimer",lua_cocos2dx_platform_tagTimeInfo_setEndGameTimer);
        tolua_function(tolua_S,"setLeaveTableTimer",lua_cocos2dx_platform_tagTimeInfo_setLeaveTableTimer);
        tolua_function(tolua_S,"setStartGameTimer",lua_cocos2dx_platform_tagTimeInfo_setStartGameTimer);
        tolua_function(tolua_S,"getEndGameTimer",lua_cocos2dx_platform_tagTimeInfo_getEndGameTimer);
        tolua_function(tolua_S,"getLeaveTableTimer",lua_cocos2dx_platform_tagTimeInfo_getLeaveTableTimer);
        tolua_function(tolua_S,"getEnterTableTimer",lua_cocos2dx_platform_tagTimeInfo_getEnterTableTimer);
        tolua_function(tolua_S,"setEnterTableTimer",lua_cocos2dx_platform_tagTimeInfo_setEnterTableTimer);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(tagTimeInfo).name();
    g_luaType[typeName] = "tagTimeInfo";
    g_typeCast["tagTimeInfo"] = "tagTimeInfo";
    return 1;
}

int lua_cocos2dx_platform_tagUserInfo_setFleeCount(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInfo_setFleeCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "tagUserInfo:setFleeCount");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInfo_setFleeCount'", nullptr);
            return 0;
        }
        cobj->setFleeCount(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInfo:setFleeCount",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInfo_setFleeCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInfo_setUserID(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInfo_setUserID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "tagUserInfo:setUserID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInfo_setUserID'", nullptr);
            return 0;
        }
        cobj->setUserID(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInfo:setUserID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInfo_setUserID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInfo_setMasterOrder(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInfo_setMasterOrder'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        uint16_t arg0;

        ok &= luaval_to_uint16(tolua_S, 2,&arg0, "tagUserInfo:setMasterOrder");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInfo_setMasterOrder'", nullptr);
            return 0;
        }
        cobj->setMasterOrder(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInfo:setMasterOrder",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInfo_setMasterOrder'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInfo_setLoveLiness(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInfo_setLoveLiness'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "tagUserInfo:setLoveLiness");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInfo_setLoveLiness'", nullptr);
            return 0;
        }
        cobj->setLoveLiness(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInfo:setLoveLiness",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInfo_setLoveLiness'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInfo_setIsAndroid(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInfo_setIsAndroid'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "tagUserInfo:setIsAndroid");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInfo_setIsAndroid'", nullptr);
            return 0;
        }
        cobj->setIsAndroid(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInfo:setIsAndroid",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInfo_setIsAndroid'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInfo_getScore(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInfo_getScore'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInfo_getScore'", nullptr);
            return 0;
        }
        long long ret = cobj->getScore();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInfo:getScore",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInfo_getScore'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInfo_setRechargeScore(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInfo_setRechargeScore'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        long long arg0;

        ok &= luaval_to_long_long(tolua_S, 2,&arg0, "tagUserInfo:setRechargeScore");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInfo_setRechargeScore'", nullptr);
            return 0;
        }
        cobj->setRechargeScore(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInfo:setRechargeScore",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInfo_setRechargeScore'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInfo_getExperience(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInfo_getExperience'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInfo_getExperience'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getExperience();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInfo:getExperience",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInfo_getExperience'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInfo_getWinCount(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInfo_getWinCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInfo_getWinCount'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getWinCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInfo:getWinCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInfo_getWinCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInfo_getChairID(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInfo_getChairID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInfo_getChairID'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->getChairID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInfo:getChairID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInfo_getChairID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInfo_getFaceID(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInfo_getFaceID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInfo_getFaceID'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->getFaceID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInfo:getFaceID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInfo_getFaceID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInfo_setChairID(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInfo_setChairID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagUserInfo:setChairID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInfo_setChairID'", nullptr);
            return 0;
        }
        cobj->setChairID(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInfo:setChairID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInfo_setChairID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInfo_getTimerInfo(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInfo_getTimerInfo'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInfo_getTimerInfo'", nullptr);
            return 0;
        }
        tagTimeInfo* ret = cobj->getTimerInfo();
        object_to_luaval<tagTimeInfo>(tolua_S, "tagTimeInfo",(tagTimeInfo*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInfo:getTimerInfo",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInfo_getTimerInfo'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInfo_setProfileUrl(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInfo_setProfileUrl'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        int arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "tagUserInfo:setProfileUrl"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "tagUserInfo:setProfileUrl");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInfo_setProfileUrl'", nullptr);
            return 0;
        }
        cobj->setProfileUrl(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInfo:setProfileUrl",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInfo_setProfileUrl'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInfo_getMasterOrder(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInfo_getMasterOrder'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInfo_getMasterOrder'", nullptr);
            return 0;
        }
        uint16_t ret = cobj->getMasterOrder();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInfo:getMasterOrder",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInfo_getMasterOrder'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInfo_setTransOutScore(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInfo_setTransOutScore'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        long long arg0;

        ok &= luaval_to_long_long(tolua_S, 2,&arg0, "tagUserInfo:setTransOutScore");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInfo_setTransOutScore'", nullptr);
            return 0;
        }
        cobj->setTransOutScore(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInfo:setTransOutScore",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInfo_setTransOutScore'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInfo_getInsure(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInfo_getInsure'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInfo_getInsure'", nullptr);
            return 0;
        }
        long long ret = cobj->getInsure();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInfo:getInsure",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInfo_getInsure'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInfo_getMemberOrder(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInfo_getMemberOrder'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInfo_getMemberOrder'", nullptr);
            return 0;
        }
        uint16_t ret = cobj->getMemberOrder();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInfo:getMemberOrder",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInfo_getMemberOrder'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInfo_setScore(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInfo_setScore'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        long long arg0;

        ok &= luaval_to_long_long(tolua_S, 2,&arg0, "tagUserInfo:setScore");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInfo_setScore'", nullptr);
            return 0;
        }
        cobj->setScore(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInfo:setScore",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInfo_setScore'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInfo_setClientAddr(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInfo_setClientAddr'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "tagUserInfo:setClientAddr");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInfo_setClientAddr'", nullptr);
            return 0;
        }
        cobj->setClientAddr(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInfo:setClientAddr",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInfo_setClientAddr'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInfo_setMemberOrder(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInfo_setMemberOrder'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        uint16_t arg0;

        ok &= luaval_to_uint16(tolua_S, 2,&arg0, "tagUserInfo:setMemberOrder");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInfo_setMemberOrder'", nullptr);
            return 0;
        }
        cobj->setMemberOrder(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInfo:setMemberOrder",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInfo_setMemberOrder'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInfo_getLastTableID(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInfo_getLastTableID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInfo_getLastTableID'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->getLastTableID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInfo:getLastTableID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInfo_getLastTableID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInfo_setUnderWrite(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInfo_setUnderWrite'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        int arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "tagUserInfo:setUnderWrite"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "tagUserInfo:setUnderWrite");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInfo_setUnderWrite'", nullptr);
            return 0;
        }
        cobj->setUnderWrite(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInfo:setUnderWrite",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInfo_setUnderWrite'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInfo_setTransInScore(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInfo_setTransInScore'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        long long arg0;

        ok &= luaval_to_long_long(tolua_S, 2,&arg0, "tagUserInfo:setTransInScore");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInfo_setTransInScore'", nullptr);
            return 0;
        }
        cobj->setTransInScore(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInfo:setTransInScore",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInfo_setTransInScore'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInfo_setIngot(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInfo_setIngot'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        long long arg0;

        ok &= luaval_to_long_long(tolua_S, 2,&arg0, "tagUserInfo:setIngot");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInfo_setIngot'", nullptr);
            return 0;
        }
        cobj->setIngot(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInfo:setIngot",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInfo_setIngot'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInfo_setMachineID(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInfo_setMachineID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        int arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "tagUserInfo:setMachineID"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "tagUserInfo:setMachineID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInfo_setMachineID'", nullptr);
            return 0;
        }
        cobj->setMachineID(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInfo:setMachineID",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInfo_setMachineID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInfo_getTransOutScore(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInfo_getTransOutScore'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInfo_getTransOutScore'", nullptr);
            return 0;
        }
        long long ret = cobj->getTransOutScore();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInfo:getTransOutScore",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInfo_getTransOutScore'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInfo_getMachineID(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInfo_getMachineID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInfo_getMachineID'", nullptr);
            return 0;
        }
        const char* ret = cobj->getMachineID();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInfo:getMachineID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInfo_getMachineID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInfo_getProfileUrl(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInfo_getProfileUrl'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInfo_getProfileUrl'", nullptr);
            return 0;
        }
        const char* ret = cobj->getProfileUrl();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInfo:getProfileUrl",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInfo_getProfileUrl'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInfo_setWinCount(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInfo_setWinCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "tagUserInfo:setWinCount");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInfo_setWinCount'", nullptr);
            return 0;
        }
        cobj->setWinCount(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInfo:setWinCount",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInfo_setWinCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInfo_getNickName(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInfo_getNickName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInfo_getNickName'", nullptr);
            return 0;
        }
        const char* ret = cobj->getNickName();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInfo:getNickName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInfo_getNickName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInfo_setTableID(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInfo_setTableID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagUserInfo:setTableID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInfo_setTableID'", nullptr);
            return 0;
        }
        cobj->setTableID(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInfo:setTableID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInfo_setTableID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInfo_getTransInScore(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInfo_getTransInScore'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInfo_getTransInScore'", nullptr);
            return 0;
        }
        long long ret = cobj->getTransInScore();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInfo:getTransInScore",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInfo_getTransInScore'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInfo_getUserStatus(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInfo_getUserStatus'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInfo_getUserStatus'", nullptr);
            return 0;
        }
        uint16_t ret = cobj->getUserStatus();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInfo:getUserStatus",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInfo_getUserStatus'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInfo_getFleeCount(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInfo_getFleeCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInfo_getFleeCount'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getFleeCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInfo:getFleeCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInfo_getFleeCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInfo_getGameID(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInfo_getGameID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInfo_getGameID'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getGameID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInfo:getGameID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInfo_getGameID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInfo_setLostCount(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInfo_setLostCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "tagUserInfo:setLostCount");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInfo_setLostCount'", nullptr);
            return 0;
        }
        cobj->setLostCount(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInfo:setLostCount",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInfo_setLostCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInfo_getCustomID(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInfo_getCustomID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInfo_getCustomID'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getCustomID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInfo:getCustomID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInfo_getCustomID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInfo_setGender(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInfo_setGender'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        uint16_t arg0;

        ok &= luaval_to_uint16(tolua_S, 2,&arg0, "tagUserInfo:setGender");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInfo_setGender'", nullptr);
            return 0;
        }
        cobj->setGender(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInfo:setGender",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInfo_setGender'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInfo_setExperience(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInfo_setExperience'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "tagUserInfo:setExperience");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInfo_setExperience'", nullptr);
            return 0;
        }
        cobj->setExperience(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInfo:setExperience",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInfo_setExperience'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInfo_setUserStatus(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInfo_setUserStatus'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        uint16_t arg0;

        ok &= luaval_to_uint16(tolua_S, 2,&arg0, "tagUserInfo:setUserStatus");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInfo_setUserStatus'", nullptr);
            return 0;
        }
        cobj->setUserStatus(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInfo:setUserStatus",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInfo_setUserStatus'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInfo_setGrade(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInfo_setGrade'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        long long arg0;

        ok &= luaval_to_long_long(tolua_S, 2,&arg0, "tagUserInfo:setGrade");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInfo_setGrade'", nullptr);
            return 0;
        }
        cobj->setGrade(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInfo:setGrade",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInfo_setGrade'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInfo_setGameID(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInfo_setGameID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "tagUserInfo:setGameID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInfo_setGameID'", nullptr);
            return 0;
        }
        cobj->setGameID(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInfo:setGameID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInfo_setGameID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInfo_setInsure(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInfo_setInsure'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        long long arg0;

        ok &= luaval_to_long_long(tolua_S, 2,&arg0, "tagUserInfo:setInsure");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInfo_setInsure'", nullptr);
            return 0;
        }
        cobj->setInsure(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInfo:setInsure",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInfo_setInsure'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInfo_setGroupID(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInfo_setGroupID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "tagUserInfo:setGroupID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInfo_setGroupID'", nullptr);
            return 0;
        }
        cobj->setGroupID(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInfo:setGroupID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInfo_setGroupID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInfo_getGender(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInfo_getGender'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInfo_getGender'", nullptr);
            return 0;
        }
        uint16_t ret = cobj->getGender();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInfo:getGender",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInfo_getGender'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInfo_setGroupName(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInfo_setGroupName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        int arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "tagUserInfo:setGroupName"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "tagUserInfo:setGroupName");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInfo_setGroupName'", nullptr);
            return 0;
        }
        cobj->setGroupName(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInfo:setGroupName",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInfo_setGroupName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInfo_getIngot(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInfo_getIngot'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInfo_getIngot'", nullptr);
            return 0;
        }
        long long ret = cobj->getIngot();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInfo:getIngot",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInfo_getIngot'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInfo_getGroupName(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInfo_getGroupName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInfo_getGroupName'", nullptr);
            return 0;
        }
        const char* ret = cobj->getGroupName();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInfo:getGroupName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInfo_getGroupName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInfo_getLoveLiness(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInfo_getLoveLiness'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInfo_getLoveLiness'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getLoveLiness();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInfo:getLoveLiness",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInfo_getLoveLiness'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInfo_setNickName(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInfo_setNickName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        int arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "tagUserInfo:setNickName"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "tagUserInfo:setNickName");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInfo_setNickName'", nullptr);
            return 0;
        }
        cobj->setNickName(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInfo:setNickName",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInfo_setNickName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInfo_getTableID(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInfo_getTableID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInfo_getTableID'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->getTableID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInfo:getTableID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInfo_getTableID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInfo_getLostCount(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInfo_getLostCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInfo_getLostCount'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getLostCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInfo:getLostCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInfo_getLostCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInfo_getGrade(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInfo_getGrade'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInfo_getGrade'", nullptr);
            return 0;
        }
        long long ret = cobj->getGrade();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInfo:getGrade",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInfo_getGrade'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInfo_getUnderWrite(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInfo_getUnderWrite'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInfo_getUnderWrite'", nullptr);
            return 0;
        }
        const char* ret = cobj->getUnderWrite();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInfo:getUnderWrite",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInfo_getUnderWrite'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInfo_getRechargeScore(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInfo_getRechargeScore'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInfo_getRechargeScore'", nullptr);
            return 0;
        }
        long long ret = cobj->getRechargeScore();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInfo:getRechargeScore",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInfo_getRechargeScore'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInfo_getGroupID(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInfo_getGroupID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInfo_getGroupID'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getGroupID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInfo:getGroupID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInfo_getGroupID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInfo_getIsAndroid(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInfo_getIsAndroid'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInfo_getIsAndroid'", nullptr);
            return 0;
        }
        bool ret = cobj->getIsAndroid();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInfo:getIsAndroid",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInfo_getIsAndroid'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInfo_getUserID(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInfo_getUserID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInfo_getUserID'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getUserID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInfo:getUserID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInfo_getUserID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInfo_getClientAddr(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInfo_getClientAddr'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInfo_getClientAddr'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getClientAddr();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInfo:getClientAddr",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInfo_getClientAddr'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInfo_getDrawCount(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInfo_getDrawCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInfo_getDrawCount'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getDrawCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInfo:getDrawCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInfo_getDrawCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInfo_setFaceID(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInfo_setFaceID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagUserInfo:setFaceID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInfo_setFaceID'", nullptr);
            return 0;
        }
        cobj->setFaceID(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInfo:setFaceID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInfo_setFaceID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInfo_setCustomID(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInfo_setCustomID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "tagUserInfo:setCustomID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInfo_setCustomID'", nullptr);
            return 0;
        }
        cobj->setCustomID(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInfo:setCustomID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInfo_setCustomID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInfo_setLastTableID(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInfo_setLastTableID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagUserInfo:setLastTableID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInfo_setLastTableID'", nullptr);
            return 0;
        }
        cobj->setLastTableID(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInfo:setLastTableID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInfo_setLastTableID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInfo_setDrawCount(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInfo_setDrawCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "tagUserInfo:setDrawCount");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInfo_setDrawCount'", nullptr);
            return 0;
        }
        cobj->setDrawCount(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInfo:setDrawCount",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInfo_setDrawCount'.",&tolua_err);
#endif

    return 0;
}
static int lua_cocos2dx_platform_tagUserInfo_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (tagUserInfo)");
    return 0;
}

int lua_register_cocos2dx_platform_tagUserInfo(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"tagUserInfo");
    tolua_cclass(tolua_S,"tagUserInfo","tagUserInfo","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"tagUserInfo");
        tolua_function(tolua_S,"setFleeCount",lua_cocos2dx_platform_tagUserInfo_setFleeCount);
        tolua_function(tolua_S,"setUserID",lua_cocos2dx_platform_tagUserInfo_setUserID);
        tolua_function(tolua_S,"setMasterOrder",lua_cocos2dx_platform_tagUserInfo_setMasterOrder);
        tolua_function(tolua_S,"setLoveLiness",lua_cocos2dx_platform_tagUserInfo_setLoveLiness);
        tolua_function(tolua_S,"setIsAndroid",lua_cocos2dx_platform_tagUserInfo_setIsAndroid);
        tolua_function(tolua_S,"getScore",lua_cocos2dx_platform_tagUserInfo_getScore);
        tolua_function(tolua_S,"setRechargeScore",lua_cocos2dx_platform_tagUserInfo_setRechargeScore);
        tolua_function(tolua_S,"getExperience",lua_cocos2dx_platform_tagUserInfo_getExperience);
        tolua_function(tolua_S,"getWinCount",lua_cocos2dx_platform_tagUserInfo_getWinCount);
        tolua_function(tolua_S,"getChairID",lua_cocos2dx_platform_tagUserInfo_getChairID);
        tolua_function(tolua_S,"getFaceID",lua_cocos2dx_platform_tagUserInfo_getFaceID);
        tolua_function(tolua_S,"setChairID",lua_cocos2dx_platform_tagUserInfo_setChairID);
        tolua_function(tolua_S,"getTimerInfo",lua_cocos2dx_platform_tagUserInfo_getTimerInfo);
        tolua_function(tolua_S,"setProfileUrl",lua_cocos2dx_platform_tagUserInfo_setProfileUrl);
        tolua_function(tolua_S,"getMasterOrder",lua_cocos2dx_platform_tagUserInfo_getMasterOrder);
        tolua_function(tolua_S,"setTransOutScore",lua_cocos2dx_platform_tagUserInfo_setTransOutScore);
        tolua_function(tolua_S,"getInsure",lua_cocos2dx_platform_tagUserInfo_getInsure);
        tolua_function(tolua_S,"getMemberOrder",lua_cocos2dx_platform_tagUserInfo_getMemberOrder);
        tolua_function(tolua_S,"setScore",lua_cocos2dx_platform_tagUserInfo_setScore);
        tolua_function(tolua_S,"setClientAddr",lua_cocos2dx_platform_tagUserInfo_setClientAddr);
        tolua_function(tolua_S,"setMemberOrder",lua_cocos2dx_platform_tagUserInfo_setMemberOrder);
        tolua_function(tolua_S,"getLastTableID",lua_cocos2dx_platform_tagUserInfo_getLastTableID);
        tolua_function(tolua_S,"setUnderWrite",lua_cocos2dx_platform_tagUserInfo_setUnderWrite);
        tolua_function(tolua_S,"setTransInScore",lua_cocos2dx_platform_tagUserInfo_setTransInScore);
        tolua_function(tolua_S,"setIngot",lua_cocos2dx_platform_tagUserInfo_setIngot);
        tolua_function(tolua_S,"setMachineID",lua_cocos2dx_platform_tagUserInfo_setMachineID);
        tolua_function(tolua_S,"getTransOutScore",lua_cocos2dx_platform_tagUserInfo_getTransOutScore);
        tolua_function(tolua_S,"getMachineID",lua_cocos2dx_platform_tagUserInfo_getMachineID);
        tolua_function(tolua_S,"getProfileUrl",lua_cocos2dx_platform_tagUserInfo_getProfileUrl);
        tolua_function(tolua_S,"setWinCount",lua_cocos2dx_platform_tagUserInfo_setWinCount);
        tolua_function(tolua_S,"getNickName",lua_cocos2dx_platform_tagUserInfo_getNickName);
        tolua_function(tolua_S,"setTableID",lua_cocos2dx_platform_tagUserInfo_setTableID);
        tolua_function(tolua_S,"getTransInScore",lua_cocos2dx_platform_tagUserInfo_getTransInScore);
        tolua_function(tolua_S,"getUserStatus",lua_cocos2dx_platform_tagUserInfo_getUserStatus);
        tolua_function(tolua_S,"getFleeCount",lua_cocos2dx_platform_tagUserInfo_getFleeCount);
        tolua_function(tolua_S,"getGameID",lua_cocos2dx_platform_tagUserInfo_getGameID);
        tolua_function(tolua_S,"setLostCount",lua_cocos2dx_platform_tagUserInfo_setLostCount);
        tolua_function(tolua_S,"getCustomID",lua_cocos2dx_platform_tagUserInfo_getCustomID);
        tolua_function(tolua_S,"setGender",lua_cocos2dx_platform_tagUserInfo_setGender);
        tolua_function(tolua_S,"setExperience",lua_cocos2dx_platform_tagUserInfo_setExperience);
        tolua_function(tolua_S,"setUserStatus",lua_cocos2dx_platform_tagUserInfo_setUserStatus);
        tolua_function(tolua_S,"setGrade",lua_cocos2dx_platform_tagUserInfo_setGrade);
        tolua_function(tolua_S,"setGameID",lua_cocos2dx_platform_tagUserInfo_setGameID);
        tolua_function(tolua_S,"setInsure",lua_cocos2dx_platform_tagUserInfo_setInsure);
        tolua_function(tolua_S,"setGroupID",lua_cocos2dx_platform_tagUserInfo_setGroupID);
        tolua_function(tolua_S,"getGender",lua_cocos2dx_platform_tagUserInfo_getGender);
        tolua_function(tolua_S,"setGroupName",lua_cocos2dx_platform_tagUserInfo_setGroupName);
        tolua_function(tolua_S,"getIngot",lua_cocos2dx_platform_tagUserInfo_getIngot);
        tolua_function(tolua_S,"getGroupName",lua_cocos2dx_platform_tagUserInfo_getGroupName);
        tolua_function(tolua_S,"getLoveLiness",lua_cocos2dx_platform_tagUserInfo_getLoveLiness);
        tolua_function(tolua_S,"setNickName",lua_cocos2dx_platform_tagUserInfo_setNickName);
        tolua_function(tolua_S,"getTableID",lua_cocos2dx_platform_tagUserInfo_getTableID);
        tolua_function(tolua_S,"getLostCount",lua_cocos2dx_platform_tagUserInfo_getLostCount);
        tolua_function(tolua_S,"getGrade",lua_cocos2dx_platform_tagUserInfo_getGrade);
        tolua_function(tolua_S,"getUnderWrite",lua_cocos2dx_platform_tagUserInfo_getUnderWrite);
        tolua_function(tolua_S,"getRechargeScore",lua_cocos2dx_platform_tagUserInfo_getRechargeScore);
        tolua_function(tolua_S,"getGroupID",lua_cocos2dx_platform_tagUserInfo_getGroupID);
        tolua_function(tolua_S,"getIsAndroid",lua_cocos2dx_platform_tagUserInfo_getIsAndroid);
        tolua_function(tolua_S,"getUserID",lua_cocos2dx_platform_tagUserInfo_getUserID);
        tolua_function(tolua_S,"getClientAddr",lua_cocos2dx_platform_tagUserInfo_getClientAddr);
        tolua_function(tolua_S,"getDrawCount",lua_cocos2dx_platform_tagUserInfo_getDrawCount);
        tolua_function(tolua_S,"setFaceID",lua_cocos2dx_platform_tagUserInfo_setFaceID);
        tolua_function(tolua_S,"setCustomID",lua_cocos2dx_platform_tagUserInfo_setCustomID);
        tolua_function(tolua_S,"setLastTableID",lua_cocos2dx_platform_tagUserInfo_setLastTableID);
        tolua_function(tolua_S,"setDrawCount",lua_cocos2dx_platform_tagUserInfo_setDrawCount);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(tagUserInfo).name();
    g_luaType[typeName] = "tagUserInfo";
    g_typeCast["tagUserInfo"] = "tagUserInfo";
    return 1;
}

int lua_cocos2dx_platform_tagCustomFaceInfo_setDataSize(lua_State* tolua_S)
{
    int argc = 0;
    tagCustomFaceInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagCustomFaceInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagCustomFaceInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagCustomFaceInfo_setDataSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "tagCustomFaceInfo:setDataSize");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagCustomFaceInfo_setDataSize'", nullptr);
            return 0;
        }
        cobj->setDataSize(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagCustomFaceInfo:setDataSize",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagCustomFaceInfo_setDataSize'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagCustomFaceInfo_setCustomFace(lua_State* tolua_S)
{
    int argc = 0;
    tagCustomFaceInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagCustomFaceInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagCustomFaceInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagCustomFaceInfo_setCustomFace'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const unsigned int* arg0;
        int arg1;

        #pragma warning NO CONVERSION TO NATIVE FOR unsigned int*
		ok = false;

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "tagCustomFaceInfo:setCustomFace");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagCustomFaceInfo_setCustomFace'", nullptr);
            return 0;
        }
        cobj->setCustomFace(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagCustomFaceInfo:setCustomFace",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagCustomFaceInfo_setCustomFace'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagCustomFaceInfo_getDataSize(lua_State* tolua_S)
{
    int argc = 0;
    tagCustomFaceInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagCustomFaceInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagCustomFaceInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagCustomFaceInfo_getDataSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagCustomFaceInfo_getDataSize'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getDataSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagCustomFaceInfo:getDataSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagCustomFaceInfo_getDataSize'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagCustomFaceInfo_getCustomFace(lua_State* tolua_S)
{
    int argc = 0;
    tagCustomFaceInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagCustomFaceInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagCustomFaceInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagCustomFaceInfo_getCustomFace'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagCustomFaceInfo_getCustomFace'", nullptr);
            return 0;
        }
        const unsigned int* ret = cobj->getCustomFace();
        #pragma warning NO CONVERSION FROM NATIVE FOR unsigned int*;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagCustomFaceInfo:getCustomFace",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagCustomFaceInfo_getCustomFace'.",&tolua_err);
#endif

    return 0;
}
static int lua_cocos2dx_platform_tagCustomFaceInfo_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (tagCustomFaceInfo)");
    return 0;
}

int lua_register_cocos2dx_platform_tagCustomFaceInfo(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"tagCustomFaceInfo");
    tolua_cclass(tolua_S,"tagCustomFaceInfo","tagCustomFaceInfo","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"tagCustomFaceInfo");
        tolua_function(tolua_S,"setDataSize",lua_cocos2dx_platform_tagCustomFaceInfo_setDataSize);
        tolua_function(tolua_S,"setCustomFace",lua_cocos2dx_platform_tagCustomFaceInfo_setCustomFace);
        tolua_function(tolua_S,"getDataSize",lua_cocos2dx_platform_tagCustomFaceInfo_getDataSize);
        tolua_function(tolua_S,"getCustomFace",lua_cocos2dx_platform_tagCustomFaceInfo_getCustomFace);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(tagCustomFaceInfo).name();
    g_luaType[typeName] = "tagCustomFaceInfo";
    g_typeCast["tagCustomFaceInfo"] = "tagCustomFaceInfo";
    return 1;
}

int lua_cocos2dx_platform_tagMatchInfo_getGameCount(lua_State* tolua_S)
{
    int argc = 0;
    tagMatchInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagMatchInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagMatchInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagMatchInfo_getGameCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagMatchInfo_getGameCount'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->getGameCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagMatchInfo:getGameCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagMatchInfo_getGameCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagMatchInfo_getTitle(lua_State* tolua_S)
{
    int argc = 0;
    tagMatchInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagMatchInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagMatchInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagMatchInfo_getTitle'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "tagMatchInfo:getTitle");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagMatchInfo_getTitle'", nullptr);
            return 0;
        }
        char* ret = cobj->getTitle(arg0);
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagMatchInfo:getTitle",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagMatchInfo_getTitle'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagMatchInfo_setGameCount(lua_State* tolua_S)
{
    int argc = 0;
    tagMatchInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagMatchInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagMatchInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagMatchInfo_setGameCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagMatchInfo:setGameCount");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagMatchInfo_setGameCount'", nullptr);
            return 0;
        }
        cobj->setGameCount(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagMatchInfo:setGameCount",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagMatchInfo_setGameCount'.",&tolua_err);
#endif

    return 0;
}
static int lua_cocos2dx_platform_tagMatchInfo_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (tagMatchInfo)");
    return 0;
}

int lua_register_cocos2dx_platform_tagMatchInfo(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"tagMatchInfo");
    tolua_cclass(tolua_S,"tagMatchInfo","tagMatchInfo","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"tagMatchInfo");
        tolua_function(tolua_S,"getGameCount",lua_cocos2dx_platform_tagMatchInfo_getGameCount);
        tolua_function(tolua_S,"getTitle",lua_cocos2dx_platform_tagMatchInfo_getTitle);
        tolua_function(tolua_S,"setGameCount",lua_cocos2dx_platform_tagMatchInfo_setGameCount);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(tagMatchInfo).name();
    g_luaType[typeName] = "tagMatchInfo";
    g_typeCast["tagMatchInfo"] = "tagMatchInfo";
    return 1;
}

int lua_cocos2dx_platform_tagMatchWaitTip_setMatchName(lua_State* tolua_S)
{
    int argc = 0;
    tagMatchWaitTip* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagMatchWaitTip",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagMatchWaitTip*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagMatchWaitTip_setMatchName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        int arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "tagMatchWaitTip:setMatchName"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "tagMatchWaitTip:setMatchName");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagMatchWaitTip_setMatchName'", nullptr);
            return 0;
        }
        cobj->setMatchName(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagMatchWaitTip:setMatchName",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagMatchWaitTip_setMatchName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagMatchWaitTip_getCurTableRank(lua_State* tolua_S)
{
    int argc = 0;
    tagMatchWaitTip* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagMatchWaitTip",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagMatchWaitTip*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagMatchWaitTip_getCurTableRank'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagMatchWaitTip_getCurTableRank'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->getCurTableRank();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagMatchWaitTip:getCurTableRank",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagMatchWaitTip_getCurTableRank'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagMatchWaitTip_setPlayingTable(lua_State* tolua_S)
{
    int argc = 0;
    tagMatchWaitTip* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagMatchWaitTip",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagMatchWaitTip*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagMatchWaitTip_setPlayingTable'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagMatchWaitTip:setPlayingTable");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagMatchWaitTip_setPlayingTable'", nullptr);
            return 0;
        }
        cobj->setPlayingTable(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagMatchWaitTip:setPlayingTable",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagMatchWaitTip_setPlayingTable'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagMatchWaitTip_getScore(lua_State* tolua_S)
{
    int argc = 0;
    tagMatchWaitTip* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagMatchWaitTip",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagMatchWaitTip*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagMatchWaitTip_getScore'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagMatchWaitTip_getScore'", nullptr);
            return 0;
        }
        long long ret = cobj->getScore();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagMatchWaitTip:getScore",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagMatchWaitTip_getScore'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagMatchWaitTip_setRank(lua_State* tolua_S)
{
    int argc = 0;
    tagMatchWaitTip* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagMatchWaitTip",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagMatchWaitTip*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagMatchWaitTip_setRank'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagMatchWaitTip:setRank");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagMatchWaitTip_setRank'", nullptr);
            return 0;
        }
        cobj->setRank(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagMatchWaitTip:setRank",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagMatchWaitTip_setRank'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagMatchWaitTip_getMatchName(lua_State* tolua_S)
{
    int argc = 0;
    tagMatchWaitTip* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagMatchWaitTip",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagMatchWaitTip*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagMatchWaitTip_getMatchName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagMatchWaitTip_getMatchName'", nullptr);
            return 0;
        }
        const char* ret = cobj->getMatchName();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagMatchWaitTip:getMatchName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagMatchWaitTip_getMatchName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagMatchWaitTip_getRank(lua_State* tolua_S)
{
    int argc = 0;
    tagMatchWaitTip* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagMatchWaitTip",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagMatchWaitTip*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagMatchWaitTip_getRank'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagMatchWaitTip_getRank'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->getRank();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagMatchWaitTip:getRank",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagMatchWaitTip_getRank'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagMatchWaitTip_getUserCount(lua_State* tolua_S)
{
    int argc = 0;
    tagMatchWaitTip* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagMatchWaitTip",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagMatchWaitTip*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagMatchWaitTip_getUserCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagMatchWaitTip_getUserCount'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->getUserCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagMatchWaitTip:getUserCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagMatchWaitTip_getUserCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagMatchWaitTip_setUserCount(lua_State* tolua_S)
{
    int argc = 0;
    tagMatchWaitTip* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagMatchWaitTip",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagMatchWaitTip*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagMatchWaitTip_setUserCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagMatchWaitTip:setUserCount");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagMatchWaitTip_setUserCount'", nullptr);
            return 0;
        }
        cobj->setUserCount(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagMatchWaitTip:setUserCount",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagMatchWaitTip_setUserCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagMatchWaitTip_getPlayingTable(lua_State* tolua_S)
{
    int argc = 0;
    tagMatchWaitTip* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagMatchWaitTip",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagMatchWaitTip*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagMatchWaitTip_getPlayingTable'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagMatchWaitTip_getPlayingTable'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->getPlayingTable();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagMatchWaitTip:getPlayingTable",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagMatchWaitTip_getPlayingTable'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagMatchWaitTip_setScore(lua_State* tolua_S)
{
    int argc = 0;
    tagMatchWaitTip* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagMatchWaitTip",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagMatchWaitTip*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagMatchWaitTip_setScore'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        long long arg0;

        ok &= luaval_to_long_long(tolua_S, 2,&arg0, "tagMatchWaitTip:setScore");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagMatchWaitTip_setScore'", nullptr);
            return 0;
        }
        cobj->setScore(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagMatchWaitTip:setScore",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagMatchWaitTip_setScore'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagMatchWaitTip_setCurTableRank(lua_State* tolua_S)
{
    int argc = 0;
    tagMatchWaitTip* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagMatchWaitTip",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagMatchWaitTip*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagMatchWaitTip_setCurTableRank'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagMatchWaitTip:setCurTableRank");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagMatchWaitTip_setCurTableRank'", nullptr);
            return 0;
        }
        cobj->setCurTableRank(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagMatchWaitTip:setCurTableRank",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagMatchWaitTip_setCurTableRank'.",&tolua_err);
#endif

    return 0;
}
static int lua_cocos2dx_platform_tagMatchWaitTip_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (tagMatchWaitTip)");
    return 0;
}

int lua_register_cocos2dx_platform_tagMatchWaitTip(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"tagMatchWaitTip");
    tolua_cclass(tolua_S,"tagMatchWaitTip","tagMatchWaitTip","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"tagMatchWaitTip");
        tolua_function(tolua_S,"setMatchName",lua_cocos2dx_platform_tagMatchWaitTip_setMatchName);
        tolua_function(tolua_S,"getCurTableRank",lua_cocos2dx_platform_tagMatchWaitTip_getCurTableRank);
        tolua_function(tolua_S,"setPlayingTable",lua_cocos2dx_platform_tagMatchWaitTip_setPlayingTable);
        tolua_function(tolua_S,"getScore",lua_cocos2dx_platform_tagMatchWaitTip_getScore);
        tolua_function(tolua_S,"setRank",lua_cocos2dx_platform_tagMatchWaitTip_setRank);
        tolua_function(tolua_S,"getMatchName",lua_cocos2dx_platform_tagMatchWaitTip_getMatchName);
        tolua_function(tolua_S,"getRank",lua_cocos2dx_platform_tagMatchWaitTip_getRank);
        tolua_function(tolua_S,"getUserCount",lua_cocos2dx_platform_tagMatchWaitTip_getUserCount);
        tolua_function(tolua_S,"setUserCount",lua_cocos2dx_platform_tagMatchWaitTip_setUserCount);
        tolua_function(tolua_S,"getPlayingTable",lua_cocos2dx_platform_tagMatchWaitTip_getPlayingTable);
        tolua_function(tolua_S,"setScore",lua_cocos2dx_platform_tagMatchWaitTip_setScore);
        tolua_function(tolua_S,"setCurTableRank",lua_cocos2dx_platform_tagMatchWaitTip_setCurTableRank);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(tagMatchWaitTip).name();
    g_luaType[typeName] = "tagMatchWaitTip";
    g_typeCast["tagMatchWaitTip"] = "tagMatchWaitTip";
    return 1;
}

int lua_cocos2dx_platform_tagMatchResult_setMatchName(lua_State* tolua_S)
{
    int argc = 0;
    tagMatchResult* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagMatchResult",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagMatchResult*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagMatchResult_setMatchName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        int arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "tagMatchResult:setMatchName"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "tagMatchResult:setMatchName");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagMatchResult_setMatchName'", nullptr);
            return 0;
        }
        cobj->setMatchName(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagMatchResult:setMatchName",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagMatchResult_setMatchName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagMatchResult_setUserName(lua_State* tolua_S)
{
    int argc = 0;
    tagMatchResult* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagMatchResult",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagMatchResult*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagMatchResult_setUserName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        int arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "tagMatchResult:setUserName"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "tagMatchResult:setUserName");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagMatchResult_setUserName'", nullptr);
            return 0;
        }
        cobj->setUserName(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagMatchResult:setUserName",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagMatchResult_setUserName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagMatchResult_setGold(lua_State* tolua_S)
{
    int argc = 0;
    tagMatchResult* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagMatchResult",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagMatchResult*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagMatchResult_setGold'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        long long arg0;

        ok &= luaval_to_long_long(tolua_S, 2,&arg0, "tagMatchResult:setGold");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagMatchResult_setGold'", nullptr);
            return 0;
        }
        cobj->setGold(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagMatchResult:setGold",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagMatchResult_setGold'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagMatchResult_setIngot(lua_State* tolua_S)
{
    int argc = 0;
    tagMatchResult* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagMatchResult",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagMatchResult*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagMatchResult_setIngot'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "tagMatchResult:setIngot");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagMatchResult_setIngot'", nullptr);
            return 0;
        }
        cobj->setIngot(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagMatchResult:setIngot",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagMatchResult_setIngot'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagMatchResult_setGameType(lua_State* tolua_S)
{
    int argc = 0;
    tagMatchResult* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagMatchResult",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagMatchResult*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagMatchResult_setGameType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagMatchResult:setGameType");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagMatchResult_setGameType'", nullptr);
            return 0;
        }
        cobj->setGameType(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagMatchResult:setGameType",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagMatchResult_setGameType'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagMatchResult_getMatchName(lua_State* tolua_S)
{
    int argc = 0;
    tagMatchResult* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagMatchResult",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagMatchResult*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagMatchResult_getMatchName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagMatchResult_getMatchName'", nullptr);
            return 0;
        }
        const char* ret = cobj->getMatchName();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagMatchResult:getMatchName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagMatchResult_getMatchName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagMatchResult_getExperience(lua_State* tolua_S)
{
    int argc = 0;
    tagMatchResult* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagMatchResult",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagMatchResult*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagMatchResult_getExperience'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagMatchResult_getExperience'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getExperience();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagMatchResult:getExperience",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagMatchResult_getExperience'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagMatchResult_getGold(lua_State* tolua_S)
{
    int argc = 0;
    tagMatchResult* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagMatchResult",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagMatchResult*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagMatchResult_getGold'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagMatchResult_getGold'", nullptr);
            return 0;
        }
        long long ret = cobj->getGold();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagMatchResult:getGold",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagMatchResult_getGold'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagMatchResult_getUserRank(lua_State* tolua_S)
{
    int argc = 0;
    tagMatchResult* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagMatchResult",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagMatchResult*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagMatchResult_getUserRank'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagMatchResult_getUserRank'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->getUserRank();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagMatchResult:getUserRank",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagMatchResult_getUserRank'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagMatchResult_getIngot(lua_State* tolua_S)
{
    int argc = 0;
    tagMatchResult* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagMatchResult",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagMatchResult*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagMatchResult_getIngot'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagMatchResult_getIngot'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getIngot();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagMatchResult:getIngot",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagMatchResult_getIngot'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagMatchResult_setExperience(lua_State* tolua_S)
{
    int argc = 0;
    tagMatchResult* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagMatchResult",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagMatchResult*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagMatchResult_setExperience'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "tagMatchResult:setExperience");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagMatchResult_setExperience'", nullptr);
            return 0;
        }
        cobj->setExperience(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagMatchResult:setExperience",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagMatchResult_setExperience'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagMatchResult_setUserRank(lua_State* tolua_S)
{
    int argc = 0;
    tagMatchResult* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagMatchResult",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagMatchResult*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagMatchResult_setUserRank'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagMatchResult:setUserRank");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagMatchResult_setUserRank'", nullptr);
            return 0;
        }
        cobj->setUserRank(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagMatchResult:setUserRank",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagMatchResult_setUserRank'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagMatchResult_getGameType(lua_State* tolua_S)
{
    int argc = 0;
    tagMatchResult* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagMatchResult",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagMatchResult*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagMatchResult_getGameType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagMatchResult_getGameType'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->getGameType();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagMatchResult:getGameType",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagMatchResult_getGameType'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagMatchResult_setUserCount(lua_State* tolua_S)
{
    int argc = 0;
    tagMatchResult* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagMatchResult",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagMatchResult*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagMatchResult_setUserCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagMatchResult:setUserCount");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagMatchResult_setUserCount'", nullptr);
            return 0;
        }
        cobj->setUserCount(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagMatchResult:setUserCount",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagMatchResult_setUserCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagMatchResult_getUserCount(lua_State* tolua_S)
{
    int argc = 0;
    tagMatchResult* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagMatchResult",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagMatchResult*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagMatchResult_getUserCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagMatchResult_getUserCount'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->getUserCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagMatchResult:getUserCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagMatchResult_getUserCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagMatchResult_getUserName(lua_State* tolua_S)
{
    int argc = 0;
    tagMatchResult* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagMatchResult",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagMatchResult*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagMatchResult_getUserName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagMatchResult_getUserName'", nullptr);
            return 0;
        }
        const char* ret = cobj->getUserName();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagMatchResult:getUserName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagMatchResult_getUserName'.",&tolua_err);
#endif

    return 0;
}
static int lua_cocos2dx_platform_tagMatchResult_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (tagMatchResult)");
    return 0;
}

int lua_register_cocos2dx_platform_tagMatchResult(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"tagMatchResult");
    tolua_cclass(tolua_S,"tagMatchResult","tagMatchResult","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"tagMatchResult");
        tolua_function(tolua_S,"setMatchName",lua_cocos2dx_platform_tagMatchResult_setMatchName);
        tolua_function(tolua_S,"setUserName",lua_cocos2dx_platform_tagMatchResult_setUserName);
        tolua_function(tolua_S,"setGold",lua_cocos2dx_platform_tagMatchResult_setGold);
        tolua_function(tolua_S,"setIngot",lua_cocos2dx_platform_tagMatchResult_setIngot);
        tolua_function(tolua_S,"setGameType",lua_cocos2dx_platform_tagMatchResult_setGameType);
        tolua_function(tolua_S,"getMatchName",lua_cocos2dx_platform_tagMatchResult_getMatchName);
        tolua_function(tolua_S,"getExperience",lua_cocos2dx_platform_tagMatchResult_getExperience);
        tolua_function(tolua_S,"getGold",lua_cocos2dx_platform_tagMatchResult_getGold);
        tolua_function(tolua_S,"getUserRank",lua_cocos2dx_platform_tagMatchResult_getUserRank);
        tolua_function(tolua_S,"getIngot",lua_cocos2dx_platform_tagMatchResult_getIngot);
        tolua_function(tolua_S,"setExperience",lua_cocos2dx_platform_tagMatchResult_setExperience);
        tolua_function(tolua_S,"setUserRank",lua_cocos2dx_platform_tagMatchResult_setUserRank);
        tolua_function(tolua_S,"getGameType",lua_cocos2dx_platform_tagMatchResult_getGameType);
        tolua_function(tolua_S,"setUserCount",lua_cocos2dx_platform_tagMatchResult_setUserCount);
        tolua_function(tolua_S,"getUserCount",lua_cocos2dx_platform_tagMatchResult_getUserCount);
        tolua_function(tolua_S,"getUserName",lua_cocos2dx_platform_tagMatchResult_getUserName);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(tagMatchResult).name();
    g_luaType[typeName] = "tagMatchResult";
    g_typeCast["tagMatchResult"] = "tagMatchResult";
    return 1;
}

int lua_cocos2dx_platform_DF_GetGameVersion(lua_State* tolua_S)
{
    int argc = 0;
    DF* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"DF",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (DF*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_DF_GetGameVersion'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_DF_GetGameVersion'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->GetGameVersion();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "DF:GetGameVersion",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_DF_GetGameVersion'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_DF_GetPlazzKindID(lua_State* tolua_S)
{
    int argc = 0;
    DF* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"DF",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (DF*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_DF_GetPlazzKindID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_DF_GetPlazzKindID'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->GetPlazzKindID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "DF:GetPlazzKindID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_DF_GetPlazzKindID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_DF_GetPlazaStringVersion(lua_State* tolua_S)
{
    int argc = 0;
    DF* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"DF",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (DF*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_DF_GetPlazaStringVersion'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_DF_GetPlazaStringVersion'", nullptr);
            return 0;
        }
        std::string ret = cobj->GetPlazaStringVersion();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "DF:GetPlazaStringVersion",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_DF_GetPlazaStringVersion'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_DF_GetMobilePhone(lua_State* tolua_S)
{
    int argc = 0;
    DF* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"DF",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (DF*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_DF_GetMobilePhone'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_DF_GetMobilePhone'", nullptr);
            return 0;
        }
        const char* ret = cobj->GetMobilePhone();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "DF:GetMobilePhone",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_DF_GetMobilePhone'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_DF_GetDeviceType(lua_State* tolua_S)
{
    int argc = 0;
    DF* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"DF",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (DF*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_DF_GetDeviceType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_DF_GetDeviceType'", nullptr);
            return 0;
        }
        uint16_t ret = cobj->GetDeviceType();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "DF:GetDeviceType",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_DF_GetDeviceType'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_DF_GetMachineID(lua_State* tolua_S)
{
    int argc = 0;
    DF* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"DF",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (DF*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_DF_GetMachineID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_DF_GetMachineID'", nullptr);
            return 0;
        }
        const char* ret = cobj->GetMachineID();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "DF:GetMachineID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_DF_GetMachineID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_DF_GetPlazaVersion(lua_State* tolua_S)
{
    int argc = 0;
    DF* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"DF",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (DF*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_DF_GetPlazaVersion'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_DF_GetPlazaVersion'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->GetPlazaVersion();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "DF:GetPlazaVersion",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_DF_GetPlazaVersion'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_DF_init(lua_State* tolua_S)
{
    int argc = 0;
    DF* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"DF",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (DF*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_DF_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 4) 
    {
        int arg0;
        int arg1;
        const char* arg2;
        const char* arg3;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "DF:init");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "DF:init");

        std::string arg2_tmp; ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp, "DF:init"); arg2 = arg2_tmp.c_str();

        std::string arg3_tmp; ok &= luaval_to_std_string(tolua_S, 5, &arg3_tmp, "DF:init"); arg3 = arg3_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_DF_init'", nullptr);
            return 0;
        }
        cobj->init(arg0, arg1, arg2, arg3);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "DF:init",argc, 4);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_DF_init'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_DF_GetGamePlayer(lua_State* tolua_S)
{
    int argc = 0;
    DF* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"DF",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (DF*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_DF_GetGamePlayer'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_DF_GetGamePlayer'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->GetGamePlayer();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "DF:GetGamePlayer",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_DF_GetGamePlayer'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_DF_GetGameKindID(lua_State* tolua_S)
{
    int argc = 0;
    DF* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"DF",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (DF*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_DF_GetGameKindID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_DF_GetGameKindID'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->GetGameKindID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "DF:GetGameKindID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_DF_GetGameKindID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_DF_GetPlatformID(lua_State* tolua_S)
{
    int argc = 0;
    DF* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"DF",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (DF*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_DF_GetPlatformID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_DF_GetPlatformID'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->GetPlatformID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "DF:GetPlatformID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_DF_GetPlatformID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_DF_GetFrameVersion(lua_State* tolua_S)
{
    int argc = 0;
    DF* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"DF",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (DF*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_DF_GetFrameVersion'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_DF_GetFrameVersion'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->GetFrameVersion();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "DF:GetFrameVersion",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_DF_GetFrameVersion'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_DF_shared(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"DF",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_DF_shared'", nullptr);
            return 0;
        }
        DF* ret = DF::shared();
        object_to_luaval<DF>(tolua_S, "DF",(DF*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "DF:shared",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_DF_shared'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_platform_DF_MD5Encrypt(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"DF",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "DF:MD5Encrypt"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_DF_MD5Encrypt'", nullptr);
            return 0;
        }
        const char* ret = DF::MD5Encrypt(arg0);
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "DF:MD5Encrypt",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_DF_MD5Encrypt'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_platform_DF_constructor(lua_State* tolua_S)
{
    int argc = 0;
    DF* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_DF_constructor'", nullptr);
            return 0;
        }
        cobj = new DF();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"DF");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "DF:DF",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_DF_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_platform_DF_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (DF)");
    return 0;
}

int lua_register_cocos2dx_platform_DF(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"DF");
    tolua_cclass(tolua_S,"DF","DF","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"DF");
        tolua_function(tolua_S,"new",lua_cocos2dx_platform_DF_constructor);
        tolua_function(tolua_S,"GetGameVersion",lua_cocos2dx_platform_DF_GetGameVersion);
        tolua_function(tolua_S,"GetPlazzKindID",lua_cocos2dx_platform_DF_GetPlazzKindID);
        tolua_function(tolua_S,"GetPlazaStringVersion",lua_cocos2dx_platform_DF_GetPlazaStringVersion);
        tolua_function(tolua_S,"GetMobilePhone",lua_cocos2dx_platform_DF_GetMobilePhone);
        tolua_function(tolua_S,"GetDeviceType",lua_cocos2dx_platform_DF_GetDeviceType);
        tolua_function(tolua_S,"GetMachineID",lua_cocos2dx_platform_DF_GetMachineID);
        tolua_function(tolua_S,"GetPlazaVersion",lua_cocos2dx_platform_DF_GetPlazaVersion);
        tolua_function(tolua_S,"init",lua_cocos2dx_platform_DF_init);
        tolua_function(tolua_S,"GetGamePlayer",lua_cocos2dx_platform_DF_GetGamePlayer);
        tolua_function(tolua_S,"GetGameKindID",lua_cocos2dx_platform_DF_GetGameKindID);
        tolua_function(tolua_S,"GetPlatformID",lua_cocos2dx_platform_DF_GetPlatformID);
        tolua_function(tolua_S,"GetFrameVersion",lua_cocos2dx_platform_DF_GetFrameVersion);
        tolua_function(tolua_S,"shared", lua_cocos2dx_platform_DF_shared);
        tolua_function(tolua_S,"MD5Encrypt", lua_cocos2dx_platform_DF_MD5Encrypt);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(DF).name();
    g_luaType[typeName] = "DF";
    g_typeCast["DF"] = "DF";
    return 1;
}

int lua_cocos2dx_platform_tagGlobalUserData_getUserTickets(lua_State* tolua_S)
{
    int argc = 0;
    tagGlobalUserData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGlobalUserData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGlobalUserData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGlobalUserData_getUserTickets'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGlobalUserData_getUserTickets'", nullptr);
            return 0;
        }
        long long ret = cobj->getUserTickets();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGlobalUserData:getUserTickets",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGlobalUserData_getUserTickets'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGlobalUserData_setUserID(lua_State* tolua_S)
{
    int argc = 0;
    tagGlobalUserData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGlobalUserData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGlobalUserData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGlobalUserData_setUserID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "tagGlobalUserData:setUserID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGlobalUserData_setUserID'", nullptr);
            return 0;
        }
        cobj->setUserID(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGlobalUserData:setUserID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGlobalUserData_setUserID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGlobalUserData_setLoveLiness(lua_State* tolua_S)
{
    int argc = 0;
    tagGlobalUserData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGlobalUserData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGlobalUserData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGlobalUserData_setLoveLiness'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "tagGlobalUserData:setLoveLiness");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGlobalUserData_setLoveLiness'", nullptr);
            return 0;
        }
        cobj->setLoveLiness(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGlobalUserData:setLoveLiness",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGlobalUserData_setLoveLiness'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGlobalUserData_getUserIngot(lua_State* tolua_S)
{
    int argc = 0;
    tagGlobalUserData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGlobalUserData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGlobalUserData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGlobalUserData_getUserIngot'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGlobalUserData_getUserIngot'", nullptr);
            return 0;
        }
        long long ret = cobj->getUserIngot();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGlobalUserData:getUserIngot",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGlobalUserData_getUserIngot'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGlobalUserData_getExperience(lua_State* tolua_S)
{
    int argc = 0;
    tagGlobalUserData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGlobalUserData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGlobalUserData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGlobalUserData_getExperience'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGlobalUserData_getExperience'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getExperience();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGlobalUserData:getExperience",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGlobalUserData_getExperience'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGlobalUserData_getUserInsure(lua_State* tolua_S)
{
    int argc = 0;
    tagGlobalUserData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGlobalUserData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGlobalUserData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGlobalUserData_getUserInsure'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGlobalUserData_getUserInsure'", nullptr);
            return 0;
        }
        long long ret = cobj->getUserInsure();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGlobalUserData:getUserInsure",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGlobalUserData_getUserInsure'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGlobalUserData_setProfileUrl(lua_State* tolua_S)
{
    int argc = 0;
    tagGlobalUserData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGlobalUserData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGlobalUserData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGlobalUserData_setProfileUrl'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        int arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "tagGlobalUserData:setProfileUrl"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "tagGlobalUserData:setProfileUrl");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGlobalUserData_setProfileUrl'", nullptr);
            return 0;
        }
        cobj->setProfileUrl(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGlobalUserData:setProfileUrl",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGlobalUserData_setProfileUrl'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGlobalUserData_setUserTickets(lua_State* tolua_S)
{
    int argc = 0;
    tagGlobalUserData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGlobalUserData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGlobalUserData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGlobalUserData_setUserTickets'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        long long arg0;

        ok &= luaval_to_long_long(tolua_S, 2,&arg0, "tagGlobalUserData:setUserTickets");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGlobalUserData_setUserTickets'", nullptr);
            return 0;
        }
        cobj->setUserTickets(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGlobalUserData:setUserTickets",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGlobalUserData_setUserTickets'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGlobalUserData_getRegisterMobile(lua_State* tolua_S)
{
    int argc = 0;
    tagGlobalUserData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGlobalUserData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGlobalUserData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGlobalUserData_getRegisterMobile'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGlobalUserData_getRegisterMobile'", nullptr);
            return 0;
        }
        const char* ret = cobj->getRegisterMobile();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGlobalUserData:getRegisterMobile",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGlobalUserData_getRegisterMobile'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGlobalUserData_setMemberOrder(lua_State* tolua_S)
{
    int argc = 0;
    tagGlobalUserData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGlobalUserData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGlobalUserData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGlobalUserData_setMemberOrder'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        uint16_t arg0;

        ok &= luaval_to_uint16(tolua_S, 2,&arg0, "tagGlobalUserData:setMemberOrder");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGlobalUserData_setMemberOrder'", nullptr);
            return 0;
        }
        cobj->setMemberOrder(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGlobalUserData:setMemberOrder",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGlobalUserData_setMemberOrder'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGlobalUserData_setMoorMachine(lua_State* tolua_S)
{
    int argc = 0;
    tagGlobalUserData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGlobalUserData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGlobalUserData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGlobalUserData_setMoorMachine'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        uint16_t arg0;

        ok &= luaval_to_uint16(tolua_S, 2,&arg0, "tagGlobalUserData:setMoorMachine");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGlobalUserData_setMoorMachine'", nullptr);
            return 0;
        }
        cobj->setMoorMachine(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGlobalUserData:setMoorMachine",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGlobalUserData_setMoorMachine'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGlobalUserData_setUnderWrite(lua_State* tolua_S)
{
    int argc = 0;
    tagGlobalUserData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGlobalUserData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGlobalUserData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGlobalUserData_setUnderWrite'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        int arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "tagGlobalUserData:setUnderWrite"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "tagGlobalUserData:setUnderWrite");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGlobalUserData_setUnderWrite'", nullptr);
            return 0;
        }
        cobj->setUnderWrite(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGlobalUserData:setUnderWrite",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGlobalUserData_setUnderWrite'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGlobalUserData_getProfileUrl(lua_State* tolua_S)
{
    int argc = 0;
    tagGlobalUserData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGlobalUserData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGlobalUserData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGlobalUserData_getProfileUrl'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGlobalUserData_getProfileUrl'", nullptr);
            return 0;
        }
        const char* ret = cobj->getProfileUrl();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGlobalUserData:getProfileUrl",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGlobalUserData_getProfileUrl'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGlobalUserData_getAccounts(lua_State* tolua_S)
{
    int argc = 0;
    tagGlobalUserData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGlobalUserData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGlobalUserData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGlobalUserData_getAccounts'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGlobalUserData_getAccounts'", nullptr);
            return 0;
        }
        const char* ret = cobj->getAccounts();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGlobalUserData:getAccounts",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGlobalUserData_getAccounts'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGlobalUserData_getInsureEnabled(lua_State* tolua_S)
{
    int argc = 0;
    tagGlobalUserData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGlobalUserData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGlobalUserData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGlobalUserData_getInsureEnabled'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGlobalUserData_getInsureEnabled'", nullptr);
            return 0;
        }
        uint16_t ret = cobj->getInsureEnabled();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGlobalUserData:getInsureEnabled",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGlobalUserData_getInsureEnabled'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGlobalUserData_setDynamicPass(lua_State* tolua_S)
{
    int argc = 0;
    tagGlobalUserData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGlobalUserData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGlobalUserData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGlobalUserData_setDynamicPass'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        int arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "tagGlobalUserData:setDynamicPass"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "tagGlobalUserData:setDynamicPass");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGlobalUserData_setDynamicPass'", nullptr);
            return 0;
        }
        cobj->setDynamicPass(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGlobalUserData:setDynamicPass",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGlobalUserData_setDynamicPass'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGlobalUserData_getNickName(lua_State* tolua_S)
{
    int argc = 0;
    tagGlobalUserData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGlobalUserData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGlobalUserData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGlobalUserData_getNickName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGlobalUserData_getNickName'", nullptr);
            return 0;
        }
        const char* ret = cobj->getNickName();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGlobalUserData:getNickName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGlobalUserData_getNickName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGlobalUserData_setUserMedal(lua_State* tolua_S)
{
    int argc = 0;
    tagGlobalUserData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGlobalUserData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGlobalUserData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGlobalUserData_setUserMedal'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "tagGlobalUserData:setUserMedal");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGlobalUserData_setUserMedal'", nullptr);
            return 0;
        }
        cobj->setUserMedal(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGlobalUserData:setUserMedal",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGlobalUserData_setUserMedal'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGlobalUserData_setUserScore(lua_State* tolua_S)
{
    int argc = 0;
    tagGlobalUserData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGlobalUserData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGlobalUserData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGlobalUserData_setUserScore'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        long long arg0;

        ok &= luaval_to_long_long(tolua_S, 2,&arg0, "tagGlobalUserData:setUserScore");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGlobalUserData_setUserScore'", nullptr);
            return 0;
        }
        cobj->setUserScore(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGlobalUserData:setUserScore",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGlobalUserData_setUserScore'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGlobalUserData_setPassword(lua_State* tolua_S)
{
    int argc = 0;
    tagGlobalUserData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGlobalUserData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGlobalUserData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGlobalUserData_setPassword'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        int arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "tagGlobalUserData:setPassword"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "tagGlobalUserData:setPassword");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGlobalUserData_setPassword'", nullptr);
            return 0;
        }
        cobj->setPassword(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGlobalUserData:setPassword",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGlobalUserData_setPassword'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGlobalUserData_setInsureEnabled(lua_State* tolua_S)
{
    int argc = 0;
    tagGlobalUserData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGlobalUserData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGlobalUserData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGlobalUserData_setInsureEnabled'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        uint16_t arg0;

        ok &= luaval_to_uint16(tolua_S, 2,&arg0, "tagGlobalUserData:setInsureEnabled");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGlobalUserData_setInsureEnabled'", nullptr);
            return 0;
        }
        cobj->setInsureEnabled(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGlobalUserData:setInsureEnabled",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGlobalUserData_setInsureEnabled'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGlobalUserData_getUserBeans(lua_State* tolua_S)
{
    int argc = 0;
    tagGlobalUserData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGlobalUserData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGlobalUserData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGlobalUserData_getUserBeans'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGlobalUserData_getUserBeans'", nullptr);
            return 0;
        }
        long long ret = cobj->getUserBeans();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGlobalUserData:getUserBeans",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGlobalUserData_getUserBeans'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGlobalUserData_getGameID(lua_State* tolua_S)
{
    int argc = 0;
    tagGlobalUserData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGlobalUserData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGlobalUserData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGlobalUserData_getGameID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGlobalUserData_getGameID'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getGameID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGlobalUserData:getGameID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGlobalUserData_getGameID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGlobalUserData_getUnderWrite(lua_State* tolua_S)
{
    int argc = 0;
    tagGlobalUserData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGlobalUserData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGlobalUserData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGlobalUserData_getUnderWrite'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGlobalUserData_getUnderWrite'", nullptr);
            return 0;
        }
        const char* ret = cobj->getUnderWrite();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGlobalUserData:getUnderWrite",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGlobalUserData_getUnderWrite'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGlobalUserData_getMemberOrder(lua_State* tolua_S)
{
    int argc = 0;
    tagGlobalUserData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGlobalUserData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGlobalUserData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGlobalUserData_getMemberOrder'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGlobalUserData_getMemberOrder'", nullptr);
            return 0;
        }
        uint16_t ret = cobj->getMemberOrder();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGlobalUserData:getMemberOrder",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGlobalUserData_getMemberOrder'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGlobalUserData_getPassword(lua_State* tolua_S)
{
    int argc = 0;
    tagGlobalUserData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGlobalUserData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGlobalUserData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGlobalUserData_getPassword'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGlobalUserData_getPassword'", nullptr);
            return 0;
        }
        const char* ret = cobj->getPassword();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGlobalUserData:getPassword",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGlobalUserData_getPassword'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGlobalUserData_getCustomID(lua_State* tolua_S)
{
    int argc = 0;
    tagGlobalUserData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGlobalUserData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGlobalUserData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGlobalUserData_getCustomID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGlobalUserData_getCustomID'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getCustomID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGlobalUserData:getCustomID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGlobalUserData_getCustomID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGlobalUserData_setGender(lua_State* tolua_S)
{
    int argc = 0;
    tagGlobalUserData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGlobalUserData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGlobalUserData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGlobalUserData_setGender'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        uint16_t arg0;

        ok &= luaval_to_uint16(tolua_S, 2,&arg0, "tagGlobalUserData:setGender");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGlobalUserData_setGender'", nullptr);
            return 0;
        }
        cobj->setGender(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGlobalUserData:setGender",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGlobalUserData_setGender'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGlobalUserData_setExperience(lua_State* tolua_S)
{
    int argc = 0;
    tagGlobalUserData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGlobalUserData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGlobalUserData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGlobalUserData_setExperience'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "tagGlobalUserData:setExperience");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGlobalUserData_setExperience'", nullptr);
            return 0;
        }
        cobj->setExperience(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGlobalUserData:setExperience",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGlobalUserData_setExperience'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGlobalUserData_setGameID(lua_State* tolua_S)
{
    int argc = 0;
    tagGlobalUserData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGlobalUserData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGlobalUserData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGlobalUserData_setGameID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "tagGlobalUserData:setGameID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGlobalUserData_setGameID'", nullptr);
            return 0;
        }
        cobj->setGameID(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGlobalUserData:setGameID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGlobalUserData_setGameID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGlobalUserData_setGroupID(lua_State* tolua_S)
{
    int argc = 0;
    tagGlobalUserData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGlobalUserData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGlobalUserData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGlobalUserData_setGroupID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "tagGlobalUserData:setGroupID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGlobalUserData_setGroupID'", nullptr);
            return 0;
        }
        cobj->setGroupID(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGlobalUserData:setGroupID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGlobalUserData_setGroupID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGlobalUserData_getGender(lua_State* tolua_S)
{
    int argc = 0;
    tagGlobalUserData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGlobalUserData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGlobalUserData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGlobalUserData_getGender'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGlobalUserData_getGender'", nullptr);
            return 0;
        }
        uint16_t ret = cobj->getGender();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGlobalUserData:getGender",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGlobalUserData_getGender'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGlobalUserData_setGroupName(lua_State* tolua_S)
{
    int argc = 0;
    tagGlobalUserData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGlobalUserData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGlobalUserData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGlobalUserData_setGroupName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        int arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "tagGlobalUserData:setGroupName"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "tagGlobalUserData:setGroupName");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGlobalUserData_setGroupName'", nullptr);
            return 0;
        }
        cobj->setGroupName(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGlobalUserData:setGroupName",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGlobalUserData_setGroupName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGlobalUserData_setUserIngot(lua_State* tolua_S)
{
    int argc = 0;
    tagGlobalUserData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGlobalUserData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGlobalUserData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGlobalUserData_setUserIngot'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        long long arg0;

        ok &= luaval_to_long_long(tolua_S, 2,&arg0, "tagGlobalUserData:setUserIngot");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGlobalUserData_setUserIngot'", nullptr);
            return 0;
        }
        cobj->setUserIngot(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGlobalUserData:setUserIngot",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGlobalUserData_setUserIngot'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGlobalUserData_getGroupName(lua_State* tolua_S)
{
    int argc = 0;
    tagGlobalUserData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGlobalUserData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGlobalUserData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGlobalUserData_getGroupName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGlobalUserData_getGroupName'", nullptr);
            return 0;
        }
        const char* ret = cobj->getGroupName();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGlobalUserData:getGroupName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGlobalUserData_getGroupName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGlobalUserData_getLoveLiness(lua_State* tolua_S)
{
    int argc = 0;
    tagGlobalUserData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGlobalUserData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGlobalUserData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGlobalUserData_getLoveLiness'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGlobalUserData_getLoveLiness'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getLoveLiness();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGlobalUserData:getLoveLiness",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGlobalUserData_getLoveLiness'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGlobalUserData_getUserScore(lua_State* tolua_S)
{
    int argc = 0;
    tagGlobalUserData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGlobalUserData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGlobalUserData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGlobalUserData_getUserScore'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGlobalUserData_getUserScore'", nullptr);
            return 0;
        }
        long long ret = cobj->getUserScore();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGlobalUserData:getUserScore",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGlobalUserData_getUserScore'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGlobalUserData_getDynamicPass(lua_State* tolua_S)
{
    int argc = 0;
    tagGlobalUserData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGlobalUserData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGlobalUserData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGlobalUserData_getDynamicPass'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGlobalUserData_getDynamicPass'", nullptr);
            return 0;
        }
        const char* ret = cobj->getDynamicPass();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGlobalUserData:getDynamicPass",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGlobalUserData_getDynamicPass'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGlobalUserData_setNickName(lua_State* tolua_S)
{
    int argc = 0;
    tagGlobalUserData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGlobalUserData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGlobalUserData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGlobalUserData_setNickName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        int arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "tagGlobalUserData:setNickName"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "tagGlobalUserData:setNickName");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGlobalUserData_setNickName'", nullptr);
            return 0;
        }
        cobj->setNickName(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGlobalUserData:setNickName",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGlobalUserData_setNickName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGlobalUserData_getUserMedal(lua_State* tolua_S)
{
    int argc = 0;
    tagGlobalUserData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGlobalUserData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGlobalUserData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGlobalUserData_getUserMedal'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGlobalUserData_getUserMedal'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getUserMedal();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGlobalUserData:getUserMedal",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGlobalUserData_getUserMedal'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGlobalUserData_getFaceID(lua_State* tolua_S)
{
    int argc = 0;
    tagGlobalUserData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGlobalUserData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGlobalUserData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGlobalUserData_getFaceID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGlobalUserData_getFaceID'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->getFaceID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGlobalUserData:getFaceID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGlobalUserData_getFaceID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGlobalUserData_setRegisterMobile(lua_State* tolua_S)
{
    int argc = 0;
    tagGlobalUserData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGlobalUserData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGlobalUserData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGlobalUserData_setRegisterMobile'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        int arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "tagGlobalUserData:setRegisterMobile"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "tagGlobalUserData:setRegisterMobile");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGlobalUserData_setRegisterMobile'", nullptr);
            return 0;
        }
        cobj->setRegisterMobile(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGlobalUserData:setRegisterMobile",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGlobalUserData_setRegisterMobile'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGlobalUserData_setUserInsure(lua_State* tolua_S)
{
    int argc = 0;
    tagGlobalUserData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGlobalUserData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGlobalUserData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGlobalUserData_setUserInsure'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        long long arg0;

        ok &= luaval_to_long_long(tolua_S, 2,&arg0, "tagGlobalUserData:setUserInsure");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGlobalUserData_setUserInsure'", nullptr);
            return 0;
        }
        cobj->setUserInsure(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGlobalUserData:setUserInsure",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGlobalUserData_setUserInsure'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGlobalUserData_getGroupID(lua_State* tolua_S)
{
    int argc = 0;
    tagGlobalUserData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGlobalUserData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGlobalUserData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGlobalUserData_getGroupID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGlobalUserData_getGroupID'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getGroupID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGlobalUserData:getGroupID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGlobalUserData_getGroupID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGlobalUserData_getUserID(lua_State* tolua_S)
{
    int argc = 0;
    tagGlobalUserData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGlobalUserData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGlobalUserData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGlobalUserData_getUserID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGlobalUserData_getUserID'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getUserID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGlobalUserData:getUserID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGlobalUserData_getUserID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGlobalUserData_setFaceID(lua_State* tolua_S)
{
    int argc = 0;
    tagGlobalUserData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGlobalUserData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGlobalUserData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGlobalUserData_setFaceID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagGlobalUserData:setFaceID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGlobalUserData_setFaceID'", nullptr);
            return 0;
        }
        cobj->setFaceID(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGlobalUserData:setFaceID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGlobalUserData_setFaceID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGlobalUserData_setAccounts(lua_State* tolua_S)
{
    int argc = 0;
    tagGlobalUserData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGlobalUserData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGlobalUserData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGlobalUserData_setAccounts'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        int arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "tagGlobalUserData:setAccounts"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "tagGlobalUserData:setAccounts");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGlobalUserData_setAccounts'", nullptr);
            return 0;
        }
        cobj->setAccounts(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGlobalUserData:setAccounts",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGlobalUserData_setAccounts'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGlobalUserData_getMoorMachine(lua_State* tolua_S)
{
    int argc = 0;
    tagGlobalUserData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGlobalUserData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGlobalUserData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGlobalUserData_getMoorMachine'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGlobalUserData_getMoorMachine'", nullptr);
            return 0;
        }
        uint16_t ret = cobj->getMoorMachine();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGlobalUserData:getMoorMachine",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGlobalUserData_getMoorMachine'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGlobalUserData_setCustomID(lua_State* tolua_S)
{
    int argc = 0;
    tagGlobalUserData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGlobalUserData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGlobalUserData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGlobalUserData_setCustomID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "tagGlobalUserData:setCustomID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGlobalUserData_setCustomID'", nullptr);
            return 0;
        }
        cobj->setCustomID(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGlobalUserData:setCustomID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGlobalUserData_setCustomID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGlobalUserData_setUserBeans(lua_State* tolua_S)
{
    int argc = 0;
    tagGlobalUserData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGlobalUserData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGlobalUserData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGlobalUserData_setUserBeans'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        long long arg0;

        ok &= luaval_to_long_long(tolua_S, 2,&arg0, "tagGlobalUserData:setUserBeans");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGlobalUserData_setUserBeans'", nullptr);
            return 0;
        }
        cobj->setUserBeans(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGlobalUserData:setUserBeans",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGlobalUserData_setUserBeans'.",&tolua_err);
#endif

    return 0;
}
static int lua_cocos2dx_platform_tagGlobalUserData_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (tagGlobalUserData)");
    return 0;
}

int lua_register_cocos2dx_platform_tagGlobalUserData(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"tagGlobalUserData");
    tolua_cclass(tolua_S,"tagGlobalUserData","tagGlobalUserData","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"tagGlobalUserData");
        tolua_function(tolua_S,"getUserTickets",lua_cocos2dx_platform_tagGlobalUserData_getUserTickets);
        tolua_function(tolua_S,"setUserID",lua_cocos2dx_platform_tagGlobalUserData_setUserID);
        tolua_function(tolua_S,"setLoveLiness",lua_cocos2dx_platform_tagGlobalUserData_setLoveLiness);
        tolua_function(tolua_S,"getUserIngot",lua_cocos2dx_platform_tagGlobalUserData_getUserIngot);
        tolua_function(tolua_S,"getExperience",lua_cocos2dx_platform_tagGlobalUserData_getExperience);
        tolua_function(tolua_S,"getUserInsure",lua_cocos2dx_platform_tagGlobalUserData_getUserInsure);
        tolua_function(tolua_S,"setProfileUrl",lua_cocos2dx_platform_tagGlobalUserData_setProfileUrl);
        tolua_function(tolua_S,"setUserTickets",lua_cocos2dx_platform_tagGlobalUserData_setUserTickets);
        tolua_function(tolua_S,"getRegisterMobile",lua_cocos2dx_platform_tagGlobalUserData_getRegisterMobile);
        tolua_function(tolua_S,"setMemberOrder",lua_cocos2dx_platform_tagGlobalUserData_setMemberOrder);
        tolua_function(tolua_S,"setMoorMachine",lua_cocos2dx_platform_tagGlobalUserData_setMoorMachine);
        tolua_function(tolua_S,"setUnderWrite",lua_cocos2dx_platform_tagGlobalUserData_setUnderWrite);
        tolua_function(tolua_S,"getProfileUrl",lua_cocos2dx_platform_tagGlobalUserData_getProfileUrl);
        tolua_function(tolua_S,"getAccounts",lua_cocos2dx_platform_tagGlobalUserData_getAccounts);
        tolua_function(tolua_S,"getInsureEnabled",lua_cocos2dx_platform_tagGlobalUserData_getInsureEnabled);
        tolua_function(tolua_S,"setDynamicPass",lua_cocos2dx_platform_tagGlobalUserData_setDynamicPass);
        tolua_function(tolua_S,"getNickName",lua_cocos2dx_platform_tagGlobalUserData_getNickName);
        tolua_function(tolua_S,"setUserMedal",lua_cocos2dx_platform_tagGlobalUserData_setUserMedal);
        tolua_function(tolua_S,"setUserScore",lua_cocos2dx_platform_tagGlobalUserData_setUserScore);
        tolua_function(tolua_S,"setPassword",lua_cocos2dx_platform_tagGlobalUserData_setPassword);
        tolua_function(tolua_S,"setInsureEnabled",lua_cocos2dx_platform_tagGlobalUserData_setInsureEnabled);
        tolua_function(tolua_S,"getUserBeans",lua_cocos2dx_platform_tagGlobalUserData_getUserBeans);
        tolua_function(tolua_S,"getGameID",lua_cocos2dx_platform_tagGlobalUserData_getGameID);
        tolua_function(tolua_S,"getUnderWrite",lua_cocos2dx_platform_tagGlobalUserData_getUnderWrite);
        tolua_function(tolua_S,"getMemberOrder",lua_cocos2dx_platform_tagGlobalUserData_getMemberOrder);
        tolua_function(tolua_S,"getPassword",lua_cocos2dx_platform_tagGlobalUserData_getPassword);
        tolua_function(tolua_S,"getCustomID",lua_cocos2dx_platform_tagGlobalUserData_getCustomID);
        tolua_function(tolua_S,"setGender",lua_cocos2dx_platform_tagGlobalUserData_setGender);
        tolua_function(tolua_S,"setExperience",lua_cocos2dx_platform_tagGlobalUserData_setExperience);
        tolua_function(tolua_S,"setGameID",lua_cocos2dx_platform_tagGlobalUserData_setGameID);
        tolua_function(tolua_S,"setGroupID",lua_cocos2dx_platform_tagGlobalUserData_setGroupID);
        tolua_function(tolua_S,"getGender",lua_cocos2dx_platform_tagGlobalUserData_getGender);
        tolua_function(tolua_S,"setGroupName",lua_cocos2dx_platform_tagGlobalUserData_setGroupName);
        tolua_function(tolua_S,"setUserIngot",lua_cocos2dx_platform_tagGlobalUserData_setUserIngot);
        tolua_function(tolua_S,"getGroupName",lua_cocos2dx_platform_tagGlobalUserData_getGroupName);
        tolua_function(tolua_S,"getLoveLiness",lua_cocos2dx_platform_tagGlobalUserData_getLoveLiness);
        tolua_function(tolua_S,"getUserScore",lua_cocos2dx_platform_tagGlobalUserData_getUserScore);
        tolua_function(tolua_S,"getDynamicPass",lua_cocos2dx_platform_tagGlobalUserData_getDynamicPass);
        tolua_function(tolua_S,"setNickName",lua_cocos2dx_platform_tagGlobalUserData_setNickName);
        tolua_function(tolua_S,"getUserMedal",lua_cocos2dx_platform_tagGlobalUserData_getUserMedal);
        tolua_function(tolua_S,"getFaceID",lua_cocos2dx_platform_tagGlobalUserData_getFaceID);
        tolua_function(tolua_S,"setRegisterMobile",lua_cocos2dx_platform_tagGlobalUserData_setRegisterMobile);
        tolua_function(tolua_S,"setUserInsure",lua_cocos2dx_platform_tagGlobalUserData_setUserInsure);
        tolua_function(tolua_S,"getGroupID",lua_cocos2dx_platform_tagGlobalUserData_getGroupID);
        tolua_function(tolua_S,"getUserID",lua_cocos2dx_platform_tagGlobalUserData_getUserID);
        tolua_function(tolua_S,"setFaceID",lua_cocos2dx_platform_tagGlobalUserData_setFaceID);
        tolua_function(tolua_S,"setAccounts",lua_cocos2dx_platform_tagGlobalUserData_setAccounts);
        tolua_function(tolua_S,"getMoorMachine",lua_cocos2dx_platform_tagGlobalUserData_getMoorMachine);
        tolua_function(tolua_S,"setCustomID",lua_cocos2dx_platform_tagGlobalUserData_setCustomID);
        tolua_function(tolua_S,"setUserBeans",lua_cocos2dx_platform_tagGlobalUserData_setUserBeans);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(tagGlobalUserData).name();
    g_luaType[typeName] = "tagGlobalUserData";
    g_typeCast["tagGlobalUserData"] = "tagGlobalUserData";
    return 1;
}

int lua_cocos2dx_platform_tagIndividualUserData_setMobilePhone(lua_State* tolua_S)
{
    int argc = 0;
    tagIndividualUserData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagIndividualUserData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagIndividualUserData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagIndividualUserData_setMobilePhone'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        int arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "tagIndividualUserData:setMobilePhone"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "tagIndividualUserData:setMobilePhone");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagIndividualUserData_setMobilePhone'", nullptr);
            return 0;
        }
        cobj->setMobilePhone(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagIndividualUserData:setMobilePhone",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagIndividualUserData_setMobilePhone'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagIndividualUserData_getSeatPhone(lua_State* tolua_S)
{
    int argc = 0;
    tagIndividualUserData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagIndividualUserData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagIndividualUserData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagIndividualUserData_getSeatPhone'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagIndividualUserData_getSeatPhone'", nullptr);
            return 0;
        }
        const char* ret = cobj->getSeatPhone();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagIndividualUserData:getSeatPhone",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagIndividualUserData_getSeatPhone'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagIndividualUserData_setCompellation(lua_State* tolua_S)
{
    int argc = 0;
    tagIndividualUserData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagIndividualUserData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagIndividualUserData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagIndividualUserData_setCompellation'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        int arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "tagIndividualUserData:setCompellation"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "tagIndividualUserData:setCompellation");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagIndividualUserData_setCompellation'", nullptr);
            return 0;
        }
        cobj->setCompellation(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagIndividualUserData:setCompellation",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagIndividualUserData_setCompellation'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagIndividualUserData_getQQ(lua_State* tolua_S)
{
    int argc = 0;
    tagIndividualUserData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagIndividualUserData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagIndividualUserData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagIndividualUserData_getQQ'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagIndividualUserData_getQQ'", nullptr);
            return 0;
        }
        const char* ret = cobj->getQQ();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagIndividualUserData:getQQ",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagIndividualUserData_getQQ'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagIndividualUserData_getEMail(lua_State* tolua_S)
{
    int argc = 0;
    tagIndividualUserData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagIndividualUserData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagIndividualUserData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagIndividualUserData_getEMail'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagIndividualUserData_getEMail'", nullptr);
            return 0;
        }
        const char* ret = cobj->getEMail();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagIndividualUserData:getEMail",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagIndividualUserData_getEMail'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagIndividualUserData_setDwellingPlace(lua_State* tolua_S)
{
    int argc = 0;
    tagIndividualUserData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagIndividualUserData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagIndividualUserData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagIndividualUserData_setDwellingPlace'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        int arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "tagIndividualUserData:setDwellingPlace"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "tagIndividualUserData:setDwellingPlace");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagIndividualUserData_setDwellingPlace'", nullptr);
            return 0;
        }
        cobj->setDwellingPlace(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagIndividualUserData:setDwellingPlace",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagIndividualUserData_setDwellingPlace'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagIndividualUserData_setQQ(lua_State* tolua_S)
{
    int argc = 0;
    tagIndividualUserData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagIndividualUserData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagIndividualUserData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagIndividualUserData_setQQ'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        int arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "tagIndividualUserData:setQQ"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "tagIndividualUserData:setQQ");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagIndividualUserData_setQQ'", nullptr);
            return 0;
        }
        cobj->setQQ(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagIndividualUserData:setQQ",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagIndividualUserData_setQQ'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagIndividualUserData_getDwellingPlace(lua_State* tolua_S)
{
    int argc = 0;
    tagIndividualUserData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagIndividualUserData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagIndividualUserData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagIndividualUserData_getDwellingPlace'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagIndividualUserData_getDwellingPlace'", nullptr);
            return 0;
        }
        const char* ret = cobj->getDwellingPlace();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagIndividualUserData:getDwellingPlace",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagIndividualUserData_getDwellingPlace'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagIndividualUserData_getMobilePhone(lua_State* tolua_S)
{
    int argc = 0;
    tagIndividualUserData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagIndividualUserData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagIndividualUserData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagIndividualUserData_getMobilePhone'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagIndividualUserData_getMobilePhone'", nullptr);
            return 0;
        }
        const char* ret = cobj->getMobilePhone();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagIndividualUserData:getMobilePhone",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagIndividualUserData_getMobilePhone'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagIndividualUserData_getCompellation(lua_State* tolua_S)
{
    int argc = 0;
    tagIndividualUserData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagIndividualUserData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagIndividualUserData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagIndividualUserData_getCompellation'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagIndividualUserData_getCompellation'", nullptr);
            return 0;
        }
        const char* ret = cobj->getCompellation();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagIndividualUserData:getCompellation",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagIndividualUserData_getCompellation'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagIndividualUserData_setEMail(lua_State* tolua_S)
{
    int argc = 0;
    tagIndividualUserData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagIndividualUserData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagIndividualUserData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagIndividualUserData_setEMail'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        int arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "tagIndividualUserData:setEMail"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "tagIndividualUserData:setEMail");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagIndividualUserData_setEMail'", nullptr);
            return 0;
        }
        cobj->setEMail(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagIndividualUserData:setEMail",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagIndividualUserData_setEMail'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagIndividualUserData_getUserNote(lua_State* tolua_S)
{
    int argc = 0;
    tagIndividualUserData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagIndividualUserData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagIndividualUserData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagIndividualUserData_getUserNote'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagIndividualUserData_getUserNote'", nullptr);
            return 0;
        }
        const char* ret = cobj->getUserNote();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagIndividualUserData:getUserNote",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagIndividualUserData_getUserNote'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagIndividualUserData_setUserNote(lua_State* tolua_S)
{
    int argc = 0;
    tagIndividualUserData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagIndividualUserData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagIndividualUserData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagIndividualUserData_setUserNote'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        int arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "tagIndividualUserData:setUserNote"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "tagIndividualUserData:setUserNote");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagIndividualUserData_setUserNote'", nullptr);
            return 0;
        }
        cobj->setUserNote(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagIndividualUserData:setUserNote",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagIndividualUserData_setUserNote'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagIndividualUserData_setSeatPhone(lua_State* tolua_S)
{
    int argc = 0;
    tagIndividualUserData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagIndividualUserData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagIndividualUserData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagIndividualUserData_setSeatPhone'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        int arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "tagIndividualUserData:setSeatPhone"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "tagIndividualUserData:setSeatPhone");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagIndividualUserData_setSeatPhone'", nullptr);
            return 0;
        }
        cobj->setSeatPhone(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagIndividualUserData:setSeatPhone",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagIndividualUserData_setSeatPhone'.",&tolua_err);
#endif

    return 0;
}
static int lua_cocos2dx_platform_tagIndividualUserData_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (tagIndividualUserData)");
    return 0;
}

int lua_register_cocos2dx_platform_tagIndividualUserData(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"tagIndividualUserData");
    tolua_cclass(tolua_S,"tagIndividualUserData","tagIndividualUserData","tagGlobalUserData",nullptr);

    tolua_beginmodule(tolua_S,"tagIndividualUserData");
        tolua_function(tolua_S,"setMobilePhone",lua_cocos2dx_platform_tagIndividualUserData_setMobilePhone);
        tolua_function(tolua_S,"getSeatPhone",lua_cocos2dx_platform_tagIndividualUserData_getSeatPhone);
        tolua_function(tolua_S,"setCompellation",lua_cocos2dx_platform_tagIndividualUserData_setCompellation);
        tolua_function(tolua_S,"getQQ",lua_cocos2dx_platform_tagIndividualUserData_getQQ);
        tolua_function(tolua_S,"getEMail",lua_cocos2dx_platform_tagIndividualUserData_getEMail);
        tolua_function(tolua_S,"setDwellingPlace",lua_cocos2dx_platform_tagIndividualUserData_setDwellingPlace);
        tolua_function(tolua_S,"setQQ",lua_cocos2dx_platform_tagIndividualUserData_setQQ);
        tolua_function(tolua_S,"getDwellingPlace",lua_cocos2dx_platform_tagIndividualUserData_getDwellingPlace);
        tolua_function(tolua_S,"getMobilePhone",lua_cocos2dx_platform_tagIndividualUserData_getMobilePhone);
        tolua_function(tolua_S,"getCompellation",lua_cocos2dx_platform_tagIndividualUserData_getCompellation);
        tolua_function(tolua_S,"setEMail",lua_cocos2dx_platform_tagIndividualUserData_setEMail);
        tolua_function(tolua_S,"getUserNote",lua_cocos2dx_platform_tagIndividualUserData_getUserNote);
        tolua_function(tolua_S,"setUserNote",lua_cocos2dx_platform_tagIndividualUserData_setUserNote);
        tolua_function(tolua_S,"setSeatPhone",lua_cocos2dx_platform_tagIndividualUserData_setSeatPhone);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(tagIndividualUserData).name();
    g_luaType[typeName] = "tagIndividualUserData";
    g_typeCast["tagIndividualUserData"] = "tagIndividualUserData";
    return 1;
}

int lua_cocos2dx_platform_tagUserInsureInfo_setRevenueTransferMember(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInsureInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInsureInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInsureInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInsureInfo_setRevenueTransferMember'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagUserInsureInfo:setRevenueTransferMember");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInsureInfo_setRevenueTransferMember'", nullptr);
            return 0;
        }
        cobj->setRevenueTransferMember(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInsureInfo:setRevenueTransferMember",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInsureInfo_setRevenueTransferMember'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInsureInfo_getRevenueTransferMember(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInsureInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInsureInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInsureInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInsureInfo_getRevenueTransferMember'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInsureInfo_getRevenueTransferMember'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->getRevenueTransferMember();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInsureInfo:getRevenueTransferMember",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInsureInfo_getRevenueTransferMember'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInsureInfo_setRevenueTransfer(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInsureInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInsureInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInsureInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInsureInfo_setRevenueTransfer'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagUserInsureInfo:setRevenueTransfer");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInsureInfo_setRevenueTransfer'", nullptr);
            return 0;
        }
        cobj->setRevenueTransfer(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInsureInfo:setRevenueTransfer",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInsureInfo_setRevenueTransfer'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInsureInfo_setUserScore(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInsureInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInsureInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInsureInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInsureInfo_setUserScore'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        long long arg0;

        ok &= luaval_to_long_long(tolua_S, 2,&arg0, "tagUserInsureInfo:setUserScore");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInsureInfo_setUserScore'", nullptr);
            return 0;
        }
        cobj->setUserScore(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInsureInfo:setUserScore",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInsureInfo_setUserScore'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInsureInfo_getEnjoinTransfer(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInsureInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInsureInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInsureInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInsureInfo_getEnjoinTransfer'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInsureInfo_getEnjoinTransfer'", nullptr);
            return 0;
        }
        uint16_t ret = cobj->getEnjoinTransfer();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInsureInfo:getEnjoinTransfer",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInsureInfo_getEnjoinTransfer'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInsureInfo_getUserInsure(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInsureInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInsureInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInsureInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInsureInfo_getUserInsure'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInsureInfo_getUserInsure'", nullptr);
            return 0;
        }
        long long ret = cobj->getUserInsure();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInsureInfo:getUserInsure",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInsureInfo_getUserInsure'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInsureInfo_getServerID(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInsureInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInsureInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInsureInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInsureInfo_getServerID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInsureInfo_getServerID'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->getServerID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInsureInfo:getServerID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInsureInfo_getServerID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInsureInfo_getTransferPrerequisite(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInsureInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInsureInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInsureInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInsureInfo_getTransferPrerequisite'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInsureInfo_getTransferPrerequisite'", nullptr);
            return 0;
        }
        long long ret = cobj->getTransferPrerequisite();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInsureInfo:getTransferPrerequisite",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInsureInfo_getTransferPrerequisite'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInsureInfo_getRevenueTake(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInsureInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInsureInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInsureInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInsureInfo_getRevenueTake'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInsureInfo_getRevenueTake'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->getRevenueTake();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInsureInfo:getRevenueTake",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInsureInfo_getRevenueTake'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInsureInfo_setServerID(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInsureInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInsureInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInsureInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInsureInfo_setServerID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagUserInsureInfo:setServerID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInsureInfo_setServerID'", nullptr);
            return 0;
        }
        cobj->setServerID(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInsureInfo:setServerID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInsureInfo_setServerID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInsureInfo_setTransferPrerequisite(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInsureInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInsureInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInsureInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInsureInfo_setTransferPrerequisite'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        long long arg0;

        ok &= luaval_to_long_long(tolua_S, 2,&arg0, "tagUserInsureInfo:setTransferPrerequisite");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInsureInfo_setTransferPrerequisite'", nullptr);
            return 0;
        }
        cobj->setTransferPrerequisite(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInsureInfo:setTransferPrerequisite",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInsureInfo_setTransferPrerequisite'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInsureInfo_setEnjoinTransfer(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInsureInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInsureInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInsureInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInsureInfo_setEnjoinTransfer'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        uint16_t arg0;

        ok &= luaval_to_uint16(tolua_S, 2,&arg0, "tagUserInsureInfo:setEnjoinTransfer");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInsureInfo_setEnjoinTransfer'", nullptr);
            return 0;
        }
        cobj->setEnjoinTransfer(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInsureInfo:setEnjoinTransfer",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInsureInfo_setEnjoinTransfer'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInsureInfo_setRevenueTake(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInsureInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInsureInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInsureInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInsureInfo_setRevenueTake'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagUserInsureInfo:setRevenueTake");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInsureInfo_setRevenueTake'", nullptr);
            return 0;
        }
        cobj->setRevenueTake(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInsureInfo:setRevenueTake",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInsureInfo_setRevenueTake'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInsureInfo_setUserInsure(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInsureInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInsureInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInsureInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInsureInfo_setUserInsure'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        long long arg0;

        ok &= luaval_to_long_long(tolua_S, 2,&arg0, "tagUserInsureInfo:setUserInsure");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInsureInfo_setUserInsure'", nullptr);
            return 0;
        }
        cobj->setUserInsure(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInsureInfo:setUserInsure",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInsureInfo_setUserInsure'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInsureInfo_getUserScore(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInsureInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInsureInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInsureInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInsureInfo_getUserScore'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInsureInfo_getUserScore'", nullptr);
            return 0;
        }
        long long ret = cobj->getUserScore();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInsureInfo:getUserScore",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInsureInfo_getUserScore'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagUserInsureInfo_getRevenueTransfer(lua_State* tolua_S)
{
    int argc = 0;
    tagUserInsureInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserInsureInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserInsureInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagUserInsureInfo_getRevenueTransfer'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagUserInsureInfo_getRevenueTransfer'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->getRevenueTransfer();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserInsureInfo:getRevenueTransfer",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagUserInsureInfo_getRevenueTransfer'.",&tolua_err);
#endif

    return 0;
}
static int lua_cocos2dx_platform_tagUserInsureInfo_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (tagUserInsureInfo)");
    return 0;
}

int lua_register_cocos2dx_platform_tagUserInsureInfo(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"tagUserInsureInfo");
    tolua_cclass(tolua_S,"tagUserInsureInfo","tagUserInsureInfo","tagIndividualUserData",nullptr);

    tolua_beginmodule(tolua_S,"tagUserInsureInfo");
        tolua_function(tolua_S,"setRevenueTransferMember",lua_cocos2dx_platform_tagUserInsureInfo_setRevenueTransferMember);
        tolua_function(tolua_S,"getRevenueTransferMember",lua_cocos2dx_platform_tagUserInsureInfo_getRevenueTransferMember);
        tolua_function(tolua_S,"setRevenueTransfer",lua_cocos2dx_platform_tagUserInsureInfo_setRevenueTransfer);
        tolua_function(tolua_S,"setUserScore",lua_cocos2dx_platform_tagUserInsureInfo_setUserScore);
        tolua_function(tolua_S,"getEnjoinTransfer",lua_cocos2dx_platform_tagUserInsureInfo_getEnjoinTransfer);
        tolua_function(tolua_S,"getUserInsure",lua_cocos2dx_platform_tagUserInsureInfo_getUserInsure);
        tolua_function(tolua_S,"getServerID",lua_cocos2dx_platform_tagUserInsureInfo_getServerID);
        tolua_function(tolua_S,"getTransferPrerequisite",lua_cocos2dx_platform_tagUserInsureInfo_getTransferPrerequisite);
        tolua_function(tolua_S,"getRevenueTake",lua_cocos2dx_platform_tagUserInsureInfo_getRevenueTake);
        tolua_function(tolua_S,"setServerID",lua_cocos2dx_platform_tagUserInsureInfo_setServerID);
        tolua_function(tolua_S,"setTransferPrerequisite",lua_cocos2dx_platform_tagUserInsureInfo_setTransferPrerequisite);
        tolua_function(tolua_S,"setEnjoinTransfer",lua_cocos2dx_platform_tagUserInsureInfo_setEnjoinTransfer);
        tolua_function(tolua_S,"setRevenueTake",lua_cocos2dx_platform_tagUserInsureInfo_setRevenueTake);
        tolua_function(tolua_S,"setUserInsure",lua_cocos2dx_platform_tagUserInsureInfo_setUserInsure);
        tolua_function(tolua_S,"getUserScore",lua_cocos2dx_platform_tagUserInsureInfo_getUserScore);
        tolua_function(tolua_S,"getRevenueTransfer",lua_cocos2dx_platform_tagUserInsureInfo_getRevenueTransfer);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(tagUserInsureInfo).name();
    g_luaType[typeName] = "tagUserInsureInfo";
    g_typeCast["tagUserInsureInfo"] = "tagUserInsureInfo";
    return 1;
}

int lua_cocos2dx_platform_tagGrowLevelParameter_getCurrLevelID(lua_State* tolua_S)
{
    int argc = 0;
    tagGrowLevelParameter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGrowLevelParameter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGrowLevelParameter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGrowLevelParameter_getCurrLevelID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGrowLevelParameter_getCurrLevelID'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->getCurrLevelID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGrowLevelParameter:getCurrLevelID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGrowLevelParameter_getCurrLevelID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGrowLevelParameter_setCurrLevelID(lua_State* tolua_S)
{
    int argc = 0;
    tagGrowLevelParameter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGrowLevelParameter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGrowLevelParameter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGrowLevelParameter_setCurrLevelID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagGrowLevelParameter:setCurrLevelID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGrowLevelParameter_setCurrLevelID'", nullptr);
            return 0;
        }
        cobj->setCurrLevelID(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGrowLevelParameter:setCurrLevelID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGrowLevelParameter_setCurrLevelID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGrowLevelParameter_setExperience(lua_State* tolua_S)
{
    int argc = 0;
    tagGrowLevelParameter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGrowLevelParameter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGrowLevelParameter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGrowLevelParameter_setExperience'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "tagGrowLevelParameter:setExperience");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGrowLevelParameter_setExperience'", nullptr);
            return 0;
        }
        cobj->setExperience(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGrowLevelParameter:setExperience",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGrowLevelParameter_setExperience'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGrowLevelParameter_setUpgradeRewardGold(lua_State* tolua_S)
{
    int argc = 0;
    tagGrowLevelParameter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGrowLevelParameter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGrowLevelParameter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGrowLevelParameter_setUpgradeRewardGold'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        long long arg0;

        ok &= luaval_to_long_long(tolua_S, 2,&arg0, "tagGrowLevelParameter:setUpgradeRewardGold");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGrowLevelParameter_setUpgradeRewardGold'", nullptr);
            return 0;
        }
        cobj->setUpgradeRewardGold(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGrowLevelParameter:setUpgradeRewardGold",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGrowLevelParameter_setUpgradeRewardGold'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGrowLevelParameter_getExperience(lua_State* tolua_S)
{
    int argc = 0;
    tagGrowLevelParameter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGrowLevelParameter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGrowLevelParameter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGrowLevelParameter_getExperience'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGrowLevelParameter_getExperience'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getExperience();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGrowLevelParameter:getExperience",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGrowLevelParameter_getExperience'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGrowLevelParameter_getUpgradeExperience(lua_State* tolua_S)
{
    int argc = 0;
    tagGrowLevelParameter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGrowLevelParameter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGrowLevelParameter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGrowLevelParameter_getUpgradeExperience'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGrowLevelParameter_getUpgradeExperience'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getUpgradeExperience();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGrowLevelParameter:getUpgradeExperience",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGrowLevelParameter_getUpgradeExperience'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGrowLevelParameter_setUpgradeRewardIngot(lua_State* tolua_S)
{
    int argc = 0;
    tagGrowLevelParameter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGrowLevelParameter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGrowLevelParameter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGrowLevelParameter_setUpgradeRewardIngot'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        long long arg0;

        ok &= luaval_to_long_long(tolua_S, 2,&arg0, "tagGrowLevelParameter:setUpgradeRewardIngot");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGrowLevelParameter_setUpgradeRewardIngot'", nullptr);
            return 0;
        }
        cobj->setUpgradeRewardIngot(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGrowLevelParameter:setUpgradeRewardIngot",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGrowLevelParameter_setUpgradeRewardIngot'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGrowLevelParameter_getUpgradeRewardGold(lua_State* tolua_S)
{
    int argc = 0;
    tagGrowLevelParameter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGrowLevelParameter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGrowLevelParameter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGrowLevelParameter_getUpgradeRewardGold'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGrowLevelParameter_getUpgradeRewardGold'", nullptr);
            return 0;
        }
        long long ret = cobj->getUpgradeRewardGold();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGrowLevelParameter:getUpgradeRewardGold",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGrowLevelParameter_getUpgradeRewardGold'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGrowLevelParameter_setUpgradeExperience(lua_State* tolua_S)
{
    int argc = 0;
    tagGrowLevelParameter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGrowLevelParameter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGrowLevelParameter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGrowLevelParameter_setUpgradeExperience'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "tagGrowLevelParameter:setUpgradeExperience");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGrowLevelParameter_setUpgradeExperience'", nullptr);
            return 0;
        }
        cobj->setUpgradeExperience(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGrowLevelParameter:setUpgradeExperience",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGrowLevelParameter_setUpgradeExperience'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_tagGrowLevelParameter_getUpgradeRewardIngot(lua_State* tolua_S)
{
    int argc = 0;
    tagGrowLevelParameter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGrowLevelParameter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGrowLevelParameter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_tagGrowLevelParameter_getUpgradeRewardIngot'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_tagGrowLevelParameter_getUpgradeRewardIngot'", nullptr);
            return 0;
        }
        long long ret = cobj->getUpgradeRewardIngot();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGrowLevelParameter:getUpgradeRewardIngot",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_tagGrowLevelParameter_getUpgradeRewardIngot'.",&tolua_err);
#endif

    return 0;
}
static int lua_cocos2dx_platform_tagGrowLevelParameter_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (tagGrowLevelParameter)");
    return 0;
}

int lua_register_cocos2dx_platform_tagGrowLevelParameter(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"tagGrowLevelParameter");
    tolua_cclass(tolua_S,"tagGrowLevelParameter","tagGrowLevelParameter","tagUserInsureInfo",nullptr);

    tolua_beginmodule(tolua_S,"tagGrowLevelParameter");
        tolua_function(tolua_S,"getCurrLevelID",lua_cocos2dx_platform_tagGrowLevelParameter_getCurrLevelID);
        tolua_function(tolua_S,"setCurrLevelID",lua_cocos2dx_platform_tagGrowLevelParameter_setCurrLevelID);
        tolua_function(tolua_S,"setExperience",lua_cocos2dx_platform_tagGrowLevelParameter_setExperience);
        tolua_function(tolua_S,"setUpgradeRewardGold",lua_cocos2dx_platform_tagGrowLevelParameter_setUpgradeRewardGold);
        tolua_function(tolua_S,"getExperience",lua_cocos2dx_platform_tagGrowLevelParameter_getExperience);
        tolua_function(tolua_S,"getUpgradeExperience",lua_cocos2dx_platform_tagGrowLevelParameter_getUpgradeExperience);
        tolua_function(tolua_S,"setUpgradeRewardIngot",lua_cocos2dx_platform_tagGrowLevelParameter_setUpgradeRewardIngot);
        tolua_function(tolua_S,"getUpgradeRewardGold",lua_cocos2dx_platform_tagGrowLevelParameter_getUpgradeRewardGold);
        tolua_function(tolua_S,"setUpgradeExperience",lua_cocos2dx_platform_tagGrowLevelParameter_setUpgradeExperience);
        tolua_function(tolua_S,"getUpgradeRewardIngot",lua_cocos2dx_platform_tagGrowLevelParameter_getUpgradeRewardIngot);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(tagGrowLevelParameter).name();
    g_luaType[typeName] = "tagGrowLevelParameter";
    g_typeCast["tagGrowLevelParameter"] = "tagGrowLevelParameter";
    return 1;
}

int lua_cocos2dx_platform_CGlobalUserInfo_ResetUserInfoData(lua_State* tolua_S)
{
    int argc = 0;
    CGlobalUserInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGlobalUserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CGlobalUserInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CGlobalUserInfo_ResetUserInfoData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CGlobalUserInfo_ResetUserInfoData'", nullptr);
            return 0;
        }
        cobj->ResetUserInfoData();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGlobalUserInfo:ResetUserInfoData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CGlobalUserInfo_ResetUserInfoData'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CGlobalUserInfo_GetInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CGlobalUserInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CGlobalUserInfo_GetInstance'", nullptr);
            return 0;
        }
        CGlobalUserInfo* ret = CGlobalUserInfo::GetInstance();
        object_to_luaval<CGlobalUserInfo>(tolua_S, "CGlobalUserInfo",(CGlobalUserInfo*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CGlobalUserInfo:GetInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CGlobalUserInfo_GetInstance'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_platform_CGlobalUserInfo_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CGlobalUserInfo)");
    return 0;
}

int lua_register_cocos2dx_platform_CGlobalUserInfo(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CGlobalUserInfo");
    tolua_cclass(tolua_S,"CGlobalUserInfo","CGlobalUserInfo","tagGrowLevelParameter",nullptr);

    tolua_beginmodule(tolua_S,"CGlobalUserInfo");
        tolua_function(tolua_S,"ResetUserInfoData",lua_cocos2dx_platform_CGlobalUserInfo_ResetUserInfoData);
        tolua_function(tolua_S,"GetInstance", lua_cocos2dx_platform_CGlobalUserInfo_GetInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CGlobalUserInfo).name();
    g_luaType[typeName] = "CGlobalUserInfo";
    g_typeCast["CGlobalUserInfo"] = "CGlobalUserInfo";
    return 1;
}

int lua_cocos2dx_platform_CGameTypeItem_GetGameType(lua_State* tolua_S)
{
    int argc = 0;
    CGameTypeItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGameTypeItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CGameTypeItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CGameTypeItem_GetGameType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CGameTypeItem_GetGameType'", nullptr);
            return 0;
        }
        tagGameType* ret = cobj->GetGameType();
        object_to_luaval<tagGameType>(tolua_S, "tagGameType",(tagGameType*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameTypeItem:GetGameType",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CGameTypeItem_GetGameType'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CGameTypeItem_GetSortID(lua_State* tolua_S)
{
    int argc = 0;
    CGameTypeItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGameTypeItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CGameTypeItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CGameTypeItem_GetSortID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CGameTypeItem_GetSortID'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->GetSortID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameTypeItem:GetSortID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CGameTypeItem_GetSortID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CGameTypeItem_constructor(lua_State* tolua_S)
{
    int argc = 0;
    CGameTypeItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CGameTypeItem_constructor'", nullptr);
            return 0;
        }
        cobj = new CGameTypeItem();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"CGameTypeItem");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameTypeItem:CGameTypeItem",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CGameTypeItem_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_platform_CGameTypeItem_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CGameTypeItem)");
    return 0;
}

int lua_register_cocos2dx_platform_CGameTypeItem(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CGameTypeItem");
    tolua_cclass(tolua_S,"CGameTypeItem","CGameTypeItem","CGameListItem",nullptr);

    tolua_beginmodule(tolua_S,"CGameTypeItem");
        tolua_function(tolua_S,"new",lua_cocos2dx_platform_CGameTypeItem_constructor);
        tolua_function(tolua_S,"GetGameType",lua_cocos2dx_platform_CGameTypeItem_GetGameType);
        tolua_function(tolua_S,"GetSortID",lua_cocos2dx_platform_CGameTypeItem_GetSortID);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CGameTypeItem).name();
    g_luaType[typeName] = "CGameTypeItem";
    g_typeCast["CGameTypeItem"] = "CGameTypeItem";
    return 1;
}

int lua_cocos2dx_platform_CGameKindItem_GetGameKind(lua_State* tolua_S)
{
    int argc = 0;
    CGameKindItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGameKindItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CGameKindItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CGameKindItem_GetGameKind'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CGameKindItem_GetGameKind'", nullptr);
            return 0;
        }
        tagGameKind* ret = cobj->GetGameKind();
        object_to_luaval<tagGameKind>(tolua_S, "tagGameKind",(tagGameKind*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameKindItem:GetGameKind",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CGameKindItem_GetGameKind'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CGameKindItem_GetSortID(lua_State* tolua_S)
{
    int argc = 0;
    CGameKindItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGameKindItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CGameKindItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CGameKindItem_GetSortID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CGameKindItem_GetSortID'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->GetSortID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameKindItem:GetSortID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CGameKindItem_GetSortID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CGameKindItem_constructor(lua_State* tolua_S)
{
    int argc = 0;
    CGameKindItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CGameKindItem_constructor'", nullptr);
            return 0;
        }
        cobj = new CGameKindItem();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"CGameKindItem");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameKindItem:CGameKindItem",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CGameKindItem_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_platform_CGameKindItem_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CGameKindItem)");
    return 0;
}

int lua_register_cocos2dx_platform_CGameKindItem(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CGameKindItem");
    tolua_cclass(tolua_S,"CGameKindItem","CGameKindItem","CGameListItem",nullptr);

    tolua_beginmodule(tolua_S,"CGameKindItem");
        tolua_function(tolua_S,"new",lua_cocos2dx_platform_CGameKindItem_constructor);
        tolua_function(tolua_S,"GetGameKind",lua_cocos2dx_platform_CGameKindItem_GetGameKind);
        tolua_function(tolua_S,"GetSortID",lua_cocos2dx_platform_CGameKindItem_GetSortID);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CGameKindItem).name();
    g_luaType[typeName] = "CGameKindItem";
    g_typeCast["CGameKindItem"] = "CGameKindItem";
    return 1;
}

int lua_cocos2dx_platform_CGameNodeItem_GetGameNode(lua_State* tolua_S)
{
    int argc = 0;
    CGameNodeItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGameNodeItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CGameNodeItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CGameNodeItem_GetGameNode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CGameNodeItem_GetGameNode'", nullptr);
            return 0;
        }
        tagGameNode* ret = cobj->GetGameNode();
        object_to_luaval<tagGameNode>(tolua_S, "tagGameNode",(tagGameNode*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameNodeItem:GetGameNode",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CGameNodeItem_GetGameNode'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CGameNodeItem_GetSortID(lua_State* tolua_S)
{
    int argc = 0;
    CGameNodeItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGameNodeItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CGameNodeItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CGameNodeItem_GetSortID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CGameNodeItem_GetSortID'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->GetSortID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameNodeItem:GetSortID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CGameNodeItem_GetSortID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CGameNodeItem_constructor(lua_State* tolua_S)
{
    int argc = 0;
    CGameNodeItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CGameNodeItem_constructor'", nullptr);
            return 0;
        }
        cobj = new CGameNodeItem();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"CGameNodeItem");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameNodeItem:CGameNodeItem",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CGameNodeItem_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_platform_CGameNodeItem_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CGameNodeItem)");
    return 0;
}

int lua_register_cocos2dx_platform_CGameNodeItem(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CGameNodeItem");
    tolua_cclass(tolua_S,"CGameNodeItem","CGameNodeItem","CGameListItem",nullptr);

    tolua_beginmodule(tolua_S,"CGameNodeItem");
        tolua_function(tolua_S,"new",lua_cocos2dx_platform_CGameNodeItem_constructor);
        tolua_function(tolua_S,"GetGameNode",lua_cocos2dx_platform_CGameNodeItem_GetGameNode);
        tolua_function(tolua_S,"GetSortID",lua_cocos2dx_platform_CGameNodeItem_GetSortID);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CGameNodeItem).name();
    g_luaType[typeName] = "CGameNodeItem";
    g_typeCast["CGameNodeItem"] = "CGameNodeItem";
    return 1;
}

int lua_cocos2dx_platform_CGameServerItem_GetGameMatch(lua_State* tolua_S)
{
    int argc = 0;
    CGameServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGameServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CGameServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CGameServerItem_GetGameMatch'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CGameServerItem_GetGameMatch'", nullptr);
            return 0;
        }
        tagGameMatch* ret = cobj->GetGameMatch();
        object_to_luaval<tagGameMatch>(tolua_S, "tagGameMatch",(tagGameMatch*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameServerItem:GetGameMatch",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CGameServerItem_GetGameMatch'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CGameServerItem_GetSortID(lua_State* tolua_S)
{
    int argc = 0;
    CGameServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGameServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CGameServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CGameServerItem_GetSortID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CGameServerItem_GetSortID'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->GetSortID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameServerItem:GetSortID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CGameServerItem_GetSortID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CGameServerItem_GetGameServer(lua_State* tolua_S)
{
    int argc = 0;
    CGameServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGameServerItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CGameServerItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CGameServerItem_GetGameServer'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CGameServerItem_GetGameServer'", nullptr);
            return 0;
        }
        tagGameServer* ret = cobj->GetGameServer();
        object_to_luaval<tagGameServer>(tolua_S, "tagGameServer",(tagGameServer*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameServerItem:GetGameServer",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CGameServerItem_GetGameServer'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CGameServerItem_constructor(lua_State* tolua_S)
{
    int argc = 0;
    CGameServerItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CGameServerItem_constructor'", nullptr);
            return 0;
        }
        cobj = new CGameServerItem();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"CGameServerItem");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameServerItem:CGameServerItem",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CGameServerItem_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_platform_CGameServerItem_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CGameServerItem)");
    return 0;
}

int lua_register_cocos2dx_platform_CGameServerItem(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CGameServerItem");
    tolua_cclass(tolua_S,"CGameServerItem","CGameServerItem","CGameListItem",nullptr);

    tolua_beginmodule(tolua_S,"CGameServerItem");
        tolua_function(tolua_S,"new",lua_cocos2dx_platform_CGameServerItem_constructor);
        tolua_function(tolua_S,"GetGameMatch",lua_cocos2dx_platform_CGameServerItem_GetGameMatch);
        tolua_function(tolua_S,"GetSortID",lua_cocos2dx_platform_CGameServerItem_GetSortID);
        tolua_function(tolua_S,"GetGameServer",lua_cocos2dx_platform_CGameServerItem_GetGameServer);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CGameServerItem).name();
    g_luaType[typeName] = "CGameServerItem";
    g_typeCast["CGameServerItem"] = "CGameServerItem";
    return 1;
}

int lua_cocos2dx_platform_CGamePageItem_GetGamePage(lua_State* tolua_S)
{
    int argc = 0;
    CGamePageItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGamePageItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CGamePageItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CGamePageItem_GetGamePage'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CGamePageItem_GetGamePage'", nullptr);
            return 0;
        }
        tagGamePage* ret = cobj->GetGamePage();
        object_to_luaval<tagGamePage>(tolua_S, "tagGamePage",(tagGamePage*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGamePageItem:GetGamePage",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CGamePageItem_GetGamePage'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CGamePageItem_GetSortID(lua_State* tolua_S)
{
    int argc = 0;
    CGamePageItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGamePageItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CGamePageItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CGamePageItem_GetSortID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CGamePageItem_GetSortID'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->GetSortID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGamePageItem:GetSortID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CGamePageItem_GetSortID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CGamePageItem_constructor(lua_State* tolua_S)
{
    int argc = 0;
    CGamePageItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CGamePageItem_constructor'", nullptr);
            return 0;
        }
        cobj = new CGamePageItem();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"CGamePageItem");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGamePageItem:CGamePageItem",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CGamePageItem_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_platform_CGamePageItem_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CGamePageItem)");
    return 0;
}

int lua_register_cocos2dx_platform_CGamePageItem(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CGamePageItem");
    tolua_cclass(tolua_S,"CGamePageItem","CGamePageItem","CGameListItem",nullptr);

    tolua_beginmodule(tolua_S,"CGamePageItem");
        tolua_function(tolua_S,"new",lua_cocos2dx_platform_CGamePageItem_constructor);
        tolua_function(tolua_S,"GetGamePage",lua_cocos2dx_platform_CGamePageItem_GetGamePage);
        tolua_function(tolua_S,"GetSortID",lua_cocos2dx_platform_CGamePageItem_GetSortID);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CGamePageItem).name();
    g_luaType[typeName] = "CGamePageItem";
    g_typeCast["CGamePageItem"] = "CGamePageItem";
    return 1;
}

int lua_cocos2dx_platform_CGameInsideItem_GetSortID(lua_State* tolua_S)
{
    int argc = 0;
    CGameInsideItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CGameInsideItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CGameInsideItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CGameInsideItem_GetSortID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CGameInsideItem_GetSortID'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->GetSortID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameInsideItem:GetSortID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CGameInsideItem_GetSortID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CGameInsideItem_constructor(lua_State* tolua_S)
{
    int argc = 0;
    CGameInsideItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CGameInsideItem_constructor'", nullptr);
            return 0;
        }
        cobj = new CGameInsideItem();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"CGameInsideItem");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CGameInsideItem:CGameInsideItem",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CGameInsideItem_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_platform_CGameInsideItem_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CGameInsideItem)");
    return 0;
}

int lua_register_cocos2dx_platform_CGameInsideItem(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CGameInsideItem");
    tolua_cclass(tolua_S,"CGameInsideItem","CGameInsideItem","CGameListItem",nullptr);

    tolua_beginmodule(tolua_S,"CGameInsideItem");
        tolua_function(tolua_S,"new",lua_cocos2dx_platform_CGameInsideItem_constructor);
        tolua_function(tolua_S,"GetSortID",lua_cocos2dx_platform_CGameInsideItem_GetSortID);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CGameInsideItem).name();
    g_luaType[typeName] = "CGameInsideItem";
    g_typeCast["CGameInsideItem"] = "CGameInsideItem";
    return 1;
}

int lua_cocos2dx_platform_CServerListData_ClearGameType(lua_State* tolua_S)
{
    int argc = 0;
    CServerListData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerListData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerListData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CServerListData_ClearGameType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CServerListData_ClearGameType'", nullptr);
            return 0;
        }
        bool ret = cobj->ClearGameType();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerListData:ClearGameType",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CServerListData_ClearGameType'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CServerListData_InsertGameServer(lua_State* tolua_S)
{
    int argc = 0;
    CServerListData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerListData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerListData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CServerListData_InsertGameServer'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const cocos2d::Ref* arg0;

        ok &= luaval_to_object<const cocos2d::Ref>(tolua_S, 2, "cc.Ref",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CServerListData_InsertGameServer'", nullptr);
            return 0;
        }
        bool ret = cobj->InsertGameServer(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerListData:InsertGameServer",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CServerListData_InsertGameServer'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CServerListData_DeleteGameType(lua_State* tolua_S)
{
    int argc = 0;
    CServerListData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerListData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerListData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CServerListData_DeleteGameType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CServerListData:DeleteGameType");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CServerListData_DeleteGameType'", nullptr);
            return 0;
        }
        bool ret = cobj->DeleteGameType(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerListData:DeleteGameType",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CServerListData_DeleteGameType'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CServerListData_SearchGameKind(lua_State* tolua_S)
{
    int argc = 0;
    CServerListData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerListData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerListData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CServerListData_SearchGameKind'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CServerListData:SearchGameKind");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CServerListData_SearchGameKind'", nullptr);
            return 0;
        }
        CGameKindItem* ret = cobj->SearchGameKind(arg0);
        object_to_luaval<CGameKindItem>(tolua_S, "CGameKindItem",(CGameKindItem*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerListData:SearchGameKind",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CServerListData_SearchGameKind'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CServerListData_GetGameTypeCount(lua_State* tolua_S)
{
    int argc = 0;
    CServerListData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerListData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerListData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CServerListData_GetGameTypeCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CServerListData_GetGameTypeCount'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->GetGameTypeCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerListData:GetGameTypeCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CServerListData_GetGameTypeCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CServerListData_GetGameKindCount(lua_State* tolua_S)
{
    int argc = 0;
    CServerListData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerListData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerListData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CServerListData_GetGameKindCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CServerListData_GetGameKindCount'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->GetGameKindCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerListData:GetGameKindCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CServerListData_GetGameKindCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CServerListData_SearchGameNodeByIndex(lua_State* tolua_S)
{
    int argc = 0;
    CServerListData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerListData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerListData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CServerListData_SearchGameNodeByIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "CServerListData:SearchGameNodeByIndex");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CServerListData_SearchGameNodeByIndex'", nullptr);
            return 0;
        }
        CGameNodeItem* ret = cobj->SearchGameNodeByIndex(arg0);
        object_to_luaval<CGameNodeItem>(tolua_S, "CGameNodeItem",(CGameNodeItem*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerListData:SearchGameNodeByIndex",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CServerListData_SearchGameNodeByIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CServerListData_GetAllOnLineCount(lua_State* tolua_S)
{
    int argc = 0;
    CServerListData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerListData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerListData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CServerListData_GetAllOnLineCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CServerListData_GetAllOnLineCount'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->GetAllOnLineCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerListData:GetAllOnLineCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CServerListData_GetAllOnLineCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CServerListData_ClearGameKind(lua_State* tolua_S)
{
    int argc = 0;
    CServerListData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerListData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerListData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CServerListData_ClearGameKind'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CServerListData_ClearGameKind'", nullptr);
            return 0;
        }
        bool ret = cobj->ClearGameKind();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerListData:ClearGameKind",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CServerListData_ClearGameKind'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CServerListData_OnGameItemInsert(lua_State* tolua_S)
{
    int argc = 0;
    CServerListData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerListData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerListData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CServerListData_OnGameItemInsert'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        CGameListItem* arg0;

        ok &= luaval_to_object<CGameListItem>(tolua_S, 2, "CGameListItem",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CServerListData_OnGameItemInsert'", nullptr);
            return 0;
        }
        cobj->OnGameItemInsert(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerListData:OnGameItemInsert",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CServerListData_OnGameItemInsert'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CServerListData_SearchGameType(lua_State* tolua_S)
{
    int argc = 0;
    CServerListData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerListData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerListData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CServerListData_SearchGameType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CServerListData:SearchGameType");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CServerListData_SearchGameType'", nullptr);
            return 0;
        }
        CGameTypeItem* ret = cobj->SearchGameType(arg0);
        object_to_luaval<CGameTypeItem>(tolua_S, "CGameTypeItem",(CGameTypeItem*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerListData:SearchGameType",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CServerListData_SearchGameType'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CServerListData_DeleteGameServer(lua_State* tolua_S)
{
    int argc = 0;
    CServerListData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerListData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerListData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CServerListData_DeleteGameServer'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CServerListData:DeleteGameServer");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CServerListData_DeleteGameServer'", nullptr);
            return 0;
        }
        bool ret = cobj->DeleteGameServer(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerListData:DeleteGameServer",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CServerListData_DeleteGameServer'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CServerListData_ClearGamePage(lua_State* tolua_S)
{
    int argc = 0;
    CServerListData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerListData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerListData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CServerListData_ClearGamePage'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CServerListData_ClearGamePage'", nullptr);
            return 0;
        }
        bool ret = cobj->ClearGamePage();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerListData:ClearGamePage",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CServerListData_ClearGamePage'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CServerListData_ClearGameServer(lua_State* tolua_S)
{
    int argc = 0;
    CServerListData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerListData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerListData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CServerListData_ClearGameServer'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CServerListData_ClearGameServer'", nullptr);
            return 0;
        }
        bool ret = cobj->ClearGameServer();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerListData:ClearGameServer",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CServerListData_ClearGameServer'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CServerListData_SearchGameServer(lua_State* tolua_S)
{
    int argc = 0;
    CServerListData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerListData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerListData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CServerListData_SearchGameServer'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CServerListData:SearchGameServer");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CServerListData_SearchGameServer'", nullptr);
            return 0;
        }
        CGameServerItem* ret = cobj->SearchGameServer(arg0);
        object_to_luaval<CGameServerItem>(tolua_S, "CGameServerItem",(CGameServerItem*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerListData:SearchGameServer",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CServerListData_SearchGameServer'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CServerListData_SearchGameKindByIndex(lua_State* tolua_S)
{
    int argc = 0;
    CServerListData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerListData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerListData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CServerListData_SearchGameKindByIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "CServerListData:SearchGameKindByIndex");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CServerListData_SearchGameKindByIndex'", nullptr);
            return 0;
        }
        CGameKindItem* ret = cobj->SearchGameKindByIndex(arg0);
        object_to_luaval<CGameKindItem>(tolua_S, "CGameKindItem",(CGameKindItem*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerListData:SearchGameKindByIndex",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CServerListData_SearchGameKindByIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CServerListData_OnGameKindFinish(lua_State* tolua_S)
{
    int argc = 0;
    CServerListData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerListData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerListData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CServerListData_OnGameKindFinish'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CServerListData:OnGameKindFinish");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CServerListData_OnGameKindFinish'", nullptr);
            return 0;
        }
        cobj->OnGameKindFinish(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerListData:OnGameKindFinish",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CServerListData_OnGameKindFinish'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CServerListData_OnGameItemFinish(lua_State* tolua_S)
{
    int argc = 0;
    CServerListData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerListData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerListData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CServerListData_OnGameItemFinish'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CServerListData_OnGameItemFinish'", nullptr);
            return 0;
        }
        cobj->OnGameItemFinish();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerListData:OnGameItemFinish",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CServerListData_OnGameItemFinish'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CServerListData_SearchGameTypeByIndex(lua_State* tolua_S)
{
    int argc = 0;
    CServerListData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerListData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerListData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CServerListData_SearchGameTypeByIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "CServerListData:SearchGameTypeByIndex");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CServerListData_SearchGameTypeByIndex'", nullptr);
            return 0;
        }
        CGameTypeItem* ret = cobj->SearchGameTypeByIndex(arg0);
        object_to_luaval<CGameTypeItem>(tolua_S, "CGameTypeItem",(CGameTypeItem*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerListData:SearchGameTypeByIndex",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CServerListData_SearchGameTypeByIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CServerListData_InsertGameNode(lua_State* tolua_S)
{
    int argc = 0;
    CServerListData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerListData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerListData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CServerListData_InsertGameNode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const cocos2d::Ref* arg0;

        ok &= luaval_to_object<const cocos2d::Ref>(tolua_S, 2, "cc.Ref",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CServerListData_InsertGameNode'", nullptr);
            return 0;
        }
        bool ret = cobj->InsertGameNode(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerListData:InsertGameNode",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CServerListData_InsertGameNode'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CServerListData_GetGameServerCount(lua_State* tolua_S)
{
    int argc = 0;
    CServerListData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerListData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerListData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CServerListData_GetGameServerCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CServerListData_GetGameServerCount'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->GetGameServerCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerListData:GetGameServerCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CServerListData_GetGameServerCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CServerListData_SetServerOnLineCount(lua_State* tolua_S)
{
    int argc = 0;
    CServerListData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerListData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerListData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CServerListData_SetServerOnLineCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        unsigned short arg0;
        unsigned int arg1;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CServerListData:SetServerOnLineCount");

        ok &= luaval_to_uint32(tolua_S, 3,&arg1, "CServerListData:SetServerOnLineCount");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CServerListData_SetServerOnLineCount'", nullptr);
            return 0;
        }
        cobj->SetServerOnLineCount(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerListData:SetServerOnLineCount",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CServerListData_SetServerOnLineCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CServerListData_ClearGameNode(lua_State* tolua_S)
{
    int argc = 0;
    CServerListData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerListData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerListData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CServerListData_ClearGameNode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CServerListData_ClearGameNode'", nullptr);
            return 0;
        }
        bool ret = cobj->ClearGameNode();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerListData:ClearGameNode",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CServerListData_ClearGameNode'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CServerListData_OnGameItemDelete(lua_State* tolua_S)
{
    int argc = 0;
    CServerListData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerListData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerListData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CServerListData_OnGameItemDelete'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        CGameListItem* arg0;

        ok &= luaval_to_object<CGameListItem>(tolua_S, 2, "CGameListItem",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CServerListData_OnGameItemDelete'", nullptr);
            return 0;
        }
        cobj->OnGameItemDelete(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerListData:OnGameItemDelete",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CServerListData_OnGameItemDelete'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CServerListData_DeleteGamePage(lua_State* tolua_S)
{
    int argc = 0;
    CServerListData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerListData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerListData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CServerListData_DeleteGamePage'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CServerListData:DeleteGamePage");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CServerListData_DeleteGamePage'", nullptr);
            return 0;
        }
        bool ret = cobj->DeleteGamePage(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerListData:DeleteGamePage",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CServerListData_DeleteGamePage'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CServerListData_DeleteGameKind(lua_State* tolua_S)
{
    int argc = 0;
    CServerListData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerListData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerListData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CServerListData_DeleteGameKind'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CServerListData:DeleteGameKind");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CServerListData_DeleteGameKind'", nullptr);
            return 0;
        }
        bool ret = cobj->DeleteGameKind(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerListData:DeleteGameKind",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CServerListData_DeleteGameKind'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CServerListData_GetGamePageCount(lua_State* tolua_S)
{
    int argc = 0;
    CServerListData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerListData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerListData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CServerListData_GetGamePageCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CServerListData_GetGamePageCount'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->GetGamePageCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerListData:GetGamePageCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CServerListData_GetGamePageCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CServerListData_SearchGamePage(lua_State* tolua_S)
{
    int argc = 0;
    CServerListData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerListData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerListData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CServerListData_SearchGamePage'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CServerListData:SearchGamePage");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CServerListData_SearchGamePage'", nullptr);
            return 0;
        }
        CGamePageItem* ret = cobj->SearchGamePage(arg0);
        object_to_luaval<CGamePageItem>(tolua_S, "CGamePageItem",(CGamePageItem*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerListData:SearchGamePage",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CServerListData_SearchGamePage'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CServerListData_SearchGameNode(lua_State* tolua_S)
{
    int argc = 0;
    CServerListData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerListData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerListData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CServerListData_SearchGameNode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CServerListData:SearchGameNode");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CServerListData_SearchGameNode'", nullptr);
            return 0;
        }
        CGameNodeItem* ret = cobj->SearchGameNode(arg0);
        object_to_luaval<CGameNodeItem>(tolua_S, "CGameNodeItem",(CGameNodeItem*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerListData:SearchGameNode",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CServerListData_SearchGameNode'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CServerListData_InsertGameType(lua_State* tolua_S)
{
    int argc = 0;
    CServerListData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerListData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerListData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CServerListData_InsertGameType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const cocos2d::Ref* arg0;

        ok &= luaval_to_object<const cocos2d::Ref>(tolua_S, 2, "cc.Ref",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CServerListData_InsertGameType'", nullptr);
            return 0;
        }
        bool ret = cobj->InsertGameType(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerListData:InsertGameType",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CServerListData_InsertGameType'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CServerListData_InsertGamePage(lua_State* tolua_S)
{
    int argc = 0;
    CServerListData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerListData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerListData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CServerListData_InsertGamePage'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const cocos2d::Ref* arg0;

        ok &= luaval_to_object<const cocos2d::Ref>(tolua_S, 2, "cc.Ref",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CServerListData_InsertGamePage'", nullptr);
            return 0;
        }
        bool ret = cobj->InsertGamePage(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerListData:InsertGamePage",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CServerListData_InsertGamePage'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CServerListData_OnGameItemUpdateFinish(lua_State* tolua_S)
{
    int argc = 0;
    CServerListData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerListData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerListData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CServerListData_OnGameItemUpdateFinish'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CServerListData_OnGameItemUpdateFinish'", nullptr);
            return 0;
        }
        cobj->OnGameItemUpdateFinish();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerListData:OnGameItemUpdateFinish",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CServerListData_OnGameItemUpdateFinish'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CServerListData_InsertGameKind(lua_State* tolua_S)
{
    int argc = 0;
    CServerListData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerListData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerListData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CServerListData_InsertGameKind'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const cocos2d::Ref* arg0;

        ok &= luaval_to_object<const cocos2d::Ref>(tolua_S, 2, "cc.Ref",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CServerListData_InsertGameKind'", nullptr);
            return 0;
        }
        bool ret = cobj->InsertGameKind(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerListData:InsertGameKind",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CServerListData_InsertGameKind'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CServerListData_GetGameNodeCount(lua_State* tolua_S)
{
    int argc = 0;
    CServerListData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerListData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerListData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CServerListData_GetGameNodeCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CServerListData_GetGameNodeCount'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->GetGameNodeCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerListData:GetGameNodeCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CServerListData_GetGameNodeCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CServerListData_SetKindOnLineCount(lua_State* tolua_S)
{
    int argc = 0;
    CServerListData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerListData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerListData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CServerListData_SetKindOnLineCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        unsigned short arg0;
        unsigned int arg1;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CServerListData:SetKindOnLineCount");

        ok &= luaval_to_uint32(tolua_S, 3,&arg1, "CServerListData:SetKindOnLineCount");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CServerListData_SetKindOnLineCount'", nullptr);
            return 0;
        }
        cobj->SetKindOnLineCount(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerListData:SetKindOnLineCount",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CServerListData_SetKindOnLineCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CServerListData_SetServerOnLineFinish(lua_State* tolua_S)
{
    int argc = 0;
    CServerListData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerListData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerListData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CServerListData_SetServerOnLineFinish'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CServerListData_SetServerOnLineFinish'", nullptr);
            return 0;
        }
        cobj->SetServerOnLineFinish();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerListData:SetServerOnLineFinish",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CServerListData_SetServerOnLineFinish'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CServerListData_SearchGamePageByIndex(lua_State* tolua_S)
{
    int argc = 0;
    CServerListData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerListData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerListData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CServerListData_SearchGamePageByIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "CServerListData:SearchGamePageByIndex");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CServerListData_SearchGamePageByIndex'", nullptr);
            return 0;
        }
        CGamePageItem* ret = cobj->SearchGamePageByIndex(arg0);
        object_to_luaval<CGamePageItem>(tolua_S, "CGamePageItem",(CGamePageItem*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerListData:SearchGamePageByIndex",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CServerListData_SearchGamePageByIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CServerListData_SearchGameServerByIndex(lua_State* tolua_S)
{
    int argc = 0;
    CServerListData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerListData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerListData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CServerListData_SearchGameServerByIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "CServerListData:SearchGameServerByIndex");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CServerListData_SearchGameServerByIndex'", nullptr);
            return 0;
        }
        CGameServerItem* ret = cobj->SearchGameServerByIndex(arg0);
        object_to_luaval<CGameServerItem>(tolua_S, "CGameServerItem",(CGameServerItem*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerListData:SearchGameServerByIndex",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CServerListData_SearchGameServerByIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CServerListData_DeleteGameNode(lua_State* tolua_S)
{
    int argc = 0;
    CServerListData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerListData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerListData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CServerListData_DeleteGameNode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CServerListData:DeleteGameNode");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CServerListData_DeleteGameNode'", nullptr);
            return 0;
        }
        bool ret = cobj->DeleteGameNode(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerListData:DeleteGameNode",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CServerListData_DeleteGameNode'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CServerListData_OnGameItemUpdate(lua_State* tolua_S)
{
    int argc = 0;
    CServerListData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerListData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerListData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CServerListData_OnGameItemUpdate'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        CGameListItem* arg0;

        ok &= luaval_to_object<CGameListItem>(tolua_S, 2, "CGameListItem",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CServerListData_OnGameItemUpdate'", nullptr);
            return 0;
        }
        cobj->OnGameItemUpdate(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerListData:OnGameItemUpdate",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CServerListData_OnGameItemUpdate'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CServerListData_InsertGameMatch(lua_State* tolua_S)
{
    int argc = 0;
    CServerListData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CServerListData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CServerListData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CServerListData_InsertGameMatch'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const cocos2d::Ref* arg0;

        ok &= luaval_to_object<const cocos2d::Ref>(tolua_S, 2, "cc.Ref",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CServerListData_InsertGameMatch'", nullptr);
            return 0;
        }
        bool ret = cobj->InsertGameMatch(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CServerListData:InsertGameMatch",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CServerListData_InsertGameMatch'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CServerListData_purge(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CServerListData",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CServerListData_purge'", nullptr);
            return 0;
        }
        CServerListData::purge();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CServerListData:purge",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CServerListData_purge'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_platform_CServerListData_shared(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CServerListData",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CServerListData_shared'", nullptr);
            return 0;
        }
        CServerListData* ret = CServerListData::shared();
        object_to_luaval<CServerListData>(tolua_S, "CServerListData",(CServerListData*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CServerListData:shared",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CServerListData_shared'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_platform_CServerListData_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CServerListData)");
    return 0;
}

int lua_register_cocos2dx_platform_CServerListData(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CServerListData");
    tolua_cclass(tolua_S,"CServerListData","CServerListData","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"CServerListData");
        tolua_function(tolua_S,"ClearGameType",lua_cocos2dx_platform_CServerListData_ClearGameType);
        tolua_function(tolua_S,"InsertGameServer",lua_cocos2dx_platform_CServerListData_InsertGameServer);
        tolua_function(tolua_S,"DeleteGameType",lua_cocos2dx_platform_CServerListData_DeleteGameType);
        tolua_function(tolua_S,"SearchGameKind",lua_cocos2dx_platform_CServerListData_SearchGameKind);
        tolua_function(tolua_S,"GetGameTypeCount",lua_cocos2dx_platform_CServerListData_GetGameTypeCount);
        tolua_function(tolua_S,"GetGameKindCount",lua_cocos2dx_platform_CServerListData_GetGameKindCount);
        tolua_function(tolua_S,"SearchGameNodeByIndex",lua_cocos2dx_platform_CServerListData_SearchGameNodeByIndex);
        tolua_function(tolua_S,"GetAllOnLineCount",lua_cocos2dx_platform_CServerListData_GetAllOnLineCount);
        tolua_function(tolua_S,"ClearGameKind",lua_cocos2dx_platform_CServerListData_ClearGameKind);
        tolua_function(tolua_S,"OnGameItemInsert",lua_cocos2dx_platform_CServerListData_OnGameItemInsert);
        tolua_function(tolua_S,"SearchGameType",lua_cocos2dx_platform_CServerListData_SearchGameType);
        tolua_function(tolua_S,"DeleteGameServer",lua_cocos2dx_platform_CServerListData_DeleteGameServer);
        tolua_function(tolua_S,"ClearGamePage",lua_cocos2dx_platform_CServerListData_ClearGamePage);
        tolua_function(tolua_S,"ClearGameServer",lua_cocos2dx_platform_CServerListData_ClearGameServer);
        tolua_function(tolua_S,"SearchGameServer",lua_cocos2dx_platform_CServerListData_SearchGameServer);
        tolua_function(tolua_S,"SearchGameKindByIndex",lua_cocos2dx_platform_CServerListData_SearchGameKindByIndex);
        tolua_function(tolua_S,"OnGameKindFinish",lua_cocos2dx_platform_CServerListData_OnGameKindFinish);
        tolua_function(tolua_S,"OnGameItemFinish",lua_cocos2dx_platform_CServerListData_OnGameItemFinish);
        tolua_function(tolua_S,"SearchGameTypeByIndex",lua_cocos2dx_platform_CServerListData_SearchGameTypeByIndex);
        tolua_function(tolua_S,"InsertGameNode",lua_cocos2dx_platform_CServerListData_InsertGameNode);
        tolua_function(tolua_S,"GetGameServerCount",lua_cocos2dx_platform_CServerListData_GetGameServerCount);
        tolua_function(tolua_S,"SetServerOnLineCount",lua_cocos2dx_platform_CServerListData_SetServerOnLineCount);
        tolua_function(tolua_S,"ClearGameNode",lua_cocos2dx_platform_CServerListData_ClearGameNode);
        tolua_function(tolua_S,"OnGameItemDelete",lua_cocos2dx_platform_CServerListData_OnGameItemDelete);
        tolua_function(tolua_S,"DeleteGamePage",lua_cocos2dx_platform_CServerListData_DeleteGamePage);
        tolua_function(tolua_S,"DeleteGameKind",lua_cocos2dx_platform_CServerListData_DeleteGameKind);
        tolua_function(tolua_S,"GetGamePageCount",lua_cocos2dx_platform_CServerListData_GetGamePageCount);
        tolua_function(tolua_S,"SearchGamePage",lua_cocos2dx_platform_CServerListData_SearchGamePage);
        tolua_function(tolua_S,"SearchGameNode",lua_cocos2dx_platform_CServerListData_SearchGameNode);
        tolua_function(tolua_S,"InsertGameType",lua_cocos2dx_platform_CServerListData_InsertGameType);
        tolua_function(tolua_S,"InsertGamePage",lua_cocos2dx_platform_CServerListData_InsertGamePage);
        tolua_function(tolua_S,"OnGameItemUpdateFinish",lua_cocos2dx_platform_CServerListData_OnGameItemUpdateFinish);
        tolua_function(tolua_S,"InsertGameKind",lua_cocos2dx_platform_CServerListData_InsertGameKind);
        tolua_function(tolua_S,"GetGameNodeCount",lua_cocos2dx_platform_CServerListData_GetGameNodeCount);
        tolua_function(tolua_S,"SetKindOnLineCount",lua_cocos2dx_platform_CServerListData_SetKindOnLineCount);
        tolua_function(tolua_S,"SetServerOnLineFinish",lua_cocos2dx_platform_CServerListData_SetServerOnLineFinish);
        tolua_function(tolua_S,"SearchGamePageByIndex",lua_cocos2dx_platform_CServerListData_SearchGamePageByIndex);
        tolua_function(tolua_S,"SearchGameServerByIndex",lua_cocos2dx_platform_CServerListData_SearchGameServerByIndex);
        tolua_function(tolua_S,"DeleteGameNode",lua_cocos2dx_platform_CServerListData_DeleteGameNode);
        tolua_function(tolua_S,"OnGameItemUpdate",lua_cocos2dx_platform_CServerListData_OnGameItemUpdate);
        tolua_function(tolua_S,"InsertGameMatch",lua_cocos2dx_platform_CServerListData_InsertGameMatch);
        tolua_function(tolua_S,"purge", lua_cocos2dx_platform_CServerListData_purge);
        tolua_function(tolua_S,"shared", lua_cocos2dx_platform_CServerListData_shared);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CServerListData).name();
    g_luaType[typeName] = "CServerListData";
    g_typeCast["CServerListData"] = "CServerListData";
    return 1;
}

int lua_cocos2dx_platform_CParameterGame_DefaultParameter(lua_State* tolua_S)
{
    int argc = 0;
    CParameterGame* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CParameterGame",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CParameterGame*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CParameterGame_DefaultParameter'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CParameterGame_DefaultParameter'", nullptr);
            return 0;
        }
        cobj->DefaultParameter();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CParameterGame:DefaultParameter",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CParameterGame_DefaultParameter'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CParameterGame_LoadParameter(lua_State* tolua_S)
{
    int argc = 0;
    CParameterGame* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CParameterGame",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CParameterGame*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CParameterGame_LoadParameter'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CParameterGame_LoadParameter'", nullptr);
            return 0;
        }
        cobj->LoadParameter();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CParameterGame:LoadParameter",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CParameterGame_LoadParameter'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CParameterGame_SaveParameter(lua_State* tolua_S)
{
    int argc = 0;
    CParameterGame* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CParameterGame",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CParameterGame*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CParameterGame_SaveParameter'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CParameterGame_SaveParameter'", nullptr);
            return 0;
        }
        cobj->SaveParameter();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CParameterGame:SaveParameter",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CParameterGame_SaveParameter'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CParameterGame_constructor(lua_State* tolua_S)
{
    int argc = 0;
    CParameterGame* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CParameterGame_constructor'", nullptr);
            return 0;
        }
        cobj = new CParameterGame();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"CParameterGame");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CParameterGame:CParameterGame",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CParameterGame_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_platform_CParameterGame_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CParameterGame)");
    return 0;
}

int lua_register_cocos2dx_platform_CParameterGame(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CParameterGame");
    tolua_cclass(tolua_S,"CParameterGame","CParameterGame","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"CParameterGame");
        tolua_function(tolua_S,"new",lua_cocos2dx_platform_CParameterGame_constructor);
        tolua_function(tolua_S,"DefaultParameter",lua_cocos2dx_platform_CParameterGame_DefaultParameter);
        tolua_function(tolua_S,"LoadParameter",lua_cocos2dx_platform_CParameterGame_LoadParameter);
        tolua_function(tolua_S,"SaveParameter",lua_cocos2dx_platform_CParameterGame_SaveParameter);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CParameterGame).name();
    g_luaType[typeName] = "CParameterGame";
    g_typeCast["CParameterGame"] = "CParameterGame";
    return 1;
}

int lua_cocos2dx_platform_CParameterServer_DefaultParameter(lua_State* tolua_S)
{
    int argc = 0;
    CParameterServer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CParameterServer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CParameterServer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CParameterServer_DefaultParameter'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CParameterServer_DefaultParameter'", nullptr);
            return 0;
        }
        cobj->DefaultParameter();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CParameterServer:DefaultParameter",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CParameterServer_DefaultParameter'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CParameterServer_GetParameterPassword(lua_State* tolua_S)
{
    int argc = 0;
    CParameterServer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CParameterServer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CParameterServer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CParameterServer_GetParameterPassword'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CParameterServer_GetParameterPassword'", nullptr);
            return 0;
        }
        char* ret = cobj->GetParameterPassword();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CParameterServer:GetParameterPassword",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CParameterServer_GetParameterPassword'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CParameterServer_constructor(lua_State* tolua_S)
{
    int argc = 0;
    CParameterServer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CParameterServer_constructor'", nullptr);
            return 0;
        }
        cobj = new CParameterServer();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"CParameterServer");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CParameterServer:CParameterServer",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CParameterServer_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_platform_CParameterServer_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CParameterServer)");
    return 0;
}

int lua_register_cocos2dx_platform_CParameterServer(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CParameterServer");
    tolua_cclass(tolua_S,"CParameterServer","CParameterServer","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"CParameterServer");
        tolua_function(tolua_S,"new",lua_cocos2dx_platform_CParameterServer_constructor);
        tolua_function(tolua_S,"DefaultParameter",lua_cocos2dx_platform_CParameterServer_DefaultParameter);
        tolua_function(tolua_S,"GetParameterPassword",lua_cocos2dx_platform_CParameterServer_GetParameterPassword);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CParameterServer).name();
    g_luaType[typeName] = "CParameterServer";
    g_typeCast["CParameterServer"] = "CParameterServer";
    return 1;
}

int lua_cocos2dx_platform_CParameterGlobal_GetParameterServer(lua_State* tolua_S)
{
    int argc = 0;
    CParameterGlobal* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CParameterGlobal",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CParameterGlobal*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CParameterGlobal_GetParameterServer'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        tagGameServer* arg0;

        ok &= luaval_to_object<tagGameServer>(tolua_S, 2, "tagGameServer",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CParameterGlobal_GetParameterServer'", nullptr);
            return 0;
        }
        CParameterServer* ret = cobj->GetParameterServer(arg0);
        object_to_luaval<CParameterServer>(tolua_S, "CParameterServer",(CParameterServer*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CParameterGlobal:GetParameterServer",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CParameterGlobal_GetParameterServer'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CParameterGlobal_GetParameterGame(lua_State* tolua_S)
{
    int argc = 0;
    CParameterGlobal* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CParameterGlobal",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CParameterGlobal*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CParameterGlobal_GetParameterGame'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        tagGameKind* arg0;

        ok &= luaval_to_object<tagGameKind>(tolua_S, 2, "tagGameKind",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CParameterGlobal_GetParameterGame'", nullptr);
            return 0;
        }
        CParameterGame* ret = cobj->GetParameterGame(arg0);
        object_to_luaval<CParameterGame>(tolua_S, "CParameterGame",(CParameterGame*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CParameterGlobal:GetParameterGame",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CParameterGlobal_GetParameterGame'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CParameterGlobal_LoadParameter(lua_State* tolua_S)
{
    int argc = 0;
    CParameterGlobal* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CParameterGlobal",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CParameterGlobal*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CParameterGlobal_LoadParameter'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CParameterGlobal_LoadParameter'", nullptr);
            return 0;
        }
        cobj->LoadParameter();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CParameterGlobal:LoadParameter",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CParameterGlobal_LoadParameter'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CParameterGlobal_SaveParameter(lua_State* tolua_S)
{
    int argc = 0;
    CParameterGlobal* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CParameterGlobal",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CParameterGlobal*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CParameterGlobal_SaveParameter'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CParameterGlobal_SaveParameter'", nullptr);
            return 0;
        }
        cobj->SaveParameter();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CParameterGlobal:SaveParameter",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CParameterGlobal_SaveParameter'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CParameterGlobal_DefaultParameter(lua_State* tolua_S)
{
    int argc = 0;
    CParameterGlobal* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CParameterGlobal",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CParameterGlobal*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CParameterGlobal_DefaultParameter'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CParameterGlobal_DefaultParameter'", nullptr);
            return 0;
        }
        cobj->DefaultParameter();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CParameterGlobal:DefaultParameter",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CParameterGlobal_DefaultParameter'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CParameterGlobal_purge(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CParameterGlobal",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CParameterGlobal_purge'", nullptr);
            return 0;
        }
        CParameterGlobal::purge();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CParameterGlobal:purge",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CParameterGlobal_purge'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_platform_CParameterGlobal_shared(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CParameterGlobal",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CParameterGlobal_shared'", nullptr);
            return 0;
        }
        CParameterGlobal* ret = CParameterGlobal::shared();
        object_to_luaval<CParameterGlobal>(tolua_S, "CParameterGlobal",(CParameterGlobal*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CParameterGlobal:shared",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CParameterGlobal_shared'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_platform_CParameterGlobal_constructor(lua_State* tolua_S)
{
    int argc = 0;
    CParameterGlobal* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CParameterGlobal_constructor'", nullptr);
            return 0;
        }
        cobj = new CParameterGlobal();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"CParameterGlobal");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CParameterGlobal:CParameterGlobal",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CParameterGlobal_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_platform_CParameterGlobal_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CParameterGlobal)");
    return 0;
}

int lua_register_cocos2dx_platform_CParameterGlobal(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CParameterGlobal");
    tolua_cclass(tolua_S,"CParameterGlobal","CParameterGlobal","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"CParameterGlobal");
        tolua_function(tolua_S,"new",lua_cocos2dx_platform_CParameterGlobal_constructor);
        tolua_function(tolua_S,"GetParameterServer",lua_cocos2dx_platform_CParameterGlobal_GetParameterServer);
        tolua_function(tolua_S,"GetParameterGame",lua_cocos2dx_platform_CParameterGlobal_GetParameterGame);
        tolua_function(tolua_S,"LoadParameter",lua_cocos2dx_platform_CParameterGlobal_LoadParameter);
        tolua_function(tolua_S,"SaveParameter",lua_cocos2dx_platform_CParameterGlobal_SaveParameter);
        tolua_function(tolua_S,"DefaultParameter",lua_cocos2dx_platform_CParameterGlobal_DefaultParameter);
        tolua_function(tolua_S,"purge", lua_cocos2dx_platform_CParameterGlobal_purge);
        tolua_function(tolua_S,"shared", lua_cocos2dx_platform_CParameterGlobal_shared);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CParameterGlobal).name();
    g_luaType[typeName] = "CParameterGlobal";
    g_typeCast["CParameterGlobal"] = "CParameterGlobal";
    return 1;
}

int lua_cocos2dx_platform_CMD_GR_C_TableTalk_getChairID(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_C_TableTalk* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_C_TableTalk",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_GR_C_TableTalk*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CMD_GR_C_TableTalk_getChairID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CMD_GR_C_TableTalk_getChairID'", nullptr);
            return 0;
        }
        uint16_t ret = cobj->getChairID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_GR_C_TableTalk:getChairID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CMD_GR_C_TableTalk_getChairID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CMD_GR_C_TableTalk_getString(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_C_TableTalk* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_C_TableTalk",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_GR_C_TableTalk*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CMD_GR_C_TableTalk_getString'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CMD_GR_C_TableTalk_getString'", nullptr);
            return 0;
        }
        const char* ret = cobj->getString();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_GR_C_TableTalk:getString",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CMD_GR_C_TableTalk_getString'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CMD_GR_C_TableTalk_setString(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_C_TableTalk* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_C_TableTalk",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_GR_C_TableTalk*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CMD_GR_C_TableTalk_setString'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        int arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CMD_GR_C_TableTalk:setString"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "CMD_GR_C_TableTalk:setString");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CMD_GR_C_TableTalk_setString'", nullptr);
            return 0;
        }
        cobj->setString(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_GR_C_TableTalk:setString",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CMD_GR_C_TableTalk_setString'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CMD_GR_C_TableTalk_getType(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_C_TableTalk* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_C_TableTalk",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_GR_C_TableTalk*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CMD_GR_C_TableTalk_getType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CMD_GR_C_TableTalk_getType'", nullptr);
            return 0;
        }
        uint16_t ret = cobj->getType();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_GR_C_TableTalk:getType",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CMD_GR_C_TableTalk_getType'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CMD_GR_C_TableTalk_setTalkSize(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_C_TableTalk* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_C_TableTalk",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_GR_C_TableTalk*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CMD_GR_C_TableTalk_setTalkSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "CMD_GR_C_TableTalk:setTalkSize");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CMD_GR_C_TableTalk_setTalkSize'", nullptr);
            return 0;
        }
        cobj->setTalkSize(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_GR_C_TableTalk:setTalkSize",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CMD_GR_C_TableTalk_setTalkSize'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CMD_GR_C_TableTalk_setTalkData(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_C_TableTalk* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_C_TableTalk",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_GR_C_TableTalk*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CMD_GR_C_TableTalk_setTalkData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        int arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CMD_GR_C_TableTalk:setTalkData"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "CMD_GR_C_TableTalk:setTalkData");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CMD_GR_C_TableTalk_setTalkData'", nullptr);
            return 0;
        }
        cobj->setTalkData(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_GR_C_TableTalk:setTalkData",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CMD_GR_C_TableTalk_setTalkData'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CMD_GR_C_TableTalk_setChairID(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_C_TableTalk* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_C_TableTalk",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_GR_C_TableTalk*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CMD_GR_C_TableTalk_setChairID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        uint16_t arg0;

        ok &= luaval_to_uint16(tolua_S, 2,&arg0, "CMD_GR_C_TableTalk:setChairID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CMD_GR_C_TableTalk_setChairID'", nullptr);
            return 0;
        }
        cobj->setChairID(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_GR_C_TableTalk:setChairID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CMD_GR_C_TableTalk_setChairID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CMD_GR_C_TableTalk_getTalkData(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_C_TableTalk* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_C_TableTalk",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_GR_C_TableTalk*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CMD_GR_C_TableTalk_getTalkData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CMD_GR_C_TableTalk_getTalkData'", nullptr);
            return 0;
        }
        const char* ret = cobj->getTalkData();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_GR_C_TableTalk:getTalkData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CMD_GR_C_TableTalk_getTalkData'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CMD_GR_C_TableTalk_getTalkSize(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_C_TableTalk* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_C_TableTalk",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_GR_C_TableTalk*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CMD_GR_C_TableTalk_getTalkSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CMD_GR_C_TableTalk_getTalkSize'", nullptr);
            return 0;
        }
        int ret = cobj->getTalkSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_GR_C_TableTalk:getTalkSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CMD_GR_C_TableTalk_getTalkSize'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CMD_GR_C_TableTalk_setType(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_C_TableTalk* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_C_TableTalk",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_GR_C_TableTalk*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CMD_GR_C_TableTalk_setType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        uint16_t arg0;

        ok &= luaval_to_uint16(tolua_S, 2,&arg0, "CMD_GR_C_TableTalk:setType");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CMD_GR_C_TableTalk_setType'", nullptr);
            return 0;
        }
        cobj->setType(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_GR_C_TableTalk:setType",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CMD_GR_C_TableTalk_setType'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CMD_GR_C_TableTalk_constructor(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_C_TableTalk* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CMD_GR_C_TableTalk_constructor'", nullptr);
            return 0;
        }
        cobj = new CMD_GR_C_TableTalk();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"CMD_GR_C_TableTalk");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_GR_C_TableTalk:CMD_GR_C_TableTalk",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CMD_GR_C_TableTalk_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_platform_CMD_GR_C_TableTalk_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CMD_GR_C_TableTalk)");
    return 0;
}

int lua_register_cocos2dx_platform_CMD_GR_C_TableTalk(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CMD_GR_C_TableTalk");
    tolua_cclass(tolua_S,"CMD_GR_C_TableTalk","CMD_GR_C_TableTalk","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"CMD_GR_C_TableTalk");
        tolua_function(tolua_S,"new",lua_cocos2dx_platform_CMD_GR_C_TableTalk_constructor);
        tolua_function(tolua_S,"getChairID",lua_cocos2dx_platform_CMD_GR_C_TableTalk_getChairID);
        tolua_function(tolua_S,"getString",lua_cocos2dx_platform_CMD_GR_C_TableTalk_getString);
        tolua_function(tolua_S,"setString",lua_cocos2dx_platform_CMD_GR_C_TableTalk_setString);
        tolua_function(tolua_S,"getType",lua_cocos2dx_platform_CMD_GR_C_TableTalk_getType);
        tolua_function(tolua_S,"setTalkSize",lua_cocos2dx_platform_CMD_GR_C_TableTalk_setTalkSize);
        tolua_function(tolua_S,"setTalkData",lua_cocos2dx_platform_CMD_GR_C_TableTalk_setTalkData);
        tolua_function(tolua_S,"setChairID",lua_cocos2dx_platform_CMD_GR_C_TableTalk_setChairID);
        tolua_function(tolua_S,"getTalkData",lua_cocos2dx_platform_CMD_GR_C_TableTalk_getTalkData);
        tolua_function(tolua_S,"getTalkSize",lua_cocos2dx_platform_CMD_GR_C_TableTalk_getTalkSize);
        tolua_function(tolua_S,"setType",lua_cocos2dx_platform_CMD_GR_C_TableTalk_setType);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CMD_GR_C_TableTalk).name();
    g_luaType[typeName] = "CMD_GR_C_TableTalk";
    g_typeCast["CMD_GR_C_TableTalk"] = "CMD_GR_C_TableTalk";
    return 1;
}

int lua_cocos2dx_platform_CPlatformGameConfig_loadConfig(lua_State* tolua_S)
{
    int argc = 0;
    CPlatformGameConfig* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CPlatformGameConfig",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CPlatformGameConfig*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CPlatformGameConfig_loadConfig'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CPlatformGameConfig_loadConfig'", nullptr);
            return 0;
        }
        cobj->loadConfig();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CPlatformGameConfig:loadConfig",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CPlatformGameConfig_loadConfig'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CPlatformGameConfig_getValue(lua_State* tolua_S)
{
    int argc = 0;
    CPlatformGameConfig* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CPlatformGameConfig",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CPlatformGameConfig*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_CPlatformGameConfig_getValue'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        int arg0;
        const char* arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "CPlatformGameConfig:getValue");

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "CPlatformGameConfig:getValue"); arg1 = arg1_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CPlatformGameConfig_getValue'", nullptr);
            return 0;
        }
        std::string ret = cobj->getValue(arg0, arg1);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CPlatformGameConfig:getValue",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CPlatformGameConfig_getValue'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_CPlatformGameConfig_purge(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CPlatformGameConfig",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CPlatformGameConfig_purge'", nullptr);
            return 0;
        }
        CPlatformGameConfig::purge();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CPlatformGameConfig:purge",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CPlatformGameConfig_purge'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_platform_CPlatformGameConfig_shared(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CPlatformGameConfig",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_CPlatformGameConfig_shared'", nullptr);
            return 0;
        }
        CPlatformGameConfig* ret = CPlatformGameConfig::shared();
        object_to_luaval<CPlatformGameConfig>(tolua_S, "CPlatformGameConfig",(CPlatformGameConfig*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CPlatformGameConfig:shared",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_CPlatformGameConfig_shared'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_platform_CPlatformGameConfig_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CPlatformGameConfig)");
    return 0;
}

int lua_register_cocos2dx_platform_CPlatformGameConfig(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CPlatformGameConfig");
    tolua_cclass(tolua_S,"CPlatformGameConfig","CPlatformGameConfig","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"CPlatformGameConfig");
        tolua_function(tolua_S,"loadConfig",lua_cocos2dx_platform_CPlatformGameConfig_loadConfig);
        tolua_function(tolua_S,"getValue",lua_cocos2dx_platform_CPlatformGameConfig_getValue);
        tolua_function(tolua_S,"purge", lua_cocos2dx_platform_CPlatformGameConfig_purge);
        tolua_function(tolua_S,"shared", lua_cocos2dx_platform_CPlatformGameConfig_shared);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CPlatformGameConfig).name();
    g_luaType[typeName] = "CPlatformGameConfig";
    g_typeCast["CPlatformGameConfig"] = "CPlatformGameConfig";
    return 1;
}

int lua_cocos2dx_platform_MultiPlatformMgr_switchVibratorState(lua_State* tolua_S)
{
    int argc = 0;
    MultiPlatformMgr* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MultiPlatformMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MultiPlatformMgr*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_MultiPlatformMgr_switchVibratorState'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "MultiPlatformMgr:switchVibratorState");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_MultiPlatformMgr_switchVibratorState'", nullptr);
            return 0;
        }
        cobj->switchVibratorState(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MultiPlatformMgr:switchVibratorState",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_MultiPlatformMgr_switchVibratorState'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_MultiPlatformMgr_obtainNetWorkState(lua_State* tolua_S)
{
    int argc = 0;
    MultiPlatformMgr* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MultiPlatformMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MultiPlatformMgr*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_MultiPlatformMgr_obtainNetWorkState'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_MultiPlatformMgr_obtainNetWorkState'", nullptr);
            return 0;
        }
        bool ret = cobj->obtainNetWorkState();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MultiPlatformMgr:obtainNetWorkState",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_MultiPlatformMgr_obtainNetWorkState'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_MultiPlatformMgr_setPlatformDelegate(lua_State* tolua_S)
{
    int argc = 0;
    MultiPlatformMgr* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MultiPlatformMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MultiPlatformMgr*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_MultiPlatformMgr_setPlatformDelegate'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        MultiPlatformMgrDelegate* arg0;

        ok &= luaval_to_object<MultiPlatformMgrDelegate>(tolua_S, 2, "MultiPlatformMgrDelegate",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_MultiPlatformMgr_setPlatformDelegate'", nullptr);
            return 0;
        }
        cobj->setPlatformDelegate(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MultiPlatformMgr:setPlatformDelegate",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_MultiPlatformMgr_setPlatformDelegate'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_MultiPlatformMgr_OpenShare(lua_State* tolua_S)
{
    int argc = 0;
    MultiPlatformMgr* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MultiPlatformMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MultiPlatformMgr*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_MultiPlatformMgr_OpenShare'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 7) 
    {
        std::vector<int> arg0;
        const char* arg1;
        const char* arg2;
        const char* arg3;
        const char* arg4;
        const char* arg5;
        const char* arg6;

        ok &= luaval_to_std_vector_int(tolua_S, 2, &arg0, "MultiPlatformMgr:OpenShare");

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "MultiPlatformMgr:OpenShare"); arg1 = arg1_tmp.c_str();

        std::string arg2_tmp; ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp, "MultiPlatformMgr:OpenShare"); arg2 = arg2_tmp.c_str();

        std::string arg3_tmp; ok &= luaval_to_std_string(tolua_S, 5, &arg3_tmp, "MultiPlatformMgr:OpenShare"); arg3 = arg3_tmp.c_str();

        std::string arg4_tmp; ok &= luaval_to_std_string(tolua_S, 6, &arg4_tmp, "MultiPlatformMgr:OpenShare"); arg4 = arg4_tmp.c_str();

        std::string arg5_tmp; ok &= luaval_to_std_string(tolua_S, 7, &arg5_tmp, "MultiPlatformMgr:OpenShare"); arg5 = arg5_tmp.c_str();

        std::string arg6_tmp; ok &= luaval_to_std_string(tolua_S, 8, &arg6_tmp, "MultiPlatformMgr:OpenShare"); arg6 = arg6_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_MultiPlatformMgr_OpenShare'", nullptr);
            return 0;
        }
        cobj->OpenShare(arg0, arg1, arg2, arg3, arg4, arg5, arg6);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 8) 
    {
        std::vector<int> arg0;
        const char* arg1;
        const char* arg2;
        const char* arg3;
        const char* arg4;
        const char* arg5;
        const char* arg6;
        bool arg7;

        ok &= luaval_to_std_vector_int(tolua_S, 2, &arg0, "MultiPlatformMgr:OpenShare");

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "MultiPlatformMgr:OpenShare"); arg1 = arg1_tmp.c_str();

        std::string arg2_tmp; ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp, "MultiPlatformMgr:OpenShare"); arg2 = arg2_tmp.c_str();

        std::string arg3_tmp; ok &= luaval_to_std_string(tolua_S, 5, &arg3_tmp, "MultiPlatformMgr:OpenShare"); arg3 = arg3_tmp.c_str();

        std::string arg4_tmp; ok &= luaval_to_std_string(tolua_S, 6, &arg4_tmp, "MultiPlatformMgr:OpenShare"); arg4 = arg4_tmp.c_str();

        std::string arg5_tmp; ok &= luaval_to_std_string(tolua_S, 7, &arg5_tmp, "MultiPlatformMgr:OpenShare"); arg5 = arg5_tmp.c_str();

        std::string arg6_tmp; ok &= luaval_to_std_string(tolua_S, 8, &arg6_tmp, "MultiPlatformMgr:OpenShare"); arg6 = arg6_tmp.c_str();

        ok &= luaval_to_boolean(tolua_S, 9,&arg7, "MultiPlatformMgr:OpenShare");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_MultiPlatformMgr_OpenShare'", nullptr);
            return 0;
        }
        cobj->OpenShare(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MultiPlatformMgr:OpenShare",argc, 7);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_MultiPlatformMgr_OpenShare'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_MultiPlatformMgr_Pay(lua_State* tolua_S)
{
    int argc = 0;
    MultiPlatformMgr* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MultiPlatformMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MultiPlatformMgr*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_MultiPlatformMgr_Pay'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 7) 
    {
        double arg0;
        long arg1;
        long arg2;
        std::string arg3;
        std::string arg4;
        long arg5;
        bool arg6;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "MultiPlatformMgr:Pay");

        ok &= luaval_to_long(tolua_S, 3, &arg1, "MultiPlatformMgr:Pay");

        ok &= luaval_to_long(tolua_S, 4, &arg2, "MultiPlatformMgr:Pay");

        ok &= luaval_to_std_string(tolua_S, 5,&arg3, "MultiPlatformMgr:Pay");

        ok &= luaval_to_std_string(tolua_S, 6,&arg4, "MultiPlatformMgr:Pay");

        ok &= luaval_to_long(tolua_S, 7, &arg5, "MultiPlatformMgr:Pay");

        ok &= luaval_to_boolean(tolua_S, 8,&arg6, "MultiPlatformMgr:Pay");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_MultiPlatformMgr_Pay'", nullptr);
            return 0;
        }
        int ret = cobj->Pay(arg0, arg1, arg2, arg3, arg4, arg5, arg6);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MultiPlatformMgr:Pay",argc, 7);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_MultiPlatformMgr_Pay'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_MultiPlatformMgr_UMPay(lua_State* tolua_S)
{
	int argc = 0;
	MultiPlatformMgr* cobj = nullptr;
	bool ok  = true;
	
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
	
	
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"MultiPlatformMgr",0,&tolua_err)) goto tolua_lerror;
#endif
	
	cobj = (MultiPlatformMgr*)tolua_tousertype(tolua_S,1,0);
	
#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_MultiPlatformMgr_UMPay'", nullptr);
		return 0;
	}
#endif
	
	argc = lua_gettop(tolua_S)-1;
	if (argc == 5)
	{
		double arg0;
		long arg1;
		long arg2;
		std::string arg3;
		std::string arg4;
		
		ok &= luaval_to_number(tolua_S, 2,&arg0, "MultiPlatformMgr:UMPay");
		
		ok &= luaval_to_long(tolua_S, 3, &arg1, "MultiPlatformMgr:UMPay");
		
		ok &= luaval_to_long(tolua_S, 4, &arg2, "MultiPlatformMgr:UMPay");
		
		ok &= luaval_to_std_string(tolua_S, 5,&arg3, "MultiPlatformMgr:UMPay");
		
		ok &= luaval_to_std_string(tolua_S, 6,&arg4, "MultiPlatformMgr:UMPay");
		
		if(!ok)
		{
			tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_MultiPlatformMgr_UMPay'", nullptr);
			return 0;
		}
		int ret = cobj->UMPay(arg0, arg1, arg2, arg3, arg4);
		tolua_pushnumber(tolua_S,(lua_Number)ret);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MultiPlatformMgr:UMPay",argc, 7);
	return 0;
	
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_MultiPlatformMgr_UMPay'.",&tolua_err);
#endif
	
	return 0;
}

int lua_cocos2dx_platform_MultiPlatformMgr_WechatLogin(lua_State* tolua_S)
{
    int argc = 0;
    MultiPlatformMgr* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MultiPlatformMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MultiPlatformMgr*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_MultiPlatformMgr_WechatLogin'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_MultiPlatformMgr_WechatLogin'", nullptr);
            return 0;
        }
        int ret = cobj->WechatLogin();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "MultiPlatformMgr:WechatLogin");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_MultiPlatformMgr_WechatLogin'", nullptr);
            return 0;
        }
        int ret = cobj->WechatLogin(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MultiPlatformMgr:WechatLogin",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_MultiPlatformMgr_WechatLogin'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_MultiPlatformMgr_getMachineId(lua_State* tolua_S)
{
    int argc = 0;
    MultiPlatformMgr* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MultiPlatformMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MultiPlatformMgr*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_MultiPlatformMgr_getMachineId'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_MultiPlatformMgr_getMachineId'", nullptr);
            return 0;
        }
        std::string ret = cobj->getMachineId();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MultiPlatformMgr:getMachineId",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_MultiPlatformMgr_getMachineId'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_MultiPlatformMgr_updateMachineID(lua_State* tolua_S)
{
    int argc = 0;
    MultiPlatformMgr* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MultiPlatformMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MultiPlatformMgr*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_MultiPlatformMgr_updateMachineID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_MultiPlatformMgr_updateMachineID'", nullptr);
            return 0;
        }
        cobj->updateMachineID();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MultiPlatformMgr:updateMachineID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_MultiPlatformMgr_updateMachineID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_MultiPlatformMgr_GetNetLevel(lua_State* tolua_S)
{
    int argc = 0;
    MultiPlatformMgr* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MultiPlatformMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MultiPlatformMgr*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_MultiPlatformMgr_GetNetLevel'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_MultiPlatformMgr_GetNetLevel'", nullptr);
            return 0;
        }
        int ret = cobj->GetNetLevel();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MultiPlatformMgr:GetNetLevel",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_MultiPlatformMgr_GetNetLevel'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_MultiPlatformMgr_HandLogin(lua_State* tolua_S)
{
    int argc = 0;
    MultiPlatformMgr* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MultiPlatformMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MultiPlatformMgr*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_MultiPlatformMgr_HandLogin'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_MultiPlatformMgr_HandLogin'", nullptr);
            return 0;
        }
        cobj->HandLogin();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MultiPlatformMgr:HandLogin",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_MultiPlatformMgr_HandLogin'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_MultiPlatformMgr_HandChangeAccount(lua_State* tolua_S)
{
    int argc = 0;
    MultiPlatformMgr* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MultiPlatformMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MultiPlatformMgr*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_MultiPlatformMgr_HandChangeAccount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_MultiPlatformMgr_HandChangeAccount'", nullptr);
            return 0;
        }
        cobj->HandChangeAccount();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MultiPlatformMgr:HandChangeAccount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_MultiPlatformMgr_HandChangeAccount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_MultiPlatformMgr_triggerPickImg(lua_State* tolua_S)
{
    int argc = 0;
    MultiPlatformMgr* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MultiPlatformMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MultiPlatformMgr*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_MultiPlatformMgr_triggerPickImg'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_MultiPlatformMgr_triggerPickImg'", nullptr);
            return 0;
        }
        cobj->triggerPickImg();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MultiPlatformMgr:triggerPickImg",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_MultiPlatformMgr_triggerPickImg'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_MultiPlatformMgr_HandSubRole(lua_State* tolua_S)
{
    int argc = 0;
    MultiPlatformMgr* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MultiPlatformMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MultiPlatformMgr*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_MultiPlatformMgr_HandSubRole'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 6) 
    {
        std::string arg0;
        std::string arg1;
        int arg2;
        long arg3;
        std::string arg4;
        std::string arg5;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "MultiPlatformMgr:HandSubRole");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "MultiPlatformMgr:HandSubRole");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "MultiPlatformMgr:HandSubRole");

        ok &= luaval_to_long(tolua_S, 5, &arg3, "MultiPlatformMgr:HandSubRole");

        ok &= luaval_to_std_string(tolua_S, 6,&arg4, "MultiPlatformMgr:HandSubRole");

        ok &= luaval_to_std_string(tolua_S, 7,&arg5, "MultiPlatformMgr:HandSubRole");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_MultiPlatformMgr_HandSubRole'", nullptr);
            return 0;
        }
        cobj->HandSubRole(arg0, arg1, arg2, arg3, arg4, arg5);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MultiPlatformMgr:HandSubRole",argc, 6);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_MultiPlatformMgr_HandSubRole'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_MultiPlatformMgr_ShowToast(lua_State* tolua_S)
{
    int argc = 0;
    MultiPlatformMgr* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MultiPlatformMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MultiPlatformMgr*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_MultiPlatformMgr_ShowToast'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "MultiPlatformMgr:ShowToast");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_MultiPlatformMgr_ShowToast'", nullptr);
            return 0;
        }
        cobj->ShowToast(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MultiPlatformMgr:ShowToast",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_MultiPlatformMgr_ShowToast'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_MultiPlatformMgr_GetWebChatType(lua_State* tolua_S)
{
    int argc = 0;
    MultiPlatformMgr* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MultiPlatformMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MultiPlatformMgr*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_MultiPlatformMgr_GetWebChatType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_MultiPlatformMgr_GetWebChatType'", nullptr);
            return 0;
        }
        int ret = cobj->GetWebChatType();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MultiPlatformMgr:GetWebChatType",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_MultiPlatformMgr_GetWebChatType'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_MultiPlatformMgr_openLocalPhoto(lua_State* tolua_S)
{
    int argc = 0;
    MultiPlatformMgr* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MultiPlatformMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MultiPlatformMgr*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_MultiPlatformMgr_openLocalPhoto'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_MultiPlatformMgr_openLocalPhoto'", nullptr);
            return 0;
        }
        cobj->openLocalPhoto();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MultiPlatformMgr:openLocalPhoto",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_MultiPlatformMgr_openLocalPhoto'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_MultiPlatformMgr_init(lua_State* tolua_S)
{
    int argc = 0;
    MultiPlatformMgr* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MultiPlatformMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MultiPlatformMgr*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_MultiPlatformMgr_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_MultiPlatformMgr_init'", nullptr);
            return 0;
        }
        cobj->init();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MultiPlatformMgr:init",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_MultiPlatformMgr_init'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_MultiPlatformMgr_GetShareNoticeNameSuccess(lua_State* tolua_S)
{
    int argc = 0;
    MultiPlatformMgr* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MultiPlatformMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MultiPlatformMgr*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_MultiPlatformMgr_GetShareNoticeNameSuccess'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_MultiPlatformMgr_GetShareNoticeNameSuccess'", nullptr);
            return 0;
        }
        std::string ret = cobj->GetShareNoticeNameSuccess();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MultiPlatformMgr:GetShareNoticeNameSuccess",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_MultiPlatformMgr_GetShareNoticeNameSuccess'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_MultiPlatformMgr_startSoundRecord(lua_State* tolua_S)
{
    int argc = 0;
    MultiPlatformMgr* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MultiPlatformMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MultiPlatformMgr*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_MultiPlatformMgr_startSoundRecord'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_MultiPlatformMgr_startSoundRecord'", nullptr);
            return 0;
        }
        cobj->startSoundRecord();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MultiPlatformMgr:startSoundRecord",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_MultiPlatformMgr_startSoundRecord'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_MultiPlatformMgr_deleteAuthorization(lua_State* tolua_S)
{
    int argc = 0;
    MultiPlatformMgr* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MultiPlatformMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MultiPlatformMgr*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_MultiPlatformMgr_deleteAuthorization'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_MultiPlatformMgr_deleteAuthorization'", nullptr);
            return 0;
        }
        int ret = cobj->deleteAuthorization();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MultiPlatformMgr:deleteAuthorization",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_MultiPlatformMgr_deleteAuthorization'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_MultiPlatformMgr_test(lua_State* tolua_S)
{
    int argc = 0;
    MultiPlatformMgr* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MultiPlatformMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MultiPlatformMgr*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_MultiPlatformMgr_test'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_MultiPlatformMgr_test'", nullptr);
            return 0;
        }
        cobj->test();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MultiPlatformMgr:test",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_MultiPlatformMgr_test'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_MultiPlatformMgr_HandFixedpay(lua_State* tolua_S)
{
    int argc = 0;
    MultiPlatformMgr* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MultiPlatformMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MultiPlatformMgr*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_MultiPlatformMgr_HandFixedpay'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_MultiPlatformMgr_HandFixedpay'", nullptr);
            return 0;
        }
        cobj->HandFixedpay();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MultiPlatformMgr:HandFixedpay",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_MultiPlatformMgr_HandFixedpay'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_MultiPlatformMgr_getPlatformDelegate(lua_State* tolua_S)
{
    int argc = 0;
    MultiPlatformMgr* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MultiPlatformMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MultiPlatformMgr*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_MultiPlatformMgr_getPlatformDelegate'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_MultiPlatformMgr_getPlatformDelegate'", nullptr);
            return 0;
        }
        MultiPlatformMgrDelegate* ret = cobj->getPlatformDelegate();
        object_to_luaval<MultiPlatformMgrDelegate>(tolua_S, "MultiPlatformMgrDelegate",(MultiPlatformMgrDelegate*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MultiPlatformMgr:getPlatformDelegate",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_MultiPlatformMgr_getPlatformDelegate'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_MultiPlatformMgr_stopSoundRecord(lua_State* tolua_S)
{
    int argc = 0;
    MultiPlatformMgr* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MultiPlatformMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MultiPlatformMgr*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_MultiPlatformMgr_stopSoundRecord'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_MultiPlatformMgr_stopSoundRecord'", nullptr);
            return 0;
        }
        const char* ret = cobj->stopSoundRecord();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MultiPlatformMgr:stopSoundRecord",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_MultiPlatformMgr_stopSoundRecord'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_MultiPlatformMgr_isAuthorized(lua_State* tolua_S)
{
    int argc = 0;
    MultiPlatformMgr* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MultiPlatformMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MultiPlatformMgr*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_MultiPlatformMgr_isAuthorized'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_MultiPlatformMgr_isAuthorized'", nullptr);
            return 0;
        }
        bool ret = cobj->isAuthorized();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MultiPlatformMgr:isAuthorized",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_MultiPlatformMgr_isAuthorized'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_MultiPlatformMgr_CallCustomServiceIphone(lua_State* tolua_S)
{
    int argc = 0;
    MultiPlatformMgr* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MultiPlatformMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MultiPlatformMgr*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_MultiPlatformMgr_CallCustomServiceIphone'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "MultiPlatformMgr:CallCustomServiceIphone");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_MultiPlatformMgr_CallCustomServiceIphone'", nullptr);
            return 0;
        }
        cobj->CallCustomServiceIphone(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MultiPlatformMgr:CallCustomServiceIphone",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_MultiPlatformMgr_CallCustomServiceIphone'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_MultiPlatformMgr_vibrator(lua_State* tolua_S)
{
    int argc = 0;
    MultiPlatformMgr* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MultiPlatformMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MultiPlatformMgr*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_MultiPlatformMgr_vibrator'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_MultiPlatformMgr_vibrator'", nullptr);
            return 0;
        }
        cobj->vibrator();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MultiPlatformMgr:vibrator",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_MultiPlatformMgr_vibrator'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_MultiPlatformMgr_updateVersion(lua_State* tolua_S)
{
    int argc = 0;
    MultiPlatformMgr* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MultiPlatformMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MultiPlatformMgr*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_MultiPlatformMgr_updateVersion'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_MultiPlatformMgr_updateVersion'", nullptr);
            return 0;
        }
        cobj->updateVersion();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MultiPlatformMgr:updateVersion",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_MultiPlatformMgr_updateVersion'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_MultiPlatformMgr_UnPay(lua_State* tolua_S)
{
    int argc = 0;
    MultiPlatformMgr* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MultiPlatformMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MultiPlatformMgr*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_MultiPlatformMgr_UnPay'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_MultiPlatformMgr_UnPay'", nullptr);
            return 0;
        }
        int ret = cobj->UnPay();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MultiPlatformMgr:UnPay",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_MultiPlatformMgr_UnPay'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_MultiPlatformMgr_GetShareNoticeNameFail(lua_State* tolua_S)
{
    int argc = 0;
    MultiPlatformMgr* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MultiPlatformMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MultiPlatformMgr*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_MultiPlatformMgr_GetShareNoticeNameFail'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_MultiPlatformMgr_GetShareNoticeNameFail'", nullptr);
            return 0;
        }
        std::string ret = cobj->GetShareNoticeNameFail();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MultiPlatformMgr:GetShareNoticeNameFail",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_MultiPlatformMgr_GetShareNoticeNameFail'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_MultiPlatformMgr_Handpay(lua_State* tolua_S)
{
	int argc = 0;
	MultiPlatformMgr* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "MultiPlatformMgr", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (MultiPlatformMgr*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_cocos2dx_platform_MultiPlatformMgr_Handpay'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 6)
	{
		std::string arg0;
		double arg1;
		std::string arg2;
		std::string arg3;
		std::string arg4;
		int arg5;

		ok &= luaval_to_std_string(tolua_S, 2, &arg0, "MultiPlatformMgr:Handpay");

		ok &= luaval_to_number(tolua_S, 3, &arg1, "MultiPlatformMgr:Handpay");

		ok &= luaval_to_std_string(tolua_S, 4, &arg2, "MultiPlatformMgr:Handpay");

		ok &= luaval_to_std_string(tolua_S, 5, &arg3, "MultiPlatformMgr:Handpay");

		ok &= luaval_to_std_string(tolua_S, 6, &arg4, "MultiPlatformMgr:Handpay");

		ok &= luaval_to_int32(tolua_S, 7, (int *)&arg5, "MultiPlatformMgr:Handpay");
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_cocos2dx_platform_MultiPlatformMgr_Handpay'", nullptr);
			return 0;
		}
		cobj->Handpay(arg0, arg1, arg2, arg3, arg4, arg5);
		lua_settop(tolua_S, 1);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MultiPlatformMgr:Handpay", argc, 6);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_cocos2dx_platform_MultiPlatformMgr_Handpay'.", &tolua_err);
#endif

	return 0;
}
int lua_cocos2dx_platform_MultiPlatformMgr_GetNetType(lua_State* tolua_S)
{
    int argc = 0;
    MultiPlatformMgr* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MultiPlatformMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MultiPlatformMgr*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_MultiPlatformMgr_GetNetType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_MultiPlatformMgr_GetNetType'", nullptr);
            return 0;
        }
        int ret = cobj->GetNetType();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MultiPlatformMgr:GetNetType",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_MultiPlatformMgr_GetNetType'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_MultiPlatformMgr_clientVersionInfo(lua_State* tolua_S)
{
    int argc = 0;
    MultiPlatformMgr* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MultiPlatformMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MultiPlatformMgr*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_MultiPlatformMgr_clientVersionInfo'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_MultiPlatformMgr_clientVersionInfo'", nullptr);
            return 0;
        }
        std::string ret = cobj->clientVersionInfo();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MultiPlatformMgr:clientVersionInfo",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_MultiPlatformMgr_clientVersionInfo'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_MultiPlatformMgr_GetBatteryLevel(lua_State* tolua_S)
{
    int argc = 0;
    MultiPlatformMgr* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MultiPlatformMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MultiPlatformMgr*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_platform_MultiPlatformMgr_GetBatteryLevel'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_MultiPlatformMgr_GetBatteryLevel'", nullptr);
            return 0;
        }
        int ret = cobj->GetBatteryLevel();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MultiPlatformMgr:GetBatteryLevel",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_MultiPlatformMgr_GetBatteryLevel'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_platform_MultiPlatformMgr_destroy(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"MultiPlatformMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_MultiPlatformMgr_destroy'", nullptr);
            return 0;
        }
        MultiPlatformMgr::destroy();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "MultiPlatformMgr:destroy",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_MultiPlatformMgr_destroy'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_platform_MultiPlatformMgr_umengPay(lua_State* tolua_S)
{
	int argc = 0;
	MultiPlatformMgr* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "MultiPlatformMgr", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (MultiPlatformMgr*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_cocos2dx_platform_MultiPlatformMgr_umengPay'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 5)
	{
		double arg0;
		int arg1;
		double arg2;
		const char* arg3;
		int arg4;

		ok &= luaval_to_number(tolua_S, 2, &arg0, "MultiPlatformMgr:umengPay");

		ok &= luaval_to_int32(tolua_S, 3, (int *)&arg1, "MultiPlatformMgr:umengPay");

		ok &= luaval_to_number(tolua_S, 4, &arg2, "MultiPlatformMgr:umengPay");

		std::string arg3_tmp; ok &= luaval_to_std_string(tolua_S, 5, &arg3_tmp, "MultiPlatformMgr:umengPay"); arg3 = arg3_tmp.c_str();

		ok &= luaval_to_int32(tolua_S, 6, (int *)&arg4, "MultiPlatformMgr:umengPay");
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_cocos2dx_platform_MultiPlatformMgr_umengPay'", nullptr);
			return 0;
		}
		cobj->umengPay(arg0, arg1, arg2, arg3, arg4);
		lua_settop(tolua_S, 1);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MultiPlatformMgr:umengPay", argc, 5);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_cocos2dx_platform_MultiPlatformMgr_umengPay'.", &tolua_err);
#endif

	return 0;
}
int lua_cocos2dx_platform_MultiPlatformMgr_umengBuy(lua_State* tolua_S)
{
	int argc = 0;
	MultiPlatformMgr* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "MultiPlatformMgr", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (MultiPlatformMgr*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_cocos2dx_platform_MultiPlatformMgr_umengBuy'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 3)
	{
		const char* arg0;
		int arg1;
		double arg2;

		std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "MultiPlatformMgr:umengBuy"); arg0 = arg0_tmp.c_str();

		ok &= luaval_to_int32(tolua_S, 3, (int *)&arg1, "MultiPlatformMgr:umengBuy");

		ok &= luaval_to_number(tolua_S, 4, &arg2, "MultiPlatformMgr:umengBuy");
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_cocos2dx_platform_MultiPlatformMgr_umengBuy'", nullptr);
			return 0;
		}
		cobj->umengBuy(arg0, arg1, arg2);
		lua_settop(tolua_S, 1);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MultiPlatformMgr:umengBuy", argc, 3);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_cocos2dx_platform_MultiPlatformMgr_umengBuy'.", &tolua_err);
#endif

	return 0;
}
int lua_cocos2dx_platform_MultiPlatformMgr_umengUser(lua_State* tolua_S)
{
	int argc = 0;
	MultiPlatformMgr* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "MultiPlatformMgr", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (MultiPlatformMgr*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_cocos2dx_platform_MultiPlatformMgr_umengUser'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 3)
	{
		const char* arg0;
		int arg1;
		double arg2;

		std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "MultiPlatformMgr:umengUser"); arg0 = arg0_tmp.c_str();

		ok &= luaval_to_int32(tolua_S, 3, (int *)&arg1, "MultiPlatformMgr:umengUser");

		ok &= luaval_to_number(tolua_S, 4, &arg2, "MultiPlatformMgr:umengUser");
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_cocos2dx_platform_MultiPlatformMgr_umengUser'", nullptr);
			return 0;
		}
		cobj->umengUser(arg0, arg1, arg2);
		lua_settop(tolua_S, 1);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MultiPlatformMgr:umengUser", argc, 3);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_cocos2dx_platform_MultiPlatformMgr_umengUser'.", &tolua_err);
#endif

	return 0;
}
int lua_cocos2dx_platform_MultiPlatformMgr_umengbonus(lua_State* tolua_S)
{
	int argc = 0;
	MultiPlatformMgr* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "MultiPlatformMgr", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (MultiPlatformMgr*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_cocos2dx_platform_MultiPlatformMgr_umengbonus'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 4)
	{
		const char* arg0;
		int arg1;
		double arg2;
		int arg3;

		std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "MultiPlatformMgr:umengbonus"); arg0 = arg0_tmp.c_str();

		ok &= luaval_to_int32(tolua_S, 3, (int *)&arg1, "MultiPlatformMgr:umengbonus");

		ok &= luaval_to_number(tolua_S, 4, &arg2, "MultiPlatformMgr:umengbonus");

		ok &= luaval_to_int32(tolua_S, 5, (int *)&arg3, "MultiPlatformMgr:umengbonus");
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_cocos2dx_platform_MultiPlatformMgr_umengbonus'", nullptr);
			return 0;
		}
		cobj->umengbonus(arg0, arg1, arg2, arg3);
		lua_settop(tolua_S, 1);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MultiPlatformMgr:umengbonus", argc, 4);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_cocos2dx_platform_MultiPlatformMgr_umengbonus'.", &tolua_err);
#endif

	return 0;
}
int lua_cocos2dx_platform_MultiPlatformMgr_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"MultiPlatformMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_platform_MultiPlatformMgr_getInstance'", nullptr);
            return 0;
        }
        MultiPlatformMgr* ret = MultiPlatformMgr::getInstance();
        object_to_luaval<MultiPlatformMgr>(tolua_S, "MultiPlatformMgr",(MultiPlatformMgr*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "MultiPlatformMgr:getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_platform_MultiPlatformMgr_getInstance'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_platform_MultiPlatformMgr_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (MultiPlatformMgr)");
    return 0;
}

int lua_register_cocos2dx_platform_MultiPlatformMgr(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"MultiPlatformMgr");
    tolua_cclass(tolua_S,"MultiPlatformMgr","MultiPlatformMgr","",nullptr);

    tolua_beginmodule(tolua_S,"MultiPlatformMgr");
        tolua_function(tolua_S,"switchVibratorState",lua_cocos2dx_platform_MultiPlatformMgr_switchVibratorState);
        tolua_function(tolua_S,"obtainNetWorkState",lua_cocos2dx_platform_MultiPlatformMgr_obtainNetWorkState);
        tolua_function(tolua_S,"setPlatformDelegate",lua_cocos2dx_platform_MultiPlatformMgr_setPlatformDelegate);
        tolua_function(tolua_S,"OpenShare",lua_cocos2dx_platform_MultiPlatformMgr_OpenShare);
        tolua_function(tolua_S,"Pay",lua_cocos2dx_platform_MultiPlatformMgr_Pay);
		tolua_function(tolua_S,"UMPay",lua_cocos2dx_platform_MultiPlatformMgr_UMPay);
        tolua_function(tolua_S,"WechatLogin",lua_cocos2dx_platform_MultiPlatformMgr_WechatLogin);
        tolua_function(tolua_S,"getMachineId",lua_cocos2dx_platform_MultiPlatformMgr_getMachineId);
        tolua_function(tolua_S,"updateMachineID",lua_cocos2dx_platform_MultiPlatformMgr_updateMachineID);
        tolua_function(tolua_S,"GetNetLevel",lua_cocos2dx_platform_MultiPlatformMgr_GetNetLevel);
        tolua_function(tolua_S,"HandLogin",lua_cocos2dx_platform_MultiPlatformMgr_HandLogin);
        tolua_function(tolua_S,"HandChangeAccount",lua_cocos2dx_platform_MultiPlatformMgr_HandChangeAccount);
        tolua_function(tolua_S,"triggerPickImg",lua_cocos2dx_platform_MultiPlatformMgr_triggerPickImg);
        tolua_function(tolua_S,"HandSubRole",lua_cocos2dx_platform_MultiPlatformMgr_HandSubRole);
        tolua_function(tolua_S,"ShowToast",lua_cocos2dx_platform_MultiPlatformMgr_ShowToast);
        tolua_function(tolua_S,"GetWebChatType",lua_cocos2dx_platform_MultiPlatformMgr_GetWebChatType);
        tolua_function(tolua_S,"openLocalPhoto",lua_cocos2dx_platform_MultiPlatformMgr_openLocalPhoto);
        tolua_function(tolua_S,"init",lua_cocos2dx_platform_MultiPlatformMgr_init);
        tolua_function(tolua_S,"GetShareNoticeNameSuccess",lua_cocos2dx_platform_MultiPlatformMgr_GetShareNoticeNameSuccess);
        tolua_function(tolua_S,"startSoundRecord",lua_cocos2dx_platform_MultiPlatformMgr_startSoundRecord);
        tolua_function(tolua_S,"deleteAuthorization",lua_cocos2dx_platform_MultiPlatformMgr_deleteAuthorization);
        tolua_function(tolua_S,"test",lua_cocos2dx_platform_MultiPlatformMgr_test);
        tolua_function(tolua_S,"HandFixedpay",lua_cocos2dx_platform_MultiPlatformMgr_HandFixedpay);
        tolua_function(tolua_S,"getPlatformDelegate",lua_cocos2dx_platform_MultiPlatformMgr_getPlatformDelegate);
        tolua_function(tolua_S,"stopSoundRecord",lua_cocos2dx_platform_MultiPlatformMgr_stopSoundRecord);
        tolua_function(tolua_S,"isAuthorized",lua_cocos2dx_platform_MultiPlatformMgr_isAuthorized);
        tolua_function(tolua_S,"CallCustomServiceIphone",lua_cocos2dx_platform_MultiPlatformMgr_CallCustomServiceIphone);
        tolua_function(tolua_S,"vibrator",lua_cocos2dx_platform_MultiPlatformMgr_vibrator);
        tolua_function(tolua_S,"updateVersion",lua_cocos2dx_platform_MultiPlatformMgr_updateVersion);
        tolua_function(tolua_S,"UnPay",lua_cocos2dx_platform_MultiPlatformMgr_UnPay);
        tolua_function(tolua_S,"GetShareNoticeNameFail",lua_cocos2dx_platform_MultiPlatformMgr_GetShareNoticeNameFail);
        tolua_function(tolua_S,"Handpay",lua_cocos2dx_platform_MultiPlatformMgr_Handpay);
        tolua_function(tolua_S,"GetNetType",lua_cocos2dx_platform_MultiPlatformMgr_GetNetType);
        tolua_function(tolua_S,"clientVersionInfo",lua_cocos2dx_platform_MultiPlatformMgr_clientVersionInfo);
        tolua_function(tolua_S,"GetBatteryLevel",lua_cocos2dx_platform_MultiPlatformMgr_GetBatteryLevel);
        tolua_function(tolua_S,"destroy", lua_cocos2dx_platform_MultiPlatformMgr_destroy);
        tolua_function(tolua_S,"getInstance", lua_cocos2dx_platform_MultiPlatformMgr_getInstance);
		tolua_function(tolua_S, "umengPay", lua_cocos2dx_platform_MultiPlatformMgr_umengPay);
		tolua_function(tolua_S, "umengBuy", lua_cocos2dx_platform_MultiPlatformMgr_umengBuy);
		tolua_function(tolua_S, "umengbonus", lua_cocos2dx_platform_MultiPlatformMgr_umengbonus);
		tolua_function(tolua_S, "umengUser", lua_cocos2dx_platform_MultiPlatformMgr_umengUser);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(MultiPlatformMgr).name();
    g_luaType[typeName] = "MultiPlatformMgr";
    g_typeCast["MultiPlatformMgr"] = "MultiPlatformMgr";
    return 1;
}
TOLUA_API int register_all_cocos2dx_platform(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"ds",0);
	tolua_beginmodule(tolua_S,"ds");

	lua_register_cocos2dx_platform_CParameterServer(tolua_S);
	lua_register_cocos2dx_platform_DF(tolua_S);
	lua_register_cocos2dx_platform_CParameterGame(tolua_S);
	lua_register_cocos2dx_platform_CGameInsideItem(tolua_S);
	lua_register_cocos2dx_platform_tagGameMatch(tolua_S);
	lua_register_cocos2dx_platform_tagGameNode(tolua_S);
	lua_register_cocos2dx_platform_tagServerAttribute(tolua_S);
	lua_register_cocos2dx_platform_tagUserScore(tolua_S);
	lua_register_cocos2dx_platform_tagGameAttribute(tolua_S);
	lua_register_cocos2dx_platform_tagCustomFaceInfo(tolua_S);
	lua_register_cocos2dx_platform_tagTimeInfo(tolua_S);
	lua_register_cocos2dx_platform_CGameNodeItem(tolua_S);
	lua_register_cocos2dx_platform_tagUserAttribute(tolua_S);
	lua_register_cocos2dx_platform_tagGlobalUserData(tolua_S);
	lua_register_cocos2dx_platform_tagIndividualUserData(tolua_S);
	lua_register_cocos2dx_platform_tagUserInfo(tolua_S);
	lua_register_cocos2dx_platform_CMD_GR_C_TableTalk(tolua_S);
	lua_register_cocos2dx_platform_CGameTypeItem(tolua_S);
	lua_register_cocos2dx_platform_tagGameServer(tolua_S);
	lua_register_cocos2dx_platform_tagMatchWaitTip(tolua_S);
	lua_register_cocos2dx_platform_tagUserAttrib(tolua_S);
	lua_register_cocos2dx_platform_tagUserInsureInfo(tolua_S);
	lua_register_cocos2dx_platform_tagGrowLevelParameter(tolua_S);
	lua_register_cocos2dx_platform_CPlatformGameConfig(tolua_S);
	lua_register_cocos2dx_platform_tagGameKind(tolua_S);
	lua_register_cocos2dx_platform_tagPropertyPackage(tolua_S);
	lua_register_cocos2dx_platform_MultiPlatformMgr(tolua_S);
	lua_register_cocos2dx_platform_CServerListData(tolua_S);
	lua_register_cocos2dx_platform_CGamePageItem(tolua_S);
	lua_register_cocos2dx_platform_CParameterGlobal(tolua_S);
	lua_register_cocos2dx_platform_tagGamePage(tolua_S);
	lua_register_cocos2dx_platform_tagUserStatus(tolua_S);
	lua_register_cocos2dx_platform_CGameServerItem(tolua_S);
	lua_register_cocos2dx_platform_tagMatchInfo(tolua_S);
	lua_register_cocos2dx_platform_CGlobalUserInfo(tolua_S);
	lua_register_cocos2dx_platform_CGameKindItem(tolua_S);
	lua_register_cocos2dx_platform_tagGameType(tolua_S);
	lua_register_cocos2dx_platform_tagMatchResult(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

#endif
