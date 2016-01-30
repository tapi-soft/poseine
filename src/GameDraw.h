#pragma once
#include "DxLib.h"
#include "GameState.h"
#include "scene/title/TitleDraw.h"

class GameDraw
{
private:
    SceneState* sceneState;
    TitleDraw* title_draw;

public:
    GameDraw(GameState*);
    ~GameDraw();
    void update();
};