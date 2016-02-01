#pragma once

class BacklogState {
private:
    int scenario_num;   // シナリオ番号
    int pos;            // 現在表示位置
public:
    BacklogState();
    ~BacklogState();
    void update();

    void setScenarioNum(int);

    int getScenarioNum();
    int getPos();
};