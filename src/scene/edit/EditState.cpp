//---------------------------------------------------------------------
#include "EditState.h"

//---------------------------------------------------------------------
EditState::EditState()
{
    scenario_num = 3;
    input_active = 0;

    SetKeyInputStringColor(
        GetColor(0, 0, 0),       // 入力文字列の色
        GetColor(0, 0, 0),       // ＩＭＥ非使用時のカーソルの色
        GetColor(255, 255, 255), // ＩＭＥ使用時の入力文字列の周りの色
        GetColor(255, 255, 255), // ＩＭＥ使用時のカーソルの色
        GetColor(0, 0, 0),       // ＩＭＥ使用時の変換文字列の下線
        GetColor(255, 255, 255), // ＩＭＥ使用時の選択対象の変換候補文字列の色
        GetColor(0, 0, 0),       // ＩＭＥ使用時の入力モード文字列の色(『全角ひらがな』等)
        GetColor(255, 0, 0),     // 入力文字列の縁の色
        GetColor(0, 255, 0),     // ＩＭＥ使用時の選択対象の変換候補文字列の縁の色
        GetColor(255, 0, 0),     // ＩＭＥ使用時の入力モード文字列の縁の色
        GetColor(255, 0, 0),     // ＩＭＥ使用時の変換候補ウインドウの縁の色
        GetColor(255, 0, 0),     // ＩＭＥ使用時の変換候補ウインドウの下地の色
        GetColor(51, 153, 255),  // 入力文字列の選択部分( SHIFTキーを押しながら左右キーで選択 )の周りの色
        GetColor(255, 255, 255), // 入力文字列の選択部分( SHIFTキーを押しながら左右キーで選択 )の色
        GetColor(51, 153, 5)     // 入力文字列の選択部分( SHIFTキーを押しながら左右キーで選択 )の縁の色
        //GetColor(255, 0, 0),   // ＩＭＥ使用時の入力文字列の色
        //GetColor(255, 0, 0));  // ＩＭＥ使用時の入力文字列の縁の色
        );
}
//---------------------------------------------------------------------
EditState::~EditState()
{

}
//---------------------------------------------------------------------
void EditState::update()
{

}
//---------------------------------------------------------------------
void EditState::selectThumbnail(int n)
{
    int num = scenario_num;
    int prev1 = AllScenarioData::getInstance()->getPrev(num);
    int prev2 = AllScenarioData::getInstance()->getPrev(prev1);
    int next1 = AllScenarioData::getInstance()->getNext(num);
    int next2 = AllScenarioData::getInstance()->getNext(next1);
    if (next1 == 0) { next2 = 0; }
    if (prev1 == 0) { prev2 = 0; }
    if (n == 0 && num != 0) { scenario_num = num; }
    if (n == -1 && prev1 != 0) { scenario_num = prev1; }
    if (n == -2 && prev2 != 0) { scenario_num = prev2; }
    if (n == 1 && next1 != 0) { scenario_num = next1; }
    if (n == 2 && next2 != 0) { scenario_num = next2; }
}
//---------------------------------------------------------------------
void EditState::offInputActive(std::string str) {
    if (input_active == 0) return;
    char name[256];
    GetKeyInputString(name, input_handl);
    DeleteKeyInput(input_handl);
    input_active = 0;

    if (str == "name") {
        AllScenarioData::getInstance()->setName(scenario_num, name);
    }
}
//---------------------------------------------------------------------
void EditState::onInputActive(std::string str) {
    input_handl = MakeKeyInput(24, TRUE, FALSE, FALSE);
    input_active = 1;
    if (str == "name") {
        SetKeyInputString(AllScenarioData::getInstance()->getName(scenario_num).c_str(), input_handl);
    }
}
//---------------------------------------------------------------------
int EditState::getScenarioNum() { return scenario_num; }
int EditState::getInputHandl() { return input_handl; }
int EditState::getInputActive() { return input_active; }
