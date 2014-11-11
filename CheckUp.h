//********************************************
//           check up
//res::http://docs.mql4.com/check
//********************************************
#ifndef CHECKUP_H__
#define CHECKUP_H__
#include"DataType.h"
int  GetLastError();
bool IsConnected();
bool IsDemo();
bool IsDllsAllowed();
bool IsExpertEnabled();
bool IsLibrariesAllowed();
bool IsOptimization();
bool IsStopped();
bool IsTesting();
bool IsTradeAllowed();
bool IsTradeContextBusy();
bool IsVisualMode();
int  UninitializeReason();


//Returns the value of a corresponding property of the mql5 program environment.
int  TerminalInfoInteger( ENUM_TERMINAL_INFO_INTEGER property_id );
//Returns the value of a corresponding property of the mql5 program environment.
int  TerminalInfoDouble(ENUM_TERMINAL_INFO_DOUBLE property_id);
//Returns the value of a corresponding property of the mql5 program environment.
int  TerminalInfoString(ENUM_TERMINAL_INFO_STRING property_id);

//Returns the value of a corresponding property of a running mql5 program.
int  MQLInfoInteger(ENUM_MQL_INFO_INTEGER property_id );
//Returns the value of a corresponding property of a running mql5 program.
int  MQLInfoString(ENUM_MQL_INFO_STRING property_id);

//Returns the name of a symbol of the current chart.
string  Symbol();

//Returns the current chart timeframe.
ENUM_TIMEFRAMES  Period();

//Returns the number of decimal digits determining the accuracy of price of the current chart symbol.
int  Digits();

//Returns the point size of the current symbol in the quote currency.
double  Point();
#endif

