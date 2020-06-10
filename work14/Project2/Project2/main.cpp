#include "head.h"
int main(void) {
	CShape *pShape[4];
	pShape[0] = new CCircle(2);
	pShape[1] = new CTriangle(3, 4, 5);
	pShape[2] = new CRectangle(5, 6);
	pShape[3] = new CTrapezia(5, 4, 10);
	for (int i = 0; i < 4; i++) {
		pShape[i]->Perimeter();
		pShape[i]->Area();
	}
	return 0;
}