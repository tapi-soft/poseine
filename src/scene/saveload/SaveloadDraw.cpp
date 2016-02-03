#include "SaveloadDraw.h"

//---------------------------------------------------------------------
SaveloadDraw::SaveloadDraw(GameState* state)
{
    saveload_state = state->getSceneState()->getSaveloadState();
    loadImage();
}
//---------------------------------------------------------------------
SaveloadDraw::~SaveloadDraw()
{

}
//---------------------------------------------------------------------
void SaveloadDraw::loadImage()
{
    image_back = LoadGraph("image/saveload/back.png");
    LoadDivGraph("image/saveload/base.png", 2, 1, 2, 514, 114, image_base);
    LoadDivGraph("image/saveload/button_num.png", 40, 20, 2, 40, 40, image_button_num);
    LoadDivGraph("image/saveload/button_back.png", 2, 2, 1, 100, 80, image_button_back);
    image_save_logo = LoadGraph("image/saveload/save_logo.png");
    image_load_logo = LoadGraph("image/saveload/load_logo.png");
}
//---------------------------------------------------------------------
void SaveloadDraw::update()
{
    // background image
    DrawGraph(0, 0, image_back, TRUE);

    // logo
    if (saveload_state->getMode() == SaveloadState::MODE_SAVE) {
        DrawGraph(25, 25, image_save_logo, TRUE);
    }
    else if (saveload_state->getMode() == SaveloadState::MODE_LOAD) {
        DrawGraph(25, 25, image_load_logo, TRUE);
    }


    // base image
    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 2; x++) {
            int px = 50 + x * 540;
            int py = 100 + y * 120;
            DrawGraph(px, py, image_base[0], TRUE);
        }
    }

    // number button image
    for (int n = 0; n < 20; n++) {
        int px = 1150 + (n / 10) * 50;
        int py = 100 + (n % 10) * 50;
        DrawGraph(px, py, image_button_num[n], TRUE);
    }

    // back button image
    DrawGraph(1140, 620, image_button_back[0], TRUE);
}