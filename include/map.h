#pragma once
#include "TextureManager.h"
#include "SDLGameObject.h"
#define MAX_MAP_X 40
#define MAX_MAP_Y 30

#define TILE_SIZE 32

class Map : public SDLGameObject
{
public:
	int tile[MAX_MAP_Y][MAX_MAP_X];
	SDL_Rect tilemap[MAX_MAP_Y][MAX_MAP_X];

	Map(const LoaderParams* pParams);
	void loadMap(const char* name);
	virtual void draw();
	virtual void update();
};

