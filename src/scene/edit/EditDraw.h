#pragma once
#include "../../GameState.h"

class EditDraw
{
private:
public:
    EditDraw(GameState*);
    ~EditDraw();
    void loadImage();
    void update();
};