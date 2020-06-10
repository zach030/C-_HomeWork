//定义一个立方体盒子（Box）类，包括长（length）、宽（width）、高（height）等数据成员和
//计算周长compute_perimeter()、表面积compute_area()、体积compute_volume()等成员函数。
//要求：能够使用构造函数对数据成员进行初始化，三个成员函数能够输出立方体盒子的周长、表面积和体积。
//① 在头文件中声明类，在源文件中定义类的成员函数和测试函数，注意类的数据成员和成员函数的访问权限；
//② 使用重载构造函数进行数据成员初始化，提供2种或以上初始化数据成员length、width、height的方法，注意类的重载构造函数的声明和定义方式；
//③ 定义一个拷贝构造函数，使得可以通过一个对象（例如box1）来初始化另一个新对象（例如box2），
//新对象的数据成员length、width、height的大小为原对象的2倍，注意类的拷贝构造函数的声明和定义方式；
//④ 设计main()测试函数，并准备好合适的测试数据。
#include <iostream>
using namespace std;
class Box {
private:
	int length;
	int width;
	int height;
public:
	int compute_perimeter();//计算周长
	int compute_area();//表面积
	int compute_volume();//体积
	Box(int length, int width, int height) {
		this->height = height;
		this->length = length;
		this->width = width;
	}
	Box(const Box &b) {//拷贝构造函数
		length = 2 * (b.length);
		width = 2 * (b.width);
		height = 2 * (b.height);
	}
};
int Box::compute_perimeter() {
	return 2 * (length + width + height);
}
int Box::compute_area() {
	return 2 * (length*width + length * height + width * height);
}
int Box::compute_volume() {
	return (length*width*height);
}
int main() {
	int length, width, height, flag = 1;
	char choose;
	while (flag) {
		cout << "Please input the length, width, height of the box:";
		cin >> length >> width >> height;
		Box b1(length, width, height);
		cout << "The perimeter of the box is :" << b1.compute_perimeter() << endl;
		cout << "The superficial area of the box is: " << b1.compute_area() << endl;
		cout << "The volume of the box is: " << b1.compute_volume() << endl;
		Box b2(b1);
		cout << "The preimeter, superficial are, volume of the box with double data is as follows:" << endl;
		cout << "The perimeter of the box is :" << b2.compute_perimeter() << endl;
		cout << "The superficial area of the box is: " << b2.compute_area() << endl;
		cout << "The volume of the box is: " << b2.compute_volume() << endl;
		cout << "Do you want to continue?(Y/N):";
		cin >> choose;
		if (choose == 'Y' || choose == 'y')
			flag = 1;
		else
	        flag = 0;
	}
	return 0;
}