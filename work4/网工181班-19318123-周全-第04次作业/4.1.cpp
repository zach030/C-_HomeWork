//设计一个矩阵（Matrix）类，可以包括矩阵的维度变量d1和d2、
//矩阵的输入函数Matrix_Input()、矩阵的显示函数Matrix_Show()、矩阵的数乘函数Matrix_Multiply()、
//矩阵的转置函数Matrix_Transpose()、矩阵的旋转函数Matrix_Rotate()等成员，定义好相应的构造函数；
#include <iostream>
using namespace std;
#define MAX 50
class Matrix {
public:
	int d1, d2;
	int matrix[MAX] = { 0 };
	void Matrix_Input();
	void Matrix_show();
	void Matrix_Multiply();
	void Matrix_Transpose();
	void Matrix_Rotate(int angle);
};
void Matrix::Matrix_show() {
	cout << "The matrix is:" << endl;
	for (int j = 0; j < d1*d2; j++) {
		cout << matrix[j] << "\t";
		if ((j + 1) % d2 == 0) cout << endl;
	}
}
void Matrix::Matrix_Input() {
	cout << "Please input the demensions of the matrix:";
	cin >> this->d1 >> this->d2;
	cout << "Please input the elements of the matrix:";
	for (int i = 0; i < d1 * d2; i++)
		cin >> this->matrix[i];
}
void Matrix::Matrix_Multiply() {
	int num = 1;
	cout << "Please input the number will multiply the matrix:";
	cin >> num;
	for (int j = 0; j < d1*d2; j++) {
		matrix[j] *= num;
	}
}
void Matrix::Matrix_Transpose() {
	cout << "The transpose matrix is:" << endl;
	int dx = d2, dy = d1;
	int j = -1;
	for (int t = 0; t < dx; t++) {
		j += 1;
		int temp = j;
		for (int i = 0; i < dy; i++) {
			cout << matrix[temp] << "\t";
			temp += dx;
			if (i == dy - 1)
				cout << endl;
		}
	}
}
void Matrix::Matrix_Rotate(int angle) {
	switch (angle) {
	case(90): {
		int j = d1 * (d2 - 1) - 1;
		for (int t = 0; t < d1; t++) {
			j += 1;
			int temp = j;
			for (int i = 0; i < d2; i++) {
				cout << matrix[temp] << "\t";
				temp -= d1;
				if (i == d2 - 1)
					cout << endl;
			}
		}
	}break;
	case(180): {
		for (int i = d1 * d2 - 1; i >= 0; i--) {
			cout << matrix[i] << "\t";
			if (i % d2 == 0)
				cout << endl;
		}
	}break;
	case(270) :{
		int j = d1;
		for (int t = 0; t < d1; t++) {
			j -= 1;
			int temp = j;
			for (int i = 0; i < d2; i++) {
				cout << matrix[temp] << "\t";
				temp += d1;
				if (i == d2 - 1)
					cout << endl;
			}
		}
	}break;
	}
}
bool choose() {
	char key;
	cin >> key;
	if (key == 'Y' || key == 'y')
		return true;
	else
		return false;
}
int main() {
	Matrix m;
	m.Matrix_Input();
	m.Matrix_show();
	cout << "Do you want to multiply the matrix?(Y/N):";
	if (choose()) {
		m.Matrix_Multiply();
		m.Matrix_show();
	}
	cout << "Do you want to transpose the matrix?(Y/N):";
	if (choose()) {
		m.Matrix_Transpose();
	}
	cout << "Do you want to rotate the matrix?(Y/N):";
	if (choose()) {
		int angle = 0;
		cout << "Please input the angle of the rotation(90/180/270):";
		cin >> angle;
		m.Matrix_Rotate(angle);
	}
	else
		return 0;
}