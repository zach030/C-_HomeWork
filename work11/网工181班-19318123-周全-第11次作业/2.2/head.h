#pragma once
#include <iostream>
#include <string>
using namespace std;
class A {
	int i;
protected:
	char c;
public:
	string s;
	A(int tempi, char tempc, string temps) :i(tempi), c(tempc), s(temps) {}
	void show() { cout << "A::i=" << i << "  A::c=" << c << "  A::s=" << s << endl; }
};
class B :virtual public A {
public:
	B(int tempi, char tempc, string temps) :A(tempi, tempc, temps) {}
};
class C :virtual public A {
public:
	C(int tempi, char tempc, string temps) :A(tempi, tempc, temps) {}
};
class D :public B, public C {
public:
	D(int i, char c, string s, int ti, char tc, string ts) :B(i, c, s), C(ti, tc, ts),A(i,c,s) {}
};