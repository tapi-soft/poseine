#pragma once
#include "../../GameState.h"
#include "../../SystemData.h"
#include "MainState.h"
#include "MainData.h"
#include "backlog/BacklogDraw.h"

class MainDraw
{
private:
    BacklogDraw* backlog_draw;
    MainState* main_state;
    InputState* input_state;
    int image_back[10];
    int image_chara[10];
    int image_textbar;
    int image_button_auto[3];
    int image_button_skip[3];
    int image_button_log[3];
    int image_button_conf[3];
    int image_button_save[3];
    int image_button_load[3];

    int font;
    int color_white;

    void loadImage();

    void drawMain();
    void drawTextwindow();
    void drawChara(int);
public:
    MainDraw(GameState*);
    ~MainDraw();
    void update();
};