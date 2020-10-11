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
		long long temp = 0;
		while (b != 0) {
			temp = a;
			a = b;
			b = temp % b;
		}
		return a;
	}
	long long up;
	long long down;

public:
	fraction(long long _up, long long _down) : up(_up), down(_down) {
		if (_down == 0) {
			throw "can't divide zero!";
		}
			long long GCD = gcd(up, down);
			up /= GCD;
			down /= GCD;
		
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
				up += down * stoll(s.substr(pos1 + 1, pos2 - 1 - pos1));
			}
			else {
				pos1 = pos2;
			}

			up += stoll(s.substr(0, pos1));
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
	bool operator<(const fraction& a) {
		return up * 1.0 / down < a.up * 1.0 / a.down;
	}
	bool operator>(const fraction& a) {
		return up * 1.0 / down > a.up * 1.0 / a.down;
	}
	bool operator==(const fraction& a) { return up == a.up && down == a.down; }
	string toString() {
		if (up == -1 && down == -1) {
			return "Not a Number!";
		}
		if (down == 1) {  // 5/1 --> 5 0/1 --> 0
			return to_string(up);
		}
		if (up < down) {  // 3/5 --> 3/5
			return to_string(up) + "/" + to_string(down);
		}
		// 5/2 --> 2'1/2
		return to_string(up / down) + "'" + to_string(up % down) + "/" +
			to_string(down);
	}
};