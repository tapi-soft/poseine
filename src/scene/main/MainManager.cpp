//---------------------------------------------------------------------
#include "MainManager.h"

//---------------------------------------------------------------------
MainManager::MainManager(GameState* state)
{
    main_state = state->getSceneState()->getMainState();
    input_state = state->getInputState();
}
//---------------------------------------------------------------------
MainManager::~MainManager()
{

}
//---------------------------------------------------------------------
void MainManager::update()
{
    // 
    main_state->update();

    // left click process
    if (input_state->getLeftClick() == 1) {
        leftClickProcess();
    }

    // mouse wheel process
    if (input_state->getMouseWheel() < 0) {
        if (main_state->isTextDisp()) {
            main_state->fullTextOpen();
        }
        else {
            main_state->nextScenario();
        }
    }
}
//---------------------------------------------------------------------
void MainManager::leftClickProcess()
{
    int mousex = input_state->getPointX();
    int mousey = input_state->getPointY();

    // auto button
    if (MainData::isButtonPos(MainData::BUTTON_AUTO, mousex, mousey)) {
        puts("auto button");
    }
    // skip button
    else if (MainData::isButtonPos(MainData::BUTTON_SKIP, mousex, mousey)) {
        puts("skip button");
    }
    // log button
    else if (MainData::isButtonPos(MainData::BUTTON_LOG, mousex, mousey)) {
        puts("log button");
    }
    // conf button
    else if (MainData::isButtonPos(MainData::BUTTON_CONF, mousex, mousey)) {
        puts("conf button");
    }
    // save button
    else if (MainData::isButtonPos(MainData::BUTTON_SAVE, mousex, mousey)) {
        puts("save button");
    }
    // load button
    else if (MainData::isButtonPos(MainData::BUTTON_LOAD, mousex, mousey)) {
        puts("load button");
    }
    // text
    else {
        if (main_state->isTextDisp()) {
            main_state->fullTextOpen();
        }
        else {
            main_state->nextScenario();
        }
    }
}