#ifndef _Dntg_BIRD_DEFINE_H_
#define _Dntg_BIRD_DEFINE_H_
#pragma once
#include "tools/manager/Move_Point_Manager.h"
#include "tools/global.h"
namespace  Dntg
{
	//////////////////////////////////////////////////////////////////////////
	//#define MAX_BIRD_IN_MANAGER					2048
	//#define MAX_BULLET_IN_MANAGER				2048
	//#define SCENE_TIME_END						600
	/*#define MAX_SMALL_PATH						217*/
	//#define MAX_BIG_PATH						130
	//#define MAX_HUGE_PATH						62
	//#define MAX_SPECIAL_PATH					24
	//#define MAX_SCENE_PATH						4


	//#define MAX_BIRD_CATCH						8
	//#define MAX_DIFFERENCE						2000

	//#define MAX_SCENE_TYPE						5

#define MAX_LEVEL_TYPE						60
#define MAX_BASE_TYPE						10
#define MAX_STORAGE_TYPE					20

#define PATH_TYPE_SMALL						0
#define PATH_TYPE_BIG						1
#define PATH_TYPE_HUGE						2
#define PATH_TYPE_SPECIAL					3
#define PATH_TYPE_SCENE						4

	//////////////////////////////////////////////////////////////////////////
	// 鱼群
	//////////////////////////////////////////////////////////////////////////
	// 场景鱼阵数量
	/*#define MAX_SCENE_SHAPE						4*/
	// 小鱼群数量
#define MAX_SMALL_SHOAL						4
	// 铁甲龟鱼群数量
#define MAX_TOR_SHOAL						1
	// 电鳗鱼群数量
#define MAX_EEL_SHOAL						1
	// 场景鱼群数量
#define MAX_SCENE_SHOAL						13

	//////////////////////////////////////////////////////////////////////////
	// 鱼效果类型
	//////////////////////////////////////////////////////////////////////////
#define BIRD_ITEM_NULL						0
#define BIRD_ITEM_SPECIAL_BOMB_1			1
#define BIRD_ITEM_SPECIAL_BOMB_2			2
#define BIRD_ITEM_SPECIAL_BOMB_3			3
#define BIRD_ITEM_SPECIAL_DING				4
#define BIRD_ITEM_SPECIAL_LUCKY				5
#define BIRD_ITEM_SPECIAL_GOLDX2			6
#define BIRD_ITEM_SPECIAL_TOR				7	//音效
#define BIRD_ITEM_SPECIAL_EEL				8   //音效
#define BIRD_ITEM_SPECIAL_SMALL_PURSE		9
#define BIRD_ITEM_SPECIAL_MIDDLE_PURSE		10
#define BIRD_ITEM_SPECIAL_BIG_PURSE			11

#define BIRD_ITEM_ZORDER_0					200
#define BIRD_ITEM_ZORDER_1					201
#define BIRD_ITEM_BOMB_EX_0					202
#define BIRD_ITEM_BOMB_EX_1					203


	//////////////////////////////////////////////////////////////////////////
	// 鱼特效
	//////////////////////////////////////////////////////////////////////////
#define BIRD_EFFECT_NULL					0
#define BIRD_EFFECT_GOLDX2					1
#define BIRD_EFFECT_LUCKY					2
#define BIRD_EFFECT_DING					3
#define BIRD_EFFECT_EEL						4
#define BIRD_EFFECT_TOR						5

	//////////////////////////////////////////////////////////////////////////
	// 鱼游动速度
	//////////////////////////////////////////////////////////////////////////
#define BIRD_FRAME_SPEED		0.26f

#define BIRD_MOVE_NORMAL		1
#define BIRD_MOVE_RUN_AWAY		20

	/**
	* 子弹大小
	*/
	const float BULLET_RADIUS = 10;

	/**
	* 鱼大小
	*/
	//const xSize	BIRD_SIZES[]  = {
	//	xSize(41, 37),	xSize(23, 44),	xSize(34, 55),	xSize(34, 72),
	//	xSize(52, 82),	xSize(41, 86),	xSize(51, 106),	xSize(53, 120),
	//	xSize(123, 114),	xSize(65, 148),	xSize(145, 139),	xSize(82, 240),	
	//	xSize(102, 255),	xSize(107, 290),	xSize(174, 300),	xSize(120, 280),
	//	xSize(200, 330),	xSize(290, 300),	xSize(120, 300), xSize(90, 90),	
	//	xSize(120, 120),	xSize(90, 90),	xSize(90, 90),	xSize(90, 90),
	//	xSize(90, 90),	xSize(90, 90),	xSize(90, 90),	xSize(90, 90),
	//};
	//change by xy 

	const xSize	BIRD_SIZES[] = {
		xSize(15, 48), xSize(18, 40), xSize(36, 58), xSize(42, 72),	//4
		xSize(33, 93), xSize(54, 78), xSize(37, 86), xSize(52, 97),		//8  
		xSize(56, 112), xSize(52, 120), xSize(71, 101), xSize(48, 112), //12
		xSize(112, 105), xSize(45, 157), xSize(69, 209), xSize(187, 165), //16
		xSize(112, 270), xSize(112, 270), xSize(131, 367), xSize(157, 315), //20
		xSize(225, 217), xSize(97, 322), xSize(266, 352), xSize(202, 345), //24
		xSize(146, 247), xSize(86, 97), xSize(180, 195), xSize(180, 195), //28
		xSize(180, 195), xSize(97, 135), //30
	};

	const xSize SPECIAL_BIRD_SIZES[] = {
		xSize(90, 90), xSize(225, 90), xSize(150, 150), xSize(165, 150), xSize(165, 165),
	};


	/**
	* 网大小
	*/
	const float NET_SIZES[] = {
		80, 80, 80, 80, 80,
		80, 80, 80, 80, 80,
		80, 80, 80, 80, 80,
		80, 80, 80, 80, 80,
		80, 80, 80, 80, 80,
		80, 80, 80, 80, 80,
		80, 80, 80, 80, 80,
		80, 80, 80, 80, 80,
		80, 80, 80, 80, 80,
	};

//////////////////////////////////////////////////////////////////////////
// 炮位置
//////////////////////////////////////////////////////////////////////////
//change by xy
// 	const int CANNON_POSITION[][2] = {
// 		{ 190, 57 }, { 500, 57 }, { 880, 57 },
// 		{ 880, 570 }, { 500, 570 }, { 190, 570 }
// 	};

	const float CANNON_POSITION[][2] = {
		{ 237*fGameRevolutionXFactor, 71*fGameRevolutionYFactor }, { 625*fGameRevolutionXFactor, 71*fGameRevolutionYFactor }, { 1100*fGameRevolutionXFactor, 71*fGameRevolutionYFactor },
		{ 1100*fGameRevolutionXFactor, 720*fGameRevolutionYFactor }, { 625*fGameRevolutionXFactor, 720*fGameRevolutionYFactor }, { 237*fGameRevolutionXFactor, 720*fGameRevolutionYFactor }
	};

	//炮旋转角度
	const float CANNON_ANGLE[] = { 180, 180, 180, 0, 0, 0 };
}
#endif // _BIRD_DEFINE_H_