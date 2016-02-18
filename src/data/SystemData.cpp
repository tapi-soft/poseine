//-----------------------------------------------------------
#include "SystemData.h"

//-----------------------------------------------------------
const int SystemData::DEFAULT_WINDOW_WIDTH  = 1280;
const int SystemData::DEFAULT_WINDOW_HEIGHT = 720;
const int SystemData::DEFAULT_WINDOW_COLOR  = 32;

//-----------------------------------------------------------
SystemData::SystemData()
{
    debug_mode = true;
    window_width = DEFAULT_WINDOW_WIDTH;
    window_height = DEFAULT_WINDOW_HEIGHT;
    window_color = DEFAULT_WINDOW_COLOR;
}
//-----------------------------------------------------------
SystemData::~SystemData()
{
    
}
//-----------------------------------------------------------
SystemData* SystemData::getInstance()
{
    static SystemData instance;
    return &instance;
}
//-----------------------------------------------------------
int SystemData::getWindowWidth() { return window_width; }
int SystemData::getWindowHeight() { return window_height; }
int SystemData::getWindowColor() { return window_color; }
bool SystemData::getDebugMode() { return debug_mode; }