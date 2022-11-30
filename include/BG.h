#pragma once
#include "Game.h"
#include "SDLGameObject.h"
#include "TextureManager.h"

class BG : public SDLGameObject
{
private:
    SDL_Rect bg { 0, 0, 1280, 960 };
    Player ply;
public:
    BG(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
};
