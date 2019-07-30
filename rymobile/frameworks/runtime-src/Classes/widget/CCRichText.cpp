#include "CCRichText.h"


bool CCRichText::init()
{
	if (!CCNode::init())
		return false;

	mOpacity = 255;
	return true;
}

void CCRichText::setColor(const ccColor3B& color)
{
	mColor = color;
}

const ccColor3B& CCRichText::getColor(void)
{
	return mColor;
}

const ccColor3B& CCRichText::getDisplayedColor(void)
{
	return mColor;
}

GLubyte CCRichText::getDisplayedOpacity(void)
{
	return mOpacity;
}

GLubyte CCRichText::getOpacity(void)
{
	return mOpacity;
}

void CCRichText::setOpacity(GLubyte opacity)
{
	if (mOpacity == opacity)
		return;
	mOpacity = opacity;

	auto ary = getChildren();
	for (int i = 0, l = (int)getChildrenCount(); i < l; ++i)
	{
		CCNodeRGBA* rgbaNode = (CCNodeRGBA*)ary.at(i);

		if (rgbaNode)
		{
			rgbaNode->setOpacity(opacity);
		}
	}
}

void CCRichText::setOpacityModifyRGB(bool bValue)
{
	mIsOpqcity = bValue;
}

bool CCRichText::isOpacityModifyRGB(void)
{
	return mIsOpqcity;
}

bool CCRichText::isCascadeColorEnabled(void)
{
	return true;
}

void CCRichText::setCascadeColorEnabled(bool cascadeColorEnabled)
{

}

void CCRichText::updateDisplayedColor(const ccColor3B& color)
{

}

bool CCRichText::isCascadeOpacityEnabled(void)
{
	return true;
}

void CCRichText::setCascadeOpacityEnabled(bool cascadeOpacityEnabled)
{

}

void CCRichText::updateDisplayedOpacity(GLubyte opacity)
{
	mOpacity = opacity;
}
