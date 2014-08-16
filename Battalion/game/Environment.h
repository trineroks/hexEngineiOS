#pragma once
#include "stdafx.h"
#include "SDL_Setup.h"
#include "Sprite.h"
#include "TileData.h"
#include "ActionMenu.h"

class CUnit;

class CEnvironment
{
public:
	CEnvironment(int *boardArray, int p_playerNum, int p_boardW, int p_boardH, CSDL_Setup* p_SDL_setup);
	~CEnvironment(void);

	void drawTopLayer(float camX, float camY);
	void draw(float camX, float camY);
	void drawUtilityTiles(float camX, float camY);

	bool selected(float camX, float camY, int mouseX, int mouseY, int &x_pos, int &y_pos);
	bool selectedAction(int mouseX, int mouseY);

	int getBoard() { return *localBoard; }
	CTileData *getHex(int x, int y);

	bool traversable(int x, int y, int moveRange, int unitType, int owner);

	bool getCombatState() { return isInCombat_; }
	int getMoveCost(int x, int y, int unitType);

	int getBoardHeight() { return height; }
	int getBoardWidth() { return width; }
	int getMapSize() { return mapSize; }

	int getPixelHeight() { return pixelHeight; }
	int getPixelWidth() { return pixelWidth; }

	void update(float camX, float camY);

	void endTurn();
	void startTurn();

	bool paintMovementTile(int x, int y, float camX, float camY);

	bool paintTargetableTile(int x, int y, float camX, float camY);
	bool paintSupportableTile(int x, int y, float camX, float camY);

	void paintEndTile(int x, int y, float camX, float camY);
	void paintFog(float camX, float camY);

	void showActionMenu(bool canAttack, int x, int y);
	void closeActionMenu();

	void setFog();

	void getAdjacentHexes(int x, int y, gamePoint adjacent[]);
	gamePoint getAdjacentHexAtDirection(int x, int y, int i_dir, int j_dir);
	bool blockedLineOfSight(int originX, int originY, int targetX, int targetY);

	CUnit *anyUnitOnTile(int x, int y);
	CUnit *anyEnemyOnTile(int x, int y, int player);

	bool hitTestMenu(gamePoint gameMouse);
    bool hitTestButton(gamePoint gameMouse);
	void HUDButtonToggle(gamePoint gameMouse);
	void HUDButtonAction(gamePoint gameMouse);
	void selectedStateToggle(gamePoint gameMouse);

	bool isValidTile(int x, int y);
	void setButtonElementsDefault();

private:
	bool unitHasMovedException();
	void checkForCombatState();
	void destroyUnitIfNecessary(CTileData* hex);
	bool existsEnemyAt(int index);
	void calculatePixelDimensions(int y);
	void hideCursor();
	void unselectCurrentlySelectedUnit();
	void actUponSelect(int x, int y, float camX, float camY);
	gamePoint hitTest(gamePoint gameMouse);
	void drawWithParameters(SDL_Rect imageCamera, int tileType);
	void doAction(int action);
	void doCombat(CTileData *attackerHex, CTileData *defenderHex, int weaponSelected);

	void setCursorPosition(int x, int y);

	void displayDefog();

	bool actionMenuOpened_;
	bool selectionMade_;

	bool isInCombat_;
	bool isInNumberFloater_;

	int animationLimit_;

	gamePoint adjacent[6];

	vector<CUnit*> p1units;
	vector<CUnit*> p2units;
	vector<gamePoint> foggedTiles;

	CTileData* attackerHex_;
	CTileData* defenderHex_;

	CUnit* currentlySelectedUnit_;
	CTileData* currentlySelectedTile_;

	int currentPlayer;
	int numberOfPlayers;

	//These are helper math constants
	float tileHeight_;
	float upperThird_;
	float halfHex_;

	CSDL_Setup* csdl_setup;
	CSprite* cursor;
	
	SDL_Renderer *renderer;

	SDL_Rect crop_;
	SDL_Rect moveHighlight_;
	SDL_Rect endHighlight_;
	SDL_Rect attackHighlight_;
	SDL_Rect supportHighlight_;
	SDL_Rect imageCamera_;

	SDL_Rect actionMenuAssets_;
	SDL_Rect onScreenButtonAssets_;

	gamePoint sheetParams;

	int height, width;
	int mapSize;

	int pixelHeight;
	int pixelWidth;

	int localBoard[1024];

	SDL_Texture *terrain;
	SDL_Texture *backgroundTexture;
	SDL_Texture *units;
	SDL_Texture *GUI;
	CTileData *hexes_;

	CGUI* endTurnButton_;
	void setMenuButton();
	void drawOnScreenMenu(float camX, float camY);

	CActionMenu *actionMenu_;
};
