#include "head.h"
int main(void){
	D d(98, 'b', "bs", 99, 'c', "cs");
	d.B::show();
	d.C::show();
	d.show();
	cout << "使用虚继承方式解决路径二义性时，派生类对象所占空间大小为：" << sizeof(d) << endl;
}
