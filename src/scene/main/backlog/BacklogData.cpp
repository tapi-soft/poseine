#include "BacklogData.h"

//---------------------------------------------------------------------
const int BacklogData::BUTTON_BACK_POS_X = 1150;
const int BacklogData::BUTTON_BACK_POS_Y = 600;
const int BacklogData::BUTTON_BACK_SIZE_X = 100;
const int BacklogData::BUTTON_BACK_SIZE_Y = 80;

//---------------------------------------------------------------------
BacklogData::BacklogData()
{

}
//---------------------------------------------------------------------
BacklogData::~BacklogData()
{

}
//---------------------------------------------------------------------
bool BacklogData::isButtonBackPos(int x, int y)
{
    int px1 = BUTTON_BACK_POS_X;
    int py1 = BUTTON_BACK_POS_Y;
    int px2 = px1 + BUTTON_BACK_SIZE_X;
    int py2 = py1 + BUTTON_BACK_SIZE_Y;
    if (x < px1 || x > px2 || y < py1 || y > py2) { return false; }
    return true;
}
//---------------------------------------------------------------------
int BacklogData::getButtonBackPosX() { return BUTTON_BACK_POS_X; }
int BacklogData::getButtonBackPosY() { return BUTTON_BACK_POS_Y; }
int BacklogData::getButtonBackSizeX() { return BUTTON_BACK_SIZE_X; }
int BacklogData::getButtonBackSizeY() { return BUTTON_BACK_SIZE_Y; }