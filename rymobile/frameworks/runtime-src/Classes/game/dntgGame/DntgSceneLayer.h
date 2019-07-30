#ifndef _Dntg_SceneLayer_H_
#define _Dntg_SceneLayer_H_

#include "cocos2d.h"

namespace  Dntg
{
	class SceneLayer
		: public cocos2d::Layer
	{
	public:
		CREATE_FUNC(SceneLayer);

	private:
		SceneLayer();
		~SceneLayer();
		bool init();

	public:
		virtual void update(float delta);

		int get_scene() const { return scene_; }
		void set_scene(int scene_);
		void chang_scene(int scene);
		static cocos2d::Animate* animationWithFrame(const char *frameName, int beginNun, int endNum, float delay);
	private:
		void change_scene_end(cocos2d::Node* node);
	private:
		int scene_;

		cocos2d::Sprite *spr_background_;
		cocos2d::Sprite *spr_background2_;

		cocos2d::Sprite *spr_cloud_;
		//change by xy
		cocos2d::Sprite *spr_water_wave_1;
		cocos2d::Sprite *spr_water_wave_2;
		cocos2d::Sprite *spr_water_wave_3;
		cocos2d::Sprite *spr_water_wave_4;

		//change end
		//cocos2d::Sprite *spr_water_wave_;
	};
}
#endif // _SceneLayer_H_