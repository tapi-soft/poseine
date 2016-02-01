#include "BacklogManager.h"

//---------------------------------------------------------------------
BacklogManager::BacklogManager(GameState* state)
{
    input_state = state->getInputState();
    main_state = state->getSceneState()->getMainState();
}
//---------------------------------------------------------------------
BacklogManager::~BacklogManager()
{

}
//---------------------------------------------------------------------
void BacklogManager::update()
{
    // left click process
    if (input_state->getLeftClick() == 1) {
        main_state->changeState(MainState::STATE_NORMAL);
    }
}
//---------------------------------------------------------------------