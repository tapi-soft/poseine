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

    // auto button
    if (MainData::isButtonPos(MainData::BUTTON_AUTO, mousex, mousey)) {
        autoButtonClickProcess();
    }
    // skip button
    else if (MainData::isButtonPos(MainData::BUTTON_SKIP, mousex, mousey)) {
        skipButtonClickProcess();
    }
    // log button
    else if (MainData::isButtonPos(MainData::BUTTON_LOG, mousex, mousey)) {
        logButtonClickProcess();
    }
    // conf button
    else if (MainData::isButtonPos(MainData::BUTTON_CONF, mousex, mousey)) {
        confButtonClickProcess();
    }
    // save button
    else if (MainData::isButtonPos(MainData::BUTTON_SAVE, mousex, mousey)) {
        saveButtonClickProcess();
    }
    // load button
    else if (MainData::isButtonPos(MainData::BUTTON_LOAD, mousex, mousey)) {
        loadButtonClickProcess();
    }
    // text
    else {
        textClickProcess();
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
    puts("autoButtonClickProcess");
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