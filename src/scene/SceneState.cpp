//---------------------------------------------------------------------
#include "SceneState.h"

//---------------------------------------------------------------------
SceneState::SceneState()
{
    scene = SCENE_TITLE;
}
//---------------------------------------------------------------------
SceneState::~SceneState()
{

}
//---------------------------------------------------------------------
int SceneState::getScene() { return scene; }