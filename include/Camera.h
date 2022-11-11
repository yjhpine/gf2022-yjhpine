#pragma once
#include "Game.h"
//https://www.youtube.com/watch?v=DeSIwhFzVYw 참고영상
#define LEVEL_WIDTH 1920      // Background's width
#define LEVEL_HEIGHT 480    // Background's height
#define SCREEN_WIDTH 640    // Screen's (camera's) width
#define SCREEN_HEIGHT 480   // Screen's (camera's) height 

class Camera : public SDLGameObject
{
public:
    Camera(const LoaderParams* pParams);
    SDL_Rect CameraRect = {
   CameraRect.x = 0,
   CameraRect.y = 0,
   CameraRect.w = SCREEN_WIDTH,
   CameraRect.h = SCREEN_HEIGHT,
    };
    virtual void update();
    virtual void draw();
};