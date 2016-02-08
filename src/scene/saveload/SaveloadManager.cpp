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
    if (input_state->getLeftClick() == 1) {
        leftClickProcess();
    }
}
//---------------------------------------------------------------------
void SaveloadManager::leftClickProcess()
{
    // 
    int mousex = input_state->getPointX();
    int mousey = input_state->getPointY();

    // back button
    if (SaveloadData::isButtonBackPos(mousex, mousey)) {
        scene_state->backScene();
    }
    // page button
    for (int n = 0; n < SaveloadData::getButtonPageNum(); n++) {
        if (SaveloadData::isButtonPagePos(n, mousex, mousey)) {
            saveload_state->setPage(n);
        }
    }
    // delete button
    for (int n = 0; n < SaveloadData::getSavedataNum(); n++) {
        int num = n + SaveloadData::getSavedataNum() * saveload_state->getPage();
        int px = SaveloadData::getButtonDeletePosX(n);
        int py = SaveloadData::getButtonDeletePosY(n);

        if (!SaveData::getInstance()->isData(num)) { continue; }
        if (SaveloadData::isButtonDeletePos(n, mousex, mousey)) {
            SaveData::getInstance()->deleteData(num);
            return;
        }
    }

    // savedata
    for (int n = 0; n < SaveloadData::getSavedataNum(); n++) {
        if (SaveloadData::isSavedataPos(n, mousex, mousey)) {
            int num = n + SaveloadData::getSavedataNum() * saveload_state->getPage();
            // load
            if (saveload_state->getMode() == SaveloadState::MODE_LOAD) {
                if (SaveData::getInstance()->isData(num)) {
                    int pos = SaveData::getInstance()->getScenarioPos(num);
                    scene_state->changeScene(SceneState::SCENE_MAIN);
                    scene_state->getMainState()->settingScenario(pos);
                }
            }
            // save
            if (saveload_state->getMode() == SaveloadState::MODE_SAVE) {
                int pos = scene_state->getMainState()->getScenarioNum();
                SaveData::getInstance()->save(num, pos);
            }
        }
    }
}