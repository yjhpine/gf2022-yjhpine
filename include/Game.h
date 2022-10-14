#pragma once
#include "GameObject.h"
#include "Player.h"
#include "Monster.h"
#include "main.h"
#include "TextureManager.h"
class Player;

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
	
	GameObject m_go;
	Player m_player;
	Monster m_mob;
	Monster m_mob2;

	int a = 1;
};
