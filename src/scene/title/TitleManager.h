#pragma once
#include "../../GameState.h"

class TitleManager
{
private:
    TitleState* title_state;
public:
    TitleManager(GameState*);
    ~TitleManager();
    void update();
};