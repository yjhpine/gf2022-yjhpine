#include "Monster.h"

void Monster::load(int x, int y, int width, int height, std::string textureID)
{
	GameObject::load(x, y, width, height, textureID);
}
void Monster::draw(SDL_Renderer* pRenderer)
{
	GameObject::draw(pRenderer);
}
void Monster::update(int speed)
{
	if (m_x <= 0)
	{
		a = 1;
		flip = SDL_FLIP_NONE;
	}
	else if (m_x > 512)
	{
		a = 2; //끝에 도달하면 다시 돌아옴
		flip = SDL_FLIP_HORIZONTAL;
	}
	if (a == 1)
	{
		m_x += speed;
	}
	else if (a == 2)
	{
		m_x -= speed;
	}
	m_currentFrame = ((SDL_GetTicks() / 70) % 6);
}