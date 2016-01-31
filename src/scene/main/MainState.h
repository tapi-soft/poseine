#pragma once
#include <string>
#include "scenario/AllScenarioData.h"

class MainState
{
private:
public:
    MainState();
    ~MainState();
    void update();

    std::string getName();
    std::string getText1();
    std::string getText2();
    std::string getText3();
};