#include "Family.h"
//Ancestor
void Ancestor::displayAncestor() {
	cout << "The information of my Ancestor is: " << Aname << "  " << Agender << endl;
}
//GrandFather
void GrandFather::displayGrandFather() {
	cout << "The information of my GrandFather is: " << Gname << "  " << Ggender << endl;
}
//Father
void Father::displayFather() {
	cout << "The information of my Father is: " << Fname << " " << Fgender << endl;
}
//Brother
void Brother::displayBrother() {
	cout << "The information of my Brother is: " << Bname << " " << Bgender << endl;
}
// Sister
void Sister::displaySister() {
	cout << "The information of my Sister is: " << Sname << " " << Sgender << endl;
}
//Me
void Me::displayMe() {
	Ancestor::displayAncestor();
	GrandFather::displayGrandFather();
	Father::displayFather();
	b.displayBrother();
	s.displaySister();
	cout << "The information of me is: " << Mname << " " << Mgender << endl;
}
