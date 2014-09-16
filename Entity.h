#include "stdafx.h"
#include "Sprite.h"
#include "Unit.h"
#include "Environment.h"

class CEntity
{
public:
	CEntity(CUnit *unit, int p_hp, int p_primaryAmmo, int p_supportAmmo, gamePoint p_pos, CSDL_Setup *p_csdl_setup, SDL_Texture *p_texture, CEnvironment *p_environment);
	~CEntity(void);
	
	void drawSprite(float camX, float camY);
	void moveTo(int x, int y);
	void doCancel();
private:
	
	
}





