#include "map.h"
#include "Game.h"
#include "SDLGameObject.h"
#define _CRT_SECUER_NO_WARNINGS

Map::Map(const LoaderParams* pParams) : SDLGameObject(pParams)
{

}
void Map::loadMap(const char* name)
{
	
}

void Map::draw()
{
	
}
void Map::update()
{
	Map::loadMap("assets/map01.dat");
}
