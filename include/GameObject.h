#pragma once
#include "main.h"

class GameObject
{
public:
    //virtual void load(int x, int y, int width, int height, std::string textureID);
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void clean() = 0;
	virtual ~GameObject() {}

protected:
	GameObject(const LoaderParams* pParams) {}

	//std::string m_textureID;
	//
	//int a;
	//
	//int m_x;
	//int m_y;
	//int m_width;
	//int m_height;
	//
	//int m_currentFrame;
	//int m_currentRow;
};

