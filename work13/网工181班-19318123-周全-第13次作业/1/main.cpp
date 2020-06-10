#include "head.h"
int main(void)
{
	cout << "Please input two dimensions of the matrix:  ";
	int d1, d2;
	cin >> d1 >> d2;
	Matrix a(d1, d2), b(d1, d2), c(d1, d2);
	a.input();  
	b.input();  
	cout << endl << "Matrix a:" << endl;  a.display();
	cout << endl << "Matrix b:" << endl;  b.display();
	c = a + b;                    //用重载运算符"+"实现两个矩阵相加
	cout << endl << "Matrix c = Matrix a + Matrix b :" << endl;  c.display();
	c = a - b;                     //用重载运算符"+"实现两个矩阵相加
	cout << endl << "Matrix c = Matrix a - Matrix b :" << endl;  c.display();
	c = a * b;                     //用重载运算符"+"实现两个矩阵相加
	cout << endl << "Matrix c = Matrix a * Matrix b :" << endl;  c.display();
	c = a / b;                      //用重载运算符"+"实现两个矩阵相加
	cout << endl << "Matrix c = Matrix a / Matrix b :" << endl;  c.display();
	return 0;
}
