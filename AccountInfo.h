//*******************************************
//           Account information
//res::http://docs.mql4.com/account
//*******************************************
#ifndef ACCOUNTINFO_H__
#define ACCOUNTINFO_H__

#include"Framework/standardCPPLibrary.h"
#include"DataType.h"

double AccountBalance( );			//returns balance value of the current account( the amount of money on the acount)
double AccountCredit( );			//returns credit value of the current account
string AccountCompany( );			//returns the brokerage company name where the current account was registered.
string AccountCurrency( );			//returns currency name of the current account
double AccountEquity( );			//returns equity value of the current account. Equity calculation depends on trading server settings
double AccountFreeMargin( );		//returns free margin value of the current account.
int	   AccountLeverage( );			//returns leverage of the current account.
double AccountMargin( );			//returns margin value of the current account
string AccountName( );				//returns the current account name.
int	   AccountNumber( );			//returns the number of the current account.
double AccountProfit( );			//returns profit value of the current account.
string AccountServer( );			//returns the connected server name
int	   AccountStopoutLevel( );		//returns the value of the Stop level

/*
 *Returns the calculation mode for the Stop Out level. Calculation mode can take the following values:
	0 - calculation of percentage ratio between margin and equity;
	1 - comparison of the free margin level to the absolute value.
*/
int	   AccountStopoutMode( );
/*
 *	Returns free margin that remains after the specified position has been opened at the current price on the current account. If the 
 *free margin is insufficient, an error 134 (ERR_NOT_ENOUGH_MONEY) will be generated.
 *Parameters:
	symbol	  -  	Symbol for trading operation.
	cmd	  -  		Operation type. It can be either OP_BUY or OP_SELL.
	volume	  -  	Number of lots.
 *Sample:
	if(AccountFreeMarginCheck(Symbol(),OP_BUY,Lots)<=0 || GetLastError()==134) return;
*/
double AccountFreeMarginCheck(string symbol, int cmd, double volume);	

/*
 *Calculation mode of free margin allowed to open positions on the current account. The calculation mode can take the following values:

	0 - floating profit/loss is not used for calculation;
	1 - both floating profit and loss on open positions on the current account are used for free margin calculation;
	2 - only profit value is used for calculation, the current loss on open positions is not considered;
	3 - only loss value is used for calculation, the current loss on open positions is not considered.
*/
double AccountFreeMarginMode();


//Returns the value of the corresponding account property. See ENUM_ACCOUNT_INFO_DOUBLE
double  AccountInfoDouble(ENUM_ACCOUNT_INFO_DOUBLE  property_id);
//Returns the value of the corresponding account property. See ENUM_ACCOUNT_INFO_INTEGER
double  AccountInfoInteger(ENUM_ACCOUNT_INFO_INTEGER  property_id);
//Returns the value of the corresponding account property. See ENUM_ACCOUNT_INFO_STRING
double  AccountInfoSTRING(ENUM_ACCOUNT_INFO_STRING  property_id);

#endif