#pragma once
//�� ����һ����������ĺ���ģ�壬��ԭ���������£�
//template <class T1, class T2, class T3>
//class OutPut {
//public:
//	//���ʵĹ��캯��
//	void Display();//����������ʵ��
//private:
//	T1 data1;		T2 data2;		T3 data3;
//};
//�� �Ӹ���ģ��ʵ����������ģ���࣬ʵ�ְ������͡������͡��ַ��ͺ��ַ��������ݵ������
#include<iostream>
#include <string>
using namespace std;
template <class T1, class T2, class T3>
class OutPut {
private:
	T1 data1;		T2 data2;		T3 data3;
public:
	//���ʵĹ��캯��
	OutPut(T1 d1,T2 d2,T3 d3):data1(d1),data2(d2),data3(d3){}
	void Display();
};
template <class T1, class T2, class T3>
void OutPut<T1, T2, T3>::Display() {
	cout << data1 << "\t" << data2 << "\t" << data3 << endl;
}