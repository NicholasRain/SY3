#include"Employee.h"
#include<vector>
#include<list>
#include<algorithm>
using namespace std;
class Report
{
private:
	vector<Employee*> members;      //存放员工数据
	list<Employee*> operator[](string job);
	double min_pay(list<Employee*> emp_list, int month);
	double max_pay(list<Employee*> emp_list, int month);
	void print(list<Employee*> emp_list,int month);
public:
	~Report();
	void insert(Employee* member);
	void print(int rp_mon);
};
