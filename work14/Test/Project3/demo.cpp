#include <iostream>
using namespace std;
class BaseClass {
public:
	BaseClass afn() { cout << "This is BaseClass.\n";  return *this; }
};
class SubClass : public BaseClass {
public:
	SubClass afn() { cout << "This is SubClass.\n";  return *this; }
};
void test(BaseClass *x) { x->afn(); }
void test(SubClass *x) { x->afn(); }
int main(void) {
	BaseClass bc;
	SubClass sc;
	test(&bc);
	test(&sc);
	return 0;
}
/*
结果：
This is BaseClass
This is SubClass
*/