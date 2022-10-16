#include "MyBullet.h"

MyBullet::MyBullet(const LoaderParams* pParams) : SDLGameObject(pParams) {}
void MyBullet::draw()
{
	SDLGameObject::draw(SDL_FLIP_NONE);
}
void MyBullet::update()
{
	m_velocity.setX(6);
	SDLGameObject::update();
}