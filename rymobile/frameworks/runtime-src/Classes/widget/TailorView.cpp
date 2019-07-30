#include "TailorView.h"

void TailorView::visit(Renderer *renderer, const Mat4& parentTransform, uint32_t parentFlags)
{
	Node::visit(renderer, parentTransform, parentFlags);

	glEnable(GL_SCISSOR_TEST);              // 开启显示指定区域  
	float n_width = this->getContentSize().width;
	float n_height = this->getContentSize().height;
	CCPoint p = this->convertToWorldSpace(ccp(0, 0));
	CCPoint pw = this->convertToWorldSpace(ccp(n_width, n_height));
	CCDirector::sharedDirector()->getOpenGLView()->setScissorInPoints(p.x, p.y, pw.x - p.x, pw.y - p.y);
	CCNode::visit();
	glDisable(GL_SCISSOR_TEST);
}

TailorView* TailorView::create(const CCSize &size)
{
	TailorView* pLayer = new TailorView();
	pLayer->setAnchorPoint(ccp(0, 0));
	pLayer->setContentSize(size);
	pLayer->setPosition(0, 0);
	pLayer->autorelease();
	return pLayer;
}
