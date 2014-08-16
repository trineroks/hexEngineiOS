#pragma once
#include "GameState.h"
#include "stdafx.h"
#include "SDL_Setup.h"

class CMainExec
{
public:
	CMainExec(int p_screenW, int p_screenH);
	~CMainExec(void);

	void changeState();
	void setNextState(int gameState);

	void exec();
private:
	int stateID;
	int nextState;

	//TO BE MOVED
	int board[1024];
	gamePoint boardDimensions;

	bool exit;

	int mouseX, mouseY;

	int screenW;
	int screenH;

	CSDL_Setup* csdl_setup;

	CGameState *currentState;
};

