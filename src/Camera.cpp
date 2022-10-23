#include "Camera.h"

Camera::Camera(const LoaderParams* pParams) : SDLGameObject(pParams) {}
void Camera::update()
{
    CameraRect.x = (m_position.getX()+ 32) - SCREEN_WIDTH / 2;
    CameraRect.y = (m_position.getY() + 32) - SCREEN_HEIGHT / 2;

    //Keeping the Camera in bounds
    if (CameraRect.x < 0)
    {
        CameraRect.x = 0;
    }
    if (CameraRect.y < 0)
    {
        CameraRect.y = 0;
    }
    if (CameraRect.x > LEVEL_WIDTH - CameraRect.w)
    {
        CameraRect.x = LEVEL_WIDTH - CameraRect.w;
    }
    if (CameraRect.y  > LEVEL_HEIGHT - CameraRect.h)
    {
        CameraRect.y = LEVEL_HEIGHT - CameraRect.h;
    }
}
void Camera::draw()
{
    SDLGameObject::draw(flip);
}