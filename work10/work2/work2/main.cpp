#include "head.h"
void main() {
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	DateTime dt(sys.wYear, sys.wMonth, sys.wDay, sys.wHour, sys.wMinute, sys.wSecond);
	char flag = 'y';
	cout << endl << "是否需要修改日期和时间？(y/n)";
	cin >> flag;
	while (tolower(flag) == 'y') {
		cout << "请输入新的日期和时间：";
		int y, mon, d, h, min, s;
		cin >> y >> mon >> d >> h >> min >> s;
		dt.SetDateTime(y, mon, d, h, min, s);
		cout << "修改后的日期和时间为：";
		dt.ShowDateTime();
		cout << endl <<"------------------------------------------" << endl;
		cout << "是否继续修改日期和时间?(y/n)";
		cin >> flag;
	}
}
