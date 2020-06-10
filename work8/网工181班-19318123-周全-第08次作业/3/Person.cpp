#include "Person.h"
//Teacher
Teacher::Teacher() {
	cin >> tno >> name >> gender >> age >> college;
}
void Teacher::Recruit() {
	cout << "一个教师招聘完成！" << endl;
}
void Teacher::ShowTeacher() {
	cout << tno <<" "<< name <<" "<< gender <<" "<< age <<" "<< college <<" "<< endl;
}
void Teacher::Course() {

}
//Student
Student::Student() {
	cin >> sno >> name >> gender >> age >> major;
}
void Student::ShowStudent() {
	cout << sno <<" "<< name <<" "<< gender <<" "<<age <<" "<< major<<" "<< endl;
}
void Student::Enroll() {
	cout << "一个学生注册完成！" << endl;
}
bool Student::LikeorNot(Teacher &t) {
	cout << name << "是否喜欢此老师" << "?"<<"(Y-Like/N-Not Like):";
	char choose;
	cin >> choose;
	if (choose == 'Y' || choose == 'y')
		return true;
	else
		return false;
}
//Administrator
Administrator::Administrator() {
	cin >> ano >> name >> gender >> age >> section;
}
void Administrator::Employ() {
	cout << "一个管理人员招聘完成！" << endl;
}
void Administrator::ShowAdministrator() {
	cout << ano <<" "<< name <<" "<< gender <<" "<< age <<" "<< section <<" "<< endl;
}
void Administrator::ArrangeCourse() {

}
void Administrator::ManageStudent(University &u) {
	cout << "请选择你的操作:1-查看学生信息 2-修改学生信息 3-删除学生信息" << endl;
	int choose;
	cin >> choose;
	int no;
	switch (choose) {
	case 1: {
		cout << "请输入学生编号:";
		cin >> no;
		u.s[no].ShowStudent();
	}
	case 2: {
		cout << "请输入学生编号";
		cin >> no;
		cout << "请重新输入信息:";
		u.s[no];
	}
	case 3:
	{
		cout << "请输入学生编号:";
		cin >> no;
		vector<Student>::iterator iter = u.s.begin() + no;
		u.s.erase(iter);
	}
	}
}
// Universty
University::University() {
	cout << "请输入大学的名称和地址: ";
	cin >> u_name >> u_address;
}
void University::TermBegin() {
	cout << "请按照如下格式输入2个学生的信息: " << endl;
	cout << "(学号 姓名 性别 年龄 专业)" << endl;
	for (int i = 0; i < 2; i++) {
		Student stu;
		s.push_back(stu);
		stu.Enroll();
	}
	cout << "请按照如下格式输入2个教师的信息：" << endl;
	cout << "(工号 姓名 性别 年龄 学院)" << endl;
	for (int i = 0; i < 2; i++) {
		Teacher tea;
		t.push_back(tea);
		tea.Recruit();
	}
	cout << "请按照如下格式输入2个管理人员的信息：" << endl;
	cout << "(工号 姓名 性别 年龄 部门)" << endl;
	for (int i = 0; i < 2; i++) {
		Administrator adm;
		a.push_back(adm);
		adm.Employ();
	}
}
void University::ShowUniversity() {
	cout << "该大学的基本信息如下：" << endl;
	cout << u_name <<" "<< u_address << endl;
	cout << "该大学的学生信息显示如下:" << endl;
	for (auto i : s) 
		i.ShowStudent();
	cout << "该大学的教师信息如下：" << endl;
	for (auto i : t) 
		i.ShowTeacher();
	cout << "该大学的管理人员信息如下:" << endl;
	for (auto i : a)
		i.ShowAdministrator();
}