#ifndef _df_H_
#define _df_H_
#include "types.h"
#include "Platform.h"

#include "cocos2d.h"

#define COL_N2G(col) (((col & 0xFF) << 16) | (col >> 8))
#define COL_G2N(col) ((col << 8) | (col >> 16))

//////////////////////////////////////////////////////////////////////////
// 对话框按钮
#define DLG_MB_OK                       0x1
#define DLG_MB_CANCEL					0x2
#define DLG_MB_YES						0x4
#define DLG_MB_NO						0x8

//////////////////////////////////////////////////////////////////////////////////
//结构定义

//字符串版本转整形版本
uint32		VerStringToInt(const char *strVer);
dword		CheStringToInt(const char *strVer);
//////////////////////////////////////////////////////////////////////////
// 辅助定义
//////////////////////////////////////////////////////////////////////////
class DF : public cocos2d::Ref
{
protected:
	std::string mGameName;
	int			mClientVersion;
	int			mKindID;
	int			mGamePlayers;
	int			mPlatformID;//平台id,0:原始平台
	std::string mInitVersion;	//初始版本号
public:
	static DF* shared();
	static const char* MD5Encrypt(const char* pszSourceData);
public:
	DF();
	virtual ~DF();

	void init(int iKindID, int iPlayers, const char * sGameVersion, const char* sGameName);
public:
	
	byte		GetDeviceType();
	const char* GetMachineID();
	const char* GetMobilePhone();	
	uint32		GetPlazaVersion();
	std::string GetPlazaStringVersion();
	uint32		GetFrameVersion();
	
	uint16		GetPlazzKindID();
	uint16		GetPlatformID();
	uint32		GetGameVersion();
	uint16		GetGameKindID();
	uint32		GetGamePlayer();
	const char* GetGameName(char szGameName[LEN_KIND]);
};
//////////////////////////////////////////////////////////////////////////
#endif // _df_H_