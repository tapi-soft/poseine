//---------------------------------------------------------------------
#include "MainState.h"

//---------------------------------------------------------------------
MainState::MainState()
{
    scenario_num = 1;
    pre_scenario_num = 1;
    disp_length = 0;
    is_text_disp = true;
    now_mode = MainData::MODE_NORMAL;
    elapsed_end_flame = 0;
    chara_alpha = 0;
}
//---------------------------------------------------------------------
MainState::~MainState()
{

}
//---------------------------------------------------------------------
void MainState::update()
{
    if (is_text_disp) {
        chara_alpha += 15;
        if (chara_alpha >= 255) { chara_alpha = 255; }
        if (chara_alpha >= 255) {
            disp_length += isJapaneseCharacter(getText()[disp_length]);
            if (disp_length >= (int)getText().length()) {
                fullTextOpen();
            }
        }
    }
    else {
        elapsed_end_flame++;
    }
    // auto mode
    if (now_mode == MainData::MODE_AUTO) {
        if (elapsed_end_flame >= 100) {
            nextScenario();
        }
    }
    // skip mode
    if (now_mode == MainData::MODE_SKIP) {
        fullTextOpen();
        if (elapsed_end_flame >= 5) {
            nextScenario();
        }
    }
}
//---------------------------------------------------------------------
int MainState::isJapaneseCharacter(unsigned char code)
{
    if ((code >= 0x81 && code <= 0x9F) ||
        (code >= 0xE0 && code <= 0xFC)) {
        return 2;
    }
    return 1;
}
//---------------------------------------------------------------------
void MainState::fullTextOpen()
{
    is_text_disp = false;
    disp_length = getText().length();
}
//---------------------------------------------------------------------
void MainState::nextScenario()
{
    pre_scenario_num = scenario_num;
    scenario_num = AllScenarioData::getInstance()->getNext(scenario_num);
    is_text_disp = true;
    disp_length = 0;
    elapsed_end_flame = 0;
    chara_alpha = 0;
}
//---------------------------------------------------------------------
std::string MainState::getName()
{
    if (chara_alpha >= 255) {
        return AllScenarioData::getInstance()->getName(scenario_num);
    }
    return "";
}
//---------------------------------------------------------------------
std::string MainState::getText()
{
    return AllScenarioData::getInstance()->getText(scenario_num);
}
//---------------------------------------------------------------------
std::string MainState::getText1()
{
    int length1 = AllScenarioData::getInstance()->getText1Length(scenario_num);

    if (disp_length >= length1) {
        return AllScenarioData::getInstance()->getText1(scenario_num);
    }
    return AllScenarioData::getInstance()->getText1(scenario_num).substr(0, disp_length);
}
//---------------------------------------------------------------------
std::string MainState::getText2()
{
    int length1 = AllScenarioData::getInstance()->getText1Length(scenario_num);
    int length2 = AllScenarioData::getInstance()->getText2Length(scenario_num);

    if (disp_length >= length1 + length2) {
        return AllScenarioData::getInstance()->getText2(scenario_num);
    }
    if (disp_length <= length1) {
        return "";
    }
    return AllScenarioData::getInstance()->getText2(scenario_num).substr(0, disp_length - length1);
}
//---------------------------------------------------------------------
std::string MainState::getText3()
{
    int length1 = AllScenarioData::getInstance()->getText1Length(scenario_num);
    int length2 = AllScenarioData::getInstance()->getText2Length(scenario_num);
    int length3 = AllScenarioData::getInstance()->getText3Length(scenario_num);

    if (disp_length >= length1 + length2 + length3) {
        return AllScenarioData::getInstance()->getText3(scenario_num);
    }
    else if (disp_length <= length1 + length2) {
        return "";
    }
    return AllScenarioData::getInstance()->getText3(scenario_num).substr(0, disp_length - length1 - length2);
}
//---------------------------------------------------------------------
int MainState::getBackimage()
{
    return AllScenarioData::getInstance()->getBackimage(scenario_num);
}
//---------------------------------------------------------------------
int MainState::getCharaNum()
{
    return AllScenarioData::getInstance()->getCharaNum(scenario_num);
}
//---------------------------------------------------------------------
int MainState::getCharaImage(int n)
{
    return AllScenarioData::getInstance()->getCharaImage(scenario_num, n);
}
//---------------------------------------------------------------------
int MainState::getCharaPos(int n)
{
    return AllScenarioData::getInstance()->getCharaPos(scenario_num, n);
}
//---------------------------------------------------------------------
int MainState::getCharaFace(int n)
{
    return AllScenarioData::getInstance()->getCharaFace(scenario_num, n);
}
//---------------------------------------------------------------------
int MainState::getPreCharaNum()
{
    return AllScenarioData::getInstance()->getCharaNum(pre_scenario_num);
}
//---------------------------------------------------------------------
int MainState::getPreCharaImage(int n)
{
    return AllScenarioData::getInstance()->getCharaImage(pre_scenario_num, n);
}
//---------------------------------------------------------------------
int MainState::getPreCharaPos(int n)
{
    return AllScenarioData::getInstance()->getCharaPos(pre_scenario_num, n);
}
//---------------------------------------------------------------------
int MainState::getPreCharaFace(int n)
{
    return AllScenarioData::getInstance()->getCharaFace(pre_scenario_num, n);
}
//---------------------------------------------------------------------
bool MainState::isTextDisp()
{
    return is_text_disp;
}
//---------------------------------------------------------------------
void MainState::changeMode(int mode)
{
    now_mode = mode;
}
//---------------------------------------------------------------------
int MainState::getButtonState(int n, int x, int y)
{
    if (now_mode == MainData::MODE_NORMAL) {
        if (MainData::isButtonPos(n, x, y)) { return 1; }
        return 0;
    }
    if (now_mode == MainData::MODE_AUTO) {
        if (n == MainData::BUTTON_AUTO) { return 1; }
        if (n == MainData::BUTTON_SKIP) { return 2; }
        if (n == MainData::BUTTON_LOG)  { return 2; }
        if (n == MainData::BUTTON_CONF) { return 2; }
        if (n == MainData::BUTTON_SAVE) { return 2; }
        if (n == MainData::BUTTON_LOAD) { return 2; }
    }
    if (now_mode == MainData::MODE_SKIP) {
        if (n == MainData::BUTTON_AUTO) { return 2; }
        if (n == MainData::BUTTON_SKIP) { return 1; }
        if (n == MainData::BUTTON_LOG)  { return 2; }
        if (n == MainData::BUTTON_CONF) { return 2; }
        if (n == MainData::BUTTON_SAVE) { return 2; }
        if (n == MainData::BUTTON_LOAD) { return 2; }
    }
    return 0;
}
//---------------------------------------------------------------------
int MainState::getNowMode()
{
    return now_mode;
}
//---------------------------------------------------------------------
int MainState::getCharaAlpha()
{
    return chara_alpha;
}
//---------------------------------------------------------------------
bool MainState::isPreCharaEqual(int chara_pos, int chara_image)
{
    for (int i = 1; i <= getPreCharaNum(); i++) {
        if (chara_pos == getPreCharaPos(i) && chara_image == getPreCharaImage(i)) { return true; }
    }
    return false;
}
//---------------------------------------------------------------------
bool MainState::isNextCharaEqual(int chara_pos, int chara_image)
{
    for (int i = 1; i <= getCharaNum(); i++) {
        if (chara_pos == getCharaPos(i) && chara_image == getCharaImage(i)) { return true; }
    }
    return false;
}