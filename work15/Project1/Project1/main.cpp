#include<iostream>
#include<iomanip>
using namespace std;
int main(void) {
	//7.1
	//int x = 30, y = 300, z = 1024;
	//cout << "Decimal:" << x << ' ' << y << ' ' << z << endl;
	//cout << "Octal:" << oct << x << ' ' << y << ' ' << z << endl;
	//cout << "Hexadecimal:" << hex << x << ' ' << y << ' ' << z << endl;
	//cout << setiosflags(ios::uppercase);//设置字母大写输出
	//cout << "Hexadecimal:" << x << ' ' << y << ' ' << z << endl;
	//cout << "Decimal:" << dec << x << ' ' << y << ' ' << z << endl;
	//7.2
	//int a = 10;
	//int b = 1000;
	//cout << setw(5) << a << "\n";
	//cout << setw(2) << b;
	//7.3
	//cout << setfill('*')
	//	<< setw(2) << "OK" << endl
	//	<< setw(3) << "OK" << endl
	//	<< setw(4) << "OK" << endl;
	//cout << setfill(' ');
	//7.4
	//double test = 22.0 / 7;
	//cout << test << endl;
	//cout << setprecision(0) << test << endl
	//	<< setprecision(1) << test << endl
	//	<< setprecision(2) << test << endl
	//	<< setprecision(3) << test << endl
	//	<< setprecision(4) << test << endl;
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(8) << test << endl;
	//cout << setprecision(6);
	//7.5
	//cout << setiosflags(ios::right)
	//	<< setw(5) << 1
	//	<< setw(5) << 2
	//	<< setw(5) << 3 << endl;
	//cout << setiosflags(ios::left)
	//	<< setw(5) << 1
	//	<< setw(5) << 2
	//	<< setw(5) << 3 << endl;
	//7.6
	/*double x = 66, y = -8.246;
	cout << x << " " << y << endl;
	cout << setiosflags(ios::showpoint);
	cout << x << " " << y << endl;*/
	//7.7
	//double x = 66, y = -8.246;
	//cout << x << " " << y << endl;
	//cout << setiosflags(ios::showpos);
	//cout << x << " " << y << endl;
	//7.8
	//char str[250];
	//cout << "请输入一字符串:\n";
	//cin.getline(str, sizeof(str), ',');
	//cout << "输出的字符串为:" << str << endl;
	//7.9
	//int x = 123;
	//double y = -3.456789;
	//cout << "x=";
	//cout.width(10);
	//cout << x;
	//
	//cout << "y=";
	//cout.width(10);
	//cout << y << endl;
	//
	//cout.setf(ios::left);
	//cout << "x=";
	//cout.width(10);
	//cout << x;
	//cout << "y=";
	//cout.width(10);
	//cout << y << endl;

	//cout.fill('*');
	//cout.precision(3);
	//cout.setf(ios::showpos);
	//cout.width(10);
	//cout << x;
	//cout << "y=";
	//cout.width(10);
	//cout << y << endl;

	//cout.setf(ios::scientific);
	//cout << x << ' ' << y << endl;
	//
	//cout.setf(ios::fixed);
	//cout << x << ' ' << y << endl;
	//7.10
	//class RMB {
	//protected:
	//	unsigned int yuan;
	//	unsigned int jf;
	//public:
	//	RMB(double v = 0.0) {
	//		yuan = unsigned(v);
	//		jf = unsigned((v - yuan) * 100 + 0.5);
	//	}
	//	operator double() {
	//		return (yuan + jf / 100.0);
	//	}
	//	void display(ostream& out) {
	//		cout << yuan << ' ' << setfill('0')
	//			<< setw(2) << jf << setfill(' ');
	//	}
	//};
	//ostream& operator << (ostream& ot, RMB& d) {
	//	d.display(ot);
	//	return ot;
	//}
	//void main() {
	//	RMB rmb(2.3);
	//	cout << "Intially rmb=" << rmb << "\n";
	//	rmb *= 2.0;
	//	cout << "them rmb=" << rmb << "\n";
	//}
	//7.11
	//class Complex {
	//	float real, img;
	//public:
	//	Complex(float r = 0, float i = 0) {
	//		real = r;
	//		img = i;
	//	}
	//	friend ostream & operator <<(ostream &, Complex &);
	//	friend istream & operator >>(istream&, Complex &);
	//};
	//ostream & operator << (ostream &output, Complex &obj) {
	//	output << obj.real;
	//	if (obj.img > 0) output << "+";
	//	if (obj.img != 0) output << obj.img << "i";
	//	return output;
	//}
	//istream & operator >>(istream &input, Complex &obj) {
	//	cout << "Input the real, imag of the complex:\n";
	//	input >> obj.real;
	//	input >> obj.img;
	//	return input;
	//}
	/*ofstream myf("d:\\myabc.txt");
	char txt[255];
	while (1) {
		cin.getline(txt, 255);
		if (strlen(txt) == 0)
			break;
		myf << txt << endl;
	}*/
	//7.13
	//ifstream myf("d:\\myabc.txt", ios::nocreate);
	//if (mrf.fail()) {
	//	cout << "file no exist!" << endl;
	//	return;
	//}
	//char txt[255];
	//myf >> txt;
	//while (!myf.eof()) {
	//	cout << txt << endl;
	//	myf >> txt;
	//}
	//ifstream ifile;
	//ofstream ofile;
	//ifile.open("d:\\fileIn.txt");
	//ofile.open("d:\\fileOut.txt");
	//if (ifile.fail() || ofile.fail()) {
	//	cerr << "open file fail\n";
	//	return EXIT_FAILURE
	//}
	//char ch;
	//ch = ifile.get();
	//while (!ifile.eof()) {
	//	ofile.put(ch);
	//	ch = ifile.get();
	//}
	//ifile.close();
	//ofile.close();
	//7.15
	//class student {
	//public:
	//	char name[10];
	//	int num;
	//	int age;
	//	char addr[15];
	//	friend ostream & operator <<(ostream &out, student&s);
	//	friend istream & operator >>(ostream &in, student&s);
	//};
	//ostream & operator << (ostream &out, student &s) {
	//	out << s.name << " " << s.num << " " << s.age << " " << s.addr << '\n';
	//	return out;
	//}
	//istream & operator >> (istream &in, student &s) {
	//	in >> s.name >> s.num >> s.age >> s.addr;
	//	return in;
	//}
	//7.16
void sort(int x[], int m) {
	//	int i, j, k, t;
	//	for (i = 0; i < m - 1; i++) {
	//		k = i;
	//		for (j = i + 1; j < m; j++) {
	//			if (x[j] < x[k]) k = j;
	//			if (k != i) {
	//				t = x[i]; x[i] = x[k]; x[k] = t;
	//			}
	//		}
	//	}
	//}
	//void main() {
	//	fstream dat, out;
	//	int i, a[20], b[20];
	//	dat.open("file.dat", ios::binary | ios::out | ios::in);
	//	if (!dat) {
	//		cout << ("can't open file\n");
	//		exit(0);
	//	}
	//	for (i = 0; i < 20; i++) {
	//		a[i] = rand();
	//		dat.write((char*)&a[i], sizeof(int));
	//	}
	//	dat.seekg(0);
	//	for (i = 0; i < 20; i++) {
	//		dat.read((char*)&b[i], sizeof(int));
	//	}
	//	sort(b, 20);
	//	out.open("file.out", ios::out);
	//	if (!out) {
	//		cout << "cannot open file\n";
	//		exit(0);
	//	}
	//	for (i = 0; i < 20; i++) {
	//		out << b[i] << ' ';
	//	}
	//	out << "\n";
	//	for (i = 0; i < 20; i++) {
	//		cout << setw(10) << b[i];
	//		if ((i + 1) % 5 == 0) cout << endl;
	//	}
	//	out.close();
	//	dat.close();
	//}
	//7.17
	//fstream f("DATA", ios::in | ios::out | ios::binary);
	//int i;
	//for (i = 0; i < 20;i++)
	//	f.write((char *)&i, sizeof(int));
	//streampos pos = f.tellp();
	//for (i = 20; i < 40; i++)
	//	f.write((char*)&i, sizeof(int));
	//f.seekg(pos);
	//f.read((char*)&i, sizeof(int));
	//cout << "the data stored is" << i << endl;
	//f.seekp(0, ios::beg);
	//for (i = 100; i < 140; i++)
	//	f.write((char*)&i, sizeof(int));
	//f.seekg(pos);
	//f.read((char*)&i, sizeof(int));
	//cout << "the data stored is" << i << endl;
	return 0;
}