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
    loadData();
}
//---------------------------------------------------------------------
AllScenarioData::~AllScenarioData()
{

}
//---------------------------------------------------------------------
void AllScenarioData::loadData()
{
    puts("シナリオデータをロードします");
    char str[1024];
    std::string s;
    std::stringstream ss;
    int num;
    int fp = FileRead_open("scenario/scenario_1.dat");
    // ファイル読み込み失敗
    if (fp == 0) {
        puts("シナリオデータの読み込みに失敗しました");
        return;
    }
    // ファイル読み込み処理
    while (FileRead_gets(str, 256, fp) != -1) {
        ss.clear();
        ss.str(str);
        ss >> s;
        //---- 番号
        if (s == "#NUM") {
            ss >> s;
            num = atoi(s.c_str());
            scenario_data[num]->setNum(num);
        }
        //---- 名前
        else if (s == "#NAME") {
            ss >> s;
            scenario_data[num]->setName(s);
        }
        //---- テキスト1
        else if (s == "#TEXT1") {
            ss >> s;
            scenario_data[num]->setText1(s);
        }
        //---- テキスト2
        else if (s == "#TEXT2") {
            ss >> s;
            scenario_data[num]->setText2(s);
        }
        //---- テキスト3
        else if (s == "#TEXT3") {
            ss >> s;
            scenario_data[num]->setText3(s);
        }
        //---- 次
        else if (s == "#NEXT") {
            ss >> s;
            scenario_data[num]->setNext(atoi(s.c_str()));
        }
        //---- キャラ
        else if (s == "#CHARA") {
            // キャラ数
            int n = scenario_data[num]->getCharaNum() + 1;
            scenario_data[num]->setCharaNum(n);
            // キャラ位置
            ss >> s;
            scenario_data[num]->setCharaPos(n, atoi(s.c_str()));
            // キャラ画像
            ss >> s;
            scenario_data[num]->setCharaImage(n, atoi(s.c_str()));
            // キャラ顔
            ss >> s;
            scenario_data[num]->setCharaFace(n, atoi(s.c_str()));
        }
        //---- 背景
        else if (s == "#BACK") {
            ss >> s;
            scenario_data[num]->setBackimage(atoi(s.c_str()));
        }
        //---- フェードの種類
        else if (s == "#FADE") {
            ss >> s;
            scenario_data[num]->setFade(atoi(s.c_str()));
        }
    }
    FileRead_close(fp);
    puts("シナリオデータの読み込みに成功しました");
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
std::string AllScenarioData::getText(int n)
{
    return getText1(n) + getText2(n) + getText3(n);
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
//---------------------------------------------------------------------
int AllScenarioData::getText1Length(int n)
{
    return scenario_data[n]->getText1().length();
}
//---------------------------------------------------------------------
int AllScenarioData::getText2Length(int n)
{
    return scenario_data[n]->getText2().length();
}
//---------------------------------------------------------------------
int AllScenarioData::getText3Length(int n)
{
    return scenario_data[n]->getText3().length();
}