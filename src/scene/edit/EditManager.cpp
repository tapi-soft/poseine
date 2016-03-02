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
    if (input_state->getKey(KEY_INPUT_F1) == 1) {
        AllScenarioData::getInstance()->saveData();
    }
}
//---------------------------------------------------------------------
void EditManager::leftClickProcess()
{
    int mousex = input_state->getPointX();
    int mousey = input_state->getPointY();

    //---- Thumbnail
    thumbnailLeftClickProcess();

    //---- 
    if (EditData::isEditNamePos(mousex, mousey)) {
        edit_state->onInputActive("name");
        SetActiveKeyInput(edit_state->getInputHandl());
    }
    else if (EditData::isEditTextPos(1, mousex, mousey)) {
        edit_state->onInputActive("text1");
        SetActiveKeyInput(edit_state->getInputHandl());
    }
    else if (EditData::isEditTextPos(2, mousex, mousey)) {
        edit_state->onInputActive("text2");
        SetActiveKeyInput(edit_state->getInputHandl());
    }
    else if (EditData::isEditTextPos(3, mousex, mousey)) {
        edit_state->onInputActive("text3");
        SetActiveKeyInput(edit_state->getInputHandl());
    }
    else {
        edit_state->offInputActive();
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
    if (EditData::isEditButtonPrevFadePos(mousex, mousey)) {
        fadeButtonPrevClickProcess();
    }
    if (EditData::isEditButtonNextFadePos(mousex, mousey)) {
        fadeButtonNextClickProcess();
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
        AllScenarioData::getInstance()->setBackimage(new_scenario_num, AllScenarioData::getInstance()->getBackimage(scenario_num));
        AllScenarioData::getInstance()->setCharaNum(new_scenario_num, AllScenarioData::getInstance()->getCharaNum(scenario_num));
        for (int i = 1; i <= AllScenarioData::getInstance()->getCharaNum(scenario_num); i++) {
            AllScenarioData::getInstance()->setCharaPos(new_scenario_num, i, AllScenarioData::getInstance()->getCharaPos(scenario_num, i));
            AllScenarioData::getInstance()->setCharaImage(new_scenario_num, i, AllScenarioData::getInstance()->getCharaImage(scenario_num, i));
            AllScenarioData::getInstance()->setCharaFace(new_scenario_num, i, AllScenarioData::getInstance()->getCharaFace(scenario_num, i));
        }
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
void EditManager::thumbnailLeftClickProcess()
{
    int mousex = input_state->getPointX();
    int mousey = input_state->getPointY();
    int num = edit_state->getScenarioNum();
    int next1 = AllScenarioData::getInstance()->getNext(num);
    int next2 = AllScenarioData::getInstance()->getNext(next1);

    for (int n = -2; n <= 2; n++) {
        // select1
        if (n == 1 && AllScenarioData::getInstance()->getSelectNum(num) == 2) {
            int select1_num = AllScenarioData::getInstance()->getSelectNext(num, 1);
            int select2_num = AllScenarioData::getInstance()->getSelectNext(num, 2);

            if (EditData::isThumbnailSelectPos(n, 1, mousex, mousey)) {
                edit_state->jumpThumbnail(select1_num);
            }
            if (EditData::isThumbnailSelectPos(n, 2, mousex, mousey)) {
                edit_state->jumpThumbnail(select2_num);
            }
        }
        // select2
        else if (n == 2 && AllScenarioData::getInstance()->getSelectNum(next1) == 2) {
            int select1_num = AllScenarioData::getInstance()->getSelectNext(next1, 1);
            int select2_num = AllScenarioData::getInstance()->getSelectNext(next1, 2);

            if (EditData::isThumbnailSelectPos(n, 1, mousex, mousey)) {
                edit_state->jumpThumbnail(select1_num);
            }
            if (EditData::isThumbnailSelectPos(n, 2, mousex, mousey)) {
                edit_state->jumpThumbnail(select2_num);
            }
        }
        else if (n == 2 && AllScenarioData::getInstance()->getSelectNum(num) == 2) {

        }
        else {
            if (EditData::isThumbnailPos(n, mousex, mousey)) {
                edit_state->selectThumbnail(n);
            }
        }
    }
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
//---------------------------------------------------------------------
void EditManager::fadeButtonPrevClickProcess()
{
    int scenario_num = edit_state->getScenarioNum();
    int fade = AllScenarioData::getInstance()->getFade(scenario_num);
    int fade_max = AllScenarioData::getInstance()->getFadeMax();

    if (fade == 0) {
        AllScenarioData::getInstance()->setFade(scenario_num, fade_max);
    }
    else {
        AllScenarioData::getInstance()->setFade(scenario_num, fade - 1);
    }
}
//---------------------------------------------------------------------
void EditManager::fadeButtonNextClickProcess()
{
    int scenario_num = edit_state->getScenarioNum();
    int fade = AllScenarioData::getInstance()->getFade(scenario_num);
    int fade_max = AllScenarioData::getInstance()->getFadeMax();

    if (fade == fade_max) {
        AllScenarioData::getInstance()->setFade(scenario_num, 0);
    }
    else {
        AllScenarioData::getInstance()->setFade(scenario_num, fade + 1);
    }
}