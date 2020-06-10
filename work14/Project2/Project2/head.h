#pragma once
//① 定义一个形状类CShape（抽象类），并添加一个普通成员函数（用来重设形状大小，重载成员函数）
//SetData()、两个纯虚成员函数 - 周长计算函数Perimeter()和面积计算函数Area()；
//② 由CShape派生出一个圆形类CCircle类，进行相应数据成员和成员函数的重新定义；
//③ 由CShape派生出一个三角形类CTriangle类，进行相应数据成员和成员函数的重新定义；
//④ 由CShape派生出一个矩形类CRectangle类，进行相应数据成员和成员函数的重新定义；
//⑤ 由CShape派生出一个梯形类CTrapezia类，进行相应数据成员和成员函数的重新定义；
//⑥ 设计测试主函数，通过输入相应的半径、长、宽、高等数据成员，计算相应的周长和面积；
//⑦ 仔细考虑数据成员有哪些（要求能够体现出：数据成员和普通虚成员函数的同名覆盖）？
//分别放到哪些类（包括基类、子类等）中？注意：虚函数、纯虚函数、抽象类和具体类的声明、定义和使用细节。
#include <iostream>
#define PI 3.14
using namespace std;
class CShape {
public:
	//virtual void SetData() = 0;
	virtual void Perimeter() = 0;
	virtual void Area() = 0;
};
class CCircle :public CShape {
private:
	int r;
public:
	CCircle(int r):r(r){}
	//void SetData();
	void Perimeter() {
		cout << "The Cirlce Perimeter is " << 2 * PI * r << endl;
	}
	void Area() {
		cout << "The Circle Area is " << PI * r * r << endl;
	}
};
class CTriangle :public CShape {
private:
	int side_a;
	int side_b;
	int side_c;
public:
	CTriangle(int a, int b, int c) :side_a(a), side_b(b), side_c(c) {}
	void Perimeter() {
		cout << "The Triangle Perimeter is " << side_a + side_b + side_c << endl;
	}
	void Area() {
		float p = (side_a + side_b + side_c) / 2;
		cout << "The Triangle Area is " << sqrt(p * (p - side_a) * (p - side_b) * (p - side_c)) << endl;
	}
};
class CRectangle :public CShape {
private:
	int width;
	int height;
public:
	CRectangle(int width, int height) :width(width), height(height) {}
	void Perimeter() {
		cout << "The Rectangle Perimeter is " << 2 * (width + height) << endl;
	}
	void Area() {
		cout << "The Rectangle Area is " << width * height << endl;
	}
};
// 等腰梯形
class CTrapezia :public CShape {
private:
	int waist;
	int head;
	int buttom;
public:
	CTrapezia(int w, int h, int b) :waist(w), head(h), buttom(b) {}
	void Perimeter() {
		cout << "The Trapezia Perimeter is " << 2 * waist + head + buttom << endl;
	}
	void Area() {
		float height = sqrt(pow(waist, 2) - pow((buttom - head) / 2, 2));
		cout << "The Rectangle Area is " << (head + buttom) * height / 2 << endl;
	}
};