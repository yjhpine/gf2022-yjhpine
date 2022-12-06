#include "map.h"
#include "Game.h"
#define _CRT_SECUER_NO_WARNINGS

Map::Map(const LoaderParams* pParams) : SDLGameObject(pParams)
{

}
void Map::loadMap(const char* name)
{
	int x, y;
	FILE* fp;

	fp = fopen(name, "rb");

	if (fp == NULL)
	{
		printf("Failed to open map %s\n", name);

		exit(1);
	}

	for (y = 0; y < MAX_MAP_Y; y++)
	{
		for (x = 0; x < MAX_MAP_X; x++)
		{
			fscanf(fp, "%d", &tile[y][x]);
		}
	}

	fclose(fp);
}

void Map::draw()
{
	int x, y;

	for (y = 0; y < MAX_MAP_Y; y++)
	{
		for (x = 0; x < MAX_MAP_X; x++)
		{
			if (tile[y][x] != 0)
			{
				TheTextureManager::Instance()->draw("brick", x * TILE_SIZE - Camera.x, y * TILE_SIZE - Camera.y, 32, 32, TheGame::Instance()->getRenderer());
			}
		}
	}
}
void Map::update()
{
	Map::loadMap("assets/map01.dat");
}
