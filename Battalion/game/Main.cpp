#include "StdAfx.h"
#include "Main.h"

CMain::CMain(CSDL_Setup *p_setup, int *p_board, gamePoint p_dimensions, int *mouseX, int *mouseY)
	: CGameState()
{
	camX = 0; camY = 0;
	screenW = p_setup->getWidth(); 
	screenH = p_setup->getHeight();
	//exit = false;
	csdl_setup = p_setup;

	int board[1024] = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		 0, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 3, 0,
		0, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 3, 0,
		 0, 2, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 0,
		0, 2, 2, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 0,
		 0, 1, 2, 1, 1, 2, 1, 1, 3, 3, 1, 2, 1, 0,
		0, 1, 1, 1, 1, 1, 1, 1, 3, 3, 1, 1, 1, 0,
		 0, 1, 1, 1, 3, 1, 1, 1, 3, 1, 1, 1, 1, 0,
		0, 1, 2, 1, 3, 3, 1, 1, 1, 1, 1, 2, 1, 0,
		 0, 1, 1, 3, 3, 1, 1, 2, 1, 1, 1, 2, 2, 0,
		0, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 2, 0,
		 0, 3, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 0,
		0, 3, 1, 1, 1, 1, 1, 1, 1, 2, 2, 1, 1, 0,
		 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	};
	//mouseX = 0; mouseY = 0;
	zone_level = new CEnvironment(board, 2, p_dimensions.x, p_dimensions.y, csdl_setup);
	controller = new CInputController(csdl_setup, mouseX, mouseY, &camX, &camY, screenW, screenH, zone_level); 
}


CMain::~CMain(void)
{
	delete controller;
	delete zone_level;
}

void CMain::GameExec()
{
	controller->update();
	zone_level->update(camX, camY);
}