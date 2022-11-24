#pragma once
#include <vector>
#include "GameObject.h"
#include "Player.h"
#include "InputHandler.h"
#include "TextureManager.h"
//#include "SDLGameObject.h"
#include "camera.h"


class Game
{
public:
	std::vector<GameObject*> m_gameObjects;

	bool init(const char* title, int xpos, int ypos, int w, int h, int flags);
	void render();
	void update();
	bool running();
	void handleEvents();
	void clean();
	void quit() { m_bRunning = false; }

	static Game* Instance() {
		if (s_pInstance == 0) {
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}
	SDL_Renderer* getRenderer() const { return m_pRenderer; }

private:
	static Game* s_pInstance;

	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;

};  typedef Game TheGame;
