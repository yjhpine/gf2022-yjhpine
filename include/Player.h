#pragma once
#include "SDLGameObject.h"
#include "InputHandler.h"

class Player : public SDLGameObject
{
private:
    bool ToF;
public:
    Player(const LoaderParams* pParams);
    void handleInput();
    void Collision();
    void Jumping();
    virtual void draw();
    virtual void update();
    virtual void clean();

};
