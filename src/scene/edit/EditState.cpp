//---------------------------------------------------------------------
#include "EditState.h"

//---------------------------------------------------------------------
EditState::EditState()
{
    scenario_num = 3;
}
//---------------------------------------------------------------------
EditState::~EditState()
{

}
//---------------------------------------------------------------------
void EditState::update()
{

}
//---------------------------------------------------------------------
void EditState::selectThumbnail(int n)
{
    int num = scenario_num;
    int prev1 = AllScenarioData::getInstance()->getPrev(num);
    int prev2 = AllScenarioData::getInstance()->getPrev(prev1);
    int next1 = AllScenarioData::getInstance()->getNext(num);
    int next2 = AllScenarioData::getInstance()->getNext(next1);
    if (n == 0 && num != 0) { scenario_num = num; }
    if (n == -1 && prev1 != 0) { scenario_num = prev1; }
    if (n == -2 && prev2 != 0) { scenario_num = prev2; }
    if (n == 1 && next1 != 0) { scenario_num = next1; }
    if (n == 2 && next2 != 0) { scenario_num = next2; }
}
//---------------------------------------------------------------------
int EditState::getScenarioNum() { return scenario_num; }