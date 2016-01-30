#pragma once

class SceneState
{
public:
    static const int SCENE_DEBUG;
    static const int SCENE_TITLE;
private:
    int scene;
public:
    SceneState();
    ~SceneState();

    int getScene();
};