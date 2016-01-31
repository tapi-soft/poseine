//---------------------------------------------------------------------
#include "MainManager.h"

//---------------------------------------------------------------------
MainManager::MainManager(GameState* state)
{
    main_state = state->getSceneState()->getMainState();
}
//---------------------------------------------------------------------
MainManager::~MainManager()
{

}
//---------------------------------------------------------------------
void MainManager::update()
{
    main_state->update();
}