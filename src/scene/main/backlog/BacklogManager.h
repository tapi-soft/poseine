#pragma once
#include "../../../GameState.h"
#include "BacklogData.h"

class BacklogManager {
private:
    InputState* input_state;
    MainState* main_state;
    BacklogState* backlog_state;
public:
    BacklogManager(GameState*);
    ~BacklogManager();
    void update();
};