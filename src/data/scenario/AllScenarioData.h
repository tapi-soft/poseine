#pragma once
#include "DxLib.h"
#include <iostream>
#include <string>
#include <sstream>
#include "ScenarioData.h"

class AllScenarioData
{
public:
private:
    static ScenarioData* scenario_data[10000];
    AllScenarioData();
    ~AllScenarioData();
public:
    void loadData();
    void saveData();
    int searchEmptyPos();
    void deleteData(int);

    static AllScenarioData* getInstance();
    std::string getName(int);
    std::string getText(int);
    std::string getText1(int);
    std::string getText2(int);
    std::string getText3(int);
    int getText1Length(int);
    int getText2Length(int);
    int getText3Length(int);
    int getNext(int);
    int getPrev(int);
    int getBackimage(int);
    int getCharaNum(int);
    int getCharaImage(int, int);
    int getCharaPos(int, int);
    int getCharaFace(int, int);
    int getSelectNum(int);
    int getSelectNext(int, int);
    std::string getSelectText(int, int);

    void setNext(int, int);
    void setPrev(int, int);
    void setName(int, std::string);
    void setText1(int, std::string);
    void setText2(int, std::string);
    void setText3(int, std::string);
    void setBackimage(int, int);
    void setCharaNum(int, int);
    void setCharaImage(int, int, int);
    void setCharaPos(int, int, int);
    void setCharaFace(int, int, int);

    int getBackimageMax();
    int getCharaImageMax();
    int getCharaPosMax();
    int getCharaFaceMax();
};