#pragma once
#include "SDL2/SDL.h"
#include <string>
#include <vector>
#include <map>

typedef int gid;

// Stores information about an individual tile to be
// displayed.
struct tile {
    SDL_Texture* sheet;
    int x;
    int y;
    int tx;
    int ty;
    int width;
    int height;

    tile(SDL_Texture* tset, int x = 0, int y = 0,
        int tx = 0, int ty = 0, int w = 0, int h = 0);
    void draw(SDL_Renderer* ren);
};

class level {
public:
    level(const std::string& name);
    void load(const std::string& path, SDL_Renderer* ren);
    void draw(SDL_Renderer* ren);
private:
    std::string name;
    int rows;
    int cols;
    int tile_width;
    int tile_height;
    std::vector<tile> tiles;
    std::map<gid, SDL_Texture*> tilesets;
};