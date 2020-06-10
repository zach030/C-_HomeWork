//① 定义一个中国好声音歌手（Singer）类。其中，包括歌手的名字（name）、性别（gender）、年龄（age）、
//  演唱曲目（song）等数据成员，提供Enroll()、Display()、Modify()等成员函数实现报名、显示、修改等功能；
//② 提供合适的构造函数实现对象的创建，并利用对象数组实现多个歌手信息的登记；
#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <vector>
#define NUM 3
using namespace std;
class Singer {
private:
	string name;
	string gender;
	int age;
	string song;
public:
	Singer() { cout << "Call constructor function!" << endl; }
	bool Enroll();
	void Display();
	void Modify();
	~Singer() { cout << "Call destructor function!" << endl; }
};
static vector<Singer> member;
bool Singer::Enroll() {
	char choose;
	cout << "Please input the info of the singer(name gender age song):";
	cin >> name >> gender >> age >> song;//分别输入报名选手的信息
	cout << "Enroll or not?(Y/N):";
	cin >> choose;
	if (choose == 'Y' || choose == 'y') {
		cout << "Enroll Successfully!" << endl;//如果报名，返回true，在主函数中会被加入到数组中
		return true;
	}
	else {
		cout << "Enroll Failed!" << endl;
		return false;
	}
}
void Singer::Display() {
	cout << name << " " << gender << " " << age << " " << song << endl;
}
void Singer::Modify() {
	cout << "Iuput the info num you need modify(1-name 2-gender 3-age 4-song):";
	int num;
	cin >> num;
	switch (num) {//通过输入数字选择，修改哪个信息
	case 1:cout << "Please input new name:" << endl; cin >> name; break;
	case 2:cout << "Please input new gender:" << endl; cin >> gender; break;
	case 3:cout << "Please input new age:" << endl; cin >> age; break;
	case 4:cout << "Please input new song:" << endl; cin >> song; break;
	}
	cout << "The info has been modified successfully!" << endl;
	cout << "The info of singer after modifying:" << endl;
	cout << name << " " << gender << " " << age << " " << song << endl;
}
int main() {
	Singer s[NUM];//定义一个大小为NUM的对象数组
	char choose;//用来存放输入的是y/n
	cout << "Please input the numbers of the singers(<=3):";
	int num;
	cin >> num;//参加的歌手数
	for (int i = 0; i < num; i++) {
		if (s[i].Enroll())//如果报名了，则加入member数组中
			member.push_back(s[i]);
	}
	cout << "The following are the info of the enrolled singers:" << endl;
	for (auto i:member)//基于范围的for循环，输出已经报名的用户信息
		i.Display();
	cout << "Modify the info of the singers?(Y/N):";
	cin >> choose;
	if (choose == 'Y' || choose == 'y') {
		cout << "Please input the number of the singer:";
		cin >> num;//调用下标为num的选手信息
		member[num].Modify();
	}
	while (1) {//设置一个死循环，提示是否要继续输入歌手信息
		cout << "Add another singer?(Y/N):";
		cin >> choose;
		if (choose == 'Y' || choose == 'y') {
			Singer s;
			s.Enroll();
			member.push_back(s);
		}
		else//如果不再继续输入，则跳出程序结束循环
			break;
	}
	cout << "End!" << endl;
	return 0;
}