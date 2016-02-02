#pragma once
#include "../../GameState.h"

class SaveloadManager
{
private:
public:
    SaveloadManager(GameState*);
    ~SaveloadManager();
    void update();
};