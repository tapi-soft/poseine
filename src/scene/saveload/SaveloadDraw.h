#pragma once
#include "../../GameState.h"

class SaveloadDraw
{
private:
    int image_back;
public:
    SaveloadDraw(GameState*);
    ~SaveloadDraw();
    void loadImage();
    void update();
};