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
    TitleState* title_state;
    MainState* main_state;
public:
    SceneState();
    ~SceneState();
    int getScene();
    TitleState* getTitleState();
    MainState* getMainState();
};