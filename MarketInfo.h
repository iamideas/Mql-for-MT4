#ifndef MARKETINFO_H_
#define MARKETINFO_H_

#include "DataType.h"
#include "DataStructures.h"
#include "Framework\standardCPPLibrary.h"

/*
	Returns the number of available(selected in Market Watch or all) symbols.
	Parameters
	selected
	[in] Request mode.Can be true or false.

	Return Value
	If the 'selected' parameter is true, the function returns the number of symbols selected in 
MarketWatch.If the value is false, it returns the total number of all symbols.
*/
int  SymbolsTotal( bool  selected );

//Returns the name of a symbol.
string  SymbolName(
	int   pos,          // number in the list
	bool  selected      // true - only symbols in MarketWatch
);

//Selects a symbol in the Market Watch window or removes a symbol from the window.
bool  SymbolSelect(
	string  name,       // symbol name
	bool    select      // add or remove
);

//The function checks whether data of a selected symbol in the terminal are synchronized with data on the trade server.
bool  SymbolIsSynchronized( string  name );

//Returns the corresponding property of a specified symbol.There are 2 variants of the function.

double  SymbolInfoDouble(
	string                   name,       // symbol
	ENUM_SYMBOL_INFO_DOUBLE  prop_id     // identifier of the property
);
/* 
	Returns true or false depending on whether a function is successfully performed.In case of success, 
the value of the property is placed into a recipient variable, passed by reference by the last parameter.
*/
bool  SymbolInfoDouble(
	string                   name,       // symbol
	ENUM_SYMBOL_INFO_DOUBLE  prop_id,    // identifier of the property
	double&                  double_var  // here we assume the property value
);

//Returns the corresponding property of a specified symbol.There are 2 variants of the function.
long  SymbolInfoInteger(
	string                    name,      // symbol
	ENUM_SYMBOL_INFO_INTEGER  prop_id    // identifier of a property

);
/*
	Returns true or false depending on whether a function is successfully performed.In case of success, the value of
the property is placed into a recipient variable, passed by reference by the last parameter.
*/
bool  SymbolInfoInteger(
	string                    name,      // symbol
	ENUM_SYMBOL_INFO_INTEGER  prop_id,   // identifier of a property
	long&                     long_var   // here we assume the property value
);

//Returns the corresponding property of a specified symbol.There are 2 variants of the function.
string  SymbolInfoString(
	string                   name,        // Symbol
	ENUM_SYMBOL_INFO_STRING  prop_id      // Property identifier
);
/*
	Returns true or false, depending on the success of a function.If successful, the value of the property is
placed in a placeholder variable passed by reference in the last parameter.
*/
bool  SymbolInfoString(
	string                   name,        // Symbol
	ENUM_SYMBOL_INFO_STRING  prop_id,     // Property identifier
	string&                  string_var   // Here we assume the property value
);

//The function returns current prices of a specified symbol in a variable of the MqlTick type.
bool  SymbolInfoTick(
	string    symbol,     // symbol name
	MqlTick&  tick        // reference to a structure
);

//Allows receiving time of beginning and end of the specified quoting sessions for a specified symbol and weekday.
bool  SymbolInfoSessionQuote(
	string            name,                // symbol name
	ENUM_DAY_OF_WEEK  day_of_week,         // day of the week
	uint              session_index,       // session index
	datetime&         from,                // time of the session beginning
	datetime&         to                   // time of the session end
);

//Allows receiving time of beginning and end of the specified trading sessions for a specified symbol and weekday.
bool  SymbolInfoSessionTrade(
	string            name,                // symbol name
	ENUM_DAY_OF_WEEK  day_of_week,         // day of the week
	uint              session_index,       // session index
	datetime&         from,                // session beginning time
	datetime&         to                   // session end time
);

//Provides opening of Depth of Market for a selected symbol, and subscribes for receiving notifications of the DOM changes.
bool  MarketBookAdd( string  symbol );
/*
	Provides closing of Depth of Market for a selected symbol, and cancels the subscription for receiving notifications 
of the DOM changes.
*/
bool  MarketBookRelease(string  symbol);

//Returns a structure array MqlBookInfo containing records of the Depth of Market of a specified symbol.
bool  MarketBookGet(
	string        symbol,     // symbol
	MqlBookInfo   book[]      // reference to an array
);
#endif

