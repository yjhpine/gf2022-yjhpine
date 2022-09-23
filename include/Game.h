#ifndef __Game__
#define __Game__

#include"SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"

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
	void DrawSurface(SDL_Surface* dst, int x, int y, SDL_Surface* src);

private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer; 
	bool m_bRunning;

	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;

	SDL_Texture* m_pTexture;
	SDL_Rect m_sourceRectangle;
	SDL_Rect m_destinationRectangle;

	SDL_Surface* message;

	TTF_Font* font;
	SDL_Color textColor = { 0, 0, 0 };
	char str[50] = "¾È³ç? SDL_ttf!";

	int a;
};

#endif /* __Game__ */g