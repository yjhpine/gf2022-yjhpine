#include "camera.h"

camera::camera(const LoaderParams* pParams) : Player(pParams) {}
void camera::draw()
{
    TheTextureManager::Instance()->draw("cam", m_position.getX() - Camera.x, m_position.getY() - Camera.y, Camera.w, Camera.h, TheGame::Instance()->getRenderer());
}
void camera::clean() {}
void camera::update()
{
    Camera.x = (m_position.getX() + 16) - SCREEN_WIDTH / 2;
    Camera.y = (m_position.getY() + 16) - SCREEN_HEIGHT / 2;
    
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
    
    std::cout << Camera.x << "/" << Camera.y << "/" << Camera.w << "/" << Camera.h << std::endl;
}