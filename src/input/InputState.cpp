//---------------------------------------------------------------------
// InputState
//---------------------------------------------------------------------
#include "InputState.h"

//---------------------------------------------------------------------
InputState::InputState()
{
    keyInit();
    mouseInit();
}
//---------------------------------------------------------------------
InputState::~InputState()
{
}
//---------------------------------------------------------------------
void InputState::keyInit()
{
    for (int i = 0; i < KEY_MAX; i++) {
        key[i] = 0;
    }
}
//---------------------------------------------------------------------
void InputState::mouseInit()
{
    point_x = 0;
    point_y = 0;
    wheel = GetMouseWheelRotVol();
    for (int i = 0; i < CLICK_MAX; i++) {
        click[i] = 0;
    }
}
//---------------------------------------------------------------------
void InputState::update()
{
    keyUpdate();
    mouseUpdate();
}
//---------------------------------------------------------------------
void InputState::keyUpdate()
{
    char tmp_key[KEY_MAX];

    GetHitKeyStateAll(tmp_key);
    for (int i = 0; i < KEY_MAX; i++) {
        key[i] = (tmp_key[i]) ? key[i] + 1 : 0;
    }
}
//---------------------------------------------------------------------
void InputState::mouseUpdate()
{
    // �}�E�X�z�C�[��
    wheel = GetMouseWheelRotVol();

    // �}�E�X�̍��W
    if (GetMousePoint(&point_x, &point_y) == -1) {
        return;
    }
    // �O�t���[���̃N���b�N���
    for (int i = 0; i < CLICK_MAX; i++) {
        pre_click[i] = click[i];
    }
    // �}�E�X�̃N���b�N���
    int MouseInput = GetMouseInput();
    for (int i = 0; i < CLICK_MAX; i++) {
        click[i] = (MouseInput & 1 << i) ? click[i] + 1 : 0;
    }
}
//---------------------------------------------------------------------
int InputState::getKey(int n) { return key[n]; }
int InputState::getMouseWheel() { return wheel; }
int InputState::getPointX() { return point_x; }
int InputState::getPointY() { return point_y; }
int InputState::getClick(int n) { return click[n - 1]; }
int InputState::getPreClick(int n) { return pre_click[n - 1]; }
bool InputState::isRereaseClick(int n) { return (click[n - 1] == 0 && pre_click[n - 1] >= 1); }