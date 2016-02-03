#include "SaveloadData.h"

//---------------------------------------------------------------------
const int SaveloadData::BUTTON_BACK_POS_X = 1140;
const int SaveloadData::BUTTON_BACK_POS_Y = 620;
const int SaveloadData::BUTTON_BACK_SIZE_X = 100;
const int SaveloadData::BUTTON_BACK_SIZE_Y = 80;
const int SaveloadData::BUTTON_PAGE_NUM = 20;
const int SaveloadData::BUTTON_PAGE_POS_X = 1150;
const int SaveloadData::BUTTON_PAGE_POS_Y = 100;
const int SaveloadData::BUTTON_PAGE_SIZE_X = 40;
const int SaveloadData::BUTTON_PAGE_SIZE_Y = 40;
const int SaveloadData::BUTTON_PAGE_MARGIN = 10;

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
bool SaveloadData::isButtonPagePos(int n, int x, int y)
{
    int px1 = getButtonPagePosX(n);
    int py1 = getButtonPagePosY(n);
    int px2 = px1 + getButtonPageSizeX();
    int py2 = py1 + getButtonPageSizeY();
    if (x < px1 || x > px2 || y < py1 || y > py2) { return false; }
    return true;
}
//---------------------------------------------------------------------
int SaveloadData::getButtonBackPosX() { return BUTTON_BACK_POS_X; }
int SaveloadData::getButtonBackPosY() { return BUTTON_BACK_POS_Y; }
int SaveloadData::getButtonBackSizeX() { return BUTTON_BACK_SIZE_X; }
int SaveloadData::getButtonBackSizeY() { return BUTTON_BACK_SIZE_Y; }

int SaveloadData::getButtonPageNum() { return BUTTON_PAGE_NUM; }
int SaveloadData::getButtonPagePosX(int n) {
    return BUTTON_PAGE_POS_X + (n / 10) * (BUTTON_PAGE_SIZE_X + BUTTON_PAGE_MARGIN);
}
int SaveloadData::getButtonPagePosY(int n) {
    return BUTTON_PAGE_POS_Y + (n % 10) * (BUTTON_PAGE_SIZE_Y + BUTTON_PAGE_MARGIN);
}
int SaveloadData::getButtonPageSizeX() { return BUTTON_PAGE_SIZE_X; }
int SaveloadData::getButtonPageSizeY() { return BUTTON_PAGE_SIZE_Y; }
int SaveloadData::getButtonPageMargin() { return BUTTON_PAGE_MARGIN; }