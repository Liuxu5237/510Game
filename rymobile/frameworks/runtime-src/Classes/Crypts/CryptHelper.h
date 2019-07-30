//
//  CryptHelper.hpp
//  Zhadizhu58
//
//  Created by ccy on 2017/7/11.
//
//

#ifndef CryptHelper_hpp
#define CryptHelper_hpp

#include "cocos2d.h"
#include "Tbase64.h"
#include "aes.h"

USING_NS_CC;
using namespace std;

class CryptHelper {
    
public:
    // AES加密字符串函数(CBC)
    static int AESFormatLength(int len);
    static string AESEncryptString(const char *instr, int length, const unsigned char keyPhrase[]);
    static string AESDecryptString(const char *instr, int length, const unsigned char keyPhrase[]);
     static void AESEncryptString_buffer(const char *instr, char *outstr, int &length, const unsigned char keyPhrase[]=0);
     static void AESDecryptString_buffer(const char *instr, char *outstr, int &length, const unsigned char keyPhrase[]=0);
    
};

#endif /* EncryptHelper_hpp */
