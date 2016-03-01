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
void AllScenarioData::saveData()
{
    FILE *fp;
    errno_t error = fopen_s(&fp, "scenario/scenario_1.dat", "wb");

    // �t�@�C���ǂݍ��ݎ��s
    if (fp == 0) {
        puts("�V�i���I�f�[�^�̓ǂݍ��݂Ɏ��s���܂���");
        return;
    }

    fprintf(fp, "#NUM 0\r\n");
    fprintf(fp, "#BACK 0\r\n");
    fprintf(fp, "#NEXT 1\r\n");
    fprintf(fp, "#PRE 0\r\n");
    fprintf(fp, "\r\n");

    for (int num = 1; num < 10000; num++) {
        fprintf(fp, "#NUM %d\r\n", num);
        fprintf(fp, "#BACK %d\r\n", scenario_data[num]->getBackimage());
        for (int i = 1; i <= scenario_data[num]->getCharaNum(); i++) {
            fprintf(fp, "#CHARA %d %d %d\r\n",
                scenario_data[num]->getCharaPos(i),
                scenario_data[num]->getCharaImage(i),
                scenario_data[num]->getCharaFace(i));
        }
        if (scenario_data[num]->getName() != "") {
            fprintf(fp, "#NAME %s\r\n", scenario_data[num]->getName().c_str());
        }
        if (scenario_data[num]->getText1() != "") {
            fprintf(fp, "#TEXT1 %s\r\n", scenario_data[num]->getText1().c_str());
        }
        if (scenario_data[num]->getText2() != "") {
            fprintf(fp, "#TEXT2 %s\r\n", scenario_data[num]->getText2().c_str());
        }
        if (scenario_data[num]->getText3() != "") {
            fprintf(fp, "#TEXT3 %s\r\n", scenario_data[num]->getText3().c_str());
        }
        fprintf(fp, "#FADE %d\r\n", scenario_data[num]->getFade());
        fprintf(fp, "#SELECTNUM %d\r\n", scenario_data[num]->getSelectNum());
        for (int i = 1; i <= scenario_data[num]->getSelectNum(); i++) {
            fprintf(fp, "#SELECT %d %d %s\r\n",
                i,
                scenario_data[num]->getSelectNext(i),
                scenario_data[num]->getSelectText(i).c_str());
        }
        fprintf(fp, "#NEXT %d\r\n", scenario_data[num]->getNext());
        fprintf(fp, "#PRE %d\r\n", scenario_data[num]->getPrev());
        fprintf(fp, "\r\n");
    }
    fclose(fp);
    puts("Success data save");
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
//---------------------------------------------------------------------
void AllScenarioData::setName(int scenario_num, std::string str) {
    scenario_data[scenario_num]->setName(str);
}
void AllScenarioData::setText1(int scenario_num, std::string str) {
    scenario_data[scenario_num]->setText1(str);
}
void AllScenarioData::setText2(int scenario_num, std::string str) {
    scenario_data[scenario_num]->setText2(str);
}
void AllScenarioData::setText3(int scenario_num, std::string str) {
    scenario_data[scenario_num]->setText3(str);
}
void AllScenarioData::setBackimage(int scenario_num, int image) {
    scenario_data[scenario_num]->setBackimage(image);
}
void AllScenarioData::setCharaNum(int scenario_num, int num) {
    scenario_data[scenario_num]->setCharaNum(num);
}
void AllScenarioData::setCharaImage(int scenario_num, int chara_num, int image) {
    scenario_data[scenario_num]->setCharaImage(chara_num, image);
}
void AllScenarioData::setCharaPos(int scenario_num, int chara_num, int pos) {
    scenario_data[scenario_num]->setCharaPos(chara_num, pos);
}
void AllScenarioData::setCharaFace(int scenario_num, int chara_num, int face) {
    scenario_data[scenario_num]->setCharaFace(chara_num, face);
}
//---------------------------------------------------------------------
int AllScenarioData::getBackimageMax() { return 2; }
int AllScenarioData::getCharaImageMax() { return 5; }
int AllScenarioData::getCharaPosMax() { return 9; }
int AllScenarioData::getCharaFaceMax() { return 1; }