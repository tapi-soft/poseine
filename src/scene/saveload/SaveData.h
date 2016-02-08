#pragma once
#include "DxLib.h"
#include <fstream>
#include <iostream>
#include <sstream>

class SaveData
{
public:
    static const int SAVEDATA_MAX = 1000;
private:
    bool is_data[SAVEDATA_MAX];
    int scenario_pos[SAVEDATA_MAX];
    std::string save_day[SAVEDATA_MAX];
    std::string save_time[SAVEDATA_MAX];

    SaveData();
    ~SaveData();
public:
    static SaveData* getInstance();

    void load();
    void save();
    void save(int, int);
    void deleteData(int);

    bool isData(int);
    int getScenarioPos(int);
    std::string getSaveDay(int);
    std::string getSaveTime(int);
};