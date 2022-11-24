#pragma once
#include "SDLGameObject.h"
//https://blog.naver.com/cory_kim/221133005724 SDL Camera lazy foo 한글번역
//https://cplusplus.com/forum/general/167637/ 카메라 구현할때 참고

class camera : public SDLGameObject
{
public:
	const int LEVEL_WIDTH = 1280;
	const int LEVEL_HEIGHT = 960;

	//Screen dimension constants
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;

	SDL_Rect Camera = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };

	camera(const LoaderParams* pParams);
	void setCamera();
};