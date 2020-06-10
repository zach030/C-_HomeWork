#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int ans[10];
bool b[10];
int cnt{ 1 };
void printmap(int pan[9][9]) {
	for (int i = 1; i <= 8; i++) {
		for (int j = 1; j <= 8; j++) {
			if (*(*(pan + i) + j) == 1) {
				cout << "# ";
			}
			else
			{
				cout << ". ";
			}
			if (j == 8) {
				cout << endl;
			}
		}
	}
}
void showout() {
	int i, j;
	for (i = 1; i <= 7; i++) {
		for (j = i + 1; j <= 8; j++)
			//是否处于斜线上
			if (i - j == ans[i] - ans[j] || i - j == ans[j] - ans[i])
				return;
		// 位于斜线上，结束showout函数的运行
	}
	cout << "No." << cnt << ":";
	for (i = 1; i <= 8; i++) {
		cout << "  " << ans[i] << "  ";
	}
	cnt++;
	cout << "\n\n按任意键继续……" << endl;
	cin.get();
	int pan[9][9] = {0};
	for (i = 1; i <= 8; i++) {
		int temp = ans[i];
		pan[i][temp] = {1};
	}
	printmap(pan);
	cout << endl;
}
void dfs(int num) {
	// 设置递归出口
	if (num >= 9) {
		showout(); return;
		// 若程序返回至此，则回到嵌套的上层递归当中
	}
	int i;
	for (i = 1; i <= 8; i++) {
		if (b[i] == false) {
			b[i] = true;
			ans[num] = i;
			dfs(num + 1);
			// 进行清零，因为不符合我们的要求
			ans[num] = 0;
			b[i] = false;
		}
	}
}
int main() {
	// 设定开始序号
	dfs(1);
	return 0;
}
