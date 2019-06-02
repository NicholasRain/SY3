#include "Report.h"

list<Employee*> Report::operator[](string job)
{
    list<Employee*> E;
    vector<Employee*>::iterator it;
    for(it=members.begin();it!=members.end();++it)
    {
        if((*it)->get_job()==job)
        {
            E.push_back(*it);
        }
    }
    return E;
}

double Report::min_pay(list<Employee*> emp_list, int month)
{
    list<Employee*>::iterator it;
    double MIN=0xffffffff;
    for(it=emp_list.begin();it!=emp_list.end();++it)
    {
        if((*it)->get_pay(month)<MIN)
        {
            MIN=(*it)->get_pay(month);
        }
    }
    return MIN;
}

double Report::max_pay(list<Employee*> emp_list, int month)
{
    list<Employee*>::iterator it;
    double MAX=0;
    for(it=emp_list.begin();it!=emp_list.end();++it)
    {
        if((*it)->get_pay(month)>MAX)
        {
            MAX=(*it)->get_pay(month);
        }
    }
    return MAX;
}

void Report::print(list<Employee*> emp_list,int month)
{
    list<Employee*>::iterator it;
    for(it=emp_list.begin();it!=emp_list.end();++it)
    {
        cout<<(*(*it))<<"\t"<<(*it)->get_pay(month)<<endl;
        cout<<"----------------------------------------------"<<endl;
    }
}

Report::~Report(){}

void Report::insert(Employee* member)
{
    members.push_back(member);
}

void Report::print(int rp_mon)
{
    cout<<"               ��"<<rp_mon<<"����Ա��н�걨��"<<endl;
    list<Employee*> e0;
    string ZC[3]={"Manager","Technicist","SalesPerson"};
    for(int i=0;i<3;++i)
    {
        cout<<"========================================================="<<endl;
        cout<<"ְλ��"<<ZC[i]<<endl;
        cout<<"����\t"<<"����\t"<<"�Ա�\t"<<"��ְʱ��\t"<<"ְλ\t"<<"���¹���"<<endl;
        e0=(*this)[ZC[i]];
        print(e0,rp_mon);
        cout<<"��ְλ��߹��ʣ�"<<max_pay(e0,rp_mon)<<endl;
        cout<<"��ְλ��͹��ʣ�"<<min_pay(e0,rp_mon)<<endl;
        cout<<"========================================================="<<endl;
    }
}
