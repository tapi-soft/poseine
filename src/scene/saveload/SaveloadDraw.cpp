#include "SaveloadDraw.h"

//---------------------------------------------------------------------
SaveloadDraw::SaveloadDraw(GameState* state)
{
    saveload_state = state->getSceneState()->getSaveloadState();
    input_state = state->getInputState();
    font_text = CreateFontToHandle("‚l‚r ƒSƒVƒbƒN", 16, 3, DX_FONTTYPE_ANTIALIASING);
    font_time = CreateFontToHandle("‚l‚r ƒSƒVƒbƒN", 16, 3, DX_FONTTYPE_ANTIALIASING);
    font_dialog = CreateFontToHandle("‚l‚r ƒSƒVƒbƒN", 25, 3, DX_FONTTYPE_ANTIALIASING);
    color_font = GetColor(63, 56, 51);
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
        SaveloadData::getSavedataSizeX(),
        SaveloadData::getSavedataSizeY(),
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
    image_thumbnail_nodata = LoadGraph("image/saveload/thumbnail_nodata.png");
    image_margin = LoadGraph("image/saveload/margin.png");
    LoadDivGraph("image/saveload/button_delete.png",
        2,
        2,
        1,
        SaveloadData::getButtonDeleteSizeX(),
        SaveloadData::getButtonDeleteSizeY(),
        image_button_delete);
}
//---------------------------------------------------------------------
void SaveloadDraw::update()
{
    DrawGraph(0, 0, image_back, TRUE);
    drawSavedata();
    DrawGraph(0, 0, image_margin, TRUE);
    drawButtonPage();
    drawButtonBack();
    drawLogo();
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
    for (int n = 0; n < SaveloadData::getSavedataNum(); n++) {
        drawSavedata(n);
    }
}
//---------------------------------------------------------------------
void SaveloadDraw::drawSavedata(int savedata_pos)
{
    int num = savedata_pos + saveload_state->getPage() * SaveloadData::getSavedataNum();
    int mousex = input_state->getPointX();
    int mousey = input_state->getPointY();

    drawSavedataThumbnail(savedata_pos);
    drawSavedataBack(savedata_pos);
    drawSavedataTime(savedata_pos);
    if (SaveData::getInstance()->isData(num)) {
        drawSavedataText(savedata_pos);
        drawButtonDelete(savedata_pos);
    }
}
//---------------------------------------------------------------------
void SaveloadDraw::drawSavedataBack(int savedata_pos)
{
    int mousex = input_state->getPointX();
    int mousey = input_state->getPointY();
    int image = SaveloadData::isSavedataPos(savedata_pos, mousex, mousey) ? 1 : 0;

    DrawGraph(
        SaveloadData::getSavedataPosX(savedata_pos),
        SaveloadData::getSavedataPosY(savedata_pos),
        image_base[image],
        TRUE);
}
//---------------------------------------------------------------------
void SaveloadDraw::drawSavedataTime(int savedata_pos)
{
    int num = savedata_pos + saveload_state->getPage() * SaveloadData::getSavedataNum();
    DrawFormatStringToHandle(
        SaveloadData::getSavedataPosX(savedata_pos) + 370,
        SaveloadData::getSavedataPosY(savedata_pos) + 90,
        color_font,
        font_time,
        "%s %s",
        SaveData::getInstance()->getSaveDay(num).c_str(),
        SaveData::getInstance()->getSaveTime(num).c_str());
}
//---------------------------------------------------------------------
void SaveloadDraw::drawSavedataText(int savedata_pos)
{
    int num = savedata_pos + saveload_state->getPage() * SaveloadData::getSavedataNum();
    int scenario_num = SaveData::getInstance()->getScenarioPos(num);
    std::string text = AllScenarioData::getInstance()->getText(scenario_num);

    DrawFormatStringToHandle(
        SaveloadData::getSavedataPosX(savedata_pos) + 195,
        SaveloadData::getSavedataPosY(savedata_pos) + 37,
        color_font,
        font_text,
        "%s",
        text.substr(0, 38).c_str());
    DrawFormatStringToHandle(
        SaveloadData::getSavedataPosX(savedata_pos) + 195,
        SaveloadData::getSavedataPosY(savedata_pos) + 57,
        color_font,
        font_text,
        "%s",
        text.substr(38, 38).c_str());
}
//---------------------------------------------------------------------
void SaveloadDraw::drawSavedataThumbnail(int savedata_pos)
{
    int num = savedata_pos + saveload_state->getPage() * SaveloadData::getSavedataNum();
    int px = SaveloadData::getSavedataPosX(savedata_pos) + 7;
    int py = SaveloadData::getSavedataPosY(savedata_pos) + 7;

    if (!SaveData::getInstance()->isData(num)) {
        DrawGraph(px, py, image_thumbnail_nodata, TRUE);
        return;
    }

    int scenario_num = SaveData::getInstance()->getScenarioPos(num);

    SetDrawMode(DX_DRAWMODE_BILINEAR);
    // background
    int back_image = AllScenarioData::getInstance()->getBackimage(scenario_num);
    DrawExtendGraph(
        px,
        py,
        px + 177,
        py + 100,
        ImageData::getInstance()->getImageBack(back_image),
        TRUE);
    // character
    for (int n = 1; n <= AllScenarioData::getInstance()->getCharaNum(scenario_num); n++) {

        int chara_image = AllScenarioData::getInstance()->getCharaImage(scenario_num, n);
        int chara_pos = AllScenarioData::getInstance()->getCharaPos(scenario_num, n);
        int image_handl = ImageData::getInstance()->getImageChara(chara_image);

        switch (chara_pos) {
        case 1: DrawExtendGraph(px + 34, py + -14, px + 146, py + 217, image_handl, TRUE); break;
        case 2: DrawExtendGraph(px + 55, py + 14, px + 125, py + 154, image_handl, TRUE); break;
        case 3: DrawExtendGraph(px + 13, py + 14, px + 83, py + 154, image_handl, TRUE); break;
        case 4: DrawExtendGraph(px + 97, py + 14, px + 167, py + 154, image_handl, TRUE); break;
        case 5: DrawExtendGraph(px + 69, py + 28, px + 117, py + 112, image_handl, TRUE); break;
        case 6: DrawExtendGraph(px + 13, py + 28, px + 55, py + 112, image_handl, TRUE); break;
        case 7: DrawExtendGraph(px + 125, py + 28, px + 167, py + 112, image_handl, TRUE); break;
        case 8: DrawExtendGraph(px + 41, py + 28, px + 83, py + 112, image_handl, TRUE); break;
        case 9: DrawExtendGraph(px + 97, py + 28, px + 139, py + 112, image_handl, TRUE); break;
        }
    }
    SetDrawMode(DX_DRAWMODE_NEAREST);
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
        if (saveload_state->getPage() == n) { image = n + num; }
        DrawGraph(px, py, image_button_num[image], TRUE);
    }
}
//---------------------------------------------------------------------
void SaveloadDraw::drawButtonBack()
{
    int mousex = input_state->getPointX();
    int mousey = input_state->getPointY();
    int image = (SaveloadData::isButtonBackPos(mousex, mousey) ? 1 : 0);
    DrawGraph(
        SaveloadData::getButtonBackPosX(),
        SaveloadData::getButtonBackPosY(),
        image_button_back[image], TRUE);
}
//---------------------------------------------------------------------
void SaveloadDraw::drawButtonDelete(int savedata_pos)
{
    int mousex = input_state->getPointX();
    int mousey = input_state->getPointY();
    int px = SaveloadData::getButtonDeletePosX(savedata_pos);
    int py = SaveloadData::getButtonDeletePosY(savedata_pos);
    int image = SaveloadData::isButtonDeletePos(savedata_pos, mousex, mousey) ? 1 : 0;
    DrawGraph(px, py, image_button_delete[image], TRUE);
}