#include <sstream>
#include "QPCipher.h"
#include "CSocketEngine.h"
#include "ISocketEngineSink.h"
#include <platform/CCCommon.h>
#include "platform/PlatformHeader.h"
#include "tools/dialog/Timer.h"
#include "LuaAssert/CMD_Data.h"
#include "CCLuaEngine.h"
#include "lua/LuaStackEx.h"

using namespace std;

#define MAIN_SOCKET_INFO  0

#define SUB_SOCKET_CONNECT  1
#define SUB_SOCKET_ERROR  2
#define SUB_SOCKET_CLOSE  3
//////////////////////////////////////////////////////////////////////////
ISocketEngine* ISocketEngine::create()
{
	return new CSocketEngine();
}

void ISocketEngine::destory(ISocketEngine* pISocketEngine)
{
	if (pISocketEngine)
	{
		delete pISocketEngine;
	}
}

//////////////////////////////////////////////////////////////////////////
CSocketEngine::CSocketEngine()
{
	mISocketEngineSink = 0;
	mIsSendTCPValidate = false;
	mSocket.setSocketSink(this);

	//加密数据
	m_cbSendRound = 0;
	m_cbRecvRound = 0;
	m_dwSendXorKey = 0;
	m_dwRecvXorKey = 0;

	m_dwSendPacketCount = 0;
	m_dwRecvPacketCount = 0;

	// add by lesten
	temp_size_ = 0;
}

CSocketEngine::~CSocketEngine()
{
	temp_size_ = 0;
	mISocketEngineSink=0;
	mSocket.setSocketSink(0);
	disconnect();
}

//////////////////////////////////////////////////////////////////////////
// ISocketEngine 接口实现

/** 设置Socket接收器 */
void CSocketEngine::setSocketEngineSink(ISocketEngineSink* pISocketEngineSink)
{
	mISocketEngineSink = pISocketEngineSink;
}

/** 链接网络 **/
bool CSocketEngine::connect(const char* url, int port)
{
	return true;
	//initValue();

	//if (mSocket.connect(url, port) != 0)
	//	return false;
	//
	////sendTCPValidate();
	//return isAlive();
}

/** 关闭网络 **/
bool CSocketEngine::disconnect()
{
	initValue();
	mSocket.disconnect();
//	mSocket.setSocketSink(0);
	return true;
}

void CSocketEngine::initValue()
{
	m_cbSendRound = 0;
	m_cbRecvRound = 0;
	m_dwSendXorKey = 0;
	m_dwRecvXorKey = 0;
	m_dwSendPacketCount = 0;
	m_dwRecvPacketCount = 0;

	mBufRevLength = 0;
	temp_size_ = 0;
	memset(mTempBuf, 0,SIZE_TCP_BUFFER*2 );
}

/** 发送数据 **/
bool CSocketEngine::send(int main, int sub, const char * data, int dataSize)
{
	LuaEngine * pEngine = LuaEngine::defaultEngine();
	if (pEngine) {

		CCmd_Data* pData = CCmd_Data::create(dataSize);
		pData->SetCmdInfo(main, sub);
		if (dataSize > 0 && data != NULL)
		{
			pData->PushByteData((BYTE*)data, dataSize);
			pData->ResetCurrentIndex();
		}
		LuaStackEx * luaStack = static_cast<LuaStackEx*>(pEngine->getLuaStack());
		luaStack->call_script_fun("game.sendCCData", (CCObject *)pData);
	}
	return true;

	//if (!isAlive())
	//{
	//	cocos2d::log("CSocketEngine::send not send main = %d  Sub= %d datasize = %d", main, sub, dataSize);
	//	return false;
	//}
// 	// 打包数据
// 	const byte* dataSend = pack(main, sub, (byte*)data, dataSize);
// 	mSocket.send((const char*)dataSend, SIZE_PACK_HEAD+dataSize);
// 
// 	if (dataSize > SOCKET_TCP_BUFFER) return false;

	//构造数据
	//unsigned char cbDataBuffer[SOCKET_TCP_BUFFER];
	//TCP_Head * pHead = (TCP_Head *)cbDataBuffer;
	//pHead->CommandInfo.wMainCmdID = main;
	//pHead->CommandInfo.wSubCmdID = sub;
	//if (dataSize > 0)
	//{
	//	memcpy(pHead + 1, data, dataSize);
	//}	
	//cocos2d::log("CSocketEngine::send main = %d  Sub= %d datasize = %d", main, sub,dataSize);

	////加密数据
	//unsigned short wSendSize = EncryptBuffer(cbDataBuffer, sizeof(TCP_Head)+dataSize, sizeof(cbDataBuffer));

	//
	//mSocket.send((const char*)cbDataBuffer, wSendSize);
	//return true;
}

/** 状态判断 **/
bool CSocketEngine::isAlive()
{
	return mSocket.isAlive();
}

/** 发送校验 **/
void CSocketEngine::setTCPValidate(bool send)
{
	mIsSendTCPValidate = send;
}

//////////////////////////////////////////////////////////////////////////
// 接口ISocketSink
void CSocketEngine::onSocketLink()
{
	//PLAZZ_PRINTF("CSocketEngine::onSocketLink\n");
	if (mISocketEngineSink != 0)
		mISocketEngineSink->onEventTCPSocketLink();
}

void CSocketEngine::onSocketShut()
{
	if (mISocketEngineSink != nullptr)
	{
		mISocketEngineSink->onEventTCPSocketShut();
	}
	disconnect();
}

void CSocketEngine::onSocketError(int errorCode)
{
	if (mISocketEngineSink != 0)
	{
		mISocketEngineSink->onEventTCPSocketError(errorCode);
	}
	disconnect();
}

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS )
#include "bugly/CrashReport.h"
#endif


void CSocketEngine::onSocketCallBack(CCObject* pData)
{
    //log("进来2");
	CCmd_Data *pCmdpData = (CCmd_Data *)pData;
	if (pCmdpData == nullptr) return;

	WORD wMain = pCmdpData->GetMainCmd();
	WORD wSub = pCmdpData->GetSubCmd();

	if (wMain == MAIN_SOCKET_INFO)
	{
		if (wSub == SUB_SOCKET_CONNECT)
		{
			onSocketLink();
		}
		else if (wSub == SUB_SOCKET_ERROR)
		{
			onSocketError(-1);
		}
		else
		{
			onSocketShut();
		}
	}
	else
	{
		onSocketData(pData, NULL);
	}
}

void CSocketEngine::onSocketData(void* data, int dataSize)
{
	CCmd_Data *pCmdpData = (CCmd_Data *)data;
	if (mISocketEngineSink != 0)
	{
		bool bHandle = true;
		bHandle = mISocketEngineSink->onEventTCPSocketRead(pCmdpData->GetMainCmd(), pCmdpData->GetSubCmd(), (char *)pCmdpData->m_pBuffer, pCmdpData->GetBufferLenght());
		if (!bHandle)
		{
			disconnect();
			return;
		}
	}
}

//////////////////////////////////////////////////////////////////////////
// 辅助函数

//void CSocketEngine::sendTCPValidate()
//{
//	if (mIsSendTCPValidate == false)
//		return;
//	// 获取验证信息
//	QPCipher::tcpValidate(&mBufPack[0], 0);
//	// 发送验证
//	ostringstream ss;
//	ss.str("");
//	for (int i = 0; i < SIZE_VALIDATE; i++)
//	{
//		ss << mBufPack[i] << ",";
//	}
//	mSocket.send(ss.str().c_str(), (int)ss.str().size());
//}
//
//const unsigned char* CSocketEngine::pack(int main, int sub, unsigned char* data, int size)
//{
//	mBufPack[0]=0;
//	int packsize = SIZE_PACK_HEAD + size;
//	QPCipher::setPackInfo(mBufPack, packsize, main, sub);
//
//	// 赋值
//	if (size > 0) {
//		memcpy(&mBufPack[SIZE_PACK_HEAD], data, size);
//	}
//	// 加密数据
//	QPCipher::encryptBuffer(mBufPack, packsize);
//	return mBufPack;
//}
//
//bool CSocketEngine::unpack(unsigned char* data, int start, int length)
//{
//	// 解密
//	if ((data[start] & QPCipher::getCipherMode()) > 0)
//	{
//		QPCipher::decryptBuffer(data, start, length);
//	}
//	// 主命令码
//	int main = QPCipher::getMainCommand(data, start);
//	// 次命令码
//	int sub = QPCipher::getSubConmmand(data, start);
//	
//	// 附加数据
//	if (length > 8) 
//	{
//		memcpy(mBufUnPack, &data[start+8], length - 8);
//	}
//	
//	length -= 8;
//
//	
//
//	//if (SOCKET_CHECK)
//	//	PLAZZ_PRINTF("Main:%d Sub:%d Size:%d\n", main, sub, length);
//
//	
//	
//	if (main == 0 && sub == 1)
//	{
//		//PLAZZ_PRINTF("REV-HEART\n");
//	}
//	else
//	{
//		if (mISocketEngineSink != 0)
//		{
//			bool bHandle = mISocketEngineSink->onEventTCPSocketRead(main, sub, (char*)mBufUnPack, length);
//
//			//if (!bHandle)
//			//	PLAZZ_PRINTF("no match: main:%d sub:%d size:%d\n", main, sub, length);
//			return bHandle;
//		}
//	}
//	
//	return true;
//}

////加密数据
//unsigned short CSocketEngine::EncryptBuffer(unsigned char * pcbDataBuffer, unsigned short wDataSize, unsigned short wBufferSize)
//{
//#if 1
//	int cmd_len = sizeof(TCP_Command);
//
//	int info_len = sizeof(TCP_Info);
//
//	int head_len = sizeof(TCP_Head);
//	//调整长度
//	unsigned short wEncryptSize = wDataSize - cmd_len, wSnapCount = 0;
//	if ((wEncryptSize%sizeof(unsigned int)) != 0)
//	{
//		wSnapCount = sizeof(unsigned int)-wEncryptSize%sizeof(unsigned int);
//		memset(pcbDataBuffer + sizeof(TCP_Info)+wEncryptSize, 0, wSnapCount);
//	}
//
//	//效验码与字节映射
//	unsigned char cbCheckCode = 0;
//	unsigned short i = 0;
//	for (i = sizeof(TCP_Info); i < wDataSize; i++)
//	{
//		cbCheckCode += pcbDataBuffer[i];
//		//cocos2d::log("CSocketEngine::EncryptBuffer MapSendByte -- 1 -- %d  ", pcbDataBuffer[i]);
//		
//		pcbDataBuffer[i] = MapSendByte(pcbDataBuffer[i]);
//
//		//cocos2d::log("CSocketEngine::EncryptBuffer MapSendByte -- 2 -- %d  ", pcbDataBuffer[i]);
//	}
//
//	//填写信息头
//	TCP_Head * pHead = (TCP_Head *)pcbDataBuffer;
//	pHead->TCPInfo.cbCheckCode = ~cbCheckCode + 1;
//	pHead->TCPInfo.wPacketSize = wDataSize;
//
//	pHead->TCPInfo.cbDataKind = DK_MAPPED;
//
//    
//	//创建密钥
//	unsigned int dwXorKey = m_dwSendXorKey;
//	if (m_dwSendPacketCount == 0)
//	{
//		//随机映射种子
//		dwXorKey = CoTimer::getCurrentTime() * CoTimer::getCurrentTime();
//		dwXorKey = SeedRandMap((unsigned short)dwXorKey);
//		dwXorKey |= ((unsigned int)SeedRandMap((unsigned int)(dwXorKey >> 16))) << 16;
//		dwXorKey ^= g_dwPacketKey;
//		m_dwSendXorKey = dwXorKey;
//		m_dwRecvXorKey = dwXorKey;
//	}
//    
//	//加密数据
//	unsigned short * pwSeed = (unsigned short *)(pcbDataBuffer + sizeof(TCP_Info));
//	unsigned int * pdwXor = (unsigned int *)(pcbDataBuffer + sizeof(TCP_Info));
//	unsigned short wEncrypCount = (wEncryptSize + wSnapCount) / sizeof(unsigned int);
//	for (unsigned short i = 0; i < wEncrypCount; i++)
//	{
//		*pdwXor++ ^= dwXorKey;
//		dwXorKey = SeedRandMap(*pwSeed++);
//		dwXorKey |= ((unsigned int)SeedRandMap(*pwSeed++)) << 16;
//		dwXorKey ^= g_dwPacketKey;
//	}
//
//	//插入密钥
//	if (m_dwSendPacketCount == 0)
//	{
//		memmove(pcbDataBuffer + sizeof(TCP_Head)+sizeof(unsigned int), pcbDataBuffer + sizeof(TCP_Head), wDataSize);
//		//	MoveMemory(pcbDataBuffer+sizeof(CMD_Head)+sizeof(unsigned int),pcbDataBuffer+sizeof(CMD_Head),wDataSize);
//		*((unsigned int *)(pcbDataBuffer + sizeof(TCP_Head))) = m_dwSendXorKey;
//		pHead->TCPInfo.wPacketSize += sizeof(unsigned int);
//		wDataSize += sizeof(unsigned int);
//	}
//
//	//cocos2d::log("CSocketEngine::EncryptBuffer cbCheckCode -- %d   m_dwSendXorKey --- %x ----   wDataSize ---- %d", pHead->TCPInfo.cbCheckCode, m_dwSendXorKey, wDataSize);
//
//	//设置变量
//	m_dwSendPacketCount++;
//	m_dwSendXorKey = dwXorKey;
//
//	return wDataSize;
//
//#else
//	//设置变量
//	m_dwSendPacketCount++;
//
//	//填写信息头
//	TCP_Head * pHead = (TCP_Head *)pcbDataBuffer;
//	pHead->TCPInfo.wPacketSize = wDataSize;
//	pHead->TCPInfo.cbDataKind = DK_MAPPED;
//	return wDataSize;
//#endif
//}
////解密数据
//unsigned short CSocketEngine::CrevasseBuffer(unsigned char pcbDataBuffer[], unsigned short wDataSize)
//{
//#if 1
//	ASSERT(m_dwSendPacketCount > 0);
//	ASSERT(wDataSize >= sizeof(TCP_Head));
//	ASSERT(((TCP_Head *)pcbDataBuffer)->TCPInfo.wPacketSize == wDataSize);
//
//	//调整长度
//	unsigned short wSnapCount = 0;
//	if ((wDataSize%sizeof(unsigned int)) != 0)
//	{
//		wSnapCount = sizeof(unsigned int)-wDataSize%sizeof(unsigned int);
//		memset(pcbDataBuffer + wDataSize, 0, wSnapCount);
//	}
//
//	if (m_dwRecvPacketCount == 0)
//	{
//		//数据包长度错误
//		if (wDataSize < (sizeof(TCP_Head)+sizeof(unsigned int)))
//			return 0;
//
//		m_dwRecvXorKey = *(unsigned int *)(pcbDataBuffer + sizeof(TCP_Head));
//		m_dwSendXorKey = m_dwRecvXorKey;
//		memmove(pcbDataBuffer + sizeof(TCP_Head), pcbDataBuffer + sizeof(TCP_Head)+sizeof(unsigned int),
//			wDataSize - sizeof(TCP_Head)-sizeof(unsigned int));
//		wDataSize -= sizeof(unsigned int);
//		((TCP_Head *)pcbDataBuffer)->TCPInfo.wPacketSize -= sizeof(unsigned int);
//	}
//
//	//解密数据
//	unsigned int dwXorKey = m_dwRecvXorKey;
//	unsigned int * pdwXor = (unsigned int *)(pcbDataBuffer + sizeof(TCP_Info));
//	unsigned short  * pwSeed = (unsigned short *)(pcbDataBuffer + sizeof(TCP_Info));
//	unsigned short wEncrypCount = (wDataSize + wSnapCount - sizeof(TCP_Info)) / 4;
//	for (unsigned short i = 0; i<wEncrypCount; i++)
//	{
//		if ((i == (wEncrypCount - 1)) && (wSnapCount>0))
//		{
//			unsigned char * pcbKey = ((unsigned char *)&m_dwRecvXorKey) + sizeof(unsigned int)-wSnapCount;
//			memcpy(pcbDataBuffer + wDataSize, pcbKey, wSnapCount);
//		}
//		dwXorKey = SeedRandMap(*pwSeed++);
//		dwXorKey |= ((unsigned int)SeedRandMap(*pwSeed++)) << 16;
//		dwXorKey ^= g_dwPacketKey;
//		*pdwXor++ ^= m_dwRecvXorKey;
//		m_dwRecvXorKey = dwXorKey;
//	}
//
//	//效验码与字节映射
//	TCP_Head * pHead = (TCP_Head *)pcbDataBuffer;
//	unsigned char cbCheckCode = pHead->TCPInfo.cbCheckCode;
//	for (int i = sizeof(TCP_Info); i < wDataSize; i++)
//	{
//		pcbDataBuffer[i] = MapRecvByte(pcbDataBuffer[i]);
//		cbCheckCode += pcbDataBuffer[i];
//	}
//	if (cbCheckCode != 0)
//	{
//		return 0;
//	}
//
//	return wDataSize;
//#else
//	return wDataSize;
//#endif
//}
//
////随机映射
//unsigned short CSocketEngine::SeedRandMap(unsigned short wSeed)
//{
//	unsigned int dwHold = wSeed;
//	return (unsigned short)((dwHold = dwHold * 241103L + 2533101L) >> 16);
//}
//
////映射发送数据
//unsigned char CSocketEngine::MapSendByte(unsigned char const cbData)
//{
//	unsigned char cbMap = g_SendByteMap[(unsigned char)(cbData + m_cbSendRound)];
//	
//	// cocos2d::log("CSocketEngine::EncryptBuffer MapSendByte -- g_SendByteMap->cbMap -- %d-----%d---%d  ", cbMap, m_cbSendRound, cbData);
//	
//	m_cbSendRound += 3;
//	return cbMap;
//}
//
////映射接收数据
//unsigned char CSocketEngine::MapRecvByte(unsigned char const cbData)
//{
//	unsigned char cbMap = g_RecvByteMap[cbData] - m_cbRecvRound;
//	m_cbRecvRound += 3;
//	return cbMap;
//}
