#pragma once
#include "DxLib.h"

class FpsManager {
public:
    static const int FPS = 60;
private:
    static const int N = 60;
    int start_time;
    int counter;
    double fps;

public:
    FpsManager();
    ~FpsManager();
    void init();
    void update();
    void wait();
};