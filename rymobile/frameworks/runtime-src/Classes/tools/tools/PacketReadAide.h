#ifndef _PacketReadAide_H_
#define _PacketReadAide_H_

#include "Convert.h"
#include <string>
#include "cocos2d.h"
/**
 * 数据包读取辅助
 */
class PacketReadAide : public cocos2d::Ref
{
private:
	void * mData;
	int mPos;
public:
	void setData(void * data, int pos = 0)
	{
		mData = data;
		mPos = pos;
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
		return (cocos2d::Ref *)mData;
	}

	unsigned int readByte()
	{
		unsigned int ret = (((const unsigned char *)mData)[mPos+0]);
		mPos += 1;
		return ret;
	}

	unsigned int read2Byte()
	{
		unsigned int ret = ((unsigned int)((((const unsigned char *)mData)[mPos + 1] & 0xff) << 8) | (((const unsigned char *)mData)[mPos + 0] & 0xff));
		mPos +=2;
		return ret;
	}

	unsigned int read4Byte()
	{
		unsigned int ret = (
			((unsigned int)(((const unsigned char *)mData)[mPos + 3] & 0xff) << 24) |
			((unsigned int)(((const unsigned char *)mData)[mPos + 2] & 0xff) << 16) |
			((unsigned int)(((const unsigned char *)mData)[mPos + 1] & 0xff) << 8) |
			((unsigned int)(((const unsigned char *)mData)[mPos + 0] & 0xff)));
		//ipone 会报错 ARM EXC_ARM_DA_ALIGN
		//unsigned int ret = *(unsigned int*)&mData[mPos];
		mPos +=4;
		return ret;
	}

	unsigned long long readu8Byte()
	{
		unsigned long long ret = (
			((unsigned long long)(((const unsigned char *)mData)[mPos + 7] & 0xff) << 56) |
			((unsigned long long)(((const unsigned char *)mData)[mPos + 6] & 0xff) << 48) |
			((unsigned long long)(((const unsigned char *)mData)[mPos + 5] & 0xff) << 40) |
			((unsigned long long)(((const unsigned char *)mData)[mPos + 4] & 0xff) << 32) |
			((unsigned long long)(((const unsigned char *)mData)[mPos + 3] & 0xff) << 24) |
			((unsigned long long)(((const unsigned char *)mData)[mPos + 2] & 0xff) << 16) |
			((unsigned long long)(((const unsigned char *)mData)[mPos + 1] & 0xff) << 8) |
			((unsigned long long)(((const unsigned char *)mData)[mPos + 0] & 0xff)));
		
		mPos += 8;
		return ret;
	}

	long readLong()
	{
		long ret = (
			((long)(((const char *)mData)[mPos + 3] & 0xff) << 24) |
			((long)(((const char *)mData)[mPos + 2] & 0xff) << 16) |
			((long)(((const char *)mData)[mPos + 1] & 0xff) << 8) |
			((long)(((const char *)mData)[mPos + 0] & 0xff)));

		mPos += 4;
		return ret;
	}

	int readInt32()
	{
		int ret = (
			((int)(((const char *)mData)[mPos + 3] & 0xff) << 24) |
			((int)(((const char *)mData)[mPos + 2] & 0xff) << 16) |
			((int)(((const char *)mData)[mPos + 1] & 0xff) << 8) |
			((int)(((const char *)mData)[mPos + 0] & 0xff)));

		mPos += 4;
		return ret;
	}

	short readInt16()
	{
		short ret = (
			((short)(((const char *)mData)[mPos + 1] & 0xff) << 8) |
			((short)(((const char *)mData)[mPos + 0] & 0xff)));

		mPos += 2;
		return ret;
	}
	
	/*unsigned int* read4Bytes(unsigned int* ary, int count)
	{
	int size = sizeof(unsigned int)*4;
	memcpy(ary, &mData[mPos], size);
	mPos+=size;
	return ary;
	}*/

	long long read8Byte()
	{
		long long ret = (
			((long long)(((const unsigned char *)mData)[mPos + 7] & 0xff) << 56) |
			((long long)(((const unsigned char *)mData)[mPos + 6] & 0xff) << 48) |
			((long long)(((const unsigned char *)mData)[mPos + 5] & 0xff) << 40) |
			((long long)(((const unsigned char *)mData)[mPos + 4] & 0xff) << 32) |
			((long long)(((const unsigned char *)mData)[mPos + 3] & 0xff) << 24) |
			((long long)(((const unsigned char *)mData)[mPos + 2] & 0xff) << 16) |
			((long long)(((const unsigned char *)mData)[mPos + 1] & 0xff) << 8) |
			((long long)(((const unsigned char *)mData)[mPos + 0] & 0xff)));

		mPos +=8;
		return ret;
	}

	

	std::string readString(int len)
	{
		u2string str;
		str.resize(len + 1, '\0');
		readUTF16(&str[0], len);

		return ucs2_utf8((const unsigned short*)&str[0]);//u2_8(&str[0]);
	}

	std::string readStdString(int len)
	{
		u1stringEx  str;
		str.resize(len + 1, '\0');
		readUTF8(&str[0],len);
		return a_u8(ucs1_utf8((const unsigned char *)&str[0],len).c_str());
	}

protected:
	void readUTF16(unsigned short* data, int len)
	{
		if (data != nullptr)
		{	
			for (int i = 0; i < len; ++i)
			{
				data[i] = (((const unsigned char *)mData)[mPos + i * 2 + 1] << 8) | ((const unsigned char *)mData)[mPos + i * 2 + 0];
			}
			mPos += len * 2;
		}
	}

	u2string readUTF16(int len)
	{
		static u2string ret;
		ret.resize(len+1, '\0');
		for (int i = 0; i < len; ++i)
		{
			ret[i] = (((const unsigned char *)mData)[mPos + i * 2 + 1] << 8) | ((const unsigned char *)mData)[mPos + i * 2 + 0];
		}

		mPos += len * 2;

		return ret;
	}
	void readUTF8(unsigned char * data, int len)
	{
		if (data != nullptr)
		{
			for (int i = 0; i < len; ++i)
			{
				data[i] = ((const unsigned char *)mData)[mPos + i];
			}
			mPos += len;
		}
	}
};

#define PACKET_AIDE_DATA(data) PacketReadAide packet;			\
	packet.setData(data);	
#endif // _PacketAide_H_
