//*******************************************
//           Timeseries access
//res::http://docs.mql4.com/series
//*******************************************
#ifndef PRICEINFO_H__
#define PRICEINFO_H__

#include"Framework/standardCPPLibrary.h"

int iBars(string symbol, int timeframe);
int iBarShift(string symbol, int timeframe, datetime time, bool exact=false);
double iClose(string symbol, int timeframe, int shift);
double iHigh(string symbol, int timeframe, int shift);
int iHighest(string symbol, int timeframe, int type, int count=WHOLE_ARRAY, int start=0);
double iLow(string symbol, int timeframe, int shift);
int iLowest(string symbol, int timeframe, int type, int count=WHOLE_ARRAY, int start=0);
double iOpen(string symbol, int timeframe, int shift);
datetime iTime(string symbol, int timeframe, int shift);
double iVolume(string symbol, int timeframe, int shift);

#endif
