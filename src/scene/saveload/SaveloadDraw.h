#pragma once
#include "../../GameState.h"

class SaveloadDraw
{
private:
    SaveloadState* saveload_state;
    int image_back;
    int image_base[20];
    int image_button_num[50];
    int image_button_back[2];
    int image_save_logo;
    int image_load_logo;
public:
    SaveloadDraw(GameState*);
    ~SaveloadDraw();
    void loadImage();
    void update();
};