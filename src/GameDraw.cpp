//-----------------------------------------------------------
#include "GameDraw.h"

//-----------------------------------------------------------
GameDraw::GameDraw(GameState* state)
{
    scene_state = state->getSceneState();
    title_draw = new TitleDraw(state);
    main_draw = new MainDraw(state);
    saveload_draw = new SaveloadDraw(state);
}
//-----------------------------------------------------------
GameDraw::~GameDraw()
{
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

    //---- fadeout/fadein
    if (scene_state->isFade()) {
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, scene_state->getAlpha());
        DrawBox(0, 0,
            SystemData::getWindowWidth(),
            SystemData::getWindowHeight(),
            GetColor(0, 0, 0), TRUE);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    }

    ScreenFlip();
}