//---------------------------------------------------------------------
#include "TitleState.h"

//---------------------------------------------------------------------
const int TitleState::STATE_CIRCLE = 0;
const int TitleState::STATE_TITLE = 1;
const int TitleState::ACTION_CIRCLE_FADEIN = 0;
const int TitleState::ACTION_CIRCLE_DISP = 1;
const int TitleState::ACTION_CIRCLE_FADEOUT = 2;

//---------------------------------------------------------------------
TitleState::TitleState()
{
    now_state = STATE_CIRCLE;
    now_action = ACTION_CIRCLE_FADEIN;
    alpha = 255;
}
//---------------------------------------------------------------------
TitleState::~TitleState()
{

}
//---------------------------------------------------------------------
void TitleState::update()
{
    if (now_action == ACTION_CIRCLE_FADEIN) {
        alpha -= 10;
    }
}
//---------------------------------------------------------------------
void TitleState::setAlpha(int a) { alpha = a; }

//---------------------------------------------------------------------
int TitleState::getNowState() { return now_state; }
int TitleState::getAlpha() { return alpha; }