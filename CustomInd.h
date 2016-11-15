//*******************************************
//          Custom indicators
//res::http://docs.mql4.com/customind
//*******************************************
#ifndef CUSTOMIND_H__
#define CUSTOMIND_H__

#include"Framework/standardCPPLibrary.h"
#include"DataType.h"

/*
 *	  Allocates memory for buffers used for custom indicator calculations. The
 * amount of buffers cannot exceed 8 or be less than the value given in the
 * indicator_buffers property. If custom indicator requires additional buffers
 * for counting, this function must be used for specifying of the total amount
 * of buffers.
 *	 Parameters:
 *		count -	Amount of buffers to be allocated. Should be within the range
 *			between indicator_buffers and 8 buffers.
 */
void IndicatorBuffers(int count);

/*
 * 	 The function returns the amount of bars not changed after the indicator had
 *been launched last. The most calculated bars do not need any recalculation. In
 *most cases, same count of index values do not need for recalculation.
 *been  The function is used to optimize calculating.
*	Note: The latest bar is not considered to be calculated and, in the most cases,
* it is necessary to recalculate only this bar. However, there occur some boundary
* cases where custom indicator is called from the expert at the first tick of the
* new bar. It is possible that the last tick of the previous bar had not been
* processed (because the last-but-one tick was being processed when this last tick
* came), the custom indicator was not called and it was not calculated because of
* this. To avoid indicator calculation errors in such situations, the IndicatorCounted()
* function returns the count of bars minus one.
 */
int IndicatorCounted();

/*
 *	 Sets precision format (the count of digits after decimal point) to visualize
 *indicator values. The symbol price preicision is used by default, the indicator
 *being attached to this symbol chart.
 */
void IndicatorDigits(int digits);

/*
 * 	 Sets the "short" name of a custom indicator to be shown in the DataWindow and
 *in the chart subwindow.
 */
void IndicatorShortName(string name);

/*
 * 	Sets an arrow symbol for indicators line of the DRAW_ARROW type.
 *Arrow codes out of range 33 to 255 cannot be used.
 */
void SetIndexArrow(int index, int code);

/*
 * 	 Binds the array variable declared at a global level to the custom indicator
 * pre-defined buffer. The amount of buffers needed to calculate the indicator is
 * set with the IndicatorBuffer() function and cannot exceed 8. If it succeeds,
 * true will be returned, otherwise, it will be false. To get the extended information
 * about the error, one has to call the GetLastError() function.
 *
 * 	Parameters:
		index	  -  	Line index. Must lie between 0 and 7.
		array[]	  -  	Array that stores calculated indicator values.
 *
 */
bool SetIndexBuffer(int index, double array[]);
bool  SetIndexBuffer(
	int                    index,         // buffer index
	double                 buffer[],      // array
	ENUM_INDEXBUFFER_TYPE  data_type      // what will be stored
	);
/*
 * 	 Sets the bar number (from the data beginning) from which the drawing of the given
 * indicator line must start. The indicators are drawn from left to right. The indicator
 * array values that are to the left of the given bar will not be shown in the chart or
 * in the DataWindow. 0 will be set as default, and all data will be drawn.
 *
 *	Parameters:
 *		index	  -  	Line index. Must lie between 0 and 7.
 *		begin	  -  	First drawing bar position number.
 */
void SetIndexDrawBegin(int index, int begin);

/*
 * 	 Sets drawing line empty value. Empty values are not drawn or shown in the DataWindow.
 * By default, empty value is EMPTY_VALUE.
 *
 *	 Parameters:
 * 		index	  -  	Line index. Must lie between 0 and 7.
 *		value	  -  	New "empty" value.
 */
void SetIndexEmptyValue(int index, double value);

/*
 * 	 Sets drawing line description for showing in the DataWindow and in the tooltip.
 *
 *	 Parameters:
 *		index	  -  	Line index. Must lie between 0 and 7.
 *		text	  -  	Label text. NULL means that index value is not shown in the DataWindow.
 *
 */
void SetIndexLabel(int index, string text);

/*
 * 	 Sets offset for the drawing line. For positive values, the line drawing will be shifted
 * to the right, otherwise it will be shifted to the left. I.e., the value calculated on the
 * current bar will be drawn shifted relatively to the current bar.
 *
 *	 Parameters:
 *		index	  -  	Line index. Must lie between 0 and 7.
 * 		shift	  -  	Shitf value in bars.
 */
void SetIndexShift(int index, int shift);

/*
 * 	 Sets the new type, style, width and color for a given indicator line.
 *	 Parameters:
 *		index	  -  	Line index. Must lie between 0 and 7.
 *		type	  -  	Shape style. Can be one of Drawing shape styles listed.
 *		style	  -  		Drawing style. It is used for one-pixel thick lines. It can be one of the
						Drawing shape styles listed. EMPTY value means that the style will not be changed.
 *		width	  -  		Line width. Valid values are: 1,2,3,4,5. EMPTY value means that width will
						not be changed.
 *		clr	  	  -  	Line color. Absence of this parameter means that the color will not be changed.
 */
void SetIndexStyle(int index, int type, int style=EMPTY, int widty=EMPTY, color clr=CLR_NONE);

/*
 * 	 The function sets a new style, width and color of horizontal levels of indicator to be output in a
 * separate window.
 *	 Parameters:
 *		draw_style	  -  		Drawing style. Can be one of the Drawing shape styles listed. EMPTY value
 *							means that the style will not be changed.
 *		line_width	  -  		Line width. Valid values are 1,2,3,4,5. EMPTY value indicates that the width
 *							will not be changed.
 *		clr	  		  -  	Line color. Empty value CLR_NONE means that the color will not be changed.
 */
void SetLevelStyle(int draw_style, int line_width, color clr=CLR_NONE);

/*
 * 	 The function sets a value for a given horizontal level of the indicator to be output in a separate window.
 *
 *	Parameters:
 *		level	  -  	Level index (0-31).
 *		value	  -  	Value for the given indicator level.
 */
void SetLeveValue(int level, double value);

/*
	The function sets the value of the corresponding indicator property.Indicator property must be of the double
type.There are two variants of the function.
	Call with specifying the property identifier.
*/
bool  IndicatorSetDouble(
	int     prop_id,           // identifier  ENUM_CUSTOMIND_PROPERTY_STRING
	double  prop_value         // value to be set
);

//Call with specifying the property identifier and modifier.
bool  IndicatorSetDouble(
	int     prop_id,           // identifier  ENUM_CUSTOMIND_PROPERTY_STRING
	int     prop_modifier,     // modifier
	double  prop_value         // value to be set
);

/*
	The function sets the value of the corresponding indicator property.Indicator property must be of the int 
or color type.There are two variants of the function.
	Call with specifying the property identifier.
*/
bool  IndicatorSetInteger(
	int  prop_id,           // identifier v ENUM_CUSTOMIND_PROPERTY_STRING
	int  prop_value         // value to be set
);

//Call with specifying the property identifier and modifier.
bool  IndicatorSetInteger(
	int  prop_id,           // identifier  ENUM_CUSTOMIND_PROPERTY_STRING
	int  prop_modifier,     // modifier
	int  prop_value         // value to be set
);

/*
	The function sets the value of the corresponding indicator property.Indicator property must be of 
the string type.There are two variants of the function.
Call with specifying the property identifier.
*/
bool  IndicatorSetString(
	int     prop_id,           // identifier  ENUM_CUSTOMIND_PROPERTY_STRING
	string  prop_value         // value to be set
);

//Call with specifying the property identifier and modifier.
bool  IndicatorSetString(
	int     prop_id,           // identifier  ENUM_CUSTOMIND_PROPERTY_STRING
	int     prop_modifier,     // modifier
	string  prop_value         // value to be set
);

/*
	The function sets the value of the corresponding property of the corresponding indicator line.The indicator
property must be of the double type.
*/
bool  PlotIndexSetDouble(
	int     plot_index,     // plotting style index
	int     prop_id,        // property identifier
	double  prop_value      // value to be set
);

/*
	The function sets the value of the corresponding property of the corresponding indicator line.The 
indicator property must be of the int, char, bool or color type.There are 2 variants of the function.
	Call indicating identifier of the property.
*/
bool  PlotIndexSetInteger(
	int  plot_index,        // plotting style index
	int  prop_id,           // property identifier ENUM_PLOT_PROPERTY_INTEGER
	int  prop_value         // value to be set
);

//Call indicating the identifier and modifier of the property.
bool  PlotIndexSetInteger(
	int  plot_index,        // plotting style index
	int  prop_id,           // property identifier ENUM_PLOT_PROPERTY_INTEGER
	int  prop_modifier,     // property modifier
	int  prop_value         // value to be set
);

/*
	The function sets the value of the corresponding property of the corresponding indicator line.The 
indicator property must be of the string type.
*/
bool  PlotIndexSetString(
	int     plot_index,     // plotting style index
	int     prop_id,        // property identifier ENUM_PLOT_PROPERTY_INTEGER
	string  prop_value      // value to be set
);

/*
	The function sets the value of the corresponding property of the corresponding indicator line.The 
indicator property must be of the int, color, bool or char type.There are 2 variants of the function.
	Call indicating identifier of the property.
*/
int  PlotIndexGetInteger(
	int  plot_index,        // plotting style index
	int  prop_id           // property identifier
);

//Call indicating the identifier and modifier of the property.
int  PlotIndexGetInteger(
	int  plot_index,        // plotting index
	int  prop_id,           // property identifier
	int  prop_modifier      // property modifier
);
#endif
