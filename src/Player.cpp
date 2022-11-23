#include "Player.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams)
{
    playerCollider.x = m_position.getX();
    playerCollider.y = m_position.getY();
    playerCollider.w = pParams->getWidth();
    playerCollider.h = pParams->getHeight();
}
void Player::draw()
{
	SDLGameObject::draw(flip);
}
void Player::update()
{
    playerCollider.x = m_position.getX();
    playerCollider.y = m_position.getY();
    std::cout << playerCollider.x <<"/" << playerCollider.y << "/" << playerCollider.w <<"/"<< playerCollider.h << std::endl;
	handleInput();
	SDLGameObject::update();
}
void Player::handleInput()
{
    m_currentFrame = ((SDL_GetTicks() / 100) % 1);

   if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
       m_velocity.setX(5);
       if (m_position.getX() + 32 > 1280)
       {
           m_velocity.setX(0);
       }
       flip = SDL_FLIP_NONE;
       m_currentFrame = ((SDL_GetTicks() / 100) % 4);
   }
   else m_velocity.setX(0);
   if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
       m_velocity.setX(-5);
       if (m_position.getX() < 0)
       {
           m_velocity.setX(0);
       }
       flip = SDL_FLIP_HORIZONTAL;
       m_currentFrame = ((SDL_GetTicks() / 100) % 4);
   }
   if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP)) {
       m_velocity.setY(-4);
       if (m_position.getY() < 0)
       {
           m_velocity.setY(0);
       }
       m_currentFrame = ((SDL_GetTicks() / 100) % 4);
   }
   else m_velocity.setY(0);

   if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN)) {
       m_velocity.setY(4);
       if (m_position.getY() > 960)
       {
           m_velocity.setY(0);
       }
       m_currentFrame = ((SDL_GetTicks() / 100) % 4);
   }
  //if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE)) {
  //    isjumping = TheInputHandler::Instance()->isJumping();
  //    m_currentFrame = 5 + ((SDL_GetTicks() / 400) % 3);
  //    if (isjumping == true) 
  //    { 
  //       Jumping();
  //    }
  //}
}
void Player::clean() {}
//void Player::Jumping()
//{
//    m_acceleration.setY(-12);
//    isjumping = false;
//}