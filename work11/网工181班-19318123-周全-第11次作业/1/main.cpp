#include "head.h"
int main(void)
{
	C c(1, 'a', "as", 2, 'b', "bs");
	//c.show();
	c.A::show();
	c.B::show();
	return 0;
}
