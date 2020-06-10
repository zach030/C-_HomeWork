#pragma once
//① 定义一个GrandFather类，包括姓名（Name）、年龄（Age）、银行卡号（CardID）等数据成员和
//显示这些数据成员的相应成员函数；定义一个Father类，包括姓名（Name）、年龄（Age）、银行卡号（CardID）
//等数据成员和显示这些数据成员的相应成员函数；定义一个Child类，包括姓名（Name）、年龄（Age）、
//银行卡号（CardID）等数据成员和显示这些数据成员的相应成员函数。其中，Father类是从GrandFather类派生而来，
//Child类是从Father类派生而来；
//② 为上述三个类分别添加合适的构造函数，实现三个类的各自数据成员的初始化，
//并编写代码验证同名覆盖、支配规则、最近优先原则等机制；
//③ 根据类的需要添加适当的其它成员，编写完整的程序并测试。
#include <iostream>
#include <string>
using namespace std;
class GrandFather {
private:
	int  CardID;
	void showCardID() { cout << "GrandFather::CardID=" << CardID << endl; }
protected:
	int Age;
	void showAge() { cout << "GrandFather::Age=" << Age << endl; }
public:
	string Name;
	void showName() { cout << "GrandFather::Name=" << Name << endl; }
	GrandFather(string name, int age, int cardid) :Name(name), Age(age), CardID(cardid) {}
	//void showGrandFatherCardID(){showCardID();}    //预留的显示GrandFather类中CardID信息的接口；
};
class Father :public GrandFather {
private:
	int CardID;
	void showCardID() { cout << "Father::CardID=" << CardID << endl; }
protected:
	int Age;
	void showAge() { cout << "Father::Age=" << Age << endl; }
public:
	string Name;
	void showName() { cout << "Father::Name=" << Name << endl; }
	Father(string g_name, int g_age, int g_cardid, string name, int age, int cardid) :Name(name), Age(age), CardID(cardid),GrandFather(g_name, g_age, g_cardid){}
};
class Child :public Father {
private:
	int CardID;
	void showCardID(){ cout << "Child::CardID=" << CardID << endl; }
protected:
	int Age;
	void showAge() { cout << "Child::Age=" << Age << endl; }
public:
	string Name;
	void showName() { cout << "Child::Name=" << Name << endl; }
	Child(string g_name, int g_age, int g_cardid, 
		string f_name, int f_age, int f_cardid,
		string name, int age, int cardid) 
		:Name(name), Age(age), CardID(cardid), 
		Father(g_name, g_age,g_cardid, f_name, f_age, f_cardid){}
};
