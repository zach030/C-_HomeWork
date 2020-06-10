#include "head.h"
int main(void) {
	OutPut<int, int, double> o1(1, 2, 3.3); 	
	o1.Display();
	OutPut<char, double, double> o2('A', 1.1, 2.2);
	o2.Display();
	OutPut<string, int, string> o3("C++",98,"分");
	o3.Display();
	return 0;
}
