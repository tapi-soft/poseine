#pragma once
#include "../../GameState.h"
#include "SaveloadData.h"
#include "SaveData.h"

class SaveloadManager
{
private:
    InputState* input_state;
    SceneState* scene_state;
    SaveloadState* saveload_state;
public:
    SaveloadManager(GameState*);
    ~SaveloadManager();
    void update();
};