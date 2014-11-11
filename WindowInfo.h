//*******************************************
//           Window functions
//res::http://docs.mql4.com/windows
//*******************************************
#ifndef WINDOWINFO_H__
#define WINDOWINFO_H__

#include"Framework\standardCPPLibrary.h"
#include"DataType.h"

void HideTestIndicators(bool hide);
bool RefreshRates();
int WindowBarsPerChart();
string WindowExpertName();
int WindowFind(string name);
int WindowHandle(string symbol, int timeframe);
bool WindowIsVisible(int index);
int WindowOnDropped();
double WindowPriceMax(int index=0);
double WindowPriceMin(int index=0);
double WindowPriceOnDropped();
void WindowRedraw();
bool WindowScreenShot(string filename, int size_x, int size_y, int start_bar=-1, int chart_scale=-1, int chart_mode=-1);
datetime WindowTimeOnDropped();
int WindowsTotal();
int WindowXOnDropped();
int WindowYOnDropped();

#endif
