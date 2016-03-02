//---------------------------------------------------------------------
#include "EditState.h"

//---------------------------------------------------------------------
EditState::EditState()
{
    scenario_num = 3;
    input_active = 0;
    select_chara = 0;

    SetKeyInputStringColor(
        GetColor(0, 0, 0),       // ���͕�����̐F
        GetColor(0, 0, 0),       // �h�l�d��g�p���̃J�[�\���̐F
        GetColor(255, 255, 255), // �h�l�d�g�p���̓��͕�����̎���̐F
        GetColor(255, 255, 255), // �h�l�d�g�p���̃J�[�\���̐F
        GetColor(0, 0, 0),       // �h�l�d�g�p���̕ϊ�������̉���
        GetColor(255, 255, 255), // �h�l�d�g�p���̑I��Ώۂ̕ϊ���╶����̐F
        GetColor(0, 0, 0),       // �h�l�d�g�p���̓��̓��[�h������̐F(�w�S�p�Ђ炪�ȁx��)
        GetColor(255, 0, 0),     // ���͕�����̉��̐F
        GetColor(0, 255, 0),     // �h�l�d�g�p���̑I��Ώۂ̕ϊ���╶����̉��̐F
        GetColor(255, 0, 0),     // �h�l�d�g�p���̓��̓��[�h������̉��̐F
        GetColor(255, 0, 0),     // �h�l�d�g�p���̕ϊ����E�C���h�E�̉��̐F
        GetColor(255, 0, 0),     // �h�l�d�g�p���̕ϊ����E�C���h�E�̉��n�̐F
        GetColor(51, 153, 255),  // ���͕�����̑I�𕔕�( SHIFT�L�[�������Ȃ��獶�E�L�[�őI�� )�̎���̐F
        GetColor(255, 255, 255), // ���͕�����̑I�𕔕�( SHIFT�L�[�������Ȃ��獶�E�L�[�őI�� )�̐F
        GetColor(51, 153, 5)     // ���͕�����̑I�𕔕�( SHIFT�L�[�������Ȃ��獶�E�L�[�őI�� )�̉��̐F
        //GetColor(255, 0, 0),   // �h�l�d�g�p���̓��͕�����̐F
        //GetColor(255, 0, 0));  // �h�l�d�g�p���̓��͕�����̉��̐F
        );
}
//---------------------------------------------------------------------
EditState::~EditState()
{

}
//---------------------------------------------------------------------
void EditState::update()
{
    if (CheckKeyInput(input_handl) == 1) {
        offInputActive();
    }
}
//---------------------------------------------------------------------
void EditState::selectThumbnail(int n)
{
    int num = scenario_num;
    int prev1 = AllScenarioData::getInstance()->getPrev(num);
    int prev2 = AllScenarioData::getInstance()->getPrev(prev1);
    int next1 = AllScenarioData::getInstance()->getNext(num);
    int next2 = AllScenarioData::getInstance()->getNext(next1);
    if (next1 == 0) { next2 = 0; }
    if (prev1 == 0) { prev2 = 0; }
    if (n == 0 && num != 0) { scenario_num = num; }
    if (n == -1 && prev1 != 0) { scenario_num = prev1; }
    if (n == -2 && prev2 != 0) { scenario_num = prev2; }
    if (n == 1 && next1 != 0) { scenario_num = next1; }
    if (n == 2 && next2 != 0) { scenario_num = next2; }

    setSelectChara(0);
}
//---------------------------------------------------------------------
void EditState::offInputActive() {
    if (input_active == 0) return;
    char name[256];
    GetKeyInputString(name, input_handl);
    DeleteKeyInput(input_handl);
    input_active = 0;

    if (input_str == "name") {
        AllScenarioData::getInstance()->setName(scenario_num, name);
    }
    if (input_str == "text1") {
        AllScenarioData::getInstance()->setText1(scenario_num, name);
    }
    if (input_str == "text2") {
        AllScenarioData::getInstance()->setText2(scenario_num, name);
    }
    if (input_str == "text3") {
        AllScenarioData::getInstance()->setText3(scenario_num, name);
    }
}
//---------------------------------------------------------------------
void EditState::onInputActive(std::string str) {
    input_handl = MakeKeyInput(100, TRUE, FALSE, FALSE);
    input_active = 1;
    input_str = str;
    if (str == "name") {
        SetKeyInputString(AllScenarioData::getInstance()->getName(scenario_num).c_str(), input_handl);
    }
    if (str == "text1") {
        SetKeyInputString(AllScenarioData::getInstance()->getText1(scenario_num).c_str(), input_handl);
    }
    if (str == "text2") {
        SetKeyInputString(AllScenarioData::getInstance()->getText2(scenario_num).c_str(), input_handl);
    }
    if (str == "text3") {
        SetKeyInputString(AllScenarioData::getInstance()->getText3(scenario_num).c_str(), input_handl);
    }
}
//---------------------------------------------------------------------
void EditState::jumpThumbnail(int num)
{
    scenario_num = num;
    setSelectChara(0);
}
//---------------------------------------------------------------------
void EditState::setSelectChara(int n) { select_chara = n; }
//---------------------------------------------------------------------
int EditState::getScenarioNum() { return scenario_num; }
int EditState::getInputHandl() { return input_handl; }
int EditState::getInputActive() { return input_active; }
std::string EditState::getInputStr() { return input_str; }
int EditState::getSelectChara() { return select_chara; }