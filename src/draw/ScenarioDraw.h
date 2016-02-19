#pragma once
#include "../GameState.h"
#include "../data/ImageData.h"
#include "../data/SystemData.h"

class ScenarioDraw
{
private:
    ScenarioDraw();
    ~ScenarioDraw();
public:
    static void draw(int, int, int, double);
    static void drawBack(int, int, int, double);
    static void drawChara(int, int, int, double);
};