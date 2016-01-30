//---------------------------------------------------------------------
#include "SceneManager.h"
#include "SceneState.h"

//---------------------------------------------------------------------
SceneManager::SceneManager(GameState* state)
{
    scene_state = state->getSceneState();
    title_manager = new TitleManager(state);
    main_manager = new MainManager(state);
}
//---------------------------------------------------------------------
SceneManager::~SceneManager()
{
    delete(main_manager);
    delete(title_manager);
}
//---------------------------------------------------------------------
void SceneManager::update()
{
    scene_state->update();

    int scene = scene_state->getScene();
    if (scene == SceneState::SCENE_DEBUG) {}
    if (scene == SceneState::SCENE_TITLE) { title_manager->update(); }
    if (scene == SceneState::SCENE_MAIN) { main_manager->update(); }
}