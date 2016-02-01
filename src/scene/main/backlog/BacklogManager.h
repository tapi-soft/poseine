#pragma once
#include "../../../GameState.h"

class BacklogManager {
private:
    InputState* input_state;
    MainState* main_state;
public:
    BacklogManager(GameState*);
    ~BacklogManager();
    void update();
};