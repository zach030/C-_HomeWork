#include "family.h"
int main(void) {
	//以下代码为验证同名覆盖机制和局部优先原则；
	GrandFather g("GrandFather", 70, 123);
	g.showName();
	//g.showAge();
	//g.showCardID();
	Father f("GrandFather", 70, 123, "Father", 40, 456);
	f.showName();
	//f.showAge();
	//f.showCardID();
	Child c("GrandFather", 70, 123, "Father", 40, 456, "Child", 10, 789);
	//c.showName();
	//c.showAge();
	//c.showCardID();

	//以下代码为验证支配规则（即作用域规则）；
	f.GrandFather::showName();
	c.GrandFather::showName();
	c.Father::showName();

	//以下代码为验证最近优先原则（需要注释掉Child类中的showName()成员函数）；
	c.showName();
	return 0;
}
