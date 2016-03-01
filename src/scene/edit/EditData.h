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

    static int getEditButtonSizeX();
    static int getEditButtonSizeY();

    static int getEditButtonPrevCharaPosPosX();
    static int getEditButtonPrevCharaPosPosY();
    static bool isEditButtonPrevCharaPosPos(int, int);
    static int getEditButtonNextCharaPosPosX();
    static int getEditButtonNextCharaPosPosY();
    static bool isEditButtonNextCharaPosPos(int, int);

    static int getEditButtonPrevCharaImagePosX();
    static int getEditButtonPrevCharaImagePosY();
    static bool isEditButtonPrevCharaImagePos(int, int);
    static int getEditButtonNextCharaImagePosX();
    static int getEditButtonNextCharaImagePosY();
    static bool isEditButtonNextCharaImagePos(int, int);

    static int getEditButtonPrevCharaFacePosX();
    static int getEditButtonPrevCharaFacePosY();
    static bool isEditButtonPrevCharaFacePos(int, int);
    static int getEditButtonNextCharaFacePosX();
    static int getEditButtonNextCharaFacePosY();
    static bool isEditButtonNextCharaFacePos(int, int);

    static int getEditButtonPrevBackimagePosX();
    static int getEditButtonPrevBackimagePosY();
    static bool isEditButtonPrevBackimagePos(int, int);
    static int getEditButtonNextBackimagePosX();
    static int getEditButtonNextBackimagePosY();
    static bool isEditButtonNextBackimagePos(int, int);

    static int getThumbnailButtonAddPosX();
    static int getThumbnailButtonAddPosY();
    static int getThumbnailButtonAddSizeX();
    static int getThumbnailButtonAddSizeY();
    static bool isThumbnailButtonAddPos(int, int);

    static int getThumbnailButtonDelPosX();
    static int getThumbnailButtonDelPosY();
    static int getThumbnailButtonDelSizeX();
    static int getThumbnailButtonDelSizeY();
    static bool isThumbnailButtonDelPos(int, int);
};