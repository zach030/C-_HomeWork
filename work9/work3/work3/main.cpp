#include "park.h"
int main(void) {
	int N = 0;
	cout << "������ͣ��λ������";
	cin >> N;                      //����ͣ��λ�������˴�����2
	Park park(N);                  //����һ��ͣ��������
	Truck truck("��A-01234", 20);   //������������
	truck.enter(park);              //truck����ͣ���������䳵λ
	Car car1("��A-56789", "Audi A8");      //�����γ�����
	car1.enter(park);                   //car1����ͣ����������ͣ��λ
	car1.leave(park);                   //car1�뿪ͣ����������ͣ����
	Bus bus("��A-43210", 50);          //��������������
	bus.enter(park);                    //bus����ͣ���������䳵λ
	/*��ʾ��ǰͣ�ŵĳ����ĳ��ƺ��룬�Լ���ǰ��ȫ��ͣ��������*/
	park.showInfo();
	Car car2("��A-98765", "Benz S400");   //�����γ�����
	car2.enter(park);
	//car2����ͣ����������ͣ��λ����Ϊû�п���ͣ��λ�������޷�����
	bus.leave(park);                      //bus�뿪ͣ����������ͣ����
	truck.leave(park);                     //truck�뿪ͣ����������ͣ����
	/*��ʾ��ǰͣ�ŵĳ����ĳ��ƺ��룬�Լ���ǰ��ȫ��ͣ��������*/
	park.showInfo();
	return 0;
}
