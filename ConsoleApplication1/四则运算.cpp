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
int main() {
	Test();
	return  0;
}