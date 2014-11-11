#ifndef CHART_H_
#define CHART_H_

#include "Framework\standardCPPLibrary.h"
#include "DataType.h"

/*
	Applies a specific template from a specified file to the chart.The command is added to chart
messages queue and will be executed after processing of all previous commands.
*/
bool  ChartApplyTemplate(
	long          chart_id,     // Chart ID
	const string  filename      // Template file name
);

//Saves current chart settings in a template with a specified name.
bool  ChartSaveTemplate(
	long          chart_id,     // Chart ID
	const string  filename      // Filename to save the template
);

/*
	The function returns the number of a subwindow where an indicator is drawn.There are 2 variants of the function.
	The function searches in the indicated chart for the subwindow with the specified "short name" of 
the indicator(the short name is displayed in the left top part of the subwindow), and it returns the subwindow 
number in case of success.
*/
int  ChartWindowFind(
	long     chart_id,                  // chart identifier
	string   indicator_shortname		// short indicator name, see INDICATOR_SHORTNAME
);
//The function must be called from a custom indicator.It returns the number of the subwindow where the indicator is working.
int  ChartWindowFind();

//Converts the coordinates of a chart from the time / price representation to the X and Y coordinates.
bool  ChartTimePriceToXY(
	long           chart_id,     // Chart ID
	int            sub_window,   // The number of the subwindow
	datetime       time,         // Time on the chart
	double         price,        // Price on the chart
	int&           x,            // The X coordinate for the time on the chart
	int&           y             // The Y coordinates for the price on the chart
);

//Opens a new chart with the specified symbol and period.
long  ChartOpen(
	string           symbol,     // Symbol name
	ENUM_TIMEFRAMES  period      // Period
);

//Returns the ID of the first chart of the client terminal.
long  ChartFirst();

//Returns the chart ID of the chart next to the specified one.
long  ChartNext(long  chart_id);

//Closes the specified chart.
bool  ChartClose(long  chart_id = 0 );

//Returns the symbol name for the specified chart.
string  ChartSymbol(long  chart_id = 0 );

//Returns the timeframe period of specified chart.
ENUM_TIMEFRAMES  ChartPeriod(long  chart_id = 0 );

//This function calls a forced redrawing of a specified chart.
void  ChartRedraw(long  chart_id = 0 );

/*
	Sets a value for a corresponding property of the specified chart.Chart property should be of a double type.The 
command is added to chart messages queue and will be executed after processing of all previous commands.
*/
bool  ChartSetDouble(
	long    chart_id,     // Chart ID
	int     prop_id,      // Property ID ENUM_CHART_PROPERTY_DOUBLE
	double  value         // Value
);

/*
	Sets a value for a corresponding property of the specified chart. Chart property must be datetime, int, color,
bool or char. The command is added to chart messages queue and will be executed after processing of all previous commands.
*/
bool  ChartSetInteger(
   long   chart_id,     // Chart ID
   int    prop_id,      // Property ID ENUM_CHART_PROPERTY_INTEGER
   long   value         // Value
   );

/*
	Sets a value for a corresponding property of the specified chart.Chart property must be of the string type.The
command is added to chart messages queue and will be executed after processing of all previous commands.
*/
bool  ChartSetString(
	long  chart_id,         // Chart ID
	int   prop_id,          // Property ID ENUM_CHART_PROPERTY_STRING
	string   str_value      // Value
);

/*
	Returns the value of a corresponding property of the specified chart.Chart property must be of double type.There
are 2 variants of the function calls.
	1. Returns the property value directly.
*/
double  ChartGetDouble(
	long  chart_id,          // Chart ID
	int   prop_id,           // Property ID ENUM_CHART_PROPERTY_DOUBLE
	int   sub_window = 0       // subwindow number, if necessary
);
/*
	2. Returns true or false, depending on the success of a function.If successful, the value of the property is placed
in a target variable double_var passed by reference.
*/
bool  ChartGetDouble(
	long    chart_id,        // Chart ID
	int     prop_id,         // Property ID ENUM_CHART_PROPERTY_DOUBLE
	int     sub_window,      // Subwindow number
	double& double_var       // Target variable for the chart property
);

/*
	Returns the value of a corresponding property of the specified chart.Chart property must be of datetime, 
int or bool type.There are 2 variants of the function calls.
	1. Returns the property value directly.
*/
long  ChartGetInteger(
	long  chart_id,          // Chart ID
	int   prop_id,           // Property ID
	int   sub_window = 0       // subwindow number, if necessary
);
/*
	2. Returns true or false, depending on the success of a function.If successful, the value of the 
property is placed in a target variable long_var passed by reference.
*/
bool  ChartGetInteger(
	long    chart_id,        // Chart ID
	int     prop_id,         // Property ID
	int     sub_window,      // subwindow number
	long&   long_var         // Target variable for the property
);

/*
	Returns the value of a corresponding property of the specified chart.Chart property must be of string
type.There are 2 variants of the function call.
	1. Returns the property value directly.
*/
string  ChartGetString(
	long  chart_id,          // Chart ID
	int   prop_id            // Property ID
);
/*
	2. Returns true or false, depending on the success of a function.If successful, the value of the property
is placed in a target variable string_var passed by reference.
*/
bool  ChartGetString(
	long    chart_id,        // Chart ID
	int     prop_id,         // Property ID
	string& string_var       // Target variable for the property
);

//Performs shift of the specified chart by the specified number of bars relative to the specified position in the chart.
bool  ChartNavigate(
	long  chart_id,     // Chart ID
	int   position,     // Position	
	int   shift = 0       // Shift value
);

//Returns the ID of the current chart.
long  ChartID();

/*
	Adds an indicator with the specified handle into a specified chart window.Indicator
and chart should be generated on the same symbol and time frame.
*/
bool  ChartIndicatorAdd(
	long  chart_id,                 // chart ID
	int   sub_window,                // number of the sub-window
	int   indicator_handle          // handle of the indicator
);

//Removes an indicator with a specified name from the specified chart window.
bool  ChartIndicatorDelete(
	long           chart_id,              // chart id
	int            sub_window,             // number of the subwindow
	const string   indicator_shortname    // short name of the indicator INDICATOR_SHORTNAME
);

//Returns the handle of the indicator with the specified short name in the specified chart window.
int  ChartIndicatorGet(
	long           chart_id,              // Chart ID
	int            sub_window,             // The number of the subwindow
	const string   indicator_shortname    // Short name of the indicator INDICATOR_SHORTNAME
);

//Returns the short name of the indicator by the number in the indicators list on the specified chart window.
string  ChartIndicatorName(
	long  chart_id,      // chart id
	int   sub_window,     // number of the subwindow
	int   index          // index of the indicator in the list of indicators added to the chart subwindow
);

//Returns the number of all indicators applied to the specified chart window.
int  ChartIndicatorsTotal(
	long  chart_id,      // chart id
	int   sub_window     // number of the subwindow
);

/*
	Returns the number(index) of the chart subwindow, the Expert Advisor or script has been dropped to. 
0 means the main chart window.
*/
int  ChartWindowOnDropped();

//Returns the price coordinate corresponding to the chart point, an Expert Advisor or script has been dropped to.
double  ChartPriceOnDropped();

//Returns the time coordinate corresponding to the chart point, an Expert Advisor or script has been dropped to.
datetime  ChartTimeOnDropped();

//Returns the X coordinate of the chart point, an Expert Advisor or script has been dropped to.
int  ChartXOnDropped();

//Returns the Y coordinateof the chart point, an Expert Advisor or script has been dropped to.
int  ChartYOnDropped();

/*
	Changes the symbol and period of the specified chart.The function is asynchronous, i.e.it sends 
the command and does not wait for its execution completion.The command is added to chart messages queue 
and will be executed after processing of all previous commands.
*/
bool  ChartSetSymbolPeriod(
	long             chart_id,     // Chart ID
	string           symbol,       // Symbol name
	ENUM_TIMEFRAMES  period        // Period
);

//The function provides a screenshot of the chart in its current state in the gif format.
bool  ChartScreenShot(
	long             chart_id,                   // Chart ID
	string           filename,                   // Symbol name
	int              width,                      // Width
	int              height,                     // Height
	ENUM_ALIGN_MODE  align_mode = ALIGN_RIGHT      // Alignment type
);
#endif