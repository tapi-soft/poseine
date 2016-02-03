#pragma once
#include "title/TitleState.h"
#include "main/MainState.h"
#include "saveload/SaveloadState.h"

class SceneState
{
public:
    static const int SCENE_DEBUG;
    static const int SCENE_TITLE;
    static const int SCENE_MAIN;
    static const int SCENE_SAVE;
    static const int SCENE_LOAD;
private:
    int scene;
    int next_scene;
    int prev_scene;
    bool is_fade;
    bool is_fadeout;
    int alpha;
    TitleState* title_state;
    MainState* main_state;
    SaveloadState* saveload_state;
public:
    SceneState();
    ~SceneState();
    void update();
    void changeScene(int);
    void backScene();
    int getScene();
    bool isFade();

    TitleState* getTitleState();
    MainState* getMainState();
    SaveloadState* getSaveloadState();
    int getAlpha();
};