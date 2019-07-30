#ifndef _Dntg_WeaponConfig_H_
#define _Dntg_WeaponConfig_H_
#pragma once
#include "DntgCMD_CatchBird.h"

namespace Dntg
{
	class WeaponConfig
	{
	public:
		static WeaponConfig & getInstance()
		{
			static WeaponConfig gWeaponConfig;
			return gWeaponConfig;
		}
		void set_weapon_info(WeaponInfo weapon_info[MAX_WEAPON_MAIN_LEVEL]);

		const WeaponInfo* getWeapon(int main_level) const;
	public:
		WeaponInfo weapons_[MAX_WEAPON_MAIN_LEVEL];
	}; // WeaponConfig

}

#endif // _WeaponConfig_H_