//---------------------------------------------------------------------
#include "ScenarioData.h"

//---------------------------------------------------------------------
ScenarioData::ScenarioData()
{
    num = 0;
    name = "";
    text1 = "";
    text2 = "";
    text3 = "";
    backimage = 0;
    next = 1;
    fade = 0;
    chara_num = 0;
    prev = 0;
    select_num = 0;
}
//---------------------------------------------------------------------
ScenarioData::~ScenarioData()
{

}
//---------------------------------------------------------------------
void ScenarioData::setNum(int num)                   { this->num = num; }
void ScenarioData::setName(std::string name)         { this->name = name; }
void ScenarioData::setText1(std::string text1)       { this->text1 = text1; }
void ScenarioData::setText2(std::string text2)       { this->text2 = text2; }
void ScenarioData::setText3(std::string text3)       { this->text3 = text3; }
void ScenarioData::setBackimage(int backimage)       { this->backimage = backimage; }
void ScenarioData::setNext(int next)                 { this->next = next; }
void ScenarioData::setPrev(int prev)                 { this->prev = prev; }
void ScenarioData::setFade(int fade)                 { this->fade = fade; }
void ScenarioData::setCharaNum(int chara_num)        { this->chara_num = chara_num; }
void ScenarioData::setCharaPos(int num, int pos)     { this->chara_pos[num] = pos; }
void ScenarioData::setCharaImage(int num, int image) { this->chara_image[num] = image; }
void ScenarioData::setCharaFace(int num, int face)   { this->chara_face[num] = face; }
void ScenarioData::setSelectNum(int num)             { this->select_num = num; }
void ScenarioData::setSelectNext(int num, int next)  { this->select_next[num] = next; }
void ScenarioData::setSelectText(int num, std::string text) { this->select_text[num] = text; }
//---------------------------------------------------------------------
int ScenarioData::getNum()               { return num; }
std::string ScenarioData::getName()      { return name; }
std::string ScenarioData::getText1()     { return text1; }
std::string ScenarioData::getText2()     { return text2; }
std::string ScenarioData::getText3()     { return text3; }
int ScenarioData::getBackimage()         { return backimage; }
int ScenarioData::getNext()              { return next; }
int ScenarioData::getPrev()              { return prev; }
int ScenarioData::getFade()              { return fade; }
int ScenarioData::getCharaNum()          { return chara_num; }
int ScenarioData::getCharaPos(int num)   { return chara_pos[num]; }
int ScenarioData::getCharaImage(int num) { return chara_image[num]; }
int ScenarioData::getCharaFace(int num)  { return chara_face[num]; }
int ScenarioData::getSelectNum()         { return select_num; }
int ScenarioData::getSelectNext(int num) { return select_next[num]; }
std::string ScenarioData::getSelectText(int num) { return select_text[num]; }