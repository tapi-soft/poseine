#pragma once
#include "scene/SceneState.h"
#include "input/InputState.h"

class GameState
{
private:
    SceneState* scene_state;
    InputState* input_state;
public:
    GameState();
    ~GameState();
    SceneState* getSceneState();
    InputState* getInputState();
};