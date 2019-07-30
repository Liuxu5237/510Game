#ifndef __Dntg_GAME_CONFIG_H__
#define __Dntg_GAME_CONFIG_H__
#pragma once
///////////////////////////////////////////////////////////////////////////////////////
#include "platform/PlatformHeader.h"
#include "DntgCMD_CatchBird.h"
#include "tools/manager/Move_Point_Manager.h"
#include "DntgBirdDefine.h"
namespace  Dntg
{
	class GameConfig
	{
	public:
		GameConfig();

		static GameConfig & getInstance() {
			static GameConfig gDntgGameConfig;
			return gDntgGameConfig;
		}

		void init(CMD_S_StatusFree *status_free);

		int get_bullet_radius() const					{ return BULLET_RADIUS; }
		const xSize& get_bird_size(int bird_type) const	{ return BIRD_SIZES[bird_type]; }
		const xSize& get_special_bird_size(int bird_type) { return SPECIAL_BIRD_SIZES[bird_type]; }
		int get_max_rank() const { return 10; }
		int get_cannon_type_max() const { return cannon_type_max_; }
		int get_cannon_price_base() const { return cannon_price_base_; }
		int get_cannon_price(int connon_type) const;
		int get_ex_score_count() { return ex_score_count_; }
		int get_ex_bullet_count() { return ex_bullet_count_; }
		int get_cannon_mulriple(int cannon_type)
		{
			if (cannon_type <= (int)mulriple_count_)
				return cannon_mulriple_[cannon_type];
			else
				return cannon_mulriple_[0];
		}
		int get_mulriple_count() const { return mulriple_count_; }
		Bullet_Config get_bullet_config(const float speed, int &type);		//由子弹速度获取当前子弹配置
		Bullet_Config get_bullet_config(const int type);					//由炮台类型获取当前子弹配置
	private:
		int cannon_type_max_;
		int cannon_price_base_;
		int ex_score_count_;
		int ex_bullet_count_;
		uint32 cannon_mulriple_[MAX_CANNON_TYPE];
		uint32 mulriple_count_;
		Bullet_Config bullet_config_[BULLET_KIND_COUNT];
	};

	///////////////////////////////////////////////////////////////////////////////////////
}

#endif