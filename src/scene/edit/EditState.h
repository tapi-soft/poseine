#pragma once

class EditState
{
private:
    int scenario_num;
public:
    EditState();
    ~EditState();
    void update();

    int getScenarioNum();
};