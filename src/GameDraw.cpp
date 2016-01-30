//-----------------------------------------------------------
#include "GameDraw.h"

//-----------------------------------------------------------
GameDraw::GameDraw(GameState* state)
{
    sceneState = state->getSceneState();
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
    int scene = sceneState->getScene();
    if (scene == SceneState::SCENE_DEBUG) {}
    if (scene == SceneState::SCENE_TITLE) { title_draw->update(); }
    if (scene == SceneState::SCENE_MAIN) { main_draw->update(); }
    ScreenFlip();
}