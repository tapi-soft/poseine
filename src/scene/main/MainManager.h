#pragma once
#include "../../GameState.h"
#include "MainData.h"

class MainManager {
private:
    MainState* main_state;
    InputState* input_state;

    void leftClickProcess();
public:
    MainManager(GameState*);
    ~MainManager();
    void update();

};