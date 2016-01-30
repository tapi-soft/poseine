//-----------------------------------------------------------
#include "GameDraw.h"

//-----------------------------------------------------------
GameDraw::GameDraw(GameState* state)
{
    sceneState = state->getSceneState();
    title_draw = new TitleDraw(state);
}
//-----------------------------------------------------------
GameDraw::~GameDraw()
{
    delete(title_draw);
}
//-----------------------------------------------------------
void GameDraw::update()
{
    int scene = sceneState->getScene();
    if (scene == SceneState::SCENE_DEBUG) {}
    if (scene == SceneState::SCENE_TITLE) { title_draw->update(); }
    ScreenFlip();
}