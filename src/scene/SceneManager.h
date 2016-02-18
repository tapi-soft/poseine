#pragma once
#include "../GameState.h"
#include "title/TitleManager.h"
#include "main/MainManager.h"
#include "saveload/SaveloadManager.h"
#include "setting/SettingManager.h"
#include "edit/EditManager.h"
#include "../data/SystemData.h"
#include "../input/InputState.h"

class SceneManager
{
private:
    InputState* input_state;

    SceneState* scene_state;
    TitleManager* title_manager;
    MainManager* main_manager;
    SaveloadManager* saveload_manager;
    SettingManager* setting_manager;
    EditManager* edit_manager;

public:
    SceneManager(GameState*);
    ~SceneManager();
    void update();
};