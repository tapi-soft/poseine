#pragma once
#include "DxLib.h"
#include "GameState.h"
#include "scene/title/TitleDraw.h"
#include "scene/main/MainDraw.h"

class GameDraw
{
private:
    SceneState* scene_state;
    TitleDraw* title_draw;
    MainDraw* main_draw;
public:
    GameDraw(GameState*);
    ~GameDraw();
    void update();
};