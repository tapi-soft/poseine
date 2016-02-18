#pragma once
#include "DxLib.h"
#include "GameState.h"
#include "scene/title/TitleDraw.h"
#include "scene/main/MainDraw.h"
#include "scene/saveload/SaveloadDraw.h"
#include "scene/setting/SettingDraw.h"
#include "scene/edit/EditDraw.h"

class GameDraw
{
private:
    SceneState* scene_state;
    TitleDraw* title_draw;
    MainDraw* main_draw;
    SaveloadDraw* saveload_draw;
    SettingDraw* setting_draw;
    EditDraw* edit_draw;

public:
    GameDraw(GameState*);
    ~GameDraw();
    void update();
};