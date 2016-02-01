#pragma once
#include <string>

class ScenarioData
{
private:
    int num;               // scenario number
    std::string name;      // character name
    std::string text1;     // 1 line text
    std::string text2;     // 2 line text
    std::string text3;     // 3 line text
    int backimage;         // background image
    int next;              // next scenario number
    int prev;              // previous scenario number
    int fade;              // fade kind
    int chara_num;         // number of character 
    int chara_pos[10];     // character position
    int chara_image[10];   // character image
    int chara_face[10];    // character face

public:
    ScenarioData();
    ~ScenarioData();

    void setNum(int);
    void setName(std::string);
    void setText1(std::string);
    void setText2(std::string);
    void setText3(std::string);
    void setBackimage(int);
    void setNext(int);
    void setPrev(int);
    void setFade(int);
    void setCharaNum(int);
    void setCharaPos(int, int);
    void setCharaImage(int, int);
    void setCharaFace(int, int);

    int getNum();
    std::string getName();
    std::string getText1();
    std::string getText2();
    std::string getText3();
    int getBackimage();
    int getNext();
    int getPrev();
    int getFade();
    int getCharaNum();
    int getCharaPos(int);
    int getCharaImage(int);
    int getCharaFace(int);
};