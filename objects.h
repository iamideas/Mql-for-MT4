//*******************************************
//           Object functions
//res::http://docs.mql4.com/objects
//*******************************************
#ifndef OBJECTS_H__
#define OBJECTS_H__

#include"Framework/standardCPPLibrary.h"
#include"DataType.h"

bool ObjectCreate(string name, int type, int window, datetime time1, double price1,
					datetime time2=0, double price2=0, datetime time3=0, double price3=0);
bool  ObjectCreate(
	long         chart_id,      // chart identifier
	string       name,          // object name
	ENUM_OBJECT  type,          // object type
	int			 nwin,          // window index
	datetime     time1,         // time of the first anchor point
	double       price1,        // price of the first anchor point
	datetime     timeN = 0,       // time of the N-th anchor point
	double       priceN = 0,      // price of the N-th anchor point
	datetime     time30 = 0,      // time of the 30th anchor point
	double       price30 = 0      // price of the 30th anchor point
	);
bool ObjectDelete(string name);
bool  ObjectDelete(
	long    chart_id,     // chart identifier
	string  name          // object name
);
string ObjectDescription(string name);
//If successful the function returns the number of the subwindow (0 means the main window of the chart)
int ObjectFind(string name);
//If successful the function returns the number of the subwindow (0 means the main window of the chart)
int  ObjectFind(
	long    chart_id,     // chart identifier
	string  name          // object name
);
double ObjectGet(string name, int index);
string ObjectGetFiboDescription(string name, int index);
int ObjectGetShiftByValue(string name, double value);
double ObjectGetValueByShift(string name, int shift);
//point -> 0
bool ObjectMove(string name, int point, datetime time1, double price1);
//The function changes coordinates of the specified anchor point of the object.
bool  ObjectMove(
	long      chart_id,        // chart identifier
	string    name,            // object name
	int       point_index,     // anchor point number 
	datetime  time,            // Time
	double    price            // Price
	);
string ObjectName(int index);
string  ObjectName(
	long  chart_id,           // chart identifier
	int   pos,                // number in the list of objects
	int   sub_window = -1,      // window index
	int   type = -1             // object type
	);
int ObjectsDeleteAll(int window=EMPTY, int type=EMPTY);
int  ObjectsDeleteAll(
	long  chart_id,           // chart identifier
	int   sub_window = -1,      // window index
	int   type = -1             // object type
	);
bool ObjectSet(string name, int index, double value);
bool ObjectSetFiboDescription(string name, int index, string text);
bool ObjectSetText(string name, string text, int font_size, string font=NULL,		            color text_color=CLR_NONE);
int ObjectsTotal(int type=EMPTY);
//The function returns the number of objects in the specified chart, specified subwindow, of the specified type.
int  ObjectsTotal(
	long  chart_id,           // chart identifier
	int   sub_window = -1,      // window index
	int   type = -1             // object type
);
int ObjectType(string name);
//The function returns the time value for the specified price value of the specified object.
datetime  ObjectGetTimeByValue(
	long    chart_id,     // chart identifier
	string  name,         // object name
	double  value,        // Price
	int     line_id       // Line number
);




/*
	The function sets the value of the corresponding object property.The object property must be of the 
datetime, int, color, bool or char type.There are 2 variants of the function.
Setting property value, without modifier
*/
bool  ObjectSetInteger(
	long    chart_id,          // chart identifier
	string  name,              // object name
	int     prop_id,           // property ENUM_OBJECT_PROPERTY_INTEGER
	long    prop_value         // value
);

//Setting a property value indicating the modifier
bool  ObjectSetInteger(
	long    chart_id,          // chart identifier
	string  name,              // object name
	int     prop_id,           // property ENUM_OBJECT_PROPERTY_INTEGER
	int     prop_modifier,     // modifier
	long    prop_value         // value
);


/*
	The function sets the value of the corresponding object property.The object property must be 
of the string type.There are 2 variants of the function.
	Setting property value, without modifier
*/
bool  ObjectSetString(
	long    chart_id,          // chart identifier
	string  name,              // object name
	int     prop_id,           // property ENUM_OBJECT_PROPERTY_STRING
	string  prop_value         // value
);

//Setting a property value indicating the modifier
bool  ObjectSetString(
	long    chart_id,          // chart identifier
	string  name,              // object name
	int     prop_id,           // property ENUM_OBJECT_PROPERTY_STRING
	int     prop_modifier,     // modifier
	string  prop_value         // value
);

/*
	The function returns the value of the corresponding object property.The object property must be of 
the double type.There are 2 variants of the function.
	1. Immediately returns the property value.
*/
double  ObjectGetDouble(
	long    chart_id,          // chart identifier
	string  name,              // object name
	int     prop_id,           // property identifier
	int     prop_modifier = 0    // property modifier, if required
);
/*
	2. Returns true or false, depending on the success of the function.If successful, the property value 
is placed to a receiving variable passed by reference by the last parameter.
*/
bool  ObjectGetDouble(
	long    chart_id,          // chart identifier
	string  name,              // object name
	int     prop_id,           // property identifier
	int     prop_modifier,     // property modifier
	double& double_var         // here we accept the property value
);

/*
	The function returns the value of the corresponding object property.The object property must be of the
datetime, int, color, bool or char type.There are 2 variants of the function.
	1. Immediately returns the property value.
*/
long  ObjectGetInteger(
	long    chart_id,          // chart identifier
	string  name,              // object name
	int     prop_id,           // property identifier
	int     prop_modifier = 0    // property modifier, if required
);
/*
	2. Returns true or false, depending on the success of the function.If successful, the property value
is placed to a receiving variable passed by reference by the last parameter.
*/
bool  ObjectGetInteger(
	long    chart_id,          // chart identifier
	string  name,              // object name
	int     prop_id,           // property identifier
	int     prop_modifier,     // property modifier
	long&   long_var           // here we accept the property value
);

/*
	The function returns the value of the corresponding object property.The object property must be of
the string type.There are 2 variants of the function.
	1. Immediately returns the property value.
*/
string  ObjectGetString(
	long    chart_id,          // chart identifier
	string  name,              // object name
	int     prop_id,           // property identifier
	int     prop_modifier = 0    // property modifier, if required
);
/*
	2. Returns true or false, depending on the success of the function.If successful, the property 
value is placed to a receiving variable passed by reference by the last parameter.
*/
bool  ObjectGetString(
	long    chart_id,          // chart identifier
	string  name,              // object name
	int     prop_id,           // property identifier
	int     prop_modifier,     // property modifier
	string& string_var         // here we accept the property value
);

/*
	The function sets the font for displaying the text using drawing methods and returns the result of
that operation.Arial font with the size - 120 (12 pt) is used by default.
*/
bool  TextSetFont(
	const string  name,            // font name or path to font file on the disk
	int           size,            // font size
	uint          flags,           // combination of flags
	int           orientation = 0    // text slope angle
);

/*
	The function displays a text in a custom array(buffer) and returns the result of that operation.The 
array is designed to create the graphical resource.
*/
bool  TextOut(
	const string       text,          // displayed text
	int                x,             // X coordinate 
	int                y,             // Y coordinate 
	uint               anchor,        // anchor type
	uint               data[],       // output buffer
	uint               width,         // buffer width in pixels
	uint               height,        // buffer height in pixels
	uint               color,         // text color
	ENUM_COLOR_FORMAT  color_format   // color format for output
);

//The function returns the line width and height at the current font settings.
bool  TextGetSize(
	const string       text,          // text string
	uint&               width,        // buffer width in pixels
	uint&               height        // buffer height in pixels
);

#endif
