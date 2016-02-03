#include "SaveloadManager.h"

//---------------------------------------------------------------------
SaveloadManager::SaveloadManager(GameState* state)
{
    input_state = state->getInputState();
    scene_state = state->getSceneState();
    saveload_state = scene_state->getSaveloadState();
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
        for (int n = 0; n < SaveloadData::getButtonPageNum(); n++) {
            if (SaveloadData::isButtonPagePos(n, mousex, mousey)) {
                saveload_state->setPage(n);
            }
        }
        for (int n = 0; n < SaveloadData::getSavedataNum(); n++) {
            if (SaveloadData::isSavedataPos(n, mousex, mousey)) {
                printf("savedata num %d\n", n);
            }
        }
    }
}