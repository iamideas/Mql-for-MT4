//*******************************************
//           String functions
//res::http://docs.mql4.com/strings
//*******************************************
#ifndef STRING_H__
#define STRING_H__

#include"Framework\standardCPPLibrary.h"
#include"DataType.h"

int StringGetChar(string text, int pos);
int StringLen(string text);
string StringSetChar(string text, int pos, int value);
string StringSubstr(string text, int start, int length=-1);
string StringTrimLeft(string &text);
string StringTrimRight(string &text);

//The function adds a substring to the end of a string.
bool  StringAdd(
	string&  string_var,        // string, to which we add
	string   add_substring      // string, which is added
);

//The function returns the size of buffer allocated for the string.
int  StringBufferLen(string  string_var);

//The function compares two strings and returns the comparison result in form of an integer.
int  StringCompare(
	const string&  string1,                 // the first string in the comparison
	const string&  string2,                 // the second string in the comparison
	bool           case_sensitive = true      // case sensitivity mode selection for the comparison
);

/*
	The function forms a string of passed parameters and returns the size of the formed string.Parameters can
be of any type.Number of parameters can't be less than 2 or more than 64.
*/
int  StringConcatenate(string&  string_var, ... );

//It fills out a selected string by specified symbols.
bool  StringFill( string&  string_var, ushort  character);

//Search for a substring in a string.
int  StringFind(
	string  string_value,        // string in which search is made
	string  match_substring,     // what is searched
	int     start_pos = 0          // from what position search starts
);

//Returns value of a symbol, located in the specified position of a string.
ushort  StringGetCharacter(
	string  string_value,     // string
	int     pos               // symbol position in the string
);
//Returns copy of a string with a changed character in a specified position.
bool  StringSetCharacter(
	string&   string_var,       // string
	int       pos,              // position
	ushort    character         // character
);

//It replaces all the found substrings of a string by a set sequence of symbols.
int  StringReplace(
	string&         str,              // the string in which substrings will be replaced
	const string    find,             // the searched substring
	const string    replacement       // the substring that will be inserted to the found positions
);

//Gets substrings by a specified separator from the specified string, returns the number of substrings obtained.
int  StringSplit(
	const string   string_value,       // A string to search in
	const ushort   separator,          // A separator using which substrings will be searched
	string         result[]          // An array passed by reference to get the found substrings
);

//Transforms all symbols of a selected string into lowercase by location.
bool  StringToLower(string&  string_var);
//Transforms all symbols of a selected string into capitals by location.
bool  StringToUpper(string&  string_var );


#endif
