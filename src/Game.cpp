#pragma once
#include "Game.h"

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

	if (!TheTextureManager::Instance()->load("Assets/CuteDog.png", "animate", m_pRenderer))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("Assets/animate-alpha.png", "animate2", m_pRenderer))
	{
		return false;
	}

	GameObject* m_go = new GameObject();
	GameObject* m_player = new Player();
	GameObject* m_monster = new Monster();

	m_go->load(100, 100, 128, 128, "animate");
	m_player->load(300, 300, 128, 128, "animate");
	m_monster->load(0, 0, 128, 82, "animate2");
	m_gameObjects.push_back(m_go);
	m_gameObjects.push_back(m_player);
	m_gameObjects.push_back(m_monster);

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

	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw(m_pRenderer);
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