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
}