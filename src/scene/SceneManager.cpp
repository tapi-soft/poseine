//---------------------------------------------------------------------
#include "SceneManager.h"
#include "SceneState.h"

//---------------------------------------------------------------------
SceneManager::SceneManager(GameState* state)
{
    scene_state = state->getSceneState();
    title_manager = new TitleManager(state);
}
//---------------------------------------------------------------------
SceneManager::~SceneManager()
{
    delete(title_manager);
}
//---------------------------------------------------------------------
void SceneManager::update()
{
    int scene = scene_state->getScene();
    if (scene == SceneState::SCENE_DEBUG) {}
    if (scene == SceneState::SCENE_TITLE) { title_manager->update(); }
}