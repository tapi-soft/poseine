//---------------------------------------------------------------------
#include "TitleManager.h"

//---------------------------------------------------------------------
TitleManager::TitleManager(GameState* state)
{
    title_state = state->getSceneState()->getTitleState();
}
//---------------------------------------------------------------------
TitleManager::~TitleManager()
{

}
//---------------------------------------------------------------------
void TitleManager::update()
{
    title_state->update();

    // click process
}
//---------------------------------------------------------------------