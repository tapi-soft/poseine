//---------------------------------------------------------------------
#include "TitleData.h"

int TitleData::button_num = 6;
int TitleData::button_size_x = 200;
int TitleData::button_size_y = 40;
int TitleData::button_pos_x = 1000;
int TitleData::button_pos_y = 300;
int TitleData::button_margin = 20;

//---------------------------------------------------------------------
TitleData::TitleData()
{

}
//---------------------------------------------------------------------
TitleData::~TitleData()
{

}
//---------------------------------------------------------------------
bool TitleData::isButtonPos(int n, int x, int y)
{
    int px1 = getButtonPosX(n);
    int py1 = getButtonPosY(n);
    int px2 = px1 + getButtonSizeX();
    int py2 = py1 + getButtonSizeY();
    if (x < px1 || x > px2 || y < py1 || y > py2) { return false; }
    return true;
}
//---------------------------------------------------------------------
int TitleData::getButtonImage(int n, int x, int y)
{
    if (isButtonPos(n, x, y)) { return n + getButtonNum(); }
    return n;
}
//---------------------------------------------------------------------
int TitleData::getButtonNum()
{
    return button_num;
}
//---------------------------------------------------------------------
int TitleData::getButtonSizeX()
{
    return button_size_x;
}
//---------------------------------------------------------------------
int TitleData::getButtonSizeY()
{
    return button_size_y;
}
//---------------------------------------------------------------------
int TitleData::getButtonPosX(int n)
{
    return button_pos_x;
}
//---------------------------------------------------------------------
int TitleData::getButtonPosY(int n)
{
    return button_pos_y + n * (button_size_y + button_margin);
}