#include <iostream>
#include <cstdio>
#define MAX 50
using std::cout;
using std::cin;
using std::endl;
// 1 2 3 4 5 6
// 1 2 3__> 1 4
// 4 5 6  > 2 5
//          3 6
int main() {
	cout << "Please input two demensions of the matrix:";
	int d_x, d_y;
	cin >> d_x >> d_y;
	cout << "Please input the elements of the matrix:";
	int matrix[MAX]{ 0 };
	for (int i = 0; i < d_x*d_y; i++)
		cin >> matrix[i];
	cout << "The original matrix you inputed:\n";
	for (int i = 0; i < d_x*d_y; i++) {
		cout << matrix[i] << "\t";
		if (((i + 1) % d_y) == 0) cout << endl;
	}
	cout <<"The transposed matrix is:\n";
	int dx = d_y, dy = d_x;
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
	return 0;
}