//
//  CryptHelper.cpp
//  Zhadizhu58
//
//  Created by ccy on 2017/7/11.
//
//

#include "CryptHelper.h"


#pragma mark - AES Crypto

#define BLOCKLEN 16 //Block length in bytes AES is 128b block only

int CryptHelper::AESFormatLength(int len)
{
    uint8_t extra = len % BLOCKLEN;
    if (extra != 0) {
        len += (BLOCKLEN - len % BLOCKLEN);
    }
    return len;
}
// AES加密字符串函数
string CryptHelper::AESEncryptString(const char *instr, int length, const unsigned char keyPhrase[])
{
    uint8_t iv[]  = { 0x12,0x5C,0x8B,0xBC,0x61,0x63,0xF6,0xA5,0xE1,0x65,0xD8,0xF5,0x5A,0x07,0xF0,0x13 };
    
    int len = AESFormatLength(length);
    unsigned char tmpbuffer[len];
    memset(tmpbuffer, 0, len);
    memcpy(tmpbuffer, instr, length);
    
    unsigned char outBuffer[len];
    memset(outBuffer, 0, sizeof(outBuffer));
    
    length = len;
    
    AES::AES_CBC_encrypt_buffer(outBuffer, tmpbuffer, length, keyPhrase, iv);
    
    printf("CBC encrypt: \n");
    for (int i=0 ; i<length; i++) {
        printf("%02x ", outBuffer[i] & 0xff);
        if ((i+1)%16==0) {
            printf("\n");
        }
    }
    printf("\n");
    
    stringstream ss;
    for (int i = 0; i != sizeof(outBuffer)/sizeof(unsigned char); ++i) {
        ss <<  (unsigned char)outBuffer[i];
    }
    string str1(ss.str());
    return str1;
    
}
// AES解密字符串函数
string CryptHelper::AESDecryptString(const char *instr, int length, const unsigned char keyPhrase[])
{
    uint8_t iv[]  = { 0x12,0x5C,0x8B,0xBC,0x61,0x63,0xF6,0xA5,0xE1,0x65,0xD8,0xF5,0x5A,0x07,0xF0,0x13 };
    
    length = AESFormatLength(length);
    
    unsigned char buffer[length];
    
    AES::AES_CBC_decrypt_buffer(buffer, (unsigned char *)instr, length, keyPhrase, iv);
    
    printf("CBC decrypt: \n");
    for (int i=0 ; i<length; i++) {
        printf("%02x ", buffer[i] & 0xff);
        if ((i+1)%16==0) {
            printf("\n");
        }
    }
    printf("\n");
    
    stringstream ss;
    for (int i = 0; i != sizeof(buffer)/sizeof(unsigned char); ++i) {
        ss <<  (unsigned char)buffer[i];
    }
    string str1(ss.str());
    return str1;
}
// AES加密字符串函数(outStr数组需要事先初始化，数组的长度必须为格式化format(length)后大小)
/**
 char outstr[CryptHelper::AESFormatLength(len)];
 CryptHelper::AESEncryptString_buffer(instr, outstr, len, aes_key);
 */
 void CryptHelper::AESEncryptString_buffer(const char *instr, char *outstr, int &length, const unsigned char keyPhrase[])
{
    uint8_t aes_key[] = {0x15, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x2b, 0x88, 0x09, 0xcf, 0x4f, 0x3c };
    uint8_t iv[]  = { 0x12, 0x5C, 0x8B, 0xBC, 0x61, 0x63, 0xF6, 0xA5, 0xE1, 0x65, 0xD8, 0xF5, 0x5A, 0x07, 0xF0, 0x13 };
    
    int outLen = AESFormatLength(length);
    unsigned char tmpStr[outLen];
    memset(tmpStr, 0, outLen);
    memcpy(tmpStr, instr, length);
    length = outLen;
    
    if (keyPhrase == 0) {
        AES::AES_CBC_encrypt_buffer((unsigned char*)outstr, tmpStr, length, aes_key, iv);
    }else {
        AES::AES_CBC_encrypt_buffer((unsigned char*)outstr, tmpStr, length, keyPhrase, iv);
    }
    
    /*printf("CBC encrypt: \n");
    for (int i=0 ; i<length; i++) {
        printf("%02x ", outstr[i] & 0xff);
        if ((i+1)%16==0) {
            printf("\n");
        }
    }
    printf("\n");*/
    
}
// AES解密字符串函数(outStr数组需要事先初始化，数组的长度必须为格式化format(length)后大小)
/**
 char outstr[CryptHelper::AESFormatLength(len)];
 CryptHelper::AESDecryptString_buffer(instr, outstr, len, aes_key);
 */
 void CryptHelper::AESDecryptString_buffer(const char *instr, char *outstr, int &length, const unsigned char keyPhrase[])
{
    uint8_t aes_key[] = {0x15, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x2b, 0x88, 0x09, 0xcf, 0x4f, 0x3c };
    uint8_t iv[]  = {  0x12, 0x5C, 0x8B, 0xBC, 0x61, 0x63, 0xF6, 0xA5, 0xE1, 0x65, 0xD8, 0xF5, 0x5A, 0x07, 0xF0, 0x13 };
    
    length = AESFormatLength(length);
    
    if (keyPhrase == 0) {
        AES::AES_CBC_decrypt_buffer((unsigned char *)outstr, (unsigned char *)instr, length, aes_key, iv);
    }else {
        AES::AES_CBC_decrypt_buffer((unsigned char *)outstr, (unsigned char *)instr, length, keyPhrase, iv);
    }
    
    
    /*printf("CBC decrypt: \n");
    for (int i=0 ; i<length; i++) {
        printf("%02x ", outstr[i] & 0xff);
        if ((i+1)%16==0) {
            printf("\n");
        }
    }
    printf("\n");*/
    
}
