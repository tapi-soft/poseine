//---------------------------------------------------------------------
#include "MainManager.h"

//---------------------------------------------------------------------
MainManager::MainManager(GameState* state)
{
    main_state = state->getSceneState()->getMainState();
    input_state = state->getInputState();
}
//---------------------------------------------------------------------
MainManager::~MainManager()
{

}
//---------------------------------------------------------------------
void MainManager::update()
{
    // 
    main_state->update();

    // 
    if (input_state->getLeftClick() == 1) {
        leftClickProcess();
    }
}
//---------------------------------------------------------------------
void MainManager::leftClickProcess()
{
    if (main_state->isTextDisp()) {
        main_state->fullTextOpen();
    }
    else {
        main_state->nextScenario();
    }
}