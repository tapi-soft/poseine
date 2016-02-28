//---------------------------------------------------------------------
#include "EditManager.h"
#include "DxLib.h"

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
        if (EditData::isEditNamePos(mousex, mousey)) {
            edit_state->onInputActive("name");
            SetActiveKeyInput(edit_state->getInputHandl());
        }
        if (EditData::isEditTextPos(1, mousex, mousey)) {
            edit_state->onInputActive("text1");
            SetActiveKeyInput(edit_state->getInputHandl());
        }
        if (EditData::isEditTextPos(2, mousex, mousey)) {
            edit_state->onInputActive("text2");
            SetActiveKeyInput(edit_state->getInputHandl());
        }
        if (EditData::isEditTextPos(3, mousex, mousey)) {
            edit_state->onInputActive("text3");
            SetActiveKeyInput(edit_state->getInputHandl());
        }
    }
    if (input_state->getKey(KEY_INPUT_RETURN)) {
        edit_state->offInputActive();
    }
}