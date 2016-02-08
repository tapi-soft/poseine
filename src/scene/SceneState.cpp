//---------------------------------------------------------------------
#include "SceneState.h"

//---------------------------------------------------------------------
const int SceneState::SCENE_DEBUG = 0;
const int SceneState::SCENE_TITLE = 1;
const int SceneState::SCENE_MAIN = 2;
const int SceneState::SCENE_SAVE = 3;
const int SceneState::SCENE_LOAD = 4;
const int SceneState::SCENE_SETTING = 5;

//---------------------------------------------------------------------
SceneState::SceneState()
{
    title_state = new TitleState();
    main_state = new MainState();
    saveload_state = new SaveloadState();
    setting_state = new SettingState();

    scene = SCENE_TITLE;
    saveload_state->setMode(SaveloadState::MODE_LOAD);
    prev_scene = scene;
    next_scene = scene;
    is_fade = false;
}
//---------------------------------------------------------------------
SceneState::~SceneState()
{
    delete(setting_state);
    delete(saveload_state);
    delete(main_state);
    delete(title_state);
}
//---------------------------------------------------------------------
void SceneState::update()
{
    if (is_fade) {
        if (is_fadeout) {
            alpha += 10;
            if (alpha >= 255) {
                alpha = 255;
                is_fadeout = false;
                prev_scene = scene;
                scene = next_scene;
            }
        }
        else {
            alpha -= 20;
            if (alpha <= 0) {
                alpha = 0;
                is_fade = false;
            }
        }
    }
}
//---------------------------------------------------------------------
void SceneState::changeScene(int scene)
{
    next_scene = scene;
    is_fade = true;
    alpha = 0;
    is_fadeout = true;
    if (scene == SCENE_SAVE) { saveload_state->setMode(SaveloadState::MODE_SAVE); }
    if (scene == SCENE_LOAD) { saveload_state->setMode(SaveloadState::MODE_LOAD); }
}
//---------------------------------------------------------------------
void SceneState::backScene()
{
    changeScene(prev_scene);
}
//---------------------------------------------------------------------
int SceneState::getScene() { return scene; }
bool SceneState::isFade() { return is_fade; }
TitleState* SceneState::getTitleState() { return title_state; }
MainState* SceneState::getMainState() { return main_state; }
SaveloadState* SceneState::getSaveloadState() { return saveload_state; }
SettingState* SceneState::getSettingState() { return setting_state; }
int SceneState::getAlpha() { return alpha; }