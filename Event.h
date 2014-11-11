#ifndef EVENT_H_
#define EVENT_H_

#include"DataType.h"
#include"Framework\standardCPPLibrary.h"
/*
	The function indicates to the client terminal that timer events should be generated at intervals 
less than one second for this Expert Advisor or indicator.
*/
bool  EventSetMillisecondTimer(
	int  milliseconds      // number of milliseconds
);

/*
	The function indicates to the client terminal, that for this indicator or Expert Advisor, events
from the timer must be generated with the specified periodicity.
*/
bool  EventSetTimer(
	int  seconds      // number of seconds
);

//Specifies the client terminal that is necessary to stop the generation of events from Timer.
void  EventKillTimer();

//The function generates a custom event for the specified chart.
bool  EventChartCustom(
	long    chart_id,            // identifier of the event receiving chart
	ushort  custom_event_id,     // event identifier
	long    lparam,              // parameter of type long
	double  dparam,              // parameter of type double
	string  sparam               // string parameter of the event
);

#endif