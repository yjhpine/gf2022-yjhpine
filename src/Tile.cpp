#include "Tile.h"

Tile::Tile(int x, int y, int tileType)
{
    //Get the offsets
    box.x = x;
    box.y = y;

    //Set the collision box
    box.w = TILE_WIDTH;
    box.h = TILE_HEIGHT;

    //Get the tile type
    type = tileType;
}
int Tile::get_type()
{
    return type;
}

SDL_Rect Tile::get_box()
{
    return box;
}