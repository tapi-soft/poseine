#pragma once
#include "DxLib.h"
#include <fstream>
#include <iostream>
#include <sstream>

class SaveData
{
private:
    bool is_data[1000];
    int scenario_pos[1000];
    std::string save_day[1000];
    std::string save_time[1000];

    SaveData();
    ~SaveData();
public:
    SaveData* getInstance();

    void setIsData(int, bool);
    void setScenarioPos(int, int);
    void setSaveDay(int, std::string);
    void setSaveTime(int, std::string);

    bool isData(int);
    int getScenarioPos(int);
    std::string getSaveDay(int);
    std::string getSaveTime(int);
};