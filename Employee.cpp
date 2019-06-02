#include "Employee.h"

Employee::Employee(string id,string name,int gender,CDate enroll,string job,double salary)
{
    this->id=id;
    this->name=name;
    this->gender=gender;
    this->enroll_date=enroll;
    this->job=job;
    this->salary=salary;
}

ostream& operator<<(ostream &os,const Employee& e)
{
    os<<e.id<<"\t"<<e.name<<"\t"<<(e.gender?"ÄÐ":"Å®")<<"\t"<<e.enroll_date<<"\t"<<e.job<<endl;
    return os;
}

Manager::Manager(string id,string name,int gender,CDate enroll,string job,double salary):Employee(id,name,gender,enroll,job,salary){}

Manager::Manager(string id,string name,int gender,CDate enroll,string job,double salary,map<int,double> bonus):Employee(id,name,gender,enroll,job,salary),bonus(bonus){}

double Manager::get_pay(int m)
{
    return get_salary()+bonus[m];
}

Technicist::Technicist(string id,string name,int gender,CDate enroll,string job,double salary):Employee(id,name,gender,enroll,job,salary){}

double Technicist::get_pay(int m)
{
    return get_salary();
}

SalesPerson::SalesPerson(string id,string name,int gender,CDate enroll,string job,double salary):Employee(id,name,gender,enroll,job,salary){}

SalesPerson::SalesPerson(string id,string name,int gender,CDate enroll,string job,double salary,map<int,double> sales):Employee(id,name,gender,enroll,job,salary),sales(sales){}

double SalesPerson::get_pay(int m)
{
    return get_salary()+(sales[m]*0.01*5);
}
