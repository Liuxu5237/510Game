#include "MissionWeiXin.h"
#include "MTNotification.h"
#include "platform/df/RoomEventIDDefine.h"

static MissionWeiXin* _sharedStringData = 0;

MissionWeiXin* MissionWeiXin::shared()
{
	if(_sharedStringData == 0){
		_sharedStringData = new MissionWeiXin();
	}
	return _sharedStringData;
}

MissionWeiXin::~MissionWeiXin()
{
	
}

MissionWeiXin::MissionWeiXin()
{
	
}

void MissionWeiXin::purge()
{
	//CC_SAFE_RELEASE_NULL(_sharedStringData);
}

void MissionWeiXin::Req_UserInfo(const std::string& access_token,const std::string& open_id, const std::string& refreshtoken, int type)
{
	std::string kUrl = "https://api.weixin.qq.com/sns/userinfo?";
	MCWebReq::pushValue(kUrl,"access_token",access_token);
	MCWebReq::pushValue(kUrl,"openid",open_id);
	m_refreshToken = refreshtoken;
	m_Type = type;
	MCWebReq::instance().sendRequestDocumentUrl(kUrl,CC_CALLBACK_1(MissionWeiXin::Rsp_UserInfo,this),nullptr);
}
void MissionWeiXin::Rsp_UserInfo(rapidjson::Document* pDoc)
{
	int errcode = MCWebReq::getDataValueInt(pDoc,"errcode");
	//cocos2d::log("MissionWeiXin::Rsp_UserInfo errcode=%d", errcode);
	if (errcode!=0)
	{
		G_NOTIFY_D("Login_Event", MTData::create(1, 3));
		return;
	}
	
	std::string Result = "";
	std::string uid = MCWebReq::getDataValueStr(pDoc,"unionid");
	std::string openid = MCWebReq::getDataValueStr(pDoc,"openid");
	std::string accessToken = "";
	std::string refreshToken = m_refreshToken;
	std::string name = MCWebReq::getDataValueStr(pDoc,"nickname");
	std::string iconurl = MCWebReq::getDataValueStr(pDoc,"headimgurl");
	int sex = MCWebReq::getDataValueInt(pDoc,"sex");
	std::string gender = "0";
	if (sex == 2)
	{
		gender = "0";
	}
	else
	{
		gender = "1";
	}
	
	Result = uid + "," + refreshToken + "," + name + "," + openid + "," + iconurl + "," + gender;
	if (m_Type == 0)
	{
		G_NOTIFY_D("Login_Event", MTData::create(1, 0, 0, Result));
	}
	else if (m_Type == 1)
	{
		G_NOTIFY_D("room_event", MTData::create(ROOM_EVENT_ID_WEBCHATBIND, 0, 0, Result));
	}
}
