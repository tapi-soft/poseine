#pragma once
#include "../../GameState.h"
#include "../../data/ImageData.h"
#include "../../draw/ScenarioDraw.h"
#include "EditData.h"

class EditDraw
{
private:
    EditState* edit_state;

    int image_back;
    int image_textbar;
    int font;
    int color_white;
public:
    EditDraw(GameState*);
    ~EditDraw();
    void loadImage();
    void update();
    void drawTextwindow(int, int, double);
};