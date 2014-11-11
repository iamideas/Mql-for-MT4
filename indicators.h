//*******************************************
//           Technical indicators
//res::http://docs.mql4.com/indicators
//*******************************************
#ifndef INDICATORS_H__
#define INDICATORS_H__

#include"Framework\standardCPPLibrary.h"
#include"DataType.h"
#include"DataStructures.h"
double iAC(string symbol, int timeframe, int shift);
int  iAC(
	string           symbol,     // symbol name
	ENUM_TIMEFRAMES  period      // period
	);
double iAD(string symbol, int timeframe, int shift);
int  iAD(
	string               symbol,             // symbol name
	ENUM_TIMEFRAMES      period,             // period
	ENUM_APPLIED_VOLUME  applied_volume      // volume type for calculation
	);
double iAlligator(string symbol, int timeframe, int jaw_period, int jaw_shift,
		            int teeth_period, int teeth_shift, int lips_period, int lips_shift,
		            int ma_method, int applied_price, int mode, int shift);
int  iAlligator(
	string              symbol,            // symbol name
	ENUM_TIMEFRAMES     period,            // period
	int                 jaw_period,        // period for the calculation of jaws
	int                 jaw_shift,         // horizontal shift of jaws
	int                 teeth_period,      // period for the calculation of teeth
	int                 teeth_shift,       // horizontal shift of teeth
	int                 lips_period,       // period for the calculation of lips
	int                 lips_shift,        // horizontal shift of lips
	ENUM_MA_METHOD      ma_method,         // type of smoothing
	ENUM_APPLIED_PRICE  applied_price      // type of price or handle
	);
double iADX(string symbol, int timeframe, int period, int applied_price, int mode, int shift);
int  iADX(
	string           symbol,         // symbol name
	ENUM_TIMEFRAMES  period,         // period
	int              adx_period      // averaging period
	);
double iATR(string symbol, int timeframe, int period, int shift);
int  iATR(
	string           symbol,        // symbol name
	ENUM_TIMEFRAMES  period,        // period
	int              ma_period      // averaging period 
	);
double iAO(string symbol, int timeframe, int shift);
int  iAO(
	string           symbol,     // symbol name
	ENUM_TIMEFRAMES  period      // period
	);
int  iADXWilder(
	string           symbol,         // symbol name
	ENUM_TIMEFRAMES  period,         // period
	int              adx_period      // averaging period
	);
int  iAMA(
	string              symbol,             // symbol name
	ENUM_TIMEFRAMES     period,             // period
	int                 ama_period,         // average period for AMA
	int                 fast_ma_period,     // fast MA period
	int                 slow_ma_period,     // slow MA period
	int                 ama_shift,          // horizontal shift of the indicator
	ENUM_APPLIED_PRICE  applied_price       // type of the price or handle
	);
double iBearsPower(string symbol, int timeframe, int period, int applied_price, int shift);
int  iBearsPower(
	string              symbol,            // symbol name
	ENUM_TIMEFRAMES     period,            // period
	int                 ma_period         // averaging period
	);
double iBands(string symbol, int timeframe, int period, int deviation, int bands_shift,
				int applied_price, int mode, int shift);
int  iBands(
	string              symbol,            // symbol name
	ENUM_TIMEFRAMES     period,            // period
	int                 bands_period,      // period for average line calculation
	int                 bands_shift,       // horizontal shift of the indicator
	double              deviation,         // number of standard deviations
	ENUM_APPLIED_PRICE  applied_price      // type of price or handle
);
double iBandsOnArray(double array[], int total, int period, int deviation, int bands_shift,
						int mode, int shift);
double iBullsPower(string symbol, int timeframe, int period, int applied_price, int shift);
int  iBullsPower(
	string              symbol,            // symbol name
	ENUM_TIMEFRAMES     period,            // period
	int                 ma_period         // averaging period
);
double iCCI(string symbol, int timeframe, int period, int applied_price, int shift);
int  iCCI(
	string              symbol,            // symbol name
	ENUM_TIMEFRAMES     period,            // period
	int                 ma_period,         // averaging period
	ENUM_APPLIED_PRICE  applied_price      // type of price or handle
	);
double iCCIOnArray(	double array[], int total, int period, int shift);
int  iChaikin(
	string               symbol,             // symbol name
	ENUM_TIMEFRAMES      period,             // period
	int                  fast_ma_period,     // fast period
	int                  slow_ma_period,     // slow period
	ENUM_MA_METHOD       ma_method,          // smoothing type
	ENUM_APPLIED_VOLUME  applied_volume      // type of volume
	);
template< typename type > double iCustom(type para, ...);
int  iCustom(
	string           symbol,     // symbol name
	ENUM_TIMEFRAMES  period,     // period
	string           name        // folder/custom_indicator_name
	...                          // list of indicator input parameters
);
double iDeMarker(string symbol, int timeframe, int period, int shift);
int  iDeMarker(
	string           symbol,        // symbol name
	ENUM_TIMEFRAMES  period,        // period
	int              ma_period      // averaging period
	);
int  iDEMA(
	string              symbol,            // symbol name
	ENUM_TIMEFRAMES     period,            // period
	int                 ma_period,         // averaging period
	int                 ma_shift,          // horizontal shift
	ENUM_APPLIED_PRICE  applied_price      // type of price or handle
	);
double iEnvelopes(string symbol, int timeframe, int ma_period, int ma_method, int ma_shift,
					int applied_price, double deviation, int mode, int shift);
int  iEnvelopes(
	string              symbol,            // symbol name
	ENUM_TIMEFRAMES     period,            // period
	int                 ma_period,         // period for the average line calculation
	int                 ma_shift,          // horizontal shift of the indicator
	ENUM_MA_METHOD      ma_method,         // type of smoothing
	ENUM_APPLIED_PRICE  applied_price,     // type of price or handle
	double              deviation          // deviation of boundaries from the midline (in percents)
	);
double iEnvelopesOnArray(double array[], int total, int ma_period, int ma_method, int ma_shift,
							double deviation, int mode, int shift);
double iForce(string symbol, int timeframe, int period, int ma_method, int applied_price, int shift);
int  iForce(
	string              symbol,            // symbol name
	ENUM_TIMEFRAMES     period,            // period
	int                 ma_period,         // averaging period
	ENUM_MA_METHOD      ma_method,         // smoothing type
	ENUM_APPLIED_VOLUME applied_volume     // volume type for calculation
	);
double iFractals(string symbol, int timeframe, int mode, int shift);
int  iFractals(
	string           symbol,     // symbol name
	ENUM_TIMEFRAMES  period      // period
	);
int  iFrAMA(
	string              symbol,            // symbol name
	ENUM_TIMEFRAMES     period,            // period
	int                 ma_period,         // averaging period
	int                 ma_shift,          // horizontal shift on the chart
	ENUM_APPLIED_PRICE  applied_price      // type of price or handle
	);
double iGator(string symbol, int timeframe, int jaw_period, int jaw_shift, int teeth_period,
				int teeth_shift, int lips_period, int lips_shift, int ma_method, int applied_price,
				int mode, int shift);
int  iGator(
	string              symbol,            // symbol name
	ENUM_TIMEFRAMES     period,            // period
	int                 jaw_period,        // period for the calculation of the jaws
	int                 jaw_shift,         // jaws horizontal shift
	int                 teeth_period,      // period for the calculation of the teeth
	int                 teeth_shift,       // teeth horizontal shift
	int                 lips_period,       // period for the calculation of the lips
	int                 lips_shift,        // lips horizontal shift
	ENUM_MA_METHOD      ma_method,         // type of smoothing
	ENUM_APPLIED_PRICE  applied_price      // type of price or handle
	);
double iIchimoku(string symbol, int timeframe, int tenkan_sen, int kijun_sen, int senkou_span_b,
					int mode, int shift);
int  iIchimoku(
	string           symbol,            // symbol name
	ENUM_TIMEFRAMES  period,            // period
	int              tenkan_sen,        // period of Tenkan-sen
	int              kijun_sen,         // period of Kijun-sen
	int              senkou_span_b      // period of Senkou Span B
	);
double iBWMFI(string symbol, int timeframe, int shift);
int  iBWMFI(
	string               symbol,             // symbol name
	ENUM_TIMEFRAMES      period,             // period
	ENUM_APPLIED_VOLUME  applied_volume      // volume type for calculation
	);
double iMomentum(string symbol, int timeframe, int period, int applied_price, int shift);
int  iMomentum(
	string               symbol,            // symbol name
	ENUM_TIMEFRAMES      period,            // period
	int                  mom_period,        // averaging period
	ENUM_APPLIED_PRICE   applied_price      // type of price or handle
	);
double iMomentumOnArray(double array[], int total, int period, int shift);
double iMFI(string symbol, int timeframe, int period, int shift);
int  iMFI(
	string               symbol,             // symbol name
	ENUM_TIMEFRAMES      period,             // period
	int                  ma_period,          // averaging period
	ENUM_APPLIED_VOLUME  applied_volume      // volume type for calculation
	);
double iMA(string symbol, int timeframe, int period, int ma_shift, int ma_method, int applied_price, int shift);
int  iMA(
	string               symbol,            // symbol name
	ENUM_TIMEFRAMES      period,            // period
	int                  ma_period,         // averaging period
	int                  ma_shift,          // horizontal shift
	ENUM_MA_METHOD       ma_method,         // smoothing type
	ENUM_APPLIED_PRICE   applied_price      // type of price or handle
	);
double iMAOnArray(double array[], int total, int period, int ma_shift, int ma_method, int shift);
double iOsMA(string symbol, int timeframe, int fast_ema_period, int slow_ema_period, int signal_period,
				int applied_price, int shift);
int  iOsMA(
	string              symbol,              // symbol name
	ENUM_TIMEFRAMES     period,              // period
	int                 fast_ema_period,     // period for Fast Moving Average
	int                 slow_ema_period,     // period for Slow Moving Average
	int                 signal_period,       // averaging period for their difference
	ENUM_APPLIED_PRICE  applied_price        // type of price or handle
	);
double iMACD(string symbol, int timeframe, int fast_ema_period, int slow_ema_period, int signal_period,
				int applied_price, int mode, int shift);
int  iMACD(
	string              symbol,              // symbol name
	ENUM_TIMEFRAMES     period,              // period
	int                 fast_ema_period,     // period for Fast average calculation
	int                 slow_ema_period,     // period for Slow average calculation
	int                 signal_period,       // period for their difference averaging
	ENUM_APPLIED_PRICE  applied_price        // type of price or handle
	);
double iOBV(string symbol, int timeframe, int applied_price, int shift);
int  iOBV(
	string                symbol,             // symbol name
	ENUM_TIMEFRAMES       period,             // period
	ENUM_APPLIED_VOLUME   applied_volume      // volume type for calculation
	);
double iSAR(string symbol, int timeframe, double step, double maximum, int shift);
int  iSAR(
	string           symbol,      // symbol name
	ENUM_TIMEFRAMES  period,      // period
	double           step,        // step increment
	double           maximum      // maximal stop level
	);
int  iRSI(
	string              symbol,            // symbol name
	ENUM_TIMEFRAMES     period,            // period
	int                 ma_period,         // averaging period
	ENUM_APPLIED_PRICE  applied_price      // type of price or handle
	);
double iRSI(string symbol, int timeframe, int period, int applied_price, int shift);
double iRSIOnArray(double array[], int total, int period, int shift);
double iRVI(string symbol, int timeframe, int period, int mode, int shift);
int  iRVI(
	string           symbol,        // symbol name
	ENUM_TIMEFRAMES  period,        // period
	int              ma_period      // averaging period
	);
double iStdDev(string symbol, int timeframe, int ma_period, int ma_shift, int ma_method, int applied_price, int shift);
int  iStdDev(
	string              symbol,            // symbol name
	ENUM_TIMEFRAMES     period,            // period
	int                 ma_period,         // averaging period
	int                 ma_shift,          // horizontal shift
	ENUM_MA_METHOD      ma_method,         // smoothing type
	ENUM_APPLIED_PRICE  applied_price      // type of price or handle
	);
double iStdDevOnArray(double array[], int total, int ma_period, int ma_shift, int ma_method, int shift);
double iStochastic(string symbol, int timeframe, int Kperiod, int Dperiod, int slowing, int method,
					int price_field, int mode, int shift);
int  iStochastic(
	string           symbol,          // symbol name
	ENUM_TIMEFRAMES  period,          // period
	int              Kperiod,         // K-period (number of bars for calculations)
	int              Dperiod,         // D-period (period of first smoothing)
	int              slowing,         // final smoothing
	ENUM_MA_METHOD   ma_method,       // type of smoothing
	ENUM_STO_PRICE   price_field      // stochastic calculation method
	);
double iWPR(string symbol, int timeframe, int period, int shift);
int  iTEMA(
	string              symbol,            // symbol name
	ENUM_TIMEFRAMES     period,            // period
	int                 ma_period,         // averaging period
	int                 ma_shift,          // horizontal shift of indicator
	ENUM_APPLIED_PRICE  applied_price      // type of price or handle
	);
int  iTriX(
	string              symbol,            // symbol name
	ENUM_TIMEFRAMES     period,            // period
	int                 ma_period,         // averaging period
	ENUM_APPLIED_PRICE  applied_price      // type of price or handle
	);
int  iWPR(
	string           symbol,          // symbol name
	ENUM_TIMEFRAMES  period,          // period
	int              calc_period      // averaging period
	);
int  iVIDyA(
	string              symbol,            // symbol name
	ENUM_TIMEFRAMES     period,            // period
	int                 cmo_period,        // period for Chande Momentum
	int                 ema_period,        // EMA smoothing period
	int                 ma_shift,          // horizontal shift on the price chart
	ENUM_APPLIED_PRICE  applied_price      // type of price or handle
	);
int  iVolumes(
	string               symbol,             // symbol name
	ENUM_TIMEFRAMES      period,             // period
	ENUM_APPLIED_VOLUME  applied_volume      // volume type for calculation
	);
//Returns information about the state of historical data.There are 2 variants of function calls.
long  SeriesInfoInteger(
	string                     symbol_name,     // symbol name
	ENUM_TIMEFRAMES            timeframe,       // period
	ENUM_SERIES_INFO_INTEGER   prop_id          // property identifier
);
//Returns true or false depending on the success of the function run.
bool  SeriesInfoInteger(
	string                     symbol_name,     // symbol name
	ENUM_TIMEFRAMES            timeframe,       // period
	ENUM_SERIES_INFO_INTEGER   prop_id,         // property ID
	long&                      long_var         // variable for getting info
);

//Returns the number of bars count in the history for a specified symbol and period.There are 2 variants of functions calls.
//Request all of the history bars
int  Bars(
	string           symbol_name,     // symbol name
	ENUM_TIMEFRAMES  timeframe        // period
);
//Request the history bars for the selected time interval
int  Bars(
	string           symbol_name,     // symbol name
	ENUM_TIMEFRAMES  timeframe,       // period
	datetime         start_time,      // start date and time
	datetime         stop_time        // end date and time
);

//Returns the number of calculated data for the specified indicator.
int  BarsCalculated(int indicator_handle);

//The function returns the handle of a specified technical indicator created based on the array of parameters of MqlParam type.
int  IndicatorCreate(
	string           symbol,                            // symbol name
	ENUM_TIMEFRAMES  period,                            // timeframe
	ENUM_INDICATOR   indicator_type,                    // indicator type from the enumeration ENUM_INDICATOR
	int              parameters_cnt = 0,                // number of parameters
	const MqlParam  parameters_array[] = NULL           // array of parameters
);

//Based on the specified handle, returns the number of input parameters of the indicator, as well as the values and types of the parameters.
int  IndicatorParameters(
	int               indicator_handle,     // indicator handle
	ENUM_INDICATOR&   indicator_type,       // a variable for receiving the indicator type
	MqlParam          parameters[]          // an array for receiving parameters
);

//The function removes an indicator handle and releases the calculation block of the indicator, if it's not used by anyone else.
bool  IndicatorRelease(int  indicator_handle);

//Call by the first position and the number of required elements
int  CopyBuffer(
	int       indicator_handle,     // indicator handle
	int       buffer_num,           // indicator buffer number
	int       start_pos,            // start position
	int       count,                // amount to copy
	double    buffer[]              // target array to copy
);
//Call by the start date and the number of required elements
int  CopyBuffer(
	int       indicator_handle,     // indicator handle
	int       buffer_num,           // indicator buffer number
	datetime  start_time,           // start date and time
	int       count,                // amount to copy
	double    buffer[]              // target array to copy
);
//Call by the start and end dates of a required time interval
int  CopyBuffer(
	int       indicator_handle,     // indicator handle
	int       buffer_num,           // indicator buffer number
	datetime  start_time,           // start date and time
	datetime  stop_time,            // end date and time
	double    buffer[]              // target array to copy
);

//Call by the first position and the number of required elements
int  CopyRates(
	string           symbol_name,       // symbol name
	ENUM_TIMEFRAMES  timeframe,         // period
	int              start_pos,         // start position
	int              count,             // data count to copy
	MqlRates         rates_array[]      // target array to copy
);
//Call by the start date and the number of required elements
int  CopyRates(
	string           symbol_name,       // symbol name
	ENUM_TIMEFRAMES  timeframe,         // period
	datetime         start_time,        // start date and time
	int              count,             // data count to copy
	MqlRates         rates_array[]      // target array to copy
);
//Call by the start and end dates of a required time interval
int  CopyRates(
	string           symbol_name,       // symbol name
	ENUM_TIMEFRAMES  timeframe,         // period
	datetime         start_time,        // start date and time
	datetime         stop_time,         // end date and time
	MqlRates         rates_array[]      // target array to copy
);

//Call by the first position and the number of required elements
int  CopyTime(
	string           symbol_name,     // symbol name
	ENUM_TIMEFRAMES  timeframe,       // period
	int              start_pos,       // start position
	int              count,           // data count to copy
	datetime         time_array[]     // target array to copy open times
);
//Call by the start date and the number of required elements
int  CopyTime(
	string           symbol_name,     // symbol name
	ENUM_TIMEFRAMES  timeframe,       // period
	datetime         start_time,      // start date and time
	int              count,           // data count to copy
	datetime         time_array[]     // target array to copy  open times
);
//Call by the start and end dates of a required time interval
int  CopyTime(
	string           symbol_name,     // symbol name
	ENUM_TIMEFRAMES  timeframe,       // period
	datetime         start_time,      // start date and time
	datetime         stop_time,       // stop date and time
	datetime         time_array[]     // target array to copy open times
);

//Call by the first position and the number of required elements
int  CopyOpen(
	string           symbol_name,     // symbol name
	ENUM_TIMEFRAMES  timeframe,       // period
	int              start_pos,       // start position
	int              count,           // data count to copy
	double           open_array[]     // target array to copy open prices
);
//Call by the start date and the number of required elements
int  CopyOpen(
	string           symbol_name,     // symbol name
	ENUM_TIMEFRAMES  timeframe,       // period
	datetime         start_time,      // start date and time
	int              count,           // data count to copy
	double           open_array[]     // target array for bar open prices
);
//Call by the start and end dates of a required time interval
int  CopyOpen(
	string           symbol_name,     // symbol name
	ENUM_TIMEFRAMES  timeframe,       // period
	datetime         start_time,      // start date and time
	datetime         stop_time,       // stop date and time
	double           open_array[]     // target array for bar open values
);

//Call by the first position and the number of required elements
int  CopyHigh(
	string           symbol_name,      // symbol name
	ENUM_TIMEFRAMES  timeframe,        // period
	int              start_pos,        // start position
	int              count,            // data count to copy
	double           high_array[]      // target array to copy
);
//Call by the start date and the number of required elements
int  CopyHigh(
	string           symbol_name,      // symbol name
	ENUM_TIMEFRAMES  timeframe,        // period
	datetime         start_time,       // start date and time
	int              count,            // data count to copy
	double           high_array[]      // target array to copy
);
//Call by the start and end dates of a required time interval
int  CopyHigh(
	string           symbol_name,      // symbol name
	ENUM_TIMEFRAMES  timeframe,        // period
	datetime         start_time,       // start date and time
	datetime         stop_time,        // stop date and time
	double           high_array[]      // target array to copy
);

//Call by the first position and the number of required elements
int  CopyLow(
	string           symbol_name,     // symbol name
	ENUM_TIMEFRAMES  timeframe,       // period
	int              start_pos,       // start position
	int              count,           // data count to copy
	double           low_array[]      // target array to copy
);
//Call by the start date and the number of required elements
int  CopyLow(
	string           symbol_name,     // symbol name
	ENUM_TIMEFRAMES  timeframe,       // period
	datetime         start_time,      // start date and time
	int              count,           // data count to copy
	double           low_array[]      // target array to copy
);
//Call by the start and end dates of a required time interval
int  CopyLow(
	string           symbol_name,     // symbol name
	ENUM_TIMEFRAMES  timeframe,       // period
	datetime         start_time,      // start date and time
	datetime         stop_time,       // stop date and time
	double           low_array[]      // target array to copy
);

//Call by the first position and the number of required elements
int  CopyClose(
	string           symbol_name,       // symbol name
	ENUM_TIMEFRAMES  timeframe,         // period
	int              start_pos,         // start position
	int              count,             // data count to copy
	double           close_array[]      // target array to copy
);
//Call by the start date and the number of required elements
int  CopyClose(
	string           symbol_name,       // symbol name
	ENUM_TIMEFRAMES  timeframe,         // period
	datetime         start_time,        // start date and time
	int              count,             // data count to copy
	double           close_array[]      // target array to copy
);
//Call by the start and end dates of a required time interval
int  CopyClose(
	string           symbol_name,       // symbol name
	ENUM_TIMEFRAMES  timeframe,         // period
	datetime         start_time,        // start date and time
	datetime         stop_time,         // stop date and time
	double           close_array[]      // target array to copy
);

//Call by the first position and the number of required elements
int  CopyTickVolume(
	string           symbol_name,      // symbol name
	ENUM_TIMEFRAMES  timeframe,        // period
	int              start_pos,        // start position
	int              count,            // data count to copy
	long             volume_array[]    // target array for tick volumes
);
//Call by the start date and the number of required elements
int  CopyTickVolume(
	string           symbol_name,      // symbol name
	ENUM_TIMEFRAMES  timeframe,        // period
	datetime         start_time,       // start date and time
	int              count,            // data count to copy
	long             volume_array[]    // target array for tick volumes
);
//Call by the start and end dates of a required time interval
int  CopyTickVolume(
	string           symbol_name,      // symbol name
	ENUM_TIMEFRAMES  timeframe,        // period
	datetime         start_time,       // start date and time
	datetime         stop_time,        // stop date and time
	long             volume_array[]    // target array for tick volumes
);

//Call by the first position and the number of required elements
int  CopyRealVolume(
	string           symbol_name,      // symbol name
	ENUM_TIMEFRAMES  timeframe,        // period
	int              start_pos,        // start position
	int              count,            // data count to copy
	long             volume_array[]    // target array for volumes values
);
//Call by the start date and the number of required elements
int  CopyRealVolume(
	string           symbol_name,      // symbol name
	ENUM_TIMEFRAMES  timeframe,        // period
	datetime         start_time,       // start date and time
	int              count,            // data count to copy
	long             volume_array[]    // target array for volumes values
);
//Call by the start and end dates of a required time interval
int  CopyRealVolume(
	string           symbol_name,      // symbol name
	ENUM_TIMEFRAMES  timeframe,        // period
	datetime         start_time,       // start date and time
	datetime         stop_time,        // stop date and time
	long             volume_array[]    // target array for volumes values
);

//Call by the first position and the number of required elements
int  CopySpread(
	string           symbol_name,      // symbol name
	ENUM_TIMEFRAMES  timeframe,        // period
	int              start_pos,        // start position
	int              count,            // data count to copy
	int              spread_array[]    // target array for spread values
);
//Call by the start date and the number of required elements
int  CopySpread(
	string           symbol_name,      // symbol name
	ENUM_TIMEFRAMES  timeframe,        // period
	datetime         start_time,       // start date and time
	int              count,            // data count to copy
	int              spread_array[]    // target array for spread values
);
//Call by the start and end dates of a required time interval
int  CopySpread(
	string           symbol_name,      // symbol name
	ENUM_TIMEFRAMES  timeframe,        // period
	datetime         start_time,       // start date and time
	datetime         stop_time,        // stop date and time
	int              spread_array[]    // target array for spread values
);
#endif
