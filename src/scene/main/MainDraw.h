#pragma once
#include "../../GameState.h"
#include "../../SystemData.h"

class MainDraw
{
private:
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