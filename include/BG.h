#pragma once
#include "Game.h"

#define LEVEL_WIDTH 1280
#define LEVEL_HEIGHT 960

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

class BG : public SDLGameObject
{
private:
    SDL_Rect bg = { 0, 0, LEVEL_WIDTH, LEVEL_HEIGHT };
public:
    BG(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
    int x = 0;
    int y = 0;
};
