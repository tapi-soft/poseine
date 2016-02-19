//---------------------------------------------------------------------
#include "EditDraw.h"
#include "DxLib.h"

//---------------------------------------------------------------------
EditDraw::EditDraw(GameState* state)
{
    edit_state = state->getSceneState()->getEditState();

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

    //---- edit
    //---- preview
    ScenarioDraw::drawImage(edit_state->getScenarioNum(), 428, 0, 0.665625);

    //---- timeline
    //---- scenario select
    int num = edit_state->getScenarioNum();
    int prev1 = AllScenarioData::getInstance()->getPrev(num);
    int prev2 = AllScenarioData::getInstance()->getPrev(prev1);
    int next1 = AllScenarioData::getInstance()->getNext(num);
    int next2 = AllScenarioData::getInstance()->getNext(next1);

    if (prev2 != 0) { ScenarioDraw::drawImage(prev2, EditData::getThumbnailPosX(-2), EditData::getThumbnailPosY(-2), 0.1); }
    if (prev1 != 0) { ScenarioDraw::drawImage(prev1, EditData::getThumbnailPosX(-1), EditData::getThumbnailPosY(-1), 0.1); }
    if (num != 0)   { ScenarioDraw::drawImage(num, EditData::getThumbnailPosX(0), EditData::getThumbnailPosY(0), 0.1); }
    if (next1 != 0) { ScenarioDraw::drawImage(next1, EditData::getThumbnailPosX(1), EditData::getThumbnailPosY(1), 0.1); }
    if (next2 != 0) { ScenarioDraw::drawImage(next2, EditData::getThumbnailPosX(2), EditData::getThumbnailPosY(2), 0.1); }
}