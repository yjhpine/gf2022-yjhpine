#pragma once
#include "main.h"
#include "SDLGameObject.h"

class MyBullet : SDLGameObject
{
public:
	MyBullet(const LoaderParams* pParams);
	void update();
	void draw();
};