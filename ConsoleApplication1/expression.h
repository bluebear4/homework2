#pragma once
#include"fraction.h"
class expression
{

	static constexpr int numberLimit = 4;
	static constexpr char ops[] = "+-*/";
	vector<fraction> nums;
	vector<char> chars;
	pair<int, int> brackets{ -1,-1 };
	fraction ans;
	string exp;
	bool invalid = 0;
	static int getPriority(char ch) {

		switch (ch) {
		case '(':
			return 1;
		case '+':
		case '-':
			return 2;

		case '*':
		case '/':
			return 3;

		default:
			return 4;
		}
	}
	fraction cal(fraction&a, fraction &b, char op) {
		if (a.toString() == "NAN" || b.toString() == "NAN")
			return fraction();
		if (op == '+') return a + b;
		if (op == '-') return a - b;
		if (op == '*') return a * b;
		if (op == '/') {
			if (b == fraction("0")) {
				return fraction();
			}
			return a / b;
		}
		return fraction();
	}
	fraction calAns() {
		queue<pair<fraction, char>> que;
		stack< char> op;
		int i = 0;
		while (i < exp.size()) {
			if (isdigit(exp[i])) {  // 如果是数字
				que.push({ fraction(exp.substr(i,exp.find(' ',i) - i)),1 });
				i = exp.find(' ', i) + 1;
			}
			else if (exp[i] == '(') {  // (:左括号
				op.push(exp[i]);
				i++;
			}
			else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {  // 操作符
				if (op.empty()) {             // 如果栈空，直接压入栈
					op.push(exp[i]);
					i++;
				}
				else {
					// 比较栈op顶的操作符与ch的优先级
					// 如果ch的优先级高，则直接压入栈
					// 否则，推出栈中的操作符，直到操作符小于ch的优先级，或者遇到（，或者栈已空
					while (!op.empty()) {
						char c = op.top();
						if (getPriority(exp[i]) <= getPriority(c)) {
							// 优先级低或等于
							que.push({ fraction(),c });
							op.pop();
						}
						else {
							break;// ch优先级高于栈中操作符}
						}  // while结束
					}
					op.push(exp[i]);
					// 防止不断的推出操作符，最后空栈了;或者ch优先级高了
					i++;
					// else
				}
			}
			else if (exp[i] == ')') {
				// 如果是右括号，一直推出栈中操作符，直到遇到左括号(
				while (op.top() != '(') {
					que.push({ fraction(),op.top() });
					op.pop();
				}
				op.pop();  // 把左括号(推出栈
				i++;
			}
			else
			{
				i++;// 如果是空白符，就进行下一个字符的处理
			}
		}                      // 第二个while结束
		while (!op.empty()) {
			que.push({ fraction(),op.top() });
			op.pop();
		}
		stack<fraction> stk;
		while (que.size()) {
			if (que.front().first.toString() != "NAN") {
				stk.push(que.front().first);
				que.pop();
			}
			else {
				fraction b = stk.top();
				stk.pop();
				fraction a = stk.top();
				stk.pop();
				char c = que.front().second;
				que.pop();
				stk.push(cal(a, b, c));
				if (stk.top() < fraction("0")) {
					return fraction();
				}
			}
		}
		return stk.top();
	}

public:
	expression(long long limit) {
		int cnt = rand() % (numberLimit - 1) + 2;

		if (cnt > 2 && rand() % 2) {
			brackets.first = rand() % (cnt - 1);
			brackets.second = rand() % (cnt - brackets.first - 1) + brackets.first + 1;
		}
		for (int i = 0; i < cnt; i++)
		{
			nums.emplace_back(limit);
		}
		for (int i = 0; i < cnt - 1; i++)
		{
			chars.emplace_back(ops[rand() % 4]);
		}

		for (int i = 0; i < cnt; i++)
		{
			if (i == brackets.first)  exp += '(';
			exp += ' ';
			exp += nums[i].toString();
			exp += ' ';
			if (i == brackets.second)  exp += ')';
			if (i < cnt - 1) exp += chars[i];
		}
		ans = calAns();
		if (ans.toString() == "NAN") {
			*this = expression(limit);
		}
	}
	string toString() {
		return exp;
	}
	fraction getAns() {
		return ans;
	}
};

