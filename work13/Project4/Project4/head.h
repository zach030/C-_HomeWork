#pragma once
//① 定义一个描述日期的类CDate，构造函数完成年、月、日的初始化，包含重新设置日期、显示日期
//（包括中国、美国和欧洲显示时间的格式选择）、判断星期几等成员函数。在日期类CDate中增加成员函数重载运算符
//<、 <= 、 == 、>、 >= 、 != 、 + 、 - 、++和--，进行日期大小的比较、加减和自加 / 自减，
//应考虑到天数相加或相减、自加或自减需要修改月数和月数相加或相减、自加或自减需要修改年数的情况，
//另外还应考虑闰年的处理。该类定义形式可以参考：
#include <iostream>
#include <string>
using namespace std;
class  CDate {
	int Year, Month, Day; //分别存放年、月、日
	static int format;  //用于确定采用哪种格式显示日期
	enum WeekName { Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday };
	enum MonthName { January, February, Mars, April, May, June, July, August, September, October, November, December };
public:
	CDate();
	CDate(const CDate & d);
	CDate(int y = 0, int m = 0, int d = 0) :Year(y), Month(m), Day(d) {}
	//void SetDate(int ,int ,int );
	//void GetDate(char *);
	inline void SetYear(int y) {
		Year = y;
	}
	inline void SetMonth(int m) {
		Month = m;
	}
	inline void SetDay(int d) {
		Day = d;
	}
	inline int GetYear() {
		return Year;
	}
	inline int GetMonth() {
		return Month;
	}
	inline int GetDay() {
		return Day;
	}
	inline void ShowDate() {
		cout << "Year: " << Year << " Month: " << Month << " Day: " << Day << endl;
	}
	string GetWeekNameofDate(const CDate & d) {
		int y = d.Year, m = d.Month, day = d.Day;
		if (m == 1 || m == 2) {
			m += 12;
			y--;
		}
		int iWeek = (d.Day + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;
		string day_Of_Week;
		switch (iWeek)
		{
		case 0: day_Of_Week = "Monday"; return day_Of_Week; break;
		case 1: day_Of_Week = "Tuesday"; return day_Of_Week; break;
		case 2: day_Of_Week = "Wednesday"; return day_Of_Week; break;
		case 3: day_Of_Week = "Tursday"; return day_Of_Week; break;
		case 4: day_Of_Week = "Friday"; return day_Of_Week; break;
		case 5: day_Of_Week = "Saturday"; return day_Of_Week; break;
		case 6: day_Of_Week = "Sunday"; return day_Of_Week; break;
		}
	}
	string GetMonthNameofDate(CDate & d) {
		int name_Of_Month = d.GetMonth();
		switch (name_Of_Month - 1) {
		case 0:return "January"; break;
		case 1:return "February"; break;
		case 2:return "March"; break;
		case 3:return "April"; break;
		case 4:return "May"; break;
		case 5:return "June"; break;
		case 6:return "July"; break;
		case 7:return "August"; break;
		case 8:return "September"; break;
		case 9:return "October"; break;
		case 10:return "November"; break;
		case 11:return "December"; break;
		}
	}
	bool IsLeapYear() {
		//1、能被4整除，但不能被100整除；
		//2、能被400整除
		if (this->Year % 4 == 0 && this->Year % 100 != 0 || this->Year % 400 == 0)
			return true;
		else
			return false;
	}
	bool operator <(const CDate & d) const {
		if (this->Year < d.Year)
			return true;
		else if (this->Year == d.Year && this->Month < d.Month)
			return true;
		else if (this->Year == d.Year && this->Month == d.Month && this->Day < this->Day)
			return true;
		else
			return false;
	}
	bool operator <=(const CDate & d) const {
		if (this->Year < d.Year)
			return true;
		else if (this->Year == d.Year && this->Month < d.Month)
			return true;
		else if (this->Year == d.Year && this->Month == d.Month && this->Day <= this->Day)
			return true;
		else
			return false;
	}
	bool operator >(const CDate & d) const {
		if (this->Year > d.Year)
			return true;
		else if (this->Year == d.Year && this->Month > d.Month)
			return true;
		else if (this->Year == d.Year && this->Month == d.Month && this->Day > this->Day)
			return true;
		else
			return false;
	}
	bool operator >=(const CDate & d) const {
		if (this->Year > d.Year)
			return true;
		else if (this->Year == d.Year && this->Month > d.Month)
			return true;
		else if (this->Year == d.Year && this->Month == d.Month && this->Day >= this->Day)
			return true;
		else
			return false;
	}
	bool operator ==(const CDate & d) const {
		if (this->Year == d.Year && this->Month == d.Month&&this->Day == d.Day)
			return true;
		else 
			return false;
	}
	bool operator !=(const CDate & d) const {
		if (this->Year == d.Year && this->Month == d.Month&&this->Day == d.Day)
			return false;
		else
			return true;
	}
	//相差多少
	CDate& operator +(const CDate & d);
	CDate& operator -(const CDate & d);

	void operator ++() {
		if (this->IsLeapYear() && this->Month == 2 && this->Day == 28) {
			//闰年二月可以有29天
			this->Day = (this->Day + 1) % 29;
		}
		if (!this->IsLeapYear() && this->Month == 2) {
			//普通年份的二月
			this->Day = (this->Day + 1) % 28;
		}
		if (this->Month == 4 || this->Month == 6 || this->Month == 9
			|| this->Month == 11) {
			//有30天的月
			this->Day = (this->Day + 1) % 30;
		}
		else
			this->Day = (this->Day + 1) % 31;
	}
	void operator --() {
		if (this->Day == 1) {
			if (this->Month == 4 || this->Month == 6 || this->Month == 9
				|| this->Month == 11) {
				//有30天的月
				this->Day = 30;
				this->Month -= 1;
			}
			else {
				this->Day = 31;
				this->Month -= 1;
			}
		}
		else {
			this->Day--;
		}
	}

	friend ostream& operator <<(ostream& out, const CDate & d);
	friend istream& operator >>(istream& in, CDate & d);
};
//定义一个描述时间的类CTime，构造函数完成时、分、秒的初始化，包含重新设置时间、
//显示时间（包括12小时、24小时的时间显示格式）等成员函数。在时间类CTime中增加成员函数重载运算符
//<、 <= 、 == 、>、 >= 、 != 、 + 、 - 、++和--，应考虑到秒数相加或相减、
//自加或自减需要修改分钟数和分钟数相加或相减、自加或自减需要修改小时数的情况。该类定义形式可以参考
class  CTime {
	int Hour, Minute, Second; //分别存放时、分、秒
	static int format;       //用于确定采用哪种制式显示时间
public:
	CTime();
	CTime(const CTime & d);
	CTime(int h = 0, int m = 0, int s = 0) :Hour(h), Minute(m), Second(s) {}
	//void SetTime(int ,int ,int );
	//void GetTime(char *);
	inline void SetHour(int h) {
		this->Hour = h;
	}
	inline void SetMinute(int m) {
		this->Minute = m;
	}
	inline void SetSecond(int s) {
		this->Second = s;
	}
	inline int GetHour() {
		return Hour;
	}
	inline int GetMinute() {
		return Minute;
	}
	inline int GetSecond() {
		return Second;
	}
	inline void ShowTime() {
		cout << "Hour: " << Hour << " Minute: " << Minute << " Second: " << Second << endl;
	}

	bool operator <(const CTime & t) const {
		if (this->Hour < t.Hour)
			return true;
		if (this->Hour == t.Hour&&this->Minute < t.Minute)
			return true;
		if (this->Hour == t.Hour&&this->Minute == t.Minute&&this->Second < t.Second)
			return true;
		else
			return false;
	}
	bool operator <=(const CTime & t) const {
		if (this->Hour < t.Hour)
			return true;
		if (this->Hour == t.Hour&&this->Minute < t.Minute)
			return true;
		if (this->Hour == t.Hour&&this->Minute == t.Minute&&this->Second <= t.Second)
			return true;
		else
			return false;
	}
	bool operator >(const CTime & t) const {
		if (this->Hour > t.Hour)
			return true;
		if (this->Hour == t.Hour&&this->Minute > t.Minute)
			return true;
		if (this->Hour == t.Hour&&this->Minute == t.Minute&&this->Second > t.Second)
			return true;
		else
			return false;
	}
	bool operator >=(const CTime & t) const {
		if (this->Hour > t.Hour)
			return true;
		if (this->Hour == t.Hour&&this->Minute > t.Minute)
			return true;
		if (this->Hour == t.Hour&&this->Minute == t.Minute&&this->Second >= t.Second)
			return true;
		else
			return false;
	}
	bool operator ==(const CTime & t) const {
		if (this->Hour == t.Hour&&this->Minute == t.Minute&&this->Second == t.Second)
			return true;
		else
			return false;
	}
	bool operator !=(const CTime & t) const {
		if (this->Hour == t.Hour&&this->Minute == t.Minute&&this->Second == t.Second)
			return false;
		else
			return true;
	}
	CTime& operator +(const CTime & t);
	CTime& operator -(const CTime & t);
	void operator ++() {
		this->Second = (this->Second + 1) % 60;
		if ((this->Second + 1) / 60)
			this->Minute += 1;
	}
	void operator --() {
		if (this->Second == 0) {
			this->Second = 59;
			this->Minute -= 1;
		}
		else
			this->Second -= 1;
	}

	friend ostream& operator <<(ostream& out, const CTime& t);
	friend istream& operator >>(istream& in, CTime& t);
};
class CDateTime: public CDate, public CTime{
public:
	CDateTime(CDate &cd, CTime &ct) :CDate(cd.GetYear(), cd.GetMonth(), cd.GetDay()), CTime(ct.GetHour(), ct.GetMinute(), ct.GetSecond()) {}
	void display() {
		cout << "Year:" << CDate::GetYear() << " Month:" << CDate::GetMonth() << " Day:" << CDate::GetDay() << " Hour:"
			<< CTime::GetHour() << " Minute:" << CTime::GetMinute() << " Second:" << CTime::GetSecond() << endl;
	}
};
