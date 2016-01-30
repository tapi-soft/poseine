#pragma once
#include "../../GameState.h"

class MainDraw
{
private:
    int image_back[10];
    void loadImage();
public:
    MainDraw(GameState*);
    ~MainDraw();
    void update();
};