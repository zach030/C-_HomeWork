#pragma once
//⑤ 为上述类分别添加合适的构造函数，实现上述类的各自数据成员的初始化，
//并考虑：上述类的普通成员函数的调用方式，比如是否可在各自构造函数中调用？
#include <iostream>
using namespace std;
//① 定义一个木头类Wood和一个金属类Metal，分别具有wamount和mamount等数据成员，
//用于存放一件家具使用的木头和金属材料的数量；分别具有UseWood()和UseMental()等成员函数，
//分别用于输出一件家具使用的木头和金属材料的数量，并且在两个类的构造函数中调用各自的成员函数；
class Wood {
public:
	int wamount;
	Wood(int temp) :wamount(temp) { UseWood(); }
	void UseWood() { cout << "The furniture uses " << wamount << " pieces woods." << endl; }
};
class Mental {
public:
	int mamount;
	Mental(int temp) :mamount(temp) { UseMental(); }
	void UseMental(){ cout << "The furniture uses " << mamount << " pieces mentals." << endl; }
};
//② 从Wood和Metal两个类派生出一个家具类Furniture，除了构造函数外，该类不具有任何数据成员和成员函数，
//仅用于传递基类初始化所需的数据；
class Furniture : public Wood, public Mental {
public:
	Furniture(int t1, int t2) :Wood(t1), Mental(t2) {}
};
//③ 从Furniture类分别派生出一个沙发类Sofa和一个床类Bed。沙发类Sofa包含重量（sofaweight）、
//容量（sofacapacity）等数据成员和CanSit()等成员函数，其中CanSit()用于输出一个沙发具有的重量（sofaweight）
//和可以坐下的人数（sofacapacity）；床类Bed包含重量（bedweight）、容量（bedcapacity）等数据成员
//和CanLie()等成员函数，其中CanLie()用于输出一个床具有的重量（bedweight）和可以躺下的人数（bedcapacity）；
class Sofa :public Furniture {
public:
	int sofaweight;
	int sofacapacity;
	Sofa(int t1, int t2, int t3, int t4) :Furniture(t1, t2), sofaweight(t4), sofacapacity(t3){
		CanSit();
	}
	void CanSit() { cout << "The Sofa weight is " << sofaweight << ".The number of people can sit is: " << sofacapacity << endl; }
};
class Bed :public Furniture {
public:
	int bedweight;
	int bedcapacity;
	Bed(int t1, int t2, int t3, int t4) :Furniture(t1, t2), bedweight(t4), bedcapacity(t3) {
		CanLie();
	}
	void CanLie(){ cout << "The Bed weight is " << bedweight << ".The number of people can lie is: " << bedcapacity << endl; }
};
//④ 从Sofa和Bed两个类派生出一个沙发床类SofaBed，具有ItsFunction()等成员函数，
//其中ItsFunction()用于输出一个沙发床具有的重量（来自于Sofa和Bed两个类的重量之和）和
//可以容纳的人数（来自于Sofa和Bed两个类的容量之和）；
class SofaBed : public Sofa, public Bed {
public:
	SofaBed(int t1, int t2, int t3, int t4, int t5, int t6, int t7, int t8) :Sofa(t1, t2, t3, t4), Bed(t5, t6, t7, t8){
		ItsFunction();
	}
	void ItsFunction(){
		cout << "The SofaBed uses " << Bed::wamount + Sofa::wamount << " pieces woods and" << Bed::mamount + Sofa::mamount << " pieces mentals," <<
			" and weights " << Bed::bedweight + Sofa::sofaweight << " and can accommodate " << Bed::bedcapacity + Sofa::sofacapacity << " persons." <<endl;
	}
};

