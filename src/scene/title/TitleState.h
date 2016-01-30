#pragma once

class TitleState
{
public:
    static const int STATE_CIRCLE;
    static const int STATE_TITLE;
    static const int ACTION_CIRCLE_FADEIN;
    static const int ACTION_CIRCLE_DISP;
    static const int ACTION_CIRCLE_FADEOUT;
    static const int ACTION_TITLE_FADEIN;
    static const int ACTION_TITLE_DISP;
private:
    int now_state;
    int now_action;
    int alpha;
    int elapsed_action_frame;

    void changeAction(int);
public:
    TitleState();
    ~TitleState();
    void update();
    void setAlpha(int);
    int getNowState();
    int getAlpha();
};