//---------------------------------------------------------------------
#include "ScenarioDraw.h"
#include "DxLib.h"

//---------------------------------------------------------------------
ScenarioDraw::ScenarioDraw()
{

}
//---------------------------------------------------------------------
ScenarioDraw::~ScenarioDraw()
{

}
//---------------------------------------------------------------------
void ScenarioDraw::drawImage(int n, int x, int y, double rate)
{
    int width = SystemData::getInstance()->getWindowWidth();
    int height = SystemData::getInstance()->getWindowHeight();

    SetDrawMode(DX_DRAWMODE_BILINEAR);
    SetDrawArea(x, y, (int)(x + width * rate), (int)(y + height * rate));
    drawBack(n, x, y, rate);
    drawChara(n, x, y, rate);
    SetDrawArea(0, 0, width, height);
    SetDrawMode(DX_DRAWMODE_NEAREST);
}
//---------------------------------------------------------------------
void ScenarioDraw::drawBack(int n, int x, int y, double rate)
{
    int image = AllScenarioData::getInstance()->getBackimage(n);

    DrawExtendGraph(
        x,
        y,
        (int)(x + 1280 * rate),
        (int)(y + 720 * rate),
        ImageData::getInstance()->getImageBack(image),
        TRUE);
}
//---------------------------------------------------------------------
void ScenarioDraw::drawChara(int num, int x, int y, double rate)
{
    for (int n = 1; n <= AllScenarioData::getInstance()->getCharaNum(num); n++) {
        int chara_image = AllScenarioData::getInstance()->getCharaImage(num, n);
        int chara_pos = AllScenarioData::getInstance()->getCharaPos(num, n);
        int image = ImageData::getInstance()->getImageChara(chara_image);

        switch (chara_pos) {
        case 1: DrawExtendGraph((int)(x + 240 * rate), (int)(y - 100 * rate), (int)(x + 1040 * rate), (int)(y + 1550 * rate), image, TRUE); break;
        case 2: DrawExtendGraph((int)(x + 390 * rate), (int)(y + 100 * rate), (int)(x + 890 * rate),  (int)(y + 1100 * rate), image, TRUE); break;
        case 3: DrawExtendGraph((int)(x + 90 * rate),  (int)(y + 100 * rate), (int)(x + 590 * rate),  (int)(y + 1100 * rate), image, TRUE); break;
        case 4: DrawExtendGraph((int)(x + 690 * rate), (int)(y + 100 * rate), (int)(x + 1190 * rate), (int)(y + 1100 * rate), image, TRUE); break;
        case 5: DrawExtendGraph((int)(x + 490 * rate), (int)(y + 200 * rate), (int)(x + 790 * rate),  (int)(y + 800 * rate),  image, TRUE); break;
        case 6: DrawExtendGraph((int)(x + 90 * rate),  (int)(y + 200 * rate), (int)(x + 390 * rate),  (int)(y + 800 * rate),  image, TRUE); break;
        case 7: DrawExtendGraph((int)(x + 890 * rate), (int)(y + 200 * rate), (int)(x + 1190 * rate), (int)(y + 800 * rate),  image, TRUE); break;
        case 8: DrawExtendGraph((int)(x + 290 * rate), (int)(y + 200 * rate), (int)(x + 590 * rate),  (int)(y + 800 * rate),  image, TRUE); break;
        case 9: DrawExtendGraph((int)(x + 690 * rate), (int)(y + 200 * rate), (int)(x + 990 * rate),  (int)(y + 800 * rate),  image, TRUE); break;
        }
    }
}