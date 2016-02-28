//---------------------------------------------------------------------
#include "EditDraw.h"
#include "DxLib.h"

//---------------------------------------------------------------------
EditDraw::EditDraw(GameState* state)
{
    edit_state = state->getSceneState()->getEditState();

    font = CreateFontToHandle("�l�r �S�V�b�N", 19, 5, DX_FONTTYPE_ANTIALIASING_EDGE);
    font_edit = CreateFontToHandle("�l�r �S�V�b�N", 12, -1, DX_FONTTYPE_NORMAL);
    
    color_white = GetColor(255, 255, 255);
    color_black = GetColor(0, 0, 0);
    loadImage();
}
//---------------------------------------------------------------------
EditDraw::~EditDraw()
{

}
//---------------------------------------------------------------------
void EditDraw::loadImage()
{
    image_back = LoadGraph("image/edit/back.png");
    image_textbar = LoadGraph("image/main/textbar.png");
}
//---------------------------------------------------------------------
void EditDraw::update()
{
    DrawGraph(0, 0, image_back, TRUE);

    //---- edit
    drawEdit();

    //---- preview
    ScenarioDraw::drawImage(edit_state->getScenarioNum(), 428, 0, 0.665625);
    drawTextwindow(428, 0, 0.665625);

    //---- timeline
    //---- scenario select
    int num = edit_state->getScenarioNum();
    int prev1 = AllScenarioData::getInstance()->getPrev(num);
    int prev2 = AllScenarioData::getInstance()->getPrev(prev1);
    int next1 = AllScenarioData::getInstance()->getNext(num);
    int next2 = AllScenarioData::getInstance()->getNext(next1);
    if (next1 == 0) { next2 = 0; }
    if (prev1 == 0) { prev2 = 0; }

    if (prev2 != 0) { ScenarioDraw::drawImage(prev2, EditData::getThumbnailPosX(-2), EditData::getThumbnailPosY(-2), 0.1); }
    if (prev1 != 0) { ScenarioDraw::drawImage(prev1, EditData::getThumbnailPosX(-1), EditData::getThumbnailPosY(-1), 0.1); }
    if (num != 0)   { ScenarioDraw::drawImage(num, EditData::getThumbnailPosX(0), EditData::getThumbnailPosY(0), 0.1); }
    if (next1 != 0) { ScenarioDraw::drawImage(next1, EditData::getThumbnailPosX(1), EditData::getThumbnailPosY(1), 0.1); }
    if (next2 != 0) { ScenarioDraw::drawImage(next2, EditData::getThumbnailPosX(2), EditData::getThumbnailPosY(2), 0.1); }
}
//---------------------------------------------------------------------
void EditDraw::drawEdit()
{
    int num = edit_state->getScenarioNum();

    //----
    DrawFormatStringToHandle(95, 20, color_black, font_edit, "%d", num);
    DrawFormatStringToHandle(235, 20, color_black, font_edit, "%d", AllScenarioData::getInstance()->getNext(num));
    DrawFormatStringToHandle(375, 20, color_black, font_edit, "%d", AllScenarioData::getInstance()->getPrev(num));
    //----
    if (edit_state->getInputActive()) {
        DrawKeyInputString(
            EditData::getEditNamePosX(),
            EditData::getEditNamePosY(),
            edit_state->getInputHandl());
    }
    else {
        DrawFormatStringToHandle(90, 65, color_black, font_edit, "%s", AllScenarioData::getInstance()->getName(num).c_str());
    }
    DrawFormatStringToHandle(90, 95, color_black, font_edit, "%s", AllScenarioData::getInstance()->getText1(num).c_str());
    DrawFormatStringToHandle(90, 123, color_black, font_edit, "%s", AllScenarioData::getInstance()->getText2(num).c_str());
    DrawFormatStringToHandle(90, 152, color_black, font_edit, "%s", AllScenarioData::getInstance()->getText3(num).c_str());
}
//---------------------------------------------------------------------
void EditDraw::drawTextwindow(int x, int y, double rate)
{
    int num = edit_state->getScenarioNum();

    // window
    DrawExtendGraph(
        x,
        (int)(y + (SystemData::getInstance()->getWindowHeight() - 200) * rate),
        (int)(x + 1280 * rate),
        (int)(y + (SystemData::getInstance()->getWindowHeight()) * rate),
        image_textbar,
        TRUE);

    // font
    if (AllScenarioData::getInstance()->getName(num) != "") {
        DrawFormatStringToHandle(
            (int)(x + 250 * rate),
            (int)(y + (SystemData::getInstance()->getWindowHeight() - 200 + 30) * rate),
            color_white, font, "�y%s�z", (AllScenarioData::getInstance()->getName(num).c_str()));
    }
    DrawFormatStringToHandle(
        (int)(x + 300 * rate),
        (int)(y + (SystemData::getInstance()->getWindowHeight() - 200 + 70) * rate),
        color_white, font, "%s", AllScenarioData::getInstance()->getText1(num).c_str());
    DrawFormatStringToHandle(
        (int)(x + 300 * rate),
        (int)(y + (SystemData::getInstance()->getWindowHeight() - 200 + 105) * rate),
        color_white, font, "%s", AllScenarioData::getInstance()->getText2(num).c_str());
    DrawFormatStringToHandle(
        (int)(x + 300 * rate),
        (int)(y + (SystemData::getInstance()->getWindowHeight() - 200 + 140) * rate),
        color_white, font, "%s", AllScenarioData::getInstance()->getText3(num).c_str());
}