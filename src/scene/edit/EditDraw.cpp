//---------------------------------------------------------------------
#include "EditDraw.h"
#include "DxLib.h"

//---------------------------------------------------------------------
EditDraw::EditDraw(GameState* state)
{
    loadImage();
}
//---------------------------------------------------------------------
EditDraw::~EditDraw()
{

}
//---------------------------------------------------------------------
void EditDraw::loadImage()
{
    image_back = LoadGraph("image/edit/back.png");
}
//---------------------------------------------------------------------
void EditDraw::update()
{
    DrawGraph(0, 0, image_back, TRUE);

    // edit
    // preview
    ScenarioDraw::draw(1, 428, 0, 0.665625);
    // timeline
    // scenario select
}