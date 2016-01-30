#pragma once
#include "DxLib.h"
#include "GameState.h"

class GameDraw
{
private:

public:
    DrawManager(GameState*);
    ~DrawManager();
    void update();
};