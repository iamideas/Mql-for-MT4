
/*************************************************************************
* 单个订单的详细信息以及订单列表的管理
**************************************************************************/
#include"standardCPPLibrary.h"
#include"..\DataType.h"

class Order{
public:
	Order(string symbol, int cmd, double lot, double price, double close, double slippage,
			double stoploss, double takeprofit, string comment, int magic, datetime expiration,
			color arrow_color){
		this->symbol = symbol;
		this->cmd = cmd;
		this->lot = lot;
		this->price = price;
		this->close = close;
		this->slippage = slippage;
		this->stoploss = stoploss;
		this->takeprofit = takeprofit;
		this->comment = comment;
		this->magic = magic;
		this->expiration = expiration;
		this->arrow_color = arrow_color;
	}

	string getSymbol();
	int getCmd();
	double getLot();
	double getPrice();
	double getClose();
	double getSlippage();
	double getStoploss();
	double getTakeprofit();
	string getComment();
	int getMagic();
	datetime getExpiration();
	color getArrow_color();

	~Order(){ /*nothing*/}
private:
	string symbol;
	int	   cmd;
	double lot;
	double price;
	double close;
	double slippage;
	double stoploss;
	double takeprofit;
	string comment;
	int	   magic;
	datetime expiration;
	color  arrow_color;
};

class TradeList{
public:
	typedef vector<Order>::iterator iter;
	
	TradeList(){/*nothing*/}
	virtual iter begin();
	virtual iter end();
	~TradeList(){/*nothing*/}
private:
	vector<Order> list;
};

/*************************************************************************
* Trading Order list
**************************************************************************/

class Trades : TradeList{
	Trades(){/*nothing*/ }
	~Trades(){/*nothing*/}
};
class TradesHistory : TradeList{
	TradesHistory(){/*nothing*/}
	~TradesHistory(){/*nothing*/}
};