//-----------------------------------------------------------
#include "DrawManager.h"

//-----------------------------------------------------------
DrawManager::DrawManager(GameState* state)
{

}
//-----------------------------------------------------------
DrawManager::~DrawManager()
{

}
//-----------------------------------------------------------
void DrawManager::update()
{
    DrawCircle(100, 100, 100, GetColor(255, 0, 0), TRUE);
    ScreenFlip();
}