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

    if (prev2 != 0) { ScenarioDraw::drawImage(prev2, 500, 625, 0.1); }
    if (prev1 != 0) { ScenarioDraw::drawImage(prev1, 650, 625, 0.1); }
    ScenarioDraw::drawImage(num, 800, 625, 0.1);
    if (next1 != 0) { ScenarioDraw::drawImage(next1, 950, 625, 0.1); }
    if (next2 != 0) { ScenarioDraw::drawImage(next2, 1100, 625, 0.1); }
}