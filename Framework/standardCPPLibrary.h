#ifndef STANDARDCPPLIBRARY_H__
#define STANDARDCPPLIBRARY_H__

//C
#include<stdlib.h>
#include<stdarg.h>
#include<time.h>

//C++
#include<iostream>
#include<string>
#include<vector>

using namespace std;


class datetime{
public:
	//construct
	datetime() :timer(0){
	}
	datetime(string time){
		timer = mktime(&format(time));
	}
	datetime(time_t time) :timer(time){ /* nothing */ }

	bool operator!=(time_t rhs){
		return this->getTime() == rhs ? false : true;
	}

	//
	string operator=(const string &rhs){
		return asctime(&format(rhs));
	}
	string operator=(const time_t &rhs){
		struct tm *localtimer;
		localtimer = localtime(&rhs);

		return asctime(localtimer);
	}

	int operator[](int i){
		return getTime();
	}
	int getTime(){ return this->timer; }

	~datetime(){ /*nothing*/ }

private:
	//privatge classes ¡¢functions
	struct tm format(string rhs){
		struct tm time = { 0 };
		return time;
	}

	//prative parameters
	time_t timer;
};


datetime operator+(datetime &lhs, datetime &rhs){
	return lhs.getTime() + rhs.getTime();
}
datetime operator-(datetime &lhs, datetime &rhs){
	return lhs.getTime() - rhs.getTime();
}
bool operator>( datetime &lhs, datetime &rhs ) { 
}
bool operator<( datetime &lhs, datetime &rhs ) {
}
bool operator!=( datetime &lhs, datetime &rhs ) { 
}

datetime operator+(datetime &lhs, int rhs){
	return lhs.getTime() + rhs;
}
datetime operator-(datetime &lhs, int rhs){
	return lhs.getTime() - rhs;
}
bool operator==(const int lhs, datetime &rhs){
	return lhs == rhs.getTime() ? true : false;
}
bool operator==(datetime &lhs, int rhs){
	return !lhs.getTime != rhs;
}


//************************************************************************
#endif