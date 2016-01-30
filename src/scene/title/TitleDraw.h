#pragma once
#include "../../GameState.h"
#include "../../SystemData.h"

class TitleDraw
{
private:
    TitleState* title_state;
    int image_circle_logo;
    int image_title_back;
    int image_title_button[12];

    void loadImage();
    void drawCircle();
    void drawTitle();
public:
    TitleDraw(GameState*);
    ~TitleDraw();
    void update();
};