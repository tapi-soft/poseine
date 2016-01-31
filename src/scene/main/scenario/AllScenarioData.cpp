//---------------------------------------------------------------------
#include "AllScenarioData.h"

//---------------------------------------------------------------------
ScenarioData* AllScenarioData::scenario_data[10000];

//---------------------------------------------------------------------
AllScenarioData::AllScenarioData()
{
    for (int i = 0; i < 10000; i++) {
        scenario_data[i] = new ScenarioData();
    }
}
//---------------------------------------------------------------------
AllScenarioData::~AllScenarioData()
{

}
//---------------------------------------------------------------------
AllScenarioData* AllScenarioData::getInstance()
{
    static AllScenarioData instance;
    return &instance;
}
//---------------------------------------------------------------------
std::string AllScenarioData::getName(int n)
{
    return scenario_data[n]->getName();
}
//---------------------------------------------------------------------
std::string AllScenarioData::getText1(int n)
{
    return scenario_data[n]->getText1();
}
//---------------------------------------------------------------------
std::string AllScenarioData::getText2(int n)
{
    return scenario_data[n]->getText2();
}
//---------------------------------------------------------------------
std::string AllScenarioData::getText3(int n)
{
    return scenario_data[n]->getText3();
}