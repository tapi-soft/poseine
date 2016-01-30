//-----------------------------------------------------------
#include "GameState.h"

//-----------------------------------------------------------
GameState::GameState()
{
    scene_state = new SceneState();
}
//-----------------------------------------------------------
GameState::~GameState()
{
    delete(scene_state);
}
//-----------------------------------------------------------
SceneState* GameState::getSceneState() { return scene_state; }