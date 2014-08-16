#pragma once
#include "stdafx.h"
#include "Sprite.h"
#include "SDL_Setup.h"
#include "GameState.h"

class CMainMenu : public CGameState
{
public:
	CMainMenu(CSDL_Setup* p_SDL_setup);
	~CMainMenu(void);
	void GameExec();
};

