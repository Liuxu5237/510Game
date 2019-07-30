#ifndef Lkpy_RICHTEXT_H_
#define Lkpy_RICHTEXT_H_

#include "cocos2d.h"

USING_NS_CC;

class CCRichText : public CCNode
{
public:
	CREATE_FUNC(CCRichText);

public:
	bool init();

	/**
	* Changes the color with R,G,B bytes
	*
	* @param color Example: ccc3(255,100,0) means R=255, G=100, B=0
	*/
	virtual void setColor(const ccColor3B& color);

	/**
	* Returns color that is currently used.
	*
	* @return The ccColor3B contains R,G,B bytes.
	*/
	virtual const ccColor3B& getColor(void);

	/**
	* Returns the displayed color.
	*
	* @return The ccColor3B contains R,G,B bytes.
	*/
	virtual const ccColor3B& getDisplayedColor(void);

	/**
	* Returns the displayed opacity.
	*
	* @return  The opacity of sprite, from 0 ~ 255
	*/
	virtual GLubyte getDisplayedOpacity(void);
	/**
	* Returns the opacity.
	*
	* The opacity which indicates how transparent or opaque this node is.
	* 0 indicates fully transparent and 255 is fully opaque.
	*
	* @return  The opacity of sprite, from 0 ~ 255
	*/
	virtual GLubyte getOpacity(void);

	/**
	* Changes the opacity.
	*
	* @param   value   Goes from 0 to 255, where 255 means fully opaque and 0 means fully transparent.
	*/
	virtual void setOpacity(GLubyte opacity);

	// optional

	/**
	* Changes the OpacityModifyRGB property.
	* If thie property is set to true, then the rendered color will be affected by opacity.
	* Normally, r = r * opacity/255, g = g * opacity/255, b = b * opacity/255.
	*
	* @param   bValue  true then the opacity will be applied as: glColor(R,G,B,opacity);
	*                  false then the opacity will be applied as: glColor(opacity, opacity, opacity, opacity);
	*/
	virtual void setOpacityModifyRGB(bool bValue);

	/**
	* Returns whether or not the opacity will be applied using glColor(R,G,B,opacity)
	* or glColor(opacity, opacity, opacity, opacity)
	*
	* @return  Returns opacity modify flag.
	*/
	virtual bool isOpacityModifyRGB(void);

	/**
	*  whether or not color should be propagated to its children.
	*/
	virtual bool isCascadeColorEnabled(void);

	virtual void setCascadeColorEnabled(bool cascadeColorEnabled);

	/**
	*  recursive method that updates display color
	*/
	virtual void updateDisplayedColor(const ccColor3B& color);

	/**
	*  whether or not opacity should be propagated to its children.
	*/
	virtual bool isCascadeOpacityEnabled(void);

	virtual void setCascadeOpacityEnabled(bool cascadeOpacityEnabled);

	/**
	*  recursive method that updates the displayed opacity.
	*/
	virtual void updateDisplayedOpacity(GLubyte opacity);

protected:
	bool  mIsOpqcity;
	ccColor3B mColor;
	GLubyte	mOpacity;
};

//////////////////////////////////////////////////////////////////////////
#endif

