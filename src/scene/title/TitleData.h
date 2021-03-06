#pragma once

class TitleData
{
public:
    static const int BUTTON_BEGIN;
    static const int BUTTON_CONTINUE;
    static const int BUTTON_SETTING;
    static const int BUTTON_SPECIAL;
    static const int BUTTON_OFFICIAL;
    static const int BUTTON_END;
private:
    TitleData();
    ~TitleData();
    static int button_num;
    static int button_size_x;
    static int button_size_y;
    static int button_pos_x;
    static int button_pos_y;
    static int button_margin;
public:
    static bool isButtonPos(int, int, int);

    static int getButtonImage(int, int, int);

    static int getButtonNum();
    static int getButtonSizeX();
    static int getButtonSizeY();
    static int getButtonPosX(int);
    static int getButtonPosY(int);
};