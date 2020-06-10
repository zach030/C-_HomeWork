#include "head.h"
int main(void) {
	int i, arr[N];	double dou[N];
	cout << "输入" << N << "个整数" << endl;
	for (i = 0; i < N; i++)
		cin >> arr[i];
	cout << "最大值为" << Max(arr, N) << endl;
	cout << "输入" << N << "个双精度型数据" << endl;
	for (i = 0; i < N; i++)
		cin >> dou[i];
	cout << "最大值为" << Max(dou, N) << endl;
	return 0;
}
