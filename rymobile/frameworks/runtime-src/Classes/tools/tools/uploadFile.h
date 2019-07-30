#ifndef __UPLOADFILE_H__
#define __UPLOADFILE_H__

#include "cocos2d.h"

using namespace cocos2d;
using namespace std;
/**
@brief    The cocos2d Application.

The reason for implement as private inheritance is to hide some interface call by Director.
*/
class  uploadFile : public CCObject
{
private:
	static string m_photoPath;
public:
    static uploadFile *m_inst;
    static uploadFile *GetInst();
    
    bool UpLoadFile(string photoPath);
	bool GetUpLoadFileSuccess(string photoPath);
    
    static size_t write_data(uint8_t *dataBack, size_t size, size_t nmemb, void *userp);
};

#endif  // __UPLOADFILE_H__

