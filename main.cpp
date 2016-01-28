#include "DxLib.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    //---- Initial processing
    SetGraphMode(1280, 720, 32);
    ChangeWindowMode(TRUE);
    SetWindowText("GameName");
    if (DxLib_Init() == -1)	{ return -1; }
    if (SetDrawScreen(DX_SCREEN_BACK) != 0) { return -1; }

    //---- Debug console
    AllocConsole();
    FILE* fp;
    freopen_s(&fp, "CONOUT$", "w", stdout);
    freopen_s(&fp, "CONIN$", "r", stdin);

    //---- End processing
    WaitKey();
    DxLib_End();
    return 0;
}