#pragma once
#include "../../../GameState.h"

class BacklogManager {
private:
public:
    BacklogManager(GameState*);
    ~BacklogManager();
    void update();
};