#pragma once

class SaveloadState
{
public:
    static const int MODE_SAVE;
    static const int MODE_LOAD;
private:
    int mode;
    int page;
public:
    SaveloadState();
    ~SaveloadState();
    void update();

    void setMode(int);
    void setPage(int);

    int getMode();
    int getPage();
};