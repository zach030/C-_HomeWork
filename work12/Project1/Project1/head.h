#pragma once
//① 定义一个图形类Figure，其中只包含一个数据成员：边数（sidenum）和合适的构造函数，没有其它数据成员或成员函数；
//② 由Figure类建立三个派生类：对角线互相垂直的四边形Quadrangle1、平行四边形类Parallelogram和
//四个角均为直角的四边形类Quadrangle2。其中，每个派生类中只包含合适的构造函数，没有其它数据成员或成员函数；
//③ 由Quadrangle1和Parallelogram两个类建立一个派生类：菱形类Rhombus，由Quadrangle2和
//Parallelogram两个类建立一个派生类：矩形类Rectangle。其中，Rhombus类新增一个数据成员：
//边长（sidelength）以及合适的构造函数，Rectangle类新增一个数据成员：角度（angle）以及合适的构造函数，两个类均没有其它数据成员或成员函数；
//④ 由Rhombus和Rectangle两个类建立一个派生类：正方形类Square，其中只包含合适的构造函数，没有其它数据成员或成员函数；
#include <iostream>
using namespace std;
class Figure {
	int sidenum;
public:
	Figure() { cout << "Figure." << endl; }
	Figure(int temp) :sidenum(temp) { cout << "The figure has " << sidenum << " sides." << endl; }
};
class Quadrangle1 :virtual public Figure {
public:
	Quadrangle1(int side_num):Figure(side_num){
		cout << "This is a quarilateral wuth two diagonal lines perpendicular to each other." << endl;
	}
};
class Parallelogram :virtual public Figure {
public:
	Parallelogram(int side_num):Figure(side_num){
		cout << "This is a parallelogram." << endl;
	}
};
class Quadrangle2 :virtual public Figure {
public:
	Quadrangle2(int side_num):Figure(side_num){
		cout << "This is a quadrilateral with four 90 degree angles." << endl;
	}
};
class Rhombus :virtual public Quadrangle1, virtual public Parallelogram {
private:
	int sidelength;
public:
	Rhombus(int side_num, int side_length):sidelength(side_length),Quadrangle1(side_num),Parallelogram(side_num){
		cout <<"This is a rhombus."<<endl;
	}
};
class Rectangle :virtual public Quadrangle2, virtual public Parallelogram {
private:
	int angle;
public:
	Rectangle(int side_num, int angle):angle(angle),Quadrangle2(side_num),Parallelogram(side_num){
		cout << "This is a rectangle." << endl;
	}
};
class Square :virtual public Rhombus, virtual public Rectangle {
public:
	Square(int side_num, int side_length, int angle):Rhombus(side_num,side_length),
		Rectangle(side_num,angle),Quadrangle1(side_num),
		Parallelogram(side_num),Quadrangle2(side_num),Figure(side_num){
		cout << "The figure is a square." << endl
			<< "All angles of the square are 90 degrees." << endl
			<< "The sidelength of the square is " << side_length << "." << endl
			<< "The area of the square is " << side_length * side_length << endl;
	}
};