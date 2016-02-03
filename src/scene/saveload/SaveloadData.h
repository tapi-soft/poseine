#pragma once

class SaveloadData
{
private:
    static const int BUTTON_BACK_POS_X;
    static const int BUTTON_BACK_POS_Y;
    static const int BUTTON_BACK_SIZE_X;
    static const int BUTTON_BACK_SIZE_Y;

    SaveloadData();
    ~SaveloadData();
public:
    static bool isButtonBackPos(int, int);

    static int getButtonBackPosX();
    static int getButtonBackPosY();
    static int getButtonBackSizeX();
    static int getButtonBackSizeY();
};