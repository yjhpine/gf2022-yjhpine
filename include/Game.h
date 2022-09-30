#ifndef __Game__
#define __Game__

#include"SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include <iostream>
#include "TextureManager.h"

class Game
{
public:
	Game() { }
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
	
	TextureManager m_textureManager;
	int m_currentFrame;
	int m_currentFrame2;

	int a;
};

#endif /* __Game__ */