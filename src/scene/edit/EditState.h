#pragma once
#include "../../data/scenario/AllScenarioData.h"

class EditState
{
private:
    int scenario_num;
    int input_handl;
    int input_active;
    int input_pos_x;
    int input_pos_y;
    std::string input_str;
    int select_chara;

public:
    EditState();
    ~EditState();
    void update();
    void selectThumbnail(int);
    void offInputActive();
    void onInputActive(std::string);

    int getScenarioNum();
    int getInputHandl();
    int getInputActive();
    std::string getInputStr();
    int getSelectChara();
};