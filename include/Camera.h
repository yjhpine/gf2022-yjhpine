#pragma once
#include "Player.h"

class camera : public Player
{
public:
	const int LEVEL_WIDTH = 1280;
	const int LEVEL_HEIGHT = 960;

	//Screen dimension constants
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;

	SDL_Rect Camera = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };

	void setCamera();
};