#pragma once
#include "DxLib.h"

class GameManager {
private:
    int update();

public:
    GameManager();
    ~GameManager();
    int start();
};