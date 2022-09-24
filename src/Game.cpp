#include "Game.h"
#include "SDL2/SDL_ttf.h"

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
				SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
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

	SDL_Surface* pTempSurface = SDL_LoadBMP("Assets/rider.bmp");
	m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
	SDL_FreeSurface(pTempSurface);

	SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h);

	m_bRunning = true;
	return true;
}
void Game::update()
{
	if (a < 100)
	{
		m_destinationRectangle.w = m_sourceRectangle.w = 50;
		m_destinationRectangle.h = m_sourceRectangle.h = 50;

		m_sourceRectangle.x = 0;
		m_sourceRectangle.y = 0;

		m_destinationRectangle.x = 80;
		m_destinationRectangle.y = 50;
	}
	else if (100 < a < 200)
	{
		m_destinationRectangle.w = m_sourceRectangle.w = 50;
		m_destinationRectangle.h = m_sourceRectangle.h = 50;

		m_sourceRectangle.x = 50;
		m_sourceRectangle.y = 50;

		m_destinationRectangle.x = 80;
		m_destinationRectangle.y = 50;
	}
	if (a > 200)
	{
		m_destinationRectangle.w = m_sourceRectangle.w = 640;
		m_destinationRectangle.h = m_sourceRectangle.h = 480;

		m_destinationRectangle.x = m_sourceRectangle.x = 0;
		m_destinationRectangle.y = m_sourceRectangle.y = 0;
	}
	if (a < 300)
	{
		a++;
		std::cout << a << std::endl;
		SDL_Delay(10);
	}
}
void Game::render()
{
	SDL_RenderClear(m_pRenderer);
	SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);
	SDL_RenderPresent(m_pRenderer);
}
void Game::handleEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) //이벤트가 감지될 때 까지 계속 루프??
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
