#include "BacklogDraw.h"

//---------------------------------------------------------------------
BacklogDraw::BacklogDraw(GameState* state)
{
    loadImage();
}
//---------------------------------------------------------------------
BacklogDraw::~BacklogDraw()
{

}
//---------------------------------------------------------------------
void BacklogDraw::update()
{
    DrawGraph(0, 0, image_window, TRUE);
}
//---------------------------------------------------------------------
void BacklogDraw::loadImage()
{
    image_window = LoadGraph("image/main/backlog_window.png");
}