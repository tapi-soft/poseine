#include "SaveloadDraw.h"

//---------------------------------------------------------------------
SaveloadDraw::SaveloadDraw(GameState* state)
{
    saveload_state = state->getSceneState()->getSaveloadState();
    input_state = state->getInputState();
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
    LoadDivGraph("image/saveload/base.png",
        2,
        1,
        2,
        514,
        114,
        image_base);
    LoadDivGraph("image/saveload/button_num.png",
        SaveloadData::getButtonPageNum() * 2,
        SaveloadData::getButtonPageNum(),
        2,
        SaveloadData::getButtonPageSizeX(),
        SaveloadData::getButtonPageSizeY(),
        image_button_num);
    LoadDivGraph("image/saveload/button_back.png",
        2,
        2,
        1,
        SaveloadData::getButtonBackSizeX(),
        SaveloadData::getButtonBackSizeY(),
        image_button_back);
    image_save_logo = LoadGraph("image/saveload/save_logo.png");
    image_load_logo = LoadGraph("image/saveload/load_logo.png");
}
//---------------------------------------------------------------------
void SaveloadDraw::update()
{
    DrawGraph(0, 0, image_back, TRUE);
    drawLogo();
    drawSavedata();
    drawButtonPage();
    drawButtonBack();
}
//---------------------------------------------------------------------
void SaveloadDraw::drawLogo()
{
    if (saveload_state->getMode() == SaveloadState::MODE_SAVE) {
        DrawGraph(25, 25, image_save_logo, TRUE);
    }
    else if (saveload_state->getMode() == SaveloadState::MODE_LOAD) {
        DrawGraph(25, 25, image_load_logo, TRUE);
    }
}
//---------------------------------------------------------------------
void SaveloadDraw::drawSavedata()
{
    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 2; x++) {
            int px = 50 + x * 540;
            int py = 100 + y * 120;
            DrawGraph(px, py, image_base[0], TRUE);
        }
    }
}
//---------------------------------------------------------------------
void SaveloadDraw::drawButtonPage()
{
    int mousex = input_state->getPointX();
    int mousey = input_state->getPointY();
    int num = SaveloadData::getButtonPageNum();

    for (int n = 0; n < num; n++) {
        int px = SaveloadData::getButtonPagePosX(n);
        int py = SaveloadData::getButtonPagePosY(n);
        int image = n + (SaveloadData::isButtonPagePos(n, mousex, mousey) ? num : 0);
        DrawGraph(px, py, image_button_num[image], TRUE);
    }
}
//---------------------------------------------------------------------
void SaveloadDraw::drawButtonBack()
{
    int mousex = input_state->getPointX();
    int mousey = input_state->getPointY();
    int image = (SaveloadData::isButtonBackPos(mousex, mousey) ? 1 : 0);
    DrawGraph(1140, 620, image_button_back[image], TRUE);
}
//---------------------------------------------------------------------