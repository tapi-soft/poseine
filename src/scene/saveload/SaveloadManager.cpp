#include "SaveloadManager.h"

//---------------------------------------------------------------------
SaveloadManager::SaveloadManager(GameState* state)
{
    input_state = state->getInputState();
    scene_state = state->getSceneState();
}
//---------------------------------------------------------------------
SaveloadManager::~SaveloadManager()
{

}
//---------------------------------------------------------------------
void SaveloadManager::update()
{
    int mousex = input_state->getPointX();
    int mousey = input_state->getPointY();

    if (input_state->getLeftClick() == 1) {
        if (SaveloadData::isButtonBackPos(mousex, mousey)) {
            scene_state->backScene();
        }
    }
}