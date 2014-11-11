#ifndef OPTIMIZATION_H_
#define OPTIMIZATION_H_

#include"Framework\standardCPPLibrary.h"
#include"DataType.h"

//Moves a pointer of frame reading to the beginning and resets a set filter.
bool  FrameFirst();

//Sets the frame reading filter and moves the pointer to the beginning.
bool  FrameFilter(
	const string  name,         // Public name/label
	long          id            // Public ID
);

/*
	Reads a frame and moves the pointer to the next one.There are two variants of the function.
	1. Calling to receive one numeric value
*/
bool  FrameNext(
	ulong&   pass,      // The number of a pass in the optimization, during which the frame has been added
	string&  name,      // Public name/label
	long&    id,        // Public ID
	double&  value      // Value
);
//2. Calling to receive all the data of a frame
template<typename TYPE>
bool  FrameNext(
	ulong&   pass,      // The number of a pass in the optimization, during which the frame has been added
	string&  name,      // Public name/label
	long&    id,        // Public ID
	double&  value,     // Value
	TYPE     data[]     // Array of any type
);

//Receives input parameters, on which the frame with the specified pass number is formed.
bool  FrameInputs(
	ulong    pass,                // The number of a pass in the optimization
	string  parameters[],        // An array of strings of form "parameterN=valueN"
	uint&    parameters_count     // The total number of parameters
);

/*
Adds a frame with data.There are two variants of the function.
1. Adding data from a file
*/
bool  FrameAdd(
	const string  name,        // Public name/label
	long          id,          // Public ID
	double        value,       // Value
	const string  filename     // Name of a data file
);
//2. Adding data from an array of any type
template<typename TYPE>
bool  FrameAdd(
	const string  name,        // Public name/label
	long          id,          // Public ID
	double        value,       // Value
	const TYPE   data[]       // Array of any type
);

/*
	Receives data on the values range and the change step for an input variable when optimizing an Expert
Advisor in the Strategy Tester.There are 2 variants of the function.
	1. Receiving data for the integer type input parameter
*/
bool  ParameterGetRange(
	const string  name,          // parameter (input variable) name
	bool&         enable,        // parameter optimization enabled
	long&         value,         // parameter value
	long&         start,         // initial value
	long&         step,          // change step
	long&         stop           // final value
);
//2. Receiving data for the real type input parameter
bool  ParameterGetRange(
	const string  name,          // parameter (input variable) name
	double&       enable,        // parameter optimization enabled
	double&       value,         // parameter value
	double&       start,         // initial value
	double&       step,          // change step
	double&       stop           // final value
);

/*
	Specifies the use of input variable when optimizing an Expert Advisor in the Strategy Tester : value, change step, initial and final values.There are 2 variants of the function.
	1. Specifying the values for the integer type input parameter
*/
bool  ParameterSetRange(
	const string  name,          // parameter (input variable) name
	bool          enable,        // parameter optimization enabled
	long          value,         // parameter value
	long          start,         // initial value
	long          step,          // change step
	long          stop           // final value
);
//2. Specifying the values for the real type input parameter
bool  ParameterSetRange(
	const string  name,          // parameter (input variable) name
	double        enable,        // parameter optimization enabled
	double        value,         // parameter value
	double        start,         // initial value
	double        step,          // change step
	double        stop           // final value
);
#endif