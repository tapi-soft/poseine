#pragma once
#include "../../GameState.h"
#include "../../SystemData.h"
#include "MainState.h"

class MainDraw
{
private:
    MainState* main_state;
    int image_back[10];
    int image_chara[10];
    int image_textbar;
    int font;
    int color_white;

    void loadImage();
public:
    MainDraw(GameState*);
    ~MainDraw();
    void update();
};