//① 定义一个学生（Student）类，用来管理一个学生的学籍信息，包括学号（sno）、姓名（sname）、性别（gender）、班级（grade）等数据成员，
//并提供一个成员函数student_show()显示学生的学号、姓名、性别、班级、课程、成绩等信息，
//一个成员函数course_show()显示课程的课程号、课程名等信息，
//一个成员函数score_show()显示分数等信息。
//其中，course_show()、score_show()分别设置为课程（Course）类和分数（Score）类的友元，
//或者将Student类设置为课程（Course）类和分数（Score）类的友元；
//② 定义一个课程（Course）类，用来管理一个学生所选的课程，包括课程号（cno）、课程名（cname）等数据成员，
//并提供一个构造函数初始化课程号（cno）、课程名（cname）等信息；
//③ 定义一个分数（Score）类，用来管理一个学生某门课程的分数，包括分数（score）等数据成员，
//并提供一个构造函数初始化分数（score）等信息；
//④ 设计main()测试函数，并准备好合适的测试数据
//学号、姓名、性别、班级、课程号、课程、成绩
#include <iostream>
#include <string>
using namespace std;
class Course {
private:
	string cno;
	string cname;
public:
	void setCourse();
	void course_show();
};
class Score {
private:
	int score;
public:
	void setScore();
	void score_show();
};
class Student {
private:
	string sno;//学号
	string sname;//姓名
	string gender;//性别
	string grade;//班级
public:
	void setStudent();
	void student_show();//输出学生信息
	friend void Course::course_show();
	friend void Score::score_show();
};
void Course::setCourse() {
	cin >> cno >> cname;
}
void Course::course_show() {
	cout << cno << " " << cname << " ";
}
void Score::setScore() {
	cin >> score;
}
void Score::score_show() {
	cout << score << endl;
}
void Student::student_show() {
	cout << sno << " " << sname << " " << gender << " " << grade << " ";
}
void Student::setStudent() {
	cin >> sno >> sname >> gender >> grade;
}
int main(void) {
	string sno;//学号
	string sname;//姓名
	string gender;//性别
	string grade;//班级
	string cno;
	string cname;
	int score;
	cout << "请输入两个学生课程信息(学号、姓名、性别、班级、课程号、课程、成绩):" << endl;
	Student s[2];
	Course c[2];
	Score sc[2];
	for (int i = 0; i < 2; i++) {
		s[i].setStudent();
		c[i].setCourse();
		sc[i].setScore();
	}
	cout << "学生课程信息如下：" << endl;
	for (int i = 0; i < 2; i++) {
		s[i].student_show();
		c[i].course_show();
		sc[i].score_show();
	}
	cout << "----------------------------------------------------" << endl;
	int flag = 1;
	while (flag) {
		cout << "继续输入成绩吗？(Y/N):";
		char key;
		cin >> key;
		if (key == 'Y' || key == 'y') {
			Student s;
			s.setStudent();
			Course c;
			c.setCourse();
			Score sc;
			sc.setScore();
			cout << "学生课程信息如下：" << endl;
			s.student_show();
			c.course_show();
			sc.score_show();
		}
		else
			flag = 0;
	}
	return 0;
}