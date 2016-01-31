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
        textClickProcess();
    }
    if (input_state->getMouseWheel() > 0) {
        logButtonClickProcess();
    }
}
//---------------------------------------------------------------------
void MainManager::leftClickProcess()
{
    int mousex = input_state->getPointX();
    int mousey = input_state->getPointY();

    if (main_state->getNowMode() == MainData::MODE_NORMAL) {
        if (MainData::isButtonPos(MainData::BUTTON_AUTO, mousex, mousey)) { autoButtonClickProcess(); }
        else if (MainData::isButtonPos(MainData::BUTTON_SKIP, mousex, mousey)) { skipButtonClickProcess(); }
        else if (MainData::isButtonPos(MainData::BUTTON_LOG, mousex, mousey)) { logButtonClickProcess(); }
        else if (MainData::isButtonPos(MainData::BUTTON_CONF, mousex, mousey)) { confButtonClickProcess(); }
        else if (MainData::isButtonPos(MainData::BUTTON_SAVE, mousex, mousey)) { saveButtonClickProcess(); }
        else if (MainData::isButtonPos(MainData::BUTTON_LOAD, mousex, mousey)) { loadButtonClickProcess(); }
        else { textClickProcess(); }
    }
    else if (main_state->getNowMode() == MainData::MODE_AUTO) {
        if (!MainData::isButtonPos(MainData::BUTTON_AUTO, mousex, mousey)) {
            main_state->changeMode(MainData::MODE_NORMAL);
        }
    }
    else if (main_state->getNowMode() == MainData::MODE_SKIP) {
        if (!MainData::isButtonPos(MainData::BUTTON_SKIP, mousex, mousey)) {
            main_state->changeMode(MainData::MODE_NORMAL);
        }
    }
}
//---------------------------------------------------------------------
void MainManager::textClickProcess()
{
    if (main_state->isTextDisp()) {
        main_state->fullTextOpen();
    }
    else {
        main_state->nextScenario();
    }
}
//---------------------------------------------------------------------
void MainManager::autoButtonClickProcess()
{
    main_state->changeMode(MainData::MODE_AUTO);
}
//---------------------------------------------------------------------
void MainManager::skipButtonClickProcess()
{
    puts("skipButtonClickProcess");
}
//---------------------------------------------------------------------
void MainManager::logButtonClickProcess()
{
    puts("logButtonClickProcess");
}
//---------------------------------------------------------------------
void MainManager::confButtonClickProcess()
{
    puts("confButtonClickProcess");
}
//---------------------------------------------------------------------
void MainManager::saveButtonClickProcess()
{
    puts("saveButtonClickProcess");
}
//---------------------------------------------------------------------
void MainManager::loadButtonClickProcess()
{
    puts("loadButtonClickProcess");
}
//---------------------------------------------------------------------