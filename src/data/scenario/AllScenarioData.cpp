//---------------------------------------------------------------------
#include "AllScenarioData.h"

//---------------------------------------------------------------------
ScenarioData* AllScenarioData::scenario_data[10000];

//---------------------------------------------------------------------
AllScenarioData::AllScenarioData()
{
    for (int i = 0; i < 10000; i++) {
        scenario_data[i] = new ScenarioData();
    }
    loadData();
}
//---------------------------------------------------------------------
AllScenarioData::~AllScenarioData()
{

}
//---------------------------------------------------------------------
void AllScenarioData::loadData()
{
    puts("�V�i���I�f�[�^�����[�h���܂�");
    char str[1024];
    std::string s;
    std::stringstream ss;
    int num;
    int fp = FileRead_open("scenario/scenario_1.dat");
    // �t�@�C���ǂݍ��ݎ��s
    if (fp == 0) {
        puts("�V�i���I�f�[�^�̓ǂݍ��݂Ɏ��s���܂���");
        return;
    }
    // �t�@�C���ǂݍ��ݏ���
    while (FileRead_gets(str, 256, fp) != -1) {
        ss.clear();
        ss.str(str);
        ss >> s;
        //---- �ԍ�
        if (s == "#NUM") {
            ss >> s;
            num = atoi(s.c_str());
            scenario_data[num]->setNum(num);
        }
        //---- ���O
        else if (s == "#NAME") {
            ss >> s;
            scenario_data[num]->setName(s);
        }
        //---- �e�L�X�g1
        else if (s == "#TEXT1") {
            ss >> s;
            scenario_data[num]->setText1(s);
        }
        //---- �e�L�X�g2
        else if (s == "#TEXT2") {
            ss >> s;
            scenario_data[num]->setText2(s);
        }
        //---- �e�L�X�g3
        else if (s == "#TEXT3") {
            ss >> s;
            scenario_data[num]->setText3(s);
        }
        //---- ��
        else if (s == "#NEXT") {
            ss >> s;
            scenario_data[num]->setNext(atoi(s.c_str()));
        }
        //---- �O
        else if (s == "#PRE") {
            ss >> s;
            scenario_data[num]->setPrev(atoi(s.c_str()));
        }
        //---- �L����
        else if (s == "#CHARA") {
            // �L������
            int n = scenario_data[num]->getCharaNum() + 1;
            scenario_data[num]->setCharaNum(n);
            // �L�����ʒu
            ss >> s;
            scenario_data[num]->setCharaPos(n, atoi(s.c_str()));
            // �L�����摜
            ss >> s;
            scenario_data[num]->setCharaImage(n, atoi(s.c_str()));
            // �L������
            ss >> s;
            scenario_data[num]->setCharaFace(n, atoi(s.c_str()));
        }
        //---- �w�i
        else if (s == "#BACK") {
            ss >> s;
            scenario_data[num]->setBackimage(atoi(s.c_str()));
        }
        //---- �t�F�[�h�̎��
        else if (s == "#FADE") {
            ss >> s;
            scenario_data[num]->setFade(atoi(s.c_str()));
        }
        //---- �I������
        else if (s == "#SELECTNUM") {
            ss >> s;
            scenario_data[num]->setSelectNum(atoi(s.c_str()));
        }
        //---- �I����1
        else if (s == "#SELECT") {
            // �ԍ�
            ss >> s;
            int select_num = atoi(s.c_str());
            // �W�����v��
            ss >> s;
            scenario_data[num]->setSelectNext(select_num, atoi(s.c_str()));
            // �e�L�X�g
            ss >> s;
            scenario_data[num]->setSelectText(select_num, s);
        }
    }
    FileRead_close(fp);
    puts("�V�i���I�f�[�^�̓ǂݍ��݂ɐ������܂���");
}
//---------------------------------------------------------------------
AllScenarioData* AllScenarioData::getInstance()
{
    static AllScenarioData instance;
    return &instance;
}
//---------------------------------------------------------------------
std::string AllScenarioData::getName(int n)
{
    return scenario_data[n]->getName();
}
//---------------------------------------------------------------------
std::string AllScenarioData::getText(int n)
{
    return getText1(n) + getText2(n) + getText3(n);
}
//---------------------------------------------------------------------
std::string AllScenarioData::getText1(int n)
{
    return scenario_data[n]->getText1();
}
//---------------------------------------------------------------------
std::string AllScenarioData::getText2(int n)
{
    return scenario_data[n]->getText2();
}
//---------------------------------------------------------------------
std::string AllScenarioData::getText3(int n)
{
    return scenario_data[n]->getText3();
}
//---------------------------------------------------------------------
int AllScenarioData::getText1Length(int n)
{
    return scenario_data[n]->getText1().length();
}
//---------------------------------------------------------------------
int AllScenarioData::getText2Length(int n)
{
    return scenario_data[n]->getText2().length();
}
//---------------------------------------------------------------------
int AllScenarioData::getText3Length(int n)
{
    return scenario_data[n]->getText3().length();
}
//---------------------------------------------------------------------
int AllScenarioData::getNext(int n)
{
    return scenario_data[n]->getNext();
}
//---------------------------------------------------------------------
int AllScenarioData::getPrev(int n)
{
    return scenario_data[n]->getPrev();
}
//---------------------------------------------------------------------
int AllScenarioData::getBackimage(int n)
{
    return scenario_data[n]->getBackimage();
}
//---------------------------------------------------------------------
int AllScenarioData::getCharaNum(int n)
{
    return scenario_data[n]->getCharaNum();
}
//---------------------------------------------------------------------
int AllScenarioData::getCharaImage(int scenario_num, int chara_num)
{
    return scenario_data[scenario_num]->getCharaImage(chara_num);
}
//---------------------------------------------------------------------
int AllScenarioData::getCharaPos(int scenario_num, int chara_num)
{
    return scenario_data[scenario_num]->getCharaPos(chara_num);
}
//---------------------------------------------------------------------
int AllScenarioData::getCharaFace(int scenario_num, int chara_num)
{
    return scenario_data[scenario_num]->getCharaFace(chara_num);
}
//---------------------------------------------------------------------
int AllScenarioData::getSelectNum(int scenario_num)
{
    return scenario_data[scenario_num]->getSelectNum();
}
//---------------------------------------------------------------------
int AllScenarioData::getSelectNext(int scenario_num, int select_num)
{
    return scenario_data[scenario_num]->getSelectNext(select_num);
}
//---------------------------------------------------------------------
std::string AllScenarioData::getSelectText(int scenario_num, int select_num)
{
    return scenario_data[scenario_num]->getSelectText(select_num);
}