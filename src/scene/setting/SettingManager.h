#pragma once
#include "../../GameState.h"

class SettingManager
{
private:
public:
    SettingManager(GameState*);
    ~SettingManager();
    void update();
};