#pragma once

class SaveloadState
{
public:
    static const int MODE_SAVE;
    static const int MODE_LOAD;
private:
    int mode;
public:
    SaveloadState();
    ~SaveloadState();
    void update();
    void setMode(int);
    int getMode();
};