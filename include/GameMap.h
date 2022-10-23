#pragma once
#include "Game.h"

class GameMap
{
public:
	GameMap();
	~GameMap();

	void LoadMap();
	void DrawMap();

private:
	SDL_Rect sec, dest;

	SDL_Texture* dirt;
	SDL_Texture* grass;
	SDL_Texture* water;

	int map[80][30];
};