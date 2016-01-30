#pragma once
#include "../GameState.h"
#include "title/TitleManager.h"
#include "main/MainManager.h"

class SceneManager
{
private:
    SceneState* scene_state;
    TitleManager* title_manager;
    MainManager* main_manager;
public:
    SceneManager(GameState*);
    ~SceneManager();
    void update();
};