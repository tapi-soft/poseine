//---------------------------------------------------------------------
#include "TitleDraw.h"
#include "DxLib.h"

//---------------------------------------------------------------------
TitleDraw::TitleDraw(GameState* state)
{
    loadImage();
}
//---------------------------------------------------------------------
TitleDraw::~TitleDraw()
{

}
//---------------------------------------------------------------------
void TitleDraw::loadImage()
{
    image_circle_logo = LoadGraph("image/title/circle_logo.png");
}
//---------------------------------------------------------------------
void TitleDraw::update()
{
    // îwåi
    DrawBox(0, 0,
        SystemData::getWindowWidth(),
        SystemData::getWindowHeight(),
        GetColor(255, 255, 255), TRUE);

    // ÉTÅ[ÉNÉãÉçÉS
    DrawGraph(
        SystemData::getWindowWidth() / 2 - 600 / 2,
        SystemData::getWindowHeight() / 2 - 600 / 2,
        image_circle_logo, TRUE);
}