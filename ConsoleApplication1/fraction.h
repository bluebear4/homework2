#pragma once
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <type_traits>
#include <typeindex>
#include <unordered_map>
#include <unordered_set>
#endif
using namespace std;
class fraction {
	static long long gcd(long long a, long long b) {
		//辗转相除法求最大公因数
		long long temp = 0;
		while (b != 0) {
			temp = a;
			a = b;
			b = temp % b;
		}
		return a;
	}
	static long long Rand(long long limit) {
		long long res = long long(rand() * 1.0 / RAND_MAX * limit);
		while (res == limit)res = long long(rand() * 1.0 / RAND_MAX * limit);
		//若出现上界则重新生成
		return res;
	}
	long long up = -1;
	long long down = -1;

public:
	fraction(const fraction &other) {
		//拷贝函数
		up = other.up;
		down = other.down;
	}
	fraction() {}
	fraction(long long _up, long long _down) : up(_up), down(_down) {
		if (_down == 0) {
			//除0抛出异常
			throw "can't divide zero!";
		}
		long long GCD = gcd(up, down);//化简
		if (GCD < 0) GCD *= -1;
		//当分子是负数时 GCD为负 若直接除会将分母变成负数 分子变成正数 不利于统一判断
		up /= GCD;
		down /= GCD;
	}
	fraction(long long limit) {//随机生成上界
		if (Rand(2) || limit == 1) {//整数
			*this = fraction(Rand(limit), 1);
		}
		else {//分数
			long long down = Rand(limit);
			while (down == 0)down = Rand(limit);
			//若分母为0则重新生成
			*this = fraction(Rand(limit), down);
		}
	}
	fraction(const string& s) {
		int pos1 = s.find("'");
		int pos2 = s.find("/");
		if (pos2 == string::npos) {  //整数
			try {
				*this = fraction(stoll(s), 1);
			}
			catch (const char* msg) {
				cerr << msg << endl;
			}
		}
		else {  //分数
			long long up = 0, down = stoll(s.substr(pos2 + 1));
			if (pos1 != string::npos) {
				//整数部分*分母加给分子
				up += down * stoll(s.substr(0, pos1));
			}
			else {
				pos1 = -1;
			}

			up += stoll(s.substr(pos1 + 1, pos2 - pos1 - 1));
			try {
				*this = fraction(up, down);
			}
			catch (const char* msg) {
				cerr << msg << endl;
			}
		}
	}
	fraction operator+(const fraction& a) {
		try {
			return fraction(up * a.down + a.up * down, down * a.down);
		}
		catch (const char* msg) {
			cerr << msg << endl;
		}
	}
	fraction operator-(const fraction& a) {
		try {
			return fraction(up * a.down - a.up * down, down * a.down);
		}
		catch (const char* msg) {
			cerr << msg << endl;
		}
	}
	fraction operator*(const fraction& a) {
		try {
			return fraction(up * a.up, down * a.down);
		}
		catch (const char* msg) {
			cerr << msg << endl;
		}
	}
	fraction operator/(const fraction& a) {
		try {
			return fraction(up * a.down, down * a.up);
		}
		catch (const char* msg) {
			cerr << msg << endl;
		}
	}
	bool operator<(const fraction& a)const {
		return up * a.down < down * a.up;
	}
	bool operator>(const fraction& a)const {
		return up * a.down > down * a.up;
	}
	bool operator==(const fraction& a)const {
		return up * a.down == down * a.up;
	}
	bool operator!=(const fraction& a) const {
		return up * a.down != down * a.up;
	}
	string toString() {
		if (up == -1 && down == -1) {
			//出现异常/0时返回NAN表示not a number
			return "NAN";
		}
		if (down == 1) {  // 5/1 --> 5 0/1 --> 0
			//分子为1则为整数
			return to_string(up);
		}
		if (up / down == 0) {  // 3/5 --> 3/5
			//整数部分为0 则是简单的真分数
			return to_string(up) + "/" + to_string(down);
		}
		// 5/2 --> 2'1/2
		//否则为带分数
		return to_string(up / down) + "'" + to_string(abs(up) % abs(down)) + "/" +
			to_string(abs(down));
	}
};