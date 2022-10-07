#pragma once
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"

class Game
{
public:
	//Game() { }
	//~Game() { }

	bool init(const char* title, int xpos, int ypos, int w, int h, int flags);
	void render();
	void update();
	bool running();
	void handleEvents();
	void clean();

private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;

	GameObject m_go;
	Player m_player;

	int a = 1;
};
