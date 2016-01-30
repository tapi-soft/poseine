#pragma once
#include "../../GameState.h"
#include "../SceneState.h"
#include "TitleData.h"

class TitleManager
{
private:
    GameState* game_state;
    TitleState* title_state;
    InputState* input_state;

    void clickTitle();
    void clickCircle();
    void clickTitleBegin();
    void clickTitleContinue();
    void clickTitleSetting();
    void clickTitleSpecial();
    void clickTitleOfficial();
    void clickTitleEnd();
public:
    TitleManager(GameState*);
    ~TitleManager();
    void update();
};