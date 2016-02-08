//---------------------------------------------------------------------
#include "MainDraw.h"

//---------------------------------------------------------------------
MainDraw::MainDraw(GameState* state)
{
    main_state = state->getSceneState()->getMainState();
    input_state = state->getInputState();
    backlog_draw = new BacklogDraw(state);

    font = CreateFontToHandle("‚l‚r ƒSƒVƒbƒN", 28, 3, DX_FONTTYPE_ANTIALIASING_EDGE);
    color_white = GetColor(255, 255, 255);
    loadImage();
}
//---------------------------------------------------------------------
MainDraw::~MainDraw()
{
    delete(backlog_draw);
}
//---------------------------------------------------------------------
void MainDraw::loadImage()
{
    image_textbar = LoadGraph("image/main/textbar.png");
    LoadDivGraph("image/main/button_auto.png", 3, 3, 1, 49, 44, image_button_auto);
    LoadDivGraph("image/main/button_skip.png", 3, 3, 1, 49, 44, image_button_skip);
    LoadDivGraph("image/main/button_log.png", 3, 3, 1, 49, 44, image_button_log);
    LoadDivGraph("image/main/button_conf.png", 3, 3, 1, 49, 44, image_button_conf);
    LoadDivGraph("image/main/button_save.png", 3, 3, 1, 49, 44, image_button_save);
    LoadDivGraph("image/main/button_load.png", 3, 3, 1, 49, 44, image_button_load);
    LoadDivGraph("image/main/select.png", 2, 1, 2, 800, 80, image_select);
}
//---------------------------------------------------------------------
void MainDraw::update()
{
    drawMain();

    if (main_state->getNowState() == MainState::STATE_LOG) {
        backlog_draw->update();
    }
}
//---------------------------------------------------------------------
void MainDraw::drawMain()
{
    // back
    int back_image = main_state->getBackimage();
    DrawGraph(0, 0, ImageData::getInstance()->getImageBack(back_image), TRUE);

    // chara
    SetDrawMode(DX_DRAWMODE_BILINEAR);
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 - main_state->getCharaAlpha());
    drawChara(1);   // pre
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, main_state->getCharaAlpha());
    drawChara(2);   // next
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    drawChara(0);   // 
    SetDrawMode(DX_DRAWMODE_NEAREST);

    // text window
    if (main_state->isDispWindow()) {
        drawTextwindow();
    }

    // select
    if (main_state->getNowMode() == MainData::MODE_SELECT) {
        drawSelect();
    }
}
//---------------------------------------------------------------------
void MainDraw::drawTextwindow()
{
    // window
    DrawGraph(0, SystemData::getWindowHeight() - 200, image_textbar, TRUE);

    int mousex = input_state->getPointX();
    int mousey = input_state->getPointY();

    // 
    int button_auto_state = main_state->getButtonState(MainData::BUTTON_AUTO, mousex, mousey);
    DrawGraph(
        MainData::getButtonPosX(MainData::BUTTON_AUTO),
        MainData::getButtonPosY(MainData::BUTTON_AUTO),
        image_button_auto[button_auto_state], TRUE);
    //
    int button_skip_state = main_state->getButtonState(MainData::BUTTON_SKIP, mousex, mousey);
    DrawGraph(
        MainData::getButtonPosX(MainData::BUTTON_SKIP),
        MainData::getButtonPosY(MainData::BUTTON_SKIP),
        image_button_skip[button_skip_state], TRUE);
    //
    int button_log_state = main_state->getButtonState(MainData::BUTTON_LOG, mousex, mousey);
    DrawGraph(
        MainData::getButtonPosX(MainData::BUTTON_LOG),
        MainData::getButtonPosY(MainData::BUTTON_LOG),
        image_button_log[button_log_state], TRUE);
    //
    int button_conf_state = main_state->getButtonState(MainData::BUTTON_CONF, mousex, mousey);
    DrawGraph(
        MainData::getButtonPosX(MainData::BUTTON_CONF),
        MainData::getButtonPosY(MainData::BUTTON_CONF),
        image_button_conf[button_conf_state], TRUE);
    //
    int button_save_state = main_state->getButtonState(MainData::BUTTON_SAVE, mousex, mousey);
    DrawGraph(
        MainData::getButtonPosX(MainData::BUTTON_SAVE),
        MainData::getButtonPosY(MainData::BUTTON_SAVE),
        image_button_save[button_save_state], TRUE);
    //
    int button_load_state = main_state->getButtonState(MainData::BUTTON_LOAD, mousex, mousey);
    DrawGraph(
        MainData::getButtonPosX(MainData::BUTTON_LOAD),
        MainData::getButtonPosY(MainData::BUTTON_LOAD),
        image_button_load[button_load_state], TRUE);

    // font
    if (main_state->getName() != "") {
        DrawFormatStringToHandle(250, SystemData::getWindowHeight() - 200 + 30, color_white, font, "y%sz", main_state->getName().c_str());
    }
    DrawFormatStringToHandle(300, SystemData::getWindowHeight() - 200 + 70, color_white, font, "%s", main_state->getText1().c_str());
    DrawFormatStringToHandle(300, SystemData::getWindowHeight() - 200 + 105, color_white, font, "%s", main_state->getText2().c_str());
    DrawFormatStringToHandle(300, SystemData::getWindowHeight() - 200 + 140, color_white, font, "%s", main_state->getText3().c_str());
}
//---------------------------------------------------------------------
void MainDraw::drawChara(int mode)
{
    for (int n = 1; n <= ((mode == 1) ? main_state->getPreCharaNum() : main_state->getCharaNum()); n++) {
        int pos =   ((mode == 1) ? main_state->getPreCharaPos(n)   : main_state->getCharaPos(n));
        int image = ((mode == 1) ? main_state->getPreCharaImage(n) : main_state->getCharaImage(n));
        int face =  ((mode == 1) ? main_state->getPreCharaFace(n)  : main_state->getCharaFace(n));
        int image_handl = ImageData::getInstance()->getImageChara(image);

        if (mode == 0 && !main_state->isPreCharaEqual(pos, image))  { continue; }
        if (mode == 1 && main_state->isNextCharaEqual(pos, image)) { continue; }
        if (mode == 2 && main_state->isPreCharaEqual(pos, image))  { continue; }

        switch (pos) {
        case 1: DrawExtendGraph(240, -100, 1040, 1550, image_handl, TRUE); break;
        case 2: DrawExtendGraph(390, 100, 890, 1100, image_handl, TRUE);   break;
        case 3: DrawExtendGraph(90, 100, 590, 1100, image_handl, TRUE);    break;
        case 4: DrawExtendGraph(690, 100, 1190, 1100, image_handl, TRUE);  break;
        case 5: DrawExtendGraph(490, 200, 790, 800, image_handl, TRUE);    break;
        case 6: DrawExtendGraph(90, 200, 390, 800, image_handl, TRUE);     break;
        case 7: DrawExtendGraph(890, 200, 1190, 800, image_handl, TRUE);   break;
        case 8: DrawExtendGraph(290, 200, 590, 800, image_handl, TRUE);    break;
        case 9: DrawExtendGraph(690, 200, 990, 800, image_handl, TRUE);    break;
        }
    }
}
//---------------------------------------------------------------------
void MainDraw::drawSelect()
{
    // 
    int mousex = input_state->getPointX();
    int mousey = input_state->getPointY();

    // select1
    DrawGraph(
        MainData::getSelectPosX(1),
        MainData::getSelectPosY(1),
        image_select[MainData::isSelectPos(1, mousex, mousey) ? 1 : 0],
        TRUE);
    DrawFormatStringToHandle(340, 225, color_white, font, "%s", "‘I‘ðŽˆ‚P");

    // select2
    DrawGraph(
        MainData::getSelectPosX(2),
        MainData::getSelectPosY(2),
        image_select[MainData::isSelectPos(2, mousex, mousey) ? 1 : 0],
        TRUE);
    DrawFormatStringToHandle(340, 375, color_white, font, "%s", "‘I‘ðŽˆ‚Q");
}