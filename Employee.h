#pragma once
#include<string>
#include<map>
#include<iostream>
#include <iomanip>
#include"date.h"
using namespace std;
class Employee
{
protected:
	string name,id;
	int gender;
	CDate enroll_date;
	string job;
	double salary;
public:
	Employee(string id,string name,int gender,CDate enroll,string job,double salary);
	void set_salary(double salary){this->salary = salary;}
	void set_job(string job){this->job = job;}
	void set_enroll(CDate enroll){this->enroll_date = enroll;}
	string get_id(){return id;}
	string get_name(){return name;}
	CDate get_enroll(){return enroll_date;}
	int get_gender(){return gender;}
	string get_job(){return job;}
	double get_salary(){return salary;}
	virtual double get_pay(int m) = 0;
	friend ostream& operator<<(ostream &os,const Employee& e);
};
class Manager:public Employee{
	map<int,double> bonus;       //月 红利
public:
	Manager(string id,string name,int gender,CDate enroll,string job,double salary);
	Manager(string id,string name,int gender,CDate enroll,string job,double salary,map<int,double> bonus);
	void set_bonus(map<int,double> bonus);
	virtual double get_pay(int m);     //月份
};
class Technicist:public Employee{
public:
	Technicist(string id,string name,int gender,CDate enroll,string job,double salary);
	virtual double get_pay(int m);
};
class SalesPerson:public Employee{
private:
	map<int,double> sales;
public:
	SalesPerson(string id,string name,int gender,CDate enroll,string job,double salary);
	SalesPerson(string id,string name,int gender,CDate enroll,string job,double salary,map<int,double> sales);
	void set_sales(map<int,double> sales);
	virtual double get_pay(int m);
};

