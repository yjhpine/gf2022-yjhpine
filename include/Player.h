#pragma once
#include "SDLGameObject.h"
#include "InputHandler.h"
#include "MyBullet.h"

class Player : public SDLGameObject
{
public:
    Player(const LoaderParams* pParams);
    void handleInput();
    void fire();
    virtual void draw();
    virtual void update();
    virtual void clean();
};
