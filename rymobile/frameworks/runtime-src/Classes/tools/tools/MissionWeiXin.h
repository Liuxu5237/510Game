#pragma  once
#include <string>
#include "MCWebReq.h"

struct WxUserInfo
{
	std::string openid;
	std::string nickname;
	int		   sex;
	std::string province;
	std::string city;
	std::string country;
	std::string headimgurl;
	std::string unionid;
};


class MissionWeiXin
{
public:
	const static int SHARE_SESSION = 0;
	const static int SHARE_MOMENTS = 1;
public:
	MissionWeiXin();
	~MissionWeiXin();
public:
	static MissionWeiXin* shared();
	static void purge();

	void Req_UserInfo(const std::string& access_token,const std::string& open_id, const std::string& refreshtoken, int type);
	void Rsp_UserInfo(rapidjson::Document* pDoc);
private:

	std::string       m_kWxAppId;
	std::string       m_kWxAppSecret;
	std::string		  m_kUrl;
	std::string		  m_refreshToken;
	int				  m_Type;
};

