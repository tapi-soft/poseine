#include "SaveloadState.h"

const int SaveloadState::MODE_SAVE = 0;
const int SaveloadState::MODE_LOAD = 1;


//---------------------------------------------------------------------
SaveloadState::SaveloadState()
{
    mode = MODE_SAVE;
}
//---------------------------------------------------------------------
SaveloadState::~SaveloadState()
{

}
//---------------------------------------------------------------------
void SaveloadState::update()
{

}
//---------------------------------------------------------------------
void SaveloadState::setMode(int mode) { this->mode = mode; }
//---------------------------------------------------------------------
int SaveloadState::getMode() { return mode; }