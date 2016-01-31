//---------------------------------------------------------------------
#include "MainDraw.h"

//---------------------------------------------------------------------
MainDraw::MainDraw(GameState* state)
{
    main_state = state->getSceneState()->getMainState();

    font = CreateFontToHandle("‚l‚r ƒSƒVƒbƒN", 28, 3, DX_FONTTYPE_ANTIALIASING_EDGE);
    color_white = GetColor(255, 255, 255);
    loadImage();
}
//---------------------------------------------------------------------
MainDraw::~MainDraw()
{

}
//---------------------------------------------------------------------
void MainDraw::loadImage()
{
    image_back[1] = LoadGraph("image/back/back_1.png");
    image_chara[1] = LoadGraph("image/chara/chara_1.png");
    image_textbar = LoadGraph("image/main/textbar.png");
}
//---------------------------------------------------------------------
void MainDraw::update()
{
    // back
    DrawGraph(0, 0, image_back[1], TRUE);

    // chara
    SetDrawMode(DX_DRAWMODE_BILINEAR);
    //DrawExtendGraph(140, -100, 1140, 1950, image_chara[1], TRUE);
    DrawExtendGraph(390, 100, 890, 1100, image_chara[1], TRUE);
    SetDrawMode(DX_DRAWMODE_NEAREST);

    // textwindow
    DrawGraph(0, SystemData::getWindowHeight() - 200, image_textbar, TRUE);

    // font
    DrawFormatStringToHandle(250, SystemData::getWindowHeight() - 200 + 30, color_white, font, "y%sz", main_state->getName().c_str());
    DrawFormatStringToHandle(300, SystemData::getWindowHeight() - 200 + 70, color_white, font, "%s", main_state->getText1().c_str());
    DrawFormatStringToHandle(300, SystemData::getWindowHeight() - 200 + 105, color_white, font, "%s", main_state->getText2().c_str());
    DrawFormatStringToHandle(300, SystemData::getWindowHeight() - 200 + 140, color_white, font, "%s", main_state->getText3().c_str());
}
