#pragma once

class EditData
{
private:
    EditData();
    ~EditData();
public:
    static int getThumbnailPosX(int);
    static int getThumbnailPosY(int);
    static int getThumbnailSizeX();
    static int getThumbnailSizeY();
    static bool isThumbnailPos(int, int, int);

    static int getEditNamePosX();
    static int getEditNamePosY();
    static int getEditNameSizeX();
    static int getEditNameSizeY();
    static bool isEditNamePos(int, int);

    static int getEditTextPosX(int);
    static int getEditTextPosY(int);
    static int getEditTextSizeX(int);
    static int getEditTextSizeY(int);
    static bool isEditTextPos(int, int, int);

    static int getEditCharaButtonPosX(int);
    static int getEditCharaButtonPosY(int);
    static int getEditCharaButtonSizeX(int);
    static int getEditCharaButtonSizeY(int);
    static bool isEditCharaButtonPos(int, int, int);
};