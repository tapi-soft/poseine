//---------------------------------------------------------------------
#include "SceneState.h"

//---------------------------------------------------------------------
const int SceneState::SCENE_DEBUG = 0;
const int SceneState::SCENE_TITLE = 1;
const int SceneState::SCENE_MAIN = 2;
//---------------------------------------------------------------------
SceneState::SceneState()
{
    scene = SCENE_TITLE;
    title_state = new TitleState();
    main_state = new MainState();
}
//---------------------------------------------------------------------
SceneState::~SceneState()
{
    delete(main_state);
    delete(title_state);
}
//---------------------------------------------------------------------
int SceneState::getScene() { return scene; }
TitleState* SceneState::getTitleState() { return title_state; }
MainState* SceneState::getMainState() { return main_state; }