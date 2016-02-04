//---------------------------------------------------------------------
#include "ImageData.h"

//---------------------------------------------------------------------
ImageData::ImageData()
{
    loadImage();
}
//---------------------------------------------------------------------
ImageData::~ImageData()
{

}
//---------------------------------------------------------------------
void ImageData::loadImage()
{
    image_back[1] = LoadGraph("image/back/back_1.png");
    image_back[2] = LoadGraph("image/back/back_2.png");
    image_chara[1] = LoadGraph("image/chara/chara_1.png");
    image_chara[2] = LoadGraph("image/chara/chara_2.png");
    image_chara[3] = LoadGraph("image/chara/chara_3.png");
    image_chara[4] = LoadGraph("image/chara/chara_4.png");
    image_chara[5] = LoadGraph("image/chara/chara_5.png");
}
//---------------------------------------------------------------------
ImageData* ImageData::getInstance()
{
    static ImageData instance;
    return &instance;
}
//---------------------------------------------------------------------
int ImageData::getImageBack(int n) { return image_back[n]; }
int ImageData::getImageChara(int n) { return image_chara[n]; }