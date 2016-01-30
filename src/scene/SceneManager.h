#pragma once
#include "../GameState.h"
#include "title/TitleManager.h"

class SceneManager
{
private:
    SceneState* scene_state;
    TitleManager* title_manager;
public:
    SceneManager(GameState*);
    ~SceneManager();
    void update();
};