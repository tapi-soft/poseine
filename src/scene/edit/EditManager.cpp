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
    int mousex = input_state->getPointX();
    int mousey = input_state->getPointY();

    if (input_state->getLeftClick() == 1) {
        for (int n = -2; n <= 2; n++) {
            if (EditData::isThumbnailPos(n, mousex, mousey)) {
                edit_state->selectThumbnail(n);
            }
        }
    }
}