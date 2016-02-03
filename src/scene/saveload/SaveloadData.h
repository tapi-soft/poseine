#pragma once

class SaveloadData
{
private:
    static const int BUTTON_BACK_POS_X;
    static const int BUTTON_BACK_POS_Y;
    static const int BUTTON_BACK_SIZE_X;
    static const int BUTTON_BACK_SIZE_Y;

    static const int BUTTON_NUM_POS_X;
    static const int BUTTON_NUM_POS_Y;
    static const int BUTTON_NUM_SIZE_X;
    static const int BUTTON_NUM_SIZE_Y;

    SaveloadData();
    ~SaveloadData();
public:
    static bool isButtonBackPos(int, int);
    static bool isButtonNumPos(int, int, int);

    static int getButtonBackPosX();
    static int getButtonBackPosY();
    static int getButtonBackSizeX();
    static int getButtonBackSizeY();

    static int getButtonNumPosX(int);
    static int getButtonNumPosY(int);
    static int getButtonNumSizeX();
    static int getButtonNumSizeY();
    
};