#pragma once
#include "../GameState.h"
#include "title/TitleManager.h"
#include "main/MainManager.h"
#include "saveload/SaveloadManager.h"
#include "setting/SettingManager.h"

class SceneManager
{
private:
    SceneState* scene_state;
    TitleManager* title_manager;
    MainManager* main_manager;
    SaveloadManager* saveload_manager;
    SettingManager* setting_manager;
public:
    SceneManager(GameState*);
    ~SceneManager();
    void update();
};