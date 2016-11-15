//asdf
#ifndef TRADESIGNALS_H_
#define TRADESIGNALS_H_

#include"Framework/StandardCPPLibrary.h"
#include"DataType.h"

//Returns the value of double type property for selected signal.
double  SignalBaseGetDouble(ENUM_SIGNAL_BASE_DOUBLE     property_id);

//Returns the value of integer type property for selected signal.
long  SignalBaseGetInteger(ENUM_SIGNAL_BASE_INTEGER     property_id);

//Returns the value of string type property for selected signal.
string  SignalBaseGetString(ENUM_SIGNAL_BASE_STRING     property_id);

//Selects a signal from signals, available in terminal for further working with it.
bool  SignalBaseSelect(int     index);

//Returns the total amount of signals, available in terminal.
int  SignalBaseTotal();

//Returns the value of double type property of signal copy settings.
double  SignalInfoGetDouble(ENUM_SIGNAL_INFO_DOUBLE     property_id);

//Returns the value of integer type property of signal copy settings.
long  SignalInfoGetInteger(ENUM_SIGNAL_INFO_INTEGER     property_id);

//Returns the value of string type property of signal copy settings.
string  SignalInfoGetString(ENUM_SIGNAL_INFO_STRING     property_id);

//Sets the value of double type property of signal copy settings.
bool  SignalInfoSetDouble(
	ENUM_SIGNAL_INFO_DOUBLE      property_id,     // property identifier
	double                       value            // new value
	);

//Sets the value of integer type property of signal copy settings.
bool  SignalInfoSetInteger(
	ENUM_SIGNAL_INFO_INTEGER     property_id,     // property identifier
	long                         value            // new value
	);

//Subscribes to the trading signal.
bool  SignalSubscribe(
	long     signal_id     // signal id 
	);

//Cancels subscription.
bool  SignalUnsubscribe();
#endif