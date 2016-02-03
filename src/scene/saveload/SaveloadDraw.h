#pragma once
#include "../../GameState.h"
#include "SaveloadData.h"
#include "../../input/InputState.h"

class SaveloadDraw
{
private:
    SaveloadState* saveload_state;
    InputState* input_state;
    int image_back;
    int image_base[20];
    int image_button_num[50];
    int image_button_back[2];
    int image_save_logo;
    int image_load_logo;

    void drawLogo();
    void drawSavedata();
    void drawButtonPage();
    void drawButtonBack();
public:
    SaveloadDraw(GameState*);
    ~SaveloadDraw();
    void loadImage();
    void update();
};