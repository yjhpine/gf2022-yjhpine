#pragma once
#include "main.h"

class GameObject
{
public:
    void load(int x, int y, int width, int height, std::string textureID);
	void draw(SDL_Renderer* pRenderer);
	void update();
	void clean() {};

protected:
	std::string m_textureID;

	SDL_RendererFlip flip;
	int a;

	int m_x;
	int m_y;
	int m_width;
	int m_height;

	int m_currentFrame;
	int m_currentRow;
};

