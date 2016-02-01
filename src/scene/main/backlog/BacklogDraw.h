#pragma once
#include "../../../GameState.h"
#include "../scenario/AllScenarioData.h"
#include "BacklogData.h"

class BacklogDraw {
private:
    BacklogState* backlog_state;
    InputState* input_state;
    int image_window;
    int image_button_back[2];
    int font;
    int color_white;

    void loadImage();
public:
    BacklogDraw(GameState* state);
    ~BacklogDraw();
    void update();
};