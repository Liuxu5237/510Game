#ifndef _PacketWriteAide_H_
#define _PacketWriteAide_H_

#include "Convert.h"
#include <string>
#include "cocos2d.h"
#include "kernel/network/ISocketEngine.h"

class PacketWriteAide : public cocos2d::Ref
{
private:
	unsigned char mData[SIZE_PACK_DATA];
	int mPos;
public:
	/**
	* @param data 网络数据
	* @param index 起始下标
	*/
	PacketWriteAide(int pos = 0) : mPos(pos)
	{
	}

	void setPosition(int pos)
	{
		mPos = pos;
	}

	int getPosition() const
	{
		return mPos;
	}

	cocos2d::Ref * getBuffer()
	{
		return (cocos2d::Ref *)this;
	}

	const char * getBufferData() const
	{
		return (const char * )mData;
	}


	void writeByte(unsigned int val)
	{
		mData[mPos + 0] = (unsigned char)(val & 0xff);
		mPos += 1;
	}

	void write2Byte(unsigned int val)
	{
		mData[mPos + 1] = (unsigned char)((val >> 8) & 0xff);
		mData[mPos + 0] = (unsigned char)((val)& 0xff);
		mPos += 2;
	}

	void write4Byte(unsigned int val)
	{
		mData[mPos + 3] = (unsigned char)((val >> 24) & 0xff);
		mData[mPos + 2] = (unsigned char)((val >> 16) & 0xff);
		mData[mPos + 1] = (unsigned char)((val >> 8) & 0xff);
		mData[mPos + 0] = (unsigned char)((val)& 0xff);
		//ipone 会报错 ARM EXC_ARM_DA_ALIGN
		//unsigned int* pVal = (unsigned int*)&mData[mPos];
		//*pVal = val;
		mPos += 4;
	}

	/*void write4Bytes(unsigned int* ary, int count)
	{
	int size = count*sizeof(unsigned int);
	memcpy(&mData[mPos], ary, size);
	mPos += size;
	}
	*/
	void write8Byte(long long val)
	{
		mData[mPos + 7] = (unsigned char)((val >> 56) & 0xff);
		mData[mPos + 6] = (unsigned char)((val >> 48) & 0xff);
		mData[mPos + 5] = (unsigned char)((val >> 40) & 0xff);
		mData[mPos + 4] = (unsigned char)((val >> 32) & 0xff);
		mData[mPos + 3] = (unsigned char)((val >> 24) & 0xff);
		mData[mPos + 2] = (unsigned char)((val >> 16) & 0xff);
		mData[mPos + 1] = (unsigned char)((val >> 8) & 0xff);
		mData[mPos + 0] = (unsigned char)(val & 0xff);
		mPos += 8;
	}

	void writeString(const char * strData, int len)
	{
		const u2string & u2 = utf8_ucs2(strData);
		const unsigned short* data = &u2[0];
	
		int ucs2len = ucs2_len(data);
		if (ucs2len > len)
			ucs2len = len;

		for (int i = 0; i < ucs2len; ++i)
		{
			mData[mPos + i * 2 + 1] = (data[i] >> 8) & 0xff;
			mData[mPos + i * 2 + 0] = (data[i]) & 0xff;
		}

		for (int i = ucs2len; i < len; ++i)
		{
			mData[mPos + i * 2 + 1] = '\0';
			mData[mPos + i * 2 + 0] = '\0';
		}

		mPos += len * 2;
	}

	void writeString(const char * strData)
	{
		const u2string & u2 = utf8_ucs2(strData);
		const unsigned short* data = &u2[0];

		int ucs2len = ucs2_len(data);
	
		for (int i = 0; i < ucs2len; ++i)
		{
			mData[mPos + i * 2 + 1] = (data[i] >> 8) & 0xff;
			mData[mPos + i * 2 + 0] = (data[i]) & 0xff;
		}

		mPos += ucs2len * 2;
	}

	void writeStdString(const char * strData, int len)
	{
		for (int i = 0; i < len; ++i)
		{
			mData[mPos + i] = strData[i];
		}
		mPos += len;
	}

	/*void writeUTF16(const unsigned short* data, int len)
	{
	int ucs2len = ucs2_len(data);
	if (ucs2len>len)ucs2len = len;

	for (int i = 0; i < ucs2len; ++i)
	{
	mData[mPos + i * 2 + 1] = (data[i] >> 8) & 0xff;
	mData[mPos + i * 2 + 0] = (data[i]) & 0xff;
	}

	for (int i = ucs2len; i < len; ++i)
	{
	mData[mPos + i * 2 + 1] = '\0';
	mData[mPos + i * 2 + 0] = '\0';
	}

	mPos += len * 2;
	}

	void writeUTF16(const u2string& u2, int len)
	{
	const unsigned short* data = &u2[0];
	int ucs2len = ucs2_len(data);
	if (ucs2len>len)ucs2len = len;

	for (int i = 0; i < ucs2len; ++i)
	{
	mData[mPos + i * 2 + 1] = (data[i] >> 8) & 0xff;
	mData[mPos + i * 2 + 0] = (data[i]) & 0xff;
	}

	for (int i = ucs2len; i < len; ++i)
	{
	mData[mPos + i * 2 + 1] = '\0';
	mData[mPos + i * 2 + 0] = '\0';
	}

	mPos += len * 2;
	}*/
};

#define PACKET_AIDE_SIZE() PacketWriteAide packet

#endif // _PacketAide_H_