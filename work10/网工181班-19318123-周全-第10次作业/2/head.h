#include <iostream>
#include <windows.h>
using namespace std;
//定义一个描述日期的类Date，构造函数完成年、月、日的初始化，
//包含一个修改日期的成员函数和一个显示日期的成员函数
class Date {
	int Year, Month, Day;
public:
	Date(int y = 0, int m = 0, int d = 0) :Year(y), Month(m), Day(d) {}
	void SetDate(int y, int m, int d) { Year = y; Month = m; Day = d; }
	void ShowDate() { cout << Year << "-" << Month << "-" << Day << " "; }
};
//② 定义一个与Date类似的描述时间的类Time，然后用这两个类作为基类，
class Time {
private:
	int Hour, Minute, Second;
public:
	Time(int h=0,int m=0,int s=0):Hour(h),Minute(m),Second(s){}
	void SetTime(int h, int m, int s) { Hour = h, Minute = m, Second = s; }
	void ShowTime() { cout << Hour << "-" << Minute << "-" << Second ; }
};
//公有派生出描述日期和时间的类DateTime，构造函数完成年、月、日、时、分、秒的初始化，
//同样包含一个修改日期和时间的成员函数和一个显示日期和时间的成员函数。DateTime类可定义为：
class DateTime : public Date, public Time {
public:
	DateTime(int y = 0, int mon = 0, int d = 0, int h = 0, int min = 0, int s = 0) :Date(y, mon, d), Time(h, min, s) { ShowDateTime(); }
	void SetDateTime(int y, int mon,int d,int h,int m,int s) {
		Date::SetDate(y, mon, d);
		Time::SetTime(h, m, s);
	}
	void ShowDateTime() {
		Date::ShowDate();
		Time::ShowTime();
	}
};
