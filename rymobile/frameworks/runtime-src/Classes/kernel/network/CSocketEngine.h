#ifndef _SocketEngine_H_
#define _SocketEngine_H_
#pragma once
#include "ISocketEngine.h"
#include "ISocketSink.h"
#include "../socket/Socket.h"

typedef unsigned char byte;


class CSocketEngine
	: public ISocketEngine
	, public ISocketSink
{
public:
	CSocketEngine();
	virtual ~CSocketEngine();

	//////////////////////////////////////////////////////////////////////////
	// 接口ISocketEngine
public:
	/** 设置Socket接收器 */
	virtual void setSocketEngineSink(ISocketEngineSink* pISocketEngineSink);
	/** 链接网络 **/
	virtual bool connect(const char* url, int port);
	/** 关闭网络 **/
	virtual bool disconnect();
	/** 发送数据 **/
	virtual bool send(int main, int sub, const char * data, int dataSize);
	/** 状态判断 **/
	virtual bool isAlive();
	/** 发送校验 **/
	virtual void setTCPValidate(bool send);

protected:
	void initValue();

	//////////////////////////////////////////////////////////////////////////
	// 接口ISocketSink
public:
	virtual void onSocketLink();
	virtual void onSocketShut();
	virtual void onSocketError(int errorCode);
	virtual void onSocketData(void* data, int dataSize);
	virtual void onSocketCallBack(CCObject* pData);

	//////////////////////////////////////////////////////////////////////////
	// 辅助函数
private:
	//void sendTCPValidate();
	//const unsigned char* pack(int main, int sub, unsigned char* data, int size);
	//bool unpack(unsigned char* data, int start, int length);

private:
	// 接收处理模块
	ISocketEngineSink* mISocketEngineSink;
	// 连接SOCKET
	CSocket mSocket;
	// 发送校验
	bool mIsSendTCPValidate;
	
	//////////////////////////////////////////////////////////////////////////
	// 数据缓冲
private:
	// 临时缓冲
	unsigned char mBufPack[SIZE_TCP_BUFFER];
	unsigned char mBufUnPack[SIZE_TCP_BUFFER];
	// 接收缓冲
	unsigned char mBufRecieve[SIZE_TCP_BUFFER];
	// 接收长度
	int mBufRevLength;

	//  add by  lesten
private:
	byte mTempBuf[SIZE_TCP_BUFFER * 2];
	unsigned int temp_size_;

	//加密数据
protected:
	unsigned char							m_cbSendRound;						//字节映射
	unsigned char							m_cbRecvRound;						//字节映射
	unsigned int							m_dwSendXorKey;						//发送密钥
	unsigned int							m_dwRecvXorKey;						//接收密钥

	//计数变量
	unsigned long							m_dwSendPacketCount;				//发送计数
	unsigned long							m_dwRecvPacketCount;				//接受计数
public:
	//加密数据
	//unsigned short EncryptBuffer(unsigned char * pcbDataBuffer, unsigned short wDataSize, unsigned short wBufferSize);
	////解密数据
	//unsigned short CrevasseBuffer(unsigned char pcbDataBuffer[], unsigned short wDataSize);
	////随机映射
	//inline unsigned short SeedRandMap(unsigned short wSeed);
	////映射发送数据
	//inline unsigned char MapSendByte(unsigned char const cbData);
	////映射接收数据
	//inline unsigned char MapRecvByte(unsigned char const cbData);
};

#endif // _SocketEngine_H_
