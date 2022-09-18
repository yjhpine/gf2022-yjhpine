#include"SDL2/SDL.h"
#pragma once

class Game
{
public:
	Game() 
	{ 
		m_bRunning = true; 
		m_pWindow = 0;
		m_pRenderer = 0;
	}
	~Game() { }

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
};