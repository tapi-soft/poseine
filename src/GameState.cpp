//-----------------------------------------------------------
#include "GameState.h"

//-----------------------------------------------------------
GameState::GameState()
{
    input_state = new InputState();
    scene_state = new SceneState();
}
//-----------------------------------------------------------
GameState::~GameState()
{
    delete(scene_state);
    delete(input_state);
}
//-----------------------------------------------------------
SceneState* GameState::getSceneState() { return scene_state; }
InputState* GameState::getInputState() { return input_state; }