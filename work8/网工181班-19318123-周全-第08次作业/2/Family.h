//④ 从父亲类Father派生出三个子类：自己类Me、兄弟类Brother和姐妹类Sister。
//每个子类均至少具有姓名、性别等数据成员，同时具有显示各自对象信息的展示函数等成员函数，
//三个子类相应的数据成员和成员函数要能区分开来。此外，在自己类Me中还有兄弟类Brother和姐妹类Sister两个对象成员；
//⑤ 为上述各个类分别添加相应的构造函数和析构函数，以进行上述各个类的对象的数据成员的初始化和对象的销毁，
//要求在构造函数和析构函数中能够输出相应的提示信息，以能够观察构造函数和析构函数的调用顺序，
//同时每个类的数据成员尽量采用成员初始化列表和构造函数体内赋值等多种初始化方式；
#pragma once
#include <iostream>
#include <string>
using namespace std;
class Ancestor {
protected:
	string Aname;	char Agender;
public:
	Ancestor(string name, char gender) : Aname(name), Agender(gender) { cout << "The Ancestor is constructed!" << endl; }
	~Ancestor() { cout << "The Ancestor is unconstructed!" << endl; }
	void displayAncestor();
};
class GrandFather :public Ancestor {
private:
	string Gname;
	char Ggender;
public:
	GrandFather(string gname, char ggender, string Aname, char Agender) :Ancestor(Aname, Agender), Gname(gname), Ggender(ggender) {
		cout << "The GrandFather is constructed!" << endl;
	}
	void displayGrandFather();
	~GrandFather() { cout << "The GrandFather is unconstructed!" << endl; }
};
class Father :public GrandFather {
private:
	string Fname;
	char Fgender;
public:
	Father(string fname, char fgender, string gname, char ggender,string Aname, char Agender) :GrandFather(gname, ggender,Aname,Agender), Fname(fname), Fgender(fgender) {
		cout << "The Father is constructed!" << endl;
	}
	~Father() { cout << "The Father is unconstructed!" << endl; }
	void displayFather();
};
class Brother :public Father {
private:
	string Bname;
	char Bgender;
public:
	Brother(string bname, char bgender, string fname, char fgender, string gname, char ggender, string aname, char agender) :Father(fname, fgender, gname, ggender, aname, agender), Bname(bname), Bgender(bgender) {
		cout << "The Brother is constructed!" << endl;
	}
	~Brother() { cout << "The Brother is unconstructed!" << endl; }
	void displayBrother();
};
class Sister :public Father {
private:
	string Sname;
	char Sgender;
public:
	Sister(string sname, char sgender, string fname, char fgender, string gname, char ggender, string aname, char agender) :Father(fname, fgender, gname, ggender, aname, agender), Sname(sname), Sgender(sgender) {
		cout << "The Sister is constructed!" << endl;
	}
	~Sister() { cout << "The Sister is unconstructed!" << endl; }
	void displaySister();
};
class Me :public Father {
private:
	string Mname;
	char Mgender;
	Brother b;
	Sister s;
public:
	Me(string mname, char mgender, string fname, char fgender,string gname,char ggender,
	   string aname, char agender,Brother bro,Sister sis) :Father(fname, fgender,gname,ggender,
	   aname,agender), 
	   Mname(mname), Mgender(mgender),b(bro),s(sis){
	   cout << "Me is constructed!" << endl;
	}
	~Me() { cout << "Me is unconstructed!" << endl; }
	void displayMe();
	
};