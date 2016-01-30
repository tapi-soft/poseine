#pragma once
#include "DxLib.h"
#include "fps/FpsManager.h"
#include "GameDraw.h"
#include "GameState.h"
#include "scene/SceneManager.h"

class GameManager {
private:
    FpsManager* fps_manager;
    GameDraw* game_draw;
    GameState* game_state;
    SceneManager* scene_manager;
    int init();
    int update();
public:
    GameManager();
    ~GameManager();
    int start();
};