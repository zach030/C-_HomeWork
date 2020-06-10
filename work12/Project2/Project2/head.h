#pragma once
//① 创建一个求最大数的函数模板，其原型声明如下：
//template <class T>
//T Max(T value[], int size) {
//
//}
//② 从该函数模板实例化出两个模板函数，分别能够求解若干整数和若干双精度浮点数中的最大数；
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
