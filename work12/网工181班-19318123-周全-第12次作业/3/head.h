#pragma once
//① 创建一个求最大数的函数模板，其原型声明如下：
//template <class T1, class T2, class T3>
//class OutPut {
//public:
//	//合适的构造函数
//	void Display();//不允许内联实现
//private:
//	T1 data1;		T2 data2;		T3 data3;
//};
//② 从该类模板实例化出三个模板类，实现包括整型、浮点型、字符型和字符串等数据的输出；
#include<iostream>
#include <string>
using namespace std;
template <class T1, class T2, class T3>
class OutPut {
private:
	T1 data1;		T2 data2;		T3 data3;
public:
	//合适的构造函数
	OutPut(T1 d1,T2 d2,T3 d3):data1(d1),data2(d2),data3(d3){}
	void Display();
};
template <class T1, class T2, class T3>
void OutPut<T1, T2, T3>::Display() {
	cout << data1 << "\t" << data2 << "\t" << data3 << endl;
}