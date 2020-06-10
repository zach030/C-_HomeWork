#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
const int MaxSize = 10;
class Array {
private:
	int length, data[MaxSize];
public:
	Array();//�൱�ڳ�ʼ��������һ�������飬����Ϊ0
	Array(int a[], int n);//�ø�������Ϊn������a��ʼ�����ݳ�Ա
	void Display();//��ʾ��������Ԫ��
	void Insert(int x);//��������Ԫ��x���뵽�����к��Ա�������������ԣ���Ҫ�жϲ�����Ԫ�ػ᲻�ᷢ���洢�ռ���������������������ʾ�������ʧ�ܣ���������У�����λ��ȷ���󣬴Ӳ���λ�������һ��Ԫ��ȫ��������һλ�����²���Ԫ�ؿճ�����λ��
	void Delete(int x);//��������ɾ��ָ��Ԫ��x�������Ԫ��ȫ��Ҫ��ǰ��һλ����ɾ��ǰ��Ҫ�ж������Ƿ�Ϊ�գ���Ϊ�ձ���ɾ������ʧ��
	void Sort();//��������н�������
	int Search(int x);//�������в���ָ��Ԫ��x�������ҳɹ�����Ԫ����������λ�ã�����ʧ�ܷ����ض�ֵ-1
};
Array::Array() {
	data[0];
}
Array::Array(int a[], int n) {
	for (int i = 0; i < n; i++)
		data[i] = a[i];
	length = n;
}
void Array::Display() {
	for (int i = 0; i < length; i++)
		cout << data[i] << " ";
	cout << endl;
}
void Array::Insert(int x) {
	int count = 0;
	if (length >= MaxSize)
		cout << "Insert Failed!" << endl;
	else {
		length++;
		for (int i = 0; i < length; i++) {
			if (x <= data[i])
				count++;
		}// ������countλ
		for (int i = length - 1; i >= count; i--)
			data[i] = data[i - 1];
		data[count] = x;
	}
	
}
void Array::Delete(int x) {
	if (length == 0)
		cout << "Delete failed!" << endl;
	else {
		int count = 0;
		for (int i = 0; i < length; i++)
			if (x == data[i]) count = i;
		for (int i = count; i < length; i++)
			data[i] = data[i + 1];
	}
	length--;
}
void Array::Sort() {
	for (int i = 0; i < length - 1; i++) 
		for (int j = 0; j < length - i - 1; j++) {
			if (data[j] < data[j + 1])
				swap(data[j], data[j + 1]);
		}
}
int Array::Search(int x) {
	int flag = 1;
	for (int i = 0; i < length; i++) {
		if (x == data[i]) {
			flag = 1;
			return i;
		}
	}
	if (!flag)
		return -1;
}
bool choose() {
	cout << "Continue or not?(Y/N):";
	char key;
	cin >> key;
	if (key == 'Y' || key == 'y')
		return true;
	else
		return false;
}
int main() {
	int *array = new int[MaxSize];
	int size = 0;
	cout << "Please input the length of the array:";
	cin >> size;
	cout << "Please input the elements of the array:";
	for (int i = 0; i < size; i++)
		cin >> *(array+i);
	Array a(array, size);
	bool flag = true;
	while (flag) {
		cout << "Please choose(1-Display 2-Sort 3-Insert 4-Delete 5-Search):";
		int key;
		cin >> key;
		int elem;
		switch (key) {
		case 1:a.Display(); flag = choose(); break;
		case 2:a.Sort(); flag = choose(); break;
		case 3: {
			cout << "Please input new element:";
			cin >> elem;
			a.Insert(elem);
			flag = choose();
		}break;
		case 4: {
			cout << "Please input the element you need to delete:";
			cin >> elem;
			a.Delete(elem);
			flag = choose();
		}break;
		case 5: {
			cout << "Please input the element you need to search:";
			cin >> elem;
			cout << "The position is " << a.Search(elem) << endl;
			flag = choose();
		}break;
		}
	}
	return 0;
}