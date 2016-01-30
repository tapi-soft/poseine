#pragma once

class SystemData
{
private:
    static const int DEFAULT_WINDOW_WIDTH;
    static const int DEFAULT_WINDOW_HEIGHT;
    static const int DEFAULT_WINDOW_COLOR;

    SystemData();
    ~SystemData();
public:
    static int getWindowWidth();
    static int getWindowHeight();
    static int getWindowColor();
};