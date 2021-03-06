#include "StdAfx.h"
#include "Infantry.h"


CInfantry::CInfantry(int p_owner, string p_name, int p_moveRange, int p_optics, int p_hp, int defense, int armor, 
	   CWeapon *primary, CWeapon *support, gamePoint p_pos, CSDL_Setup *p_csdl_setup, SDL_Texture *p_texture, CEnvironment *p_environment)
			 : CUnit(p_owner, p_name, UNIT_INFANTRY, p_moveRange, p_optics, p_hp, defense, armor, primary, support, p_pos, p_csdl_setup, p_texture, p_environment)
{
	SDL_Rect portion;
	if (p_owner == 0) 
	{
		portion.x = 0;
		portion.y = 0;
		portion.w = 320;
		portion.h = 160;
	}
	else
	{
		portion.x = 320;
		portion.y = 0;
		portion.w = 320;
		portion.h = 160;
	}
	setupSprite(portion, p_csdl_setup, NULL, NULL, 4, 2);
}


CInfantry::~CInfantry(void)
{
}
