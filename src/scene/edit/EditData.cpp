//---------------------------------------------------------------------
#include "EditData.h"

//---------------------------------------------------------------------
EditData::EditData()
{

}
//---------------------------------------------------------------------
EditData::~EditData()
{

}
//---------------------------------------------------------------------
int EditData::getThumbnailPosX(int n) { return 800 + 150 * n; }
int EditData::getThumbnailPosY(int n) { return 625; }
int EditData::getThumbnailSizeX() { return 128; }
int EditData::getThumbnailSizeY() { return 72; }
bool EditData::isThumbnailPos(int n, int x, int y)
{
    int px1 = getThumbnailPosX(n);
    int py1 = getThumbnailPosY(n);
    int px2 = px1 + getThumbnailSizeX();
    int py2 = py1 + getThumbnailSizeY();
    if (x < px1 || x > px2 || y < py1 || y > py2) { return false; }
    return true;
}
//---------------------------------------------------------------------
int EditData::getEditNamePosX() { return 72; }
int EditData::getEditNamePosY() { return 56; }
int EditData::getEditNameSizeX() { return 355; }
int EditData::getEditNameSizeY() { return 28; }
bool EditData::isEditNamePos(int x, int y)
{
    int px1 = getEditNamePosX();
    int py1 = getEditNamePosY();
    int px2 = px1 + getEditNameSizeX();
    int py2 = py1 + getEditNameSizeY();
    if (x < px1 || x > px2 || y < py1 || y > py2) { return false; }
    return true;
}