#pragma once
#include <string>
#include "scenario/AllScenarioData.h"
#include "MainData.h"
#include "backlog/BacklogState.h"

class MainState
{
public:
    static const int STATE_NORMAL;
    static const int STATE_LOG;

private:
    BacklogState* backlog_state;
    int scenario_num;
    int pre_scenario_num;
    int disp_length;
    bool is_text_disp;
    int elapsed_end_flame;   // テキスト表示終わってからの経過フレーム数
    int now_mode;
    int chara_alpha;
    int now_state;           // 現在の状態
    bool is_disp_window;     // ウインドウ表示しているか

public:
    MainState();
    ~MainState();
    void update();
    void updateNormal();
    int isJapaneseCharacter(unsigned char);
    void fullTextOpen();
    void nextScenario();
    void settingScenario(int);

    int getScenarioNum();
    std::string getName();
    std::string getText();
    std::string getText1();
    std::string getText2();
    std::string getText3();
    int getBackimage();
    int getCharaNum();
    int getCharaImage(int);
    int getCharaPos(int);
    int getCharaFace(int);
    int getPreCharaNum();
    int getPreCharaImage(int);
    int getPreCharaPos(int);
    int getPreCharaFace(int);
    int getSelectNum();
    int getSelectNext(int);
    std::string getSelectText(int);

    int getButtonState(int, int, int);
    int getNowMode();
    int getCharaAlpha();

    void changeMode(int);
    bool isTextDisp();
    bool isPreCharaEqual(int, int);  // 前に同じ画像があるか
    bool isNextCharaEqual(int, int); // 次に同じ画像があるか
    void changeState(int);
    int getNowState();
    BacklogState* getBacklogState();
    bool isDispWindow();
};