#pragma once

class MainData {
public:
    static const int BUTTON_AUTO;
    static const int BUTTON_SKIP;
    static const int BUTTON_LOG;
    static const int BUTTON_CONF;
    static const int BUTTON_SAVE;
    static const int BUTTON_LOAD;

    static const int MODE_NORMAL;
    static const int MODE_AUTO;
    static const int MODE_SKIP;
    static const int MODE_SELECT;

private:
    static const int BUTTON_POS_X;
    static const int BUTTON_POS_Y;
    static const int BUTTON_SIZE_X;
    static const int BUTTON_SIZE_Y;
    static const int BUTTON_MARGIN_X;
    static const int BUTTON_MARGIN_Y;

    static const int SELECT_SIZE_X;
    static const int SELECT_SIZE_Y;
    static const int SELECT1_POS_X;
    static const int SELECT1_POS_Y;
    static const int SELECT2_POS_X;
    static const int SELECT2_POS_Y;

    MainData();
    ~MainData();
public:
    static int getButtonPosX(int);
    static int getButtonPosY(int);
    static bool isButtonPos(int, int, int);

    static int getSelectSizeX();
    static int getSelectSizeY();
    static int getSelectPosX(int);
    static int getSelectPosY(int);
    static bool isSelectPos(int, int, int);
};