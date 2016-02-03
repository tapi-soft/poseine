//---------------------------------------------------------------------
#include "SaveData.h"

//---------------------------------------------------------------------
SaveData::SaveData()
{

}
//---------------------------------------------------------------------
SaveData::~SaveData()
{

}
//---------------------------------------------------------------------
SaveData* SaveData::getInstance()
{
    static SaveData instance;
    return &instance;
}
//---------------------------------------------------------------------
void SaveData::setIsData(int n, bool flag) { is_data[n] = flag; }
void SaveData::setScenarioPos(int n, int pos) { scenario_pos[n] = pos; }
void SaveData::setSaveDay(int n, std::string day) { save_day[n] = day; }
void SaveData::setSaveTime(int n, std::string time) { save_time[n] = time; }
//---------------------------------------------------------------------
bool SaveData::isData(int n) { return is_data[n]; }
int SaveData::getScenarioPos(int n) { return scenario_pos[n]; }
std::string SaveData::getSaveDay(int n) { return save_day[n]; }
std::string SaveData::getSaveTime(int n) { return save_time[n]; }
