#pragma once
#include "../../GameState.h"

class SettingManager
{
private:
    SceneState* scene_state;
    SettingState* setting_state;
    InputState* input_state;
public:
    SettingManager(GameState*);
    ~SettingManager();
    void update();
};