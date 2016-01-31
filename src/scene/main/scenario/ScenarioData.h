#pragma once
#include <string>

class ScenarioData
{
private:
    std::string name;
    std::string text1;
    std::string text2;
    std::string text3;
public:
    ScenarioData();
    ~ScenarioData();

    std::string getName();
    std::string getText1();
    std::string getText2();
    std::string getText3();
};