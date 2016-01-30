#pragma once
#include "DxLib.h"
#include "GameState.h"

class DrawManager
{
private:

public:
    DrawManager(GameState*);
    ~DrawManager();
    void update();
};