#include "GameManager.h"
#include <iostream>

//---------------------------------------------------------------------
GameManager::GameManager()
{
    printf("a");
}
//---------------------------------------------------------------------
GameManager::~GameManager()
{
}
//---------------------------------------------------------------------
int GameManager::start()
{
    while (1) {
        if (ProcessMessage() != 0) return -1;
        if (ClearDrawScreen() != 0) return -1;
        if (update() != 0) return -1;
    }
    return 0;
}
//---------------------------------------------------------------------
int GameManager::update()
{
    return 0;
}
//---------------------------------------------------------------------