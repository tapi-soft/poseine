#include "DxLib.h"
#include "GameManager.h"
#include "data/SystemData.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    //---- Initial processing
    SetGraphMode(
        SystemData::getInstance()->getWindowWidth(),
        SystemData::getInstance()->getWindowHeight(),
        SystemData::getInstance()->getWindowColor());
    ChangeWindowMode(TRUE);
    SetWindowText("GameName");

    if (DxLib_Init() == -1)	{ return -1; }
    if (SetDrawScreen(DX_SCREEN_BACK) != 0) { return -1; }
    //SetDrawMode(DX_DRAWMODE_BILINEAR);
    //---- Debug console
    AllocConsole();
    FILE* fp;
    freopen_s(&fp, "CONOUT$", "w", stdout);
    freopen_s(&fp, "CONIN$", "r", stdin);

    //---- Game Start
    GameManager game_manager;
    game_manager.start();

    //---- End processing
    DxLib_End();
    return 0;
}