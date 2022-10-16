#include "Player.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams) {}
void Player::draw()
{
	SDLGameObject::draw();
}
void Player::update()
{
	//m_position.setX(m_position.getX() + 1);
	m_currentFrame = ((SDL_GetTicks() / 100) % 6);
	//m_velocity.setX(1); �ӵ��� 1�� �����ϸ� ���ӵ��� ���ص� ��� �ӵ� ����
	m_acceleration.setX(0.01);
	SDLGameObject::update();
}
void Player::clean() {}