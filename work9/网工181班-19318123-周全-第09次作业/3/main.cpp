#include "park.h"
int main(void) {
	int N = 0;
	cout << "请输入停车位数量：";
	cin >> N;                      //输入停车位数量，此处输入2
	Park park(N);                  //创建一个停车场对象
	Truck truck("苏A-01234", 20);   //创建卡车对象
	truck.enter(park);              //truck进入停车场，分配车位
	Car car1("苏A-56789", "Audi A8");      //创建轿车对象
	car1.enter(park);                   //car1进入停车场，分配停车位
	car1.leave(park);                   //car1离开停车场，缴纳停车费
	Bus bus("苏A-43210", 50);          //创建公交车对象
	bus.enter(park);                    //bus进入停车场，分配车位
	/*显示当前停放的车辆的车牌号码，以及当前的全部停车费收入*/
	park.showInfo();
	Car car2("苏A-98765", "Benz S400");   //创建轿车对象
	car2.enter(park);
	//car2进入停车场，分配停车位。因为没有空余停车位，所以无法分配
	bus.leave(park);                      //bus离开停车场，缴纳停车费
	truck.leave(park);                     //truck离开停车场，缴纳停车费
	/*显示当前停放的车辆的车牌号码，以及当前的全部停车费收入*/
	park.showInfo();
	return 0;
}
