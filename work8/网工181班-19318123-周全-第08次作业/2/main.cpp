//① 创建一个祖先类Ancestor。在祖先类Ancestor中，至少具有姓名（Aname）、性别（Agender）等数据成员，
//同时具有显示祖先信息的展示函数displayAncestor()等成员函数；
//② 从祖先类Ancestor派生出一个祖父类GrandFather，至少具有姓名（Gname）、性别（Ggender）等数据成员，
//同时具有显示祖父信息的展示函数displayGrandFather()等成员函数；
//③ 从祖父类GrandFather派生出一个子类：父亲类Father，至少具有姓名、性别等数据成员，
//同时具有显示各自对象信息的展示函数等成员函数；
//④ 从父亲类Father派生出三个子类：自己类Me、兄弟类Brother和姐妹类Sister。
//每个子类均至少具有姓名、性别等数据成员，同时具有显示各自对象信息的展示函数等成员函数，
//三个子类相应的数据成员和成员函数要能区分开来。此外，在自己类Me中还有兄弟类Brother和姐妹类Sister两个对象成员；
//⑤ 为上述各个类分别添加相应的构造函数和析构函数，以进行上述各个类的对象的数据成员的初始化和对象的销毁，
//要求在构造函数和析构函数中能够输出相应的提示信息，以能够观察构造函数和析构函数的调用顺序，
//同时每个类的数据成员尽量采用成员初始化列表和构造函数体内赋值等多种初始化方式；
#include "Family.h"

void main() {
	Brother bro("ZX", 'M', "ZF", 'M', "FQ", 'M', "Bro", 'M');
	Sister  sis("ZX", 'M', "ZF", 'M', "FQ", 'M', "Sis", 'F');
	Me me("ZX", 'M', "ZF", 'M', "FQ", 'M', "Me", 'M', bro, sis);
	me.displayMe();
}

