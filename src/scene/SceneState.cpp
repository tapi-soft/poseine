//---------------------------------------------------------------------
#include "SceneState.h"

//---------------------------------------------------------------------
const int SceneState::SCENE_DEBUG = 0;
const int SceneState::SCENE_TITLE = 1;

//---------------------------------------------------------------------
SceneState::SceneState()
{
    scene = SCENE_TITLE;
    title_state = new TitleState();
}
//---------------------------------------------------------------------
SceneState::~SceneState()
{
    delete(title_state);
}
//---------------------------------------------------------------------
int SceneState::getScene() { return scene; }