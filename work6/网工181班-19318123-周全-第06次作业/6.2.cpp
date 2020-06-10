//① 定义一个学生（Student）类，用来管理一个学生的学籍信息，包括学号（sno）、姓名（sname）、
//性别（gender）、班级（grade）、课程（scourse）、成绩（sscore）等数据成员，
//并提供一个成员函数student_show()显示学生的学号、姓名、性别、班级、课程、成绩等信息。
//其中，课程（scourse）、分数（sscore）分别为课程（Course）类和分数（Score）类的对象；
//② 定义一个课程（Course）类，用来管理一个学生所选的课程，包括课程号（cno）、课程名（cname）等数据成员，
//并提供一个成员函数course_show()显示课程号（cno）、课程名（cname）等信息；
//③ 定义一个分数（Score）类，用来管理一个学生某门课程的分数，包括分数（score）等数据成员，
//并提供一个成员函数score_show()显示分数（score）等信息；
#include <iostream>
#include <string>
using namespace std;
class Course {
private:
	int cno;
	string cname;
public:
	Course() {};
	Course(int cno, string name) {//构造函数
		this->cno = cno;
		this->cname = name;
	}
	void course_show() {
		cout << cno << " " << cname;
	}
};
class Score {
private:
	int score;
public:
	Score() {};
	Score(int score) {
		this->score = score;
	}
	void score_show() {
		cout << score;
	}
};
class Student {
private:
	int sno;
	string sname;
	string gender;
	string grade;
	Course scourse;
	Score sscore;
public:
	Student(int sno, string sname, string gender, string grade, Course &cs, Score &ss) {
		this->gender = gender;
		this->grade = grade;
		this->scourse = cs;
		this->sname = sname;
		this->sno = sno;
		this->sscore = ss;
	}
	void student_show() {
		cout << "The all information of the student is:  ";
		cout << sno << " " << sname << " " << gender << " "
			<< grade << " ";
		scourse.course_show(); 
		cout << " ";
		sscore.score_show();
	}
};
int main() {
	Course cs1(19218120, "C++");	
	Score sc1(90);
	Student st1(201811219, "张三", "男", "计科161", cs1, sc1);
	st1.student_show();
	return 0;
}
