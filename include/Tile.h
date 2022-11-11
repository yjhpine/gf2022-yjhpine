#pragma once
#include "SDLGameObject.h"
//https://github.com/connorkuehl/sdl2-tiled-example/blob/master/src/level.cpp Âü°í
class Tile
{
private:
    //The attributes of the tile
    SDL_Rect box;

    //The tile type
    int type;

    //Tile constants
    const int TILE_WIDTH = 80;
    const int TILE_HEIGHT = 80;
    const int TOTAL_TILES = 192;
    const int TILE_SPRITES = 12;

    //The different tile sprites
    const int TILE_RED = 0;
    const int TILE_GREEN = 1;
    const int TILE_BLUE = 2;
    const int TILE_CENTER = 3;
    const int TILE_TOP = 4;
    const int TILE_TOPRIGHT = 5;
    const int TILE_RIGHT = 6;
    const int TILE_BOTTOMRIGHT = 7;
    const int TILE_BOTTOM = 8;
    const int TILE_BOTTOMLEFT = 9;
    const int TILE_LEFT = 10;
    const int TILE_TOPLEFT = 11;

public:
    //Initializes the variables
    Tile(int x, int y, int tileType);

    //Shows the tile
    //void show();

    //Get the tile type
    int get_type();

    //Get the collision box
    SDL_Rect get_box();
};