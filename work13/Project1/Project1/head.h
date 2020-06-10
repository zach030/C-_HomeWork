#pragma once
//① 有两个矩阵a和b，均为m行n列（m、n的值用户输入），求两个矩阵之和、差、积、商，重载运算符
//“ + ”、“ - ”、“ * ”、“ / ”，使之能够用于矩阵的加、减、乘、除，如c = a + b、c = a * b等；
//② 设计一个矩阵类Matrix，具有至少两个数据成员：行数m和列数n；设计相应的构造函数，实现矩阵对象的创建；
//③ 采用合适的方式（成员函数或者友元函数）实现矩阵的加减乘除运算符；
#include <iostream>
using namespace std;
class Matrix      //定义Matrix类
{
	int mat[50][50];
public:
	int m, n;
	Matrix(int x, int y) :m(x), n(y) {}                   //默认构造函数
	friend Matrix operator +(Matrix &, Matrix &);       //重载运算符"+"
	friend Matrix operator -(Matrix &, Matrix &);
	friend Matrix operator *(Matrix &, Matrix &);
	friend Matrix operator /(Matrix &, Matrix &);
	void input();                                    //输入数据函数
	void display();                                  //输出数据函数
};
void Matrix::input() {
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
		}
}
void Matrix::display() {
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			cout << mat[i][j] << " ";
			if (j == n - 1)
				cout << endl;
		}
}
Matrix operator +(Matrix &a, Matrix &b) {
	if (a.m == b.m&&a.n == b.n) {
		Matrix result(a.m, a.n);
		for (int i = 0; i < a.m; i++)
			for (int j = 0; j < a.n; j++)
				result.mat[i][j] = a.mat[i][j] + b.mat[i][j];
		return result;
	}
	else
		cout << "You can't add this two matrix." << endl;

}
Matrix operator -(Matrix &a, Matrix &b) {
	if (a.m == b.m&&a.n == b.n) {
		Matrix result(a.m, a.n);
		for (int i = 0; i < a.m; i++)
			for (int j = 0; j < a.n; j++)
				result.mat[i][j] = a.mat[i][j] - b.mat[i][j];
		return result;
	}
	else
		cout << "You can't sub this two matrix." << endl;

}
Matrix operator *(Matrix &a, Matrix &b) {
	if (a.m == b.n&&a.n == b.m) {
		Matrix result(a.m, b.n);
		for (int i = 0; i < a.m; i++)
			for (int j = 0; j < b.n; j++) {
				for (int k = 0; k < a.n; k++)
					result.mat[i][j] = a.mat[i][k] * b.mat[k][i];
			}
		return result;
	}
	else
		cout << "You can't multiply this two matrix." << endl;

}
Matrix operator /(Matrix &a, Matrix &b) {
	if (a.m == b.m || a.n == b.n) {
		Matrix result(b.n, a.n);
		for (int i = 0; i < a.m; i++)
			for (int j = 0; j < b.n; j++) {
				result.mat[i][j] = a.mat[i][j] / b.mat[i][j];
			}
		return result;
	}
	else
		cout << "You can't divide this two matrix." << endl;

}
