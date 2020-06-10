#pragma once
//① 创建一个类Base。在类Base的每个权限区域（Private、Protected和Public）下，
//均有一个数据成员（分别为x、y和z）。在Public区域下，有一个显示所有数据成员数据的成员函数showxyz()；
//② 从类Base公有派生（可以额外试试私有派生和保护派生）出一个子类Derive。
//在Derive子类的每个权限区域（Private、Protected和Public）下，均有一个数据成员（分别为dx、dy和dz）。
//在Public区域下，有一个显示所有数据成员数据的成员函数showdxyz()；
//③ 为上述两个类分别添加合适的构造函数，实现两个类的各自数据成员的初始化；
#include <iostream>
using namespace std;
class Base {
private:
	int x;
protected:
	int y;
public:
	int z;
	void showxyz() { cout << "Base::x=" << x << "  Base::y=" << y << "  Base::z=" << z << endl; }
	Base(int t1, int t2, int t3) :x(t1), y(t2), z(t3) {}
};
class Derive :public Base {
private:
	int dx;
protected:
	int dy;
public:
	int dz;
	void showxyz() { cout << "Derive::x=" << dx << " Derive::y=" << dy << " Derive::z=" << dz << endl; }
	Derive(int t1, int t2, int t3, int tx, int ty, int tz):Base(t1, t2, t3),dx(tx),dy(ty),dz(tz) {}
};
