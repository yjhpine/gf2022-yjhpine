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
    void Jumping();
    virtual void draw();
    virtual void update();
    virtual void clean();
};
