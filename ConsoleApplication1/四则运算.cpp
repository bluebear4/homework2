#include "fraction.h"
#include "expression.h"
void Test() {
	cout << fraction("0/0").toString() << endl;
	cout << fraction("0").toString() << endl;
	cout << fraction("1").toString() << endl;
	cout << fraction("4/2").toString() << endl;
	cout << fraction("5/1").toString() << endl;
	cout << fraction("2/4").toString() << endl;
	cout << fraction("3/5").toString() << endl;
	cout << fraction("5/4").toString() << endl;
	cout << fraction("2'5/4").toString() << endl;
	cout << fraction("2'2/4").toString() << endl;
}
void Test2() {
	cout << (fraction("2") + fraction("5")).toString() << endl;
	cout << (fraction("2/4") + fraction("5")).toString() << endl;
	cout << (fraction("2/4") + fraction("1/4")).toString() << endl;
	cout << (fraction("2/4") + fraction("2/4")).toString() << endl;
	cout << endl;

	cout << (fraction("5") - fraction("2")).toString() << endl;
	cout << (fraction("5") - fraction("2/4")).toString() << endl;
	cout << (fraction("2/4") - fraction("1/4")).toString() << endl;
	cout << (fraction("2/4") - fraction("2/4")).toString() << endl;
	cout << endl;

	cout << (fraction("5") * fraction("2")).toString() << endl;
	cout << (fraction("4") * fraction("1/4")).toString() << endl;
	cout << (fraction("2/4") * fraction("1/4")).toString() << endl;
	cout << (fraction("2/4") * fraction("2/5")).toString() << endl;
	cout << endl;

	cout << (fraction("5") / fraction("2")).toString() << endl;
	cout << (fraction("4") / fraction("1/4")).toString() << endl;
	cout << (fraction("2/4") / fraction("1/4")).toString() << endl;
	cout << (fraction("2/4") / fraction("2/5")).toString() << endl;
}
void Test3() {
	for (int i = 0; i < 10; ++i) {
		expression e = expression(2);
		cout << e.toString() << "= " << e.getAns().toString() << endl;
	}
}

int main(int argc, char const *argv[])
{
	srand(time(0));
	Test3();
	return 0;
}