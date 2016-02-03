//---------------------------------------------------------------------
#include "SaveData.h"

//---------------------------------------------------------------------
SaveData::SaveData()
{
    for (int n = 0; n < SAVEDATA_MAX; n++) {
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
    FileRead_close(fp);
    puts("Success loading savedata file");
}
//---------------------------------------------------------------------
void SaveData::save(int num, int scenario_pos)
{
    //---- 
    is_data[num] = true;

    //---- 
    this->scenario_pos[num] = scenario_pos;

    //---- 
    char c[256];
    DATEDATA date;
    GetDateTime(&date);
    std::stringstream ds;
    sprintf_s(c, "%02d", date.Year);
    ds << c << "/";
    sprintf_s(c, "%02d", date.Mon);
    ds << c << "/";
    sprintf_s(c, "%02d", date.Day);
    ds << c;
    save_day[num] = ds.str();

    //---- 
    ds.str("");
    sprintf_s(c, "%02d", date.Hour);
    ds << c << ":";
    sprintf_s(c, "%02d", date.Min);
    ds << c;
    save_time[num] = ds.str();

    //----
    FILE *fp;
    errno_t error = fopen_s(&fp, "savedata/savedata.dat", "wb");

    if (fp == NULL){ // NULL‚ª•Ô‚Á‚Ä‚«‚½‚çƒGƒ‰[”­¶
        puts("Fail data save");
        return;
    }
    for (int n = 0; n < SAVEDATA_MAX; n++) {
        if (is_data[n]) {
            fprintf(fp, "%d %d %s %s\r\n", n, this->scenario_pos[n], save_day[n].c_str(), save_time[n].c_str());
        }
    }
    fclose(fp);
    puts("Success data save");
}
//---------------------------------------------------------------------
SaveData* SaveData::getInstance()
{
    static SaveData instance;
    return &instance;
}
//---------------------------------------------------------------------
bool SaveData::isData(int n) { return is_data[n]; }
int SaveData::getScenarioPos(int n) { return scenario_pos[n]; }
std::string SaveData::getSaveDay(int n) { return save_day[n]; }
std::string SaveData::getSaveTime(int n) { return save_time[n]; }
