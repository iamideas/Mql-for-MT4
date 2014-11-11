#ifndef DATASTRUCTURES_H_
#define DATASTRUCTURES_H_
#include"DataType.h"
struct MqlDateTime
{
	int year;           // Year
	int mon;            // Month
	int day;            // Day
	int hour;           // Hour
	int min;            // Minutes
	int sec;            // Seconds
	int day_of_week;    // Day of week (0-Sunday, 1-Monday, ... ,6-Saturday)
	int day_of_year;    // Day number of the year (January 1st is assigned the number value of zero)
};

/*
	The MqlParam structure has been specially designed to provide input parameters when creating the handle 
of a technical indicator using the IndicatorCreate() function.
*/
struct MqlParam
{
	ENUM_DATATYPE     type;                    // type of the input parameter, value of ENUM_DATATYPE
	long              integer_value;           // field to store an integer type
	double            double_value;            // field to store a double type
	string            string_value;            // field to store a string type
};

//This structure stores information about the prices, volumes and spread.
struct MqlRates
{
	datetime time;         // Period start time
	double   open;         // Open price
	double   high;         // The highest price of the period
	double   low;          // The lowest price of the period
	double   close;        // Close price
	long     tick_volume;  // Tick volume
	int      spread;       // Spread
	long     real_volume;  // Trade volume
};

//It provides information about the market depth data.
struct MqlBookInfo
{
	ENUM_BOOK_TYPE   type;       // Order type from ENUM_BOOK_TYPE enumeration
	double           price;      // Price
	long             volume;     // Volume
};

/*
	Interaction between the client terminal and a trade server for executing the order placing operation, is 
performed by using trade requests.The trade request is represented by the special predefined structure of 
MqlTradeRequest type, which contain all the fields necessary to perform trade deals.The request processing 
result is represented by the structure of MqlTradeResult type.
*/
struct MqlTradeRequest
{
	ENUM_TRADE_REQUEST_ACTIONS    action;           // Trade operation type
	ulong                         magic;            // Expert Advisor ID (magic number)
	ulong                         order;            // Order ticket
	string                        symbol;           // Trade symbol
	double                        volume;           // Requested volume for a deal in lots
	double                        price;            // Price
	double                        stoplimit;        // StopLimit level of the order
	double                        sl;               // Stop Loss level of the order
	double                        tp;               // Take Profit level of the order
	ulong                         deviation;        // Maximal possible deviation from the requested price
	ENUM_ORDER_TYPE               type;             // Order type
	ENUM_ORDER_TYPE_FILLING       type_filling;     // Order execution type
	ENUM_ORDER_TYPE_TIME          type_time;        // Order expiration type
	datetime                      expiration;       // Order expiration time (for the orders of ORDER_TIME_SPECIFIED type)
	string                        comment;          // Order comment
};


/*
	Before sending a request for a trade operation to a trade server, it is recommended to check it.The check is 
performed using the OrderCheck() function, to which the checked request and a variable of the MqlTradeCheckResult
structure type are passed.The check result will be written to this variable.
*/
struct MqlTradeCheckResult
{
	uint         retcode;             // Reply code
	double       balance;             // Balance after the execution of the deal
	double       equity;              // Equity after the execution of the deal
	double       profit;              // Floating profit
	double       margin;              // Margin requirements
	double       margin_free;         // Free margin
	double       margin_level;        // Margin level
	string       comment;             // Comment to the reply code (description of the error)
};

/*
	As result of a trade request, a trade server returns data about the trade request processing result as a special
predefined structure of MqlTradeResult type.
*/
struct MqlTradeResult
{
	uint     retcode;          // Operation return code
	ulong    deal;             // Deal ticket, if it is performed
	ulong    order;            // Order ticket, if it is placed
	double   volume;           // Deal volume, confirmed by broker
	double   price;            // Deal price, confirmed by broker
	double   bid;              // Current Bid price
	double   ask;              // Current Ask price
	string   comment;          // Broker comment to operation (by default it is filled by the operation description)
	uint     request_id;       // Request ID set by the terminal during the dispatch 
};
/*
	When performing some definite actions on a trade account, its state changes.Such actions include :
		Sending a trade request from any MQL5 application in the client terminal using OrderSend and OrderSendAsync functions 
	and its further execution;
		Sending a trade request via the terminal graphical interface and its further execution;
		Pending orders and stop orders activation on the server;
		Performing operations on a trade server side.

	The following trade transactions are performed as a result of these actions :
		handling a trade request;
		changing open orders;
		changing orders history;
		changing deals history;
		changing positions.
	For example, when sending a market buy order, it is handled, an appropriate buy order is created for the account, the order is then 
executed and removed from the list of the open ones, then it is added to the orders history, an appropriate deal is added to the
history and a new position is created.All these actions are trade transactions.

	Special OnTradeTransaction() handler is provided in MQL5 to get trade transactions applied to an account.The first parameter of 
the handler gets MqlTradeTransaction structure describing trade transactions.
*/
struct MqlTradeTransaction
{
	ulong                         deal;             // Deal ticket
	ulong                         order;            // Order ticket
	string                        symbol;           // Trade symbol name
	ENUM_TRADE_TRANSACTION_TYPE   type;             // Trade transaction type
	ENUM_ORDER_TYPE               order_type;       // Order type
	ENUM_ORDER_STATE              order_state;      // Order state
	ENUM_DEAL_TYPE                deal_type;        // Deal type
	ENUM_ORDER_TYPE_TIME          time_type;        // Order type by action period
	datetime                      time_expiration;  // Order expiration time
	double                        price;            // Price 
	double                        price_trigger;    // Stop limit order activation price
	double                        price_sl;         // Stop Loss level
	double                        price_tp;         // Take Profit level
	double                        volume;           // Volume in lots
};

/*
	This is a structure for storing the latest prices of the symbol.It is designed for fast retrieval of the most requested information 
about current prices.
*/
struct MqlTick
{
	datetime     time;          // Time of the last prices update
	double       bid;           // Current Bid price
	double       ask;           // Current Ask price
	double       last;          // Price of the last deal (Last)
	ulong        volume;        // Volume for the current Last price
};
#endif