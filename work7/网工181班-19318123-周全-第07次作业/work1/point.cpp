#include "points.h"

Point::Point() {//Ĭ���޲ι��캯����Ĭ��Ϊԭ��
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