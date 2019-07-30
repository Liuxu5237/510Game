#include "SpriteHelper.h"
#include "../../tools/DictionaryAide.h"

//#include "lesten/Convert.h"

#include <cocos/deprecated/CCDictionary.h>

USING_NS_CC;

void cachAnimation(__Dictionary* info)
{
	SpriteFrameCache *cache = SpriteFrameCache::getInstance();
	DictionaryAide aide(info);

	const char* name = aide.stringFromKey("name");
	const char* format = aide.stringFromKey("format");
	float delay = aide.floatFromKey("delay");
	__Array* frames = aide.arrayFromKey("frames");
	int count = frames == 0 ? 0 : frames->count();
	CCAssert(frames != 0, "frames is null");

	Vector<SpriteFrame*> animFrames = Vector<SpriteFrame*>(count); // Vector::createWithCapacity(count);

	char str[80];
	for (int k = 0; k < count; k++)
	{
		const char* sFrame = ((__String*)frames->getObjectAtIndex(k))->getCString();
		int frame = -1;
		float frameDelay = 0;
		sscanf(sFrame, "%d,%f", &frame, &frameDelay);
		sprintf(str, format, frame);
		SpriteFrame *sptFrame = cache->getSpriteFrameByName(str);
		//CCLOG("photo name is ==%s", str);
		CCAssert(sptFrame != 0, str);

		if (sptFrame)
		{
			//AnimationFrame* aniFrame = AnimationFrame::create(sptFrame, frameDelay, ValueMapNull);
			animFrames.pushBack(sptFrame);
			//aniFrame->release();
		}
	}

	Animation *animation = Animation::createWithSpriteFrames(animFrames, delay / 3 * 2);
	//bool haveReBack = animation->getRestoreOriginalFrame();
	AnimationCache::getInstance()->addAnimation(animation, name);
	//animation->release();
}

cocos2d::Animate* SpriteHelper::createAnimate(const char* name)
{
	Animation* animation = AnimationCache::getInstance()->getAnimation(name);
	if (animation == 0)
		return 0;

	CCAnimate* animate = Animate::create(animation);
	return animate;
}

cocos2d::Animate* SpriteHelper::createEffectAnimate(const char* name, float time)
{
	Animation* animation = AnimationCache::getInstance()->getAnimation(name);
	if (animation == 0)
		return 0;

	CCAnimate* animate = Animate::create(animation);
	animate->setDuration(time);

	return animate;
}

Animate* SpriteHelper::createBirdAnimate(int type)
{
	char str[80];
	sprintf(str, "bird%d_move", type);
	return createAnimate(str);
}

Animate* SpriteHelper::createBirdDeadAnimate(int type)
{
	char str[80];
	if (type > 25)
	{
		sprintf(str, "bird%d_dead", type);
	}
	else
	{
		sprintf(str, "bird%d_move", type);
	}
	return createAnimate(str);
}

Animate* SpriteHelper::createJdbyBirdDeadAnimate(int type)
{
	char str[80];
	sprintf(str, "bird%d_dead", type);
	return createAnimate(str);
}

// bool SpriteHelper::cacheAnimations()
// {
// 	CCArray* arr = CCArray::createWithContentsOfFile("animations.plist");
// 	if (arr == 0)
// 		return false;
// 
// 	for (int i = 0, l = arr->count(); i < l; ++i)
// 	{
// 		const char* name = ((CCString*)arr->objectAtIndex(i))->getCString();
// 		char plist_name[64] = { 0 };
// 		sprintf(plist_name, "%s.plist", name);
// 		CCArray* arr2 = CCArray::createWithContentsOfFile(plist_name);
// 
// 		for (int j = 0, jl = (int)arr2->count(); j < jl; ++j)
// 		{
// 			CCDictionary* ani = (CCDictionary*)arr2->objectAtIndex(j);
// 			CCAssert(ani != 0, name);
// 
// 			if (ani == 0)
// 				continue;
// 
// 			::cachAnimation(ani);
// 		}
// 	}
// 
// 	return true;
// }

static __Array* visitArray(const ValueVector& array);

static __Dictionary* visitDict(const ValueMap& dict)
{
	__Dictionary* ret = new __Dictionary();
	ret->init();

	for (auto iter = dict.begin(); iter != dict.end(); ++iter)
	{
		if (iter->second.getType() == Value::Type::MAP)
		{
			const ValueMap& subDict = iter->second.asValueMap();
			auto sub = visitDict(subDict);
			ret->setObject(sub, iter->first);
			sub->release();
		}
		else if (iter->second.getType() == Value::Type::VECTOR)
		{
			const ValueVector& arr = iter->second.asValueVector();
			auto sub = visitArray(arr);
			ret->setObject(sub, iter->first);
			sub->release();
		}
		else
		{
			auto str = new __String(iter->second.asString());
			ret->setObject(str, iter->first);
			str->release();
		}
	}
	return ret;
}

static __Array* visitArray(const ValueVector& array)
{
	__Array* ret = new __Array();
	ret->init();

	for (const auto &value : array) {
		if (value.getType() == Value::Type::MAP)
		{
			const ValueMap& subDict = value.asValueMap();
			auto sub = visitDict(subDict);
			ret->addObject(sub);
			sub->release();
		}
		else if (value.getType() == Value::Type::VECTOR)
		{
			const ValueVector& arr = value.asValueVector();
			auto sub = visitArray(arr);
			ret->addObject(sub);
			sub->release();
		}
		else
		{
			auto str = new __String(value.asString());
			ret->addObject(str);
			str->release();
		}
	}

	return ret;
}

bool SpriteHelper::cacheAnimations(std::string rootName)
{

	__Array *arr = __Array::createWithContentsOfFile(rootName.append("/animations.plist"));
	arr->retain();

	if (arr == 0)
		return false;
	for (int i = 0, l = arr->count(); i < l; ++i){
		const char* name = ((__String*)arr->getObjectAtIndex(i))->getCString();
		char plist_name[64] = { 0 };
		sprintf(plist_name, "%s.plist", name);
		ValueVector arr2_ = FileUtils::getInstance()->getValueVectorFromFile(plist_name);

		__Array *arr2 = visitArray(arr2_);
		if (arr2){
			arr2->autorelease();
		}

		for (int j = 0, jl = (int)arr2->count(); j < jl; ++j)
		{
			__Dictionary* ani = (__Dictionary*)arr2->getObjectAtIndex(j);
			CCAssert(ani != 0, name);

			if (ani == 0)
				continue;

			::cachAnimation(ani);
		}
	}
	return true;
}

void SpriteHelper::removeAnimations(std::string rootName)
{
	__Array *arr = __Array::createWithContentsOfFile(rootName.append("/animations.plist"));
	arr->retain();

	if (arr == 0)
		return;

	for (int i = 0, l = arr->count(); i < l; ++i){

		const char* name = ((__String*)arr->getObjectAtIndex(i))->getCString();
		char plist_name[64] = { 0 };
		sprintf(plist_name, "%s.plist", name);

		ValueVector arr2_ = FileUtils::getInstance()->getValueVectorFromFile(plist_name);

		__Array *arr2 = visitArray(arr2_);
		if (arr2){
			arr2->autorelease();
		}

		for (int j = 0, jl = (int)arr2->count(); j < jl; ++j)
		{
			__Dictionary* ani = (__Dictionary*)arr2->getObjectAtIndex(j);
			CCAssert(ani != 0, name);

			DictionaryAide aide(ani);
			AnimationCache::getInstance()->removeAnimation(aide.stringFromKey("name"));
		}
	}
	
}

const char* getPath(char szPath[], int len, const char* file)
{
	const char* ppos = strrchr(file, '/');
	int index = ppos - file;
	if (index > len)
		index = len;
	memcpy(szPath, file, index);
	return szPath;
}

bool SpriteHelper::cacheAnimation(const char* plist)
{
	__Dictionary* dic = __Dictionary::createWithContentsOfFile(plist);
	if (dic == 0)
		return false;

	SpriteFrameCache *cache = SpriteFrameCache::getInstance();
	DictionaryAide aide(dic);

	const char* name = aide.stringFromKey("name");
	const char* format = aide.stringFromKey("format");
	float delay = aide.floatFromKey("delay");
	__Array* frames = aide.arrayFromKey("frames");
	int count = frames == 0 ? 0 : frames->count();
	CCAssert(frames != 0, "frames is null");

	Vector<SpriteFrame*> animFrames = Vector<SpriteFrame*>(count);

	char str[80];
	for (int k = 0; k < count; k++)
	{
		const char* sFrame = ((__String*)frames->getObjectAtIndex(k))->getCString();
		int frame = -1;
		float frameDelay = 0;
		sscanf(sFrame, "%d,%f", &frame, &frameDelay);
		sprintf(str, format, frame);
		SpriteFrame *sptFrame = cache->getSpriteFrameByName(str);
		CCAssert(sptFrame != 0, str);

		if (sptFrame)
		{
			animFrames.pushBack(sptFrame);
			// 			AnimationFrame* aniFrame = new CCAnimationFrame();
			// 			aniFrame->initWithSpriteFrame(sptFrame, frameDelay, 0);
			// 			animFrames->addObject(aniFrame);
			// 			aniFrame->release();
		}
	}

	Animation *animation = Animation::createWithSpriteFrames(animFrames, delay);
	AnimationCache::getInstance()->addAnimation(animation, name);
	//animFrames->release();
	dic->release();
	return true;
}

void SpriteHelper::removeAnimation(const char* plist)
{
	__Dictionary* dic = __Dictionary::createWithContentsOfFile(plist);
	if (dic == 0)
		return;

	//SpriteFrameCache *cache = SpriteFrameCache::getInstance();
	DictionaryAide aide(dic);
	AnimationCache::getInstance()->removeAnimation(aide.stringFromKey("name"));
	dic->release();
}
