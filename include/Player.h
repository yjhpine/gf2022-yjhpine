#pragma once
#include "SDLGameObject.h"
#include "InputHandler.h"
#include "Collision.h"
#include "loadmap.h"

class Player : public SDLGameObject
{
private:
    bool isjumping;
    SDL_Rect playerCollider;
    Collision coll;
    loadMap loadmap;
    SDL_Rect camera;

    //The dimensions of the level
    const int LEVEL_WIDTH = 1280;
    const int LEVEL_HEIGHT = 960;

    //Screen dimension constants
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;

public:
    Player(const LoaderParams* pParams);
    void handleInput();
    void Jumping();
    void setCamera();
    virtual void draw();
    virtual void update();
    virtual void clean();
};
