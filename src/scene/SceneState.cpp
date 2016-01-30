//---------------------------------------------------------------------
#include "SceneState.h"

//---------------------------------------------------------------------
const int SceneState::SCENE_DEBUG = 0;
const int SceneState::SCENE_TITLE = 1;
const int SceneState::SCENE_MAIN = 2;
//---------------------------------------------------------------------
SceneState::SceneState()
{
    title_state = new TitleState();
    main_state = new MainState();
    scene = SCENE_TITLE;
    is_fade = false;
}
//---------------------------------------------------------------------
SceneState::~SceneState()
{
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
                scene = next_scene;
            }
        }
        else {
            alpha -= 10;
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
}
//---------------------------------------------------------------------
int SceneState::getScene() { return scene; }
bool SceneState::isFade() { return is_fade; }
TitleState* SceneState::getTitleState() { return title_state; }
MainState* SceneState::getMainState() { return main_state; }
int SceneState::getAlpha() { return alpha; }