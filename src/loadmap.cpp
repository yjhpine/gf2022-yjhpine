#include "loadmap.h"

loadMap::loadMap()
{
    ground[0].x = 32;
    ground[0].y = 320;
    ground[0].w = 605 - 32;
    ground[0].h = 479 - 230;

    ground[1].x = 288;
    ground[1].y = 304;
    ground[1].w = 496 - 288;
    ground[1].h = 338 - 304;

    ground[2].x = 384;
    ground[2].y = 288;
    ground[2].w = 447 - 384;
    ground[2].h = 303 - 288;
}