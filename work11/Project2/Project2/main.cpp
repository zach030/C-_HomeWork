#include "head.h"
int main(void)
{
	D d(98, 'b', "bs", 99, 'c', "cs");
	//d.show();
	d.B::show();
	d.C::show();
	cout << "使用作用域规则解决路径二义性时，派生类对象所占空间大小为：" << sizeof(d) << endl;
	return 0;
}
