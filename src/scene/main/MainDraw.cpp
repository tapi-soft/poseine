//---------------------------------------------------------------------
#include "MainDraw.h"

//---------------------------------------------------------------------
MainDraw::MainDraw(GameState* state)
{
    main_state = state->getSceneState()->getMainState();
    input_state = state->getInputState();

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
    LoadDivGraph("image/main/button_auto.png", 3, 3, 1, 49, 44, image_button_auto);
    LoadDivGraph("image/main/button_skip.png", 3, 3, 1, 49, 44, image_button_skip);
    LoadDivGraph("image/main/button_log.png", 3, 3, 1, 49, 44, image_button_log);
    LoadDivGraph("image/main/button_conf.png", 3, 3, 1, 49, 44, image_button_conf);
    LoadDivGraph("image/main/button_save.png", 3, 3, 1, 49, 44, image_button_save);
    LoadDivGraph("image/main/button_load.png", 3, 3, 1, 49, 44, image_button_load);
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

    drawTextwindow();

    // font
    DrawFormatStringToHandle(250, SystemData::getWindowHeight() - 200 + 30, color_white, font, "y%sz", main_state->getName().c_str());
    DrawFormatStringToHandle(300, SystemData::getWindowHeight() - 200 + 70, color_white, font, "%s", main_state->getText1().c_str());
    DrawFormatStringToHandle(300, SystemData::getWindowHeight() - 200 + 105, color_white, font, "%s", main_state->getText2().c_str());
    DrawFormatStringToHandle(300, SystemData::getWindowHeight() - 200 + 140, color_white, font, "%s", main_state->getText3().c_str());
}

//---------------------------------------------------------------------
void MainDraw::drawTextwindow()
{
    // textwindow
    DrawGraph(0, SystemData::getWindowHeight() - 200, image_textbar, TRUE);

    int mousex = input_state->getPointX();
    int mousey = input_state->getPointY();

    //
    int button_auto_state = MainData::isButtonPos(MainData::BUTTON_AUTO, mousex, mousey) ? 1 : 0;
    DrawGraph(
        MainData::getButtonPosX(MainData::BUTTON_AUTO),
        MainData::getButtonPosY(MainData::BUTTON_AUTO),
        image_button_auto[button_auto_state], TRUE);
    //
    int button_skip_state = MainData::isButtonPos(MainData::BUTTON_SKIP, mousex, mousey) ? 1 : 0;
    DrawGraph(
        MainData::getButtonPosX(MainData::BUTTON_SKIP),
        MainData::getButtonPosY(MainData::BUTTON_SKIP),
        image_button_skip[button_skip_state], TRUE);
    //
    int button_log_state = MainData::isButtonPos(MainData::BUTTON_LOG, mousex, mousey) ? 1 : 0;
    DrawGraph(
        MainData::getButtonPosX(MainData::BUTTON_LOG),
        MainData::getButtonPosY(MainData::BUTTON_LOG),
        image_button_log[button_log_state], TRUE);
    //
    int button_conf_state = MainData::isButtonPos(MainData::BUTTON_CONF, mousex, mousey) ? 1 : 0;
    DrawGraph(
        MainData::getButtonPosX(MainData::BUTTON_CONF),
        MainData::getButtonPosY(MainData::BUTTON_CONF),
        image_button_conf[button_conf_state], TRUE);
    //
    int button_save_state = MainData::isButtonPos(MainData::BUTTON_SAVE, mousex, mousey) ? 1 : 0;
    DrawGraph(
        MainData::getButtonPosX(MainData::BUTTON_SAVE),
        MainData::getButtonPosY(MainData::BUTTON_SAVE),
        image_button_save[button_save_state], TRUE);
    //
    int button_load_state = MainData::isButtonPos(MainData::BUTTON_LOAD, mousex, mousey) ? 1 : 0;
    DrawGraph(
        MainData::getButtonPosX(MainData::BUTTON_LOAD),
        MainData::getButtonPosY(MainData::BUTTON_LOAD),
        image_button_load[button_load_state], TRUE);
}