#pragma once
#include "../../GameState.h"

class EditDraw
{
private:
    int image_back;
public:
    EditDraw(GameState*);
    ~EditDraw();
    void loadImage();
    void update();
};