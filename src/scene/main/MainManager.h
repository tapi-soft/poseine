#pragma once
#include "../../GameState.h"

class MainManager {
private:
    MainState* main_state;
public:
    MainManager(GameState*);
    ~MainManager();
    void update();
};