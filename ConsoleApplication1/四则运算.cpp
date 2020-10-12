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
bool check(string my, string std, string nowPath) {
	if ((!my.empty() && std.empty()) || (my.empty() && !std.empty())) {
		cout << "please input 2 file path to check. e.g. -e <exercisefile>.txt -a <answerfile>.txt" << endl;
		system("pause");
		return 0;
	}
	if (my.empty() && std.empty()) return 1;
	ifstream myFile(my);
	if (myFile.fail()) {
		cout << "can't open file " << my << endl;
		system("pause");
		return 0;
	}
	vector<fraction> myans;
	string s;
	while (getline(myFile, s)) {
		if (s.empty()) continue;
		myans.emplace_back(s.substr(s.find('.') + 1));
	}
	myFile.close();

	ifstream stdFile(std);
	if (stdFile.fail()) {
		cout << "can't open file " << std << endl;
		system("pause");
		return 0;
	}
	vector<fraction> stdans;

	while (getline(stdFile, s)) {
		if (s.empty()) continue;
		stdans.emplace_back(s.substr(s.find('.') + 1));
	}
	stdFile.close();

	ofstream GradeFile(nowPath + "/Grade.txt");
	if (GradeFile.fail()) {
		cout << "can't open file Grade.txt" << endl;
		system("pause");
		return 0;
	}
	vector<int> Correct, Wrong;
	for (size_t i = 0; i < myans.size(); i++)
	{
		if (myans[i] == stdans[i]) {
			Correct.emplace_back(i + 1);
		}
		else {
			Wrong.emplace_back(i + 1);
		}
	}
	GradeFile << "Correct: ";
	GradeFile << Correct.size();
	if (Correct.size())GradeFile << " (";
	for (size_t i = 0; i < Correct.size(); i++)
	{
		GradeFile << Correct[i] << " )"[i + 1 == Correct.size()];
	}
	GradeFile << endl;

	GradeFile << "Wrong: ";
	GradeFile << Wrong.size();
	if (Wrong.size())GradeFile << " (";
	for (size_t i = 0; i < Wrong.size(); i++)
	{
		GradeFile << Wrong[i] << " )"[i + 1 == Wrong.size()];
	}
	GradeFile << endl;
	return 1;
}
int main(int argc, char const *argv[])
{
	srand(time(0));
	string nowPath = argv[0];
	nowPath.erase(nowPath.begin() + nowPath.find_last_of("\\\\"), nowPath.end());
	
	int cnt = -1;
	long long limit = 100;//默认100
	string my, std;
	for (size_t i = 0; i < argc; i++)
	{
		if (strcmp(argv[i], "-n") == 0) {
			if (i + 1 >= argc || !isdigit(argv[i + 1][0])) {
				cout << "please input a positive integer after -n" << endl;
				system("pause");
				return 0;
			}
			else {
				cnt = stoi(argv[i + 1]);
			}
		}
		if (strcmp(argv[i], "-r") == 0) {
			if (i + 1 >= argc || !isdigit(argv[i + 1][0])) {
				cout << "please input a positive integer more than 1 after -r" << endl;
				system("pause");
				return 0;
			}
			else {
				limit = stoll(argv[i + 1]);
			}
		}
		if (strcmp(argv[i], "-r") == 0) {
			if (i + 1 >= argc || !isdigit(argv[i + 1][0])) {
				cout << "please input a positive integer more than 1 after -r" << endl;
				system("pause");
				return 0;
			}
			else {
				limit = stoll(argv[i + 1]);
			}
		}
		if (strcmp(argv[i], "-e") == 0) {
			if (i + 1 >= argc) {
				cout << "please input a file path after -e" << endl;
				system("pause");
				return 0;
			}
			else {
				my = argv[i + 1];
			}
		}
		if (strcmp(argv[i], "-a") == 0) {
			if (i + 1 >= argc) {
				cout << "please input a file path after -a" << endl;
				system("pause");
				return 0;
			}
			else {
				std = argv[i + 1];
			}
		}
	}
	if (!check(my, std, nowPath)) {
		return 0;
	}
	if (cnt < 1) {
		cout << "please input a positive integer after -n" << endl;
		system("pause");
		return 0;
	}
	if (limit < 2) {
		cout << "please input a positive integer more than 1 after -r" << endl;
		system("pause");
		return 0;
	}
	ofstream exFile(nowPath + "\\Exercises.txt");
	if (exFile.fail()) {
		cout << "can't open file Exercises.txt" << endl;
		system("pause");
		return 0;
	}
	ofstream ansFile(nowPath + "\\Answers.txt");
	if (ansFile.fail()) {
		cout << "can't open file Answers.txt" << endl;
		system("pause");
		return 0;
	}
	set<expression> ex;
	while (ex.size() < cnt)
	{
		ex.insert(expression(limit));
	}
	int id = 1;
	for (auto it : ex) {
		exFile << id << "." << it.toString() << endl;
		++id;
	}
	exFile.close();
	id = 1;
	for (auto it : ex) {
		ansFile << id << "." << it.getAns().toString() << endl;
		++id;
	}
	ansFile.close();
	system("pause");
	return 0;
}