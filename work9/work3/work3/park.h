#pragma once
//① 定义汽车基类（Automobile），包括车牌号码（plateNO，字符串）数据成员；
//② 定义派生类卡车（Truck）、公交车（Bus）、轿车（Car）。这些车辆除了拥有车牌号码之外，还拥有各自不同的属性。
//Truck包括载重量属性（load，浮点数），Bus包括核定载员数量（capacity，整型），Car包括品牌属性（brand，字符串）。
//此外，每个派生类需要实现成员函数pay()，用于显示车辆信息并缴纳停车费。
//其中，Truck收费3元 / 次，Bus收费2元 / 次，Car收费1元 / 次；
//③ 停车场（Park）有N个停车位（space），每个停车位可以停放不同类型的汽车（Automobile），
//包括Truck、Bus、Car，但同一时刻一个停车位只能停放0或1辆汽车。如果没有空余停车位，则显示提示信息，
//但不会为车辆安排停车位；停车场可以显示当前停放的车辆的车牌号码以及当前的全部停车费入（income）；
//④ 程序模拟车辆停车的情况：新来车辆时如果有空位，按顺序为该车分配停车位；车辆开走时，应交纳停车费；
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Park {
private:
	int total_amount;
	int income = 0;
public:
	int current_amount=0;
	Park(int number) :total_amount(number) { car_number[3] = { 0 }; }//构造函数
	vector<string> car_store_info;//定义一个存放停车信息的vector
	int car_number[3];//分别记录truck，bus和car的车数
	bool enter_or_not() {//判断是否可停车
		if (current_amount < total_amount)
			return true;
		else
			return false;
	}
	void add_income(int money) {
		income += money;
	}
	void showInfo() {
		cout << "停车场目前停放了" << current_amount << "辆汽车:";
		cout << "有" << car_number[0] << "辆truck,有" << car_number[1] << "辆bus,有" << car_number[2] << "辆car" << endl<<"分别为：";
		for (auto car : car_store_info) {
			cout << car << ",";
		}
		cout << ",共收入停车费" << income << "元！" << endl;
	}
};
class Automobile {
protected:
	string plateNO;
public:
	Automobile(string car_name) :plateNO(car_name) {}
	void remove_car(Park &park) {
		vector<string>::iterator it;
		for (it = park.car_store_info.begin(); it != park.car_store_info.end();)
		{
			if (*it == plateNO)
				it = park.car_store_info.erase(it);    //删除元素，返回值指向已删除元素的下一个位置
			else
				++it;    //指向下一个位置
		}
	}
};
class Truck :public Automobile {
private:
	float load;
public:
	Truck(string car_name, float car_load) :Automobile(car_name), load(car_load) {}
	void enter(Park &park) {
		if (park.enter_or_not()) {
			cout << plateNO << "进入停车场，分配停车位！" << endl;
			park.car_number[0]++;
			park.current_amount += 1;
			//cout << "现有truck:" << park.car_number[0] << endl;
			park.car_store_info.push_back(plateNO);
		}
		else
		{
			cout << "停车场已满，无法为"<<plateNO<<"分配车位！" << endl;
		}
	}
	void leave(Park &park) {
		cout << plateNO << "离开停车场，缴纳停车费3元!" << endl;
		park.car_number[0]--;
		park.add_income(3);
		park.current_amount--;
		remove_car(park);
	}
};
class Bus :public Automobile {
private:
	int capacity;
public:
	Bus(string car_name, int car_capacity) :Automobile(car_name), capacity(car_capacity) {}
	void enter(Park &park) {
		if (park.enter_or_not()) {
			cout << plateNO << "进入停车场，分配停车位！" << endl;
			park.car_number[1]++;
			park.current_amount++;
			//cout << "现有bus:" << park.car_number[1] << endl;
			park.car_store_info.push_back(plateNO);
		}
		else
		{
			cout << "停车场已满，无法为" << plateNO << "分配车位！" << endl;
		}
	}
	void leave(Park &park) {
		cout << plateNO << "离开停车场，缴纳停车费2元!" << endl;
		park.add_income(2);
		park.car_number[1]--;
		park.current_amount--;
		remove_car(park);
	}
};
class Car :public Automobile {
private:
	string brand;
public:
	Car(string car_name, string car_brand) :Automobile(car_name), brand(car_brand) {}
	void enter(Park &park) {
		if (park.enter_or_not()) {
			cout << plateNO << "进入停车场，分配停车位！" << endl;
			park.car_number[2]++;
			park.current_amount++;
			//cout << "现有car:" << park.car_number[2] << endl;
			park.car_store_info.push_back(plateNO);
		}
		else
		{
			cout << "停车场已满，无法为" << plateNO << "分配车位！" << endl;
		}
	}
	void leave(Park &park) {
		cout << plateNO << "离开停车场，缴纳停车费1元!" << endl;
		park.car_number[2]--;
		park.add_income(1);
		park.current_amount--;
		//cout << "car number:"<<park.car_number[2] << endl;
		remove_car(park);
	}
};
