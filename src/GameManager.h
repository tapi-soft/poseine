#pragma once
#include "DxLib.h"
#include "fps/FpsManager.h"
#include "DrawManager.h"
#include "GameState.h"

class GameManager {
private:
    FpsManager* fps_manager;
    DrawManager* draw_manager;
    GameState* game_state;
    int init();
    int update();
public:
    GameManager();
    ~GameManager();
    int start();
};