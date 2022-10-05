#include "Game.h"
#include "SDL2/SDL_image.h"

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

	if (!TheTextureManager::Instance()->load("Assets/Tree.png", "animate", m_pRenderer))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("Assets/CuteDog.png", "animate2", m_pRenderer))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("Assets/hihit.png", "animate3", m_pRenderer))
	{
		return false;
	}


	m_bRunning = true;
	return true;
}
void Game::update()
{
	m_currentFrame = ((SDL_GetTicks() / 80) % 5);
	m_currentFrame2 = ((SDL_GetTicks() / 40) % 5);
    m_currentFrame3 = ((SDL_GetTicks() / 120) % 5);
}
void Game::render()
{
	SDL_SetRenderDrawColor(m_pRenderer, 133, 251, 255, 255);//기본 배경
	SDL_RenderClear(m_pRenderer);

	SDL_Rect fillRect = { 350, 250, 290, 280 }; //흙바닥을 표현하는 사각형들(언덕)
	SDL_SetRenderDrawColor(m_pRenderer, 105, 73, 0, 255);
	SDL_RenderFillRect(m_pRenderer, &fillRect);

	SDL_Rect fillRect2 = { 350, 250, 290, 20 }; //잔디 표현(언덕)
	SDL_SetRenderDrawColor(m_pRenderer, 103, 255, 56, 255);
	SDL_RenderFillRect(m_pRenderer, &fillRect2);
	
	SDL_Rect fillRect3 = { 0, 400, 1280, 200}; //흙바닥을 표현하는 사각형들
	SDL_SetRenderDrawColor(m_pRenderer, 105, 73, 0, 255);
	SDL_RenderFillRect(m_pRenderer, &fillRect3);

	SDL_Rect fillRect4 = { 0, 400, 1280, 20 }; //잔디 표현
	SDL_SetRenderDrawColor(m_pRenderer, 103, 255, 56, 255);
	SDL_RenderFillRect(m_pRenderer, &fillRect4);

	TheTextureManager::Instance()->draw("animate", 100, 190, 256, 256, m_pRenderer); //나무
	TheTextureManager::Instance()->draw("animate", 850, 150, 300, 300, m_pRenderer); 

	TheTextureManager::Instance()->draw("animate2", a, 310, 128, 128, m_pRenderer); //강아지

	TheTextureManager::Instance()->draw("animate2", 400, 160, 128, 128, m_pRenderer, SDL_FLIP_HORIZONTAL); //수평으로 flip한 강아지
	TheTextureManager::Instance()->drawFrame("animate3", 400, 360, 64, 64, 0, m_currentFrame, m_pRenderer);
	TheTextureManager::Instance()->drawFrame("animate3", 100, 360, 64, 64, 0, m_currentFrame2, m_pRenderer);
	TheTextureManager::Instance()->drawFrame("animate3", 500, 360, 64, 64, 0, m_currentFrame3, m_pRenderer);

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
		if (0 < a < 1280)
		{
			switch (event.key.keysym.sym)
			{
			case SDLK_RIGHT:
				a += 25;
				break;
			case SDLK_LEFT:
				a -= 25;
				break;
			}
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