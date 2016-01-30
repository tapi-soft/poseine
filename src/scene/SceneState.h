#pragma once
#include "title/TitleState.h"
#include "main/MainState.h"

class SceneState
{
public:
    static const int SCENE_DEBUG;
    static const int SCENE_TITLE;
    static const int SCENE_MAIN;
private:
    int scene;
    int next_scene;
    bool is_fade;
    bool is_fadeout;
    int alpha;
    TitleState* title_state;
    MainState* main_state;
public:
    SceneState();
    ~SceneState();
    void update();
    void changeScene(int);
    int getScene();
    bool isFade();

    TitleState* getTitleState();
    MainState* getMainState();
    int getAlpha();
};