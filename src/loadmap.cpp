#include "loadmap.h"

loadMap::loadMap()
{
    ground[0].x = 0;
    ground[0].y = 400;
    ground[0].w = 1280;
    ground[0].h = 80;

    ground[1].x = 600;
    ground[1].y = 350;
    ground[1].w = 300;
    ground[1].h = 50;

    ground[2].x = 900;
    ground[2].y = 280;
    ground[2].w = 300;
    ground[2].h = 200;

    ground[3].x = 1000;
    ground[3].y = 200;
    ground[3].w = 300;
    ground[3].h = 500;

    cloud[0].x = 600;
    cloud[0].y = 50;
    cloud[0].w = 200;
    cloud[0].h = 50;

    cloud[1].x = 50;
    cloud[1].y = 20;
    cloud[1].w = 200;
    cloud[1].h = 50;

    cloud[2].x = 1000;
    cloud[2].y = 10;
    cloud[2].w = 200;
    cloud[2].h = 50;

    cloud[3].x = 550;
    cloud[3].y = 40;
    cloud[3].w = 200;
    cloud[3].h = 50;
}