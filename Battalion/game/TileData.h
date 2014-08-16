#pragma once
#include "stdafx.h"
#include "Sprite.h"

class CUnit;

class CTileData
{
public:
	CTileData(int p_intType, int p_moveAir, int p_moveInf, int p_moveVeh);
	CTileData();
	~CTileData(void);

	void initializeValues(string p_type, int p_moveAir, int p_moveInf, int p_moveVeh, int p_defenseModifier, bool p_isObstacle);

	void setMoveCost(int p_moveCost);

	string getType() { return type; }
	void setType(string p_type) { type = p_type; }

	bool getSelected() { return selected; }
	void setSelected(bool p_selected) { selected = p_selected; }

	bool getMoveAttack() { return selectedAttack; }
	void setMoveAttack(bool p_selectedAttack) { selectedAttack = p_selectedAttack; }

	void setMoveCost(int air, int inf, int veh);
	moveCost getMoveCost() { return tileMoveCost; }

	bool getIsObstacle() { return isObstacle; }

	bool isFogged() { return fogOfWar; }
	void setFog(bool toggle) { fogOfWar = toggle; }

	CUnit *getUnit() { return unitOnTile; };
	bool existsUnit() { return unitExists; };
	void setUnit(CUnit* unit);
	void removeUnit();
	void destroyUnit();

private:
	moveCost tileMoveCost;

	bool unitExists;
	bool isObstacle;
	bool selected;
	bool selectedAttack;
	bool fogOfWar;
	string type;
	CUnit *unitOnTile;

	//CSprite *highlight;

	int defenseModifier;

};

