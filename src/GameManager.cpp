#include "GameManager.h"
#include <iostream>

//---------------------------------------------------------------------
GameManager::GameManager()
{
    game_state = new GameState();
    fps_manager = new FpsManager();
    game_draw = new GameDraw(game_state);
    scene_manager = new SceneManager(game_state);
}
//---------------------------------------------------------------------
GameManager::~GameManager()
{
    delete(scene_manager);
    delete(game_draw);
    delete(fps_manager);
    delete(game_state);
}
//---------------------------------------------------------------------
int GameManager::init()
{
    fps_manager->init();
    return 0;
}
//---------------------------------------------------------------------
int GameManager::start()
{
    if (init() != 0) { return -1; }

    while (1) {
        if (ProcessMessage() != 0) { return -1; }
        if (ClearDrawScreen() != 0) { return -1; }
        if (update() != 0) { return -1; }
    }
    return 0;
}
//---------------------------------------------------------------------
int GameManager::update()
{
    fps_manager->update();
    game_state->getInputState()->update();
    scene_manager->update();
    game_draw->update();
    fps_manager->wait();
    return 0;
}
//---------------------------------------------------------------------