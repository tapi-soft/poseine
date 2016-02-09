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
    int key[KEY_MAX];         // �L�[���͏��
    int point_x;              // �}�E�X�̍��Wx
    int point_y;              // �}�E�X�̍��Wy
    int click[CLICK_MAX];     // �N���b�N���
    int pre_click[CLICK_MAX]; // �O�t���[���̃N���b�N���
    int wheel;                // �}�E�X��]��

    void keyInit();                  // �L�[���͏�ԏ�����
    void mouseInit();                // �}�E�X���͏�ԏ�����
    void keyUpdate();                // �L�[���͏�ԍX�V
    void mouseUpdate();              // �}�E�X���͏�ԍX�V

public:
    InputState();
    ~InputState();
    void update();
    int getKey(int);
    int getMouseWheel();        // �}�E�X�z�C�[����]�ʎ擾
    int getPointX();            // ���Wx���擾
    int getPointY();            // ���Wy���擾
    int getClick(int);          // �N���b�N���擾
    int getLeftClick();
    int getRightClick();
    int getPreClick(int);       // �O�t���[���N���b�N���擾
    bool isRereaseClick(int);   // �w��N���b�N�������ꂽ��
};