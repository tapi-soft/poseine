#include "SaveloadData.h"

//---------------------------------------------------------------------
const int SaveloadData::BUTTON_BACK_POS_X = 1140;
const int SaveloadData::BUTTON_BACK_POS_Y = 620;
const int SaveloadData::BUTTON_BACK_SIZE_X = 100;
const int SaveloadData::BUTTON_BACK_SIZE_Y = 80;

//---------------------------------------------------------------------
SaveloadData::SaveloadData()
{

}
//---------------------------------------------------------------------
SaveloadData::~SaveloadData()
{

}
//---------------------------------------------------------------------
bool SaveloadData::isButtonBackPos(int x, int y)
{
    int px1 = getButtonBackPosX();
    int py1 = getButtonBackPosY();
    int px2 = px1 + getButtonBackSizeX();
    int py2 = py1 + getButtonBackSizeY();
    if (x < px1 || x > px2 || y < py1 || y > py2) { return false; }
    return true;
}
//---------------------------------------------------------------------
int SaveloadData::getButtonBackPosX() { return BUTTON_BACK_POS_X; }
int SaveloadData::getButtonBackPosY() { return BUTTON_BACK_POS_Y; }
int SaveloadData::getButtonBackSizeX() { return BUTTON_BACK_SIZE_X; }
int SaveloadData::getButtonBackSizeY() { return BUTTON_BACK_SIZE_Y; }