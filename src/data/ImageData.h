#pragma once
#include "DxLib.h"

class ImageData
{
private:
    int image_back[100];
    int image_chara[100];

    ImageData();
    ~ImageData();
    void loadImage();
public:
    static ImageData* getInstance();

    int getImageBack(int);
    int getImageChara(int);
};