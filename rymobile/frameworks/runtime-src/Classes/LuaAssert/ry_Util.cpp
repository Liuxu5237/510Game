//
//  ry_Util.cpp
//  GloryProject
//
//  Created by chunyong on 2017/9/15.
//
//

#include "ry_Util.h"
#include "ry_MD5.h"
#include "CCLuaEngine.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"

#define d_sign1_key "^_^()_#)@_#)_RQUIWWWW*)" //sign1  key

static ryUtil* g_ryUtil_ptr = nullptr;


ryUtil* ryUtil::getIns() {
    if (g_ryUtil_ptr == nullptr) {
        g_ryUtil_ptr = new ryUtil();
    }
    return g_ryUtil_ptr;
}

//生成sign1
std::string ryUtil::getSign1(const char* userid, const char* key, const char* time)
{
    std::string md5data = StringUtils::format("%s%s%s",userid,key,time);
    std::string md5datastring=md5(md5data);
    char* sendMd5 = new char(md5datastring.length());
    memset(sendMd5, 0, md5datastring.length());
    memcpy(sendMd5, md5datastring.c_str(), md5datastring.length());
    for(int i =0;i<md5datastring.length();i++){
        sendMd5[i] = tolower(sendMd5[i]);
    }
    md5datastring = std::string(sendMd5);
    CC_SAFE_DELETE(sendMd5);
    md5datastring = md5(md5datastring);
    sendMd5 = new char(md5datastring.length());
    memset(sendMd5, 0, md5datastring.length());
    memcpy(sendMd5, md5datastring.c_str(), md5datastring.length());
    for(int i =0;i<md5datastring.length();i++){
        sendMd5[i] = tolower(sendMd5[i]);
    }
    std::string endStr = std::string(sendMd5);
    CCLOG("== endStr:%s",endStr.c_str());
    CC_SAFE_DELETE(sendMd5);
    return endStr;
}

static int toLua_getSign1(lua_State* tolua_S)
{
    int argc = lua_gettop(tolua_S);
    if(argc == 3)
    {
        const char* userid = lua_tostring(tolua_S,1);
        const char* key = lua_tostring(tolua_S,2);
        const char* time = lua_tostring(tolua_S,3);
        
        std::string sign = ryUtil::getIns()->getSign1(userid, d_sign1_key, time);
        lua_pushstring(tolua_S,sign.c_str());
        
        return 1;
    }
    return 0;
}

//获取时间锉
std::string ryUtil::getUnixTime()
{
    return StringUtils::format("%ld",time(nullptr)).c_str();
}

static int toLua_getUnixTime(lua_State* tolua_S)
{
    std::string time = ryUtil::getIns()->getUnixTime();
    lua_pushstring(tolua_S, time.c_str());
    return 1;
}

//删除换行制表空格
void ryUtil::trimSpace(std::string *s)
{
    if ((*s).empty()) return;
    while (1) {
        unsigned long pos = (*s).find("\n");
        if (pos != std::string::npos) {
            (*s).replace(pos, strlen("\n"), "");
        }else
            break;
    }
    while (1) {
        unsigned long pos = (*s).find("\r");
        if (pos != std::string::npos) {
            (*s).replace(pos, strlen("\r"), "");
        }else
            break;
    }
    while (1) {
        unsigned long pos = (*s).find(" ");
        if (pos != std::string::npos) {
            (*s).replace(pos, strlen(" "), "");
        }else
            break;
    }
}
static int toLua_trimSpace(lua_State* tolua_S)
{
    int argc = lua_gettop(tolua_S);
    if(argc == 1)
    {
        const char* s = lua_tostring(tolua_S,1);
        std::string s1 = std::string(s);
        ryUtil::getIns()->trimSpace(&s1);
        lua_pushstring(tolua_S,s1.c_str());
        
        return 1;
    }
    return 0;
}

int register_all_RyUtil()
{
    lua_State* tolua_S = LuaEngine::getInstance()->getLuaStack()->getLuaState();
    lua_register(tolua_S,"GetSign1",toLua_getSign1);
    lua_register(tolua_S,"GetUnixTime",toLua_getUnixTime);
    lua_register(tolua_S,"TrimSpace",toLua_trimSpace);
    return 1;
}
