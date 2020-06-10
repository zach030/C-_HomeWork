#include <iostream>
#include <windows.h>
using namespace std;
//����һ���������ڵ���Date�����캯������ꡢ�¡��յĳ�ʼ����
//����һ���޸����ڵĳ�Ա������һ����ʾ���ڵĳ�Ա����
class Date {
	int Year, Month, Day;
public:
	Date(int y = 0, int m = 0, int d = 0) :Year(y), Month(m), Day(d) {}
	void SetDate(int y, int m, int d) { Year = y; Month = m; Day = d; }
	void ShowDate() { cout << Year << "-" << Month << "-" << Day << " "; }
};
//�� ����һ����Date���Ƶ�����ʱ�����Time��Ȼ��������������Ϊ���࣬
class Time {
private:
	int Hour, Minute, Second;
public:
	Time(int h=0,int m=0,int s=0):Hour(h),Minute(m),Second(s){}
	void SetTime(int h, int m, int s) { Hour = h, Minute = m, Second = s; }
	void ShowTime() { cout << Hour << "-" << Minute << "-" << Second ; }
};
//�����������������ں�ʱ�����DateTime�����캯������ꡢ�¡��ա�ʱ���֡���ĳ�ʼ����
//ͬ������һ���޸����ں�ʱ��ĳ�Ա������һ����ʾ���ں�ʱ��ĳ�Ա������DateTime��ɶ���Ϊ��
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
