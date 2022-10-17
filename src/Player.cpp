#include "Player.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams) {}
void Player::draw()
{
	SDLGameObject::draw(flip);
}
void Player::update()
{
    Collision();
	handleInput();
	SDLGameObject::update();
}
void Player::handleInput()
{
   if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
       m_velocity.setX(4);
       flip = SDL_FLIP_NONE;
       m_currentFrame = ((SDL_GetTicks() / 100) % 6);
   }
   else m_velocity.setX(0);

   if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
       m_velocity.setX(-4);
       flip = SDL_FLIP_HORIZONTAL;
       m_currentFrame = ((SDL_GetTicks() / 100) % 6);
   }

   if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP)) {
       m_velocity.setY(-4);
       m_currentFrame = ((SDL_GetTicks() / 100) % 6);
   }
   else m_velocity.setY(0);

   if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN)) {
       m_velocity.setY(4);
       m_currentFrame = ((SDL_GetTicks() / 100) % 6);
   }
   if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE))
   {
       ToF = TheInputHandler::Instance()->isJumping();
       m_currentFrame = ((SDL_GetTicks() / 100) % 6);
       std::cout << m_acceleration.getY() << "\nÁ¡ÇÁ\n" << ToF << std::endl;
       Jumping();
   }
}
void Player::clean() {}
void Player::Collision()
{
    if (m_position.getX() >= 540)
    {
        m_position.setX(m_position.getX() - 4);
    }
    if (m_position.getX() < -20)
    {
        m_position.setX(m_position.getX() + 4);
    }
    if (m_position.getY() <= 0)
    {
        m_position.setY(m_position.getY() + 4);
    }
    if (m_position.getY() > 400)
    {
        m_position.setY(m_position.getY() - 4);
    }
}
void Player::Jumping()
{
    if (ToF == true)
    {
        
    }
}