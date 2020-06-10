#include "points.h"

Point::Point() {//默认无参构造函数，默认为原点
	x = 0, y = 0;
}
double Distance::MemberDistance(Point& a, Point& b) {
	double squre_distance = pow((a.x - b.x), 2) + pow((a.y - b.y), 2);
	return sqrt(squre_distance);
}
double ExternalDistance(Point& a, Point& b) {
	double squre_distance = pow((a.x - b.x), 2) + pow((a.y - b.y), 2);
	return sqrt(squre_distance);
}