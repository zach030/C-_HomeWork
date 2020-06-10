#include <iostream>
#include <cmath>
using namespace std;
class Point;
class Distance {
public:
	double MemberDistance(Point& a, Point& b);
};
class Point{
	double x, y;
public:
	Point();
	Point(double tempx, double tempy) :x(tempx), y(tempy) {};
	friend double ExternalDistance(Point& a, Point& b);
	friend double Distance::MemberDistance(Point& a, Point& b);
	friend class Distance;
};
