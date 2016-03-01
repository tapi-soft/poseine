//---------------------------------------------------------------------
#include "EditDraw.h"
#include "DxLib.h"

//---------------------------------------------------------------------
EditDraw::EditDraw(GameState* state)
{
    edit_state = state->getSceneState()->getEditState();

    font = CreateFontToHandle("‚l‚r ƒSƒVƒbƒN", 19, 5, DX_FONTTYPE_ANTIALIASING_EDGE);
    font_edit = CreateFontToHandle("‚l‚r ƒSƒVƒbƒN", 12, -1, DX_FONTTYPE_NORMAL);
    
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
    LoadDivGraph("image/edit/chara_button.png", 20, 10, 2,
        EditData::getEditCharaButtonSizeX(0), EditData::getEditCharaButtonSizeY(0), image_chara_button);
    LoadDivGraph("image/edit/button_next.png", 2, 2, 1, 28, 28, image_button_next);
    LoadDivGraph("image/edit/button_prev.png", 2, 2, 1, 28, 28, image_button_prev);
}
//---------------------------------------------------------------------
void EditDraw::update()
{
    DrawGraph(0, 0, image_back, TRUE);

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

    //---- edit
    drawEdit();

}
//---------------------------------------------------------------------
void EditDraw::drawEdit()
{
    int num = edit_state->getScenarioNum();

    //----
    DrawFormatStringToHandle(95, 20, color_black, font_edit, "%d", num);
    DrawFormatStringToHandle(235, 20, color_black, font_edit, "%d", AllScenarioData::getInstance()->getNext(num));
    DrawFormatStringToHandle(375, 20, color_black, font_edit, "%d", AllScenarioData::getInstance()->getPrev(num));
    //---- name
    if (edit_state->getInputActive() && edit_state->getInputStr() == "name") {
        DrawKeyInputString(EditData::getEditNamePosX(), EditData::getEditNamePosY(), edit_state->getInputHandl());
    }
    else {
        DrawFormatStringToHandle(90, 65, color_black, font_edit, "%s", AllScenarioData::getInstance()->getName(num).c_str());
    }
    //---- text1
    if (edit_state->getInputActive() && edit_state->getInputStr() == "text1") {
        DrawKeyInputString(EditData::getEditTextPosX(1), EditData::getEditTextPosY(1), edit_state->getInputHandl());
    }
    else {
        DrawFormatStringToHandle(90, 95, color_black, font_edit, "%s", AllScenarioData::getInstance()->getText1(num).c_str());
    }
    //---- text2
    if (edit_state->getInputActive() && edit_state->getInputStr() == "text2") {
        DrawKeyInputString(EditData::getEditTextPosX(2), EditData::getEditTextPosY(2), edit_state->getInputHandl());
    }
    else {
        DrawFormatStringToHandle(90, 123, color_black, font_edit, "%s", AllScenarioData::getInstance()->getText2(num).c_str());
    }
    //---- text3
    if (edit_state->getInputActive() && edit_state->getInputStr() == "text3") {
        DrawKeyInputString(EditData::getEditTextPosX(3), EditData::getEditTextPosY(3), edit_state->getInputHandl());
    }
    else {
        DrawFormatStringToHandle(90, 152, color_black, font_edit, "%s", AllScenarioData::getInstance()->getText3(num).c_str());
    }
    //---- chara button
    for (int i = 0; i < AllScenarioData::getInstance()->getCharaNum(num); i++) {
        DrawGraph(
            EditData::getEditCharaButtonPosX(i),
            EditData::getEditCharaButtonPosY(i),
            image_chara_button[((edit_state->getSelectChara() == i) ? i + 10 : i)], TRUE);
    }
    //---- chara
    int chara_num = edit_state->getSelectChara() + 1;
    if (chara_num <= AllScenarioData::getInstance()->getCharaNum(num)) {
        //---- chara pos
        DrawFormatStringToHandle(90, 220, color_black, font_edit, "%d", AllScenarioData::getInstance()->getCharaPos(num, chara_num));
        DrawGraph(
            EditData::getEditButtonPrevCharaPosPosX(),
            EditData::getEditButtonPrevCharaPosPosY(),
            image_button_prev[0], TRUE);
        DrawGraph(
            EditData::getEditButtonNextCharaPosPosX(),
            EditData::getEditButtonNextCharaPosPosY(),
            image_button_next[0], TRUE);
        //---- chara image
        DrawFormatStringToHandle(90, 250, color_black, font_edit, "%d", AllScenarioData::getInstance()->getCharaImage(num, chara_num));
        DrawGraph(
            EditData::getEditButtonPrevCharaImagePosX(),
            EditData::getEditButtonPrevCharaImagePosY(),
            image_button_prev[0], TRUE);
        DrawGraph(
            EditData::getEditButtonNextCharaImagePosX(),
            EditData::getEditButtonNextCharaImagePosY(),
            image_button_next[0], TRUE);
        //---- chara face
        DrawFormatStringToHandle(90, 280, color_black, font_edit, "%d", AllScenarioData::getInstance()->getCharaFace(num, chara_num));
        DrawGraph(
            EditData::getEditButtonPrevCharaFacePosX(),
            EditData::getEditButtonPrevCharaFacePosY(),
            image_button_prev[0], TRUE);
        DrawGraph(
            EditData::getEditButtonNextCharaFacePosX(),
            EditData::getEditButtonNextCharaFacePosY(),
            image_button_next[0], TRUE);
    }
    //---- back
    DrawFormatStringToHandle(90, 325, color_black, font_edit, "%d", AllScenarioData::getInstance()->getBackimage(num));
    DrawGraph(
        EditData::getEditButtonPrevBackimagePosX(),
        EditData::getEditButtonPrevBackimagePosY(),
        image_button_prev[0], TRUE);
    DrawGraph(
        EditData::getEditButtonNextBackimagePosX(),
        EditData::getEditButtonNextBackimagePosY(),
        image_button_next[0], TRUE);
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
            color_white, font, "y%sz", (AllScenarioData::getInstance()->getName(num).c_str()));
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