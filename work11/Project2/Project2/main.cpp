#include "head.h"
int main(void)
{
	D d(98, 'b', "bs", 99, 'c', "cs");
	//d.show();
	d.B::show();
	d.C::show();
	cout << "ʹ�������������·��������ʱ�������������ռ�ռ��СΪ��" << sizeof(d) << endl;
	return 0;
}
