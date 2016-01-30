//-----------------------------------------------------------
#include "GameDraw.h"

//-----------------------------------------------------------
GameDraw::GameDraw(GameState* state)
{
    scene_state = state->getSceneState();
    title_draw = new TitleDraw(state);
    main_draw = new MainDraw(state);
}
//-----------------------------------------------------------
GameDraw::~GameDraw()
{
    delete(main_draw);
    delete(title_draw);
}
//-----------------------------------------------------------
void GameDraw::update()
{
    int scene = scene_state->getScene();
    if (scene == SceneState::SCENE_DEBUG) {}
    if (scene == SceneState::SCENE_TITLE) { title_draw->update(); }
    if (scene == SceneState::SCENE_MAIN) { main_draw->update(); }

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