//---------------------------------------------------------------------
#include "TitleManager.h"

//---------------------------------------------------------------------
TitleManager::TitleManager(GameState* state)
{
    game_state = state;
    title_state = state->getSceneState()->getTitleState();
    input_state = state->getInputState();
}
//---------------------------------------------------------------------
TitleManager::~TitleManager()
{

}
//---------------------------------------------------------------------
void TitleManager::update()
{
    // 
    int state = title_state->getNowState();

    // 
    title_state->update();

    // click process
    if (input_state->getClick(MOUSE_INPUT_LEFT) == 1) {
        if (state == TitleState::STATE_CIRCLE) { clickCircle(); }
        else if (state == TitleState::STATE_TITLE) { clickTitle(); }
    }
}
//---------------------------------------------------------------------
void TitleManager::clickTitle()
{
    // 
    int mousex = input_state->getPointX();
    int mousey = input_state->getPointY();

    // 
    if (TitleData::isButtonPos(TitleData::BUTTON_BEGIN, mousex, mousey)) {
        clickTitleBegin();
    }
    else if (TitleData::isButtonPos(TitleData::BUTTON_CONTINUE, mousex, mousey)) {
        clickTitleContinue();
    }
    else if (TitleData::isButtonPos(TitleData::BUTTON_SETTING, mousex, mousey)) {
        clickTitleSetting();
    }
    else if (TitleData::isButtonPos(TitleData::BUTTON_SPECIAL, mousex, mousey)) {
        clickTitleSpecial();
    }
    else if (TitleData::isButtonPos(TitleData::BUTTON_OFFICIAL, mousex, mousey)) {
        clickTitleOfficial();
    }
    else if (TitleData::isButtonPos(TitleData::BUTTON_END, mousex, mousey)) {
        clickTitleEnd();
    }
}
//---------------------------------------------------------------------
void TitleManager::clickCircle()
{

}
//---------------------------------------------------------------------
void TitleManager::clickTitleBegin()
{

}
//---------------------------------------------------------------------
void TitleManager::clickTitleContinue()
{

}
//---------------------------------------------------------------------
void TitleManager::clickTitleSetting()
{

}
//---------------------------------------------------------------------
void TitleManager::clickTitleSpecial()
{

}
//---------------------------------------------------------------------
void TitleManager::clickTitleOfficial()
{
    ShellExecute(
        NULL,
        TEXT("open"),
        TEXT("http://tapi-soft.github.io/"),
        NULL,
        TEXT(""),
        SW_SHOW);
}
//---------------------------------------------------------------------
void TitleManager::clickTitleEnd()
{
    game_state->gameEnd();
}