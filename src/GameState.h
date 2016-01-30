#pragma once
#include "scene/SceneState.h"

class GameState
{
private:
    SceneState* scene_state;
public:
    GameState();
    ~GameState();
    SceneState* getSceneState();
};