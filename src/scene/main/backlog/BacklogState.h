#pragma once

class BacklogState {
private:
    int scenario_num;   // �V�i���I�ԍ�
    int pos;            // ���ݕ\���ʒu
public:
    BacklogState();
    ~BacklogState();
    void update();

    void setScenarioNum(int);

    int getScenarioNum();
    int getPos();
};