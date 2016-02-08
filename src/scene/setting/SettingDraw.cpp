//---------------------------------------------------------------------
#include "SettingDraw.h"

//---------------------------------------------------------------------
SettingDraw::SettingDraw(GameState* state)
{
    loadImage();
}
//---------------------------------------------------------------------
SettingDraw::~SettingDraw()
{

}
//---------------------------------------------------------------------
void SettingDraw::loadImage()
{
    image_back = LoadGraph("image/setting/back.png");
}
//---------------------------------------------------------------------
void SettingDraw::update()
{
    DrawGraph(0, 0, image_back, TRUE);
}