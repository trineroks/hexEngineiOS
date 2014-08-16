#pragma once
#include "SDL_Setup.h"
#include "Sprite.h"
#include "InputController.h"
#include "Environment.h"
#include "GameState.h"

class CMain : public CGameState
{
public:
	CMain(CSDL_Setup *p_setup, int *p_board, gamePoint p_dimensions, int *mouseX, int *mouseY);
	~CMain(void);
	void GameExec();

private:
	float camX, camY;
	int screenW, screenH;

	CInputController* controller;
	CEnvironment* zone_level;

	bool exit;

	CSDL_Setup* csdl_setup;

	//int mouseX, mouseY;
};

