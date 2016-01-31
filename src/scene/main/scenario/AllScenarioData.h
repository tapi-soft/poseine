#pragma once
#include <string>
#include "ScenarioData.h"

class AllScenarioData
{
public:
private:
    static ScenarioData* scenario_data[10000];
    AllScenarioData();
    ~AllScenarioData();
public:
    static AllScenarioData* getInstance();
    std::string getName(int);
    std::string getText1(int);
    std::string getText2(int);
    std::string getText3(int);
};