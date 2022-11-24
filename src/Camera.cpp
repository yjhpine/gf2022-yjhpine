#include "camera.h"

camera::camera(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void camera::draw()
{
    SDL_RenderDrawRect(Game::Instance()->getRenderer(), &Camera);
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
}