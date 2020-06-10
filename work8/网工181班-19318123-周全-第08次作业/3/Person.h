#pragma once
//① 创建一个基类Person，数据成员有姓名（name）、性别（gender）、年龄（age）等数据成员，
//成员函数根据需要自行设计；
//② 学生类Student从Person派生，增加学号（sno）、专业（major）等数据成员，
//增加包括构造函数、析构函数、开学登记注册函数Enroll()、学生信息显示函数ShowStudent()、
//上课教师印象评价函数LikeOrNot()等在内的成员函数，并根据需要添加每个成员函数的参数；
//③ 教师类Teacher从Person派生，增加工号（tno）、学院（college）等数据成员，
//增加包括构造函数、析构函数、教师招聘函数Recruit()、教师信息显示函数ShowTeacher()、
//课程管理函数Course()等在内的成员函数，并根据需要添加每个成员函数的参数；
//④ 管理人员类Administrator从Person派生，增加工号（ano）、部门（section）等数据成员，
//增加包括构造函数、析构函数、管理人员雇佣函数Employ()、管理人员信息显示函数ShowAdministrator()、
//学生学籍管理函数ManageStudent()、教师课程管理函数ArrangeCourse()等在内的成员函数，并根据需要添加每个成员函数的参数；
//⑤ 创建一个学校类University，包括学校名字（uname）、地址（uaddress）等数据成员
//和学生、教师、教务管理人员等对象成员数组（每个数组至少包含一个对象成员），
//增加包括构造函数、析构函数、学校开学注册管理函数TermBegin()、
//学校的名称 / 地址 / 学生 / 教师 / 管理人员信息显示函数ShowUniversity()等在内的成员函数，并根据需要添加每个成员函数的参数；
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Person {
protected:
	string name, gender; int age;
public:
	Person() {}
	Person(string tname, string tgender, int tage)
		:name(tname), gender(tgender), age(tage) {}
};
class Teacher :public Person {
private:
	string tno;
	string college;
public:
	Teacher();
	~Teacher(){}
	void Recruit();
	void ShowTeacher();
	void Course();
};
class Student :public Person {
private:
	string sno;
	string major;
public:
	Student();
	~Student(){}
	void Enroll();
	void ShowStudent();
	bool LikeorNot(Teacher &t);
};
class University;
class Administrator :public Person {
private:
	string ano;
	string section;
public:
	Administrator();
	~Administrator(){}
	void Employ();//管理人员雇佣函数
	void ShowAdministrator();//管理人员信息显示函数
	void ManageStudent(University &u);//学生学籍管理函数
	void ArrangeCourse();//教师课程管理函数
};
class University {
private:
	string u_name;
	string u_address;
	vector<Student> s;
	//Student s[N];
	vector<Teacher> t;
	//Teacher t[N];
	vector<Administrator> a;
	//Administrator a[N];
public:
	University();
	~University() {}
	friend void Student::Enroll();
	friend class Administrator;//私有类用来管理学生和教师
	void TermBegin();// 学校开学注册管理函数
	void ShowUniversity();//管理人员信息显示函数
};
