//---------------------------------------------------------------------
#include "TitleManager.h"

//---------------------------------------------------------------------
TitleManager::TitleManager(GameState* state)
{
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
        printf("BUTTON_BEGIN\n");
    }
    else if (TitleData::isButtonPos(TitleData::BUTTON_CONTINUE, mousex, mousey)) {
        printf("BUTTON_CONTINUE\n");
    }
    else if (TitleData::isButtonPos(TitleData::BUTTON_SETTING, mousex, mousey)) {
        printf("BUTTON_SETTING\n");
    }
    else if (TitleData::isButtonPos(TitleData::BUTTON_SPECIAL, mousex, mousey)) {
        printf("BUTTON_SPECIAL\n");
    }
    else if (TitleData::isButtonPos(TitleData::BUTTON_OFFICIAL, mousex, mousey)) {
        printf("BUTTON_OFFICIAL\n");
    }
    else if (TitleData::isButtonPos(TitleData::BUTTON_END, mousex, mousey)) {
        printf("BUTTON_END\n");
    }
}
//---------------------------------------------------------------------
void TitleManager::clickCircle()
{

}