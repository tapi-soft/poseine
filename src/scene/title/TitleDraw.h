#pragma once
#include "../../GameState.h"
#include "../../SystemData.h"

class TitleDraw
{
private:
    int image_circle_logo;

    void loadImage();
public:
    TitleDraw(GameState*);
    ~TitleDraw();
    void update();
};