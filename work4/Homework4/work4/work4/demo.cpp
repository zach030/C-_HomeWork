//�� ����һ���й����������֣�Singer���ࡣ���У��������ֵ����֣�name�����Ա�gender�������䣨age����
//  �ݳ���Ŀ��song�������ݳ�Ա���ṩEnroll()��Display()��Modify()�ȳ�Ա����ʵ�ֱ�������ʾ���޸ĵȹ��ܣ�
//�� �ṩ���ʵĹ��캯��ʵ�ֶ���Ĵ����������ö�������ʵ�ֶ��������Ϣ�ĵǼǣ�
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
	cin >> name >> gender >> age >> song;//�ֱ����뱨��ѡ�ֵ���Ϣ
	cout << "Enroll or not?(Y/N):";
	cin >> choose;
	if (choose == 'Y' || choose == 'y') {
		cout << "Enroll Successfully!" << endl;//�������������true�����������лᱻ���뵽������
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
	switch (num) {//ͨ����������ѡ���޸��ĸ���Ϣ
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
	Singer s[NUM];//����һ����СΪNUM�Ķ�������
	char choose;//��������������y/n
	cout << "Please input the numbers of the singers(<=3):";
	int num;
	cin >> num;//�μӵĸ�����
	for (int i = 0; i < num; i++) {
		if (s[i].Enroll())//��������ˣ������member������
			member.push_back(s[i]);
	}
	cout << "The following are the info of the enrolled singers:" << endl;
	for (auto i:member)//���ڷ�Χ��forѭ��������Ѿ��������û���Ϣ
		i.Display();
	cout << "Modify the info of the singers?(Y/N):";
	cin >> choose;
	if (choose == 'Y' || choose == 'y') {
		cout << "Please input the number of the singer:";
		cin >> num;//�����±�Ϊnum��ѡ����Ϣ
		member[num].Modify();
	}
	while (1) {//����һ����ѭ������ʾ�Ƿ�Ҫ�������������Ϣ
		cout << "Add another singer?(Y/N):";
		cin >> choose;
		if (choose == 'Y' || choose == 'y') {
			Singer s;
			s.Enroll();
			member.push_back(s);
		}
		else//������ټ������룬�������������ѭ��
			break;
	}
	cout << "End!" << endl;
	return 0;
}