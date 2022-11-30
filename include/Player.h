#pragma once
#include "SDLGameObject.h"
#include "InputHandler.h"
#include "Collision.h"

#define LEVEL_WIDTH 1280
#define LEVEL_HEIGHT 960

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

class Player : public SDLGameObject
{
private:
    bool isjumping;
    SDL_Rect playerCollider;
    Collision coll;

public:
    void handleInput();
    //void Jumping();
    virtual void draw();
    virtual void update();
    virtual void clean();

    Player(const LoaderParams* pParams);

    SDL_Rect Camera = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
};
