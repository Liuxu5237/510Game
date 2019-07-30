#ifndef YRCOMMON_H_
#define YRCOMMON_H_

#include "cocos2d.h"

/*
 *	������Դ
 */
//��ȡͷ��
const char * YRComGetHeadImageById(int head_id);

/*
 *	��������
 */
//�ַ����Ƿ�ȫ������
bool YRComStringIsNumber(const std::string strString);

///< ���������ֹ��ɵ��ı�
#define DIGIT_SCALE(target, cond) if((cond) > (2 << 22)) target->setScale(0.7f); \
			else target->setScale(0.8f);

///cocos2d::Vec2 YRComGetConfineToRandomVec2(cocos2d::Vec2 & oprign, int radius);

#endif //YRCOMMON_H_

