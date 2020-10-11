#include "fraction.h"
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
int main() {
	Test2();
	return  0;
}