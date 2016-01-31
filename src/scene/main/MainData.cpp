//---------------------------------------------------------------------
#include "MainData.h"
#include "../../SystemData.h"

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

const int MainData::BUTTON_POS_X = SystemData::getWindowWidth() - 130;
const int MainData::BUTTON_POS_Y = SystemData::getWindowHeight() - 160;
const int MainData::BUTTON_SIZE_X = 49;
const int MainData::BUTTON_SIZE_Y = 44;
const int MainData::BUTTON_MARGIN_X = 5;
const int MainData::BUTTON_MARGIN_Y = 5;

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