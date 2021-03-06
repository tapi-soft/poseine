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
    // 
    int mousex = input_state->getPointX();
    int mousey = input_state->getPointY();


    // left click process
    if (input_state->getLeftClick() == 1) {
        if (BacklogData::isButtonBackPos(mousex, mousey)) {
            main_state->changeState(MainState::STATE_NORMAL);
        }
    }
    // mouse wheel process
    if (input_state->getMouseWheel() < 0) {
        if (backlog_state->nextLog()) {
            main_state->changeState(MainState::STATE_NORMAL);
        }
    }
    if (input_state->getMouseWheel() > 0) {
        backlog_state->prevLog();
    }
}
//---------------------------------------------------------------------