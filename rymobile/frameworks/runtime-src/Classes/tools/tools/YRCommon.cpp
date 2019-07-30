#include "YRCommon.h"

#define IMG_HEAD_PHOTO_1  "TX-1.png"
#define IMG_HEAD_PHOTO_2  "TX-2.png"
#define IMG_HEAD_PHOTO_3  "TX-3.png"
#define IMG_HEAD_PHOTO_4  "TX-4.png"
#define IMG_HEAD_PHOTO_5  "TX-5.png"
#define IMG_HEAD_PHOTO_6  "TX-6.png"
#define IMG_HEAD_PHOTO_7  "TX-7.png"
#define IMG_HEAD_PHOTO_8  "TX-8.png"
#define IMG_HEAD_PHOTO_9  "TX-9.png"
#define IMG_HEAD_PHOTO_10  "TX-10.png"
const char * YRComGetHeadImageById(int head_id)
{
	switch (head_id)
	{
		case 0:
			return IMG_HEAD_PHOTO_1;
		case 1:
			return IMG_HEAD_PHOTO_2;
		case 2:
			return IMG_HEAD_PHOTO_3;
		case 3:
			return IMG_HEAD_PHOTO_4;
		case 4:
			return IMG_HEAD_PHOTO_5;
		case 5:
			return IMG_HEAD_PHOTO_6;
		case 6:
			return IMG_HEAD_PHOTO_7;
		case 7:
			return IMG_HEAD_PHOTO_8;
		case 8:
			return IMG_HEAD_PHOTO_9;
		case 9:
			return IMG_HEAD_PHOTO_10;
		default:
			return IMG_HEAD_PHOTO_1;
	}
}

bool YRComStringIsNumber(const std::string strString)
{
	if (strString.empty()) return false;

	for (std::string::size_type i = 0; i < strString.size(); i++)
	{
		auto ch = strString[i];
		if (ch >= '0' && ch <= '9')
			continue;
		return false;
	}
	return true;
}