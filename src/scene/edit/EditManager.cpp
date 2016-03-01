//---------------------------------------------------------------------
#include "EditManager.h"
#include "DxLib.h"

//---------------------------------------------------------------------
EditManager::EditManager(GameState* state)
{
    edit_state = state->getSceneState()->getEditState();
    input_state = state->getInputState();
    scene_state = state->getSceneState();
}
//---------------------------------------------------------------------
EditManager::~EditManager()
{

}
//---------------------------------------------------------------------
void EditManager::update()
{

    if (input_state->getLeftClick() == 1) {
        leftClickProcess();
    }
    if (input_state->getKey(KEY_INPUT_RETURN)) {
        edit_state->offInputActive();
        AllScenarioData::getInstance()->saveData();
    }
}
//---------------------------------------------------------------------
void EditManager::leftClickProcess()
{
    int mousex = input_state->getPointX();
    int mousey = input_state->getPointY();

    for (int n = -2; n <= 2; n++) {
        if (EditData::isThumbnailPos(n, mousex, mousey)) {
            edit_state->selectThumbnail(n);
        }
    }
    if (EditData::isEditNamePos(mousex, mousey)) {
        edit_state->onInputActive("name");
        SetActiveKeyInput(edit_state->getInputHandl());
    }
    if (EditData::isEditTextPos(1, mousex, mousey)) {
        edit_state->onInputActive("text1");
        SetActiveKeyInput(edit_state->getInputHandl());
    }
    if (EditData::isEditTextPos(2, mousex, mousey)) {
        edit_state->onInputActive("text2");
        SetActiveKeyInput(edit_state->getInputHandl());
    }
    if (EditData::isEditTextPos(3, mousex, mousey)) {
        edit_state->onInputActive("text3");
        SetActiveKeyInput(edit_state->getInputHandl());
    }

    for (int i = 0; i < AllScenarioData::getInstance()->getCharaNum(edit_state->getScenarioNum()); i++) {
        if (EditData::isEditCharaButtonPos(i, mousex, mousey)) {
            edit_state->setSelectChara(i);
        }
    }

    if (EditData::isEditButtonPrevCharaPosPos(mousex, mousey)) {
        charaPosButtonPrevClickProcess();
    }
    if (EditData::isEditButtonNextCharaPosPos(mousex, mousey)) {
        charaPosButtonNextClickProcess();
    }
    if (EditData::isEditButtonPrevCharaImagePos(mousex, mousey)) {
        charaImageButtonPrevClickProcess();
    }
    if (EditData::isEditButtonNextCharaImagePos(mousex, mousey)) {
        charaImageButtonNextClickProcess();
    }
    if (EditData::isEditButtonPrevCharaFacePos(mousex, mousey)) {
        charaFaceButtonPrevClickProcess();
    }
    if (EditData::isEditButtonNextCharaFacePos(mousex, mousey)) {
        charaFaceButtonNextClickProcess();
    }
}
//---------------------------------------------------------------------
void EditManager::rightClickProcess()
{

}

void EditManager::charaPosButtonPrevClickProcess()
{
    int scenario_num = edit_state->getScenarioNum();
    int chara_num = edit_state->getSelectChara() + 1;
    int pos = AllScenarioData::getInstance()->getCharaPos(scenario_num, chara_num);
    int pos_max = AllScenarioData::getInstance()->getCharaPosMax();

    if (pos == 1) {
        AllScenarioData::getInstance()->setCharaPos(scenario_num, chara_num, pos_max);
    }
    else {
        AllScenarioData::getInstance()->setCharaPos(scenario_num, chara_num, pos - 1);
    }
}
void EditManager::charaPosButtonNextClickProcess()
{
    int scenario_num = edit_state->getScenarioNum();
    int chara_num = edit_state->getSelectChara() + 1;
    int pos = AllScenarioData::getInstance()->getCharaPos(scenario_num, chara_num);
    int pos_max = AllScenarioData::getInstance()->getCharaPosMax();

    if (pos == pos_max) {
        AllScenarioData::getInstance()->setCharaPos(scenario_num, chara_num, 1);
    }
    else {
        AllScenarioData::getInstance()->setCharaPos(scenario_num, chara_num, pos + 1);
    }
}
void EditManager::charaImageButtonPrevClickProcess()
{
    int scenario_num = edit_state->getScenarioNum();
    int chara_num = edit_state->getSelectChara() + 1;
    int image = AllScenarioData::getInstance()->getCharaImage(scenario_num, chara_num);
    int image_max = AllScenarioData::getInstance()->getCharaImageMax();

    if (image == 1) {
        AllScenarioData::getInstance()->setCharaImage(scenario_num, chara_num, image_max);
    }
    else {
        AllScenarioData::getInstance()->setCharaImage(scenario_num, chara_num, image - 1);
    }
}
void EditManager::charaImageButtonNextClickProcess()
{
    int scenario_num = edit_state->getScenarioNum();
    int chara_num = edit_state->getSelectChara() + 1;
    int image = AllScenarioData::getInstance()->getCharaImage(scenario_num, chara_num);
    int image_max = AllScenarioData::getInstance()->getCharaImageMax();

    if (image == image_max) {
        AllScenarioData::getInstance()->setCharaImage(scenario_num, chara_num, 1);
    }
    else {
        AllScenarioData::getInstance()->setCharaImage(scenario_num, chara_num, image + 1);
    }
}
void EditManager::charaFaceButtonPrevClickProcess()
{
    int scenario_num = edit_state->getScenarioNum();
    int chara_num = edit_state->getSelectChara() + 1;
    int face = AllScenarioData::getInstance()->getCharaFace(scenario_num, chara_num);
    int face_max = AllScenarioData::getInstance()->getCharaFaceMax();

    if (face == 1) {
        AllScenarioData::getInstance()->setCharaFace(scenario_num, chara_num, face_max);
    }
    else {
        AllScenarioData::getInstance()->setCharaPos(scenario_num, chara_num, face - 1);
    }
}
void EditManager::charaFaceButtonNextClickProcess()
{
    int scenario_num = edit_state->getScenarioNum();
    int chara_num = edit_state->getSelectChara() + 1;
    int face = AllScenarioData::getInstance()->getCharaFace(scenario_num, chara_num);
    int face_max = AllScenarioData::getInstance()->getCharaFaceMax();

    if (face == face_max) {
        AllScenarioData::getInstance()->setCharaFace(scenario_num, chara_num, 1);
    }
    else {
        AllScenarioData::getInstance()->setCharaPos(scenario_num, chara_num, face + 1);
    }
}