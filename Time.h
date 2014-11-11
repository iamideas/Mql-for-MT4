//********************************************
//              Data & Time functions
//res::http://docs.mql4.com/dateandtime
//********************************************
#ifndef DATETIME_H__
#define DATETIME_H__

#include"Framework\standardCPPLibrary.h"
#include"DataStructures.h"
/*
 * 	 Returns the current day of the month, i.e., the day of month of the last
 * known server time.
 * 	 Note: At the testing, the last known server time is modeled.
 */
int Day();

/*
 * 	 Returns the current zero-based day of the week (0-Sunday,1,2,3,4,5,6) of the
 * last known server time.
 * 	 Note: At the testing, the last known server time is modeled.
 */
int DayOfWeek();

/*
 *   Returns the current day of the year (1 means 1 January,..,365(6) does 31
 * December), i.e., the day of year of the last known server time.
 * 	 Note: At the testing, the last known server time is modeled.
 */
int DayOfYear();

/*
 *   Returns the hour (0,1,2,..23) of the last known server time by the moment
 * of the program start (this value will not change within the time of the program execution).
 *   Note: At the testing, the last known server time is modeled.
 */
int Hour();

/*
 *   Returns the current minute (0,1,2,..59) of the last known server time by the
 * moment of the program start (this value will not change within the time of the
 * program execution).
 */
int Minute();

/*
 * 	 Returns the amount of seconds elapsed from the beginning of the current
 * minute of the last known server time by the moment of the program start
 * (this value will not change within the time of the program execution).
 */
int Seconds();

/*
 *   Returns the current month as number (1-January,2,3,4,5,6,7,8,9,10,11,12), i.e.,
 * the number of month of the last known server time.
 *   Note: At the testing, the last known server time is modeled.
 */
int Mouth();  	//Returns the current month as number(1,2,3,4,...12),i.e,

/*
 * 	 Returns the current year, i.e., the year of the last known server time.
 * 	 Note: At the testing, the last known time is modeled.
 */
int Year();


/*
 * 	 Returns the last known server time (time of incoming of the latest quote) as
 * number of seconds elapsed from 00:00 January 1, 1970.
 *   Note: At the testing, the last known server time is modeled.
 */
datetime TimeCurrent();
datetime TimeCurrent(MqlDateTime& dt_struct );
/*
 *  Returns day of month (1 - 31) for the specified date.
	Parameters:
		date  -	Datetime as number of seconds elapsed since midnight (00:00:00), January 1, 1970.
 *
 */
int TimeDay(datetime date);

/*
 *  Returns the zero-based day of week(0 means Sunday, 123456);
	Parameters:
		date  -	Datetime as number of seconds elapsed since midnight (00:00:00), January 1, 1970.
 *
 */
int TimeDayOfWeek(datetime date);

/*
 *  Returns day (1 means 1 January,..,365() does 31 December) of year for the specified date..
	Parameters:
		date  -	Datetime as number of seconds elapsed since midnight (00:00:00), January 1, 1970.
 *
 */
int TimeDayOfYear(datetime date);

/*
 * 	Returns the hour for the specified time.
 * 	time - Datetime is the number of second elapsed since 1970
 */
int TimeHour(datetime time);

/*
 * 	Returns local computer time as number of seconds since...1970
 */
datetime TimeLocal();
datetime  TimeLocal(MqlDateTime&  dt_struct);
/*
 *  Returns the minute for the specified time. Since 1970
 * 	time - Datetime is the number of second elapsed since 1970
 */
int TimeMinute(datetime time);

/*
 *  Returns the month number  for the specified time. Since 1970
 * 	time - Datetime is the number of second elapsed since 1970
 */
int TimeMonth(datetime time);

/*
 *  Returns the seconds number  for the specified time. Since 1970
 * 	time - Datetime is the number of second elapsed since 1970
 */
int TimeSeconds(datetime time);

/*
 *  	Returns year for the specified date. The returned value can be
 *  within the range of 1970 to 2037.
 * 	time - Datetime is the number of second elapsed since 1970
 */
int TimeYear(datetime time);


/*
	Returns the calculated current time of the trade server.Unlike TimeCurrent(), the calculation 
of the time value is performed in the client terminal and depends on the time settings on your 
computer.There are 2 variants of the function.
*/
datetime  TimeTradeServer();
datetime  TimeTradeServer(MqlDateTime&  dt_struct);

/*
	Returns the GMT, which is calculated taking into account the DST switch by the local time 
on the computer where the client terminal is running.There are 2 variants of the function.
*/
datetime  TimeGMT();
datetime  TimeGMT(MqlDateTime&  dt_struct);

/*
	Returns correction for daylight saving time in seconds, switch to summer time has been made.
It depends on the time settings of your computer.
*/
int  TimeDaylightSavings();

/*
	Returns the current difference between GMT time and the local computer time in seconds, taking
into account switch to winter or summer time.Depends on the time settings of your computer.
*/
int  TimeGMTOffset();

//Converts a value of datetime type(number of seconds since 01.01.1970) into a structure variable MqlDateTime.
void  TimeToStruct(datetime dt, MqlDateTime&  dt_struct);
//Converts a structure variable MqlDateTime into a value of datetime type and returns the resulting value.
datetime  StructToTime(MqlDateTime& dt_struct);

#endif