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
			//�Ƿ���б����
			if (i - j == ans[i] - ans[j] || i - j == ans[j] - ans[i])
				return;
		// λ��б���ϣ�����showout����������
	}
	cout << "No." << cnt << ":";
	for (i = 1; i <= 8; i++) {
		cout << "  " << ans[i] << "  ";
	}
	cnt++;
	cout << "\n\n���������������" << endl;
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
	// ���õݹ����
	if (num >= 9) {
		showout(); return;
		// �����򷵻����ˣ���ص�Ƕ�׵��ϲ�ݹ鵱��
	}
	int i;
	for (i = 1; i <= 8; i++) {
		if (b[i] == false) {
			b[i] = true;
			ans[num] = i;
			dfs(num + 1);
			// �������㣬��Ϊ���������ǵ�Ҫ��
			ans[num] = 0;
			b[i] = false;
		}
	}
}
int main() {
	// �趨��ʼ���
	dfs(1);
	return 0;
}
