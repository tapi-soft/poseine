#pragma once
#include "../../GameState.h"
#include "EditState.h"
#include "EditData.h"

class EditManager
{
private:
    EditState* edit_state;
    InputState* input_state;
    SceneState* scene_state;

public:
    EditManager(GameState*);
    ~EditManager();
    void update();
    void leftClickProcess();
    void rightClickProcess();
};