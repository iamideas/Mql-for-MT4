#ifndef STANDARDCPPLIBRARY_H__
#define STANDARDCPPLIBRARY_H__

#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include<time.h>
//C++
#include<string>

using namespace std;


class datetime{
public:
	datetime(){ }
	datetime(string time){	}
	datetime( int time ) { }
	bool operator!=(datetime &rhs){}
	datetime operator=(datetime &rhs){ }
	datetime operator=(const string &rhs){ }

	int operator[](int i){	}

	~datetime(){ /*nothing*/ }
};


datetime operator+(datetime &lhs, int rhs){	}
string operator+( string lhs, datetime rhs ) { }
datetime operator-(datetime &lhs, int rhs){ }
int operator-(datetime &lhs, datetime &rhs){ }
bool operator>( datetime &lhs, datetime &rhs ) { }
bool operator>=(datetime &lhs, datetime &rhs) { }
bool operator<( datetime &lhs, datetime &rhs ) { }
bool operator<=(datetime &lhs, datetime &rhs) { }
bool operator>( datetime &lhs, int rhs ) { }
bool operator>=(datetime &lhs, int rhs) { }
bool operator<( datetime &lhs, int rhs ) { }
bool operator<=(datetime &lhs, int rhs) { }
bool operator==( datetime &lhs, datetime &rhs ) { }


//************************************************************************
#endif