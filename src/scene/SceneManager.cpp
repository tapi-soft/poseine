//---------------------------------------------------------------------
#include "SceneManager.h"

//---------------------------------------------------------------------
SceneManager::SceneManager(GameState* state)
{
    scene_state = state->getSceneState();
}
//---------------------------------------------------------------------
SceneManager::~SceneManager()
{

}
//---------------------------------------------------------------------
void SceneManager::update()
{
    switch (scene_state->getScene())
    {
    case SceneState::SCENE_DEBUG: break;
    case SceneState::SCENE_TITLE: break;
    default:
        break;
    }
}