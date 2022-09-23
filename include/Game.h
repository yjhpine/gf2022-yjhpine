#ifndef __Game__
#define __Game__

#include"SDL2/SDL.h"

class Game
{
public:
	Game() 
	{
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

	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;

	SDL_Texture* m_pTexture;
	SDL_Rect m_sourceRectangle;
	SDL_Rect m_destinationRectangle;

	SDL_Texture* texture;
	SDL_Rect SR;
	SDL_Rect DR;
	

	int a;
};

#endif /* __Game__ */g