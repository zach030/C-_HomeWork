//用户根据程序提示输入数字，选择要进行的运算，可以进行加、减、乘、除、平方、求模、求方根等运算；
//针对加、减、乘、除、平方、求模、求方根操作，每种操作设计一个成员函数实现相应功能；
#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;
class Calc {
public:
	int oper1 = 0, oper2 = 0;
	char my_operator = '\0';
	void Calc_sum();
	void Calc_sub();
	void Calc_mul();
	void Calc_div();
	void Calc_mod();
	void Calc_sqrt(int op);
};
void Calc::Calc_sum() {
	int ans = oper1 + oper2;
	cout << oper1 << " + " << oper2 << " = " << ans;
	oper1 = ans;
}
void Calc::Calc_sub() {
	int ans = oper1 - oper2;
	cout << oper1 << " - " << oper2 << " = " << ans;
	oper1 = ans;
}
void Calc::Calc_mul() {
	int ans = oper1 * oper2;
	cout << oper1 << " * " << oper2 << " = " << ans;
	oper1 = ans;
}
void Calc::Calc_div() {
	int ans = oper1 / oper2;
	cout << oper1 << " / " << oper2 << " = " << ans;
	oper1 = ans;
}
void Calc::Calc_mod() {
	int ans = oper1 % oper2;
	cout << oper1 << " % " << oper2 << " = " << ans;
	oper1 = ans;
}
void Calc::Calc_sqrt(int op) {
	int ans = sqrt(op);
	cout << "The answer is : " << ans << endl;
	oper1 = ans;
}
bool choose() {
	char key;
	cout << "Continue?(Y/N):";
	cin >> key;
	if (key == 'Y' || key == 'y')
		return true;
	else
		return false;
}
int main() {
	Calc c;
	bool flag = true;
	cout << "please input operand1:";
	cin >> c.oper1;
	cout << "please input operand2:";
	cin >> c.oper2;
	cout << "Please input operator:";
	cin >> c.my_operator;
	switch (c.my_operator) {
	    case ('+'): {
		    c.Calc_sum();
		    cout << endl;
	    }break;
	    case('-'): {
		    c.Calc_sub();
		    cout << endl;
	    }break;
		case('*'): {
			c.Calc_mul();
			cout << endl;
		}break;
		case('/'): {
			c.Calc_div();
			cout << endl;
		}break;
	}
	flag = choose();
	while (flag) {
		cout << "Please input new operand:";
		cin >> c.oper2;
		cout << "Please input new operator:";
		cin >> c.my_operator;
		switch (c.my_operator) {
		case ('+'): {
			c.Calc_sum();
			cout << endl;
		}break;
		case('-'): {
			c.Calc_sub();
			cout << endl;
		}break;
		case('*'): {
			c.Calc_mul();
			cout << endl;
		}break;
		case('/'): {
			c.Calc_div();
			cout << endl;
		}break;
		case('%'): {
			c.Calc_mod();
			cout << endl;
		}break;
		case('#'): {
			c.Calc_sqrt(c.oper2);
			cout << endl;
		}break;
		}flag = choose();
	}
	return 0;
}