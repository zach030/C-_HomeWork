//����һ����������ӣ�Box���࣬��������length������width�����ߣ�height�������ݳ�Ա��
//�����ܳ�compute_perimeter()�������compute_area()�����compute_volume()�ȳ�Ա������
//Ҫ���ܹ�ʹ�ù��캯�������ݳ�Ա���г�ʼ����������Ա�����ܹ������������ӵ��ܳ���������������
//�� ��ͷ�ļ��������࣬��Դ�ļ��ж�����ĳ�Ա�����Ͳ��Ժ�����ע��������ݳ�Ա�ͳ�Ա�����ķ���Ȩ�ޣ�
//�� ʹ�����ع��캯���������ݳ�Ա��ʼ�����ṩ2�ֻ����ϳ�ʼ�����ݳ�Աlength��width��height�ķ�����ע��������ع��캯���������Ͷ��巽ʽ��
//�� ����һ���������캯����ʹ�ÿ���ͨ��һ����������box1������ʼ����һ���¶�������box2����
//�¶�������ݳ�Աlength��width��height�Ĵ�СΪԭ�����2����ע����Ŀ������캯���������Ͷ��巽ʽ��
//�� ���main()���Ժ�������׼���ú��ʵĲ������ݡ�
#include <iostream>
using namespace std;
class Box {
private:
	int length;
	int width;
	int height;
public:
	int compute_perimeter();//�����ܳ�
	int compute_area();//�����
	int compute_volume();//���
	Box(int length, int width, int height) {
		this->height = height;
		this->length = length;
		this->width = width;
	}
	Box(const Box &b) {//�������캯��
		length = 2 * (b.length);
		width = 2 * (b.width);
		height = 2 * (b.height);
	}
};
int Box::compute_perimeter() {
	return 2 * (length + width + height);
}
int Box::compute_area() {
	return 2 * (length*width + length * height + width * height);
}
int Box::compute_volume() {
	return (length*width*height);
}
int main() {
	int length, width, height, flag = 1;
	char choose;
	while (flag) {
		cout << "Please input the length, width, height of the box:";
		cin >> length >> width >> height;
		Box b1(length, width, height);
		cout << "The perimeter of the box is :" << b1.compute_perimeter() << endl;
		cout << "The superficial area of the box is: " << b1.compute_area() << endl;
		cout << "The volume of the box is: " << b1.compute_volume() << endl;
		Box b2(b1);
		cout << "The preimeter, superficial are, volume of the box with double data is as follows:" << endl;
		cout << "The perimeter of the box is :" << b2.compute_perimeter() << endl;
		cout << "The superficial area of the box is: " << b2.compute_area() << endl;
		cout << "The volume of the box is: " << b2.compute_volume() << endl;
		cout << "Do you want to continue?(Y/N):";
		cin >> choose;
		if (choose == 'Y' || choose == 'y')
			flag = 1;
		else
	        flag = 0;
	}
	return 0;
}