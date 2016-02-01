#pragma once
#include "../scenario/AllScenarioData.h"

class BacklogState {
private:
    int scenario_num;   // �V�i���I�ԍ�
    int pos;            // ���ݕ\���ʒu
public:
    BacklogState();
    ~BacklogState();
    void update();

    bool prevLog();
    bool nextLog();

    void setScenarioNum(int);

    int getScenarioNum();
    int getPos();
};