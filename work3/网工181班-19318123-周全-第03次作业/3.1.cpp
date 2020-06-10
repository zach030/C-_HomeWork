#include <iostream>
#define MAX 50
using std::cout;
using std::endl;
using std::cin;
void ShowMatrix(int* array,int d_x,int d_y) {
	for (int j = 0; j < d_x*d_y; j++) {
		cout << array[j] << "\t";
		if ((j + 1) % d_y == 0) cout << endl;
	}
}
void MatrixPro(int* matrix,int d_x,int d_y) {
	cout << "Please input the elememts of the matrix: ";
	for (int i = 0; i < d_x*d_y; i++)
		cin >> matrix[i];
	cout << "The original matrix you inputed is:\n";
	ShowMatrix(matrix, d_x, d_y);
	cout << "Please input the number that will multiply the matrix: ";
	int mul; cin >> mul;
	for (int i = 0; i < d_x* d_y; i++)
		matrix[i] *= mul;
	cout << "The matrix mutiply by the number is:\n";
	ShowMatrix(matrix, d_x, d_y);
}
void func1() {
	int dimension;
	int matrix[MAX]{ 0 };
	cout << "Please input the dimension of the matrix: ";
	cin >> dimension;
	MatrixPro(matrix, dimension, dimension);
}
void func2() {
	int d_x, d_y;
	int matrix[MAX]{ 0 };
	cout << "Please input the two dimensions of the matrix: ";
	cin >> d_x >> d_y;
	MatrixPro(matrix, d_x, d_y);
}
int main() {
	func1();
	func2();
	return 0;
}