#pragma once
#include <iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
#include<ctime>
using namespace std;
class CDate{
	int d,m,y;
	static const string df_s;
	static const string df_l;
	static CDate *default_date;
public:
	CDate(int dd,int mm,int yy);
	CDate();
	void add_year(int n);
	void add_month(int n);
	void add_day(int n);
	string format(string df);
	int get_day() const;
	int get_month() const;
	int get_year() const;
	static void set_default(int,int,int);
	friend ostream& operator<<(ostream &os,CDate d);
};
