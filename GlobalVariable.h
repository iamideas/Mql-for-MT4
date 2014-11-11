//*******************************************
//           Globalvariable function
//res::http://docs.mql4.com/globals
//*******************************************

#ifndef GLOBALVARIABLE_H__
#define GLOBALVARIABLE_H__

#include"Framework/standardCPPLibrary.h"

bool GlobalVariableCheck(string name);
bool GlobalVariableDel(string name);
/*
	Returns the value of an existing global variable of the client terminal.There are 2 variants of the function.
	1. Immediately returns the value of the global variable.
*/
double  GlobalVariableGet(string  name);
/*
	2. Returns true or false depending on the success of the function run.If successful, the global variable of
the client terminal is placed in a variable passed by reference in the second parameter.
*/
bool  GlobalVariableGet(
	string  name,              // Global variable name
	double& double_var         // This variable will contain the value of the global variable
);
datetime GlobalVariableSet(string name, double value);
int GlobalVariablesDeleteAll(string prefix_name=NULL);
int GlobalVariablesTotal();

//Returns the time when the global variable was last accessed.
datetime  GlobalVariableTime(string  name );

//Returns the name of a global variable by it's ordinal number.
string  GlobalVariableName(
	int  index      // Global variable number in the list of global variables
);

//Forcibly saves contents of all global variables to a disk.
void  GlobalVariablesFlush();

/*
	The function attempts to create a temporary global variable.If the variable doesn't exist, the 
system creates a new temporary global variable.
*/
bool  GlobalVariableTemp(
	string  name      // Global variable name
);

/*
	Sets the new value of the existing global variable if the current value equals to the third parameter
check_value.If there is no global variable, the function will generate an error ERR_GLOBALVARIABLE_NOT_FOUND(4501)
and return false.
*/
bool  GlobalVariableSetOnCondition(
	string  name,            // Global variable name
	double  value,           // New value for variable if condition is true
	double  check_value      // Check value condition
);

//Deletes global variables of the client terminal.
int  GlobalVariablesDeleteAll(
	string     prefix_name = NULL,     // All global variables with names beginning with the prefix
	datetime   limit_data = 0          // All global variables that were changed before this date
);

//Returns the total number of global variables of the client terminal.
int  GlobalVariablesTotal();
#endif
