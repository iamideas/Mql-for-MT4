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
	//privatge classes 、functions
	struct tm format(string rhs){
		struct tm time = { 0 };
		int previous, current;

		if ("" == rhs)
			timer = 0;

		//日期
		if (string::npos != rhs.find(".")){
			current = rhs.find('.');
			time.tm_mon = atoi(rhs.substr(0, current).c_str());
			previous = current;

			current = rhs.find('.', previous);
			time.tm_mday = atoi(rhs.substr(previous, current).c_str());
			previous = current;

			current = rhs.find(' ', previous);
			time.tm_year = atoi(rhs.substr(previous, current).c_str());
			previous = current;
		}
		//时间
		if (string::npos == rhs.find('.')){
			current = rhs.find(':');
			time.tm_hour = atoi(rhs.substr(current - 2, current).c_str());

			//minute
			if (rhs.end == rhs.at(current + 2))
				time.tm_min = atoi(rhs.substr(current, current + 2).c_str());
			//second
			previous = current;
			current = rhs.find_last_of(":");
			if (string::npos != current && previous != current)
				time.tm_sec = atoi(rhs.substr(current, current + 2).c_str());

		}
		return time;
	}

	//prative parameters
	time_t timer;
};


datetime operator+(datetime &lhs, int rhs){
	return lhs.getTime() + rhs;
}
datetime operator+(datetime &lhs, datetime &rhs){
	return lhs.getTime() + rhs.getTime();
}
datetime operator-(datetime &lhs, datetime &rhs){
	return lhs.getTime() - rhs.getTime();
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