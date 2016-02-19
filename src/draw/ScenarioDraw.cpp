//---------------------------------------------------------------------
#include "ScenarioDraw.h"
#include "DxLib.h"

//---------------------------------------------------------------------
ScenarioDraw::ScenarioDraw()
{

}
//---------------------------------------------------------------------
ScenarioDraw::~ScenarioDraw()
{

}
//---------------------------------------------------------------------
void ScenarioDraw::draw(int n, int x, int y, double rate)
{
    drawBack(n, x, y, rate);
}
//---------------------------------------------------------------------
void ScenarioDraw::drawBack(int n, int x, int y, double rate)
{
    DrawExtendGraph(
        x,
        y,
        (int)(x + 1280 * rate),
        (int)(y + 720 * rate),
        ImageData::getInstance()->getImageBack(1),
        TRUE);
}