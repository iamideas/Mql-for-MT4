/****************************************************************
 *                   MT4Library for mt4editer                  *
 *                            by ideas                          *
 ****************************************************************/
#ifndef DATATYPE_H__
#define DATATYPE_H__

#include"Framework\standardCPPLibrary.h"

typedef unsigned  color;
typedef int		  stacksize;	//stack size
#define library					//a library; no start function is assigned, non-referenced function are not removed

#define _MQL4_
#define _MQL5_
#define _DEBUG
#define _RELEASE

typedef unsigned long ulong;
typedef unsigned int  uint;
typedef unsigned char uchar;
typedef unsigned short ushort;
//********************************************
//           Controlling compilation
//res::http://docs.mql4.com/cn/basis/preprosessor/compilation
//********************************************
typedef void	indicator_chart_window;	// show the indicator in the chart whindow
typedef void	indicator_separate_window; // show the indicator in a separate window
typedef int		indicator_buffer;			// the number of buffers for calculation, up to 8
typedef double	indicator_minimum;		// the bottom scaling limit for a separate indicator window
typedef double	indicator_maximum;		// the top scaling limit for a separate indicator window
typedef color	indicator_colorN;		// the color for displaying line N, where N lies between 1 and 8
typedef int		indicator_widthN;		// width of the line N, where N lies between 1 and 8
typedef int		indicator_styleN;		// style of the line N, where N lies between 1 and 8
typedef double	indicator_levelN;		// predefined level N for separate window custom indicator, where N liew between 1 and 8
typedef color	indicator_levelcolor;	// level line color
typedef int		indicator_levelwidth;	// level line width
typedef int		indicator_levelstyle;	// level line style

//res::http://www.mql5.com/en/docs/basis/preprosessor/compilation
typedef int indicator_applied_price; //Specifies the default value for the "Apply to" field. You can specify one of the value of
									//ENUM_APPLIED_PRICE. if the property is not specified, the default value is PRICE_CLOSE
typedef int indicator_height;		//Fixed height of the indicator subwindow in pixels(property INDICATOR_HEIGHT)
typedef int indicator_plots;		// Number of graphic series in the indicator
typedef string indicator_labelN;    //Sets a label for the N - th graphic series displayed in DataWindow.For graphic series 
									//requiring multiple indicator buffers(DRAW_CANDLES, DRAW_FILLING and others), the tag names
									//are defined by the separator ';'.
typedef color indicator_colorN;		//The color for displaying line N, where N is the number of graphic series; numbering starts from 1
typedef int	indicator_widthN;		//Line thickness in graphic series, where N - number of graphic series, numbering starts from 1
typedef int indicator_styleN;		//Line style in graphic series, specified by the values of ENUM_LINE_STYLE.N - number of graphic series, numbering starts from 1
typedef int indicator_typeN;		//Type of graphical plotting, specified by the values of ENUM_DRAW_TYPE.N - number of graphic series, numbering starts from 1
typedef double indicator_levelN;	//Horizontal level of N in a separate indicator window
typedef color indicator_levelcolor;	//Color of horizontal levels of the indicator
typedef int indicator_levelwidth;   //Thickness of horizontal levels of the indicator
typedef int indicator_levelstyle;	//Style of horizontal levels of the indicator
typedef void script_show_confirm;	//Display a confirmation window before running the script
typedef void script_show_inputs;	//Display a window with the properties before running the script and disable this confirmation window

//********************************************
//              Series arrays
//res::http://docs.mql4.com/constants/series
//********************************************
#define MODE_OPEN		0	// open price
#define MODE_LOW		1	// low price
#define MODE_HIGH		2	// High price
#define MODE_CLOSE		3	// Close price
#define MODE_VOLUME		4	// Volume, used in iLowest() and iHighest() functions.
#define MODE_TIME		5	// Bar open time, used in ArrayCopySeries() fucntion

//********************************************
//                Timeframes
//res::http://docs.mql4.com/constants/timeframes
//********************************************
enum ENUM_TIMEFRAMES{
	PERIOD_CURRENT, //Current timeframe
	PERIOD_M1, //1 minute
	PERIOD_M2, //2 minutes
	PERIOD_M3, //	3 minutes
	PERIOD_M4, //4 minutes
	PERIOD_M5, //5 minutes
	PERIOD_M6, //6 minutes
	PERIOD_M10, //10 minutes
	PERIOD_M12, //12 minutes
	PERIOD_M15, //15 minutes
	PERIOD_M20, //20 minutes
	PERIOD_M30, //30 minutes
	PERIOD_H1, //1 hour
	PERIOD_H2, //2 hours
	PERIOD_H3, //3 hours
	PERIOD_H4, //4 hours
	PERIOD_H6, //6 hours
	PERIOD_H8, //8 hours
	PERIOD_H12, //12 hours
	PERIOD_D1, //1 day
	PERIOD_W1, //1 week
	PERIOD_MN1 //1 month
};

//********************************************
//          
//res::
//********************************************
#define OP_BUY			0	// Buying position.
#define OP_SELL			1	// Selling position.
#define OP_BUYLIMIT		2	// Buy limit pending position.
#define OP_SELLLIMIT	3	// Sell limit pending position.
#define OP_BUYSTOP		4	// Buy stop pending position.
#define OP_SELLSTOP		5	// Sell stop pending position.

//*******************************************
//          Price constants
//res::http://www.mql5.com/en/docs/constants/indicatorconstants/prices
//*******************************************
enum ENUM_APPLIED_PRICE{
	PRICE_CLOSE,		// Close price.
	PRICE_OPEN,			// Open price.
	PRICE_HIGH,			// High price.
	PRICE_LOW,			// Low price.
	PRICE_MEDIAN,		// Median price, (high+low)/2.
	PRICE_TYPICAL,		// Typical price, (high+low+close)/3.
	PRICE_WEIGHTED,		// Weighted close price, (high+low+close+close)/4.
};
enum ENUM_APPLIED_VOLUME{
	VOLUME_TICK, //Tick volume
	VOLUME_REAL  //Trade volume
};

enum ENUM_STO_PRICE{
	STO_LOWHIGH,  //Calculation is based on Low/High prices
	STO_CLOSECLOSE, //Calculation is based on Close/Close prices
};


#define MODE_LOW				1		// Low day price.
#define MODE_HIGH				2		// High day price.
#define MODE_TIME				5		// The last incoming tick time (last known server time).
#define MODE_BID				9		// Last incoming bid price. For the current symbol, it is stored in the predefined variable Bid
#define MODE_ASK				10		// Last incoming ask price. For the current symbol, it is stored in the predefined variable Ask
#define MODE_POINT				11		// Point size in the quote currency. For the current symbol, it is stored in the predefined variable Point
#define MODE_DIGITS				12		// Count of digits after decimal point in the symbol prices. For the current symbol, it is stored in the --
										//predefined variable Digits
#define MODE_SPREAD				13		// Spread value in points.
#define MODE_STOPLEVEL			14		// Stop level in points.
#define MODE_LOTSIZE			15		// Lot size in the base currency.
#define MODE_TICKVALUE			16		// Tick value in the deposit currency.
#define MODE_TICKSIZE			17		// Tick size in points.
#define MODE_SWAPLONG			18		// Swap of the long position.
#define MODE_SWAPSHORT			19		// Swap of the short position.
#define MODE_STARTING			20		// Market starting date (usually used for futures).
#define MODE_EXPIRATION			21		// Market expiration date (usually used for futures).
#define MODE_TRADEALLOWED		22		// Trade is allowed for the symbol.
#define MODE_MINLOT				23		// Minimum permitted amount of a lot.
#define MODE_LOTSTEP			24		// Step for changing lots.
#define MODE_MAXLOT				25		// Maximum permitted amount of a lot.
#define MODE_SWAPTYPE			26		// Swap calculation method. 0 - in points; 1 - in the symbol base currency; 2 - by interest; 3 - in the margin currency.
#define MODE_PROFITCALCMODE		27		// Profit calculation mode. 0 - Forex; 1 - CFD; 2 - Futures.
#define MODE_MARGINCALCMODE		28		// Margin calculation mode. 0 - Forex; 1 - CFD; 2 - Futures; 3 - CFD for indices.
#define MODE_MARGININIT			29		// Initial margin requirements for 1 lot.
#define MODE_MARGINMAINTENANCE	30		// Margin to maintain open positions calculated for 1 lot.
#define MODE_MARGINHEDGED		31		// Hedged margin calculated for 1 lot.
#define MODE_MARGINREQUIRED		32		// Free margin required to open 1 lot for buying.
#define MODE_FREEZELEVEL		33		// Order freeze level in points. If the execution price lies within the range defined by the freeze level, --
										// the order cannot be modified, cancelled or closed.

//*******************************************
//          Drawing styles
//res::http://docs.mql4.com/constants/drawstyles
//*******************************************
//Drawing shape style enumeration for SetIndexStyle() function.

enum ENUM_DRAW_TYPE{
//	ID					Description									Data buffers				Color buffers
	DRAW_NONE,			//Not drawn									1							0
	DRAW_LINE,			//Line										1							0
	DRAW_SECTION,		//Section									1							0
	DRAW_HISTOGRAM,		//Histogram from the zero line				1							0
	DRAW_HISTOGRAM2,		//Histogram of the two indicator buffers	2							0
	DRAW_ARROW,			//Drawing arrows							1							0
	DRAW_ZIGZAG,		//Style Zigzag allows vertical section on the bar		2					0
	DRAW_FILLING,		//Color fill between the two levels			2							0
	DRAW_BARS,			//Display as a sequence of bars				4							0
	DRAW_CANDLES,		//Display as a sequence of candlesticks		4							0
	DRAW_COLOR_LINE,	//Multicolored line							1							1
	DRAW_COLOR_SECTION,	//Multicolored section						1							1
	DRAW_COLOR_HISTOGRAM,	//Multicolored histogram from the zero line 1							1
	DRAW_COLOR_HISTOGRAM2,	//Multicolored histogram of the two indicator buffers 2				1
	DRAW_COLOR_ARROW,	//Drawing multicolored arrows				1							1
	DRAW_COLOR_ZIGZAG,	//Multicolored ZigZag						2							1
	DRAW_COLOR_BARS,    //Multicolored bars							4							1
	DRAW_COLOR_CANDLES,	//Multicolored candlesticks					4							1
};

/*
	To refine the display of the selected drawing type identifiers listed in ENUM_PLOT_PROPERTY are used.
	For functions PlotIndexSetInteger() and PlotIndexGetInteger() with complex graphical styles requiring
several indicator buffers for display, the namesfor each buffer can be specified using ";" as a separator. 
Sample code is shown in DRAW_CANDLES (for PlotIndexSetString())
*/
enum ENUM_PLOT_PROPERTY_INTEGER{
	 PLOT_ARROW,		//int Arrow code for style DRAW_ARROW
	 PLOT_ARROW_SHIFT, //int Vertical shift of arrows for style DRAW_ARROW
	 PLOT_DRAW_BEGIN,  //int Number of initial bars without drawing and values in the DataWindow
	 PLOT_DRAW_TYPE,	//ENUM_DRAW_TYPE Type of graphical construction					 
	 PLOT_SHOW_DATA,	//bool Sign of display of construction values in the DataWindow
	 PLOT_SHIFT,		//int Shift of indicator plotting along the time axis in bars
	 PLOT_LINE_STYLE,	//ENUM_LINE_STYLE Drawing line style					  				 
	 PLOT_LINE_WIDTH,  //int The thickness of the drawing line
	 PLOT_COLOR_INDEXES, //int The number of colors
	 PLOT_LINE_COLOR,	//color The index of a buffer containing the drawing color  modifier = index number of colors
	 PLOT_EMPTY_VALUE,	//double An empty value for plotting, for which there is no drawing ( for PlotIndexSetDouble())
	 PLOT_LABEL			//string The name of the indicator graphical series to display in the DataWindow. When working

};

//Drawing style. Valid when width=1. It can be any of the following values:
enum ENUM_LINE_STYLE{
	STYLE_SOLID,			// The pen is solid.
	STYLE_DASH,				// The pen is dashed.
	STYLE_DOT,				// The pen is dotted.
	STYLE_DASHDOT,			// The pen has alternating dashes and dots.
	STYLE_DASHDOTDOT,		// The pen has alternating dashes and double dots.
};

//*******************************************
//          Arrow codes
//res::http://docs.mql4.com/constants/arrows
//All sign in::http://docs.mql4.com/constants/wingdings
//*******************************************
#define SYMBOL_THUMBSUP		67	// Thumb up symbol (C).
#define SYMBOL_THUMBSDOWN	68	// Thumb down symbol (D).
#define SYMBOL_ARROWUP		241	// Arrow up symbol (ñ).
#define SYMBOL_ARROWDOWN	242	// Arrow down symbol (ò).
#define SYMBOL_STOPSIGN		251	// Stop sign symbol (û).
#define SYMBOL_CHECKSIGN	252	// Check sign symbol (ü).

#define SYMBOL_LEFTPRICE	5	// Left sided price label.
#define SYMBOL_RIGHTPRICE	6	// Right sided price label.

//*******************************************
//          indicator lines
//res::http://www.mql5.com/en/docs/constants/indicatorconstants/lines
//*******************************************
//Indicator line identifiers used in iMACD(), iRVI() and iStochastic() indicators.
//It can be one of the following values:
#define MAIN_LINE			0	// Base indicator line.
#define SIGNAL_LINE			1	// Signal line.
#define MODE_MAIN			0
#define MODE_SIGNAL			1

//Indicator line identifiers used in iADX() indicator.
#define MAIN_LINE			0	// Base indicator line.
#define PLUSDI_LINE			1	// +DI indicator line.
#define MINUSDI_LINE		2	// -DI indicator line.

//Indicator line identifiers used in iBands(), iEnvelopes(), iEnvelopesOnArray(),
#define BASE_LINE			0   //Main line
#define UPPER_BAND			1   //Upper limit
#define LOWER_BAND          2   //Lower limit

//iFractals() and iGator() indicators.
#define UPPER_LINE			1	// Upper line.
#define LOWER_LINE			2	// Lower line.

//....
enum ENUM_INDEXBUFFER_TYPE {
	INDICATOR_DATA, //Data to draw
	INDICATOR_COLOR_INDEX, //Color
	INDICATOR_CALCULATIONS 	//Auxiliary buffers for intermediate calculations
};

//	  A custom indicator has a lot of settings to provide convenient displaying.These settings are made
//through the assignment of corresponding indicator properties using functions IndicatorSetDouble(), 
//IndicatorSetInteger() and IndicatorSetString().Identifiers of indicator properties are listed in the ENUM_CUSTOMIND_PROPERTY enumeration.
enum ENUM_CUSTOMIND_PROPERTY_INTEGER{
	INDICATOR_DIGITS, //int Accuracy of drawing of indicator values
	INDICATOR_HEIGHT, //int Fixed height of the indicator's window (the preprocessor command #property indicator_height)
	INDICATOR_LEVELS, //int Number of levels in the indicator window
	INDICATOR_LEVELCOLOR, //color Color of the level line modifier = level number
	INDICATOR_LEVELSTYLE,  //ENUM_LINE_STYLE Style of the level line 
	INDICATOR_LEVELWIDTH   //int Thickness of the level line  modifier = level number
};

enum ENUM_CUSTOMIND_PROPERTY_DOUBLE{
 INDICATOR_MINIMUM, //double Minimum of the indicator window
 INDICATOR_MAXIMUM, //double Maximum of the indicator window
 INDICATOR_LEVELVALUE //double Level value modifier = level number
};

enum ENUM_CUSTOMIND_PROPERTY_STRING{
	INDICATOR_SHORTNAME, //string  Short indicator name
	INDICATOR_LEVELTEXT  //string Level description modifier = level number
};
enum ENUM_INDICATOR{
	IND_AC, 
	IND_AD, //Accumulation  Distribution
	IND_ADX, //	Average Directional Index
	IND_ADXW, //ADX by Welles Wilder
	IND_ALLIGATOR, //Alligator
	IND_AMA, //	Adaptive Moving Average
	IND_AO, //Awesome Oscillator
	IND_ATR, //	Average True Range
	IND_BANDS, //Bollinger Bands®
	IND_BEARS, //Bears Power
	IND_BULLS, //Bulls Power
	IND_BWMFI, //Market Facilitation Index
	IND_CCI, //Commodity Channel Index
	IND_CHAIKIN, //Chaikin Oscillator
	IND_CUSTOM, //Custom indicator
	IND_DEMA, //Double Exponential Moving Average
	IND_DEMARKER, //DeMarker
	IND_ENVELOPES, //Envelopes
	IND_FORCE, //Force Index
	IND_FRACTALS, //Fractals
	IND_FRAMA, //Fractal Adaptive Moving Average
	IND_GATOR, //Gator Oscillator
	IND_ICHIMOKU, //Ichimoku Kinko Hyo
	IND_MA, //Moving Average
	IND_MACD, //MACD
	IND_MFI, //Money Flow Index
	IND_MOMENTUM, //Momentum
	IND_OBV, //On Balance Volume
	IND_OSMA, //OsMA
	IND_RSI, //	Relative Strength Index
	IND_RVI, //Relative Vigor Index
	IND_SAR, //	Parabolic SAR
	IND_STDDEV, //Standard Deviation
	IND_STOCHASTIC, //Stochastic Oscillator
	IND_TEMA, //Triple Exponential Moving Average
	IND_TRIX, //Triple Exponential Moving Averages Oscillator
	IND_VIDYA, //Variable Index Dynamic Average
	IND_VOLUMES, //Volumes
	IND_WPR //Williams' Percent Range
};

enum ENUM_DATATYPE{
	TYPE_BOOL,
	TYPE_CHAR,
	TYPE_UCHAR,
	TYPE_SHORT,
	TYPE_USHORT,
	TYPE_COLOR,
	TYPE_INT,
	TYPE_UINT,
	TYPE_DATETIME,
	TYPE_LONG,
	TYPE_ULONG,
	TYPE_FLOAT,
	TYPE_DOUBLE,
	TYPE_STRING
};



//*******************************************
//          Files mode
//res::http://www.mql5.com/en/docs/constants/io_constants/fileflags
//*******************************************
/*
	File is opened for reading.Flag is used in FileOpen().When opening a file specification of FILE_WRITE and / or
FILE_READ is required.
*/
#define FILE_READ 1 
/*
	File is opened for writing.Flag is used in FileOpen().When opening a file specification of FILE_WRITE and /
or FILE_READ is required.
*/
#define FILE_WRITE 2 
//Binary read  write mode(without string to string conversion).Flag is used in FileOpen()
#define FILE_BIN 4 
/*
	CSV file(all its elements are converted to strings of the appropriate type, unicode or ansi, and separated by
separator).Flag is used in FileOpen()
*/
#define FILE_CSV 8 
//Simple text file(the same as csv file, but without taking into account the separators).Flag is used in FileOpen()
#define FILE_TXT 16
//Strings of ANSI type(one byte symbols).Flag is used in FileOpen()
#define FILE_ANSI 32 
//Strings of UNICODE type(two byte symbols).Flag is used in FileOpen()
#define FILE_UNICODE 64 
/*
	Shared access for reading from several programs.Flag is used in FileOpen(), but it does not replace the necessity to 
indicate FILE_WRITE and / or the FILE_READ flag when opening a file.
*/
#define FILE_SHARE_READ 128 
/*
	Shared access for writing from several programs.Flag is used in FileOpen(), but it does not replace the necessity to
indicate FILE_WRITE and / or the FILE_READ flag when opening a file.
*/
#define FILE_SHARE_WRITE 256 
/*
	Possibility for the file rewrite using functions FileCopy() and FileMove().The file should exist or should be opened for 
writing, otherwise the file will not be opened.
*/
#define FILE_REWRITE 512 
/*
	The file path in the common folder of all client terminals \Terminal\Common\Files.Flag is used in FileOpen(), FileCopy(), 
FileMove() and in FileIsExist() functions.
*/
#define FILE_COMMON 4096 
#define INVALID_HANDLE -1 //Incorrect handle


//--------------File Properties
/*
	The FileGetInteger() function is used for obtaining file properties.The identifier of the required property from the
	ENUM_FILE_PROPERTY_INTEGER enumeration is passed to it during call.
*/
enum ENUM_FILE_PROPERTY_INTEGER{
	FILE_EXISTS, //	Check the existence
	FILE_CREATE_DATE, //Date of creation
	FILE_MODIFY_DATE, //Date of the last modification
	FILE_ACCESS_DATE, //Date of the last access to the file
	FILE_SIZE, //File size in bytes
	FILE_POSITION, //Position of a pointer in the file
	FILE_END, //Get the end of file sign
	FILE_LINE_END, //Get the end of line sign
	FILE_IS_COMMON, //The file is opened in a shared folder of all terminals(see FILE_COMMON)
	FILE_IS_TEXT, //The file is opened as a text file(see FILE_TXT)
	FILE_IS_BINARY, //The file is opened as a binary file(see FILE_BIN)
	FILE_IS_CSV, //The file is opened as CSV(see FILE_CSV)
	FILE_IS_ANSI, //The file is opened as ANSI(see FILE_ANSI)
	FILE_IS_READABLE, //The opened file is readable(see FILE_READ)
	FILE_IS_WRITABLE //The opened file is writable(see FILE_WRITE)
};

enum ENUM_FILE_POSITION{
	SEEK_SET, //File beginning
	SEEK_CUR, //Current position of a file pointer
	SEEK_END  //File end
};


//*******************************************
//           Ichimoku Kinko Hyo
//res::http://docs.mql4.com/constants/ichimoku
//*******************************************
//Ichimoku Kinko Hyo identifiers used in iIchimoku() indicator call as source of requested data.
//It can be one of the following values:
#define MODE_TENKANSEN		1	// Tenkan-sen.
#define MODE_KIJUNSEN		2	// Kijun-sen.
#define MODE_SENKOUSPANA	3	// Senkou Span A.
#define MODE_SENKOUSPANB	4	// Senkou Span B.
#define MODE_CHINKOUSPAN	5	// Chinkou Span.

//*******************************************
//           Smoothing Methods
//res::http://www.mql5.com/en/docs/constants/indicatorconstants/enum_ma_method
//*******************************************
enum ENUM_MA_METHOD{
	MODE_SMA,				// Simple moving average,
	MODE_EMA,				// Exponential moving average,
	MODE_SMMA,				// Smoothed moving average,
	MODE_LWMA				// Linear weighted moving average.
};

//*******************************************
//           MessageBox
//res::http://docs.mql4.com/constants/messagebox
//*******************************************
//Detail see the WinUser32.h

//*******************************************
//           Object types
//res::http://www.mql5.com/en/docs/constants/objectconstants/enum_object
//*******************************************
enum ENUM_OBJECT{
	OBJ_VLINE, //vertical_line
	OBJ_HLINE, //Horizontal Line
	OBJ_TREND, //Trend Line
	OBJ_TRENDBYANGLE, //trend_line)by_angle
	OBJ_CYCLES, //Cycle Lines
	OBJ_ARROWED_LINE, //Arrowed Line
	OBJ_CHANNEL, //Equidistant Channel
	OBJ_STDDEVCHANNEL, //Standard Deviation Channel
	OBJ_REGRESSION, //Linear Regression Channel
	OBJ_PITCHFORK, //Andrews Pitchfork
	OBJ_GANNLINE, //Gann Line
	OBJ_GANNFAN, //Gann Fan
	OBJ_GANNGRID, //Gann Grid
	OBJ_FIBO, //Fibonacci Retracement
	OBJ_FIBOTIMES, //Fibonacci Time Zones
	OBJ_FIBOFAN, //Fibonacci Fan
	OBJ_FIBOARC, //Fibonacci Arcs
	OBJ_FIBOCHANNEL, //Fibonacci Channel
	OBJ_EXPANSION, //Fibonacci Expansion
	OBJ_ELLIOTWAVE5, //Elliott Motive Wave
	OBJ_ELLIOTWAVE3, //Elliott Correction Wave
	OBJ_RECTANGLE, //Rectangle
	OBJ_TRIANGLE, //Triangle
	OBJ_ELLIPSE, //Ellipse
	OBJ_ARROW_THUMB_UP, //Thumbs Up
	OBJ_ARROW_THUMB_DOWN, //Thumbs Down
	OBJ_ARROW_UP, //Arrow Up
	OBJ_ARROW_DOWN, //Arrow Down
	OBJ_ARROW_STOP, //Stop Sign
	OBJ_ARROW_CHECK, //Check Sign
	OBJ_ARROW_LEFT_PRICE, //Left Price Label
	OBJ_ARROW_RIGHT_PRICE, //Right Price Label
	OBJ_ARROW_BUY, //Buy Sign
	OBJ_ARROW_SELL, //Sell Sign
	OBJ_ARROW, //Arrow
	OBJ_TEXT, //Text
	OBJ_LABEL, //Label
	OBJ_BUTTON, //Button
	OBJ_CHART, //Chart
	OBJ_BITMAP, //Bitmap
	OBJ_BITMAP_LABEL, //Bitmap Label
	OBJ_EDIT, //Edit
	OBJ_EVENT, //The "Event" object corresponding to an event in the economic calendar
	OBJ_RECTANGLE_LABEL //The "Rectangle label" object for creating and designing the custom graphical interface.
};

//-----------------------Object properties
//res:: http://www.mql5.com/en/docs/constants/objectconstants/enum_object_property
//For functions ObjectSetInteger() and ObjectGetInteger()

enum ENUM_OBJECT_PROPERTY_INTEGER{
	OBJPROP_COLOR,	//color
	OBJPROP_STYLE,	//ENUM_LINE_STYLE  Style 
	OBJPROP_WIDTH,	//int   Line thickness
	OBJPROP_BACK,	//bool Object in the background
	/*
		long Priority of a graphical object for receiving events of clicking on a chart(CHARTEVENT_CLICK).The
	default zero value is set when creating an object; the priority can be increased if necessary.When
	applying objects one over another, only one of them with the highest priority will receive the 
	CHARTEVENT_CLICK event.
	*/
	OBJPROP_ZORDER, 
	/*
		bool Fill an object with color(for OBJ_RECTANGLE, OBJ_TRIANGLE, OBJ_ELLIPSE, OBJ_CHANNEL, OBJ_STDDEVCHANNEL,
	/OBJ_REGRESSION)
	*/
	OBJPROP_FILL,
	/*
		bool Prohibit showing of the name of a graphical object in the list of objects from the terminal menu 
	"Charts" - "Objects" - "List of objects".The true value allows to hide an object from the list.By 
	default, true is set to the objects that display calendar events, trading history and to the objects 
	created from MQL5 programs.To see such graphical objects and access their properties, click on the 
	"All" button in the "List of objects" window.
	*/
	OBJPROP_HIDDEN, 
	OBJPROP_SELECTED,	//bool Object is selected
	OBJPROP_READONLY,	//bool  Ability to edit text in the Edit object
	OBJPROP_TYPE,		//ENUM_OBJECT Object type of    r / o
	OBJPROP_TIME,		//datetime  Time coordinate modifier = number of anchor point
	OBJPROP_SELECTABLE, //bool Object availability
	OBJPROP_CREATETIME, //datetime Time of object creation
	OBJPROP_LEVELS,		//int  Number of levels
	OBJPROP_LEVELCOLOR, //color Color of the line - level    modifier = level number
	OBJPROP_LEVELSTYLE, //ENUM_LINE_STYLE Style of the line - level  modifier = level number
	OBJPROP_LEVELWIDTH, //int Thickness of the line - level modifier = level number
	OBJPROP_ALIGN,		//ENUM_ALIGN_MODE Horizontal text alignment in the "Edit" object(OBJ_EDIT) ->
	OBJPROP_FONTSIZE,	//int Font size
	OBJPROP_RAY_LEFT,	//bool Ray goes to the left
	BJPROP_RAY_RIGHT,	//bool Ray goes to the right
	OBJPROP_RAY,		//bool A vertical line goes through all the windows of a chart
	OBJPROP_ELLIPSE,	//bool Showing the full ellipse of the Fibonacci Arc object(OBJ_FIBOARC)
	OBJPROP_ARROWCODE,	//char Arrow code for the Arrow object
	OBJPROP_TIMEFRAMES, //ENUM_TIMEFRAMES Visibility of an object at timeframes set of flags in Visibility of Ojbects (OBJ_PERIOD_ series)
	/*
		ENUM_ANCHOR_POINT Location of the anchor point of a graphical object
	ENUM_ARROW_ANCHOR(for OBJ_ARROW),
	(for OBJ_LABEL, OBJ_BITMAP_LABEL and OBJ_TEXT)
	*/
	OBJPROP_ANCHOR,	
	OBJPROP_XDISTANCE,	//int The distance in pixels along the X axis from the binding corner(see note)
	OBJPROP_YDISTANCE,	//int The distance in pixels along the Y axis from the binding corner(see note)
	OBJPROP_DIRECTION,	//ENUM_GANN_DIRECTION Trend of the Gann object
	OBJPROP_DEGREE,		//ENUM_ELLIOT_WAVE_DEGREE Level of the Elliott Wave Marking
	OBJPROP_DRAWLINES,	//bool Displaying lines for marking the Elliott Wave
	OBJPROP_STATE,		//bool Button state(pressed / depressed)
	/*
		long ID of the "Chart" object(OBJ_CHART).It allows working with the properties of this 
	object like with a normal chart using the functions described in Chart Operations, 
	but there some exceptions.
	*/
	OBJPROP_CHART_ID,
	/*
		int The object's width along the X axis in pixels. Specified for  OBJ_LABEL (read only),
	OBJ_BUTTON, OBJ_CHART, OBJ_BITMAP, OBJ_BITMAP_LABEL, OBJ_EDIT, OBJ_RECTANGLE_LABEL objects.
	*/
	OBJPROP_XSIZE, 
	/*
		int The object's height along the Y axis in pixels. Specified for  OBJ_LABEL (read only),
	OBJ_BUTTON, OBJ_CHART, OBJ_BITMAP, OBJ_BITMAP_LABEL, OBJ_EDIT, OBJ_RECTANGLE_LABEL objects.
	*/
	OBJPROP_YSIZE,
	/*
		int The X coordinate of the upper left corner of the rectangular visible area in the graphical
	objects "Bitmap Label" and "Bitmap" (OBJ_BITMAP_LABEL and OBJ_BITMAP).The value is set in pixels 
	relative to the upper left corner of the original image.
	*/
	OBJPROP_XOFFSET,
	/*
		int The Y coordinate of the upper left corner of the rectangular visible area in the graphical
	objects "Bitmap Label" and "Bitmap" (OBJ_BITMAP_LABEL and OBJ_BITMAP).The value is set in pixels
	relative to the upper left corner of the original image.
	*/
	OBJPROP_YOFFSET, 
	OBJPROP_PERIOD,			//ENUM_TIMEFRAMESTimeframe for the Chart object
	OBJPROP_DATE_SCALE,		//bool Displaying the time scale for the Chart object
	OBJPROP_CHART_SCALE,	//The scale for the Chart object						//value in the range 05
	OBJPROP_BGCOLOR,		//color The background color for  OBJ_EDIT, OBJ_BUTTON, OBJ_RECTANGLE_LABEL
	OBJPROP_CORNER,			//ENUM_BASE_CORNER The corner of the chart to link a graphical object
	OBJPROP_BORDER_TYPE,	//ENUM_BORDER_TYPE Border type for the "Rectangle label" object
	OBJPROP_BORDER_COLOR	//color Border color for the OBJ_EDIT and OBJ_BUTTON objects
};

//For functions ObjectSetDouble() and ObjectGetDouble()
enum ENUM_OBJECT_PROPERTY_DOUBLE{
	OBJPROP_PRICE,		//double Price coordinate modifier = number of anchor point
	OBJPROP_LEVELVALUE,	//double Level value modifier = level number
	OBJPROP_SCALE,		//double Scale(properties of Gann objects and Fibonacci Arcs)
	/*
		double Angle for the objects with no angle specified, created from a program, the
	value is equal to EMPTY_VALUE
	*/
	OBJPROP_ANGLE,
	OBJPROP_DEVIATION //double Deviation for the Standard Deviation Channel
};

//For functions ObjectSetString() and ObjectGetString()
enum ENUM_OBJECT_PROPERTY_STRING{
	OBJPROP_NAME, //string Object name
	OBJPROP_TEXT, //string Description of the object(the text contained in the object)
	/*
		string The text of a tooltip.If the property is not set, then the tooltip generated automatically by the
	terminal is shown.A tooltip can be disabled by setting the "\n" (line feed) value to it
	*/
	OBJPROP_TOOLTIP,
	OBJPROP_LEVELTEXT,	//string Level description   modifier = level number
	OBJPROP_FONT,		//string Font
	OBJPROP_BMPFILE,	//string The name of BMP - file for Bitmap Label.See also Resources modifier : 0 - state ON, 1 - state OFF
	OBJPROP_SYMBOL		//string Symbol for the Chart object
};

//-------------------------Object visibility
#define OBJ_PERIOD_M1		0x00000001	// Object shown is only on 1-minute charts.
#define OBJ_PERIOD_M5		0x00000010	// Object shown is only on 5-minute charts.
#define OBJ_PERIOD_M15		0x00000100	// Object shown is only on 15-minute charts.
#define OBJ_PERIOD_M30		0x00000400	// Object shown is only on 30-minute charts.
#define OBJ_PERIOD_H1		0x00000800	// Object shown is only on 1-hour charts.
#define OBJ_PERIOD_H4		0x00004000	// Object shown is only on 4-hour charts.
#define OBJ_PERIOD_D1		0x00040000	// Object shown is only on daily charts.
#define OBJ_PERIOD_W1		0x00080000	// Object shown is only on weekly charts.
#define OBJ_PERIOD_MN1		0x00100000	// Object shown is only on monthly charts.
#define OBJ_ALL_PERIODS		0x001FFFFF	// Object shown is on all timeframes.
#define OBJ_NO_PERIODS				 0	// Object shown is on all timeframes.

//For the OBJ_RECTANGLE_LABEL 
//object("Rectangle label") one of the three design modes can be set, to which the following values of ENUM_BORDER_TYPE correspond.
enum ENUM_BORDER_TYPE{
	BORDER_FLAT, //Flat form
	BORDER_RAISED, //Prominent form
	BORDER_SUNKEN //Concave form
};


//For the OBJ_EDIT 
//object("Edit") and for the ChartScreenShot() function, you can specify the horizontal alignment type using the values of the ENUM_ALIGN_MODE enumeration.
enum ENUM_ALIGN_MODE{
	ALIGN_LEFT, //Left alignment
	ALIGN_CENTER, //Centered(only for the Edit object)
	ALIGN_RIGHT //Right alignment
};

//The OBJ_BUTTON, OBJ_RECTANGLE_LABEL, OBJ_EDIT and OBJ_CHART objects have a fixed anchor point in the upper left corner(ANCHOR_LEFT_UPPER).
enum ENUM_ANCHOR_POINT{
	ANCHOR_LEFT_UPPER,	//Anchor point at the upper left corner
	ANCHOR_LEFT,	//Anchor point to the left in the center
	ANCHOR_LEFT_LOWER,	//Anchor point at the lower left corner
	ANCHOR_LOWER,	//Anchor point below in the center
	ANCHOR_RIGHT_LOWER,	//Anchor point at the lower right corner
	ANCHOR_RIGHT,	//Anchor point to the right in the center
	ANCHOR_RIGHT_UPPER,	//Anchor point at the upper right corner
	ANCHOR_UPPER,	//Anchor point above in the center
	ANCHOR_CENTER,	//Anchor point strictly in the center of the object
};

//Graphical objects Arrow(OBJ_ARROW) have only 2 ways of linking their coordinates.Identifiers are listed in ENUM_ARROW_ANCHOR.
enum ENUM_ARROW_ANCHOR{
	ANCHOR_TOP,	//Anchor on the top side
	ANCHOR_BOTTOM,	//Anchor on the bottom side
};


//Label(OBJ_LABEL);
//Button(OBJ_BUTTON);
//Chart(OBJ_CHART);
//Bitmap Label(OBJ_BITMAP_LABEL);
//Rectangle Label(OBJ_RECTANGLE_LABEL);
//Edit(OBJ_EDIT).
enum ENUM_BASE_CORNER{
	CORNER_LEFT_UPPER, //Center of coordinates is in the upper left corner of the chart
	CORNER_LEFT_LOWER, //Center of coordinates is in the lower left corner of the chart
	CORNER_RIGHT_LOWER, //Center of coordinates is in the lower right corner of the chart
	CORNER_RIGHT_UPPER, //Center of coordinates is in the upper right corner of the chart
};

//-------------Gann Objects
enum ENUM_GANN_DIRECTION{
	GANN_UP_TREND, //Line corresponding to the uptrend line
	GANN_DOWN_TREND, // Line corresponding to the downward trend
};


//-------------------------Levels of Elliott wave
enum ENUM_ELLIOT_WAVE_DEGREE{
	ELLIOTT_GRAND_SUPERCYCLE, 	//Grand Supercycle
	ELLIOTT_SUPERCYCLE, 		//Supercycle
	ELLIOTT_CYCLE, 				//Cycle
	ELLIOTT_PRIMARY, 			//Primary
	ELLIOTT_INTERMEDIATE, 		//Intermediate
	ELLIOTT_MINOR, 				//Minor
	ELLIOTT_MINUTE, 			//Minute
	ELLIOTT_MINUETTE,			//Minuette
	ELLIOTT_SUBMINUETTE,		//Subminuette
};


//*******************************************
//           uninitialize reason codes
//res::http://docs.mql4.com/constants/uninit
//*******************************************
//								0	   Script finished its execution independently.
#define REASON_REMOVE			1	// Expert removed from chart.
#define REASON_RECOMPILE		2	// Expert recompiled.
#define REASON_CHARTCHANGE		3	// symbol or timeframe changed on the chart.
#define REASON_CHARTCLOSE		4	// Chart closed.
#define REASON_PARAMETERS		5	// Inputs parameters was changed by user.
#define REASON_ACCOUNT			6	// Other account activated.

//*******************************************
//           uninitialize reason codes
//res::http://docs.mql4.com/constants/special
//*******************************************
#define NULL					0			// Indicates empty state of the string.
#define EMPTY					-1			// Indicates empty state of the parameter.
#define EMPTY_VALUE				0x7FFFFFFF	// Default custom indicator empty value.
#define CLR_NONE				0xFFFFFFFF	// Indicates empty state of colors.
#define WHOLE_ARRAY				0			// Used with array functions. Indicates that all array elements will be processed.

//********************************************
//           Char  event
//res::http://www.mql5.com/en/docs/constants/chartconstants
//********************************************
enum ENUM_CHART_EVENT{
	CHARTEVENT_KEYDOWN,			//Keystrokes
	CHARTEVENT_MOUSE_MOVE,		//Mouse move, mouse clicks(if CHART_EVENT_MOUSE_MOVE = true is set for the chart)
	CHARTEVENT_OBJECT_CREATE,   //Graphical object created(if CHART_EVENT_OBJECT_CREATE = true is set for the chart)
	CHARTEVENT_OBJECT_CHANGE,   //Graphical object property changed via the properties dialog
	CHARTEVENT_OBJECT_DELETE,   //Graphical object deleted(if CHART_EVENT_OBJECT_DELETE = true is set for the chart)
	CHARTEVENT_CLICK,			//Clicking on a chart
	CHARTEVENT_OBJECT_CLICK,	//Clicking on a graphical object
	CHARTEVENT_OBJECT_DRAG,		//Drag and drop of a graphical object
	CHARTEVENT_OBJECT_ENDEDIT,	//End of text editing in the graphical object Edit
	CHARTEVENT_CHART_CHANGE,	//Change of the chart size or modification of chart properties through the Properties dialog
	CHARTEVENT_CUSTOM,			//Initial number of an event from a range of custom events
	CHARTEVENT_CUSTOM_LAST		//The final number of an event from a range of custom events
};
//For CHARTEVENT_MOUSE_MOVE event the sparam string parameter contains information about state of the keyboard and mouse buttons :
//
//Bit	Description
//1	State of the left mouse button
//2	Always zero for MQL5 - programs
//3	State of the SHIFT button
//4	State of the CTRL button
//5	State of the middle mouse button
//6	State of the first extra mouse button
//7	State of the second extra mouse button


//                    Chart Properties
//For functions ChartSetInteger() and ChartGetInteger()
enum ENUM_CHART_PROPERTY_INTEGER{
	CHART_IS_OBJECT,	//bool Identifying "Chart" (OBJ_CHART)object  returns true for a graphical object.Returns false for a real chart
	CHART_BRING_TO_TOP, //bool Show chart on top of other charts
	/*
		bool Scrolling the chart horizontally using the left mouse button.Vertical scrolling is also available if the value of 
	any following properties is set to true: CHART_SCALEFIX, CHART_SCALEFIX_11 or CHART_SCALE_PT_PER_BAR
	*/
	CHART_MOUSE_SCROLL, 
	CHART_EVENT_MOUSE_MOVE,		//bool Send notifications of mouse move and mouse click events(CHARTEVENT_MOUSE_MOVE) to all mql5 programs on a chart
	CHART_EVENT_OBJECT_CREATE,	//bool Send a notification of an event of new object creation(CHARTEVENT_OBJECT_CREATE) to all mql5 - programs on a chart
	CHART_EVENT_OBJECT_DELETE,	//bool Send a notification of an event of object deletion(CHARTEVENT_OBJECT_DELETE) to all mql5 - programs on a chart
	CHART_MODE,					//ENUM_CHART_MODE Chart type(candlesticks, bars or line)
	CHART_FOREGROUND,			//bool Price chart in the foreground
	CHART_SHIF,					//bool Mode of price chart indent from the right border
	CHART_AUTOSCROLL,			//bool Mode of automatic moving to the right border of the chart
	CHART_SCALE,				//int  Scale from 0 to 5
	CHART_SCALEFIX,				//bool Fixed scale mode
	HART_SCALEFIX_11,			//bool Scale 1:1 mode
	CHART_SCALE_PT_PER_BAR,		//bool Scale to be specified in points per bar
	CHART_SHOW_OHLC,			//bool Show OHLC values in the upper left corner
	CHART_SHOW_BID_LINE,		//bool Display Bid values as a horizontal line in a chart
	CHART_SHOW_ASK_LINE,		//bool Display Ask values as a horizontal line in a chart
	CHART_SHOW_LAST_LINE,		//bool Display Last values as a horizontal line in a chart
	CHART_SHOW_PERIOD_SEP,		//bool Display vertical separators between adjacent periods
	CHART_SHOW_GRID,			//bool Display grid in the chart
	CHART_SHOW_VOLUMES,			//ENUM_CHART_VOLUME_MODE  Display volume in the chart ->enum 
	CHART_SHOW_OBJECT_DESCR,	//bool Pop - up descriptions of graphical objects
	CHART_VISIBLE_BARS,			//int The number of bars on the chart that can be displayed
	CHART_WINDOWS_TOTAL,		//int The total number of chart windows, including indicator subwindows
	CHART_WINDOW_IS_VISIBLE,	//bool Visibility of subwindows  bool r / o   modifier - subwindow number
	CHART_WINDOW_HANDLE,		//int Chart window handle(HWND)	int r / o
	/*
		int    The distance between the upper frame of the indicator subwindow and the upper frame of the main chart 
	window, along the vertical Y axis, in pixels.In case of a mouse event, the cursor coordinates are passed
	in terms of the coordinates of the main chart window, while the coordinates of graphical objects in an 
	indicator subwindow are set relative to the upper left corner of the subwindow.
		The value is required for converting the absolute coordinates of the main chart to the local coordinates
	of a subwindow for correct work with the graphical objects, whose coordinates are set relative to  the upper
	left corner of the subwindow frame. int r / o     modifier - subwindow number
	*/
	CHART_WINDOW_YDISTANCE, 	
	CHART_FIRST_VISIBLE_BAR,	//int Number of the first visible bar in the chart.Indexing of bars is the same as for timeseries.
	CHART_WIDTH_IN_BARS,		//int Chart width in bars
	CHART_WIDTH_IN_PIXELS,		//int Chart width in pixels
	CHART_HEIGHT_IN_PIXELS,		//int Chart height in pixels  int modifier - subwindow number
	CHART_COLOR_BACKGROUND,		//color Chart background color
	CHART_COLOR_FOREGROUND,		//color Color of axes, scales and OHLC line
	CHART_COLOR_GRID, 			//color Grid color
	CHART_COLOR_VOLUME,			//color Color of volumes and position opening levels
	CHART_COLOR_CHART_UP,		//color Color for the up bar, shadows and body borders of bull candlesticks
	CHART_COLOR_CHART_DOWN,		//color Color for the down bar, shadows and body borders of bear candlesticks
	CHART_COLOR_CHART_LINE,		//color Line chart color and color of "Doji" Japanese candlesticks
	CHART_COLOR_CANDLE_BULL,	//color Body color of a bull candlestick
	CHART_COLOR_CANDLE_BEAR,	//color Body color of a bear candlestick
	CHART_COLOR_BID,			//color Bid price level color
	HART_COLOR_ASK,				//color Ask price level color
	CHART_COLOR_LAST,			//color Line color of the last executed deal price(Last)
	CHART_COLOR_STOP_LEVEL,		//color Color of stop order levels(Stop Loss and Take Profit)
	CHART_SHOW_TRADE_LEVELS,	//bool Displaying trade levels in the chart(levels of open positions, Stop Loss, Take Profit and pending orders)
	CHART_DRAG_TRADE_LEVELS,	//bool Permission to drag trading levels on a chart with a mouse.The drag mode is enabled by default (true value)
	CHART_SHOW_DATE_SCALE,		//bool Showing the time scale on a chart
	CHART_SHOW_PRICE_SCALE		//bool Showing the price scale on a chart
};

//For functions ChartSetDouble() and ChartGetDouble()
enum ENUM_CHART_PROPERTY_DOUBLE{
	CHART_SHIFT_SIZE, //doubleThe size of the zero bar indent from the right border in percents | double(from 10 to 50 percents)
	/*
		double Chart fixed position from the left border in percent value.Chart fixed position is marked by a small gray 
	triangle on the horizontal time axis.It is displayed only if the automatic chart scrolling to the right on 
	tick incoming is disabled(see CHART_AUTOSCROLL property).The bar on a fixed position remains in the same 
	place when zooming in and out.
	*/
	CHART_FIXED_POSITION, 
	CHART_FIXED_MAX, //double Fixed  chart maximum
	CHART_FIXED_MIN, //double Fixed  chart minimum
	CHART_POINTS_PER_BAR, //double Scale in points per bar
	CHART_PRICE_MIN, //double Chart minimum 	double r / o   modifier - subwindow number
	CHART_PRICE_MAX, //double Chart maximum 	double r / o   modifier - subwindow number

};
//For functions ChartSetString() and ChartGetString()
enum ENUM_CHART_PROPERTY_STRING {
	CHART_COMMENT  //string Text of a comment in a chart
};


//*******************************************
//           Positioning Constants
//res::http://www.mql5.com/en/docs/constants/chartconstants/enum_chart_position
//*******************************************
enum ENUM_CHART_POSITION{
	CHART_BEGIN,		//Chart beginning(the oldest prices)
	CHART_CURRENT_POS,  //Current position
	CHART_END			//Chart end(the latest prices)
};

//*******************************************
//           Positioning Constants
//res::http://www.mql5.com/en/docs/constants/chartconstants/chart_view
//*******************************************
enum ENUM_CHART_MODE {
	CHART_BARS,   //Display as a sequence of bars
	CHART_CANDLES, //Display as Japanese candlesticks
	CHART_LINE     //Display as a line drawn by Close prices
};

enum ENUM_CHART_VOLUME_MODE{
	CHART_VOLUME_HIDE, //Volumes are not shown
	CHART_VOLUME_TICK, //Tick volumes
	CHART_VOLUME_REAL //Trade volumes
};

//*******************************************
//          Client Terminal Properties
//res::http://www.mql5.com/en/docs/constants/environment_state/terminalstatus
//*******************************************
/*
	Information about the client terminal can be obtained by two functions : TerminalInfoInteger() and
TerminalInfoString().For parameters, these functions accept values from ENUM_TERMINAL_INFO_INTEGER 
and ENUM_TERMINAL_INFO_STRING respectively.
*/
enum ENUM_TERMINAL_INFO_INTEGER{
	TERMINAL_BUILD,				//int The client terminal build number
	TERMINAL_COMMUNITY_ACCOUNT, //bool The flag indicates the presence of MQL5.community authorization data in the terminal
	TERMINAL_COMMUNITY_CONNECTION, //bool Connection to MQL5.community
	TERMINAL_CONNECTED,			//bool Connection to a trade server
	TERMINAL_DLLS_ALLOWED,		//bool Permission to use DLL
	TERMINAL_TRADE_ALLOWED,		//bool Permission to trade
	TERMINAL_EMAIL_ENABLED,		//bool Permission to send e - mails using SMTP - server and login, specified in the terminal settings
	TERMINAL_FTP_ENABLED,		//bool Permission to send reports using FTP - server and login, specified in the terminal settings
	TERMINAL_NOTIFICATIONS_ENABLED, //bool Permission to send notifications to smartphone
	TERMINAL_MAXBARS,			//int The maximal bars count on the chart
	TERMINAL_MQID,				//bool The flag indicates the presence of MetaQuotes ID data for Push notifications
	TERMINAL_CODEPAGE,			//int Number of the code page of the language installed in the client terminal
	TERMINAL_CPU_CORES,			//int The number of CPU cores in the system
	TERMINAL_DISK_SPACE,		//int Free disk space for the MQL5\Files folder of the terminal(agent), MB
	TERMINAL_MEMORY_PHYSICAL,	//int Physical memory in the system, MB
	TERMINAL_MEMORY_TOTAL,		//int Memory available to the process of the terminal(agent), MB
	TERMINAL_MEMORY_AVAILABLE,	//int Free memory of the terminal(agent) process, MB
	TERMINAL_MEMORY_USED,		//int Memory used by the terminal(agent), MB
	TERMINAL_X64,				//bool Indication of the "64-bit terminal"
	TERMINAL_OPENCL_SUPPORT		//int The version of the supported OpenCL in the format of 0x00010002 = 1.2. "0" means that OpenCL is not supported
};

enum ENUM_TERMINAL_INFO_DOUBLE{
	TERMINAL_COMMUNITY_BALANCE //Balance in MQL5.community
};

/*
	File operations can be performed only in two directories; corresponding paths can be obtained using
the request for TERMINAL_DATA_PATH and TERMINAL_COMMONDATA_PATH properties.
*/
enum ENUM_TERMINAL_INFO_STRING{
	TERMINAL_LANGUAGE, //Language of the terminal
	TERMINAL_COMPANY, //Company name
	TERMINAL_NAME, //Terminal name
	TERMINAL_PATH, //Folder from which the terminal is started
	TERMINAL_DATA_PATH, //Folder in which terminal data are stored
	TERMINAL_COMMONDATA_PATH //Common path for all of the terminals installed on a computer
};

/*
	For a better understanding of paths, stored in properties of TERMINAL_PATH, TERMINAL_DATA_PATH and
TERMINAL_COMMONDATA_PATH parameters, it is recommended to execute the script, which will return these 
values for the current copy of the client terminal, installed on your computer
*/

//*******************************************
//          Running MQL5 Program Properties
//res::http://www.mql5.com/en/docs/constants/environment_state/terminalstatus
//*******************************************
//	To obtain information about the currently running mql5 program, constants from ENUM_MQL_INFO_INTEGER
//and ENUM_MQL_INFO_STRING are used.

//For function MQLInfoInteger()
enum ENUM_MQL_INFO_INTEGER{
	MQL_MEMORY_LIMIT, //int Maximum possible amount of dynamic memory for MQL5 program in MB
	MQL_MEMORY_USED, //int The memory size used by MQL5 program in MB
	MQL_PROGRAM_TYPE, //ENUM_PROGRAM_TYPE Type of the mql5 program   
	MQL_DLLS_ALLOWED, //bool The permission to use DLL for the given executed program
	MQL_TRADE_ALLOWED, //bool The permission to trade for the given executed program
	MQL_SIGNALS_ALLOWED, //bool The permission to modify the Signals for the given executed program
	MQL_DEBUG, //bool The flag, that indicates the debug mode
	MQL_PROFILER, //bool The flag, that indicates the program operating in the code profiling mode
	MQL_TESTER, //bool The flag, that indicates the tester process
	MQL_OPTIMIZATION, //bool The flag, that indicates the optimization process
	MQL_VISUAL_MODE, //bool The flag, that indicates the visual tester process
	MQL_FRAME_MODE //bool The flag, that indicates the Expert Advisor operating in gathering optimization result frames mode
};
/*
	Type of license of the EX5 module.The license refers to the EX5 module, 
from which a request is made using MQLInfoInteger(MQL_LICENSE_TYPE). return ENUM_LICENSE_TYPEs
*/
ENUM_LICENSE_TYPE MQL_LICENSE_TYPE; 

//For function MQLInfoString
enum ENUM_MQL_INFO_STRING{
	MQL_PROGRAM_NAME, //Name of the mql5 - program executed
	MQL5_PROGRAM_PATH //Path for the given executed program
};


//For information about the type of the running program, values of ENUM_PROGRAM_TYPE are used.
enum ENUM_PROGRAM_TYPE{
	PROGRAM_SCRIPT,		//Script
	PROGRAM_EXPERT,		//Expert
	PROGRAM_INDICATOR,	//Indicator
};

enum ENUM_LICENSE_TYPE{
	LICENSE_FREE, //A free unlimited version
	LICENSE_DEMO, //A trial version of a paid product from the Market.It works only in the strategy tester
	/*
		A purchased licensed version allows at least 5 activations.The number of activations is
	specified by seller.Seller may increase the allowed number of activations
	*/
	LICENSE_FULL, 
	LICENSE_TIME  //A version with limited term liсense
};

//*******************************************
//          Symbol Properties
//res::http://www.mql5.com/en/docs/constants/environment_state/marketinfoconstants
//*******************************************
//	To obtain the current market information there are several functions : SymbolInfoInteger(), SymbolInfoDouble() 
//and SymbolInfoString().The first parameter is the symbol name, the values of the second function parameter can be 
//one of the identifiers of ENUM_SYMBOL_INFO_INTEGER, ENUM_SYMBOL_INFO_DOUBLE and ENUM_SYMBOL_INFO_STRING.

//For function SymbolInfoInteger()
enum ENUM_SYMBOL_INFO_INTEGER{
	SYMBOL_SELECT,			//bool Symbol is selected in Market Watch
	SYMBOL_SESSION_DEALS,	//long Number of deals in the current session
	SYMBOL_SESSION_BUY_ORDERS,	//long Number of Buy orders at the moment
	SYMBOL_SESSION_SELL_ORDERS, //long Number of Sell orders at the moment
	SYMBOL_VOLUME,			//long Volume of the last deal
	SYMBOL_VOLUMEHIGH,		//long Maximal day volume
	SYMBOL_VOLUMELOW,		//long Minimal day volume
	SYMBOL_TIME,			//datetime Time of the last quote
	SYMBOL_DIGITS,			//int Digits after a decimal point
	SYMBOL_SPREAD_FLOAT,	//bool Indication of a floating spread
	SYMBOL_SPREAD,			//int Spread value in points
	/*
	int 	Maximal number of requests shown in Depth of Market.For symbols that have no queue of requests,
	the value is equal to zero.
	*/
	SYMBOL_TICKS_BOOKDEPTH, 
	SYMBOL_TRADE_CALC_MODE, //ENUM_SYMBOL_CALC_MODE Contract price calculation mode ENUM_SYMBOL_CALC_MODE
	SYMBOL_TRADE_MODE,		//ENUM_SYMBOL_TRADE_MODE Order execution type ENUM_SYMBOL_TRADE_MODE
	SYMBOL_START_TIME,		//datetime Date of the symbol trade beginning(usually used for futures)
	SYMBOL_EXPIRATION_TIME, //datetime Date of the symbol trade end(usually used for futures)
	SYMBOL_TRADE_STOPS_LEVEL,  //int Minimal indention in points from the current close price to place Stop orders
	SYMBOL_TRADE_FREEZE_LEVEL, //int Distance to freeze trade operations in points
	SYMBOL_TRADE_EXEMODE,	//ENUM_SYMBOL_TRADE_EXECUTION Deal execution mode   ENUM_SYMBOL_TRADE_EXECUTION
	SYMBOL_SWAP_MODE,		//ENUM_SYMBOL_SWAP_MODE Swap calculation model    ENUM_SYMBOL_SWAP_MODE
	SYMBOL_SWAP_ROLLOVER3DAYS, //ENUM_DAY_OF_WEEK Weekday to charge 3 days swap rollover  ENUM_DAY_OF_WEEK
	SYMBOL_EXPIRATION_MODE, //int Flags of allowed order expiration modes 
	SYMBOL_FILLING_MODE,	//int Flags of allowed order filling modes
	SYMBOL_ORDER_MODE		//int Flags of allowed order types
};

/*
	There are several symbol trading modes.Information about trading modes of a certain symbol is reflected 
in the values of enumeration ENUM_SYMBOL_TRADE_MODE.
*/
enum ENUM_SYMBOL_TRADE_MODE{
	SYMBOL_TRADE_MODE_DISABLED, //Trade is disabled for the symbol
	SYMBOL_TRADE_MODE_LONGONLY, //Allowed only long positions
	SYMBOL_TRADE_MODE_SHORTONLY, //Allowed only short positions
	SYMBOL_TRADE_MODE_CLOSEONLY, //Allowed only position close operations
	SYMBOL_TRADE_MODE_FULL		 //No trade restrictions
};
//	Possible deal execution modes for a certain symbol are defined in enumeration ENUM_SYMBOL_TRADE_EXECUTION.
enum ENUM_SYMBOL_TRADE_EXECUTION{
	SYMBOL_TRADE_EXECUTION_REQUEST, //Execution by request
	SYMBOL_TRADE_EXECUTION_INSTANT, //Instant execution
	SYMBOL_TRADE_EXECUTION_MARKET,	//Market execution
	SYMBOL_TRADE_EXECUTION_EXCHANGE, //Exchange execution
};
/*
	For each symbol several expiration modes of pending orders can be specified.A flag is matched to each mode.Flags can be
combined using the operation of logical OR(| ), for example, SYMBOL_EXPIRATION_GTC | SYMBOL_EXPIRATION_SPECIFIED.In order
to check whether a certain mode is allowed for the symbol, the result of the logical AND(&) should be compared to the mode flag.
If flag SYMBOL_EXPIRATION_SPECIFIED is specified for a symbol, then while sending a pending order, you may specify the moment
this pending order is valid till.
*/
#define SYMBOL_EXPIRATION_GTC		1  //The order is valid during the unlimited time period, until it is explicitly canceled
#define SYMBOL_EXPIRATION_DAY		2  //The order is valid till the end of the day
#define SYMBOL_EXPIRATION_SPECIFIED 4  //The expiration time is specified in the order
#define SYMBOL_EXPIRATION_SPECIFIED_DAY 8  //The expiration date is specified in the order

/*
	When sending an order, you can specify the filling policy for the volume set in the order.Allowed order filling modes for
each symbol are specified in the table.You can set several modes for one symbol by combining flags.The flags can be combined
by the operation of the logical OR(| ), for example, SYMBOL_FILLING_FOK | SYMBOL_FILLING_IOC.In order to check whether a
certain mode is allowed for the symbol, the result of the logical AND(&) should be compared to the mode flag.
*/

//---Fill Policy		Fill or Kill		
/*	
	This policy means that a deal can be executed only with the specified volume.If
the necessary amount of a financial instrument is currently unavailable in the
market, the order will not be executed.The required volume can be filled using
several offers available on the market at the moment.
*/
#define SYMBOL_FILLING_FOK  1
//---Immediate or Cancel
/*	
	In this case a trader agrees to execute a deal with the volume maximally available
in the market within that indicated in the order.In case the order cannot be filled
completely, the available volume of the order will be filled, and the remaining volume
will be canceled.The possibility of using IOC orders is determined at the trade server.
*/
#define SYMBOL_FILLING_IOC  2       		
//---Return
/*	
	This policy is used only for market orders(Buy and Sell), limit and stop limit orders
and only for the symbols with Market or Exchange execution.In case of partial filling a market
or limit order with remaining volume is not canceled but processed further.
In the Request and Instant execution modes the Fill or Kill policy is always used for market
orders, and the Return policy is always used for limit orders.In this case, when sending
orders using OrderSend or OrderSendAsync, there is no need to specify a fill policy for them.
*/
//----No identifier

/*	
	When sending a trade request using OrderSend() function, an order type from ENUM_ORDER_TYPE
enumeration should be specified for some operations.Not all types of orders may be allowed for a
specific symbol.SYMBOL_ORDER_MODE property describes the flags of the allowed order types.
*/
#define SYMBOL_ORDER_MARKET		1 //Market orders are allowed(Buy and Sell)
#define SYMBOL_ORDER_LIMIT		2 //Limit orders are allowed(Buy Limit and Sell Limit)
#define SYMBOL_ORDER_STOP		4 //Stop orders are allowed(Buy Stop and Sell Stop)
#define SYMBOL_ORDER_STOP_LIMIT 8 //Stop - limit orders are allowed(Buy Stop Limit and Sell Stop Limit)
#define SYMBOL_ORDER_SL			16 //Stop Loss is allowed 
#define SYMBOL_ORDER_TP			32 //Take Profit is allowed


//Values of the ENUM_DAY_OF_WEEK enumeration are used for specifying weekdays.
enum ENUM_DAY_OF_WEEK{
	SUNDAY,		//	Sunday
	MONDAY,		//	Monday
	TUESDAY,	//	Tuesday
	WEDNESDAY,	//	Wednesday
	THURSDAY,	//	Thursday
	FRIDAY,		//	Friday
	SATURDAY,	//	Saturday
};
/*
	Methods of swap calculation at position transfer are specified in enumeration ENUM_SYMBOL_SWAP_MODE.The method of
swap calculation determines the units of measure of the SYMBOL_SWAP_LONG and SYMBOL_SWAP_SHORT parameters.For
example, if swaps are charged in the client deposit currency, then the values of those parameters are specified
as an amount of money in the client deposit currency.
*/
enum ENUM_SYMBOL_SWAP_MODE {
	//Swaps disabled(no swaps)
	SYMBOL_SWAP_MODE_DISABLED,
	//Swaps are charged in points
	SYMBOL_SWAP_MODE_POINTS,
	//Swaps are charged in money in base currency of the symbol
	SYMBOL_SWAP_MODE_CURRENCY_SYMBOL,
	//Swaps are charged in money in margin currency of the symbol
	SYMBOL_SWAP_MODE_CURRENCY_MARGIN,
	//Swaps are charged in money, in client deposit currency
	SYMBOL_SWAP_MODE_CURRENCY_DEPOSIT,
	/*
	Swaps are charged as the specified annual interest from the instrument price at
	calculation of swap(standard bank year is 360 days)
	*/
	SYMBOL_SWAP_MODE_INTEREST_CURRENT,
	/*
	Swaps are charged as the specified annual interest from the open price of position
	(standard bank year is 360 days)
	*/
	SYMBOL_SWAP_MODE_INTEREST_OPEN,
	/*
	Swaps are charged by reopening positions.At the end of a trading day the position
	is closed.Next day it is reopened by the
	close price + / -specified number of points(parameters SYMBOL_SWAP_LONG and SYMBOL_SWAP_SHORT)
	*/
	SYMBOL_SWAP_MODE_REOPEN_CURRENT,
	/*
	Swaps are charged by reopening positions.At the end of a trading day the position is closed.Next
	day it is reopened by the
	current Bid price + / -specified number of points(parameters SYMBOL_SWAP_LONG and SYMBOL_SWAP_SHORT)
	*/
	SYMBOL_SWAP_MODE_REOPEN_BID
};
enum ENUM_SYMBOL_CALC_MODE{
	/*
	Forex mode - calculation of profit and margin for Forex
	Margin : Lots*Contract_Size / Leverage
	Profit : (close_price - open_price)*Contract_Size*Lots
	*/
	SYMBOL_CALC_MODE_FOREX,
	/*
	Futures mode - calculation of margin and profit for future
	Margin : Lots *InitialMargin*Percentage / 100
	Profit : (close_price - open_price)*TickPrice / TickSize*Lots
	*/
	SYMBOL_CALC_MODE_FUTURES,
	/*
	CFD mode - calculation of margin and profit for CFD
	Margin : Lots *ContractSize*MarketPrice*Percentage / 100
	Profit : (close_price - open_price)*Contract_Size*Lots
	*/
	SYMBOL_CALC_MODE_CFD,
	/*
	CFD index mode - calculation of margin and profit for CFD by indexes
	Margin : (Lots*ContractSize*MarketPrice)*TickPrice / TickSize
	Profit : (close_price - open_price)*Contract_Size*Lots
	*/
	SYMBOL_CALC_MODE_CFDINDEX,
	/*
	CFD Leverage mode - calculation of margin and profit for CFD at leverage trading
	Margin : (Lots*ContractSize*MarketPrice*Percentage) / Leverage
	Profit : (close_price - open_price)*Contract_Size*Lots
	*/
	SYMBOL_CALC_MODE_CFDLEVERAGE,
	/*
	Exchange mode  calculation of margin and profit for trading securities on a stock exchange
	Margin : Lots*ContractSize*OpenPrice
	Profit : (close_price - open_price)*Contract_Size*Lots
	*/
	SYMBOL_CALC_MODE_EXCH_STOCKS,
	/*
	Futures mode   calculation of margin and profit for trading futures contracts on a stock exchange
	Margin : Lots*InitialMargin or Lots*MaintenanceMargin
	Profit : (close_price - open_price)*Lots*TickPrice / TickSize
	*/
	SYMBOL_CALC_MODE_EXCH_FUTURES,
	/*
		FORTS Futures mode   calculation of margin and profit for trading futures contracts on FORTS.The margin
	may be reduced by the amount of MarginDiscount deviation according to the following rules :
		1. If the price of a long position(buy order) is less than the estimated price,
	MarginDiscount = Lots*((PriceSettle - PriceOrder)*TickPrice / TickSize)
		2. If the price of a short position(sell order) exceeds the estimated price,
	MarginDiscount = Lots*((PriceOrder - PriceSettle)*TickPrice / TickSize)
	where :
		PriceSettle  estimated(clearing) price of the previous session;
		PriceOrder  average weighted position price or open price set in the order(request);
		TickPrice  tick price(cost of the price change by one point)
		TickSize  tick size(minimum price change step)

	Margin: Lots*InitialMargin or Lots*MaintenanceMargin
	Profit : (close_price - open_price)*Lots*TickPrice / TickSize
	*/
	SYMBOL_CALC_MODE_EXCH_FUTURES_FORTS
};
//For function SymbolInfoDouble()
enum ENUM_SYMBOL_INFO_DOUBLE{
	SYMBOL_BID, //Bid - best sell offer
	SYMBOL_BIDHIGH, //Maximal Bid of the day
	SYMBOL_BIDLOW, //Minimal Bid of the day
	SYMBOL_ASK, //Ask - best buy offer
	SYMBOL_ASKHIGH, //Maximal Ask of the day
	SYMBOL_ASKLOW, //Minimal Ask of the day
	SYMBOL_LAST, //Price of the last deal
	SYMBOL_LASTHIGH, //Maximal Last of the day
	SYMBOL_LASTLOW, //Minimal Last of the day
	SYMBOL_POINT, //Symbol point value
	SYMBOL_TRADE_TICK_VALUE, //Value of SYMBOL_TRADE_TICK_VALUE_PROFIT
	SYMBOL_TRADE_TICK_VALUE_PROFIT, //Calculated tick price for a profitable position
	SYMBOL_TRADE_TICK_VALUE_LOSS, //Calculated tick price for a losing position
	SYMBOL_TRADE_TICK_SIZE, //Minimal price change
	SYMBOL_TRADE_CONTRACT_SIZE, //Trade contract size
	SYMBOL_VOLUME_MIN, //Minimal volume for a deal
	SYMBOL_VOLUME_MAX, //Maximal volume for a deal
	SYMBOL_VOLUME_STEP, //Minimal volume change step for deal execution
	/*
		Maximum allowed aggregate volume of an open position and pending orders in one
	direction(buy or sell) for the symbol.For example, with the limitation of 5 lots, 
	you can have an open buy position with the volume of 5 lots and place a pending order 
	Sell Limit with the volume of 5 lots.But in this case you cannot place a Buy Limit 
	pending order(since the total volume in one direction will exceed the limitation) or
	place Sell Limit with the volume more than 5 lots.
	*/
	SYMBOL_VOLUME_LIMIT, 
	SYMBOL_SWAP_LONG, //Long swap value
	SYMBOL_SWAP_SHORT, //Short swap value
	/*	
		Initial margin means the amount in the margin currency required for opening a position
	with the volume of one lot.It is used for checking a client's assets when he or she enters the market.
	*/
	SYMBOL_MARGIN_INITIAL, 
	/*
		The maintenance margin.If it is set, it sets the margin amount in the margin 
	currency of the symbol, charged from one lot.It is used for checking a client's assets when 
	his/her account state changes. If the maintenance margin is equal to 0, the initial margin is used.
	*/
	SYMBOL_MARGIN_MAINTENANCE, 
	SYMBOL_SESSION_VOLUME, //Summary volume of current session deals
	SYMBOL_SESSION_TURNOVER, //Summary turnover of the current session
	SYMBOL_SESSION_INTEREST, //Summary open interest
	SYMBOL_SESSION_BUY_ORDERS_VOLUME, //Current volume of Buy orders
	SYMBOL_SESSION_SELL_ORDERS_VOLUME, //Current volume of Sell orders
	SYMBOL_SESSION_OPEN, //Open price of the current session
	SYMBOL_SESSION_CLOSE, //Close price of the current session
	SYMBOL_SESSION_AW, //Average weighted price of the current session
	SYMBOL_SESSION_PRICE_SETTLEMENT, //Settlement price of the current session
	SYMBOL_SESSION_PRICE_LIMIT_MIN, //Minimal price of the current session
	SYMBOL_SESSION_PRICE_LIMIT_MAX //Maximal price of the current session
};

//For function SymbolInfoString()
enum ENUM_SYMBOL_INFO_STRING{
	SYMBOL_CURRENCY_BASE, //Basic currency of a symbol
	SYMBOL_CURRENCY_PROFIT, //Profit currency
	SYMBOL_CURRENCY_MARGIN, //Margin currency
	SYMBOL_BANK, //Feeder of the current quote
	SYMBOL_DESCRIPTION, //Symbol description
	/*
		The name of a symbol in the ISIN system(International Securities Identification Number).The International 
	Securities Identification Number is a 12 - digit alphanumeric code that uniquely identifies a security.The
	presence of this symbol property is determined on the side of a trade server.
	*/
	SYMBOL_ISIN, 
	SYMBOL_PATH //Path in the symbol tree
};



//*******************************************
//           Account Properties
//res::http://www.mql5.com/en/docs/constants/environment_state/accountinformation
//*******************************************
//To obtain information about the current account there are several functions : AccountInfoInteger(), AccountInfoDouble() 
//and AccountInfoString().The function parameter values can accept values from the corresponding ENUM_ACCOUNT_INFO enumerations.

//For the function AccountInfoInteger()
enum ENUM_ACCOUNT_INFO_INTEGER{
 ACCOUNT_LOGIN,			//long Account number
 ACCOUNT_TRADE_MODE,	//ENUM_ACCOUNT_TRADE_MODE Account trade mode ENUM_ACCOUNT_TRADE_MODE
 ACCOUNT_LEVERAGE,		//long Account leverage
 ACCOUNT_LIMIT_ORDERS,	//int Maximum allowed number of active pending orders
 ACCOUNT_MARGIN_SO_MODE, //ENUM_ACCOUNT_STOPOUT_MODE Mode for setting the minimal allowed margin 	ENUM_ACCOUNT_STOPOUT_MODE;
 ACCOUNT_TRADE_ALLOWED, //bool Allowed trade for the current account
 ACCOUNT_TRADE_EXPERT,	//bool Allowed trade for an Expert Advisor
};

//For the function AccountInfoDouble()
enum ENUM_ACCOUNT_INFO_DOUBLE{
	ACCOUNT_BALANCE, //Account balance in the deposit currency
	ACCOUNT_CREDIT, //Account credit in the deposit currency
	ACCOUNT_PROFIT, //Current profit of an account in the deposit currency
	ACCOUNT_EQUITY, //Account equity in the deposit currency
	ACCOUNT_MARGIN, //Account margin used in the deposit currency
	ACCOUNT_FREEMARGIN, //Free margin of an account in the deposit currency
	ACCOUNT_MARGIN_LEVEL, //Account margin level in percents
	/*
		Margin call level.Depending on the set ACCOUNT_MARGIN_SO_MODE is expressed
	in percents or in the deposit currency
	*/
	ACCOUNT_MARGIN_SO_CALL, 
	/*
		Margin stop out level.Depending on the set ACCOUNT_MARGIN_SO_MODE is expressed 
	in percents or in the deposit currency
	*/
	ACCOUNT_MARGIN_SO_SO 
};

//For function AccountInfoString()
enum ENUM_ACCOUNT_INFO_STRING{
	ACCOUNT_NAME,	//Client name
	ACCOUNT_SERVER, //Trade server name
	ACCOUNT_CURRENCY, //Account currency
	ACCOUNT_COMPANY //Name of a company that serves the account
};


/*
	There are several types of accounts that can be opened on a trade server.The type of account on which an MQL5 program is
running can be found out using the ENUM_ACCOUNT_TRADE_MODE enumeration.
*/
enum ENUM_ACCOUNT_TRADE_MODE{
	ACCOUNT_TRADE_MODE_DEMO,	//Demo account
	ACCOUNT_TRADE_MODE_CONTEST, //Contest account
	ACCOUNT_TRADE_MODE_REAL		//Real account
};

/*
	In case equity is not enough for maintaining open positions, the Stop Out situation, i.e.forced closing occurs.The
minimum margin level at which Stop Out occurs can be set in percentage or in monetary terms.To find out the mode set for the
account use the ENUM_ACCOUNT_STOPOUT_MODE enumeration.
*/
enum ENUM_ACCOUNT_STOPOUT_MODE{
	ACCOUNT_STOPOUT_MODE_PERCENT, //Account stop out mode in percents
	ACCOUNT_STOPOUT_MODE_MONEY   //Account stop out mode in money
};


//*******************************************
//           Testing Statistics
//res::http://www.mql5.com/en/docs/constants/environment_state/statistics
//*******************************************
enum ENUM_STATISTICS{
	 STAT_INITIAL_DEPOSIT,	//double The value of the initial deposit
	 STAT_WITHDRAWAL,		//double Money withdrawn from an account
	 STAT_PROFIT,			//double Net profit after testing, the sum of STAT_GROSS_PROFIT and STAT_GROSS_LOSS(STAT_GROSS_LOSS is always less than or equal to zero)
	 STAT_GROSS_PROFIT,		//double Total profit, the sum of all profitable(positive) trades.The value is greater than or equal to zero
	 STAT_GROSS_LOSS,		//double Total loss, the sum of all negative trades.The value is less than or equal to zero
	 STAT_MAX_PROFITTRADE,	//double Maximum profit  the largest value of all profitable trades.The value is greater than or equal to zero
	 STAT_MAX_LOSSTRADE,	//double Maximum loss  the lowest value of all losing trades.The value is less than or equal to zero
	 STAT_CONPROFITMAX,		//double Maximum profit in a series of profitable trades.The value is greater than or equal to zero
	 STAT_CONPROFITMAX_TRADES, //int The number of trades that have formed STAT_CONPROFITMAX(maximum profit in a series of profitable trades)
	 STAT_MAX_CONWINS,		//double The total profit of the longest series of profitable trades
	 STAT_MAX_CONPROFIT_TRADES, //int The number of trades in the longest series of profitable trades STAT_MAX_CONWINS
	 STAT_CONLOSSMAX,		//double Maximum loss in a series of losing trades.The value is less than or equal to zero
	 STAT_CONLOSSMAX_TRADES, //int The number of trades that have formed STAT_CONLOSSMAX(maximum loss in a series of losing trades)
	 STAT_MAX_CONLOSSES,	//double The total loss of the longest series of losing trades
	 STAT_MAX_CONLOSS_TRADES, //int The number of trades in the longest series of losing trades STAT_MAX_CONLOSSES
	 STAT_BALANCEMIN,		//double Minimum balance value
	 /*
		double Maximum balance drawdown in monetary terms.In the process of trading, a balance may have numerous drawdowns; here 
	 the largest value is taken
	 */
	 STAT_BALANCE_DD,
	 /*
		double Balance drawdown as a percentage that was recorded at the moment of the maximum balance drawdown in monetary
	 terms(STAT_BALANCE_DD).
	 */
	 STAT_BALANCEDD_PERCENT, 
	 /*
		double Maximum balance drawdown as a percentage.In the process of trading, a balance may have numerous drawdowns,
	 for each of which the relative drawdown value in percents is calculated.The greatest value is returned
	 */
	 STAT_BALANCE_DDREL_PERCENT,
	 /*
		double Balance drawdown in monetary terms that was recorded at the moment of the maximum balance drawdown as a
	 percentage(STAT_BALANCE_DDREL_PERCENT).
	 */
	 STAT_BALANCE_DD_RELATIVE, 
	 STAT_EQUITYMIN,		//double Minimum equity value
	 /*
		double Maximum equity drawdown in monetary terms.In the process of trading, numerous drawdowns may appear on the equity; 
	 here the largest value is taken
	 */
	 STAT_EQUITY_DD,		
	 STAT_EQUITYDD_PERCENT, //double Drawdown in percent that was recorded at the moment of the maximum equity drawdown in monetary terms(STAT_EQUITY_DD).
	 /*
		double Maximum equity drawdown as a percentage.In the process of trading, an equity may have numerous drawdowns, 
	 for each of which the relative drawdown value in percents is calculated.The greatest value is returned
	 */
	 STAT_EQUITY_DDREL_PERCENT, 
	 /*
		double Equity drawdown in monetary terms that was recorded at the moment of the maximum equity drawdown in percent
	 (STAT_EQUITY_DDREL_PERCENT).
	 */
	 STAT_EQUITY_DD_RELATIVE, 
	 STAT_EXPECTED_PAYOFF,	//double Expected payoff
	 /*
		double Profit factor, equal to  the ratio of STAT_GROSS_PROFIT / STAT_GROSS_LOSS.If STAT_GROSS_LOSS = 0, the profit factor
	 is equal to DBL_MAX
	 */
	 STAT_PROFIT_FACTOR,	
	 STAT_RECOVERY_FACTOR,	//double Recovery factor, equal to the ratio of STAT_PROFIT / STAT_BALANCE_DD
	 STAT_SHARPE_RATIO,		//double Sharpe ratio
	 STAT_MIN_MARGINLEVEL,	//double Minimum value of the margin level
	 STAT_CUSTOM_ONTESTER,	//double The value of the calculated custom optimization criterion returned by the OnTester() function
	 STAT_DEALS,			//int The number of deals
	 STAT_TRADES,			//int The number of trades
	 STAT_PROFIT_TRADES,	//int Profitable trades
	 STAT_LOSS_TRADES,		//int Losing trades
	 STAT_SHORT_TRADES,		//int Short trades
	 STAT_LONG_TRADES,		//int Long trades
	 STAT_PROFIT_SHORTTRADES,	//int Profitable short trades
	 STAT_PROFIT_LONGTRADES,	//int Profitable long trades
	 STAT_PROFITTRADES_AVGCON,	//int Average length of a profitable series of trades
	 STAT_LOSSTRADES_AVGCON		//int Average length of a losing series of trades
};



//*******************************************
//				Trade Constants
//res::http://www.mql5.com/en/docs/constants/tradingconstants
//*******************************************

//--------History Database Properties
//	When accessing timeseries the SeriesInfoInteger() function is used for obtaining additional symbol information.Identifier of a 
//required property is passed as the function parameter.The identifier can be one of values of ENUM_SERIES_INFO_INTEGER.
enum ENUM_SERIES_INFO_INTEGER{
	SERIES_BARS_COUNT,		//long Bars count for the symbol - period for the current moment
	SERIES_FIRSTDATE,		//datetime The very first date for the symbol - period for the current moment
	SERIES_LASTBAR_DATE,	//datetime Open time of the last bar of the symbol - period
	SERIES_SERVER_FIRSTDATE,	//datetime The very first date in the history of the symbol on the server regardless of the timeframe
	SERIES_TERMINAL_FIRSTDATE,	//datetime The very first date in the history of the symbol in the client terminal, regardless of the timeframe
	SERIES_SYNCHRONIZED		//bool Symbol / period data synchronization flag for the current moment
};


//--------Order Properties
//	Requests to execute trade operations are formalized as orders.Each order has a variety of properties for reading.Information 
//on them can be obtained using functions OrderGet...() and HistoryOrderGet...().

//For functions OrderGetInteger() and HistoryOrderGetInteger()
enum ENUM_ORDER_PROPERTY_INTEGER{
	ORDER_TIME_SETUP,	//datetime Order setup time
	ORDER_TYPE,			//ENUM_ORDER_TYPE Order type ENUM_ORDER_TYPE;
	ORDER_STATE,		//ENUM_ORDER_STATE Order state ENUM_ORDER_STATE;
	ORDER_TIME_EXPIRATION,	//datetime Order expiration time
	ORDER_TIME_DONE,		//datetime Order execution or cancellation time
	ORDER_TIME_SETUP_MSC,	//long The time of placing an order for execution in milliseconds since 01.01.1970
	ORDER_TIME_DONE_MSC,	//long Order execution / cancellation time in milliseconds since 01.01.1970
	ORDER_TYPE_FILLING,		//ENUM_ORDER_TYPE_FILLING Order filling type ENUM_ORDER_TYPE_FILLING
	ORDER_TYPE_TIME,	//ENUM_ORDER_TYPE_TIME Order lifetime	ENUM_ORDER_TYPE_TIME
	ORDER_MAGIC,		//long ID of an Expert Advisor that has placed the order(designed to ensure that each Expert Advisor places its own unique number)
	/*
		long 	Position identifier that is set to an order as soon as it is executed.Each executed order results in a
	deal that opens or modifies an already existing position.The identifier of exactly this position is set to the executed
	order at this moment.
	*/
	ORDER_POSITION_ID
};

//For functions OrderGetDouble() and HistoryOrderGetDouble()
enum ENUM_ORDER_PROPERTY_DOUBLE{
	ORDER_VOLUME_INITIAL, //Order initial volume
	ORDER_VOLUME_CURRENT, //Order current volume
	ORDER_PRICE_OPEN,	  //Price specified in the order
	ORDER_SL,			  //Stop Loss value
	ORDER_TP,			  //Take Profit value
	ORDER_PRICE_CURRENT,  //The current price of the order symbol
	ORDER_PRICE_STOPLIMIT //The Limit order price for the StopLimit order
};


//For functions OrderGetString() and HistoryOrderGetString()
enum ENUM_ORDER_PROPERTY_STRING{
	ORDER_SYMBOL, //Symbol of the order
	ORDER_COMMENT //Order comment
};


//	When sending a trade request using the OrderSend() function, some operations require the indication of the order type.The order type is 
//specified in the type field of the special structure MqlTradeRequest, and can accept values of the ENUM_ORDER_TYPE enumeration.
enum ENUM_ORDER_TYPE{
	ORDER_TYPE_BUY, //Market Buy order
	ORDER_TYPE_SELL, //	Market Sell order
	ORDER_TYPE_BUY_LIMIT, //Buy Limit pending order
	ORDER_TYPE_SELL_LIMIT, //Sell Limit pending order
	ORDER_TYPE_BUY_STOP, //Buy Stop pending order
	ORDER_TYPE_SELL_STOP, //Sell Stop pending order
	ORDER_TYPE_BUY_STOP_LIMIT, //Upon reaching the order price, a pending Buy Limit order is places at the StopLimit price
	ORDER_TYPE_SELL_STOP_LIMIT //Upon reaching the order price, a pending Sell Limit order is places at the StopLimit price
};

//	Each order has a status that describes its state.To obtain information, use OrderGetInteger() or HistoryOrderGetInteger() with the
//ORDER_STATE modifier.Allowed values are stored in the ENUM_ORDER_STATE enumeration.
enum ENUM_ORDER_STATE{
	ORDER_STATE_STARTED, //Order checked, but not yet accepted by broker
	ORDER_STATE_PLACED, //Order accepted
	ORDER_STATE_CANCELED, //Order canceled by client
	ORDER_STATE_PARTIAL, //Order partially executed
	ORDER_STATE_FILLED, //Order fully executed
	ORDER_STATE_REJECTED, //Order rejected
	ORDER_STATE_EXPIRED, //Order expired
	ORDER_STATE_REQUEST_ADD, //Order is being registered(placing to the trading system)
	ORDER_STATE_REQUEST_MODIFY, //Order is being modified(changing its parameters)
	ORDER_STATE_REQUEST_CANCEL //Order is being deleted(deleting from the trading system)
};


//	When sending a trade request using the OrderSend() function, the filling policy can be set for an order in the type_filling 
//field of the special structure MqlTradeRequest.Values of the ENUM_ORDER_TYPE_FILLING enumeration are allowed.To obtain the value 
//of this property, use the function OrderGetInteger() or HistoryOrderGetInteger() with the ORDER_TYPE_FILLING modifier.
enum ENUM_ORDER_TYPE_FILLING{
	/*
		This filling policy means that an order can be filled only in the specified amount.If the necessary 
	amount of a financial instrument is currently unavailable in the market, the order will not be executed.The
	required volume can be filled using several offers available on the market at the moment.
	*/
	ORDER_FILLING_FOK, 
	/*
		This mode means that a trader agrees to execute a deal with the volume maximally available in the market 
	within that indicated in the order.In case the the entire volume of an order cannot be filled, the available
	volume of it will be filled, and the remaining volume will be canceled.
	*/
	ORDER_FILLING_IOC, 
	/*
		This policy is used only for market orders(ORDER_TYPE_BUY and ORDER_TYPE_SELL), limit and stop limit 
	orders(ORDER_TYPE_BUY_LIMIT, ORDER_TYPE_SELL_LIMIT, ORDER_TYPE_BUY_STOP_LIMIT and ORDER_TYPE_SELL_STOP_LIMIT) 
	and only for the symbols with Market or Exchange execution.In case of partial filling a market or limit order 
	with remaining volume is not canceled but processed further.
		For the activation of the ORDER_TYPE_BUY_STOP_LIMIT and ORDER_TYPE_SELL_STOP_LIMIT orders, a corresponding
	limit order ORDER_TYPE_BUY_LIMIT / ORDER_TYPE_SELL_LIMIT with the ORDER_FILLING_RETURN execution type is created.
	*/
	ORDER_FILLING_RETURN 
};

/*
	The order validity period can be set in the type_time field of the special structure MqlTradeRequest when sending a trade request 
sing the OrderSend() function.Values of the ENUM_ORDER_TYPE_TIME enumeration are allowed.To obtain the value of this property use the 
function OrderGetInteger() or HistoryOrderGetInteger() with the ORDER_TYPE_TIME modifier.
*/
enum ENUM_ORDER_TYPE_TIME{
	ORDER_TIME_GTC, //Good till cancel order
	ORDER_TIME_DAY, //Good till current trade day order
	ORDER_TIME_SPECIFIED, //Good till expired order
	/*	
		The order will be effective till 00:00 of the specified day.If this time is outside a trading session,
	the order expires in the nearest trading time.
	*/
	ORDER_TIME_SPECIFIED_DAY 
};


//-----------------Position Properties
/*
	Execution of trade operations results in the opening of a position, changing of its volume and / or direction, or its 
disappearance.Trade operations are conducted based on orders, sent by the OrderSend() function in the form of trade requests.
For each financial security(symbol) only one open position is possible.A position has a set of properties available for reading
by the PositionGet...() functions.
*/
//For the function PositionGetInteger()
enum ENUM_POSITION_PROPERTY_INTEGER{
	POSITION_TIME, //datetime Position open time
	POSITION_TIME_MSC, //long Position opening time in milliseconds since 01.01.1970
	POSITION_TIME_UPDATE, //long Position changing time in seconds since 01.01.1970
	POSITION_TIME_UPDATE_MSC, //long Position changing time in milliseconds since 01.01.1970
	POSITION_TYPE, //ENUM_POSITION_TYPE Position type ENUM_POSITION_TYPE
	POSITION_MAGIC, //long Position magic number(see ORDER_MAGIC)
	/*
		long Position identifier is a unique number that is assigned to every newly opened position and doesn't change
	during the entire lifetime of the position. Position turnover doesn't change its identifier.
	*/
	POSITION_IDENTIFIER 
};

//For the function PositionGetDouble()
enum ENUM_POSITION_PROPERTY_DOUBLE{
	POSITION_VOLUME,	//double Position volume
	POSITION_PRICE_OPEN, //double Position open price
	POSITION_SL,		//double Stop Loss level of opened position
	POSITION_TP,		//double Take Profit level of opened position
	POSITION_PRICE_CURRENT, //double Current price of the position symbol
	POSITION_COMMISSION, //double Commission
	POSITION_SWAP,		//double Cumulative swap
	POSITION_PROFIT		//double Current profit
};


//For the function PositionGetString()
enum ENUM_POSITION_PROPERTY_STRING{
	POSITION_SYMBOL, //string Symbol of the position
	POSITION_COMMENT //string Position comment
};


/*
	Direction of an open position(buy or sell) is defined by the value from the ENUM_POSITION_TYPE enumeration.In 
order to obtain the type of an open position use the PositionGetInteger() function with the POSITION_TYPE modifier.
*/
enum ENUM_POSITION_TYPE{
	POSITION_TYPE_BUY, //Buy
	POSITION_TYPE_SELL //Sell
};



//----------------------Deal Properties
/*
	A deal is the reflection of the fact of a trade operation execution based on an order that contains a trade request.Each 
trade is described by properties that allow to obtain information about it.In order to read values of properties, functions 
of the HistoryDealGet...() type are used, that return values from corresponding enumerations.
*/
//For the function HistoryDealGetInteger()
enum ENUM_DEAL_PROPERTY_INTEGER{
	DEAL_ORDER,  //long Deal order number
	DEAL_TIME, //datetime Deal time
	DEAL_TIME_MSC, //long The time of a deal execution in milliseconds since 01.01.1970
	DEAL_TYPE, //ENUM_DEAL_TYPE Deal type ENUM_DEAL_TYPE
	DEAL_ENTRY, //ENUM_DEAL_ENTRY Deal entry - entry in, entry out, reverse
	DEAL_MAGIC, //long Deal magic number(see ORDER_MAGIC)
	/*
		long 	Identifier of a position, in the opening, modification or change of which this deal took part.Each
	position has a unique identifier that is assigned to all deals executed for the symbol during the
	entire lifetime of the position.
	*/
	DEAL_POSITION_ID 
};

//For the function HistoryDealGetDouble()
enum ENUM_DEAL_PROPERTY_DOUBLE{
	DEAL_VOLUME,	//double Deal volume
	DEAL_PRICE,		//double Deal price
	DEAL_COMMISSION, //double Deal commission
	DEAL_SWAP,		//double Cumulative swap on close
	DEAL_PROFIT		//double Deal profit
};

//For the function HistoryDealGetString()
enum ENUM_DEAL_PROPERTY_STRING{
	DEAL_SYMBOL, //string Deal symbol
	DEAL_COMMENT //string Deal comment
};

/*
	Each deal is characterized by a type, allowed values are enumerated in ENUM_DEAL_TYPE.In order to obtain information 
about the deal type, use the HistoryDealGetInteger() function with the DEAL_TYPE modifier.
*/
enum ENUM_DEAL_TYPE{
	DEAL_TYPE_BUY, //Buy
	DEAL_TYPE_SELL, //Sell
	DEAL_TYPE_BALANCE, //Balance
	DEAL_TYPE_CREDIT, //Credit
	DEAL_TYPE_CHARGE, //Additional charge
	DEAL_TYPE_CORRECTION, //Correction
	DEAL_TYPE_BONUS, //Bonus
	DEAL_TYPE_COMMISSION, //Additional commission
	DEAL_TYPE_COMMISSION_DAILY, //Daily commission
	DEAL_TYPE_COMMISSION_MONTHLY, //Monthly commission
	DEAL_TYPE_COMMISSION_AGENT_DAILY, //Daily agent commission
	DEAL_TYPE_COMMISSION_AGENT_MONTHLY, //Monthly agent commission
	DEAL_TYPE_INTEREST, //Interest rate
	/*
		Canceled buy deal.There can be a situation when a previously executed buy deal is canceled.In this case, the type of
	the previously executed deal(DEAL_TYPE_BUY) is changed to DEAL_TYPE_BUY_CANCELED, and its profit / loss is zeroized.Previously 
	obtained profit / loss is charged / withdrawn using a separated balance operation
	*/
	DEAL_TYPE_BUY_CANCELED,
	/*
		Canceled sell deal.There can be a situation when a previously executed sell deal is canceled.In this case, the type of 
	the previously executed deal(DEAL_TYPE_SELL) is changed to DEAL_TYPE_SELL_CANCELED, and its profit / loss is zeroized.Previously
	obtained profit / loss is charged / withdrawn using a separated balance operation
	*/
	DEAL_TYPE_SELL_CANCELED
};

/*
	Deals differ not only in their types set in ENUM_DEAL_TYPE, but also in the way they change positions.This can be a simple position 
opening, or accumulation of a previously opened position(market entering), position closing by an opposite deal of a corresponding 
volume(market exiting), or position reversing, if the opposite - direction deal covers the volume of the previously opened position.
	All these situations are described by values from the ENUM_DEAL_ENTRY enumeration.In order to receive this information about a deal,
use the HistoryDealGetInteger() function with the DEAL_ENTRY modifier.
*/
enum ENUM_DEAL_ENTRY{
	DEAL_ENTRY_IN, //Entry in
	DEAL_ENTRY_OUT, //Entry out
	DEAL_ENTRY_INOUT //Reverse
};

//-------------------------Trade Operation Types
/*
	Trading is done by sending orders to open positions using the OrderSend() function, as well as to place, modify or delete pending 
orders.Each trade order refers to the type of the requested operation.Trading operations are described in the ENUM_TRADE_REQUEST_ACTIONS
enumeration.
*/
enum ENUM_TRADE_REQUEST_ACTIONS{
	TRADE_ACTION_DEAL, //Place a trade order for an immediate execution with the specified parameters(market order)
	TRADE_ACTION_PENDING, //Place a trade order for the execution under specified conditions(pending order)
	TRADE_ACTION_SLTP, //Modify Stop Loss and Take Profit values of an opened position
	TRADE_ACTION_MODIFY, //Modify the parameters of the order placed previously
	TRADE_ACTION_REMOVE //Delete the pending order placed previously
};


//------------------Trade Transaction Types
enum ENUM_TRADE_TRANSACTION_TYPE{
	//Adding a new open order.
	TRADE_TRANSACTION_ORDER_ADD,
	/*
		Updating an open order.The updates include not only evident changes from the client terminal or a trade server sides but
	also changes of an order state when setting it(for example, transition from ORDER_STATE_STARTED to ORDER_STATE_PLACED or from
	ORDER_STATE_PLACED to ORDER_STATE_PARTIAL, etc.).
	*/
	TRADE_TRANSACTION_ORDER_UPDATE,
	/*
		Removing an order from the list of the open ones.An order can be deleted from the open ones as a result of setting an 
	appropriate request or execution(filling) and moving to the history.
	*/
	TRADE_TRANSACTION_ORDER_DELETE,
	/*
		Adding a deal to the history.The action is performed as a result of an order execution or performing operations with an 
	account balance.
	*/
	TRADE_TRANSACTION_DEAL_ADD,
	/*
		Updating a deal in the history.There may be cases when a previously executed deal is changed on a server.For example,
	a deal has been changed in an external trading system(exchange) where it was previously transferred by a broker.
	*/
	TRADE_TRANSACTION_DEAL_UPDATE,
	/*
		Deleting a deal from the history.There may be cases when a previously executed deal is deleted from a server.For 
	example, a deal has been deleted in an external trading system(exchange) where it was previously transferred by a broker.
	*/
	TRADE_TRANSACTION_DEAL_DELETE,
	//	Adding an order to the history as a result of execution or cancellation.
	TRADE_TRANSACTION_HISTORY_ADD,
	//	Changing an order located in the orders history.This type is provided for enhancing functionality on a trade server side.
	TRADE_TRANSACTION_HISTORY_UPDATE,
	//	Deleting an order from the orders history.This type is provided for enhancing functionality on a trade server side.

	TRADE_TRANSACTION_HISTORY_DELETE,
	/*
		Changing a position not related to a deal execution.This type of transaction shows that a position has been changed
	on a trade server side.Position volume, open price, Stop Loss and Take Profit levels can be changed.Data on changes are 
	submitted in MqlTradeTransaction structure via OnTradeTransaction handler.Position change(adding, changing or closing), 
	as a result of a deal execution, does not lead to the occurrence of TRADE_TRANSACTION_POSITION transaction.
	*/
	TRADE_TRANSACTION_POSITION,
	/*
		Notification of the fact that a trade request has been processed by a server and processing result has been received.
	Only type field(trade transaction type) must be analyzed for such transactions in MqlTradeTransaction structure.The second
	and third parameters of OnTradeTransaction(request and result) must be analyzed for additional data.
	*/
	TRADE_TRANSACTION_REQUEST
};



//--------------Trade Orders in Depth Of Market
/*
	To obtain information about the current state of the DOM by MQL5 means, the MarketBookGet() function is used, which places
the DOM "screen shot" into the MqlBookInfo array of structures.Each element of the array in the type field contains information
about the direction of the order - the value of the ENUM_BOOK_TYPE enumeration.
*/
enum ENUM_BOOK_TYPE{
	BOOK_TYPE_SELL, //Sell order(Offer)
	BOOK_TYPE_BUY, //Buy order(Bid)
	BOOK_TYPE_SELL_MARKET, //Sell order by Market
	BOOK_TYPE_BUY_MARKET //Buy order by Market
};

//--------------------Signal Properties
/*
	The following enumerations are used when working with trading signals and signal copy settings.
Enumeration of double type properties of the trading signal :
*/
enum ENUM_SIGNAL_BASE_DOUBLE{
	SIGNAL_BASE_BALANCE,	//Account balance
	SIGNAL_BASE_EQUITY,		//Account equity
	SIGNAL_BASE_GAIN,		//Account gain
	SIGNAL_BASE_MAX_DRAWDOWN, //Account maximum drawdown
	SIGNAL_BASE_PRICE,		//Signal subscription price
	SIGNAL_BASE_ROI			//Return on Investment(%)
};

//Enumeration of integer type properties of the trading signal :
enum ENUM_SIGNAL_BASE_INTEGER{
	SIGNAL_BASE_DATE_PUBLISHED, //Publication date(date when it become available for subscription)
	SIGNAL_BASE_DATE_STARTED, //Monitoring starting date
	SIGNAL_BASE_ID, //Signal ID
	SIGNAL_BASE_LEVERAGE, //Account leverage
	SIGNAL_BASE_PIPS, //Profit in pips
	SIGNAL_BASE_RATING, //Position in rating
	SIGNAL_BASE_SUBSCRIBERS, //Number of subscribers
	SIGNAL_BASE_TRADES, //Number of trades
	SIGNAL_BASE_TRADE_MODE //Account type(0 - real, 1 - demo, 2 - contest)
};

//Enumeration of string type properties of the trading signal :
enum ENUM_SIGNAL_BASE_STRING{
	SIGNAL_BASE_AUTHOR_LOGIN,	//Author login
	SIGNAL_BASE_BROKER,			//Broker name(company)
	SIGNAL_BASE_BROKER_SERVER,	//Broker server
	SIGNAL_BASE_NAME			//Signal name
};

//Enumeration of double type properties of the signal copy settings :
enum ENUM_SIGNAL_INFO_DOUBLE{
	SIGNAL_INFO_EQUITY_LIMIT,	//Equity limit
	SIGNAL_INFO_SLIPPAGE,		//Slippage(used when placing market orders in synchronization of positions and copying of trades)
	SIGNAL_INFO_VOLUME_PERCENT, //Maximum percent of deposit used(%), r / o
};

//Enumeration of integer type properties of the signal copy settings :
enum ENUM_SIGNAL_INFO_INTEGER{
	SIGNAL_INFO_CONFIRMATIONS_DISABLED, //The flag enables synchronization without confirmation dialog
	SIGNAL_INFO_COPY_SLTP,				//Copy Stop Loss and Take Profit flag
	SIGNAL_INFO_DEPOSIT_PERCENT,		//Deposit percent(%)
	SIGNAL_INFO_ID,						//Signal id, r / o
	SIGNAL_INFO_SUBSCRIPTION_ENABLED,	//"Copy trades by subscription" permission flag
	SIGNAL_INFO_TERMS_AGREE				//"Agree to terms of use of Signals service" flag, r / o
};

//Enumeration of string type properties of the signal copy settings :
enum ENUM_SIGNAL_INFO_STRING{
	SIGNAL_INFO_NAME  //Signal name, r / o
};

enum ENUM_POINTER_TYPE{
	POINTER_INVALID, //Incorrect pointer
	POINTER_DYNAMIC, //Pointer of the object created by the new() operator
	POINTER_AUTOMATIC //Pointer of any objects created automatically(not using new())
};

//------------------------Other Constants

#define CHARTS_MAX		100			//The maximum possible number of simultaneously open charts in the terminal
#define clrNONE			-1			//Absence of color
#define EMPTY_VALUE		DBL_MAX		//Empty value in an indicator buffer
#define INVALID_HANDLE  -1			//Incorrect handle
#define IS_DEBUG_MODE   0			//Flag that a mq5 - program operates in debug mode non zero in debug mode, otherwise zero
#define IS_PROFILE_MODE 0			//Flag that a mq5 - program operates in profiling mode non zero in profiling mode, otherwise zero
#define NULL			0			//Zero for any types
#define WHOLE_ARRAY     -1			//Means the number of items remaining until the end of the array, i.e., the entire array will be processed
#define	WRONG_VALUE     -1          //The constant can be implicitly cast to any enumeration type

enum ENUM_CRYPT_METHOD{
	CRYPT_BASE64, //BASE64
	CRYPT_AES128, //AES encryption with 128 bit key(16 bytes)
	CRYPT_AES256, //AES encryption with 256 bit key(32 bytes)
	CRYPT_DES,    //DES encryption with 56 bit key(7 bytes)
	CRYPT_HASH_SHA1, //SHA1 HASH caculation
	CRYPT_HASH_SHA256, //SHA256 HASH caculation
	CRYPT_HASH_MD5,   //MD5 HASH caculation
	CRYPT_ARCH_ZIP  //ZIP archives
};

//-----------------codepage
#define	CP_ACP 0 //The current Windows ANSI code page.
#define	CP_OEMCP 1 //The current system OEM code page.
/*
The current system Macintosh code page.
Note: This value is mostly used in earlier created program codes and is of no use now,
since modern Macintosh computers use Unicode for encoding.
*/
#define	CP_MACCP 2
#define	CP_THREAD_ACP  3  //The Windows ANSI code page for the current thread.
#define	CP_SYMBOL 	  42  //Symbol code page
#define	CP_UTF7    65000  //UTF - 7 code page.
#define	CP_UTF8	   65001  //UTF - 8 code page.


enum ENUM_COLOR_FORMAT{
	COLOR_FORMAT_XRGB_NOALPHA, //The component of the alpha channel is ignored
	COLOR_FORMAT_ARGB_RAW,	   //Color components are not handled by the terminal(must be correctly set by the user)
	COLOR_FORMAT_ARGB_NORMALIZE //Color components are handled by the terminal
};
//#define PreVariable 
double	Point = 0.00001;	
int		Digits = 4;
int		Bars = 100;
double	Ask = 0.0;
double	Bid = 0.0;
double	Open[1];
double	Close[1];
double	High[1];
double	Low[1];
double	Volume[1];
time_t  Time[1];

//-------MQL5
int    _Digits;
double _Point;
int    _LastError;
int    _Period;
//_RandomSeed
bool   _StopFlag;
string _Symbol;
int    _UninitReason;
#endif