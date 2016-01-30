#pragma once
#include "../../GameState.h"
#include "../../SystemData.h"

class TitleDraw
{
private:
    TitleState* title_state;
    int image_circle_logo;

    void loadImage();
    void drawCircle();
    void drawTitle();
public:
    TitleDraw(GameState*);
    ~TitleDraw();
    void update();
};