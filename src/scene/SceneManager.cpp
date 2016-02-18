//---------------------------------------------------------------------
#include "SceneManager.h"
#include "SceneState.h"

//---------------------------------------------------------------------
SceneManager::SceneManager(GameState* state)
{
    scene_state = state->getSceneState();
    title_manager = new TitleManager(state);
    main_manager = new MainManager(state);
    saveload_manager = new SaveloadManager(state);
    setting_manager = new SettingManager(state);
    edit_manager = new EditManager(state);
}
//---------------------------------------------------------------------
SceneManager::~SceneManager()
{
    delete(edit_manager);
    delete(setting_manager);
    delete(saveload_manager);
    delete(main_manager);
    delete(title_manager);
}
//---------------------------------------------------------------------
void SceneManager::update()
{
    scene_state->update();

    if (!scene_state->isFade()) {
        int scene = scene_state->getScene();
        if (scene == SceneState::SCENE_DEBUG) {}
        else if (scene == SceneState::SCENE_TITLE) { title_manager->update(); }
        else if (scene == SceneState::SCENE_MAIN) { main_manager->update(); }
        else if (scene == SceneState::SCENE_SAVE) { saveload_manager->update(); }
        else if (scene == SceneState::SCENE_LOAD) { saveload_manager->update(); }
        else if (scene == SceneState::SCENE_SETTING) { setting_manager->update(); }
        else if (scene == SceneState::SCENE_EDIT) { edit_manager->update(); }
    }
}