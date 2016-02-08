#pragma once
#include "../../GameState.h"

class SettingDraw
{
private:
    int image_back;

    void loadImage();
public:
    SettingDraw(GameState*);
    ~SettingDraw();
    void update();
};