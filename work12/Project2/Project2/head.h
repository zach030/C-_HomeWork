#pragma once
//�� ����һ����������ĺ���ģ�壬��ԭ���������£�
//template <class T>
//T Max(T value[], int size) {
//
//}
//�� �Ӹú���ģ��ʵ����������ģ�庯�����ֱ��ܹ������������������˫���ȸ������е��������
#include<iostream>
#include<string>
using namespace std;
const int N = 5;
template <class T>
T Max(T value[], int size) {
	T max = value[0];
	for (int i = 1; i <= size;i++) {
		if (value[i] > max) {
			max = value[i];
		}
	}
	return max;
}
