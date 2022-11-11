#include "Player.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams)
{
    playerCollider.x = m_position.getX();
    playerCollider.y = m_position.getY();
    playerCollider.w = pParams->getWidth();
    playerCollider.h = pParams->getHeight();

    camera.x = (m_position.getX() + pParams->getWidth() / 2) - SCREEN_WIDTH / 2;
    camera.y = (m_position.getY() + pParams->getHeight() / 2) - SCREEN_HEIGHT / 2;
}
void Player::draw()
{
	SDLGameObject::draw(flip);
}
void Player::update()
{
    playerCollider.x = m_position.getX();
    playerCollider.y = m_position.getY();
    Gravity();
    std::cout << m_gravity.getY() << " : " << m_gravitySpeed.getY() << std::endl;
    for (int a = 0; a < 4; a++)
    {
        if (coll.check_collision(playerCollider, loadmap.ground[a]))
        {
            m_position.setY(loadmap.ground[a].y - playerCollider.h);
            m_acceleration.setY(0);
            m_gravitySpeed.setY(-1);
        }
    }
	handleInput();
    setCamera();
	SDLGameObject::update();
}
void Player::handleInput()
{
    m_currentFrame = ((SDL_GetTicks() / 100) % 1);
   if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
       m_velocity.setX(5);
       flip = SDL_FLIP_NONE;
       m_currentFrame = ((SDL_GetTicks() / 100) % 4);
   }
   else m_velocity.setX(0);
   if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
       m_velocity.setX(-5);
       flip = SDL_FLIP_HORIZONTAL;
       m_currentFrame = ((SDL_GetTicks() / 100) % 4);
   }
   if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP)) {
       m_velocity.setY(-4);
       m_currentFrame = ((SDL_GetTicks() / 100) % 4);
   }
   else m_velocity.setY(0);

   if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN)) {
       m_velocity.setY(4);
       m_currentFrame = ((SDL_GetTicks() / 100) % 4);
   }
   if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE)) {
       isjumping = TheInputHandler::Instance()->isJumping();
       m_currentFrame = 5 + ((SDL_GetTicks() / 400) % 3);
       if (isjumping == true) 
       { 
          Jumping();
       }
   }
}
void Player::clean() {}
void Player::Jumping()
{
    m_acceleration.setY(-12);
    isjumping = false;
}
void Player::setCamera()
{
    //Keep the camera in bounds
    if (camera.x < 0)
    {
        camera.x = 0;
    }
    if (camera.y < 0)
    {
        camera.y = 0;
    }
    if (camera.x > LEVEL_WIDTH - camera.w)
    {
        camera.x = LEVEL_WIDTH - camera.w;
    }
    if (camera.y > LEVEL_HEIGHT - camera.h)
    {
        camera.y = LEVEL_HEIGHT - camera.h;
    }
}