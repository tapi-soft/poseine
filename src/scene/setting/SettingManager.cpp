//---------------------------------------------------------------------
#include "SettingManager.h"

//---------------------------------------------------------------------
SettingManager::SettingManager(GameState* state)
{
    scene_state = state->getSceneState();
    setting_state = scene_state->getSettingState();
    input_state = state->getInputState();
}
//---------------------------------------------------------------------
SettingManager::~SettingManager()
{

}
//---------------------------------------------------------------------
void SettingManager::update()
{
    if (input_state->getLeftClick() == 1) {
        scene_state->backScene();
    }
}