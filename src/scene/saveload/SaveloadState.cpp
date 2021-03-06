#include "SaveloadState.h"

const int SaveloadState::MODE_SAVE = 0;
const int SaveloadState::MODE_LOAD = 1;


//---------------------------------------------------------------------
SaveloadState::SaveloadState()
{
    mode = MODE_SAVE;
    page = 0;
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
void SaveloadState::setPage(int page) { this->page = page; }
//---------------------------------------------------------------------
int SaveloadState::getMode() { return mode; }
int SaveloadState::getPage() { return page; }