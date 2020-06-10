//（1）程序功能简介
//设计一个点（Point）类，其中包括一对坐标数据成员、三个求两点之间距离的友元接口
//（包括友元函数、友元成员和友元类），并用数据进行测试。
//（2）程序设计说明
//① 在头文件中声明类，在源文件中定义类的成员函数，采用构造函数进行对象的初始化；
//② 首先，采用友元函数ExternalDistance()的方式实现友元接口；其次，采用友元成员的方式实现友元接口；
//最后，采用友元类的方式实现友元接口。
//③ 对于友元成员和友元类两种实现方式，需要另外定义一个求解两点距离的Distance类，
//将MemberDistance()作为该类的成员函数；
//源文件demo.cpp内容如下
#include "points.h"
using namespace std;
int main(void){
	//友成员函数实现
	Distance d;
	cout << "Please input the coordinate values of two points (x1,y1) (x2,y2) : ";
	int x1, x2, y1, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	Point p1(x1, y1);
	Point p2(x2, y2);
	cout << "The two points are: (" << x1 << "," << y1 << ") (" << x2 << "," << y2 << ")" << endl;
	cout << "The distance (calculated with friend class) is: " << d.MemberDistance(p1, p2) << endl;
	//友元函数实现
	cout << "Please input the coordinate values of two points (x1,y1) (x2,y2) : ";
	cin >> x1 >> y1 >> x2 >> y2;
	Point p3(x1, y1);
	Point p4(x2, y2);
	cout << "The two points are: (" << x1 << "," << y1 << ") (" << x2 << "," << y2 << ")" << endl;
	cout <<"The distance (calculated with friend function) is: "<<ExternalDistance(p3, p4) << endl;
	//友元类实现
	Distance ds;
	cout << "Please input the coordinate values of two points (x1,y1) (x2,y2) : ";
	cin >> x1 >> y1 >> x2 >> y2;
	cout << "The two points are: (" << x1 << "," << y1 << ") (" << x2 << "," << y2 << ")" << endl;
	cout << "The distance (calculated with friend class) is: " << ds.MemberDistance(p1, p2) << endl;
	return 0;
}


