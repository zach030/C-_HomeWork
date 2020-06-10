#include <iostream>
#define MAX 100
using std::cin;
using std::cout;
using std::endl;
//0 1 2__3 0
//3 4 5  4 1
//       5 2
void rotate_90(int* matrix, int dx, int dy) {
	int j = dx * (dy - 1) - 1;
	for (int t = 0; t < dx; t++) {
		j += 1;
		int temp = j;
		for (int i = 0; i < dy; i++) {
			cout << matrix[temp] << "\t";
			temp -= dx;
			if (i == dy - 1)
				cout << endl;
		}
	}
}
//1 2 3__6 5 4
//4 5 6  3 2 1
void rotate_180(int* matrix, int dx, int dy) {
	for (int i = dx * dy - 1; i >= 0; i--) {
		cout << matrix[i] << "\t";
		if (i % dy == 0)
			cout << endl;
	}
}
//0 1 2__2 5
//3 4 5  1 4
//       0 3
void rotate_270(int* matrix, int dx, int dy) {
	int j = dx;
	for (int t = 0; t < dx; t++) {
		j -= 1;
		int temp = j;
		for (int i = 0; i < dy; i++) {
			cout << matrix[temp] << "\t";
			temp += dx;
			if (i == dy - 1)
				cout << endl;
		}
	}
}
int choose() {
	cout << "Do you want to continue?(y/n):";
	char key;
	cin >> key;
	if ((key == 'y') || (key == 'Y'))
		return 1;
	else
		return 0;
}
int main() {
	cout << "Please input two dimensions of the matrix:";
	int dx, dy, matrix[MAX] = { 0 };
	cin >> dx >> dy;
	cout << "Please input the elements of the matrix:";
	for (int i = 0; i < dx*dy; i++)
		cin >> matrix[i];
	cout << "The orignal matrix you inputed is:\n";
	for (int i = 0; i < dx*dy; i++) {
		cout << matrix[i] << "\t";
		if ((i + 1) % dy == 0)
			cout << endl;
	}
	int flag = 1;
	while (flag) {
		cout << "Please input the angle you want to rotate:(90,180,270):";
		int angle;
		cin >> angle;
		switch (angle)
		{
		case(90): {
			rotate_90(matrix, dy, dx);
			flag = choose();
		}break; 
		case(180): {
			rotate_180(matrix, dx, dy);
			flag = choose();
		}break; 
		case(270): {
			rotate_270(matrix, dy, dx);
			flag = choose();
		}break; 
		default:
			break;
		}
	}

	return 0;
}