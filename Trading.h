//*******************************************
//           Trading functions
//res::http://docs.mql4.com/trading
//*******************************************
#ifndef TRADING_H__
#define TRADING_H__

#include"Framework/standardCPPLibrary.h"
#include"DataType.h"
#include"DataStructures.h"

#define MODE_TRADES  1
#define MODE_HISTORY 2
#define SELECT_BY_POS 1

bool OrderClose(int ticket, double lots, double price, int slippage, color Color=CLR_NONE);
bool OrderCloseBy(int ticket, int opposite, color Color=CLR_NONE);
double OrderClosePrice();
datetime OrderCloseTime();
string OrderComment();
double OrderCommission();
double OrderCommission();
datetime OrderExpiration();
double OrderLots();
int OrderMagicNumber();
bool OrderModify(int ticket, double price, double stoploss, double takeprofit, datetime expiration, 
	             color arrow_color=CLR_NONE);
double OrderOpenPrice();
datetime OrderOpenTime();
void OrderPrint();
double OrderProfit();
bool OrderSelect(int index, int select, int pool=MODE_TRADES);
int OrderSend(string symbol, int cmd, double volume, double price, int slippage, double stoploss, 
              double takeprofit, string comment=NULL, int magic=0, datetime expiration=0, 
			  color arrow_color=CLR_NONE);
int OrdersHistoryTotal();
double OrderStopLoss();
int OrdersTotal();
double OrderSwap();
string OrderSymbol();
double OrderTakeProfit();
int OrderTicket();
int OrderType();


/*
	The function calculates the margin required for the specified order type, on the current account, 
in the current market environment not taking into account current pending orders and open positions. 
It allows the evaluation of margin for the trade operation planned. The value is returned in the account 
currency.
*/
bool  OrderCalcMargin(
	ENUM_ORDER_TYPE       action,           // type of order
	string                symbol,           // symbol name
	double                volume,           // volume
	double                price,            // open price
	double&               margin            // value for obtaining the margin value
);

/*
	The function calculates the profit for the current account, in the current market conditions, based 
on the parameters passed.The function is used for pre - evaluation of the result of a trade operation.
The value is returned in the account currency.
*/
bool  OrderCalcProfit(
	ENUM_ORDER_TYPE       action,           // type of the order (ORDER_TYPE_BUY or ORDER_TYPE_SELL)
	string                symbol,           // symbol name
	double                volume,           // volume
	double                price_open,       // open price
	double                price_close,      // close price
	double&               profit            // variable for obtaining the profit value
);

/*
	The OrderCheck() function checks if there are enough money to execute a required trade operation.
The check results are placed to the fields of the MqlTradeCheckResult structure.
*/
bool  OrderCheck(
	MqlTradeRequest&       request,      // request structure
	MqlTradeCheckResult&   result        // result structure
);

//The OrderSend() function is used for executing trade operations by sending requests to a trade server.
bool  OrderSend(
	MqlTradeRequest&  request,      // query structure
	MqlTradeResult&   result        // structure of the answer
);

/*
	The OrderSendAsync() function is used for conducting asynchronous trade operations without waiting for 
the trade server's response to a sent request. The function is designed for high-frequency trading, 
when under the terms of the trading algorithm it is unacceptable to waste time waiting for a response 
from the server.
*/
bool  OrderSendAsync(
	MqlTradeRequest&  request,      // Request structure
	MqlTradeResult&   result        // Response structure
);

//Returns the number of open positions.
int  PositionsTotal();

/*
	Returns the symbol corresponding to the open position and automatically selects the position for further 
working with it using functions PositionGetDouble, PositionGetInteger, PositionGetString.
*/
string  PositionGetSymbol(
	int  index      // Number in the list of positions
);

/*
	Chooses an open position for further working with it.Returns true if the function is successfully 
completed.Returns false in case of failure.To obtain information about the error, call GetLastError().
*/
bool  PositionSelect(
	string  symbol      // Symbol name
);

/*
	The function returns the requested property of an open position, pre - selected using PositionGetSymbol 
or PositionSelect.The position property must be of the double type.There are 2 variants of the function.
	1. Immediately returns the property value..
*/
double  PositionGetDouble(ENUM_POSITION_PROPERTY_DOUBLE  property_id );
/*
	2. Returns true or false, depending on the success of the function execution.If successful, the value
of the property is placed in a receiving variable passed by reference by the last parameter.
*/
bool  PositionGetDouble(
	ENUM_POSITION_PROPERTY_DOUBLE  property_id,     // Property identifier
	double&                        double_var       // Here we accept the property value
);

/*
	The function returns the requested property of an open position, pre - selected using PositionGetSymbol
or PositionSelect.The position property should be of datetime, int type.There are 2 variants of the function.
	1. Immediately returns the property value.
*/
long  PositionGetInteger(ENUM_POSITION_PROPERTY_INTEGER  property_id );
/*
	2. Returns true or false, depending on the success of the function execution.If successful, the value of
the property is placed in a receiving variables passed by reference by the last parameter.
*/
bool  PositionGetInteger(
	ENUM_POSITION_PROPERTY_INTEGER  property_id,     // Property identifier
	long&                           long_var         // Here we accept the property value
);

/*
	The function returns the requested property of an open position, pre - selected using PositionGetSymbol or
PositionSelect.The position property should be of the string type.There are 2 variants of the function.
	1. Immediately returns the property value.
*/
string  PositionGetString(ENUM_POSITION_PROPERTY_STRING  property_id  );
/*
	2. Returns true or false, depending on the success of the function execution.If successful, the value of the
property is placed in a receiving variables passed by reference by the last parameter.
*/
bool  PositionGetString(
	ENUM_POSITION_PROPERTY_STRING  property_id,     // Property identifier
	string&                        string_var       // Here we accept the property value
);

//Returns ticket of a corresponding order automatically selects the order for further working with it using functions.
ulong  OrderGetTicket(
	int  index      // Number in the list of orders
);

/*
	Selects an order to work with.Returns true if the function has been successfully completed.Returns false if the
function completion has failed.For more information about an error call GetLastError().
*/
bool  OrderSelect(ulong   ticket);

/*
	Returns the requested property of an order, pre - selected using OrderGetTicket or OrderSelect.The order property 
must be of the double type.There are 2 variants of the function.
	1. Immediately returns the property value.
*/
double  OrderGetDouble(ENUM_ORDER_PROPERTY_DOUBLE  property_id  );
/*
	2. Returns true or false, depending on the success of a function.If successful, the value of the property is placed 
in a target variable passed by reference by the last parameter.
*/
bool  OrderGetDouble(
	ENUM_ORDER_PROPERTY_DOUBLE  property_id,       // Property identifier
	double&                        double_var         // Here we accept the property value
);

/*
	Returns the requested order property, pre - selected using OrderGetTicket or OrderSelect.Order property must be 
of the datetime, int type.There are 2 variants of the function.
	1. Immediately returns the property value.
*/
long  OrderGetInteger(ENUM_ORDER_PROPERTY_INTEGER  property_id );
/*
	2. Returns true or false depending on the success of the function.If successful, the value of the property 
is placed into a target variable passed by reference by the last parameter.
*/
bool  OrderGetInteger(
	ENUM_ORDER_PROPERTY_INTEGER  property_id,       // Property identifier
	long&                        long_var           // Here we accept the property value
);

/*
	Returns the requested order property, pre - selected using OrderGetTicket or OrderSelect.The order property 
must be of the string type.There are 2 variants of the function.
	1. Immediately returns the property value.
*/
string  OrderGetString(ENUM_ORDER_PROPERTY_STRING  property_id );
/*
	2. Returns true or false, depending on the success of the function.If successful, the value of the property 
is placed into a target variable passed by reference by the last parameter.
*/
bool  OrderGetString(
	ENUM_ORDER_PROPERTY_STRING  property_id,       // Property identifier
	string&                     string_var         // Here we accept the property value
);

//Retrieves the history of deals and orders for the specified period of server time.
bool  HistorySelect(
	datetime  from_date,     // From date
	datetime  to_date        // To date
);

//Retrieves the history of deals and orders having the specified position identifier.
bool  HistorySelectByPosition(
	long   position_id     // position identifier - POSITION_IDENTIFIER
);

/*
	Selects an order from the history for further calling it through appropriate functions.It returns true
if the function has been successfully completed.Returns false if the function has failed.For more details on
error call GetLastError().
*/
bool  HistoryOrderSelect(
	ulong  ticket      // Order ticket
);

/*
	Returns the number of orders in the history.Prior to calling HistoryOrdersTotal(), first it is necessary 
to receive the history of deals and orders using the HistorySelect() or HistorySelectByPosition() function.
*/
int  HistoryOrdersTotal();

/*
	Return the ticket of a corresponding order in the history.Prior to calling HistoryOrderGetTicket(), 
first it is necessary to receive the history of deals and orders using the HistorySelect() or 
HistorySelectByPosition() function.
*/
ulong  HistoryOrderGetTicket(
	int  index      // Number in the list of orders
);

/*
	Returns the requested order property.The order property must be of the double type.There are 2 variants of the function.
	1. Immediately returns the property value.
*/
double  HistoryOrderGetDouble(
	ulong                       ticket_number,     // Ticket
	ENUM_ORDER_PROPERTY_DOUBLE  property_id        // Property identifier
);
/*
	2. Returns true or false, depending on the success of the function.If successful, the value of the property 
is placed into a target variable passed by reference by the last parameter.
*/
bool  HistoryOrderGetDouble(
	ulong                       ticket_number,     // Ticket
	ENUM_ORDER_PROPERTY_DOUBLE  property_id,       // Property identifier
	double&                     double_var         // Here we accept the property value
);

/*
	Returns the requested property of an order.The order property must be of datetime, int type.There are 2 variants 
of the function.
	1. Immediately returns the property value.
*/
long  HistoryOrderGetInteger(
	ulong                        ticket_number,     // Ticket
	ENUM_ORDER_PROPERTY_INTEGER  property_id        // Property identifier
);
/*
	2. Returns true or false, depending on the success of the function.If successful, the value of the property is 
placed into a target variable passed by reference by the last parameter.
*/
bool  HistoryOrderGetInteger(
	ulong                        ticket_number,     // Ticket
	ENUM_ORDER_PROPERTY_INTEGER  property_id,       // Property identifier
	long&                        long_var           // Here we accept the property value
);

/*
	Returns the requested property of an order.The order property must be of the string type.There are 2 variants 
of the function.
	1. Immediately returns the property value.
*/
string  HistoryOrderGetString(
	ulong                       ticket_number,     // Ticket
	ENUM_ORDER_PROPERTY_STRING  property_id        // Property identifier
);
/*
	2. Returns true or false, depending on the success of the function.If successful, the value of the property 
is placed into a target variable passed by reference by the last parameter.
*/
bool  HistoryOrderGetString(
	ulong                       ticket_number,     // Ticket
	ENUM_ORDER_PROPERTY_STRING  property_id,       // Property identifier
	string&                     string_var         // Here we accept the property value
);

/*
	Selects a deal in the history for further calling it through appropriate functions.It returns true if the 
function has been successfully completed.Returns false if the function has failed.For more details on error 
call GetLastError().
*/
bool  HistoryDealSelect(ulong  ticket);

/*
	Returns the number of deal in history.Prior to calling HistoryDealsTotal(), first it is necessary to 
receive the history of deals and orders using the HistorySelect() or HistorySelectByPosition() function.
*/
int  HistoryDealsTotal();

/*
	The function selects a deal for further processing and returns the deal ticket in history.Prior to 
calling HistoryDealGetTicket(), first it is necessary to receive the history of deals and orders using 
the HistorySelect() or HistorySelectByPosition() function.
*/
ulong  HistoryDealGetTicket(int  index);

/*
	Returns the requested property of a deal.The deal property must be of the double type.There are 2 
variants of the function.
	1. Immediately returns the property value.
*/
double  HistoryDealGetDouble(
	ulong                      ticket_number,     // Ticket
	ENUM_DEAL_PROPERTY_DOUBLE  property_id        // Property identifier
);
/*
	2. Returns true or false, depending on the success of the function.If successful, the value of the 
property is placed into a target variable passed by reference by the last parameter.
*/
bool  HistoryDealGetDouble(
	ulong                      ticket_number,     // Ticket
	ENUM_DEAL_PROPERTY_DOUBLE  property_id,       // Property identifier
	double&                    double_var         // Here we accept the property value
);

/*
	Returns the requested property of a deal.The deal property must be of the datetime, int type.There are 2
variants of the function.
	1. Immediately returns the property value.
*/
long  HistoryDealGetInteger(
	ulong                       ticket_number,     // Ticket
	ENUM_DEAL_PROPERTY_INTEGER  property_id        // Property identifier
);
/*
	2. Returns true or false, depending on the success of the function.If successful, the value of the property
is placed into a target variable passed by reference by the last parameter.
*/
bool  HistoryDealGetInteger(
	ulong                       ticket_number,     // Ticket
	ENUM_DEAL_PROPERTY_INTEGER  property_id,       // Property identifier
	long&                       long_var           // Here we accept the property value
);

/*
	Returns the requested property of a deal.The deal property must be of the string type.There are 2 variants 
of the function.
	1. Immediately returns the property value.
*/
string  HistoryDealGetString(
	ulong                      ticket_number,     // Ticket
	ENUM_DEAL_PROPERTY_STRING  property_id        // Property identifier
);
/*
	2. Returns true or false, depending on the success of the function.If successful, the value of the property 
is placed into a target variable passed by reference by the last parameter.
*/
bool  HistoryDealGetString(
	ulong                      ticket_number,     // Ticket
	ENUM_DEAL_PROPERTY_STRING  property_id,       // Property identifier
	string&                    string_var         // Here we accept the property value
);


#endif
