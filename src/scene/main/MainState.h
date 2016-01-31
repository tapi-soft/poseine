#pragma once
#include <string>
#include "scenario/AllScenarioData.h"
#include "MainData.h"

class MainState
{
private:
    int scenario_num;
    int disp_length;
    bool is_text_disp;
    int elapsed_end_flame;   // テキスト表示終わってからの経過フレーム数
    int now_mode;
public:
    MainState();
    ~MainState();
    void update();
    int isJapaneseCharacter(unsigned char);
    void fullTextOpen();
    void nextScenario();

    std::string getName();
    std::string getText();
    std::string getText1();
    std::string getText2();
    std::string getText3();
    int getBackimage();
    int getCharaNum();
    int getCharaImage(int);
    int getCharaPos(int);
    int getCharaFace(int);

    int getButtonState(int, int, int);
    int getNowMode();

    void changeMode(int);
    bool isTextDisp();
};