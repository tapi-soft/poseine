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
    if (x < px1 || x >= px2 || y < py1 || y >= py2) { return false; }
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
    if (x < px1 || x >= px2 || y < py1 || y >= py2) { return false; }
    return true;
}
//---------------------------------------------------------------------
int EditData::getEditTextPosX(int n) { return 72; }
int EditData::getEditTextPosY(int n)
{
    if (n == 1) { return 85; }
    if (n == 2) { return 114; }
    if (n == 3) { return 143; }
    return 0;
}
int EditData::getEditTextSizeX(int n) { return 355; }
int EditData::getEditTextSizeY(int n) { return 28; }
bool EditData::isEditTextPos(int n, int x, int y)
{
    int px1 = getEditTextPosX(n);
    int py1 = getEditTextPosY(n);
    int px2 = px1 + getEditTextSizeX(n);
    int py2 = py1 + getEditTextSizeY(n);
    if (x < px1 || x >= px2 || y < py1 || y >= py2) { return false; }
    return true;
}
//---------------------------------------------------------------------
int EditData::getEditCharaButtonPosX(int n) { return 1 + getEditCharaButtonSizeX(n) * n; }
int EditData::getEditCharaButtonPosY(int n) { return 185; }
int EditData::getEditCharaButtonSizeX(int n) { return 28; }
int EditData::getEditCharaButtonSizeY(int n) { return 28; }
bool EditData::isEditCharaButtonPos(int n, int x, int y)
{
    int px1 = getEditCharaButtonPosX(n);
    int py1 = getEditCharaButtonPosY(n);
    int px2 = px1 + getEditCharaButtonSizeX(n);
    int py2 = py1 + getEditCharaButtonSizeY(n);
    if (x < px1 || x >= px2 || y < py1 || y >= py2) { return false; }
    return true;
}
//---------------------------------------------------------------------
int EditData::getEditButtonSizeX() { return 28; }
int EditData::getEditButtonSizeY() { return 28; }
//---------------------------------------------------------------------
int EditData::getEditButtonPrevCharaPosPosX() { return 371; }
int EditData::getEditButtonPrevCharaPosPosY() { return 214; }
bool EditData::isEditButtonPrevCharaPosPos(int x, int y)
{
    int px1 = getEditButtonPrevCharaPosPosX();
    int py1 = getEditButtonPrevCharaPosPosY();
    int px2 = px1 + getEditButtonSizeX();
    int py2 = py1 + getEditButtonSizeY();
    if (x < px1 || x >= px2 || y < py1 || y >= py2) { return false; }
    return true;
}
int EditData::getEditButtonNextCharaPosPosX() { return 399; }
int EditData::getEditButtonNextCharaPosPosY() { return 214; }
bool EditData::isEditButtonNextCharaPosPos(int x, int y)
{
    int px1 = getEditButtonNextCharaPosPosX();
    int py1 = getEditButtonNextCharaPosPosY();
    int px2 = px1 + getEditButtonSizeX();
    int py2 = py1 + getEditButtonSizeY();
    if (x < px1 || x >= px2 || y < py1 || y >= py2) { return false; }
    return true;
}
//---------------------------------------------------------------------
int EditData::getEditButtonPrevCharaImagePosX() { return 371; }
int EditData::getEditButtonPrevCharaImagePosY() { return 243; }
bool EditData::isEditButtonPrevCharaImagePos(int x, int y)
{
    int px1 = getEditButtonPrevCharaImagePosX();
    int py1 = getEditButtonPrevCharaImagePosY();
    int px2 = px1 + getEditButtonSizeX();
    int py2 = py1 + getEditButtonSizeY();
    if (x < px1 || x >= px2 || y < py1 || y >= py2) { return false; }
    return true;
}
int EditData::getEditButtonNextCharaImagePosX() { return 399; }
int EditData::getEditButtonNextCharaImagePosY() { return 243; }
bool EditData::isEditButtonNextCharaImagePos(int x, int y)
{
    int px1 = getEditButtonNextCharaImagePosX();
    int py1 = getEditButtonNextCharaImagePosY();
    int px2 = px1 + getEditButtonSizeX();
    int py2 = py1 + getEditButtonSizeY();
    if (x < px1 || x >= px2 || y < py1 || y >= py2) { return false; }
    return true;
}
//---------------------------------------------------------------------
int EditData::getEditButtonPrevCharaFacePosX() { return 371; }
int EditData::getEditButtonPrevCharaFacePosY() { return 272; }
bool EditData::isEditButtonPrevCharaFacePos(int x, int y)
{
    int px1 = getEditButtonPrevCharaFacePosX();
    int py1 = getEditButtonPrevCharaFacePosY();
    int px2 = px1 + getEditButtonSizeX();
    int py2 = py1 + getEditButtonSizeY();
    if (x < px1 || x >= px2 || y < py1 || y >= py2) { return false; }
    return true;
}
int EditData::getEditButtonNextCharaFacePosX() { return 399; }
int EditData::getEditButtonNextCharaFacePosY() { return 272; }
bool EditData::isEditButtonNextCharaFacePos(int x, int y)
{
    int px1 = getEditButtonNextCharaFacePosX();
    int py1 = getEditButtonNextCharaFacePosY();
    int px2 = px1 + getEditButtonSizeX();
    int py2 = py1 + getEditButtonSizeY();
    if (x < px1 || x >= px2 || y < py1 || y >= py2) { return false; }
    return true;
}
//---------------------------------------------------------------------
int EditData::getEditButtonPrevBackimagePosX() { return 371; }
int EditData::getEditButtonPrevBackimagePosY() { return 314; }
bool EditData::isEditButtonPrevBackimagePos(int x, int y)
{
    int px1 = getEditButtonPrevBackimagePosX();
    int py1 = getEditButtonPrevBackimagePosY();
    int px2 = px1 + getEditButtonSizeX();
    int py2 = py1 + getEditButtonSizeY();
    if (x < px1 || x >= px2 || y < py1 || y >= py2) { return false; }
    return true;
}
int EditData::getEditButtonNextBackimagePosX() { return 399; }
int EditData::getEditButtonNextBackimagePosY() { return 314; }
bool EditData::isEditButtonNextBackimagePos(int x, int y)
{
    int px1 = getEditButtonNextBackimagePosX();
    int py1 = getEditButtonNextBackimagePosY();
    int px2 = px1 + getEditButtonSizeX();
    int py2 = py1 + getEditButtonSizeY();
    if (x < px1 || x >= px2 || y < py1 || y >= py2) { return false; }
    return true;
}