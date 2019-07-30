#ifndef _TAILORVIEW_H_
#define _TAILORVIEW_H_

#include "cocos2d.h"
USING_NS_CC;

class TailorView : public CCNode
{
public:
	virtual void visit(Renderer *renderer, const Mat4& parentTransform, uint32_t parentFlags);
	static TailorView* create(const CCSize &size);
private:
};

//裁剪框

#endif
// 裁剪框  

