//*******************************************
//          Array functions
//res::http://docs.mql4.com/array
//*******************************************
#ifndef ARRAYSERIES_H__
#define ARRAYSERIES_H__

#include "DataType.h"
#define MODE_ASCEND   1
#define MODE_DESCEND  2

/*
*   If the element with the specified value doesn't exist in the array, the function returns 
the index of the nearest smallest value of the elements between which the searched value is located.
The function cannot be used with string arrays and series arrays (with the exception of the 
series array of the bar open time).
*   Note: Binary search processes only sorted arrays. To sort numeric arrays use the ArraySort() function.
 *Parameters:
	array[]	  -  	The numeric array to search for.
	value	  -  	The value to search for.
	count	  -  	Count of elements to search for. By default, it searches in the whole array.
	start	  -  	Starting index to search for. By default, the search starts at the first element.
	direction	  - Search direction. It can be any of the following values:
	MODE_ASCEND		searching in forward direction,
	MODE_DESCEND	searching in backward direction.
 */
int ArrayBsearch( double array[], double value, int count=WHOLE_ARRAY, int start=0, int direction=MODE_ASCEND);
//The function searches for a specified value in a one - dimension numeric array.
//For searching in an array of double type
int  ArrayBsearch(const double array[], double value);
int  ArrayBsearch(const float  array[], float value);
int  ArrayBsearch(const long array[], long value);
int  ArrayBsearch(const int array[], int value);
int  ArrayBsearch(const short array[], short value);
int  ArrayBsearch(const char array[], char value);

/*
dest[]	  -  	Destination array.
source[]	  - Source array.
start_dest	  - Starting index for the destination array. By default, start index is 0.
start_source	Starting index for the source array. By default, start index is 0.
count	  -  	The count of elements that should be copied. By default, it is WHOLE_ARRAY constant.
 */
//It copies an array into another one.
template< typename TYPE >int  ArrayCopy(
	TYPE		 dst_array[],         // destination array
	const TYPE   src_array[],         // source array
	int          dst_start = 0,         // index starting from which write into destination array
	int          src_start = 0,         // first index of a source array
	int          count = WHOLE_ARRAY    // number of elements
	);

/*
	Copies rates to the two-dimensional array from chart RateInfo array and returns copied bars amount,
or -1 if failed. First dimension of RateInfo array contains bars amount, second dimension has 6 elements:
	0 - time,
	1 - open,
	2 - low,
	3 - high,
	4 - close,
	5 - volume.

	If data (symbol name and/or timeframe differ from the current ones) are requested from another chart, 
the situation is possible that the corresponding chart was not opened in the client terminal and the 
necessary data must be requested from the server. In this case, error ERR_HISTORY_WILL_UPDATED (4066 - the 
requested history data are under updating) will be placed in the last_error variable, and one will has to
re-request (see example of ArrayCopySeries()).

	Notes: This rates array is normally used to pass data to a DLL function.
Memory is not really allocated for data array, and no real copying is performed. When such an array is accessed, the access will be redirected.

Parameters:
	dest_array[]	Reference to the two-dimensional destination array of double type.
	symbol	  -  	Symbol name (currency pair name)
	timeframe	  - Timeframe. It can be any of the listed timeframes values.

Sample:
	double array1[][6];
	ArrayCopyRates(array1,"EURUSD", PERIOD_H1);
	Print("Current bar ",TimeToStr(array1[0][0]),"Open", array1[0][1]);
*/
template<typename N>
int ArrayCopyRates( N dest_array[], string symbol=NULL, int timeframe=0); 

/*
	Copies a series array to another one and returns the count of the copied elements.

	There is no real memory allocation for data array and nothing is copied. When such an array is accessed, 
the access is redirected.Excluded are arrays that are assigned as indexed ones in custom indicators. In this 
case, data are really copied.

	If data are copied from another chart with different symbol and/or timeframe, it is possible that the 
necessary data will lack. Inthis case, error ERR_HISTORY_WILL_UPDATED (4066 - requested history data under
updating) will be placed into the last_error variable, and there will be necessary to retry copying after a
certain period of time.

	Note: If series_index is MODE_TIME, the array to be passed to the function must be of the datetime type.
Parameters:
	array[]	  -  	Reference to the destination one-dimensional numeric array.
	series_index	Series array identifier. It must be one of series array listed identifiers values.
	symbol	  -  	Symbol name (the name of the currency pair)
	timeframe	  - Timeframe of the chart. It can be any of Timeframe list values.
*/
template<typename N>
int ArrayCopySeries(N array[], int series_index, string symbol=NULL, int timeframe=0);

/*
	Returns the multidimensional array rank.
Parameters:
	array[]	  -  	Array for which the rank will be returned.
*/
template<typename N>
int ArrayDimension(	N array[]);

/*
	Returns true if array is organized as a series array (array elements are indexed from the last 
	to the first one), otherwise returns false.
Parameters:
	array[]	  -  	Array to be checked.
*/
template<typename N>
bool ArrayGetAsSeries(N array[]);

/*
	Sets all elements of a numeric array to the same value. Returns the count of initialized elements.
	Note: It is not recommended to initialize index buffers in the custom indicator init() function as 
such functions are initialized automatically 
with an "empty value" at allocation and re-allocation of buffers.
Parameters:
	array[]	  -  	Numeric array to be initialized.
	value	  -  	New value to be set.
*/
template<typename N>
int ArrayInitialize(N array[], N value);

/*
	Returns true if the array under check is a series array (Time[],Open[],Close[],High[],Low[], or Volume[]), otherwise returns false.
Parameters:
	array[]	  -  	Array under check.
 */
template<typename N>
bool ArrayIsSeries(	N array[]);

/*
	Searches for the element with maximum value. The function returns position of this maximum element in the array.
Parameters:
	array[]	  -  	The numeric array to search in.
	count	  -  	The amount of elements to search in.
	start	  -  	Initial search index.
*/
template<typename TYPE>
int ArrayMaximum(TYPE array[], int count=WHOLE_ARRAY, int start=0);

/*
	Searches for the element with minimum value. The function returns position of this minimum element in the array.
Parameters:
	array[]	  -  	The numeric array to search in.
	count	  -  	The amount of elements to search in.
	start	  -  	Initial search index.
*/
template<typename TYPE>
int ArrayMinimum(TYPE array[], int count=WHOLE_ARRAY, int start=0);

/*
	Returns the count of elements in the given dimension of the array. Since indexes are zero-based, the size of 
dimension is 1 greater than the largest index.
Parameters:
	array[]	  -  	Array to check
	range_index	-  	Dimension index.
*/
template<typename N>
int ArrayRange(	N array[], int range_index);

/*
	Sets a new size for the first dimension. If executed successfully, it returns count of all elements contained 
in the array after resizing, otherwise, returns -1, and array is not resized.
	Note: Array declared at a local level in a function and resized will remain unchanged after the function has 
completed its operation. After the function has been recalled, such array will have a size differing from the 
declared one.
	Parameters:
		array[]	  -  	Array to resize.
	new_size	  -  	New size for the first dimension.
*/
template<typename N>
int ArrayResize(N array[], int new_size);
//The function sets a new size for the first dimension
template<typename TYPE>
int  ArrayResize(
	TYPE   array[],              // array passed by reference
	int    new_size,             // new array size
	int    reserve_size = 0      // reserve size value (excess)
);
/*
	Sets indexing direction of the array. If the set parameter has the true value, the array will be indexed 
in a reversed order, i.e., the last element has a zero index. The false value sets a standard indexing order. 
The function returns the previous status.
	The function sets the AS_SERIES flag to a selected object of a dynamic array, and elements will be indexed like in timeseries.
Parameters:
	array[]	  -  	The numeric array to set.
	flag	  -  	Array indexing order.
*/
template<typename TYPE>
bool  ArraySetAsSeries(
const TYPE  array[],    // array by reference
bool         flag       // true denotes reverse order of indexing
);

//Returns the count of elements contained in the array
template<typename N>
int ArraySize(N array[]);

/*
	Sorts numeric arrays by first dimension. Series arrays cannot be sorted by ArraySort().
Parameters:
	array[]	  -  	The numeric array to be sorted.
	count	  -  	Count of elements to be sorted.
	start	  -  	Starting index.
	sort_dir	  - Array sorting direction. It can be any of the following values:
	MODE_ASCEND -	sort ascending,
	MODE_DESCEND -	sort descending.
*/
template<typename N>
int ArraySort(N array[], int count=WHOLE_ARRAY, int start=0, int sort_dir=MODE_ASCEND);
//The function sorts numeric arrays in ascending order from left to right.
template<typename TYPE>
bool  ArraySort(TYPE  array[]); // array for sorting
 

/*
	The function returns the result of comparing two arrays of the same type.It can be used to compare arrays of
simple types or custom structures without complex objects, that is the custom structures that do not contain 
strings, dynamic arrays, classes and other structures with complex objects.
*/
template< typename TYPE >
int  ArrayCompare(
const TYPE   array1[],            // first array
const TYPE   array2[],            // second array
uint         start1 = 0,            // initial offset in the first array
uint         start2 = 0,            // initial offset in the second array
uint         count = WHOLE_ARRAY    // number of elements for comparison
);

//It frees up a buffer of any dynamic array and sets the size of the zero dimension to 0.
template< typename TYPE >
void  ArrayFree(TYPE  array[]);

//The function fills an array with the specified value.
template<typename TYPE>
void  ArrayFill(
	TYPE   array[],      // array
	uint   start,         // starting index
	uint   count,         // number of elements to fill
	void   value          // value
);

//The function checks whether an array is dynamic.
template< typename TYPE >
bool  ArrayIsDynamic(
	const TYPE  array[]    // checked array
);


#endif
