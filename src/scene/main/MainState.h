#pragma once
#include <string>
#include "scenario/AllScenarioData.h"

class MainState
{
private:
    int scenario_num;
    int disp_length;
    bool is_text_disp;
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

    bool isTextDisp();
};