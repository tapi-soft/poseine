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
    int image_chara_button[20];
    int image_button_next[2];
    int image_button_prev[2];
    int image_button_add[2];
    int image_button_del[2];
    int font;
    int font_edit;
    int color_white;
    int color_black;

    void drawEdit();
    void drawTextwindow(int, int, double);
public:
    EditDraw(GameState*);
    ~EditDraw();
    void loadImage();
    void update();

};