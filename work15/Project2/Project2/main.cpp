//编程实现如下功能：域宽为14，以数据符号左对齐、数据本身右对齐方式打印输出9999；
//域宽为12，以有符号数和无符号数两种方式打印输出999；域宽为10，以0x开头的十六进制格式打印输出99；
//域宽为8，用前导符号$格式打印9.999。
#include <iostream>
#include <iomanip>
using namespace std;
int main() {
	cout << "域宽为14，以数据符号左对齐、数据本身右对齐方式打印输出9999" << endl;
	cout.setf(ios::showpos);
	cout << setiosflags(ios::left) << setw(14) << 9999 << setiosflags(ios::right) << endl;
	cout << "域宽为12，以有符号数和无符号数两种方式打印输出999" << endl;
	cout.setf(ios::showpos);
	cout << setw(10) << 999 << " ";
	cout.unsetf(ios::showpos);
	cout << 999 << endl;
	cout << "域宽为10，以0x开头的十六进制格式打印输出99" << endl;
	cout << setw(10) << hex << 99 << endl;
	cout << "域宽为8，用前导符号$格式打印9.999" << endl;
	cout.fill('$');
	cout.unsetf(ios::showpos);
	cout << setw(10) << 9.999 << endl;
	return 0;
}