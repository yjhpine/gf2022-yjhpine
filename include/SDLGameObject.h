#pragma once
#include "GameObject.h"

class SDLGameObject : public GameObject {
public:
	SDLGameObject(const LoaderParams* pParams);
	virtual void draw(SDL_RendererFlip flip, int x, int y);
	virtual void update();
	virtual void clean() {}
	//void Gravity();
	virtual ~SDLGameObject() {}

protected:
	//Vector2D m_gravitySpeed;
	//Vector2D m_gravity;

	Vector2D m_acceleration;
	Vector2D m_velocity;
	Vector2D m_position;

	SDL_RendererFlip flip = SDL_FLIP_NONE;

	int m_width;
	int m_height;
	int m_currentRow;
	int m_currentFrame;
	
	std::string m_textureID;
};
