#pragma once
#include "Game.h"
Game* Game::s_pInstance = 0;

bool Game::init(const char* title, int xpos, int ypos, int w, int h, int flags)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, w, h, flags);
		if (m_pWindow != 0)
		{
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
			if (m_pRenderer != 0)
			{
				SDL_SetRenderDrawColor(m_pRenderer, 197, 218, 250, 255);
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("Assets/animate-alpha.png", "animate", m_pRenderer))
	{
		return false;
	}

	m_gameObjects.push_back(new Player(new LoaderParams(100, 100, 128, 82, "animate")));
	m_gameObjects.push_back(new Enemy(new LoaderParams(100, 100, 128, 82, "animate")));

	m_bRunning = true;
	return true;
}
void Game::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}
void Game::render()
{
	SDL_RenderClear(m_pRenderer);

	for (int i = 0; i != m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}

	SDL_RenderPresent(m_pRenderer);
}
void Game::handleEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) //이벤트가 감지될 때 까지 계속 루프
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_bRunning = false;
			break;
		default:
			break;
		}
	}
}
void Game::clean()
{
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit(); 
}
bool Game::running()
{
	return m_bRunning;
}