#include <iostream>
using namespace std;
//分析下面程序，然后利用关键字virtual来修改程序代码，使其运行结果如下图所示。
//观察运行结果，比较添加virtual前后的运行结果，理解多态性的概念。
class Student {
public:
	virtual void calTuition() { cout << "计算学生学费" << endl; }
};
class Master : public Student {
public:
	void calTuition() { cout << "计算硕士生学费" << endl; }
};
class Doctor : public Student {
public:
	void calTuition() { cout << "计算博士生学费" << endl; }
};
void fn(Student& x) { x.calTuition(); }
int main(void)
{
	Student s;   Master m;  Doctor d;
	fn(s);           //计算一下学生s的学费
	fn(m);          //计算一下硕士生m的学费
	fn(d);          //计算一下博士生d的学费
	return 0;
}
