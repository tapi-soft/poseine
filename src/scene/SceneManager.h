#pragma once
#include "../GameState.h"

class SceneManager
{
private:
    SceneState* scene_state;
public:
    SceneManager(GameState*);
    ~SceneManager();
    void update();
};