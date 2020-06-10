//① 创建一个类CBase。在类CBase的每个权限区域（Private、Protected和Public）下，
//均有一个数据成员和若干个成员函数，其中一个成员函数用于显示同权限区域内数据成员的数据；
//② 从类CBase分别采用三种派生方式（私有派生、保护派生和公有派生）
//派生出三个子类CDeriveA、CDeriveB和CDeriveC。在三个子类的每个权限区域（Private、Protected和Public）下，
//均有一个数据成员和若干个成员函数，其中一个成员函数用于显示同权限区域内数据成员
//以及父类CBase相同权限区域内数据成员的数据（对于不能直接访问的父类数据成员，思考如何显示）；
//③ 为上述四个类分别添加合适的构造函数，实现四个类的各自数据成员的初始化；
//④ 根据程序编写时的编译情况，体会父类不同权限区域内的成员在不同继承方式下的访问情况，
//并尝试利用访问声明改变父类中不可访问的成员的权限；
#include <iostream>
using namespace std;
class CBase {
private:
	int x;
	void showx() { cout << "CBase::x=" << x << endl; }
protected:
	int y;
	void showy() { cout << "CBase::y=" << y << endl; }
public:
	int z;
	void showz() { cout << "CBase::z=" << z << endl; }
	CBase(int t1, int t2, int t3) :x(t1), y(t2), z(t3) {}
	void showbasex() { showx(); }
	void showbasey() { showy(); }
};
class CDeriveA :private CBase {
private:
	int x;
	void showax() { cout << "CDeriveA::x=" << x << endl; }
protected:
	int y;
	void showay() { cout << "CDeriveA::y=" << y << endl; }
public:
	int z;
	void showaz() { cout << "CDeriveA::z=" << z << endl; }
	CDeriveA(int a1, int a2, int a3, int a4, int a5, int a6) :x(a1), y(a2), z(a3), CBase(a4, a5, a6){}
	void showAxandBasexfromOuterA() {
		showax();
		showbasex();
	}
	void showAyandBaseyfromOuterA() {
		showay();
		showbasey();
	}

};
class CDeriveB :protected CBase {
private:
	int x;
	void showbx() { cout << "CDeriveB::x=" << x << endl; }
protected:
	int y;
	void showby() { cout << "CDeriveB::y=" << y << endl; }
public:
	int z;
	CDeriveB(int b1,int b2,int b3,int b4,int b5,int b6):x(b1),y(b2),z(b3),CBase(b4,b5,b6){}
	void showbz() {
		cout << "CDeriveB::z=" << z << endl;
	}
	void showBxandBasexfromOuterB() {
		showbx();
		showbasex();
	}
	void showByandBaseyfromOuterB() {
		showby();
		showbasey();
	}
};
class CDeriveC :public CBase {
private:
	int x;
	void showcx() { cout << "CDeriveC::x=" << x << endl; }
protected:
	int y;
	void showcy() { cout << "CDeriveC::y=" << y << endl; }
public:
	int z;
	void showcz() { cout << "CDeriveC::z=" << z << endl; }
	void showCxandBasexfromOuterC() {
		showcx(); 
		showbasex();
	}
	void showCyandBaseyfromOuterC() {
		showcy();
		showbasey();
	}
	CDeriveC(int c1, int c2, int c3,int c4, int c5, int c6):x(c1),y(c2),z(c3),CBase(c4,c5,c6){}
};

int main(void) {
	CDeriveA ca(11, 12, 13, 14, 15, 16);
	//ca.showx();
	//ca.showy();
	//ca.showz();
	//ca.showax();
	cout << "Derived from private:" << endl;
	ca.showAxandBasexfromOuterA();
	//ca.showay();
	ca.showAyandBaseyfromOuterA();
	ca.showaz();

	CDeriveB cb(21, 22, 23, 24, 25, 26);
	//cb.showx();
	//cb.showy();
	//cb.showz();
	//cb.showbx();
	cout << "Derived from protected:" << endl;
	cb.showBxandBasexfromOuterB();
	//cb.showby();
	cb.showByandBaseyfromOuterB();
	cb.showbz();

	CDeriveC cc(31, 32, 33, 34, 35, 36);
	//cc.showx();
	//cc.showy();
	//cc.showcx();
	//cc.showcy();
	cout << "Derived from public:" << endl;
	cc.showCxandBasexfromOuterC();
	cc.showCyandBaseyfromOuterC();
	cc.showz();
	cc.showcz();
	return 0;
}