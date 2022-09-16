// SDL 
// written by changhoonpark@gmail.com
//우오앙

#include "main.h"
#include <SDL2/SDL.h>

SDL_Window* g_pWindow = 0;
SDL_Renderer* g_pRenderer = 0;
bool g_bRunning = false;
bool init(const char* title, int xpos, int ypos, int height, int width, int flags);
void render();

int main(int argc, char* args[])
{
	if (init("Breaking Up HelloSDL", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, 640, 480,
		SDL_WINDOW_SHOWN))
	{
		g_bRunning = true;
	}
	else
	{
		return 1;
	}
	int a = 0;//과제 - 탈출을 위한 변수
	while (g_bRunning)//추가 실습 - !g_bRunning이라면 반복이 바로 종료됨
	{
		render();
		SDL_Delay(500);
		a++;
		if (a == 10)//과제 - 변수 a가 10이 된다면 g_bRunning을 false로 바꾸고 while문 종료
		{
			g_bRunning = false;
		}
	}
	SDL_Quit();
	return 0;
}
bool init(const char* title, int xpos, int ypos, int height, int width, int flags)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		g_pWindow = SDL_CreateWindow(
			title, xpos, ypos, height, width, flags);
		if (g_pWindow != 0)
		{
			g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
		}
	}
	else
	{
		return false;
	}
	return true;
}
void render()
{
	SDL_RenderClear(g_pRenderer);
	SDL_RenderPresent(g_pRenderer);

	SDL_SetRenderDrawColor(g_pRenderer, rand() % 256, rand() % 256, rand() % 256, 255);//추가 실습 - 색을 랜덤으로 바꿈
	SDL_Delay(1000);
}

