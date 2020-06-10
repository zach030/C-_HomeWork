#pragma once
//�� ����һ����Base������Base��ÿ��Ȩ������Private��Protected��Public���£�
//����һ�����ݳ�Ա���ֱ�Ϊx��y��z������Public�����£���һ����ʾ�������ݳ�Ա���ݵĳ�Ա����showxyz()��
//�� ����Base�������������Զ�������˽�������ͱ�����������һ������Derive��
//��Derive�����ÿ��Ȩ������Private��Protected��Public���£�����һ�����ݳ�Ա���ֱ�Ϊdx��dy��dz����
//��Public�����£���һ����ʾ�������ݳ�Ա���ݵĳ�Ա����showdxyz()��
//�� Ϊ����������ֱ���Ӻ��ʵĹ��캯����ʵ��������ĸ������ݳ�Ա�ĳ�ʼ����
#include <iostream>
using namespace std;
class Base {
private:
	int x;
protected:
	int y;
public:
	int z;
	void showxyz() { cout << "Base::x=" << x << "  Base::y=" << y << "  Base::z=" << z << endl; }
	Base(int t1, int t2, int t3) :x(t1), y(t2), z(t3) {}
};
class Derive :public Base {
private:
	int dx;
protected:
	int dy;
public:
	int dz;
	void showxyz() { cout << "Derive::x=" << dx << " Derive::y=" << dy << " Derive::z=" << dz << endl; }
	Derive(int t1, int t2, int t3, int tx, int ty, int tz):Base(t1, t2, t3),dx(tx),dy(ty),dz(tz) {}
};
