//-----------------------------------------------------------
#include "SystemData.h"

//-----------------------------------------------------------
const int SystemData::DEFAULT_WINDOW_WIDTH  = 1280;
const int SystemData::DEFAULT_WINDOW_HEIGHT = 720;
const int SystemData::DEFAULT_WINDOW_COLOR  = 32;

//-----------------------------------------------------------
SystemData::SystemData()
{
    
}
//-----------------------------------------------------------
SystemData::~SystemData()
{
    
}
//-----------------------------------------------------------
int SystemData::getWindowWidth() { return DEFAULT_WINDOW_WIDTH; }
int SystemData::getWindowHeight() { return DEFAULT_WINDOW_HEIGHT; }
int SystemData::getWindowColor() { return DEFAULT_WINDOW_COLOR; }