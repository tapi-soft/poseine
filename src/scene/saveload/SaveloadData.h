#pragma once

class SaveloadData
{
private:
    static const int BUTTON_BACK_POS_X;
    static const int BUTTON_BACK_POS_Y;
    static const int BUTTON_BACK_SIZE_X;
    static const int BUTTON_BACK_SIZE_Y;

    static const int BUTTON_PAGE_NUM;
    static const int BUTTON_PAGE_POS_X;
    static const int BUTTON_PAGE_POS_Y;
    static const int BUTTON_PAGE_SIZE_X;
    static const int BUTTON_PAGE_SIZE_Y;
    static const int BUTTON_PAGE_MARGIN;

    static const int SAVEDATA_NUM;
    static const int SAVEDATA_NUM_X;
    static const int SAVEDATA_NUM_Y;
    static const int SAVEDATA_POS_X;
    static const int SAVEDATA_POS_Y;
    static const int SAVEDATA_SIZE_X;
    static const int SAVEDATA_SIZE_Y;
    static const int SAVEDATA_MARGIN_X;
    static const int SAVEDATA_MARGIN_Y;

    static const int BUTTON_DELETE_POS_X;
    static const int BUTTON_DELETE_POS_Y;
    static const int BUTTON_DELETE_SIZE_X;
    static const int BUTTON_DELETE_SIZE_Y;

    SaveloadData();
    ~SaveloadData();
public:
    static bool isButtonBackPos(int, int);
    static bool isButtonPagePos(int, int, int);
    static bool isSavedataPos(int, int, int);
    static bool isButtonDeletePos(int, int, int);

    static int getButtonBackPosX();
    static int getButtonBackPosY();
    static int getButtonBackSizeX();
    static int getButtonBackSizeY();

    static int getButtonPageNum();
    static int getButtonPagePosX(int);
    static int getButtonPagePosY(int);
    static int getButtonPageSizeX();
    static int getButtonPageSizeY();
    static int getButtonPageMargin();

    static int getSavedataNum();
    static int getSavedataNumX();
    static int getSavedataNumY();
    static int getSavedataPosX(int);
    static int getSavedataPosY(int);
    static int getSavedataSizeX();
    static int getSavedataSizeY();
    static int getSavedataMarginX();
    static int getSavedataMarginY();

    static int getButtonDeletePosX(int);
    static int getButtonDeletePosY(int);
    static int getButtonDeleteSizeX();
    static int getButtonDeleteSizeY();
};