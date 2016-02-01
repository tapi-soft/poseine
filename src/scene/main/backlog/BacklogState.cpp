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
int BacklogState::getScenarioNum() { return scenario_num; }
int BacklogState::getPos() { return pos; }