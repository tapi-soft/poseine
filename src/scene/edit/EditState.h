#pragma once
#include "../../data/scenario/AllScenarioData.h"

class EditState
{
private:
    int scenario_num;
public:
    EditState();
    ~EditState();
    void update();
    void selectThumbnail(int);

    int getScenarioNum();
};