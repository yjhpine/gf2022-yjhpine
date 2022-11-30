#include "BG.h"

BG::BG(const LoaderParams* pParams) : SDLGameObject(pParams) 
{
    
}
void BG::draw()
{
    TextureManager::Instance()->draw("BG",
        m_position.getX(), m_position.getY(),
        ply.Camera.w, ply.Camera.h, 
        TheGame::Instance()->getRenderer(), SDL_FLIP_NONE);
}
void BG::update()
{
    SDLGameObject::update();
}