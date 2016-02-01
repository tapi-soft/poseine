#include "BacklogManager.h"

//---------------------------------------------------------------------
BacklogManager::BacklogManager(GameState* state)
{
    input_state = state->getInputState();
    main_state = state->getSceneState()->getMainState();
    backlog_state = main_state->getBacklogState();
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
    // mouse wheel process
    if (input_state->getMouseWheel() < 0) {
        backlog_state->nextLog();
    }
    if (input_state->getMouseWheel() > 0) {
        backlog_state->prevLog();
    }
}
//---------------------------------------------------------------------