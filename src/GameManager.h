#pragma once
#include "DxLib.h"
#include "FpsManager.h"

class GameManager {
private:
    FpsManager* fps_manager;
    int init();
    int update();
public:
    GameManager();
    ~GameManager();
    int start();
};