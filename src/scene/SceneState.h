#pragma once
#include "title/TitleState.h"

class SceneState
{
public:
    static const int SCENE_DEBUG;
    static const int SCENE_TITLE;

private:
    int scene;
    TitleState* title_state;

public:
    SceneState();
    ~SceneState();

    int getScene();
};