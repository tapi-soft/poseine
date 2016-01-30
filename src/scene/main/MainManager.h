#pragma once
#include "../../GameState.h"

class MainManager {
private:

public:
    MainManager(GameState*);
    ~MainManager();
    void update();
};