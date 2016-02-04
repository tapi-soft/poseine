#pragma once
#include "../../GameState.h"
#include "SaveloadData.h"
#include "../../input/InputState.h"
#include "SaveData.h"
#include "../main/scenario/AllScenarioData.h"
#include "../../data/ImageData.h"

class SaveloadDraw
{
private:
    SaveloadState* saveload_state;
    InputState* input_state;
    int image_back;
    int image_base[20];
    int image_margin;
    int image_button_num[50];
    int image_button_back[2];
    int image_save_logo;
    int image_load_logo;
    int image_thumbnail_nodata;
    int font_text;
    int font_time;
    int font_dialog;
    int color_font;

    void drawLogo();
    void drawSavedata();
    void drawSavedata(int);
    void drawSavedataBack(int);
    void drawSavedataTime(int);
    void drawSavedataText(int);
    void drawSavedataThumbnail(int);
    void drawButtonPage();
    void drawButtonBack();
public:
    SaveloadDraw(GameState*);
    ~SaveloadDraw();
    void loadImage();
    void update();
};