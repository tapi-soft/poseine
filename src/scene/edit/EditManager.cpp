//---------------------------------------------------------------------
#include "EditManager.h"

//---------------------------------------------------------------------
EditManager::EditManager(GameState* state)
{
    edit_state = state->getSceneState()->getEditState();
    input_state = state->getInputState();
    scene_state = state->getSceneState();
}
//---------------------------------------------------------------------
EditManager::~EditManager()
{

}
//---------------------------------------------------------------------
void EditManager::update()
{
    if (input_state->getLeftClick()) {
    }
}