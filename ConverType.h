//********************************************
//           Conversion functions
//res::http://docs.mql4.com/convert
//********************************************
#ifndef CONVERTYPE_H__
#define CONVERTYPE_H__

#include"Framework\standardCPPLibrary.h"
#include"DataType.h"

#define TIME_DATE		0x0000000F
#define TIME_MINUTES    0x000000F0
#define TIME_SECONDS    0x00000F00

string CharToStr(int char_code);
string ChartToString(int char_code);
string DoubleToStr(double value, int digits = 8);
string DoubleToString(double value, int digits = 8);
double NormalizeDouble(double value, int digits);
double StrToDouble(string value);
double StringToDouble(string value);
int    StrToInteger(string value);
int    StrToInteger(string value);
datetime StrToTime(string value);
datetime StringToTime(string value);
string   TimeToStr(datetime value, int mode=TIME_DATE|TIME_MINUTES);
//Converting a value containing time in seconds elapsed since 01.01.1970 into a string of "yyyy.mm.dd hh:mi" format.
string  TimeToString(datetime  value, int mode = TIME_DATE | TIME_MINUTES);

//Symbol - wise copies a string converted from Unicode to ANSI, to a selected place of array of uchar type.It returns the number of copied elements.
int  StringToCharArray(
	string  text_string,         // source string
	uchar   array[],             // array
	int     start = 0,             // starting position in the array
	int     count = -1,             // number of symbols
	uint    codepage = CP_ACP      // code page
);

//It copies and converts part of array of uchar type into a returned string.
string  CharArrayToString(
	uchar  array[],                // array
	int    start = 0,              // starting position in the array
	int    count = -1,             // number of symbols
	uint    codepage = CP_ACP      // code page
);
/*
	Converting "R,G,B" string or string with color name into color type value.
	color_string = "R,G,B";
*/
color  StringToColor( string  color_string ); 

//The function converts string containing a symbol representation of number into number of double type.
double  StringToDouble( string  value );

//The function converts string containing a symbol representation of number into number of int(integer) type.
long  StringToInteger( string  value );

//The function symbol - wise copies a string into a specified place of an array of ushort type.It returns the number of copied elements.
int  StringToShortArray(
	string  text_string,       // source string
	ushort  array[],           // array
	int     start = 0,         // starting position in the array
	int     count = -1         // number of symbols
);

//The function converts a string containing time or date in "yyyy.mm.dd [hh:mi]" format into datetime type.
datetime  StringToTime( string  value );

//The function formats obtained parameters and returns a string.
string  StringFormat(string  format, ...);

/*
	The function converts color type into uint type to get ARGB representation of the color.ARGB 
color format is used to generate a graphical resource, text display, as well as for CCanvas 
standard library class.
*/
uint  ColorToARGB(
	color  clr,          // converted color in color format
	uchar  alpha = 255     // alpha channel managing color transparency
);

//It converts color value into string of "R,G,B" form.
string  ColorToString(
	color  color_value,     // color value
	bool   color_name       // show color name or not
);

//Converting an enumeration value of any type to a text form.
template<typename ENUM_TYPE> string  EnumToString(
  ENUM_TYPE value      // any type enumeration value
);

//This function converting value of integer type into a string of a specified length and returns the obtained string.
string  IntegerToString(
	long    number,              //number
	int     str_len = 0,         //length of result string
	ushort  fill_symbol = ' '        // filler
);

//It converts the symbol code(unicode) into one - symbol string and returns resulting string.
string  ShortToString(ushort  symbol_code);

//It copies part of array into a returned string.
string  ShortArrayToString(
	ushort  array[],      // array
	int     start = 0,      // starting position in the array
	int     count = -1      // number of symbols
);


#endif