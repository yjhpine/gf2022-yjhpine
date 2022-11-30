#pragma once
#include "SDLGameObject.h"
#include "InputHandler.h"
#include "Collision.h"

class Player : public SDLGameObject
{
private:
    bool isjumping;
    SDL_Rect playerCollider;
    Collision coll;

public:
    Player(const LoaderParams* pParams);
    void handleInput();
    //void Jumping();
    virtual void draw();
    virtual void update();
    virtual void clean();
    void setCamera();

    const int LEVEL_WIDTH = 1280;
    const int LEVEL_HEIGHT = 960;

    //Screen dimension constants
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;

    SDL_Rect Camera = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
};
