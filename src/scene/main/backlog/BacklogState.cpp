#include "BacklogState.h"

//---------------------------------------------------------------------
BacklogState::BacklogState()
{
    scenario_num = 0;
    pos = 0;
}
//---------------------------------------------------------------------
BacklogState::~BacklogState()
{

}
//---------------------------------------------------------------------
void BacklogState::update()
{

}
//---------------------------------------------------------------------
void BacklogState::setScenarioNum(int num)
{
    scenario_num = num;
    pos = num;
}
//---------------------------------------------------------------------
bool BacklogState::prevLog()
{
    int num = AllScenarioData::getInstance()->getPrev(pos);
    int pre1 = AllScenarioData::getInstance()->getPrev(num);
    int pre2 = AllScenarioData::getInstance()->getPrev(pre1);
    if (pre2 == 0) { return true; }
    pos = num;
    return false;
}
//---------------------------------------------------------------------
bool BacklogState::nextLog()
{
    int num = AllScenarioData::getInstance()->getNext(pos);
    if (pos == scenario_num) { return true; }
    pos = num;
    return false;
}
//---------------------------------------------------------------------
int BacklogState::getScenarioNum() { return scenario_num; }
int BacklogState::getPos() { return pos; }