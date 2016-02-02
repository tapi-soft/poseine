#include "SaveloadDraw.h"

//---------------------------------------------------------------------
SaveloadDraw::SaveloadDraw(GameState* state)
{
    loadImage();
}
//---------------------------------------------------------------------
SaveloadDraw::~SaveloadDraw()
{

}
//---------------------------------------------------------------------
void SaveloadDraw::loadImage()
{
    image_back = LoadGraph("image/saveload/back.png");
}
//---------------------------------------------------------------------
void SaveloadDraw::update()
{
    DrawGraph(0, 0, image_back, TRUE);
}