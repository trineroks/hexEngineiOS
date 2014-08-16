#pragma once
#include "stdafx.h"
#include "Sprite.h"
//#include "Environment.h"
#include "Label.h"
#include "GUI.h"
#include "SDL_Setup.h"

class CActionMenu
{
public:
	CActionMenu(CSDL_Setup *p_csdl_setup, SDL_Rect assetsPortion, int posX, int posY, int width);
	~CActionMenu(void);

	gamePoint getPosition() { return position_; }

	bool mouseOverMenu(gamePoint mouse);

	void toggleButtonState(gamePoint mouse);
	void setToDefaultState();

	int getButtonPressed(gamePoint mouse);

	void addElement(char p_string[], int actionToDo);
	void draw();
private:
	void updateActionMenuDimensions();

	gamePoint position_;
	CSDL_Setup *csdl_setup_;
	SDL_Texture *actionMenuAssets_;

	vector<CGUI*> elements_;

	CSprite *header_;
	CSprite *footer_;

	TTF_Font *labelFont_;
	TTF_Font *labelOutline_;

	int elementIndex_;
	SDL_Rect rect_;
	SDL_Rect assetsPortion_;
	SDL_Rect actionMenuBox_;
};

