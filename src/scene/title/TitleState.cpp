//---------------------------------------------------------------------
#include "TitleState.h"

//---------------------------------------------------------------------
const int TitleState::STATE_CIRCLE = 0;
const int TitleState::STATE_TITLE = 1;
const int TitleState::ACTION_CIRCLE_FADEIN = 0;
const int TitleState::ACTION_CIRCLE_DISP = 1;
const int TitleState::ACTION_CIRCLE_FADEOUT = 2;
const int TitleState::ACTION_TITLE_FADEIN = 3;
const int TitleState::ACTION_TITLE_DISP = 4;

//---------------------------------------------------------------------
TitleState::TitleState()
{
    now_state = STATE_CIRCLE;
    now_action = ACTION_CIRCLE_FADEIN;
    alpha = 255;
    elapsed_action_frame = 0;
}
//---------------------------------------------------------------------
TitleState::~TitleState()
{

}
//---------------------------------------------------------------------
void TitleState::update()
{
    //---- 
    elapsed_action_frame++;

    //---- ACTION_CIRCLE_FADEIN
    if (now_action == TitleState::ACTION_CIRCLE_FADEIN) {
        alpha -= 10;
        if (alpha <= 0) {
            alpha = 0;
            changeAction(TitleState::ACTION_CIRCLE_DISP);
        }
    }
    //---- ACTION_CIRCLE_DISP
    else if (now_action == TitleState::ACTION_CIRCLE_DISP) {
        if (elapsed_action_frame >= 100) {
            changeAction(TitleState::ACTION_CIRCLE_FADEOUT);
        }
    }
    //---- ACTION_CIRCLE_FADEOUT
    else if (now_action == TitleState::ACTION_CIRCLE_FADEOUT) {
        alpha += 10;
        if (alpha >= 255) {
            alpha = 255;
            changeAction(TitleState::ACTION_TITLE_FADEIN);
        }
    }
    //---- ACTION_TITLE_FADEIN
    else if (now_action == TitleState::ACTION_TITLE_FADEIN) {
        alpha -= 10;
        if (alpha <= 0) {
            alpha = 0;
            changeAction(TitleState::ACTION_TITLE_DISP);
        }
    }
    //---- ACTION_TITLE_DISP
    else if (now_action == TitleState::ACTION_TITLE_DISP) {

    }
}
//---------------------------------------------------------------------
void TitleState::changeAction(int action)
{
    now_action = action;
    elapsed_action_frame = 0;
    if (now_action == ACTION_TITLE_FADEIN) {
        now_state = STATE_TITLE;
    }
}
//---------------------------------------------------------------------
void TitleState::setAlpha(int a) { alpha = a; }

//---------------------------------------------------------------------
int TitleState::getNowState() { return now_state; }
int TitleState::getAlpha() { return alpha; }