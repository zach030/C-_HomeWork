#pragma once
//有两个有理数r1和r2，求两个有理数之和、差、积、商。重载运算符“ + ”、“ - ”、“ * ”、“ / ”，
//使之能够用于有理数的加减乘除，如r = r1 + r2、r = r1 * r2；
//② 设计一个有理数类Rational，具有至少两个数据成员：分子（numerator）和分母（denominator），
//设计相应的构造函数，实现有理数对象的创建；
//③ 采用合适的方式（成员函数或者友元函数）实现有理数的加减乘除运算符；
#include<iostream>
using namespace std;
class Rational
{
	int m, n;   //分母和分子
public:
	Rational(int nn = 1, int mm = 1) :m(mm), n(nn) {};
	void print();
	void simple();
	Rational  operator  +(Rational & a);                       //加法
	friend  Rational  operator  -(Rational & a, Rational & b);     //减法
	friend  Rational  operator  *(Rational & a, Rational & b);     //乘法
	friend  Rational  operator  /(Rational & a, Rational & b);      //除法
	Rational  operator  -();//取反
	Rational &  operator  ++();            //r=++r1
	Rational  operator  ++(int);            //r=r1++
	Rational &  operator  --();             //r=--r1
	Rational  operator  --(int);             //r =r1--
	operator double();
	friend ostream& operator<<(ostream& output, Rational& a);
	bool operator  <(Rational &);
	friend bool operator  ==(Rational&, Rational&);
};
void Rational::simple() {
	int x = this->m;
	int y = this->n;
	int z = y;
	while (x%y != 0)
	{
		z = x % y;
		x = y;
		y = z;
	}
	this->m /= z;
	this->n /= z;
}
void Rational::print() {
	simple();
	cout << "The value is : " << n << "/" << m << endl;
}
Rational Rational::operator+(Rational &a) {
	Rational *temp = new Rational();
	temp->n = this->n * a.m + a.n * this->m;
	temp->m = this->m * a.m;
	return *temp;
}
Rational operator-(Rational &a, Rational &b) {
	Rational *temp = new Rational();
	temp->m = a.m * b.m;
	temp->n = a.n*b.m - b.n*a.m;
	return *temp;
}
Rational operator*(Rational &a, Rational &b) {
	Rational *temp = new Rational();
	temp->m = a.m * b.m;
	temp->n = a.n * b.n;
	return *temp;
}
Rational operator/(Rational &a, Rational &b) {
	Rational *temp = new Rational();
	temp->m = a.m * b.n;
	temp->n = a.n * b.m;
	return *temp;
}
Rational Rational::operator-() {
	Rational *temp = new Rational();
	temp->n = -this->n;
	temp->m = this->m;
	return *temp;
}
Rational& Rational::operator++() {
	this->n += this->m;
	return *this;
}
Rational Rational::operator++(int num) {
	Rational *temp;
	temp = this;
	this->n += (num*this->m);
	return *temp;
}
Rational& Rational::operator--() {
	this->n -= this->m;
	return *this;
}
Rational Rational::operator--(int) {
	Rational *temp = new Rational();
	temp->m = this->m;
	temp->n = this->n;
	this->n -= this->m;
	return *temp;
}