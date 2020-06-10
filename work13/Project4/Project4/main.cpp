#include "head.h"
int main(void) {
	CDate cd(2020, 5, 20), cd1(2020, 5, 21);
	cd.ShowDate();
	cout << cd.GetMonthNameofDate(cd) << " " << cd.GetWeekNameofDate(cd) << endl;
	cout << cd.operator<(cd1) << endl;
	cd.operator++();
	cd.ShowDate();
	CTime ct(13, 14, 20);
	ct.ShowTime();
	CDateTime cdt(cd, ct);
	cdt.display();
	return 0;
}