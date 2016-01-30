#include "GameManager.h"
#include <iostream>

//---------------------------------------------------------------------
GameManager::GameManager()
{
    fps_manager = new FpsManager();
    draw_manager = new DrawManager();
}
//---------------------------------------------------------------------
GameManager::~GameManager()
{
    delete(draw_manager);
    delete(fps_manager);
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
    draw_manager->update();
    fps_manager->wait();
    return 0;
}
//---------------------------------------------------------------------