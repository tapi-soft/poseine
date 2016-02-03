//---------------------------------------------------------------------
#include "SaveData.h"

//---------------------------------------------------------------------
SaveData::SaveData()
{
    for (int n = 0; n < 1000; n++) {
        is_data[n] = false;
        scenario_pos[n] = 0;
        save_day[n] = "----/--/--";
        save_time[n] = "--:--";
    }
    load();
}
//---------------------------------------------------------------------
SaveData::~SaveData()
{

}
//---------------------------------------------------------------------
void SaveData::load()
{
    char str[1024];
    std::string s;
    std::stringstream ss;
    int num;

    int fp = FileRead_open("savedata/savedata.dat");
    if (fp == 0) {
        puts("Fail loading savedata file");
        return;
    }
    while (FileRead_gets(str, 256, fp) != -1) {
        ss.clear();
        ss.str(str);
        //---- 
        ss >> s;
        num = atoi(s.c_str());
        is_data[num] = 1;
        //---- 
        ss >> s;
        scenario_pos[num] = atoi(s.c_str());
        //---- 
        ss >> s;
        save_day[num] = s;
        ss >> s;
        save_time[num] = s;
    }
    puts("Success loading savedata file");
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
