#include "head.h"
int main(void) {
	Rational  A(2, 6), B(1, -2), C;
	C = -A;    C.print();           //输出1/3
	C = A + B;    C.print();           //输出-1/6
	Rational D = C * A; 
	C = D / B;    C.print(); 
	C = ++A;    A.print();    C.print();
	C = B--;    B.print();    C.print();
	return 0;
}
