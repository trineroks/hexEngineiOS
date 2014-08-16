#include "StdAfx.h"
#include "TileData.h"

#include "Unit.h"

CTileData::CTileData()
{
	type = "NULL";
	tileMoveCost.air = NON_PASSABLE;
	tileMoveCost.infantry = NON_PASSABLE;
	tileMoveCost.vehicle = NON_PASSABLE;
	unitOnTile = NULL;
	unitExists = false;
	fogOfWar = false;
}

CTileData::CTileData(int p_intType, int p_moveAir, int p_moveInf, int p_moveVeh)
{
	tileMoveCost.air = p_moveAir;
	tileMoveCost.infantry = p_moveInf;
	tileMoveCost.vehicle = p_moveVeh;
	unitOnTile = NULL;
	unitExists = false;
	fogOfWar = false;
}


CTileData::~CTileData(void)
{
	unitOnTile = NULL;
	//delete parentTile;
}

void CTileData::setMoveCost(int air, int inf, int veh)
{
	tileMoveCost.air = air;
	tileMoveCost.infantry = inf;
	tileMoveCost.vehicle = veh;
}

void CTileData::initializeValues(string p_type, int p_moveAir, int p_moveInf, int p_moveVeh, int p_defenseModifier, bool p_isObstacle)
{
	setType(p_type);
	setMoveCost(p_moveAir, p_moveInf, p_moveVeh);
	defenseModifier = p_defenseModifier;
	isObstacle = p_isObstacle;
}

void CTileData::setUnit(CUnit* unit)
{
	if (unitExists)
		printf("Overriding unit at tile!\n");
	unitOnTile = unit;
	unitExists = true;
}
	
void CTileData::removeUnit()
{
	unitOnTile = NULL;
	unitExists = false;
}

void CTileData::destroyUnit()
{
	delete unitOnTile;
	unitOnTile = NULL;
	unitExists = false;
}