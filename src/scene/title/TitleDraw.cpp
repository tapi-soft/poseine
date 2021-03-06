//---------------------------------------------------------------------
#include "TitleDraw.h"
#include "DxLib.h"

//---------------------------------------------------------------------
TitleDraw::TitleDraw(GameState* state)
{
    title_state = state->getSceneState()->getTitleState();
    input_state = state->getInputState();
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
    image_title_back = LoadGraph("image/title/title_back.png");
    LoadDivGraph("image/title/title_button.png",
        TitleData::getButtonNum() * 2,
        TitleData::getButtonNum(),
        2,
        TitleData::getButtonSizeX(),
        TitleData::getButtonSizeY(),
        image_title_button);
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
        SystemData::getInstance()->getWindowWidth(),
        SystemData::getInstance()->getWindowHeight(),
        GetColor(0, 0, 0), TRUE);
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}
//---------------------------------------------------------------------
void TitleDraw::drawCircle()
{
    // background
    DrawBox(0, 0,
        SystemData::getInstance()->getWindowWidth(),
        SystemData::getInstance()->getWindowHeight(),
        GetColor(255, 255, 255), TRUE);

    // circle logo
    DrawGraph(
        SystemData::getInstance()->getWindowWidth() / 2 - 600 / 2,
        SystemData::getInstance()->getWindowHeight() / 2 - 600 / 2,
        image_circle_logo, TRUE);
}
//---------------------------------------------------------------------
void TitleDraw::drawTitle()
{
    //
    int mousex = input_state->getPointX();
    int mousey = input_state->getPointY();

    // background
    DrawGraph(0, 0, image_title_back, TRUE);

    // button
    for (int n = 0; n < 6; n++) {
        DrawGraph(
            TitleData::getButtonPosX(n),
            TitleData::getButtonPosY(n),
            image_title_button[TitleData::getButtonImage(n, mousex, mousey)],
            TRUE);
    }
}