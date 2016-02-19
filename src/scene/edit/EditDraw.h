#pragma once
#include "../../GameState.h"
#include "../../data/ImageData.h"
#include "../../draw/ScenarioDraw.h"

class EditDraw
{
private:
    EditState* edit_state;

    int image_back;
public:
    EditDraw(GameState*);
    ~EditDraw();
    void loadImage();
    void update();
};