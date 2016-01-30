#pragma once

class SceneState
{
public:
    static const int SCENE_DEBUG = 0;
    static const int SCENE_TITLE = 1;
private:
    int scene;
public:
    SceneState();
    ~SceneState();

    int getScene();
};