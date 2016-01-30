#pragma once

class TitleState
{
public:
    static const int STATE_CIRCLE;
    static const int STATE_TITLE;
    static const int ACTION_CIRCLE_FADEIN;
    static const int ACTION_CIRCLE_DISP;
    static const int ACTION_CIRCLE_FADEOUT;
private:
    int now_state;
    int now_action;
    int alpha;
public:
    TitleState();
    ~TitleState();
    void update();
    void setAlpha(int);
    int getNowState();
    int getAlpha();
};