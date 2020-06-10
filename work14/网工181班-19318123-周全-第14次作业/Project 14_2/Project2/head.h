#pragma once
//�� ����һ����״��CShape�������ࣩ�������һ����ͨ��Ա����������������״��С�����س�Ա������
//SetData()�����������Ա���� - �ܳ����㺯��Perimeter()��������㺯��Area()��
//�� ��CShape������һ��Բ����CCircle�࣬������Ӧ���ݳ�Ա�ͳ�Ա���������¶��壻
//�� ��CShape������һ����������CTriangle�࣬������Ӧ���ݳ�Ա�ͳ�Ա���������¶��壻
//�� ��CShape������һ��������CRectangle�࣬������Ӧ���ݳ�Ա�ͳ�Ա���������¶��壻
//�� ��CShape������һ��������CTrapezia�࣬������Ӧ���ݳ�Ա�ͳ�Ա���������¶��壻
//�� ��Ʋ�����������ͨ��������Ӧ�İ뾶���������ߵ����ݳ�Ա��������Ӧ���ܳ��������
//�� ��ϸ�������ݳ�Ա����Щ��Ҫ���ܹ����ֳ������ݳ�Ա����ͨ���Ա������ͬ�����ǣ���
//�ֱ�ŵ���Щ�ࣨ�������ࡢ����ȣ��У�ע�⣺�麯�������麯����������;�����������������ʹ��ϸ�ڡ�
#include <iostream>
#define PI 3.14
using namespace std;
class CShape {
public:
	//virtual void SetData() = 0;
	virtual void Perimeter() = 0;
	virtual void Area() = 0;
};
class CCircle :public CShape {
private:
	int r;
public:
	CCircle(int r):r(r){}
	//void SetData();
	void Perimeter() {
		cout << "The Cirlce Perimeter is " << 2 * PI * r << endl;
	}
	void Area() {
		cout << "The Circle Area is " << PI * r * r << endl;
	}
};
class CTriangle :public CShape {
private:
	int side_a;
	int side_b;
	int side_c;
public:
	CTriangle(int a, int b, int c) :side_a(a), side_b(b), side_c(c) {}
	void Perimeter() {
		cout << "The Triangle Perimeter is " << side_a + side_b + side_c << endl;
	}
	void Area() {
		float p = (side_a + side_b + side_c) / 2;
		cout << "The Triangle Area is " << sqrt(p * (p - side_a) * (p - side_b) * (p - side_c)) << endl;
	}
};
class CRectangle :public CShape {
private:
	int width;
	int height;
public:
	CRectangle(int width, int height) :width(width), height(height) {}
	void Perimeter() {
		cout << "The Rectangle Perimeter is " << 2 * (width + height) << endl;
	}
	void Area() {
		cout << "The Rectangle Area is " << width * height << endl;
	}
};
// ��������
class CTrapezia :public CShape {
private:
	int waist;
	int head;
	int buttom;
public:
	CTrapezia(int w, int h, int b) :waist(w), head(h), buttom(b) {}
	void Perimeter() {
		cout << "The Trapezia Perimeter is " << 2 * waist + head + buttom << endl;
	}
	void Area() {
		float height = sqrt(pow(waist, 2) - pow((buttom - head) / 2, 2));
		cout << "The Rectangle Area is " << (head + buttom) * height / 2 << endl;
	}
};