#pragma once
#include "../../GameState.h"
#include "MainData.h"

class MainManager {
private:
    MainState* main_state;
    InputState* input_state;

    void leftClickProcess();
    void textClickProcess();
    void autoButtonClickProcess();
    void skipButtonClickProcess();
    void logButtonClickProcess();
    void confButtonClickProcess();
    void saveButtonClickProcess();
    void loadButtonClickProcess();
public:
    MainManager(GameState*);
    ~MainManager();
    void update();

};