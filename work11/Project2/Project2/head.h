#pragma once
//① 对于多继承机制中的路径二义性，分别定义四个类：A、B、C和D。其中，类B和类C均从类A公有继承而来，
//类D从类B和类C公有继承而来。在类A的private和protected区域中均具有一个数据成员，
//public区域中具有一个数据成员、构造函数和一个普通成员函数；类B、C、D中除构造函数外，
//没有其它的数据成员和成员函数，则由类D创建的一个对象d在访问类A的公有数据成员或成员函数时会产生路径二义性；
//② 为上述类分别添加合适的构造函数，实现类的各自数据成员的初始化，
//并分别使用作用域规则和虚继承两种方式解决上述路径二义性；
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
class B :public A {
public:
	B(int tempi, char tempc, string temps):A(tempi,tempc,temps){}
};
class C :public A {
public:
	C(int tempi, char tempc, string temps):A(tempi, tempc, temps) {}
};
class D :public B, public C {
public:
	D(int i, char c, string s,int ti,char tc,string ts):B(i,c,s),C(ti,tc,ts){}
};