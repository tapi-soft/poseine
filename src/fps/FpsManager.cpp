#include "FpsManager.h"

//---------------------------------------------------------------------
FpsManager::FpsManager()
{
    init();
}
//---------------------------------------------------------------------
FpsManager::~FpsManager()
{

}
//---------------------------------------------------------------------
void FpsManager::init()
{
    start_time = 0;
    counter = 0;
    fps = 0;
}
//---------------------------------------------------------------------
void FpsManager::update()
{
    if (counter == 0) {
        start_time = GetNowCount();
    }
    if (counter == N) {
        int t = GetNowCount();
        fps = 1000.f / ((t - start_time) / (double)N);
        counter = 0;
        start_time = t;
    }
    counter++;
}
//---------------------------------------------------------------------
void FpsManager::wait(){
    int took_time = GetNowCount() - start_time;
    int wait_time = counter * 1000 / FPS - took_time;
    if (wait_time > 0){
        Sleep(wait_time);
    }
}