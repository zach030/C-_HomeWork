#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
const int MaxSize = 10;
class Array {
private:
	int length, data[MaxSize];
public:
	Array();//相当于初始化操作，一个空数组，长度为0
	Array(int a[], int n);//用给定长度为n的数组a初始化数据成员
	void Display();//显示所有数组元素
	void Insert(int x);//将给定的元素x插入到数组中后，仍保持数组的有序性；需要判断插入新元素会不会发生存储空间的溢出情况，若发生溢出提示插入操作失败；插入过程中，插入位置确定后，从插入位置至最后一个元素全部往后移一位，给新插入元素空出插入位置
	void Delete(int x);//从数组中删除指定元素x，后面的元素全部要往前移一位；做删除前需要判断数组是否为空，若为空表，则删除操作失败
	void Sort();//对数组进行降序排序
	int Search(int x);//从数组中查找指定元素x，若查找成功返回元素在数组中位置，查找失败返回特定值-1
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
		}// 插入在count位
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