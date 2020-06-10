#pragma once
//① 对于多继承机制中的同名二义性，分别定义三个类：A、B和C。其中，类C分别从类A和类B公有继承而来。
//在类A和类B的private、protected和public区域中具有相同的数据成员，类C中除构造函数外，
//没有其它的数据成员和成员函数，则由类C创建的一个对象c在访问基类A和B中的同名公有数据成员或成员函数时会产生同名二义性；
//② 为上述类分别添加合适的构造函数，实现类的各自数据成员的初始化，并利用作用域规则解决上述同名二义性；
#include <iostream>
#include <string>
using namespace std;
class A {
private:
	int i;
protected:
	char c;
public:
	string s;
	A(int tempi, char tempc, string temps) :i(tempi), c(tempc), s(temps) {}
	void show() { cout << "A::i=" << i << "  A::c=" << c << "  A::s=" << s << endl; }
};
class B {
private:
	int i;
protected:
	char c;
public:
	string s;
	B(int ti,char tc,string ts):i(ti),c(tc),s(ts){}
	void show() { cout << "B::i=" << i << "  B::c=" << c << "  B::s=" << s << endl; }
};
class C : public A, public B {
public:
	C(int tempi, char tempc, string temps, int ti, char tc, string ts):A(tempi,tempc,temps),B(ti,tc,ts){}
};
