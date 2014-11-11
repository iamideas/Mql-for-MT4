//+------------------------------------------------------------------+
//|                                                       stdlib.mqh |
//|                      Copyright ?2004, MetaQuotes Software Corp. |
//|                                       http://www.metaquotes.net/ |
//+------------------------------------------------------------------+
#ifndef STDLIB_H__
#define STDLIB_H__

#include"Framework\standardCPPLibrary.h"

string ErrorDescription(int error_code);
int    RGB(int red_value,int green_value,int blue_value);
bool   CompareDoubles(double number1,double number2);
string DoubleToStrMorePrecision(double number,int precision);
string IntegerToHexString(int integer_number);

#endif