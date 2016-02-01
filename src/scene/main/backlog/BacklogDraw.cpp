#include "BacklogDraw.h"

//---------------------------------------------------------------------
BacklogDraw::BacklogDraw(GameState* state)
{
    backlog_state = state->getSceneState()->getMainState()->getBacklogState();

    font = CreateFontToHandle("‚l‚r ƒSƒVƒbƒN", 28, 3, DX_FONTTYPE_ANTIALIASING_EDGE);
    color_white = GetColor(255, 255, 255);
    loadImage();
}
//---------------------------------------------------------------------
BacklogDraw::~BacklogDraw()
{

}
//---------------------------------------------------------------------
void BacklogDraw::update()
{
    DrawGraph(0, 0, image_window, TRUE);

    int num = backlog_state->getPos();
    int pre1 = AllScenarioData::getInstance()->getPrev(num);
    int pre2 = AllScenarioData::getInstance()->getPrev(pre1);

    if (pre2 == 0) { pre2 = pre1; pre1 = num; num = 0; }
    if (pre2 == 0) { pre2 = pre1; pre1 = num; num = 0; }

    if (pre2 != 0) {
        if (AllScenarioData::getInstance()->getName(pre2) != "") {
            DrawFormatStringToHandle(250, 100, color_white, font, "y%sz", AllScenarioData::getInstance()->getName(pre2).c_str());
        }
        DrawFormatStringToHandle(300, 140, color_white, font, "%s", AllScenarioData::getInstance()->getText1(pre2).c_str());
        DrawFormatStringToHandle(300, 175, color_white, font, "%s", AllScenarioData::getInstance()->getText2(pre2).c_str());
        DrawFormatStringToHandle(300, 210, color_white, font, "%s", AllScenarioData::getInstance()->getText3(pre2).c_str());
    }

    if (pre1 != 0) {
        if (AllScenarioData::getInstance()->getName(pre1) != "") {
            DrawFormatStringToHandle(250, 300, color_white, font, "y%sz", AllScenarioData::getInstance()->getName(pre1).c_str());
        }
        DrawFormatStringToHandle(300, 340, color_white, font, "%s", AllScenarioData::getInstance()->getText1(pre1).c_str());
        DrawFormatStringToHandle(300, 375, color_white, font, "%s", AllScenarioData::getInstance()->getText2(pre1).c_str());
        DrawFormatStringToHandle(300, 410, color_white, font, "%s", AllScenarioData::getInstance()->getText3(pre1).c_str());
    }

    if (AllScenarioData::getInstance()->getName(num) != "") {
        DrawFormatStringToHandle(250, 500, color_white, font, "y%sz", AllScenarioData::getInstance()->getName(num).c_str());
    }
    DrawFormatStringToHandle(300, 540, color_white, font, "%s", AllScenarioData::getInstance()->getText1(num).c_str());
    DrawFormatStringToHandle(300, 575, color_white, font, "%s", AllScenarioData::getInstance()->getText2(num).c_str());
    DrawFormatStringToHandle(300, 610, color_white, font, "%s", AllScenarioData::getInstance()->getText3(num).c_str());
}
//---------------------------------------------------------------------
void BacklogDraw::loadImage()
{
    image_window = LoadGraph("image/main/backlog_window.png");

}