//---------------------------------------------------------------------
// InputState
//---------------------------------------------------------------------
#pragma once
#include "DxLib.h"

class InputState
{
public:
    static const int KEY_MAX = 256;
    static const int CLICK_MAX = 8;

private:
    int key[KEY_MAX];         // キー入力状態
    int point_x;              // マウスの座標x
    int point_y;              // マウスの座標y
    int click[CLICK_MAX];     // クリック情報
    int pre_click[CLICK_MAX]; // 前フレームのクリック情報
    int wheel;                // マウス回転量

    void keyInit();                  // キー入力状態初期化
    void mouseInit();                // マウス入力状態初期化
    void keyUpdate();                // キー入力状態更新
    void mouseUpdate();              // マウス入力状態更新

public:
    InputState();
    ~InputState();
    void update();
    int getKey(int);
    int getMouseWheel();        // マウスホイール回転量取得
    int getPointX();            // 座標xを取得
    int getPointY();            // 座標yを取得
    int getClick(int);          // クリック情報取得
    int getLeftClick();
    int getRightClick();
    int getPreClick(int);       // 前フレームクリック情報取得
    bool isRereaseClick(int);   // 指定クリックが離されたか
};