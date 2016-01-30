//---------------------------------------------------------------------
#include "TitleDraw.h"
#include "DxLib.h"

//---------------------------------------------------------------------
TitleDraw::TitleDraw(GameState* state)
{
    title_state = state->getSceneState()->getTitleState();
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
    //---- main content
    int state = title_state->getNowState();
    if (state == TitleState::STATE_CIRCLE) { drawCircle(); }
    if (state == TitleState::STATE_TITLE) { drawTitle(); }

    //---- fadeout/fadein
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, title_state->getAlpha());
    DrawBox(0, 0,
        SystemData::getWindowWidth(),
        SystemData::getWindowHeight(),
        GetColor(0, 0, 0), TRUE);
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}
//---------------------------------------------------------------------
void TitleDraw::drawCircle()
{
    // background
    DrawBox(0, 0,
        SystemData::getWindowWidth(),
        SystemData::getWindowHeight(),
        GetColor(255, 255, 255), TRUE);

    // circle logo
    DrawGraph(
        SystemData::getWindowWidth() / 2 - 600 / 2,
        SystemData::getWindowHeight() / 2 - 600 / 2,
        image_circle_logo, TRUE);
}
//---------------------------------------------------------------------
void TitleDraw::drawTitle()
{

}