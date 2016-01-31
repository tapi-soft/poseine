#pragma once
#include <string>
#include "scenario/AllScenarioData.h"
#include "MainData.h"

class MainState
{
private:
    int scenario_num;
    int pre_scenario_num;
    int disp_length;
    bool is_text_disp;
    int elapsed_end_flame;   // �e�L�X�g�\���I����Ă���̌o�߃t���[����
    int now_mode;
    int chara_alpha;
public:
    MainState();
    ~MainState();
    void update();
    int isJapaneseCharacter(unsigned char);
    void fullTextOpen();
    void nextScenario();

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

    int getButtonState(int, int, int);
    int getNowMode();
    int getCharaAlpha();

    void changeMode(int);
    bool isTextDisp();
    bool isPreCharaEqual(int, int);  // �O�ɓ����摜�����邩
    bool isNextCharaEqual(int, int); // ���ɓ����摜�����邩
};