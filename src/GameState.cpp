//-----------------------------------------------------------
#include "GameState.h"

//-----------------------------------------------------------
GameState::GameState()
{
    input_state = new InputState();
    scene_state = new SceneState();
    is_end = false;
}
//-----------------------------------------------------------
GameState::~GameState()
{
    delete(scene_state);
    delete(input_state);
}
//-----------------------------------------------------------
void GameState::gameEnd()
{
    is_end = true;
}
//-----------------------------------------------------------
bool GameState::isEnd()
{
    return is_end;
}
//-----------------------------------------------------------
SceneState* GameState::getSceneState() { return scene_state; }
InputState* GameState::getInputState() { return input_state; }