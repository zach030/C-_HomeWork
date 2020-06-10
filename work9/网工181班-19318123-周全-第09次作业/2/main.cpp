#include "base.h"
void main() {
	Base b(1, 2, 3);
	cout << "公有派生类对象赋值给基类对象前，基类对象的数据状态如下：" << endl;
	b.showxyz();
	Derive d(11, 12, 13, 14, 15, 16);
	b = d;
	cout << "公有派生类对象赋值给基类对象后，基类对象的数据状态如下：" << endl;
	b.showxyz();
	Base &rb = d;
	cout << "公有派生类对象初始化基类对象引用后，基类对象的数据状态如下：" << endl;
	rb.showxyz();
	Base *pb = &d;
	cout << "公有派生类对象地址赋值给基类对象指针后，基类对象的数据状态如下：" << endl;
	pb->showxyz();
}
