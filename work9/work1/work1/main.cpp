#include "family.h"
int main(void) {
	//���´���Ϊ��֤ͬ�����ǻ��ƺ;ֲ�����ԭ��
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

	//���´���Ϊ��֤֧����򣨼���������򣩣�
	f.GrandFather::showName();
	c.GrandFather::showName();
	c.Father::showName();

	//���´���Ϊ��֤�������ԭ����Ҫע�͵�Child���е�showName()��Ա��������
	c.showName();
	return 0;
}
