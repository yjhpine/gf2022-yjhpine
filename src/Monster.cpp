#include "Monster.h"

void Monster::load(int x, int y, int width, int height, std::string textureID)
{
	GameObject::load(x, y, width, height, textureID);
}
void Monster::draw(SDL_Renderer* pRenderer)
{
	GameObject::draw(pRenderer);
}
void Monster::update()
{
	if (m_x <= 0)
	{
		a = 1;
		flip = SDL_FLIP_NONE;
	}
	else if (m_x > 540)
	{
		a = 2;
		flip = SDL_FLIP_HORIZONTAL;
	}
	if (a == 1)
	{
		m_x += 3;
	}
	else if (a == 2)
	{
		m_x -= 3;
	}
	m_currentFrame = ((SDL_GetTicks() / 100) % 6);
}