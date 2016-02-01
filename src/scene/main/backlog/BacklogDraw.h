#pragma once
#include "../../../GameState.h"
#include "../scenario/AllScenarioData.h"

class BacklogDraw {
private:
    BacklogState* backlog_state;
    int image_window;
    int font;
    int color_white;

    void loadImage();
public:
    BacklogDraw(GameState* state);
    ~BacklogDraw();
    void update();
};