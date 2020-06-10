#pragma once
//① 定义人People、幼儿Baby、学生Student、成年Adult和老年Older四个类，它们的派生关系为：
//People公有派生Baby，Baby公有派生Student，Student公有派生Adult，Adult公有派生Older。
//在上述类中，分别增加一个私有数据成员age和一个同名成员函数showage()，
//并将成员函数声明为纯虚函数（People类）或虚函数（其它四个类），用于存储和显示人生不同阶段的年龄；
//② 定义一个People类指针数组，用来存放上述四个派生类的对象，
//并利用该指针数组实现访问上述四个类的不同版本的showage()成员函数；
#include <iostream>
using namespace std;
class People {
private:
	int age;
public:
	virtual void showage() = 0;
};
class Baby :public People {
private:
	int age;
public:
	Baby(int age) :age(age){}
	void showage() {
		cout << "The baby age is " << age << endl;
	}
};
class Student :public Baby {
private:
	int age;
public:
	Student(int bage, int sage):Baby(bage),age(sage){}
	void showage() {
		cout << "The Student age is " << age << endl;
	}
};
class Adult :public Student {
private:
	int age;
public:
	Adult(int bage, int sage, int aage):Student(bage, sage),age(aage){}
	void showage() {
		cout << "The Adult age is " << age << endl;
	}
};
class Older :public Adult {
private:
	int age;
public:
	Older(int bage, int sage, int aage, int oage):Adult(bage, sage, aage),age(oage){}
	void showage() {
		cout << "The Older age is " << age << endl;
	}
};