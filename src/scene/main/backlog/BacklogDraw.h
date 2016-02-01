#pragma once
#include "../../../GameState.h"

class BacklogDraw {
private:
    int image_window;

    void loadImage();
public:
    BacklogDraw(GameState* state);
    ~BacklogDraw();
    void update();
};