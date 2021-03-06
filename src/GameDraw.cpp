//-----------------------------------------------------------
#include "GameDraw.h"

//-----------------------------------------------------------
GameDraw::GameDraw(GameState* state)
{
    scene_state = state->getSceneState();
    title_draw = new TitleDraw(state);
    main_draw = new MainDraw(state);
    saveload_draw = new SaveloadDraw(state);
    setting_draw = new SettingDraw(state);
    edit_draw = new EditDraw(state);
}
//-----------------------------------------------------------
GameDraw::~GameDraw()
{
    delete(edit_draw);
    delete(setting_draw);
    delete(saveload_draw);
    delete(main_draw);
    delete(title_draw);
}
//-----------------------------------------------------------
void GameDraw::update()
{
    int scene = scene_state->getScene();
    if (scene == SceneState::SCENE_DEBUG) {}
    else if (scene == SceneState::SCENE_TITLE) { title_draw->update(); }
    else if (scene == SceneState::SCENE_MAIN) { main_draw->update(); }
    else if (scene == SceneState::SCENE_SAVE) { saveload_draw->update(); }
    else if (scene == SceneState::SCENE_LOAD) { saveload_draw->update(); }
    else if (scene == SceneState::SCENE_SETTING) { setting_draw->update(); }
    else if (scene == SceneState::SCENE_EDIT) { edit_draw->update(); }

    //---- fadeout/fadein
    if (scene_state->isFade()) {
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, scene_state->getAlpha());
        DrawBox(0, 0,
            SystemData::getInstance()->getWindowWidth(),
            SystemData::getInstance()->getWindowHeight(),
            GetColor(0, 0, 0), TRUE);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    }

    ScreenFlip();
}