#include "Player.h"
#include "TextureManager.h"
#include "Game.h"
#include "map.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams)
{
    playerCollider.x = m_position.getX();
    playerCollider.y = m_position.getY();
    playerCollider.w = pParams->getWidth();
    playerCollider.h = pParams->getHeight();
}
void Player::draw()
{
    TheTextureManager::Instance()->draw("BG", -Camera.x, -Camera.y, LEVEL_WIDTH, LEVEL_HEIGHT, TheGame::Instance()->getRenderer(), SDL_FLIP_NONE);
    drawmap();
	SDLGameObject::draw(flip, m_position.getX() - Camera.x, m_position.getY() - Camera.y);
}
void Player::update()
{
    playerCollider.x = m_position.getX();
    playerCollider.y = m_position.getY();
	handleInput();
    loadmap("assets/map01.dat");
	SDLGameObject::update();

    //Camera
    Camera.x = (m_position.getX() + 16) - SCREEN_WIDTH / 2;
    Camera.y = (m_position.getY() + 16) - SCREEN_HEIGHT / 2;

    //if (m_position.getY() + 36 <= 960)
    //{
    //    Gravity();
    //}

    for (int a = 0; a < 2400; a++)
    {
        if (!coll.check_collision(playerCollider, tilemap2[a]))
        {
            Gravity();
        }
    }

    if (m_position.getY() + 36 > 960)
    {
        m_velocity.setY(0);
        m_gravitySpeed.setY(0);
        m_acceleration.setY(0);
    }

    if (Camera.x < 0)
    {
        Camera.x = 0;
    }
    if (Camera.y < 0)
    {
        Camera.y = 0;
    }
    if (Camera.x > LEVEL_WIDTH - Camera.w)
    {
        Camera.x = LEVEL_WIDTH - Camera.w;
    }
    if (Camera.y > LEVEL_HEIGHT - Camera.h)
    {
        Camera.y = LEVEL_HEIGHT - Camera.h;
    }
    std::cout << m_position.getY() << std::endl;
}
void Player::handleInput()
{
    m_currentFrame = ((SDL_GetTicks() / 100) % 1);//idle���� �ִϸ��̼�

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
       if (m_position.getY() + 32 > 960)
       {
           m_velocity.setY(0);
       }
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
    m_acceleration.setY(-20);
    isjumping = false;
}
void Player::drawmap()
{
    int x, y;

    for (y = 0; y < MAX_MAP_Y; y++)
    {
        for (x = 0; x < MAX_MAP_X; x++)
        {
            if (tile[y][x] != 0)
            {
                tilemap[y][x].x = x * 32;
                tilemap[y][x].y = y * 32;
                tilemap2[y] = tilemap[y][x];
                TheTextureManager::Instance()->draw("brick", tilemap[y][x].x - Camera.x, tilemap[y][x].y - Camera.y, 32, 32, TheGame::Instance()->getRenderer());
                //SDL_RenderDrawRect(TheGame::Instance()->getRenderer(), &tilemap2[y][x]);
            }
        }
    }
    
}
void Player::loadmap(const char* name)
{
    int x, y;
    FILE* fp;

    fp = fopen(name, "rb");

    if (fp == NULL)
    {
        printf("Failed to open map %s\n", name);

        exit(1);
    }

    for (y = 0; y < MAX_MAP_Y; y++)
    {
        for (x = 0; x < MAX_MAP_X; x++)
        {
            fscanf(fp, "%d", &tile[y][x]);
        }
    }


    fclose(fp);
}