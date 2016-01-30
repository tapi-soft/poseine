#pragma once
#include "scene/SceneState.h"
#include "input/InputState.h"

class GameState
{
private:
    SceneState* scene_state;
    InputState* input_state;
    bool is_end;
public:
    GameState();
    ~GameState();
    void gameEnd();
    bool isEnd();

    SceneState* getSceneState();
    InputState* getInputState();

};