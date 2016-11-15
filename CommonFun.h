//********************************************
//           Common functions
//res::http://docs.mql4.com/common
//********************************************
#ifndef COMMONFUN_H__
#define COMMONFUN_H__

#include"Framework\standardCPPLibrary.h"
#include"DataType.h"
#include"Object.mqh"
template< typename type > void Alert(type para, ...);
template< typename type > void Print(type para, ...);
void Print(string para);
template< typename type > void Comment(type para, ...);

double MarketInfo(string symbol, int type);
void PlaySound(string filename);
bool SendFTP(string filename, string ftp_path=NULL);
bool SendMail(string subject, string some_text);
bool SendNotification(string message);
void Sleep(int milliseconds);

//----MQL5
//The function returns the type of the object pointer.
ENUM_POINTER_TYPE  CheckPointer(
	void* anyobject      // object pointer
);

//Transforms the data from array with the specified method.
int  CryptEncode(
	ENUM_CRYPT_METHOD   method,        // method
	const uchar        data[],        // source array
	const uchar        key[],         // key
	const uchar        result[]       // destination array
);

//Performs the inverse transformation of the data from array, tranformed by CryptEncode().
int  CryptEncode(
	ENUM_CRYPT_METHOD   method,        // method
	const uchar        data[],        // source array
	const uchar        key[],         // key
	const uchar        result[]       // destination array
);

//It is a program breakpoint in debugging.
void  DebugBreak();

//The function stops an Expert Advisor and unloads it from a chart.
void  ExpertRemove();

//The function returns the object pointer.
void*  GetPointer(
	CObject anyobject      // object of any class
);

//The GetTickCount() function returns the number of milliseconds that elapsed since the system start.
uint  GetTickCount();

//It creates and shows a message box and manages it.A message box contains a message and header, any combination of predefined signs and command buttons.
int  MessageBox(
	string  text,             // message text
	string  caption = NULL,     // box header
	int     flags = 0           // defines set of buttons in the box
);

//This function returns number of seconds in a period.
int  PeriodSeconds(
	ENUM_TIMEFRAMES  period = PERIOD_CURRENT      // chart period
);

//It formats and enters sets of symbols and values in the Expert Advisor log in accordance with a preset format.
//Instead of PrintFormat() you can use printf().
void  PrintFormat( 	string format_string, ...);

//Sets the value of the predefined variable _LastError into zero.
void  ResetLastError();

//Creates an image resource based on a data set.There are two variants of the function :
//Creating a resource based on a file
bool  ResourceCreate(
	const string      resource_name,       // Resource name
	const string      path                 // A relative path to the file
);
//Creating a resource based on the array of pixels
bool  ResourceCreate(
	const string      resource_name,       // Resource name
	const uint        data[],              // Data set as an array
	uint              img_width,           // The width of the image resource
	uint              img_height,          // The height of the image resource
	uint              data_xoffset,        // The horizontal rightward offset of the upper left corner of the image
	uint              data_yoffset,        // The vertical downward offset of the upper left corner of the image
	uint              data_width,          // The total width of the image based on the data set
	ENUM_COLOR_FORMAT color_format         // Color processing method
);
enum ENUM_COLOR_FORMAT{
	COLOR_FORMAT_XRGB_NOALPHA, //The component of the alpha channel is ignored
	COLOR_FORMAT_ARGB_RAW, //Color components are not handled by the terminal(must be correctly set by the user)
	COLOR_FORMAT_ARGB_NORMALIZE, //Color components are handled by the terminal
};
//The function deletes dynamically created resource(freeing the memory allocated for it).
bool  ResourceFree( const string  resource_name );

//The function reads data from the graphical resource created by ResourceCreate() function or saved in EX5 file during compilation.
bool  ResourceReadImage(
	const string      resource_name,       // graphical resource name for reading
	uint              data[],              // array from receiving data from the resource
	uint              width,               // for receiving the image width in the resource
	uint              height               // for receiving the image height in the resource
);

//Saves a resource into the specified file.
/*
Parameters
resource_name [in]  The name of the resource, must start with "::".
file_name	  [in]  The name of the file relative to MQL5\Files.
*/
bool  ResourceSave(
	const string  resource_name,      // Resource name
	const string  file_name          // File name
);

//Sets the predefined variable _LastError into the value equal to ERR_USER_ERROR_FIRST + user_error
void  SetUserError( ushort user_error );

//The function commands the terminal to complete operation.
//ret_code [in]  Return code, returned by the process of the client terminal at the operation completion.
bool  TerminalClose(
	int ret_code      // closing code of the client terminal
);

//The function returns the value of the specified statistical parameter calculated based on testing results.
double  TesterStatistics( ENUM_STATISTICS statistic_id );

//The special function to emulate the operation of money withdrawal in the process of testing.Can be used in some asset management systems.
bool  TesterWithdrawal( double money );

//Sends HTTP request to the specified server.
int  WebRequest(
	const string      method,           // HTTP request method
	const string      url,              // url address
	const string      cookie,           // cookie
	const string      referer,          // referer
	int               timeout,          // timeout
	const char        data[],           // array with HTTP request message
	int               data_size,        // size of data[] array
	char              result[],         // server response data array
	string            result_headers    // server response headers
);

//The function resets a variable passed to it by reference.
void  ZeroMemory(
	void variable      // reset variable
);
#endif