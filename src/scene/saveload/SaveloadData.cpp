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

const int SaveloadData::SAVEDATA_NUM = 10;
const int SaveloadData::SAVEDATA_NUM_X = 2;
const int SaveloadData::SAVEDATA_NUM_Y = 5;
const int SaveloadData::SAVEDATA_POS_X = 50;
const int SaveloadData::SAVEDATA_POS_Y = 100;
const int SaveloadData::SAVEDATA_SIZE_X = 514;
const int SaveloadData::SAVEDATA_SIZE_Y = 114;
const int SaveloadData::SAVEDATA_MARGIN_X = 26;
const int SaveloadData::SAVEDATA_MARGIN_Y = 6;

const int SaveloadData::BUTTON_DELETE_POS_X = 485;
const int SaveloadData::BUTTON_DELETE_POS_Y = 4;
const int SaveloadData::BUTTON_DELETE_SIZE_X = 25;
const int SaveloadData::BUTTON_DELETE_SIZE_Y = 25;

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
bool SaveloadData::isSavedataPos(int n, int x, int y)
{
    int px1 = getSavedataPosX(n);
    int py1 = getSavedataPosY(n);
    int px2 = px1 + getSavedataSizeX();
    int py2 = py1 + getSavedataSizeY();
    if (x < px1 || x > px2 || y < py1 || y > py2) { return false; }
    return true;
}
//---------------------------------------------------------------------
bool SaveloadData::isButtonDeletePos(int n, int x, int y)
{
    int px1 = getButtonDeletePosX(n);
    int py1 = getButtonDeletePosY(n);
    int px2 = px1 + getButtonDeleteSizeX();
    int py2 = py1 + getButtonDeleteSizeY();
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

int SaveloadData::getSavedataNum() { return SAVEDATA_NUM; }
int SaveloadData::getSavedataNumX() { return SAVEDATA_NUM_X; }
int SaveloadData::getSavedataNumY() { return SAVEDATA_NUM_Y; }
int SaveloadData::getSavedataPosX(int n) { return SAVEDATA_POS_X + (n / SAVEDATA_NUM_Y) * (SAVEDATA_SIZE_X + SAVEDATA_MARGIN_X); }
int SaveloadData::getSavedataPosY(int n) { return SAVEDATA_POS_Y + (n % SAVEDATA_NUM_Y) * (SAVEDATA_SIZE_Y + SAVEDATA_MARGIN_Y); }
int SaveloadData::getSavedataSizeX() { return SAVEDATA_SIZE_X; }
int SaveloadData::getSavedataSizeY() { return SAVEDATA_SIZE_Y; }
int SaveloadData::getSavedataMarginX() { return SAVEDATA_MARGIN_X; }
int SaveloadData::getSavedataMarginY() { return SAVEDATA_MARGIN_Y; }

int SaveloadData::getButtonDeletePosX(int n) { return getSavedataPosX(n) + BUTTON_DELETE_POS_X; }
int SaveloadData::getButtonDeletePosY(int n) { return getSavedataPosY(n) + BUTTON_DELETE_POS_Y; }
int SaveloadData::getButtonDeleteSizeX() { return BUTTON_DELETE_SIZE_X; }
int SaveloadData::getButtonDeleteSizeY() { return BUTTON_DELETE_SIZE_Y; }