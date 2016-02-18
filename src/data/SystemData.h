#pragma once

class SystemData
{
private:
    static const int DEFAULT_WINDOW_WIDTH;
    static const int DEFAULT_WINDOW_HEIGHT;
    static const int DEFAULT_WINDOW_COLOR;

    bool debug_mode;
    int window_width;
    int window_height;
    int window_color;

    SystemData();
    ~SystemData();
public:
    static SystemData* getInstance();
    int getWindowWidth();
    int getWindowHeight();
    int getWindowColor();
    bool getDebugMode();
};