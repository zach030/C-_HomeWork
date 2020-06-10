#include <iostream>
#include <cstdio>
using namespace std;
int ans[10];
bool b[10];
void out() {
	int i, j;
	for (i = 1; i <= 7; i++) {
		for (j = i; j <= 8; j++)
			if (i - j == ans[i] - ans[j] || i - j == ans[j] - ans[i])
				return;
	}
	for (i = 1; i <= 8; i++)
		cout << "(" << i << "," << ")" << endl;
	cout << endl;
}
void dfs(int num) {
	if (num >= 9) {
		out(); return;
	}
	int i;
	for (i = 1; i <= 8; i++) {
		if (b[i] == false) {
			b[i] = true;
			ans[num] = i;
			dfs(num + 1);
			ans[num] = 0;
			b[i] = false;
		}
	}
}
int main() {
	dfs(1);
	return 0;
}
