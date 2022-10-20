#include "Collision.h"
bool Collision::check_collision(SDL_Rect a, SDL_Rect b)
{
    if (a.x + a.w >= b.x &&
        b.x + b.w >= a.x &&
        a.y + a.h >= b.y &&
        b.y + b.h >= b.y) 
    {
        return true;
    }
    return false;
}