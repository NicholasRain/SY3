#include <iostream>
#include "date.h"
#include "Employee.h"
#include "Report.h"
using namespace std;
Report rr;
int mm;
Employee *p[5];
int main()
{
    Manager m("1","lyb",1,CDate(10,5,2019),"Manager",12000,map<int,double>{{1,5000},{2,4500},{3,3000},{4,6000},{5,5500},{6,4500},{7,7000},{8,5000},{9,45000},{10,6650},{11,6500},{12,6000}});
    p[0]=&m;
    rr.insert(p[0]);
    Technicist t1("2","lqj",1,CDate(14,5,2019),"Technicist",5500);
    p[1]=&t1;
    rr.insert(p[1]);
    Technicist t2("3","eq",0,CDate(10,5,2019),"Technicist",5000);
    p[2]=&t2;
    rr.insert(p[2]);
    SalesPerson s1("4","xjp",1,CDate(20,5,2019),"SalesPerson",4000,map<int,double>{{1,10000},{2,8000},{3,12000},{4,9000},{5,10500},{6,10000},{7,12000},{8,10500},{9,10400},{10,12000},{11,10300},{12,9000}});
    p[3]=&s1;
    rr.insert(p[3]);
    SalesPerson s2("5","xzj",1,CDate(18,5,2019),"SalesPerson",4500,map<int,double>{{1,12000},{2,10000},{3,10200},{4,9500},{5,10500},{6,11000},{7,10900},{8,11500},{9,11400},{10,10500},{11,11000},{12,10000}});
    p[4]=&s2;
    rr.insert(p[4]);
    while(1)
    {
        cout<<"请输入查询月份：";
        cin>>mm;
        if(mm>=1&&mm<=12)
        {
            rr.print(mm);
        }
        else
        {
            cout<<"输入有误！"<<endl;
        }
    }
    return 0;
}
