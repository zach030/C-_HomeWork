#include "head.h"
int main(void) {
	People *pe[4];
	pe[0] = new Baby(3);
	pe[1] = new Student(3,12);
	pe[2] = new Adult(3,12,25);
	pe[3] = new Older(3,12,25,68);
	for (int i = 0; i < 4; i++) {
		pe[i]->showage();
	}
	return 0;
}