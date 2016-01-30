#pragma once
#include "../../GameState.h"
#include "TitleData.h"

class TitleManager
{
private:
    TitleState* title_state;
    InputState* input_state;

    void clickTitle();
    void clickCircle();
public:
    TitleManager(GameState*);
    ~TitleManager();
    void update();
};