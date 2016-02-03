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

    SaveloadData();
    ~SaveloadData();
public:
    static bool isButtonBackPos(int, int);
    static bool isButtonPagePos(int, int, int);

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
};