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
    if (input_state->getKey(KEY_INPUT_RETURN) == 1) {
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
    if (EditData::isEditButtonPlusCharaPos(mousex, mousey)) {
        int scenario_num = edit_state->getScenarioNum();
        int num = AllScenarioData::getInstance()->getCharaNum(scenario_num);
        if (num < ScenarioData::CHARA_NUM_MAX) {
            AllScenarioData::getInstance()->setCharaNum(scenario_num, num + 1);
            AllScenarioData::getInstance()->setCharaImage(scenario_num, num + 1, 1);
            AllScenarioData::getInstance()->setCharaPos(scenario_num, num + 1, 5);
            AllScenarioData::getInstance()->setCharaFace(scenario_num, num + 1, 1);
        }
    }
    if (EditData::isEditButtonMinusCharaPos(mousex, mousey)) {
        int scenario_num = edit_state->getScenarioNum();
        int num = AllScenarioData::getInstance()->getCharaNum(scenario_num);
        if (num > 0) {
            AllScenarioData::getInstance()->setCharaNum(scenario_num, num - 1);
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
    if (EditData::isEditButtonPrevBackimagePos(mousex, mousey)) {
        backimageButtonPrevClickProcess();
    }
    if (EditData::isEditButtonNextBackimagePos(mousex, mousey)) {
        backimageButtonNextClickProcess();
    }

    if (EditData::isThumbnailButtonAddPos(mousex, mousey)) {
        int new_scenario_num = AllScenarioData::getInstance()->searchEmptyPos();
        int scenario_num = edit_state->getScenarioNum();

        AllScenarioData::getInstance()->setNext(new_scenario_num, AllScenarioData::getInstance()->getNext(scenario_num));
        AllScenarioData::getInstance()->setPrev(new_scenario_num, scenario_num);
        if (AllScenarioData::getInstance()->getNext(scenario_num) != 0) {
            AllScenarioData::getInstance()->setPrev(AllScenarioData::getInstance()->getNext(scenario_num), new_scenario_num);
        }
        AllScenarioData::getInstance()->setNext(scenario_num, new_scenario_num);
        AllScenarioData::getInstance()->setBackimage(new_scenario_num, 1);
        edit_state->selectThumbnail(1);
    }
    if (EditData::isThumbnailButtonDelPos(mousex, mousey)) {
        int scenario_num = edit_state->getScenarioNum();
        int prev_scenario_num = AllScenarioData::getInstance()->getPrev(scenario_num);
        int next_scenario_num = AllScenarioData::getInstance()->getNext(scenario_num);

        if (prev_scenario_num == 0) {
            edit_state->selectThumbnail(1);
        }
        else {
            edit_state->selectThumbnail(-1);
        }
        AllScenarioData::getInstance()->setPrev(next_scenario_num, prev_scenario_num);
        AllScenarioData::getInstance()->setNext(prev_scenario_num, next_scenario_num);
        AllScenarioData::getInstance()->deleteData(scenario_num);
    }
}
//---------------------------------------------------------------------
void EditManager::rightClickProcess()
{

}
//---------------------------------------------------------------------
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
//---------------------------------------------------------------------
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
//---------------------------------------------------------------------
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
//---------------------------------------------------------------------
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
//---------------------------------------------------------------------
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
//---------------------------------------------------------------------
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
//---------------------------------------------------------------------
void EditManager::backimageButtonPrevClickProcess()
{
    int scenario_num = edit_state->getScenarioNum();
    int image = AllScenarioData::getInstance()->getBackimage(scenario_num);
    int image_max = AllScenarioData::getInstance()->getBackimageMax();

    if (image == 1) {
        AllScenarioData::getInstance()->setBackimage(scenario_num, image_max);
    }
    else {
        AllScenarioData::getInstance()->setBackimage(scenario_num, image - 1);
    }
}
//---------------------------------------------------------------------
void EditManager::backimageButtonNextClickProcess()
{
    int scenario_num = edit_state->getScenarioNum();
    int image = AllScenarioData::getInstance()->getBackimage(scenario_num);
    int image_max = AllScenarioData::getInstance()->getBackimageMax();

    if (image == image_max) {
        AllScenarioData::getInstance()->setBackimage(scenario_num, 1);
    }
    else {
        AllScenarioData::getInstance()->setBackimage(scenario_num, image + 1);
    }
}