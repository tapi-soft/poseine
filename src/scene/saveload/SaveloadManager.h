#pragma once
#include "../../GameState.h"
#include "SaveloadData.h"

class SaveloadManager
{
private:
    InputState* input_state;
    SceneState* scene_state;
public:
    SaveloadManager(GameState*);
    ~SaveloadManager();
    void update();
};