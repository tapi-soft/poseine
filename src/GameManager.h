#pragma once
#include "DxLib.h"
#include "FpsManager.h"
#include "draw/DrawManager.h"

class GameManager {
private:
    FpsManager* fps_manager;
    DrawManager* draw_manager;
    int init();
    int update();
public:
    GameManager();
    ~GameManager();
    int start();
};