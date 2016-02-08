//---------------------------------------------------------------------
#include "MainData.h"
#include "../../data/SystemData.h"

//---------------------------------------------------------------------
const int MainData::BUTTON_AUTO = 0;
const int MainData::BUTTON_SKIP = 1;
const int MainData::BUTTON_LOG = 2;
const int MainData::BUTTON_CONF = 3;
const int MainData::BUTTON_SAVE = 4;
const int MainData::BUTTON_LOAD = 5;

const int MainData::MODE_NORMAL = 0;
const int MainData::MODE_AUTO = 1;
const int MainData::MODE_SKIP = 2;
const int MainData::MODE_SELECT = 3;

const int MainData::BUTTON_POS_X = SystemData::getWindowWidth() - 130;
const int MainData::BUTTON_POS_Y = SystemData::getWindowHeight() - 160;
const int MainData::BUTTON_SIZE_X = 49;
const int MainData::BUTTON_SIZE_Y = 44;
const int MainData::BUTTON_MARGIN_X = 5;
const int MainData::BUTTON_MARGIN_Y = 5;

const int MainData::SELECT_SIZE_X = 800;
const int MainData::SELECT_SIZE_Y = 80;
const int MainData::SELECT1_POS_X = 240;
const int MainData::SELECT1_POS_Y = 200;
const int MainData::SELECT2_POS_X = 240;
const int MainData::SELECT2_POS_Y = 350;

//---------------------------------------------------------------------
int MainData::getButtonPosX(int n)
{
    if (n % 2 == 0) {
        return BUTTON_POS_X;
    }
    return BUTTON_POS_X + BUTTON_SIZE_X + BUTTON_MARGIN_X;
}
//---------------------------------------------------------------------
int MainData::getButtonPosY(int n)
{
    return BUTTON_POS_Y + (n / 2) * (BUTTON_SIZE_Y + BUTTON_MARGIN_Y);
}
//---------------------------------------------------------------------
bool MainData::isButtonPos(int n, int x, int y)
{
    int px1 = getButtonPosX(n);
    int py1 = getButtonPosY(n);
    int px2 = px1 + BUTTON_SIZE_X;
    int py2 = py1 + BUTTON_SIZE_Y;
    if (x < px1 || x > px2 || y < py1 || y > py2) { return false; }
    return true;
}
//---------------------------------------------------------------------
int MainData::getSelectSizeX()
{
    return SELECT_SIZE_X;
}
//---------------------------------------------------------------------
int MainData::getSelectSizeY()
{
    return SELECT_SIZE_Y;
}
//---------------------------------------------------------------------
int MainData::getSelectPosX(int n)
{
    if (n == 1) { return SELECT1_POS_X; }
    if (n == 2) { return SELECT2_POS_X; }
    return 0;
}
//---------------------------------------------------------------------
int MainData::getSelectPosY(int n)
{
    if (n == 1) { return SELECT1_POS_Y; }
    if (n == 2) { return SELECT2_POS_Y; }
    return 0;
}
//---------------------------------------------------------------------
bool MainData::isSelectPos(int n, int x, int y)
{
    int px1 = getSelectPosX(n);
    int py1 = getSelectPosY(n);
    int px2 = px1 + getSelectSizeX();
    int py2 = py1 + getSelectSizeY();
    if (x < px1 || x > px2 || y < py1 || y > py2) { return false; }
    return true;
}