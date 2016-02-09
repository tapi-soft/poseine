//---------------------------------------------------------------------
#include "MainManager.h"

//---------------------------------------------------------------------
MainManager::MainManager(GameState* state)
{
    scene_state = state->getSceneState();
    main_state = scene_state->getMainState();
    input_state = state->getInputState();
    backlog_manager = new BacklogManager(state);
}
//---------------------------------------------------------------------
MainManager::~MainManager()
{
    delete(backlog_manager);
}
//---------------------------------------------------------------------
void MainManager::update()
{
    // 
    main_state->update();

    if (main_state->getNowState() == MainState::STATE_NORMAL) {
        updateNormal();
    }
    else if (main_state->getNowState() == MainState::STATE_LOG) {
        backlog_manager->update();
    }
}
//---------------------------------------------------------------------
void MainManager::updateNormal()
{
    // 
    int mode = main_state->getNowMode();

    // left click process
    if (input_state->getLeftClick() == 1) {
        leftClickProcess();
    }
    // right click process
    if (input_state->getRightClick() == 1) {
        rightClickProcess();
    }
    // mouse wheel process
    if (input_state->getMouseWheel() < 0) {
        if (mode == MainData::MODE_NORMAL) {
            textClickProcess();
        }
        else if (mode == MainData::MODE_SELECT) {

        }
        else {
            main_state->changeMode(MainData::MODE_NORMAL);
        }
    }
    if (input_state->getMouseWheel() > 0) {
        if (mode == MainData::MODE_NORMAL) {
            logButtonClickProcess();
        }
        else if (mode == MainData::MODE_SELECT) {
            logButtonClickProcess();
        }
        else {
            main_state->changeMode(MainData::MODE_NORMAL);
        }
    }
}
//---------------------------------------------------------------------
void MainManager::leftClickProcess()
{
    int mousex = input_state->getPointX();
    int mousey = input_state->getPointY();
    int mode = main_state->getNowMode();

    if (mode == MainData::MODE_NORMAL) {
        if (MainData::isButtonPos(MainData::BUTTON_AUTO, mousex, mousey)) { autoButtonClickProcess(); }
        else if (MainData::isButtonPos(MainData::BUTTON_SKIP, mousex, mousey)) { skipButtonClickProcess(); }
        else if (MainData::isButtonPos(MainData::BUTTON_LOG, mousex, mousey)) { logButtonClickProcess(); }
        else if (MainData::isButtonPos(MainData::BUTTON_CONF, mousex, mousey)) { confButtonClickProcess(); }
        else if (MainData::isButtonPos(MainData::BUTTON_SAVE, mousex, mousey)) { saveButtonClickProcess(); }
        else if (MainData::isButtonPos(MainData::BUTTON_LOAD, mousex, mousey)) { loadButtonClickProcess(); }
        else { textClickProcess(); }
    }
    else if (mode == MainData::MODE_AUTO) {
        if (!MainData::isButtonPos(MainData::BUTTON_AUTO, mousex, mousey)) {
            main_state->changeMode(MainData::MODE_NORMAL);
        }
    }
    else if (mode == MainData::MODE_SKIP) {
        if (!MainData::isButtonPos(MainData::BUTTON_SKIP, mousex, mousey)) {
            main_state->changeMode(MainData::MODE_NORMAL);
        }
    }
    else if (mode == MainData::MODE_SELECT) {
        if (MainData::isButtonPos(MainData::BUTTON_LOG, mousex, mousey)) { logButtonClickProcess(); }
        else if (MainData::isButtonPos(MainData::BUTTON_CONF, mousex, mousey)) { confButtonClickProcess(); }
        else if (MainData::isButtonPos(MainData::BUTTON_SAVE, mousex, mousey)) { saveButtonClickProcess(); }
        else if (MainData::isButtonPos(MainData::BUTTON_LOAD, mousex, mousey)) { loadButtonClickProcess(); }
        for (int n = 1; n <= main_state->getSelectNum(); n++) {
            if (MainData::isSelectPos(n, mousex, mousey)) {
                main_state->select(n);
            }
        }
    }
    else if (mode == MainData::MODE_HIDE) {
        main_state->changeMode(MainData::MODE_NORMAL);
    }
}
//---------------------------------------------------------------------
void MainManager::rightClickProcess()
{
    int mousex = input_state->getPointX();
    int mousey = input_state->getPointY();
    int mode = main_state->getNowMode();

    if (mode == MainData::MODE_NORMAL) {
        main_state->changeMode(MainData::MODE_HIDE);
    }
    else if (mode == MainData::MODE_HIDE) {
        main_state->changeMode(MainData::MODE_NORMAL);
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
    main_state->changeMode(MainData::MODE_SKIP);
}
//---------------------------------------------------------------------
void MainManager::logButtonClickProcess()
{
    main_state->changeState(MainState::STATE_LOG);
}
//---------------------------------------------------------------------
void MainManager::confButtonClickProcess()
{
    scene_state->changeScene(SceneState::SCENE_SETTING);
}
//---------------------------------------------------------------------
void MainManager::saveButtonClickProcess()
{
    scene_state->changeScene(SceneState::SCENE_SAVE);
}
//---------------------------------------------------------------------
void MainManager::loadButtonClickProcess()
{
    scene_state->changeScene(SceneState::SCENE_LOAD);
}
//---------------------------------------------------------------------